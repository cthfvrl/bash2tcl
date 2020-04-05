#pragma once
#include "compound.hpp"

class Pipeline : public Compound {
    bool inverted;

public:
    using Compound::Compound;
    void invert();
    void print(size_t indent = 0) override;
};