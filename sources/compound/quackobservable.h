#ifndef QUACKOBSERVABLE_H
#define QUACKOBSERVABLE_H

class QuackObservable;

class Observer {
public:
  virtual void update(QuackObservable* duck ) = 0;
  virtual ~Observer() = default;
};

class QuackObservable {
public:
  virtual void registerObserver(Observer *observer) = 0;
  virtual void notifyObservers() const = 0;
};


#endif // QUACKOBSERVABLE_H
