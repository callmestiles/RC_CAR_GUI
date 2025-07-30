/****************************************************************************
** Meta object code from reading C++ file 'ThumbstickController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ThumbstickController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThumbstickController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThumbstickController_t {
    QByteArrayData data[44];
    char stringdata0[625];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThumbstickController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThumbstickController_t qt_meta_stringdata_ThumbstickController = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ThumbstickController"
QT_MOC_LITERAL(1, 21, 17), // "connectionChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 17), // "serialPortChanged"
QT_MOC_LITERAL(4, 58, 24), // "thumbstickEnabledChanged"
QT_MOC_LITERAL(5, 83, 14), // "armDataChanged"
QT_MOC_LITERAL(6, 98, 16), // "motorDataChanged"
QT_MOC_LITERAL(7, 115, 18), // "serialDataReceived"
QT_MOC_LITERAL(8, 134, 4), // "data"
QT_MOC_LITERAL(9, 139, 18), // "armControlReceived"
QT_MOC_LITERAL(10, 158, 7), // "command"
QT_MOC_LITERAL(11, 166, 20), // "motorControlReceived"
QT_MOC_LITERAL(12, 187, 9), // "direction"
QT_MOC_LITERAL(13, 197, 5), // "speed"
QT_MOC_LITERAL(14, 203, 18), // "buttonStateChanged"
QT_MOC_LITERAL(15, 222, 22), // "gripperControlReceived"
QT_MOC_LITERAL(16, 245, 5), // "state"
QT_MOC_LITERAL(17, 251, 13), // "carUrlChanged"
QT_MOC_LITERAL(18, 265, 15), // "httpRequestSent"
QT_MOC_LITERAL(19, 281, 8), // "endpoint"
QT_MOC_LITERAL(20, 290, 17), // "httpRequestFailed"
QT_MOC_LITERAL(21, 308, 5), // "error"
QT_MOC_LITERAL(22, 314, 13), // "connectSerial"
QT_MOC_LITERAL(23, 328, 16), // "disconnectSerial"
QT_MOC_LITERAL(24, 345, 23), // "getAvailableSerialPorts"
QT_MOC_LITERAL(25, 369, 18), // "sendGripperCommand"
QT_MOC_LITERAL(26, 388, 17), // "onSerialDataReady"
QT_MOC_LITERAL(27, 406, 13), // "onSerialError"
QT_MOC_LITERAL(28, 420, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(29, 449, 21), // "onHttpRequestFinished"
QT_MOC_LITERAL(30, 471, 14), // "QNetworkReply*"
QT_MOC_LITERAL(31, 486, 5), // "reply"
QT_MOC_LITERAL(32, 492, 11), // "isConnected"
QT_MOC_LITERAL(33, 504, 10), // "serialPort"
QT_MOC_LITERAL(34, 515, 17), // "thumbstickEnabled"
QT_MOC_LITERAL(35, 533, 7), // "armRawX"
QT_MOC_LITERAL(36, 541, 7), // "armRawY"
QT_MOC_LITERAL(37, 549, 10), // "armCommand"
QT_MOC_LITERAL(38, 560, 9), // "motorRawX"
QT_MOC_LITERAL(39, 570, 9), // "motorRawY"
QT_MOC_LITERAL(40, 580, 14), // "motorDirection"
QT_MOC_LITERAL(41, 595, 10), // "motorSpeed"
QT_MOC_LITERAL(42, 606, 11), // "buttonState"
QT_MOC_LITERAL(43, 618, 6) // "carUrl"

    },
    "ThumbstickController\0connectionChanged\0"
    "\0serialPortChanged\0thumbstickEnabledChanged\0"
    "armDataChanged\0motorDataChanged\0"
    "serialDataReceived\0data\0armControlReceived\0"
    "command\0motorControlReceived\0direction\0"
    "speed\0buttonStateChanged\0"
    "gripperControlReceived\0state\0carUrlChanged\0"
    "httpRequestSent\0endpoint\0httpRequestFailed\0"
    "error\0connectSerial\0disconnectSerial\0"
    "getAvailableSerialPorts\0sendGripperCommand\0"
    "onSerialDataReady\0onSerialError\0"
    "QSerialPort::SerialPortError\0"
    "onHttpRequestFinished\0QNetworkReply*\0"
    "reply\0isConnected\0serialPort\0"
    "thumbstickEnabled\0armRawX\0armRawY\0"
    "armCommand\0motorRawX\0motorRawY\0"
    "motorDirection\0motorSpeed\0buttonState\0"
    "carUrl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThumbstickController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
      12,  160, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    0,  115,    2, 0x06 /* Public */,
       4,    0,  116,    2, 0x06 /* Public */,
       5,    0,  117,    2, 0x06 /* Public */,
       6,    0,  118,    2, 0x06 /* Public */,
       7,    1,  119,    2, 0x06 /* Public */,
       9,    1,  122,    2, 0x06 /* Public */,
      11,    2,  125,    2, 0x06 /* Public */,
      14,    0,  130,    2, 0x06 /* Public */,
      15,    1,  131,    2, 0x06 /* Public */,
      17,    0,  134,    2, 0x06 /* Public */,
      18,    3,  135,    2, 0x06 /* Public */,
      20,    2,  142,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    0,  147,    2, 0x0a /* Public */,
      23,    0,  148,    2, 0x0a /* Public */,
      24,    0,  149,    2, 0x0a /* Public */,
      25,    1,  150,    2, 0x0a /* Public */,
      26,    0,  153,    2, 0x08 /* Private */,
      27,    1,  154,    2, 0x08 /* Private */,
      29,    1,  157,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   19,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   21,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28,   21,
    QMetaType::Void, 0x80000000 | 30,   31,

 // properties: name, type, flags
      32, QMetaType::Bool, 0x00495001,
      33, QMetaType::QString, 0x00495103,
      34, QMetaType::Bool, 0x00495103,
      35, QMetaType::Int, 0x00495001,
      36, QMetaType::Int, 0x00495001,
      37, QMetaType::QString, 0x00495001,
      38, QMetaType::Int, 0x00495001,
      39, QMetaType::Int, 0x00495001,
      40, QMetaType::QString, 0x00495001,
      41, QMetaType::Int, 0x00495001,
      42, QMetaType::QString, 0x00495001,
      43, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       3,
       3,
       4,
       4,
       4,
       4,
       8,
      10,

       0        // eod
};

void ThumbstickController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThumbstickController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectionChanged(); break;
        case 1: _t->serialPortChanged(); break;
        case 2: _t->thumbstickEnabledChanged(); break;
        case 3: _t->armDataChanged(); break;
        case 4: _t->motorDataChanged(); break;
        case 5: _t->serialDataReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->armControlReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->motorControlReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->buttonStateChanged(); break;
        case 9: _t->gripperControlReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->carUrlChanged(); break;
        case 11: _t->httpRequestSent((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->httpRequestFailed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 13: _t->connectSerial(); break;
        case 14: _t->disconnectSerial(); break;
        case 15: { QStringList _r = _t->getAvailableSerialPorts();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->sendGripperCommand((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->onSerialDataReady(); break;
        case 18: _t->onSerialError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 19: _t->onHttpRequestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 19:
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
            using _t = void (ThumbstickController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::connectionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::serialPortChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::thumbstickEnabledChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::armDataChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::motorDataChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::serialDataReceived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::armControlReceived)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)(const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::motorControlReceived)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::buttonStateChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::gripperControlReceived)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::carUrlChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)(const QString & , const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::httpRequestSent)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (ThumbstickController::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThumbstickController::httpRequestFailed)) {
                *result = 12;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ThumbstickController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isConnected(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->serialPort(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->thumbstickEnabled(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->armRawX(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->armRawY(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->armCommand(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->motorRawX(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->motorRawY(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->motorDirection(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->motorSpeed(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->buttonState(); break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->carUrl(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ThumbstickController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setSerialPort(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setThumbstickEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 11: _t->setCarUrl(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ThumbstickController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ThumbstickController.data,
    qt_meta_data_ThumbstickController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThumbstickController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThumbstickController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThumbstickController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThumbstickController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 12;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ThumbstickController::connectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ThumbstickController::serialPortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ThumbstickController::thumbstickEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ThumbstickController::armDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ThumbstickController::motorDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ThumbstickController::serialDataReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ThumbstickController::armControlReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ThumbstickController::motorControlReceived(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ThumbstickController::buttonStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ThumbstickController::gripperControlReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ThumbstickController::carUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void ThumbstickController::httpRequestSent(const QString & _t1, const QString & _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ThumbstickController::httpRequestFailed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
