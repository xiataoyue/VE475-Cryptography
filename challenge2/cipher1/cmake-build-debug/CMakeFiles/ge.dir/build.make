# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Jetbrains\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\Jetbrains\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\James Xia\Desktop\cipher1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\James Xia\Desktop\cipher1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ge.dir/flags.make

CMakeFiles/ge.dir/generate.cpp.obj: CMakeFiles/ge.dir/flags.make
CMakeFiles/ge.dir/generate.cpp.obj: ../generate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\James Xia\Desktop\cipher1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ge.dir/generate.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ge.dir\generate.cpp.obj -c "C:\Users\James Xia\Desktop\cipher1\generate.cpp"

CMakeFiles/ge.dir/generate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ge.dir/generate.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\James Xia\Desktop\cipher1\generate.cpp" > CMakeFiles\ge.dir\generate.cpp.i

CMakeFiles/ge.dir/generate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ge.dir/generate.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\James Xia\Desktop\cipher1\generate.cpp" -o CMakeFiles\ge.dir\generate.cpp.s

# Object files for target ge
ge_OBJECTS = \
"CMakeFiles/ge.dir/generate.cpp.obj"

# External object files for target ge
ge_EXTERNAL_OBJECTS =

ge.exe: CMakeFiles/ge.dir/generate.cpp.obj
ge.exe: CMakeFiles/ge.dir/build.make
ge.exe: CMakeFiles/ge.dir/linklibs.rsp
ge.exe: CMakeFiles/ge.dir/objects1.rsp
ge.exe: CMakeFiles/ge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\James Xia\Desktop\cipher1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ge.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ge.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ge.dir/build: ge.exe

.PHONY : CMakeFiles/ge.dir/build

CMakeFiles/ge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ge.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ge.dir/clean

CMakeFiles/ge.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\James Xia\Desktop\cipher1" "C:\Users\James Xia\Desktop\cipher1" "C:\Users\James Xia\Desktop\cipher1\cmake-build-debug" "C:\Users\James Xia\Desktop\cipher1\cmake-build-debug" "C:\Users\James Xia\Desktop\cipher1\cmake-build-debug\CMakeFiles\ge.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ge.dir/depend

