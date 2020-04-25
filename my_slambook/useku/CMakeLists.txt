#声明要求的CMAKE 最低版本
cmake_minimum_required(VERSION 2.8)

#声明一个cmake工程
project(HelloSLAM)
#添加一个库

add_library( hello libHelloSLAM.cpp)#静态库
add_library( hello_shared SHARED libHelloSLAM.cpp)#动态库


add_executable( useHello useHello.cpp)#调用gcc进行编译
target_link_libraries( useHello hello_shared)#将程序链接到库上

