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

    TimeBar * time_bar = new TimeBar();
    middleLayout->addWidget(time_bar);
}

MainWindow::~MainWindow()
{

}

void MainWindow::setStatusMsg(const char * msg) {
    myStatusBar->showMessage(QString(msg), 2500);
}
