#include "compound.hpp"

Compound::Compound(Element* e) : elements({e}) {
}

void Compound::add(Element* e) {
    elements.push_back(e);
}

void Compound::noOutput() {
    Element::noOutput();
    for (auto e : elements)
        e->noOutput();
}

Compound::~Compound() {
}