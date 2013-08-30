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

void CmdLineBar::focus()
{
    lineEdit->setFocus();
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

    if (event->key() == 16777220 || event->key() == 16777221) {


        if (lineEdit->text() == "")
            return;

        QString str = lineEdit->text();
        lineEdit->setText("");
        QRegExp rx("\\d");
        QList<int> barcode;
        if (! MainWindow::getInstance()->getTeamManager()->addRound(str)) {
            if (str.contains(rx)) {
                if (str.count() <= 2) {
                    qDebug() << "ID: " << (str.toInt());
                    MainWindow::getInstance()->getTeamManager()->addRound(str.toInt());
                }
                else {
                    for (int i = 0; i < str.count(); i++) {
                        barcode.append(QString(str[i]).toInt());
                    }
                    MainWindow::getInstance()->getTeamManager()->addRound(barcode);
                }
            }
            /*else {

                for (int i = 0; i < str.count(); i++) {
                    QString pattern = "é+ěščřžýáí";
                    for (int j = 0; j < pattern.count(); j++) {
                        if (pattern.at(j) == str.at(i)) {
                            barcode.append(j);
                            break;
                        }
                    }
                }
                MainWindow::getInstance()->getTeamManager()->addRound(barcode);
            }*/
        }
    }

    // CTRL + T - tisk or P - print
    if ((event->key() == Qt::Key_T || event->key() == Qt::Key_P) && (event->modifiers() == Qt::ControlModifier)) {
        // print database - show dialog how to print - ASC/DESC and byTime/byRounds && call resultprinter
        MainWindow::getInstance()->printDialogShow();

    }
    // CTRL + Z - zaloha or S - save to
    if ((event->key() == Qt::Key_Z || event->key() == Qt::Key_S) && (event->modifiers() == Qt::ControlModifier)) {
        // save database to
        MainWindow::getInstance()->save();
        MainWindow::getInstance()->saveAs();

    }

    // TO DO handle command line focus
    if (event->key() == Qt::Key_Escape) {
        //MainWindow::getInstance()->setFocus();
    }
}

void CmdLineBar::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setFocus();
}
