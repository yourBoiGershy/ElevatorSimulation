#include "floorrequest.h"

FloorRequest::FloorRequest(int floor, Direction direction, int timeStep)
    : m_floor(floor), m_direction(direction), m_timeStep(timeStep), m_handled(false)
{
}

int FloorRequest::getFloor() const
{
    return m_floor;
}

Direction FloorRequest::getDirection() const
{
    return m_direction;
}

int FloorRequest::getTimeStep() const
{
    return m_timeStep;
}

bool FloorRequest::isHandled() const
{
    return m_handled;
}

void FloorRequest::setHandled(bool handled)
{
    m_handled = handled;
} 