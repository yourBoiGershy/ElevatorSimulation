#ifndef FLOORREQUEST_H
#define FLOORREQUEST_H

enum class Direction {
    UP,
    DOWN,
    NONE
};

class FloorRequest
{
public:
    FloorRequest(int floor, Direction direction, int timeStep);
    
    int getFloor() const;
    Direction getDirection() const;
    int getTimeStep() const;
    bool isHandled() const;
    void setHandled(bool handled);
    
private:
    int m_floor;
    Direction m_direction;
    int m_timeStep;
    bool m_handled;
};

#endif // FLOORREQUEST_H 