#ifndef COMMAND_H
#define COMMAND_H

#include <cassert>
#include <functional>

class Command {
 private:
  std::function<void()> cmd;

 public:
  explicit Command() : cmd(nullptr) {}
  Command(std::function<void()> f) : cmd(f) {}
  virtual ~Command() = default;
  virtual void execute() const {
    assert(cmd);
    cmd();
  }
  virtual void undo() const {};
};

class NoCommand : public Command {
  void execute() const final {}
  void undo() const final {}
};

#endif  // COMMAND_H
