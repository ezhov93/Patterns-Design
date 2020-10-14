#ifndef MENU_H
#define MENU_H

#include <assert.h>
#include <menucomponent.h>
#include <algorithm>
#include <vector>
#include "iostream"

class Menu : public MenuComponent {
 private:
  std::string _name;
  std::string _description;
  mutable std::vector<MenuComponent*> _menuComponents;
  std::vector<MenuComponent*>::iterator it;
 public:
  Menu(const std::string name, const std::string description)
      : _name(name), _description(description) {}
  void add(MenuComponent* menuComponent) {
    assert(menuComponent);
    _menuComponents.push_back(menuComponent);
  }
  void remove(MenuComponent* menuComponent) {
    assert(menuComponent);
    auto pos = std::find(_menuComponents.begin(), _menuComponents.end(),
                         menuComponent);
    _menuComponents.erase(pos);
  }
  MenuComponent* getChild(int i) const { return _menuComponents[i]; }
  std::string getName() const { return _name; }
  std::string getDescription() const { return _description; }
  void print() const {
    std::cout << std::endl << getName().c_str();
    std::cout << ", " << getDescription().c_str() << std::endl;
    std::cout << "---------------------" << std::endl;
    auto it = _menuComponents.begin();
    while (it != _menuComponents.end()) {
      MenuComponent* menuComponent = *it++;  // next
      menuComponent->print();
    }
  }
};

#endif  // MENU_H
