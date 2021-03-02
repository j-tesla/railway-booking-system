# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

cmake_minimum_required(VERSION 3.17)

project(RailwayBookingSystem)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)

add_executable(RailwayBookingSystem_application ${SOURCE_FILES})

include_directories(RailwayBookingSystem_lib)
add_subdirectory(RailwayBookingSystem_lib)

target_link_libraries(RailwayBookingSystem_application RailwayBookingSystem_lib)

add_subdirectory(Unit_tests)