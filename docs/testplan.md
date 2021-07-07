# TestPlan

## Station_test

### NameCheck
Is name of station correct ?

### EqualityCheck
Is station identified by its name?

## Railways_test

### DistanceSymmetry
Is distance between symmetric?

### InvalidStation
Is ValdiStation method giving false for invalid station

### ValidStation
Is ValdiStation method giving true for valid station

## Date_test

### EqualityOperatorCheck
Check equality operator

### ConstructionFromStringCheck
Check construction from strings in right format

### DaysAfter31InvalidityCheck
day > 31 throw exception

### DaysAfter30InvalidityCheck
day > 30 for certain months is invalid

### February29Check
feb 29 is valid only in leap years

### InvalidMonthCheck
1 <= month <= 12

### DateFormatCheck

construction from wrong format throw

### OstreamCheck
check output stream format

## PassengerDetails_test

### ValidFullNameCheck
throw no exception valid full name case

### FullNameCheck
check first, middle and last names

### OnlyFirstNameCheck
valid if firstname is not empty

### OnlyLastName
valid if firstname is not empty

### EmptyFirstAndLastNameCheck
invalid

### ValidAadhaarCheck

### NonNumericAadhaarCheck
invalid throw exception

### InvalidLengthAadhaarCheck
invalid throw exception

### ValidPhoneNumberCheck

### NonNumericPhoneNumberCheck
invalid throw exception

### InvalidLengthPhoneNumberCheck
invalid throw exception

## Passenger_test

### OnlyDivyaangCategoryCheck
invalid if no divyaang id and has divyaang category

### OnlyDivyaangIDCheck
invalid if no divyaang category and has divyaang id

### NoDivyaangCheck
valid if divyaang not selected

### ValidDivyaangCheck
valid if divyaang category and divyaang id

## BookingClasses_test

### NameCheck
check name of class

### NumberOfTiersCheck
check number of tiers

### OstreamFormatCheck
check output stream format

## General_test

### EligiblePassengerCheck
all are eligible

## Ladies_test

### EligiblePassengerCheck
female elible, male not

## Priority_test

### OnedayEligibilityCheck
eligible before one day, rest days not

## SeniorCitizen_test

### EligiblePassengerCheck
eligibilty check based on age for both genders

### IneligiblePassengerCheck
ineligibilty check based on age for both genders

## DivyaangCategory_test

### EligiblePassengerCheck
eligible passenger check

### WrongDisabilityPassengerCheck
not eligible if wrong disabilty selected

### AbledPassengerCheck
not elible if abled

## Booking_test

### PNRSequenceCheck
PNR sequence goes 1, 2, 3 ...

### BookingsCountIncrementCheck
bookings count increment by 1 after a valid booking

### BookingStatusCheck
status is true for valid booking

### ToStationCheck
to station is correct

### FromStationCheck
from station is correct

### FareCheck
fare is computed correctly

### OstreamFormatCheck
check output stream format

### InvalidStationCheck
throw exception if station is invalid

### IneligiblePassengerCheck
throw exception if passenger is ineligible for selected category

### PastBookingDateCheck
throw exception if date of booking not greater than date of reservation

### MoreThanAfterOneYearBookingDateCheck
throw exception if date of booking more than one year later than date of reservation



## Test Application
As out application has limited features, there is nothing much left to cover as almost all cases are covered in unit tests of Booking class even the output printed is tested


### expected output
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


> 19CS10068