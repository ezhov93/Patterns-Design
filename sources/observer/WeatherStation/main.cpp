#include <iostream>
#include "view.h"

using namespace std;

int main()
{
    WeatherData weatherData;
    CurrentConditionsDisplay current(weatherData);
    StatisticDisplay statistic(weatherData);

    weatherData.setMeasurements(80, 65, 30.4);
    weatherData.setMeasurements(82, 70, 29.2);
    weatherData.setMeasurements(78, 90, 29.2);

    system("pause");
    return 0;
}
