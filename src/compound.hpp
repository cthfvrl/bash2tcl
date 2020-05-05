#pragma once
#include "element.hpp"
#include <string>
#include <vector>

template <class T = Element>
class Compound : virtual public Element {
protected:
    std::vector<T*> elements;

public:
    Compound() = default;

    Compound(T* e) : elements({e}) {
    }

    virtual void add(T* e) {
        elements.push_back(e);
    }

    void set_output_file(std::string new_output_file) override {
        Element::set_output_file(new_output_file);
        for (auto e : elements)
            e->set_output_file(new_output_file);
    }

    virtual ~Compound() {
    }
};