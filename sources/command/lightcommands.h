#ifndef LIGHTCOMMANDS_H
#define LIGHTCOMMANDS_H

#include "command.h"
#include "light.h"

class LightOnCommand : public Command {
 private:
  const Light *light;

 public:
  explicit LightOnCommand(const Light *light) : light(light) { assert(light); }
  virtual void execute() const final { light->on(); }
  virtual void undo() const final { light->off(); }
};

class LightOffCommand : public Command {
 private:
  const Light *light;

 public:
  explicit LightOffCommand(const Light *light) : light(light) { assert(light); }
  virtual void execute() const final { light->off(); }
  virtual void undo() const final { light->on(); }
};

#endif  // LIGHTCOMMANDS_H
