#ifndef MAINTESTWINDOW_H
#define MAINTESTWINDOW_H

#include "ui_MainTestWindow.h"

class MainTestWindow : public QMainWindow, private Ui::MainTestWindow
{
    Q_OBJECT
    
public:
    explicit MainTestWindow(QWidget *parent = 0);
};

#endif // MAINTESTWINDOW_H
