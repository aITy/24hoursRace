#include "teammanager.h"
#include "timebar.h"
#include "mainwindow.h"
#include <QDebug>

TeamManager::TeamManager(QWidget *parent)
    :QWidget(parent)
{
    timebar = MainWindow::getInstance()->getTimeBar();
}

/*
TeamManager::~TeamManager()
{
    if (teams.size() != 0) {
        for (int i = 0; i < teams.size(); i++) {
            delete teams.at(i);
        }
    }
}
*/

Team *TeamManager::addTeam()
{
    Team * team = new Team();
    teams.append(team);
    return team;
}

Team *TeamManager::addTeam(const QString & name)
{
    Team * team = new Team(name);
    teams.append(team);
    return team;
}

Team *TeamManager::addTeam(const QString & name, QList<int> barcode)
{
    Team * team = new Team(name, barcode);
    teams.append(team);
    return team;
}

Team *TeamManager::addTeam(const QString & name, QList<QString> racers)
{
    Team * team = new Team(name, racers);
    teams.append(team);
    return team;
}

Team *TeamManager::addTeam(const QString & name, QList<int> barcode, QList<QString> racers)
{
    Team * team = new Team(name, barcode, racers);
    teams.append(team);
    return team;
}


void TeamManager::addRound(QList<int> barcode)
{
    if (! timebar->isRunning())
        return;
    int passed_rounds_ms = 0;
    for(int i = 0; i < teams.size(); i++) {
        if (teams.at(i)->getBarcode() == barcode) {
            QList<int> team_rounds = teams.at(i)->getRounds();
            for (int j = 0; j < team_rounds.size(); j++) {
                passed_rounds_ms += team_rounds.at(j);
            }
            teams.at(i)->addRound(timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime());
            rounds.append(QPair<Team *, int>(teams.at(i), timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime()));
            break;
        }
    }
    printRoundsByTeam();
}

void TeamManager::addRound(const QString & name)
{
    if (! timebar->isRunning())
        return;
    int passed_rounds_ms = 0;
    for(int i = 0; i < teams.size(); i++) {
        if (teams.at(i)->getName() == name) {
            QList<int> team_rounds = teams.at(i)->getRounds();
            for (int j = 0; j < team_rounds.size(); j++) {
                passed_rounds_ms += team_rounds.at(j);
            }
            qDebug() << "passed_rounds_ms" << passed_rounds_ms;
            qDebug() << "total time" << timebar->getTotalTime();
            qDebug() << "current time" << timebar->getCurrentTime();
            teams.at(i)->addRound(timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime());
            rounds.append(QPair<Team *, int>(teams.at(i), timebar->getTotalTime() - passed_rounds_ms - timebar->getCurrentTime()));
            break;
        }
    }
    printRoundsByTeam();
}

QPair<QString, int> TeamManager::getBestRound()
{
    if (teams.empty())
        return QPair<QString, int>("", -1);
    int ind = 0;
    int ms = teams.first()->getBestRound();
    for(int i = 1; i < teams.size(); i++) {
        if (ms < teams.at(i)->getBestRound()) {
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

QList<Team *> TeamManager::getTeams()
{
    return teams;
}

QList<Team *> TeamManager::getTeamOrderByBestTime()
{
    // DESC sort by time
    return teams;
}

QList<Team *> TeamManager::getTeamOrderByRounds()
{
    // DESC sort by rounds count
    return teams;
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
