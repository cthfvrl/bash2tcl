#include "redirection.hpp"
#include <iostream>

Redirection::Redirection(const std::string& redirection, String* value)
    : descriptor(nullptr), redirection(redirection), value(value) {
}

Redirection::Redirection(String* descriptor, const std::string& redirection, String* value)
    : descriptor(descriptor), redirection(redirection), value(value) {
}

void Redirection::print(size_t indent) {
    if (descriptor)
        descriptor->print();
    std::cout << redirection;
    value->print();
}

void RedirectionList::print(size_t indent) {
    std::cout << std::string(indent, '\t');
    for (auto e : elements) {
        std::cout << ' ';
        e->print();
    }
}