#ifndef HOMETHEATERFACADE_H
#define HOMETHEATERFACADE_H

#include <string>
#include "hometheatersystem.h"

class HomeTheaterFacade {
private:
  Amplifier *amp;
  Tuner *tuner;
  DvdPlayer *dvd;
  CdPlayer *cd;
  Projector *projector;
  TheaterLights *lights;
  Screen *screen;
  PopcornPopper *popper;

public:
  HomeTheaterFacade(Amplifier *amp,
                    Tuner *tuner,
                    DvdPlayer *dvd,
                    CdPlayer *cd,
                    Projector *projector,
                    Screen *screen,
                    TheaterLights *lights,
                    PopcornPopper *popper);
  void watchMovie(std::string);
  void endMovie();
};

#endif // HOMETHEATERFACADE_H
