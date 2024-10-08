# 自动化编译和运行的脚本
mkdir build
cd build/
#windows下使用MinGW编译
cmake -G "MinGW Makefiles" ..
make 
./SmartCar