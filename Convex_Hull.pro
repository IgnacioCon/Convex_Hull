TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Punto2D.cpp

HEADERS += \
    Punto2D.h


win32: LIBS += -lfreeglut -lglut32 -lopengl32
else:unix: LIBS += -lGL -lglut
