#include "duck.h"

#include <iostream>

using namespace std;

void IFly::fly() {
    cout<<"I'm flying"<<endl;
}

void FlyWithWings::fly() {
    cout<<"I can fly"<<endl;
}

void FlyNoWay::fly() {
    cout<<"I can't fly"<<endl;
}

void Quack::quack() {
    cout<<"Quack"<<endl;
}

void MuteQuack::quack() {
    cout<<"<< Silence >>"<<endl;
}

void Squeak::quack() {
    cout<<"Squeak"<<endl;
}

Duck::~Duck() {
    if (iFly != nullptr)
        delete iFly;
    if (iQuack != nullptr)
        delete iQuack;
}

void Duck::fly() {
    iFly->fly();
}

void Duck::quack() {
    iQuack->quack();
}

void Duck::swim() {
    cout<<"All ducks float. even decoys!"<<endl;
}

MallardDuck::MallardDuck() {
    iFly = new FlyWithWings;
    iQuack = new Quack;
    cout<<"Create Mallar"<<endl;
}

void MallardDuck::display() {
    cout<<"I am Mallard Duck!"<<endl;
}

TransformDuck::TransformDuck() {
    iFly = new FlyNoWay;
    iQuack = new MuteQuack;
    cout<<"Create Mallar"<<endl;
}

void TransformDuck::display() {
    cout<<"I am Transformer Duck!"<<endl;
}


void TransformDuck::setFlyInterface(IFly *iFly) {
    this->iFly = iFly;
}

void TransformDuck::setQuackInterface(IQuack *iQuack) {
    this->iQuack = iQuack;
}
