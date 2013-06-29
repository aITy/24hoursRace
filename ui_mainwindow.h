/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Start;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *middleLayout;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuData;
    QToolBar *mainToolBar;
    QStatusBar *myStatusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(795, 650);
        action_Start = new QAction(MainWindow);
        action_Start->setObjectName(QStringLiteral("action_Start"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(260, 0, 261, 611));
        middleLayout = new QVBoxLayout(verticalLayoutWidget);
        middleLayout->setSpacing(6);
        middleLayout->setContentsMargins(11, 11, 11, 11);
        middleLayout->setObjectName(QStringLiteral("middleLayout"));
        middleLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 795, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuData = new QMenu(menuBar);
        menuData->setObjectName(QStringLiteral("menuData"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        myStatusBar = new QStatusBar(MainWindow);
        myStatusBar->setObjectName(QStringLiteral("myStatusBar"));
        MainWindow->setStatusBar(myStatusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuData->menuAction());
        menuMenu->addAction(action_Start);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_Start->setText(QApplication::translate("MainWindow", "Start", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
        menuData->setTitle(QApplication::translate("MainWindow", "Data", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
