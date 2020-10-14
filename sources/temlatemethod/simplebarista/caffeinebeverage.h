#ifndef CAFFEINEBEVERAGE_H
#define CAFFEINEBEVERAGE_H

#include <iostream>

class CaffeineBeverage {
public:
  virtual ~CaffeineBeverage() = default;
  void prepareRecipe() {
    boilWater();
    brew();
    pourInCup();
    if (customerCondiments()) addCondiments();
  }
protected:
  virtual void brew() const = 0;
  virtual void addCondiments() const = 0;
  void boilWater() const { std::cout<<"Boiling water"<<std::endl; }
  void pourInCup() const { std::cout<<"Pouring into cup"<<std::endl; }
  // перехватчик
  bool virtual customerCondiments() const { return true; }
};

#endif // CAFFEINEBEVERAGE_H
