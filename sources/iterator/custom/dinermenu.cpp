#include "dinermenu.h"
#include <iostream>

DinerMenu::DinerMenu() {
  numberOfItems = 0;
  menuItems = new MenuItem*[MAX_ITEMS+1];
  for (int i=0; i<MAX_ITEMS; ++i) menuItems[i] = 0;
  addItem("Vegetarian BLT",
          "(Fakin’)Bacon with lettuce & tomato on whole wheat", true, 2.99);
  addItem("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
  addItem("Soup of the day", "Soup of the day, with a side of potato salad",
          false, 3.29);
  addItem("Hotdog",
          "A hot dog, with saurkraut, relish, onions, topped with cheese",
          false, 3.05);
}

void DinerMenu::addItem(std::string name, std::string description,
                        bool vegetarian, double price) {
  auto *menuItem = new MenuItem(name, description, vegetarian, price);
  if (numberOfItems >= MAX_ITEMS)
    std::cout << "Sorry, menu is full !Can’t add item to menu" << std::endl;
  else {
    menuItems[numberOfItems] = menuItem;
    ++numberOfItems;
  }
}
