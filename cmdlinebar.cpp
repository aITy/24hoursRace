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
    Q_UNUSED(event);
}

void CmdLineBar::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()) {
        event->ignore();
    }
    if (event->key() == 16777220) {

        if (lineEdit->text() == "")
            return;

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

    // CTRL + T - tisk or P - print
    if ((event->key() == Qt::Key_T || event->key() == Qt::Key_P) && (event->modifiers() == Qt::ControlModifier)) {
        // print database - show dialog how to print - ASC/DESC and byTime/byRounds && call resultprinter

    }
    // CTRL + Z - zaloha or S - save to
    if ((event->key() == Qt::Key_Z || event->key() == Qt::Key_S) && (event->modifiers() == Qt::ControlModifier)) {
        // save database to
        MainWindow::getInstance()->save();
        MainWindow::getInstance()->saveAs();

    }

    if (event->key() == Qt::Key_Escape) {
        MainWindow::getInstance()->setFocus();
    }
}

void CmdLineBar::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setFocus();
}
