#ifndef TEAM_H
#define TEAM_H

#include <QCoreApplication>
#include <QPair>

class Team : public QObject
{
    Q_OBJECT
public:
    explicit Team(QObject *parent = 0);
    explicit Team(const QString & , QObject * parent = 0);
    explicit Team(const QString & , QList <QString> , QObject * parent = 0);
    explicit Team(const QString &, QList<QString>, QList<int>, QObject *parent = 0);

    QPair < int, int > getLastRound();
    QPair < int, int > getBestRound();
    int getTotalRounds();
    void addRound(QPair<int, int>);
    void addRacer(const QString &);
    void addRacers(QList<QString>);
    void changeBarcode(QList<int>);
    void changeName(const QString &);
    QString getName() { return name; }
    QList<int> getBarcode() { return barcode; }
    void setRoundStart() { /*settings->getRaceTime()*/ }
    int getRoundStart() { return round_start; }

private:
    QString name;
    QList<int> barcode;
    QList<QString> racers;
    // list of time in ms and current position at the moment
    QList< QPair<int, int> > rounds;
    int round_start;

signals:
    
public slots:
    
};

#endif // TEAM_H
