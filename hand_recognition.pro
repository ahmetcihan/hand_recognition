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
    activation_function.cpp \
    net_76800_1024_1024_6.cpp \
    snapshot_images.cpp

HEADERS  += mainwindow.h \
    ann.h \
    my_macros.h

FORMS    += mainwindow.ui \
    ann.ui

INCLUDEPATH += /home/ahmet/Desktop/opencv_installation_files/opencv-3.4.10/build/include

LIBS += -L"/home/ahmet/Desktop/opencv_installation_files/opencv-3.4.10/build/lib"
LIBS += -lopencv_core
LIBS += -lopencv_highgui
LIBS += -lopencv_videoio \
-lopencv_imgproc \
-lopencv_imgcodecs \
-lopencv_ml \
-lopencv_video \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_flann \
-lopencv_photo \
-lopencv_stitching \
-lopencv_ts \
-lopencv_videostab
