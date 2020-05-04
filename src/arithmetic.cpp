#include "arithmetic.hpp"
#include <iostream>
#include <string>

void ArithmeticCommand::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "if {!(";
    for (auto& e : elements)
        e->print();
    std::cout << ")} {error \"\"}";
}

void ArithmeticCommand::print_condition(size_t indent, bool reverse, bool in_body) {
    if (in_body) {
        std::cout << std::string(indent, '\t') << "if {" << (reverse ? "" : "!") << "(";
        for (auto& e : elements)
            e->print();
        std::cout << ")} {error \"\"} ";
    } else {
        std::cout << std::string(indent, '\t') << (reverse ? "!" : "") << '(';
        for (auto& e : elements)
            e->print();
        std::cout << ')';
    }
}

void ArithmeticExpression::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "expr ";
    for (auto& e : elements)
        e->print();
}