#include "wordlist.hpp"
#include <iostream>
#include <string>

void WordList::print(size_t indent) {
    std::cout << std::string(indent, '\t');
    for (auto e : elements) {
        e->print();
        std::cout << ' ';
    }
}