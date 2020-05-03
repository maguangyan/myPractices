cmake_minimum_required(VERSION 2.8)
project(012_practice)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")

# 添加OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(virtual-billboard virtual-billboard.cpp)
target_link_libraries(virtual-billboard ${OpenCV_LIBS})
