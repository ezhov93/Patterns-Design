#ifndef COFFEE_H
#define COFFEE_H

#include "caffeinebeverage.h"
#include <algorithm>

class Coffee: public CaffeineBeverage{
protected:
  virtual void brew() const final{
    std::cout<<"Dripping Coffee through filter"<<std::endl;
  }
  virtual void addCondiments() const final {
    std::cout<<"Adding Sugar and Milk"<<std::endl;
  }
public:
  virtual bool customerCondiments() const final {
    std::string answer = getUserInput();
    std::transform(answer.begin(), answer.end(), answer.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    return (answer.find("y")!=std::string::npos) ? true : false;
  }

private:
  std::string getUserInput() const {
    std::string answer;
    std::cout<<"Would you like milk and sugar with your coffee (y/n)? ";
    std::cin>>answer;
    return answer;
  }

};

#endif // COFFEE_H
