#ifndef CONDIMENTDECORATOR_H
#define CONDIMENTDECORATOR_H

#include "bevarage.h"

class CondimentDecorator: public Bevarage
{
public:
    virtual std::string description() = 0;
    Size size() { return bevarage->size(); }

protected:
    Bevarage *bevarage;
};

#endif // CONDIMENTDECORATOR_H
