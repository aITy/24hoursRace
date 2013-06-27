#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include "ui_mainwindow.h"

class TimeBar;

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
    TimeBar* getTimeBarPtr() { return timebar; }

private:
    static MainWindow * instance;
    TimeBar * timebar;
};

#endif // MAINWINDOW_H
