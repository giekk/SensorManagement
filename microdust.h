#ifndef MICRODUST_H
#define MICRODUST_H

#include "sensor.h"

class Microdust : public Sensor
{
private:
    int minimum;
    int maximum;
    int average;
public:
    Microdust();

    Microdust(
        const std::string& _name,
        const std::string& _id
    );

    Microdust(
        const std::string& _name,
        const std::string& _id,
        const int& _minimum, 
        const int& _maximum, 
        const int& _average
    );

    Microdust(const Microdust& sensor);

    void setMaximum(const int& _maximum) override;
    void setMinimum(const int& _minimum) override;
    void setAverage(const int& _average) override;

    virtual void accept(IVisitor& visitor);

    int getMaximum() const override;
    int getMinimum() const override;
    int getAverage() const override;
};

#endif