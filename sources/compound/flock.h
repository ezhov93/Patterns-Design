#ifndef FLOCK_H
#define FLOCK_H

#include "quackable.h"
#include <vector>
#include <cassert>
#include <string>

class Flock : public Quackable {
  Flock(const Flock&) = delete;
  void operator=(const Flock&) = delete;

private:
  mutable std::vector<Quackable*> quackers;

public:
  Flock() = default;
  void add(Quackable* quacker) {
    assert(quacker);
    quackers.push_back(quacker);
  }
  virtual void quack() const final { for(auto it:quackers) it->quack(); }
  virtual void registerObserver(Observer* observer) final {
    assert(observer);
    for(auto it:quackers)
      it->registerObserver(observer);
  }
  void  virtual notifyObservers() const final {}
  virtual std::string toStrung() const final { return "Flock"; }
};

#endif // FLOCK_H
