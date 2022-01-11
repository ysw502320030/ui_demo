/****************************************************************************
** Meta object code from reading C++ file 'dialogspine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SpineToAttachUI/dialogspine.h"
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
    QByteArrayData data[18];
    char stringdata0[396];
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
QT_MOC_LITERAL(3, 37, 17), // "CloseGraphSetting"
QT_MOC_LITERAL(4, 55, 13), // "handleTimeout"
QT_MOC_LITERAL(5, 69, 23), // "handle_readNotification"
QT_MOC_LITERAL(6, 93, 6), // "socket"
QT_MOC_LITERAL(7, 100, 13), // "enlarge_scale"
QT_MOC_LITERAL(8, 114, 12), // "shrink_scale"
QT_MOC_LITERAL(9, 127, 18), // "test_label_clicked"
QT_MOC_LITERAL(10, 146, 16), // "FocusFirstWidget"
QT_MOC_LITERAL(11, 163, 41), // "on_comboBox_4_ch1Zoom_current..."
QT_MOC_LITERAL(12, 205, 5), // "index"
QT_MOC_LITERAL(13, 211, 41), // "on_comboBox_3_ch2Zoom_current..."
QT_MOC_LITERAL(14, 253, 41), // "on_comboBox_2_ch3Zoom_current..."
QT_MOC_LITERAL(15, 295, 47), // "on_comboBox_5_change_xRange_c..."
QT_MOC_LITERAL(16, 343, 25), // "on_pushButton_clr_clicked"
QT_MOC_LITERAL(17, 369, 26) // "on_pushButton_exit_clicked"

    },
    "DialogSpine\0signal_to_handleTimeout\0"
    "\0CloseGraphSetting\0handleTimeout\0"
    "handle_readNotification\0socket\0"
    "enlarge_scale\0shrink_scale\0"
    "test_label_clicked\0FocusFirstWidget\0"
    "on_comboBox_4_ch1Zoom_currentIndexChanged\0"
    "index\0on_comboBox_3_ch2Zoom_currentIndexChanged\0"
    "on_comboBox_2_ch3Zoom_currentIndexChanged\0"
    "on_comboBox_5_change_xRange_currentIndexChanged\0"
    "on_pushButton_clr_clicked\0"
    "on_pushButton_exit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogSpine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   86,    2, 0x0a /* Public */,
       5,    1,   87,    2, 0x0a /* Public */,
       7,    0,   90,    2, 0x0a /* Public */,
       8,    0,   91,    2, 0x0a /* Public */,
       9,    0,   92,    2, 0x0a /* Public */,
      10,    0,   93,    2, 0x0a /* Public */,
      11,    1,   94,    2, 0x08 /* Private */,
      13,    1,   97,    2, 0x08 /* Private */,
      14,    1,  100,    2, 0x08 /* Private */,
      15,    1,  103,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
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
        case 1: _t->CloseGraphSetting(); break;
        case 2: _t->handleTimeout(); break;
        case 3: _t->handle_readNotification((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->enlarge_scale(); break;
        case 5: _t->shrink_scale(); break;
        case 6: _t->test_label_clicked(); break;
        case 7: _t->FocusFirstWidget(); break;
        case 8: _t->on_comboBox_4_ch1Zoom_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_comboBox_3_ch2Zoom_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_comboBox_2_ch3Zoom_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_comboBox_5_change_xRange_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_clr_clicked(); break;
        case 13: _t->on_pushButton_exit_clicked(); break;
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
        {
            using _t = void (DialogSpine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogSpine::CloseGraphSetting)) {
                *result = 1;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void DialogSpine::signal_to_handleTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DialogSpine::CloseGraphSetting()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
