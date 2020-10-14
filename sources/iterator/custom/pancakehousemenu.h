#ifndef PANCAKEHOUSEMENU_H
#define PANCAKEHOUSEMENU_H

#include "menuitem.h"
#include "iterators.h"

class PancakeHouseMenu: public Menu {
public:
  friend class PancakeHouseMenuIterator;
  PancakeHouseMenu();
  void addItem(std::string name, std::string description, bool vegetarian,
               double price);
  Iterator<MenuItem>* createIterator() const override {
    return dynamic_cast<Iterator<MenuItem>*>(new PancakeHouseMenuIterator(menuItems));
  }

private:
  std::vector<MenuItem*> menuItems;
};



#endif  // PANCAKEHOUSEMENU_H
