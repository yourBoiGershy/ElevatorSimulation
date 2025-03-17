#ifndef SIMULATIONCONTROLLER_H
#define SIMULATIONCONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include "building.h"
#include "passenger.h"
#include "safetymonitor.h"

enum class SimulationState {
    SETUP,
    RUNNING,
    PAUSED,
    COMPLETED
};

class SimulationController : public QObject
{
    Q_OBJECT

public:
    explicit SimulationController(QObject *parent = nullptr);
    ~SimulationController();

    void setupSimulation(int numFloors, int numElevators, int numPassengers);
    void addPassenger(int startFloor);
    void addPassengerEvent(int passengerId, PassengerAction action, int timeStep, int floor = -1,
                          Direction direction = Direction::NONE, int targetFloor = -1, int elevatorId = -1);
    void addSafetyEvent(ElevatorSafetyEvent eventType, int timeStep, int elevatorId = -1);
    void setElevatorAllocationStrategy(ElevatorAllocationStrategy* strategy);
    
    Building* getBuilding() const;
    int getCurrentTimeStep() const;
    SimulationState getState() const;
    QString getStateString() const;
    const QVector<Passenger*>& getPassengers() const;
    SafetyMonitor* getSafetyMonitor() const;

public slots:
    void startSimulation();
    void pauseSimulation();
    void resumeSimulation();
    void stopSimulation();
    void stepSimulation();
    void resetSimulation();
    void update(); // Called by timer

signals:
    void simulationStarted();
    void simulationPaused();
    void simulationResumed();
    void simulationStopped();
    void simulationReset();
    void simulationCompleted();
    void timeStepChanged(int timeStep);
    void stateChanged(SimulationState state);
    void logMessage(const QString& message);

private:
    Building* m_building;
    QVector<Passenger*> m_passengers;
    SafetyMonitor* m_safetyMonitor;
    QTimer m_simulationTimer;
    int m_currentTimeStep;
    SimulationState m_state;
    int m_simulationSpeed; // milliseconds per time step
    
    bool isSimulationComplete() const;
    void processPassengerEvents();
    void processSafetyEvents();
};

#endif // SIMULATIONCONTROLLER_H 