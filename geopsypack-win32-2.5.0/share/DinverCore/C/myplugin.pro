include(../config.pri)

CONFIG+=plugin
TEMPLATE=lib
QT-=gui
TARGET=my_c_plugin

LIBS+= -L $$BINPATH/lib -Wl,-rpath,$$BINPATH/lib -lQGpCoreTools -lDinverCore

HEADERS += myplugin.h
SOURCES += forward.c myplugin.cpp

