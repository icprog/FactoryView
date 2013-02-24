#include "clsLanTest.h"
#include <QApplication>
#include <QDebug>
#include <QStringList>
#include <QThread>
#include <QTime>
clsLanTest::clsLanTest(QObject *parent) :
    QObject(parent)
{
    blInit=false;
    res.isSet=false;
}
bool clsLanTest::init()
{
    socket  = new QTcpSocket(this);
    socket->connectToHost(this->strIp,this->intPort,QIODevice::ReadWrite);
    const int Timeout=5*1000;
    qDebug("State:%d ",socket->state());
    // State: 2; 2代表ConnectingState，正确的应该为3（ConnectedState）
    if(!socket->waitForConnected(Timeout))
    {
        this->blInit=false;
        return false;
    }
    qDebug("State:%d ",socket->state());
    // State: 3（ConnectedState）正确
    this->blInit=true;
    connect(socket,SIGNAL(readyRead()),this,SLOT(read()));
    return true;
}

void clsLanTest::setAddress(QString address)
{
    QStringList list = address.split(",");
    qDebug()<< list;
    if(list.length()==1)
    {
        this->strIp = (QString)list.at(0);
        this->intPort=WK4300PORT;
    }
    else
    {
        this->strIp=(QString)list.at(0);
        this->intPort=((QString)list.at(1)).toInt();
    }

}

QString clsLanTest::sendCommand(QString strCommand, bool hasReturn)
{

    if(!blInit)
        init();

    if(!blInit)
        return "";

    res.isSet=false;
    QByteArray byteArray=strCommand.toStdString().c_str();

    socket->write(byteArray,byteArray.length());

//    socket->waitForBytesWritten(-1);
    qDebug()<< "write command finished!";
    socket->waitForReadyRead();

    while(!res.isSet)
    {
        sleep(10);
        qApp->processEvents();
    }

    return QString(res.result);

}

void clsLanTest::disConnect()
{
    socket->disconnectFromHost();
    if (socket->state() == QAbstractSocket::UnconnectedState ||
            socket->waitForDisconnected(1000))
        qDebug("Disconnected!");
}

void clsLanTest::read()
{   qDebug()<<"new data comming";
   res.result=socket->readLine();
   res.isSet=true;
   qApp->processEvents();
}
void clsLanTest::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
