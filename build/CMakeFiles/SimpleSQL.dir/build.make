# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/renhoshizora/Learning/CMiniProjects/SimpleSQL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/build

# Include any dependencies generated for this target.
include CMakeFiles/SimpleSQL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SimpleSQL.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleSQL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleSQL.dir/flags.make

CMakeFiles/SimpleSQL.dir/src/input.c.o: CMakeFiles/SimpleSQL.dir/flags.make
CMakeFiles/SimpleSQL.dir/src/input.c.o: /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/src/input.c
CMakeFiles/SimpleSQL.dir/src/input.c.o: CMakeFiles/SimpleSQL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/renhoshizora/Learning/CMiniProjects/SimpleSQL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SimpleSQL.dir/src/input.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SimpleSQL.dir/src/input.c.o -MF CMakeFiles/SimpleSQL.dir/src/input.c.o.d -o CMakeFiles/SimpleSQL.dir/src/input.c.o -c /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/src/input.c

CMakeFiles/SimpleSQL.dir/src/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SimpleSQL.dir/src/input.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/src/input.c > CMakeFiles/SimpleSQL.dir/src/input.c.i

CMakeFiles/SimpleSQL.dir/src/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SimpleSQL.dir/src/input.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/src/input.c -o CMakeFiles/SimpleSQL.dir/src/input.c.s

CMakeFiles/SimpleSQL.dir/src/main.c.o: CMakeFiles/SimpleSQL.dir/flags.make
CMakeFiles/SimpleSQL.dir/src/main.c.o: /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/src/main.c
CMakeFiles/SimpleSQL.dir/src/main.c.o: CMakeFiles/SimpleSQL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/renhoshizora/Learning/CMiniProjects/SimpleSQL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SimpleSQL.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SimpleSQL.dir/src/main.c.o -MF CMakeFiles/SimpleSQL.dir/src/main.c.o.d -o CMakeFiles/SimpleSQL.dir/src/main.c.o -c /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/src/main.c

CMakeFiles/SimpleSQL.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SimpleSQL.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/src/main.c > CMakeFiles/SimpleSQL.dir/src/main.c.i

CMakeFiles/SimpleSQL.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SimpleSQL.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/src/main.c -o CMakeFiles/SimpleSQL.dir/src/main.c.s

# Object files for target SimpleSQL
SimpleSQL_OBJECTS = \
"CMakeFiles/SimpleSQL.dir/src/input.c.o" \
"CMakeFiles/SimpleSQL.dir/src/main.c.o"

# External object files for target SimpleSQL
SimpleSQL_EXTERNAL_OBJECTS =

SimpleSQL: CMakeFiles/SimpleSQL.dir/src/input.c.o
SimpleSQL: CMakeFiles/SimpleSQL.dir/src/main.c.o
SimpleSQL: CMakeFiles/SimpleSQL.dir/build.make
SimpleSQL: CMakeFiles/SimpleSQL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/renhoshizora/Learning/CMiniProjects/SimpleSQL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable SimpleSQL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimpleSQL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleSQL.dir/build: SimpleSQL
.PHONY : CMakeFiles/SimpleSQL.dir/build

CMakeFiles/SimpleSQL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimpleSQL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimpleSQL.dir/clean

CMakeFiles/SimpleSQL.dir/depend:
	cd /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/renhoshizora/Learning/CMiniProjects/SimpleSQL /home/renhoshizora/Learning/CMiniProjects/SimpleSQL /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/build /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/build /home/renhoshizora/Learning/CMiniProjects/SimpleSQL/build/CMakeFiles/SimpleSQL.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SimpleSQL.dir/depend

