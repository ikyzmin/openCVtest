cmake_minimum_required(VERSION 3.5.1)
project(openCVtest)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
set(OpenCV_DIR  /home/opencv/opencv)

find_package( OpenCV REQUIRED )

add_executable(openCVtest ${SOURCE_FILES})
target_link_libraries( openCVtest ${OpenCV_LIBS} )
