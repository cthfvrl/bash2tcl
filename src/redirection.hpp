#pragma once
#include "compound.hpp"
#include "element.hpp"
#include "string.hpp"

class Redirection : public Element {
    String* descriptor;
    std::string redirection;
    String* value;

public:
    Redirection(const std::string&, String*);
    Redirection(String*, const std::string&, String*);
    void print(size_t indent = 0) override;
};

class RedirectionList : public Compound<> {
public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
};