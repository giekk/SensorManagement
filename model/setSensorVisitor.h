#ifndef SETSENSORVISITOR_H
#define SETSENSORVISITOR_H

#include "IVisitor.h"
#include "dataManagement.h"

class SetSensorVisitor : public IVisitor
{
private:
    DataManagement& model;
    int month;
    int year;

    int minimum;
    int maximum;
    int average;
public:
    SetSensorVisitor(DataManagement& model, const int& month, const int& year);
   
    virtual void visitTemperature(Temperature& sensor);
    virtual void visitMicrodust(Microdust& sensor);
    virtual void visitHumidity(Humidity& sensor);

    int getMinimum() const;
    int getMaximum() const;
    int getAverage() const;
};

#endif