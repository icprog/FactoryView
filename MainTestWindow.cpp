#include "MainTestWindow.h"
#include <QDebug>
MainTestWindow::MainTestWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    lan = new clsLan();
    lan->setAddress("192.168.0.199,9760");
    lan->init();
}



void MainTestWindow::on_pushButton_clicked()
{
    for(int i=0;i<500000;i++)
    {
        qDebug()<<QString("[%1] - %2").arg(i).arg(lan->sendCommand(":MEAS:TRIG\n",true));
        if((i%100)==1)
            lan->sleep(2000);
    }
}
