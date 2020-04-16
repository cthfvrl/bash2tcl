#pragma once
#include "compound.hpp"
#include "element.hpp"
#include "string.hpp"

class Assignment : public Element {
    String* variable;
    Element* value;

public:
    Assignment(String*, Element*);
    void print(size_t indent = 0) override;
    void print_env(size_t indent = 0);
};

class AssignmentList : public Compound<> {
public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
    void print_env(size_t indent = 0);
};