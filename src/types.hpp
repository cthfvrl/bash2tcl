#pragma once
#include "assignment.hpp"
#include "command.hpp"
#include "command_substitution.hpp"
#include "element.hpp"
#include "for.hpp"
#include "list.hpp"
#include "pipeline.hpp"
#include "redirection.hpp"
#include "string.hpp"
#include "wordlist.hpp"

struct DATA {
    String* string;
    Element* element;
    List* list;
    Pipeline* pipeline;
    Command* command;
    WordList* wordlist;
    Assignment* assignment;
    AssignmentList* assignmentlist;
    Redirection* redirection;
    RedirectionList* redirectionlist;
    CommandSubstitution* commandsubstitution;
    For* forclause;
    Range* range;
};
#define YYSTYPE DATA