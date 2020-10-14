#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
 public:
  MenuItem(std::string name, std::string description, bool vegetarian,
           double price) {
    this->name = name;
    this->description = description;
    this->vegetarian = vegetarian;
    this->price = price;
  }
  std::string getName() { return name; }
  std::string getDescription() { return description; }
  double getPrice() { return price; }
  bool isVegetarian() { return vegetarian; }

 private:
  std::string name;
  std::string description;
  bool vegetarian;
  double price;
};

#endif  // MENUITEM_H
