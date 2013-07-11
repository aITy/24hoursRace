/********************************************************************************
** Form generated from reading UI file 'cmdlinebar.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMDLINEBAR_H
#define UI_CMDLINEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Cmdline
{
public:
    QLineEdit *lineEdit;

    void setupUi(QWidget *Form_Cmdline)
    {
        if (Form_Cmdline->objectName().isEmpty())
            Form_Cmdline->setObjectName(QStringLiteral("Form_Cmdline"));
        Form_Cmdline->resize(220, 40);
        Form_Cmdline->setStyleSheet(QStringLiteral("background: rgb(180, 180, 180);"));
        lineEdit = new QLineEdit(Form_Cmdline);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(12, 10, 201, 21));
        lineEdit->setStyleSheet(QStringLiteral("background: white;"));

        retranslateUi(Form_Cmdline);

        QMetaObject::connectSlotsByName(Form_Cmdline);
    } // setupUi

    void retranslateUi(QWidget *Form_Cmdline)
    {
        Form_Cmdline->setWindowTitle(QApplication::translate("Form_Cmdline", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Form_Cmdline: public Ui_Form_Cmdline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMDLINEBAR_H
