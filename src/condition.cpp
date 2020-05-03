#include "condition.hpp"
#include <iostream>

void Condition::print_condition(size_t indent, bool reverse) {
    std::cout << (reverse ? "" : "!") << "[catch {";
    print();
    std::cout << "}]";
}