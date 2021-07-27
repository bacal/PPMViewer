cmake_minimum_required(VERSION 3.10)
project(Main)
set(CMAKE_C_STANDARD 99)

add_subdirectory(PPMViewer)
link_libraries(PPMViewer)

add_executable(main main.c)
