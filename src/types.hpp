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
#include "while.hpp"
#include "if.hpp"
#include "arithmetic.hpp"

struct DATA {
    String* string;
    Var* var;
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
    While* whileclause;
    If* ifclause;
    Arithmetic* arithmetic;
};
#define YYSTYPE DATA