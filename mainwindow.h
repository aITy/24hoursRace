#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include "ui_mainwindow.h"

class TeamManager;
class TimeBar;
class CmdLineBar;

class MainWindow : public QMainWindow, Ui::MainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static MainWindow * getInstance() {
            return instance;
    }

    void setStatusMsg(const char *);
    TimeBar * getTimeBar() { return timebar; }
    TeamManager * getTeamManager() { return manager; }
    CmdLineBar * getCmdline() { return cmdline; }

private:
    static MainWindow * instance;
    TimeBar * timebar;
    TeamManager * manager;
    CmdLineBar * cmdline;

public slots:

private slots:
    void run();

signals:

};

#endif // MAINWINDOW_H
