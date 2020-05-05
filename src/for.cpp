#include "for.hpp"
#include <iostream>
#include <string>

void Range::print(size_t indent) {
    std::cout << "[concat";
    for (auto e : elements) {
        std::cout << ' ';
        e->print();
    }
    std::cout << ']';
}

For::For(String* variable, Range* range, Condition* body)
    : variable(variable), range(range), body(body) {
}

void For::print(size_t indent) {
    reset_rc(indent);
    std::cout << std::string(indent, '\t') << "foreach ";
    variable->print();
    std::cout << ' ';
    range->print();
    std::cout << " {\n";
    body->print(indent + 1);
    std::cout << "\n"
              << std::string(indent + 1, '\t') << "set " << get_rc_str() << " $"
              << body->get_rc_str();
    std::cout << "}";
}

void For::set_output_file(std::string new_output_file) {
    range->set_output_file(new_output_file);
    body->set_output_file(new_output_file);
}

Pattern::Pattern(String* s) : pattern(s) {
}

void Pattern::print(size_t indent) {
    std::cout << "[glob ";
    pattern->print();
    std::cout << "]";
}

Element* Pattern::check_pattern(String* s) {
    if (s->find('*') || s->find('?'))
        return new Pattern(s);
    return s;
}