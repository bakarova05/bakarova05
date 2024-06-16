#include <gtest/gtest.h>
#include "f3.h"

TEST(Test1, first) {
    ASSERT_EQ(f3("x-2x+1=0"), "x=1");
}
TEST(Test2, second) {
    ASSERT_EQ(f3("x+5=x-5"), "NO");
}
TEST(Test3, third) {
    ASSERT_EQ(f3("2x+3=5+x+2+x-4"), "Infinite");
}