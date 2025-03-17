QT += testlib
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    test_scenarios.cpp \
    ../src/elevator.cpp \
    ../src/building.cpp \
    ../src/passenger.cpp \
    ../src/simulationcontroller.cpp \
    ../src/floorrequest.cpp \
    ../src/elevatorallocationstrategy.cpp \
    ../src/safetymonitor.cpp

HEADERS += \
    ../include/elevator.h \
    ../include/building.h \
    ../include/passenger.h \
    ../include/simulationcontroller.h \
    ../include/floorrequest.h \
    ../include/elevatorallocationstrategy.h \
    ../include/safetymonitor.h

INCLUDEPATH += ../include/ 