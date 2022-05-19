/****************************************************************************
** Meta object code from reading C++ file 'FileBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DATA/DATA_Base/FileBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileBase_t {
    QByteArrayData data[22];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileBase_t qt_meta_stringdata_FileBase = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FileBase"
QT_MOC_LITERAL(1, 9, 11), // "signal_File"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "fileName"
QT_MOC_LITERAL(4, 31, 4), // "data"
QT_MOC_LITERAL(5, 36, 10), // "signal_Del"
QT_MOC_LITERAL(6, 47, 13), // "signal_Rename"
QT_MOC_LITERAL(7, 61, 7), // "fileOld"
QT_MOC_LITERAL(8, 69, 7), // "fileNew"
QT_MOC_LITERAL(9, 77, 30), // "signal_CommonINFO_FromFileBase"
QT_MOC_LITERAL(10, 108, 7), // "content"
QT_MOC_LITERAL(11, 116, 20), // "slot_onNewConnection"
QT_MOC_LITERAL(12, 137, 16), // "slot_onReadyRead"
QT_MOC_LITERAL(13, 154, 16), // "slot_onConnected"
QT_MOC_LITERAL(14, 171, 19), // "slot_onDisconnected"
QT_MOC_LITERAL(15, 191, 12), // "slot_onError"
QT_MOC_LITERAL(16, 204, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(17, 233, 11), // "socketError"
QT_MOC_LITERAL(18, 245, 23), // "slot_ONOFF_ServerListen"
QT_MOC_LITERAL(19, 269, 4), // "Host"
QT_MOC_LITERAL(20, 274, 4), // "port"
QT_MOC_LITERAL(21, 279, 5) // "ONOFF"

    },
    "FileBase\0signal_File\0\0fileName\0data\0"
    "signal_Del\0signal_Rename\0fileOld\0"
    "fileNew\0signal_CommonINFO_FromFileBase\0"
    "content\0slot_onNewConnection\0"
    "slot_onReadyRead\0slot_onConnected\0"
    "slot_onDisconnected\0slot_onError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "slot_ONOFF_ServerListen\0Host\0port\0"
    "ONOFF"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,
       6,    2,   72,    2, 0x06 /* Public */,
       9,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   80,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,
      13,    0,   82,    2, 0x0a /* Public */,
      14,    0,   83,    2, 0x0a /* Public */,
      15,    1,   84,    2, 0x0a /* Public */,
      18,    3,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   19,   20,   21,

       0        // eod
};

void FileBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_File((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 1: _t->signal_Del((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->signal_Rename((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->signal_CommonINFO_FromFileBase((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slot_onNewConnection(); break;
        case 5: _t->slot_onReadyRead(); break;
        case 6: _t->slot_onConnected(); break;
        case 7: _t->slot_onDisconnected(); break;
        case 8: _t->slot_onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 9: _t->slot_ONOFF_ServerListen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileBase::*)(const QString & , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileBase::signal_File)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileBase::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileBase::signal_Del)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FileBase::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileBase::signal_Rename)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FileBase::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileBase::signal_CommonINFO_FromFileBase)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FileBase.data,
    qt_meta_data_FileBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FileBase::signal_File(const QString & _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileBase::signal_Del(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileBase::signal_Rename(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileBase::signal_CommonINFO_FromFileBase(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
