# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build

# Include any dependencies generated for this target.
include source/CMakeFiles/algodat_4_tests.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/algodat_4_tests.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/algodat_4_tests.dir/flags.make

source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o: source/CMakeFiles/algodat_4_tests.dir/flags.make
source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o: ../source/algodat_4_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o"
	cd /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build/source && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o -c /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/source/algodat_4_tests.cpp

source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.i"
	cd /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/source/algodat_4_tests.cpp > CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.i

source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.s"
	cd /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/source/algodat_4_tests.cpp -o CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.s

source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o.requires:

.PHONY : source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o.requires

source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o.provides: source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/algodat_4_tests.dir/build.make source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o.provides.build
.PHONY : source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o.provides

source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o.provides.build: source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o


# Object files for target algodat_4_tests
algodat_4_tests_OBJECTS = \
"CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o"

# External object files for target algodat_4_tests
algodat_4_tests_EXTERNAL_OBJECTS =

source/algodat_4_tests: source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o
source/algodat_4_tests: source/CMakeFiles/algodat_4_tests.dir/build.make
source/algodat_4_tests: source/CMakeFiles/algodat_4_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algodat_4_tests"
	cd /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/algodat_4_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/algodat_4_tests.dir/build: source/algodat_4_tests

.PHONY : source/CMakeFiles/algodat_4_tests.dir/build

source/CMakeFiles/algodat_4_tests.dir/requires: source/CMakeFiles/algodat_4_tests.dir/algodat_4_tests.cpp.o.requires

.PHONY : source/CMakeFiles/algodat_4_tests.dir/requires

source/CMakeFiles/algodat_4_tests.dir/clean:
	cd /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build/source && $(CMAKE_COMMAND) -P CMakeFiles/algodat_4_tests.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/algodat_4_tests.dir/clean

source/CMakeFiles/algodat_4_tests.dir/depend:
	cd /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4 /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/source /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build/source /home/karoline/Documents/studium/17_sose/algorithmen_und_datenstrukturen/algodat_4/build/source/CMakeFiles/algodat_4_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/algodat_4_tests.dir/depend

