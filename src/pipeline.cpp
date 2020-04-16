#include "pipeline.hpp"
#include <iostream>
#include <string>

void Pipeline::print(size_t indent) {
    std::cout << std::string(indent, '\t');
    if (elements.size() > 1) {
        std::cout << "Pipelines are not supported yet...\n";
        return;
        // TODO
    }
    // for (size_t i = 0; i < elements.size() - 1; ++i) {
    //     elements[i]->print();
    //     std::cout << "| ";
    // }
    elements.back()->print();
}

void Pipeline::print_condition(size_t indent) {
    std::cout << std::string(indent, '\t');
    if (elements.size() > 1) {
        std::cout << "Pipelines are not supported yet...\n";
        return;
        // TODO
    }
    elements.back()->print_condition();
}
