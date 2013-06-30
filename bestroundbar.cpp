#include "bestroundbar.h"
#include <QDebug>

BestRoundBar::BestRoundBar(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void BestRoundBar::updateBar(const QString & name, int ms)
{
    label_Team->setText(name);
    int minutes = (ms % (1000*60*60)) / (1000*60);
    int seconds = ((ms % (1000*60*60)) % (1000*60)) / 1000;

    //Move the MM:SS to the labels

    if (minutes < 10)
        label_M->setText(QString("0%1").arg(minutes));
    else
        label_M->setText(QString::number(minutes));

    if (seconds < 10)
        label_S->setText(QString("0%1").arg(seconds));
    else
        label_S->setText(QString::number(seconds));
}
