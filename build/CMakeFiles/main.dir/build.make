# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/ramiro/cs/4_sem/comp_graf/voronoi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ramiro/cs/4_sem/comp_graf/voronoi/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.o: ../src/DiagramaVoronoi.cpp
CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ramiro/cs/4_sem/comp_graf/voronoi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.o -MF CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.o.d -o CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.o -c /home/ramiro/cs/4_sem/comp_graf/voronoi/src/DiagramaVoronoi.cpp

CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ramiro/cs/4_sem/comp_graf/voronoi/src/DiagramaVoronoi.cpp > CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.i

CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ramiro/cs/4_sem/comp_graf/voronoi/src/DiagramaVoronoi.cpp -o CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.s

CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.o: ../src/ExibeVARIOSPoligonos.cpp
CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ramiro/cs/4_sem/comp_graf/voronoi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.o -MF CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.o.d -o CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.o -c /home/ramiro/cs/4_sem/comp_graf/voronoi/src/ExibeVARIOSPoligonos.cpp

CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ramiro/cs/4_sem/comp_graf/voronoi/src/ExibeVARIOSPoligonos.cpp > CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.i

CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ramiro/cs/4_sem/comp_graf/voronoi/src/ExibeVARIOSPoligonos.cpp -o CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.s

CMakeFiles/main.dir/src/Linha.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Linha.cpp.o: ../src/Linha.cpp
CMakeFiles/main.dir/src/Linha.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ramiro/cs/4_sem/comp_graf/voronoi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/Linha.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Linha.cpp.o -MF CMakeFiles/main.dir/src/Linha.cpp.o.d -o CMakeFiles/main.dir/src/Linha.cpp.o -c /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Linha.cpp

CMakeFiles/main.dir/src/Linha.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Linha.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Linha.cpp > CMakeFiles/main.dir/src/Linha.cpp.i

CMakeFiles/main.dir/src/Linha.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Linha.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Linha.cpp -o CMakeFiles/main.dir/src/Linha.cpp.s

CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.o: ../src/ListaDeCoresRGB.cpp
CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ramiro/cs/4_sem/comp_graf/voronoi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.o -MF CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.o.d -o CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.o -c /home/ramiro/cs/4_sem/comp_graf/voronoi/src/ListaDeCoresRGB.cpp

CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ramiro/cs/4_sem/comp_graf/voronoi/src/ListaDeCoresRGB.cpp > CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.i

CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ramiro/cs/4_sem/comp_graf/voronoi/src/ListaDeCoresRGB.cpp -o CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.s

CMakeFiles/main.dir/src/Poligono.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Poligono.cpp.o: ../src/Poligono.cpp
CMakeFiles/main.dir/src/Poligono.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ramiro/cs/4_sem/comp_graf/voronoi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/Poligono.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Poligono.cpp.o -MF CMakeFiles/main.dir/src/Poligono.cpp.o.d -o CMakeFiles/main.dir/src/Poligono.cpp.o -c /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Poligono.cpp

CMakeFiles/main.dir/src/Poligono.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Poligono.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Poligono.cpp > CMakeFiles/main.dir/src/Poligono.cpp.i

CMakeFiles/main.dir/src/Poligono.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Poligono.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Poligono.cpp -o CMakeFiles/main.dir/src/Poligono.cpp.s

CMakeFiles/main.dir/src/Ponto.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Ponto.cpp.o: ../src/Ponto.cpp
CMakeFiles/main.dir/src/Ponto.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ramiro/cs/4_sem/comp_graf/voronoi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/Ponto.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Ponto.cpp.o -MF CMakeFiles/main.dir/src/Ponto.cpp.o.d -o CMakeFiles/main.dir/src/Ponto.cpp.o -c /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Ponto.cpp

CMakeFiles/main.dir/src/Ponto.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Ponto.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Ponto.cpp > CMakeFiles/main.dir/src/Ponto.cpp.i

CMakeFiles/main.dir/src/Ponto.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Ponto.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Ponto.cpp -o CMakeFiles/main.dir/src/Ponto.cpp.s

CMakeFiles/main.dir/src/Temporizador.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Temporizador.cpp.o: ../src/Temporizador.cpp
CMakeFiles/main.dir/src/Temporizador.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ramiro/cs/4_sem/comp_graf/voronoi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/Temporizador.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Temporizador.cpp.o -MF CMakeFiles/main.dir/src/Temporizador.cpp.o.d -o CMakeFiles/main.dir/src/Temporizador.cpp.o -c /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Temporizador.cpp

CMakeFiles/main.dir/src/Temporizador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Temporizador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Temporizador.cpp > CMakeFiles/main.dir/src/Temporizador.cpp.i

CMakeFiles/main.dir/src/Temporizador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Temporizador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ramiro/cs/4_sem/comp_graf/voronoi/src/Temporizador.cpp -o CMakeFiles/main.dir/src/Temporizador.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.o" \
"CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.o" \
"CMakeFiles/main.dir/src/Linha.cpp.o" \
"CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.o" \
"CMakeFiles/main.dir/src/Poligono.cpp.o" \
"CMakeFiles/main.dir/src/Ponto.cpp.o" \
"CMakeFiles/main.dir/src/Temporizador.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/DiagramaVoronoi.cpp.o
main: CMakeFiles/main.dir/src/ExibeVARIOSPoligonos.cpp.o
main: CMakeFiles/main.dir/src/Linha.cpp.o
main: CMakeFiles/main.dir/src/ListaDeCoresRGB.cpp.o
main: CMakeFiles/main.dir/src/Poligono.cpp.o
main: CMakeFiles/main.dir/src/Ponto.cpp.o
main: CMakeFiles/main.dir/src/Temporizador.cpp.o
main: CMakeFiles/main.dir/build.make
main: /usr/lib/x86_64-linux-gnu/libGLU.so
main: /usr/lib/x86_64-linux-gnu/libglut.so
main: /usr/lib/x86_64-linux-gnu/libGLX.so
main: /usr/lib/x86_64-linux-gnu/libOpenGL.so
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ramiro/cs/4_sem/comp_graf/voronoi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/ramiro/cs/4_sem/comp_graf/voronoi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ramiro/cs/4_sem/comp_graf/voronoi /home/ramiro/cs/4_sem/comp_graf/voronoi /home/ramiro/cs/4_sem/comp_graf/voronoi/build /home/ramiro/cs/4_sem/comp_graf/voronoi/build /home/ramiro/cs/4_sem/comp_graf/voronoi/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend
