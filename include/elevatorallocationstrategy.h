#ifndef ELEVATORALLOCATIONSTRATEGY_H
#define ELEVATORALLOCATIONSTRATEGY_H

#include <QVector>
#include "floorrequest.h"

// Forward declarations
class Elevator;

class ElevatorAllocationStrategy
{
public:
    virtual ~ElevatorAllocationStrategy() = default;
    virtual int allocateElevator(const QVector<Elevator*>& elevators, const FloorRequest& request) = 0;
};

// Nearest Elevator Strategy
class NearestElevatorStrategy : public ElevatorAllocationStrategy
{
public:
    int allocateElevator(const QVector<Elevator*>& elevators, const FloorRequest& request) override;
};

// Least Busy Elevator Strategy
class LeastBusyElevatorStrategy : public ElevatorAllocationStrategy
{
public:
    int allocateElevator(const QVector<Elevator*>& elevators, const FloorRequest& request) override;
};

// Direction-based Elevator Strategy
class DirectionBasedElevatorStrategy : public ElevatorAllocationStrategy
{
public:
    int allocateElevator(const QVector<Elevator*>& elevators, const FloorRequest& request) override;
};

#endif // ELEVATORALLOCATIONSTRATEGY_H 