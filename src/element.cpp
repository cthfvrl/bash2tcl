#include "element.hpp"

Element::Element() : output(true) {
}

void Element::print(size_t indent) {
}

void Element::noOutput() {
    output = false;
}