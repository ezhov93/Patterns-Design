#include <iostream>
#include "pizzastore.h"

int main()
{
    PizzaStore store1(new SimplePizzaFactory());
    store1.orderPizza("cheese");
    std::cout<<std::endl;

    PizzaStore store2(new SimplePizzaFactory());
    store1.orderPizza("pepperoni");
    std::cout<<std::endl;

    PizzaStore store3(new SimplePizzaFactory());
    store1.orderPizza("clam");
    std::cout<<std::endl;

    return 0;
}
