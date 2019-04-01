#ifndef CONDIMENTS_H
#define CONDIMENTS_H

#include "condimentdecorator.h"

class Mocha: public CondimentDecorator {
public:
    Mocha(Bevarage &bevarage);
    virtual std::string description() final;
    virtual double cost() final;
private:
    Bevarage *bevarage;
};

class Whip: public CondimentDecorator {
public:
    Whip(Bevarage &bevarage);
    virtual std::string description() final;
    virtual double cost() final;
private:
    Bevarage *bevarage;
};


#endif // CONDIMENTS_H
