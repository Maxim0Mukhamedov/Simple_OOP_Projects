cmake_minimum_required(VERSION 3.23)
project(Muchausen)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_subdirectory(geom)

add_executable(AD AD.cpp)

target_link_libraries(AD geom)