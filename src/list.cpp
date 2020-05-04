#include "list.hpp"
#include <algorithm>
#include <iostream>
#include <string>

void List::print(size_t indent) {
    elements.front()->print(indent);
    for (size_t i = 1; i < elements.size(); ++i) {
        std::cout << '\n';
        elements[i]->print(indent);
    }
}

void List::print_condition(size_t indent, bool reverse, bool in_body) {
    elements.front()->print_condition(indent, reverse, in_body);
    for (size_t i = 1; i < elements.size(); ++i) {
        std::cout << '\n';
        elements[i]->print_condition(indent, reverse, in_body);
    }
}

int List::getSubshellLevel() {
    return subshellLevel;
}

void List::setSubshellLevel(int level) {
    subshellLevel = level;
}

void List::add(List* e) {
    Compound<Condition>::add(e);
    subshellLevel = std::max(subshellLevel, e->getSubshellLevel());
}