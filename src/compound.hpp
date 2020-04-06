#pragma once
#include "element.hpp"
#include <vector>

class Compound : public Element {
protected:
    std::vector<Element*> elements;

public:
    Compound(Element*);
    void add(Element*);
    void noOutput() override;
    virtual ~Compound();
};