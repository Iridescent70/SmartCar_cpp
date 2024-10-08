#include "AGXModule.h"
#include <iostream>
#include <fstream>

AGXModule::AGXModule(const std::string& model, int aiPerformance, int cudaCores, int tensorCores, int memory, int storage)
    : model(model), aiPerformance(aiPerformance), cudaCores(cudaCores), tensorCores(tensorCores), memory(memory), storage(storage) {}

void AGXModule::setModel(const std::string& model) {
    this->model = model;
}

void AGXModule::print() const {
    std::cout << "AGX套件型号: " << model << std::endl;
    std::cout << "AI: " << aiPerformance << " TOPS" << std::endl;
    std::cout << "CUDA核心: " << cudaCores << std::endl;
    std::cout << "Tensor CORE: " << tensorCores << std::endl;
    std::cout << "显存: " << memory << "G" << std::endl;
    std::cout << "存储: " << storage << "G" << std::endl;
}

void AGXModule::save() const {
    std::ofstream ofs("../data/" + model + "_agx.txt");
    ofs << "AGX套件型号: " << model << std::endl;
    ofs << "AI: " << aiPerformance << " TOPS" << std::endl;
    ofs << "CUDA核心: " << cudaCores << std::endl;
    ofs << "Tensor CORE: " << tensorCores << std::endl;
    ofs << "显存: " << memory << "G" << std::endl;
    ofs << "存储: " << storage << "G" << std::endl;
}
