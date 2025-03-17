#include "elevator.h"
#include <QDebug>
#include <algorithm>

Elevator::Elevator(int id, int totalFloors, QObject *parent)
    : QObject(parent),
      m_id(id),
      m_currentFloor(1),
      m_targetFloor(1),
      m_totalFloors(totalFloors),
      m_state(ElevatorState::IDLE),
      m_doorOpenTime(10),
      m_doorHoldOpen(false),
      m_overloaded(false),
      m_currentSafetyEvent(ElevatorSafetyEvent::NONE),
      m_doorObstacleCount(0),
      m_safeFloor(1)
{
    // Initialize button array for each floor
    m_buttonPressed.resize(m_totalFloors + 1, false);
    
    // Connect door timer
    connect(&m_doorTimer, &QTimer::timeout, this, &Elevator::closeDoor);
    
    // Connect door obstacle timer
    connect(&m_doorObstacleTimer, &QTimer::timeout, this, [this]() {
        m_doorObstacleCount = 0;
    });
}

Elevator::~Elevator()
{
}

int Elevator::getId() const
{
    return m_id;
}

int Elevator::getCurrentFloor() const
{
    return m_currentFloor;
}

ElevatorState Elevator::getState() const
{
    return m_state;
}

QString Elevator::getStateString() const
{
    switch (m_state) {
        case ElevatorState::IDLE:
            return "Idle";
        case ElevatorState::MOVING_UP:
            return "Moving Up";
        case ElevatorState::MOVING_DOWN:
            return "Moving Down";
        case ElevatorState::DOOR_OPENING:
            return "Door Opening";
        case ElevatorState::DOOR_OPEN:
            return "Door Open";
        case ElevatorState::DOOR_CLOSING:
            return "Door Closing";
        case ElevatorState::STOPPED_EMERGENCY:
            return "Emergency Stop";
        default:
            return "Unknown";
    }
}

bool Elevator::isIdle() const
{
    return m_state == ElevatorState::IDLE;
}

bool Elevator::isDoorOpen() const
{
    return m_state == ElevatorState::DOOR_OPEN || m_state == ElevatorState::DOOR_OPENING;
}

bool Elevator::hasDestination(int floor) const
{
    return m_destinations.contains(floor);
}

const QVector<int>& Elevator::getDestinations() const
{
    return m_destinations;
}

bool Elevator::isButtonPressed(int floor) const
{
    if (floor < 1 || floor > m_totalFloors) {
        return false;
    }
    return m_buttonPressed[floor];
}

void Elevator::pressButton(int floor)
{
    if (floor < 1 || floor > m_totalFloors) {
        return;
    }
    m_buttonPressed[floor] = true;
    addDestination(floor);
}

void Elevator::resetButton(int floor)
{
    if (floor < 1 || floor > m_totalFloors) {
        return;
    }
    m_buttonPressed[floor] = false;
}

bool Elevator::isOverloaded() const
{
    return m_overloaded;
}

bool Elevator::hasSafetyEvent() const
{
    return m_currentSafetyEvent != ElevatorSafetyEvent::NONE;
}

ElevatorSafetyEvent Elevator::getCurrentSafetyEvent() const
{
    return m_currentSafetyEvent;
}

void Elevator::moveToFloor(int floor)
{
    if (floor < 1 || floor > m_totalFloors || hasSafetyEvent()) {
        return;
    }
    
    addDestination(floor);
}

void Elevator::addDestination(int floor)
{
    if (floor < 1 || floor > m_totalFloors || hasSafetyEvent()) {
        return;
    }
    
    // Don't add if already in destinations or current floor with door open
    if (m_destinations.contains(floor) || (floor == m_currentFloor && isDoorOpen())) {
        return;
    }
    
    m_destinations.append(floor);
    sortDestinations();
    
    emit destinationsChanged(m_id, m_destinations);
    
    // If idle, start moving
    if (m_state == ElevatorState::IDLE && !m_destinations.isEmpty()) {
        m_targetFloor = getNextDestination();
        if (m_targetFloor > m_currentFloor) {
            m_state = ElevatorState::MOVING_UP;
        } else if (m_targetFloor < m_currentFloor) {
            m_state = ElevatorState::MOVING_DOWN;
        }
        emit stateChanged(m_id, m_state);
    }
}

void Elevator::update()
{
    // Handle safety events first
    if (hasSafetyEvent()) {
        handleSafetyEvent();
        return;
    }
    
    // Update based on current state
    switch (m_state) {
        case ElevatorState::IDLE:
            // Check if there are destinations
            if (!m_destinations.isEmpty()) {
                m_targetFloor = getNextDestination();
                if (m_targetFloor > m_currentFloor) {
                    m_state = ElevatorState::MOVING_UP;
                } else if (m_targetFloor < m_currentFloor) {
                    m_state = ElevatorState::MOVING_DOWN;
                } else {
                    // Target is current floor, open door
                    m_state = ElevatorState::DOOR_OPENING;
                }
                emit stateChanged(m_id, m_state);
            }
            break;
            
        case ElevatorState::MOVING_UP:
        case ElevatorState::MOVING_DOWN:
            moveOneStep();
            break;
            
        case ElevatorState::DOOR_OPENING:
            // Transition to door open
            m_state = ElevatorState::DOOR_OPEN;
            emit stateChanged(m_id, m_state);
            emit doorOpened(m_id);
            
            // Start door timer
            m_doorTimer.start(m_doorOpenTime * 1000);
            break;
            
        case ElevatorState::DOOR_OPEN:
            // Door remains open until timer expires or door close button pressed
            // Nothing to do here
            break;
            
        case ElevatorState::DOOR_CLOSING:
            // Transition to idle or moving
            m_state = ElevatorState::IDLE;
            emit stateChanged(m_id, m_state);
            emit doorClosed(m_id);
            
            // Remove current floor from destinations
            m_destinations.removeAll(m_currentFloor);
            resetButton(m_currentFloor);
            emit destinationsChanged(m_id, m_destinations);
            
            // Check if there are more destinations
            if (!m_destinations.isEmpty()) {
                m_targetFloor = getNextDestination();
                if (m_targetFloor > m_currentFloor) {
                    m_state = ElevatorState::MOVING_UP;
                } else if (m_targetFloor < m_currentFloor) {
                    m_state = ElevatorState::MOVING_DOWN;
                }
                emit stateChanged(m_id, m_state);
            }
            break;
            
        case ElevatorState::STOPPED_EMERGENCY:
            // Remain in emergency state until cleared
            break;
    }
}

void Elevator::openDoor()
{
    if (m_state == ElevatorState::DOOR_CLOSING) {
        m_state = ElevatorState::DOOR_OPENING;
        emit stateChanged(m_id, m_state);
    } else if (m_state == ElevatorState::IDLE) {
        m_state = ElevatorState::DOOR_OPENING;
        emit stateChanged(m_id, m_state);
    }
}

void Elevator::closeDoor()
{
    if (m_state == ElevatorState::DOOR_OPEN && !m_doorHoldOpen) {
        m_state = ElevatorState::DOOR_CLOSING;
        emit stateChanged(m_id, m_state);
    }
}

void Elevator::pressHelpButton()
{
    if (hasSafetyEvent()) {
        return;
    }
    
    triggerSafetyEvent(ElevatorSafetyEvent::HELP_BUTTON_PRESSED);
    emit helpButtonPressed(m_id);
}

void Elevator::triggerSafetyEvent(ElevatorSafetyEvent event)
{
    if (m_currentSafetyEvent != ElevatorSafetyEvent::NONE) {
        return; // Already handling a safety event
    }
    
    m_currentSafetyEvent = event;
    
    // Stop the elevator and handle the event
    if (m_state == ElevatorState::MOVING_UP || m_state == ElevatorState::MOVING_DOWN) {
        m_state = ElevatorState::STOPPED_EMERGENCY;
        emit stateChanged(m_id, m_state);
    }
    
    emit safetyEventTriggered(m_id, event);
    
    // Display and audio messages based on event type
    QString message;
    switch (event) {
        case ElevatorSafetyEvent::HELP_BUTTON_PRESSED:
            message = "Help button pressed. Connecting to building safety service.";
            break;
        case ElevatorSafetyEvent::DOOR_OBSTACLE:
            message = "Door obstacle detected. Door reopening.";
            break;
        case ElevatorSafetyEvent::FIRE_ALARM:
            message = "FIRE ALARM! Elevator moving to safe floor. Please remain calm.";
            break;
        case ElevatorSafetyEvent::OVERLOAD:
            message = "OVERLOAD DETECTED! Please reduce load before elevator can move.";
            break;
        case ElevatorSafetyEvent::POWER_OUT:
            message = "POWER OUTAGE! Elevator moving to safe floor using backup power.";
            break;
        default:
            message = "Safety event detected.";
    }
    
    emit displayMessage(m_id, message);
    emit audioMessage(m_id, message);
}

void Elevator::clearSafetyEvent()
{
    if (m_currentSafetyEvent == ElevatorSafetyEvent::NONE) {
        return;
    }
    
    ElevatorSafetyEvent previousEvent = m_currentSafetyEvent;
    m_currentSafetyEvent = ElevatorSafetyEvent::NONE;
    
    // Return to idle state
    m_state = ElevatorState::IDLE;
    emit stateChanged(m_id, m_state);
    
    emit safetyEventCleared(m_id);
    
    // Display and audio messages based on previous event type
    QString message;
    switch (previousEvent) {
        case ElevatorSafetyEvent::HELP_BUTTON_PRESSED:
            message = "Help request resolved.";
            break;
        case ElevatorSafetyEvent::DOOR_OBSTACLE:
            message = "Door obstacle cleared.";
            break;
        case ElevatorSafetyEvent::FIRE_ALARM:
            message = "Fire alarm cleared. Resuming normal operation.";
            break;
        case ElevatorSafetyEvent::OVERLOAD:
            message = "Overload resolved. Resuming normal operation.";
            break;
        case ElevatorSafetyEvent::POWER_OUT:
            message = "Power restored. Resuming normal operation.";
            break;
        default:
            message = "Safety event resolved.";
    }
    
    emit displayMessage(m_id, message);
    emit audioMessage(m_id, message);
}

void Elevator::moveToSafeFloor()
{
    // Clear destinations and set safe floor as the only destination
    m_destinations.clear();
    m_destinations.append(m_safeFloor);
    emit destinationsChanged(m_id, m_destinations);
    
    // Start moving to safe floor
    m_targetFloor = m_safeFloor;
    
    if (m_currentFloor < m_safeFloor) {
        m_state = ElevatorState::MOVING_UP;
    } else if (m_currentFloor > m_safeFloor) {
        m_state = ElevatorState::MOVING_DOWN;
    } else {
        // Already at safe floor, open door
        m_state = ElevatorState::DOOR_OPENING;
    }
    
    emit stateChanged(m_id, m_state);
}

void Elevator::simulateDoorObstacle()
{
    if (m_state == ElevatorState::DOOR_CLOSING) {
        m_doorObstacleCount++;
        
        // Reopen door
        m_state = ElevatorState::DOOR_OPENING;
        emit stateChanged(m_id, m_state);
        
        // Trigger safety event if repeated obstacles
        if (m_doorObstacleCount >= 3) {
            triggerSafetyEvent(ElevatorSafetyEvent::DOOR_OBSTACLE);
        } else {
            // Start the obstacle timer if not already running
            if (!m_doorObstacleTimer.isActive()) {
                m_doorObstacleTimer.start(10000); // Reset count after 10 seconds
            }
            
            // Display warning message
            QString message = "Door obstacle detected. Door reopening.";
            emit displayMessage(m_id, message);
            emit audioMessage(m_id, message);
        }
    }
}

void Elevator::simulateOverload()
{
    m_overloaded = true;
    triggerSafetyEvent(ElevatorSafetyEvent::OVERLOAD);
}

void Elevator::sortDestinations()
{
    // Sort destinations based on current direction
    if (m_state == ElevatorState::MOVING_UP) {
        // Sort destinations: first floors above current floor in ascending order, then floors below in descending order
        std::sort(m_destinations.begin(), m_destinations.end(), [this](int a, int b) {
            bool aAbove = a >= m_currentFloor;
            bool bAbove = b >= m_currentFloor;
            
            if (aAbove && bAbove) return a < b;
            if (!aAbove && !bAbove) return a > b;
            return aAbove;
        });
    } else if (m_state == ElevatorState::MOVING_DOWN) {
        // Sort destinations: first floors below current floor in descending order, then floors above in ascending order
        std::sort(m_destinations.begin(), m_destinations.end(), [this](int a, int b) {
            bool aBelow = a <= m_currentFloor;
            bool bBelow = b <= m_currentFloor;
            
            if (aBelow && bBelow) return a > b;
            if (!aBelow && !bBelow) return a < b;
            return aBelow;
        });
    } else {
        // If idle, sort by distance from current floor
        std::sort(m_destinations.begin(), m_destinations.end(), [this](int a, int b) {
            return std::abs(a - m_currentFloor) < std::abs(b - m_currentFloor);
        });
    }
}

int Elevator::getNextDestination() const
{
    if (m_destinations.isEmpty()) {
        return m_currentFloor;
    }
    return m_destinations.first();
}

void Elevator::moveOneStep()
{
    // Move one floor in the current direction
    if (m_state == ElevatorState::MOVING_UP) {
        m_currentFloor++;
    } else if (m_state == ElevatorState::MOVING_DOWN) {
        m_currentFloor--;
    }
    
    // Check if arrived at a destination
    if (m_currentFloor == m_targetFloor || m_destinations.contains(m_currentFloor)) {
        handleArrival();
    }
    
    // Emit signal for floor change
    emit arrivedAtFloor(m_id, m_currentFloor);
}

void Elevator::handleArrival()
{
    // Ring bell and open doors
    m_state = ElevatorState::DOOR_OPENING;
    emit stateChanged(m_id, m_state);
    
    // Update target floor for next movement
    if (!m_destinations.isEmpty()) {
        m_targetFloor = getNextDestination();
    }
}

void Elevator::handleSafetyEvent()
{
    switch (m_currentSafetyEvent) {
        case ElevatorSafetyEvent::FIRE_ALARM:
        case ElevatorSafetyEvent::POWER_OUT:
            // Move to safe floor
            if (m_currentFloor != m_safeFloor) {
                // Continue moving to safe floor
                if (m_currentFloor < m_safeFloor) {
                    m_state = ElevatorState::MOVING_UP;
                    moveOneStep();
                } else if (m_currentFloor > m_safeFloor) {
                    m_state = ElevatorState::MOVING_DOWN;
                    moveOneStep();
                }
            } else {
                // At safe floor, open door if not already open
                if (m_state != ElevatorState::DOOR_OPEN && m_state != ElevatorState::DOOR_OPENING) {
                    m_state = ElevatorState::DOOR_OPENING;
                    emit stateChanged(m_id, m_state);
                }
            }
            break;
            
        case ElevatorSafetyEvent::OVERLOAD:
            // Stay in place until overload is resolved
            if (m_overloaded) {
                // Display message periodically
                emit displayMessage(m_id, "OVERLOAD DETECTED! Please reduce load before elevator can move.");
                emit audioMessage(m_id, "OVERLOAD DETECTED! Please reduce load before elevator can move.");
            } else {
                // Overload resolved
                clearSafetyEvent();
            }
            break;
            
        case ElevatorSafetyEvent::DOOR_OBSTACLE:
            // Keep door open until obstacle is cleared
            if (m_state != ElevatorState::DOOR_OPEN) {
                m_state = ElevatorState::DOOR_OPEN;
                emit stateChanged(m_id, m_state);
            }
            break;
            
        case ElevatorSafetyEvent::HELP_BUTTON_PRESSED:
            // Stay in place until help is provided
            // Nothing to do here, handled by SafetyMonitor
            break;
            
        default:
            break;
    }
} 