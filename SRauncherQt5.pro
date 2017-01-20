#-------------------------------------------------
#
# Project created by QtCreator 2017-01-10T11:15:33
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SRauncherQt5
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        srauncher.cpp \
    sampservers.cpp \
    serverrename.cpp \
    runngame.cpp \
    selectlibs.cpp \
    udpconnect.cpp \
    settings.cpp \
    group.cpp

HEADERS  += srauncher.h \
    sampservers.h \
    serverrename.h \
    runngame.h \
    selectlibs.h \
    udpconnect.h \
    settings.h \
    group.h

FORMS    += srauncher.ui \
    serverrename.ui \
    selectlibs.ui \
    settings.ui \
    group.ui

DISTFILES +=

win32:RC_FILE = resource.rc


win32: LIBS += -luser32
win32: LIBS += -lkernel32
win32: LIBS += -lws2_32

win32: QMAKE_LFLAGS += -static -static-libgcc
win32: QMAKE_LFLAGS += -static -static-libstdc++
win32: QMAKE_LFLAGS_RELEASE += -static -static-libgcc
win32: QMAKE_LFLAGS_RELEASE += -static -static-libstdc++

INCLUDEPATH += C:/Qt/Qt5.7.1/5.7/Src/qtbase/include
DEPENDPATH += C:/Qt/Qt5.7.1/5.7/Src/qtbase/include

