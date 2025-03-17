#ifndef BUILDING_H
#define BUILDING_H

#include <QObject>
#include <QVector>
#include "elevator.h"
#include "floorrequest.h"
#include "elevatorallocationstrategy.h"

class Building : public QObject
{
    Q_OBJECT

public:
    explicit Building(int numFloors, int numElevators, QObject *parent = nullptr);
    ~Building();

    int getNumFloors() const;
    int getNumElevators() const;
    Elevator* getElevator(int id) const;
    const QVector<Elevator*>& getElevators() const;
    bool isFloorButtonPressed(int floor, Direction direction) const;
    void setElevatorAllocationStrategy(ElevatorAllocationStrategy* strategy);

public slots:
    void requestElevator(int floor, Direction direction);
    void resetFloorButton(int floor, Direction direction);
    void update(); // Called each simulation time step
    void triggerFireAlarm();
    void triggerPowerOutage();
    void clearEmergency();

signals:
    void floorButtonPressed(int floor, Direction direction);
    void floorButtonReset(int floor, Direction direction);
    void elevatorAllocated(int elevatorId, int floor, Direction direction);
    void emergencyTriggered(const QString& emergencyType);
    void emergencyCleared();
    void logMessage(const QString& message);

private:
    int m_numFloors;
    int m_numElevators;
    QVector<Elevator*> m_elevators;
    QVector<bool> m_floorButtonsUp; // Changed from QVector<QVector<bool>>
    QVector<bool> m_floorButtonsDown; // Changed from QVector<QVector<bool>>
    QVector<FloorRequest> m_pendingRequests;
    ElevatorAllocationStrategy* m_allocationStrategy;
    bool m_emergencyMode;
    QString m_emergencyType;

    void allocateElevatorToRequest(const FloorRequest& request);
    void handleEmergency();
};

#endif // BUILDING_H 