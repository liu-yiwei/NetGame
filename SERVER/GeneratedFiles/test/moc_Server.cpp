/****************************************************************************
** Meta object code from reading C++ file 'Server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameServer_t {
    QByteArrayData data[15];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameServer_t qt_meta_stringdata_GameServer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameServer"
QT_MOC_LITERAL(1, 11, 13), // "connectClient"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "readData"
QT_MOC_LITERAL(4, 35, 14), // "sockDisConnect"
QT_MOC_LITERAL(5, 50, 8), // "sentData"
QT_MOC_LITERAL(6, 59, 14), // "sentDisConnect"
QT_MOC_LITERAL(7, 74, 1), // "i"
QT_MOC_LITERAL(8, 76, 5), // "clear"
QT_MOC_LITERAL(9, 82, 18), // "sockDisConnectSlot"
QT_MOC_LITERAL(10, 101, 6), // "handle"
QT_MOC_LITERAL(11, 108, 2), // "ip"
QT_MOC_LITERAL(12, 111, 4), // "prot"
QT_MOC_LITERAL(13, 116, 8), // "QThread*"
QT_MOC_LITERAL(14, 125, 2) // "th"

    },
    "GameServer\0connectClient\0\0readData\0"
    "sockDisConnect\0sentData\0sentDisConnect\0"
    "i\0clear\0sockDisConnectSlot\0handle\0ip\0"
    "prot\0QThread*\0th"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,
       3,    4,   56,    2, 0x06 /* Public */,
       4,    3,   65,    2, 0x06 /* Public */,
       5,    2,   72,    2, 0x06 /* Public */,
       6,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   80,    2, 0x0a /* Public */,
       9,    4,   81,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort, QMetaType::QByteArray,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort,    2,    2,    2,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort, 0x80000000 | 13,   10,   11,   12,   14,

       0        // eod
};

void GameServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameServer *_t = static_cast<GameServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectClient((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3]))); break;
        case 1: _t->readData((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< const QByteArray(*)>(_a[4]))); break;
        case 2: _t->sockDisConnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 3: _t->sentData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 4: _t->sentDisConnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->clear(); break;
        case 6: _t->sockDisConnectSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< QThread*(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameServer::*_t)(const int , const QString & , const quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameServer::connectClient)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GameServer::*_t)(const int , const QString & , quint16 , const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameServer::readData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GameServer::*_t)(int , QString , quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameServer::sockDisConnect)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GameServer::*_t)(const QByteArray & , const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameServer::sentData)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GameServer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameServer::sentDisConnect)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject GameServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_GameServer.data,
      qt_meta_data_GameServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameServer.stringdata0))
        return static_cast<void*>(const_cast< GameServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int GameServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GameServer::connectClient(const int _t1, const QString & _t2, const quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameServer::readData(const int _t1, const QString & _t2, quint16 _t3, const QByteArray & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameServer::sockDisConnect(int _t1, QString _t2, quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameServer::sentData(const QByteArray & _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GameServer::sentDisConnect(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
