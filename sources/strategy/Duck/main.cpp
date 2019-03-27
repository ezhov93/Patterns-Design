#include <iostream>
#include "duck.h"

using namespace std;

int main()
{
    MallardDuck mallar;
    mallar.display();
    mallar.fly();
    mallar.quack();
    cout<<endl;

    TransformDuck transformer;
    transformer.display();
    transformer.fly();
    transformer.quack();
    transformer.setFlyInterface(new FlyWithWings);
    transformer.setQuackInterface(new Squeak);
    transformer.fly();
    transformer.quack();
    cout<<endl;

    system("pause");
    return 0;
}
