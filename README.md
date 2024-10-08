```c++
/SmartCarProject
│
├── include
│   ├── SmartCar.h        // 智能小车类
│   ├── Chassis.h         // 底盘类 ：包含Tire类
│   ├── Tire.h            // 轮胎类
│   ├── AGXModule.h       // AGX套件类
│   ├── Camera.h          // 双目摄像头类
│   ├── IMU.h             // 9轴陀螺仪类
│   ├── Lidar.h           // 多线激光雷达类
│   ├── Display.h         // 液晶显示屏类
│   ├── Battery.h         // 电池模块类
│   └── Student.h         // 学生类
│
├── src
│   ├── main.cpp          // 主函数
│   ├── SmartCar.cpp      // 智能小车类实现
│   ├── Chassis.cpp       // 底盘类实现
│   ├── Tire.cpp          // 轮胎类实现
│   ├── AGXModule.cpp     // AGX套件类实现
│   ├── Camera.cpp        // 双目摄像头类实现
│   ├── IMU.cpp           // 9轴陀螺仪类实现
│   ├── Lidar.cpp         // 多线激光雷达类实现
│   ├── Display.cpp       // 液晶显示屏类实现
│   ├── Battery.cpp       // 电池模块类实现
│   └── Student.cpp       // 学生类实现
│
├── data
│   └── SmartCars.txt     // 保存的小车信息文件

├── run.py    //启动脚本
│
├── CMakeLists.txt        // CMake构建文件
└── README.md             // 项目说明文件
```

启动项目

```c++
python ./run.py
```

