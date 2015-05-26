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
    arene.cpp \
    sphere.cpp \
    math2.cpp \
    bras_robot.cpp \
    cercle.cpp \
    disque_troue.cpp \
    trou.cpp \
    cible.cpp \
    paroi.cpp

HEADERS  += window.h \
    myglwidget.h \
    arene.h \
    sphere.h \
    math2.h \
    bras_robot.h \
    cercle.h \
    disque_troue.h \
    trou.h \
    cible.h \
    paroi.h

FORMS    += window.ui
