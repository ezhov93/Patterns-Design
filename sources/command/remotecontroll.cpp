#include "remotecontroll.h"
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>

RemoteControll::RemoteControll() {
  onCommands = new std::vector<Command *>;
  offCommands = new std::vector<Command *>;
}

void RemoteControll::setCommand(Command *onCommand, Command *offCommand) {
  assert(onCommand);
  assert(offCommand);
  onCommands->push_back(onCommand);
  offCommands->push_back(offCommand);
}

void RemoteControll::onButtonWasPressed(size_t slot) const {
  onCommands->at(slot)->execute();
  undoCommand = onCommands->at(slot);
}

void RemoteControll::offButtonWasPressed(size_t slot) const {
  offCommands->at(slot)->execute();
  undoCommand = offCommands->at(slot);
}

std::string RemoteControll::toString() const {
  std::stringstream value;
  value << "\n------ Remote Control -------\n" << std::endl;
  for (size_t i = 0; i < onCommands->size(); i++) {
    value << "[slot" << std::to_string(i) << "] ";
    value << typeid(&onCommands[i]).name();
    value << "\t";
    value << typeid(&offCommands[i]).name();
    value << std::endl;
  }
  value << "[undo] " << typeid(undoCommand).name() << std::endl;
  return value.str();
}
