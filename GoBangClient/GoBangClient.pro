QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gameboard.cpp \
    gameboardwindow.cpp \
    gamenetwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    gameboard.h \
    gameboardwindow.h \
    gamenetwindow.h \
    mainwindow.h

FORMS += \
    gameboardwindow.ui \
    gamenetwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    images/black.png \
    images/black1.png \
    images/black2.png \
    images/white.png \
    images/white1.png \
    images/white2.png
