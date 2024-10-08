#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "SmartCar.h"
#include "Chassis.h"
#include "Tire.h"
#include "AGXModule.h"
#include "Camera.h"
#include "IMU.h"
#include "Lidar.h"
#include "Display.h"
#include "Battery.h"
#include "Student.h"

// 函数声明
void loadCars(const std::string &filename, std::vector<SmartCar> &cars);

int main()
{
    std::vector<SmartCar> cars;                // 存储小车对象的向量
    loadCars("../data/SmartCars_1.txt", cars); // 从文件中加载小车信息

    while (true)
    {
        std::cout << "\nmenu:\n";
        std::cout << "1. 显示小车信息\n";
        std::cout << "2. 保存小车信息\n";
        std::cout << "3. 修改小车信息\n";
        std::cout << "4. Exit\n";

        int choice;
        std::cin >> choice;

        if (choice == 1) // 显示功能
        {
            int currentIndex = 0; // 当前显示的小车索引
            char command;

            while (true)
            {
                // 显示当前小车的信息
                if (currentIndex >= 0 && currentIndex < 9)
                {
                    cars[currentIndex].print(); // 打印当前小车信息
                }
                else
                {
                    std::cout << "没有更多小车信息可显示。" << std::endl;
                    break;
                }

                // 获取用户输入
                std::cout << "按 'n' 显示下一辆小车信息，按 'p' 显示上一辆小车信息，按 'q' 退出: ";
                std::cin >> command;

                if (command == 'n')
                {
                    if (currentIndex < 9) // 如果不是最后一辆车
                        currentIndex++;
                    else
                        std::cout << "已经是最后一辆车了。" << std::endl;
                }
                else if (command == 'p')
                {
                    if (currentIndex > 0) // 如果不是第一辆车
                        currentIndex--;
                    else
                        std::cout << "已经是第一辆车了。" << std::endl;
                }
                else if (command == 'q') // 按 'q' 退出
                {
                    break;
                }
                else
                {
                    std::cout << "无效命令，请重新输入。" << std::endl;
                }
            }
        }
        else if (choice == 2) // 保存功能
        {
            while (true)
            {
                std::cout << "请输入要保存的小车编号（从1开始），或输入 'b' 返回主菜单：" << std::endl;
                std::string input;
                std::cin >> input;

                if (input == "b") // 返回主菜单
                {
                    break;
                }

                int carNumber = std::stoi(input);

                if (carNumber < 1 || carNumber > static_cast<int>(cars.size()))
                {
                    std::cerr << "无效的编号，请重新输入！" << std::endl;
                    continue;
                }

                int index = carNumber - 1; // 调整为0-based索引
                cars[index].save();        // 保存到文件
                std::cout << "小车 " << carNumber << " 已成功保存到文件中！" << std::endl;
                break; // 成功保存后返回主菜单
            }
        }
        else if (choice == 3) // 修改功能
        {
            while (true)
            {
                std::cout << "请输入要修改的小车编号（从1开始），或输入 'b' 返回主菜单：" << std::endl;
                std::string input;
                std::cin >> input;

                if (input == "b") // 返回主菜单
                {
                    break;
                }

                int carNumber = std::stoi(input);

                if (carNumber < 1 || carNumber > static_cast<int>(cars.size()))
                {
                    std::cerr << "无效的编号，请重新输入！" << std::endl;
                    continue;
                }

                int index = carNumber - 1; // 调整为0-based索引
                SmartCar &car = cars[index];

                std::cout << "请选择要修改的属性，或输入 'b' 返回主菜单：" << std::endl;
                std::cout << "1. 小车编号" << std::endl;
                std::cout << "2. 底盘信息" << std::endl;
                std::cout << "3. AGX模块" << std::endl;
                std::cout << "4. 摄像头" << std::endl;
                std::cout << "5. 陀螺仪" << std::endl;
                std::cout << "6. 激光雷达" << std::endl;
                std::cout << "7. 显示器" << std::endl;
                std::cout << "8. 电池" << std::endl;
                std::cout << "9. 分配的学生" << std::endl;

                std::string attributeInput;
                std::cin >> attributeInput;

                if (attributeInput == "b") // 返回主菜单
                {
                    break;
                }

                int attributeChoice = std::stoi(attributeInput);

                switch (attributeChoice)
                {
                case 1:
                {
                    std::string newID;
                    std::cout << "请输入新的小车编号：" << std::endl;
                    std::cin >> newID;
                    car.setID(newID);
                    break;
                }
                case 2:
                {
                    std::string newID;
                    std::cout << "请输入新的底盘ID：" << std::endl;
                    std::cin >> newID;
                    car.chassis.setChassisID(newID);
                    break;
                }
                case 3:
                {
                    std::string newID;
                    std::cout << "请输入新的AGX模块ID：" << std::endl;
                    std::cin >> newID;
                    car.agxModule.setModel(newID);
                    break;
                }
                case 4:
                {
                    std::string newID;
                    std::cout << "请输入新的摄像头ID：" << std::endl;
                    std::cin >> newID;
                    car.camera.setModel(newID);
                    break;
                }
                case 5:
                {
                    std::string newID;
                    std::cout << "请输入新的IMU ID：" << std::endl;
                    std::cin >> newID;
                    car.imu.setModel(newID);
                    break;
                }
                case 6:
                {
                    std::string newID;
                    std::cout << "请输入新的Lidar ID：" << std::endl;
                    std::cin >> newID;
                    car.lidar.setModel(newID);
                    break;
                }
                case 7:
                {
                    float newSize;
                    std::cout << "请输入新的显示器类型：" << std::endl;
                    std::cin >> newSize;
                    car.display.setSize(newSize);
                    break;
                }
                case 8:
                {
                    std::string newType;
                    std::cout << "请输入新的电池类型：" << std::endl;
                    std::cin >> newType;
                    car.battery.setParameters(newType);
                    break;
                }
                case 9:
                {
                    std::string newID, newName;
                    std::cout << "请输入新的学生ID：" << std::endl;
                    std::cin >> newID;
                    std::cout << "请输入新的学生姓名：" << std::endl;
                    std::cin >> newName;
                    car.assignedStudent.setStudentID(newID);
                    car.assignedStudent.setName(newName);
                    break;
                }
                default:
                    std::cerr << "无效的选择，请重新输入！" << std::endl;
                    continue;
                }

                std::cout << "修改成功！" << std::endl;
                break; // 成功修改后返回主菜单
            }
        }

        else if (choice == 4) // 退出
        {
            break;
        }
        else
        {
            std::cout << "无效选项，请重新输入。" << std::endl; continue;;
        }
    }

    return 0;
}

// 实现读取小车信息的函数
void loadCars(const std::string &filename, std::vector<SmartCar> &cars)
{
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "error open ../data/SmartCars.txt " << std::endl;
        return;
    }
    std::string line;

    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string scId, chassisId, model;
        int length, width, height, seatCount;
        std::string driveType, maxSpeed;

        // 读取底盘信息
        std::getline(iss, scId, ',');
        std::getline(iss, chassisId, ',');
        std::getline(iss, model, ',');
        iss >> length;
        iss.ignore();
        iss >> width;
        iss.ignore();
        iss >> height;
        iss.ignore();
        iss >> seatCount;
        iss.ignore();
        std::getline(iss, driveType, ',');
        std::getline(iss, maxSpeed, ',');

        // 读取轮胎信息
        std::string tireType;
        int tireSize;
        std::getline(iss, tireType, ',');
        iss >> tireSize;
        iss.ignore();

        // 读取AGX模块信息
        std::string agxId;
        int agxVersion, ram, rom, cpuCores, gpuCores;
        std::getline(iss, agxId, ',');
        iss >> agxVersion;
        iss.ignore();
        iss >> ram;
        iss.ignore();
        iss >> rom;
        iss.ignore();
        iss >> cpuCores;
        iss.ignore();
        iss >> gpuCores;
        iss.ignore();

        // 读取摄像头信息
        std::string cameraModel, cameraId, resolution, fov;
        int frameRate, depthFrameRate;
        std::getline(iss, cameraModel, ',');
        std::getline(iss, cameraId, ',');
        std::getline(iss, resolution, ',');
        iss >> frameRate;
        iss.ignore();
        std::getline(iss, fov, ',');
        iss >> depthFrameRate;
        iss.ignore();

        // 读取陀螺仪信息
        std::string imuId, imuSerial;
        std::getline(iss, imuId, ',');
        std::getline(iss, imuSerial, ',');

        // 读取激光雷达信息
        std::string lidarId;
        int lidarChannels, range, rotationSpeed;
        std::getline(iss, lidarId, ',');
        iss >> lidarChannels;
        iss.ignore();
        iss >> range;
        iss.ignore();
        iss >> rotationSpeed;
        iss.ignore();

        // 读取显示器信息
        float displaySize;
        std::string displayType;
        iss >> displaySize;
        iss.ignore();
        std::getline(iss, displayType, ',');

        // 读取电池信息
        std::string batteryType, batteryVoltage;
        int batteryCount;
        std::getline(iss, batteryType, ',');
        std::getline(iss, batteryVoltage, ',');
        iss >> batteryCount;
        iss.ignore();

        // 读取学生信息
        std::string studentId, studentName;
        std::getline(iss, studentId, ',');
        std::getline(iss, studentName, ',');

        // 创建小车对象并添加到向量中
        Tire tire(tireType, tireSize);
        Chassis chassis(chassisId, model, length, width, height, seatCount, driveType, maxSpeed, tire);
        AGXModule agxModule(agxId, agxVersion, ram, rom, cpuCores, gpuCores);
        Camera camera(cameraModel, cameraId, resolution, frameRate, fov, depthFrameRate);
        IMU imu(imuId, imuSerial);
        Lidar lidar(lidarId, lidarChannels, range, rotationSpeed);
        Display display(displaySize, displayType);
        Battery battery(batteryType, batteryVoltage, batteryCount);
        Student student(studentId, studentName);
        SmartCar smartCar(scId, chassis, agxModule, camera, lidar, imu, display, battery, student);

        cars.push_back(smartCar); // 将小车对象添加到向量中
    }
}
