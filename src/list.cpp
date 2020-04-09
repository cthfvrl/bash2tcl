#include "list.hpp"
#include <iostream>
#include <string>

void List::print(size_t indent) {
    for (auto e : elements) {
        e->print(indent);
    }
}
