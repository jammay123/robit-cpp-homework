# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jammay/robit-cpp-homework/HW2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jammay/robit-cpp-homework/build-HW2-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/HW2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HW2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HW2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW2.dir/flags.make

CMakeFiles/HW2.dir/main.cpp.o: CMakeFiles/HW2.dir/flags.make
CMakeFiles/HW2.dir/main.cpp.o: /home/jammay/robit-cpp-homework/HW2/main.cpp
CMakeFiles/HW2.dir/main.cpp.o: CMakeFiles/HW2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jammay/robit-cpp-homework/build-HW2-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW2.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HW2.dir/main.cpp.o -MF CMakeFiles/HW2.dir/main.cpp.o.d -o CMakeFiles/HW2.dir/main.cpp.o -c /home/jammay/robit-cpp-homework/HW2/main.cpp

CMakeFiles/HW2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW2.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jammay/robit-cpp-homework/HW2/main.cpp > CMakeFiles/HW2.dir/main.cpp.i

CMakeFiles/HW2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW2.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jammay/robit-cpp-homework/HW2/main.cpp -o CMakeFiles/HW2.dir/main.cpp.s

# Object files for target HW2
HW2_OBJECTS = \
"CMakeFiles/HW2.dir/main.cpp.o"

# External object files for target HW2
HW2_EXTERNAL_OBJECTS =

HW2: CMakeFiles/HW2.dir/main.cpp.o
HW2: CMakeFiles/HW2.dir/build.make
HW2: CMakeFiles/HW2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jammay/robit-cpp-homework/build-HW2-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HW2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW2.dir/build: HW2
.PHONY : CMakeFiles/HW2.dir/build

CMakeFiles/HW2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW2.dir/clean

CMakeFiles/HW2.dir/depend:
	cd /home/jammay/robit-cpp-homework/build-HW2-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jammay/robit-cpp-homework/HW2 /home/jammay/robit-cpp-homework/HW2 /home/jammay/robit-cpp-homework/build-HW2-Desktop-Debug /home/jammay/robit-cpp-homework/build-HW2-Desktop-Debug /home/jammay/robit-cpp-homework/build-HW2-Desktop-Debug/CMakeFiles/HW2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW2.dir/depend

