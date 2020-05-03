cmake_minimum_required(VERSION 2.8)
PROJECT(002_practice)

set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS "-std=c++11")

# 添加eigen3
include_directories("/usr/include/eigen3/")

# 添加OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# convertIndex
add_executable(convertIndex convertIndex.cpp)
target_link_libraries(convertIndex ${OpenCV_LIBS})

#eigenRotate
add_executable(eigenRotate eigenRotate.cpp)
