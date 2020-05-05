#pragma once
#include "compound.hpp"
#include "condition.hpp"

class List : public Compound<Condition>, public Condition {
    int subshellLevel = 0;

public:
    List(Condition*);
    void print(size_t indent = 0) override;
    int getSubshellLevel();
    void setSubshellLevel(int);
    void add(List*);
};