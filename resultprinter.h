#ifndef RESULTPRINTER_H
#define RESULTPRINTER_H

#include <QObject>

class TeamManager;
class Team;

class ResultPrinter : public QObject
{
    Q_OBJECT
public:
    explicit ResultPrinter(QObject *parent = 0);

    bool printResultsByRoundCount(bool);
    bool printResultsByTime(bool);

private:
    TeamManager * manager;

signals:

public slots:

};

#endif // RESULTPRINTER_H
