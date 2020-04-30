#include "quote.hpp"
#include <iostream>
#include <string>

void Quote::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "\"";
    for (auto& e : elements)
        e->print();
    std::cout << "\"";
}