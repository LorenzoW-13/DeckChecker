cmake_minimum_required(VERSION 3.16)

project(MTGManager VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGL Sql)
qt_standard_project_setup()

qt_add_executable(MTGManager
    main.cpp

    deckchecker.cpp
    deckchecker.ui
    databaseerror.cpp
    databaseerror.ui

    ItemColor.cpp
)

target_link_libraries(MTGManager PRIVATE Qt6::Widgets Qt6::Sql)


set_target_properties(MTGManager PROPERTIES
    #WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)