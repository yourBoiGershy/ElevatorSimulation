#include "building.h"
#include <QDebug>

Building::Building(int numFloors, int numElevators, QObject *parent)
    : QObject(parent),
      m_numFloors(numFloors),
      m_numElevators(numElevators),
      m_allocationStrategy(nullptr),
      m_emergencyMode(false)
{
    // Create elevators
    for (int i = 0; i < m_numElevators; ++i) {
        Elevator* elevator = new Elevator(i, m_numFloors, this);
        m_elevators.append(elevator);
        
        // Connect elevator signals
        connect(elevator, &Elevator::arrivedAtFloor, this, [this](int elevatorId, int floor) {
            emit logMessage(QString("Elevator %1 arrived at floor %2").arg(elevatorId).arg(floor));
        });
        
        connect(elevator, &Elevator::doorOpened, this, [this](int elevatorId) {
            emit logMessage(QString("Elevator %1 door opened").arg(elevatorId));
        });
        
        connect(elevator, &Elevator::doorClosed, this, [this](int elevatorId) {
            emit logMessage(QString("Elevator %1 door closed").arg(elevatorId));
        });
        
        connect(elevator, &Elevator::stateChanged, this, [this, elevator](int elevatorId, ElevatorState) {
            emit logMessage(QString("Elevator %1 state changed to %2").arg(elevatorId).arg(elevator->getStateString()));
        });
    }
    
    // Initialize floor buttons
    m_floorButtonsUp.resize(m_numFloors + 1);
    m_floorButtonsDown.resize(m_numFloors + 1);
    
    // Initialize all buttons to false
    for (int i = 0; i <= m_numFloors; ++i) {
        m_floorButtonsUp[i] = false;
        m_floorButtonsDown[i] = false;
    }
}

Building::~Building()
{
    // Elevators are deleted automatically as they are children of this object
    delete m_allocationStrategy;
}

int Building::getNumFloors() const
{
    return m_numFloors;
}

int Building::getNumElevators() const
{
    return m_numElevators;
}

Elevator* Building::getElevator(int id) const
{
    if (id < 0 || id >= m_elevators.size()) {
        return nullptr;
    }
    return m_elevators[id];
}

const QVector<Elevator*>& Building::getElevators() const
{
    return m_elevators;
}

bool Building::isFloorButtonPressed(int floor, Direction direction) const
{
    if (floor < 1 || floor > m_numFloors) {
        return false;
    }
    
    if (direction == Direction::UP) {
        return m_floorButtonsUp[floor];
    } else if (direction == Direction::DOWN) {
        return m_floorButtonsDown[floor];
    }
    
    return false;
}

void Building::setElevatorAllocationStrategy(ElevatorAllocationStrategy* strategy)
{
    delete m_allocationStrategy;
    m_allocationStrategy = strategy;
}

void Building::requestElevator(int floor, Direction direction)
{
    if (floor < 1 || floor > m_numFloors) {
        return;
    }
    
    // Set floor button state
    if (direction == Direction::UP) {
        m_floorButtonsUp[floor] = true;
    } else if (direction == Direction::DOWN) {
        m_floorButtonsDown[floor] = true;
    }
    
    emit floorButtonPressed(floor, direction);
    emit logMessage(QString("Floor %1 %2 button pressed").arg(floor).arg(direction == Direction::UP ? "UP" : "DOWN"));
    
    // Add to pending requests
    FloorRequest request(floor, direction, 0); // Time step not used here
    m_pendingRequests.append(request);
    
    // Allocate elevator to handle the request
    allocateElevatorToRequest(request);
}

void Building::resetFloorButton(int floor, Direction direction)
{
    if (floor < 1 || floor > m_numFloors) {
        return;
    }
    
    // Reset floor button state
    if (direction == Direction::UP) {
        m_floorButtonsUp[floor] = false;
    } else if (direction == Direction::DOWN) {
        m_floorButtonsDown[floor] = false;
    }
    
    emit floorButtonReset(floor, direction);
    emit logMessage(QString("Floor %1 %2 button reset").arg(floor).arg(direction == Direction::UP ? "UP" : "DOWN"));
}

void Building::update()
{
    // Update all elevators
    for (Elevator* elevator : m_elevators) {
        elevator->update();
    }
    
    // Handle emergency if active
    if (m_emergencyMode) {
        handleEmergency();
    }
    
    // Check for completed requests
    for (int i = 0; i < m_pendingRequests.size(); ++i) {
        FloorRequest& request = m_pendingRequests[i];
        if (!request.isHandled()) {
            // Check if any elevator has arrived at the requested floor
            for (Elevator* elevator : m_elevators) {
                if (elevator->getCurrentFloor() == request.getFloor() && 
                    elevator->isDoorOpen()) {
                    // Mark request as handled
                    request.setHandled(true);
                    
                    // Reset floor button
                    resetFloorButton(request.getFloor(), request.getDirection());
                    break;
                }
            }
        }
    }
    
    // Remove handled requests
    for (int i = m_pendingRequests.size() - 1; i >= 0; --i) {
        if (m_pendingRequests[i].isHandled()) {
            m_pendingRequests.removeAt(i);
        }
    }
}

void Building::triggerFireAlarm()
{
    if (m_emergencyMode) {
        return;
    }
    
    m_emergencyMode = true;
    m_emergencyType = "Fire Alarm";
    
    emit emergencyTriggered(m_emergencyType);
    emit logMessage("FIRE ALARM TRIGGERED! All elevators moving to safe floor.");
    
    // Move all elevators to safe floor
    for (Elevator* elevator : m_elevators) {
        elevator->triggerSafetyEvent(ElevatorSafetyEvent::FIRE_ALARM);
        elevator->moveToSafeFloor();
    }
}

void Building::triggerPowerOutage()
{
    if (m_emergencyMode) {
        return;
    }
    
    m_emergencyMode = true;
    m_emergencyType = "Power Outage";
    
    emit emergencyTriggered(m_emergencyType);
    emit logMessage("POWER OUTAGE DETECTED! All elevators moving to safe floor using backup power.");
    
    // Move all elevators to safe floor
    for (Elevator* elevator : m_elevators) {
        elevator->triggerSafetyEvent(ElevatorSafetyEvent::POWER_OUT);
        elevator->moveToSafeFloor();
    }
}

void Building::clearEmergency()
{
    if (!m_emergencyMode) {
        return;
    }
    
    m_emergencyMode = false;
    
    emit emergencyCleared();
    emit logMessage(QString("%1 CLEARED! Resuming normal operation.").arg(m_emergencyType));
    
    // Clear safety events for all elevators
    for (Elevator* elevator : m_elevators) {
        elevator->clearSafetyEvent();
    }
}

void Building::allocateElevatorToRequest(const FloorRequest& request)
{
    if (!m_allocationStrategy) {
        // Default to first available elevator if no strategy is set
        for (Elevator* elevator : m_elevators) {
            if (!elevator->hasSafetyEvent()) {
                elevator->addDestination(request.getFloor());
                emit elevatorAllocated(elevator->getId(), request.getFloor(), request.getDirection());
                emit logMessage(QString("Elevator %1 allocated to floor %2 %3 request")
                               .arg(elevator->getId())
                               .arg(request.getFloor())
                               .arg(request.getDirection() == Direction::UP ? "UP" : "DOWN"));
                return;
            }
        }
    } else {
        // Use the allocation strategy
        int elevatorId = m_allocationStrategy->allocateElevator(m_elevators, request);
        if (elevatorId >= 0 && elevatorId < m_elevators.size()) {
            m_elevators[elevatorId]->addDestination(request.getFloor());
            emit elevatorAllocated(elevatorId, request.getFloor(), request.getDirection());
            emit logMessage(QString("Elevator %1 allocated to floor %2 %3 request")
                           .arg(elevatorId)
                           .arg(request.getFloor())
                           .arg(request.getDirection() == Direction::UP ? "UP" : "DOWN"));
        } else {
            emit logMessage(QString("No suitable elevator found for floor %1 %2 request")
                           .arg(request.getFloor())
                           .arg(request.getDirection() == Direction::UP ? "UP" : "DOWN"));
        }
    }
}

void Building::handleEmergency()
{
    // Check if all elevators have reached safe floor
    bool allAtSafeFloor = true;
    for (Elevator* elevator : m_elevators) {
        if (elevator->getCurrentFloor() != 1) { // Assuming safe floor is 1
            allAtSafeFloor = false;
            break;
        }
    }
    
    if (allAtSafeFloor) {
        emit logMessage("All elevators have reached the safe floor.");
    }
} 