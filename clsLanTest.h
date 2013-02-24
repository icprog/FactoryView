#ifndef CLSLANTEST_H
#define CLSLANTEST_H
#include <QTcpSocket>
#include <QObject>

#define WK4300PORT 9760
#define WK6500PORT 2000

struct resType
{
    bool isSet;
    QByteArray result;
};

class clsLanTest : public QObject
{
    Q_OBJECT
public:
    explicit clsLanTest(QObject *parent = 0);
    
    bool init();
    void setAddress(QString address);
    QString sendCommand(QString strCommand, bool hasReturn=false);
    void disConnect();
    void sleep(unsigned int msec);
private slots:
    void read();
private:
    QString strIp;
    quint16 intPort;

    QTcpSocket *socket;
    bool blInit;
    resType res;

    
};

#endif // CLSLANTEST_H
