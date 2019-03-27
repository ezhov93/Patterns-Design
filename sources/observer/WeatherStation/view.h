#ifndef VIEW_H
#define VIEW_H

#include "model.h"

class IDisplayElement {
public:
    virtual ~IDisplayElement() = default;
    virtual void display() = 0;
};

class CurrentConditionsDisplay: public IObserver, public IDisplayElement {
public:
    CurrentConditionsDisplay(ISubject &weatherData);
    virtual ~CurrentConditionsDisplay() override;
    virtual void update(double temp, double humidity, double pressure) override;
    virtual void display() override;
private:
    double temperature = 0;
    double humidity = 0;
    ISubject *weatherData;
};

class StatisticDisplay: public IObserver, public IDisplayElement {
public:
    StatisticDisplay(ISubject &weatherData);
    virtual ~StatisticDisplay() override;
    virtual void update(double temp, double humidity, double pressure) override;
    virtual void display() override;
private:
    double temperature = 0;
    ISubject *weatherData;
};


#endif // VIEW_H
