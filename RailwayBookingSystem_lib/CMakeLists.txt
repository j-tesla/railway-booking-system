project(RailwayBookingSystemLibrary)

set(HEADER_FILES
        Date.h
        Station.h
        Railways.h
        BookingClass.h
        )

set(SOURCE_FILES
        Date.cpp
        Station.cpp
        Railways.cpp
        BookingClass.cpp
        )

add_library(RailwayBookingSystem_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

