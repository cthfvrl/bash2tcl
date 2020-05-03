#include "if.hpp"
#include <iostream>
#include <string>

IfElement::IfElement(Condition* condition, Element* body, bool reverse)
    : condition(condition), body(body), reverse(reverse) {
}

void IfElement::print(size_t indent) {
    std::cout << '{';
    condition->print_condition(0, reverse);
    std::cout << "} {\n";
    body->print(indent + 1);
    std::cout << "} ";
}

If::If() : Compound(), elseBody(nullptr) {
}

void If::addElse(Element* e) {
    elseBody = e;
}

void If::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "if ";
    elements.back()->print(indent);
    for (int i = elements.size() - 2; i > 0; --i) {
        std::cout << "elseif ";
        elements[i]->print(indent);
    }
    if (elseBody) {
        std::cout << "else {\n";
        elseBody->print(indent + 1);
        std::cout << "}";
    }
}