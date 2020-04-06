#include "command_substitution.hpp"
#include <iostream>
#include <string>

CommandSubstitution::CommandSubstitution(Element* element) : element(element) {
    element->noOutput();
}

void CommandSubstitution::print(size_t indent) {
    std::cout << std::string(indent, '\t') << '[';
    element->print();
    std::cout << ']';
}