#pragma once
#include "compound.hpp"
#include "element.hpp"
#include "condition.hpp"
#include <vector>

class IfElement : public Element {
    Condition* condition;
    Element* body;
    bool reverse;

public:
    IfElement(Condition*, Element*, bool reverse = false);
    void print(size_t indent = 0) override;
};

class If : public Compound<>, public Condition {
    Element* elseBody;

public:
    using Compound::Compound;
    If();
    void addElse(Element*);
    void print(size_t indent = 0) override;
    using Condition::print_condition;
};