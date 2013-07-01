/********************************************************************************
** Form generated from reading UI file 'lastroundbar.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASTROUNDBAR_H
#define UI_LASTROUNDBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LastRoundBar
{
public:
    QWidget *widget;
    QLabel *label_M;
    QLabel *label_S;
    QLabel *label_Min;
    QLabel *label_4;
    QLabel *label_Team;
    QLabel *label_Rounds;
    QLabel *label;

    void setupUi(QWidget *LastRoundBar)
    {
        if (LastRoundBar->objectName().isEmpty())
            LastRoundBar->setObjectName(QStringLiteral("LastRoundBar"));
        LastRoundBar->resize(220, 180);
        LastRoundBar->setMinimumSize(QSize(220, 180));
        LastRoundBar->setMaximumSize(QSize(220, 180));
        LastRoundBar->setStyleSheet(QLatin1String("background: rgb(180, 180, 180);\n"
"border: 2px solid black;\n"
""));
        widget = new QWidget(LastRoundBar);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(2, 2, 216, 176));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(216, 176));
        widget->setStyleSheet(QLatin1String("border: none;\n"
""));
        label_M = new QLabel(widget);
        label_M->setObjectName(QStringLiteral("label_M"));
        label_M->setGeometry(QRect(10, 8, 61, 41));
        QFont font;
        font.setFamily(QStringLiteral("Radio Space Bold"));
        font.setPointSize(32);
        font.setBold(true);
        font.setWeight(75);
        label_M->setFont(font);
        label_M->setStyleSheet(QStringLiteral("color: rgb(245, 245, 245)"));
        label_M->setAlignment(Qt::AlignCenter);
        label_S = new QLabel(widget);
        label_S->setObjectName(QStringLiteral("label_S"));
        label_S->setGeometry(QRect(90, 8, 60, 41));
        label_S->setFont(font);
        label_S->setAutoFillBackground(false);
        label_S->setStyleSheet(QStringLiteral("color: rgb(245, 245, 245)"));
        label_S->setAlignment(Qt::AlignCenter);
        label_Min = new QLabel(widget);
        label_Min->setObjectName(QStringLiteral("label_Min"));
        label_Min->setGeometry(QRect(150, 8, 60, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Radio Space Bold"));
        font1.setPointSize(23);
        font1.setBold(true);
        font1.setWeight(75);
        label_Min->setFont(font1);
        label_Min->setStyleSheet(QStringLiteral("color: rgb(245, 245, 245)"));
        label_Min->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(71, 8, 20, 41));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(245, 245, 245)"));
        label_4->setInputMethodHints(Qt::ImhNone);
        label_4->setAlignment(Qt::AlignCenter);
        label_Team = new QLabel(widget);
        label_Team->setObjectName(QStringLiteral("label_Team"));
        label_Team->setGeometry(QRect(10, 50, 200, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Radio Space Bold"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_Team->setFont(font2);
        label_Team->setStyleSheet(QStringLiteral("color: rgb(29, 29, 29)"));
        label_Team->setAlignment(Qt::AlignCenter);
        label_Rounds = new QLabel(widget);
        label_Rounds->setObjectName(QStringLiteral("label_Rounds"));
        label_Rounds->setGeometry(QRect(10, 92, 200, 51));
        QFont font3;
        font3.setFamily(QStringLiteral("Radio Space Bold"));
        font3.setPointSize(30);
        font3.setBold(true);
        font3.setWeight(75);
        label_Rounds->setFont(font3);
        label_Rounds->setStyleSheet(QStringLiteral("color: rgb(44, 44, 44)"));
        label_Rounds->setAlignment(Qt::AlignCenter);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(3, 146, 211, 30));
        QFont font4;
        font4.setFamily(QStringLiteral("Radio Space Bold"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);
        label->setStyleSheet(QStringLiteral("color: white;"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(LastRoundBar);

        QMetaObject::connectSlotsByName(LastRoundBar);
    } // setupUi

    void retranslateUi(QWidget *LastRoundBar)
    {
        LastRoundBar->setWindowTitle(QApplication::translate("LastRoundBar", "Form", 0));
        label_M->setText(QApplication::translate("LastRoundBar", "00", 0));
        label_S->setText(QApplication::translate("LastRoundBar", "00", 0));
        label_Min->setText(QApplication::translate("LastRoundBar", "min.", 0));
        label_4->setText(QApplication::translate("LastRoundBar", ":", 0));
        label_Team->setText(QString());
        label_Rounds->setText(QApplication::translate("LastRoundBar", "0", 0));
        label->setText(QApplication::translate("LastRoundBar", "POSLEDNI PRIPSANE KOLO", 0));
    } // retranslateUi

};

namespace Ui {
    class LastRoundBar: public Ui_LastRoundBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASTROUNDBAR_H
