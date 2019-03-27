#include "model.h"
#include <algorithm>

WeatherData::WeatherData() {
    observers = new vector<IObserver*>;
}

WeatherData::~WeatherData() {
    delete observers;
}

void WeatherData::registerObserver(IObserver &obj) {
    observers->push_back(&obj);
}

void WeatherData::removeObserver(IObserver &obj) {    
    auto it = find(observers->begin(), observers->end(), &obj);
    int i = distance(observers->begin(), it);
    if (i>=0 && i!=static_cast<int>(observers->size()))
        observers->erase(it);
}

void WeatherData::notifyObserver() {
    for (size_t i=0; i<observers->size(); ++i)
        observers->at(i)->update(temperature, humidity, pressure);
}

void WeatherData::measurementChanged() {
    notifyObserver();
}

void WeatherData::setMeasurements(double temperature, double humidity, double pressure) {
    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    measurementChanged();
}

