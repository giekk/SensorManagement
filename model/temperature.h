#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "sensor.h"

class Temperature : public Sensor
{
private:
    int minimum;
    int maximum;
    int average;
public:
    Temperature();

    Temperature(           //costruttore per info base
        const std::string& _name,
        const std::string& _id
    );

    Temperature(
        const std::string& _name,
        const std::string& _id,
        const int& _minimum, 
        const int& _maximum, 
        const int& _average
    );

    Temperature(const Temperature& sensor);

    void setMinimum(const int& _minimum) override;
    void setMaximum(const int& _maximum) override;
    void setAverage(const int& _average) override;

    virtual void accept(IVisitor& visitor);

    int getMinimum() const;
    int getMaximum() const;
    int getAverage() const;
};

#endif