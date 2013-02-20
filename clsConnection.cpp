#include "clsConnection.h"
#include "gpib488.h"
#include <QStringList>
#include <QDebug>


clsGpib::clsGpib()
{
    this->blInit=false;

}

bool clsGpib::init()
{
    ibdev(0,intAddress,0,10,1,0);

    Send(0,intAddress,"*IDN?",strlen("*IDN?"),DABend);
    char data[50];
    Receive (0,intAddress, data, 50, STOPend);

    QString strData = QString(data);
    QStringList strDataList = strData.split('\n');
    if(strDataList.count()>1)
    {
        strData =strDataList[0];
    }
    else
        strData="";

    if(strData.isEmpty())
    {
        blInit=false;
    }
    else
    {
        if(strData.contains("WAYNE"))
        {

            blInit = true;
        }
        else
        {
            blInit = false;
        }
    }


    return this->blInit;
}

void clsGpib::setAddress(QString address)
{
    this->intAddress = address.toInt();

    if(address.isEmpty())
        this->intAddress =6;

}

QString clsGpib::sendCommand(QString strCommand, bool hasReturn)
{

    if(!blInit)
    {
        Send(0,intAddress,"*IDN?",strlen("*IDN?"),DABend);
        char data[50];
        Receive (0,intAddress, data, 50, STOPend);

        QString strData = QString(data);
        QStringList strDataList = strData.split('\n');
        if(strDataList.count()>1)
        {
            strData =strDataList[0];
        }
        else
            strData="";

        if(strData.isEmpty())
        {
            blInit=false;
            return "";
        }
        else
        {
            blInit = true;
        }


    }

    const char *cmd;
    std::string xx= strCommand.toStdString();
    cmd = xx.c_str();


    unsigned int cmdLength;

    cmdLength=strlen(cmd);
    //ibwrt(device,cmd,cmdLength);
    Send(0,intAddress,cmd,cmdLength,DABend);

    if(Ibcnt()!= cmdLength || Ibsta() & ERR)
    {
          return "";
    }


    if(!hasReturn)
        return "";


    char buffer[129];
    const int bufsize=128;

    Receive (0,intAddress, buffer, bufsize, STOPend);


    while ( (ibsta & CMPL+ERR) == 0);

    if ((Ibcnt()==bufsize) || (Ibcnt()==0 )|| (Ibsta()&ERR))
        return "";
    else
    {
        buffer[Ibcnt()-1] = '\0';    /* Terminate string */
    }

    QString str= QString(buffer);


    if(!str.isEmpty())
    {
        if(str.at(0) =='N')
            str= str.remove(0,1);
    }

   // qDebug()<< str;
    return str;

}

void clsGpib::disConnect()
{
    short addres[]={(short) intAddress};
    EnableLocal(0,addres);
     blInit=false;
}


connectionFactory::connectionFactory()
{
}

clsConnection *connectionFactory::getConnection(QString strConnect)
{
    if(strConnect.toUpper()=="GPIB")
    {
        return new clsGpib;
    }
    else
    {
        return (clsConnection *)0;
    }

}


clsConnection *connectionFactory::getGpib()
{
    return new clsGpib;
}
