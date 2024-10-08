#ifndef TIRE_H
#define TIRE_H

#include <string>
#include <fstream>
#include <iostream>

class Tire {
private:
    std::string tireType;
    int size;

public:
    Tire(const std::string& type, int size) ;
    void setTireType(const std::string& type);
    void setSize(int size);
    void print() const;
    void save() const;
};

#endif // TIRE_H
