#ifndef WAITRESS_H
#define WAITRESS_H

#include "iterators.h"
#include <iostream>

class Waitress {
public:
  Waitress(PancakeHouseMenu *pancakeHouseMenu, DinerMenu *dinerMenu);
  void printMenu();

private:
  PancakeHouseMenu *pancakeHouseMenu;
  DinerMenu *dinerMenu;
  void printMenu(Iterator<MenuItem> *iterator);
};

#endif // WAITRESS_H
