# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild

# Utility rule file for nanobench-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/nanobench-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/nanobench-populate.dir/progress.make

CMakeFiles/nanobench-populate: CMakeFiles/nanobench-populate-complete

CMakeFiles/nanobench-populate-complete: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-install
CMakeFiles/nanobench-populate-complete: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-mkdir
CMakeFiles/nanobench-populate-complete: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-download
CMakeFiles/nanobench-populate-complete: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-update
CMakeFiles/nanobench-populate-complete: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-patch
CMakeFiles/nanobench-populate-complete: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-configure
CMakeFiles/nanobench-populate-complete: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-build
CMakeFiles/nanobench-populate-complete: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-install
CMakeFiles/nanobench-populate-complete: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'nanobench-populate'"
	/usr/bin/cmake -E make_directory /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles
	/usr/bin/cmake -E touch /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles/nanobench-populate-complete
	/usr/bin/cmake -E touch /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-done

nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-update:
.PHONY : nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-update

nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-build: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'nanobench-populate'"
	cd /home/dmitry/labs_oop/stl/1/_deps/nanobench-build && /usr/bin/cmake -E echo_append
	cd /home/dmitry/labs_oop/stl/1/_deps/nanobench-build && /usr/bin/cmake -E touch /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-build

nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-configure: nanobench-populate-prefix/tmp/nanobench-populate-cfgcmd.txt
nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-configure: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'nanobench-populate'"
	cd /home/dmitry/labs_oop/stl/1/_deps/nanobench-build && /usr/bin/cmake -E echo_append
	cd /home/dmitry/labs_oop/stl/1/_deps/nanobench-build && /usr/bin/cmake -E touch /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-configure

nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-download: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-gitinfo.txt
nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-download: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'nanobench-populate'"
	cd /home/dmitry/labs_oop/stl/1/_deps && /usr/bin/cmake -P /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/tmp/nanobench-populate-gitclone.cmake
	cd /home/dmitry/labs_oop/stl/1/_deps && /usr/bin/cmake -E touch /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-download

nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-install: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'nanobench-populate'"
	cd /home/dmitry/labs_oop/stl/1/_deps/nanobench-build && /usr/bin/cmake -E echo_append
	cd /home/dmitry/labs_oop/stl/1/_deps/nanobench-build && /usr/bin/cmake -E touch /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-install

nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'nanobench-populate'"
	/usr/bin/cmake -Dcfgdir= -P /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/tmp/nanobench-populate-mkdirs.cmake
	/usr/bin/cmake -E touch /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-mkdir

nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-patch: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'nanobench-populate'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-patch

nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-update:
.PHONY : nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-update

nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-test: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'nanobench-populate'"
	cd /home/dmitry/labs_oop/stl/1/_deps/nanobench-build && /usr/bin/cmake -E echo_append
	cd /home/dmitry/labs_oop/stl/1/_deps/nanobench-build && /usr/bin/cmake -E touch /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-test

nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-update: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'nanobench-populate'"
	cd /home/dmitry/labs_oop/stl/1/_deps/nanobench-src && /usr/bin/cmake -P /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/tmp/nanobench-populate-gitupdate.cmake

nanobench-populate: CMakeFiles/nanobench-populate
nanobench-populate: CMakeFiles/nanobench-populate-complete
nanobench-populate: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-build
nanobench-populate: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-configure
nanobench-populate: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-download
nanobench-populate: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-install
nanobench-populate: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-mkdir
nanobench-populate: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-patch
nanobench-populate: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-test
nanobench-populate: nanobench-populate-prefix/src/nanobench-populate-stamp/nanobench-populate-update
nanobench-populate: CMakeFiles/nanobench-populate.dir/build.make
.PHONY : nanobench-populate

# Rule to build all files generated by this target.
CMakeFiles/nanobench-populate.dir/build: nanobench-populate
.PHONY : CMakeFiles/nanobench-populate.dir/build

CMakeFiles/nanobench-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nanobench-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nanobench-populate.dir/clean

CMakeFiles/nanobench-populate.dir/depend:
	cd /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild /home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/CMakeFiles/nanobench-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nanobench-populate.dir/depend

