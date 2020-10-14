#ifndef REMOTECONTROLL_H
#define REMOTECONTROLL_H

#include <vector>
#include "command.h"

class Commnad;
class RemoteControll {
  std::vector<Command *> *onCommands;
  std::vector<Command *> *offCommands;
  mutable Command *undoCommand;

 public:
  RemoteControll();
  void setCommand(Command *onCommand, Command *offCommand);
  void onButtonWasPressed(size_t slot) const;
  void offButtonWasPressed(size_t slot) const;
  void undoButtonWasPressed() const { undoCommand->undo(); }
  size_t numberOfSlots() const { return onCommands->size(); }
  std::string toString() const;
};

#endif  // REMOTECONTROLL_H
