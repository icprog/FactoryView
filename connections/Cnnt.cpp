#include "Cnnt.h"
#include <QtCore/QCoreApplication>
#include <QDebug>
Cnnt *Cnnt::mGlobal=0;

Cnnt *Cnnt::Instance()
{
    static QMutex mutex;
    if (!mGlobal)
    {
        QMutexLocker locker(&mutex);
        if (!mGlobal)
            mGlobal = new Cnnt();
    }

    return mGlobal;
}
/*仪器的连接类型*/
void Cnnt::setConnectionType(QString connectionType)
{
    this->connectionType=connectionType;
}
/*设置仪器连接的地址*/
void Cnnt::setConnectionAddress(QString strAddress)
{
    this->strAddress=strAddress;
}

/*设置仪器的连接*/
bool Cnnt::setUpConnection()
{
    cnt= connectionFactory::getConnection(this->connectionType);
    cnt->setAddress(this->strAddress);
    isConnectionInit=cnt->init();
    return isConnectionInit;
}

/*建立PC和仪器的连接*/
bool Cnnt::setUpConnection(QString connectionType, QString strAddress)
{
    this->connectionType=connectionType;
    this->strAddress=strAddress;
    return setUpConnection();
}

/*发送GPIB指令并读取返回值*/
QString Cnnt::sendCommand(QString command, bool hasReturn)
{
    if(isConnectionInit)
        return cnt->sendCommand(command,hasReturn);
    else
    {
        qDebug()<<"The connection does't setup correctly!";
        return "";
    }
}

Cnnt::Cnnt()
{
    isConnectionInit=false;
}
