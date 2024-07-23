#include "dataChart.h"

DataChart::DataChart(const int& month, const int& year) 
{
    this->days = this->getDaysInMonth(month, year);
    this->temperatures = this->monthTemperatures(month, year);
    this->humidities = this->monthHumidities(month, year);
    this->microdusts = this->monthMicrodusts(month, year);
}

void DataChart::updateData(const int& month, const int& year)
{
    this->days = this->getDaysInMonth(month, year);
    this->temperatures.clear();
    this->temperatures = this->monthTemperatures(month, year);
    this->humidities.clear();
    this->humidities = this->monthHumidities(month, year);
    this->microdusts.clear();
    this->microdusts = this->monthMicrodusts(month, year);
}

int DataChart::getDays() const
{
    return this->days;
}

std::vector<int> DataChart::getTemperatures() const
{
    std::vector<int> temp;
    for (auto it = this->temperatures.begin(); it != this->temperatures.end(); ++it)
    {
        temp.push_back(*it);
    }
    return temp;
}

std::vector<int> DataChart::getHumidities() const
{
    std::vector<int> hum;
    for (auto it = this->humidities.begin(); it != this->humidities.end(); ++it)
    {
        hum.push_back(*it);
    }
    return hum;
}

std::vector<int> DataChart::getMicrodusts() const
{
    std::vector<int> micro;
    for (auto it = this->microdusts.begin(); it != this->microdusts.end(); ++it)
    {
        micro.push_back(*it);
    }
    return micro;
}


