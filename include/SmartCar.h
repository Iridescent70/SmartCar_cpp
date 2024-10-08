#ifndef SMARTCAR_H
#define SMARTCAR_H

#include "Chassis.h"
#include "Tire.h"
#include "AGXModule.h"
#include "Camera.h"
#include "IMU.h"
#include "Lidar.h"
#include "Display.h"
#include "Battery.h"
#include "Student.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class SmartCar {
public:
    std::string carID; // 小车编号
    Chassis chassis; // 底盘信息
    AGXModule agxModule; // AGX模块
    Camera camera; // 摄像头
    IMU imu; // 陀螺仪
    Lidar lidar; // 激光雷达
    Display display; // 显示器
    Battery battery; // 电池
    Student assignedStudent; // 分配的学生

public:
    // 构造函数，接受小车编号和各个模块的实例
    SmartCar(const std::string& id, const Chassis& ch, const AGXModule& agx, const Camera& cam,
             const Lidar& lidar, const IMU& imu, const Display& display, const Battery& battery, const Student& student);
    
    void setID(const std::string& id); // 设置小车编号
    void print() const; // 打印小车信息
    void save() const; // 保存小车信息
    void assignStudent(const Student& student); // 分配学生
};

#endif // SMARTCAR_H
