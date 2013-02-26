#include "MainTestWindow.h"
#include <QApplication>
#include "connections/clsUsb.h"
#include <QDebug>
#include "connections/clsGpib.h"
#include "connections/clsLan.h"

#include "connections/Cnnt.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainTestWindow w;
//    w.show();

   // Global::Instance()->setUpConnection("GPIB","6");
    Cnnt::Instance()->setUpConnection("USB","6");
    //qDebug()<< Global::Instance()->QueryConnectionStatus();

    qDebug()<<Cnnt::Instance()->sendCommand(":MEAS:TRIG",true);
    qDebug()<<"Finish!";
    return a.exec();
}


////Lan Test
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    clsLan lan;

//    lan.setAddress("192.168.1.245,9760");
//    lan.init();
//    for(int i=0;i<100; i++)
//        qDebug()<<i<<" - " <<lan.sendCommand(":MEAS:TRIG\n\n",true);
//    lan.disConnect();
//    return a.exec();
//}




/* Usb connection test

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainTestWindow w;
//    w.show();
    //For cls usb test
    //clsUsb usb;
    clsUsb usb;
   // usb.setAddress("6");

    for(int i=0;i<100; i++)
    {
        qDebug()<< usb.sendCommand(":MEAS:TRIG",true);
    }
    usb.disConnect();

    return a.exec();
}
*/
