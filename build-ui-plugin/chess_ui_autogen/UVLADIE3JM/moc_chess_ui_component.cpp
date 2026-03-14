/****************************************************************************
** Meta object code from reading C++ file 'chess_ui_component.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/chess_ui_component.h"
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chess_ui_component.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
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
struct qt_meta_tag_ZN16ChessUIComponentE_t {};
} // unnamed namespace

template <> constexpr inline auto ChessUIComponent::qt_create_metaobjectdata<qt_meta_tag_ZN16ChessUIComponentE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ChessUIComponent"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ChessUIComponent, qt_meta_tag_ZN16ChessUIComponentE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ChessUIComponent::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16ChessUIComponentE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16ChessUIComponentE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16ChessUIComponentE_t>.metaTypes,
    nullptr
} };

void ChessUIComponent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ChessUIComponent *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *ChessUIComponent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChessUIComponent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16ChessUIComponentE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IComponent"))
        return static_cast< IComponent*>(this);
    if (!strcmp(_clname, "com.logos.component.IComponent"))
        return static_cast< IComponent*>(this);
    return QObject::qt_metacast(_clname);
}

int ChessUIComponent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_ChessUIComponent[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1e,  'c',  'o',  'm',  '.',  'l', 
    'o',  'g',  'o',  's',  '.',  'c',  'o',  'm', 
    'p',  'o',  'n',  'e',  'n',  't',  '.',  'I', 
    'C',  'o',  'm',  'p',  'o',  'n',  'e',  'n', 
    't', 
    // "className"
    0x03,  0x70,  'C',  'h',  'e',  's',  's',  'U', 
    'I',  'C',  'o',  'm',  'p',  'o',  'n',  'e', 
    'n',  't', 
    // "MetaData"
    0x04,  0xa9,  0x66,  'a',  'u',  't',  'h',  'o', 
    'r',  0x6a,  'j',  'i',  'm',  'm',  'y',  '-', 
    'c',  'l',  'a',  'w',  0x68,  'c',  'a',  't', 
    'e',  'g',  'o',  'r',  'y',  0x65,  'g',  'a', 
    'm',  'e',  's',  0x6c,  'd',  'e',  'p',  'e', 
    'n',  'd',  'e',  'n',  'c',  'i',  'e',  's', 
    0x81,  0x6c,  'c',  'h',  'e',  's',  's',  '_', 
    'm',  'o',  'd',  'u',  'l',  'e',  0x6b,  'd', 
    'e',  's',  'c',  'r',  'i',  'p',  't',  'i', 
    'o',  'n',  0x77,  'C',  'h',  'e',  's',  's', 
    ' ',  'g',  'a',  'm',  'e',  ' ',  'U',  'I', 
    ' ',  'f',  'o',  'r',  ' ',  'L',  'o',  'g', 
    'o',  's',  0x64,  'm',  'a',  'i',  'n',  0xa3, 
    0x6c,  'd',  'a',  'r',  'w',  'i',  'n',  '-', 
    'a',  'r',  'm',  '6',  '4',  0x6b,  'c',  'h', 
    'e',  's',  's',  '_',  'u',  'i',  '.',  's', 
    'o',  0x6d,  'l',  'i',  'n',  'u',  'x',  '-', 
    'a',  'a',  'r',  'c',  'h',  '6',  '4',  0x6b, 
    'c',  'h',  'e',  's',  's',  '_',  'u',  'i', 
    '.',  's',  'o',  0x6b,  'l',  'i',  'n',  'u', 
    'x',  '-',  'a',  'm',  'd',  '6',  '4',  0x6b, 
    'c',  'h',  'e',  's',  's',  '_',  'u',  'i', 
    '.',  's',  'o',  0x6f,  'm',  'a',  'n',  'i', 
    'f',  'e',  's',  't',  'V',  'e',  'r',  's', 
    'i',  'o',  'n',  0x65,  '0',  '.',  '1',  '.', 
    '0',  0x64,  'n',  'a',  'm',  'e',  0x68,  'c', 
    'h',  'e',  's',  's',  '_',  'u',  'i',  0x64, 
    't',  'y',  'p',  'e',  0x62,  'u',  'i',  0x67, 
    'v',  'e',  'r',  's',  'i',  'o',  'n',  0x65, 
    '0',  '.',  '1',  '.',  '0', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(ChessUIComponent, ChessUIComponent, qt_pluginMetaDataV2_ChessUIComponent)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_ChessUIComponent[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1e,  'c',  'o',  'm',  '.',  'l', 
    'o',  'g',  'o',  's',  '.',  'c',  'o',  'm', 
    'p',  'o',  'n',  'e',  'n',  't',  '.',  'I', 
    'C',  'o',  'm',  'p',  'o',  'n',  'e',  'n', 
    't', 
    // "className"
    0x03,  0x70,  'C',  'h',  'e',  's',  's',  'U', 
    'I',  'C',  'o',  'm',  'p',  'o',  'n',  'e', 
    'n',  't', 
    // "MetaData"
    0x04,  0xa9,  0x66,  'a',  'u',  't',  'h',  'o', 
    'r',  0x6a,  'j',  'i',  'm',  'm',  'y',  '-', 
    'c',  'l',  'a',  'w',  0x68,  'c',  'a',  't', 
    'e',  'g',  'o',  'r',  'y',  0x65,  'g',  'a', 
    'm',  'e',  's',  0x6c,  'd',  'e',  'p',  'e', 
    'n',  'd',  'e',  'n',  'c',  'i',  'e',  's', 
    0x81,  0x6c,  'c',  'h',  'e',  's',  's',  '_', 
    'm',  'o',  'd',  'u',  'l',  'e',  0x6b,  'd', 
    'e',  's',  'c',  'r',  'i',  'p',  't',  'i', 
    'o',  'n',  0x77,  'C',  'h',  'e',  's',  's', 
    ' ',  'g',  'a',  'm',  'e',  ' ',  'U',  'I', 
    ' ',  'f',  'o',  'r',  ' ',  'L',  'o',  'g', 
    'o',  's',  0x64,  'm',  'a',  'i',  'n',  0xa3, 
    0x6c,  'd',  'a',  'r',  'w',  'i',  'n',  '-', 
    'a',  'r',  'm',  '6',  '4',  0x6b,  'c',  'h', 
    'e',  's',  's',  '_',  'u',  'i',  '.',  's', 
    'o',  0x6d,  'l',  'i',  'n',  'u',  'x',  '-', 
    'a',  'a',  'r',  'c',  'h',  '6',  '4',  0x6b, 
    'c',  'h',  'e',  's',  's',  '_',  'u',  'i', 
    '.',  's',  'o',  0x6b,  'l',  'i',  'n',  'u', 
    'x',  '-',  'a',  'm',  'd',  '6',  '4',  0x6b, 
    'c',  'h',  'e',  's',  's',  '_',  'u',  'i', 
    '.',  's',  'o',  0x6f,  'm',  'a',  'n',  'i', 
    'f',  'e',  's',  't',  'V',  'e',  'r',  's', 
    'i',  'o',  'n',  0x65,  '0',  '.',  '1',  '.', 
    '0',  0x64,  'n',  'a',  'm',  'e',  0x68,  'c', 
    'h',  'e',  's',  's',  '_',  'u',  'i',  0x64, 
    't',  'y',  'p',  'e',  0x62,  'u',  'i',  0x67, 
    'v',  'e',  'r',  's',  'i',  'o',  'n',  0x65, 
    '0',  '.',  '1',  '.',  '0', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(ChessUIComponent, ChessUIComponent)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP
