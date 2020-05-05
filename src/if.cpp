#include "if.hpp"
#include <iostream>
#include <string>

IfElement::IfElement(Condition* condition, Condition* body, bool reverse_condition)
    : condition(condition), body(body), reverse_condition(reverse_condition), parent_rc(-1) {
}

void IfElement::print(size_t indent) {
    condition->print(indent);
    std::cout << '\n'
              << std::string(indent, '\t') << "if {" << (reverse_condition ? "" : "!")
              << '$' << condition->get_rc_str() << "} {\n";
    body->print(indent + 1);
    std::cout << "\n"
              << std::string(indent + 1, '\t') << "set "
              << Condition::get_rc_str(parent_rc) << " $" << body->get_rc_str();
    std::cout << "\n} ";
}

void IfElement::set_parent_rc(int new_rc) {
    parent_rc = new_rc;
}

If::If() : elseBody(nullptr) {
}

If::If(IfElement* e) : Compound<IfElement>(e) {
    e->set_parent_rc(get_rc());
}

void If::add(IfElement* e) {
    Compound<IfElement>::add(e);
    e->set_parent_rc(get_rc());
}

void If::addElse(Condition* e) {
    elseBody = e;
}

void If::print(size_t indent) {
    reset_rc(indent);
    elements.back()->print(indent);
    for (int i = elements.size() - 2; i >= 0; --i) {
        std::cout << "else {\n";
        elements[i]->print(indent);
    }
    if (elseBody) {
        std::cout << "else {\n";
        elseBody->print(indent + 1);
        std::cout << "\n}";
    }
    std::cout << std::string(elements.size() - 1, '}');
}