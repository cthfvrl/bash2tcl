#include "while.hpp"
#include <iostream>
#include <string>

While::While(Condition* condition, Element* body)
    : condition(condition), body(body) {
}

void While::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "while {";
    condition->print_condition();
    std::cout << "} {\n";
    body->print(indent + 1);
    std::cout << "}";
}