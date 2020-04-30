#pragma once
#include "compound.hpp"
#include "condition.hpp"

class Quote : public Compound<> {
public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
};