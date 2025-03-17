/****************************************************************************
** Meta object code from reading C++ file 'elevator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/elevator.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elevator.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8ElevatorE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN8ElevatorE = QtMocHelpers::stringData(
    "Elevator",
    "arrivedAtFloor",
    "",
    "elevatorId",
    "floor",
    "doorOpened",
    "doorClosed",
    "stateChanged",
    "ElevatorState",
    "state",
    "destinationsChanged",
    "QList<int>",
    "destinations",
    "helpButtonPressed",
    "safetyEventTriggered",
    "ElevatorSafetyEvent",
    "event",
    "safetyEventCleared",
    "displayMessage",
    "message",
    "audioMessage",
    "moveToFloor",
    "addDestination",
    "update",
    "openDoor",
    "closeDoor",
    "pressHelpButton",
    "triggerSafetyEvent",
    "clearSafetyEvent",
    "moveToSafeFloor",
    "simulateDoorObstacle",
    "simulateOverload"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN8ElevatorE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  140,    2, 0x06,    1 /* Public */,
       5,    1,  145,    2, 0x06,    4 /* Public */,
       6,    1,  148,    2, 0x06,    6 /* Public */,
       7,    2,  151,    2, 0x06,    8 /* Public */,
      10,    2,  156,    2, 0x06,   11 /* Public */,
      13,    1,  161,    2, 0x06,   14 /* Public */,
      14,    2,  164,    2, 0x06,   16 /* Public */,
      17,    1,  169,    2, 0x06,   19 /* Public */,
      18,    2,  172,    2, 0x06,   21 /* Public */,
      20,    2,  177,    2, 0x06,   24 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      21,    1,  182,    2, 0x0a,   27 /* Public */,
      22,    1,  185,    2, 0x0a,   29 /* Public */,
      23,    0,  188,    2, 0x0a,   31 /* Public */,
      24,    0,  189,    2, 0x0a,   32 /* Public */,
      25,    0,  190,    2, 0x0a,   33 /* Public */,
      26,    0,  191,    2, 0x0a,   34 /* Public */,
      27,    1,  192,    2, 0x0a,   35 /* Public */,
      28,    0,  195,    2, 0x0a,   37 /* Public */,
      29,    0,  196,    2, 0x0a,   38 /* Public */,
      30,    0,  197,    2, 0x0a,   39 /* Public */,
      31,    0,  198,    2, 0x0a,   40 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    3,    9,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,    3,   12,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,    3,   16,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,   19,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Elevator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN8ElevatorE.offsetsAndSizes,
    qt_meta_data_ZN8ElevatorE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN8ElevatorE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Elevator, std::true_type>,
        // method 'arrivedAtFloor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'doorOpened'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'doorClosed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<ElevatorState, std::false_type>,
        // method 'destinationsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<int> &, std::false_type>,
        // method 'helpButtonPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'safetyEventTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<ElevatorSafetyEvent, std::false_type>,
        // method 'safetyEventCleared'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'displayMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'audioMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'moveToFloor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'addDestination'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'update'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openDoor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeDoor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pressHelpButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerSafetyEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ElevatorSafetyEvent, std::false_type>,
        // method 'clearSafetyEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveToSafeFloor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'simulateDoorObstacle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'simulateOverload'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Elevator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Elevator *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->arrivedAtFloor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->doorOpened((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->doorClosed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ElevatorState>>(_a[2]))); break;
        case 4: _t->destinationsChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[2]))); break;
        case 5: _t->helpButtonPressed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->safetyEventTriggered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ElevatorSafetyEvent>>(_a[2]))); break;
        case 7: _t->safetyEventCleared((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->displayMessage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->audioMessage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 10: _t->moveToFloor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->addDestination((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->update(); break;
        case 13: _t->openDoor(); break;
        case 14: _t->closeDoor(); break;
        case 15: _t->pressHelpButton(); break;
        case 16: _t->triggerSafetyEvent((*reinterpret_cast< std::add_pointer_t<ElevatorSafetyEvent>>(_a[1]))); break;
        case 17: _t->clearSafetyEvent(); break;
        case 18: _t->moveToSafeFloor(); break;
        case 19: _t->simulateDoorObstacle(); break;
        case 20: _t->simulateOverload(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Elevator::*)(int , int );
            if (_q_method_type _q_method = &Elevator::arrivedAtFloor; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Elevator::*)(int );
            if (_q_method_type _q_method = &Elevator::doorOpened; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Elevator::*)(int );
            if (_q_method_type _q_method = &Elevator::doorClosed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (Elevator::*)(int , ElevatorState );
            if (_q_method_type _q_method = &Elevator::stateChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (Elevator::*)(int , const QVector<int> & );
            if (_q_method_type _q_method = &Elevator::destinationsChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (Elevator::*)(int );
            if (_q_method_type _q_method = &Elevator::helpButtonPressed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (Elevator::*)(int , ElevatorSafetyEvent );
            if (_q_method_type _q_method = &Elevator::safetyEventTriggered; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (Elevator::*)(int );
            if (_q_method_type _q_method = &Elevator::safetyEventCleared; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (Elevator::*)(int , const QString & );
            if (_q_method_type _q_method = &Elevator::displayMessage; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _q_method_type = void (Elevator::*)(int , const QString & );
            if (_q_method_type _q_method = &Elevator::audioMessage; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject *Elevator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Elevator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN8ElevatorE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Elevator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void Elevator::arrivedAtFloor(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Elevator::doorOpened(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Elevator::doorClosed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Elevator::stateChanged(int _t1, ElevatorState _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Elevator::destinationsChanged(int _t1, const QVector<int> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Elevator::helpButtonPressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Elevator::safetyEventTriggered(int _t1, ElevatorSafetyEvent _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Elevator::safetyEventCleared(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Elevator::displayMessage(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Elevator::audioMessage(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
