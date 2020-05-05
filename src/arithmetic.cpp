#include "arithmetic.hpp"
#include <iostream>
#include <string>

void ArithmeticCommand::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "set " << get_rc_str() << " [expr (";
    for (auto& e : elements)
        e->print();
    std::cout << ") == 0 ? 1 : 0]";
}

void ArithmeticExpression::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "expr ";
    for (auto& e : elements)
        e->print();
}