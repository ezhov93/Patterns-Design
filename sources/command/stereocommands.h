#ifndef STEREOCOMMANDS_H
#define STEREOCOMMANDS_H

#include "command.h"
#include "stereo.h"

class StereoOnWithCDCommand : public Command {
 private:
  const Stereo *stereo;

 public:
  StereoOnWithCDCommand(const Stereo *stereo) : stereo(stereo) {
    assert(stereo);
  }
  virtual void execute() const final;
  virtual void undo() const final { stereo->off(); }
};

class StereoOffWithCDCommand : public Command {
 private:
  const Stereo *stereo;

 public:
  StereoOffWithCDCommand(const Stereo *stereo) : stereo(stereo) {
    assert(stereo);
  }
  virtual void execute() const final { stereo->off(); }
  virtual void undo() const final { stereo->on(); }
};

#endif  // STEREOCOMMANDS_H
