#include <iostream>
#include "machine.h"
#include "states.h"

using namespace std;

Machine::Machine(int numberGumballs) : _count( numberGumballs ) {
  assert( numberGumballs >= 0 );
  _soldOutState = new SoldOutState( this );
  _noQuarterState = new NoQuarterState( this );
  _hasQuarterState = new HasQuarterState( this );
  _soldState = new SoldState( this );
  _winnerState = new WinnerState( this );
  _state = _soldOutState;
  if( _count  > 0 ) _state = _noQuarterState;
}

int main()
{
  Machine machine(5);

  cout << machine.toString() << endl;
  machine.insertQuarter();
  machine.turnCrank();
  cout << machine.toString() << endl;
  machine.insertQuarter();
  machine.turnCrank();
  machine.insertQuarter();
  machine.turnCrank();
  cout << machine.toString() << endl;

  return 0;
}
