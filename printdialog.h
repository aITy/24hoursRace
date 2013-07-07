#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H

#include <QDialog>
#include "ui_printdialog.h"

class PrintDialog : public QDialog, Ui::PrintDialog
{
    Q_OBJECT
    
public:
    explicit PrintDialog(QWidget *parent = 0);
    ~PrintDialog();

signals:
    void selection(int);

public slots:
    void acceptRequest();
    
private:

};

#endif // PRINTDIALOG_H
