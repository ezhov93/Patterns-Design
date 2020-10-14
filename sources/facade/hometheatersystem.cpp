#include "hometheatersystem.h"

void Amplifier::setStereoSound() {
  std::cout << description << " stereo mode on" << std::endl;
}

void Amplifier::setSurroundSound() {
  std::cout << description << " surround sound on (5 speakers, 1 subwoofer)"
            << std::endl;
}

void Amplifier::setVolume(int level) {
  std::cout << description << " setting volume to " << level << std::endl;
}

void Amplifier::setTuner(Tuner &tuner) {
  std::cout << description << " setting tuner to " << *dvd << std::endl;
  this->tuner = &tuner;
}

void Amplifier::setDvd(DvdPlayer &dvd) {
  std::cout << description << " setting DVD player to " << dvd << std::endl;
  this->dvd = &dvd;
}

void Amplifier::setCd(CdPlayer &cd) {
  std::cout << description << " setting CD player to " << cd << std::endl;
  this->cd = &cd;
}

void Tuner::setFrequency(double frequency) {
  std::cout << description << " setting frequency to " << frequency;
  this->frequency = frequency;
}

void DvdPlayer::eject() {
  movie.empty();
  std::cout << description << " eject" << std::endl;
}

void DvdPlayer::play(std::string movie) {
  this->movie = movie;
  currentTrack = 0;
  std::cout << description << " playing \"" << movie << "\"" << std::endl;
}

void DvdPlayer::play(int track) {
  if (!movie.length())
    std::cout << description << " can't play track " << track
              << " no dvd inserted" << std::endl;
  else {
    currentTrack = track;
    std::cout << description << " playing track " << currentTrack << " of \""
              << movie << "\"" << std::endl;
  }
}

void DvdPlayer::stop() {
  currentTrack = 0;
  std::cout << description << " stopped \"" << movie << "\"" << std::endl;
}

void DvdPlayer::pause() {
  std::cout << description << " paused \"" << movie << "\"" << std::endl;
}

void DvdPlayer::setTwoChannelAudio() {
  std::cout << description << " set two channel audio" << std::endl;
}

void DvdPlayer::setSurroundAudio() {
  std::cout << description << " set surround audio" << std::endl;
}


void CdPlayer::eject() {
  title.empty();
  std::cout << description << " eject" << std::endl;
}

void CdPlayer::play(std::string title) {
  this->title = title;
  currentTrack = 0;
  std::cout << description << " playing \"" << title << "\"" << std::endl;
}

void CdPlayer::play(int track) {
  if (title.length() == 0)
    std::cout << description << " can't play track " << currentTrack
              << ", no cd inserted" << std::endl;
  else {
    currentTrack = track;
    std::cout << description << " playing track " << currentTrack << std::endl;
  }
}

void CdPlayer::stop() {
  currentTrack = 0;
  std::cout << description << " stopped" << std::endl;
}

void CdPlayer::pause() {
  std::cout << description << " paused \"" << title << "\"" << std::endl;
}


void Projector::wideScreenMode() {
  std::cout << description << " in widescreen mode (16x9 aspect ratio)"
            << std::endl;
}

void Projector::tvMode() {
  std::cout << description << " in tv mode (4x3 aspect ratio)" << std::endl;
}

void TheaterLights::dim(int level) {
  std::cout << description << " dimming to " << level << "%" << std::endl;
}
