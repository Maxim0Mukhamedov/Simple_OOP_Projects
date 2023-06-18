cmake_minimum_required(VERSION 3.21)
project(ccn_example)

find_package(OpenCV CONFIG REQUIRED)

include_directories(${OpenCV_INCLUDE_DIR})
message("OpenCV_INCLUDE_DIRS: " ${OpenCV_INCLUDE_DIR})

add_executable(${PROJECT_NAME} example_cmd_app.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ccn)

target_compile_definitions(${PROJECT_NAME} PRIVATE INSTALL_PATH="${CMAKE_INSTALL_PREFIX}/bin")
install(TARGETS ${PROJECT_NAME})
if(WIN32)
    set(OpenCV_RUNTIME_PATH "${OpenCV_DIR}/../../bin")
else()
    set(OpenCV_RUNTIME_PATH "${OpenCV_DIR}/../../lib")
endif()

install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*opencv_core*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*highgui*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*imgcodecs*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*imgproc*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*videoio*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*zlib*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*jpeg*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*libwebpdecoder*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*libwebp*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*libpng*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*libsharpyuv*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*tiff*"
        )
install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        FILES_MATCHING PATTERN "*liblzma*"
        )
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test_input DESTINATION ./bin)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test_output DESTINATION ./bin)
