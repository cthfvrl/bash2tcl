#pragma once
#include "arithmetic.hpp"
#include "assignment.hpp"
#include "command.hpp"
#include "command_substitution.hpp"
#include "condition.hpp"
#include "element.hpp"
#include "for.hpp"
#include "if.hpp"
#include "list.hpp"
#include "pipeline.hpp"
#include "redirection.hpp"
#include "string.hpp"
#include "subshell.hpp"
#include "while.hpp"
#include "wordlist.hpp"

struct DATA {
    String* string;
    Var* var;
    Element* element;
    Condition* condition;
    List* list;
    Pipeline* pipeline;
    PipelineCommand* pipelinecommand;
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