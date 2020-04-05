#include "pipeline.hpp"
#include <iostream>
#include <string>

void Pipeline::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "exec ";
    for (size_t i = 0; i < elements.size() - 1; ++i) {
        elements[i]->print();
        std::cout << "| ";
    }
    elements.back()->print();
}
