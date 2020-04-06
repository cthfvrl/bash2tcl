#pragma once
#include <cstddef>

class Element {
protected:
    bool output;
    Element();

public:
    virtual void print(size_t indent = 0);
    virtual void noOutput();
    virtual ~Element() = default;
};
