/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Apr 20 03:08:39 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../game_of_life/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      33,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      75,   11,   11,   11, 0x08,
      97,   11,   11,   11, 0x08,
     136,  130,   11,   11, 0x08,
     171,  130,   11,   11, 0x08,
     206,  130,   11,   11, 0x08,
     241,  130,   11,   11, 0x08,
     276,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_ini_pau_clicked()\0"
    "on_life_pressed()\0on_Diffussion_pressed()\0"
    "on_personal_pressed()\0"
    "on_propagacion_valueChanged(int)\0index\0"
    "on_comboX_currentIndexChanged(int)\0"
    "on_comboY_currentIndexChanged(int)\0"
    "on_comboW_currentIndexChanged(int)\0"
    "on_comboZ_currentIndexChanged(int)\0"
    "on_limpia_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_ini_pau_clicked(); break;
        case 1: on_life_pressed(); break;
        case 2: on_Diffussion_pressed(); break;
        case 3: on_personal_pressed(); break;
        case 4: on_propagacion_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_comboX_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_comboY_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_comboW_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_comboZ_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_limpia_clicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
