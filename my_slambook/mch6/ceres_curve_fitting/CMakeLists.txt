cmake_minimum_required(VERSION 2.8)

project( ceres_curve_fitting)

set(CMAKE_BUILD_TYPE "Debug")
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )
#添加cmake模块 以使用ceres模块
list(APPEND CMAKE_MOUDULE_PATH ${PROJECT_SOURCE_DIR}/cmake_moudles )

#寻找Ceres库并添加它的头文件
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

#添加opencv 库
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_DIRS})

#添加可执行文件  并链接所需要的库
add_executable(curve_fitting main.cpp)
target_link_libraries(curve_fitting ${CERES_LIBRARIES} ${OpenCV_LIBS})