cmake_minimum_required(VERSION 2.8)
project(g20_curve_fitting)

set(CMAKE_BUILD_TYPE "Debug")
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

#添加cmake模块以使用ceres库
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

#寻找g20
find_package(G2O REQUIRED)
include_directories(${G2O_INCLUDE_DIRS} "/usr/include/eigen3")

#opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_DIRS})

add_executable( curve_fitting main.cpp)
#链接到G2O 和 OpenCV
target_link_libraries(curve_fitting ${OpenCV_LIBS} g2o_core g2o_stuff)