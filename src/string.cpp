#include "string.hpp"
#include <iostream>

String::String(const std::string& s) : string(s) {
}

void String::print(size_t indent) {
    std::cout << string;
}