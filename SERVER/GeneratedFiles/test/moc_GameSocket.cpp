/****************************************************************************
** Meta object code from reading C++ file 'GameSocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GameSocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameSocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameSocket_t {
    QByteArrayData data[9];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameSocket_t qt_meta_stringdata_GameSocket = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameSocket"
QT_MOC_LITERAL(1, 11, 14), // "sockDisConnect"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "QThread*"
QT_MOC_LITERAL(4, 36, 8), // "sentData"
QT_MOC_LITERAL(5, 45, 9), // "disConTcp"
QT_MOC_LITERAL(6, 55, 1), // "i"
QT_MOC_LITERAL(7, 57, 8), // "readData"
QT_MOC_LITERAL(8, 66, 9) // "startNext"

    },
    "GameSocket\0sockDisConnect\0\0QThread*\0"
    "sentData\0disConTcp\0i\0readData\0startNext"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   48,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x09 /* Protected */,
       8,    0,   57,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort, 0x80000000 | 3,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameSocket *_t = static_cast<GameSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sockDisConnect((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3])),(*reinterpret_cast< QThread*(*)>(_a[4]))); break;
        case 1: _t->sentData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 2: _t->disConTcp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->readData(); break;
        case 4: _t->startNext(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameSocket::*_t)(const int , const QString & , const quint16 , QThread * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameSocket::sockDisConnect)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GameSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_GameSocket.data,
      qt_meta_data_GameSocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameSocket.stringdata0))
        return static_cast<void*>(const_cast< GameSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int GameSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void GameSocket::sockDisConnect(const int _t1, const QString & _t2, const quint16 _t3, QThread * _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
