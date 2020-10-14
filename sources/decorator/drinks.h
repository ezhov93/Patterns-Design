#ifndef DRINKS_H
#define DRINKS_H

#include "bevarage.h"

class Espresso : public Bevarage {
 public:
  Espresso() { _description = "Espresso"; }
  virtual double cost() const final { return 1.99; }
};

class HouseBlend : public Bevarage {
 public:
  HouseBlend() { _description = "House Blend Coffee"; }
  virtual double cost() const final { return .89; }
};

#endif  // DRINKS_H
