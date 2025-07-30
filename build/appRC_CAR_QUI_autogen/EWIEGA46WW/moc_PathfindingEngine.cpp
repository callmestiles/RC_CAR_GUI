/****************************************************************************
** Meta object code from reading C++ file 'PathfindingEngine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../PathfindingEngine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PathfindingEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PathfindingEngine_t {
    QByteArrayData data[21];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PathfindingEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PathfindingEngine_t qt_meta_stringdata_PathfindingEngine = {
    {
QT_MOC_LITERAL(0, 0, 17), // "PathfindingEngine"
QT_MOC_LITERAL(1, 18, 14), // "pathCalculated"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "path"
QT_MOC_LITERAL(4, 39, 22), // "optimalRouteCalculated"
QT_MOC_LITERAL(5, 62, 5), // "route"
QT_MOC_LITERAL(6, 68, 8), // "setNodes"
QT_MOC_LITERAL(7, 77, 5), // "nodes"
QT_MOC_LITERAL(8, 83, 14), // "setConnections"
QT_MOC_LITERAL(9, 98, 11), // "connections"
QT_MOC_LITERAL(10, 110, 8), // "findPath"
QT_MOC_LITERAL(11, 119, 11), // "startNodeId"
QT_MOC_LITERAL(12, 131, 9), // "endNodeId"
QT_MOC_LITERAL(13, 141, 26), // "findOptimalCollectionRoute"
QT_MOC_LITERAL(14, 168, 11), // "targetNodes"
QT_MOC_LITERAL(15, 180, 30), // "findOptimalBallCollectionRoute"
QT_MOC_LITERAL(16, 211, 13), // "releaseNodeId"
QT_MOC_LITERAL(17, 225, 13), // "carryCapacity"
QT_MOC_LITERAL(18, 239, 19), // "calculateRouteValue"
QT_MOC_LITERAL(19, 259, 20), // "std::vector<QString>"
QT_MOC_LITERAL(20, 280, 9) // "clearPath"

    },
    "PathfindingEngine\0pathCalculated\0\0"
    "path\0optimalRouteCalculated\0route\0"
    "setNodes\0nodes\0setConnections\0connections\0"
    "findPath\0startNodeId\0endNodeId\0"
    "findOptimalCollectionRoute\0targetNodes\0"
    "findOptimalBallCollectionRoute\0"
    "releaseNodeId\0carryCapacity\0"
    "calculateRouteValue\0std::vector<QString>\0"
    "clearPath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PathfindingEngine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    1,   70,    2, 0x02 /* Public */,
       8,    1,   73,    2, 0x02 /* Public */,
      10,    2,   76,    2, 0x02 /* Public */,
      13,    2,   81,    2, 0x02 /* Public */,
      15,    3,   86,    2, 0x02 /* Public */,
      15,    2,   93,    2, 0x22 /* Public | MethodCloned */,
      18,    2,   98,    2, 0x02 /* Public */,
      20,    0,  103,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantList,    3,
    QMetaType::Void, QMetaType::QVariantList,    5,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariantList,    7,
    QMetaType::Void, QMetaType::QVariantMap,    9,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QVariantList,   11,   14,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QString, QMetaType::Int,   11,   16,   17,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QString,   11,   16,
    QMetaType::Double, 0x80000000 | 19, QMetaType::QString,    5,   16,
    QMetaType::Void,

       0        // eod
};

void PathfindingEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PathfindingEngine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pathCalculated((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 1: _t->optimalRouteCalculated((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 2: _t->setNodes((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 3: _t->setConnections((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 4: { QVariantList _r = _t->findPath((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 5: { QVariantList _r = _t->findOptimalCollectionRoute((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariantList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariantList _r = _t->findOptimalBallCollectionRoute((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 7: { QVariantList _r = _t->findOptimalBallCollectionRoute((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 8: { double _r = _t->calculateRouteValue((*reinterpret_cast< const std::vector<QString>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->clearPath(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PathfindingEngine::*)(const QVariantList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PathfindingEngine::pathCalculated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PathfindingEngine::*)(const QVariantList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PathfindingEngine::optimalRouteCalculated)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PathfindingEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PathfindingEngine.data,
    qt_meta_data_PathfindingEngine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PathfindingEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PathfindingEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PathfindingEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PathfindingEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void PathfindingEngine::pathCalculated(const QVariantList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PathfindingEngine::optimalRouteCalculated(const QVariantList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
