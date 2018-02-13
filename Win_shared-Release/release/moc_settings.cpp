/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSettings_t {
    QByteArrayData data[11];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSettings_t qt_meta_stringdata_CSettings = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CSettings"
QT_MOC_LITERAL(1, 10, 22), // "on_cbAsiLoader_toggled"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "checked"
QT_MOC_LITERAL(4, 42, 20), // "on_cbWinMode_toggled"
QT_MOC_LITERAL(5, 63, 20), // "on_btnImport_clicked"
QT_MOC_LITERAL(6, 84, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(7, 116, 5), // "index"
QT_MOC_LITERAL(8, 122, 20), // "on_dial_valueChanged"
QT_MOC_LITERAL(9, 143, 5), // "value"
QT_MOC_LITERAL(10, 149, 33) // "on_comboBox_2_currentIndexCha..."

    },
    "CSettings\0on_cbAsiLoader_toggled\0\0"
    "checked\0on_cbWinMode_toggled\0"
    "on_btnImport_clicked\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_dial_valueChanged\0value\0"
    "on_comboBox_2_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    0,   50,    2, 0x08 /* Private */,
       6,    1,   51,    2, 0x08 /* Private */,
       8,    1,   54,    2, 0x08 /* Private */,
      10,    1,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void CSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSettings *_t = static_cast<CSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_cbAsiLoader_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_cbWinMode_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_btnImport_clicked(); break;
        case 3: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CSettings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CSettings.data,
      qt_meta_data_CSettings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSettings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
