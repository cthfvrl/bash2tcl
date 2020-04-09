#pragma once
#include "element.hpp"

class While : public Element {
    Element* condition;
    Element* body;

public:
    While(Element*, Element*);
    void print(size_t indent = 0) override;
};