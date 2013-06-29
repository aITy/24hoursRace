#ifndef CMDLINEBAR_H
#define CMDLINEBAR_H

#include <QWidget>
#include "ui_cmdlinebar.h"

class CmdLineBar : public QWidget, Ui::Form_Cmdline
{
    Q_OBJECT
public:
    explicit CmdLineBar(QWidget *parent = 0);
    
signals:
    void keyCaught(QKeyEvent *e);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    
public slots:
    
};

#endif // CMDLINEBAR_H
