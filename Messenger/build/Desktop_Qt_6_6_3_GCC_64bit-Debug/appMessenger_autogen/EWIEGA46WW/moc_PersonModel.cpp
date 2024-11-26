/****************************************************************************
** Meta object code from reading C++ file 'PersonModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../PersonModel.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PersonModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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
struct qt_meta_stringdata_CLASSPersonModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPersonModelENDCLASS = QtMocHelpers::stringData(
    "PersonModel",
    "currentChatChanged",
    "",
    "currentAvatarChanged",
    "currentNameChanged",
    "receiveNewMsg",
    "msg",
    "handleUserActive",
    "user",
    "clickChat",
    "index",
    "sendMsg",
    "currentChat",
    "ChatModel*",
    "currentAvatar",
    "currentName"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPersonModelENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[12];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[19];
    char stringdata5[14];
    char stringdata6[4];
    char stringdata7[17];
    char stringdata8[5];
    char stringdata9[10];
    char stringdata10[6];
    char stringdata11[8];
    char stringdata12[12];
    char stringdata13[11];
    char stringdata14[14];
    char stringdata15[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPersonModelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPersonModelENDCLASS_t qt_meta_stringdata_CLASSPersonModelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "PersonModel"
        QT_MOC_LITERAL(12, 18),  // "currentChatChanged"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 20),  // "currentAvatarChanged"
        QT_MOC_LITERAL(53, 18),  // "currentNameChanged"
        QT_MOC_LITERAL(72, 13),  // "receiveNewMsg"
        QT_MOC_LITERAL(86, 3),  // "msg"
        QT_MOC_LITERAL(90, 16),  // "handleUserActive"
        QT_MOC_LITERAL(107, 4),  // "user"
        QT_MOC_LITERAL(112, 9),  // "clickChat"
        QT_MOC_LITERAL(122, 5),  // "index"
        QT_MOC_LITERAL(128, 7),  // "sendMsg"
        QT_MOC_LITERAL(136, 11),  // "currentChat"
        QT_MOC_LITERAL(148, 10),  // "ChatModel*"
        QT_MOC_LITERAL(159, 13),  // "currentAvatar"
        QT_MOC_LITERAL(173, 11)   // "currentName"
    },
    "PersonModel",
    "currentChatChanged",
    "",
    "currentAvatarChanged",
    "currentNameChanged",
    "receiveNewMsg",
    "msg",
    "handleUserActive",
    "user",
    "clickChat",
    "index",
    "sendMsg",
    "currentChat",
    "ChatModel*",
    "currentAvatar",
    "currentName"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPersonModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       3,   71, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    4 /* Public */,
       3,    0,   57,    2, 0x06,    5 /* Public */,
       4,    0,   58,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   59,    2, 0x0a,    7 /* Public */,
       7,    1,   62,    2, 0x0a,    9 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   65,    2, 0x02,   11 /* Public */,
      11,    1,   68,    2, 0x02,   13 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,    6,

 // properties: name, type, flags
      12, 0x80000000 | 13, 0x0001590b, uint(0), 0,
      14, QMetaType::QString, 0x00015001, uint(1), 0,
      15, QMetaType::QString, 0x00015001, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject PersonModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSPersonModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPersonModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPersonModelENDCLASS_t,
        // property 'currentChat'
        QtPrivate::TypeAndForceComplete<ChatModel*, std::true_type>,
        // property 'currentAvatar'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PersonModel, std::true_type>,
        // method 'currentChatChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentAvatarChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receiveNewMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'handleUserActive'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'clickChat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sendMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void PersonModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PersonModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentChatChanged(); break;
        case 1: _t->currentAvatarChanged(); break;
        case 2: _t->currentNameChanged(); break;
        case 3: _t->receiveNewMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->handleUserActive((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->clickChat((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->sendMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PersonModel::*)();
            if (_t _q_method = &PersonModel::currentChatChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PersonModel::*)();
            if (_t _q_method = &PersonModel::currentAvatarChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PersonModel::*)();
            if (_t _q_method = &PersonModel::currentNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ChatModel* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<PersonModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ChatModel**>(_v) = _t->currentChat(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->currentAvatar(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->currentName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<PersonModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentChat(*reinterpret_cast< ChatModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *PersonModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PersonModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPersonModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int PersonModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PersonModel::currentChatChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PersonModel::currentAvatarChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PersonModel::currentNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
