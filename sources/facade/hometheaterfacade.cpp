#include "hometheaterfacade.h"

#include <iostream>

HomeTheaterFacade::HomeTheaterFacade(Amplifier *amp, Tuner *tuner, DvdPlayer *dvd, CdPlayer *cd, Projector *projector, Screen *screen, TheaterLights *lights, PopcornPopper *popper) {
  this->amp = amp;
  this->tuner = tuner;
  this->dvd = dvd;
  this->cd = cd;
  this->projector = projector;
  this->screen = screen;
  this->lights = lights;
  this->popper = popper;
}

void HomeTheaterFacade::watchMovie(std::string movie) {
  std::cout<<"Get ready to watch a movie..."<<std::endl;
  popper->on();
  popper->pop();
  lights->dim(10);
  screen->down();
  projector->on();
  projector->wideScreenMode();
  amp->on();
  amp->setDvd(*dvd);
  amp->setSurroundSound();
  amp->setVolume(5);
  dvd->on();
  dvd->play(movie);
}

void HomeTheaterFacade::endMovie() {
  std::cout<<"Shutting movie theater down..."<<std::endl;
  popper->off();
  lights->on();
  screen->up();
  projector->off();
  amp->off();
  dvd->stop();
  dvd->eject();
  dvd->off();
}
