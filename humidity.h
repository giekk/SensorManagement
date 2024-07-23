#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "sensor.h"

class Humidity : public Sensor
{
private:
    int minimum;
    int maximum;
    int average;
public:
    Humidity();

    Humidity(
        const std::string& _name,
        const std::string& _id
    );
    
    Humidity(
        const std::string& _name,
        const std::string& _id,
        const int& _minimum, 
        const int& _maximum, 
        const int& _average
    );

    Humidity(const Humidity& sensor);

    virtual void accept(IVisitor& visitor);

    void setMinimum(const int& _minimum) override;
    void setMaximum(const int& _maximum) override;
    void setAverage(const int& _average) override;

    int getMinimum() const override;
    int getMaximum() const override;
    int getAverage() const override;
};

#endif