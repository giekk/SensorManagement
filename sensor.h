#ifndef SENSOR_H
#define SENSOR_H

#include <string>

#include "IVisitor.h"

class Sensor 
{
private:
    std::string name;
    std::string id;
    std::string type;
    int reliability;
public:
    Sensor();

    Sensor(
        const std::string& _name,
        const std::string& _id, 
        const std::string& _type, 
        const int& _reliability
    );
    
    virtual ~Sensor() = default;

    virtual void accept(IVisitor& visitor) = 0;

    void setName(const std::string& _name);
    void setId(const std::string& _id);
    void setType(const std::string& _type);
    void setReliability(const unsigned int& _reliability);

    virtual void setMinimum(const int& _minimum) = 0;
    virtual void setMaximum(const int& _maximum) = 0;
    virtual void setAverage(const int& _average) = 0;

    std::string getName() const;
    std::string getId() const;
    std::string getType() const;
    int getReliability() const;

    virtual int getMinimum() const = 0;
    virtual int getMaximum() const = 0;
    virtual int getAverage() const = 0;
};

#endif