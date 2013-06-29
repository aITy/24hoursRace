#include "mainwindow.h"
#include "timebar.h"
#include "teammanager.h"
#include "team.h"
#include "cmdlinebar.h"

MainWindow * MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    instance = this;
    setupUi(this);
    connect(action_Start, SIGNAL(triggered()), this, SLOT(run()));

    timebar = new TimeBar();
    manager = new TeamManager(timebar);
    cmdline = new CmdLineBar();

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
}

MainWindow::~MainWindow()
{
    if (timebar)
        delete timebar;
}

void MainWindow::setStatusMsg(const char * msg) {
    myStatusBar->showMessage(QString(msg), 2500);
}

void MainWindow::run()
{
    if (manager->getTeams().size() == 0)
        return;

    timebar->run();
}
