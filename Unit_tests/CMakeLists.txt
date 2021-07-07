#
# Created by Jayanth PSY (19CS10068) on 03/03/21
#

project(Unit_tests)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(Unit_tests_run Main.cpp Station_test.cpp Railways_test.cpp BookingClasses_test.cpp Booking_test.cpp Date_test.cpp Passenger_test.cpp BookingCategories_test.cpp)

# linking Google_Tests_run with DateConverter_lib which will be tested
target_link_libraries(Unit_tests_run RailwayBookingSystem_lib)

target_link_libraries(Unit_tests_run gtest)
target_link_libraries(Unit_tests_run gmock)
