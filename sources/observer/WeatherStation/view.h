#ifndef VIEW_H
#define VIEW_H

#include "model.h"
#include <list>

class IDisplayElement {
public:
    virtual ~IDisplayElement() = default;
    virtual void display() = 0;
};

class CurrentConditionsDisplay: public IObserver, public IDisplayElement {
public:
    CurrentConditionsDisplay(ISubject &weatherData);
    virtual ~CurrentConditionsDisplay() override;
    virtual void update(double temperature, double humidity, double pressure) override;
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
    virtual void update(double temperature, double humidity, double pressure) override;
    virtual void display() override;
private:
    std::list<double> list;
    double avg = 0;
    double max = 0;
    double min = 0;
    bool initialize = false;
    ISubject *weatherData;
};


#endif // VIEW_H
