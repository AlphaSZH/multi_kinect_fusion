#-------------------------------------------------
#
# Project created by QtCreator 2018-04-16T16:23:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = multi_kinect_fusion
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    sacsvstream.cpp \
    util.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    sacsvstream.h \
    util.h

FORMS    += mainwindow.ui


