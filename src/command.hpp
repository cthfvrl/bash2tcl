#pragma once
#include "assignment.hpp"
#include "element.hpp"
#include "redirection.hpp"
#include "wordlist.hpp"

class Command : public Element {
    AssignmentList* assignmentlist;
    WordList* wordlist;
    RedirectionList* redirectionlist;

public:
    Command(WordList*);
    Command(AssignmentList*);
    Command(AssignmentList*, WordList*);
    Command(WordList*, RedirectionList*);
    Command(AssignmentList*, WordList*, RedirectionList*);
    void print(size_t indent = 0) override;
};