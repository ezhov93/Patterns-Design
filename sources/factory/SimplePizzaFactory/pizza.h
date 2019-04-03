#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <list>

class Pizza
{
public:
    virtual ~Pizza() = default;
    virtual void prepare();
    virtual void bake();
    virtual void cut();
    virtual void box();
    std::string name();

protected:
    std::string _name;
    std::string _dough;
    std::string _sauce;
    std::list<std::string> _toppings;
};

class CheesePizza:public Pizza
{
public:
    CheesePizza();
};

class VeggiePizza:public Pizza
{
public:
    VeggiePizza();
};

class ClamPizza:public Pizza
{
public:
    ClamPizza();
};

class PepperoniPizza:public Pizza
{
public:
    PepperoniPizza();
};

#endif // PIZZA_H

