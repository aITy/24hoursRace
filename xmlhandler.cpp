#include <QtCore>
#include <QXmlStreamWriter>
#include <QtXml/qdom.h>
#include "xmlhandler.h"
#include "mainwindow.h"
#include "teammanager.h"
#include "resultprinter.h"
#include "team.h"
#include "timebar.h"
#include "settings.h"

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
    int err_line, err_column;
    QByteArray bytes = file.readAll();


    if (!xml.setContent(bytes, &err_msg, &err_line, &err_column)) {
        qDebug() << err_msg << err_line << err_column;
        file.close();
        return false;
    }
    file.close();

    QDomElement root = xml.documentElement();
    QDomElement elem;
    QDomNodeList nodes;
    QDomNode node;


    nodes = xml.elementsByTagName("db_casovac");
    if (nodes.count() <= 0)
        return false;
    elem = nodes.at(0).toElement();
    if (!elem.hasAttribute("celkovy_cas") || !elem.hasAttribute("aktualni_cas"))
        return false;

    MainWindow::getInstance()->reconstructTimeBar(elem.attributeNode("celkovy_cas").value().toInt(), elem.attributeNode("aktualni_cas").value().toInt());


    nodes = xml.elementsByTagName("db_tymy");
    if (nodes.count() <= 0)
        return false;
    node = nodes.at(0).firstChild();


    MainWindow::getInstance()->getTeamManager()->clearTeams();
    MainWindow::getInstance()->getTeamManager()->clearRounds();

    while(!node.isNull()) {
        elem = node.toElement();

        if (!elem.hasAttribute("nazev"))
            return false;
        QString name = elem.attributeNode("nazev").value();

        if (!elem.hasAttribute("kod"))
            return false;
        QString barcode_str = elem.attributeNode("kod").value();

        if (!elem.hasAttribute("id"))
            return false;

        int id = elem.attributeNode("id").value().toInt();

        QList<int> barcode;
        for(int i = 0; i < barcode_str.count(); i++) {
            barcode.append(QString(barcode_str.at(i)).toInt());
        }    

        MainWindow::getInstance()->getTeamManager()->addTeam(id, name, barcode);
        Team * team =  MainWindow::getInstance()->getTeamManager()->getTeamByName(name);
        if (node.hasChildNodes()) {
            QDomNodeList racers_nodes = node.childNodes();
            QDomNode racer_node = racers_nodes.at(0);

            while(!racer_node.isNull()) {
                if (!racer_node.toElement().hasAttribute("jmeno"))
                    break;

                team->addRacer(racer_node.toElement().attributeNode("jmeno").value());
                racer_node = racer_node.nextSibling();
            }
        }

        node = node.nextSibling();
    }

    nodes = xml.elementsByTagName("db_kol");
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

    nodes = xml.elementsByTagName("db_nastaveni");
    if (nodes.count() <= 0)
        return false;
    elem = nodes.at(0).toElement();
    if (!elem.hasAttribute("nadpis") || !elem.hasAttribute("pocet_tymu") || !elem.hasAttribute("delka_zavodu")
            || !elem.hasAttribute("limit_pripsani_kola") || !elem.hasAttribute("cesta_zalohy"))
        return false;

    Settings * settings = MainWindow::getInstance()->getSettings();

    settings->setHeadline(elem.attributeNode("nadpis").value());
    settings->setTeamsCount(elem.attributeNode("pocet_tymu").value().toInt());
    settings->setRaceLength(elem.attributeNode("delka_zavodu").value().toInt());
    settings->setRoundAdditionLimit(elem.attributeNode("limit_pripsani_kola").value().toInt());
    settings->setFilepath(elem.attributeNode("cesta_zalohy").value());
    settings->save();

    MainWindow::getInstance()->layoutBoard(settings->getTeamsCount());
    MainWindow::getInstance()->getTimeBar()->showTime();
    MainWindow::getInstance()->getTeamManager()->updateToolBar();
    MainWindow::getInstance()->getPrinter()->updateTeams();

    return true;

}

bool XmlHandler::xmlExport(const QString & filename)
{
    QDomDocument doc;
    QDomProcessingInstruction instr = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
    doc.appendChild(instr);

    QDomElement root = doc.createElement("db");
    QDomElement team_db = doc.createElement("db_tymy");

    QList<Team *> teams = MainWindow::getInstance()->getTeamManager()->getTeams();
    QList<QPair< Team *, int > > rounds = MainWindow::getInstance()->getTeamManager()->getRounds();
    TimeBar * timebar = MainWindow::getInstance()->getTimeBar();
    Settings * settings = MainWindow::getInstance()->getSettings();

    for (int i = 0; i < teams.count(); i++) {
        QDomElement team = doc.createElement("tym");
        team.setAttribute("nazev", teams.at(i)->getName());
        team.setAttribute("kod", teams.at(i)->getBarcodeStr());
        team.setAttribute("id", teams.at(i)->getID());
        for (int j = 0; j < teams.at(i)->getRacers().count(); j++) {
            QDomElement racer = doc.createElement("zavodnik");
            racer.setAttribute("jmeno", teams.at(i)->getRacers().at(j));
            team.appendChild(racer);
        }
        team_db.appendChild(team);
    }

    root.appendChild(team_db);

    QDomElement rounds_db = doc.createElement("db_kol");
    for (int i = 0; i < rounds.count(); i++) {
        QDomElement round = doc.createElement("kolo");
        round.setAttribute("tym", rounds.at(i).first->getName());
        round.setAttribute("cas", QString::number(rounds.at(i).second));
        rounds_db.appendChild(round);
    }
    root.appendChild(rounds_db);


    QDomElement timer_db = doc.createElement("db_casovac");
    timer_db.setAttribute("celkovy_cas", QString::number(timebar->getTotalTime()));
    timer_db.setAttribute("aktualni_cas", QString::number(timebar->getCurrentTime()));
    root.appendChild(timer_db);


    QDomElement settings_db = doc.createElement("db_nastaveni");
    settings_db.setAttribute("nadpis", settings->getHeadline());
    settings_db.setAttribute("pocet_tymu", settings->getTeamsCount());
    settings_db.setAttribute("delka_zavodu", settings->getRaceLength());
    settings_db.setAttribute("limit_pripsani_kola", settings->getRoundAdditionLimit());
    settings_db.setAttribute("cesta_zalohy", settings->getFilepath());
    root.appendChild(settings_db);

    doc.appendChild(root);

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    stream << doc.toString();
    file.close();

    return true;

}

