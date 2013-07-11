#include "barcodehandler.h"
#include <setupapi.h>
#include <devguid.h>
#include <dbt.h>
#include <usbiodef.h>
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <QTextStream>
#include <QApplication>
#include "mainwindow.h"
#include "teammanager.h"


BarCodeHandler::BarCodeHandler(QObject *parent) :
    QObject(parent)
{
    ReadHandle = INVALID_HANDLE_VALUE;

    msgp = false;       //Boolean true after the first WM_PAINT Windows event
    UsbRv = false;      // Boolean true when a packet is received
    TimerRv = false;    // Boolean for timeout
    hDevNotify = 0;     // Handle of attach/detach notifier
    USBConnected = false;

    /*
    USBConnected = USBCheck();

    //Connections for attach/detach notification
    connect(this, SIGNAL(USB_Arrived()),this, SLOT(in_USBArrived()));
    connect(this, SIGNAL(USB_Removed()),this, SLOT(in_USBRemoved()));

    //Receiving thread
    rthread = new ReadThread;
    connect(rthread, SIGNAL(USBReceived()),this, SLOT(in_USBReceived()));
    rthread->start();
    */
    clipboard = QApplication::clipboard();
    connect(clipboard, SIGNAL(dataChanged()), this, SLOT(readCin()));
}

BarCodeHandler::~BarCodeHandler()
{
    /*
    if(hDevNotify)
        UnregisterDeviceNotification(hDevNotify);
    rthread->quit();
    */
}

QList<int> BarCodeHandler::convertToBarcode(const QString & str)
{
    QString pattern = "+ěščřžýáíé";
    QList<int> ret;
    int ind;
    for (int i = 0; i < str.count(); i++) {
        ind = pattern.indexOf(str.at(i));
        if (ind == -1) {
            ret.clear();
            return ret;
        }
        if (ind == pattern.count() - 1) {
            ret.append(0);
        }
        else {
            ret.append(ind + 1);
        }
    }

    return ret;
}


bool BarCodeHandler::winEvent(MSG *msg, long *result)
{
    return true;
}


void BarCodeHandler::in_USBReceived()
{

}

void BarCodeHandler::in_USBArrived()
{

}

void BarCodeHandler::in_USBRemoved()
{

}

void BarCodeHandler::in_timerTimeout()
{

}

void BarCodeHandler::readCin()
{
    data = clipboard->text();
    QList<int> barcode = convertToBarcode(data);

    MainWindow::getInstance()->getTeamManager()->addRound(barcode);
}
