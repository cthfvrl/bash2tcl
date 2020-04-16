#pragma once
#include "compound.hpp"
#include "condition.hpp"

class List : public Compound<Condition>, public Condition {
public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
    void print_condition(size_t indent = 0) override;
};