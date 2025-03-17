#include "passenger.h"
#include <QDebug>

Passenger::Passenger(int id, int startFloor, QObject *parent)
    : QObject(parent),
      m_id(id),
      m_currentFloor(startFloor),
      m_currentElevator(-1),
      m_inElevator(false)
{
}

Passenger::~Passenger()
{
}

int Passenger::getId() const
{
    return m_id;
}

int Passenger::getCurrentFloor() const
{
    return m_currentFloor;
}

int Passenger::getCurrentElevator() const
{
    return m_currentElevator;
}

bool Passenger::isInElevator() const
{
    return m_inElevator;
}

void Passenger::addEvent(PassengerAction action, int timeStep, int floor, 
                        Direction direction, int targetFloor, int elevatorId)
{
    PassengerEvent event;
    event.action = action;
    event.timeStep = timeStep;
    event.floor = floor;
    event.direction = direction;
    event.targetFloor = targetFloor;
    event.elevatorId = elevatorId;
    
    m_events.append(event);
}

PassengerEvent Passenger::getNextEvent(int currentTimeStep) const
{
    PassengerEvent emptyEvent;
    emptyEvent.action = PassengerAction::NONE;
    emptyEvent.timeStep = -1;
    
    for (const PassengerEvent& event : m_events) {
        if (event.timeStep == currentTimeStep) {
            return event;
        }
    }
    
    return emptyEvent;
}

bool Passenger::hasEventsRemaining(int currentTimeStep) const
{
    for (const PassengerEvent& event : m_events) {
        if (event.timeStep >= currentTimeStep) {
            return true;
        }
    }
    
    return false;
}

void Passenger::enterElevator(int elevatorId)
{
    if (m_inElevator) {
        return;
    }
    
    m_inElevator = true;
    m_currentElevator = elevatorId;
    
    emit enteredElevator(m_id, elevatorId);
    emit logMessage(QString("Passenger %1 entered elevator %2 at floor %3").arg(m_id).arg(elevatorId).arg(m_currentFloor));
}

void Passenger::exitElevator()
{
    if (!m_inElevator) {
        return;
    }
    
    int elevatorId = m_currentElevator;
    m_inElevator = false;
    m_currentElevator = -1;
    
    emit exitedElevator(m_id, elevatorId, m_currentFloor);
    emit logMessage(QString("Passenger %1 exited elevator %2 at floor %3").arg(m_id).arg(elevatorId).arg(m_currentFloor));
}

void Passenger::setCurrentFloor(int floor)
{
    m_currentFloor = floor;
}

void Passenger::executeEvent(const PassengerEvent& event)
{
    switch (event.action) {
        case PassengerAction::REQUEST_ELEVATOR:
            emit requestedElevator(m_id, event.floor, event.direction);
            emit logMessage(QString("Passenger %1 requested elevator at floor %2 going %3")
                           .arg(m_id)
                           .arg(event.floor)
                           .arg(event.direction == Direction::UP ? "UP" : "DOWN"));
            break;
            
        case PassengerAction::ENTER_ELEVATOR:
            enterElevator(event.elevatorId);
            break;
            
        case PassengerAction::PRESS_FLOOR_BUTTON:
            if (m_inElevator) {
                emit pressedFloorButton(m_id, m_currentElevator, event.targetFloor);
                emit logMessage(QString("Passenger %1 pressed floor %2 button in elevator %3")
                               .arg(m_id)
                               .arg(event.targetFloor)
                               .arg(m_currentElevator));
            }
            break;
            
        case PassengerAction::PRESS_HELP_BUTTON:
            if (m_inElevator) {
                emit pressedHelpButton(m_id, m_currentElevator);
                emit logMessage(QString("Passenger %1 pressed HELP button in elevator %2")
                               .arg(m_id)
                               .arg(m_currentElevator));
            }
            break;
            
        case PassengerAction::PRESS_DOOR_OPEN:
            if (m_inElevator) {
                emit pressedDoorOpen(m_id, m_currentElevator);
                emit logMessage(QString("Passenger %1 pressed DOOR OPEN button in elevator %2")
                               .arg(m_id)
                               .arg(m_currentElevator));
            }
            break;
            
        case PassengerAction::PRESS_DOOR_CLOSE:
            if (m_inElevator) {
                emit pressedDoorClose(m_id, m_currentElevator);
                emit logMessage(QString("Passenger %1 pressed DOOR CLOSE button in elevator %2")
                               .arg(m_id)
                               .arg(m_currentElevator));
            }
            break;
            
        case PassengerAction::EXIT_ELEVATOR:
            if (m_inElevator) {
                exitElevator();
            }
            break;
            
        case PassengerAction::NONE:
            // Do nothing
            break;
    }
} 