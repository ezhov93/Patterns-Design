#include "tea.h"
#include "coffee.h"

int main()
{
  Tea tea;
  Coffee coffeeHook;

  std::cout<<"\nMaking tea..."<<std::endl;
  tea.prepareRecipe();

  std::cout<<"\nMaking coffee..."<<std::endl;
  coffeeHook.prepareRecipe();
  return 0;
}
