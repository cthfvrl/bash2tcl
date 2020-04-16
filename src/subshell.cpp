#include "subshell.hpp"
#include <iostream>
#include <string>

Subshell::Subshell(List* list)
    : list(list), subshellLevel(list->getSubshellLevel()) {
}

void Subshell::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "interp create i" << subshellLevel << '\n';
    std::cout << std::string(indent, '\t') << "interp eval i" << subshellLevel << " {\n";
    list->print(indent + 1);
    std::cout << std::string(indent, '\t') << "\n}\n";
    std::cout << std::string(indent, '\t') << "interp delete i" << subshellLevel;
}