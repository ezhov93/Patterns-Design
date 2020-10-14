#ifndef DUCK_H
#define DUCK_H

#include <iostream>

class Duck
{
public:
  virtual ~Duck() {std::clog<<"\tDestroy Duck"<<std::endl;};
  virtual void quack() const = 0;
  virtual void fly() const = 0;
};

#endif // DUCK_H
