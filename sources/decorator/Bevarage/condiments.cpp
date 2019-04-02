#include "condiments.h"

class Bevarage;
static double sizeCost(Bevarage::Size size)
{
    double cost = 0;
    if (size == Bevarage::TALL)
        cost = .10;
    if (size == Bevarage::GRANDE)
        cost = .15;
    if (size ==  Bevarage::VENTI)
        cost = .20;
    return cost;
}

Mocha::Mocha(Bevarage &beverage) {
    this->bevarage = &beverage;
}

std::string Mocha::description() {
    return bevarage->description() + ", Mocha";
}

double Mocha::cost() {
    return bevarage->cost() + sizeCost(bevarage->size())+ .55;
}


Whip::Whip(Bevarage &beverage) {
    this->bevarage = &beverage;
}

std::string Whip::description() {
    return bevarage->description() + ", Whip";
}

double Whip::cost() {
    return bevarage->cost() + sizeCost(bevarage->size())+ .55;
}
