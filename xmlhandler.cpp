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
    file.open(QIODevice::ReadOnly);
    QDomDocument xml;
    xml.setContent(file.readAll());

    QDomElement elem;
    QDomNodeList nodes;
    QDomNode node;

    nodes = xml.elementsByTagName(trUtf8("Týmy"));
    node = nodes.at(0);
    elem = node.toElement();

    // destroy vsech objektu... a novy, timer atd.

    while(!node.isNull()) {

        if (!node.toElement().hasAttribute(trUtf8("název")))
            return false;
        QString name = node.toElement().attributeNode(trUtf8("název")).value();

        if (!node.toElement().hasAttribute(trUtf8("kód")))
            return false;
        QString barcode_str = node.toElement().attributeNode(trUtf8("kód")).value();
        QList<int> barcode;
        for(int i = 0; i < barcode_str.count(); i++) {
            barcode.append(QString(barcode_str.at(i)).toInt());
        }

        Team * team = new Team(name, barcode);
        if (node.hasChildNodes()) {
            nodes = node.childNodes();
            node = nodes.at(0);

            while(!node.isNull()) {
                if (!node.toElement().hasAttribute(trUtf8("jméno")))
                    break;

                team->addRacer(node.toElement().attributeNode(trUtf8("jméno")).value());
                node = node.nextSibling();
            }

        }

        node = node.nextSibling();
    }


    file.close();

    return true;

}

bool XmlHandler::xmlExport(const QString & filename)
{
    QDomDocument doc;
    doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
    QDomElement team_db = doc.createElement(trUtf8("Týmy"));

    QList<Team *> teams = MainWindow::getInstance()->getTeamManager()->getTeams();
    TimeBar * timebar = MainWindow::getInstance()->getTimeBar();

    for (int i = 0; i < teams.count(); i++) {
        QDomElement team = doc.createElement(trUtf8("Tým"));
        team.setAttribute(trUtf8("název"), teams.at(i)->getName());
        team.setAttribute(trUtf8("kód"), teams.at(i)->getBarcodeStr());
        for (int j = 0; j < teams.at(i)->getRacers().count(); j++) {
            QDomElement racer = doc.createElement(trUtf8("závodník"));
            racer.setAttribute(trUtf8("jméno"), teams.at(i)->getRacers().at(j));
            team.appendChild(racer);
        }
        team_db.appendChild(team);
    }

    doc.appendChild(team_db);

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    stream << doc.toString();
    file.close();

    return true;

}

