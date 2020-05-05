#pragma once
#include "condition.hpp"
#include "list.hpp"

class Subshell : public Condition {
    List* list;
    int subshellLevel;

public:
    Subshell(List*);
    void print(size_t indent = 0) override;
};