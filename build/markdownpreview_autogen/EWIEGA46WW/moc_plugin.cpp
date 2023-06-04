/****************************************************************************
** Meta object code from reading C++ file 'plugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../plugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MarkdownPreviewPlugin_t {
    QByteArrayData data[1];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MarkdownPreviewPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MarkdownPreviewPlugin_t qt_meta_stringdata_MarkdownPreviewPlugin = {
    {
QT_MOC_LITERAL(0, 0, 21) // "MarkdownPreviewPlugin"

    },
    "MarkdownPreviewPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MarkdownPreviewPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MarkdownPreviewPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject MarkdownPreviewPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<KTextEditor::Plugin::staticMetaObject>(),
    qt_meta_stringdata_MarkdownPreviewPlugin.data,
    qt_meta_data_MarkdownPreviewPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MarkdownPreviewPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MarkdownPreviewPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MarkdownPreviewPlugin.stringdata0))
        return static_cast<void*>(this);
    return KTextEditor::Plugin::qt_metacast(_clname);
}

int MarkdownPreviewPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KTextEditor::Plugin::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MarkdownPreviewPluginView_t {
    QByteArrayData data[1];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MarkdownPreviewPluginView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MarkdownPreviewPluginView_t qt_meta_stringdata_MarkdownPreviewPluginView = {
    {
QT_MOC_LITERAL(0, 0, 25) // "MarkdownPreviewPluginView"

    },
    "MarkdownPreviewPluginView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MarkdownPreviewPluginView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MarkdownPreviewPluginView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject MarkdownPreviewPluginView::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MarkdownPreviewPluginView.data,
    qt_meta_data_MarkdownPreviewPluginView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MarkdownPreviewPluginView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MarkdownPreviewPluginView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MarkdownPreviewPluginView.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "KXMLGUIClient"))
        return static_cast< KXMLGUIClient*>(this);
    return QObject::qt_metacast(_clname);
}

int MarkdownPreviewPluginView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
