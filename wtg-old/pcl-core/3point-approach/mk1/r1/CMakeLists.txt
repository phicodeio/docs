cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(operation)

find_package(PCL 1.5 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (operation src.cpp)
target_link_libraries (operation ${PCL_LIBRARIES})

