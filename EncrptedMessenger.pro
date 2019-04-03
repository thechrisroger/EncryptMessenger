#-------------------------------------------------
#
# Project created by QtCreator 2018-10-30T18:29:29
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = EncryptedMessenger
TEMPLATE = app


INCLUDEPATH += C:\OpenSSL-Win64\include

LIBS += C:\OpenSSL-Win64\lib\libcrypto.lib
LIBS += C:\OpenSSL-Win64\lib\libssl.lib

DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
RC_ICONS = image\mainIcon.ico

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cipher.cpp \
    camera.cpp \
    friend.cpp \
    connect.cpp \
    data.cpp \
    send.cpp \
    receive.cpp

HEADERS += \
        mainwindow.h \
    cipher.h \
    camera.h \
    friend.h \
    connect.h \
    data.h \
    send.h \
    receive.h

FORMS += \
        mainwindow.ui \
    friend.ui \
    connect.ui \
    send.ui \
    receive.ui


