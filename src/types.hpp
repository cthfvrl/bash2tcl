#pragma once
#include "command.hpp"
#include "element.hpp"
#include "list.hpp"
#include "pipeline.hpp"
#include "string.hpp"
#include "wordlist.hpp"
#include "assignment.hpp"
#include "command_substitution.hpp"
#include "for.hpp"

struct DATA {
    String* string;
    Element* element;
    List* list;
    Pipeline* pipeline;
    Command* command;
    WordList* wordlist;
    Assignment* assignment;
    AssignmentList* assignmentlist;
    CommandSubstitution* commandsubstitution;
    For* forclause;
    Range* range;
};
#define YYSTYPE DATA