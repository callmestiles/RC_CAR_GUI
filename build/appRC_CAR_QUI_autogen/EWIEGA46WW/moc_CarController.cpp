/****************************************************************************
** Meta object code from reading C++ file 'CarController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CarController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CarController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CarController_t {
    QByteArrayData data[23];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarController_t qt_meta_stringdata_CarController = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CarController"
QT_MOC_LITERAL(1, 14, 17), // "connectionChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "directionChanged"
QT_MOC_LITERAL(4, 50, 12), // "speedChanged"
QT_MOC_LITERAL(5, 63, 11), // "requestSent"
QT_MOC_LITERAL(6, 75, 9), // "direction"
QT_MOC_LITERAL(7, 85, 13), // "requestFailed"
QT_MOC_LITERAL(8, 99, 5), // "error"
QT_MOC_LITERAL(9, 105, 11), // "moveForward"
QT_MOC_LITERAL(10, 117, 12), // "moveBackward"
QT_MOC_LITERAL(11, 130, 8), // "turnLeft"
QT_MOC_LITERAL(12, 139, 9), // "turnRight"
QT_MOC_LITERAL(13, 149, 7), // "stopCar"
QT_MOC_LITERAL(14, 157, 12), // "backAndForth"
QT_MOC_LITERAL(15, 170, 13), // "emergencyStop"
QT_MOC_LITERAL(16, 184, 17), // "onRequestFinished"
QT_MOC_LITERAL(17, 202, 14), // "QNetworkReply*"
QT_MOC_LITERAL(18, 217, 5), // "reply"
QT_MOC_LITERAL(19, 223, 19), // "onBackAndForthTimer"
QT_MOC_LITERAL(20, 243, 11), // "isConnected"
QT_MOC_LITERAL(21, 255, 16), // "currentDirection"
QT_MOC_LITERAL(22, 272, 5) // "speed"

    },
    "CarController\0connectionChanged\0\0"
    "directionChanged\0speedChanged\0requestSent\0"
    "direction\0requestFailed\0error\0moveForward\0"
    "moveBackward\0turnLeft\0turnRight\0stopCar\0"
    "backAndForth\0emergencyStop\0onRequestFinished\0"
    "QNetworkReply*\0reply\0onBackAndForthTimer\0"
    "isConnected\0currentDirection\0speed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       3,  104, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    1,   87,    2, 0x06 /* Public */,
       7,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   93,    2, 0x0a /* Public */,
      10,    0,   94,    2, 0x0a /* Public */,
      11,    0,   95,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x0a /* Public */,
      13,    0,   97,    2, 0x0a /* Public */,
      14,    0,   98,    2, 0x0a /* Public */,
      15,    0,   99,    2, 0x0a /* Public */,
      16,    1,  100,    2, 0x08 /* Private */,
      19,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,

 // properties: name, type, flags
      20, QMetaType::Bool, 0x00495001,
      21, QMetaType::QString, 0x00495001,
      22, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void CarController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CarController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectionChanged(); break;
        case 1: _t->directionChanged(); break;
        case 2: _t->speedChanged(); break;
        case 3: _t->requestSent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->requestFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->moveForward(); break;
        case 6: _t->moveBackward(); break;
        case 7: _t->turnLeft(); break;
        case 8: _t->turnRight(); break;
        case 9: _t->stopCar(); break;
        case 10: _t->backAndForth(); break;
        case 11: _t->emergencyStop(); break;
        case 12: _t->onRequestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 13: _t->onBackAndForthTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CarController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarController::connectionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CarController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarController::directionChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CarController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarController::speedChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CarController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarController::requestSent)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CarController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarController::requestFailed)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CarController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isConnected(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->currentDirection(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->speed(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CarController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setSpeed(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CarController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CarController.data,
    qt_meta_data_CarController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CarController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CarController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CarController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CarController::connectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CarController::directionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CarController::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CarController::requestSent(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CarController::requestFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
