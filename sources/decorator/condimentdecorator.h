#ifndef CONDIMENTDECORATOR_H
#define CONDIMENTDECORATOR_H

#include "bevarage.h"

class CondimentDecorator : public Bevarage {
private:
  CondimentDecorator(const CondimentDecorator&);
  void operator=(const CondimentDecorator&);

protected:
  CondimentDecorator() = default;
  using Bevarage::description;
  Bevarage* bevarage;
};

#endif  // CONDIMENTDECORATOR_H
