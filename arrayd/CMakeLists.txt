cmake_minimum_required(VERSION 3.24)
project(DynamicArray)

set(CMAKE_CXX_STANDARD 20)
find_package(doctest)
add_subdirectory(arrayd)
add_executable(test main.cpp)
target_link_libraries(test arrayd doctest::doctest)

