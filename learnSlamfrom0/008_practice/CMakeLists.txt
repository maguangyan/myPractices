cmake_minimum_required(VERSION 2.8)
project(08_practice)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")

# 添加eigen
include_directories("/usr/include/eigen3/")

# 添加sophus
find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

# 添加pangolin
find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})

# 添加可执行程序
add_executable(draw_trajectory draw_trajectory.cpp)
target_link_libraries(draw_trajectory
    ${Sophus_LIBRARIES}
    ${Pangolin_LIBRARIES})
