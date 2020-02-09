#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:40:34
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = signSystem
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    person.cpp \
    login.cpp \
    regisform.cpp

HEADERS  += widget.h \
    person.h \
    login.h \
    regisform.h

FORMS    += widget.ui \
    person.ui \
    login.ui \
    regisform.ui

RESOURCES += \
    background.qrc \
    resource/background.qrc \
    qss/kongjian.qrc

DISTFILES +=
