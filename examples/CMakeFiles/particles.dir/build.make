# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ASUS\Documents\Program\C++\Rederer2

# Include any dependencies generated for this target.
include examples/CMakeFiles/particles.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/particles.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/particles.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/particles.dir/flags.make

examples/CMakeFiles/particles.dir/particles.c.obj: examples/CMakeFiles/particles.dir/flags.make
examples/CMakeFiles/particles.dir/particles.c.obj: examples/CMakeFiles/particles.dir/includes_C.rsp
examples/CMakeFiles/particles.dir/particles.c.obj: C:/Users/ASUS/Documents/Program/C++/glfw-3.3.3/examples/particles.c
examples/CMakeFiles/particles.dir/particles.c.obj: examples/CMakeFiles/particles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ASUS\Documents\Program\C++\Rederer2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/particles.dir/particles.c.obj"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/particles.dir/particles.c.obj -MF CMakeFiles\particles.dir\particles.c.obj.d -o CMakeFiles\particles.dir\particles.c.obj -c C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\examples\particles.c

examples/CMakeFiles/particles.dir/particles.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/particles.c.i"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\examples\particles.c > CMakeFiles\particles.dir\particles.c.i

examples/CMakeFiles/particles.dir/particles.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/particles.c.s"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\examples\particles.c -o CMakeFiles\particles.dir\particles.c.s

examples/CMakeFiles/particles.dir/glfw.rc.obj: examples/CMakeFiles/particles.dir/flags.make
examples/CMakeFiles/particles.dir/glfw.rc.obj: C:/Users/ASUS/Documents/Program/C++/glfw-3.3.3/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ASUS\Documents\Program\C++\Rederer2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object examples/CMakeFiles/particles.dir/glfw.rc.obj"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\examples\glfw.rc CMakeFiles\particles.dir\glfw.rc.obj

examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj: examples/CMakeFiles/particles.dir/flags.make
examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj: examples/CMakeFiles/particles.dir/includes_C.rsp
examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj: C:/Users/ASUS/Documents/Program/C++/glfw-3.3.3/deps/tinycthread.c
examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj: examples/CMakeFiles/particles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ASUS\Documents\Program\C++\Rederer2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj -MF CMakeFiles\particles.dir\__\deps\tinycthread.c.obj.d -o CMakeFiles\particles.dir\__\deps\tinycthread.c.obj -c C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\deps\tinycthread.c

examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/__/deps/tinycthread.c.i"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\deps\tinycthread.c > CMakeFiles\particles.dir\__\deps\tinycthread.c.i

examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/__/deps/tinycthread.c.s"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\deps\tinycthread.c -o CMakeFiles\particles.dir\__\deps\tinycthread.c.s

examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj: examples/CMakeFiles/particles.dir/flags.make
examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj: examples/CMakeFiles/particles.dir/includes_C.rsp
examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj: C:/Users/ASUS/Documents/Program/C++/glfw-3.3.3/deps/getopt.c
examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj: examples/CMakeFiles/particles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ASUS\Documents\Program\C++\Rederer2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj -MF CMakeFiles\particles.dir\__\deps\getopt.c.obj.d -o CMakeFiles\particles.dir\__\deps\getopt.c.obj -c C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\deps\getopt.c

examples/CMakeFiles/particles.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/__/deps/getopt.c.i"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\deps\getopt.c > CMakeFiles\particles.dir\__\deps\getopt.c.i

examples/CMakeFiles/particles.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/__/deps/getopt.c.s"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\deps\getopt.c -o CMakeFiles\particles.dir\__\deps\getopt.c.s

examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj: examples/CMakeFiles/particles.dir/flags.make
examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj: examples/CMakeFiles/particles.dir/includes_C.rsp
examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj: C:/Users/ASUS/Documents/Program/C++/glfw-3.3.3/deps/glad_gl.c
examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj: examples/CMakeFiles/particles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ASUS\Documents\Program\C++\Rederer2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\particles.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\particles.dir\__\deps\glad_gl.c.obj -c C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\deps\glad_gl.c

examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\deps\glad_gl.c > CMakeFiles\particles.dir\__\deps\glad_gl.c.i

examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\deps\glad_gl.c -o CMakeFiles\particles.dir\__\deps\glad_gl.c.s

# Object files for target particles
particles_OBJECTS = \
"CMakeFiles/particles.dir/particles.c.obj" \
"CMakeFiles/particles.dir/glfw.rc.obj" \
"CMakeFiles/particles.dir/__/deps/tinycthread.c.obj" \
"CMakeFiles/particles.dir/__/deps/getopt.c.obj" \
"CMakeFiles/particles.dir/__/deps/glad_gl.c.obj"

# External object files for target particles
particles_EXTERNAL_OBJECTS =

examples/particles.exe: examples/CMakeFiles/particles.dir/particles.c.obj
examples/particles.exe: examples/CMakeFiles/particles.dir/glfw.rc.obj
examples/particles.exe: examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj
examples/particles.exe: examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj
examples/particles.exe: examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj
examples/particles.exe: examples/CMakeFiles/particles.dir/build.make
examples/particles.exe: src/libglfw3.a
examples/particles.exe: examples/CMakeFiles/particles.dir/linklibs.rsp
examples/particles.exe: examples/CMakeFiles/particles.dir/objects1.rsp
examples/particles.exe: examples/CMakeFiles/particles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ASUS\Documents\Program\C++\Rederer2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable particles.exe"
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\particles.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/particles.dir/build: examples/particles.exe
.PHONY : examples/CMakeFiles/particles.dir/build

examples/CMakeFiles/particles.dir/clean:
	cd /d C:\Users\ASUS\Documents\Program\C++\Rederer2\examples && $(CMAKE_COMMAND) -P CMakeFiles\particles.dir\cmake_clean.cmake
.PHONY : examples/CMakeFiles/particles.dir/clean

examples/CMakeFiles/particles.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3 C:\Users\ASUS\Documents\Program\C++\glfw-3.3.3\examples C:\Users\ASUS\Documents\Program\C++\Rederer2 C:\Users\ASUS\Documents\Program\C++\Rederer2\examples C:\Users\ASUS\Documents\Program\C++\Rederer2\examples\CMakeFiles\particles.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/particles.dir/depend

