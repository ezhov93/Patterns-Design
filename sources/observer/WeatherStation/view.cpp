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
    (void)(pressure); // Q_UNUSE
    this->temperature = temperature;
    this->humidity = humidity;
    display();
}

void CurrentConditionsDisplay::display() {
    cout<<"Current conditions: "<<temperature<<"C deg and "<<humidity<<"% humidity"<<endl;
}

StatisticDisplay::StatisticDisplay(ISubject &weatherData) {
    this->weatherData = &weatherData;
    this->weatherData->registerObserver(*this);
}

StatisticDisplay::~StatisticDisplay() {
    delete weatherData;
}

void StatisticDisplay::update(double temperature, double humidity, double pressure) {
    (void)(pressure); // Q_UNUSE
    (void)(humidity); // Q_UNUSE
    avg = temperature;
    list.push_back(temperature);
    if (initialize) {
        // Avg
        avg = 0;
        for(auto it:list)
            avg+=it;
        avg /=list.size();
        // Max
        if (temperature>max)
            max = temperature;
        // Min
        if (temperature<min)
            min = temperature;
    }
    else {
        avg = max = min = temperature;
        initialize = true;
    }
    display();
}

void StatisticDisplay::display(){
    cout<<"Avg/Max/Min temperature =  "
       <<avg<<"/"<<max<<"/"<<min<<endl;
}
