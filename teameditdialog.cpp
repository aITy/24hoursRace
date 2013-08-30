#include "teameditdialog.h"
#include "teammanager.h"
#include "mainwindow.h"
#include "team.h"

TeamEditDialog::TeamEditDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    QList<QAbstractButton *> buttonbox = buttonBox->buttons();
    button_ok = buttonbox.at(0);
    button_cancel = buttonbox.at(1);

    verticalLayout_Teams->setAlignment(Qt::AlignTop);

    connect(button_ok, SIGNAL(clicked()), this, SLOT(acceptRequest()));
    connect(button_cancel, SIGNAL(clicked()), this, SLOT(reject()));

    connect(lineEdit_TeamName, SIGNAL(textChanged(QString)), this, SLOT(update()));
    connect(lineEdit_Racers, SIGNAL(textChanged(QString)), this, SLOT(update()));
    connect(lineEdit_Barcode, SIGNAL(textChanged(QString)), this, SLOT(update()));

    connect(pushButton_addTeam, SIGNAL(clicked()), this, SLOT(addTeam()));
    pushButton_addTeam->setFocus();
}

TeamEditDialog::TeamEditDialog(TeamManager * manager_ptr, QWidget *parent):
    QDialog(parent)
{
    setupUi(this);
    manager = manager_ptr;

    verticalLayout_Teams->setAlignment(Qt::AlignTop);

    QList<QAbstractButton *> buttonbox = buttonBox->buttons();
    button_ok = buttonbox.at(0);
    button_cancel = buttonbox.at(1);

    connect(button_ok, SIGNAL(clicked()), this, SLOT(acceptRequest()));
    connect(button_cancel, SIGNAL(clicked()), this, SLOT(reject()));

    connect(lineEdit_TeamName, SIGNAL(textChanged(QString)), this, SLOT(update()));
    connect(lineEdit_Racers, SIGNAL(textChanged(QString)), this, SLOT(update()));
    connect(lineEdit_Barcode, SIGNAL(textChanged(QString)), this, SLOT(update()));

    connect(pushButton_addTeam, SIGNAL(clicked()), this, SLOT(addTeam()));
    pushButton_addTeam->setFocus();

    for(int i = 0; i < manager->getTeams().count(); i++) {
        updateTeam(manager->getTeams().at(i));
    }
}

TeamEditDialog::~TeamEditDialog()
{
    if (teams.count() > 0) {
        for (int i = 0; i < teams.count(); i++) {
            Team * team = teams.takeAt(0);
            delete team;
        }
    }
}

void TeamEditDialog::updateTeam(Team * team)
{
    bool found = false;
    for(int i = 0; i < teams.count(); i++) {
        if (QString::compare(teams.at(i)->getName(), team->getName(), Qt::CaseInsensitive) == 0) {
            labels.at(i)->setText(QString("%1. \t %2 \t %3").arg(teams.size() + 1).arg(team->getName()).arg(team->getBarcodeStr()));
            teams.at(i)->changeBarcode(team->getBarcode());
            teams.at(i)->addRacers(team->getRacers());
            found = true;
        }
        else if (teams.at(i)->getBarcodeStr() == team->getBarcodeStr()) {
            labels.at(i)->setText(QString("%1. \t %2 \t %3").arg(teams.size() + 1).arg(team->getName()).arg(team->getBarcodeStr()));
            teams.at(i)->changeName(team->getName());
            teams.at(i)->addRacers(team->getRacers());
            found = true;
        }
    }
    if (!found) {
        QLabel * label = new QLabel(QString("%1. \t %2 \t %3").arg(teams.size() + 1).arg(team->getName()).arg(team->getBarcodeStr()));
        label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        label->setFont(QFont("Radio Space Bold", 16));
        label->setAlignment(Qt::AlignLeft);
        //label->setMaximumWidth(16777215);
        //label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
        labels.append(label);

        QAbstractButton * but = new QPushButton();
        but->setText("odstranit");
        //but->setMaximumWidth(100);
        //but->setFont(QFont("Radio Space Bold", 10));
        connect(but, SIGNAL(clicked()), this, SLOT(deleteTeam()));
        buttons.append(but);
        /*verticalLayout_Teams->addWidget(label);*/
        formLayout->addRow(label, but);
        teams.append(team);
    }

    lineEdit_TeamName->clear();
    lineEdit_Racers->clear();
    lineEdit_Barcode->clear();
}

void TeamEditDialog::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()) {
        event->ignore();
    }
    if (event->key() == 16777220) {
        acceptRequest();
        event->ignore();
    }
    if (event->key() == Qt::Key_Escape) {
        reject();
    }
}

void TeamEditDialog::update()
{
    team_name = lineEdit_TeamName->text();
    barcode = lineEdit_Barcode->text();
    racers_str = lineEdit_Racers->text();

}

void TeamEditDialog::acceptRequest()
{

    for (int i = 0; i < teams.count(); i++) {
        manager->updateTeam(teams.at(i));
    }
    MainWindow::getInstance()->updateOrder();
    QDialog::accept();
}

void TeamEditDialog::addTeam()
{
    if (team_name.isEmpty() || barcode.isEmpty())
        return;
    QList<int> real_barcode;
    for (int i = 0; i < barcode.count(); i++) {
        real_barcode.append(QString(barcode.at(i)).toInt());
    }
    Team * team = new Team(teams.size() + 1, team_name, real_barcode);
    QString str = racers_str;
    int state = 0;
    QString racer;
    if (!str.isEmpty()) {
        for(int i = 0; i < str.count(); i++) {
            switch(state) {
                case 0:
                    if (str.at(i) == ",") {
                        state = 1;
                    }
                    else {
                        racer.append(str.at(i));
                    }
                    break;
                case 1:
                    racers.append(racer);
                    racer = "";
                    state = 0;
                    break;
            }
        }
        team->addRacers(racers);
    }
    updateTeam(team);
}

void TeamEditDialog::deleteTeam()
{
    QAbstractButton * delete_but = qobject_cast<QAbstractButton *>(this->sender());
    for (int i = 0; i < buttons.size(); i++) {
        if (buttons.at(i) == delete_but) {

            QLayoutItem * item_label = formLayout->itemAt(i, QFormLayout::LabelRole);
            QLayoutItem * item_button = formLayout->itemAt(i, QFormLayout::FieldRole);
            formLayout->removeItem(item_label);
            formLayout->removeItem(item_button);
            delete item_label;
            delete item_button;

            qDebug() << "pred smazanim" << buttons.count();
            delete buttons.at(i);
            qDebug() << "po smazani" << buttons.count();
            buttons.removeAt(i);
            delete labels.at(i);
            labels.removeAt(i);

            teams.removeAt(i);
        }
    }

}
