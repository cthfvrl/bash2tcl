#pragma once
#include "element.hpp"

class Condition : virtual public Element {
public:
    virtual void print_condition(size_t indent = 0, bool reverse = false, bool in_body = true);
};