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

    void setupUi(QWidget *TimeBarWidget)
    {
        if (TimeBarWidget->objectName().isEmpty())
            TimeBarWidget->setObjectName(QStringLiteral("TimeBarWidget"));
        TimeBarWidget->resize(160, 216);
        TimeBarWidget->setStyleSheet(QStringLiteral(""));
        label_H = new QLabel(TimeBarWidget);
        label_H->setObjectName(QStringLiteral("label_H"));
        label_H->setGeometry(QRect(0, 70, 41, 61));
        label_H->setAlignment(Qt::AlignCenter);
        label_M = new QLabel(TimeBarWidget);
        label_M->setObjectName(QStringLiteral("label_M"));
        label_M->setGeometry(QRect(60, 70, 41, 61));
        label_M->setAlignment(Qt::AlignCenter);
        label_S = new QLabel(TimeBarWidget);
        label_S->setObjectName(QStringLiteral("label_S"));
        label_S->setGeometry(QRect(120, 70, 41, 61));
        label_S->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(TimeBarWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 70, 16, 61));
        label_4->setInputMethodHints(Qt::ImhNone);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(TimeBarWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 70, 16, 61));
        label_5->setInputMethodHints(Qt::ImhNone);
        label_5->setAlignment(Qt::AlignCenter);

        retranslateUi(TimeBarWidget);

        QMetaObject::connectSlotsByName(TimeBarWidget);
    } // setupUi

    void retranslateUi(QWidget *TimeBarWidget)
    {
        TimeBarWidget->setWindowTitle(QApplication::translate("TimeBarWidget", "Form", 0));
        label_H->setText(QString());
        label_M->setText(QString());
        label_S->setText(QString());
        label_4->setText(QApplication::translate("TimeBarWidget", ":", 0));
        label_5->setText(QApplication::translate("TimeBarWidget", ":", 0));
    } // retranslateUi

};

namespace Ui {
    class TimeBarWidget: public Ui_TimeBarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEBAR_H
