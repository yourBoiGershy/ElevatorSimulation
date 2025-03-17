/****************************************************************************
** Meta object code from reading C++ file 'safetymonitor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/safetymonitor.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'safetymonitor.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13SafetyMonitorE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN13SafetyMonitorE = QtMocHelpers::stringData(
    "SafetyMonitor",
    "safetyEventTriggered",
    "",
    "ElevatorSafetyEvent",
    "eventType",
    "elevatorId",
    "buildingSafetyEventTriggered",
    "safetyEventResolved",
    "buildingSafetyEventResolved",
    "emergency911Called",
    "logMessage",
    "message",
    "displayMessage",
    "audioMessage",
    "handleHelpButtonPressed",
    "handleDoorObstacle",
    "handleFireAlarm",
    "handleElevatorFireAlarm",
    "handleOverload",
    "handlePowerOutage",
    "checkSafetyEvents",
    "currentTimeStep",
    "startHelpResponseTimer"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN13SafetyMonitorE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  110,    2, 0x06,    1 /* Public */,
       6,    1,  115,    2, 0x06,    4 /* Public */,
       7,    1,  118,    2, 0x06,    6 /* Public */,
       8,    0,  121,    2, 0x06,    8 /* Public */,
       9,    1,  122,    2, 0x06,    9 /* Public */,
      10,    1,  125,    2, 0x06,   11 /* Public */,
      12,    2,  128,    2, 0x06,   13 /* Public */,
      13,    2,  133,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,  138,    2, 0x0a,   19 /* Public */,
      15,    1,  141,    2, 0x0a,   21 /* Public */,
      16,    0,  144,    2, 0x0a,   23 /* Public */,
      17,    1,  145,    2, 0x0a,   24 /* Public */,
      18,    1,  148,    2, 0x0a,   26 /* Public */,
      19,    0,  151,    2, 0x0a,   28 /* Public */,
      20,    1,  152,    2, 0x0a,   29 /* Public */,
      22,    1,  155,    2, 0x0a,   31 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject SafetyMonitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN13SafetyMonitorE.offsetsAndSizes,
    qt_meta_data_ZN13SafetyMonitorE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN13SafetyMonitorE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SafetyMonitor, std::true_type>,
        // method 'safetyEventTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ElevatorSafetyEvent, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'buildingSafetyEventTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ElevatorSafetyEvent, std::false_type>,
        // method 'safetyEventResolved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'buildingSafetyEventResolved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'emergency911Called'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'logMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'displayMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'audioMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'handleHelpButtonPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleDoorObstacle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleFireAlarm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleElevatorFireAlarm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleOverload'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handlePowerOutage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkSafetyEvents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'startHelpResponseTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void SafetyMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SafetyMonitor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->safetyEventTriggered((*reinterpret_cast< std::add_pointer_t<ElevatorSafetyEvent>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->buildingSafetyEventTriggered((*reinterpret_cast< std::add_pointer_t<ElevatorSafetyEvent>>(_a[1]))); break;
        case 2: _t->safetyEventResolved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->buildingSafetyEventResolved(); break;
        case 4: _t->emergency911Called((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->displayMessage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->audioMessage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->handleHelpButtonPressed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->handleDoorObstacle((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->handleFireAlarm(); break;
        case 11: _t->handleElevatorFireAlarm((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->handleOverload((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->handlePowerOutage(); break;
        case 14: _t->checkSafetyEvents((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->startHelpResponseTimer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (SafetyMonitor::*)(ElevatorSafetyEvent , int );
            if (_q_method_type _q_method = &SafetyMonitor::safetyEventTriggered; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (SafetyMonitor::*)(ElevatorSafetyEvent );
            if (_q_method_type _q_method = &SafetyMonitor::buildingSafetyEventTriggered; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (SafetyMonitor::*)(int );
            if (_q_method_type _q_method = &SafetyMonitor::safetyEventResolved; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (SafetyMonitor::*)();
            if (_q_method_type _q_method = &SafetyMonitor::buildingSafetyEventResolved; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (SafetyMonitor::*)(int );
            if (_q_method_type _q_method = &SafetyMonitor::emergency911Called; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (SafetyMonitor::*)(const QString & );
            if (_q_method_type _q_method = &SafetyMonitor::logMessage; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (SafetyMonitor::*)(int , const QString & );
            if (_q_method_type _q_method = &SafetyMonitor::displayMessage; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (SafetyMonitor::*)(int , const QString & );
            if (_q_method_type _q_method = &SafetyMonitor::audioMessage; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject *SafetyMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SafetyMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN13SafetyMonitorE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SafetyMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SafetyMonitor::safetyEventTriggered(ElevatorSafetyEvent _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SafetyMonitor::buildingSafetyEventTriggered(ElevatorSafetyEvent _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SafetyMonitor::safetyEventResolved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SafetyMonitor::buildingSafetyEventResolved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SafetyMonitor::emergency911Called(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SafetyMonitor::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SafetyMonitor::displayMessage(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SafetyMonitor::audioMessage(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
