#include "Tire.h"
#include <iostream>
#include <fstream>

Tire::Tire(const std::string& type, int size) : tireType(type), size(size) {}

void Tire::setTireType(const std::string& type) {
    tireType = type;
}

void Tire::setSize(int size) {
    this->size = size;
}

void Tire::print() const {
    std::cout << "轮胎型号: " << tireType << ", 尺寸: " << size << "mm" << std::endl;
}

void Tire::save() const {
    std::ofstream ofs("../data/" + tireType + "_tire.txt");
    ofs << "轮胎型号: " << tireType << std::endl;
    ofs << "尺寸: " << size << "mm" << std::endl;
}
