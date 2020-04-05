#include "list.hpp"
#include <string>
#include <iostream>

void List::print(size_t indent) {
    for (auto e: elements) {
        std::cout << std::string(indent, '\t');
        e->print(indent);
        std::cout << std::endl;
    }
}
