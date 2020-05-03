cmake_minimum_required(VERSION 2.8)

project(003_practice)

set(CMAKE_CXX_FLAGS "-std=c++11")

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_DIRS})

add_executable(my_sort my_sort.cpp)
target_link_libraries(my_sort ${OpenCV_LIBS})