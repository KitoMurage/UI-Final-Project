cmake_minimum_required(VERSION 3.16)

project(cw3 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(cw3
    main.cpp
    pollutant.cpp
    model.cpp
    dataset.cpp 
    dashboard.cpp
    overview.cpp
    window.cpp
    pop.cpp
)

target_link_libraries(cw3 PRIVATE Qt6::Widgets)

set_target_properties(cw3 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE OFF
)
