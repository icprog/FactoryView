#include "MainTestWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainTestWindow w;
    w.show();
    
    return a.exec();
}
