#include "waitress.h"

Waitress::Waitress(PancakeHouseMenu *pancakeHouseMenu, DinerMenu *dinerMenu) {
  this->pancakeHouseMenu = pancakeHouseMenu;
  this->dinerMenu = dinerMenu;
}

void Waitress::printMenu() {
  auto pancakeIterator = pancakeHouseMenu->createIterator();
  auto dinerIterator = dinerMenu->createIterator();
  std::cout<<"MENU\n----\nBREAKFAST"<<std::endl;
  printMenu(pancakeIterator);
  std::cout<<"\nLUNCH"<<std::endl;
  printMenu(dinerIterator);
  delete pancakeIterator;
  delete dinerIterator;
}

void Waitress::printMenu(Eiterator<MenuItem> *iterator) {
  while (iterator->hasNext()) {
    MenuItem menuItem = iterator->next();
    std::cout<<menuItem.getName()<<", ";
    std::cout<<menuItem.getPrice()<<" -- ";
    std::cout<<menuItem.getDescription()<<std::endl;
  }
}
