#include "MainTestWindow.h"
#include <QDebug>
MainTestWindow::MainTestWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    lan = new clsGpib();
//    lan->setAddress("192.168.0.199,6500");
    lan->setAddress("6");
    lan->init();
}



void MainTestWindow::on_pushButton_clicked()
{
    lan->sendCommand(":METER:SPEED MAX",false);
    for(int i=0;i<500000;i++)
    {
        qApp->processEvents();
        qDebug()<<QString("[%1] - %2").arg(i).arg(lan->sendCommand(":METER:TRIG",true));
//        if((i%50)==1)
//            lan->sleep(20000);
    }
}
