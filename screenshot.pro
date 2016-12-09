#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T01:36:18
#
#-------------------------------------------------

QT       += core gui network

VERSION = 0.3
DEFINES += VERSION_STRING=\\\"0.3.0\\\"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = screenshot
TEMPLATE = app


SOURCES += main.cpp \
    form.cpp \
    successdialog.cpp \
    utils.cpp

HEADERS  += \
    form.h \
    successdialog.h \
    utils.h

FORMS    += \
    form.ui \
    successdialog.ui

DISTFILES += \
    paths.properties
