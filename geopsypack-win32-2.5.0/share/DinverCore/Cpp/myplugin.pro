include(../config.pri)

CONFIG+=plugin
TEMPLATE=lib
QT-=gui
TARGET=my_cpp_plugin

LIBS+= -L $$BINPATH/lib -Wl,-rpath,$$BINPATH/lib -lQGpCoreTools -lDinverCore

HEADERS += forward.h myplugin.h
SOURCES += forward.cpp myplugin.cpp
