#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include <string>
#include "pizza.h"


class PizzaStore
{
public:
    virtual ~PizzaStore() = default;
    Pizza *orderPizza(std::string type);
private:
    virtual Pizza *createPizza(std::string type) = 0;
};


class NYStylePizzaStore:public PizzaStore
{
    virtual Pizza *createPizza(std::string type) final;
};

class ChicagoStylePizzaStore:public PizzaStore
{
private:
    virtual Pizza *createPizza(std::string type) final;
};
#endif // PIZZASTORE_H
