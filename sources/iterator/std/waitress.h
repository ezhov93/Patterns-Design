#ifndef WAITRESS_H
#define WAITRESS_H

#include "pancakehousemenu.h"
#include "dinermenu.h"

class Waitress {
  PancakeHouseMenu pancakeHouseMenu;
  DinerMenu dinerMenu;
public:
  Waitress(PancakeHouseMenu pancakeHouseMenu, DinerMenu dinerMenu) {
    this->pancakeHouseMenu = pancakeHouseMenu;
    this->dinerMenu = dinerMenu;
  }
  void printMenu() {
    Iterator pancakeIterator = pancakeHouseMenu.createIterator();
    Iterator dinerIterator = dinerMenu.createIterator();
    std::cout<<"MENU\n----\nBREAKFAST"<<std::endl;
    printMenu(pancakeIterator);
    System.out.println(“\nLUNCH”);
    printMenu(dinerIterator);
  }
private:
  void printMenu(Iterator iterator) {
    while (iterator.hasNext()) {
      MenuItem menuItem = iterator.next();
      System.out.print(menuItem.getName() + “, “);
      System.out.print(menuItem.getPrice() + “ -- “);
      System.out.println(menuItem.getDescription());
    }
  }
  // другие методы
}
#endif // WAITRESS_H
