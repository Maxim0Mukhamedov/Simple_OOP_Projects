cmake_minimum_required(VERSION 3.15)

project(misis-proga LANGUAGES CXX)

add_library(settings INTERFACE)
target_compile_features(settings INTERFACE cxx_std_17)

file(GLOB_RECURSE SOURCE_LIST
        "./*.cpp"
        )

foreach(file ${SOURCE_LIST})
    get_filename_component(file_name ${file} NAME_WE)
    add_executable(${file_name} ${file})
    target_link_libraries(${file_name} PUBLIC settings)
endforeach()
