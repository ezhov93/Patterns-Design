#include <iostream>

#include "drinks.h"
#include "condiments.h"

using namespace std;

int main()
{
    Bevarage *bevarage = new  Espresso;
    std::cout<<bevarage->description()<<" $"<<bevarage->cost()<<std::endl;

    Bevarage *bevarage2 =new HouseBlend;
    bevarage2->setSize(Bevarage::TALL);
    bevarage2 = new Mocha(*bevarage2);
    bevarage2 = new Mocha(*bevarage2);
    bevarage2 = new Whip(*bevarage2);
    bevarage2->description();
    std::cout<<bevarage2->description()<<" $"<<bevarage2->cost()<<std::endl;

    delete bevarage;
    delete bevarage2;

    system("pause");
    return 0;
}
