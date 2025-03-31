#include "sensor.h"

Sensor::Sensor() : name(0), id(0), type(0), reliability(0) {}

Sensor::Sensor(
    const std::string& _name,
    const std::string& _id, 
    const std::string& _type, 
    const int& _reliability
) : 
    name(_name), id(_id), type(_type), reliability(_reliability) {
}

void Sensor::setName(const std::string& _name)
{
    this->name = _name;
}

void Sensor::setId(const std::string& _id)
{
    this->id = _id;
}

void Sensor::setType(const std::string& _type)
{
    this->type = _type;
}

void Sensor::setReliability(const unsigned int& _reliability)
{
    this->reliability = _reliability;
}

std::string Sensor::getName() const 
{
    return this->name;
}

std::string Sensor::getId() const 
{
    return this->id;
}

std::string Sensor::getType() const 
{
    return this->type;
}

int Sensor::getReliability() const 
{
    return this->reliability;
}