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
include _deps/protobuf-build/CMakeFiles/protoc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/protobuf-build/CMakeFiles/protoc.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/protobuf-build/CMakeFiles/protoc.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/protobuf-build/CMakeFiles/protoc.dir/flags.make

_deps/protobuf-build/CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.o: _deps/protobuf-build/CMakeFiles/protoc.dir/flags.make
_deps/protobuf-build/CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.o: _deps/protobuf-src/src/google/protobuf/compiler/main.cc
_deps/protobuf-build/CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.o: _deps/protobuf-build/CMakeFiles/protoc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/protobuf-build/CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.o"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/protobuf-build/CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.o -MF CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.o.d -o CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.o -c /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/src/google/protobuf/compiler/main.cc

_deps/protobuf-build/CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.i"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/src/google/protobuf/compiler/main.cc > CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.i

_deps/protobuf-build/CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.s"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src/src/google/protobuf/compiler/main.cc -o CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.s

# Object files for target protoc
protoc_OBJECTS = \
"CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.o"

# External object files for target protoc
protoc_EXTERNAL_OBJECTS =

_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/CMakeFiles/protoc.dir/src/google/protobuf/compiler/main.cc.o
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/CMakeFiles/protoc.dir/build.make
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/libprotoc.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/libprotobuf.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/base/libabsl_base.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_cord.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_die_if_null.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/hash/libabsl_hash.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_initialize.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_globals.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/base/libabsl_log_severity.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_distributions.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/status/libabsl_status.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/status/libabsl_statusor.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_strings.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/synchronization/libabsl_synchronization.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/time/libabsl_time.a
_deps/protobuf-build/protoc-27.0.3: /usr/lib/libz.so
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/utf8_range/libutf8_validity.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_check_op.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/debugging/libabsl_leak_check.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_conditions.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_message.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_nullguard.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/debugging/libabsl_examine_stack.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_format.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_proto.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_log_sink_set.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_sink.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_entry.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_marshalling.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_reflection.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_config.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_program_name.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_private_handle_accessor.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_commandlineflag.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/flags/libabsl_flags_commandlineflag_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_globals.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_globals.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_vlog_config_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/log/libabsl_log_internal_fnmatch.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/container/libabsl_raw_hash_set.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/hash/libabsl_hash.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/hash/libabsl_city.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/hash/libabsl_low_level_hash.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/container/libabsl_hashtablez_sampler.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_distributions.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_seed_sequences.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_internal_pool_urbg.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_internal_randen.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_internal_randen_hwaes.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_internal_randen_hwaes_impl.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_internal_randen_slow.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_internal_platform.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_internal_seed_material.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/random/libabsl_random_seed_gen_exception.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/status/libabsl_status.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_cord.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_cordz_info.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_cord_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_cordz_functions.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/profiling/libabsl_exponential_biased.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_cordz_handle.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/crc/libabsl_crc_cord_state.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/crc/libabsl_crc32c.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/crc/libabsl_crc_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/crc/libabsl_crc_cpu_detect.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/types/libabsl_bad_optional_access.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/base/libabsl_strerror.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_str_format_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/synchronization/libabsl_synchronization.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/debugging/libabsl_stacktrace.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/debugging/libabsl_symbolize.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/debugging/libabsl_debugging_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/debugging/libabsl_demangle_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/synchronization/libabsl_graphcycles_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/synchronization/libabsl_kernel_timeout_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/base/libabsl_malloc_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/time/libabsl_time.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_strings.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_strings_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/strings/libabsl_string_view.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/base/libabsl_base.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/base/libabsl_spinlock_wait.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/base/libabsl_throw_delegate.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/numeric/libabsl_int128.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/time/libabsl_civil_time.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/time/libabsl_time_zone.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/types/libabsl_bad_variant_access.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/base/libabsl_raw_logging_internal.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/third_party/abseil-cpp/absl/base/libabsl_log_severity.a
_deps/protobuf-build/protoc-27.0.3: _deps/protobuf-build/CMakeFiles/protoc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable protoc"
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/protoc.dir/link.txt --verbose=$(VERBOSE)
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build && $(CMAKE_COMMAND) -E cmake_symlink_executable protoc-27.0.3 protoc

_deps/protobuf-build/protoc: _deps/protobuf-build/protoc-27.0.3

# Rule to build all files generated by this target.
_deps/protobuf-build/CMakeFiles/protoc.dir/build: _deps/protobuf-build/protoc
.PHONY : _deps/protobuf-build/CMakeFiles/protoc.dir/build

_deps/protobuf-build/CMakeFiles/protoc.dir/clean:
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build && $(CMAKE_COMMAND) -P CMakeFiles/protoc.dir/cmake_clean.cmake
.PHONY : _deps/protobuf-build/CMakeFiles/protoc.dir/clean

_deps/protobuf-build/CMakeFiles/protoc.dir/depend:
	cd /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-src /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build /home/rrop/Dropbox/box_inside/git_branch/cpps/Disk_Jockey_Engine_Mini/cmake-build-Release/_deps/protobuf-build/CMakeFiles/protoc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/protobuf-build/CMakeFiles/protoc.dir/depend

