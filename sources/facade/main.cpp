#include "hometheaterfacade.h"

int main() {
  Amplifier amp("Amplifier");
  Tuner tuner("Tuner", &amp);
  DvdPlayer dvd("DVD player", &amp);
  CdPlayer cd("CD player", &amp);
  Projector projector("Projector", &dvd);
  TheaterLights lights("Lights");
  Screen screen("Screen");
  PopcornPopper popper("Popper");

  HomeTheaterFacade homeTheater(&amp, &tuner, &dvd, &cd, &projector, &screen,
                                &lights, &popper);
  homeTheater.watchMovie("Raiders of the Lost Ark");
  homeTheater.endMovie();

  system("pause");
  return 0;
}
