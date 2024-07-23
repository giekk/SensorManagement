#include "sensorInfoVisitor.h"

QLabel* SensorInfoVisitor::getLabel_1()
{
    return this->label_1;
}

QLabel* SensorInfoVisitor::getLabel_2()
{
    return this->label_2;
}

QLabel* SensorInfoVisitor::getLabel_3()
{
    return this->label_3;
}

void SensorInfoVisitor::visitTemperature(Temperature& sensor)
{
    this->label_1 = new QLabel("Temperatura minima: " + QString::number(sensor.getMinimum()) + "°C");
    this->label_2 = new QLabel("Temperatura massima: " + QString::number(sensor.getMaximum()) + "°C");
    this->label_3 = new QLabel("Temperatura media: " + QString::number(sensor.getAverage()) + "°C");
}

void SensorInfoVisitor::visitHumidity(Humidity& sensor)
{
    this->label_1 = new QLabel("Umidità minima: " + QString::number(sensor.getMinimum()) + "%");
    this->label_2 = new QLabel("Umidità massima: " + QString::number(sensor.getMaximum()) + "%");
    this->label_3 = new QLabel("Umidità media: " + QString::number(sensor.getAverage()) + "%");
}

void SensorInfoVisitor::visitMicrodust(Microdust& sensor)
{
    this->label_1 = new QLabel("Percentuale minima polveri: " + QString::number(sensor.getMinimum()) + "%");
    this->label_2 = new QLabel("Percentuale massima polveri: " + QString::number(sensor.getMaximum()) + "%");
    this->label_3 = new QLabel("Percentuale media polveri: " + QString::number(sensor.getAverage()) + "%");
}