# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anovotarskyi/Desktop/masha_dyplom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anovotarskyi/Desktop/masha_dyplom/build

# Include any dependencies generated for this target.
include src/CMakeFiles/keepass_src.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/keepass_src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/keepass_src.dir/flags.make

src/ui_mainwindow.h: ../src/mainwindow.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/anovotarskyi/Desktop/masha_dyplom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_mainwindow.h"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && /usr/lib/qt5/bin/uic -o /home/anovotarskyi/Desktop/masha_dyplom/build/src/ui_mainwindow.h /home/anovotarskyi/Desktop/masha_dyplom/src/mainwindow.ui

src/CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.o: src/CMakeFiles/keepass_src.dir/flags.make
src/CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.o: src/keepass_src_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anovotarskyi/Desktop/masha_dyplom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.o"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.o -c /home/anovotarskyi/Desktop/masha_dyplom/build/src/keepass_src_autogen/mocs_compilation.cpp

src/CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.i"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anovotarskyi/Desktop/masha_dyplom/build/src/keepass_src_autogen/mocs_compilation.cpp > CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.i

src/CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.s"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anovotarskyi/Desktop/masha_dyplom/build/src/keepass_src_autogen/mocs_compilation.cpp -o CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.s

src/CMakeFiles/keepass_src.dir/ArgsParser.cpp.o: src/CMakeFiles/keepass_src.dir/flags.make
src/CMakeFiles/keepass_src.dir/ArgsParser.cpp.o: ../src/ArgsParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anovotarskyi/Desktop/masha_dyplom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/keepass_src.dir/ArgsParser.cpp.o"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/keepass_src.dir/ArgsParser.cpp.o -c /home/anovotarskyi/Desktop/masha_dyplom/src/ArgsParser.cpp

src/CMakeFiles/keepass_src.dir/ArgsParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/keepass_src.dir/ArgsParser.cpp.i"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anovotarskyi/Desktop/masha_dyplom/src/ArgsParser.cpp > CMakeFiles/keepass_src.dir/ArgsParser.cpp.i

src/CMakeFiles/keepass_src.dir/ArgsParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/keepass_src.dir/ArgsParser.cpp.s"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anovotarskyi/Desktop/masha_dyplom/src/ArgsParser.cpp -o CMakeFiles/keepass_src.dir/ArgsParser.cpp.s

src/CMakeFiles/keepass_src.dir/mainwindow.cpp.o: src/CMakeFiles/keepass_src.dir/flags.make
src/CMakeFiles/keepass_src.dir/mainwindow.cpp.o: ../src/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anovotarskyi/Desktop/masha_dyplom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/keepass_src.dir/mainwindow.cpp.o"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/keepass_src.dir/mainwindow.cpp.o -c /home/anovotarskyi/Desktop/masha_dyplom/src/mainwindow.cpp

src/CMakeFiles/keepass_src.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/keepass_src.dir/mainwindow.cpp.i"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anovotarskyi/Desktop/masha_dyplom/src/mainwindow.cpp > CMakeFiles/keepass_src.dir/mainwindow.cpp.i

src/CMakeFiles/keepass_src.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/keepass_src.dir/mainwindow.cpp.s"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anovotarskyi/Desktop/masha_dyplom/src/mainwindow.cpp -o CMakeFiles/keepass_src.dir/mainwindow.cpp.s

# Object files for target keepass_src
keepass_src_OBJECTS = \
"CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/keepass_src.dir/ArgsParser.cpp.o" \
"CMakeFiles/keepass_src.dir/mainwindow.cpp.o"

# External object files for target keepass_src
keepass_src_EXTERNAL_OBJECTS =

src/libkeepass_src.a: src/CMakeFiles/keepass_src.dir/keepass_src_autogen/mocs_compilation.cpp.o
src/libkeepass_src.a: src/CMakeFiles/keepass_src.dir/ArgsParser.cpp.o
src/libkeepass_src.a: src/CMakeFiles/keepass_src.dir/mainwindow.cpp.o
src/libkeepass_src.a: src/CMakeFiles/keepass_src.dir/build.make
src/libkeepass_src.a: src/CMakeFiles/keepass_src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anovotarskyi/Desktop/masha_dyplom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libkeepass_src.a"
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && $(CMAKE_COMMAND) -P CMakeFiles/keepass_src.dir/cmake_clean_target.cmake
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/keepass_src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/keepass_src.dir/build: src/libkeepass_src.a

.PHONY : src/CMakeFiles/keepass_src.dir/build

src/CMakeFiles/keepass_src.dir/clean:
	cd /home/anovotarskyi/Desktop/masha_dyplom/build/src && $(CMAKE_COMMAND) -P CMakeFiles/keepass_src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/keepass_src.dir/clean

src/CMakeFiles/keepass_src.dir/depend: src/ui_mainwindow.h
	cd /home/anovotarskyi/Desktop/masha_dyplom/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anovotarskyi/Desktop/masha_dyplom /home/anovotarskyi/Desktop/masha_dyplom/src /home/anovotarskyi/Desktop/masha_dyplom/build /home/anovotarskyi/Desktop/masha_dyplom/build/src /home/anovotarskyi/Desktop/masha_dyplom/build/src/CMakeFiles/keepass_src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/keepass_src.dir/depend

