#pragma once
#include "compound.hpp"
#include "element.hpp"
#include <vector>

class IfElement : public Element {
    Element* condition;
    Element* body;

public:
    IfElement(Element*, Element*);
    void print(size_t indent = 0) override;
};

class If : public Compound {
    Element* elseBody;

public:
    using Compound::Compound;
    If();
    void addElse(Element*);
    void print(size_t indent = 0) override;
};