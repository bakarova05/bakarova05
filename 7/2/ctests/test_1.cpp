#include <cassert >
#include "main2.h"

void test_1() {
assert(main2(0, 0, 2, -3, 4));
}

void test_2() {
assert(main2(0, 0, 2, -3, 5));
}

void test_3() {
assert(main2(1, 1, 2, -3, 4));
}

int main() {
test_1();
test_2();
test_3();
}