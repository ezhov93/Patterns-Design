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

NYStylePepperoniPizza::NYStylePepperoniPizza()
{
    _name = "NY Style Sauce and Pepperomi Pizza";
    _dough = "Thin Crust Dough";
    _sauce = "ketchup";
    _toppings.push_back("Grated");
    _toppings.push_back("Reggiano");
    _toppings.push_back("Cheese”");
}

NYStyleCheesePizza::NYStyleCheesePizza()
{
    _name = "NY Style Sauce and Cheese Pizza";
    _dough = "Thin Crust Dough";
    _sauce = "Marinara Sauce";
    _toppings.push_back("Grated");
    _toppings.push_back("Reggiano");
    _toppings.push_back("Cheese”");
}

NYStyleClamPizza::NYStyleClamPizza()
{
    _name = "Clam Pizza";
    _dough = "thick";
    _sauce = "mayonnaise";
    _toppings.push_back("chesse");
    _toppings.push_back("clam");
    _toppings.push_back("shrimp");
}

NYStyleVeggiePizza::NYStyleVeggiePizza()
{
    _name = "Pepperoni Pizza";
    _dough = "thin";
    _sauce = "ketchup, mayonnaise";
    _toppings.push_back("pepperoni");
    _toppings.push_back("chesse");
    _toppings.push_back("tomatoes");
}

ChicagoStyleCheesePizza::ChicagoStyleCheesePizza()
{
    _name = "Cheese Pizza";
    _dough = "thick";
    _sauce = "ketchup";
    _toppings.push_back("Grated");
    _toppings.push_back("Reggiano");
    _toppings.push_back("Cheese”");
}

ChicagoStylePepperoniPizza::ChicagoStylePepperoniPizza()
{
    _name = "NY Style Sauce and Cheese Pizza";
    _dough = "Thin Crust Dough";
    _sauce = "Marinara Sauce";
    _toppings.push_back("Grated");
    _toppings.push_back("Reggiano");
    _toppings.push_back("Cheese”");
}

ChicagoStyleClamPizza::ChicagoStyleClamPizza()
{
    _name = "Clam Pizza";
    _dough = "thick";
    _sauce = "mayonnaise";
    _toppings.push_back("chesse");
    _toppings.push_back("clam");
    _toppings.push_back("shrimp");
}

ChicagoStyleVeggiePizza::ChicagoStyleVeggiePizza()
{
    _name = "Pepperoni Pizza";
    _dough = "thin";
    _sauce = "ketchup, mayonnaise";
    _toppings.push_back("pepperoni");
    _toppings.push_back("chesse");
    _toppings.push_back("tomatoes");
}
