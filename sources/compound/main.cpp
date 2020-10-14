#include <iostream>
#include <memory>
#include "gooseadapter.h"
#include "countingduckfactory.h"
#include "flock.h"
#include "quacklogist.h"

#define NEXT()  system("pause & cls")

using namespace std;

void simulate();
void simulate(unique_ptr<AbstractDuckFactory>&);
void simulateFlock(unique_ptr<AbstractDuckFactory>&);
void simulateObserver(unique_ptr<AbstractDuckFactory>&);
static void simulate(const Quackable&);

int main()
{
  simulate();
  NEXT();
  std::unique_ptr<AbstractDuckFactory> duckFactory(new CountingDuckFactory);
  simulate(duckFactory);
  NEXT();
  simulateFlock(duckFactory);
  NEXT();
  simulateObserver(duckFactory);
  return 0;
}


void simulate() {
  // Decorator + Strategy
  unique_ptr<Quackable> mallardDuck(new QuackCounter(new  MallardDuck));
  unique_ptr<Quackable> redheadDuck (new QuackCounter(new RedheadDuck));
  unique_ptr<Quackable> duckCall (new QuackCounter(new DuckCall));
  unique_ptr<Quackable> rubberDuck (new QuackCounter(new RubberDuck));
  // Adapter
  unique_ptr<Quackable> gooseDuck(new GooseAdapter(new Goose));

  cout<<endl<<"*** Duck Simulator ***"<<endl;
  simulate(*mallardDuck.get());
  simulate(*redheadDuck.get());
  simulate(*duckCall.get());
  simulate(*rubberDuck.get());
  simulate(*gooseDuck.get());

  cout<<"The ducks quacked "<<QuackCounter::getQuacks()<<" times"<<endl;
  QuackCounter::resetQuacks();
}

void simulate(unique_ptr<AbstractDuckFactory> &duckFactory) {
  // Decorator + Strategy + Factory
  unique_ptr<Quackable> mallardDuck(duckFactory->createMallardDuck());
  unique_ptr<Quackable> redheadDuck(duckFactory->createRedheadDuck());
  unique_ptr<Quackable> duckCall(duckFactory->createDuckCall());
  unique_ptr<Quackable> rubberDuck(duckFactory->createRubberDuck());
  // Adapter
  unique_ptr<Quackable> gooseDuck(new GooseAdapter(new Goose));

  cout<<endl<<"*** Duck Simulator: With Abstract Factory ***"<<endl;
  simulate(*mallardDuck.get());
  simulate(*redheadDuck.get());
  simulate(*duckCall.get());
  simulate(*rubberDuck.get());
  simulate(*gooseDuck.get());

  cout<<"The ducks quacked "<<QuackCounter::getQuacks()<<" times"<<endl;
  QuackCounter::resetQuacks();
}

void simulateFlock(unique_ptr<AbstractDuckFactory> &duckFactory) {
  // Decorator + Strategy + Factory
  unique_ptr<Quackable> mallardDuck(duckFactory->createMallardDuck());
  unique_ptr<Quackable> redheadDuck(duckFactory->createRedheadDuck());
  unique_ptr<Quackable> duckCall(duckFactory->createDuckCall());
  unique_ptr<Quackable> rubberDuck(duckFactory->createRubberDuck());
  // Adapter
  unique_ptr<Quackable> gooseDuck(new GooseAdapter(new Goose));
  cout<<endl<<"Duck Simulator: With Composite - Flocks";
  // Composite
  Flock flockOfDucks;
  flockOfDucks.add(mallardDuck.get());
  flockOfDucks.add(redheadDuck.get());
  flockOfDucks.add(duckCall.get());
  flockOfDucks.add(rubberDuck.get());
  flockOfDucks.add(gooseDuck.get());

  Flock flockOfMallards;
  unique_ptr<Quackable> mallardDuckOne(duckFactory->createMallardDuck());
  unique_ptr<Quackable> mallardDuckTwo(duckFactory->createMallardDuck());
  unique_ptr<Quackable> mallardDuckThree(duckFactory->createMallardDuck());
  unique_ptr<Quackable> mallardDuckFour(duckFactory->createMallardDuck());

  flockOfMallards.add(mallardDuckOne.get());
  flockOfMallards.add(mallardDuckTwo.get());
  flockOfMallards.add(mallardDuckThree.get());
  flockOfMallards.add(mallardDuckFour.get());

  flockOfDucks.add(&flockOfMallards);

  cout<<endl<<"Duck Simulator: Whole Flock Simulation"<<endl;
  simulate(flockOfDucks);
  cout<<endl<<"Duck Simulator: Mallard Flock Simulation"<<endl;
  simulate(flockOfMallards);
  cout<<"The ducks quacked "<<QuackCounter::getQuacks()<<" times"<<endl;
  QuackCounter::resetQuacks();
}

void simulateObserver(unique_ptr<AbstractDuckFactory> &duckFactory) {
  // Decorator + Strategy + Factory
  unique_ptr<Quackable> mallardDuck(duckFactory->createMallardDuck());
  unique_ptr<Quackable> redheadDuck(duckFactory->createRedheadDuck());
  unique_ptr<Quackable> duckCall(duckFactory->createDuckCall());
  unique_ptr<Quackable> rubberDuck(duckFactory->createRubberDuck());
  // Adapter
  unique_ptr<Quackable> gooseDuck(new GooseAdapter(new Goose));
  cout<<endl<<"Duck Simulator: With Composite — Flocks";
  // Composite
  Flock flockOfDucks;
  flockOfDucks.add(mallardDuck.get());
  flockOfDucks.add(redheadDuck.get());
  flockOfDucks.add(duckCall.get());
  flockOfDucks.add(rubberDuck.get());
  flockOfDucks.add(gooseDuck.get());

  Flock flockOfMallards;
  unique_ptr<Quackable> mallardDuckOne(duckFactory->createMallardDuck());
  unique_ptr<Quackable> mallardDuckTwo(duckFactory->createMallardDuck());
  unique_ptr<Quackable> mallardDuckThree(duckFactory->createMallardDuck());
  unique_ptr<Quackable> mallardDuckFour(duckFactory->createMallardDuck());

  flockOfMallards.add(mallardDuckOne.get());
  flockOfMallards.add(mallardDuckTwo.get());
  flockOfMallards.add(mallardDuckThree.get());
  flockOfMallards.add(mallardDuckFour.get());

  flockOfDucks.add(&flockOfMallards);

  cout<<endl<<"Duck Simulator: With Observer"<<endl;
  unique_ptr<Quacklogist> quacklogist(new Quacklogist);
  flockOfDucks.registerObserver(quacklogist.get());
  simulate(flockOfDucks);

  cout<<"The ducks quacked "<<QuackCounter::getQuacks()<<" times"<<endl;
  QuackCounter::resetQuacks();
}

void simulate(const Quackable &duck) {
  duck.quack();
}
