# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yan/Desktop/practices/learnSlamfrom0/003_practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yan/Desktop/practices/learnSlamfrom0/003_practice/build

# Include any dependencies generated for this target.
include CMakeFiles/my_sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_sort.dir/flags.make

CMakeFiles/my_sort.dir/my_sort.cpp.o: CMakeFiles/my_sort.dir/flags.make
CMakeFiles/my_sort.dir/my_sort.cpp.o: ../my_sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/Desktop/practices/learnSlamfrom0/003_practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_sort.dir/my_sort.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_sort.dir/my_sort.cpp.o -c /home/yan/Desktop/practices/learnSlamfrom0/003_practice/my_sort.cpp

CMakeFiles/my_sort.dir/my_sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_sort.dir/my_sort.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/Desktop/practices/learnSlamfrom0/003_practice/my_sort.cpp > CMakeFiles/my_sort.dir/my_sort.cpp.i

CMakeFiles/my_sort.dir/my_sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_sort.dir/my_sort.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/Desktop/practices/learnSlamfrom0/003_practice/my_sort.cpp -o CMakeFiles/my_sort.dir/my_sort.cpp.s

CMakeFiles/my_sort.dir/my_sort.cpp.o.requires:

.PHONY : CMakeFiles/my_sort.dir/my_sort.cpp.o.requires

CMakeFiles/my_sort.dir/my_sort.cpp.o.provides: CMakeFiles/my_sort.dir/my_sort.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_sort.dir/build.make CMakeFiles/my_sort.dir/my_sort.cpp.o.provides.build
.PHONY : CMakeFiles/my_sort.dir/my_sort.cpp.o.provides

CMakeFiles/my_sort.dir/my_sort.cpp.o.provides.build: CMakeFiles/my_sort.dir/my_sort.cpp.o


# Object files for target my_sort
my_sort_OBJECTS = \
"CMakeFiles/my_sort.dir/my_sort.cpp.o"

# External object files for target my_sort
my_sort_EXTERNAL_OBJECTS =

my_sort: CMakeFiles/my_sort.dir/my_sort.cpp.o
my_sort: CMakeFiles/my_sort.dir/build.make
my_sort: /usr/local/lib/libopencv_dnn.so.3.3.1
my_sort: /usr/local/lib/libopencv_ml.so.3.3.1
my_sort: /usr/local/lib/libopencv_objdetect.so.3.3.1
my_sort: /usr/local/lib/libopencv_shape.so.3.3.1
my_sort: /usr/local/lib/libopencv_stitching.so.3.3.1
my_sort: /usr/local/lib/libopencv_superres.so.3.3.1
my_sort: /usr/local/lib/libopencv_videostab.so.3.3.1
my_sort: /usr/local/lib/libopencv_viz.so.3.3.1
my_sort: /usr/local/lib/libopencv_calib3d.so.3.3.1
my_sort: /usr/local/lib/libopencv_features2d.so.3.3.1
my_sort: /usr/local/lib/libopencv_flann.so.3.3.1
my_sort: /usr/local/lib/libopencv_highgui.so.3.3.1
my_sort: /usr/local/lib/libopencv_photo.so.3.3.1
my_sort: /usr/local/lib/libopencv_video.so.3.3.1
my_sort: /usr/local/lib/libopencv_videoio.so.3.3.1
my_sort: /usr/local/lib/libopencv_imgcodecs.so.3.3.1
my_sort: /usr/local/lib/libopencv_imgproc.so.3.3.1
my_sort: /usr/local/lib/libopencv_core.so.3.3.1
my_sort: CMakeFiles/my_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yan/Desktop/practices/learnSlamfrom0/003_practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my_sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_sort.dir/build: my_sort

.PHONY : CMakeFiles/my_sort.dir/build

CMakeFiles/my_sort.dir/requires: CMakeFiles/my_sort.dir/my_sort.cpp.o.requires

.PHONY : CMakeFiles/my_sort.dir/requires

CMakeFiles/my_sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_sort.dir/clean

CMakeFiles/my_sort.dir/depend:
	cd /home/yan/Desktop/practices/learnSlamfrom0/003_practice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yan/Desktop/practices/learnSlamfrom0/003_practice /home/yan/Desktop/practices/learnSlamfrom0/003_practice /home/yan/Desktop/practices/learnSlamfrom0/003_practice/build /home/yan/Desktop/practices/learnSlamfrom0/003_practice/build /home/yan/Desktop/practices/learnSlamfrom0/003_practice/build/CMakeFiles/my_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_sort.dir/depend

