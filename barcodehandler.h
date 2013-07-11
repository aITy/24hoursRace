#ifndef BARCODEHANDLER_H
#define BARCODEHANDLER_H

#include <QObject>
#include "qt_windows.h"
#include <QThread>
#include <QClipboard>

#define MY_DEVICE_VIDPID  "VID_04B4&PID_0100"
#define HID_CLASSGUID {0xA5DCBF10L, 0x6530, 0x11D2,{ 0x90, 0x1F, 0x00, 0xC0, 0x4F, 0xB9, 0x51, 0xED}}

class ReadThread : public QThread
 {
     Q_OBJECT

 protected:
     void run();
 signals:
      void USBReceived();

 };


class BarCodeHandler : public QObject
{
    Q_OBJECT
public:
    explicit BarCodeHandler(QObject *parent = 0);
    ~BarCodeHandler();

    HANDLE ReadHandle;
    bool USBConnected;
    unsigned char OutputBuffer[65];
    unsigned char InputBuffer[65];

private:
    QList<int> convertToBarcode(const QString &);
    bool USBCheck();

    HDEVNOTIFY hDevNotify;
    bool msgp;
    bool UsbRv;
    bool TimerRv;
    ReadThread *rthread;
    QString data;
    QClipboard * clipboard;

protected :
    bool winEvent(MSG *msg,long * result);

signals:
    void USB_Removed();
    void USB_Arrived();

private slots:
    void in_USBReceived();
    void in_USBArrived();
    void in_USBRemoved();
    void in_timerTimeout();


    void readCin();
    
};

#endif // BARCODEHANDLER_H
