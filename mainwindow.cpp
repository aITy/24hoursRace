#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timebar.h"

MainWindow * MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    instance = this;
    setupUi(this);
    //middleLayout->setAlignment(Qt::AlignCenter);

    timebar = new TimeBar();
    middleLayout->addWidget(timebar);
}

MainWindow::~MainWindow()
{
    if (timebar)
        delete timebar;
}

void MainWindow::setStatusMsg(const char * msg) {
    myStatusBar->showMessage(QString(msg), 2500);
}
