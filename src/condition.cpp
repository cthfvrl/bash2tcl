#include "condition.hpp"
#include <iostream>

void Condition::print_condition(size_t indent) {
    std::cout << "![catch {";
    print();
    std::cout << "}]";
}