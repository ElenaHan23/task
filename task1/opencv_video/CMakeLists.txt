cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

project( opencv_video )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

aux_source_directory(. DIR_SRCS)

add_subdirectory(class/Armor)
add_subdirectory(class/ImgProdCons)
add_subdirectory(class/LightDescriptor)

add_executable(main main.cpp)

target_link_libraries(main ${OpenCV_LIBS})
target_link_libraries(main LIGHTDESCRIPTOR)
target_link_libraries(main ARMOR)
target_link_libraries(main IMGPRODCONS)
