#ifndef XMLHANDLER_H
#define XMLHANDLER_H

#include <QObject>

class XmlHandler : public QObject
{
    Q_OBJECT
public:
    explicit XmlHandler(QObject *parent = 0);

    bool xmlImport(const QString &);
    bool xmlExport(const QString &);
signals:
    
public slots:
    
};

#endif // XMLHANDLER_H
