#include "assignment.hpp"
#include <iostream>
#include <string>

Assignment::Assignment(String* variable, Element* value)
    : variable(variable), value(value) {
}

void Assignment::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "set ";
    variable->print();
    std::cout << ' ';
    value->print();
}

void Assignment::print_env(size_t indent) {
    std::cout << std::string(indent, '\t') << "set ";
    std::cout << "env(";
    variable->print();
    std::cout << ") ";
    value->print();
}

void AssignmentList::print(size_t indent) {
    for (auto& e : elements) {
        e->print(indent);
        std::cout << '\n';
    }
}

void AssignmentList::print_env(size_t indent) {
    for (auto& e : elements) {
        dynamic_cast<Assignment*>(e)->print_env(indent);
        std::cout << '\n';
    }
}