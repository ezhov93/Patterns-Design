#ifndef WAITRESS_H
#define WAITRESS_H

#include <menucomponent.h>
#include <cassert>

class Waitress {
 private:
  const MenuComponent* _allMenus;
  Waitress(const Waitress&);        // Disable copy constructor
  void operator=(const Waitress&);  // Disable assignment operator

 public:
  explicit Waitress(const MenuComponent* allMenus) : _allMenus(allMenus) {
    assert(allMenus);
  }
  void printMenu() const { _allMenus->print(); }
};

#endif  // WAITRESS_H
