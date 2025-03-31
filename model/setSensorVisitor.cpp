#include "setSensorVisitor.h"

SetSensorVisitor::SetSensorVisitor(DataManagement& model, const int& month, const int& year) : model(model), month(month), year(year) 
{}

void SetSensorVisitor::visitTemperature(Temperature& sensor) 
{
    std::vector<int> datas = model.monthTemperatures(this->month, this->year);
    this->minimum = *std::min_element(datas.begin(), datas.end());
    this->maximum = *std::max_element(datas.begin(), datas.end());
    this->average = std::accumulate(datas.begin(), datas.end(), 0) / datas.size();
    sensor.setMinimum(minimum);
    sensor.setMaximum(maximum);
    sensor.setAverage(average);
    datas.clear();
}

void SetSensorVisitor::visitMicrodust(Microdust& sensor) 
{
    std::vector<int> datas = model.monthMicrodusts(this->month, this->year);
    this->minimum = *std::min_element(datas.begin(), datas.end());
    this->maximum = *std::max_element(datas.begin(), datas.end());
    this->average = std::accumulate(datas.begin(), datas.end(), 0) / datas.size();
    sensor.setMinimum(minimum);
    sensor.setMaximum(maximum);
    sensor.setAverage(average);
    datas.clear();
}

void SetSensorVisitor::visitHumidity(Humidity& sensor) 
{
    std::vector<int> datas = model.monthHumidities(this->month, this->year);
    this->minimum = *std::min_element(datas.begin(), datas.end());
    this->maximum = *std::max_element(datas.begin(), datas.end());
    this->average = std::accumulate(datas.begin(), datas.end(), 0) / datas.size();
    sensor.setMinimum(minimum);
    sensor.setMaximum(maximum);
    sensor.setAverage(average);
    datas.clear();
}

int SetSensorVisitor::getMinimum() const 
{
    return this->minimum;
}

int SetSensorVisitor::getMaximum() const 
{
    return this->maximum;
}

int SetSensorVisitor::getAverage() const 
{
    return this->average;
}