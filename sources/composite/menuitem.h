#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include "menucomponent.h"

class MenuItem : public MenuComponent {
 private:
  std::string _name;
  std::string _description;
  bool _vegetarian;
  double _price;

 public:
  MenuItem(const std::string name, const std::string description,
           bool vegetarian, double price)
      : _name(name),
        _description(description),
        _vegetarian(vegetarian),
        _price(price) {}
  std::string getName() const { return _name; }
  std::string getDescription() const { return _description; }
  double getPrice() const { return _price; }
  bool isVegetarian() const { return _vegetarian; }
  void print() const {
    std::cout << "  " << getName().c_str();
    if (isVegetarian()) std::cout << "(v)";
    std::cout << ", " << getPrice() << std::endl;
    std::cout << "     -- " << getDescription().c_str() << std::endl;
  }
};

#endif  // MENUITEM_H
