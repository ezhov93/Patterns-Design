#ifndef DINERMENU_H
#define DINERMENU_H

#include <iostream>
#include <iterator>
#include <list>
#include "menuitem.h"

class DinerMenuIterator;

class DinerMenu {
 private:
  static const int MAX_ITEMS = 6;
  int numberOfItems = 0;
  MenuItem* menuItems[MAX_ITEMS];

 public:
  friend class DinerMenuIterator;
  DinerMenu();
  void addItem(std::string name, std::string description, bool vegetarian,
               double price);
  std::iterator<std::input_iterator_tag, DinerMenu> *createIterator() const;
};

class DinerMenuIterator
    : public std::iterator<std::input_iterator_tag, MenuItem> {
 private:
  DinerMenu* menu;
  int index = 0;
  int size;

 public:
  DinerMenuIterator(DinerMenu* menu);
  DinerMenuIterator(const DinerMenuIterator& dmi) {
    DinerMenuIterator(dmi.menu);
  }
  const DinerMenu* begin() noexcept { return &menu[0]; }
  const DinerMenu* end() noexcept { return &menu[size - 1]; }
  DinerMenuIterator& operator++();
  DinerMenuIterator operator++(int);
  bool operator==(const DinerMenuIterator& rhs) const {
    return menu == rhs.menu;
  }
  bool operator!=(const DinerMenuIterator& rhs) const {
    return menu != rhs.menu;
  }
  bool operator()() { return index != menu->numberOfItems + 1; }
  DinerMenu& operator*() { return *menu; }
};

#endif  // DINERMENU_H
