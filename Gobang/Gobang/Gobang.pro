#-------------------------------------------------
#
# Project created by QtCreator 2021-07-06T09:54:45
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gobang
TEMPLATE = app


SOURCES += main.cpp\
    gamenetwindow.cpp \
    gamevscomputer.cpp \
        mainwindow.cpp \
    gameboard.cpp \
    gameboardwindow.cpp

HEADERS  += mainwindow.h \
    gameboard.h \
    gameboardwindow.h \
    gamenetwindow.h \
    gamevscomputer.h

FORMS    += mainwindow.ui \
    gameboardwindow.ui \
    gamenetwindow.ui \
    gamevscomputer.ui

RESOURCES += \
    image.qrc
