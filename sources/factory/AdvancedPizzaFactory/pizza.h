#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <list>

// Abstract pizza class
class Pizza
{
public:
    void prepare();
    void bake();
    void cut();
    void box();
    std::string name();

protected:
    std::string _name;
    std::string _dough;
    std::string _sauce;
    std::list<std::string> _toppings;
};

// NY style pizza
class NYStyleCheesePizza:public Pizza
{
public:
    NYStyleCheesePizza();
};

class NYStyleVeggiePizza:public Pizza
{
public:
    NYStyleVeggiePizza();
};

class NYStyleClamPizza:public Pizza
{
public:
    NYStyleClamPizza();
};

class NYStylePepperoniPizza:public Pizza
{
public:
    NYStylePepperoniPizza();
};

// Chickago style pizza
class ChicagoStyleCheesePizza:public Pizza
{
public:
    ChicagoStyleCheesePizza();
};

class ChicagoStylePepperoniPizza:public Pizza
{
public:
    ChicagoStylePepperoniPizza();
};

class ChicagoStyleClamPizza:public Pizza
{
public:
    ChicagoStyleClamPizza();
};

class ChicagoStyleVeggiePizza:public Pizza
{
public:
    ChicagoStyleVeggiePizza();
};

#endif // PIZZA_H

