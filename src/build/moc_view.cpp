/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../headers/view.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
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
struct qt_meta_stringdata_CLASSs21SCOPEViewENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSs21SCOPEViewENDCLASS = QtMocHelpers::stringData(
    "s21::View",
    "digits_numbers",
    "",
    "math_func",
    "delete_all_text",
    "backspace",
    "equal",
    "credit_window",
    "deposit_window",
    "draw_graph"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSs21SCOPEViewENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[10];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[16];
    char stringdata5[10];
    char stringdata6[6];
    char stringdata7[14];
    char stringdata8[15];
    char stringdata9[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSs21SCOPEViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSs21SCOPEViewENDCLASS_t qt_meta_stringdata_CLASSs21SCOPEViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "s21::View"
        QT_MOC_LITERAL(10, 14),  // "digits_numbers"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 9),  // "math_func"
        QT_MOC_LITERAL(36, 15),  // "delete_all_text"
        QT_MOC_LITERAL(52, 9),  // "backspace"
        QT_MOC_LITERAL(62, 5),  // "equal"
        QT_MOC_LITERAL(68, 13),  // "credit_window"
        QT_MOC_LITERAL(82, 14),  // "deposit_window"
        QT_MOC_LITERAL(97, 10)   // "draw_graph"
    },
    "s21::View",
    "digits_numbers",
    "",
    "math_func",
    "delete_all_text",
    "backspace",
    "equal",
    "credit_window",
    "deposit_window",
    "draw_graph"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSs21SCOPEViewENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject s21::View::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSs21SCOPEViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSs21SCOPEViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSs21SCOPEViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<View, std::true_type>,
        // method 'digits_numbers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'math_func'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'delete_all_text'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'backspace'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'equal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'credit_window'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deposit_window'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'draw_graph'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void s21::View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<View *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->digits_numbers(); break;
        case 1: _t->math_func(); break;
        case 2: _t->delete_all_text(); break;
        case 3: _t->backspace(); break;
        case 4: _t->equal(); break;
        case 5: _t->credit_window(); break;
        case 6: _t->deposit_window(); break;
        case 7: _t->draw_graph(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *s21::View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSs21SCOPEViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int s21::View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
