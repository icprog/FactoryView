#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include "connections/clsConnection.h"

class Cnnt :public QObject
{

public:
    static Cnnt* Instance();

    void setConnectionType(QString connectionType);
    void setConnectionAddress(QString strAddress);
    bool setUpConnection();
    bool setUpConnection(QString connectionType, QString strAddress);
    QString sendCommand(QString command, bool hasReturn);
    bool QueryConnectionStatus(){return isConnectionInit;}

private:
    Cnnt();
    static Cnnt *mGlobal;

    clsConnection *cnt;
    QString connectionType;
    QString strAddress;
    bool isConnectionInit;
    
};

#endif // CONNECTION_H
