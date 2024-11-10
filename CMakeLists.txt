cmake_minimum_required(VERSION 3.25)
project(Rubik C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
#add_library(${CMAKE_LIBRARY_PATH_FLAG})
add_definitions(${GTK3_CFLAGS_OTHER})

set(CMAKE_C_STANDARD 11)


add_executable(Rubik main1.c)
find_library(MATH_LIBRARY m)
target_link_libraries(Rubik ${GTK3_LIBRARIES} -lm)
