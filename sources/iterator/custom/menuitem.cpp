#include "menuitem.h"

MenuItem::MenuItem(std::string name, std::string description, bool vegetarian,
                   double price) {
  this->name = name;
  this->description = description;
  this->vegetarian = vegetarian;
  this->price = price;
}
