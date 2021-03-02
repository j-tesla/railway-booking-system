project(RailwayBookingSystemLibrary)

set(HEADER_FILES
        Date.h
        Station.h
        BookingClasses.h
        )

set(SOURCE_FILES
        Date.cpp
        Station.cpp
        BookingClasses.cpp
        )

add_library(RailwayBookingSystem_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

