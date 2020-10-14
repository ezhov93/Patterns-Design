#ifndef CONDIMENTS_H
#define CONDIMENTS_H

#include "condimentdecorator.h"
#include "cassert"

static double sizeCost(Bevarage::Size size) {
  double cost = 0;
  if (size == Bevarage::TALL) cost = .10;
  if (size == Bevarage::GRANDE) cost = .15;
  if (size == Bevarage::VENTI) cost = .20;
  return cost;
}

class Mocha : public CondimentDecorator {
public:
  explicit Mocha(Bevarage *bevarage) {
    assert(bevarage);
    this->bevarage = bevarage;
  }

  virtual std::string description() const final {
    return bevarage->description() + ", Mocha";
  }
  virtual double cost() const final {
    return bevarage->cost() + sizeCost(bevarage->size()) + .55;
  }
};

class Whip : public CondimentDecorator {
public:
  explicit Whip(Bevarage *bevarage) {
    assert(bevarage);
    this->bevarage = bevarage;
  }
  virtual std::string description() const final {
    return bevarage->description() + ", Whip";
  }
  virtual double cost() const final {
    return bevarage->cost() + sizeCost(bevarage->size()) + .55;
  }
};

#endif  // CONDIMENTS_H
