#ifndef QUACKABLE_H
#define QUACKABLE_H

#include "observable.h"
#include <string>

class Quackable : public QuackObservable
{
public:
  virtual ~Quackable() = default;
  virtual void quack() const = 0;
  virtual std::string toStrung() const = 0;
};

#endif // QUACKABLE_H
