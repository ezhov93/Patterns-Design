#ifndef MENUCOMPONENT_H
#define MENUCOMPONENT_H

#include "menuexception.h"

class MenuComponent {
 private:
  MenuComponent(const MenuComponent&);   // Disable copy constructor
  void operator=(const MenuComponent&);  // Disable assignment operator

 public:
  MenuComponent() = default;
  virtual ~MenuComponent() = default;
  virtual void add(MenuComponent*) {
    throw new UnsupportedOperationException();
  }
  virtual void remove(MenuComponent*) {
    throw new UnsupportedOperationException();
  }
  virtual const MenuComponent* getChild(int) const {
    throw new UnsupportedOperationException();
  }
  virtual std::string getName() const {
    throw new UnsupportedOperationException();
  }
  virtual std::string getDescription() const {
    throw new UnsupportedOperationException();
  }
  virtual double getPrice() const { throw new UnsupportedOperationException(); }
  virtual bool isVegetarian() const {
    throw new UnsupportedOperationException();
  }
  virtual void print() const { throw new UnsupportedOperationException(); }
};

#endif  // MENUCOMPONENT_H
