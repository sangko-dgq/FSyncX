/****************************************************************************
** Meta object code from reading C++ file 'FileWatcher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DATA/DATA_Sync/FileWatcher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileWatcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileWatcher_t {
    QByteArrayData data[13];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileWatcher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileWatcher_t qt_meta_stringdata_FileWatcher = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FileWatcher"
QT_MOC_LITERAL(1, 12, 23), // "singal_DirectoryChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "path"
QT_MOC_LITERAL(4, 42, 16), // "singal_FileAdded"
QT_MOC_LITERAL(5, 59, 4), // "file"
QT_MOC_LITERAL(6, 64, 18), // "singal_FileRemoved"
QT_MOC_LITERAL(7, 83, 18), // "singal_FileChanged"
QT_MOC_LITERAL(8, 102, 18), // "singal_FileRenamed"
QT_MOC_LITERAL(9, 121, 7), // "oldName"
QT_MOC_LITERAL(10, 129, 7), // "newName"
QT_MOC_LITERAL(11, 137, 18), // "onDirectoryChanged"
QT_MOC_LITERAL(12, 156, 13) // "onFileChanged"

    },
    "FileWatcher\0singal_DirectoryChanged\0"
    "\0path\0singal_FileAdded\0file\0"
    "singal_FileRemoved\0singal_FileChanged\0"
    "singal_FileRenamed\0oldName\0newName\0"
    "onDirectoryChanged\0onFileChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileWatcher[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,
       7,    1,   58,    2, 0x06 /* Public */,
       8,    2,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   66,    2, 0x08 /* Private */,
      12,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void FileWatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileWatcher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->singal_DirectoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->singal_FileAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->singal_FileRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->singal_FileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->singal_FileRenamed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->onDirectoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onFileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileWatcher::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileWatcher::singal_DirectoryChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileWatcher::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileWatcher::singal_FileAdded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FileWatcher::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileWatcher::singal_FileRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FileWatcher::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileWatcher::singal_FileChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FileWatcher::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileWatcher::singal_FileRenamed)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileWatcher::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FileWatcher.data,
    qt_meta_data_FileWatcher,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileWatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileWatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileWatcher.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileWatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FileWatcher::singal_DirectoryChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileWatcher::singal_FileAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileWatcher::singal_FileRemoved(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileWatcher::singal_FileChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FileWatcher::singal_FileRenamed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
