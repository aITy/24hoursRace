#include "resultprinter.h"
#include "mainwindow.h"
#include "teammanager.h"
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
                                   QDir::homePath(),
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
                                   QDir::homePath(),
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
