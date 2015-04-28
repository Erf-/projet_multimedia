#-------------------------------------------------
#
# Project created by QtCreator 2013-09-25T09:11:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyOpenGL
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    myglwidget.cpp \
    cercle_troue.cpp \
    sphere.cpp

HEADERS  += window.h \
    myglwidget.h \
    cercle_troue.h \
    sphere.h

FORMS    += window.ui
