QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ElevatorSimulation
TEMPLATE = app

CONFIG += c++17

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/elevator.cpp \
    src/building.cpp \
    src/passenger.cpp \
    src/simulationcontroller.cpp \
    src/floorrequest.cpp \
    src/elevatorallocationstrategy.cpp \
    src/safetymonitor.cpp

HEADERS += \
    include/mainwindow.h \
    include/elevator.h \
    include/building.h \
    include/passenger.h \
    include/simulationcontroller.h \
    include/floorrequest.h \
    include/elevatorallocationstrategy.h \
    include/safetymonitor.h

FORMS += \
    ui/mainwindow.ui

INCLUDEPATH += include/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target 