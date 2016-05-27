#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T16:39:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RobotPathFinder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    board.cpp \
    button.cpp \
    puzzle.cpp \
    square.cpp

HEADERS  += mainwindow.h \
    button.h \
    board.h \
    puzzle.h \
    pq.h \
    square.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

CONFIG += c++11
