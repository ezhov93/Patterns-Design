#include <iostream>
#include <memory>
#include "wildturkey.h"
#include "mallardduck.h"
#include "turkeyadapter.h"

static void testDuck(Duck &duck);

int main() {
  std::unique_ptr<MallardDuck> duck(new MallardDuck);
  //  std::unique_ptr<WildTurkey> turkey(new WildTurkey);
  //  std::unique_ptr<Duck> turkeyAdapter(new TurkeyAdapter(turkey.get()));

  std::shared_ptr<WildTurkey> turkey(new WildTurkey);
  auto turkeyAdapter = std::make_shared<TurkeyAdapter>(turkey);
  std::cout<<"The Turkey says..."<<std::endl;
  turkey.get()->gobble();
  turkey.get()->fly();
  std::cout<<"\nThe Duck says..."<<std::endl;
  testDuck(*duck);
  duck.reset();
  std::cout<<"\nThe TurkeyAdapter says..."<<std::endl;
  testDuck(*turkeyAdapter);

  return 0;
}

static void testDuck(Duck &duck) {
  duck.quack();
  duck.fly();
}
