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

void List::print_condition(size_t indent) {
    elements.front()->print_condition(indent);
    for (size_t i = 1; i < elements.size(); ++i) {
        std::cout << '\n';
        elements[i]->print_condition(indent);
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