/********************************************************************************
** Form generated from reading UI file 'timebar.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEBAR_H
#define UI_TIMEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeBarWidget
{
public:
    QLabel *label_H;
    QLabel *label_M;
    QLabel *label_S;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;

    void setupUi(QWidget *TimeBarWidget)
    {
        if (TimeBarWidget->objectName().isEmpty())
            TimeBarWidget->setObjectName(QStringLiteral("TimeBarWidget"));
        TimeBarWidget->resize(220, 130);
        TimeBarWidget->setMinimumSize(QSize(220, 130));
        TimeBarWidget->setMaximumSize(QSize(220, 130));
        QFont font;
        font.setFamily(QStringLiteral("Radio Space Bold"));
        font.setBold(false);
        font.setWeight(50);
        TimeBarWidget->setFont(font);
        TimeBarWidget->setAutoFillBackground(false);
        TimeBarWidget->setStyleSheet(QStringLiteral("background-color: black"));
        label_H = new QLabel(TimeBarWidget);
        label_H->setObjectName(QStringLiteral("label_H"));
        label_H->setGeometry(QRect(10, 10, 60, 80));
        QFont font1;
        font1.setFamily(QStringLiteral("Radio Space Bold"));
        font1.setPointSize(32);
        font1.setBold(true);
        font1.setWeight(75);
        label_H->setFont(font1);
        label_H->setStyleSheet(QStringLiteral("color: white;"));
        label_H->setAlignment(Qt::AlignCenter);
        label_M = new QLabel(TimeBarWidget);
        label_M->setObjectName(QStringLiteral("label_M"));
        label_M->setGeometry(QRect(80, 10, 60, 80));
        label_M->setFont(font1);
        label_M->setAutoFillBackground(false);
        label_M->setStyleSheet(QStringLiteral("color: white;"));
        label_M->setAlignment(Qt::AlignCenter);
        label_S = new QLabel(TimeBarWidget);
        label_S->setObjectName(QStringLiteral("label_S"));
        label_S->setGeometry(QRect(150, 10, 60, 80));
        label_S->setFont(font1);
        label_S->setStyleSheet(QStringLiteral("color: white;"));
        label_S->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(TimeBarWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 10, 10, 80));
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("color: white;"));
        label_4->setInputMethodHints(Qt::ImhNone);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(TimeBarWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(140, 10, 10, 80));
        label_5->setFont(font1);
        label_5->setStyleSheet(QStringLiteral("color: white;"));
        label_5->setInputMethodHints(Qt::ImhNone);
        label_5->setAlignment(Qt::AlignCenter);
        label = new QLabel(TimeBarWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 80, 200, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Radio Space Bold"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setStyleSheet(QStringLiteral("color: white;"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(TimeBarWidget);

        QMetaObject::connectSlotsByName(TimeBarWidget);
    } // setupUi

    void retranslateUi(QWidget *TimeBarWidget)
    {
        TimeBarWidget->setWindowTitle(QApplication::translate("TimeBarWidget", "Form", 0));
        label_H->setText(QApplication::translate("TimeBarWidget", "00", 0));
        label_M->setText(QApplication::translate("TimeBarWidget", "00", 0));
        label_S->setText(QApplication::translate("TimeBarWidget", "00", 0));
        label_4->setText(QApplication::translate("TimeBarWidget", ":", 0));
        label_5->setText(QApplication::translate("TimeBarWidget", ":", 0));
        label->setText(QApplication::translate("TimeBarWidget", "CAS DO KONCE ZAVODU", 0));
    } // retranslateUi

};

namespace Ui {
    class TimeBarWidget: public Ui_TimeBarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEBAR_H
