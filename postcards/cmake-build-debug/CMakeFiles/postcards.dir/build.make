# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/mac/Desktop/algosy/personal tasks/postcards"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/mac/Desktop/algosy/personal tasks/postcards/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/postcards.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/postcards.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/postcards.dir/flags.make

CMakeFiles/postcards.dir/main.cpp.o: CMakeFiles/postcards.dir/flags.make
CMakeFiles/postcards.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/mac/Desktop/algosy/personal tasks/postcards/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/postcards.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/postcards.dir/main.cpp.o -c "/Users/mac/Desktop/algosy/personal tasks/postcards/main.cpp"

CMakeFiles/postcards.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/postcards.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/mac/Desktop/algosy/personal tasks/postcards/main.cpp" > CMakeFiles/postcards.dir/main.cpp.i

CMakeFiles/postcards.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/postcards.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/mac/Desktop/algosy/personal tasks/postcards/main.cpp" -o CMakeFiles/postcards.dir/main.cpp.s

# Object files for target postcards
postcards_OBJECTS = \
"CMakeFiles/postcards.dir/main.cpp.o"

# External object files for target postcards
postcards_EXTERNAL_OBJECTS =

postcards: CMakeFiles/postcards.dir/main.cpp.o
postcards: CMakeFiles/postcards.dir/build.make
postcards: CMakeFiles/postcards.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/mac/Desktop/algosy/personal tasks/postcards/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable postcards"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/postcards.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/postcards.dir/build: postcards

.PHONY : CMakeFiles/postcards.dir/build

CMakeFiles/postcards.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/postcards.dir/cmake_clean.cmake
.PHONY : CMakeFiles/postcards.dir/clean

CMakeFiles/postcards.dir/depend:
	cd "/Users/mac/Desktop/algosy/personal tasks/postcards/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/mac/Desktop/algosy/personal tasks/postcards" "/Users/mac/Desktop/algosy/personal tasks/postcards" "/Users/mac/Desktop/algosy/personal tasks/postcards/cmake-build-debug" "/Users/mac/Desktop/algosy/personal tasks/postcards/cmake-build-debug" "/Users/mac/Desktop/algosy/personal tasks/postcards/cmake-build-debug/CMakeFiles/postcards.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/postcards.dir/depend

