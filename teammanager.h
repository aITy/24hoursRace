#ifndef TEAMMANAGER_H
#define TEAMMANAGER_H

#include <QWidget>
#include "team.h"
#include <QDebug>

class TimeBar;

class TeamManager : public QWidget
{
    Q_OBJECT
public:
    TeamManager(QWidget * parent = 0);
    ~TeamManager();

    Team * addTeam();
    Team * addTeam(const QString &);
    Team * addTeam(const QString &, QList<int>);
    Team * addTeam(const QString &, QList<QString>);
    Team * addTeam(const QString &, QList<int>, QList<QString>);

    Team * getTeamByName(const QString &);
    Team * getTeamByBarcode(QList<int>);

    void addRound(QList<int>);
    void addRound(const QString &);
    void addRound(const QString &, int);

    QList<QPair< Team *, int > > getRounds() { return rounds; }
    QPair< QString, int> getBestRound();
    QPair< QString, int> getLastRound();

    QList<Team *> getTeams();
    QList<Team *> getTeamOrderByBestTime();
    QList<Team *> getTeamOrderByRounds();

    void clearTeams();
    void clearRounds();
    void updateToolBar();

    // bool = true - DESC
    void sortByRounds(bool);
    void sortByTime(bool);

    static bool sortByRoundsDesc(Team * s1, Team * s2) {
        return s1->getTotalRounds() > s2->getTotalRounds();
    }

    static bool sortByRoundsAsc(Team * s1, Team * s2) {
        return s1->getTotalRounds() < s2->getTotalRounds();
    }

    static bool sortByTimeDesc(Team * s1, Team * s2) {
        if (s1->getBestRound() == -1) {
            return true;
        }
        if (s2->getBestRound() == -1) {
            return false;
        }
        return s1->getBestRound() > s2->getBestRound();
    }

    static bool sortByTimeAsc(Team * s1, Team * s2) {
        if (s1->getBestRound() == -1)
            return false;
        if (s2->getBestRound() == -1)
            return true;
        return s1->getBestRound() < s2->getBestRound();
    }


    // DEBUGGING FUNCTIONS
    void printRounds(); // TODO - DELETE
    void printRoundsByTeam(); // TODO - DELETE


private:
    QList<Team *> teams;
    TimeBar * timebar;
    int last_round_team_ind;
    QList<QPair< Team *, int > > rounds;
signals:
    
public slots:
    
};

#endif // TEAMMANAGER_H
