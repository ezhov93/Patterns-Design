#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include <iostream>
#include "duck.h"

class MallardDuck : public Duck {
 public:
  virtual void quack() const final { std::cout << "Quack" << std::endl; }
  virtual void fly() const final { std::cout << "I'm flying" << std::endl; }
};

#endif  // MALLARDDUCK_H
