#include "while.hpp"
#include <iostream>
#include <string>

While::While(Condition* condition, Condition* body)
    : condition(condition), body(body) {
}

void While::print(size_t indent) {
    reset_rc(indent);
    std::cout << std::string(indent, '\t') << "while {true} {\n";
    condition->print(indent + 1);
    std::cout << '\n'
              << std::string(indent + 1, '\t') << "if {!$"
              << condition->get_rc_str() << "} {\n";
    body->print(indent + 2);
    std::cout << "\n"
              << std::string(indent + 2, '\t') << "set " << get_rc_str() << " $"
              << body->get_rc_str();
    std::cout << "} {break} }";
}