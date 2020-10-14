#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include <vector>
#include "command.h"

class MacroCommand : public Command {
 public:
  explicit MacroCommand(std::vector<Command *> *commands) : commands(commands) {
    assert(commands);
  }
  virtual void execute() const final {
    for (auto &it : *commands) it->execute();
  }
  virtual void undo() const final {}

 private:
  std::vector<Command *> *commands;
};

#endif  // MACROCOMMAND_H
