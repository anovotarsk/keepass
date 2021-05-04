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
    EntryForm.ui
    EntryForm.h
    EntryForm.cpp
    IconChooser.cpp
    IconChooser.h
    IconChooser.ui
    GroupForm.cpp
    GroupForm.h
    GroupForm.ui
    Form.h
    Form.cpp
)

qt5_wrap_ui( keepass_src mainwindow.ui )
qt5_wrap_ui( keepass_src EntryForm.ui )
qt5_wrap_ui( keepass_src IconChooser.ui )

#target_link_libraries(keepass_src Qt5:Widgets)
target_link_libraries(keepass_src PRIVATE Qt5::Widgets keepasslib)
