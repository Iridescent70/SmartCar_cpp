#include "Camera.h"
#include <iostream>
#include <fstream>

Camera::Camera(const std::string& model, const std::string& cameraID, const std::string& rgbResolution, 
               int rgbFrameRate, const std::string& fov, int depthFrameRate)
    : model(model), cameraID(cameraID), rgbResolution(rgbResolution),
      rgbFrameRate(rgbFrameRate), fov(fov), depthFrameRate(depthFrameRate) {}

void Camera::setModel(const std::string& model) {
    this->model = model;
}

void Camera::print() const {
    std::cout << "双目摄像头型号: " << model << std::endl;
    std::cout << "摄像头: " << cameraID << std::endl;
    std::cout << "RGB帧分辨率: " << rgbResolution << std::endl;
    std::cout << "RGB帧率: " << rgbFrameRate << std::endl;
    std::cout << "FOV: " << fov << std::endl;
    std::cout << "深度帧率: " << depthFrameRate << std::endl;
}

void Camera::save() const {
    std::ofstream ofs("../data/" + model + "_camera.txt");
    ofs << "双目摄像头型号: " << model << std::endl;
    ofs << "摄像头: " << cameraID << std::endl;
    ofs << "RGB帧分辨率: " << rgbResolution << std::endl;
    ofs << "RGB帧率: " << rgbFrameRate << std::endl;
    ofs << "FOV: " << fov << std::endl;
    ofs << "深度帧率: " << depthFrameRate << std::endl;
}
