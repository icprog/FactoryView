#ifndef CLSGPIB_H
#define CLSGPIB_H
#include "connections/clsConnection.h"

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

#endif // CLSGPIB_H
