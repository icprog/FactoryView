#-------------------------------------------------
#
# Project created by QtCreator 2013-02-20T17:30:00
#
#-------------------------------------------------

QT       += core gui network
RC_FILE  =Icon.rc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FactoryView
TEMPLATE = app

LIBS    += gpib488.obj \
        visa.lib


SOURCES += main.cpp\
        MainTestWindow.cpp \
    connections/clsGpib.cpp \
    connections/clsConnection.cpp \
    connections/clsUsb.cpp \
    connections/clsLan.cpp \
    clsLanTest.cpp \
    Cnnt.cpp

HEADERS  += MainTestWindow.h \
    connections/gpib488.h \
    connections/GPIB.h \
    connections/clsGpib.h \
    connections/clsConnection.h \
    connections/visa.h \
    connections/visatype.h \
    connections/clsUsb.h \
    connections/clsLan.h \
    clsLanTest.h \
    Cnnt.h

FORMS    += MainTestWindow.ui

RESOURCES += \
    myRec.qrc
