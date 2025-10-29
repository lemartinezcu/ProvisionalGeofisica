include(../config.pri)

CONFIG+=plugin
TEMPLATE=lib
QT-=gui
TARGET=rosenbrock

LIBS+= -L $$BINPATH/lib -Wl,-rpath,$$BINPATH/lib -lQGpCoreTools -lDinverCore

HEADERS += rosenbrock.h
SOURCES += forward.c rosenbrock.cpp

