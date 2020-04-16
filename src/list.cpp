#include "list.hpp"
#include <iostream>
#include <string>

void List::print(size_t indent) {
    for (auto e : elements) {
        e->print(indent);
        std::cout << '\n';
    }
}

void List::print_condition(size_t indent) {
    for (auto e : elements) {
        e->print_condition(indent);
        std::cout << '\n';
    }
}
