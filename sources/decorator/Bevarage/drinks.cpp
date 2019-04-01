#include "drinks.h"

Espresso::Espresso()
{
    _description = "Espresso";
}


double Espresso::cost()
{
    return 1.99;
}

HouseBlend::HouseBlend()
{
    _description = "House Blend Coffee";
}

double HouseBlend::cost()
{
    return .89;
}
