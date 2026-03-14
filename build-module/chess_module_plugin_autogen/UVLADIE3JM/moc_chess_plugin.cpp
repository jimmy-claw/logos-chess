/****************************************************************************
** Meta object code from reading C++ file 'chess_plugin.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/chess_plugin.h"
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chess_plugin.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11ChessPluginE_t {};
} // unnamed namespace

template <> constexpr inline auto ChessPlugin::qt_create_metaobjectdata<qt_meta_tag_ZN11ChessPluginE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ChessPlugin",
        "version",
        "",
        "initLogos",
        "LogosAPI*",
        "api",
        "newGame",
        "getCurrentFEN",
        "makeMove",
        "fromSquare",
        "toSquare",
        "promotion",
        "getValidMoves",
        "QVariantList",
        "square",
        "getGameState",
        "QVariantMap",
        "loadPosition",
        "fen"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'version'
        QtMocHelpers::MethodData<QString() const>(1, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'initLogos'
        QtMocHelpers::MethodData<void(LogosAPI *)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Method 'newGame'
        QtMocHelpers::MethodData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'getCurrentFEN'
        QtMocHelpers::MethodData<QString() const>(7, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'makeMove'
        QtMocHelpers::MethodData<bool(int, int, const QString &)>(8, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 9 }, { QMetaType::Int, 10 }, { QMetaType::QString, 11 },
        }}),
        // Method 'makeMove'
        QtMocHelpers::MethodData<bool(int, int)>(8, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::Int, 9 }, { QMetaType::Int, 10 },
        }}),
        // Method 'getValidMoves'
        QtMocHelpers::MethodData<QVariantList(int) const>(12, 2, QMC::AccessPublic, 0x80000000 | 13, {{
            { QMetaType::Int, 14 },
        }}),
        // Method 'getGameState'
        QtMocHelpers::MethodData<QVariantMap() const>(15, 2, QMC::AccessPublic, 0x80000000 | 16),
        // Method 'loadPosition'
        QtMocHelpers::MethodData<void(const QString &)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 18 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ChessPlugin, qt_meta_tag_ZN11ChessPluginE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ChessPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ChessPluginE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ChessPluginE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11ChessPluginE_t>.metaTypes,
    nullptr
} };

void ChessPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ChessPlugin *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->initLogos((*reinterpret_cast< std::add_pointer_t<LogosAPI*>>(_a[1]))); break;
        case 2: _t->newGame(); break;
        case 3: { QString _r = _t->getCurrentFEN();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->makeMove((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->makeMove((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariantList _r = _t->getValidMoves((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 7: { QVariantMap _r = _t->getGameState();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->loadPosition((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *ChessPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChessPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ChessPluginE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ChessPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_ChessPlugin[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x20,  'c',  'o',  'm',  '.',  'l', 
    'o',  'g',  'o',  's',  '.',  'm',  'o',  'd', 
    'u',  'l',  'e',  '.',  'P',  'l',  'u',  'g', 
    'i',  'n',  'I',  'n',  't',  'e',  'r',  'f', 
    'a',  'c',  'e', 
    // "className"
    0x03,  0x6b,  'C',  'h',  'e',  's',  's',  'P', 
    'l',  'u',  'g',  'i',  'n', 
    // "MetaData"
    0x04,  0xa9,  0x66,  'a',  'u',  't',  'h',  'o', 
    'r',  0x6a,  'j',  'i',  'm',  'm',  'y',  '-', 
    'c',  'l',  'a',  'w',  0x68,  'c',  'a',  't', 
    'e',  'g',  'o',  'r',  'y',  0x65,  'g',  'a', 
    'm',  'e',  's',  0x6c,  'd',  'e',  'p',  'e', 
    'n',  'd',  'e',  'n',  'c',  'i',  'e',  's', 
    0x81,  0x69,  'k',  'v',  '_',  'm',  'o',  'd', 
    'u',  'l',  'e',  0x6b,  'd',  'e',  's',  'c', 
    'r',  'i',  'p',  't',  'i',  'o',  'n',  0x78, 
    0x21,  'C',  'h',  'e',  's',  's',  ' ',  'g', 
    'a',  'm',  'e',  ' ',  'l',  'o',  'g',  'i', 
    'c',  ' ',  'm',  'o',  'd',  'u',  'l',  'e', 
    ' ',  'f',  'o',  'r',  ' ',  'L',  'o',  'g', 
    'o',  's',  0x64,  'm',  'a',  'i',  'n',  0xa3, 
    0x6c,  'd',  'a',  'r',  'w',  'i',  'n',  '-', 
    'a',  'r',  'm',  '6',  '4',  0x76,  'c',  'h', 
    'e',  's',  's',  '_',  'm',  'o',  'd',  'u', 
    'l',  'e',  '_',  'p',  'l',  'u',  'g',  'i', 
    'n',  '.',  's',  'o',  0x6d,  'l',  'i',  'n', 
    'u',  'x',  '-',  'a',  'a',  'r',  'c',  'h', 
    '6',  '4',  0x76,  'c',  'h',  'e',  's',  's', 
    '_',  'm',  'o',  'd',  'u',  'l',  'e',  '_', 
    'p',  'l',  'u',  'g',  'i',  'n',  '.',  's', 
    'o',  0x6b,  'l',  'i',  'n',  'u',  'x',  '-', 
    'a',  'm',  'd',  '6',  '4',  0x76,  'c',  'h', 
    'e',  's',  's',  '_',  'm',  'o',  'd',  'u', 
    'l',  'e',  '_',  'p',  'l',  'u',  'g',  'i', 
    'n',  '.',  's',  'o',  0x6f,  'm',  'a',  'n', 
    'i',  'f',  'e',  's',  't',  'V',  'e',  'r', 
    's',  'i',  'o',  'n',  0x65,  '0',  '.',  '1', 
    '.',  '0',  0x64,  'n',  'a',  'm',  'e',  0x6c, 
    'c',  'h',  'e',  's',  's',  '_',  'm',  'o', 
    'd',  'u',  'l',  'e',  0x64,  't',  'y',  'p', 
    'e',  0x64,  'c',  'o',  'r',  'e',  0x67,  'v', 
    'e',  'r',  's',  'i',  'o',  'n',  0x65,  '0', 
    '.',  '1',  '.',  '0', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(ChessPlugin, ChessPlugin, qt_pluginMetaDataV2_ChessPlugin)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_ChessPlugin[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x20,  'c',  'o',  'm',  '.',  'l', 
    'o',  'g',  'o',  's',  '.',  'm',  'o',  'd', 
    'u',  'l',  'e',  '.',  'P',  'l',  'u',  'g', 
    'i',  'n',  'I',  'n',  't',  'e',  'r',  'f', 
    'a',  'c',  'e', 
    // "className"
    0x03,  0x6b,  'C',  'h',  'e',  's',  's',  'P', 
    'l',  'u',  'g',  'i',  'n', 
    // "MetaData"
    0x04,  0xa9,  0x66,  'a',  'u',  't',  'h',  'o', 
    'r',  0x6a,  'j',  'i',  'm',  'm',  'y',  '-', 
    'c',  'l',  'a',  'w',  0x68,  'c',  'a',  't', 
    'e',  'g',  'o',  'r',  'y',  0x65,  'g',  'a', 
    'm',  'e',  's',  0x6c,  'd',  'e',  'p',  'e', 
    'n',  'd',  'e',  'n',  'c',  'i',  'e',  's', 
    0x81,  0x69,  'k',  'v',  '_',  'm',  'o',  'd', 
    'u',  'l',  'e',  0x6b,  'd',  'e',  's',  'c', 
    'r',  'i',  'p',  't',  'i',  'o',  'n',  0x78, 
    0x21,  'C',  'h',  'e',  's',  's',  ' ',  'g', 
    'a',  'm',  'e',  ' ',  'l',  'o',  'g',  'i', 
    'c',  ' ',  'm',  'o',  'd',  'u',  'l',  'e', 
    ' ',  'f',  'o',  'r',  ' ',  'L',  'o',  'g', 
    'o',  's',  0x64,  'm',  'a',  'i',  'n',  0xa3, 
    0x6c,  'd',  'a',  'r',  'w',  'i',  'n',  '-', 
    'a',  'r',  'm',  '6',  '4',  0x76,  'c',  'h', 
    'e',  's',  's',  '_',  'm',  'o',  'd',  'u', 
    'l',  'e',  '_',  'p',  'l',  'u',  'g',  'i', 
    'n',  '.',  's',  'o',  0x6d,  'l',  'i',  'n', 
    'u',  'x',  '-',  'a',  'a',  'r',  'c',  'h', 
    '6',  '4',  0x76,  'c',  'h',  'e',  's',  's', 
    '_',  'm',  'o',  'd',  'u',  'l',  'e',  '_', 
    'p',  'l',  'u',  'g',  'i',  'n',  '.',  's', 
    'o',  0x6b,  'l',  'i',  'n',  'u',  'x',  '-', 
    'a',  'm',  'd',  '6',  '4',  0x76,  'c',  'h', 
    'e',  's',  's',  '_',  'm',  'o',  'd',  'u', 
    'l',  'e',  '_',  'p',  'l',  'u',  'g',  'i', 
    'n',  '.',  's',  'o',  0x6f,  'm',  'a',  'n', 
    'i',  'f',  'e',  's',  't',  'V',  'e',  'r', 
    's',  'i',  'o',  'n',  0x65,  '0',  '.',  '1', 
    '.',  '0',  0x64,  'n',  'a',  'm',  'e',  0x6c, 
    'c',  'h',  'e',  's',  's',  '_',  'm',  'o', 
    'd',  'u',  'l',  'e',  0x64,  't',  'y',  'p', 
    'e',  0x64,  'c',  'o',  'r',  'e',  0x67,  'v', 
    'e',  'r',  's',  'i',  'o',  'n',  0x65,  '0', 
    '.',  '1',  '.',  '0', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(ChessPlugin, ChessPlugin)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP
