#include "compound.hpp"

Compound::Compound(Element* e) : elements({e}) {
}

void Compound::add(Element* e) {
    elements.push_back(e);
}

Compound::~Compound() {
}