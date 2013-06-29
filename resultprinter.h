#ifndef RESULTPRINTER_H
#define RESULTPRINTER_H

#include <QObject>
#include "team.h"

class TeamManager;

class ResultPrinter : public QObject
{
    Q_OBJECT
public:
    explicit ResultPrinter(QObject *parent = 0);

    void updateTeams();

    void printResultsByRoundCount(bool);
    void printResultsByTime(bool);
    void printBestResultsByRoundCount(bool);
    void printBestResultsByTime(bool);


    void sortByRounds(bool order);
    void sortByTime(bool order);

    static bool sortByRoundsDesc(Team * s1, Team * s2) {
         return s1->getTotalRounds() > s2->getTotalRounds();
    }

    static bool sortByRoundsAsc(Team * s1, Team * s2) {
         return s1->getTotalRounds() < s2->getTotalRounds();
    }

    static bool sortByTimeDesc(Team * s1, Team * s2) {
         return s1->getBestRound() > s2->getBestRound();
    }

    static bool sortByTimeAsc(Team * s1, Team * s2) {
         return s1->getBestRound() < s2->getBestRound();
    }

private:
    TeamManager * manager;
    QList<Team *> teams;

signals:

public slots:

};

#endif // RESULTPRINTER_H
