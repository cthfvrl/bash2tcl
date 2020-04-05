#pragma once
#include <cstddef>

class Element {
public: // Replace with protected later
    Element() = default;

public:
    virtual void print(size_t indent = 0) {}
    virtual ~Element() = default;
};
