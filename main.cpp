#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QFont>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QStringList list;
    list << "RadioSpace.ttf" << "RadioSpace-Bold.ttf" << "RadioSpace-Italic.ttf" << "RadioSpace-BoldItalic.ttf";
    int fontID(-1);
    bool fontWarningShown(false);
    for (QStringList::const_iterator constIterator = list.constBegin(); constIterator != list.constEnd(); ++constIterator) {
        QFile res(":/" + *constIterator);
        if (res.open(QIODevice::ReadOnly) == false) {
            if (fontWarningShown == false) {
                QMessageBox::warning(0, "Application", (QString)"Impossible to open font " + QChar(0x00AB) + " Radio Space " + QChar(0x00BB) + ".");
                fontWarningShown = true;
            }
        } else {
            fontID = QFontDatabase::addApplicationFontFromData(res.readAll());
            if (fontID == -1 && fontWarningShown == false) {
                QMessageBox::warning(0, "Application", (QString)"Impossible to open font " + QChar(0x00AB) + " Radio Space " + QChar(0x00BB) + ".");
                fontWarningShown = true;
            }
        }
    }

    w.show();
    
    return a.exec();
}
