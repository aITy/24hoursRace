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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QAction *actionPrintByRounds;
    QAction *actionBestByTimeDesc;
    QAction *actionBestByTimeAsc;
    QAction *actionPrintByTimeDesc;
    QAction *actionPrintByTimeAsc;
    QAction *actionXmlExport;
    QAction *actionXmlImport;
    QAction *actionPrintByTeam;
    QAction *action_SortByTimeDesc;
    QAction *action_SortByTimeAsc;
    QAction *action_SortByRoundsDesc;
    QAction *action_SortByRoundsAsc;
    QAction *action_Save;
    QAction *action_Open;
    QAction *action_changeSettings;
    QAction *action_TeamEdit;
    QAction *action_Print;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *ListRight;
    QLabel *label_RankRight;
    QLabel *label_NameRight;
    QLabel *label_RoundRight;
    QGridLayout *ListLeft;
    QLabel *label_RankLeft;
    QLabel *label_RoundLeft;
    QLabel *label_NameLeft;
    QVBoxLayout *middleLayout;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuData;
    QMenu *menuTest;
    QMenu *menu_azen;
    QToolBar *mainToolBar;
    QStatusBar *myStatusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        action_Start = new QAction(MainWindow);
        action_Start->setObjectName(QStringLiteral("action_Start"));
        actionBestByRoundsDesc = new QAction(MainWindow);
        actionBestByRoundsDesc->setObjectName(QStringLiteral("actionBestByRoundsDesc"));
        actionBestByRoundsAsc = new QAction(MainWindow);
        actionBestByRoundsAsc->setObjectName(QStringLiteral("actionBestByRoundsAsc"));
        actionPrintByRoundsDesc = new QAction(MainWindow);
        actionPrintByRoundsDesc->setObjectName(QStringLiteral("actionPrintByRoundsDesc"));
        actionPrintByRounds = new QAction(MainWindow);
        actionPrintByRounds->setObjectName(QStringLiteral("actionPrintByRounds"));
        actionBestByTimeDesc = new QAction(MainWindow);
        actionBestByTimeDesc->setObjectName(QStringLiteral("actionBestByTimeDesc"));
        actionBestByTimeAsc = new QAction(MainWindow);
        actionBestByTimeAsc->setObjectName(QStringLiteral("actionBestByTimeAsc"));
        actionPrintByTimeDesc = new QAction(MainWindow);
        actionPrintByTimeDesc->setObjectName(QStringLiteral("actionPrintByTimeDesc"));
        actionPrintByTimeAsc = new QAction(MainWindow);
        actionPrintByTimeAsc->setObjectName(QStringLiteral("actionPrintByTimeAsc"));
        actionXmlExport = new QAction(MainWindow);
        actionXmlExport->setObjectName(QStringLiteral("actionXmlExport"));
        actionXmlImport = new QAction(MainWindow);
        actionXmlImport->setObjectName(QStringLiteral("actionXmlImport"));
        actionPrintByTeam = new QAction(MainWindow);
        actionPrintByTeam->setObjectName(QStringLiteral("actionPrintByTeam"));
        action_SortByTimeDesc = new QAction(MainWindow);
        action_SortByTimeDesc->setObjectName(QStringLiteral("action_SortByTimeDesc"));
        action_SortByTimeAsc = new QAction(MainWindow);
        action_SortByTimeAsc->setObjectName(QStringLiteral("action_SortByTimeAsc"));
        action_SortByRoundsDesc = new QAction(MainWindow);
        action_SortByRoundsDesc->setObjectName(QStringLiteral("action_SortByRoundsDesc"));
        action_SortByRoundsAsc = new QAction(MainWindow);
        action_SortByRoundsAsc->setObjectName(QStringLiteral("action_SortByRoundsAsc"));
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        action_changeSettings = new QAction(MainWindow);
        action_changeSettings->setObjectName(QStringLiteral("action_changeSettings"));
        action_TeamEdit = new QAction(MainWindow);
        action_TeamEdit->setObjectName(QStringLiteral("action_TeamEdit"));
        action_Print = new QAction(MainWindow);
        action_Print->setObjectName(QStringLiteral("action_Print"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setSizeIncrement(QSize(0, 0));
        centralWidget->setBaseSize(QSize(0, 0));
        centralWidget->setStyleSheet(QStringLiteral("border: 1px solid black;"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ListRight = new QGridLayout();
        ListRight->setSpacing(0);
        ListRight->setObjectName(QStringLiteral("ListRight"));
        ListRight->setContentsMargins(6, -1, -1, -1);
        label_RankRight = new QLabel(centralWidget);
        label_RankRight->setObjectName(QStringLiteral("label_RankRight"));

        ListRight->addWidget(label_RankRight, 0, 0, 1, 1);

        label_NameRight = new QLabel(centralWidget);
        label_NameRight->setObjectName(QStringLiteral("label_NameRight"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_NameRight->sizePolicy().hasHeightForWidth());
        label_NameRight->setSizePolicy(sizePolicy1);
        label_NameRight->setAlignment(Qt::AlignCenter);

        ListRight->addWidget(label_NameRight, 0, 1, 1, 1);

        label_RoundRight = new QLabel(centralWidget);
        label_RoundRight->setObjectName(QStringLiteral("label_RoundRight"));
        sizePolicy1.setHeightForWidth(label_RoundRight->sizePolicy().hasHeightForWidth());
        label_RoundRight->setSizePolicy(sizePolicy1);
        label_RoundRight->setMaximumSize(QSize(60, 16777215));
        label_RoundRight->setAlignment(Qt::AlignCenter);

        ListRight->addWidget(label_RoundRight, 0, 2, 1, 1);


        gridLayout->addLayout(ListRight, 0, 2, 1, 1);

        ListLeft = new QGridLayout();
        ListLeft->setSpacing(0);
        ListLeft->setObjectName(QStringLiteral("ListLeft"));
        ListLeft->setSizeConstraint(QLayout::SetMaximumSize);
        ListLeft->setContentsMargins(6, 0, 6, 0);
        label_RankLeft = new QLabel(centralWidget);
        label_RankLeft->setObjectName(QStringLiteral("label_RankLeft"));

        ListLeft->addWidget(label_RankLeft, 0, 0, 1, 1);

        label_RoundLeft = new QLabel(centralWidget);
        label_RoundLeft->setObjectName(QStringLiteral("label_RoundLeft"));
        sizePolicy1.setHeightForWidth(label_RoundLeft->sizePolicy().hasHeightForWidth());
        label_RoundLeft->setSizePolicy(sizePolicy1);
        label_RoundLeft->setMinimumSize(QSize(0, 0));
        label_RoundLeft->setMaximumSize(QSize(60, 16777215));
        label_RoundLeft->setAlignment(Qt::AlignCenter);

        ListLeft->addWidget(label_RoundLeft, 0, 2, 1, 1);

        label_NameLeft = new QLabel(centralWidget);
        label_NameLeft->setObjectName(QStringLiteral("label_NameLeft"));
        sizePolicy1.setHeightForWidth(label_NameLeft->sizePolicy().hasHeightForWidth());
        label_NameLeft->setSizePolicy(sizePolicy1);
        label_NameLeft->setAlignment(Qt::AlignCenter);

        ListLeft->addWidget(label_NameLeft, 0, 1, 1, 1);


        gridLayout->addLayout(ListLeft, 0, 0, 1, 1);

        middleLayout = new QVBoxLayout();
        middleLayout->setSpacing(0);
        middleLayout->setObjectName(QStringLiteral("middleLayout"));
        middleLayout->setSizeConstraint(QLayout::SetNoConstraint);

        gridLayout->addLayout(middleLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuData = new QMenu(menuBar);
        menuData->setObjectName(QStringLiteral("menuData"));
        menuTest = new QMenu(menuBar);
        menuTest->setObjectName(QStringLiteral("menuTest"));
        menu_azen = new QMenu(menuBar);
        menu_azen->setObjectName(QStringLiteral("menu_azen"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        myStatusBar = new QStatusBar(MainWindow);
        myStatusBar->setObjectName(QStringLiteral("myStatusBar"));
        MainWindow->setStatusBar(myStatusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuData->menuAction());
        menuBar->addAction(menu_azen->menuAction());
        menuBar->addAction(menuTest->menuAction());
        menuMenu->addAction(action_Start);
        menuMenu->addAction(action_changeSettings);
        menuMenu->addAction(action_Open);
        menuMenu->addAction(action_Save);
        menuMenu->addAction(action_Print);
        menuData->addAction(action_TeamEdit);
        menuTest->addAction(actionBestByRoundsDesc);
        menuTest->addAction(actionBestByRoundsAsc);
        menuTest->addAction(actionPrintByRounds);
        menuTest->addAction(actionBestByTimeDesc);
        menuTest->addAction(actionBestByTimeAsc);
        menuTest->addAction(actionPrintByTeam);
        menuTest->addAction(actionXmlExport);
        menuTest->addAction(actionXmlImport);
        menu_azen->addAction(action_SortByTimeAsc);
        menu_azen->addAction(action_SortByTimeDesc);
        menu_azen->addAction(action_SortByRoundsAsc);
        menu_azen->addAction(action_SortByRoundsDesc);

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
        actionPrintByRounds->setText(QApplication::translate("MainWindow", "printByRounds", 0));
        actionBestByTimeDesc->setText(QApplication::translate("MainWindow", "bestByTimeDesc", 0));
        actionBestByTimeAsc->setText(QApplication::translate("MainWindow", "bestByTimeAsc", 0));
        actionPrintByTimeDesc->setText(QApplication::translate("MainWindow", "printByTimeDesc", 0));
        actionPrintByTimeAsc->setText(QApplication::translate("MainWindow", "printByTimeAsc", 0));
        actionXmlExport->setText(QApplication::translate("MainWindow", "xmlExport", 0));
        actionXmlImport->setText(QApplication::translate("MainWindow", "xmlImport", 0));
        actionPrintByTeam->setText(QApplication::translate("MainWindow", "printByTeam", 0));
        action_SortByTimeDesc->setText(QApplication::translate("MainWindow", "se\305\231adit podle nejhor\305\241\303\255ho \304\215asu", 0));
        action_SortByTimeAsc->setText(QApplication::translate("MainWindow", "se\305\231adit podle nejlep\305\241\303\255ho \304\215asu", 0));
        action_SortByRoundsDesc->setText(QApplication::translate("MainWindow", "se\305\231adit podle po\304\215tu kol sestupn\304\233", 0));
        action_SortByRoundsAsc->setText(QApplication::translate("MainWindow", "se\305\231adit podle po\304\215tu kol vzestupn\304\233", 0));
        action_Save->setText(QApplication::translate("MainWindow", "Ulo\305\276it stav", 0));
        action_Open->setText(QApplication::translate("MainWindow", "Na\304\215\303\255st stav", 0));
        action_changeSettings->setText(QApplication::translate("MainWindow", "Zm\304\233nit nastaven\303\255", 0));
        action_TeamEdit->setText(QApplication::translate("MainWindow", "Editovat t\303\275my", 0));
        action_Print->setText(QApplication::translate("MainWindow", "Tisk", 0));
        label_RankRight->setText(QApplication::translate("MainWindow", "Po\305\231ad\303\255", 0));
        label_NameRight->setText(QApplication::translate("MainWindow", "Jm\303\251no", 0));
        label_RoundRight->setText(QApplication::translate("MainWindow", "Kol", 0));
        label_RankLeft->setText(QApplication::translate("MainWindow", "Po\305\231ad\303\255", 0));
        label_RoundLeft->setText(QApplication::translate("MainWindow", "Kol", 0));
        label_NameLeft->setText(QApplication::translate("MainWindow", "Jm\303\251no", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
        menuData->setTitle(QApplication::translate("MainWindow", "Data", 0));
        menuTest->setTitle(QApplication::translate("MainWindow", "Developing", 0));
        menu_azen->setTitle(QApplication::translate("MainWindow", "\305\230azen\303\255", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
