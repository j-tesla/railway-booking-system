## unit tests compliance
```
Running main() for tests from /home/j-tesla/Documents/projects/CLionProjects/RailwayBookingSystem/Unit_tests/Main.cpp
[==========] Running 50 tests from 12 test suites.
[----------] Global test environment set-up.
[----------] 2 tests from Station_test
[ RUN      ] Station_test.NameCheck
[       OK ] Station_test.NameCheck (0 ms)
[ RUN      ] Station_test.EqualityCheck
[       OK ] Station_test.EqualityCheck (0 ms)
[----------] 2 tests from Station_test (0 ms total)

[----------] 3 tests from Railways_test
[ RUN      ] Railways_test.DistanceSymmetry
[       OK ] Railways_test.DistanceSymmetry (1 ms)
[ RUN      ] Railways_test.InvalidStation
[       OK ] Railways_test.InvalidStation (0 ms)
[ RUN      ] Railways_test.ValidStation
[       OK ] Railways_test.ValidStation (0 ms)
[----------] 3 tests from Railways_test (1 ms total)

[----------] 3 tests from BookingClasses_test
[ RUN      ] BookingClasses_test.NameCheck
[       OK ] BookingClasses_test.NameCheck (0 ms)
[ RUN      ] BookingClasses_test.NumberOfTiersCheck
[       OK ] BookingClasses_test.NumberOfTiersCheck (0 ms)
[ RUN      ] BookingClasses_test.OstreamFormatCheck
[       OK ] BookingClasses_test.OstreamFormatCheck (0 ms)
[----------] 3 tests from BookingClasses_test (0 ms total)

[----------] 11 tests from Booking_test
[ RUN      ] Booking_test.PNRSequenceCheck
[       OK ] Booking_test.PNRSequenceCheck (0 ms)
[ RUN      ] Booking_test.BookingsCountIncrementCheck
[       OK ] Booking_test.BookingsCountIncrementCheck (0 ms)
[ RUN      ] Booking_test.BookingStatusCheck
[       OK ] Booking_test.BookingStatusCheck (0 ms)
[ RUN      ] Booking_test.ToStationCheck
[       OK ] Booking_test.ToStationCheck (0 ms)
[ RUN      ] Booking_test.FromStationCheck
[       OK ] Booking_test.FromStationCheck (0 ms)
[ RUN      ] Booking_test.FareCheck
[       OK ] Booking_test.FareCheck (0 ms)
[ RUN      ] Booking_test.OstreamFormatCheck
[       OK ] Booking_test.OstreamFormatCheck (0 ms)
[ RUN      ] Booking_test.InvalidStationCheck
[       OK ] Booking_test.InvalidStationCheck (1 ms)
[ RUN      ] Booking_test.IneligiblePassengerCheck
[       OK ] Booking_test.IneligiblePassengerCheck (0 ms)
[ RUN      ] Booking_test.PastBookingDateCheck
[       OK ] Booking_test.PastBookingDateCheck (0 ms)
[ RUN      ] Booking_test.MoreThanAfterOneYearBookingDateCheck
[       OK ] Booking_test.MoreThanAfterOneYearBookingDateCheck (0 ms)
[----------] 11 tests from Booking_test (1 ms total)

[----------] 8 tests from Date_test
[ RUN      ] Date_test.EqualityOperatorCheck
[       OK ] Date_test.EqualityOperatorCheck (0 ms)
[ RUN      ] Date_test.ConstructionFromStringCheck
[       OK ] Date_test.ConstructionFromStringCheck (2 ms)
[ RUN      ] Date_test.DaysAfter31InvalidityCheck
[       OK ] Date_test.DaysAfter31InvalidityCheck (0 ms)
[ RUN      ] Date_test.DaysAfter30InvalidityCheck
[       OK ] Date_test.DaysAfter30InvalidityCheck (1 ms)
[ RUN      ] Date_test.February29Check
[       OK ] Date_test.February29Check (2 ms)
[ RUN      ] Date_test.InvalidMonthCheck
[       OK ] Date_test.InvalidMonthCheck (2 ms)
[ RUN      ] Date_test.DateFormatCheck
[       OK ] Date_test.DateFormatCheck (1 ms)
[ RUN      ] Date_test.OstreamCheck
[       OK ] Date_test.OstreamCheck (0 ms)
[----------] 8 tests from Date_test (8 ms total)

[----------] 11 tests from PassengerDetails_test
[ RUN      ] PassengerDetails_test.ValidFullNameCheck
[       OK ] PassengerDetails_test.ValidFullNameCheck (0 ms)
[ RUN      ] PassengerDetails_test.FullNameCheck
[       OK ] PassengerDetails_test.FullNameCheck (0 ms)
[ RUN      ] PassengerDetails_test.OnlyFirstNameCheck
[       OK ] PassengerDetails_test.OnlyFirstNameCheck (0 ms)
[ RUN      ] PassengerDetails_test.OnlyLastName
[       OK ] PassengerDetails_test.OnlyLastName (0 ms)
[ RUN      ] PassengerDetails_test.EmptyFirstAndLastNameCheck
[       OK ] PassengerDetails_test.EmptyFirstAndLastNameCheck (0 ms)
[ RUN      ] PassengerDetails_test.ValidAadhaarCheck
[       OK ] PassengerDetails_test.ValidAadhaarCheck (0 ms)
[ RUN      ] PassengerDetails_test.NonNumericAadhaarCheck
[       OK ] PassengerDetails_test.NonNumericAadhaarCheck (0 ms)
[ RUN      ] PassengerDetails_test.InvalidLengthAadhaarCheck
[       OK ] PassengerDetails_test.InvalidLengthAadhaarCheck (0 ms)
[ RUN      ] PassengerDetails_test.ValidPhoneNumberCheck
[       OK ] PassengerDetails_test.ValidPhoneNumberCheck (0 ms)
[ RUN      ] PassengerDetails_test.NonNumericPhoneNumberCheck
[       OK ] PassengerDetails_test.NonNumericPhoneNumberCheck (0 ms)
[ RUN      ] PassengerDetails_test.InvalidLengthPhoneNumberCheck
[       OK ] PassengerDetails_test.InvalidLengthPhoneNumberCheck (0 ms)
[----------] 11 tests from PassengerDetails_test (0 ms total)

[----------] 4 tests from Passenger_test
[ RUN      ] Passenger_test.OnlyDivyaangCategoryCheck
[       OK ] Passenger_test.OnlyDivyaangCategoryCheck (0 ms)
[ RUN      ] Passenger_test.OnlyDivyaangIDCheck
[       OK ] Passenger_test.OnlyDivyaangIDCheck (0 ms)
[ RUN      ] Passenger_test.NoDivyaangCheck
[       OK ] Passenger_test.NoDivyaangCheck (0 ms)
[ RUN      ] Passenger_test.ValidDivyaangCheck
[       OK ] Passenger_test.ValidDivyaangCheck (0 ms)
[----------] 4 tests from Passenger_test (1 ms total)

[----------] 1 test from General_test
[ RUN      ] General_test.EligiblePassengerCheck
[       OK ] General_test.EligiblePassengerCheck (0 ms)
[----------] 1 test from General_test (0 ms total)

[----------] 1 test from Ladies_test
[ RUN      ] Ladies_test.EligiblePassengerCheck
[       OK ] Ladies_test.EligiblePassengerCheck (0 ms)
[----------] 1 test from Ladies_test (0 ms total)

[----------] 1 test from Priority_test
[ RUN      ] Priority_test.OnedayEligibilityCheck
[       OK ] Priority_test.OnedayEligibilityCheck (0 ms)
[----------] 1 test from Priority_test (0 ms total)

[----------] 2 tests from SeniorCitizen_test
[ RUN      ] SeniorCitizen_test.EligiblePassengerCheck
[       OK ] SeniorCitizen_test.EligiblePassengerCheck (0 ms)
[ RUN      ] SeniorCitizen_test.IneligiblePassengerCheck
[       OK ] SeniorCitizen_test.IneligiblePassengerCheck (0 ms)
[----------] 2 tests from SeniorCitizen_test (0 ms total)

[----------] 3 tests from DivyaangCategory_test
[ RUN      ] DivyaangCategory_test.EligiblePassengerCheck
[       OK ] DivyaangCategory_test.EligiblePassengerCheck (0 ms)
[ RUN      ] DivyaangCategory_test.WrongDisabilityPassengerCheck
[       OK ] DivyaangCategory_test.WrongDisabilityPassengerCheck (0 ms)
[ RUN      ] DivyaangCategory_test.AbledPassengerCheck
[       OK ] DivyaangCategory_test.AbledPassengerCheck (0 ms)
[----------] 3 tests from DivyaangCategory_test (0 ms total)

[----------] Global test environment tear-down
[==========] 50 tests from 12 test suites ran. (11 ms total)
[  PASSED  ] 50 tests.
```

## test application output
```
Bad Booking: invalid from station
Bad Booking: invalid from station
Bad Passenger: Disability type needs to be entered along with disability ID
BOOKING SUCCEEDED:
PNR Number = 1
From Station = Delhi
To Station = Mumbai
Travel Date = 20/AUG/2021
Travel Class = AC 3 Tier
  - Mode: Sleeping
  - AC: Yes
  - Bunks: 3
  - Luxury: No
Booking Category = Divyaang
Fare = 492

BOOKING SUCCEEDED:
PNR Number = 2
From Station = Delhi
To Station = Mumbai
Travel Date = 20/AUG/2021
Travel Class = Sleeper
  - Mode: Sleeping
  - AC: No
  - Bunks: 3
  - Luxury: No
Booking Category = Divyaang
Fare = 201

BOOKING SUCCEEDED:
PNR Number = 3
From Station = Kolkata
To Station = Delhi
Travel Date = 10/NOV/2020
Travel Class = First Class
  - Mode: Sleeping
  - AC: No
  - Bunks: 2
  - Luxury: Yes
Booking Category = General
Fare = 2258

BOOKING SUCCEEDED:
PNR Number = 4
From Station = Chennai
To Station = Delhi
Travel Date = 10/NOV/2020
Travel Class = Executive Chair Car
  - Mode: Sitting
  - AC: Yes
  - Bunks: 0
  - Luxury: Yes
Booking Category = General
Fare = 5510

BOOKING SUCCEEDED:
PNR Number = 5
From Station = Kolkata
To Station = Mumbai
Travel Date = 10/NOV/2020
Travel Class = AC Chair Car
  - Mode: Sitting
  - AC: Yes
  - Bunks: 0
  - Luxury: No
Booking Category = Senior Citizen
Fare = 1248

```




> 19CS10068 Jayanth PSY