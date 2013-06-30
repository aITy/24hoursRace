#include "lastroundbar.h"
#include "ui_lastroundbar.h"

LastRoundBar::LastRoundBar(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

LastRoundBar::~LastRoundBar()
{

}

void LastRoundBar::updateBar(const QString & name, int ms, int rounds_count)
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

    label_Rounds->setText(QString::number(rounds_count));
}
