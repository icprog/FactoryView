/********************************************************************************
** Form generated from reading UI file 'MainTestWindow.ui'
**
** Created: Fri Feb 22 11:21:47 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTESTWINDOW_H
#define UI_MAINTESTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainTestWindow
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainTestWindow)
    {
        if (MainTestWindow->objectName().isEmpty())
            MainTestWindow->setObjectName(QString::fromUtf8("MainTestWindow"));
        MainTestWindow->resize(400, 300);
        centralWidget = new QWidget(MainTestWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainTestWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainTestWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        MainTestWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainTestWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainTestWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainTestWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainTestWindow->setStatusBar(statusBar);

        retranslateUi(MainTestWindow);

        QMetaObject::connectSlotsByName(MainTestWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainTestWindow)
    {
        MainTestWindow->setWindowTitle(QApplication::translate("MainTestWindow", "FactoryView Main Test Window", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainTestWindow: public Ui_MainTestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTESTWINDOW_H
