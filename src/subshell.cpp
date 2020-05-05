#include "subshell.hpp"
#include <iostream>
#include <string>

Subshell::Subshell(List* list)
    : list(list), subshellLevel(list->getSubshellLevel()) {
}

void Subshell::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "interp create i" << subshellLevel << '\n';
    std::cout << std::string(indent, '\t') << "set " << get_rc_str() << "[catch {interp eval i" << subshellLevel << " {\n";
    list->print(indent + 1);
    std::cout << '\n' << std::string(indent, '\t') << "}}]\n";
    std::cout << std::string(indent, '\t') << "interp delete i" << subshellLevel;
}