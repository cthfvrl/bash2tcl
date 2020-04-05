#include "list.hpp"
#include <iostream>
#include <string>

void List::print(size_t indent) {
    for (auto e : elements) {
        std::cout << std::string(indent, '\t');
        e->print(indent);
    }
}
