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

# Include any dependencies generated for this target.
include _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/flags.make

_deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.o: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/flags.make
_deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.o: _deps/protobuf-src/third_party/abseil-cpp/absl/flags/commandlineflag.cc
_deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.o: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.o"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/flags && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.o -MF CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.o.d -o CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.o -c /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/third_party/abseil-cpp/absl/flags/commandlineflag.cc

_deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.i"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/flags && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/third_party/abseil-cpp/absl/flags/commandlineflag.cc > CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.i

_deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.s"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/flags && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/third_party/abseil-cpp/absl/flags/commandlineflag.cc -o CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.s

# Object files for target flags_commandlineflag
flags_commandlineflag_OBJECTS = \
"CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.o"

# External object files for target flags_commandlineflag
flags_commandlineflag_EXTERNAL_OBJECTS =

_deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_commandlineflag.a: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/commandlineflag.cc.o
_deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_commandlineflag.a: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/build.make
_deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_commandlineflag.a: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_flags_commandlineflag.a"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/flags && $(CMAKE_COMMAND) -P CMakeFiles/flags_commandlineflag.dir/cmake_clean_target.cmake
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/flags && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flags_commandlineflag.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/build: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_commandlineflag.a
.PHONY : _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/build

_deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/clean:
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/flags && $(CMAKE_COMMAND) -P CMakeFiles/flags_commandlineflag.dir/cmake_clean.cmake
.PHONY : _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/clean

_deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/depend:
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/third_party/abseil-cpp/absl/flags /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/flags /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/protobuf-build/third_party/abseil-cpp/absl/flags/CMakeFiles/flags_commandlineflag.dir/depend

