TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cellingfancommands.cpp \
        main.cpp \
        remotecontroll.cpp \
        stereocommands.cpp

HEADERS += \
    cellingfan.h \
    cellingfancommands.h \
    command.h \
    light.h \
    lightcommands.h \
    macrocommand.h \
    remotecontroll.h \
    stereo.h \
    stereocommands.h


