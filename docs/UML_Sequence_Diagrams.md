# UML Sequence Diagrams

## Normal Use Scenario 1: Passenger Requests Elevator and Travels to Destination

```
Passenger          SimulationController          Building          Elevator          ElevatorAllocationStrategy
   |                       |                        |                  |                       |
   | requestElevator       |                        |                  |                       |
   |---------------------> |                        |                  |                       |
   |                       | requestElevator        |                  |                       |
   |                       |----------------------> |                  |                       |
   |                       |                        | floorButtonPressed|                      |
   |                       |                        |----------------> |                       |
   |                       |                        | allocateElevatorToRequest               |
   |                       |                        |---------------------------------------->|
   |                       |                        |                  |                       |
   |                       |                        |                  | allocateElevator      |
   |                       |                        | <------------------------------------- |
   |                       |                        |                  |                       |
   |                       |                        | addDestination   |                       |
   |                       |                        |----------------> |                       |
   |                       |                        |                  |                       |
   |                       |                        |                  | moveToFloor           |
   |                       |                        |                  | ----------------     |
   |                       |                        |                  |                |     |
   |                       |                        |                  | <---------------     |
   |                       |                        |                  |                       |
   |                       |                        |                  | arrivedAtFloor       |
   |                       |                        | <--------------- |                       |
   |                       |                        |                  |                       |
   |                       |                        |                  | doorOpened           |
   |                       |                        | <--------------- |                       |
   |                       |                        |                  |                       |
   | enterElevator         |                        |                  |                       |
   |---------------------> |                        |                  |                       |
   |                       |                        |                  |                       |
   | pressFloorButton      |                        |                  |                       |
   |---------------------> |                        |                  |                       |
   |                       | pressButton           |                  |                       |
   |                       |------------------------------------------------> |               |
   |                       |                        |                  |                       |
   |                       |                        |                  | addDestination        |
   |                       |                        |                  | ----------------     |
   |                       |                        |                  |                |     |
   |                       |                        |                  | <---------------     |
   |                       |                        |                  |                       |
   |                       |                        |                  | doorClosed           |
   |                       |                        | <--------------- |                       |
   |                       |                        |                  |                       |
   |                       |                        |                  | moveToFloor           |
   |                       |                        |                  | ----------------     |
   |                       |                        |                  |                |     |
   |                       |                        |                  | <---------------     |
   |                       |                        |                  |                       |
   |                       |                        |                  | arrivedAtFloor       |
   |                       |                        | <--------------- |                       |
   |                       |                        |                  |                       |
   |                       |                        |                  | doorOpened           |
   |                       |                        | <--------------- |                       |
   |                       |                        |                  |                       |
   | exitElevator          |                        |                  |                       |
   |---------------------> |                        |                  |                       |
   |                       |                        |                  |                       |
   |                       |                        |                  | doorClosed           |
   |                       |                        | <--------------- |                       |
   |                       |                        |                  |                       |
```

## Normal Use Scenario 2: Multiple Passengers Using Different Elevators

```
Passenger1         Passenger2         SimulationController          Building          Elevator1         Elevator2
   |                   |                       |                        |                  |                  |
   | requestElevator   |                       |                        |                  |                  |
   |-----------------> |                       |                        |                  |                  |
   |                   | requestElevator       |                        |                  |                  |
   |                   |---------------------> |                        |                  |                  |
   |                   |                       | requestElevator        |                  |                  |
   |                   |                       |----------------------> |                  |                  |
   |                   |                       |                        | allocateElevator1|                  |
   |                   |                       |                        |----------------> |                  |
   |                   |                       |                        |                  |                  |
   |                   |                       | requestElevator        |                  |                  |
   |                   |                       |----------------------> |                  |                  |
   |                   |                       |                        | allocateElevator2|                  |
   |                   |                       |                        |---------------------------------> |
   |                   |                       |                        |                  |                  |
   |                   |                       |                        |                  | moveToFloor      |
   |                   |                       |                        |                  | ------------     |
   |                   |                       |                        |                  |            |     |
   |                   |                       |                        |                  | <-----------     |
   |                   |                       |                        |                  |                  |
   |                   |                       |                        |                  |                  | moveToFloor
   |                   |                       |                        |                  |                  | ------------
   |                   |                       |                        |                  |                  |            |
   |                   |                       |                        |                  |                  | <-----------
   |                   |                       |                        |                  |                  |
   |                   |                       |                        |                  | arrivedAtFloor   |
   |                   |                       |                        | <--------------- |                  |
   |                   |                       |                        |                  |                  |
   |                   |                       |                        |                  | doorOpened       |
   |                   |                       |                        | <--------------- |                  |
   |                   |                       |                        |                  |                  |
   | enterElevator     |                       |                        |                  |                  |
   |-----------------> |                       |                        |                  |                  |
   |                   |                       |                        |                  |                  |
   | pressFloorButton  |                       |                        |                  |                  |
   |-----------------> |                       |                        |                  |                  |
   |                   |                       |                        |                  |                  |
   |                   |                       |                        |                  |                  | arrivedAtFloor
   |                   |                       |                        | <---------------------------------- |
   |                   |                       |                        |                  |                  |
   |                   |                       |                        |                  |                  | doorOpened
   |                   |                       |                        | <---------------------------------- |
   |                   |                       |                        |                  |                  |
   |                   | enterElevator         |                        |                  |                  |
   |                   |---------------------> |                        |                  |                  |
   |                   |                       |                        |                  |                  |
   |                   | pressFloorButton      |                        |                  |                  |
   |                   |---------------------> |                        |                  |                  |
   |                   |                       |                        |                  |                  |
   |                   |                       |                        |                  | doorClosed       |
   |                   |                       |                        | <--------------- |                  |
   |                   |                       |                        |                  |                  |
   |                   |                       |                        |                  |                  | doorClosed
   |                   |                       |                        | <---------------------------------- |
   |                   |                       |                        |                  |                  |
   |                   |                       |                        |                  | moveToFloor      |
   |                   |                       |                        |                  | ------------     |
   |                   |                       |                        |                  |            |     |
   |                   |                       |                        |                  | <-----------     |
   |                   |                       |                        |                  |                  |
   |                   |                       |                        |                  |                  | moveToFloor
   |                   |                       |                        |                  |                  | ------------
   |                   |                       |                        |                  |                  |            |
   |                   |                       |                        |                  |                  | <-----------
```

## Safety Scenario 1: Fire Alarm

```
SimulationController          Building          Elevator1         Elevator2         SafetyMonitor
   |                             |                  |                  |                  |
   | checkSafetyEvents           |                  |                  |                  |
   |---------------------------------------------------------> |                  |
   |                             |                  |                  |                  |
   |                             |                  |                  | handleFireAlarm  |
   |                             |                  |                  | <--------------- |
   |                             |                  |                  |                  |
   |                             | triggerFireAlarm |                  |                  |
   |                             | <---------------------------------- |                  |
   |                             |                  |                  |                  |
   |                             | triggerSafetyEvent                  |                  |
   |                             |----------------> |                  |                  |
   |                             |                  |                  |                  |
   |                             | triggerSafetyEvent                  |                  |
   |                             |---------------------------------> |                  |
   |                             |                  |                  |                  |
   |                             |                  | displayMessage   |                  |
   |                             |                  | ------------     |                  |
   |                             |                  |            |     |                  |
   |                             |                  | <-----------     |                  |
   |                             |                  |                  |                  |
   |                             |                  | audioMessage     |                  |
   |                             |                  | ------------     |                  |
   |                             |                  |            |     |                  |
   |                             |                  | <-----------     |                  |
   |                             |                  |                  |                  |
   |                             | moveToSafeFloor  |                  |                  |
   |                             |----------------> |                  |                  |
   |                             |                  |                  |                  |
   |                             | moveToSafeFloor  |                  |                  |
   |                             |---------------------------------> |                  |
   |                             |                  |                  |                  |
   |                             |                  | moveOneStep      |                  |
   |                             |                  | ------------     |                  |
   |                             |                  |            |     |                  |
   |                             |                  | <-----------     |                  |
   |                             |                  |                  |                  |
   |                             |                  |                  | moveOneStep      |
   |                             |                  |                  | ------------     |
   |                             |                  |                  |            |     |
   |                             |                  |                  | <-----------     |
   |                             |                  |                  |                  |
   |                             |                  | arrivedAtFloor   |                  |
   |                             | <--------------- |                  |                  |
   |                             |                  |                  |                  |
   |                             |                  |                  | arrivedAtFloor   |
   |                             | <---------------------------------- |                  |
   |                             |                  |                  |                  |
   |                             |                  | doorOpened       |                  |
   |                             | <--------------- |                  |                  |
   |                             |                  |                  |                  |
   |                             |                  |                  | doorOpened       |
   |                             | <---------------------------------- |                  |
```

## Safety Scenario 2: Help Button

```
Passenger          SimulationController          Elevator          SafetyMonitor
   |                       |                        |                  |
   | pressHelpButton       |                        |                  |
   |---------------------> |                        |                  |
   |                       | pressHelpButton        |                  |
   |                       |----------------------> |                  |
   |                       |                        |                  |
   |                       |                        | triggerSafetyEvent|
   |                       |                        |----------------> |
   |                       |                        |                  |
   |                       |                        |                  | handleHelpButtonPressed
   |                       |                        |                  | ----------------
   |                       |                        |                  |                |
   |                       |                        |                  | <---------------
   |                       |                        |                  |
   |                       |                        |                  | startHelpResponseTimer
   |                       |                        |                  | ----------------
   |                       |                        |                  |                |
   |                       |                        |                  | <---------------
   |                       |                        |                  |
   |                       |                        | displayMessage   |
   |                       |                        | ------------     |
   |                       |                        |            |     |
   |                       |                        | <-----------     |
   |                       |                        |                  |
   |                       |                        | audioMessage     |
   |                       |                        | ------------     |
   |                       |                        |            |     |
   |                       |                        | <-----------     |
   |                       |                        |                  |
   |                       |                        |                  | (No response within 5 seconds)
   |                       |                        |                  |
   |                       |                        |                  | emergency911Called
   |                       |                        |                  | ----------------
   |                       |                        |                  |                |
   |                       |                        |                  | <---------------
   |                       |                        |                  |
   |                       |                        | clearSafetyEvent |
   |                       |                        | <--------------- |
   |                       |                        |                  |
   |                       |                        | displayMessage   |
   |                       |                        | ------------     |
   |                       |                        |            |     |
   |                       |                        | <-----------     |
   |                       |                        |                  |
   |                       |                        | audioMessage     |
   |                       |                        | ------------     |
   |                       |                        |            |     |
   |                       |                        | <-----------     |
``` 