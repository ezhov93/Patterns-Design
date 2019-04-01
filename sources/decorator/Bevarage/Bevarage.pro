TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    drinks.cpp \
    condiments.cpp \
    bevarage.cpp

HEADERS += \
    bevarage.h \
    condimentdecorator.h \
    drinks.h \
    condiments.h
