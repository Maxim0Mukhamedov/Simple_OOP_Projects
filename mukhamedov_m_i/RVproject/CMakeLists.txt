cmake_minimum_required(VERSION 3.23)
project(project151122)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(RV)

include_directories(RV)

add_executable(project151122 main.cpp doctest.h)

target_link_libraries(project151122 rad_vec)
