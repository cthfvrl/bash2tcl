#pragma once
#include "compound.hpp"
#include "conditional.hpp"

class List : public Compound, public Conditional {
public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
};