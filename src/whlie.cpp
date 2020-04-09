#include "while.hpp"
#include <iostream>
#include <string>

While::While(Element* condition, Element* body)
    : condition(condition), body(body) {
}

void While::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "while true {\n";
    std::cout << std::string(indent + 1, '\t') << "if {![catch {\n";
    condition->print(indent + 2);
    std::cout << std::string(indent + 1, '\t') << "}]} {\n";
    body->print(indent + 2);
    std::cout << std::string(indent + 1, '\t') << "} { break }\n";
    std::cout << std::string(indent, '\t') << "}\n";
}