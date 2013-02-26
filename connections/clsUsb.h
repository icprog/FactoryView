#ifndef CLSUSB_H
#define CLSUSB_H
#include "connections/visa.h"
#include "connections/clsConnection.h"
/**
 *���������USB���ӵ������а�����USB��ʼ����ͨ����ѯ�ַ�����Ѱ�Ҳ�����������������ͽ�����ӡ�
 *
 *�����ֻ������һ̨USB�豸������������USB�豸����ʹ���������������
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
#define MAX_CNT 200

class clsUsb : public clsConnection
{
public:
    clsUsb();
    bool init();
    void setAddress(QString address);
    QString sendCommand(QString strCommand, bool hasReturn=false);
    void disConnect();
private:
    bool blInit;

    ViStatus status;            /* For checking errors  */
    ViSession defaultRM, instr; /* Communication channels  */
    ViUInt32 retCount;          /* Return count from string I/O */
    ViChar desc[MAX_CNT];       /* Buffer for string I/O  */
    ViUInt32   numInstrs;       /* The number of instruments */
    ViFindList findList;        /* find lists of instrument */
    ViUInt32 retLen;           /* The return length  */
    unsigned char buffer[MAX_CNT];       /* For read result back */
    ViByte command[];
    QString strResult;
};

#endif // CLSUSB_H
