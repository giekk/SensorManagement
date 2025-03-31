#include "humidity.h"

Humidity::Humidity() : Sensor::Sensor(), minimum(0), maximum(0), average(0) 
{}

Humidity::Humidity(
    const std::string& _name,
    const std::string& _id
) : 
    Sensor(_name, _id, "Umidità", 85), minimum(0), maximum(0), average(0)
{}

Humidity::Humidity(
    const std::string& _name,
    const std::string& _id,
    const int& _minimum, 
    const int& _maximum, 
    const int& _average
) :
    Sensor(_name, _id, "Umidità", 85), minimum(_minimum), maximum(_maximum), average(_average)
{}

Humidity::Humidity(const Humidity& sensor)
    :   Sensor(sensor.getName(), sensor.getId(), "Umidità", 85),
        minimum(sensor.minimum), maximum(sensor.maximum), average(sensor.average)
{}

void Humidity::accept(IVisitor& visitor)
{
    visitor.visitHumidity(*this);
}

void Humidity::setMinimum(const int& _minimum) 
{
    this->minimum = _minimum;
}

void Humidity::setMaximum(const int& _maximum) 
{
    this->maximum = _maximum;
}

void Humidity::setAverage(const int& _average) 
{
    this->average = _average;
}

int Humidity::getMinimum() const {
    return minimum;
}

int Humidity::getMaximum() const {
    return maximum;
}

int Humidity::getAverage() const {
    return average;
}