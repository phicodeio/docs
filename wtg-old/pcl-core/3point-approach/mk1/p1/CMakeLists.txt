cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(region-grow)

find_package(PCL 1.5 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (region-grow src-mod.cpp)
target_link_libraries (region-grow ${PCL_LIBRARIES})

