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
    team.cpp \
    timebar.cpp \
    lastroundbar.cpp \
    settings.cpp \
    teameditdialog.cpp \
    printdialog.cpp

HEADERS  += teammanager.h \
    mainwindow.h \
    xmlhandler.h \
    resultprinter.h \
    bestroundbar.h \
    cmdlinebar.h \
    barcodehandler.h \
    team.h \
    timebar.h \
    lastroundbar.h \
    settings.h \
    teameditdialog.h \
    printdialog.h

FORMS    += mainwindow.ui \
    timebar.ui \
    cmdlinebar.ui \
    bestroundbar.ui \
    lastroundbar.ui \
    settings.ui \
    teameditdialog.ui \
    printdialog.ui

RESOURCES += \
    recources.qrc

LIBS    += -lsetupapi
