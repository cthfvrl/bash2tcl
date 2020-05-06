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
    Condition* body;

public:
    For(String*, Range*, Condition*);
    void print(size_t indent = 0) override;
    void set_output_file(std::string const&) override;
};

class Pattern : public Element {
    String* pattern;

public:
    Pattern(String*);
    void print(size_t indent = 0) override;
    static Element* check_pattern(String*);
};