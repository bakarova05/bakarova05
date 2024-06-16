#include <gtest/gtest.h>
#include "f4.h"

TEST(Test1, first) {
    ASSERT_EQ(f4({"10:40", "10:50"}), 10);
}
TEST(Test2, second) {
    ASSERT_EQ(f4({"08:01", "13:09", "14:01", "15:10"}), 52);
}
TEST(Test3, third) {
    ASSERT_EQ(f4({"19:15", "17:15", "10:00"}), 120);
}