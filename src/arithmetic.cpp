#include "arithmetic.hpp"
#include <iostream>
#include <string>

void Arithmetic::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "expr ";
    for (auto& e : elements)
        e->print();
}

void Arithmetic::print_condition(size_t indent) {
    std::cout << std::string(indent, '\t') << '(';
    for (auto& e : elements)
        e->print();
    std::cout << ')';
}