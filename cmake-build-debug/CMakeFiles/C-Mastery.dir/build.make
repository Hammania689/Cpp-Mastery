# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files(x86) - data drive\apps\CLion\ch-0\172.3544.40\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files(x86) - data drive\apps\CLion\ch-0\172.3544.40\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Documents - data drive\Github\Cpp-Mastery"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Documents - data drive\Github\Cpp-Mastery\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/C-Mastery.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C-Mastery.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C-Mastery.dir/flags.make

CMakeFiles/C-Mastery.dir/main.cpp.obj: CMakeFiles/C-Mastery.dir/flags.make
CMakeFiles/C-Mastery.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documents - data drive\Github\Cpp-Mastery\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C-Mastery.dir/main.cpp.obj"
	C:\tools\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\C-Mastery.dir\main.cpp.obj -c "D:\Documents - data drive\Github\Cpp-Mastery\main.cpp"

CMakeFiles/C-Mastery.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C-Mastery.dir/main.cpp.i"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents - data drive\Github\Cpp-Mastery\main.cpp" > CMakeFiles\C-Mastery.dir\main.cpp.i

CMakeFiles/C-Mastery.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C-Mastery.dir/main.cpp.s"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents - data drive\Github\Cpp-Mastery\main.cpp" -o CMakeFiles\C-Mastery.dir\main.cpp.s

CMakeFiles/C-Mastery.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/C-Mastery.dir/main.cpp.obj.requires

CMakeFiles/C-Mastery.dir/main.cpp.obj.provides: CMakeFiles/C-Mastery.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\C-Mastery.dir\build.make CMakeFiles/C-Mastery.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/C-Mastery.dir/main.cpp.obj.provides

CMakeFiles/C-Mastery.dir/main.cpp.obj.provides.build: CMakeFiles/C-Mastery.dir/main.cpp.obj


CMakeFiles/C-Mastery.dir/Maps.cpp.obj: CMakeFiles/C-Mastery.dir/flags.make
CMakeFiles/C-Mastery.dir/Maps.cpp.obj: ../Maps.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documents - data drive\Github\Cpp-Mastery\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/C-Mastery.dir/Maps.cpp.obj"
	C:\tools\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\C-Mastery.dir\Maps.cpp.obj -c "D:\Documents - data drive\Github\Cpp-Mastery\Maps.cpp"

CMakeFiles/C-Mastery.dir/Maps.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C-Mastery.dir/Maps.cpp.i"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents - data drive\Github\Cpp-Mastery\Maps.cpp" > CMakeFiles\C-Mastery.dir\Maps.cpp.i

CMakeFiles/C-Mastery.dir/Maps.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C-Mastery.dir/Maps.cpp.s"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents - data drive\Github\Cpp-Mastery\Maps.cpp" -o CMakeFiles\C-Mastery.dir\Maps.cpp.s

CMakeFiles/C-Mastery.dir/Maps.cpp.obj.requires:

.PHONY : CMakeFiles/C-Mastery.dir/Maps.cpp.obj.requires

CMakeFiles/C-Mastery.dir/Maps.cpp.obj.provides: CMakeFiles/C-Mastery.dir/Maps.cpp.obj.requires
	$(MAKE) -f CMakeFiles\C-Mastery.dir\build.make CMakeFiles/C-Mastery.dir/Maps.cpp.obj.provides.build
.PHONY : CMakeFiles/C-Mastery.dir/Maps.cpp.obj.provides

CMakeFiles/C-Mastery.dir/Maps.cpp.obj.provides.build: CMakeFiles/C-Mastery.dir/Maps.cpp.obj


# Object files for target C-Mastery
C__Mastery_OBJECTS = \
"CMakeFiles/C-Mastery.dir/main.cpp.obj" \
"CMakeFiles/C-Mastery.dir/Maps.cpp.obj"

# External object files for target C-Mastery
C__Mastery_EXTERNAL_OBJECTS =

C-Mastery.exe: CMakeFiles/C-Mastery.dir/main.cpp.obj
C-Mastery.exe: CMakeFiles/C-Mastery.dir/Maps.cpp.obj
C-Mastery.exe: CMakeFiles/C-Mastery.dir/build.make
C-Mastery.exe: CMakeFiles/C-Mastery.dir/linklibs.rsp
C-Mastery.exe: CMakeFiles/C-Mastery.dir/objects1.rsp
C-Mastery.exe: CMakeFiles/C-Mastery.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Documents - data drive\Github\Cpp-Mastery\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable C-Mastery.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\C-Mastery.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C-Mastery.dir/build: C-Mastery.exe

.PHONY : CMakeFiles/C-Mastery.dir/build

CMakeFiles/C-Mastery.dir/requires: CMakeFiles/C-Mastery.dir/main.cpp.obj.requires
CMakeFiles/C-Mastery.dir/requires: CMakeFiles/C-Mastery.dir/Maps.cpp.obj.requires

.PHONY : CMakeFiles/C-Mastery.dir/requires

CMakeFiles/C-Mastery.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C-Mastery.dir\cmake_clean.cmake
.PHONY : CMakeFiles/C-Mastery.dir/clean

CMakeFiles/C-Mastery.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Documents - data drive\Github\Cpp-Mastery" "D:\Documents - data drive\Github\Cpp-Mastery" "D:\Documents - data drive\Github\Cpp-Mastery\cmake-build-debug" "D:\Documents - data drive\Github\Cpp-Mastery\cmake-build-debug" "D:\Documents - data drive\Github\Cpp-Mastery\cmake-build-debug\CMakeFiles\C-Mastery.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/C-Mastery.dir/depend

