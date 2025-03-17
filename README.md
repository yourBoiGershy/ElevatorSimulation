# Elevator Simulation System

This project implements a simulation of an elevator system with multiple elevators, floors, and passengers. The simulation includes various safety features and allows for different elevator allocation strategies.

## Features

- Variable number of passengers, floors, elevators, and allocation strategies
- Simulation time display and control (start, pause, continue, stop)
- Elevator location and state display
- Safety features:
  - Help button with building safety service connection
  - Door obstacle detection
  - Fire alarm response
  - Overload detection
  - Power outage handling

## Building and Running

### Prerequisites

- Qt 5.15 or higher
- C++17 compatible compiler

### Build Instructions

1. Use the provided build script:
   ```bash
   cd ElevatorSimulation
   ./build.sh
   ```

2. Or open the project in Qt Creator:
   - Open Qt Creator
   - Select "Open Project"
   - Navigate to the ElevatorSimulation directory and open ElevatorSimulation.pro
   - Configure the project for your system
   - Build the project

### Running the Application

After building, run the application:

```bash
cd build
./ElevatorSimulation.app/Contents/MacOS/ElevatorSimulation  # On macOS
# OR
./ElevatorSimulation  # On Linux/Windows
```

## Running the Use Cases

The application allows you to set up and run different use case scenarios:

### Basic Setup for All Use Cases

1. Configure the simulation parameters:
   - Set the number of floors (e.g., 5)
   - Set the number of elevators (e.g., 2)
   - Set the number of passengers (e.g., 3)
   - Choose an allocation strategy (e.g., "Nearest Elevator")

### Use Case 1: Basic Elevator Request

1. Add passenger events:
   - Passenger ID: 0
   - Event Type: "Request Elevator"
   - Time Step: 1
   - Floor: 1
   - Direction: UP
   - Click "Add Event"

2. Add more events for the same passenger:
   - Enter Elevator (Time Step: 3)
   - Press Floor Button (Time Step: 4, Target Floor: 3)
   - Exit Elevator (Time Step: 10)

3. Start the simulation and observe the elevator's movement and passenger's actions.

### Use Case 2: Multiple Passengers Using Different Elevators

1. Add events for multiple passengers requesting elevators from different floors and traveling to different destinations.
2. Start the simulation and observe how the elevators are allocated and handle multiple requests.

### Use Case 3: Fire Alarm Safety Scenario

1. Set up a basic passenger journey.
2. Add a fire alarm safety event:
   - Event Type: "Fire Alarm"
   - Time Step: 6 (while elevator is moving)
   - Elevator ID: -1 (for building-wide event)

3. Observe how all elevators move to the safe floor and passengers exit.

### Use Case 4: Help Button Safety Scenario

1. Set up a basic passenger journey.
2. Add a help button press event:
   - Passenger ID: 0
   - Event Type: "Press Help Button"
   - Time Step: 5
   - Elevator ID: 0

3. Observe the safety protocol, including the 911 call simulation if no response is received within 5 seconds.

## Running the Tests

The project includes automated test scenarios that demonstrate the use cases:

```bash
cd ElevatorSimulation
./build_tests.sh
cd build_tests
./tests
```

## Design Documentation

The project includes comprehensive design documentation:

### UML Diagrams

- **Class Diagram**: Located in `docs/UML_Class_Diagram.md`
  - Shows the structure of all classes in the system
  - Includes relationships between classes
  - Shows Qt framework elements used

- **Sequence Diagrams**: Located in `docs/UML_Sequence_Diagrams.md`
  - Normal Use Scenario 1: Passenger Requests Elevator and Travels to Destination
  - Normal Use Scenario 2: Multiple Passengers Using Different Elevators
  - Safety Scenario 1: Fire Alarm
  - Safety Scenario 2: Help Button

- **State Machine Diagrams**: Located in `docs/UML_State_Machines.md`
  - Simulation Controller State Machine
  - Elevator State Machine

### Requirements Traceability

- **Requirements Traceability Matrix**: Located in `docs/Requirements_Traceability_Matrix.md`
  - Maps requirements to use cases, design elements, implementation, and tests
  - Provides complete traceability from requirements to implementation

### Design Decisions

- **Design Decisions Document**: Located in `docs/Design_Decisions.md`
  - Explains architectural choices
  - Details design patterns used
  - Describes safety feature implementation
  - Outlines communication mechanisms
  - Discusses extensibility considerations

## Implementation Details

The system is designed using object-oriented principles and follows the Model-View-Controller pattern:

- **Model**: Classes like `Elevator`, `Building`, `Passenger`, and `FloorRequest`
- **View**: `MainWindow` and its UI components
- **Controller**: `SimulationController` coordinating between model and view

The implementation uses Qt's signal-slot mechanism for communication between components, providing loose coupling and making the system more maintainable and extensible.

## Visual Enhancements

The UI includes visual enhancements for better usability:

- Color-coded elevator states (idle, moving, door opening/closing, emergency)
- Clear floor button indicators with distinct colors for pressed/unpressed states
- Prominent display of safety events
- Detailed log console for tracking all events in the simulation

## Contributors

This project was developed as part of COMP3004 assignment. 