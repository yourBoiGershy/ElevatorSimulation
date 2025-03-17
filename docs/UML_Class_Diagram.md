# UML Class Diagram

```
+------------------+       +------------------+       +------------------+
|    MainWindow    |       |SimulationController|     |     Building     |
+------------------+       +------------------+       +------------------+
| -ui: Ui::MainWindow|     | -m_building: Building*|  | -m_numFloors: int |
| -m_simulationController:| | -m_passengers: QVector<| -m_numElevators: int|
|  SimulationController* | |   Passenger*>     |     | -m_elevators: QVector<|
| -m_elevatorStateLabels:| | -m_safetyMonitor: |     |   Elevator*>     |
|  QVector<QLabel*>  |     |   SafetyMonitor*  |     | -m_floorButtonsUp: |
| -m_elevatorFloorLabels:| | -m_simulationTimer: |   |   QVector<QVector<bool>>|
|  QVector<QLabel*>  |     |   QTimer          |     | -m_floorButtonsDown: |
| -m_floorButtonLabels: |  | -m_currentTimeStep: int| |   QVector<QVector<bool>>|
|  QVector<QLabel*>  |     | -m_state: SimulationState| -m_pendingRequests: |
| -m_activeSafetyLabels: | | -m_simulationSpeed: int| |   QVector<FloorRequest>|
|  QVector<QLabel*>  |     +------------------+     | -m_allocationStrategy: |
+------------------+       | +setupSimulation() |   |   ElevatorAllocationStrategy*|
| +setupUI()       |       | +addPassenger()   |     | -m_emergencyMode: bool|
| +updateElevatorDisplay()| | +addPassengerEvent() | | -m_emergencyType: QString|
| +updateFloorDisplay() |  | +addSafetyEvent() |     +------------------+
| +updateSafetyDisplay() | | +startSimulation() |    | +requestElevator() |
| +updateUIState()  |      | +pauseSimulation() |    | +resetFloorButton() |
| +createElevatorAllocation| +resumeSimulation() |   | +update()        |
|  Strategy()      |       | +stopSimulation() |     | +triggerFireAlarm() |
+------------------+       | +stepSimulation() |     | +triggerPowerOutage() |
                           | +resetSimulation() |    | +clearEmergency() |
                           | +update()         |     +------------------+
                           +------------------+       |
                                   |                  |
                                   |                  |
                                   v                  v
+------------------+       +------------------+       +------------------+
|     Passenger    |       |     Elevator     |       |  SafetyMonitor   |
+------------------+       +------------------+       +------------------+
| -m_id: int       |       | -m_id: int       |       | -m_scheduledEvents: |
| -m_currentFloor: int|    | -m_currentFloor: int|    |   QVector<SafetyEvent>|
| -m_currentElevator: int| | -m_targetFloor: int|     | -m_activeHelpRequests: |
| -m_inElevator: bool|     | -m_totalFloors: int|     |   QVector<int>   |
| -m_events: QVector<|     | -m_state: ElevatorState| | -m_helpResponseTimer: |
|   PassengerEvent> |      | -m_destinations: |      |   QTimer         |
+------------------+       |   QVector<int>   |       | -m_helpResponseTimeoutSeconds: |
| +addEvent()      |       | -m_buttonPressed: |      |   int            |
| +getNextEvent()  |       |   QVector<bool>  |       | -m_buildingEmergencyActive: |
| +hasEventsRemaining() |  | -m_doorTimer: QTimer|    |   bool           |
| +enterElevator() |       | -m_doorOpenTime: int|    | -m_buildingEmergencyType: |
| +exitElevator()  |       | -m_doorHoldOpen: bool|   |   ElevatorSafetyEvent|
| +executeEvent()  |       | -m_overloaded: bool|     +------------------+
+------------------+       | -m_currentSafetyEvent: | | +addSafetyEvent() |
                           |   ElevatorSafetyEvent| | +getEventsForTimeStep() |
                           | -m_doorObstacleCount: | | +hasEventsRemaining() |
                           |   int            |     | +connectToElevator() |
                           | -m_doorObstacleTimer: | | +handleHelpButtonPressed() |
                           |   QTimer         |     | +handleDoorObstacle() |
                           | -m_safeFloor: int|     | +handleFireAlarm() |
                           +------------------+     | +handleElevatorFireAlarm() |
                           | +moveToFloor()   |     | +handleOverload() |
                           | +addDestination() |    | +handlePowerOutage() |
                           | +update()        |     | +checkSafetyEvents() |
                           | +openDoor()      |     | +startHelpResponseTimer() |
                           | +closeDoor()     |     +------------------+
                           | +pressHelpButton() |
                           | +triggerSafetyEvent() |
                           | +clearSafetyEvent() |
                           | +moveToSafeFloor() |
                           | +simulateDoorObstacle() |
                           | +simulateOverload() |
                           +------------------+

+------------------+       +------------------+       +------------------+
|   FloorRequest   |       |ElevatorAllocationStrategy| |   SafetyEvent    |
+------------------+       +------------------+       +------------------+
| -m_floor: int    |       | +allocateElevator() |    | -eventType:     |
| -m_direction: Direction| +------------------+     |   ElevatorSafetyEvent|
| -m_timeStep: int |       |                  |     | -timeStep: int   |
| -m_handled: bool |       |                  |     | -elevatorId: int |
+------------------+       |                  |     +------------------+
| +getFloor()      |       |                  |
| +getDirection()  |       |                  |
| +getTimeStep()   |       |                  |
| +isHandled()     |       |                  |
| +setHandled()    |       |                  |
+------------------+       |                  |
                           v                  v
            +------------------+       +------------------+
            |NearestElevatorStrategy|  |DirectionBasedElevatorStrategy|
            +------------------+       +------------------+
            | +allocateElevator() |    | +allocateElevator() |
            +------------------+       +------------------+
                      |
                      |
                      v
            +------------------+
            |LeastBusyElevatorStrategy|
            +------------------+
            | +allocateElevator() |
            +------------------+
```

## Qt Framework Classes Used

```
+------------------+       +------------------+       +------------------+
|     QObject      |       |    QMainWindow   |       |      QTimer      |
+------------------+       +------------------+       +------------------+
| Base class for all|      | Main application |       | Provides timer   |
| Qt objects       |      | window           |       | functionality    |
+------------------+       +------------------+       +------------------+
        ^                         ^                         ^
        |                         |                         |
+------------------+       +------------------+       +------------------+
|     QWidget      |       |      QLabel      |       |    QTextEdit     |
+------------------+       +------------------+       +------------------+
| Base widget class|       | Display text/image|      | Multi-line text  |
|                  |       |                  |       | editing widget   |
+------------------+       +------------------+       +------------------+
        ^
        |
+------------------+       +------------------+       +------------------+
|    QPushButton   |       |     QSpinBox     |       |    QComboBox     |
+------------------+       +------------------+       +------------------+
| Command button   |       | Numeric input    |       | Drop-down list   |
| widget           |       | widget           |       | widget           |
+------------------+       +------------------+       +------------------+
``` 