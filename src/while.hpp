#pragma once
#include "condition.hpp"
#include "element.hpp"

class While : public Condition {
    Condition* condition;
    Condition* body;

public:
    While(Condition*, Condition*);
    void print(size_t indent = 0) override;
    void set_output_file(std::string const&) override;
};