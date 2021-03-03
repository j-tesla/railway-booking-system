
cmake_minimum_required(VERSION 3.17)

project(RailwayBookingSystem)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

add_executable(RailwayBookingSystem_application ${SOURCE_FILES})

include_directories(RailwayBookingSystem_lib)
add_subdirectory(RailwayBookingSystem_lib)

target_link_libraries(RailwayBookingSystem_application RailwayBookingSystem_lib)

add_subdirectory(Unit_tests)