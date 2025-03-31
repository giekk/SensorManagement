#include "temperature.h"

Temperature::Temperature() : Sensor(), minimum(0), maximum(0), average(0) {
}

Temperature::Temperature(
    const std::string& _name,
    const std::string& _id
) : 
    Sensor(_name, _id, "Temperatura", 70), minimum(0), maximum(0), average(0)
{}

Temperature::Temperature(
    const std::string& _name,
    const std::string& _id,
    const int& _minimum, 
    const int& _maximum, 
    const int& _average
) :
    Sensor(_name, _id, "Temperatura", 70), minimum(_minimum), maximum(_maximum), average(_average)
{}

Temperature::Temperature(const Temperature& sensor)
    :   Sensor(sensor.getName(), sensor.getId(), "Temperatura", 70),
        minimum(sensor.minimum), maximum(sensor.maximum), average(sensor.average)
{}

void Temperature::accept(IVisitor& visitor) 
{
    visitor.visitTemperature(*this);
}

void Temperature::setMinimum(const int& _minimum) 
{
    this->minimum = _minimum;
}

void Temperature::setMaximum(const int& _maximum) 
{
    this->maximum = _maximum;
}

void Temperature::setAverage(const int& _average)
{
    this->average = _average;
}

int Temperature::getMinimum() const {
    return this->minimum;
}

int Temperature::getMaximum() const {
    return this->maximum;
}

int Temperature::getAverage() const {
    return this->average;
}