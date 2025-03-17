/****************************************************************************
** Meta object code from reading C++ file 'simulationcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/simulationcontroller.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulationcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN20SimulationControllerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN20SimulationControllerE = QtMocHelpers::stringData(
    "SimulationController",
    "simulationStarted",
    "",
    "simulationPaused",
    "simulationResumed",
    "simulationStopped",
    "simulationReset",
    "simulationCompleted",
    "timeStepChanged",
    "timeStep",
    "stateChanged",
    "SimulationState",
    "state",
    "logMessage",
    "message",
    "startSimulation",
    "pauseSimulation",
    "resumeSimulation",
    "stopSimulation",
    "stepSimulation",
    "resetSimulation",
    "update"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN20SimulationControllerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x06,    1 /* Public */,
       3,    0,  111,    2, 0x06,    2 /* Public */,
       4,    0,  112,    2, 0x06,    3 /* Public */,
       5,    0,  113,    2, 0x06,    4 /* Public */,
       6,    0,  114,    2, 0x06,    5 /* Public */,
       7,    0,  115,    2, 0x06,    6 /* Public */,
       8,    1,  116,    2, 0x06,    7 /* Public */,
      10,    1,  119,    2, 0x06,    9 /* Public */,
      13,    1,  122,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,  125,    2, 0x0a,   13 /* Public */,
      16,    0,  126,    2, 0x0a,   14 /* Public */,
      17,    0,  127,    2, 0x0a,   15 /* Public */,
      18,    0,  128,    2, 0x0a,   16 /* Public */,
      19,    0,  129,    2, 0x0a,   17 /* Public */,
      20,    0,  130,    2, 0x0a,   18 /* Public */,
      21,    0,  131,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SimulationController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN20SimulationControllerE.offsetsAndSizes,
    qt_meta_data_ZN20SimulationControllerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN20SimulationControllerE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SimulationController, std::true_type>,
        // method 'simulationStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'simulationPaused'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'simulationResumed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'simulationStopped'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'simulationReset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'simulationCompleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timeStepChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SimulationState, std::false_type>,
        // method 'logMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'startSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pauseSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resumeSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stepSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SimulationController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SimulationController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->simulationStarted(); break;
        case 1: _t->simulationPaused(); break;
        case 2: _t->simulationResumed(); break;
        case 3: _t->simulationStopped(); break;
        case 4: _t->simulationReset(); break;
        case 5: _t->simulationCompleted(); break;
        case 6: _t->timeStepChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<SimulationState>>(_a[1]))); break;
        case 8: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->startSimulation(); break;
        case 10: _t->pauseSimulation(); break;
        case 11: _t->resumeSimulation(); break;
        case 12: _t->stopSimulation(); break;
        case 13: _t->stepSimulation(); break;
        case 14: _t->resetSimulation(); break;
        case 15: _t->update(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (SimulationController::*)();
            if (_q_method_type _q_method = &SimulationController::simulationStarted; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (SimulationController::*)();
            if (_q_method_type _q_method = &SimulationController::simulationPaused; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (SimulationController::*)();
            if (_q_method_type _q_method = &SimulationController::simulationResumed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (SimulationController::*)();
            if (_q_method_type _q_method = &SimulationController::simulationStopped; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (SimulationController::*)();
            if (_q_method_type _q_method = &SimulationController::simulationReset; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (SimulationController::*)();
            if (_q_method_type _q_method = &SimulationController::simulationCompleted; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (SimulationController::*)(int );
            if (_q_method_type _q_method = &SimulationController::timeStepChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (SimulationController::*)(SimulationState );
            if (_q_method_type _q_method = &SimulationController::stateChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (SimulationController::*)(const QString & );
            if (_q_method_type _q_method = &SimulationController::logMessage; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject *SimulationController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimulationController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN20SimulationControllerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SimulationController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void SimulationController::simulationStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SimulationController::simulationPaused()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SimulationController::simulationResumed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SimulationController::simulationStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SimulationController::simulationReset()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SimulationController::simulationCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SimulationController::timeStepChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SimulationController::stateChanged(SimulationState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SimulationController::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
