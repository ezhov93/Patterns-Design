#ifndef ITERATORS_H
#define ITERATORS_H

#include "dinermenu.h"
#include "pancakehousemenu.h"
#include <vector>

template <class T>
class Iterator {
public:
  virtual ~Iterator() = default;
  virtual bool hasNext() const = 0;
  virtual T *next() const = 0;
};

class DinerMenu;
class DinerMenuIterator: public Iterator<MenuItem> {
private:
  MenuItem **items;
  mutable int position = 0;
  DinerMenuIterator( const DinerMenuIterator& ); // Disable copy constructor
  void operator=( const DinerMenuIterator& ); // Disable assignment operator

public:
  DinerMenuIterator(MenuItem **items) { this->items = items; }
  virtual bool hasNext() const final {
    return items[position] !=0 ? true : false;
  };
  virtual MenuItem *next() const final {
    MenuItem* item = items[position++];
    return item;
  };
};

class PancakeHouseMenu;
class PancakeHouseMenuIterator: public Iterator<MenuItem> {
private:
  std::vector<MenuItem*> items;
  mutable int position;
  PancakeHouseMenuIterator( const PancakeHouseMenuIterator& ); // Disable copy constructor
  void operator=( const PancakeHouseMenuIterator& ); // Disable assignment operator

public:
  PancakeHouseMenuIterator(std::vector<MenuItem*> items)
    : items(items), position(0) = default;
  bool hasNext() { position >= static_cast<int>(items.size()) ? false : true; };
  MenuItem *next() {
    MenuItem* menuItem = items[position++];
    return menuItem;
  }
};

#endif // ITERATORS_H
