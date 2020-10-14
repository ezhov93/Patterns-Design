#ifndef HOMETHEATERSYSTEM_H
#define HOMETHEATERSYSTEM_H

#include <iostream>
#include <string>
#include<cassert>

class Amplifier;
class Tuner;
class DvdPlayer;
class CdPlayer;
class Projector;
class TheaterLights;
class Screen;
class PopcornPopper;

class Amplifier {
public:
  Amplifier(std::string description):
    description(description), tuner(0), dvd(0), cd(0) {}
  void on() { std::cout << description << "on" << std::endl; }
  void off() { std::cout << description << " off" << std::endl; }
  void setStereoSound();
  void setSurroundSound();
  void setVolume(int level);
  void setTuner(Tuner &tuner);
  void setDvd(DvdPlayer &dvd);
  void setCd(CdPlayer &cd);
  friend std::ostream& operator<< (std::ostream &out, const Amplifier &obj) {
    return out<< obj.description;
  }

private:
  std::string description;
  Tuner *tuner;
  DvdPlayer *dvd;
  CdPlayer *cd;
  Amplifier( const Amplifier& ); // Disable copy constructor
  void operator=( const Amplifier& ); // Disable assignment operator
};

class Tuner {
public:
  Tuner(std::string description, Amplifier *amplifier):
    description(description), amplifier(amplifier), frequency(.0) { assert(amplifier); }
  void on() { std::cout << description << " on"; }
  void off() { std::cout << description << " off"; }
  void setFrequency(double frequency);
  void setAm() { std::cout << description << " setting AM mode"; }
  void setFm() { std::cout << description << " setting FM mode"; }
  friend std::ostream& operator<< (std::ostream &out, const Tuner &obj) {
    return out<< obj.description;
  }

private:
  std::string description;
  Amplifier *amplifier;
  double frequency;
  Tuner( const Tuner& ); // Disable copy constructor
  void operator=( const Tuner& ); // Disable assignment operator
};

class DvdPlayer {
public:
  DvdPlayer(std::string description, Amplifier *amplifier):
    description( description), amplifier(amplifier), currentTrack(0) { assert(amplifier); }
  void on() { std::cout << description << " on" << std::endl; }
  void off() { std::cout << description << " off" << std::endl; }
  void eject();
  void play(std::string movie);
  void play(int track);
  void stop();
  void pause();
  void setTwoChannelAudio();
  void setSurroundAudio();
  friend std::ostream& operator<< (std::ostream &out, const DvdPlayer &obj) {
    return out<< obj.description;
  }

private:
  std::string description;
  Amplifier *amplifier;
  int currentTrack;
  std::string movie;
  DvdPlayer( const DvdPlayer& ); // Disable copy constructor
  void operator=( const DvdPlayer& ); // Disable assignment operator
};

class CdPlayer {
public:
  CdPlayer(std::string description, Amplifier *amplifier):
    description(description), amplifier(amplifier), currentTrack(0) { assert(amplifier); };
  void on() { std::cout << description << " on" << std::endl; }
  void off() { std::cout << description << " off" << std::endl; }
  void eject();
  void play(std::string title);
  void play(int track);
  void stop();
  void pause();
  friend std::ostream& operator<< (std::ostream &out, const CdPlayer &obj) {
    return out<< obj.description;
  }

private:
  std::string description;
  Amplifier *amplifier;
  int currentTrack;
  std::string title;
  CdPlayer( const CdPlayer& ); // Disable copy constructor
  void operator=( const CdPlayer& ); // Disable assignment operator
};

class Projector {
public:
  Projector(std::string description, DvdPlayer *dvdPlayer):
    description(description), dvdPlayer(dvdPlayer) { assert(dvdPlayer); }
  void on() { std::cout << description << " on" << std::endl; }
  void off() { std::cout << description << " off" << std::endl; }
  void wideScreenMode();
  void tvMode();
  friend std::ostream& operator<< (std::ostream &out, const Projector &obj) {
    return out<< obj.description;
  }

private:
  std::string description;
  DvdPlayer *dvdPlayer;
  Projector( const Projector& ); // Disable copy constructor
  void operator=( const Projector& ); // Disable assignment operator
};

class TheaterLights {
public:
  TheaterLights(std::string description): description(description) {}
  void on() { std::cout << description << " on" << std::endl; }
  void off() { std::cout << description << " off" << std::endl; }
  void dim(int level);
  friend std::ostream& operator<< (std::ostream &out, const TheaterLights &obj) {
    return out<< obj.description;
  }

private:
  std::string description;
  TheaterLights( const TheaterLights& ); // Disable copy constructor
  void operator=( const TheaterLights& ); // Disable assignment operato
};

class Screen {
public:
  Screen(std::string description): description(description) {}
  void up() { std::cout << description << " going up" << std::endl; }
  void down() { std::cout << description << " going down" << std::endl; }
  friend std::ostream& operator<< (std::ostream &out, const Screen &obj) {
    return out<< obj.description;
  }

private:
  std::string description;
  Screen( const Screen& ); // Disable copy constructor
  void operator=( const Screen& ); // Disable assignment operator
};

class PopcornPopper {
public:
  PopcornPopper(std::string description): description(description) {}
  void on() { std::cout << description << " on" << std::endl; }
  void off() { std::cout << description << " off" << std::endl; }
  void pop() { std::cout << description << " popping popcorn!" << std::endl; }
  friend std::ostream& operator<< (std::ostream &out, const PopcornPopper &obj) {
    return out<< obj.description;
  }

private:
  std::string description;
  PopcornPopper( const PopcornPopper& ); // Disable copy constructor
  void operator=( const PopcornPopper& ); // Disable assignment operator
};

#endif  // HOMETHEATERSYSTEM_H
