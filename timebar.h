#ifndef TIMEBAR_H
#define TIMEBAR_H

#include <QWidget>
#include <QLCDNumber>
#include <QTime>
#include <QTimer>
#include "ui_timebar.h"

class TimeBar : public QWidget, Ui::TimeBarWidget
{
    Q_OBJECT
public:
    TimeBar(QWidget * parent = 0);
    TimeBar(int, int, QWidget * parent = 0);
    ~TimeBar();
    int getCurrentTime() { return ms; }
    int getTotalTime() { return total_time; }
    void run();
    bool isRunning() { return running; }
    void setTimer(int);

private:
    QTimer * countdown;
    int ms;
    int total_time;
    bool running;
signals:
    
public slots:
    void showTime();
    
};

#endif // TIMEBAR_H
