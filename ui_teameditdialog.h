/********************************************************************************
** Form generated from reading UI file 'teameditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMEDITDIALOG_H
#define UI_TEAMEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeamEditDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Racers;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_Barcode;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_addTeam;
    QLabel *label_5;
    QLineEdit *lineEdit_TeamName;
    QLabel *label;
    QVBoxLayout *verticalLayout_Teams;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TeamEditDialog)
    {
        if (TeamEditDialog->objectName().isEmpty())
            TeamEditDialog->setObjectName(QStringLiteral("TeamEditDialog"));
        TeamEditDialog->resize(509, 368);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TeamEditDialog->sizePolicy().hasHeightForWidth());
        TeamEditDialog->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(TeamEditDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 511, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        lineEdit_Racers = new QLineEdit(verticalLayoutWidget);
        lineEdit_Racers->setObjectName(QStringLiteral("lineEdit_Racers"));

        gridLayout->addWidget(lineEdit_Racers, 2, 1, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(57, 20));
        label_8->setMaximumSize(QSize(57, 20));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_Barcode = new QLineEdit(verticalLayoutWidget);
        lineEdit_Barcode->setObjectName(QStringLiteral("lineEdit_Barcode"));

        gridLayout->addWidget(lineEdit_Barcode, 1, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_3->setContentsMargins(140, -1, -1, -1);
        pushButton_addTeam = new QPushButton(verticalLayoutWidget);
        pushButton_addTeam->setObjectName(QStringLiteral("pushButton_addTeam"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_addTeam->sizePolicy().hasHeightForWidth());
        pushButton_addTeam->setSizePolicy(sizePolicy2);
        pushButton_addTeam->setMaximumSize(QSize(120, 24));

        verticalLayout_3->addWidget(pushButton_addTeam);


        gridLayout->addLayout(verticalLayout_3, 4, 1, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        lineEdit_TeamName = new QLineEdit(verticalLayoutWidget);
        lineEdit_TeamName->setObjectName(QStringLiteral("lineEdit_TeamName"));

        gridLayout->addWidget(lineEdit_TeamName, 0, 1, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout_Teams = new QVBoxLayout();
        verticalLayout_Teams->setSpacing(3);
        verticalLayout_Teams->setObjectName(QStringLiteral("verticalLayout_Teams"));
        verticalLayout_Teams->setSizeConstraint(QLayout::SetMaximumSize);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Teams->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout_Teams);


        verticalLayout->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setMaximumSize(QSize(16777215, 26));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TeamEditDialog);

        QMetaObject::connectSlotsByName(TeamEditDialog);
    } // setupUi

    void retranslateUi(QDialog *TeamEditDialog)
    {
        TeamEditDialog->setWindowTitle(QApplication::translate("TeamEditDialog", "Dialog", 0));
        label_6->setText(QString());
        label_7->setText(QApplication::translate("TeamEditDialog", "Z\303\241vodn\303\255c\303\255 (voliteln\303\251)", 0));
        label_8->setText(QApplication::translate("TeamEditDialog", "N\303\241zev t\303\275mu", 0));
        pushButton_addTeam->setText(QApplication::translate("TeamEditDialog", "P\305\231idat|Zm\304\233nit t\303\275m", 0));
        label_5->setText(QApplication::translate("TeamEditDialog", "\304\214\303\241rov\303\275 k\303\263d", 0));
        label->setText(QApplication::translate("TeamEditDialog", "Heslo", 0));
    } // retranslateUi

};

namespace Ui {
    class TeamEditDialog: public Ui_TeamEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMEDITDIALOG_H
