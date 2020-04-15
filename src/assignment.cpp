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
    elements.front()->print(indent);
    for (size_t i = 1; i < elements.size(); ++i) {
        std::cout << '\n';
        elements[i]->print(indent);
    }
}

void AssignmentList::print_env(size_t indent) {
    dynamic_cast<Assignment*>(elements.front())->print_env(indent);
    for (size_t i = 1; i < elements.size(); ++i) {
        std::cout << '\n';
        dynamic_cast<Assignment*>(elements[i])->print_env(indent);
    }
}