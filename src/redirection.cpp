#include "redirection.hpp"
#include <iostream>

Redirection::Redirection(String* descriptor, String* value)
    : descriptor(descriptor), value(value) {
}

void Redirection::print(size_t indent) {
    descriptor->print();
    value->print();
}

void RedirectionList::print(size_t indent) {
    std::cout << std::string(indent, '\t');
    elements.front()->print();
    for (size_t i = 1; i < elements.size(); ++i) {
        std::cout << ' ';
        elements[i]->print();
    }
}