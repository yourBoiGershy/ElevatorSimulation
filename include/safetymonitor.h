#ifndef SAFETYMONITOR_H
#define SAFETYMONITOR_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include <QString>
#include "elevator.h"

struct SafetyEvent {
    ElevatorSafetyEvent eventType;
    int timeStep;
    int elevatorId; // -1 for building-wide events
};

class SafetyMonitor : public QObject
{
    Q_OBJECT

public:
    explicit SafetyMonitor(QObject *parent = nullptr);
    ~SafetyMonitor();

    void addSafetyEvent(ElevatorSafetyEvent eventType, int timeStep, int elevatorId = -1);
    QVector<SafetyEvent> getEventsForTimeStep(int timeStep) const;
    bool hasEventsRemaining(int currentTimeStep) const;
    void connectToElevator(Elevator* elevator);

public slots:
    void handleHelpButtonPressed(int elevatorId);
    void handleDoorObstacle(int elevatorId);
    void handleFireAlarm();
    void handleElevatorFireAlarm(int elevatorId);
    void handleOverload(int elevatorId);
    void handlePowerOutage();
    void checkSafetyEvents(int currentTimeStep);
    void startHelpResponseTimer(int elevatorId);

signals:
    void safetyEventTriggered(ElevatorSafetyEvent eventType, int elevatorId);
    void buildingSafetyEventTriggered(ElevatorSafetyEvent eventType);
    void safetyEventResolved(int elevatorId);
    void buildingSafetyEventResolved();
    void emergency911Called(int elevatorId);
    void logMessage(const QString& message);
    void displayMessage(int elevatorId, const QString& message);
    void audioMessage(int elevatorId, const QString& message);

private:
    QVector<SafetyEvent> m_scheduledEvents;
    QVector<int> m_activeHelpRequests;
    QTimer m_helpResponseTimer;
    int m_helpResponseTimeoutSeconds;
    bool m_buildingEmergencyActive;
    ElevatorSafetyEvent m_buildingEmergencyType;

    void handleBuildingWideEvent(ElevatorSafetyEvent eventType);
    void handleElevatorEvent(ElevatorSafetyEvent eventType, int elevatorId);
};

#endif // SAFETYMONITOR_H 