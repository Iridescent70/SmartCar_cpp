#ifndef AGXMODULE_H
#define AGXMODULE_H

#include <string>
#include <fstream>
#include <iostream>

class AGXModule {
private:
    std::string model;       // 型号
    int aiPerformance;       // AI性能
    int cudaCores;          // CUDA核心数量
    int tensorCores;        // Tensor核心数量
    int memory;             // 显存
    int storage;            // 存储

public:
    // 构造函数
    AGXModule(const std::string& model, int aiPerformance, int cudaCores, int tensorCores, int memory, int storage);

    void setModel(const std::string& model); // 设置型号
    void print() const;                       // 打印信息
    void save() const;                        // 保存信息
};

#endif // AGXMODULE_H
