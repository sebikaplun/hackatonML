/****************************************************************************
** Meta object code from reading C++ file 'imageloader.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/imageloader.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageloader.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageLoader[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       6,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      28,   12,   12,   12, 0x05,
      43,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   12,   12,   12, 0x08,
      84,   78,   12,   12, 0x08,

 // properties: name, type, flags
      78,  118, 0xff495001,
     135,  127, 0x0a495001,
     141,  127, 0x0a095001,
     147,  127, 0x0a095001,
     154,  127, 0x0a095001,
     169,  164, 0x01495001,

 // properties: notify_signal_id
       0,
       1,
       0,
       0,
       0,
       2,

       0        // eod
};

static const char qt_meta_stringdata_ImageLoader[] = {
    "ImageLoader\0\0imageChanged()\0labelChanged()\0"
    "loadingChanged()\0onReplyFinished()\0"
    "image\0onImageProcessingFinished(QImage)\0"
    "QVariant\0QString\0label\0price\0seller\0"
    "permalink\0bool\0loading\0"
};

void ImageLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageLoader *_t = static_cast<ImageLoader *>(_o);
        switch (_id) {
        case 0: _t->imageChanged(); break;
        case 1: _t->labelChanged(); break;
        case 2: _t->loadingChanged(); break;
        case 3: _t->onReplyFinished(); break;
        case 4: _t->onImageProcessingFinished((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageLoader::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageLoader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageLoader,
      qt_meta_data_ImageLoader, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageLoader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageLoader))
        return static_cast<void*>(const_cast< ImageLoader*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariant*>(_v) = image(); break;
        case 1: *reinterpret_cast< QString*>(_v) = label(); break;
        case 2: *reinterpret_cast< QString*>(_v) = price(); break;
        case 3: *reinterpret_cast< QString*>(_v) = seller(); break;
        case 4: *reinterpret_cast< QString*>(_v) = permalink(); break;
        case 5: *reinterpret_cast< bool*>(_v) = loading(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ImageLoader::imageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ImageLoader::labelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ImageLoader::loadingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
