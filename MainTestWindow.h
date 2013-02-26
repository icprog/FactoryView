#ifndef MAINTESTWINDOW_H
#define MAINTESTWINDOW_H

#include "ui_MainTestWindow.h"
#include "connections/clsLan.h"
#include "connections/clsGpib.h"
class MainTestWindow : public QMainWindow, private Ui::MainTestWindow
{
    Q_OBJECT
    
public:
    explicit MainTestWindow(QWidget *parent = 0);
private slots:
    void on_pushButton_clicked();
private:
    clsLan *lan;
};

#endif // MAINTESTWINDOW_H
