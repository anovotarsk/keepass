cmake_minimum_required(VERSION 3.5)

project(keepass_src LANGUAGES CXX)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(keepass_src
    ArgsParser.cpp
    ArgsParser.h
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    UTreeWidgetItem.cpp
    UTreeWidgetItem.h
)

qt5_wrap_ui( keepass_src mainwindow.ui)

#target_link_libraries(keepass_src Qt5:Widgets)
target_link_libraries(keepass_src PRIVATE Qt5::Widgets keepasslib)
