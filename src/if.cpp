#include "if.hpp"
#include <iostream>
#include <string>

IfElement::IfElement(Condition* condition, Condition* body, bool reverse_condition)
    : condition(condition), body(body), reverse_condition(reverse_condition) {
}

void IfElement::print(size_t indent) {
    std::cout << '{';
    condition->print_condition(0, reverse_condition, false);
    std::cout << "} {\n";
    body->print(indent + 1);
    std::cout << "} ";
}

void IfElement::print_condition(size_t indent, bool reverse, bool in_body) {
    std::cout << '{';
    condition->print_condition(0, reverse_condition, false);
    std::cout << "} {\n";
    body->print_condition(indent + 1);
    std::cout << "} ";
}

If::If() : Compound(), elseBody(nullptr) {
}

void If::addElse(Condition* e) {
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

void If::print_condition(size_t indent, bool reverse, bool in_body) {
    std::cout << std::string(indent, '\t') << (reverse ? "" : "!") << "[catch {if ";
    elements.back()->print_condition(indent);
    for (int i = elements.size() - 2; i > 0; --i) {
        std::cout << "elseif ";
        elements[i]->print_condition(indent);
    }
    if (elseBody) {
        std::cout << "else {\n";
        elseBody->print_condition(indent + 1);
        std::cout << "}";
    }
    std::cout << "}]";
}