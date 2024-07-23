#include "microdust.h"

Microdust::Microdust() : Sensor(), minimum(0), maximum(0), average(0) {
}

Microdust::Microdust(
    const std::string& _name,
    const std::string& _id
) : 
    Sensor(_name, _id, "Micropolveri", 60), minimum(0), maximum(0), average(0)
{}

Microdust::Microdust(
    const std::string& _name,
    const std::string& _id,
    const int& _minimum, 
    const int& _maximum, 
    const int& _average
) :
    Sensor(_name, _id, "Micropolveri", 60), 
    minimum(_minimum), maximum(_maximum), average(_average)
{}

Microdust::Microdust(const Microdust& sensor)
    :   Sensor(sensor.getName(), sensor.getId(), "Micropolveri", 60),
        minimum(sensor.minimum), maximum(sensor.maximum), average(sensor.average)
{}

void Microdust::accept(IVisitor& visitor)
{
    visitor.visitMicrodust(*this);
}

void Microdust::setMinimum(const int& _minimum)
{
    this->minimum = _minimum;
}

void Microdust::setMaximum(const int& _maximum)
{
    this->maximum = _maximum;
}

void Microdust::setAverage(const int& _average)
{
    this->average = _average;
}

int Microdust::getMinimum() const 
{
    return this->minimum;
}

int Microdust::getMaximum() const
{
    return this->maximum;
}

int Microdust::getAverage() const
{
    return this->average;
}