#-------------------------------------------------
#
# Project created by QtCreator 2016-11-23T09:25:43
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fb
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    login.cpp \
    connect.cpp

HEADERS  += widget.h \
    login.h \
    connect.h

FORMS    += widget.ui \
    login.ui
