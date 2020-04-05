#include "pipeline.hpp"
#include <iostream>
#include <string>

void Pipeline::invert() {
    inverted = true;
}

void Pipeline::print(size_t indent) {
    if (inverted)
        ; // TODO
    if (elements.size() == 1) {
        std::cout << std::string(indent, '\t');
        elements.front()->print(indent);
    } else {
        std::cout << std::string(indent, '\t') << "exec ";
        for (size_t i = 0; i < elements.size() - 1; ++i) {
            elements[i]->print();
            std::cout << "| ";
        }
        elements.back()->print();
    }
}
