add_library(arrayt INTERFACE)
set_property(TARGET arrayt PROPERTY CXX_STANDARD 20)
# CMake Error: CMake can not determine linker language for target: arrayt
set_target_properties(arrayt PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(arrayt INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )
#install(TARGETS arrayt)