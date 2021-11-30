/****************************************************************************
** Meta object code from reading C++ file 'datathread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "datathread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datathread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Datathread_t {
    QByteArrayData data[7];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Datathread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Datathread_t qt_meta_stringdata_Datathread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Datathread"
QT_MOC_LITERAL(1, 11, 19), // "entry_data_to_spine"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "test_signal"
QT_MOC_LITERAL(4, 44, 15), // "signal_to_table"
QT_MOC_LITERAL(5, 60, 12), // "dataObtained"
QT_MOC_LITERAL(6, 73, 13) // "init_notifier"

    },
    "Datathread\0entry_data_to_spine\0\0"
    "test_signal\0signal_to_table\0dataObtained\0"
    "init_notifier"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Datathread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Datathread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Datathread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->entry_data_to_spine(); break;
        case 1: _t->test_signal(); break;
        case 2: _t->signal_to_table(); break;
        case 3: _t->dataObtained(); break;
        case 4: _t->init_notifier(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Datathread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Datathread::entry_data_to_spine)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Datathread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Datathread::test_signal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Datathread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Datathread::signal_to_table)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Datathread::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Datathread.data,
    qt_meta_data_Datathread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Datathread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Datathread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Datathread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Datathread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Datathread::entry_data_to_spine()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Datathread::test_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Datathread::signal_to_table()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
