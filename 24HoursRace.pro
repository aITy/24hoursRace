#-------------------------------------------------
#
# Project created by QtCreator 2013-06-26T15:20:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 24HoursRace
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xmlhandler.cpp \
    resultprinter.cpp \
    bestroundbar.cpp \
    timebar.cpp \
    cmdlinebar.cpp \
    barcodehandler.cpp \
    setttingsdialog.cpp \
    team.cpp \
    databaseeditdialog.cpp

HEADERS  += mainwindow.h \
    xmlhandler.h \
    resultprinter.h \
    bestroundbar.h \
    timebar.h \
    cmdlinebar.h \
    barcodehandler.h \
    setttingsdialog.h \
    team.h \
    databaseeditdialog.h

FORMS    += mainwindow.ui
