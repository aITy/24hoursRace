#include "team.h"
#include "mainwindow.h"
#include "timebar.h"

Team::Team(QObject * parent) :
    QObject(parent)
{
    name = "";
    round_start = MainWindow::getInstance()->getTimeBar()->getTotalTime();
}

Team::Team(const QString & new_name, QObject * parent)
    :name(new_name), QObject(parent)
{
    round_start = MainWindow::getInstance()->getTimeBar()->getTotalTime();
}

Team::Team(const QString & new_name, QList<int> new_barcode, QObject * parent)
    :name(new_name), barcode(new_barcode), QObject(parent)
{
    round_start = MainWindow::getInstance()->getTimeBar()->getTotalTime();
}

Team::Team(const QString & new_name, QList<QString> new_racers, QObject * parent)
    :name(new_name), racers(new_racers), QObject(parent)
{
    round_start = MainWindow::getInstance()->getTimeBar()->getTotalTime();
}

Team::Team(const QString & new_name, QList<int> new_barcode, QList<QString> new_racers, QObject * parent)
    :name(new_name), barcode(new_barcode), racers(new_racers), QObject(parent)
{
    round_start = MainWindow::getInstance()->getTimeBar()->getTotalTime();
}

int Team::getLastRound()
{
    if (rounds.empty())
        return -1;
    return rounds.last();
}

int Team::getBestRound()
{
    if (rounds.empty())
        return -1;

    int ind = 0;
    int best = rounds.first();
    for (int i = 1; i < rounds.size(); i++) {
        if (rounds.at(i) < best) {
            best = rounds.at(i);
            ind = i;
        }

    }
    return rounds[ind];
}

int Team::getTotalRounds()
{
    return rounds.size();
}


void Team::addRound(int round)
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

QString Team::getBarcodeStr()
{
    QString str;
    for (int i = 0; i < barcode.size(); i++) {
        str.append(QString::number(barcode.at(i)));
    }
    return str;
}

void Team::addRacer(const QString & racer)
{
    racers.append(racer);
}

void Team::addRacers(QList<QString> new_racers)
{
    racers = new_racers;
}

bool Team::isFilled()
{
    if (barcode.empty() || name == "")
        return false;
    return true;
}
