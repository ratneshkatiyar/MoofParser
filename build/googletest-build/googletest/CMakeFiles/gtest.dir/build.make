# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build

# Include any dependencies generated for this target.
include googletest-build/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include googletest-build/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include googletest-build/googletest/CMakeFiles/gtest.dir/flags.make

googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: googletest-build/googletest/CMakeFiles/gtest.dir/flags.make
googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: googletest-src/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-build/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-src/googletest/src/gtest-all.cc

googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-build/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-src/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-build/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-src/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtest.a: googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtest.a: googletest-build/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtest.a: googletest-build/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libgtest.a"
	cd /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-build/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-build/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest-build/googletest/CMakeFiles/gtest.dir/build: lib/libgtest.a

.PHONY : googletest-build/googletest/CMakeFiles/gtest.dir/build

googletest-build/googletest/CMakeFiles/gtest.dir/clean:
	cd /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-build/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : googletest-build/googletest/CMakeFiles/gtest.dir/clean

googletest-build/googletest/CMakeFiles/gtest.dir/depend:
	cd /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-src/googletest /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-build/googletest /home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-build/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest-build/googletest/CMakeFiles/gtest.dir/depend
