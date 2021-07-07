# RailwayBookingSystem
Software Engineering: CS20006  

19CS10068 - Jayanth PSY

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
    * BookingClasses.cpp:  
      contains implementations and definitions of abstract class BookingClass and base classes
    * BookingClasses.h  
      contains abstract class BookingClass and base classes
    * BookingCategories.cpp:  
      contains implementations and definitions of abstract class BookingCategory and base classes
    * BookingCategories.h  
      contains abstract class BookingCategory and base classes
    * Divyaang.cpp:  
      contains implementations and definitions of abstract class Divyaang and base classes
    * Divyaang.h  
      contains abstract class Divyaang and base classes
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
      contains unit tests of Station class
    * BookingClasses_test.cpp  
      contains unit tests of Booking classes
    * BookingCategories_test.cpp  
      contains unit tests of Booking categories
    * Passenger_test.cpp
      contains unit tests of Passenger and related classes
