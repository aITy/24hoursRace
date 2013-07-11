/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *settingsLayout;
    QLabel *headlineLabel;
    QLineEdit *headlineLineEdit;
    QLabel *teamsCountLabel;
    QLineEdit *teamsCountLineEdit;
    QLabel *asovLimitMeziPIpsNMKolaLabel;
    QLineEdit *roundAdditionLimitLineEdit;
    QLabel *cestaKSouboruProVlastnZLohuLabel;
    QLineEdit *filepathLineEdit;
    QLabel *raceLengthLabel;
    QLineEdit *raceLengthLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(781, 200);
        formLayoutWidget = new QWidget(Settings);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 9, 761, 152));
        settingsLayout = new QFormLayout(formLayoutWidget);
        settingsLayout->setObjectName(QStringLiteral("settingsLayout"));
        settingsLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        settingsLayout->setContentsMargins(0, 0, 0, 0);
        headlineLabel = new QLabel(formLayoutWidget);
        headlineLabel->setObjectName(QStringLiteral("headlineLabel"));

        settingsLayout->setWidget(0, QFormLayout::LabelRole, headlineLabel);

        headlineLineEdit = new QLineEdit(formLayoutWidget);
        headlineLineEdit->setObjectName(QStringLiteral("headlineLineEdit"));
        headlineLineEdit->setAlignment(Qt::AlignCenter);

        settingsLayout->setWidget(0, QFormLayout::FieldRole, headlineLineEdit);

        teamsCountLabel = new QLabel(formLayoutWidget);
        teamsCountLabel->setObjectName(QStringLiteral("teamsCountLabel"));

        settingsLayout->setWidget(1, QFormLayout::LabelRole, teamsCountLabel);

        teamsCountLineEdit = new QLineEdit(formLayoutWidget);
        teamsCountLineEdit->setObjectName(QStringLiteral("teamsCountLineEdit"));
        teamsCountLineEdit->setAlignment(Qt::AlignCenter);

        settingsLayout->setWidget(1, QFormLayout::FieldRole, teamsCountLineEdit);

        asovLimitMeziPIpsNMKolaLabel = new QLabel(formLayoutWidget);
        asovLimitMeziPIpsNMKolaLabel->setObjectName(QStringLiteral("asovLimitMeziPIpsNMKolaLabel"));

        settingsLayout->setWidget(3, QFormLayout::LabelRole, asovLimitMeziPIpsNMKolaLabel);

        roundAdditionLimitLineEdit = new QLineEdit(formLayoutWidget);
        roundAdditionLimitLineEdit->setObjectName(QStringLiteral("roundAdditionLimitLineEdit"));
        roundAdditionLimitLineEdit->setAlignment(Qt::AlignCenter);

        settingsLayout->setWidget(3, QFormLayout::FieldRole, roundAdditionLimitLineEdit);

        cestaKSouboruProVlastnZLohuLabel = new QLabel(formLayoutWidget);
        cestaKSouboruProVlastnZLohuLabel->setObjectName(QStringLiteral("cestaKSouboruProVlastnZLohuLabel"));

        settingsLayout->setWidget(4, QFormLayout::LabelRole, cestaKSouboruProVlastnZLohuLabel);

        filepathLineEdit = new QLineEdit(formLayoutWidget);
        filepathLineEdit->setObjectName(QStringLiteral("filepathLineEdit"));
        filepathLineEdit->setAlignment(Qt::AlignCenter);

        settingsLayout->setWidget(4, QFormLayout::FieldRole, filepathLineEdit);

        raceLengthLabel = new QLabel(formLayoutWidget);
        raceLengthLabel->setObjectName(QStringLiteral("raceLengthLabel"));

        settingsLayout->setWidget(2, QFormLayout::LabelRole, raceLengthLabel);

        raceLengthLineEdit = new QLineEdit(formLayoutWidget);
        raceLengthLineEdit->setObjectName(QStringLiteral("raceLengthLineEdit"));
        raceLengthLineEdit->setAlignment(Qt::AlignCenter);

        settingsLayout->setWidget(2, QFormLayout::FieldRole, raceLengthLineEdit);

        passwordLabel = new QLabel(formLayoutWidget);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        settingsLayout->setWidget(5, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(formLayoutWidget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));

        settingsLayout->setWidget(5, QFormLayout::FieldRole, passwordLineEdit);

        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 170, 760, 24));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", 0));
        headlineLabel->setText(QApplication::translate("Settings", "Z\303\241hlav\303\255", 0));
        headlineLineEdit->setText(QApplication::translate("Settings", "24 hodin nonstop CHOCE\305\207 2013", 0));
        teamsCountLabel->setText(QApplication::translate("Settings", "Po\304\215et t\303\275mu", 0));
        teamsCountLineEdit->setText(QApplication::translate("Settings", "40", 0));
        asovLimitMeziPIpsNMKolaLabel->setText(QApplication::translate("Settings", "\304\214asov\303\275 limit mezi p\305\231ips\303\241n\303\255m kola (hh:mm:ss)", 0));
        roundAdditionLimitLineEdit->setText(QApplication::translate("Settings", "00:00:00", 0));
        cestaKSouboruProVlastnZLohuLabel->setText(QApplication::translate("Settings", "Cesta k souboru pro vlastn\303\255 z\303\241lohu", 0));
        raceLengthLabel->setText(QApplication::translate("Settings", "D\303\251lka z\303\241vodu (hh:mm:ss)", 0));
        raceLengthLineEdit->setText(QApplication::translate("Settings", "24:00:00", 0));
        passwordLabel->setText(QApplication::translate("Settings", "Heslo", 0));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
