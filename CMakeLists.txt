cmake_minimum_required(VERSION 3.25)
project(howyoujini)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(howyoujini main.cpp image_blur.cpp)

target_link_libraries(howyoujini ${OpenCV_LIBS})