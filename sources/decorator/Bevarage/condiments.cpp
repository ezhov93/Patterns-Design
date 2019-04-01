#include "condiments.h"

Mocha::Mocha(Bevarage &beverage) {
    this->bevarage = &beverage;
}

std::string Mocha::description() {
    return bevarage->description() + ", Mocha";
}

double Mocha::cost() {
    return .20 + bevarage->cost();
}


Whip::Whip(Bevarage &beverage) {
    this->bevarage = &beverage;
}

std::string Whip::description() {
    return bevarage->description() + ", Whip";
}

double Whip::cost() {
    return .55 + bevarage->cost();
}
