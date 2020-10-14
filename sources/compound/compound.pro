TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
  abstractduckfactory.h \
  countingduckfactory.h \
  duckfactory.h \
  ducks.h \
  flock.h \
  goose.h \
  gooseadapter.h \
  observable.h \
  quackable.h \
  quackcounter.h \
  quacklogist.h \
  quackobservable.h
