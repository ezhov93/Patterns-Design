#ifndef WILDTURKEY_H
#define WILDTURKEY_H

#include "turkey.h"

class WildTurkey : public Turkey {
 public:
  virtual void gobble() const final {
    std::cout << "Gobble gobble" << std::endl;
  }
  virtual void fly() const final {
    std::cout << "I'm flying a short distance" << std::endl;
  }
};

#endif  // WILDTURKEY_H
