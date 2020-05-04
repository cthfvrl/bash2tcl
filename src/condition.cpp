#include "condition.hpp"
#include <iostream>
#include <string>

void Condition::print_condition(size_t indent, bool reverse, bool in_body) {
    std::cout << std::string(indent, '\t') << (reverse ? "" : "!") << "[catch {";
    print();
    std::cout << "}]";
}