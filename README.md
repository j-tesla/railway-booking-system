# RailwayBookingSystem
Software Engineering: CS20006  
Assignment – 3: Inheritance Hierarchy, Design, Analysis & Testing

---

A rudimentary railway reservation / booking system (somewhat like IRCTC Train Ticket
Booking, but extremely scaled down in features)


### Dependencies
* cmake >= 3.17
* gcc >= 9.3.0

### File List

* CMakeLists.txt:  
  cmake directives and instructions describing the project's source files

* TestApplication.cpp:  
  Given Test Application

* TestApplication_extended.cpp  
  Extended Test Application to test the booking system

* RailwayBookingSystem_lib/:
    * CMakeLists.txt
    * Booking.cpp  
      contains implementations and definitions of BookingCase and Booking classes
    * Booking.h:  
      contains BookingCase and Booking classes
    * BookingClass.cpp:  
      contains implementations and definitions of abstract class BookingClass and base classes
    * BookingClass.h  
      contains abstract class BookingClass and base classes
    * Date.cpp  
      contains implementations and declarations of Date class
    * Date.h  
      contains Date class
    * Passenger.cpp  
      contains implementations and declarations of Passenger class
    * Passenger.h  
      contains of Passenger class
    * Railways.cpp  
      contains implementations and declarations of Railways class
    * Railways.h  
      contains Railways class
    * Station.cpp  
      contains implementations and declarations of Station class
    * Station.h  
      contains Station class

* Unit_tests/:
    * CMakeLists.txt
    * lib/:  
      google test source files from https://github.com/google/googletest
    * Main.cpp:  
      runs all the unit tests
    * Booking_test.cpp  
      contains unit tests of Booking class
    * Date_test.cpp  
      contains unit tests of Date class
    * Railways_test.cpp  
      contains unit tests of Railways class
    * Station_test.cpp  
    
    
