# Design Decisions

## Architecture Overview

The Elevator Simulation System is designed using the Model-View-Controller (MVC) architectural pattern:

- **Model**: Represented by classes like `Elevator`, `Building`, `Passenger`, and `FloorRequest` that encapsulate the core business logic and data.
- **View**: Implemented in the `MainWindow` class and its UI components, responsible for displaying the simulation state to the user.
- **Controller**: The `SimulationController` class acts as the central controller, coordinating between the model and view components.

## Design Patterns

Several design patterns have been employed in the implementation:

1. **Strategy Pattern**: Used for elevator allocation strategies through the `ElevatorAllocationStrategy` abstract class and its concrete implementations (`NearestElevatorStrategy`, `LeastBusyElevatorStrategy`, and `DirectionBasedElevatorStrategy`). This allows for different elevator selection algorithms to be swapped at runtime.

2. **Observer Pattern**: Implemented using Qt's signal-slot mechanism to enable loose coupling between components. For example, elevators emit signals when their state changes, and interested components (like the building or safety monitor) can connect to these signals without direct dependencies.

3. **State Pattern**: Used for managing the states of both the simulation controller and elevators. Each state has specific behaviors and transitions, as shown in the state machine diagrams.

4. **Facade Pattern**: The `SimulationController` acts as a facade, providing a simplified interface to the complex subsystem of elevators, passengers, and safety features.

## Safety Features Implementation

Safety features are implemented through a dedicated `SafetyMonitor` class that centralizes safety-related logic:

1. **Help Button**: When pressed, connects to building safety service with a timeout mechanism that calls 911 if no response is received within 5 seconds.

2. **Door Obstacles**: Implemented with a counter that tracks repeated obstacles and triggers a safety event if the threshold is exceeded.

3. **Fire Alarm**: Can be triggered building-wide or for a specific elevator, causing all affected elevators to move to a safe floor.

4. **Overload Detection**: Prevents elevator movement until the load is reduced.

5. **Power Outage**: Uses backup power to move all elevators to a safe floor.

## Communication Mechanism

The system uses Qt's signal-slot mechanism extensively for communication between components:

- Elevators emit signals when their state changes, doors open/close, or they arrive at a floor.
- Passengers emit signals when they request elevators, press buttons, or enter/exit elevators.
- The safety monitor emits signals when safety events are triggered or resolved.
- The simulation controller emits signals to update the UI when the simulation state changes.

This approach allows for loose coupling between components and makes the system more maintainable and extensible.

## Extensibility Considerations

The system is designed to be extensible in several ways:

1. **Variable Configuration**: The number of floors, elevators, and passengers can be configured at runtime.

2. **Pluggable Strategies**: New elevator allocation strategies can be added by implementing the `ElevatorAllocationStrategy` interface.

3. **Event-Driven Architecture**: The event-driven nature of the system (using signals and slots) makes it easy to add new event types or handlers.

4. **Modular Components**: Each major component (elevator, building, passenger, safety monitor) is implemented as a separate class with clear responsibilities, making it easier to modify or extend individual parts of the system. 