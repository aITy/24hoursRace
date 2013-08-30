#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QKeyEvent>
#include <QTimer>
#include "ui_mainwindow.h"
#define NOMINMAX
#include "windows.h"
#include "teameditdialog.h"

class TeamManager;
class TimeBar;
class CmdLineBar;
class ResultPrinter;
class XmlHandler;
class BestRoundBar;
class LastRoundBar;
class Settings;
class BarCodeHandler;

class MainWindow : public QMainWindow, Ui::MainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static MainWindow * getInstance() {
            return instance;
    }

    void setStatusMsg(const char *);
    void reconstructTimeBar();
    void reconstructTimeBar(int, int);

    // get methods
    TimeBar * getTimeBar() { return timebar; }
    TeamManager * getTeamManager() { return manager; }
    CmdLineBar * getCmdline() { return cmdline; }
    ResultPrinter * getPrinter() { return printer; }
    XmlHandler * getXmlHandler() { return xml_handler; }
    BestRoundBar * getBestRoundBar() { return bestround_bar; }
    LastRoundBar * getLastRoundBar() { return lastround_bar; }
    Settings * getSettings() { return settings; }
    BarCodeHandler * getBarcodeHandler() { return barcode_handler; }

    /* not used
    void setTimeBar(TimeBar * ptr) { timebar = ptr; }
    void setTeamManager(TeamManager * ptr) { manager = ptr; }
    void setCmdline(CmdLineBar * ptr) { cmdline = ptr; }
    void setPrinter(ResultPrinter * ptr) { printer = ptr; }
    void setXmlHandler(XmlHandler * ptr) { xml_handler = ptr; }
    void setBestRoundBar(BestRoundBar * ptr) { bestround_bar = ptr; }
    void setLastRoundBar(LastRoundBar * ptr) { lastround_bar = ptr; }
    */

    void updateOrder();
    void layoutBoard(int);

    typedef enum {
        SORTBYROUNDSDESC,
        SORTBYROUNDSASC,
        SORTBYTIMEDESC,
        SORTBYTIMEASC
    } board_state;

    board_state getState() { return state; }

    void clearLayout(QLayout *, bool deleteWidgets = true);
    void InitRawInput(HWND hWnd);

private:
    static MainWindow * instance;
    TimeBar * timebar;
    TeamManager * manager;
    CmdLineBar * cmdline;
    ResultPrinter * printer;
    XmlHandler * xml_handler;
    BestRoundBar * bestround_bar;
    LastRoundBar * lastround_bar;
    Settings * settings;
    BarCodeHandler * barcode_handler;
    TeamEditDialog *team_dialog;

    QList<QLabel *> label_names;
    QList<QLabel *> label_rounds;
    QList<QLabel *> label_ranks;

    board_state state;
    QString file;

    QTimer * time_to_start;
    bool running;
    bool loaded;

    QList<int>scanned_barcode;

    QList<int> fixBarcode(QList<int>);

protected:
    void closeEvent(QCloseEvent *);
    void mousePressEvent(QMouseEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result);

public slots:
    void save();
    void saveAs();
    void openFromFile();
    void printDialogShow();

    void sortByRoundsDesc();
    void sortByRoundsAsc();

    void sortByTimeDesc();
    void sortByTimeAsc();


private slots:
    void startTheRace();
    void run();

    void changeSettings();
    void boardSettingsChanged();
    void raceLengthChanged();
    void headlineChanged();

    void teamEdit();
    void printSelection(int);

    // developing

    void printBestByRoundsDesc();
    void printBestByRoundsAsc();
    void printBestByTimeDesc();
    void printBestByTimeAsc();

    void printByRounds();
    void printByTeam();



    void xmlexport();
    void xmlimport();

signals:

};

#endif // MAINWINDOW_H
