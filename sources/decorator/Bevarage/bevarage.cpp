#include "bevarage.h"

std::string Bevarage::description()
{
    return _description;
}

void Bevarage::setSize(Bevarage::Size size)
{
    _size = size;
}

Bevarage::Size Bevarage::size() {
    return _size;
}
