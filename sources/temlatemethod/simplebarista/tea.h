#ifndef TEA_H
#define TEA_H

#include "caffeinebeverage.h"

class Tea: public CaffeineBeverage {
protected:
  virtual void brew() const final { std::cout<<"Steeping the tea"<<std::endl; }
  virtual void addCondiments() const final{ std::cout<<"Adding Lemon"<<std::endl; }
};

#endif // TEA_H
