#pragma once
#include "compound.hpp"
#include "condition.hpp"

class List : public Compound<Condition>, public Condition {
    int subshellLevel = 0;

public:
    using Compound<Condition>::Compound;
    void print(size_t indent = 0) override;
    void print_condition(size_t indent = 0, bool reverse = false) override;
    int getSubshellLevel();
    void setSubshellLevel(int);
    void add(List*);
};