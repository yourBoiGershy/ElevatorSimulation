# Requirements Traceability Matrix

| ID | Requirement Description | Use Case(s) | Design Element(s) | Implementation Element(s) | Test |
|----|------------------------|-------------|-------------------|---------------------------|------|
| R1 | Variable number of passengers | All use cases | SimulationController | SimulationController::setupSimulation(), SimulationController::addPassenger() | TestScenarios::testMultiplePassengerRequests |
| R2 | Variable number of floors | All use cases | Building | Building constructor, Building::getNumFloors() | All test scenarios |
| R3 | Variable number of elevators | All use cases | Building | Building constructor, Building::getNumElevators() | All test scenarios |
| R4 | Variable elevator allocation strategy | All use cases | ElevatorAllocationStrategy | NearestElevatorStrategy, LeastBusyElevatorStrategy, DirectionBasedElevatorStrategy | TestScenarios::testBasicElevatorRequest, TestScenarios::testMultiplePassengerRequests |
| R5 | Display simulation time in GUI | All use cases | MainWindow, SimulationController | MainWindow::onTimeStepChanged(), SimulationController::update() | Visual verification |
| R6 | Display elevator location and state | All use cases | MainWindow, Elevator | MainWindow::updateElevatorDisplay(), Elevator::getCurrentFloor(), Elevator::getState() | Visual verification |
| R7 | Elevators move floor by floor (no teleporting) | All use cases | Elevator | Elevator::moveOneStep() | TestScenarios::testBasicElevatorRequest |
| R8 | Up/Down buttons on each floor | Basic elevator request, Multiple passengers | Building | Building::requestElevator(), Building::isFloorButtonPressed() | TestScenarios::testBasicElevatorRequest |
| R9 | Floor buttons inside elevator | Basic elevator request, Multiple passengers | Elevator | Elevator::pressButton(), Elevator::isButtonPressed() | TestScenarios::testBasicElevatorRequest |
| R10 | Door open/close buttons | All use cases | Elevator | Elevator::openDoor(), Elevator::closeDoor() | Visual verification |
| R11 | Help button | Help button safety scenario | Elevator, SafetyMonitor | Elevator::pressHelpButton(), SafetyMonitor::handleHelpButtonPressed() | TestScenarios::testHelpButtonScenario |
| R12 | Door obstacle detection | All use cases | Elevator | Elevator::simulateDoorObstacle() | Visual verification |
| R13 | Fire alarm response | Fire alarm safety scenario | Building, Elevator, SafetyMonitor | Building::triggerFireAlarm(), SafetyMonitor::handleFireAlarm() | TestScenarios::testFireAlarmScenario |
| R14 | Overload detection | All use cases | Elevator | Elevator::simulateOverload() | Visual verification |
| R15 | Power outage handling | All use cases | Building, Elevator | Building::triggerPowerOutage() | Visual verification |
| R16 | Simulation control (start, pause, continue, stop) | All use cases | SimulationController, MainWindow | SimulationController::startSimulation(), pauseSimulation(), resumeSimulation(), stopSimulation() | Visual verification |
| R17 | Log console for events | All use cases | MainWindow | MainWindow::onLogMessage() | Visual verification |
| R18 | Elevator bell when arriving at floor | All use cases | Elevator | Elevator::handleArrival() | Visual verification |
| R19 | Elevator display showing current floor | All use cases | Elevator, MainWindow | Elevator::getCurrentFloor(), MainWindow::updateElevatorDisplay() | Visual verification |
| R20 | Elevator audio system | Safety scenarios | Elevator | Elevator::audioMessage() | Visual verification |
| R21 | 911 emergency call for unresponsive help | Help button safety scenario | SafetyMonitor | SafetyMonitor::startHelpResponseTimer() | TestScenarios::testHelpButtonScenario |
| R22 | Move to safe floor during emergencies | Fire alarm safety scenario | Elevator | Elevator::moveToSafeFloor() | TestScenarios::testFireAlarmScenario | 