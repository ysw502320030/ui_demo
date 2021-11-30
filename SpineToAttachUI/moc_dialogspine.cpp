/****************************************************************************
** Meta object code from reading C++ file 'dialogspine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogspine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogspine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogSpine_t {
    QByteArrayData data[8];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogSpine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogSpine_t qt_meta_stringdata_DialogSpine = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DialogSpine"
QT_MOC_LITERAL(1, 12, 23), // "signal_to_handleTimeout"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "handleTimeout"
QT_MOC_LITERAL(4, 51, 23), // "handle_readNotification"
QT_MOC_LITERAL(5, 75, 6), // "socket"
QT_MOC_LITERAL(6, 82, 13), // "enlarge_scale"
QT_MOC_LITERAL(7, 96, 12) // "shrink_scale"

    },
    "DialogSpine\0signal_to_handleTimeout\0"
    "\0handleTimeout\0handle_readNotification\0"
    "socket\0enlarge_scale\0shrink_scale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogSpine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogSpine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogSpine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_to_handleTimeout(); break;
        case 1: _t->handleTimeout(); break;
        case 2: _t->handle_readNotification((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->enlarge_scale(); break;
        case 4: _t->shrink_scale(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogSpine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogSpine::signal_to_handleTimeout)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogSpine::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_DialogSpine.data,
    qt_meta_data_DialogSpine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogSpine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogSpine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogSpine.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogSpine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void DialogSpine::signal_to_handleTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
