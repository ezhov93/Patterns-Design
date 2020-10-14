#ifndef STATES_H
#define STATES_H

#include <cassert>
#include <iostream>
#include <string>
#include "machine.h"
#include "state.h"
#include <cassert>

class HasQuarterState : public State {
private:
  Machine* _machine;
  int _random;
  HasQuarterState(const HasQuarterState&);  // Disable copy constructor
  void operator=(const HasQuarterState&);   // Disable assignment operator

public:
  explicit HasQuarterState(Machine* machine) : _machine(machine), _random(0) {
    assert(machine);
    srand(_getpid());
  }
  void insertQuarter() const {
    std::cout << "You can't insert another quarter" << std::endl;
  }
  void ejectQuarter() const {
    std::cout << "Quarter returned" << std::endl;
    _machine->setState(_machine->getNoQuarterState());
  }
  void turnCrank() const {
    std::cout << "You turned..." << std::endl;
    int winner = rand() % 5;
    if ((winner == 0) && (_machine->getCount() > 0)) {
      _machine->setState(_machine->getWinnerState());
    } else {
      _machine->setState(_machine->getSoldState());
    }
  }
  void dispense() { std::cout << "No gumball dispensed" << std::endl; }
  std::string toString() const { return "waiting for turn of crank"; }
};

class NoQuarterState : public State {
private:
  Machine* _machine;

  NoQuarterState(const NoQuarterState&);  // Disable copy constructor
  void operator=(const NoQuarterState&);  // Disable assignment operator

public:
  explicit NoQuarterState(Machine* machine) : _machine(machine) {
    assert(machine);
  }
  void insertQuarter() const {
    std::cout << "You inserted a quarter" << std::endl;
    _machine->setState(_machine->getHasQuarterState());
  }
  void ejectQuarter() const {
    std::cout << "You haven't inserted a quarter" << std::endl;
  }
  void turnCrank() const {
    std::cout << "You turned, but there's no quarter" << std::endl;
  }
  void dispense() { std::cout << "You need to pay first" << std::endl; }
  std::string toString() const { return "waiting for quarter"; }
};

class SoldOutState : public State {
private:
  Machine* _machine;

  SoldOutState(const SoldOutState&);    // Disable copy constructor
  void operator=(const SoldOutState&);  // Disable assignment operator

public:
  explicit SoldOutState(Machine* machine) : _machine(machine) {
    assert(machine);
  }
  void insertQuarter() const {
    std::cout << "You can't insert a quarter, the machine is sold out"
              << std::endl;
  }
  void ejectQuarter() const {
    std::cout << "You can't eject, you haven't inserted a quarter yet"
              << std::endl;
  }
  void turnCrank() const {
    std::cout << "You turned, but there are no gumballs" << std::endl;
  }
  void dispense() { std::cout << "No gumball dispensed" << std::endl; }
  std::string toString() const { return "sold out"; }
};

class SoldState : public State {
private:
  Machine* _machine;

  SoldState(const SoldState&);       // Disable copy constructor
  void operator=(const SoldState&);  // Disable assignment operator

public:
  explicit SoldState(Machine* machine) : _machine(machine) { assert(machine); }
  void insertQuarter() const {
    std::cout << "Please wait, we're already giving you a gumball" << std::endl;
  }
  void ejectQuarter() const {
    std::cout << "Sorry, you already turned the crank" << std::endl;
  }
  void turnCrank() const {
    std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
  }
  void dispense() {
    _machine->releaseBall();
    if (_machine->getCount() > 0) {
      _machine->setState(_machine->getNoQuarterState());
    } else {
      std::cout << "Oops, out of gumballs!" << std::endl;
      _machine->setState(_machine->getSoldOutState());
    }
  }
  std::string toString() const { return "dispensing a gumball"; }
};

class WinnerState : public State {

private:
  Machine* _machine;

  WinnerState( const WinnerState& ); // Disable copy constructor
  void operator=( const WinnerState& ); // Disable assignment operator

public:
  explicit WinnerState( Machine* machine ) :
    _machine( machine ) { assert( machine ); }
  void insertQuarter() const {
    std::cout << "Please wait, we're already giving you a Gumball" << std::endl;
  }
  void ejectQuarter() const {
    std::cout << "Please wait, we're already giving you a Gumball" << std::endl;
  }
  void turnCrank() const {
    std::cout << "Turning again doesn't get you another gumball!" << std::endl;
  }
  void dispense() {
    std::cout << "YOU'RE A WINNER! You get two gumballs for your quarter" << std::endl;
    _machine->releaseBall();
    if( _machine->getCount() == 0 ) {
      _machine->setState( _machine->getSoldOutState() );
    } else {
      _machine->releaseBall();
      if( _machine->getCount() > 0 ) {
        _machine->setState( _machine->getNoQuarterState() );
      } else {
        std::cout << "Oops, out of gumballs!" << std::endl;
        _machine->setState( _machine->getSoldOutState() );
      }
    }
  }
  std::string toString() const {
    return "despensing two gumballs for your quarter, because YOU'RE A WINNER!";
  }
};

#endif  // STATES_H
