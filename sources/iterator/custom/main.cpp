#include <iostream>
#include "iterators.h"

int main()
{
  DinerMenu menu1;
  MyIterator<MenuItem> *it1;
  it1 = menu1.createIterator();
  while(it1->hasNext()) {
    std::cout<<it1->next().getName()<<std::endl;
  }


  PancakeHouseMenu menu2;
  PancakeHouseMenuIterator it2(&menu2);

  return 0;
}
