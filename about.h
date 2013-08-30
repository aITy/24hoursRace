#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include "ui_about.h"


class About : public QWidget, Ui::About
{
    Q_OBJECT
    
public:
    explicit About(QWidget *parent = 0);
    ~About();
    
};

#endif // ABOUT_H
