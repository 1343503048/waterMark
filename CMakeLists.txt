cmake_minimum_required(VERSION 2.8)
project(waterMark)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp waterMark.cpp waterMark.h)
add_executable(waterMark ${SOURCE_FILES} waterMark.cpp waterMark.h)

target_link_libraries(waterMark ${OpenCV_LIBS})