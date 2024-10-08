#include "IMU.h"
#include <iostream>
#include <fstream>

IMU::IMU(const std::string& model, const std::string& manufacturer)
    : model(model), manufacturer(manufacturer) {}

void IMU::setModel(const std::string& model) {
    this->model = model;
}

void IMU::print() const {
    std::cout << "9轴陀螺仪型号: " << model << std::endl;
    std::cout << "厂家: " << manufacturer << std::endl;
}

void IMU::save() const {
    std::ofstream ofs("../data/" + model + "_imu.txt");
    ofs << "9轴陀螺仪型号: " << model << std::endl;
    ofs << "厂家: " << manufacturer << std::endl;
}
