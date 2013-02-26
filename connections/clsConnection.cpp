#include "connections/clsConnection.h"
#include "connections/clsGpib.h"
#include "connections/clsUsb.h"
#include "connections/clsLan.h"
connectionFactory::connectionFactory()
{
}

/*ͨ������ģʽ����ȡ���ӵĽӿ�ʵ����
 *
 *V1.0
 *!*/

clsConnection *connectionFactory::getConnection(QString strConnect)
{
    if(strConnect.toUpper()=="GPIB")
    {
        return new clsGpib;
    }
    else if(strConnect.toUpper()=="USB")
    {
        return new clsUsb;
    }
    else if(strConnect.toUpper()=="LAN")
    {
        return new clsLan;
    }
    else
    {
        return (clsConnection *)0;
    }

}

/*����ͨ������ģʽȥ��ȡGPIB��Ҳ����ͨ�����������������ȡ
 *
 *V1.0
 *!*/
clsConnection *connectionFactory::getGpib()
{
    return new clsGpib;
}


/*����ͨ������ģʽȥ��ȡUSB��Ҳ����ͨ�����������������ȡ
 *
 *V1.0
 *!*/
clsConnection *connectionFactory::getUsb()
{
    return new clsUsb;
}


/*����ͨ������ģʽȥ��ȡLAN��Ҳ����ͨ�����������������ȡ
 *
 *V1.0
 *!*/
clsConnection *connectionFactory::getLan()
{
    return new clsLan;
}
