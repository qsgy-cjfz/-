# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/qsgy/workspace/qsgy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qsgy/workspace/qsgy/build

# Include any dependencies generated for this target.
include CMakeFiles/qsgy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/qsgy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/qsgy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qsgy.dir/flags.make

CMakeFiles/qsgy.dir/qsgy/config.cc.o: CMakeFiles/qsgy.dir/flags.make
CMakeFiles/qsgy.dir/qsgy/config.cc.o: /home/qsgy/workspace/qsgy/qsgy/config.cc
CMakeFiles/qsgy.dir/qsgy/config.cc.o: CMakeFiles/qsgy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/qsgy/workspace/qsgy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/qsgy.dir/qsgy/config.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/config.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qsgy.dir/qsgy/config.cc.o -MF CMakeFiles/qsgy.dir/qsgy/config.cc.o.d -o CMakeFiles/qsgy.dir/qsgy/config.cc.o -c /home/qsgy/workspace/qsgy/qsgy/config.cc

CMakeFiles/qsgy.dir/qsgy/config.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qsgy.dir/qsgy/config.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/config.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qsgy/workspace/qsgy/qsgy/config.cc > CMakeFiles/qsgy.dir/qsgy/config.cc.i

CMakeFiles/qsgy.dir/qsgy/config.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qsgy.dir/qsgy/config.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/config.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qsgy/workspace/qsgy/qsgy/config.cc -o CMakeFiles/qsgy.dir/qsgy/config.cc.s

CMakeFiles/qsgy.dir/qsgy/fiber.cc.o: CMakeFiles/qsgy.dir/flags.make
CMakeFiles/qsgy.dir/qsgy/fiber.cc.o: /home/qsgy/workspace/qsgy/qsgy/fiber.cc
CMakeFiles/qsgy.dir/qsgy/fiber.cc.o: CMakeFiles/qsgy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/qsgy/workspace/qsgy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/qsgy.dir/qsgy/fiber.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/fiber.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qsgy.dir/qsgy/fiber.cc.o -MF CMakeFiles/qsgy.dir/qsgy/fiber.cc.o.d -o CMakeFiles/qsgy.dir/qsgy/fiber.cc.o -c /home/qsgy/workspace/qsgy/qsgy/fiber.cc

CMakeFiles/qsgy.dir/qsgy/fiber.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qsgy.dir/qsgy/fiber.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/fiber.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qsgy/workspace/qsgy/qsgy/fiber.cc > CMakeFiles/qsgy.dir/qsgy/fiber.cc.i

CMakeFiles/qsgy.dir/qsgy/fiber.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qsgy.dir/qsgy/fiber.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/fiber.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qsgy/workspace/qsgy/qsgy/fiber.cc -o CMakeFiles/qsgy.dir/qsgy/fiber.cc.s

CMakeFiles/qsgy.dir/qsgy/log.cc.o: CMakeFiles/qsgy.dir/flags.make
CMakeFiles/qsgy.dir/qsgy/log.cc.o: /home/qsgy/workspace/qsgy/qsgy/log.cc
CMakeFiles/qsgy.dir/qsgy/log.cc.o: CMakeFiles/qsgy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/qsgy/workspace/qsgy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/qsgy.dir/qsgy/log.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/log.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qsgy.dir/qsgy/log.cc.o -MF CMakeFiles/qsgy.dir/qsgy/log.cc.o.d -o CMakeFiles/qsgy.dir/qsgy/log.cc.o -c /home/qsgy/workspace/qsgy/qsgy/log.cc

CMakeFiles/qsgy.dir/qsgy/log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qsgy.dir/qsgy/log.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/log.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qsgy/workspace/qsgy/qsgy/log.cc > CMakeFiles/qsgy.dir/qsgy/log.cc.i

CMakeFiles/qsgy.dir/qsgy/log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qsgy.dir/qsgy/log.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/log.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qsgy/workspace/qsgy/qsgy/log.cc -o CMakeFiles/qsgy.dir/qsgy/log.cc.s

CMakeFiles/qsgy.dir/qsgy/thread.cc.o: CMakeFiles/qsgy.dir/flags.make
CMakeFiles/qsgy.dir/qsgy/thread.cc.o: /home/qsgy/workspace/qsgy/qsgy/thread.cc
CMakeFiles/qsgy.dir/qsgy/thread.cc.o: CMakeFiles/qsgy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/qsgy/workspace/qsgy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/qsgy.dir/qsgy/thread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/thread.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qsgy.dir/qsgy/thread.cc.o -MF CMakeFiles/qsgy.dir/qsgy/thread.cc.o.d -o CMakeFiles/qsgy.dir/qsgy/thread.cc.o -c /home/qsgy/workspace/qsgy/qsgy/thread.cc

CMakeFiles/qsgy.dir/qsgy/thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qsgy.dir/qsgy/thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/thread.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qsgy/workspace/qsgy/qsgy/thread.cc > CMakeFiles/qsgy.dir/qsgy/thread.cc.i

CMakeFiles/qsgy.dir/qsgy/thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qsgy.dir/qsgy/thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/thread.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qsgy/workspace/qsgy/qsgy/thread.cc -o CMakeFiles/qsgy.dir/qsgy/thread.cc.s

CMakeFiles/qsgy.dir/qsgy/scheduler.cc.o: CMakeFiles/qsgy.dir/flags.make
CMakeFiles/qsgy.dir/qsgy/scheduler.cc.o: /home/qsgy/workspace/qsgy/qsgy/scheduler.cc
CMakeFiles/qsgy.dir/qsgy/scheduler.cc.o: CMakeFiles/qsgy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/qsgy/workspace/qsgy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/qsgy.dir/qsgy/scheduler.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/scheduler.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qsgy.dir/qsgy/scheduler.cc.o -MF CMakeFiles/qsgy.dir/qsgy/scheduler.cc.o.d -o CMakeFiles/qsgy.dir/qsgy/scheduler.cc.o -c /home/qsgy/workspace/qsgy/qsgy/scheduler.cc

CMakeFiles/qsgy.dir/qsgy/scheduler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qsgy.dir/qsgy/scheduler.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/scheduler.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qsgy/workspace/qsgy/qsgy/scheduler.cc > CMakeFiles/qsgy.dir/qsgy/scheduler.cc.i

CMakeFiles/qsgy.dir/qsgy/scheduler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qsgy.dir/qsgy/scheduler.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/scheduler.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qsgy/workspace/qsgy/qsgy/scheduler.cc -o CMakeFiles/qsgy.dir/qsgy/scheduler.cc.s

CMakeFiles/qsgy.dir/qsgy/util.cc.o: CMakeFiles/qsgy.dir/flags.make
CMakeFiles/qsgy.dir/qsgy/util.cc.o: /home/qsgy/workspace/qsgy/qsgy/util.cc
CMakeFiles/qsgy.dir/qsgy/util.cc.o: CMakeFiles/qsgy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/qsgy/workspace/qsgy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/qsgy.dir/qsgy/util.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/util.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qsgy.dir/qsgy/util.cc.o -MF CMakeFiles/qsgy.dir/qsgy/util.cc.o.d -o CMakeFiles/qsgy.dir/qsgy/util.cc.o -c /home/qsgy/workspace/qsgy/qsgy/util.cc

CMakeFiles/qsgy.dir/qsgy/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qsgy.dir/qsgy/util.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/util.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qsgy/workspace/qsgy/qsgy/util.cc > CMakeFiles/qsgy.dir/qsgy/util.cc.i

CMakeFiles/qsgy.dir/qsgy/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qsgy.dir/qsgy/util.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"qsgy/util.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qsgy/workspace/qsgy/qsgy/util.cc -o CMakeFiles/qsgy.dir/qsgy/util.cc.s

# Object files for target qsgy
qsgy_OBJECTS = \
"CMakeFiles/qsgy.dir/qsgy/config.cc.o" \
"CMakeFiles/qsgy.dir/qsgy/fiber.cc.o" \
"CMakeFiles/qsgy.dir/qsgy/log.cc.o" \
"CMakeFiles/qsgy.dir/qsgy/thread.cc.o" \
"CMakeFiles/qsgy.dir/qsgy/scheduler.cc.o" \
"CMakeFiles/qsgy.dir/qsgy/util.cc.o"

# External object files for target qsgy
qsgy_EXTERNAL_OBJECTS =

/home/qsgy/workspace/qsgy/lib/libqsgy.so: CMakeFiles/qsgy.dir/qsgy/config.cc.o
/home/qsgy/workspace/qsgy/lib/libqsgy.so: CMakeFiles/qsgy.dir/qsgy/fiber.cc.o
/home/qsgy/workspace/qsgy/lib/libqsgy.so: CMakeFiles/qsgy.dir/qsgy/log.cc.o
/home/qsgy/workspace/qsgy/lib/libqsgy.so: CMakeFiles/qsgy.dir/qsgy/thread.cc.o
/home/qsgy/workspace/qsgy/lib/libqsgy.so: CMakeFiles/qsgy.dir/qsgy/scheduler.cc.o
/home/qsgy/workspace/qsgy/lib/libqsgy.so: CMakeFiles/qsgy.dir/qsgy/util.cc.o
/home/qsgy/workspace/qsgy/lib/libqsgy.so: CMakeFiles/qsgy.dir/build.make
/home/qsgy/workspace/qsgy/lib/libqsgy.so: CMakeFiles/qsgy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/qsgy/workspace/qsgy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library /home/qsgy/workspace/qsgy/lib/libqsgy.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qsgy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qsgy.dir/build: /home/qsgy/workspace/qsgy/lib/libqsgy.so
.PHONY : CMakeFiles/qsgy.dir/build

CMakeFiles/qsgy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qsgy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qsgy.dir/clean

CMakeFiles/qsgy.dir/depend:
	cd /home/qsgy/workspace/qsgy/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qsgy/workspace/qsgy /home/qsgy/workspace/qsgy /home/qsgy/workspace/qsgy/build /home/qsgy/workspace/qsgy/build /home/qsgy/workspace/qsgy/build/CMakeFiles/qsgy.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/qsgy.dir/depend

