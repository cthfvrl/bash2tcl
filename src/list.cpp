#include "list.hpp"
#include <algorithm>
#include <iostream>
#include <string>

List::List(Condition* e) : Compound<Condition>(e), Condition(e->get_rc()) {
}

void List::print(size_t indent) {
    elements.front()->print(indent);
    for (size_t i = 1; i < elements.size(); ++i) {
        std::cout << '\n';
        elements[i]->print(indent);
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
    set_rc(e->get_rc());
}