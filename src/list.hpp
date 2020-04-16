#pragma once
#include "compound.hpp"
#include "condition.hpp"

class List : public Compound<Condition>, public Condition {
    int subshellLevel = 0;

public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
    void print_condition(size_t indent = 0) override;
    int getSubshellLevel();
    void setSubshellLevel(int);
};