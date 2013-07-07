#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

#include "ui_settings.h"

class Settings : public QWidget, Ui::Settings
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    int convertTimeToInt(const QString &);
    QString convertTimeToStr(int);

    QString getHeadline() { return headline; }
    int getTeamsCount() { return teams_count; }
    int getRaceLength() { return race_length; }
    int getRoundAdditionLimit() { return round_addition_limit; }
    QString getFilepath() { return filepath; }

    void setHeadline(const QString &);
    void setTeamsCount(int);
    void setRaceLength(int);
    void setRoundAdditionLimit(int);
    void setFilepath(const QString &);
    void save();
    
private:
    QString headline;
    int teams_count;
    int race_length;
    int round_addition_limit;
    QString filepath;

    QString real_paswd;

    typedef struct backup {
        QString headline;
        int teams_count;
        int race_length;
        int round_addition_limit;
        QString filepath;
    } backup;

    backup back_up;

protected:
    virtual void keyReleaseEvent(QKeyEvent *event);

private slots:
    void accept();
    void reject();
    void update();
signals:
    void raceLengthChanged();
    void headlineChanged();
    void boardChanged();

};

#endif // SETTINGS_H
