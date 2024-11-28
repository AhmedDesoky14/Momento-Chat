/****************************************************************************
** Meta object code from reading C++ file 'loadingscreen_ui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../loadingscreen_ui.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loadingscreen_ui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSloadingscreen_uiENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSloadingscreen_uiENDCLASS = QtMocHelpers::stringData(
    "loadingscreen_ui",
    "ShowWindowSlot",
    "",
    "CloseWindowSlot",
    "SetLoadingBarSlot",
    "val",
    "SetLoadingTextSlot",
    "text",
    "Style"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSloadingscreen_uiENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[17];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[18];
    char stringdata5[4];
    char stringdata6[19];
    char stringdata7[5];
    char stringdata8[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSloadingscreen_uiENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSloadingscreen_uiENDCLASS_t qt_meta_stringdata_CLASSloadingscreen_uiENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "loadingscreen_ui"
        QT_MOC_LITERAL(17, 14),  // "ShowWindowSlot"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 15),  // "CloseWindowSlot"
        QT_MOC_LITERAL(49, 17),  // "SetLoadingBarSlot"
        QT_MOC_LITERAL(67, 3),  // "val"
        QT_MOC_LITERAL(71, 18),  // "SetLoadingTextSlot"
        QT_MOC_LITERAL(90, 4),  // "text"
        QT_MOC_LITERAL(95, 5)   // "Style"
    },
    "loadingscreen_ui",
    "ShowWindowSlot",
    "",
    "CloseWindowSlot",
    "SetLoadingBarSlot",
    "val",
    "SetLoadingTextSlot",
    "text",
    "Style"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSloadingscreen_uiENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x0a,    1 /* Public */,
       3,    0,   39,    2, 0x0a,    2 /* Public */,
       4,    1,   40,    2, 0x0a,    3 /* Public */,
       6,    2,   43,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject loadingscreen_ui::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSloadingscreen_uiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSloadingscreen_uiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSloadingscreen_uiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<loadingscreen_ui, std::true_type>,
        // method 'ShowWindowSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CloseWindowSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SetLoadingBarSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SetLoadingTextSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void loadingscreen_ui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<loadingscreen_ui *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ShowWindowSlot(); break;
        case 1: _t->CloseWindowSlot(); break;
        case 2: _t->SetLoadingBarSlot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->SetLoadingTextSlot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *loadingscreen_ui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loadingscreen_ui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSloadingscreen_uiENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int loadingscreen_ui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
