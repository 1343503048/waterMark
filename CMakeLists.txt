cmake_minimum_required(VERSION 3.5)
project(waterMark)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

set(SOURCE_FILES
        main.cpp
        waterMark.cpp
        waterMark.h encode.cpp)

add_executable(encode encode.cpp)
add_executable(decode decode.cpp)
target_link_libraries(encode ${OpenCV_LIBS})
target_link_libraries(decode ${OpenCV_LIBS})
