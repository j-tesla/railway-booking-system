project(RailwayBookingSystemLibrary)

set(HEADER_FILES
        Date.h
        Station.h
        Railways.h
        BookingClasses.h
        )

set(SOURCE_FILES
        Date.cpp
        Station.cpp
        Railways.cpp
        BookingClasses.cpp
        )

add_library(RailwayBookingSystem_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

