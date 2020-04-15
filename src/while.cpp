#include "while.hpp"
#include <iostream>
#include <string>

While::While(Element* condition, Element* body)
    : condition(condition), body(body) {
}

void While::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "while {![catch {\n";
    condition->print(indent + 1);
    std::cout << std::string(indent + 1, '\t') << "}]} {\n";
    body->print(indent + 1);
    std::cout << std::string(indent, '\t') << "}";
}