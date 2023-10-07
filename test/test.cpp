#include "../googletest/googletest/include/gtest/gtest.h"
#include "../include/Three.h"

using namespace std;

TEST(ThreeTest, Simple) {
    Three simpleNumber {112};
    Array result {'2', '1', '1'};
    ASSERT_TRUE(simpleNumber == Three{result});
}

TEST(ThreeTest_Addition, Basic) {
    Three test1 {101010101};
    Three test2 {110101010};
    Three result {211111111};
    ASSERT_TRUE(test1 + test2 == result);
}

TEST(ThreeTest_Addition, WithOverflow) {
    Three test1 {122};
    Three test2 {211};
    Three result {1110};
    ASSERT_TRUE(test1 + test2 == result);
}

TEST(ThreeTest_Addition, SecondIsLonger) {
    Three test1 {100};
    Three test2 {"21111111"};
    Three result {21111211};
    (test1 + test2).print();
    ASSERT_TRUE(test1 + test2 == result);
}

TEST(ThreeTest_Reduction, LeadingZeros) {
    Three test1 {111010101};
    Three test2 {100101010};
    Three result {10202021};
    ASSERT_TRUE(test1 - test2 == result);
}

TEST(ThreeTest_Reduction, SmallerMinusBigger) {
    Three test1 {111};
    Three test2 {222};
    Three errResult {0};
    (test1 - test2).print();
    ASSERT_TRUE(test1 - test2 == errResult);
}

TEST(ThreeTest_Compare, Smaller) {
    Three test1 {111};
    Three test2 {222};
    ASSERT_TRUE(test1 < test2);
}

TEST(ThreeTest_Compare, Bigger) {
    Three test1 {10122};
    Three test2 {10012};
    ASSERT_TRUE(test1 > test2);
}

TEST(ThreeTest_Compare, Equals) {
    Three test1 {10122};
    Three test2 {10122};
    ASSERT_TRUE(test1 == test2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}