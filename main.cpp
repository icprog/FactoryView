#include "MainTestWindow.h"
#include <QApplication>
#include "connections/clsUsb.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainTestWindow w;
//    w.show();
    /*For cls usb test*/
    clsUsb usb;
    usb.sendCommand(":MEAS:TRIG",true);
    usb.disConnect();

    return a.exec();
}
