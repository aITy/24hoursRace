#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QKeyEvent>
#include "ui_mainwindow.h"

class TeamManager;
class TimeBar;
class CmdLineBar;
class ResultPrinter;

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
    ResultPrinter * getPrinter() { return printer; }

private:
    static MainWindow * instance;
    TimeBar * timebar;
    TeamManager * manager;
    CmdLineBar * cmdline;
    ResultPrinter * printer;

protected:
    void closeEvent(QCloseEvent *);
    void mousePressEvent(QMouseEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

public slots:

private slots:
    void run();

signals:

};

#endif // MAINWINDOW_H
