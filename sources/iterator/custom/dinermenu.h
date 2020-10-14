#ifndef DINERMENU_H
#define DINERMENU_H

#include "iterators.h"
#include "menuitem.h"
#include <string>

class MenuItem;
class DinerMenu: public Menu {
private:
  static const int MAX_ITEMS = 6;
  int numberOfItems = 0;
  MenuItem **menuItems;
  DinerMenu(const DinerMenu&); // Disable copy constructor
  void operator=(const DinerMenu&); // Disable assignment operato

public:
  friend class DinerMenuIterator;
  DinerMenu();
  void addItem(std::string name, std::string description, bool vegetarian,
               double price);
  Iterator<MenuItem> *createIterator() {
    return dynamic_cast<Iterator<MenuItem>*>(new DinerMenuIterator(menuItems));
  }
};


#endif  // DINERMENU_H
