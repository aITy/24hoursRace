/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata[342];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 4),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 6),
QT_MOC_LITERAL(4, 24, 12),
QT_MOC_LITERAL(5, 37, 15),
QT_MOC_LITERAL(6, 53, 3),
QT_MOC_LITERAL(7, 57, 16),
QT_MOC_LITERAL(8, 74, 15),
QT_MOC_LITERAL(9, 90, 14),
QT_MOC_LITERAL(10, 105, 13),
QT_MOC_LITERAL(11, 119, 14),
QT_MOC_LITERAL(12, 134, 20),
QT_MOC_LITERAL(13, 155, 17),
QT_MOC_LITERAL(14, 173, 15),
QT_MOC_LITERAL(15, 189, 8),
QT_MOC_LITERAL(16, 198, 14),
QT_MOC_LITERAL(17, 213, 21),
QT_MOC_LITERAL(18, 235, 20),
QT_MOC_LITERAL(19, 256, 19),
QT_MOC_LITERAL(20, 276, 18),
QT_MOC_LITERAL(21, 295, 13),
QT_MOC_LITERAL(22, 309, 11),
QT_MOC_LITERAL(23, 321, 9),
QT_MOC_LITERAL(24, 331, 9)
    },
    "MainWindow\0save\0\0saveAs\0openFromFile\0"
    "printDialogShow\0run\0sortByRoundsDesc\0"
    "sortByRoundsAsc\0sortByTimeDesc\0"
    "sortByTimeAsc\0changeSettings\0"
    "boardSettingsChanged\0raceLengthChanged\0"
    "headlineChanged\0teamEdit\0printSelection\0"
    "printBestByRoundsDesc\0printBestByRoundsAsc\0"
    "printBestByTimeDesc\0printBestByTimeAsc\0"
    "printByRounds\0printByTeam\0xmlexport\0"
    "xmlimport\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  129,    2, 0x0a,
       3,    0,  130,    2, 0x0a,
       4,    0,  131,    2, 0x0a,
       5,    0,  132,    2, 0x0a,
       6,    0,  133,    2, 0x08,
       7,    0,  134,    2, 0x08,
       8,    0,  135,    2, 0x08,
       9,    0,  136,    2, 0x08,
      10,    0,  137,    2, 0x08,
      11,    0,  138,    2, 0x08,
      12,    0,  139,    2, 0x08,
      13,    0,  140,    2, 0x08,
      14,    0,  141,    2, 0x08,
      15,    0,  142,    2, 0x08,
      16,    1,  143,    2, 0x08,
      17,    0,  146,    2, 0x08,
      18,    0,  147,    2, 0x08,
      19,    0,  148,    2, 0x08,
      20,    0,  149,    2, 0x08,
      21,    0,  150,    2, 0x08,
      22,    0,  151,    2, 0x08,
      23,    0,  152,    2, 0x08,
      24,    0,  153,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->saveAs(); break;
        case 2: _t->openFromFile(); break;
        case 3: _t->printDialogShow(); break;
        case 4: _t->run(); break;
        case 5: _t->sortByRoundsDesc(); break;
        case 6: _t->sortByRoundsAsc(); break;
        case 7: _t->sortByTimeDesc(); break;
        case 8: _t->sortByTimeAsc(); break;
        case 9: _t->changeSettings(); break;
        case 10: _t->boardSettingsChanged(); break;
        case 11: _t->raceLengthChanged(); break;
        case 12: _t->headlineChanged(); break;
        case 13: _t->teamEdit(); break;
        case 14: _t->printSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->printBestByRoundsDesc(); break;
        case 16: _t->printBestByRoundsAsc(); break;
        case 17: _t->printBestByTimeDesc(); break;
        case 18: _t->printBestByTimeAsc(); break;
        case 19: _t->printByRounds(); break;
        case 20: _t->printByTeam(); break;
        case 21: _t->xmlexport(); break;
        case 22: _t->xmlimport(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
