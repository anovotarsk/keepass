# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/149/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/149/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anovotarskyi/Desktop/masha_dyplom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anovotarskyi/Desktop/masha_dyplom/cmake-build-debug

# Utility rule file for keepass_src_autogen.

# Include the progress variables for this target.
include src/CMakeFiles/keepass_src_autogen.dir/progress.make

src/CMakeFiles/keepass_src_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/anovotarskyi/Desktop/masha_dyplom/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target keepass_src"
	cd /home/anovotarskyi/Desktop/masha_dyplom/cmake-build-debug/src && /snap/clion/149/bin/cmake/linux/bin/cmake -E cmake_autogen /home/anovotarskyi/Desktop/masha_dyplom/cmake-build-debug/src/CMakeFiles/keepass_src_autogen.dir/AutogenInfo.json Debug

keepass_src_autogen: src/CMakeFiles/keepass_src_autogen
keepass_src_autogen: src/CMakeFiles/keepass_src_autogen.dir/build.make

.PHONY : keepass_src_autogen

# Rule to build all files generated by this target.
src/CMakeFiles/keepass_src_autogen.dir/build: keepass_src_autogen

.PHONY : src/CMakeFiles/keepass_src_autogen.dir/build

src/CMakeFiles/keepass_src_autogen.dir/clean:
	cd /home/anovotarskyi/Desktop/masha_dyplom/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/keepass_src_autogen.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/keepass_src_autogen.dir/clean

src/CMakeFiles/keepass_src_autogen.dir/depend:
	cd /home/anovotarskyi/Desktop/masha_dyplom/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anovotarskyi/Desktop/masha_dyplom /home/anovotarskyi/Desktop/masha_dyplom/src /home/anovotarskyi/Desktop/masha_dyplom/cmake-build-debug /home/anovotarskyi/Desktop/masha_dyplom/cmake-build-debug/src /home/anovotarskyi/Desktop/masha_dyplom/cmake-build-debug/src/CMakeFiles/keepass_src_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/keepass_src_autogen.dir/depend
