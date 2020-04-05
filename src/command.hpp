#pragma once
#include "element.hpp"
#include "wordlist.hpp"

class Command : public Element {
    WordList *wordlist;
public:
    Command(WordList *);
    void print(size_t indent = 0) override;
};