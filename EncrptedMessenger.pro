#-------------------------------------------------
#
# Project created by QtCreator 2018-10-30T18:29:29
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 static
TARGET = EncryptedMessenger
TEMPLATE = app


INCLUDEPATH += C:\OpenSSL-Win32\include

LIBS += C:\OpenSSL-Win32\lib\libcrypto.lib
LIBS += C:\OpenSSL-Win32\lib\libssl.lib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cipher.cpp \
    file.cpp \
    camera.cpp \
    friend.cpp \
    connect.cpp

HEADERS += \
        mainwindow.h \
    cipher.h \
    file.h \
    camera.h \
    friend.h \
    connect.h

FORMS += \
        mainwindow.ui \
    file.ui \
    friend.ui \
    connect.ui

RESOURCES +=
