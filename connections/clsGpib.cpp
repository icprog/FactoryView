/**
 *���������GPIB���ӵ������а�����GPIB��ʼ��������GPIB��ַĬ����6����������ͽ�����ӡ�
 *
 *�����ֻ������һ̨GPIB�豸������������GPIB�豸����ʹ���������������
 *
 *���GPIB������ֻ����������WK������ʹ�ã���Ϊ�����޶����ԡ�WAYNE����ͷ�������豸���ص��ַ�����
 *
 *���ߣ���ͬ��
 *
 *�汾��V1.0
 *
 *ʱ�䣺2013-2-22
 *
 *!*/

#include "connections/clsGpib.h"
#include "connections/clsConnection.h"
#include "connections/gpib488.h"
#include <QStringList>
#include <QDebug>

clsGpib::clsGpib()
{
    this->intAddress=6;
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

    if(address.isEmpty() || this->intAddress==0)
        this->intAddress =6;

}

QString clsGpib::sendCommand(QString strCommand, bool hasReturn)
{

    if(!blInit)
    {
        init();
    }

    if(!blInit)
        return "";

    strCommand = strCommand.append('\n');
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


    if(!str.isEmpty())  //��ǰһ��ʱ�䷢�֣�6500�ķ���ֵǰ�����һ����N������ǳ���֡�
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
