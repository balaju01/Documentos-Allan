#-------------------------------------------------
#
# Project created by QtCreator 2015-05-05T15:01:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_life
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../qcustomplot/qcustomplot.cpp \
    estados.cpp

HEADERS  += mainwindow.h \
    ../qcustomplot/qcustomplot.h \
    estados.h

FORMS    += mainwindow.ui
