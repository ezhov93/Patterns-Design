#ifndef PANCAKEHOUSEMENU_H
#define PANCAKEHOUSEMENU_H

#include <list>
#include "menuitem.h"

class PancakeHouseMenu {
 private:
  std::list<MenuItem *> menuItems;

 public:
  PancakeHouseMenu();
  void addItem(std::string name, std::string description, bool vegetarian,
               double price);
  std::iterator<std::input_iterator_tag, MenuItem>  *createIterator() const {
    return menuItems.;
  }
};

#endif  // PANCAKEHOUSEMENU_H
