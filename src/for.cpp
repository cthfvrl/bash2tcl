#include "for.hpp"
#include <iostream>
#include <string>

void Range::print(size_t indent) {
    std::cout << "[concat";
    for (auto e : elements) {
        std::cout << ' ';
        e->print();
    }
    std::cout << ']';
}

For::For(String* variable, Range* range, Element* list)
    : variable(variable), range(range), list(list) {
}

void For::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "foreach ";
    variable->print();
    std::cout << ' ';
    range->print();
    std::cout << " {\n";
    list->print(indent + 1);
    std::cout << "}\n";
}