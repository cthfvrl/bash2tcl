#pragma once
#include "element.hpp"
#include <string>

class CommandSubstitution : public Element {
    Element* element;
    int index;
    static int index_max;
    static const std::string fname_prefix;

    std::string get_fname();
    static std::string get_fname(int);

public:
    CommandSubstitution(Element*);
    void print(size_t indent = 0) override;
    static void remove_tempfiles();
};