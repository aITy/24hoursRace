#include "resultprinter.h"
#include "mainwindow.h"
#include "teammanager.h"
#include "team.h"
#include <QFileDialog>
#include <QTextStream>

ResultPrinter::ResultPrinter(QObject *parent) :
    QObject(parent)
{
    manager = MainWindow::getInstance()->getTeamManager();
    teams = manager->getTeams();
}

void ResultPrinter::updateTeams()
{
    teams = manager->getTeams();
}

void ResultPrinter::printResultsByRoundCount(bool)
{

}

void ResultPrinter::printResultsByTime(bool)
{

}

void ResultPrinter::printBestResultsByRoundCount(bool order)
{
    // order = true - descending, false - ascending
    QString fn = QFileDialog::getSaveFileName(NULL,
                                   trUtf8("Ulozit aktualni vysledky do souboru"),
                                   "",
                                   trUtf8("Jakykoliv typ souboru %1").arg("*.*"));
    if (!fn.isEmpty())
    {
        QFile f(fn);
        /** overwrite file */
        if (! f.open(QIODevice::WriteOnly | QIODevice::Truncate))
            return;
        QTextStream fs(&f);

        QString content;
        int longest_name = 0;

        if (order)
            sortByRounds(true);
        else
            sortByRounds(false);

        for (int i = 0; i < teams.size(); i++) {
            if (teams.at(i)->getName().count() > longest_name)
                longest_name = teams.at(i)->getName().count();
        }

        for (int i = 0; i < teams.size(); i++) {
            content.append(QString("%1. %2").arg(i+1).arg(teams.at(i)->getName()));
            for( int j = 0; j < longest_name + 1 - teams.at(i)->getName().count(); j++) {
                content.append(QString(" "));
            }
            content.append(QString::number(teams.at(i)->getTotalRounds()));
            content.append("\n");
        }

        fs << content;
    }

}

void ResultPrinter::printBestResultsByTime(bool order)
{
    // order = true - descending, false - ascending

    QString fn = QFileDialog::getSaveFileName(NULL,
                                   trUtf8("Ulozit aktualni vysledky do souboru"),
                                   "",
                                   trUtf8("Jakykoliv typ souboru %1").arg("*.*"));
    if (!fn.isEmpty())
    {
        QFile f(fn);
        /** overwrite file */
        if (! f.open(QIODevice::WriteOnly | QIODevice::Truncate))
            return;
        QTextStream fs(&f);

        QString content;
        int longest_name = 0;

        if (order)
            sortByTime(true);
        else
            sortByTime(false);

        for (int i = 0; i < teams.size(); i++) {
            if (teams.at(i)->getName().count() > longest_name)
                longest_name = teams.at(i)->getName().count();
        }

        for (int i = 0; i < teams.size(); i++) {
            content.append(QString("%1. %2").arg(i+1).arg(teams.at(i)->getName()));
            for( int j = 0; j < longest_name + 1 - teams.at(i)->getName().count(); j++) {
                content.append(QString(" "));
            }

            int time = teams.at(i)->getBestRound();
            int hours = time / (1000*60*60);
            int minutes = (time % (1000*60*60)) / (1000*60);
            int seconds = ((time % (1000*60*60)) % (1000*60)) / 1000;

            //Move the HH:MM:SS to the labels
            if (hours < 10)
                content.append(QString("0%1").arg(hours));
            else
                content.append(QString::number(hours));

            content.append(QString(":"));

            if (minutes < 10)
                content.append(QString("0%1").arg(minutes));
            else
                content.append(QString::number(minutes));

            content.append(QString(":"));

            if (seconds < 10)
                content.append(QString("0%1").arg(seconds));
            else
                content.append(QString::number(seconds));

            content.append("\n");
        }

        fs << content;
    }
}

void ResultPrinter::printResultsByTeams()
{
    QString fn = QFileDialog::getSaveFileName(NULL,
                                   trUtf8("Ulozit aktualni vysledky do souboru"),
                                   "",
                                   trUtf8("Jakykoliv typ souboru %1").arg("*.*"));
    if (!fn.isEmpty())
    {
        QFile f(fn);
        /** overwrite file */
        if (! f.open(QIODevice::WriteOnly | QIODevice::Truncate))
            return;
        QTextStream fs(&f);

        QString content;
        QString name = trUtf8("Název týmu:");
        QString racers = trUtf8("Závodníci:");
        QString rounds_str = trUtf8("Jednotlivá kola:");
        int longest_name = rounds_str.length();

        for (int i = 0; i < teams.size(); i++) {
            content.append(QString("%1.\n").arg(i+1));

            content.append(name);
            for( int j = 0; j < longest_name + 4 - name.length(); j++) {
                content.append(QString(" "));
            }
            content.append(teams.at(i)->getName());
            content.append("\n");

            if (! teams.at(i)->getRacers().empty()) {
                content.append(racers);
                for( int j = 0; j < longest_name + 4 - racers.length(); j++) {
                    content.append(QString(" "));
                }
                for (int j = 0; j < teams.at(i)->getRacers().count(); j++) {
                    content.append(teams.at(i)->getRacers().at(j));
                    if (j + 1 < teams.at(i)->getRacers().count()) {
                        content.append(", ");
                    }
                }
                content.append("\n");
            }

            content.append(rounds_str);
            QList<int>rounds = teams.at(i)->getRounds();
            int time;
            for(int j = 0; j < rounds.count(); j++) {
                if (j == 0) {
                    for( int j = 0; j < longest_name + 4 - rounds_str.length(); j++) {
                        content.append(QString(" "));
                    }
                }
                else {
                    for( int j = 0; j < longest_name + 4; j++) {
                        content.append(QString(" "));
                    }
                }
                content.append(QString("%1.").arg(j + 1));
                time = rounds.at(j);

                int hours = time / (1000*60*60);
                int minutes = (time % (1000*60*60)) / (1000*60);
                int seconds = ((time % (1000*60*60)) % (1000*60)) / 1000;

                if (hours < 10)
                    content.append(QString("0%1").arg(hours));
                else
                    content.append(QString::number(hours));

                content.append(QString(":"));

                if (minutes < 10)
                    content.append(QString("0%1").arg(minutes));
                else
                    content.append(QString::number(minutes));

                content.append(QString(":"));

                if (seconds < 10)
                    content.append(QString("0%1").arg(seconds));
                else
                    content.append(QString::number(seconds));

                content.append("\n");

            }
        }
        fs.setCodec("UTF-8");
        fs << content;
        f.close();
    }
}

void ResultPrinter::printByRounds()
{
    QString fn = QFileDialog::getSaveFileName(NULL,
                                   trUtf8("Ulozit aktualni vysledky do souboru"),
                                   "",
                                   trUtf8("Jakykoliv typ souboru %1").arg("*.*"));
    if (!fn.isEmpty())
    {
        QFile f(fn);
        /** overwrite file */
        if (! f.open(QIODevice::WriteOnly | QIODevice::Truncate))
            return;
        QTextStream fs(&f);

        QString content;
        QString rounds_str = trUtf8("Čas kola");

        int longest_name = 0;
        for (int i = 0; i < teams.size(); i++) {
            if (teams.at(i)->getName().count() > longest_name)
                longest_name = teams.at(i)->getName().count();
        }

        content.append(trUtf8("Pořadí Název týmu"));
        for(int i = 0; i < longest_name - content.count() + 1; i++) {
            content.append(" ");
        }
        content.append(trUtf8("Čas kola\n"));
        QList<QPair<Team *, int> > rounds = MainWindow::getInstance()->getTeamManager()->getRounds();

        for (int i = 0; i < rounds.count(); i++) {
            QString order_number = QString::number(i + 1);
            for (int j = 0; j < 7 - 1 - 1 - order_number.count(); j++) {
                content.append(" ");
            }
            content.append(QString("%1. ").arg(i + 1));
            content.append(rounds.at(i).first->getName());
            for(int j = 0; j < longest_name + 1 - rounds.at(i).first->getName().count(); j++) {
                content.append(" ");
            }

            int time = rounds.at(i).second;

            int hours = time / (1000*60*60);
            int minutes = (time % (1000*60*60)) / (1000*60);
            int seconds = ((time % (1000*60*60)) % (1000*60)) / 1000;

            if (hours < 10)
                content.append(QString("0%1").arg(hours));
            else
                content.append(QString::number(hours));

            content.append(QString(":"));

            if (minutes < 10)
                content.append(QString("0%1").arg(minutes));
            else
                content.append(QString::number(minutes));

            content.append(QString(":"));

            if (seconds < 10)
                content.append(QString("0%1").arg(seconds));
            else
                content.append(QString::number(seconds));

            content.append("\n");
        }

        fs.setCodec("UTF-8");
        fs << content;
        f.close();
    }
}

void ResultPrinter::sortByRounds(bool order)
{
    if (order) {
        // DESC
        qSort(teams.begin(), teams.end(), sortByRoundsDesc);
    }
    else {
        // ASC
        qSort(teams.begin(), teams.end(), sortByRoundsAsc);
    }
}

void ResultPrinter::sortByTime(bool order)
{
    if (order) {
        // DESC
        qSort(teams.begin(), teams.end(), sortByTimeDesc);
    }
    else {
        // ASC
        qSort(teams.begin(), teams.end(), sortByTimeAsc);
    }
}
