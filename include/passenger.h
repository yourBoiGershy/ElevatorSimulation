#ifndef PASSENGER_H
#define PASSENGER_H

#include <QObject>
#include <QVector>
#include "floorrequest.h"

enum class PassengerAction {
    REQUEST_ELEVATOR,
    ENTER_ELEVATOR,
    PRESS_FLOOR_BUTTON,
    PRESS_HELP_BUTTON,
    PRESS_DOOR_OPEN,
    PRESS_DOOR_CLOSE,
    EXIT_ELEVATOR,
    NONE
};

struct PassengerEvent {
    PassengerAction action;
    int timeStep;
    int floor;
    Direction direction;
    int targetFloor;
    int elevatorId;
};

class Passenger : public QObject
{
    Q_OBJECT

public:
    explicit Passenger(int id, int startFloor, QObject *parent = nullptr);
    ~Passenger();

    int getId() const;
    int getCurrentFloor() const;
    int getCurrentElevator() const;
    bool isInElevator() const;
    void addEvent(PassengerAction action, int timeStep, int floor = -1, 
                 Direction direction = Direction::NONE, int targetFloor = -1, int elevatorId = -1);
    PassengerEvent getNextEvent(int currentTimeStep) const;
    bool hasEventsRemaining(int currentTimeStep) const;

public slots:
    void enterElevator(int elevatorId);
    void exitElevator();
    void setCurrentFloor(int floor);
    void executeEvent(const PassengerEvent& event);

signals:
    void requestedElevator(int passengerId, int floor, Direction direction);
    void enteredElevator(int passengerId, int elevatorId);
    void exitedElevator(int passengerId, int elevatorId, int floor);
    void pressedFloorButton(int passengerId, int elevatorId, int floor);
    void pressedHelpButton(int passengerId, int elevatorId);
    void pressedDoorOpen(int passengerId, int elevatorId);
    void pressedDoorClose(int passengerId, int elevatorId);
    void logMessage(const QString& message);

private:
    int m_id;
    int m_currentFloor;
    int m_currentElevator;
    bool m_inElevator;
    QVector<PassengerEvent> m_events;
};

#endif // PASSENGER_H 