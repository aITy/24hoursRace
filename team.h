#ifndef TEAM_H
#define TEAM_H

#include <QCoreApplication>
#include <QPair>

class Team : public QObject
{
    Q_OBJECT
public:
    explicit Team(QObject *parent = 0);
    explicit Team(const QString &, QObject * parent = 0);
    explicit Team(const QString &, QList<int> , QObject * parent = 0);
    explicit Team(const QString &, QList<QString> , QObject * parent = 0);
    explicit Team(const QString &, QList<int>, QList<QString>, QObject * parent = 0);

    int getLastRound();
    int getBestRound();
    int getTotalRounds();
    QList<int> getRounds() { return rounds; }
    void addRound(int);
    void addRacer(const QString &);
    void addRacers(QList<QString>);
    void changeBarcode(QList<int>);
    void changeName(const QString &);
    QString getName() { return name; }
    QList<int> getBarcode() { return barcode; }
    void setRoundStart() { /*settings->getRaceTime()*/ }
    int getRoundStart() { return round_start; }

    bool isFilled();

private:
    QString name;
    QList<int> barcode;
    QList<QString> racers;
    // list of time
    QList<int> rounds;
    int round_start;

signals:
    
public slots:
    
};

#endif // TEAM_H
