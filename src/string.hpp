#pragma once
#include "element.hpp"
#include <string>

class String : public Element {
    std::string string;

public:
    String(const std::string&);
    void print(size_t indent = 0) override;
    bool find(char);
};

class Var : public Element {
    std::string string;

public:
    Var(const std::string&);
    void print(size_t indent = 0) override;
};
