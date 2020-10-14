#ifndef DUCKS_H
#define DUCKS_H

#include "quackable.h"
#include <iostream>
#include "observable.h"
#include <memory>

class MallardDuck: public Quackable {
private:
  std::unique_ptr<Observable> observable;

public:
  MallardDuck() { observable.reset(new Observable(this)); }
  virtual void quack() const {
    std::cout<<"Quack"<<std::endl;
    notifyObservers();
  }
  virtual void registerObserver(Observer *observer) {
    observable->registerObserver(observer);
  }
  virtual void notifyObservers() const {
    observable->notifyObservers();
  }

  virtual std::string toStrung() const final {return "MallardDuck"; }
};

class RedheadDuck : public Quackable {
private:
  std::unique_ptr<Observable> observable;

public:
  RedheadDuck() { observable.reset(new Observable(this)); }
  virtual void quack() const {
    std::cout<<"Quack"<<std::endl;
    notifyObservers();
  }
  virtual void registerObserver(Observer *observer) {
    observable->registerObserver(observer);
  }
  virtual void notifyObservers() const {
    observable->notifyObservers();
  }
  virtual std::string toStrung() const final {return "RedheadDuck"; }
};

class DuckCall : public Quackable {
private:
  std::unique_ptr<Observable> observable;

public:
  DuckCall() { observable.reset(new Observable(this)); }
  virtual void quack() const {
    std::cout<<"Kwak"<<std::endl;
    notifyObservers();
  }
  virtual void registerObserver(Observer *observer) {
    observable->registerObserver(observer);
  }
  virtual void notifyObservers() const {
    observable->notifyObservers();
  }

  virtual std::string toStrung() const final {return "DuckCall"; }
};

class RubberDuck : public Quackable {
private:
  std::unique_ptr<Observable> observable;

public:
  RubberDuck() { observable.reset(new Observable(this)); }
  virtual void quack() const {
    std::cout<<"Squeak"<<std::endl;
    notifyObservers();
  }
  virtual void registerObserver(Observer *observer) {
    observable->registerObserver(observer);
  }
  virtual void notifyObservers() const {
    observable->notifyObservers();
  }
  virtual std::string toStrung() const final {return "RubberDuck"; }
};

#endif // DUCKS_H
