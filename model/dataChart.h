#ifndef DATACHART_H
#define DATACHART_H

#include <vector>

#include "dataManagement.h"

class DataChart : public DataManagement
{
private:
    int days;
    std::vector<int> temperatures;
    std::vector<int> humidities;
    std::vector<int> microdusts;

public:
    explicit DataChart(const int& month, const int& year);

    void updateData(const int& month, const int& year);

    int getDays() const;
    std::vector<int> getTemperatures() const;
    std::vector<int> getHumidities() const;
    std::vector<int> getMicrodusts() const;
};

#endif