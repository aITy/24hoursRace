#-------------------------------------------------
#
# Project created by QtCreator 2013-06-26T15:20:44
#
#-------------------------------------------------

QT += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = 24HoursRace
TEMPLATE = app

SOURCES += main.cpp\
    teammanager.cpp \
    mainwindow.cpp \
    xmlhandler.cpp \
    resultprinter.cpp \
    bestroundbar.cpp \
    cmdlinebar.cpp \
    barcodehandler.cpp \
    setttingsdialog.cpp \
    team.cpp \
    databaseeditdialog.cpp \
    timebar.cpp \
    lastroundbar.cpp

HEADERS  += teammanager.h \
    mainwindow.h \
    xmlhandler.h \
    resultprinter.h \
    bestroundbar.h \
    cmdlinebar.h \
    barcodehandler.h \
    setttingsdialog.h \
    team.h \
    databaseeditdialog.h \
    timebar.h \
    lastroundbar.h

FORMS    += mainwindow.ui \
    timebar.ui \
    cmdlinebar.ui \
    bestroundbar.ui \
    lastroundbar.ui

RESOURCES += \
    recources.qrc
