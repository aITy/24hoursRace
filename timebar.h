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
    explicit TimeBar(QWidget *parent = 0);

private:
    QTimer * countdown;
    int ms;
signals:
    
public slots:
    void showTime();
    
};

#endif // TIMEBAR_H
