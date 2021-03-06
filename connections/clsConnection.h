#ifndef CLSCONNECTION_H
#define CLSCONNECTION_H

#include <QObject>


class clsConnection : public QObject
{
    Q_OBJECT
public:

    virtual bool init()=0;
    virtual void setAddress(QString address)=0;
    virtual QString sendCommand(QString strCommand, bool hasReturn=false)=0;
    virtual void disConnect()=0;
    ~clsConnection(){}
};


class connectionFactory
{
public:
    connectionFactory();

    static clsConnection *getConnection(QString strConnect);
    static clsConnection *getGpib();
    static clsConnection *getUsb();
    static clsConnection *getLan();
};


#endif // CLSCONNECTION_H
