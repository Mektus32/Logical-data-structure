# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /snap/cmake/192/bin/cmake

# The command to remove a file.
RM = /snap/cmake/192/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mektus/Desktop/lds

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mektus/Desktop/lds

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/cmake/192/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/snap/cmake/177/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mektus/Desktop/lds/CMakeFiles /home/mektus/Desktop/lds/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mektus/Desktop/lds/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named lds

# Build rule for target.
lds: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 lds
.PHONY : lds

# fast build rule for target.
lds/fast:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/build
.PHONY : lds/fast

source/Stack.o: source/Stack.cpp.o

.PHONY : source/Stack.o

# target to build an object file
source/Stack.cpp.o:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/Stack.cpp.o
.PHONY : source/Stack.cpp.o

source/Stack.i: source/Stack.cpp.i

.PHONY : source/Stack.i

# target to preprocess a source file
source/Stack.cpp.i:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/Stack.cpp.i
.PHONY : source/Stack.cpp.i

source/Stack.s: source/Stack.cpp.s

.PHONY : source/Stack.s

# target to generate assembly for a file
source/Stack.cpp.s:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/Stack.cpp.s
.PHONY : source/Stack.cpp.s

source/Text.o: source/Text.cpp.o

.PHONY : source/Text.o

# target to build an object file
source/Text.cpp.o:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/Text.cpp.o
.PHONY : source/Text.cpp.o

source/Text.i: source/Text.cpp.i

.PHONY : source/Text.i

# target to preprocess a source file
source/Text.cpp.i:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/Text.cpp.i
.PHONY : source/Text.cpp.i

source/Text.s: source/Text.cpp.s

.PHONY : source/Text.s

# target to generate assembly for a file
source/Text.cpp.s:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/Text.cpp.s
.PHONY : source/Text.cpp.s

source/WordsList.o: source/WordsList.cpp.o

.PHONY : source/WordsList.o

# target to build an object file
source/WordsList.cpp.o:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/WordsList.cpp.o
.PHONY : source/WordsList.cpp.o

source/WordsList.i: source/WordsList.cpp.i

.PHONY : source/WordsList.i

# target to preprocess a source file
source/WordsList.cpp.i:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/WordsList.cpp.i
.PHONY : source/WordsList.cpp.i

source/WordsList.s: source/WordsList.cpp.s

.PHONY : source/WordsList.s

# target to generate assembly for a file
source/WordsList.cpp.s:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/WordsList.cpp.s
.PHONY : source/WordsList.cpp.s

source/main.o: source/main.cpp.o

.PHONY : source/main.o

# target to build an object file
source/main.cpp.o:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/main.cpp.o
.PHONY : source/main.cpp.o

source/main.i: source/main.cpp.i

.PHONY : source/main.i

# target to preprocess a source file
source/main.cpp.i:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/main.cpp.i
.PHONY : source/main.cpp.i

source/main.s: source/main.cpp.s

.PHONY : source/main.s

# target to generate assembly for a file
source/main.cpp.s:
	$(MAKE) -f CMakeFiles/lds.dir/build.make CMakeFiles/lds.dir/source/main.cpp.s
.PHONY : source/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... lds"
	@echo "... edit_cache"
	@echo "... source/Stack.o"
	@echo "... source/Stack.i"
	@echo "... source/Stack.s"
	@echo "... source/Text.o"
	@echo "... source/Text.i"
	@echo "... source/Text.s"
	@echo "... source/WordsList.o"
	@echo "... source/WordsList.i"
	@echo "... source/WordsList.s"
	@echo "... source/main.o"
	@echo "... source/main.i"
	@echo "... source/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

