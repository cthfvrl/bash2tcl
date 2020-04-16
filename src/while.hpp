#pragma once
#include "condition.hpp"
#include "element.hpp"

class While : virtual public Element, public Condition {
    Condition* condition;
    Element* body;

public:
    While(Condition*, Element*);
    void print(size_t indent = 0) override;
    using Condition::print_condition;
};