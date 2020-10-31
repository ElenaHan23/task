cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(PCL_TEST)
set(CMAKE_BUILD_TYPE"Debug")
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(PCL 1.7 REQUIRED)


include_directories(${PCL_INCLUDE_DIRS})
link_LIBRARIES(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcl_test main.cpp)
target_link_libraries(pcl_test ${PCL_LIBRARIES})
