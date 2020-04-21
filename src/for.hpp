#pragma once
#include "compound.hpp"
#include "condition.hpp"
#include "element.hpp"
#include "string.hpp"

class Range : public Compound<> {
public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
};

class For : public Condition {
    String* variable;
    Range* range;
    Element* body;

public:
    For(String*, Range*, Element*);
    void print(size_t indent = 0) override;
    using Condition::print_condition;
};

class Pattern : public Element {
    String* pattern;

public:
    Pattern(String*);
    void print(size_t indent = 0) override;
    static Element* check_pattern(String*);
};