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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marcussss1/Algorithms-course

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcussss1/Algorithms-course/build

# Include any dependencies generated for this target.
include CMakeFiles/graph.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/graph.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/graph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graph.dir/flags.make

CMakeFiles/graph.dir/main.cpp.o: CMakeFiles/graph.dir/flags.make
CMakeFiles/graph.dir/main.cpp.o: /home/marcussss1/Algorithms-course/main.cpp
CMakeFiles/graph.dir/main.cpp.o: CMakeFiles/graph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/Algorithms-course/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graph.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph.dir/main.cpp.o -MF CMakeFiles/graph.dir/main.cpp.o.d -o CMakeFiles/graph.dir/main.cpp.o -c /home/marcussss1/Algorithms-course/main.cpp

CMakeFiles/graph.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/Algorithms-course/main.cpp > CMakeFiles/graph.dir/main.cpp.i

CMakeFiles/graph.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/Algorithms-course/main.cpp -o CMakeFiles/graph.dir/main.cpp.s

CMakeFiles/graph.dir/arcGraph.cpp.o: CMakeFiles/graph.dir/flags.make
CMakeFiles/graph.dir/arcGraph.cpp.o: /home/marcussss1/Algorithms-course/arcGraph.cpp
CMakeFiles/graph.dir/arcGraph.cpp.o: CMakeFiles/graph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/Algorithms-course/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graph.dir/arcGraph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph.dir/arcGraph.cpp.o -MF CMakeFiles/graph.dir/arcGraph.cpp.o.d -o CMakeFiles/graph.dir/arcGraph.cpp.o -c /home/marcussss1/Algorithms-course/arcGraph.cpp

CMakeFiles/graph.dir/arcGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph.dir/arcGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/Algorithms-course/arcGraph.cpp > CMakeFiles/graph.dir/arcGraph.cpp.i

CMakeFiles/graph.dir/arcGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph.dir/arcGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/Algorithms-course/arcGraph.cpp -o CMakeFiles/graph.dir/arcGraph.cpp.s

CMakeFiles/graph.dir/listGraph.cpp.o: CMakeFiles/graph.dir/flags.make
CMakeFiles/graph.dir/listGraph.cpp.o: /home/marcussss1/Algorithms-course/listGraph.cpp
CMakeFiles/graph.dir/listGraph.cpp.o: CMakeFiles/graph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/Algorithms-course/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/graph.dir/listGraph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph.dir/listGraph.cpp.o -MF CMakeFiles/graph.dir/listGraph.cpp.o.d -o CMakeFiles/graph.dir/listGraph.cpp.o -c /home/marcussss1/Algorithms-course/listGraph.cpp

CMakeFiles/graph.dir/listGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph.dir/listGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/Algorithms-course/listGraph.cpp > CMakeFiles/graph.dir/listGraph.cpp.i

CMakeFiles/graph.dir/listGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph.dir/listGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/Algorithms-course/listGraph.cpp -o CMakeFiles/graph.dir/listGraph.cpp.s

CMakeFiles/graph.dir/matrixGraph.cpp.o: CMakeFiles/graph.dir/flags.make
CMakeFiles/graph.dir/matrixGraph.cpp.o: /home/marcussss1/Algorithms-course/matrixGraph.cpp
CMakeFiles/graph.dir/matrixGraph.cpp.o: CMakeFiles/graph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/Algorithms-course/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/graph.dir/matrixGraph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph.dir/matrixGraph.cpp.o -MF CMakeFiles/graph.dir/matrixGraph.cpp.o.d -o CMakeFiles/graph.dir/matrixGraph.cpp.o -c /home/marcussss1/Algorithms-course/matrixGraph.cpp

CMakeFiles/graph.dir/matrixGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph.dir/matrixGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/Algorithms-course/matrixGraph.cpp > CMakeFiles/graph.dir/matrixGraph.cpp.i

CMakeFiles/graph.dir/matrixGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph.dir/matrixGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/Algorithms-course/matrixGraph.cpp -o CMakeFiles/graph.dir/matrixGraph.cpp.s

CMakeFiles/graph.dir/setGraph.cpp.o: CMakeFiles/graph.dir/flags.make
CMakeFiles/graph.dir/setGraph.cpp.o: /home/marcussss1/Algorithms-course/setGraph.cpp
CMakeFiles/graph.dir/setGraph.cpp.o: CMakeFiles/graph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/Algorithms-course/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/graph.dir/setGraph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph.dir/setGraph.cpp.o -MF CMakeFiles/graph.dir/setGraph.cpp.o.d -o CMakeFiles/graph.dir/setGraph.cpp.o -c /home/marcussss1/Algorithms-course/setGraph.cpp

CMakeFiles/graph.dir/setGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph.dir/setGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/Algorithms-course/setGraph.cpp > CMakeFiles/graph.dir/setGraph.cpp.i

CMakeFiles/graph.dir/setGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph.dir/setGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/Algorithms-course/setGraph.cpp -o CMakeFiles/graph.dir/setGraph.cpp.s

# Object files for target graph
graph_OBJECTS = \
"CMakeFiles/graph.dir/main.cpp.o" \
"CMakeFiles/graph.dir/arcGraph.cpp.o" \
"CMakeFiles/graph.dir/listGraph.cpp.o" \
"CMakeFiles/graph.dir/matrixGraph.cpp.o" \
"CMakeFiles/graph.dir/setGraph.cpp.o"

# External object files for target graph
graph_EXTERNAL_OBJECTS =

graph: CMakeFiles/graph.dir/main.cpp.o
graph: CMakeFiles/graph.dir/arcGraph.cpp.o
graph: CMakeFiles/graph.dir/listGraph.cpp.o
graph: CMakeFiles/graph.dir/matrixGraph.cpp.o
graph: CMakeFiles/graph.dir/setGraph.cpp.o
graph: CMakeFiles/graph.dir/build.make
graph: CMakeFiles/graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marcussss1/Algorithms-course/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable graph"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graph.dir/build: graph
.PHONY : CMakeFiles/graph.dir/build

CMakeFiles/graph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graph.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graph.dir/clean

CMakeFiles/graph.dir/depend:
	cd /home/marcussss1/Algorithms-course/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcussss1/Algorithms-course /home/marcussss1/Algorithms-course /home/marcussss1/Algorithms-course/build /home/marcussss1/Algorithms-course/build /home/marcussss1/Algorithms-course/build/CMakeFiles/graph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graph.dir/depend
