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
CMAKE_SOURCE_DIR = "C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ex6_gmp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex6_gmp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex6_gmp.dir/flags.make

CMakeFiles/ex6_gmp.dir/ex6_gmp.cpp.obj: CMakeFiles/ex6_gmp.dir/flags.make
CMakeFiles/ex6_gmp.dir/ex6_gmp.cpp.obj: ../ex6_gmp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex6_gmp.dir/ex6_gmp.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex6_gmp.dir\ex6_gmp.cpp.obj -c "C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6\ex6_gmp.cpp"

CMakeFiles/ex6_gmp.dir/ex6_gmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex6_gmp.dir/ex6_gmp.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6\ex6_gmp.cpp" > CMakeFiles\ex6_gmp.dir\ex6_gmp.cpp.i

CMakeFiles/ex6_gmp.dir/ex6_gmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex6_gmp.dir/ex6_gmp.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6\ex6_gmp.cpp" -o CMakeFiles\ex6_gmp.dir\ex6_gmp.cpp.s

# Object files for target ex6_gmp
ex6_gmp_OBJECTS = \
"CMakeFiles/ex6_gmp.dir/ex6_gmp.cpp.obj"

# External object files for target ex6_gmp
ex6_gmp_EXTERNAL_OBJECTS =

ex6_gmp.exe: CMakeFiles/ex6_gmp.dir/ex6_gmp.cpp.obj
ex6_gmp.exe: CMakeFiles/ex6_gmp.dir/build.make
ex6_gmp.exe: CMakeFiles/ex6_gmp.dir/linklibs.rsp
ex6_gmp.exe: CMakeFiles/ex6_gmp.dir/objects1.rsp
ex6_gmp.exe: CMakeFiles/ex6_gmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex6_gmp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex6_gmp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex6_gmp.dir/build: ex6_gmp.exe

.PHONY : CMakeFiles/ex6_gmp.dir/build

CMakeFiles/ex6_gmp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex6_gmp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex6_gmp.dir/clean

CMakeFiles/ex6_gmp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6" "C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6" "C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6\cmake-build-debug" "C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6\cmake-build-debug" "C:\Users\James Xia\Desktop\VE475 Cryptography\homework\h6\ex6\cmake-build-debug\CMakeFiles\ex6_gmp.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ex6_gmp.dir/depend

