#include "Student.h"
#include <iostream>
#include <fstream>

Student::Student(const std::string& studentID, const std::string& name)
    : studentID(studentID), name(name) {}

void Student::setStudentID(const std::string& id) {
    studentID = id;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

void Student::print() const {
    std::cout << "学号: " << studentID << ", 姓名: " << name << std::endl;
}

void Student::save() const {
    std::ofstream ofs("../data/" + studentID + "_student.txt");
    ofs << "学号: " << studentID << std::endl;
    ofs << "姓名: " << name << std::endl;
}
