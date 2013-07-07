#include "mainwindow.h"
#include "timebar.h"
#include "teammanager.h"
#include "team.h"
#include "cmdlinebar.h"
#include "resultprinter.h"
#include "xmlhandler.h"
#include "bestroundbar.h"
#include "lastroundbar.h"
#include "settings.h"
#include "teameditdialog.h"
#include "printdialog.h"
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

    connect(action_Save, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(action_Open, SIGNAL(triggered()), this, SLOT(openFromFile()));

    connect(action_changeSettings, SIGNAL(triggered()), this, SLOT(changeSettings()));
    connect(action_TeamEdit, SIGNAL(triggered()), this, SLOT(teamEdit()));

    connect(actionBestByRoundsDesc, SIGNAL(triggered()), this, SLOT(printBestByRoundsDesc()));
    connect(actionBestByRoundsAsc, SIGNAL(triggered()), this, SLOT(printBestByRoundsAsc()));
    connect(actionBestByTimeDesc, SIGNAL(triggered()), this, SLOT(printBestByTimeDesc()));
    connect(actionBestByTimeAsc, SIGNAL(triggered()), this, SLOT(printBestByTimeAsc()));

    connect(actionPrintByRounds, SIGNAL(triggered()), this, SLOT(printByRounds()));
    connect(actionPrintByTeam, SIGNAL(triggered()), this, SLOT(printByTeam()));
    connect(action_Print, SIGNAL(triggered()), this, SLOT(printDialogShow()));

    connect(actionXmlExport, SIGNAL(triggered()), this, SLOT(xmlexport()));
    connect(actionXmlImport, SIGNAL(triggered()), this, SLOT(xmlimport()));

    timebar = new TimeBar();
    manager = new TeamManager();
    cmdline = new CmdLineBar();
    printer = new ResultPrinter();
    xml_handler = new XmlHandler();
    bestround_bar = new BestRoundBar();
    lastround_bar = new LastRoundBar();
    settings = new Settings();

    timebar->showTime();

    connect(settings, SIGNAL(boardChanged()), this, SLOT(boardSettingsChanged()));
    connect(settings, SIGNAL(raceLengthChanged()), this, SLOT(raceLengthChanged()));
    connect(settings, SIGNAL(headlineChanged()), this, SLOT(headlineChanged()));

    middleLayout->addWidget(timebar);
    middleLayout->addWidget(bestround_bar);
    middleLayout->addWidget(lastround_bar);
    middleLayout->addWidget(cmdline);

    layoutBoard(settings->getTeamsCount());

    file = "db.xml";

    state = SORTBYROUNDSDESC;
    setFocus();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setStatusMsg(const char * msg) {
    myStatusBar->showMessage(QString(msg), 2500);
}

void MainWindow::reconstructTimeBar()
{
    if (timebar)
        delete timebar;
    timebar = new TimeBar();
    middleLayout->addWidget(timebar, Qt::AlignTop);
}

void MainWindow::reconstructTimeBar(int total_ms, int curr_ms)
{
    if (timebar)
        delete timebar;
    timebar = new TimeBar(total_ms, curr_ms);
    middleLayout->insertWidget(0,timebar);
    manager->updateTimeBarPtr();
}

void MainWindow::updateOrder()
{
    QList<Team *> teams_ptr = manager->getTeams();
    qDebug() << (int)state;

    if (state == SORTBYROUNDSDESC || state == SORTBYROUNDSASC) {
        label_RoundLeft->setText(trUtf8("Počet kol"));
        label_RoundRight->setText(trUtf8("Počet kol"));
        for(int i = 0;i < label_rounds.count(); i++) {
            label_RoundLeft->setMaximumWidth(60);
            label_RoundRight->setMaximumWidth(60);
            label_rounds.at(i)->setMaximumWidth(60);
        }
    }
    else {
        label_RoundLeft->setText(trUtf8("Čas"));
        label_RoundRight->setText(trUtf8("Čas"));
        for(int i = 0; i < label_rounds.count(); i++) {
            label_RoundLeft->setMaximumWidth(130);
            label_RoundRight->setMaximumWidth(130);
            label_rounds.at(i)->setMaximumWidth(130);
        }
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

void MainWindow::clearLayout(QLayout* layout, bool deleteWidgets)
{

    while (QLayoutItem* item = layout->takeAt(3))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                delete widget;
        }
        else if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}

void MainWindow::layoutBoard(int team_count)
{
    if (label_names.count() != 0) {
        clearLayout(ListLeft);
        clearLayout(ListRight);
        label_names.clear();
        label_rounds.clear();
        label_ranks.clear();
    }

    for(int i = 0; i < team_count; i++){
        label_names.append(new QLabel());
        label_rounds.append(new QLabel());
        label_ranks.append(new QLabel());
        label_rounds.last()->setMaximumWidth(60);
        label_names.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
        label_names.last()->setFont(QFont("Radio Space", 14));
        label_names.last()->setAlignment(Qt::AlignCenter);
        label_rounds.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
        label_rounds.last()->setFont(QFont("Radio Space Bold", 16));
        label_rounds.last()->setAlignment(Qt::AlignCenter);
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
        label_ranks.last()->setFont(QFont("Radio Space", 12));
        label_ranks.last()->setAlignment(Qt::AlignCenter);
        label_ranks.last()->setText(QString("%1.").arg(i+1));
        if((team_count % 2 == 0) && (i < (team_count/2)) || (team_count % 2 == 1) && (i < (team_count/2 +1) )){
            ListLeft->addWidget(label_ranks.at(i), i+1,0);
            ListLeft->addWidget(label_names.at(i),i+1,1);
            ListLeft->addWidget(label_rounds.at(i),i+1,2);

        }
        else{
            ListRight->addWidget(label_ranks.at(i), i-team_count/2+1,0);
            ListRight->addWidget(label_names.at(i),i-team_count/2+1,1);
            ListRight->addWidget(label_rounds.at(i),i-team_count/2+1,2);

        }
    }
    updateOrder();
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
        printDialogShow();
    }
    // CTRL + Z - zaloha or S - save to
    if ((event->key() == Qt::Key_Z || event->key() == Qt::Key_S) && (event->modifiers() == Qt::ControlModifier)) {
        // save database to
        qDebug() << "CTRL + Z || CTRL + S pressed";
        save();
        saveAs();
    }

}

void MainWindow::run()
{
    if (manager->getTeams().size() == 0 && !timebar->isRunning())
        return;

    updateOrder();
    save();
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

void MainWindow::printByRounds() {
    printer->printByRounds();
}

void MainWindow::printByTeam()
{
    printer->printResultsByTeams();
}

void MainWindow::printSelection(int index)
{
    switch(index) {
        case 0:
            MainWindow::getInstance()->getPrinter()->printResultsByTeams();
            break;

        case 1:
            MainWindow::getInstance()->getPrinter()->printByRounds();
            break;

        case 2:
            MainWindow::getInstance()->getPrinter()->printBestResultsByRoundCount(true);
            break;

        case 3:
            MainWindow::getInstance()->getPrinter()->printBestResultsByRoundCount(false);
            break;

        case 4:
            MainWindow::getInstance()->getPrinter()->printBestResultsByTime(true);
            break;
        case 5:
            MainWindow::getInstance()->getPrinter()->printBestResultsByTime(false);
            break;
        case -1:
            break;
    }
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

void MainWindow::changeSettings()
{
    settings->show();
}

void MainWindow::boardSettingsChanged()
{
    layoutBoard(settings->getTeamsCount());
}

void MainWindow::raceLengthChanged()
{
    timebar->setTimer(settings->getRaceLength());
    timebar->showTime();
}

void MainWindow::headlineChanged()
{

}

void MainWindow::teamEdit()
{
    TeamEditDialog *dialog = new TeamEditDialog(manager);
    dialog->show();
}

void MainWindow::save()
{
    if (!xml_handler->xmlExport(file))
        setStatusMsg("error while saving temp file");
    if (!settings->getFilepath().isEmpty()) {
        if (!xml_handler->xmlExport(settings->getFilepath()))
            setStatusMsg("error while saving backup file");
    }

}

void MainWindow::saveAs()
{
    QString fn = QFileDialog::getSaveFileName(NULL,
                                   trUtf8("Ulozit do souboru"),
                                   "",
                                   trUtf8("Jakykoliv typ souboru %1").arg("*.*"));
    if (fn.isEmpty())
        return;

    if (!xml_handler->xmlExport(fn))
        setStatusMsg("error");
}

void MainWindow::openFromFile()
{
    QString fn = QFileDialog::getOpenFileName(NULL,
                                   trUtf8("Nacist ze souboru"),
                                   "",
                                   trUtf8("Jakykoliv typ souboru %1").arg("*.*"));


    if (fn.isEmpty())
        return;

    if (!xml_handler->xmlImport(fn)) {
        setStatusMsg("error");
        return;
    }
    updateOrder();
    save();
}

void MainWindow::printDialogShow()
{
    PrintDialog * dialog = new PrintDialog();
    connect(dialog, SIGNAL(selection(int)), this, SLOT(printSelection(int)));
    dialog->show();
}

void MainWindow::xmlexport()
{
    QString fn = QFileDialog::getSaveFileName(NULL,
                                   trUtf8("Ulozit do souboru"),
                                   "",
                                   trUtf8("Jakykoliv typ souboru %1").arg("*.*"));

    if (fn.isEmpty())
        return;

    if (!xml_handler->xmlExport(fn))
        setStatusMsg("error");
}

void MainWindow::xmlimport()
{
    QString fn = QFileDialog::getOpenFileName(NULL,
                                   trUtf8("Nacist ze souboru"),
                                   "",
                                   trUtf8("Jakykoliv typ souboru %1").arg("*.*"));



    if (fn.isEmpty())
        return;

    if (!xml_handler->xmlImport(fn)) {
        setStatusMsg("error");
        return;
    }
    updateOrder();

}
