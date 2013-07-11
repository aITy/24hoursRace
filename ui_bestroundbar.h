/********************************************************************************
** Form generated from reading UI file 'bestroundbar.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BESTROUNDBAR_H
#define UI_BESTROUNDBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QLabel *label_M;
    QLabel *label_4;
    QLabel *label_Min;
    QLabel *label_S;
    QLabel *label_Team;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(220, 130);
        Form->setStyleSheet(QLatin1String("background: rgb(180, 180, 180);\n"
"border: none;"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 90, 200, 30));
        QFont font;
        font.setFamily(QStringLiteral("Radio Space Bold"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: white;"));
        label->setAlignment(Qt::AlignCenter);
        label_M = new QLabel(Form);
        label_M->setObjectName(QStringLiteral("label_M"));
        label_M->setGeometry(QRect(10, 0, 70, 80));
        QFont font1;
        font1.setFamily(QStringLiteral("Radio Space Bold"));
        font1.setPointSize(32);
        font1.setBold(true);
        font1.setWeight(75);
        label_M->setFont(font1);
        label_M->setStyleSheet(QStringLiteral("color: white;"));
        label_M->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Form);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(76, 0, 16, 80));
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("color: white;"));
        label_4->setInputMethodHints(Qt::ImhNone);
        label_4->setAlignment(Qt::AlignCenter);
        label_Min = new QLabel(Form);
        label_Min->setObjectName(QStringLiteral("label_Min"));
        label_Min->setGeometry(QRect(150, 0, 60, 85));
        QFont font2;
        font2.setFamily(QStringLiteral("Radio Space Bold"));
        font2.setPointSize(23);
        font2.setBold(true);
        font2.setWeight(75);
        label_Min->setFont(font2);
        label_Min->setStyleSheet(QStringLiteral("color: white;"));
        label_Min->setAlignment(Qt::AlignCenter);
        label_S = new QLabel(Form);
        label_S->setObjectName(QStringLiteral("label_S"));
        label_S->setGeometry(QRect(90, 0, 60, 80));
        label_S->setFont(font1);
        label_S->setAutoFillBackground(false);
        label_S->setStyleSheet(QStringLiteral("color: white;"));
        label_S->setAlignment(Qt::AlignCenter);
        label_Team = new QLabel(Form);
        label_Team->setObjectName(QStringLiteral("label_Team"));
        label_Team->setGeometry(QRect(10, 60, 200, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Radio Space Bold"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        label_Team->setFont(font3);
        label_Team->setStyleSheet(QStringLiteral("color: rgb(29, 29, 29)"));
        label_Team->setAlignment(Qt::AlignCenter);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label->setText(QApplication::translate("Form", "NEJRYCHLEJSI KOLO", 0));
        label_M->setText(QApplication::translate("Form", "00", 0));
        label_4->setText(QApplication::translate("Form", ":", 0));
        label_Min->setText(QApplication::translate("Form", "min.", 0));
        label_S->setText(QApplication::translate("Form", "00", 0));
        label_Team->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BESTROUNDBAR_H
