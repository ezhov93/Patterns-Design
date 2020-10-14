#ifndef COUNTINGDUCKFACTORY_H
#define COUNTINGDUCKFACTORY_H

#include "abstractduckfactory.h"
#include "ducks.h"
#include "quackcounter.h"

class CountingDuckFactory : public AbstractDuckFactory
{
public:
  virtual Quackable* createMallardDuck() const final {
    return new QuackCounter(new MallardDuck());
  }
  virtual Quackable* createRedheadDuck() const final {
    return new QuackCounter(new RedheadDuck());
  }
  virtual Quackable* createDuckCall() const final {
    return new QuackCounter(new DuckCall());
  }
  virtual Quackable* createRubberDuck() const final {
    return new QuackCounter(new RubberDuck());
  }
};

#endif // COUNTINGDUCKFACTORY_H
