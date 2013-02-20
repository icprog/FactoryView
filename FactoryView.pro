#-------------------------------------------------
#
# Project created by QtCreator 2013-02-20T17:30:00
#
#-------------------------------------------------

QT       += core gui
RC_FILE  =Icon.rc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FactoryView
TEMPLATE = app

LIBS    += gpib488.obj

SOURCES += main.cpp\
        MainTestWindow.cpp \
    clsConnection.cpp

HEADERS  += MainTestWindow.h \
    clsConnection.h \
    gpib488.h

FORMS    += MainTestWindow.ui

RESOURCES += \
    myRec.qrc
