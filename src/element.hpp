#pragma once
#include <cstddef>
#include <string>

class Element {
protected:
    Element();
    std::string output_file;

public:
    virtual void print(size_t indent = 0);
    virtual void set_output_file(std::string);
    virtual ~Element() = default;
};
