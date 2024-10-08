#include "Battery.h"
#include <iostream>
#include <fstream>

Battery::Battery(const std::string& parameters, const std::string& externalPower, int chargingTime)
    : parameters(parameters), externalPower(externalPower), chargingTime(chargingTime) {}

void Battery::setParameters(const std::string& parameters) {
    this->parameters = parameters;
}

void Battery::print() const {
    std::cout << "电池参数: " << parameters << std::endl;
    std::cout << "对外供电: " << externalPower << std::endl;
    std::cout << "充电时长: " << chargingTime << "H" << std::endl;
}

void Battery::save() const {
    std::ofstream ofs("../data/" + parameters + "_battery.txt");
    ofs << "电池参数: " << parameters << std::endl;
    ofs << "对外供电: " << externalPower << std::endl;
    ofs << "充电时长: " << chargingTime << "H" << std::endl;
}
