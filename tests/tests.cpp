#include "../header/convertTimeTo24h.h"
#include <gtest/gtest.h>
#include <utility>

TEST(test_01, basic_test_am_1) {
    std::string inputTime = "8:30";
    std::string inputPeriod = "am";
    std::string result = convertTimeTo24h(inputTime, inputPeriod);
    ASSERT_TRUE(result == "0830");
}

TEST(test_02, basic_test_am_2) {
    std::string inputTime = "11:59";
    std::string inputPeriod = "am";
    std::string result = convertTimeTo24h(inputTime, inputPeriod);
    ASSERT_TRUE(result == "1159");
}

TEST(test_03, basic_test_pm_1) {
    std::string inputTime = "8:30";
    std::string inputPeriod = "pm";
    std::string result = convertTimeTo24h(inputTime, inputPeriod);
    ASSERT_TRUE(result == "2030");
}

TEST(test_04, basic_test_pm_2) {
    std::string inputTime = "11:29";
    std::string inputPeriod = "pm";
    std::string result = convertTimeTo24h(inputTime, inputPeriod);
    ASSERT_TRUE(result == "2329");
}

TEST(test_05, midnight_pm) {
    std::string inputTime = "12:30";
    std::string inputPeriod = "pm";
    std::string result = convertTimeTo24h(inputTime, inputPeriod);
    ASSERT_TRUE(result == "0030");
}

TEST(test_06, midnight_am) {
    std::string inputTime = "12:30";
    std::string inputPeriod = "am";
    std::string result = convertTimeTo24h(inputTime, inputPeriod);
    ASSERT_TRUE(result == "1230");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}