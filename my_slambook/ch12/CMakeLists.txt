cmake_minimum_required(VERSION 2.8)
project(loop_closure)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS  "-std=c++11 -O3")

# opencv
find_package(OpenCV 3.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

#dbow3
#如果是默认安装的话
set(DBoW3_INCLUDE_DIRS "/usr/local/include")
set(DBoW3_LIBS "/usr/local/lib/libDBoW3.a")

#我感觉也可以使用findpackge
#find_package(DBow3 REQUIRED)
#include_directories(${DBow3_INCLUDE_DIRS)

add_executable(feature_tranining feature_tranining.cpp)
target_link_libraries(feature_tranining ${OpenCV_LIBS} ${DBoW3_LIBS})

add_executable(loop_closure loop_closure.cpp)
target_link_libraries(loop_closure ${OpenCV_LIBS} ${DBoW3_LIBS})
