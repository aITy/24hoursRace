#ifndef BESTROUNDBAR_H
#define BESTROUNDBAR_H

#include <QWidget>
#include "ui_bestroundbar.h"

class BestRoundBar : public QWidget, Ui::Form
{
    Q_OBJECT
public:
    explicit BestRoundBar(QWidget *parent = 0);

    void updateBar(const QString &, int);
    
signals:
    
public slots:
    
};

#endif // BESTROUNDBAR_H
