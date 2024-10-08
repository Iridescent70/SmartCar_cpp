#ifndef LIDAR_H
#define LIDAR_H

#include <string>
#include <fstream>
#include <iostream>

class Lidar {
private:
    std::string model;          // 型号
    int channels;               // 通道数
    int testRange;              // 测试范围
    int powerConsumption;       // 功耗

public:
    // 构造函数
    Lidar(const std::string& model, int channels, int testRange, int powerConsumption);

    void setModel(const std::string& model); // 设置型号
    void print() const;                       // 打印信息
    void save() const;                        // 保存信息
};

#endif // LIDAR_H
