#include "view.h"
#include <iostream>

using namespace std;

CurrentConditionsDisplay::CurrentConditionsDisplay(ISubject &weatherData)    {
    this->weatherData = &weatherData;
    this->weatherData->registerObserver(*this);
}

CurrentConditionsDisplay::~CurrentConditionsDisplay() {
    delete weatherData;
}

void CurrentConditionsDisplay::update(double temperature,
                                      double humidity, double pressure) {
    this->temperature = temperature;
    this->humidity = humidity;
    display();
}

void CurrentConditionsDisplay::display() {
    cout<<"Current conditions: "<<temperature<<"C deg and "<<humidity<<"% humidity"<<endl;
}

StatisticDisplay::StatisticDisplay(ISubject &weatherData) {

}
StatisticDisplay::~StatisticDisplay() {

}

void StatisticDisplay::update(double temp, double humidity, double pressure) {

}

void StatisticDisplay::display(){

}
