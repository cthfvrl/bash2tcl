#include "if.hpp"
#include <iostream>
#include <string>

IfElement::IfElement(Element* condition, Element* body)
    : condition(condition), body(body) {
}

void IfElement::print(size_t indent) {
    std::cout << "{![catch {\n";
    condition->print(indent + 1);
    std::cout << std::string(indent + 1, '\t') << "}]} {\n";
    body->print(indent + 1);
    std::cout << std::string(indent, '\t') << "} ";
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
        std::cout << std::string(indent, '\t') << "}";
    }
    std::cout << '\n';
}

// TODO tests
// TODO condition class