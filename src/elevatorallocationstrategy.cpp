#include "elevatorallocationstrategy.h"
#include "elevator.h"
#include <cmath>
#include <algorithm>

// Nearest Elevator Strategy
int NearestElevatorStrategy::allocateElevator(const QVector<Elevator*>& elevators, const FloorRequest& request)
{
    if (elevators.isEmpty()) {
        return -1;
    }

    int nearestElevatorId = -1;
    int shortestDistance = INT_MAX;

    for (Elevator* elevator : elevators) {
        // Skip elevators with safety events
        if (elevator->hasSafetyEvent()) {
            continue;
        }

        int distance = std::abs(elevator->getCurrentFloor() - request.getFloor());
        
        // If elevator is idle or moving in the same direction as the request
        if (elevator->isIdle() || 
            (elevator->getState() == ElevatorState::MOVING_UP && request.getDirection() == Direction::UP) ||
            (elevator->getState() == ElevatorState::MOVING_DOWN && request.getDirection() == Direction::DOWN)) {
            
            if (distance < shortestDistance) {
                shortestDistance = distance;
                nearestElevatorId = elevator->getId();
            }
        }
    }

    // If no suitable elevator found, find any available elevator
    if (nearestElevatorId == -1) {
        for (Elevator* elevator : elevators) {
            if (!elevator->hasSafetyEvent()) {
                int distance = std::abs(elevator->getCurrentFloor() - request.getFloor());
                if (distance < shortestDistance) {
                    shortestDistance = distance;
                    nearestElevatorId = elevator->getId();
                }
            }
        }
    }

    return nearestElevatorId;
}

// Least Busy Elevator Strategy
int LeastBusyElevatorStrategy::allocateElevator(const QVector<Elevator*>& elevators, const FloorRequest& request)
{
    if (elevators.isEmpty()) {
        return -1;
    }

    int leastBusyElevatorId = -1;
    int fewestDestinations = INT_MAX;

    for (Elevator* elevator : elevators) {
        // Skip elevators with safety events
        if (elevator->hasSafetyEvent()) {
            continue;
        }

        int numDestinations = elevator->getDestinations().size();
        
        if (numDestinations < fewestDestinations) {
            fewestDestinations = numDestinations;
            leastBusyElevatorId = elevator->getId();
        }
    }

    return leastBusyElevatorId;
}

// Direction-based Elevator Strategy
int DirectionBasedElevatorStrategy::allocateElevator(const QVector<Elevator*>& elevators, const FloorRequest& request)
{
    if (elevators.isEmpty()) {
        return -1;
    }

    int bestElevatorId = -1;
    int bestScore = INT_MAX;

    for (Elevator* elevator : elevators) {
        // Skip elevators with safety events
        if (elevator->hasSafetyEvent()) {
            continue;
        }

        int score = INT_MAX;
        int distance = std::abs(elevator->getCurrentFloor() - request.getFloor());
        
        // Elevator is idle - good candidate
        if (elevator->isIdle()) {
            score = distance;
        }
        // Elevator is moving in the same direction and will pass the requested floor
        else if ((elevator->getState() == ElevatorState::MOVING_UP && 
                 request.getDirection() == Direction::UP && 
                 elevator->getCurrentFloor() < request.getFloor()) ||
                (elevator->getState() == ElevatorState::MOVING_DOWN && 
                 request.getDirection() == Direction::DOWN && 
                 elevator->getCurrentFloor() > request.getFloor())) {
            score = distance / 2;  // Give priority to elevators already moving in the right direction
        }
        // Elevator is moving but will need to change direction
        else {
            score = distance * 2;  // Penalize elevators that need to change direction
        }
        
        // Add a penalty based on how many destinations the elevator already has
        score += elevator->getDestinations().size() * 5;
        
        if (score < bestScore) {
            bestScore = score;
            bestElevatorId = elevator->getId();
        }
    }

    return bestElevatorId;
} 