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
CMAKE_SOURCE_DIR = /home/nate/repos/Beldas-Adventure/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nate/repos/Beldas-Adventure/src/build

# Include any dependencies generated for this target.
include CMakeFiles/Beldas-Adventure.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Beldas-Adventure.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Beldas-Adventure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Beldas-Adventure.dir/flags.make

CMakeFiles/Beldas-Adventure.dir/main.c.o: CMakeFiles/Beldas-Adventure.dir/flags.make
CMakeFiles/Beldas-Adventure.dir/main.c.o: ../main.c
CMakeFiles/Beldas-Adventure.dir/main.c.o: CMakeFiles/Beldas-Adventure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nate/repos/Beldas-Adventure/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Beldas-Adventure.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Beldas-Adventure.dir/main.c.o -MF CMakeFiles/Beldas-Adventure.dir/main.c.o.d -o CMakeFiles/Beldas-Adventure.dir/main.c.o -c /home/nate/repos/Beldas-Adventure/src/main.c

CMakeFiles/Beldas-Adventure.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Beldas-Adventure.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nate/repos/Beldas-Adventure/src/main.c > CMakeFiles/Beldas-Adventure.dir/main.c.i

CMakeFiles/Beldas-Adventure.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Beldas-Adventure.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nate/repos/Beldas-Adventure/src/main.c -o CMakeFiles/Beldas-Adventure.dir/main.c.s

# Object files for target Beldas-Adventure
Beldas__Adventure_OBJECTS = \
"CMakeFiles/Beldas-Adventure.dir/main.c.o"

# External object files for target Beldas-Adventure
Beldas__Adventure_EXTERNAL_OBJECTS =

Linux64/Debug/Beldas-Adventure: CMakeFiles/Beldas-Adventure.dir/main.c.o
Linux64/Debug/Beldas-Adventure: CMakeFiles/Beldas-Adventure.dir/build.make
Linux64/Debug/Beldas-Adventure: Linux64/Debug/static\ libs/libBSC-Engine.a
Linux64/Debug/Beldas-Adventure: CMakeFiles/Beldas-Adventure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nate/repos/Beldas-Adventure/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Linux64/Debug/Beldas-Adventure"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Beldas-Adventure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Beldas-Adventure.dir/build: Linux64/Debug/Beldas-Adventure
.PHONY : CMakeFiles/Beldas-Adventure.dir/build

CMakeFiles/Beldas-Adventure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Beldas-Adventure.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Beldas-Adventure.dir/clean

CMakeFiles/Beldas-Adventure.dir/depend:
	cd /home/nate/repos/Beldas-Adventure/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nate/repos/Beldas-Adventure/src /home/nate/repos/Beldas-Adventure/src /home/nate/repos/Beldas-Adventure/src/build /home/nate/repos/Beldas-Adventure/src/build /home/nate/repos/Beldas-Adventure/src/build/CMakeFiles/Beldas-Adventure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Beldas-Adventure.dir/depend
