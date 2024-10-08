#ifndef CHASSIS_H
#define CHASSIS_H

#include <string>
#include <vector>
#include "Tire.h"
#include <fstream>
#include <iostream>

class Chassis {
private:
    std::string chassisID; // 编号
    std::string model;     // 型号
    int wheelbase;         // 轴距
    int trackWidth;        // 轮距
    int minGroundClearance; // 最小离地间隙
    int minTurningRadius;  // 最小转弯半径
    std::string driveType; // 驱动形式
    std::string maxRange;  // 最大行程
    Tire tire; // 轮胎

public:
    Chassis(const std::string& id, const std::string& model, int wheelbase, int trackWidth,
            int minGroundClearance, int minTurningRadius, const std::string& driveType, const std::string& maxRange,const Tire& tire);
    void setChassisID(const std::string& id);
    void setModel(const std::string& model);
    void print() const;
    void save() const;
    // void setTire(int index, const Tire& tire); // 设置轮胎



};

#endif // CHASSIS_H
