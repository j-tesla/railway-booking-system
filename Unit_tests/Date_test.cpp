//
// Created by j-tesla on 06/03/21.
//

#include <sstream>

#include "gtest/gtest.h"

#include "Date.h"


// checks ostream << output
TEST(Date_test, OstreamCheck) {
    Date d1(5, 5, 2025);
    Date d2(12, 2, 2022);
    Date d3(11, 11, 2019);
    Date d4(30, 1, 2015);
    std::stringstream buffer;
    buffer << d1;
    EXPECT_EQ(buffer.str(), "5/May/2025");
    buffer.str(std::string());
    buffer << d2;
    EXPECT_EQ(buffer.str(), "12/Feb/2022");
    buffer.str(std::string());
    buffer << d3;
    EXPECT_EQ(buffer.str(), "11/Nov/2019");
    buffer.str(std::string());
    buffer << d4;
    EXPECT_EQ(buffer.str(), "30/Jan/2015");
    buffer.str(std::string());
}
