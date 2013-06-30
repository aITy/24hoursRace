#ifndef LASTROUNDBAR_H
#define LASTROUNDBAR_H

#include <QWidget>
#include "ui_lastroundbar.h"


class LastRoundBar : public QWidget, Ui::LastRoundBar
{
    Q_OBJECT
    
public:
    explicit LastRoundBar(QWidget *parent = 0);
    ~LastRoundBar();

    void updateBar(const QString &, int, int);
    
private:
};

#endif // LASTROUNDBAR_H
