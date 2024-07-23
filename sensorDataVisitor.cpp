#include "sensorDataVisitor.h"

int SensorDataVisitor::getMin()
{
    return this->min;
}

int SensorDataVisitor::getMax()
{
    return this->max;
}

int SensorDataVisitor::getAvg()
{
    return this->avg;
}

void SensorDataVisitor::visitTemperature(Temperature& temperature)
{
    this->min = temperature.getMinimum();
    this->max = temperature.getMaximum();
    this->avg = temperature.getAverage();
}

void SensorDataVisitor::visitHumidity(Humidity& humidity)
{
    this->min = humidity.getMinimum();
    this->max = humidity.getMaximum();
    this->avg = humidity.getAverage();
}

void SensorDataVisitor::visitMicrodust(Microdust& microdust)
{
    this->min = microdust.getMinimum();
    this->max = microdust.getMaximum();
    this->avg = microdust.getAverage();
}