#include "Lidar.h"
#include <iostream>
#include <fstream>

Lidar::Lidar(const std::string& model, int channels, int testRange, int powerConsumption)
    : model(model), channels(channels), testRange(testRange), powerConsumption(powerConsumption) {}

void Lidar::setModel(const std::string& model) {
    this->model = model;
}

void Lidar::print() const {
    std::cout << "多线激光雷达型号: " << model << std::endl;
    std::cout << "通道数: " << channels << std::endl;
    std::cout << "测试范围: " << testRange << "m" << std::endl;
    std::cout << "功耗: " << powerConsumption << "W" << std::endl;
}

void Lidar::save() const {
    std::ofstream ofs("../data/" + model + "_lidar.txt");
    ofs << "多线激光雷达型号: " << model << std::endl;
    ofs << "通道数: " << channels << std::endl;
    ofs << "测试范围: " << testRange << "m" << std::endl;
    ofs << "功耗: " << powerConsumption << "W" << std::endl;
}
