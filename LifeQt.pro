#-------------------------------------------------
#
# Project created by QtCreator 2017-12-19T11:54:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LifeQt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    gamesquare.cpp

HEADERS += \
        mainwindow.h \
    gamesquare.h

FORMS += \
        mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Life/x64/release/ -lLife
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Life/x64/debug/ -lLife

INCLUDEPATH += $$PWD/../Life/Life
DEPENDPATH += $$PWD/../Life/Life

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Life/x64/release/libLife.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Life/x64/debug/libLife.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Life/x64/release/Life.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Life/x64/debug/Life.lib
