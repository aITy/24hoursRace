#include "printdialog.h"
#include "mainwindow.h"
#include "resultprinter.h"
#include <QAbstractButton>

PrintDialog::PrintDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    QList<QAbstractButton *> buttons = buttonBox->buttons();
    QAbstractButton * button_ok = buttons.at(0);
    QAbstractButton * button_cancel = buttons.at(1);

    connect(button_ok, SIGNAL(clicked()), this, SLOT(acceptRequest()));
    connect(button_cancel, SIGNAL(clicked()), this, SLOT(reject()));
}

PrintDialog::~PrintDialog()
{

}


void PrintDialog::acceptRequest()
{
    emit(selection(comboBox->currentIndex()));
    QDialog::accept();
}
