# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release

# Utility rule file for NightlySubmit.

# Include any custom commands dependencies for this target.
include _deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit.dir/progress.make

_deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit:
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp && /usr/bin/ctest -D NightlySubmit

NightlySubmit: _deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit
NightlySubmit: _deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit.dir/build.make
.PHONY : NightlySubmit

# Rule to build all files generated by this target.
_deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit.dir/build: NightlySubmit
.PHONY : _deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit.dir/build

_deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit.dir/clean:
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp && $(CMAKE_COMMAND) -P CMakeFiles/NightlySubmit.dir/cmake_clean.cmake
.PHONY : _deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit.dir/clean

_deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit.dir/depend:
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/third_party/abseil-cpp /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/protobuf-build/third_party/abseil-cpp/CMakeFiles/NightlySubmit.dir/depend

