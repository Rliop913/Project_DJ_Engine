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
include _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/flags.make

_deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/internal/globals.cc.o: _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/flags.make
_deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/internal/globals.cc.o: _deps/protobuf-src/third_party/abseil-cpp/absl/log/internal/globals.cc
_deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/internal/globals.cc.o: _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/internal/globals.cc.o"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/internal/globals.cc.o -MF CMakeFiles/log_internal_globals.dir/internal/globals.cc.o.d -o CMakeFiles/log_internal_globals.dir/internal/globals.cc.o -c /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/third_party/abseil-cpp/absl/log/internal/globals.cc

_deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/internal/globals.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/log_internal_globals.dir/internal/globals.cc.i"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/third_party/abseil-cpp/absl/log/internal/globals.cc > CMakeFiles/log_internal_globals.dir/internal/globals.cc.i

_deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/internal/globals.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/log_internal_globals.dir/internal/globals.cc.s"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/third_party/abseil-cpp/absl/log/internal/globals.cc -o CMakeFiles/log_internal_globals.dir/internal/globals.cc.s

# Object files for target log_internal_globals
log_internal_globals_OBJECTS = \
"CMakeFiles/log_internal_globals.dir/internal/globals.cc.o"

# External object files for target log_internal_globals
log_internal_globals_EXTERNAL_OBJECTS =

_deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_globals.a: _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/internal/globals.cc.o
_deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_globals.a: _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/build.make
_deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_globals.a: _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_log_internal_globals.a"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/log && $(CMAKE_COMMAND) -P CMakeFiles/log_internal_globals.dir/cmake_clean_target.cmake
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/log && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/log_internal_globals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/build: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_globals.a
.PHONY : _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/build

_deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/clean:
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/log && $(CMAKE_COMMAND) -P CMakeFiles/log_internal_globals.dir/cmake_clean.cmake
.PHONY : _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/clean

_deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/depend:
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/third_party/abseil-cpp/absl/log /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/log /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/protobuf-build/third_party/abseil-cpp/absl/log/CMakeFiles/log_internal_globals.dir/depend

