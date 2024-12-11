cmake_minimum_required(VERSION 3.16)

project(cw3 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Charts LinguistTools)
qt_standard_project_setup(I18N_TRANSLATED_LANGUAGES es en en_GB)

qt_add_translations(cw3 TS_FILES
    translation/translations_en.ts
    translation/translations_es.ts
    translation/translations_en_GB.ts
)

qt_add_executable(cw3
    main.cpp
    pollutant.cpp
    model.cpp
    dataset.cpp 
    dashboard.cpp
    overview.cpp
    window.cpp
    pop.cpp
    Compliance.cpp
)

target_link_libraries(cw3 PRIVATE Qt6::Widgets Qt6::Charts)

set_target_properties(cw3 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE OFF
)
