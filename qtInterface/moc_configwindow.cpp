/****************************************************************************
** Meta object code from reading C++ file 'configwindow.h'
**
** Created: Thu Oct 22 00:55:38 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "configwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfigWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      36,   13,   13,   13, 0x08,
      54,   13,   13,   13, 0x08,
      74,   13,   13,   13, 0x08,
      94,   13,   13,   13, 0x08,
     116,   13,   13,   13, 0x08,
     146,  138,   13,   13, 0x08,
     178,  163,   13,   13, 0x08,
     219,  202,   13,   13, 0x08,
     257,  245,   13,   13, 0x08,
     290,  278,   13,   13, 0x08,
     311,  278,   13,   13, 0x08,
     344,  332,   13,   13, 0x08,
     370,   13,   13,   13, 0x08,
     384,   13,   13,   13, 0x08,
     398,   13,   13,   13, 0x08,
     410,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConfigWindow[] = {
    "ConfigWindow\0\0videoBitRateChanged()\0"
    "videoStdChanged()\0videoCodecChanged()\0"
    "soundCodecChanged()\0soundBitRateChanged()\0"
    "samplingRateChanged()\0looping\0"
    "setLooping(bool)\0disablePreview\0"
    "setDisablePreview(bool)\0disableFileWrite\0"
    "setDisableFileWrite(bool)\0passthrough\0"
    "setPassthrough(bool)\0doNotEncode\0"
    "setEncodeVideo(bool)\0setEncodeSound(bool)\0"
    "deinterlace\0setDeinterlaceVideo(bool)\0"
    "browseVideo()\0browseSound()\0startDemo()\0"
    "exit()\0"
};

const QMetaObject ConfigWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConfigWindow,
      qt_meta_data_ConfigWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConfigWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConfigWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConfigWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigWindow))
        return static_cast<void*>(const_cast< ConfigWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int ConfigWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: videoBitRateChanged(); break;
        case 1: videoStdChanged(); break;
        case 2: videoCodecChanged(); break;
        case 3: soundCodecChanged(); break;
        case 4: soundBitRateChanged(); break;
        case 5: samplingRateChanged(); break;
        case 6: setLooping((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: setDisablePreview((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: setDisableFileWrite((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: setPassthrough((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: setEncodeVideo((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: setEncodeSound((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: setDeinterlaceVideo((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: browseVideo(); break;
        case 14: browseSound(); break;
        case 15: startDemo(); break;
        case 16: exit(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
