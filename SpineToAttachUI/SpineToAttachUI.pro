QT       += core gui

QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

QT += testlib

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controltable.cpp \
    datathread.cpp \
    deviationlabel.cpp \
    dialogspine.cpp \
    dialogtable.cpp \
    dialogtable2.cpp \
    encoder.cpp \
    keyBoard.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    controltable.h \
    datathread.h \
    deviationlabel.h \
    dialogspine.h \
    dialogtable.h \
    dialogtable2.h \
    encoder.h \
    keyBoard.h \
    mainwindow.h \
    sharedvariable.h

FORMS += \
    dialogspine.ui \
    dialogtable.ui \
    dialogtable2.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
