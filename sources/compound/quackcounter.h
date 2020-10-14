#ifndef QUACKCOUNTER_H
#define QUACKCOUNTER_H

#include "quackable.h"
#include <memory>
#include <cassert>



class QuackCounter: public Quackable
{
  QuackCounter(const QuackCounter&) = delete;
  void operator=(const QuackCounter&) = delete;

private:
  std::unique_ptr<Quackable> duck;
  static int number;

public:
  explicit QuackCounter(Quackable *duck): duck(duck) { assert(duck); }
  virtual void quack() const final {
    duck->quack();
    number++;
  }
  static int getQuacks() { return number; }
  static void resetQuacks() { number = 0; }

  void registerObserver( Observer* observer) {
    assert(observer);
    duck->registerObserver( observer );
  }
  void notifyObservers() const {
    duck->notifyObservers();
  }
  virtual std::string toStrung() const final { return "QuackCounter"; }

};

int QuackCounter::number(0);

#endif // QUACKCOUNTER_H
