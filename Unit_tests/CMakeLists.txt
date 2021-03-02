project(Unit_tests)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(Unit_tests_run StationTests.cpp)

# linking Google_Tests_run with DateConverter_lib which will be tested
target_link_libraries(Unit_tests_run RailwayBookingSystem_lib)

target_link_libraries(Unit_tests_run gtest gtest_main)
