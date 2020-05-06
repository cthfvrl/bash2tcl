#include "element.hpp"

Element::Element() : output_file("") {
}

void Element::print(size_t indent) {
}

void Element::set_output_file(std::string const& new_output_file) {
    output_file = new_output_file;
}