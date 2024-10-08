#ifndef BATTERY_H
#define BATTERY_H

#include <string>
#include <fstream>
#include <iostream>

class Battery {
private:
    std::string parameters;
    std::string externalPower;
    int chargingTime;

public:
    Battery(const std::string& parameters, const std::string& externalPower, int chargingTime);
    void setParameters(const std::string& parameters);
    void print() const;
    void save() const;
};

#endif // BATTERY_H
