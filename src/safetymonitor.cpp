#include "safetymonitor.h"
#include <QDebug>

SafetyMonitor::SafetyMonitor(QObject *parent)
    : QObject(parent),
      m_helpResponseTimeoutSeconds(5),
      m_buildingEmergencyActive(false),
      m_buildingEmergencyType(ElevatorSafetyEvent::NONE)
{
    // Connect help response timer
    connect(&m_helpResponseTimer, &QTimer::timeout, this, [this]() {
        for (int elevatorId : m_activeHelpRequests) {
            emit emergency911Called(elevatorId);
            emit logMessage(QString("No response from building safety service for elevator %1. Calling 911 emergency.").arg(elevatorId));
        }
        m_activeHelpRequests.clear();
    });
}

SafetyMonitor::~SafetyMonitor()
{
}

void SafetyMonitor::addSafetyEvent(ElevatorSafetyEvent eventType, int timeStep, int elevatorId)
{
    SafetyEvent event;
    event.eventType = eventType;
    event.timeStep = timeStep;
    event.elevatorId = elevatorId;
    
    m_scheduledEvents.append(event);
}

QVector<SafetyEvent> SafetyMonitor::getEventsForTimeStep(int timeStep) const
{
    QVector<SafetyEvent> events;
    
    for (const SafetyEvent& event : m_scheduledEvents) {
        if (event.timeStep == timeStep) {
            events.append(event);
        }
    }
    
    return events;
}

bool SafetyMonitor::hasEventsRemaining(int currentTimeStep) const
{
    for (const SafetyEvent& event : m_scheduledEvents) {
        if (event.timeStep >= currentTimeStep) {
            return true;
        }
    }
    
    return false;
}

void SafetyMonitor::connectToElevator(Elevator* elevator)
{
    if (!elevator) {
        return;
    }
    
    connect(elevator, &Elevator::helpButtonPressed, this, &SafetyMonitor::handleHelpButtonPressed);
    connect(elevator, &Elevator::safetyEventTriggered, this, [this](int elevatorId, ElevatorSafetyEvent event) {
        if (event == ElevatorSafetyEvent::FIRE_ALARM) {
            handleElevatorFireAlarm(elevatorId);
        } else if (event == ElevatorSafetyEvent::OVERLOAD) {
            handleOverload(elevatorId);
        }
    });
}

void SafetyMonitor::handleHelpButtonPressed(int elevatorId)
{
    emit logMessage(QString("Help button pressed in elevator %1. Connecting to building safety service.").arg(elevatorId));
    
    // Add to active help requests
    if (!m_activeHelpRequests.contains(elevatorId)) {
        m_activeHelpRequests.append(elevatorId);
    }
    
    // Start help response timer if not already running
    if (!m_helpResponseTimer.isActive()) {
        m_helpResponseTimer.start(m_helpResponseTimeoutSeconds * 1000);
    }
    
    emit safetyEventTriggered(ElevatorSafetyEvent::HELP_BUTTON_PRESSED, elevatorId);
}

void SafetyMonitor::handleDoorObstacle(int elevatorId)
{
    emit logMessage(QString("Door obstacle detected in elevator %1.").arg(elevatorId));
    emit safetyEventTriggered(ElevatorSafetyEvent::DOOR_OBSTACLE, elevatorId);
}

void SafetyMonitor::handleFireAlarm()
{
    if (m_buildingEmergencyActive) {
        return;
    }
    
    m_buildingEmergencyActive = true;
    m_buildingEmergencyType = ElevatorSafetyEvent::FIRE_ALARM;
    
    emit logMessage("FIRE ALARM TRIGGERED in the building!");
    emit buildingSafetyEventTriggered(ElevatorSafetyEvent::FIRE_ALARM);
}

void SafetyMonitor::handleElevatorFireAlarm(int elevatorId)
{
    emit logMessage(QString("FIRE ALARM TRIGGERED in elevator %1!").arg(elevatorId));
    
    // If not already in building emergency, trigger it
    if (!m_buildingEmergencyActive) {
        handleFireAlarm();
    }
}

void SafetyMonitor::handleOverload(int elevatorId)
{
    emit logMessage(QString("OVERLOAD detected in elevator %1!").arg(elevatorId));
    emit safetyEventTriggered(ElevatorSafetyEvent::OVERLOAD, elevatorId);
    
    // Display and audio messages
    QString message = "OVERLOAD DETECTED! Please reduce load before elevator can move.";
    emit displayMessage(elevatorId, message);
    emit audioMessage(elevatorId, message);
}

void SafetyMonitor::handlePowerOutage()
{
    if (m_buildingEmergencyActive) {
        return;
    }
    
    m_buildingEmergencyActive = true;
    m_buildingEmergencyType = ElevatorSafetyEvent::POWER_OUT;
    
    emit logMessage("POWER OUTAGE DETECTED in the building!");
    emit buildingSafetyEventTriggered(ElevatorSafetyEvent::POWER_OUT);
}

void SafetyMonitor::checkSafetyEvents(int currentTimeStep)
{
    // Check for scheduled safety events at this time step
    QVector<SafetyEvent> events = getEventsForTimeStep(currentTimeStep);
    
    for (const SafetyEvent& event : events) {
        if (event.elevatorId == -1) {
            // Building-wide event
            handleBuildingWideEvent(event.eventType);
        } else {
            // Elevator-specific event
            handleElevatorEvent(event.eventType, event.elevatorId);
        }
    }
}

void SafetyMonitor::startHelpResponseTimer(int elevatorId)
{
    // Simulate building safety service responding to help request
    if (m_activeHelpRequests.contains(elevatorId)) {
        m_activeHelpRequests.removeAll(elevatorId);
        emit logMessage(QString("Building safety service responded to help request in elevator %1.").arg(elevatorId));
        emit safetyEventResolved(elevatorId);
    }
    
    // If no more active help requests, stop the timer
    if (m_activeHelpRequests.isEmpty() && m_helpResponseTimer.isActive()) {
        m_helpResponseTimer.stop();
    }
}

void SafetyMonitor::handleBuildingWideEvent(ElevatorSafetyEvent eventType)
{
    switch (eventType) {
        case ElevatorSafetyEvent::FIRE_ALARM:
            handleFireAlarm();
            break;
            
        case ElevatorSafetyEvent::POWER_OUT:
            handlePowerOutage();
            break;
            
        default:
            // Other events are not building-wide
            break;
    }
}

void SafetyMonitor::handleElevatorEvent(ElevatorSafetyEvent eventType, int elevatorId)
{
    switch (eventType) {
        case ElevatorSafetyEvent::HELP_BUTTON_PRESSED:
            handleHelpButtonPressed(elevatorId);
            break;
            
        case ElevatorSafetyEvent::DOOR_OBSTACLE:
            handleDoorObstacle(elevatorId);
            break;
            
        case ElevatorSafetyEvent::FIRE_ALARM:
            handleElevatorFireAlarm(elevatorId);
            break;
            
        case ElevatorSafetyEvent::OVERLOAD:
            handleOverload(elevatorId);
            break;
            
        default:
            // Other events handled elsewhere
            break;
    }
} 