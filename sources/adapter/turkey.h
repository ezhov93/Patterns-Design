#ifndef TURKEY_H
#define TURKEY_H

#include <iostream>

class Turkey {
 public:
  virtual ~Turkey() { std::clog<<"\tDestroy Turkey"<<std::endl; };
  virtual void gobble() const = 0;
  virtual void fly() const = 0;
};

#endif  // TURKEY_H
