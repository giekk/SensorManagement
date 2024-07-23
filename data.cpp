#include "data.h"

Data::Data() : date(QDate::currentDate()), temperature(0), humidity(0), microdust(0) {
}

Data::Data(
    const QDate& _date,
    const int& _temperature,
    const int& _humidity,
    const int& _microdust
) :
    date(_date), temperature(_temperature), humidity(_humidity), microdust(_microdust)
{}

Data::Data(const Data& _data) :
    date(_data.date), temperature(_data.temperature), humidity(_data.humidity), microdust(_data.microdust)
{}

const QDate& Data::getDate() const {
    return this->date;
}

int Data::getTemperature() const {
    return this->temperature;
}

int Data::getHumidity() const {
    return this->humidity;
}

int Data::getMicrodust() const {
    return this->microdust;
}

void Data::setDate(const QDate& _date) {
    this->date = _date;
}

void Data::setTemperature(const int& _temperature) {
    this->temperature = _temperature;
}

void Data::setHumidity(const int& _humidity) {
    this->humidity = _humidity;
}

void Data::setMicrodust(const int& _microdust) {
    this->microdust = _microdust;
}