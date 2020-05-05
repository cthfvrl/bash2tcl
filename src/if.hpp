#pragma once
#include "compound.hpp"
#include "condition.hpp"
#include "element.hpp"
#include <vector>

class IfElement : public Element {
    Condition* condition;
    Condition* body;
    bool reverse_condition;
    int parent_rc;

public:
    IfElement(Condition*, Condition*, bool reverse_condition = false);
    void print(size_t indent = 0) override;
    void set_parent_rc(int);
};

class If : public Compound<IfElement>, public Condition {
    Condition* elseBody;

public:
    If();
    If(IfElement*);
    void add(IfElement*) override;
    void addElse(Condition*);
    void print(size_t indent = 0) override;
};