#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QTimer>

enum class ElevatorState {
    IDLE,
    MOVING_UP,
    MOVING_DOWN,
    DOOR_OPENING,
    DOOR_OPEN,
    DOOR_CLOSING,
    STOPPED_EMERGENCY
};

enum class ElevatorSafetyEvent {
    NONE,
    HELP_BUTTON_PRESSED,
    DOOR_OBSTACLE,
    FIRE_ALARM,
    OVERLOAD,
    POWER_OUT
};

class Elevator : public QObject
{
    Q_OBJECT

public:
    explicit Elevator(int id, int totalFloors, QObject *parent = nullptr);
    ~Elevator();

    int getId() const;
    int getCurrentFloor() const;
    ElevatorState getState() const;
    QString getStateString() const;
    bool isIdle() const;
    bool isDoorOpen() const;
    bool hasDestination(int floor) const;
    const QVector<int>& getDestinations() const;
    bool isButtonPressed(int floor) const;
    void pressButton(int floor);
    void resetButton(int floor);
    bool isOverloaded() const;
    bool hasSafetyEvent() const;
    ElevatorSafetyEvent getCurrentSafetyEvent() const;

public slots:
    void moveToFloor(int floor);
    void addDestination(int floor);
    void update(); // Called each simulation time step
    void openDoor();
    void closeDoor();
    void pressHelpButton();
    void triggerSafetyEvent(ElevatorSafetyEvent event);
    void clearSafetyEvent();
    void moveToSafeFloor();
    void simulateDoorObstacle();
    void simulateOverload();

signals:
    void arrivedAtFloor(int elevatorId, int floor);
    void doorOpened(int elevatorId);
    void doorClosed(int elevatorId);
    void stateChanged(int elevatorId, ElevatorState state);
    void destinationsChanged(int elevatorId, const QVector<int>& destinations);
    void helpButtonPressed(int elevatorId);
    void safetyEventTriggered(int elevatorId, ElevatorSafetyEvent event);
    void safetyEventCleared(int elevatorId);
    void displayMessage(int elevatorId, const QString& message);
    void audioMessage(int elevatorId, const QString& message);

private:
    int m_id;
    int m_currentFloor;
    int m_targetFloor;
    int m_totalFloors;
    ElevatorState m_state;
    QVector<int> m_destinations;
    QVector<bool> m_buttonPressed;
    QTimer m_doorTimer;
    int m_doorOpenTime;
    bool m_doorHoldOpen;
    bool m_overloaded;
    ElevatorSafetyEvent m_currentSafetyEvent;
    int m_doorObstacleCount;
    QTimer m_doorObstacleTimer;
    int m_safeFloor;

    void sortDestinations();
    int getNextDestination() const;
    void moveOneStep();
    void handleArrival();
    void handleSafetyEvent();
};

#endif // ELEVATOR_H 