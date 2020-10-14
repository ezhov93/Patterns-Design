#ifndef MACHINE_H
#define MACHINE_H

#include <cassert>
#include <iostream>
#include "state.h"
#include <sstream>

class Machine {
 private:
  State* _soldOutState;
  State* _noQuarterState;
  State* _hasQuarterState;
  State* _soldState;
  State* _winnerState;
  State* _state;
  int _count;
  Machine(const Machine&);         // Disable copy constructor
  void operator=(const Machine&);  // Disable assignment operator

 public:
  explicit Machine(int count);
  ~Machine() {
    delete _soldOutState;
    delete _noQuarterState;
    delete _hasQuarterState;
    delete _soldState;
    delete _winnerState;
  }
  void insertQuarter() const { _state->insertQuarter(); }
  void ejectQuarter() const { _state->ejectQuarter(); }
  void turnCrank() const {
    _state->turnCrank();
    _state->dispense();
  }
  void setState(State* state) {
    assert(state);
    _state = state;
  }
  void releaseBall() {
    std::cout << "A gumball comes rolling out the slot..." << std::endl;
    if (_count != 0) _count--;
  }
  int getCount() const { return _count; }
  void refill(int count) {
    assert(count > 0);
    _count = count;
    _state = _noQuarterState;
  }
  State* getState() const { return _state; }
  State* getSoldOutState() const { return _soldOutState; }
  State* getNoQuarterState() const { return _noQuarterState; }
  State* getHasQuarterState() const { return _hasQuarterState; }
  State* getSoldState() const { return _soldState; }
  State* getWinnerState() const { return _winnerState; }
  std::string toString() const {
    std::stringstream value;
    value << std::endl << "Mighty Gumball, Inc.";
    value << std::endl << "C++-enabled Standing Gumball Model #2004";
    value << std::endl << "Inventory: " << _count << " gumball";
    if (_count > 1) value << "s";
    value << std::endl;
    value << "Machine is " << _state->toString() << std::endl;
    return value.str();
  }
};



#endif  // MACHINE_H
