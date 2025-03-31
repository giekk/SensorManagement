#include "sensorData.h"

SensorData::SensorData() : name(""), id(""), type(""), reliability(0), max(0), min(0), avg(0) 
{}

SensorData::SensorData(
    QString _name,
    QString _id,
    QString _type,
    int _reliability,
    int _max,
    int _min,
    int _avg
) :
    name(_name), id(_id), type(_type), reliability(_reliability), max(_max), min(_min), avg(_avg)
{}

SensorData::SensorData(const SensorData& _sensorData) :
    name(_sensorData.name), id(_sensorData.id), type(_sensorData.type), reliability(_sensorData.reliability), max(_sensorData.max), min(_sensorData.min), avg(_sensorData.avg)
{}

const QString& SensorData::getName() const {
    return this->name;
}

const QString& SensorData::getId() const {
    return this->id;
}

const QString& SensorData::getType() const {
    return this->type;
}

int SensorData::getReliability() const {
    return this->reliability;
}

int SensorData::getMax() const {
    return this->max;
}

int SensorData::getMin() const {
    return this->min;
}

int SensorData::getAvg() const {
    return this->avg;
}

void SensorData::setName(const QString& _name) {
    this->name = _name;
}

void SensorData::setId(const QString& _id) {
    this->id = _id;
}

void SensorData::setType(const QString& _type) {
    this->type = _type;
}

void SensorData::setReliability(const int& _reliability) {
    this->reliability = _reliability;
}

void SensorData::setMax(const int& _max) {
    this->max = _max;
}

void SensorData::setMin(const int& _min) {
    this->min = _min;
}

void SensorData::setAvg(const int& _avg) {
    this->avg = _avg;
}