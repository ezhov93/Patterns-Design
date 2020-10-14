#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "quackobservable.h"
#include <vector>
#include <cassert>

class Observable : public QuackObservable {
  Observable(const Observable&) = delete;
  void operator=(const Observable&) = delete;

private:
  mutable std::vector<Observer*> observers;
  QuackObservable* duck;

public:
  explicit Observable(QuackObservable* duck) :
    duck(duck) {
    assert(duck);
  }
  virtual void registerObserver(Observer* observer) final{
    assert(observer);
    observers.push_back(observer);
  }
  virtual void notifyObservers() const final {
    for (auto it:observers) it->update(duck);
  }
  std::vector<Observer*> getObservers() { return observers; }
};

#endif // OBSERVABLE_H
