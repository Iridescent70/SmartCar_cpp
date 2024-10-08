#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <fstream>
#include <iostream>

class Camera {
private:
    std::string model;        // 型号
    std::string cameraID;     // 摄像头ID
    std::string rgbResolution; // RGB帧分辨率
    int rgbFrameRate;         // RGB帧率
    std::string fov;          // 视场角
    int depthFrameRate;       // 深度帧率

public:
    // 构造函数
    Camera(const std::string& model, const std::string& cameraID, const std::string& rgbResolution,
           int rgbFrameRate, const std::string& fov, int depthFrameRate);

    void setModel(const std::string& model); // 设置型号
    void print() const;                       // 打印信息
    void save() const;                        // 保存信息
};

#endif // CAMERA_H
