#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFrame>
#include <QMessageBox>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_simulationController(new SimulationController(this))
{
    ui->setupUi(this);
    
    // Initialize random seed
    srand(QTime::currentTime().msec());
    
    // Setup UI components
    setupUI();
    
    // Connect simulation controller signals
    connect(m_simulationController, &SimulationController::simulationStarted, this, &MainWindow::onSimulationStarted);
    connect(m_simulationController, &SimulationController::simulationPaused, this, &MainWindow::onSimulationPaused);
    connect(m_simulationController, &SimulationController::simulationResumed, this, &MainWindow::onSimulationResumed);
    connect(m_simulationController, &SimulationController::simulationStopped, this, &MainWindow::onSimulationStopped);
    connect(m_simulationController, &SimulationController::simulationReset, this, &MainWindow::onSimulationReset);
    connect(m_simulationController, &SimulationController::simulationCompleted, this, &MainWindow::onSimulationCompleted);
    connect(m_simulationController, &SimulationController::timeStepChanged, this, &MainWindow::onTimeStepChanged);
    connect(m_simulationController, &SimulationController::stateChanged, this, &MainWindow::onStateChanged);
    connect(m_simulationController, &SimulationController::logMessage, this, &MainWindow::onLogMessage);
    
    // Connect UI signals
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
    connect(ui->pauseButton, &QPushButton::clicked, this, &MainWindow::onPauseButtonClicked);
    connect(ui->resumeButton, &QPushButton::clicked, this, &MainWindow::onResumeButtonClicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::onStopButtonClicked);
    connect(ui->stepButton, &QPushButton::clicked, this, &MainWindow::onStepButtonClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetButtonClicked);
    connect(ui->addPassengerEventButton, &QPushButton::clicked, this, &MainWindow::onAddPassengerEventButtonClicked);
    connect(ui->addSafetyEventButton, &QPushButton::clicked, this, &MainWindow::onAddSafetyEventButtonClicked);
    connect(ui->strategyComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onStrategyComboBoxChanged);
    
    // Connect menu actions
    connect(ui->actionExit, &QAction::triggered, this, &QMainWindow::close);
    connect(ui->actionAbout, &QAction::triggered, this, [this]() {
        QMessageBox::about(this, "About Elevator Simulation",
                          "Elevator Simulation System\n\n"
                          "A simulation of an elevator system with multiple elevators, floors, and passengers.\n"
                          "Includes various safety features and different elevator allocation strategies.");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    setupSimulationControls();
    setupElevatorDisplay();
    setupFloorDisplay();
    setupPassengerControls();
    setupSafetyControls();
    setupLogConsole();
}

void MainWindow::setupSimulationControls()
{
    // Set maximum values based on UI limits
    ui->floorsSpinBox->setMaximum(20);
    ui->elevatorsSpinBox->setMaximum(10);
    ui->passengersSpinBox->setMaximum(20);
    
    // Set initial values
    ui->floorsSpinBox->setValue(5);
    ui->elevatorsSpinBox->setValue(2);
    ui->passengersSpinBox->setValue(3);
    ui->strategyComboBox->setCurrentIndex(0);
}

void MainWindow::setupElevatorDisplay()
{
    // Will be created dynamically when simulation starts
}

void MainWindow::setupFloorDisplay()
{
    // Will be created dynamically when simulation starts
}

void MainWindow::setupPassengerControls()
{
    // Set initial values
    ui->passengerIdSpinBox->setValue(0);
    ui->eventTypeComboBox->setCurrentIndex(0);
    ui->timeStepEventSpinBox->setValue(1);
    ui->floorSpinBox->setValue(1);
    ui->directionComboBox->setCurrentIndex(0);
    ui->targetFloorSpinBox->setValue(1);
    ui->elevatorIdSpinBox->setValue(0);
}

void MainWindow::setupSafetyControls()
{
    // Set initial values
    ui->safetyEventTypeComboBox->setCurrentIndex(0);
    ui->safetyTimeStepSpinBox->setValue(1);
    ui->safetyElevatorIdSpinBox->setValue(-1);
}

void MainWindow::setupLogConsole()
{
    ui->logTextEdit->clear();
    ui->logTextEdit->setFont(QFont("Courier New", 10));
    onLogMessage("Elevator Simulation System initialized.");
}

void MainWindow::updateElevatorDisplay()
{
    if (!m_simulationController->getBuilding()) {
        return;
    }
    
    // Update elevator state and floor labels
    for (int i = 0; i < m_simulationController->getBuilding()->getNumElevators(); ++i) {
        Elevator* elevator = m_simulationController->getBuilding()->getElevator(i);
        if (elevator && i < m_elevatorStateLabels.size() && i < m_elevatorFloorLabels.size()) {
            m_elevatorStateLabels[i]->setText(elevator->getStateString());
            m_elevatorFloorLabels[i]->setText(QString::number(elevator->getCurrentFloor()));
            
            // Set background color based on state - ENHANCED COLORS
            QString stateColor;
            switch (elevator->getState()) {
                case ElevatorState::IDLE:
                    stateColor = "background-color: #D3D3D3; color: black; font-weight: bold;"; // Light gray
                    break;
                case ElevatorState::MOVING_UP:
                    stateColor = "background-color: #90EE90; color: black; font-weight: bold;"; // Light green
                    break;
                case ElevatorState::MOVING_DOWN:
                    stateColor = "background-color: #ADD8E6; color: black; font-weight: bold;"; // Light blue
                    break;
                case ElevatorState::DOOR_OPENING:
                case ElevatorState::DOOR_OPEN:
                    stateColor = "background-color: #FFFACD; color: black; font-weight: bold;"; // Light yellow
                    break;
                case ElevatorState::DOOR_CLOSING:
                    stateColor = "background-color: #FFE4B5; color: black; font-weight: bold;"; // Moccasin
                    break;
                case ElevatorState::STOPPED_EMERGENCY:
                    stateColor = "background-color: #FF6347; color: white; font-weight: bold;"; // Tomato red
                    break;
                default:
                    stateColor = "background-color: white; color: black;";
            }
            m_elevatorStateLabels[i]->setStyleSheet(stateColor);
            
            // Make floor number more prominent
            m_elevatorFloorLabels[i]->setStyleSheet("background-color: #F0F8FF; color: black; font-weight: bold; font-size: 14px; border: 1px solid #A9A9A9;");
            
            // Update safety status
            if (elevator->hasSafetyEvent()) {
                QString safetyText;
                QString safetyStyle;
                switch (elevator->getCurrentSafetyEvent()) {
                    case ElevatorSafetyEvent::HELP_BUTTON_PRESSED:
                        safetyText = "HELP";
                        safetyStyle = "background-color: #FF4500; color: white; font-weight: bold;"; // OrangeRed
                        break;
                    case ElevatorSafetyEvent::DOOR_OBSTACLE:
                        safetyText = "DOOR OBSTACLE";
                        safetyStyle = "background-color: #FFA500; color: black; font-weight: bold;"; // Orange
                        break;
                    case ElevatorSafetyEvent::FIRE_ALARM:
                        safetyText = "FIRE ALARM";
                        safetyStyle = "background-color: #FF0000; color: white; font-weight: bold;"; // Red
                        break;
                    case ElevatorSafetyEvent::OVERLOAD:
                        safetyText = "OVERLOAD";
                        safetyStyle = "background-color: #8B0000; color: white; font-weight: bold;"; // DarkRed
                        break;
                    case ElevatorSafetyEvent::POWER_OUT:
                        safetyText = "POWER OUT";
                        safetyStyle = "background-color: #4B0082; color: white; font-weight: bold;"; // Indigo
                        break;
                    default:
                        safetyText = "SAFETY EVENT";
                        safetyStyle = "background-color: red; color: white; font-weight: bold;";
                }
                m_activeSafetyLabels[i]->setText(safetyText);
                m_activeSafetyLabels[i]->setStyleSheet(safetyStyle);
            } else {
                m_activeSafetyLabels[i]->setText("OK");
                m_activeSafetyLabels[i]->setStyleSheet("background-color: #008000; color: white; font-weight: bold;"); // Green
            }
        }
    }
}

void MainWindow::updateFloorDisplay()
{
    if (!m_simulationController->getBuilding()) {
        return;
    }
    
    // Update floor button labels
    for (int i = 0; i < m_simulationController->getBuilding()->getNumFloors(); ++i) {
        int floor = i + 1;
        if (i < m_floorButtonLabels.size()) {
            bool upPressed = m_simulationController->getBuilding()->isFloorButtonPressed(floor, Direction::UP);
            bool downPressed = m_simulationController->getBuilding()->isFloorButtonPressed(floor, Direction::DOWN);
            
            QString upStatus = upPressed ? "UP: ⬤" : "UP: ○";
            QString downStatus = downPressed ? "DOWN: ⬤" : "DOWN: ○";
            
            // Create a more visual representation with colored text
            QString labelText = QString("Floor %1:   %2   %3")
                .arg(floor)
                .arg(upStatus)
                .arg(downStatus);
            
            m_floorButtonLabels[i]->setText(labelText);
            
            // Set text color based on button status
            QString styleSheet = "padding: 5px; font-weight: bold;";
            
            if (upPressed && downPressed) {
                styleSheet += "background-color: #FFFFE0;"; // Light yellow
            } else if (upPressed) {
                styleSheet += "background-color: #E6F2FF;"; // Light blue
            } else if (downPressed) {
                styleSheet += "background-color: #FFE6E6;"; // Light red
            } else {
                styleSheet += "background-color: #F8F8FF;"; // GhostWhite
            }
            
            m_floorButtonLabels[i]->setStyleSheet(styleSheet);
        }
    }
}

void MainWindow::updateSafetyDisplay()
{
    // Already handled in updateElevatorDisplay
}

void MainWindow::updateUIState()
{
    SimulationState state = m_simulationController->getState();
    
    // Update button states based on simulation state
    ui->startButton->setEnabled(state == SimulationState::SETUP || state == SimulationState::COMPLETED);
    ui->pauseButton->setEnabled(state == SimulationState::RUNNING);
    ui->resumeButton->setEnabled(state == SimulationState::PAUSED);
    ui->stepButton->setEnabled(state == SimulationState::PAUSED);
    ui->stopButton->setEnabled(state == SimulationState::RUNNING || state == SimulationState::PAUSED);
    ui->resetButton->setEnabled(state == SimulationState::PAUSED || state == SimulationState::COMPLETED);
    
    // Update setup controls
    bool setupEnabled = (state == SimulationState::SETUP);
    ui->floorsSpinBox->setEnabled(setupEnabled);
    ui->elevatorsSpinBox->setEnabled(setupEnabled);
    ui->passengersSpinBox->setEnabled(setupEnabled);
    ui->strategyComboBox->setEnabled(setupEnabled);
    
    // Update event controls
    bool eventsEnabled = (state == SimulationState::SETUP);
    ui->passengerEventsGroupBox->setEnabled(eventsEnabled);
    ui->safetyEventsGroupBox->setEnabled(eventsEnabled);
    
    // Update state and time step labels
    ui->stateLabel->setText(QString("State: %1").arg(m_simulationController->getStateString()));
    ui->timeStepLabel->setText(QString("Time Step: %1").arg(m_simulationController->getCurrentTimeStep()));
    
    // Update displays
    if (state != SimulationState::SETUP) {
        updateElevatorDisplay();
        updateFloorDisplay();
        updateSafetyDisplay();
    }
}

void MainWindow::createElevatorAllocationStrategy()
{
    ElevatorAllocationStrategy* strategy = nullptr;
    
    switch (ui->strategyComboBox->currentIndex()) {
        case 0:
            strategy = new NearestElevatorStrategy();
            break;
        case 1:
            strategy = new LeastBusyElevatorStrategy();
            break;
        case 2:
            strategy = new DirectionBasedElevatorStrategy();
            break;
        default:
            strategy = new NearestElevatorStrategy();
    }
    
    m_simulationController->setElevatorAllocationStrategy(strategy);
}

void MainWindow::onStartButtonClicked()
{
    // Get simulation parameters
    int numFloors = ui->floorsSpinBox->value();
    int numElevators = ui->elevatorsSpinBox->value();
    int numPassengers = ui->passengersSpinBox->value();
    
    // Setup simulation
    m_simulationController->setupSimulation(numFloors, numElevators, numPassengers);
    
    // Create elevator allocation strategy
    createElevatorAllocationStrategy();
    
    // Create building display
    QLayoutItem* child;
    while ((child = ui->buildingLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    
    // Create elevator display
    m_elevatorStateLabels.clear();
    m_elevatorFloorLabels.clear();
    m_activeSafetyLabels.clear();
    
    QGridLayout* elevatorLayout = new QGridLayout();
    
    // Create header with better styling
    QLabel* headerElevator = new QLabel("Elevator", this);
    QLabel* headerState = new QLabel("State", this);
    QLabel* headerFloor = new QLabel("Floor", this);
    QLabel* headerSafety = new QLabel("Safety", this);
    
    // Style headers
    QString headerStyle = "background-color: #4682B4; color: white; font-weight: bold; padding: 5px;";
    headerElevator->setStyleSheet(headerStyle);
    headerState->setStyleSheet(headerStyle);
    headerFloor->setStyleSheet(headerStyle);
    headerSafety->setStyleSheet(headerStyle);
    
    elevatorLayout->addWidget(headerElevator, 0, 0);
    elevatorLayout->addWidget(headerState, 0, 1);
    elevatorLayout->addWidget(headerFloor, 0, 2);
    elevatorLayout->addWidget(headerSafety, 0, 3);
    
    for (int i = 0; i < numElevators; ++i) {
        QLabel* elevatorLabel = new QLabel(QString("Elevator %1").arg(i), this);
        QLabel* stateLabel = new QLabel("Idle", this);
        QLabel* floorLabel = new QLabel("1", this);
        QLabel* safetyLabel = new QLabel("OK", this);
        
        // Style elevator row
        elevatorLabel->setStyleSheet("background-color: #E6E6FA; font-weight: bold; padding: 5px;"); // Lavender
        
        stateLabel->setAlignment(Qt::AlignCenter);
        floorLabel->setAlignment(Qt::AlignCenter);
        safetyLabel->setAlignment(Qt::AlignCenter);
        
        stateLabel->setStyleSheet("background-color: #D3D3D3; color: black; font-weight: bold; padding: 5px;"); // Light gray
        floorLabel->setStyleSheet("background-color: #F0F8FF; color: black; font-weight: bold; font-size: 14px; padding: 5px; border: 1px solid #A9A9A9;"); // AliceBlue
        safetyLabel->setStyleSheet("background-color: #008000; color: white; font-weight: bold; padding: 5px;"); // Green
        
        elevatorLayout->addWidget(elevatorLabel, i + 1, 0);
        elevatorLayout->addWidget(stateLabel, i + 1, 1);
        elevatorLayout->addWidget(floorLabel, i + 1, 2);
        elevatorLayout->addWidget(safetyLabel, i + 1, 3);
        
        m_elevatorStateLabels.append(stateLabel);
        m_elevatorFloorLabels.append(floorLabel);
        m_activeSafetyLabels.append(safetyLabel);
    }
    
    // Set column stretch to make the display more balanced
    elevatorLayout->setColumnStretch(0, 1);
    elevatorLayout->setColumnStretch(1, 2);
    elevatorLayout->setColumnStretch(2, 1);
    elevatorLayout->setColumnStretch(3, 2);
    
    QFrame* elevatorFrame = new QFrame(this);
    elevatorFrame->setLayout(elevatorLayout);
    elevatorFrame->setFrameShape(QFrame::Box);
    elevatorFrame->setStyleSheet("border: 2px solid #4682B4;"); // SteelBlue border
    ui->buildingLayout->addWidget(elevatorFrame);
    
    // Create floor display
    m_floorButtonLabels.clear();
    
    QVBoxLayout* floorLayout = new QVBoxLayout();
    
    // Add header for floor display
    QLabel* floorHeader = new QLabel("Floor Buttons", this);
    floorHeader->setStyleSheet("background-color: #4682B4; color: white; font-weight: bold; padding: 5px;");
    floorLayout->addWidget(floorHeader);
    
    for (int i = numFloors; i >= 1; --i) {
        QLabel* floorLabel = new QLabel(this);
        floorLabel->setStyleSheet("background-color: #F8F8FF; padding: 5px;"); // GhostWhite
        floorLabel->setMinimumHeight(30);
        floorLayout->addWidget(floorLabel);
        
        // Store in reverse order (top floor first)
        m_floorButtonLabels.prepend(floorLabel);
    }
    
    QFrame* floorFrame = new QFrame(this);
    floorFrame->setLayout(floorLayout);
    floorFrame->setFrameShape(QFrame::Box);
    floorFrame->setStyleSheet("border: 2px solid #4682B4;"); // SteelBlue border
    ui->buildingLayout->addWidget(floorFrame);
    
    // Start simulation
    m_simulationController->startSimulation();
}

void MainWindow::onPauseButtonClicked()
{
    m_simulationController->pauseSimulation();
}

void MainWindow::onResumeButtonClicked()
{
    m_simulationController->resumeSimulation();
}

void MainWindow::onStopButtonClicked()
{
    m_simulationController->stopSimulation();
}

void MainWindow::onStepButtonClicked()
{
    m_simulationController->stepSimulation();
}

void MainWindow::onResetButtonClicked()
{
    m_simulationController->resetSimulation();
}

void MainWindow::onAddPassengerEventButtonClicked()
{
    int passengerId = ui->passengerIdSpinBox->value();
    int eventTypeIndex = ui->eventTypeComboBox->currentIndex();
    int timeStep = ui->timeStepEventSpinBox->value();
    int floor = ui->floorSpinBox->value();
    Direction direction = ui->directionComboBox->currentIndex() == 0 ? Direction::UP : Direction::DOWN;
    int targetFloor = ui->targetFloorSpinBox->value();
    int elevatorId = ui->elevatorIdSpinBox->value();
    
    PassengerAction action;
    switch (eventTypeIndex) {
        case 0:
            action = PassengerAction::REQUEST_ELEVATOR;
            break;
        case 1:
            action = PassengerAction::ENTER_ELEVATOR;
            break;
        case 2:
            action = PassengerAction::PRESS_FLOOR_BUTTON;
            break;
        case 3:
            action = PassengerAction::PRESS_HELP_BUTTON;
            break;
        case 4:
            action = PassengerAction::PRESS_DOOR_OPEN;
            break;
        case 5:
            action = PassengerAction::PRESS_DOOR_CLOSE;
            break;
        case 6:
            action = PassengerAction::EXIT_ELEVATOR;
            break;
        default:
            action = PassengerAction::NONE;
    }
    
    m_simulationController->addPassengerEvent(passengerId, action, timeStep, floor, direction, targetFloor, elevatorId);
    
    onLogMessage(QString("Added passenger event: Passenger %1, Event %2, Time Step %3")
                .arg(passengerId)
                .arg(ui->eventTypeComboBox->currentText())
                .arg(timeStep));
}

void MainWindow::onAddPassengerButtonClicked()
{
    if (m_simulationController->getState() != SimulationState::SETUP) {
        return;
    }
    
    int startFloor = ui->floorSpinBox->value();
    m_simulationController->addPassenger(startFloor);
    
    onLogMessage(QString("Added passenger at floor %1").arg(startFloor));
}

void MainWindow::onAddSafetyEventButtonClicked()
{
    int eventTypeIndex = ui->safetyEventTypeComboBox->currentIndex();
    int timeStep = ui->safetyTimeStepSpinBox->value();
    int elevatorId = ui->safetyElevatorIdSpinBox->value();
    
    ElevatorSafetyEvent eventType;
    switch (eventTypeIndex) {
        case 0:
            eventType = ElevatorSafetyEvent::HELP_BUTTON_PRESSED;
            break;
        case 1:
            eventType = ElevatorSafetyEvent::DOOR_OBSTACLE;
            break;
        case 2:
            eventType = ElevatorSafetyEvent::FIRE_ALARM;
            break;
        case 3:
            eventType = ElevatorSafetyEvent::OVERLOAD;
            break;
        case 4:
            eventType = ElevatorSafetyEvent::POWER_OUT;
            break;
        default:
            eventType = ElevatorSafetyEvent::NONE;
    }
    
    m_simulationController->addSafetyEvent(eventType, timeStep, elevatorId);
    
    onLogMessage(QString("Added safety event: %1, Time Step %2, Elevator %3")
                .arg(ui->safetyEventTypeComboBox->currentText())
                .arg(timeStep)
                .arg(elevatorId == -1 ? "All (Building)" : QString::number(elevatorId)));
}

void MainWindow::onStrategyComboBoxChanged(int)
{
    if (m_simulationController->getState() == SimulationState::SETUP) {
        onLogMessage(QString("Elevator allocation strategy set to: %1").arg(ui->strategyComboBox->currentText()));
    }
}

void MainWindow::onSimulationStarted()
{
    updateUIState();
}

void MainWindow::onSimulationPaused()
{
    updateUIState();
}

void MainWindow::onSimulationResumed()
{
    updateUIState();
}

void MainWindow::onSimulationStopped()
{
    updateUIState();
}

void MainWindow::onSimulationReset()
{
    // Clear displays
    QLayoutItem* child;
    while ((child = ui->buildingLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    
    m_elevatorStateLabels.clear();
    m_elevatorFloorLabels.clear();
    m_activeSafetyLabels.clear();
    m_floorButtonLabels.clear();
    
    updateUIState();
}

void MainWindow::onSimulationCompleted()
{
    updateUIState();
    QMessageBox::information(this, "Simulation Completed", "The simulation has completed successfully.");
}

void MainWindow::onTimeStepChanged(int timeStep)
{
    ui->timeStepLabel->setText(QString("Time Step: %1").arg(timeStep));
    updateUIState();
}

void MainWindow::onStateChanged(SimulationState)
{
    ui->stateLabel->setText(QString("State: %1").arg(m_simulationController->getStateString()));
    updateUIState();
}

void MainWindow::onLogMessage(const QString& message)
{
    ui->logTextEdit->append(QString("[%1] %2")
                           .arg(QTime::currentTime().toString("hh:mm:ss.zzz"))
                           .arg(message));
} 