#pragma once
#include "assignment.hpp"
#include "element.hpp"
#include "wordlist.hpp"

class Command : public Element {
    AssignmentList* assignmentlist;
    WordList* wordlist;

public:
    Command(WordList*);
    Command(AssignmentList*);
    Command(AssignmentList*, WordList*);
    void print(size_t indent = 0) override;
};