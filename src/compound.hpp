#pragma once
#include "element.hpp"
#include <vector>

template <class T = Element>
class Compound : virtual public Element {
protected:
    std::vector<T*> elements;

public:
    Compound() = default;

    Compound(T* e) : elements({e}) {
    }

    void add(T* e) {
        elements.push_back(e);
    }

    void noOutput() override {
        Element::noOutput();
        for (auto e : elements)
            e->noOutput();
    }

    virtual ~Compound() {
    }
};