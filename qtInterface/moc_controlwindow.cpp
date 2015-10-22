/****************************************************************************
** Meta object code from reading C++ file 'controlwindow.h'
**
** Created: Thu Oct 22 01:44:43 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controlwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ControlWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      32,   14,   14,   14, 0x08,
      67,   46,   14,   14, 0x08,
     102,   14,   14,   14, 0x08,
     112,   14,   14,   14, 0x08,
     131,   14,   14,   14, 0x08,
     142,   14,   14,   14, 0x08,
     153,   14,   14,   14, 0x08,
     160,   14,   14,   14, 0x08,
     173,   14,   14,   14, 0x08,
     186,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ControlWindow[] = {
    "ControlWindow\0\0showFullScreen()\0"
    "togglePause()\0position,label,value\0"
    "statusMessage(int,QString,QString)\0"
    "hideOSD()\0toggleVisibility()\0incTrans()\0"
    "decTrans()\0stop()\0stopFromKb()\0"
    "playFromKb()\0pauseFromKb()\0"
};

const QMetaObject ControlWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ControlWindow,
      qt_meta_data_ControlWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ControlWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ControlWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ControlWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlWindow))
        return static_cast<void*>(const_cast< ControlWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int ControlWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showFullScreen(); break;
        case 1: togglePause(); break;
        case 2: statusMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: hideOSD(); break;
        case 4: toggleVisibility(); break;
        case 5: incTrans(); break;
        case 6: decTrans(); break;
        case 7: stop(); break;
        case 8: stopFromKb(); break;
        case 9: playFromKb(); break;
        case 10: pauseFromKb(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
