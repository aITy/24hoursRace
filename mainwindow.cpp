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
#include "printdialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QTime>

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

    connect(action_PrintByRounds, SIGNAL(triggered()), this, SLOT(printByRounds()));
    connect(action_PrintByTeam, SIGNAL(triggered()), this, SLOT(printByTeam()));
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
    //barcode_handler = new BarCodeHandler();

    timebar->showTime();

    connect(settings, SIGNAL(boardChanged()), this, SLOT(boardSettingsChanged()));
    connect(settings, SIGNAL(raceLengthChanged()), this, SLOT(raceLengthChanged()));
    connect(settings, SIGNAL(headlineChanged()), this, SLOT(headlineChanged()));

    middleLayout->addWidget(timebar);
    middleLayout->addWidget(bestround_bar);
    middleLayout->addWidget(lastround_bar);
    middleLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding));
    middleLayout->addWidget(cmdline);

    state = SORTBYROUNDSDESC;
    layoutBoard(settings->getTeamsCount());
    headline->setText(settings->getHeadline());

    file = "db.xml";

    running = false;
    loaded = false;

    InitRawInput((HWND)this->effectiveWinId());

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
    //qDebug() << (int)state;

    if (state == SORTBYROUNDSDESC || state == SORTBYROUNDSASC) {
        label_RoundLeft->setText(trUtf8("Kol"));
        label_RoundRight->setText(trUtf8("Kol"));
        for(int i = 0;i < label_rounds.count(); i++) {
            label_RoundLeft->setMaximumWidth(80);
            label_RoundRight->setMaximumWidth(80);
            label_rounds.at(i)->setMaximumWidth(80);
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

        label_names.at(i)->setText(QString("%1 (%2)").arg(teams_ptr.at(i)->getName()).arg(teams_ptr.at(i)->getID()));

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

QList<int> MainWindow::fixBarcode(QList<int> barcode)
{
    QList<int>ret;
/*
    int size = barcode.count();

    QList<bool> duplicated;
    for(int i = 0; i < barcode.size(); i++) {
        if (barcode.size() - 1 == i) {
            duplicated.append(false);
            break;
        }
        if (barcode.at(i) == barcode.at(i + 1)) {
            if (i > 0 && barcode.at(i-1) == barcode.at(i+1)) {
                duplicated.append(false);
                duplicated.replace(i-1, true);
            }
            else {
                duplicated.append(true);
            }
        }
        else {
            duplicated.append(false);
        }
    }
    qDebug() << duplicated;

    int is_it_duplicated = 0;
    for (int i = 0; i < duplicated.size(); i++) {
        if (duplicated.at(i) == true) {
            is_it_duplicated += 1;
        }
    }
    if (is_it_duplicated == barcode.size()/2) {
    */
        for(int i = 0; i < barcode.count(); i++) {
            if (i%2 == 0) {
                ret.append(barcode.at(i));
            }
        }
        /*
        return ret;
    } else {
        return barcode;
    }*/
    return ret;

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
        label_rounds.last()->setMaximumWidth(80);
        //label_rounds.last()->setStyleSheet("background-color: rgb(255, 204, 1);");
        label_names.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
        label_names.last()->setFont(QFont("Radio Space", 14));
        label_names.last()->setAlignment(Qt::AlignCenter);
        label_rounds.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
        label_rounds.last()->setFont(QFont("Radio Space Bold", 16));
        label_rounds.last()->setAlignment(Qt::AlignCenter);
        if(i%2 == 0){
            // set gray background
            label_ranks.last()->setStyleSheet("background-color:rgb(255, 204, 1);");
            label_names.last()->setStyleSheet("background-color:rgb(197, 195, 196);");
            label_rounds.last()->setStyleSheet("background-color:rgb(197, 195, 196);");
        }
        else{
            label_ranks.last()->setStyleSheet("background-color: rgb(255, 204, 1);");
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

void MainWindow::InitRawInput(HWND hWnd) {
    //Q_UNUSED(hWnd);
    RAWINPUTDEVICE Rid[1];
    Rid[0].usUsagePage = 0x01;
    //Rid[0].usUsage = 0x06;
    Rid[0].usUsage = 0x00;
    Rid[0].dwFlags = RIDEV_PAGEONLY;
    Rid[0].hwndTarget = hWnd;
    //Rid[0].hwndTarget = 0;
    if (RegisterRawInputDevices(Rid, 1, sizeof(Rid[0])) == false) {
        setStatusMsg("Device registration failed");
        qDebug() << "Device registration failed";
    }

}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType);
    MSG *msg = reinterpret_cast<MSG*>(message);
    LPARAM lParam = msg->lParam;
    LPBYTE lpb;
    UINT dwSize;
    RAWINPUT *raw;
    if (msg->message == WM_INPUT) {
        GetRawInputData((HRAWINPUT)lParam, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));
        lpb = new BYTE[dwSize];
        if (lpb == NULL)
            return 0;

        if (GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER)) != dwSize) {
            setStatusMsg("GetRawInputData doesn´t return correct size");
        }

        raw = (RAWINPUT*) lpb;
        UINT size = 256;
        TCHAR tBuffer[256] = {0};
        if (GetRawInputDeviceInfo(raw->header.hDevice, RIDI_DEVICENAME, tBuffer, &size) < 0) {
            setStatusMsg("GetRawInputDeviceInfo error - RIDI_DEVICENAME");
        }
        RID_DEVICE_INFO rdi;
        rdi.cbSize = sizeof(RID_DEVICE_INFO);
        UINT cbSize = rdi.cbSize;
        if (GetRawInputDeviceInfo(raw->header.hDevice, RIDI_DEVICEINFO, &rdi, &cbSize) < 0) {
            setStatusMsg("GetRawInputDeviceInfo error - RIDI_DEVICEINFO");
        }

        if (rdi.keyboard.dwNumberOfKeysTotal == 264) {
            if (raw->header.dwType == RIM_TYPEKEYBOARD) {
                if (raw->data.keyboard.Message = WM_KEYUP || raw->data.keyboard.Message == WM_SYSKEYUP) {
                    USHORT usKey = raw->data.keyboard.VKey;
                    //qDebug() << usKey;
                    if (usKey >= 48 && usKey <= 57) {
                        scanned_barcode.append((int)usKey - 48);
                    }
                    if (usKey == 13) {
                        if (scanned_barcode.count() >= 0) {

                            scanned_barcode = fixBarcode(scanned_barcode);
                            if(timebar->isRunning()) {
                                manager->addRound(scanned_barcode);
                            }
                            scanned_barcode.clear();
                        }
                    }
                }
            }
            result = 0;
            msg = 0;

            // ?
            //delete lpb;

            return true;
        }
        delete lpb;

    }
    return QMainWindow::nativeEvent(eventType, msg, result);
}


void MainWindow::run()
{
    if (manager->getTeams().size() == 0 && !timebar->isRunning() && !running) {
        this->setStatusMsg("Pro start zavodu nejdrive pridejte alespon jeden tým!");
        return;
    }

    time_to_start = new QTimer(this);
    time_to_start->setSingleShot(true);
    connect(time_to_start, SIGNAL(timeout()), this, SLOT(startTheRace()));

    QTime time = QTime::currentTime();
    QTime to_start = QTime();
    int ms = settings->getStartTime();
    int hours = ms / (1000*60*60);
    int minutes = (ms % (1000*60*60)) / (1000*60);
    int seconds = ((ms % (1000*60*60)) % (1000*60)) / 1000;
    to_start.setHMS(hours, minutes, seconds);
    qDebug() << to_start;

    if (!loaded) {
        time_to_start->setInterval(time.secsTo(to_start) * 1000);
        time_to_start->start();
    }
    else {
        int ms = (24 * 3600 + time.secsTo(to_start)) * 1000;
        timebar->shiftTimer(ms);
        timebar->run();
    }

    running = true;
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

void MainWindow::startTheRace()
{
    updateOrder();
    save();
    timebar->run();
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
    headline->setText(settings->getHeadline());
}

void MainWindow::teamEdit()
{
    team_dialog = new TeamEditDialog(manager);
    //InitRawInput((HWND)team_dialog->effectiveWinId());
    team_dialog->show();
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
    if (timebar->getCurrentTime() != timebar->getTotalTime())
        loaded = true;
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
    if (timebar->getCurrentTime() != timebar->getTotalTime())
        loaded = true;

}
