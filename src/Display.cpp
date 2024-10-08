#include "Display.h"
#include <iostream>
#include <fstream>

Display::Display(float size, const std::string& model)
    : size(size), model(model) {}

void Display::setSize(float size) {
    this->size = size;
}

void Display::print() const {
    std::cout << "液晶显示屏尺寸: " << size << "\"" << std::endl;
    std::cout << "型号: " << model << std::endl;
}

void Display::save() const {
    std::ofstream ofs("../data/" + model + "_display.txt");
    ofs << "液晶显示屏尺寸: " << size << "\"" << std::endl;
    ofs << "型号: " << model << std::endl;
}
