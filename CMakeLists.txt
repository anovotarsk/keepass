cmake_minimum_required(VERSION 3.5)

project(keepass LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

link_libraries("-lcrypto" "-lz")

include_directories(
    src
    libkeepass/src
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(keepass
    main.cpp
)

add_subdirectory(src)
add_subdirectory(libkeepass)

target_link_libraries(keepass PRIVATE Qt5::Widgets keepass_src keepasslib)
