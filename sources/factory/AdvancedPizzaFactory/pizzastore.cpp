#include "pizzastore.h"

using namespace std;

Pizza* PizzaStore::orderPizza(string type)
{
    Pizza &pizza = *createPizza(type);

    pizza.prepare();
    pizza.bake();
    pizza.cut();
    pizza.box();

    return &pizza;
}

Pizza* NYStylePizzaStore::createPizza(string type)
{
    Pizza *pizza = nullptr;
    if (type == "cheese") {
        pizza = new NYStyleCheesePizza;
    } else if (type == "pepperoni") {
        pizza = new NYStylePepperoniPizza;
    } else if (type == "clam") {
        pizza = new NYStyleClamPizza;
    } else if (type == "veggie") {
        pizza = new NYStyleVeggiePizza;
    }
    return pizza;
}

Pizza* ChicagoStylePizzaStore::createPizza(string type)
{
    Pizza *pizza = nullptr;
    if (type == "cheese") {
        pizza = new ChicagoStyleCheesePizza;
    } else if (type == "pepperoni") {
        pizza = new ChicagoStylePepperoniPizza;
    } else if (type == "clam") {
        pizza = new ChicagoStyleClamPizza;
    } else if (type == "veggie") {
        pizza = new ChicagoStyleVeggiePizza;
    }
    return pizza;
}
