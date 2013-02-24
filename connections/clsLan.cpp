#include "clsLan.h"
#include <QTcpSocket>
#include <QStringList>
#include <QDebug>
#include <QApplication>
#include <QDataStream>
#include <QTime>
clsLan::clsLan()
{
    this->blInit=false;
    this->strIp="192.168.1.199";
    this->intPort=WK4300PORT;
}

bool clsLan::init()
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
    // connect(socket,SIGNAL(readyRead()),this,SLOT(read()));
    return true;
}

void clsLan::setAddress(QString address)
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

QString clsLan::sendCommand(QString strCommand, bool hasReturn)
{

    if(!blInit)
        init();
    if(socket->state()==QAbstractSocket::UnconnectedState)
        init();

    if(!blInit)
        return "";


    std::string str2 = std::string(strCommand.toAscii().data());

    socket->write(str2.c_str());
    qApp->processEvents();

    socket->waitForBytesWritten(5000);
  //  qDebug()<< "write command finished!";

    if(!hasReturn)
        return "";

    socket->waitForReadyRead(5000);

    char buff[200];
    int byte= socket->readLine(buff,200);
    if (byte>=0)
        buff[byte]='\0';
    QString res=QString(buff);

    return res.remove('\n');

}

void clsLan::disConnect()
{
    socket->disconnectFromHost();
    if (socket->state() == QAbstractSocket::UnconnectedState ||
            socket->waitForDisconnected(1000))
        qDebug("Disconnected!");
}

void clsLan::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
