#pragma once
#include "element.hpp"

class Conditional : virtual public Element {
public:
    virtual void print_conditional(size_t indent = 0);
};