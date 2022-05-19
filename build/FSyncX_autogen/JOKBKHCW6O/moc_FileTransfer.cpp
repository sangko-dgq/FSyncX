/****************************************************************************
** Meta object code from reading C++ file 'FileTransfer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DATA/DATA_Sync/FileTransfer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileTransfer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileTransfer_t {
    QByteArrayData data[15];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileTransfer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileTransfer_t qt_meta_stringdata_FileTransfer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FileTransfer"
QT_MOC_LITERAL(1, 13, 34), // "signal_CommonINFO_FromFileTra..."
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 7), // "content"
QT_MOC_LITERAL(4, 57, 16), // "slot_onReadyRead"
QT_MOC_LITERAL(5, 74, 16), // "slot_onConnected"
QT_MOC_LITERAL(6, 91, 19), // "slot_onDisconnected"
QT_MOC_LITERAL(7, 111, 12), // "slot_onError"
QT_MOC_LITERAL(8, 124, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 153, 11), // "socketError"
QT_MOC_LITERAL(10, 165, 19), // "slot_ConnectToFBase"
QT_MOC_LITERAL(11, 185, 4), // "Host"
QT_MOC_LITERAL(12, 190, 4), // "port"
QT_MOC_LITERAL(13, 195, 31), // "slot_Reject_or_Break_Connection"
QT_MOC_LITERAL(14, 227, 4) // "Type"

    },
    "FileTransfer\0signal_CommonINFO_FromFileTransfer\0"
    "\0content\0slot_onReadyRead\0slot_onConnected\0"
    "slot_onDisconnected\0slot_onError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "slot_ConnectToFBase\0Host\0port\0"
    "slot_Reject_or_Break_Connection\0Type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileTransfer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x0a /* Public */,
       5,    0,   53,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,
      10,    2,   58,    2, 0x0a /* Public */,
      13,    3,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   14,

       0        // eod
};

void FileTransfer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileTransfer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_CommonINFO_FromFileTransfer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slot_onReadyRead(); break;
        case 2: _t->slot_onConnected(); break;
        case 3: _t->slot_onDisconnected(); break;
        case 4: _t->slot_onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->slot_ConnectToFBase((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->slot_Reject_or_Break_Connection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
            using _t = void (FileTransfer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileTransfer::signal_CommonINFO_FromFileTransfer)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileTransfer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FileTransfer.data,
    qt_meta_data_FileTransfer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileTransfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileTransfer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileTransfer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileTransfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FileTransfer::signal_CommonINFO_FromFileTransfer(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
