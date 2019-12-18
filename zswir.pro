#-------------------------------------------------
#
# Project created by QtCreator 2019-12-12T13:58:23
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zswir
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

win32 {
INCLUDEPATH += $$_PRO_FILE_PWD_\include \
    $$OPENCV_DIR\include

LIBS += -L$$_PRO_FILE_PWD_/lib \
    -lavcodec\
    -lavutil\
    -lavformat\
    -lswscale\
    -lswresample \
    -lopencv_world410
}
unix {
INCLUDEPATH += /usr/local/include \
    /usr/local/include/opencv4

LIBS += -L/usr/local/lib \
    -lavcodec\
    -lavutil\
    -lavformat\
    -lswscale\
    -lswresample \
    -lopencv_world \
}

SOURCES += \
        canvas.cpp \
        imagebrowser.cpp \
        imagebutton.cpp \
        main.cpp \
        mainwindow.cpp \
        photothread.cpp \
        replaycanvas.cpp \
        replaydlg.cpp \
        settingdialog.cpp \
        swircapturer.cpp \
        swirprocessor.cpp \
        utils.cpp \
        videoencoder.cpp \
        zswirdialog.cpp

HEADERS += \
        canvas.h \
        global.h \
        imagebrowser.h \
        imagebutton.h \
        mainwindow.h \
        photothread.h \
        replaycanvas.h \
        replaydlg.h \
        settingdialog.h \
        swircapturer.h \
        swirprocessor.h \
        videoencoder.h \
        zswirdialog.h

FORMS += \
        mainwindow.ui \
        settingdialog.ui \
        zswirdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    zswir.qrc
