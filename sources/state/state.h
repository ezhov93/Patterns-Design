#ifndef STATE_H
#define STATE_H

#include <string>

class State {
 public:
  virtual ~State() = default;
  virtual void insertQuarter() const = 0;
  virtual void ejectQuarter() const = 0;
  virtual void turnCrank() const = 0;
  virtual void dispense() = 0;
  virtual std::string toString() const = 0;
};

#endif  // STATE_H
