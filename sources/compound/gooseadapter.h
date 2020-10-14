#ifndef GOOSEADAPTER_H
#define GOOSEADAPTER_H

#include "quackable.h"
#include <memory>
#include "goose.h"
#include "cassert"
#include "observable.h"

class GooseAdapter: public Quackable
{
  GooseAdapter( const GooseAdapter& ) = delete;
  void operator=( const GooseAdapter& ) = delete;

public:
  explicit GooseAdapter(Goose *goose): goose(goose), observable(new Observable(this)){
    assert(goose);
  }

  virtual void quack() const final {
    goose->honk();
    notifyObservers();
  }

  virtual void registerObserver(Observer* observer) final {
    assert(observer);
    observable->registerObserver( observer );
  }
  virtual void notifyObservers() const final {
    observable->notifyObservers();
  }

   virtual std::string toStrung() const final {
    return "GooseAdapter";
  }

private:
  std::unique_ptr<Goose> goose;
  std::unique_ptr<Observable> observable;
};

#endif // GOOSEADAPTER_H
