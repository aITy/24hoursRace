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
    QAction *actionBestByRoundsDesc;
    QAction *actionBestByRoundsAsc;
    QAction *actionPrintByRoundsDesc;
    QAction *actionPrintByRoundsAsc;
    QAction *actionBestByTimeDesc;
    QAction *actionBestByTimeAsc;
    QAction *actionPrintByTimeDesc;
    QAction *actionPrintByTimeAsc;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *middleLayout;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuData;
    QMenu *menuTest;
    QToolBar *mainToolBar;
    QStatusBar *myStatusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(795, 650);
        action_Start = new QAction(MainWindow);
        action_Start->setObjectName(QStringLiteral("action_Start"));
        actionBestByRoundsDesc = new QAction(MainWindow);
        actionBestByRoundsDesc->setObjectName(QStringLiteral("actionBestByRoundsDesc"));
        actionBestByRoundsAsc = new QAction(MainWindow);
        actionBestByRoundsAsc->setObjectName(QStringLiteral("actionBestByRoundsAsc"));
        actionPrintByRoundsDesc = new QAction(MainWindow);
        actionPrintByRoundsDesc->setObjectName(QStringLiteral("actionPrintByRoundsDesc"));
        actionPrintByRoundsAsc = new QAction(MainWindow);
        actionPrintByRoundsAsc->setObjectName(QStringLiteral("actionPrintByRoundsAsc"));
        actionBestByTimeDesc = new QAction(MainWindow);
        actionBestByTimeDesc->setObjectName(QStringLiteral("actionBestByTimeDesc"));
        actionBestByTimeAsc = new QAction(MainWindow);
        actionBestByTimeAsc->setObjectName(QStringLiteral("actionBestByTimeAsc"));
        actionPrintByTimeDesc = new QAction(MainWindow);
        actionPrintByTimeDesc->setObjectName(QStringLiteral("actionPrintByTimeDesc"));
        actionPrintByTimeAsc = new QAction(MainWindow);
        actionPrintByTimeAsc->setObjectName(QStringLiteral("actionPrintByTimeAsc"));
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
        menuTest = new QMenu(menuBar);
        menuTest->setObjectName(QStringLiteral("menuTest"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        myStatusBar = new QStatusBar(MainWindow);
        myStatusBar->setObjectName(QStringLiteral("myStatusBar"));
        MainWindow->setStatusBar(myStatusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuData->menuAction());
        menuBar->addAction(menuTest->menuAction());
        menuMenu->addAction(action_Start);
        menuTest->addAction(actionBestByRoundsDesc);
        menuTest->addAction(actionBestByRoundsAsc);
        menuTest->addAction(actionPrintByRoundsDesc);
        menuTest->addAction(actionPrintByRoundsAsc);
        menuTest->addAction(actionBestByTimeDesc);
        menuTest->addAction(actionBestByTimeAsc);
        menuTest->addAction(actionPrintByTimeDesc);
        menuTest->addAction(actionPrintByTimeAsc);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_Start->setText(QApplication::translate("MainWindow", "Start", 0));
        actionBestByRoundsDesc->setText(QApplication::translate("MainWindow", "bestByRoundsDesc", 0));
        actionBestByRoundsAsc->setText(QApplication::translate("MainWindow", "bestByRoundsAsc", 0));
        actionPrintByRoundsDesc->setText(QApplication::translate("MainWindow", "printByRoundsDesc", 0));
        actionPrintByRoundsAsc->setText(QApplication::translate("MainWindow", "printByRoundsAsc", 0));
        actionBestByTimeDesc->setText(QApplication::translate("MainWindow", "bestByTimeDesc", 0));
        actionBestByTimeAsc->setText(QApplication::translate("MainWindow", "bestByTimeAsc", 0));
        actionPrintByTimeDesc->setText(QApplication::translate("MainWindow", "printByTimeDesc", 0));
        actionPrintByTimeAsc->setText(QApplication::translate("MainWindow", "printByTimeAsc", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
        menuData->setTitle(QApplication::translate("MainWindow", "Data", 0));
        menuTest->setTitle(QApplication::translate("MainWindow", "Developing", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
