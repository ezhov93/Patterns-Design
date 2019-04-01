#ifndef DRINKS_H
#define DRINKS_H

#include "bevarage.h"

class Espresso: public Bevarage
{
public:
    Espresso();
    virtual double cost() final;
};

class HouseBlend: public Bevarage
{
public:
    HouseBlend();
    virtual double cost() final;
};


#endif // DRINKS_H
