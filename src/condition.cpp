#include "condition.hpp"
#include <iostream>
#include <string>

void Condition::print_condition(size_t indent, bool reverse) {
    std::cout << std::string(indent, '\t') << (reverse ? "" : "!") << "[catch {";
    print();
    std::cout << "}]";
}