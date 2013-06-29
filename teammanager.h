#ifndef TEAMMANAGER_H
#define TEAMMANAGER_H

#include <QWidget>
#include "team.h"

class TimeBar;

class TeamManager : public QWidget
{
    Q_OBJECT
public:
    TeamManager(QWidget * parent = 0);
    //~TeamManager();

    Team * addTeam();
    Team * addTeam(const QString &);
    Team * addTeam(const QString &, QList<int>);
    Team * addTeam(const QString &, QList<QString>);
    Team * addTeam(const QString &, QList<int>, QList<QString>);

    void addRound(QList<int>);
    void addRound(const QString &);

    QPair< QString, int> getBestRound();
    QPair< QString, int> getLastRound();

    QList<Team *> getTeams();
    QList<Team *> getTeamOrderByBestTime();
    QList<Team *> getTeamOrderByRounds();

    void printRounds();
    void printRoundsByTeam();

private:
    QList<Team *> teams;
    TimeBar * timebar;
    int last_round_team_ind;
    QList<QPair< Team *, int > > rounds;
signals:
    
public slots:
    
};

#endif // TEAMMANAGER_H
