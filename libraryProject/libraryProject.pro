#-------------------------------------------------
#
# Project created by QtCreator 2015-05-09T00:29:59
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = libraryProject
TEMPLATE = app


SOURCES += main.cpp\
        library.cpp \
    checkoutwindow.cpp \
    createconnection.cpp \
    returnwindow.cpp \
    addremovewindow.cpp \
    listauthorinsub.cpp

HEADERS  += library.h \
    checkoutwindow.h \
    createconnection.h \
    returnwindow.h \
    addremovewindow.h \
    listauthorinsub.h

FORMS    += library.ui \
    checkoutwindow.ui \
    returnwindow.ui \
    addremovewindow.ui \
    listauthorinsub.ui
