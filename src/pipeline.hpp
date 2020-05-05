#pragma once
#include "compound.hpp"
#include "condition.hpp"
#include "redirection.hpp"
#include "wordlist.hpp"

class PipelineCommand : public Element {
    WordList* wordlist;
    RedirectionList* redirectionlist;

public:
    PipelineCommand(WordList*);
    PipelineCommand(WordList*, RedirectionList*);
    void print(size_t indent = 0) override;
};

class Pipeline : public Compound<PipelineCommand>, public Condition {
public:
    using Compound::Compound;
    void print(size_t indent = 0) override;
};
