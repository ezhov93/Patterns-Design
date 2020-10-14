TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dinermenu.cpp \
        main.cpp \
        menuitem.cpp \
        pancakehousemenu.cpp \
        waitress.cpp

HEADERS += \
  dinermenu.h \
  iterators.h \
  menuitem.h \
  pancakehousemenu.h \
  waitress.h
