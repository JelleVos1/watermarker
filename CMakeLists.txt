cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 17)

# set the project name
project(watermarker)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# add the executable
add_executable(watermarker Main.cpp utils/FileUtils.cpp utils/Watermarker.cpp)

target_link_libraries(watermarker ${OpenCV_LIBS})