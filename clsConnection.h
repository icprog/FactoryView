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



class clsGpib:public clsConnection
{
public:
    clsGpib();
    bool init();
    void setAddress(QString address);
    QString sendCommand(QString strCommand, bool hasReturn=false);
    void disConnect();
private:
    bool blInit;
    int intAddress;

};


class connectionFactory
{
public:
    connectionFactory();

    static clsConnection *getConnection(QString strConnect);
    static clsConnection *getGpib();
};


#endif // CLSCONNECTION_H
