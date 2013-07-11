/********************************************************************************
** Form generated from reading UI file 'printdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTDIALOG_H
#define UI_PRINTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PrintDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QDialog *PrintDialog)
    {
        if (PrintDialog->objectName().isEmpty())
            PrintDialog->setObjectName(QStringLiteral("PrintDialog"));
        PrintDialog->resize(359, 78);
        buttonBox = new QDialogButtonBox(PrintDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 40, 361, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label = new QLabel(PrintDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 101, 21));
        label->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(PrintDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(105, 10, 251, 22));

        retranslateUi(PrintDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PrintDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PrintDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PrintDialog);
    } // setupUi

    void retranslateUi(QDialog *PrintDialog)
    {
        PrintDialog->setWindowTitle(QApplication::translate("PrintDialog", "Dialog", 0));
        label->setText(QApplication::translate("PrintDialog", "Vyberte form\303\241t tisku", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PrintDialog", "tisk v\305\241ech kol podle t\303\275m\305\257", 0)
         << QApplication::translate("PrintDialog", "tisk v\305\241ech kol chronologicky", 0)
         << QApplication::translate("PrintDialog", "pouze nejlep\305\241\303\255 v\303\275sledky podle po\304\215tu kol sestupn\304\233", 0)
         << QApplication::translate("PrintDialog", "pouze nejlep\305\241\303\255 v\303\275sledky podle po\304\215tu kol vzestupn\304\233", 0)
         << QApplication::translate("PrintDialog", "pouze nejlep\305\241\303\255 v\303\275sledky podle nejlep\305\241iho kola sestupn\304\233", 0)
         << QApplication::translate("PrintDialog", "pouze nejlep\305\241\303\255 v\303\275sledky podle nejlep\305\241iho kola vzestupn\304\233", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class PrintDialog: public Ui_PrintDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTDIALOG_H
