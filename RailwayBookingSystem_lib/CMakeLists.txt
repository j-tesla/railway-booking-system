#
# Created by Jayanth PSY (19CS10068) on 02/03/21
#
project(RailwayBookingSystemLibrary)

set(HEADER_FILES
        Date.h
        Station.h
        Railways.h
        BookingClasses.h
        BookingClasses.h
        Gender.h
        Divyaang.h
        Passenger.h
        Booking.h
        Exceptions.h)

set(SOURCE_FILES
        Date.cpp
        Station.cpp
        Railways.cpp
        BookingClasses.cpp
        BookingCategories.cpp
        Gender.cpp
        Divyaang.cpp
        Passenger.cpp
        Booking.cpp
        Exceptions.cpp)

add_library(RailwayBookingSystem_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

