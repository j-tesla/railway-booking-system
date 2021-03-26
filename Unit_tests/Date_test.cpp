/**
 * @file Date_test.cpp
 * @brief contains unit tests of Date class
 * @author Jayanth PSY - 19CS10068
 */


#include <sstream>

#include "gtest/gtest.h"

#include "Date.h"

/** \test
 * checks equality operator
 */
TEST(Date_test, EqualityOperatorCheck) {
    Date d1 = Date::Construct(1, 1, 1999);
    Date d2 = Date::Construct(1, 1, 1999);

    EXPECT_EQ(d1, d2);
}

/** \test
 * check construction for valid dates
 */
TEST(Date_test, ConstructionFromStringCheck) {
    Date d1 = Date::Construct(10, 5, 2000);
    Date d1_ = Date::Construct("10/05/2000");
    EXPECT_EQ(d1, d1_);

    Date d2  = Date::Construct(22, 2, 1888);
    Date d2_ = Date::Construct("22/FEB/1888");
    EXPECT_EQ(d2, d2_);
}

/** \test
 * checks whether date construction throws correct exception when day is greater than 31
 */
TEST(Date_test, DaysAfter31InvalidityCheck) {
    try {
        Date invalid = Date::Construct(32, 4, 2001);
        FAIL() << "Failed to throw required exception\n";
    } catch (const Bad_Date &e) {
        EXPECT_STREQ(e.what(), "Bad Date: Invalid day");
    } catch (...) {
        FAIL() << "Unexpected exception thrown\n";
    }
}

/** \test
 * checks whether date construction throws correct exception when day is greater than 30 in months like April
 */
TEST(Date_test, DaysAfter30InvalidityCheck) {
    try {
        Date invalid = Date::Construct("31/APR/1998");
        FAIL() << "Failed to throw required exception\n";
    } catch (const Bad_Date &e) {
        EXPECT_STREQ(e.what(), "Bad Date: Invalid day");
    } catch (...) {
        FAIL() << "Unexpected exception thrown\n";
    }
}

/**
 * checks validity of 29 Feb if leap year or otherwise
 */
TEST(Date_test, February29Check) {
    try {
        Date::Construct("29/FEB/1998");
        FAIL() << "Failed to throw required exception\n";
    } catch (const Bad_Date &e) {
        EXPECT_STREQ(e.what(), "Bad Date: Invalid day");
    } catch (...) {
        FAIL() << "Unexpected exception thrown\n";
    }

    try {
        Date::Construct("29/FEB/1996");
    } catch (...) {
        FAIL() << "Unexpected exception thrown\n";
    }
}

/** \test
 * checks whether construction throws correct exception when month is invalid
 */
TEST(Date_test, InvalidMonthCheck) {
    try {
        Date::Construct(10, 16, 2222);
        FAIL() << "Failed to throw required exception\n";
    } catch (const Bad_Date &e) {
        EXPECT_STREQ(e.what(), "Bad Date: Invalid month");
    } catch (...) {
        FAIL() << "Unexpected exception thrown\n";
    }

    try {
        Date::Construct("05/20/2000");
        FAIL() << "Failed to throw required exception\n";
    } catch (const Bad_Date &e) {
        EXPECT_STREQ(e.what(), "Bad Date: Invalid month");
    } catch (...) {
        FAIL() << "Unexpected exception thrown\n";
    }

    try {
        Date::Construct("05/POP/2000");
        FAIL() << "Failed to throw required exception\n";
    } catch (const Bad_Date &e) {
        EXPECT_STREQ(e.what(), "Bad Date: Invalid month");
    } catch (...) {
        FAIL() << "Unexpected exception thrown\n";
    }
}

/** \test
 * checks whether construction throws correct exception when month is invalid
 */
TEST(Date_test, DateFormatCheck) {
    try {
        Date::Construct("not a date format");
        FAIL() << "Failed to throw required exception\n";
    } catch (const Bad_Date &e) {
        EXPECT_STREQ(e.what(), "Bad Date: Invalid pattern, dd/MMM/yyyy and dd//mm/yyyy are valid");
    } catch (...) {
        FAIL() << "Unexpected exception thrown\n";
    }
}

/** \test
 * checks ostream << overload output
 */
TEST(Date_test, OstreamCheck) {
    Date d1 = Date::Construct(5, 5, 2025);
    Date d2 = Date::Construct(12, 2, 2022);
    Date d3 = Date::Construct(11, 11, 2019);
    Date d4 = Date::Construct(30, 1, 2015);
    std::stringstream buffer;
    buffer << d1;
    EXPECT_EQ(buffer.str(), "5/MAY/2025");
    buffer.str(std::string());
    buffer << d2;
    EXPECT_EQ(buffer.str(), "12/FEB/2022");
    buffer.str(std::string());
    buffer << d3;
    EXPECT_EQ(buffer.str(), "11/NOV/2019");
    buffer.str(std::string());
    buffer << d4;
    EXPECT_EQ(buffer.str(), "30/JAN/2015");
    buffer.str(std::string());
}