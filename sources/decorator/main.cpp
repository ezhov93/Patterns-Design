#include <iostream>
#include <memory>
#include "condiments.h"
#include "drinks.h"

int main() {
  Espresso bevarage;
  std::cout << bevarage.description() << " $" << bevarage.cost() << std::endl;

    Bevarage *bevarage3 = new HouseBlend;
    bevarage3->setSize(Bevarage::TALL);
    bevarage3 = new Whip(bevarage3);
    bevarage3 = new Mocha(bevarage3);
    bevarage3 = new Whip(bevarage3);
    bevarage3->description();
    std::cout << bevarage3->description() << " $" << bevarage3->cost()
            << std::endl;


  return 0;
}
