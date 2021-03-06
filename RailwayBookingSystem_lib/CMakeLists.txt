project(RailwayBookingSystemLibrary)

set(HEADER_FILES
        Date.h
        Station.h
        Railways.h
        BookingClass.h
        Passenger.h
        Booking.h)

set(SOURCE_FILES
        Date.cpp
        Station.cpp
        Railways.cpp
        BookingClass.cpp
        Passenger.cpp
        Booking.cpp)

add_library(RailwayBookingSystem_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

