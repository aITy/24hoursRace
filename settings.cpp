#include "settings.h"
#include "mainwindow.h"
#include "ui_settings.h"
#include <QAbstractButton>
#include <QDebug>

Settings::Settings(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    headline = back_up.headline = headlineLineEdit->text();
    teams_count = back_up.teams_count = teamsCountLineEdit->text().toInt();
    race_length = back_up.race_length = convertTimeToInt(raceLengthLineEdit->text());
    round_addition_limit = back_up.round_addition_limit = convertTimeToInt(roundAdditionLimitLineEdit->text());
    filepath = back_up.filepath = filepathLineEdit->text();

    QList<QAbstractButton *> buttons = buttonBox->buttons();
    QAbstractButton * button_ok = buttons.at(0);
    QAbstractButton * button_cancel = buttons.at(1);
    connect(button_ok, SIGNAL(clicked()), this, SLOT(accept()));
    connect(button_cancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(headlineLineEdit, SIGNAL(textChanged(QString)),this, SLOT(update()));
    connect(teamsCountLineEdit, SIGNAL(textChanged(QString)), this, SLOT(update()));
    connect(raceLengthLineEdit, SIGNAL(textChanged(QString)), this, SLOT(update()));
    connect(roundAdditionLimitLineEdit, SIGNAL(textChanged(QString)), this, SLOT(update()));
    connect(filepathLineEdit, SIGNAL(textChanged(QString)), this, SLOT(update()));

    real_paswd = "navratil";
}

Settings::~Settings()
{

}

int Settings::convertTimeToInt(const QString & str)
{
    QString hh;
    QString mm;
    QString ss;
    int ms = 0;
    int state = 0;
    for (int i = 0; i < str.count(); i++) {
        if (str.at(i) == ":") {
            state += 1;
            continue;
        }
        switch(state) {
            case 0:
                hh.append(str.at(i));
                break;
            case 1:
                mm.append(str.at(i));
                break;
            case 2:
                ss.append(str.at(i));
                break;
            default:
                break;
        }
    }
    ms = (hh.toInt() * 3600 + mm.toInt() * 60 + ss.toInt())*1000;
    return ms;
}

QString Settings::convertTimeToStr(int ms)
{
    QString str;
    int hours = ms / (1000*60*60);
    int minutes = (ms % (1000*60*60)) / (1000*60);
    int seconds = ((ms % (1000*60*60)) % (1000*60)) / 1000;

    if (hours < 10)
        str.append(QString("0%1").arg(hours));
    else
        str.append(QString::number(hours));

    str.append(":");

    if (minutes < 10)
        str.append(QString("0%1").arg(minutes));
    else
        str.append(QString::number(minutes));

    str.append(":");
    if (seconds < 10)
        str.append(QString("0%1").arg(seconds));
    else
        str.append(QString::number(seconds));

    qDebug() << str;

    return str;
}

void Settings::setHeadline(const QString & str)
{
    headline = str;
    headlineLineEdit->setText(str);
}

void Settings::setTeamsCount(int x)
{
    teams_count = x;
    teamsCountLineEdit->setText(QString::number(x));
}

void Settings::setRaceLength(int x)
{
    race_length = x;
    raceLengthLineEdit->setText(convertTimeToStr(x));
}

void Settings::setRoundAdditionLimit(int x)
{
    round_addition_limit = x;
    roundAdditionLimitLineEdit->setText(convertTimeToStr(x));
}

void Settings::setFilepath(const QString & str)
{
    filepath = str;
    filepathLineEdit->setText(str);
}

void Settings::save()
{
    back_up.headline = headline;
    back_up.teams_count = teams_count;
    back_up.race_length = race_length;
    back_up.round_addition_limit = round_addition_limit;
    back_up.filepath = filepath;
}

void Settings::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()) {
        event->ignore();
    }
    if (event->key() == 16777220) {
        accept();
    }
    if (event->key() == Qt::Key_Escape) {
        reject();
    }
}

void Settings::accept()
{
    // check validity + ? running - what can be changed and what can´t !
    if (passwordLineEdit->text() != real_paswd) {
        headline = back_up.headline;
        teams_count = back_up.teams_count;
        race_length = back_up.race_length;
        round_addition_limit = back_up.round_addition_limit;
        filepath = back_up.filepath;
        this->close();
    }

    if (back_up.teams_count != teams_count)
        emit(boardChanged());
    else if (back_up.race_length != race_length)
        emit(raceLengthChanged());
    else if (back_up.headline != headline)
        emit(headlineChanged());

    back_up.headline = headline;
    back_up.teams_count = teams_count;
    back_up.race_length = race_length;
    back_up.round_addition_limit = round_addition_limit;
    back_up.filepath = filepath;

    passwordLineEdit->clear();

    MainWindow::getInstance()->save();

    this->close();
}

void Settings::reject()
{
    headline = back_up.headline;
    teams_count = back_up.teams_count;
    race_length = back_up.race_length;
    round_addition_limit = back_up.round_addition_limit;
    filepath = back_up.filepath;

    this->close();
}

void Settings::update()
{
    headline = headlineLineEdit->text();
    teams_count = teamsCountLineEdit->text().toInt();
    race_length = convertTimeToInt(raceLengthLineEdit->text());
    round_addition_limit = convertTimeToInt(roundAdditionLimitLineEdit->text());
    filepath = filepathLineEdit->text();
}
