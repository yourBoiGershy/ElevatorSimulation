/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *leftLayout;
    QGroupBox *simulationControlsGroupBox;
    QGridLayout *gridLayout;
    QLabel *floorsLabel;
    QSpinBox *floorsSpinBox;
    QLabel *elevatorsLabel;
    QSpinBox *elevatorsSpinBox;
    QLabel *passengersLabel;
    QSpinBox *passengersSpinBox;
    QLabel *strategyLabel;
    QComboBox *strategyComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QPushButton *stepButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QLabel *timeStepLabel;
    QLabel *stateLabel;
    QGroupBox *passengerEventsGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *passengerIdLabel;
    QSpinBox *passengerIdSpinBox;
    QLabel *eventTypeLabel;
    QComboBox *eventTypeComboBox;
    QLabel *timeStepEventLabel;
    QSpinBox *timeStepEventSpinBox;
    QLabel *floorLabel;
    QSpinBox *floorSpinBox;
    QLabel *directionLabel;
    QComboBox *directionComboBox;
    QLabel *targetFloorLabel;
    QSpinBox *targetFloorSpinBox;
    QLabel *elevatorIdLabel;
    QSpinBox *elevatorIdSpinBox;
    QPushButton *addPassengerEventButton;
    QGroupBox *safetyEventsGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *safetyEventTypeLabel;
    QComboBox *safetyEventTypeComboBox;
    QLabel *safetyTimeStepLabel;
    QSpinBox *safetyTimeStepSpinBox;
    QLabel *safetyElevatorIdLabel;
    QSpinBox *safetyElevatorIdSpinBox;
    QPushButton *addSafetyEventButton;
    QWidget *layoutWidget1;
    QVBoxLayout *rightLayout;
    QGroupBox *buildingDisplayGroupBox;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *buildingScrollArea;
    QWidget *buildingScrollAreaContents;
    QVBoxLayout *buildingLayout;
    QGroupBox *logGroupBox;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *logTextEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 800);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        leftLayout = new QVBoxLayout(layoutWidget);
        leftLayout->setObjectName("leftLayout");
        leftLayout->setContentsMargins(0, 0, 0, 0);
        simulationControlsGroupBox = new QGroupBox(layoutWidget);
        simulationControlsGroupBox->setObjectName("simulationControlsGroupBox");
        gridLayout = new QGridLayout(simulationControlsGroupBox);
        gridLayout->setObjectName("gridLayout");
        floorsLabel = new QLabel(simulationControlsGroupBox);
        floorsLabel->setObjectName("floorsLabel");

        gridLayout->addWidget(floorsLabel, 0, 0, 1, 1);

        floorsSpinBox = new QSpinBox(simulationControlsGroupBox);
        floorsSpinBox->setObjectName("floorsSpinBox");
        floorsSpinBox->setMinimum(2);
        floorsSpinBox->setMaximum(20);
        floorsSpinBox->setValue(5);

        gridLayout->addWidget(floorsSpinBox, 0, 1, 1, 1);

        elevatorsLabel = new QLabel(simulationControlsGroupBox);
        elevatorsLabel->setObjectName("elevatorsLabel");

        gridLayout->addWidget(elevatorsLabel, 0, 2, 1, 1);

        elevatorsSpinBox = new QSpinBox(simulationControlsGroupBox);
        elevatorsSpinBox->setObjectName("elevatorsSpinBox");
        elevatorsSpinBox->setMinimum(1);
        elevatorsSpinBox->setMaximum(10);
        elevatorsSpinBox->setValue(2);

        gridLayout->addWidget(elevatorsSpinBox, 0, 3, 1, 1);

        passengersLabel = new QLabel(simulationControlsGroupBox);
        passengersLabel->setObjectName("passengersLabel");

        gridLayout->addWidget(passengersLabel, 1, 0, 1, 1);

        passengersSpinBox = new QSpinBox(simulationControlsGroupBox);
        passengersSpinBox->setObjectName("passengersSpinBox");
        passengersSpinBox->setMinimum(0);
        passengersSpinBox->setMaximum(20);
        passengersSpinBox->setValue(3);

        gridLayout->addWidget(passengersSpinBox, 1, 1, 1, 1);

        strategyLabel = new QLabel(simulationControlsGroupBox);
        strategyLabel->setObjectName("strategyLabel");

        gridLayout->addWidget(strategyLabel, 1, 2, 1, 1);

        strategyComboBox = new QComboBox(simulationControlsGroupBox);
        strategyComboBox->addItem(QString());
        strategyComboBox->addItem(QString());
        strategyComboBox->addItem(QString());
        strategyComboBox->setObjectName("strategyComboBox");

        gridLayout->addWidget(strategyComboBox, 1, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        startButton = new QPushButton(simulationControlsGroupBox);
        startButton->setObjectName("startButton");

        horizontalLayout->addWidget(startButton);

        pauseButton = new QPushButton(simulationControlsGroupBox);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setEnabled(false);

        horizontalLayout->addWidget(pauseButton);

        resumeButton = new QPushButton(simulationControlsGroupBox);
        resumeButton->setObjectName("resumeButton");
        resumeButton->setEnabled(false);

        horizontalLayout->addWidget(resumeButton);

        stepButton = new QPushButton(simulationControlsGroupBox);
        stepButton->setObjectName("stepButton");
        stepButton->setEnabled(false);

        horizontalLayout->addWidget(stepButton);

        stopButton = new QPushButton(simulationControlsGroupBox);
        stopButton->setObjectName("stopButton");
        stopButton->setEnabled(false);

        horizontalLayout->addWidget(stopButton);

        resetButton = new QPushButton(simulationControlsGroupBox);
        resetButton->setObjectName("resetButton");
        resetButton->setEnabled(false);

        horizontalLayout->addWidget(resetButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 4);

        timeStepLabel = new QLabel(simulationControlsGroupBox);
        timeStepLabel->setObjectName("timeStepLabel");

        gridLayout->addWidget(timeStepLabel, 3, 0, 1, 2);

        stateLabel = new QLabel(simulationControlsGroupBox);
        stateLabel->setObjectName("stateLabel");

        gridLayout->addWidget(stateLabel, 3, 2, 1, 2);


        leftLayout->addWidget(simulationControlsGroupBox);

        passengerEventsGroupBox = new QGroupBox(layoutWidget);
        passengerEventsGroupBox->setObjectName("passengerEventsGroupBox");
        gridLayout_2 = new QGridLayout(passengerEventsGroupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        passengerIdLabel = new QLabel(passengerEventsGroupBox);
        passengerIdLabel->setObjectName("passengerIdLabel");

        gridLayout_2->addWidget(passengerIdLabel, 0, 0, 1, 1);

        passengerIdSpinBox = new QSpinBox(passengerEventsGroupBox);
        passengerIdSpinBox->setObjectName("passengerIdSpinBox");
        passengerIdSpinBox->setMinimum(0);
        passengerIdSpinBox->setMaximum(19);

        gridLayout_2->addWidget(passengerIdSpinBox, 0, 1, 1, 1);

        eventTypeLabel = new QLabel(passengerEventsGroupBox);
        eventTypeLabel->setObjectName("eventTypeLabel");

        gridLayout_2->addWidget(eventTypeLabel, 0, 2, 1, 1);

        eventTypeComboBox = new QComboBox(passengerEventsGroupBox);
        eventTypeComboBox->addItem(QString());
        eventTypeComboBox->addItem(QString());
        eventTypeComboBox->addItem(QString());
        eventTypeComboBox->addItem(QString());
        eventTypeComboBox->addItem(QString());
        eventTypeComboBox->addItem(QString());
        eventTypeComboBox->addItem(QString());
        eventTypeComboBox->setObjectName("eventTypeComboBox");

        gridLayout_2->addWidget(eventTypeComboBox, 0, 3, 1, 1);

        timeStepEventLabel = new QLabel(passengerEventsGroupBox);
        timeStepEventLabel->setObjectName("timeStepEventLabel");

        gridLayout_2->addWidget(timeStepEventLabel, 1, 0, 1, 1);

        timeStepEventSpinBox = new QSpinBox(passengerEventsGroupBox);
        timeStepEventSpinBox->setObjectName("timeStepEventSpinBox");
        timeStepEventSpinBox->setMinimum(1);
        timeStepEventSpinBox->setMaximum(100);

        gridLayout_2->addWidget(timeStepEventSpinBox, 1, 1, 1, 1);

        floorLabel = new QLabel(passengerEventsGroupBox);
        floorLabel->setObjectName("floorLabel");

        gridLayout_2->addWidget(floorLabel, 1, 2, 1, 1);

        floorSpinBox = new QSpinBox(passengerEventsGroupBox);
        floorSpinBox->setObjectName("floorSpinBox");
        floorSpinBox->setMinimum(1);
        floorSpinBox->setMaximum(20);

        gridLayout_2->addWidget(floorSpinBox, 1, 3, 1, 1);

        directionLabel = new QLabel(passengerEventsGroupBox);
        directionLabel->setObjectName("directionLabel");

        gridLayout_2->addWidget(directionLabel, 2, 0, 1, 1);

        directionComboBox = new QComboBox(passengerEventsGroupBox);
        directionComboBox->addItem(QString());
        directionComboBox->addItem(QString());
        directionComboBox->setObjectName("directionComboBox");

        gridLayout_2->addWidget(directionComboBox, 2, 1, 1, 1);

        targetFloorLabel = new QLabel(passengerEventsGroupBox);
        targetFloorLabel->setObjectName("targetFloorLabel");

        gridLayout_2->addWidget(targetFloorLabel, 2, 2, 1, 1);

        targetFloorSpinBox = new QSpinBox(passengerEventsGroupBox);
        targetFloorSpinBox->setObjectName("targetFloorSpinBox");
        targetFloorSpinBox->setMinimum(1);
        targetFloorSpinBox->setMaximum(20);

        gridLayout_2->addWidget(targetFloorSpinBox, 2, 3, 1, 1);

        elevatorIdLabel = new QLabel(passengerEventsGroupBox);
        elevatorIdLabel->setObjectName("elevatorIdLabel");

        gridLayout_2->addWidget(elevatorIdLabel, 3, 0, 1, 1);

        elevatorIdSpinBox = new QSpinBox(passengerEventsGroupBox);
        elevatorIdSpinBox->setObjectName("elevatorIdSpinBox");
        elevatorIdSpinBox->setMinimum(0);
        elevatorIdSpinBox->setMaximum(9);

        gridLayout_2->addWidget(elevatorIdSpinBox, 3, 1, 1, 1);

        addPassengerEventButton = new QPushButton(passengerEventsGroupBox);
        addPassengerEventButton->setObjectName("addPassengerEventButton");

        gridLayout_2->addWidget(addPassengerEventButton, 3, 2, 1, 2);


        leftLayout->addWidget(passengerEventsGroupBox);

        safetyEventsGroupBox = new QGroupBox(layoutWidget);
        safetyEventsGroupBox->setObjectName("safetyEventsGroupBox");
        gridLayout_3 = new QGridLayout(safetyEventsGroupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        safetyEventTypeLabel = new QLabel(safetyEventsGroupBox);
        safetyEventTypeLabel->setObjectName("safetyEventTypeLabel");

        gridLayout_3->addWidget(safetyEventTypeLabel, 0, 0, 1, 1);

        safetyEventTypeComboBox = new QComboBox(safetyEventsGroupBox);
        safetyEventTypeComboBox->addItem(QString());
        safetyEventTypeComboBox->addItem(QString());
        safetyEventTypeComboBox->addItem(QString());
        safetyEventTypeComboBox->addItem(QString());
        safetyEventTypeComboBox->addItem(QString());
        safetyEventTypeComboBox->setObjectName("safetyEventTypeComboBox");

        gridLayout_3->addWidget(safetyEventTypeComboBox, 0, 1, 1, 1);

        safetyTimeStepLabel = new QLabel(safetyEventsGroupBox);
        safetyTimeStepLabel->setObjectName("safetyTimeStepLabel");

        gridLayout_3->addWidget(safetyTimeStepLabel, 1, 0, 1, 1);

        safetyTimeStepSpinBox = new QSpinBox(safetyEventsGroupBox);
        safetyTimeStepSpinBox->setObjectName("safetyTimeStepSpinBox");
        safetyTimeStepSpinBox->setMinimum(1);
        safetyTimeStepSpinBox->setMaximum(100);

        gridLayout_3->addWidget(safetyTimeStepSpinBox, 1, 1, 1, 1);

        safetyElevatorIdLabel = new QLabel(safetyEventsGroupBox);
        safetyElevatorIdLabel->setObjectName("safetyElevatorIdLabel");

        gridLayout_3->addWidget(safetyElevatorIdLabel, 2, 0, 1, 1);

        safetyElevatorIdSpinBox = new QSpinBox(safetyEventsGroupBox);
        safetyElevatorIdSpinBox->setObjectName("safetyElevatorIdSpinBox");
        safetyElevatorIdSpinBox->setMinimum(-1);
        safetyElevatorIdSpinBox->setMaximum(9);
        safetyElevatorIdSpinBox->setValue(-1);

        gridLayout_3->addWidget(safetyElevatorIdSpinBox, 2, 1, 1, 1);

        addSafetyEventButton = new QPushButton(safetyEventsGroupBox);
        addSafetyEventButton->setObjectName("addSafetyEventButton");

        gridLayout_3->addWidget(addSafetyEventButton, 3, 0, 1, 2);


        leftLayout->addWidget(safetyEventsGroupBox);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName("layoutWidget1");
        rightLayout = new QVBoxLayout(layoutWidget1);
        rightLayout->setObjectName("rightLayout");
        rightLayout->setContentsMargins(0, 0, 0, 0);
        buildingDisplayGroupBox = new QGroupBox(layoutWidget1);
        buildingDisplayGroupBox->setObjectName("buildingDisplayGroupBox");
        verticalLayout_2 = new QVBoxLayout(buildingDisplayGroupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        buildingScrollArea = new QScrollArea(buildingDisplayGroupBox);
        buildingScrollArea->setObjectName("buildingScrollArea");
        buildingScrollArea->setWidgetResizable(true);
        buildingScrollAreaContents = new QWidget();
        buildingScrollAreaContents->setObjectName("buildingScrollAreaContents");
        buildingScrollAreaContents->setGeometry(QRect(0, 0, 454, 300));
        buildingLayout = new QVBoxLayout(buildingScrollAreaContents);
        buildingLayout->setObjectName("buildingLayout");
        buildingScrollArea->setWidget(buildingScrollAreaContents);

        verticalLayout_2->addWidget(buildingScrollArea);


        rightLayout->addWidget(buildingDisplayGroupBox);

        logGroupBox = new QGroupBox(layoutWidget1);
        logGroupBox->setObjectName("logGroupBox");
        verticalLayout_3 = new QVBoxLayout(logGroupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        logTextEdit = new QTextEdit(logGroupBox);
        logTextEdit->setObjectName("logTextEdit");
        logTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(logTextEdit);


        rightLayout->addWidget(logGroupBox);

        splitter->addWidget(layoutWidget1);

        verticalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Elevator Simulation", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        simulationControlsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Simulation Controls", nullptr));
        floorsLabel->setText(QCoreApplication::translate("MainWindow", "Floors:", nullptr));
        elevatorsLabel->setText(QCoreApplication::translate("MainWindow", "Elevators:", nullptr));
        passengersLabel->setText(QCoreApplication::translate("MainWindow", "Passengers:", nullptr));
        strategyLabel->setText(QCoreApplication::translate("MainWindow", "Strategy:", nullptr));
        strategyComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Nearest Elevator", nullptr));
        strategyComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Least Busy", nullptr));
        strategyComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Direction-based", nullptr));

        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        resumeButton->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
        stepButton->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        timeStepLabel->setText(QCoreApplication::translate("MainWindow", "Time Step: 0", nullptr));
        stateLabel->setText(QCoreApplication::translate("MainWindow", "State: Setup", nullptr));
        passengerEventsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Passenger Events", nullptr));
        passengerIdLabel->setText(QCoreApplication::translate("MainWindow", "Passenger ID:", nullptr));
        eventTypeLabel->setText(QCoreApplication::translate("MainWindow", "Event Type:", nullptr));
        eventTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Request Elevator", nullptr));
        eventTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Enter Elevator", nullptr));
        eventTypeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Press Floor Button", nullptr));
        eventTypeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Press Help Button", nullptr));
        eventTypeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Press Door Open", nullptr));
        eventTypeComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Press Door Close", nullptr));
        eventTypeComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Exit Elevator", nullptr));

        timeStepEventLabel->setText(QCoreApplication::translate("MainWindow", "Time Step:", nullptr));
        floorLabel->setText(QCoreApplication::translate("MainWindow", "Floor:", nullptr));
        directionLabel->setText(QCoreApplication::translate("MainWindow", "Direction:", nullptr));
        directionComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "UP", nullptr));
        directionComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "DOWN", nullptr));

        targetFloorLabel->setText(QCoreApplication::translate("MainWindow", "Target Floor:", nullptr));
        elevatorIdLabel->setText(QCoreApplication::translate("MainWindow", "Elevator ID:", nullptr));
        addPassengerEventButton->setText(QCoreApplication::translate("MainWindow", "Add Event", nullptr));
        safetyEventsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Safety Events", nullptr));
        safetyEventTypeLabel->setText(QCoreApplication::translate("MainWindow", "Event Type:", nullptr));
        safetyEventTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Help Button", nullptr));
        safetyEventTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Door Obstacle", nullptr));
        safetyEventTypeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Fire Alarm", nullptr));
        safetyEventTypeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Overload", nullptr));
        safetyEventTypeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Power Out", nullptr));

        safetyTimeStepLabel->setText(QCoreApplication::translate("MainWindow", "Time Step:", nullptr));
        safetyElevatorIdLabel->setText(QCoreApplication::translate("MainWindow", "Elevator ID:", nullptr));
        addSafetyEventButton->setText(QCoreApplication::translate("MainWindow", "Add Safety Event", nullptr));
        buildingDisplayGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Building Display", nullptr));
        logGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Log Console", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
