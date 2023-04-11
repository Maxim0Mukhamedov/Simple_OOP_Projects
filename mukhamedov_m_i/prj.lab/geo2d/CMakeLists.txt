add_library(geo2d geo2d.cpp include/geo2d/ellipse.hpp include/geo2d/geo2d.hpp include/geo2d/transform.hpp include/geo2d/line.hpp include/geo2d/point.hpp include/geo2d/ring.hpp include/geo2d/polygon.hpp)
set_property(TARGET geo2d PROPERTY CXX_STANDARD 20)
target_include_directories(geo2d PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )
install(TARGETS geo2d)