#ifndef TEAMEDITDIALOG_H
#define TEAMEDITDIALOG_H

#include <QCoreApplication>
#include <QAbstractButton>
#include "ui_teameditdialog.h"

class TeamManager;
class Team;

class TeamEditDialog : public QDialog, Ui::TeamEditDialog
{
    Q_OBJECT
    
public:
    explicit TeamEditDialog(QWidget *parent = 0);
    explicit TeamEditDialog(TeamManager *, QWidget *parent = 0);
    ~TeamEditDialog();

    void updateTeam(Team *);
    
private:

    TeamManager * manager;
    QList<Team *> teams;
    QAbstractButton * button_ok;
    QAbstractButton * button_cancel;

    QString team_name;
    QString barcode;
    QString racers_str;
    QList<QString> racers;
    QList<QLabel *> labels;
    QList<QAbstractButton *> buttons;


protected:
    virtual void keyReleaseEvent(QKeyEvent *event);

signals:

private slots:
    void update();
    void acceptRequest();
    void addTeam();
    void deleteTeam();
};

#endif // TEAMEDITDIALOG_H
