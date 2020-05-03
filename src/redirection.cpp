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
    for (auto e : elements) {
        std::cout << ' ';
        e->print();
    }
}