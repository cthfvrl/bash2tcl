#include "wordlist.hpp"
#include <iostream>
#include <string>

void WordList::print(size_t indent) {
    std::cout << std::string(indent, '\t');
    elements.front()->print();
    for (size_t i = 1; i < elements.size(); ++i) {
        std::cout << ' ';
        elements[i]->print();
    }
}