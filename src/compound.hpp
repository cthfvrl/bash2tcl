#pragma once
#include "element.hpp"
#include <vector>

class Compound : virtual public Element {
protected:
    std::vector<Element*> elements;

public:
    Compound() = default;
    Compound(Element*);
    void add(Element*);
    void noOutput() override;
    virtual ~Compound();
};