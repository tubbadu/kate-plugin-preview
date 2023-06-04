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
struct qt_meta_stringdata_MarkdownPandocPreviewPlugin_t {
    QByteArrayData data[1];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MarkdownPandocPreviewPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MarkdownPandocPreviewPlugin_t qt_meta_stringdata_MarkdownPandocPreviewPlugin = {
    {
QT_MOC_LITERAL(0, 0, 27) // "MarkdownPandocPreviewPlugin"

    },
    "MarkdownPandocPreviewPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MarkdownPandocPreviewPlugin[] = {

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

void MarkdownPandocPreviewPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject MarkdownPandocPreviewPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<KTextEditor::Plugin::staticMetaObject>(),
    qt_meta_stringdata_MarkdownPandocPreviewPlugin.data,
    qt_meta_data_MarkdownPandocPreviewPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MarkdownPandocPreviewPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MarkdownPandocPreviewPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MarkdownPandocPreviewPlugin.stringdata0))
        return static_cast<void*>(this);
    return KTextEditor::Plugin::qt_metacast(_clname);
}

int MarkdownPandocPreviewPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KTextEditor::Plugin::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MarkdownPandocPreviewPluginView_t {
    QByteArrayData data[1];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MarkdownPandocPreviewPluginView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MarkdownPandocPreviewPluginView_t qt_meta_stringdata_MarkdownPandocPreviewPluginView = {
    {
QT_MOC_LITERAL(0, 0, 31) // "MarkdownPandocPreviewPluginView"

    },
    "MarkdownPandocPreviewPluginView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MarkdownPandocPreviewPluginView[] = {

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

void MarkdownPandocPreviewPluginView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject MarkdownPandocPreviewPluginView::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MarkdownPandocPreviewPluginView.data,
    qt_meta_data_MarkdownPandocPreviewPluginView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MarkdownPandocPreviewPluginView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MarkdownPandocPreviewPluginView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MarkdownPandocPreviewPluginView.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "KXMLGUIClient"))
        return static_cast< KXMLGUIClient*>(this);
    return QObject::qt_metacast(_clname);
}

int MarkdownPandocPreviewPluginView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
