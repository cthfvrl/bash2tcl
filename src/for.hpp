#pragma once
#include "compound.hpp"
#include "element.hpp"
#include "string.hpp"

class Range : public Compound {
public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
};

class For : public Element {
    String* variable;
    Range* range;
    Element* list;

public:
    For(String*, Range*, Element*);
    void print(size_t indent = 0) override;
};