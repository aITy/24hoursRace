#include "mainwindow.h"
#include "timebar.h"
#include "teammanager.h"
#include "team.h"
#include "cmdlinebar.h"
#include "resultprinter.h"
#include "xmlhandler.h"
#include "bestroundbar.h"
#include "lastroundbar.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow * MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    instance = this;
    setupUi(this);
    setWindowTitle(qApp->applicationName());

    connect(action_Start, SIGNAL(triggered()), this, SLOT(run()));

    connect(action_SortByRoundsDesc, SIGNAL(triggered()), this, SLOT(sortByRoundsDesc()));
    connect(action_SortByRoundsAsc, SIGNAL(triggered()), this, SLOT(sortByRoundsAsc()));
    connect(action_SortByTimeDesc, SIGNAL(triggered()), this, SLOT(sortByTimeDesc()));
    connect(action_SortByTimeAsc, SIGNAL(triggered()), this, SLOT(sortByTimeAsc()));

    connect(actionBestByRoundsDesc, SIGNAL(triggered()), this, SLOT(printBestByRoundsDesc()));
    connect(actionBestByRoundsAsc, SIGNAL(triggered()), this, SLOT(printBestByRoundsAsc()));
    connect(actionBestByTimeDesc, SIGNAL(triggered()), this, SLOT(printBestByTimeDesc()));
    connect(actionBestByTimeAsc, SIGNAL(triggered()), this, SLOT(printBestByTimeAsc()));

    connect(actionPrintByRoundsDesc, SIGNAL(triggered()), this, SLOT(printByRoundsDesc()));
    connect(actionPrintByRoundsAsc, SIGNAL(triggered()), this, SLOT(printByRoundsAsc()));
    connect(actionPrintByRoundsDesc, SIGNAL(triggered()), this, SLOT(printByTimeDesc()));
    connect(actionPrintByRoundsAsc, SIGNAL(triggered()), this, SLOT(printByTimeAsc()));

    connect(actionPrintByTeam, SIGNAL(triggered()), this, SLOT(printByTeam()));

    connect(actionXmlExport, SIGNAL(triggered()), this, SLOT(xmlexport()));
    connect(actionXmlImport, SIGNAL(triggered()), this, SLOT(xmlimport()));

    timebar = new TimeBar();
    manager = new TeamManager();
    cmdline = new CmdLineBar();
    printer = new ResultPrinter();
    xml_handler = new XmlHandler();
    bestround_bar = new BestRoundBar();
    lastround_bar = new LastRoundBar();

    middleLayout->addWidget(timebar);
    middleLayout->addWidget(bestround_bar);
    middleLayout->addWidget(lastround_bar);
    middleLayout->addWidget(cmdline);

    QList<int> barcode1;
    QList<int> barcode2;
    QList<int> barcode3;

    team_count = 40;
    for(int i = 0; i < team_count; i++){
        label_names.append(new QLabel());
        label_rounds.append(new QLabel());
        label_ranks.append(new QLabel());
        label_rounds.last()->setMaximumWidth(50);
        label_names.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
        label_rounds.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
        if(i%2 == 0){
            // set gray background
            label_ranks.last()->setStyleSheet("background-color:gray;");
            label_names.last()->setStyleSheet("background-color:gray;");
            label_rounds.last()->setStyleSheet("background-color:gray;");
        }
        else{
            label_ranks.last()->setStyleSheet("background-color:white;");
            label_names.last()->setStyleSheet("background-color:white;");
            label_rounds.last()->setStyleSheet("background-color:white;");
        }
        if((team_count % 2 == 0) && (i < (team_count/2)) || (team_count % 2 == 1) && (i < (team_count/2 +1) )){
            ListLeft->addWidget(label_names.at(i),i+1,1); // +1 because of title
            ListLeft->addWidget(label_rounds.at(i),i+1,2);

        }
        else{
            ListRight->addWidget(label_names.at(i),i-team_count/2+1,1); // -19 == 2nd grid + title
            ListRight->addWidget(label_rounds.at(i),i-team_count/2+1,2);
        }
    }

    for (int i = 0; i < 5; i++) {
        barcode1.append(i);
        barcode2.append(5 - i);
        barcode3.append(i + 5);
    }

    manager->addTeam("jirin", barcode1);
    manager->addTeam("venca", barcode2);
    manager->addTeam("dlouheee jmenooo", barcode3);

    Team * jirin = manager->getTeamByName("jirin");
    jirin->addRacer("JiRin");
    jirin->addRacer("Roman");

    Team * venca = manager->getTeamByName("venca");
    venca->addRacer("venca");

    state = SORTBYROUNDSDESC;

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

void MainWindow::reconstructTimeBar()
{
    if (timebar)
        delete timebar;
    timebar = new TimeBar();
}

void MainWindow::reconstructTimeBar(int total_ms, int curr_ms)
{
    if (timebar)
        delete timebar;
    timebar = new TimeBar(total_ms, curr_ms);
}

void MainWindow::updateOrder()
{
    QList<Team *> teams_ptr = manager->getTeams();
    qDebug() << (int)state;

    if (state == SORTBYROUNDSDESC || state == SORTBYROUNDSASC) {
        label_RoundLeft->setText(trUtf8("Počet kol"));
        label_RoundRight->setText(trUtf8("Počet kol"));
    }
    else {
        label_RoundLeft->setText(trUtf8("Čas"));
        label_RoundRight->setText(trUtf8("Čas"));
    }

    for(int i = 0; i < teams_ptr.count(); i++){
        label_names.at(i)->setText(teams_ptr.at(i)->getName());

        if (state == SORTBYROUNDSDESC || state == SORTBYROUNDSASC) {
            label_rounds.at(i)->setText(QString::number(teams_ptr.at(i)->getTotalRounds()));
        }
        else {
            int ms = teams_ptr.at(i)->getBestRound();
            int hours = ms / (1000*60*60);
            int minutes = (ms % (1000*60*60)) / (1000*60);
            int seconds = ((ms % (1000*60*60)) % (1000*60)) / 1000;
            QString str;
            if (hours != 0) {
                str.append(QString::number(hours));
                str.append(":");
            }
            str.append(QString("%1:%2 min.").arg(minutes).arg(seconds));
            label_rounds.at(i)->setText(str);
        }
    }

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

void MainWindow::printByTeam()
{
    printer->printResultsByTeams();
}

void MainWindow::sortByRoundsDesc()
{
    manager->sortByRounds(true);
    state = SORTBYROUNDSDESC;
    updateOrder();
}

void MainWindow::sortByRoundsAsc()
{
    manager->sortByRounds(false);
    state = SORTBYROUNDSASC;
    updateOrder();
}

void MainWindow::sortByTimeDesc()
{
    manager->sortByTime(true);
    state = SORTBYTIMEDESC;
    updateOrder();
}

void MainWindow::sortByTimeAsc()
{
    manager->sortByTime(false);
    state = SORTBYTIMEASC;
    updateOrder();
}

void MainWindow::xmlexport()
{
    QString fn = QFileDialog::getSaveFileName(NULL,
                                   trUtf8("Ulozit do souboru"),
                                   "",
                                   trUtf8("Jakykoliv typ souboru %1").arg("*.*"));
    if (fn.isEmpty())
        return;

    xml_handler->xmlExport(fn);
}

void MainWindow::xmlimport()
{
    QString fn = QFileDialog::getOpenFileName(NULL,
                                   trUtf8("Nacist ze souboru"),
                                   "",
                                   trUtf8("Jakykoliv typ souboru %1").arg("*.*"));
    if (fn.isEmpty())
        return;

    xml_handler->xmlImport(fn);
}
