/****************************************************************************
** Meta object code from reading C++ file 'textedit.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MIPS/textedit.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_TextEdit_t {
    uint offsetsAndSizes[16];
    char stringdata0[9];
    char stringdata1[26];
    char stringdata2[1];
    char stringdata3[26];
    char stringdata4[29];
    char stringdata5[17];
    char stringdata6[14];
    char stringdata7[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TextEdit_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TextEdit_t qt_meta_stringdata_TextEdit = {
    {
        QT_MOC_LITERAL(0, 8),  // "TextEdit"
        QT_MOC_LITERAL(9, 25),  // "textEditHScrollBarChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 25),  // "textEditVScrollBarChanged"
        QT_MOC_LITERAL(62, 28),  // "textBrowserVScrollBarChanged"
        QT_MOC_LITERAL(91, 16),  // "scrollBarChanged"
        QT_MOC_LITERAL(108, 13),  // "onTextChanged"
        QT_MOC_LITERAL(122, 16)   // "highlightCurLine"
    },
    "TextEdit",
    "textEditHScrollBarChanged",
    "",
    "textEditVScrollBarChanged",
    "textBrowserVScrollBarChanged",
    "scrollBarChanged",
    "onTextChanged",
    "highlightCurLine"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TextEdit[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TextEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TextEdit.offsetsAndSizes,
    qt_meta_data_TextEdit,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TextEdit_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TextEdit, std::true_type>,
        // method 'textEditHScrollBarChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'textEditVScrollBarChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'textBrowserVScrollBarChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scrollBarChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'highlightCurLine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextEdit *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->textEditHScrollBarChanged(); break;
        case 1: _t->textEditVScrollBarChanged(); break;
        case 2: _t->textBrowserVScrollBarChanged(); break;
        case 3: _t->scrollBarChanged(); break;
        case 4: _t->onTextChanged(); break;
        case 5: _t->highlightCurLine(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *TextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextEdit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
