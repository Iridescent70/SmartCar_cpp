#include "SmartCar.h"
#include <iostream>
#include <fstream>

SmartCar::SmartCar(const std::string& id, const Chassis& ch, const AGXModule& agx, const Camera& cam,
                   const Lidar& lidar, const IMU& imu, const Display& display, const Battery& battery,
                   const Student& student)
    : carID(id), chassis(ch), agxModule(agx), camera(cam), lidar(lidar), imu(imu), display(display), battery(battery), assignedStudent(student) {}

void SmartCar::setID(const std::string& id) {
    carID = id; // 设置小车编号
}

void SmartCar::print() const {
    std::cout << "智能小车编号: " << carID << std::endl;
    chassis.print(); // 打印底盘信息
    agxModule.print(); // 打印AGX模块信息
    camera.print(); // 打印摄像头信息
    lidar.print(); // 打印激光雷达信息
    imu.print(); // 打印陀螺仪信息
    display.print(); // 打印显示器信息
    battery.print(); // 打印电池信息
    assignedStudent.print(); // 打印分配的学生信息
}

void SmartCar::save() const {
    std::ofstream ofs("../data/" + carID + ".txt");
    if (!ofs) {
        std::cerr << "无法打开文件进行写入: " << "../data/" + carID + ".txt" << std::endl;
        return;
    }
    ofs << "智能小车编号: " << carID << std::endl;
    chassis.save(); // 保存底盘信息
    agxModule.save(); // 保存AGX模块信息
    camera.save(); // 保存摄像头信息
    lidar.save(); // 保存激光雷达信息
    imu.save(); // 保存陀螺仪信息
    display.save(); // 保存显示器信息
    battery.save(); // 保存电池信息
    assignedStudent.save(); // 保存分配的学生信息
}
