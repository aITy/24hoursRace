#include "teammanager.h"
#include "timebar.h"
#include "mainwindow.h"
#include "resultprinter.h"
#include "bestroundbar.h"
#include "lastroundbar.h"
#include "settings.h"
#include <QDebug>

TeamManager::TeamManager(QWidget *parent)
    :QWidget(parent)
{
    timebar = MainWindow::getInstance()->getTimeBar();
}


TeamManager::~TeamManager()
{
    clearTeams();
    clearRounds();
}


Team *TeamManager::addTeam()
{
    Team * team = new Team(getLastID() + 1);
    teams.append(team);
    MainWindow::getInstance()->getPrinter()->updateTeams();
    return team;
}

Team *TeamManager::addTeam(const QString & name)
{
    Team * team = new Team(getLastID() + 1, name);
    teams.append(team);
    MainWindow::getInstance()->getPrinter()->updateTeams();
    return team;
}

Team *TeamManager::addTeam(int id, const QString & name, QList<int> barcode)
{
    Team * team = new Team(id, name, barcode);
    teams.append(team);
    MainWindow::getInstance()->getPrinter()->updateTeams();
    return team;
}

Team *TeamManager::addTeam(const QString & name, QList<int> barcode)
{
    Team * team = new Team(getLastID() + 1, name, barcode);
    teams.append(team);
    MainWindow::getInstance()->getPrinter()->updateTeams();
    return team;
}

Team *TeamManager::addTeam(const QString & name, QList<QString> racers)
{
    Team * team = new Team(getLastID() + 1, name, racers);
    teams.append(team);
    MainWindow::getInstance()->getPrinter()->updateTeams();
    return team;
}

Team *TeamManager::addTeam(const QString & name, QList<int> barcode, QList<QString> racers)
{
    Team * team = new Team(getLastID() + 1, name, barcode, racers);
    teams.append(team);
    MainWindow::getInstance()->getPrinter()->updateTeams();
    return team;
}

Team *TeamManager::getTeamByName(const QString & str)
{
    for(int i = 0; i < teams.count(); i++) {
        if (QString::compare(teams.at(i)->getName(),str, Qt::CaseInsensitive) == 0)
            return teams.at(i);
    }
    return NULL;
}

Team *TeamManager::getTeamByBarcode(QList<int> list)
{
    for(int i = 0; i < teams.size(); i++) {
        if (teams.at(i)->getBarcode() == list)
            return teams.at(i);
    }
    return NULL;
}

int TeamManager::getLastID()
{
    return teams.size();
}

void TeamManager::addRound(int id)
{
    if (! timebar->isRunning())
        return;

    int passed_rounds_ms = 0;
    bool found = false;
    for(int i = 0; i < teams.size(); i++) {
        if (teams.at(i)->getID() == id) {
            QList<int> team_rounds = teams.at(i)->getRounds();
            for (int j = 0; j < team_rounds.count(); j++) {
                passed_rounds_ms += team_rounds.at(j);
            }
            if (timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime() < MainWindow::getInstance()->getSettings()->getRoundAdditionLimit())
                return;
            teams.at(i)->addRound(timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime());
            rounds.append(QPair<Team *, int>(teams.at(i), timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime()));
            found = true;
            break;
        }
    }
    if (!found)
        return;

    MainWindow::getInstance()->save();
    updateToolBar();
    printRoundsByTeam();
}


void TeamManager::addRound(QList<int> barcode)
{
    if (! timebar->isRunning())
        return;

    int passed_rounds_ms = 0;
    bool found = false;
    for(int i = 0; i < teams.size(); i++) {
        if (teams.at(i)->getBarcode() == barcode) {
            QList<int> team_rounds = teams.at(i)->getRounds();
            for (int j = 0; j < team_rounds.count(); j++) {
                passed_rounds_ms += team_rounds.at(j);
            }
            if (timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime() < MainWindow::getInstance()->getSettings()->getRoundAdditionLimit())
                return;
            teams.at(i)->addRound(timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime());
            rounds.append(QPair<Team *, int>(teams.at(i), timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime()));
            found = true;
            break;
        }
    }
    if (!found)
        return;

    MainWindow::getInstance()->save();
    updateToolBar();
    printRoundsByTeam();
}

bool TeamManager::addRound(const QString & name)
{
    if (! timebar->isRunning())
        return false;
    int passed_rounds_ms = 0;
    bool found = false;
    for(int i = 0; i < teams.count(); i++) {
        if (QString::compare(teams.at(i)->getName(),name, Qt::CaseInsensitive) == 0) {

            QList<int> team_rounds = teams.at(i)->getRounds();
            for (int j = 0; j < team_rounds.count(); j++) {
                passed_rounds_ms += team_rounds.at(j);
            }

            if (timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime() < MainWindow::getInstance()->getSettings()->getRoundAdditionLimit())
                return false;

            teams.at(i)->addRound(timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime());
            rounds.append(QPair<Team *, int>(teams.at(i), timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime()));
            found = true;
            break;
        }
    }
    if (!found)
        return false;

    /*QPair<QString, int> best_round = getBestRound();
    QPair<QString, int> last_round = getLastRound();
    int rounds_count = MainWindow::getInstance()->getTeamManager()->getTeamByName(name)->getTotalRounds();
    MainWindow::getInstance()->getBestRoundBar()->updateBar(best_round.first, best_round.second);
    MainWindow::getInstance()->getLastRoundBar()->updateBar(last_round.first, last_round.second, rounds_count);
    MainWindow::getInstance()->updateOrder();*/
    MainWindow::getInstance()->save();
    updateToolBar();
    printRoundsByTeam();

    return true;
}

void TeamManager::addRound(const QString & name, int ms)
{
    for(int i = 0; i < teams.count(); i++) {
        if (QString::compare(teams.at(i)->getName(), name, Qt::CaseInsensitive) == 0) {

            teams.at(i)->addRound(ms);
            rounds.append(QPair<Team *, int>(teams.at(i), ms));
            MainWindow::getInstance()->save();
            break;
        }
    }
}

QPair<QString, int> TeamManager::getBestRound()
{
    if (teams.empty())
        return QPair<QString, int>("", -1);
    int ind = 0;
    int ms = timebar->getTotalTime();
    for(int i = 0; i < teams.count(); i++) {
        if (teams.at(i)->getBestRound() < ms && teams.at(i)->getBestRound() != -1) {
            ms = teams.at(i)->getBestRound();
            ind = i;
        }
    }
    int best_round = teams.at(ind)->getBestRound();
    QString best_round_team = teams.at(ind)->getName();
    return QPair< QString, int>(best_round_team, best_round);
}

QPair<QString, int> TeamManager::getLastRound()
{
    QString name = rounds.last().first->getName();
    int round = rounds.last().second;

    return QPair<QString, int>(name, round);
}

void TeamManager::updateTeam(Team * team)
{
    bool found = false;
    for(int i = 0; i < teams.count(); i++) {
        if (QString::compare(teams.at(i)->getName(), team->getName(), Qt::CaseInsensitive) == 0) {
            teams.at(i)->changeBarcode(team->getBarcode());
            teams.at(i)->addRacers(team->getRacers());
            found = true;
        }
        if (teams.at(i)->getBarcodeStr() == team->getBarcodeStr()) {
            teams.at(i)->changeName(team->getName());
            teams.at(i)->addRacers(team->getRacers());
            found = true;
        }
    }
    if (!found) {
        addTeam(team->getName(), team->getBarcode(), team->getRacers());
    }
}

QList<Team *> TeamManager::getTeams()
{
    return teams;
}


void TeamManager::sortByRounds(bool order)
{
    if (order) {
        // DESC
        qSort(teams.begin(), teams.end(), sortByRoundsDesc);
    }
    else {
        // ASC
        qSort(teams.begin(), teams.end(), sortByRoundsAsc);
    }
}

void TeamManager::sortByTime(bool order)
{
    if (order) {
        // DESC
        qSort(teams.begin(), teams.end(), sortByTimeDesc);
    }
    else {
        // ASC
        qSort(teams.begin(), teams.end(), sortByTimeAsc);
    }
}



void TeamManager::printRounds()
{
    for (int i = 0; i < rounds.size(); i++) {
        qDebug() << rounds.at(i).first->getName() << rounds.at(i).second;
    }
}

void TeamManager::printRoundsByTeam()
{
    for (int i = 0; i < teams.size(); i++) {
        qDebug() << teams.at(i)->getName();
        QList<int> print_rounds = teams.at(i)->getRounds();
        for (int j = 0; j < print_rounds.size(); j++) {
            qDebug() << print_rounds.at(j);
        }
    }
}


void TeamManager::clearTeams()
{
    for (int i = teams.count() - 1; i >= 0; i--) {
        Team * team = teams.takeAt(i);
        delete team;
    }
}

void TeamManager::clearRounds()
{
    rounds.clear();
}

void TeamManager::updateToolBar()
{
    if (rounds.count() <= 0)
        return;
    QPair<QString, int> best_round = getBestRound();
    QPair<QString, int> last_round = getLastRound();
    int rounds_count = MainWindow::getInstance()->getTeamManager()->getTeamByName(last_round.first)->getTotalRounds();
    MainWindow::getInstance()->getBestRoundBar()->updateBar(best_round.first, best_round.second);
    MainWindow::getInstance()->getLastRoundBar()->updateBar(last_round.first, last_round.second, rounds_count);

    MainWindow::board_state state = MainWindow::getInstance()->getState();
    if (state == MainWindow::SORTBYROUNDSDESC) {
        MainWindow::getInstance()->sortByRoundsDesc();
    }
    else if (state == MainWindow::SORTBYROUNDSASC) {
        MainWindow::getInstance()->sortByRoundsAsc();
    }
    else if (state == MainWindow::SORTBYTIMEDESC) {
        MainWindow::getInstance()->sortByTimeDesc();
    }
    else {
        MainWindow::getInstance()->sortByTimeAsc();
    }
    //MainWindow::getInstance()->updateOrder();
}

void TeamManager::updateTimeBarPtr()
{
    timebar = MainWindow::getInstance()->getTimeBar();
}
