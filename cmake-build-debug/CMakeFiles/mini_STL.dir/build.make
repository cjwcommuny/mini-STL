# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cjw/workspace/mini-STL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cjw/workspace/mini-STL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mini_STL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mini_STL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mini_STL.dir/flags.make

CMakeFiles/mini_STL.dir/main.cpp.o: CMakeFiles/mini_STL.dir/flags.make
CMakeFiles/mini_STL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cjw/workspace/mini-STL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mini_STL.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mini_STL.dir/main.cpp.o -c /Users/cjw/workspace/mini-STL/main.cpp

CMakeFiles/mini_STL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mini_STL.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cjw/workspace/mini-STL/main.cpp > CMakeFiles/mini_STL.dir/main.cpp.i

CMakeFiles/mini_STL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mini_STL.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cjw/workspace/mini-STL/main.cpp -o CMakeFiles/mini_STL.dir/main.cpp.s

CMakeFiles/mini_STL.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/mini_STL.dir/main.cpp.o.requires

CMakeFiles/mini_STL.dir/main.cpp.o.provides: CMakeFiles/mini_STL.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/mini_STL.dir/build.make CMakeFiles/mini_STL.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/mini_STL.dir/main.cpp.o.provides

CMakeFiles/mini_STL.dir/main.cpp.o.provides.build: CMakeFiles/mini_STL.dir/main.cpp.o


CMakeFiles/mini_STL.dir/myVector.cpp.o: CMakeFiles/mini_STL.dir/flags.make
CMakeFiles/mini_STL.dir/myVector.cpp.o: ../myVector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cjw/workspace/mini-STL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mini_STL.dir/myVector.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mini_STL.dir/myVector.cpp.o -c /Users/cjw/workspace/mini-STL/myVector.cpp

CMakeFiles/mini_STL.dir/myVector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mini_STL.dir/myVector.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cjw/workspace/mini-STL/myVector.cpp > CMakeFiles/mini_STL.dir/myVector.cpp.i

CMakeFiles/mini_STL.dir/myVector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mini_STL.dir/myVector.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cjw/workspace/mini-STL/myVector.cpp -o CMakeFiles/mini_STL.dir/myVector.cpp.s

CMakeFiles/mini_STL.dir/myVector.cpp.o.requires:

.PHONY : CMakeFiles/mini_STL.dir/myVector.cpp.o.requires

CMakeFiles/mini_STL.dir/myVector.cpp.o.provides: CMakeFiles/mini_STL.dir/myVector.cpp.o.requires
	$(MAKE) -f CMakeFiles/mini_STL.dir/build.make CMakeFiles/mini_STL.dir/myVector.cpp.o.provides.build
.PHONY : CMakeFiles/mini_STL.dir/myVector.cpp.o.provides

CMakeFiles/mini_STL.dir/myVector.cpp.o.provides.build: CMakeFiles/mini_STL.dir/myVector.cpp.o


CMakeFiles/mini_STL.dir/myIterator.cpp.o: CMakeFiles/mini_STL.dir/flags.make
CMakeFiles/mini_STL.dir/myIterator.cpp.o: ../myIterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cjw/workspace/mini-STL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mini_STL.dir/myIterator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mini_STL.dir/myIterator.cpp.o -c /Users/cjw/workspace/mini-STL/myIterator.cpp

CMakeFiles/mini_STL.dir/myIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mini_STL.dir/myIterator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cjw/workspace/mini-STL/myIterator.cpp > CMakeFiles/mini_STL.dir/myIterator.cpp.i

CMakeFiles/mini_STL.dir/myIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mini_STL.dir/myIterator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cjw/workspace/mini-STL/myIterator.cpp -o CMakeFiles/mini_STL.dir/myIterator.cpp.s

CMakeFiles/mini_STL.dir/myIterator.cpp.o.requires:

.PHONY : CMakeFiles/mini_STL.dir/myIterator.cpp.o.requires

CMakeFiles/mini_STL.dir/myIterator.cpp.o.provides: CMakeFiles/mini_STL.dir/myIterator.cpp.o.requires
	$(MAKE) -f CMakeFiles/mini_STL.dir/build.make CMakeFiles/mini_STL.dir/myIterator.cpp.o.provides.build
.PHONY : CMakeFiles/mini_STL.dir/myIterator.cpp.o.provides

CMakeFiles/mini_STL.dir/myIterator.cpp.o.provides.build: CMakeFiles/mini_STL.dir/myIterator.cpp.o


# Object files for target mini_STL
mini_STL_OBJECTS = \
"CMakeFiles/mini_STL.dir/main.cpp.o" \
"CMakeFiles/mini_STL.dir/myVector.cpp.o" \
"CMakeFiles/mini_STL.dir/myIterator.cpp.o"

# External object files for target mini_STL
mini_STL_EXTERNAL_OBJECTS =

mini_STL: CMakeFiles/mini_STL.dir/main.cpp.o
mini_STL: CMakeFiles/mini_STL.dir/myVector.cpp.o
mini_STL: CMakeFiles/mini_STL.dir/myIterator.cpp.o
mini_STL: CMakeFiles/mini_STL.dir/build.make
mini_STL: CMakeFiles/mini_STL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cjw/workspace/mini-STL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable mini_STL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mini_STL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mini_STL.dir/build: mini_STL

.PHONY : CMakeFiles/mini_STL.dir/build

CMakeFiles/mini_STL.dir/requires: CMakeFiles/mini_STL.dir/main.cpp.o.requires
CMakeFiles/mini_STL.dir/requires: CMakeFiles/mini_STL.dir/myVector.cpp.o.requires
CMakeFiles/mini_STL.dir/requires: CMakeFiles/mini_STL.dir/myIterator.cpp.o.requires

.PHONY : CMakeFiles/mini_STL.dir/requires

CMakeFiles/mini_STL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mini_STL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mini_STL.dir/clean

CMakeFiles/mini_STL.dir/depend:
	cd /Users/cjw/workspace/mini-STL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cjw/workspace/mini-STL /Users/cjw/workspace/mini-STL /Users/cjw/workspace/mini-STL/cmake-build-debug /Users/cjw/workspace/mini-STL/cmake-build-debug /Users/cjw/workspace/mini-STL/cmake-build-debug/CMakeFiles/mini_STL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mini_STL.dir/depend

