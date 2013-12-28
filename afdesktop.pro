#-------------------------------------------------
#
# Project created by QtCreator 2013-12-17T21:52:08
#
#-------------------------------------------------

QT       += core gui network widgets

TARGET = afdesktop
TEMPLATE = app


SOURCES +=\
    src/ui/mainwindow.cpp \
    src/controller/server.cpp \
	src/controller/charactercontroller.cpp \
    src/business/character.cpp \
    src/main.cpp \
	src/ui/tabs/tabpjs.cpp \
    src/ui/tabs/tabpnjs.cpp \
    src/ui/dialogs/dialogcharacter.cpp \
    src/ui/views/characteritemview.cpp \
    src/ui/models/characterlistmodel.cpp \
    src/business/adventure.cpp \
    src/controller/adventurecontroller.cpp \
    src/ui/dialogs/dialogabout.cpp \
    src/ui/dialogs/dialognewadventure.cpp

HEADERS += src/ui/mainwindow.h \
    src/controller/server.h \
	src/controller/charactercontroller.h \
    src/business/character.h \
	src/ui/tabs/tabpjs.h \
    src/ui/tabs/tabpnjs.h \
    src/ui/dialogs/dialogcharacter.h \
    src/ui/views/characteritemview.h \
    src/ui/models/characterlistmodel.h \
    src/business/adventure.h \
    src/controller/adventurecontroller.h \
    src/ui/dialogs/dialogabout.h \
    src/ui/dialogs/dialognewadventure.h

FORMS += src/ui/mainwindow.ui \
    src/ui/tabs/tabpjs.ui \
    src/ui/tabs/tabpnjs.ui \
    src/ui/dialogs/dialogcharacter.ui \
    src/ui/views/characteritemview.ui \
    src/ui/dialogs/dialogabout.ui \
    src/ui/dialogs/dialognewadventure.ui

CONFIG += c++11

OTHER_FILES +=

RESOURCES += \
    src/ui/resources.qrc
