#ifndef CELLINGFANCOMMANDS_H
#define CELLINGFANCOMMANDS_H

#include "cellingfan.h"
#include "command.h"

class CeilingFanCommand : public Command {
 public:
  explicit CeilingFanCommand(const CeilingFan *ceilingFan)
      : ceilingFan(ceilingFan) {
    assert(ceilingFan);
  }
  virtual void execute() const = 0;
  virtual void undo() const final;

 protected:
  const CeilingFan *ceilingFan;
  mutable CeilingFan::Speed prevSpeed;
};

class CeilingFanHighCommand : public CeilingFanCommand {
 public:
  using CeilingFanCommand::CeilingFanCommand;
  virtual void execute() const final {
    prevSpeed = ceilingFan->getSpeed();
    ceilingFan->high();
  }
};

class CeilingFanMediumCommand : public CeilingFanCommand {
 public:
  using CeilingFanCommand::CeilingFanCommand;
  virtual void execute() const final {
    prevSpeed = ceilingFan->getSpeed();
    ceilingFan->medium();
  }
};

class CeilingFanLowCommand : public CeilingFanCommand {
 public:
  using CeilingFanCommand::CeilingFanCommand;
  virtual void execute() const final {
    prevSpeed = ceilingFan->getSpeed();
    ceilingFan->low();
  }
};

class CeilingFanOffCommand : public CeilingFanCommand {
 public:
  using CeilingFanCommand::CeilingFanCommand;
  virtual void execute() const final {
    prevSpeed = ceilingFan->getSpeed();
    ceilingFan->off();
  }
};

#endif  // CELLINGFANCOMMANDS_H
