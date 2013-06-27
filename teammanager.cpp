#include "teammanager.h"
#include "timebar.h"
#include "team.h"
#include "mainwindow.h"

TeamManager::TeamManager(QObject *parent) :
    QObject(parent)
{
    timebar = MainWindow::getInstance()->getTimeBarPtr();
}

QPair<QString, QPair<int, int> > TeamManager::getBestRound()
{
    if (teams.empty())
        return QPair<QString, QPair<int, int> >("", QPair<int,int>(-1,-1));
    int ind = 0;
    int ms = teams.first()->getBestRound().first;
    for(int i = 1; i < teams.size(); i++) {
        if (ms < teams.at(i)->getBestRound().first) {
            ind = i;
        }
    }
    QPair<int, int> best_round = teams.at(i)->getBestRound();
    QString best_round_team = teams.at(i)->getName();
    return QPair< QString, QPair <int, int> >(best_round_team, best_round);
}

QPair<QString, QPair<int, int> > TeamManager::getLastRound()
{

}

QList<Team *> TeamManager::getTeamOrder()
{
    return teams;
}

QList<Team *> TeamManager::getTeamOrderByBestTime()
{
    // DESC sort by time
}

QList<Team *> TeamManager::getTeamOrderByRounds()
{
    // DESC sort by rounds count
}
