#include "team.h"

Team::Team(QObject *parent) :
    QObject(parent)
{
}

QPair<int, int> Team::getLastRound()
{
    if (rounds.empty())
        return QPair<int, int>(-1, -1);
    return rounds.last();
}

QPair<int, int> Team::getBestRound()
{
    if (rounds.empty())
        return QPair<int, int>(-1, -1);

    int ind = 0;
    int best = rounds.first().first;
    for (int i = 1; i < rounds.size(); i++) {
        if (rounds.at(i).first < best) {
            best = rounds.at(i).first;
            ind = i;
        }

    }
    return rounds[ind];
}

int Team::getTotalRounds()
{
    return rounds.size();
}


void Team::addRound(QPair<int, int> round)
{
    rounds.append(round);
}

void Team::changeBarcode(QList<int> new_barcode)
{
    barcode = new_barcode;
}


void Team::changeName(const QString & new_name)
{
    name = new_name;
}

void Team::addRacer(const QString & racer)
{
    racers.append(racer);
}

void Team::addRacers(QList<QString> new_racers)
{
    racers = new_racers;
}
