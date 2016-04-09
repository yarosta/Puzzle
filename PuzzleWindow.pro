#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T19:47:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PuzzleWindow
TEMPLATE = app


SOURCES += main.cpp\
        puzzlewindow.cpp \
    puzzleview.cpp \
    puzzlemodel.cpp \
    tile.cpp

HEADERS  += puzzlewindow.h \
    puzzleview.h \
    puzzlemodel.h \
    tile.h

FORMS    += puzzlewindow.ui

RESOURCES += \
    zasoby.qrc
