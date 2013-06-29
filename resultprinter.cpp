#include "resultprinter.h"
#include "mainwindow.h"
#include "teammanager.h"
#include <QFileDialog>
#include <QTextStream>

ResultPrinter::ResultPrinter(QObject *parent) :
    QObject(parent)
{
    manager = MainWindow::getInstance()->getTeamManager();
}

bool ResultPrinter::printResultsByRoundCount(bool order)
{
    // order = true - descending, false - ascending
    QString fn = QFileDialog::getSaveFileName(NULL,
                                   trUtf8("Ulozit aktualni vysledky do souboru"),
                                   QDir::homePath(),
                                   trUtf8("Jakykoliv typ souboru").arg("*.*"));
    if (!fn.isEmpty())
    {
        QFile f(fn);
        /** overwrite file */
        f.open(QIODevice::WriteOnly | QIODevice::Truncate);
        QTextStream fs(&f);



        QString content;







        //fs << ;
        return true;
    }

    return false;
}

bool ResultPrinter::printResultsByTime(bool order)
{
    // order = true - descending, false - ascending
    return false;
}
