# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/12___3_10__Ack_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/12___3_10__Ack_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/12___3_10__Ack_.dir/flags.make

CMakeFiles/12___3_10__Ack_.dir/main.c.o: CMakeFiles/12___3_10__Ack_.dir/flags.make
CMakeFiles/12___3_10__Ack_.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/12___3_10__Ack_.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/12___3_10__Ack_.dir/main.c.o   -c "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)/main.c"

CMakeFiles/12___3_10__Ack_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/12___3_10__Ack_.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)/main.c" > CMakeFiles/12___3_10__Ack_.dir/main.c.i

CMakeFiles/12___3_10__Ack_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/12___3_10__Ack_.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)/main.c" -o CMakeFiles/12___3_10__Ack_.dir/main.c.s

# Object files for target 12___3_10__Ack_
12___3_10__Ack__OBJECTS = \
"CMakeFiles/12___3_10__Ack_.dir/main.c.o"

# External object files for target 12___3_10__Ack_
12___3_10__Ack__EXTERNAL_OBJECTS =

12___3_10__Ack_: CMakeFiles/12___3_10__Ack_.dir/main.c.o
12___3_10__Ack_: CMakeFiles/12___3_10__Ack_.dir/build.make
12___3_10__Ack_: CMakeFiles/12___3_10__Ack_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 12___3_10__Ack_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/12___3_10__Ack_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/12___3_10__Ack_.dir/build: 12___3_10__Ack_

.PHONY : CMakeFiles/12___3_10__Ack_.dir/build

CMakeFiles/12___3_10__Ack_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/12___3_10__Ack_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/12___3_10__Ack_.dir/clean

CMakeFiles/12___3_10__Ack_.dir/depend:
	cd "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)" "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)" "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)/cmake-build-debug" "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)/cmake-build-debug" "/Users/mxligr/Desktop/UNI/AN I/CP/LAB/lab12-recursion/12 - 3.10 (Ack)/cmake-build-debug/CMakeFiles/12___3_10__Ack_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/12___3_10__Ack_.dir/depend

