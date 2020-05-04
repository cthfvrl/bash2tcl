#pragma once
#include "compound.hpp"
#include "element.hpp"
#include "condition.hpp"
#include <vector>

class IfElement : public Condition {
    Condition* condition;
    Condition* body;
    bool reverse_condition;

public:
    IfElement(Condition*, Condition*, bool reverse_condition = false);
    void print(size_t indent = 0) override;
    void print_condition(size_t indent = 0, bool reverse = false, bool in_body = true) override;
};

class If : public Compound<Condition>, public Condition {
    Condition* elseBody;

public:
    using Compound::Compound;
    If();
    void addElse(Condition*);
    void print(size_t indent = 0) override;
    void print_condition(size_t indent = 0, bool reverse = false, bool in_body = true) override;
};