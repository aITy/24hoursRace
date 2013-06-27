#ifndef TEAMMANAGER_H
#define TEAMMANAGER_H

#include <QObject>

class Team;
class TimeBar;

class TeamManager : public QObject
{
    Q_OBJECT
public:
    explicit TeamManager(QObject *parent = 0);
    QPair< QString, QPair< int, int> > getBestRound();
    QPair< QString, QPair< int, int> > getLastRound();
    QList<Team *> getTeamOrder();
    QList<Team *> getTeamOrderByBestTime();
    QList<Team *> getTeamOrderByRounds();

private:
    QList<Team*> teams;
    TimeBar * timebar;
    int last_round_team_ind;
signals:
    
public slots:
    
};

#endif // TEAMMANAGER_H
