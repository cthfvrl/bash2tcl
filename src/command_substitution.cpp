#include "command_substitution.hpp"
#include <iostream>
#include <string>

int CommandSubstitution::index_max = 0;
const std::string CommandSubstitution::fname_prefix = "___fn";

std::string CommandSubstitution::get_fname() {
    return fname_prefix + std::to_string(index);
}

std::string CommandSubstitution::get_fname(int index) {
    return fname_prefix + std::to_string(index);
}

CommandSubstitution::CommandSubstitution(Element* element)
    : element(element), index(index_max++) {
    element->set_output_file("$" + get_fname());
}

void CommandSubstitution::print(size_t indent) {
    std::cout << std::string(indent, '\t') << '[';
    std::cout << "file tempfile " << get_fname() << '\n';
    element->print();
    std::cout << "\nregsub -all {\\n} [exec cat $" << get_fname() << "] \" \"]";
}

void CommandSubstitution::remove_tempfiles() {
    for (int i = 0; i < index_max; ++i)
        std::cout << "file delete $" << get_fname(i) << '\n';
}