include(../config.pri)

CONFIG+=plugin
TEMPLATE=lib
QT-=gui
TARGET=my_for_plugin

QMAKE_CFLAGS_RELEASE += -ffixed-line-length-none
LIBS+= -L $$BINPATH/lib -Wl,-rpath,$$BINPATH/lib -lQGpCoreTools -lDinverCore

HEADERS += myplugin.h
SOURCES += forward.f myplugin.cpp description.c

