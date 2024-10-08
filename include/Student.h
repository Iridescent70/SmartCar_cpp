#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>
#include <iostream>

class Student {
private:
    std::string studentID; // 学号
    std::string name;      // 姓名

public:
    // 构造函数
    Student(const std::string& studentID, const std::string& name);

    void setStudentID(const std::string& id); // 设置学号
    void setName(const std::string& name);     // 设置姓名
    void print() const;                        // 打印信息
    void save() const;                         // 保存信息
};

#endif // STUDENT_H
