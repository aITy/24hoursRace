#include "mainwindow.h"
#include "timebar.h"
#include "teammanager.h"
#include "team.h"
#include "cmdlinebar.h"
#include "resultprinter.h"
#include <QDebug>
#include <QMessageBox>

MainWindow * MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    instance = this;
    setupUi(this);
    setWindowTitle(qApp->applicationName());


    connect(action_Start, SIGNAL(triggered()), this, SLOT(run()));

    connect(actionBestByRoundsDesc, SIGNAL(triggered()), this, SLOT(printBestByRoundsDesc()));
    connect(actionBestByRoundsAsc, SIGNAL(triggered()), this, SLOT(printBestByRoundsAsc()));
    connect(actionBestByTimeDesc, SIGNAL(triggered()), this, SLOT(printBestByTimeDesc()));
    connect(actionBestByTimeAsc, SIGNAL(triggered()), this, SLOT(printBestByTimeAsc()));

    connect(actionPrintByRoundsDesc, SIGNAL(triggered()), this, SLOT(printByRoundsDesc()));
    connect(actionPrintByRoundsAsc, SIGNAL(triggered()), this, SLOT(printByRoundsAsc()));
    connect(actionPrintByRoundsDesc, SIGNAL(triggered()), this, SLOT(printByTimeDesc()));
    connect(actionPrintByRoundsAsc, SIGNAL(triggered()), this, SLOT(printByTimeAsc()));


    timebar = new TimeBar();
    manager = new TeamManager(timebar);
    cmdline = new CmdLineBar();
    printer = new ResultPrinter();

    middleLayout->addWidget(timebar);
    middleLayout->addWidget(cmdline);

    QList<int> barcode1;
    QList<int> barcode2;

    for (int i = 0; i < 13; i++) {
        barcode1.append(i);
        barcode2.append(13 - i);
    }

    manager->addTeam("jirin", barcode1);
    manager->addTeam("venca", barcode2);
    manager->addTeam("Beatrice Technics Creato", barcode1);
    setFocus();
}

MainWindow::~MainWindow()
{
    if (timebar)
        delete timebar;
}

void MainWindow::setStatusMsg(const char * msg) {
    myStatusBar->showMessage(QString(msg), 2500);
}

void MainWindow::closeEvent(QCloseEvent * event) {
        QMessageBox::StandardButton choice;
        choice = QMessageBox::question(this,
                trUtf8("Opravdu ukoncit?"),
                trUtf8("Opravdu chcete ukoncit aplikaci '%1'?<br><b>Neulozene zmeny budou ztraceny!</b>").arg(qApp->applicationName()),
                QMessageBox::Yes | QMessageBox::No,
                QMessageBox::No);

        if (choice == QMessageBox::Yes)
                event->accept();
        else
                event->ignore();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setFocus();
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    // CTRL + T - tisk or P - print
    if ((event->key() == Qt::Key_T || event->key() == Qt::Key_P) && (event->modifiers() == Qt::ControlModifier)) {
        // print database
        qDebug() << "CTRL + T || CTRL + P pressed";
    }
    // CTRL + Z - zaloha or S - save to
    if ((event->key() == Qt::Key_Z || event->key() == Qt::Key_S) && (event->modifiers() == Qt::ControlModifier)) {
        // save database to
        qDebug() << "CTRL + Z || CTRL + S pressed";
    }

}

void MainWindow::run()
{
    if (manager->getTeams().size() == 0)
        return;

    timebar->run();
}

void MainWindow::printBestByRoundsDesc()
{
    printer->printBestResultsByRoundCount(true);
}

void MainWindow::printBestByRoundsAsc()
{
    printer->printBestResultsByRoundCount(false);
}

void MainWindow::printBestByTimeDesc()
{
    printer->printBestResultsByTime(true);
}

void MainWindow::printBestByTimeAsc()
{
    printer->printBestResultsByTime(false);
}

void MainWindow::printByRoundsDesc()
{

}

void MainWindow::printByRoundsAsc()
{

}

void MainWindow::printByTimeDesc()
{
}

void MainWindow::printByTimeAsc()
{

}
