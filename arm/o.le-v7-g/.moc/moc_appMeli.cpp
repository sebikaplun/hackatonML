/****************************************************************************
** Meta object code from reading C++ file 'appMeli.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/appMeli.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appMeli.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AppMeli[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      31,    8,    8,    8, 0x08,

 // methods: signature, parameters, type, tag, flags
      71,    8,   63,    8, 0x02,
      93,   84,    8,    8, 0x02,
     112,    8,    8,    8, 0x02,
     152,  125,    8,    8, 0x02,
     194,    8,   63,    8, 0x02,

 // properties: name, type, flags
     230,  205, 0x00095409,

       0        // eod
};

static const char qt_meta_stringdata_AppMeli[] = {
    "AppMeli\0\0commentDataReceived()\0"
    "requestFinished(QNetworkReply*)\0QString\0"
    "currentDir()\0fileName\0pushImage(QString)\0"
    "loadImages()\0val,price,seller,permalink\0"
    "addImage(QString,QString,QString,QString)\0"
    "getImage()\0bb::cascades::DataModel*\0"
    "model\0"
};

void AppMeli::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AppMeli *_t = static_cast<AppMeli *>(_o);
        switch (_id) {
        case 0: _t->commentDataReceived(); break;
        case 1: _t->requestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: { QString _r = _t->currentDir();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: _t->pushImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->loadImages(); break;
        case 5: _t->addImage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 6: { QString _r = _t->getImage();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AppMeli::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AppMeli::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AppMeli,
      qt_meta_data_AppMeli, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AppMeli::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AppMeli::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AppMeli::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AppMeli))
        return static_cast<void*>(const_cast< AppMeli*>(this));
    return QObject::qt_metacast(_clname);
}

int AppMeli::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bb::cascades::DataModel**>(_v) = model(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
