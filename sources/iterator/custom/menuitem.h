#ifndef MENUITEM_H
#define MENUITEM_H

#include "iterators.h"
#include <sstream>

class MenuItem {
public:
  MenuItem(std::string name, std::string description, bool vegetarian,
           double price);
  std::string getName() { return name; }
  std::string getDescription() { return description; }
  double getPrice() { return price; }
  bool isVegetarian() { return vegetarian; }
  std::string toString() {
    std::stringstream value(name);
    value << " $" << price << std::endl << description;
    return value.str();
  }

private:
  std::string name;
  std::string description;
  bool vegetarian;
  double price;
  MenuItem( const MenuItem& ); // Disable copy constructor
  void operator=( const MenuItem& ); // Disable assignment operator
};

class Menu {
public:
  virtual ~Menu() = default;
  virtual Iterator<MenuItem>* createIterator() const = 0;
};

#endif  // MENUITEM_H
