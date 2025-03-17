/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "onStartButtonClicked",
    "",
    "onPauseButtonClicked",
    "onResumeButtonClicked",
    "onStopButtonClicked",
    "onStepButtonClicked",
    "onResetButtonClicked",
    "onAddPassengerButtonClicked",
    "onAddPassengerEventButtonClicked",
    "onAddSafetyEventButtonClicked",
    "onStrategyComboBoxChanged",
    "index",
    "onSimulationStarted",
    "onSimulationPaused",
    "onSimulationResumed",
    "onSimulationStopped",
    "onSimulationReset",
    "onSimulationCompleted",
    "onTimeStepChanged",
    "timeStep",
    "onStateChanged",
    "SimulationState",
    "state",
    "onLogMessage",
    "message"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x08,    1 /* Private */,
       3,    0,  129,    2, 0x08,    2 /* Private */,
       4,    0,  130,    2, 0x08,    3 /* Private */,
       5,    0,  131,    2, 0x08,    4 /* Private */,
       6,    0,  132,    2, 0x08,    5 /* Private */,
       7,    0,  133,    2, 0x08,    6 /* Private */,
       8,    0,  134,    2, 0x08,    7 /* Private */,
       9,    0,  135,    2, 0x08,    8 /* Private */,
      10,    0,  136,    2, 0x08,    9 /* Private */,
      11,    1,  137,    2, 0x08,   10 /* Private */,
      13,    0,  140,    2, 0x08,   12 /* Private */,
      14,    0,  141,    2, 0x08,   13 /* Private */,
      15,    0,  142,    2, 0x08,   14 /* Private */,
      16,    0,  143,    2, 0x08,   15 /* Private */,
      17,    0,  144,    2, 0x08,   16 /* Private */,
      18,    0,  145,    2, 0x08,   17 /* Private */,
      19,    1,  146,    2, 0x08,   18 /* Private */,
      21,    1,  149,    2, 0x08,   20 /* Private */,
      24,    1,  152,    2, 0x08,   22 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::QString,   25,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'onStartButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPauseButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onResumeButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStopButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStepButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onResetButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddPassengerButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddPassengerEventButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddSafetyEventButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStrategyComboBoxChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onSimulationStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSimulationPaused'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSimulationResumed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSimulationStopped'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSimulationReset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSimulationCompleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTimeStepChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SimulationState, std::false_type>,
        // method 'onLogMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onStartButtonClicked(); break;
        case 1: _t->onPauseButtonClicked(); break;
        case 2: _t->onResumeButtonClicked(); break;
        case 3: _t->onStopButtonClicked(); break;
        case 4: _t->onStepButtonClicked(); break;
        case 5: _t->onResetButtonClicked(); break;
        case 6: _t->onAddPassengerButtonClicked(); break;
        case 7: _t->onAddPassengerEventButtonClicked(); break;
        case 8: _t->onAddSafetyEventButtonClicked(); break;
        case 9: _t->onStrategyComboBoxChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->onSimulationStarted(); break;
        case 11: _t->onSimulationPaused(); break;
        case 12: _t->onSimulationResumed(); break;
        case 13: _t->onSimulationStopped(); break;
        case 14: _t->onSimulationReset(); break;
        case 15: _t->onSimulationCompleted(); break;
        case 16: _t->onTimeStepChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->onStateChanged((*reinterpret_cast< std::add_pointer_t<SimulationState>>(_a[1]))); break;
        case 18: _t->onLogMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
