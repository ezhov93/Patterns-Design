#ifndef DUCKFACTORY_H
#define DUCKFACTORY_H

#include "ducks.h"
#include "quackcounter.h"
#include "abstractduckfactory.h"

class DuckFactory : public AbstractDuckFactory
{
public:
  virtual Quackable* createMallardDuck() const final {
    return new MallardDuck();
  }
  virtual Quackable* createRedheadDuck() const final {
    return new RedheadDuck();
  }
  virtual Quackable* createDuckCall() const final {
    return new DuckCall();
  }
  virtual Quackable* createRubberDuck() const final {
    return new RubberDuck();
  }
};

#endif // DUCKFACTORY_H
