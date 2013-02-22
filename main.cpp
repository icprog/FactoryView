#include "MainTestWindow.h"
#include <QApplication>
#include "connections/clsUsb.h"
#include <QDebug>
#include "connections/clsGpib.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainTestWindow w;
//    w.show();
    /*For cls usb test*/
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
