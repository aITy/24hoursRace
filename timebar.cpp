#include "timebar.h"
#include "mainwindow.h"

TimeBar::TimeBar(QWidget *parent)
    :QWidget(parent)
{

    setupUi(this);

    countdown = new QTimer(this);
    countdown->setInterval(1000);
    countdown->setSingleShot(false);
    connect(countdown, SIGNAL(timeout()), this, SLOT(showTime()));
    // change to settable - implement method to settings
    ms = total_time = 24 * 3600 * 1000;
    running = false;
}

TimeBar::TimeBar(int total_ms, int current_ms, QWidget *parent)
    :QWidget(parent)
{
    setupUi(this);

    countdown = new QTimer(this);
    countdown->setInterval(1000);
    countdown->setSingleShot(false);
    connect(countdown, SIGNAL(timeout()), this, SLOT(showTime()));
    total_time = total_ms;
    ms = current_ms;
    running = false;
}

TimeBar::~TimeBar()
{
}

void TimeBar::showTime()
{
    int hours;
    int minutes;
    int seconds;
    if (ms - 1000 >= 0)
    {
        ms = ms - 1000;


        hours = ms / (1000*60*60);
        minutes = (ms % (1000*60*60)) / (1000*60);
        seconds = ((ms % (1000*60*60)) % (1000*60)) / 1000;

        //Move the HH:MM:SS to the labels
        if (hours < 10)
            label_H->setText(QString("0%1").arg(hours));
        else
            label_H->setText(QString::number(hours));

        if (minutes < 10)
            label_M->setText(QString("0%1").arg(minutes));
        else
            label_M->setText(QString::number(minutes));

        if (seconds < 10)
            label_S->setText(QString("0%1").arg(seconds));
        else
            label_S->setText(QString::number(seconds));

        //MainWindow::getInstance()->setStatusMsg(QString("%1:%2:%3").arg(hours).arg(minutes).arg(seconds).toStdString().c_str());
        if (ms <=0) //If timeout
        {
            countdown->stop(); //Stop the timer
            MainWindow::getInstance()->setStatusMsg("konec timeoutu");

        }
    }
    else
    {
        countdown->stop(); //Stop the timer
        MainWindow::getInstance()->setStatusMsg("konec timeoutu");
    }
}


void TimeBar::run()
{
    countdown->start();
    running = true;
}
