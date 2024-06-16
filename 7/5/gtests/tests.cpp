#include <gtest/gtest.h>
#include "f5.h"

TEST(Test1 , res) {
ASSERT_TRUE(f5(1, 1, 3));
}
TEST(Test2 , res) {
ASSERT_FALSE(f5(1, 12, 2));
}
TEST(Test3 , res) {
ASSERT_TRUE(f5(1, 4, 2));
}
