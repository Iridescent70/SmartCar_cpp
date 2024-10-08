cmake_minimum_required(VERSION 3.15)
project(SmartCar)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(./src/ DIR_SRC) 
# 搜索 src 目录下的所有源文件并将其列表存储在变量 DIR_SRC 中

# 设置编译器标志以确保使用 UTF-8 编码
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")

include_directories(./include/) 
# 包含头文件目录 include，以确保编译器在编译时能够找到头文件

add_executable(SmartCar ${DIR_SRC} )
# 定义可执行文件 Demo，并指定其源文件为变量 DIR_SRC 中的文件