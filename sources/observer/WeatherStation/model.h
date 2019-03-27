#ifndef MODEL_H
#define MODEL_H

#include <vector>

using namespace std;

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(double temp, double humidity, double pressure) = 0;
};

class ISubject  {
public:
    virtual ~ISubject() = default;
    virtual void registerObserver(IObserver &obj) = 0;
    virtual void removeObserver(IObserver &obj) = 0;
    virtual void notifyObserver() = 0;
};

class WeatherData:public ISubject {
private:
    vector<IObserver*> *observers;
    double temperature = 0;
    double humidity = 0;
    double pressure = 0;
public:
    explicit WeatherData();
    virtual ~WeatherData() override;
    virtual void registerObserver(IObserver &obj) override;
    virtual void removeObserver(IObserver &obj) override;
    virtual void notifyObserver() override;
    void measurementChanged();
    void setMeasurements(double temperature, double humidity, double pressure);
};

#endif // MODEL_H
