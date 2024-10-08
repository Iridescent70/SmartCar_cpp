#include "Chassis.h"
#include <iostream>
#include <fstream>

Chassis::Chassis(const std::string& id, const std::string& model, int wheelbase, int trackWidth,
                 int minGroundClearance, int minTurningRadius, const std::string& driveType, const std::string& maxRange,const Tire& tire)
    : chassisID(id), model(model), wheelbase(wheelbase), trackWidth(trackWidth),
      minGroundClearance(minGroundClearance), minTurningRadius(minTurningRadius),
      driveType(driveType), maxRange(maxRange), tire{tire} {}

void Chassis::setChassisID(const std::string& id) {
    chassisID = id;
}

void Chassis::setModel(const std::string& model) {
    this->model = model;
}

// void Chassis::setTire(int index, const Tire& tire) {
//     if (index >= 0 && index < 4) {
//         tires[index] = tire;
//     }
// }

void Chassis::print() const {
    std::cout << "底盘编号: " << chassisID << std::endl;
    std::cout << "型号: " << model << std::endl;
    std::cout << "轴距: " << wheelbase << "mm" << std::endl;
    std::cout << "轮距: " << trackWidth << "mm" << std::endl;
    std::cout << "最小离地间隙: " << minGroundClearance << "mm" << std::endl;
    std::cout << "最小转弯半径: " << minTurningRadius << "m" << std::endl;
    std::cout << "驱动形式: " << driveType << std::endl;
    std::cout << "最大行程: " << maxRange << std::endl;
    tire.print(); // 打印轮胎信息
}

void Chassis::save() const {
    std::ofstream ofs("../data/" + chassisID + "_chassis.txt");
    ofs << "底盘编号: " << chassisID << std::endl;
    ofs << "型号: " << model << std::endl;
    ofs << "轴距: " << wheelbase << "mm" << std::endl;
    ofs << "轮距: " << trackWidth << "mm" << std::endl;
    ofs << "最小离地间隙: " << minGroundClearance << "mm" << std::endl;
    ofs << "最小转弯半径: " << minTurningRadius << "m" << std::endl;
    ofs << "驱动形式: " << driveType << std::endl;
    ofs << "最大行程: " << maxRange << std::endl;
    tire.save(); // 保存轮胎信息
}
