#include "cmdlinebar.h"
#include "mainwindow.h"
#include "teammanager.h"
#include <QKeyEvent>
#include <QDebug>

CmdLineBar::CmdLineBar(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}


void CmdLineBar::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "key pressed - " << event->key();
}

void CmdLineBar::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()) {
        event->ignore();
    }
    if (event->key() == 16777220) {
        QString str = lineEdit->text();
        lineEdit->setText("");
        QRegExp rx("\\D");
        if (str.contains(rx)) {
            MainWindow::getInstance()->getTeamManager()->addRound(str);
        }
        else {
            QList<int> barcode;
            for (int i = 0; i < str.count(); i++) {
                barcode.append(QString(str[i]).toInt());
                MainWindow::getInstance()->getTeamManager()->addRound(barcode);
            }
        }
    }
}

void CmdLineBar::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setFocus();
}
