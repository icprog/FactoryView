��Connection�ļ�������Ҫ�ǰ�����5����1���ӿ�

Interface �ࣺ
    clsConnection
        |
        |   bool init()=0;
        |   void setAddress(QString address)=0;
        |   QString sendCommand(QString strCommand, bool hasReturn=false)=0;
        |   void disConnect()=0;


��������������:
    clsGpib:clsConnection   //GPIB ����
    clsLan:clsConnection    //LAN ����
    clsUsb:clsConnection    //USB����

ͨ��Factory��������ģʽ���߷��ʾ�̬�ķ��������ʺ͹�����Щ����
   clsConnection* connectionFactory::getConnection(QString)
   ���д��ݵĲ�������ѡ�� "GPIB","LAN","USB"

��ͨ��singleton����һ��ģʽ�����ӱ����ȫ�ֿ���ʹ�õ�����
class Cnnt :public QObject


    static Cnnt* Instance();
        |
        | setConnectionType(QString connectionType);
        | setConnectionAddress(QString strAddress);
        | setUpConnection();
        | setUpConnection(QString connectionType, QString strAddress);
        | sendCommand(QString command, bool hasReturn);
        | QueryConnectionStatus(){return isConnectionInit;}

ͨ�������Cnnt::Instance()->�����������Щ���������Եõ���ǰ������״̬��
Ҳ����ͨ��sendCommandȥ���������������ȥ��




