#ifndef IMU_H
#define IMU_H

#include <string>
#include <fstream>
#include <iostream>

class IMU {
private:
    std::string model;
    std::string manufacturer;

public:
    IMU(const std::string& model, const std::string& manufacturer);
    void setModel(const std::string& model);
    void print() const;
    void save() const;
};

#endif // IMU_H
