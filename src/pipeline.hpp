#pragma once
#include "compound.hpp"
#include "condition.hpp"
#include "redirection.hpp"
#include "wordlist.hpp"

class PipelineCommand : virtual public Element, public Condition {
    WordList* wordlist;
    RedirectionList* redirectionlist;

public:
    PipelineCommand(WordList*);
    PipelineCommand(WordList*, RedirectionList*);
    void print(size_t indent = 0) override;
    using Condition::print_condition;
};

class Pipeline : public Compound<PipelineCommand>, public Condition {
public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
    void print_condition(size_t indent = 0, bool reverse = false, bool in_body = true) override;
};
