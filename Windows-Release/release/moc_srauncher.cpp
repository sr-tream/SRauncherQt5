/****************************************************************************
** Meta object code from reading C++ file 'srauncher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../srauncher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'srauncher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SRauncher_t {
    QByteArrayData data[23];
    char stringdata0[404];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SRauncher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SRauncher_t qt_meta_stringdata_SRauncher = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SRauncher"
QT_MOC_LITERAL(1, 10, 16), // "updateServerInfo"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "on_btnAddSrv_clicked"
QT_MOC_LITERAL(4, 49, 22), // "on_srvList_itemClicked"
QT_MOC_LITERAL(5, 72, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 89, 4), // "item"
QT_MOC_LITERAL(7, 94, 21), // "on_btnConnect_clicked"
QT_MOC_LITERAL(8, 116, 20), // "on_btnRename_clicked"
QT_MOC_LITERAL(9, 137, 20), // "on_btnRemove_clicked"
QT_MOC_LITERAL(10, 158, 29), // "on_srvList_currentItemChanged"
QT_MOC_LITERAL(11, 188, 7), // "current"
QT_MOC_LITERAL(12, 196, 8), // "previous"
QT_MOC_LITERAL(13, 205, 20), // "on_btnInject_clicked"
QT_MOC_LITERAL(14, 226, 22), // "on_btnSettings_clicked"
QT_MOC_LITERAL(15, 249, 22), // "on_tsUrl_linkActivated"
QT_MOC_LITERAL(16, 272, 4), // "link"
QT_MOC_LITERAL(17, 277, 30), // "on_cbGroup_currentIndexChanged"
QT_MOC_LITERAL(18, 308, 4), // "arg1"
QT_MOC_LITERAL(19, 313, 25), // "on_btnGroupRemove_clicked"
QT_MOC_LITERAL(20, 339, 22), // "on_btnGroupAdd_clicked"
QT_MOC_LITERAL(21, 362, 19), // "on_btnDebug_clicked"
QT_MOC_LITERAL(22, 382, 21) // "on_toolButton_clicked"

    },
    "SRauncher\0updateServerInfo\0\0"
    "on_btnAddSrv_clicked\0on_srvList_itemClicked\0"
    "QListWidgetItem*\0item\0on_btnConnect_clicked\0"
    "on_btnRename_clicked\0on_btnRemove_clicked\0"
    "on_srvList_currentItemChanged\0current\0"
    "previous\0on_btnInject_clicked\0"
    "on_btnSettings_clicked\0on_tsUrl_linkActivated\0"
    "link\0on_cbGroup_currentIndexChanged\0"
    "arg1\0on_btnGroupRemove_clicked\0"
    "on_btnGroupAdd_clicked\0on_btnDebug_clicked\0"
    "on_toolButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SRauncher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    2,   97,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    1,  104,    2, 0x08 /* Private */,
      17,    1,  107,    2, 0x08 /* Private */,
      19,    0,  110,    2, 0x08 /* Private */,
      20,    0,  111,    2, 0x08 /* Private */,
      21,    0,  112,    2, 0x08 /* Private */,
      22,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SRauncher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SRauncher *_t = static_cast<SRauncher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateServerInfo(); break;
        case 1: _t->on_btnAddSrv_clicked(); break;
        case 2: _t->on_srvList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_btnConnect_clicked(); break;
        case 4: _t->on_btnRename_clicked(); break;
        case 5: _t->on_btnRemove_clicked(); break;
        case 6: _t->on_srvList_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 7: _t->on_btnInject_clicked(); break;
        case 8: _t->on_btnSettings_clicked(); break;
        case 9: _t->on_tsUrl_linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_cbGroup_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_btnGroupRemove_clicked(); break;
        case 12: _t->on_btnGroupAdd_clicked(); break;
        case 13: _t->on_btnDebug_clicked(); break;
        case 14: _t->on_toolButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SRauncher::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SRauncher.data,
      qt_meta_data_SRauncher,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SRauncher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SRauncher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SRauncher.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SRauncher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
