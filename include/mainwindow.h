#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QGroupBox>
#include "simulationcontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartButtonClicked();
    void onPauseButtonClicked();
    void onResumeButtonClicked();
    void onStopButtonClicked();
    void onStepButtonClicked();
    void onResetButtonClicked();
    void onAddPassengerButtonClicked();
    void onAddPassengerEventButtonClicked();
    void onAddSafetyEventButtonClicked();
    void onStrategyComboBoxChanged(int index);
    
    void onSimulationStarted();
    void onSimulationPaused();
    void onSimulationResumed();
    void onSimulationStopped();
    void onSimulationReset();
    void onSimulationCompleted();
    void onTimeStepChanged(int timeStep);
    void onStateChanged(SimulationState state);
    void onLogMessage(const QString& message);

private:
    Ui::MainWindow *ui;
    SimulationController* m_simulationController;
    QVector<QLabel*> m_elevatorStateLabels;
    QVector<QLabel*> m_elevatorFloorLabels;
    QVector<QLabel*> m_floorButtonLabels;
    QVector<QLabel*> m_activeSafetyLabels;
    
    void setupUI();
    void setupSimulationControls();
    void setupElevatorDisplay();
    void setupFloorDisplay();
    void setupPassengerControls();
    void setupSafetyControls();
    void setupLogConsole();
    
    void updateElevatorDisplay();
    void updateFloorDisplay();
    void updateSafetyDisplay();
    void updateUIState();
    
    void createElevatorAllocationStrategy();
};

#endif // MAINWINDOW_H 