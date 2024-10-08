#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <fstream>
#include <iostream>

class Display {
private:
    float size;
    std::string model;

public:
    Display(float size, const std::string& model);
    void setSize(float size);
    void print() const;
    void save() const;
};

#endif // DISPLAY_H
