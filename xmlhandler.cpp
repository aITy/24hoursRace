#include <QtCore>
#include <QXmlStreamWriter>
#include <QtXml/qdom.h>
#include "xmlhandler.h"
#include "mainwindow.h"
#include "teammanager.h"
#include "team.h"
#include "timebar.h"

XmlHandler::XmlHandler(QObject *parent) :
    QObject(parent)
{
}

bool XmlHandler::xmlImport(const QString & filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QDomDocument xml;

    QString err_msg;
    if (!xml.setContent(file.readAll(),&err_msg)) {
        qDebug() << err_msg;
        file.close();
        return false;
    }
    file.close();

    QDomElement elem;
    QDomNodeList nodes;
    QDomNode node;

    nodes = xml.elementsByTagName("Tymy");
    if (nodes.count() <= 0)
        return false;
    node = nodes.at(0).firstChild();


    // destroy vsech objektu... a novy, timer atd.

    while(!node.isNull()) {
        elem = node.toElement();

        if (!elem.hasAttribute("nazev"))
            return false;
        QString name = elem.attributeNode("nazev").value();

        if (!elem.hasAttribute("kod"))
            return false;
        QString barcode_str = elem.attributeNode("kod").value();
        QList<int> barcode;
        for(int i = 0; i < barcode_str.count(); i++) {
            barcode.append(QString(barcode_str.at(i)).toInt());
        }

        MainWindow::getInstance()->getTeamManager()->addTeam(name, barcode);
        Team * team =  MainWindow::getInstance()->getTeamManager()->getTeamByName(name);
        if (node.hasChildNodes()) {
            nodes = node.childNodes();
            node = nodes.at(0);

            while(!node.isNull()) {
                if (!node.toElement().hasAttribute("jmeno"))
                    break;

                team->addRacer(node.toElement().attributeNode("jmeno").value());
                node = node.nextSibling();
            }

        }

        node = node.nextSibling();
    }
    // TODO error - SOMEHOW this function returns NULL - file checked - everything all right
    nodes = xml.elementsByTagName("Kola");
    if (nodes.count() <= 0)
        return false;
    node = nodes.at(0).firstChild();


    while (! node.isNull()) {
        elem = node.toElement();

        if (!elem.hasAttribute("tym") || !elem.hasAttribute("cas"))
            return false;
        QString round_team = elem.attributeNode("tym").value();
        int round_time = elem.attributeNode("cas").value().toInt();

        MainWindow::getInstance()->getTeamManager()->addRound(round_team, round_time);

        node = node.nextSibling();
    }

    nodes = xml.elementsByTagName("casovac");
    if (nodes.count() <= 0)
        return false;
    elem = nodes.at(0).toElement();
    if (!elem.hasAttribute("celkovy_cas") || !elem.hasAttribute("aktualni_cas"))
        return false;

    MainWindow::getInstance()->reconstructTimeBar(elem.attributeNode("celkovy_cas").value().toInt(), elem.attributeNode("aktualni_cas").value().toInt());
    MainWindow::getInstance()->getTimeBar()->showTime();

    MainWindow::getInstance()->updateOrder();

    return true;

}

bool XmlHandler::xmlExport(const QString & filename)
{
    QDomDocument doc;
    doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
    QDomElement team_db = doc.createElement("Tymy");

    QList<Team *> teams = MainWindow::getInstance()->getTeamManager()->getTeams();
    QList<QPair< Team *, int > > rounds = MainWindow::getInstance()->getTeamManager()->getRounds();
    TimeBar * timebar = MainWindow::getInstance()->getTimeBar();

    for (int i = 0; i < teams.count(); i++) {
        QDomElement team = doc.createElement("Tym");
        team.setAttribute("nazev", teams.at(i)->getName());
        team.setAttribute("kod", teams.at(i)->getBarcodeStr());
        for (int j = 0; j < teams.at(i)->getRacers().count(); j++) {
            QDomElement racer = doc.createElement("Zavodnik");
            racer.setAttribute("jmeno", teams.at(i)->getRacers().at(j));
            team.appendChild(racer);
        }
        team_db.appendChild(team);
    }

    doc.appendChild(team_db);

    QDomElement rounds_db = doc.createElement("Kola");
    for (int i = 0; i < rounds.count(); i++) {
        QDomElement round = doc.createElement("Kolo");
        round.setAttribute("tym", rounds.at(i).first->getName());
        round.setAttribute("cas", rounds.at(i).second);
        rounds_db.appendChild(round);
    }
    doc.appendChild(rounds_db);

    QDomElement timer_db = doc.createElement("casovac");
    timer_db.setAttribute("celkovy_cas", QString::number(timebar->getTotalTime()));
    timer_db.setAttribute("aktualni_cas", QString::number(timebar->getCurrentTime()));
    doc.appendChild(timer_db);

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    stream << doc.toString();
    file.close();

    return true;

}

