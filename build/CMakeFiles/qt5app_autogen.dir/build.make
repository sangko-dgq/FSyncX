# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = D:\Qt5\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = D:\Qt5\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\22012\Desktop\FSyncX\FSyncX

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\22012\Desktop\FSyncX\FSyncX\build

# Utility rule file for qt5app_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/qt5app_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/qt5app_autogen.dir/progress.make

CMakeFiles/qt5app_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\22012\Desktop\FSyncX\FSyncX\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target qt5app"
	D:\Qt5\Tools\CMake_64\bin\cmake.exe -E cmake_autogen C:/Users/22012/Desktop/FSyncX/FSyncX/build/CMakeFiles/qt5app_autogen.dir/AutogenInfo.json Debug

qt5app_autogen: CMakeFiles/qt5app_autogen
qt5app_autogen: CMakeFiles/qt5app_autogen.dir/build.make
.PHONY : qt5app_autogen

# Rule to build all files generated by this target.
CMakeFiles/qt5app_autogen.dir/build: qt5app_autogen
.PHONY : CMakeFiles/qt5app_autogen.dir/build

CMakeFiles/qt5app_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\qt5app_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/qt5app_autogen.dir/clean

CMakeFiles/qt5app_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\22012\Desktop\FSyncX\FSyncX C:\Users\22012\Desktop\FSyncX\FSyncX C:\Users\22012\Desktop\FSyncX\FSyncX\build C:\Users\22012\Desktop\FSyncX\FSyncX\build C:\Users\22012\Desktop\FSyncX\FSyncX\build\CMakeFiles\qt5app_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qt5app_autogen.dir/depend
