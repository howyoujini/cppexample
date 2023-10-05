cmake_minimum_required(VERSION 3.25)
project(howyoujini)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenCV REQUIRED)

add_executable(howyoujini main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(howyoujini ${OpenCV_LIBS})