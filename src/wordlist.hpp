#pragma once
#include "compound.hpp"

class WordList : public Compound<> {
public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
};
