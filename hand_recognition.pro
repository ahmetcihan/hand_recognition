#-------------------------------------------------
#
# Project created by QtCreator 2020-05-23T18:08:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hand_recognition
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ann.cpp \
    activation_function.cpp

HEADERS  += mainwindow.h \
    ann.h

FORMS    += mainwindow.ui \
    ann.ui
