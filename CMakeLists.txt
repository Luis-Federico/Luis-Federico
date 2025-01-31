cmake_minimum_required(VERSION 3.28)
project(vortex C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
#add_library(${CMAKE_LIBRARY_PATH_FLAG})
add_definitions(${GTK3_CFLAGS_OTHER})

set(CMAKE_C_STANDARD 11)

# install (TARGETS vortex)
add_executable(vortex main.c)
find_library(MATH_LIBRARY m)
target_link_libraries(vortex ${GTK3_LIBRARIES} ${MATH_LIBRARY})
