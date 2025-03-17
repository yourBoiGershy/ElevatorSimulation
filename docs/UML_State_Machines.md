# UML State Machine Diagrams

## Simulation Controller State Machine

```
                                  +----------------+
                                  |                |
                                  |     SETUP      |
                                  |                |
                                  +-------+--------+
                                          |
                                          | startSimulation()
                                          v
                                  +----------------+
                                  |                |
                                  |    RUNNING     +<---------+
                                  |                |          |
                                  +-------+--------+          |
                                          |                   |
                +-------------------------+-------------------+
                |                         |                   |
                | pauseSimulation()       | stopSimulation()  | resumeSimulation()
                v                         v                   |
       +----------------+        +----------------+           |
       |                |        |                |           |
       |     PAUSED     +------->+   COMPLETED    |           |
       |                |        |                |           |
       +-------+--------+        +----------------+           |
               |                                              |
               +----------------------------------------------+
```

## Elevator State Machine

```
                                  +----------------+
                                  |                |
                                  |      IDLE      +<---------+
                                  |                |          |
                                  +-------+--------+          |
                                          |                   |
                +-------------------------+                   |
                |                         |                   |
                | addDestination()        | addDestination()  |
                | (target > current)      | (target < current)|
                v                         v                   |
       +----------------+        +----------------+           |
       |                |        |                |           |
       |   MOVING_UP    |        |  MOVING_DOWN   |           |
       |                |        |                |           |
       +-------+--------+        +-------+--------+           |
               |                         |                    |
               | arrivedAtDestination    | arrivedAtDestination
               v                         v                    |
       +----------------+        +----------------+           |
       |                |        |                |           |
       |  DOOR_OPENING  |        |  DOOR_OPENING  |           |
       |                |        |                |           |
       +-------+--------+        +-------+--------+           |
               |                         |                    |
               | doorTimer expired       | doorTimer expired  |
               | or doorClose pressed    | or doorClose pressed
               v                         v                    |
       +----------------+        +----------------+           |
       |                |        |                |           |
       |  DOOR_CLOSING  |        |  DOOR_CLOSING  |           |
       |                |        |                |           |
       +-------+--------+        +-------+--------+           |
               |                         |                    |
               +-------------------------+--------------------+
                                         |
                                         | Safety Event
                                         v
                                  +----------------+
                                  |                |
                                  |  STOPPED_      |
                                  |  EMERGENCY     |
                                  |                |
                                  +-------+--------+
                                          |
                                          | clearSafetyEvent()
                                          v
                                  +----------------+
                                  |                |
                                  |      IDLE      |
                                  |                |
                                  +----------------+
``` 