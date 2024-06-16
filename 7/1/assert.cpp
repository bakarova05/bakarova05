#include <cassert>
#include "mainN.h"
#include <iostream>
void test_correct() {
assert(def1(10,11) == 8);
}
void test_incorrect() {
assert(def1(8,8) != 8);
}
void test_skip_spaces() {
assert(def1(8,7) == 8);
}
int main() {
    std::cout << "test_correct..." << std::flush;
    test_correct();
    std::cout << "OK" << std::endl;

    std::cout << "test_incorrect..." << std::flush;
    test_incorrect();
    std::cout << "OK" << std::endl;

    std::cout << "test_skip_spaces..." << std::flush;
    test_skip_spaces();
    std::cout << "OK" << std::endl;
}