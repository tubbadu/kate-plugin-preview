# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /home/tubbadu/code/kate-plugin/markdown-preview

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tubbadu/code/kate-plugin/markdown-preview/build

# Include any dependencies generated for this target.
include CMakeFiles/markdownpreview.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/markdownpreview.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/markdownpreview.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/markdownpreview.dir/flags.make

CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.o: CMakeFiles/markdownpreview.dir/flags.make
CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.o: markdownpreview_autogen/mocs_compilation.cpp
CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.o: CMakeFiles/markdownpreview.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tubbadu/code/kate-plugin/markdown-preview/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.o -MF CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.o -c /home/tubbadu/code/kate-plugin/markdown-preview/build/markdownpreview_autogen/mocs_compilation.cpp

CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tubbadu/code/kate-plugin/markdown-preview/build/markdownpreview_autogen/mocs_compilation.cpp > CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.i

CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tubbadu/code/kate-plugin/markdown-preview/build/markdownpreview_autogen/mocs_compilation.cpp -o CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.s

CMakeFiles/markdownpreview.dir/plugin.cpp.o: CMakeFiles/markdownpreview.dir/flags.make
CMakeFiles/markdownpreview.dir/plugin.cpp.o: /home/tubbadu/code/kate-plugin/markdown-preview/plugin.cpp
CMakeFiles/markdownpreview.dir/plugin.cpp.o: CMakeFiles/markdownpreview.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tubbadu/code/kate-plugin/markdown-preview/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/markdownpreview.dir/plugin.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/markdownpreview.dir/plugin.cpp.o -MF CMakeFiles/markdownpreview.dir/plugin.cpp.o.d -o CMakeFiles/markdownpreview.dir/plugin.cpp.o -c /home/tubbadu/code/kate-plugin/markdown-preview/plugin.cpp

CMakeFiles/markdownpreview.dir/plugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/markdownpreview.dir/plugin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tubbadu/code/kate-plugin/markdown-preview/plugin.cpp > CMakeFiles/markdownpreview.dir/plugin.cpp.i

CMakeFiles/markdownpreview.dir/plugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/markdownpreview.dir/plugin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tubbadu/code/kate-plugin/markdown-preview/plugin.cpp -o CMakeFiles/markdownpreview.dir/plugin.cpp.s

# Object files for target markdownpreview
markdownpreview_OBJECTS = \
"CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/markdownpreview.dir/plugin.cpp.o"

# External object files for target markdownpreview
markdownpreview_EXTERNAL_OBJECTS =

markdownpreview.so: CMakeFiles/markdownpreview.dir/markdownpreview_autogen/mocs_compilation.cpp.o
markdownpreview.so: CMakeFiles/markdownpreview.dir/plugin.cpp.o
markdownpreview.so: CMakeFiles/markdownpreview.dir/build.make
markdownpreview.so: /usr/lib64/libX11.so
markdownpreview.so: CMakeFiles/markdownpreview.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tubbadu/code/kate-plugin/markdown-preview/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared module markdownpreview.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/markdownpreview.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/markdownpreview.dir/build: markdownpreview.so
.PHONY : CMakeFiles/markdownpreview.dir/build

CMakeFiles/markdownpreview.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/markdownpreview.dir/cmake_clean.cmake
.PHONY : CMakeFiles/markdownpreview.dir/clean

CMakeFiles/markdownpreview.dir/depend:
	cd /home/tubbadu/code/kate-plugin/markdown-preview/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tubbadu/code/kate-plugin/markdown-preview /home/tubbadu/code/kate-plugin/markdown-preview /home/tubbadu/code/kate-plugin/markdown-preview/build /home/tubbadu/code/kate-plugin/markdown-preview/build /home/tubbadu/code/kate-plugin/markdown-preview/build/CMakeFiles/markdownpreview.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/markdownpreview.dir/depend

