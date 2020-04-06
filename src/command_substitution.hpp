#pragma once
#include "element.hpp"

class CommandSubstitution : public Element {
    Element* element;

public:
    CommandSubstitution(Element*);
    void print(size_t indent = 0) override;
};