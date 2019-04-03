#include "pizza.h"

#include <iostream>

using namespace std;

void Pizza::prepare()
{
    cout<<"Preparing "<<_name<<endl;
    cout<<"Tossing dough..."<<endl;
    cout<<"Adding sauce..."<<endl;
    cout<<"Adding toppings: "<<endl;
    for (auto topping:_toppings)
        cout<<"   "<<topping<<endl;
}

void Pizza::bake()
{
    cout<<"Bake for 25 minutes at 350"<<endl;
}

void Pizza::cut()
{
    cout<<"Cutting the pizza into diagonal slices"<<endl;
}

void Pizza::box()
{
    cout<<"Place pizza in official PizzaStore box"<<endl;
}

std::string Pizza::name()
{
    return _name;
}

CheesePizza::CheesePizza()
{
    _name = "Cheese Pizza";
    _dough = "thick";
    _sauce = "ketchup";
    _toppings.push_back("chesse");
}

VeggiePizza::VeggiePizza()
{
    _name = "Veggie Pizza";
    _dough = "thin";
    _sauce = "mustard";
    _toppings.push_back("chesse");
    _toppings.push_back("broccoli");
    _toppings.push_back("tomatoes");
}

ClamPizza::ClamPizza()
{
    _name = "Clam Pizza";
    _dough = "thick";
    _sauce = "mayonnaise";
    _toppings.push_back("chesse");
    _toppings.push_back("clam");
    _toppings.push_back("shrimp");
}

PepperoniPizza::PepperoniPizza()
{
    _name = "Pepperoni Pizza";
    _dough = "thin";
    _sauce = "ketchup, mayonnaise";
    _toppings.push_back("pepperoni");
    _toppings.push_back("chesse");
    _toppings.push_back("tomatoes");
}
