# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/shizde/Projects/huffman_compressor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shizde/Projects/huffman_compressor/build

# Include any dependencies generated for this target.
include CMakeFiles/compression.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/compression.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/compression.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/compression.dir/flags.make

CMakeFiles/compression.dir/codegen:
.PHONY : CMakeFiles/compression.dir/codegen

CMakeFiles/compression.dir/compression.cpp.o: CMakeFiles/compression.dir/flags.make
CMakeFiles/compression.dir/compression.cpp.o: /home/shizde/Projects/huffman_compressor/compression.cpp
CMakeFiles/compression.dir/compression.cpp.o: CMakeFiles/compression.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shizde/Projects/huffman_compressor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/compression.dir/compression.cpp.o"
	/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/compression.dir/compression.cpp.o -MF CMakeFiles/compression.dir/compression.cpp.o.d -o CMakeFiles/compression.dir/compression.cpp.o -c /home/shizde/Projects/huffman_compressor/compression.cpp

CMakeFiles/compression.dir/compression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/compression.dir/compression.cpp.i"
	/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shizde/Projects/huffman_compressor/compression.cpp > CMakeFiles/compression.dir/compression.cpp.i

CMakeFiles/compression.dir/compression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/compression.dir/compression.cpp.s"
	/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shizde/Projects/huffman_compressor/compression.cpp -o CMakeFiles/compression.dir/compression.cpp.s

# Object files for target compression
compression_OBJECTS = \
"CMakeFiles/compression.dir/compression.cpp.o"

# External object files for target compression
compression_EXTERNAL_OBJECTS =

libcompression.a: CMakeFiles/compression.dir/compression.cpp.o
libcompression.a: CMakeFiles/compression.dir/build.make
libcompression.a: CMakeFiles/compression.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/shizde/Projects/huffman_compressor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcompression.a"
	$(CMAKE_COMMAND) -P CMakeFiles/compression.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compression.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/compression.dir/build: libcompression.a
.PHONY : CMakeFiles/compression.dir/build

CMakeFiles/compression.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/compression.dir/cmake_clean.cmake
.PHONY : CMakeFiles/compression.dir/clean

CMakeFiles/compression.dir/depend:
	cd /home/shizde/Projects/huffman_compressor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shizde/Projects/huffman_compressor /home/shizde/Projects/huffman_compressor /home/shizde/Projects/huffman_compressor/build /home/shizde/Projects/huffman_compressor/build /home/shizde/Projects/huffman_compressor/build/CMakeFiles/compression.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/compression.dir/depend
