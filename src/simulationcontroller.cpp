#include "simulationcontroller.h"
#include <QDebug>

SimulationController::SimulationController(QObject *parent)
    : QObject(parent),
      m_building(nullptr),
      m_safetyMonitor(nullptr),
      m_currentTimeStep(0),
      m_state(SimulationState::SETUP),
      m_simulationSpeed(1000) // 1 second per time step
{
    // Connect simulation timer
    connect(&m_simulationTimer, &QTimer::timeout, this, &SimulationController::update);
}

SimulationController::~SimulationController()
{
    delete m_building;
    delete m_safetyMonitor;
    
    // Passengers are deleted automatically as they are children of this object
}

void SimulationController::setupSimulation(int numFloors, int numElevators, int numPassengers)
{
    // Clean up previous simulation if any
    resetSimulation();
    
    // Create building
    m_building = new Building(numFloors, numElevators, this);
    
    // Connect building signals
    connect(m_building, &Building::logMessage, this, &SimulationController::logMessage);
    
    // Create safety monitor
    m_safetyMonitor = new SafetyMonitor(this);
    
    // Connect safety monitor signals
    connect(m_safetyMonitor, &SafetyMonitor::logMessage, this, &SimulationController::logMessage);
    connect(m_safetyMonitor, &SafetyMonitor::buildingSafetyEventTriggered, this, [this](ElevatorSafetyEvent event) {
        if (event == ElevatorSafetyEvent::FIRE_ALARM) {
            m_building->triggerFireAlarm();
        } else if (event == ElevatorSafetyEvent::POWER_OUT) {
            m_building->triggerPowerOutage();
        }
    });
    
    // Connect safety monitor to elevators
    for (Elevator* elevator : m_building->getElevators()) {
        m_safetyMonitor->connectToElevator(elevator);
    }
    
    // Create passengers
    for (int i = 0; i < numPassengers; ++i) {
        // Randomly assign starting floor
        int startFloor = rand() % numFloors + 1;
        addPassenger(startFloor);
    }
    
    emit logMessage(QString("Simulation setup complete: %1 floors, %2 elevators, %3 passengers")
                   .arg(numFloors).arg(numElevators).arg(numPassengers));
}

void SimulationController::addPassenger(int startFloor)
{
    int id = m_passengers.size();
    Passenger* passenger = new Passenger(id, startFloor, this);
    
    // Connect passenger signals
    connect(passenger, &Passenger::logMessage, this, &SimulationController::logMessage);
    connect(passenger, &Passenger::requestedElevator, this, [this](int, int floor, Direction direction) {
        m_building->requestElevator(floor, direction);
    });
    connect(passenger, &Passenger::pressedFloorButton, this, [this](int, int elevatorId, int floor) {
        if (elevatorId >= 0 && elevatorId < m_building->getNumElevators()) {
            m_building->getElevator(elevatorId)->pressButton(floor);
        }
    });
    connect(passenger, &Passenger::pressedHelpButton, this, [this](int, int elevatorId) {
        if (elevatorId >= 0 && elevatorId < m_building->getNumElevators()) {
            m_building->getElevator(elevatorId)->pressHelpButton();
        }
    });
    connect(passenger, &Passenger::pressedDoorOpen, this, [this](int, int elevatorId) {
        if (elevatorId >= 0 && elevatorId < m_building->getNumElevators()) {
            m_building->getElevator(elevatorId)->openDoor();
        }
    });
    connect(passenger, &Passenger::pressedDoorClose, this, [this](int, int elevatorId) {
        if (elevatorId >= 0 && elevatorId < m_building->getNumElevators()) {
            m_building->getElevator(elevatorId)->closeDoor();
        }
    });
    
    m_passengers.append(passenger);
}

void SimulationController::addPassengerEvent(int passengerId, PassengerAction action, int timeStep, int floor,
                                           Direction direction, int targetFloor, int elevatorId)
{
    if (passengerId < 0 || passengerId >= m_passengers.size()) {
        return;
    }
    
    m_passengers[passengerId]->addEvent(action, timeStep, floor, direction, targetFloor, elevatorId);
}

void SimulationController::addSafetyEvent(ElevatorSafetyEvent eventType, int timeStep, int elevatorId)
{
    if (!m_safetyMonitor) {
        return;
    }
    
    m_safetyMonitor->addSafetyEvent(eventType, timeStep, elevatorId);
}

void SimulationController::setElevatorAllocationStrategy(ElevatorAllocationStrategy* strategy)
{
    if (!m_building) {
        return;
    }
    
    m_building->setElevatorAllocationStrategy(strategy);
}

Building* SimulationController::getBuilding() const
{
    return m_building;
}

int SimulationController::getCurrentTimeStep() const
{
    return m_currentTimeStep;
}

SimulationState SimulationController::getState() const
{
    return m_state;
}

QString SimulationController::getStateString() const
{
    switch (m_state) {
        case SimulationState::SETUP:
            return "Setup";
        case SimulationState::RUNNING:
            return "Running";
        case SimulationState::PAUSED:
            return "Paused";
        case SimulationState::COMPLETED:
            return "Completed";
        default:
            return "Unknown";
    }
}

const QVector<Passenger*>& SimulationController::getPassengers() const
{
    return m_passengers;
}

SafetyMonitor* SimulationController::getSafetyMonitor() const
{
    return m_safetyMonitor;
}

void SimulationController::startSimulation()
{
    if (m_state != SimulationState::SETUP && m_state != SimulationState::COMPLETED) {
        return;
    }
    
    m_currentTimeStep = 0;
    m_state = SimulationState::RUNNING;
    
    emit simulationStarted();
    emit stateChanged(m_state);
    emit timeStepChanged(m_currentTimeStep);
    emit logMessage("Simulation started");
    
    // Start the simulation timer
    m_simulationTimer.start(m_simulationSpeed);
}

void SimulationController::pauseSimulation()
{
    if (m_state != SimulationState::RUNNING) {
        return;
    }
    
    m_state = SimulationState::PAUSED;
    
    emit simulationPaused();
    emit stateChanged(m_state);
    emit logMessage("Simulation paused");
    
    // Stop the simulation timer
    m_simulationTimer.stop();
}

void SimulationController::resumeSimulation()
{
    if (m_state != SimulationState::PAUSED) {
        return;
    }
    
    m_state = SimulationState::RUNNING;
    
    emit simulationResumed();
    emit stateChanged(m_state);
    emit logMessage("Simulation resumed");
    
    // Restart the simulation timer
    m_simulationTimer.start(m_simulationSpeed);
}

void SimulationController::stopSimulation()
{
    if (m_state != SimulationState::RUNNING && m_state != SimulationState::PAUSED) {
        return;
    }
    
    m_state = SimulationState::COMPLETED;
    
    emit simulationStopped();
    emit stateChanged(m_state);
    emit logMessage("Simulation stopped");
    
    // Stop the simulation timer
    m_simulationTimer.stop();
}

void SimulationController::stepSimulation()
{
    if (m_state != SimulationState::PAUSED) {
        return;
    }
    
    // Manually advance one time step
    update();
}

void SimulationController::resetSimulation()
{
    // Stop the simulation timer
    m_simulationTimer.stop();
    
    // Reset state
    m_currentTimeStep = 0;
    m_state = SimulationState::SETUP;
    
    // Clean up objects
    delete m_building;
    m_building = nullptr;
    
    delete m_safetyMonitor;
    m_safetyMonitor = nullptr;
    
    // Delete all passengers
    qDeleteAll(m_passengers);
    m_passengers.clear();
    
    emit simulationReset();
    emit stateChanged(m_state);
    emit timeStepChanged(m_currentTimeStep);
    emit logMessage("Simulation reset");
}

void SimulationController::update()
{
    if (m_state != SimulationState::RUNNING) {
        return;
    }
    
    // Increment time step
    m_currentTimeStep++;
    emit timeStepChanged(m_currentTimeStep);
    emit logMessage(QString("Time step: %1").arg(m_currentTimeStep));
    
    // Process passenger events
    processPassengerEvents();
    
    // Process safety events
    processSafetyEvents();
    
    // Update building (which updates elevators)
    if (m_building) {
        m_building->update();
    }
    
    // Check if simulation is complete
    if (isSimulationComplete()) {
        m_state = SimulationState::COMPLETED;
        emit simulationCompleted();
        emit stateChanged(m_state);
        emit logMessage("Simulation completed");
        
        // Stop the simulation timer
        m_simulationTimer.stop();
    }
}

bool SimulationController::isSimulationComplete() const
{
    // Check if all passengers have no more events
    for (const Passenger* passenger : m_passengers) {
        if (passenger->hasEventsRemaining(m_currentTimeStep)) {
            return false;
        }
    }
    
    // Check if all elevators are idle
    if (m_building) {
        for (Elevator* elevator : m_building->getElevators()) {
            if (!elevator->isIdle()) {
                return false;
            }
        }
    }
    
    // Check if there are any pending safety events
    if (m_safetyMonitor && m_safetyMonitor->hasEventsRemaining(m_currentTimeStep)) {
        return false;
    }
    
    return true;
}

void SimulationController::processPassengerEvents()
{
    for (Passenger* passenger : m_passengers) {
        PassengerEvent event = passenger->getNextEvent(m_currentTimeStep);
        if (event.action != PassengerAction::NONE) {
            passenger->executeEvent(event);
        }
    }
}

void SimulationController::processSafetyEvents()
{
    if (m_safetyMonitor) {
        m_safetyMonitor->checkSafetyEvents(m_currentTimeStep);
    }
} 