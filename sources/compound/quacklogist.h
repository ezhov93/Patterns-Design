#ifndef QUACKLOGIST_H
#define QUACKLOGIST_H

#include "observable.h"
#include <iostream>
#include "quackable.h"

class Quacklogist: public Observer {
public:
  virtual void update(QuackObservable *duck) final {
    std::cout<<"Quacklogist: "<<dynamic_cast<Quackable*>(duck)->toStrung()
            <<" just quacked."<<std::endl;
  }
};

#endif // QUACKLOGIST_H
