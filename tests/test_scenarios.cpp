#include <QTest>
#include <QSignalSpy>
#include "../include/simulationcontroller.h"
#include "../include/elevator.h"
#include "../include/building.h"
#include "../include/passenger.h"
#include "../include/safetymonitor.h"
#include "../include/elevatorallocationstrategy.h"

class TestScenarios : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    
    // Normal use scenarios
    void testBasicElevatorRequest();
    void testMultiplePassengerRequests();
    
    // Safety scenarios
    void testFireAlarmScenario();
    void testHelpButtonScenario();

private:
    SimulationController* m_controller;
};

void TestScenarios::initTestCase()
{
    m_controller = new SimulationController();
}

void TestScenarios::cleanupTestCase()
{
    delete m_controller;
}

void TestScenarios::testBasicElevatorRequest()
{
    // Setup simulation with 5 floors, 2 elevators, 3 passengers
    m_controller->setupSimulation(5, 2, 3);
    m_controller->setElevatorAllocationStrategy(new NearestElevatorStrategy());
    
    // Create a basic scenario: passenger 0 requests elevator at floor 1 going up
    m_controller->addPassengerEvent(0, PassengerAction::REQUEST_ELEVATOR, 1, 1, Direction::UP);
    
    // Passenger enters elevator 0 when it arrives
    m_controller->addPassengerEvent(0, PassengerAction::ENTER_ELEVATOR, 2, 1, Direction::NONE, -1, 0);
    
    // Passenger presses button for floor 3
    m_controller->addPassengerEvent(0, PassengerAction::PRESS_FLOOR_BUTTON, 3, -1, Direction::NONE, 3, 0);
    
    // Passenger exits at floor 3
    m_controller->addPassengerEvent(0, PassengerAction::EXIT_ELEVATOR, 10, -1, Direction::NONE, -1, 0);
    
    // Start simulation
    QSignalSpy completedSpy(m_controller, SIGNAL(simulationCompleted()));
    m_controller->startSimulation();
    
    // Run simulation until completion or timeout
    QTest::qWait(5000);
    
    // Verify simulation completed
    QVERIFY(completedSpy.count() > 0 || m_controller->getState() == SimulationState::COMPLETED);
    
    // Verify elevator returned to idle state
    QVERIFY(m_controller->getBuilding()->getElevator(0)->isIdle());
    
    // Reset for next test
    m_controller->resetSimulation();
}

void TestScenarios::testMultiplePassengerRequests()
{
    // Setup simulation with 5 floors, 2 elevators, 3 passengers
    m_controller->setupSimulation(5, 2, 3);
    m_controller->setElevatorAllocationStrategy(new DirectionBasedElevatorStrategy());
    
    // Passenger 0 requests elevator at floor 1 going up
    m_controller->addPassengerEvent(0, PassengerAction::REQUEST_ELEVATOR, 1, 1, Direction::UP);
    
    // Passenger 1 requests elevator at floor 4 going down
    m_controller->addPassengerEvent(1, PassengerAction::REQUEST_ELEVATOR, 2, 4, Direction::DOWN);
    
    // Passenger 2 requests elevator at floor 2 going up
    m_controller->addPassengerEvent(2, PassengerAction::REQUEST_ELEVATOR, 3, 2, Direction::UP);
    
    // Passengers enter elevators and press buttons
    m_controller->addPassengerEvent(0, PassengerAction::ENTER_ELEVATOR, 4, -1, Direction::NONE, -1, 0);
    m_controller->addPassengerEvent(0, PassengerAction::PRESS_FLOOR_BUTTON, 5, -1, Direction::NONE, 5, 0);
    
    m_controller->addPassengerEvent(1, PassengerAction::ENTER_ELEVATOR, 6, -1, Direction::NONE, -1, 1);
    m_controller->addPassengerEvent(1, PassengerAction::PRESS_FLOOR_BUTTON, 7, -1, Direction::NONE, 1, 1);
    
    m_controller->addPassengerEvent(2, PassengerAction::ENTER_ELEVATOR, 8, -1, Direction::NONE, -1, 0);
    m_controller->addPassengerEvent(2, PassengerAction::PRESS_FLOOR_BUTTON, 9, -1, Direction::NONE, 3, 0);
    
    // Passengers exit at their destinations
    m_controller->addPassengerEvent(0, PassengerAction::EXIT_ELEVATOR, 15, -1, Direction::NONE, -1, 0);
    m_controller->addPassengerEvent(1, PassengerAction::EXIT_ELEVATOR, 20, -1, Direction::NONE, -1, 1);
    m_controller->addPassengerEvent(2, PassengerAction::EXIT_ELEVATOR, 25, -1, Direction::NONE, -1, 0);
    
    // Start simulation
    QSignalSpy completedSpy(m_controller, SIGNAL(simulationCompleted()));
    m_controller->startSimulation();
    
    // Run simulation until completion or timeout
    QTest::qWait(10000);
    
    // Verify simulation completed
    QVERIFY(completedSpy.count() > 0 || m_controller->getState() == SimulationState::COMPLETED);
    
    // Verify elevators returned to idle state
    QVERIFY(m_controller->getBuilding()->getElevator(0)->isIdle());
    QVERIFY(m_controller->getBuilding()->getElevator(1)->isIdle());
    
    // Reset for next test
    m_controller->resetSimulation();
}

void TestScenarios::testFireAlarmScenario()
{
    // Setup simulation with 5 floors, 2 elevators, 3 passengers
    m_controller->setupSimulation(5, 2, 3);
    m_controller->setElevatorAllocationStrategy(new NearestElevatorStrategy());
    
    // Passenger 0 requests elevator at floor 1 going up
    m_controller->addPassengerEvent(0, PassengerAction::REQUEST_ELEVATOR, 1, 1, Direction::UP);
    
    // Passenger enters elevator 0 when it arrives
    m_controller->addPassengerEvent(0, PassengerAction::ENTER_ELEVATOR, 2, 1, Direction::NONE, -1, 0);
    
    // Passenger presses button for floor 5
    m_controller->addPassengerEvent(0, PassengerAction::PRESS_FLOOR_BUTTON, 3, -1, Direction::NONE, 5, 0);
    
    // Fire alarm is triggered while elevator is moving
    m_controller->addSafetyEvent(ElevatorSafetyEvent::FIRE_ALARM, 5, -1);
    
    // Passenger exits at safe floor (floor 1)
    m_controller->addPassengerEvent(0, PassengerAction::EXIT_ELEVATOR, 15, -1, Direction::NONE, -1, 0);
    
    // Start simulation
    QSignalSpy completedSpy(m_controller, SIGNAL(simulationCompleted()));
    m_controller->startSimulation();
    
    // Run simulation until completion or timeout
    QTest::qWait(10000);
    
    // Verify simulation completed
    QVERIFY(completedSpy.count() > 0 || m_controller->getState() == SimulationState::COMPLETED);
    
    // Verify elevators returned to safe floor (floor 1)
    QCOMPARE(m_controller->getBuilding()->getElevator(0)->getCurrentFloor(), 1);
    QCOMPARE(m_controller->getBuilding()->getElevator(1)->getCurrentFloor(), 1);
    
    // Reset for next test
    m_controller->resetSimulation();
}

void TestScenarios::testHelpButtonScenario()
{
    // Setup simulation with 5 floors, 2 elevators, 3 passengers
    m_controller->setupSimulation(5, 2, 3);
    m_controller->setElevatorAllocationStrategy(new NearestElevatorStrategy());
    
    // Passenger 0 requests elevator at floor 1 going up
    m_controller->addPassengerEvent(0, PassengerAction::REQUEST_ELEVATOR, 1, 1, Direction::UP);
    
    // Passenger enters elevator 0 when it arrives
    m_controller->addPassengerEvent(0, PassengerAction::ENTER_ELEVATOR, 2, 1, Direction::NONE, -1, 0);
    
    // Passenger presses button for floor 3
    m_controller->addPassengerEvent(0, PassengerAction::PRESS_FLOOR_BUTTON, 3, -1, Direction::NONE, 3, 0);
    
    // Passenger presses help button
    m_controller->addPassengerEvent(0, PassengerAction::PRESS_HELP_BUTTON, 5, -1, Direction::NONE, -1, 0);
    
    // Simulate building safety service response after 3 seconds
    QTimer::singleShot(3000, [this]() {
        if (m_controller->getSafetyMonitor()) {
            m_controller->getSafetyMonitor()->startHelpResponseTimer(0);
        }
    });
    
    // Passenger exits at floor 3 after help is resolved
    m_controller->addPassengerEvent(0, PassengerAction::EXIT_ELEVATOR, 15, -1, Direction::NONE, -1, 0);
    
    // Start simulation
    QSignalSpy completedSpy(m_controller, SIGNAL(simulationCompleted()));
    m_controller->startSimulation();
    
    // Run simulation until completion or timeout
    QTest::qWait(10000);
    
    // Verify simulation completed
    QVERIFY(completedSpy.count() > 0 || m_controller->getState() == SimulationState::COMPLETED);
    
    // Reset for next test
    m_controller->resetSimulation();
}

QTEST_MAIN(TestScenarios)
#include "test_scenarios.moc" 