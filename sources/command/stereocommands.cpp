#include "stereocommands.h"

void StereoOnWithCDCommand::execute() const {
  stereo->on();
  stereo->setCD();
  stereo->setVolume(11);
}
