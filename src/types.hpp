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
#include "quote.hpp"
#include "redirection.hpp"
#include "string.hpp"
#include "subshell.hpp"
#include "while.hpp"
#include "wordlist.hpp"

struct DATA {
    String* string;
    Element* element;
    Condition* condition;
    List* list;
    Pipeline* pipeline;
    PipelineCommand* pipelinecommand;
    Command* command;
    Quote* quote;
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
    ArithmeticCommand* arithmeticcommand;
    ArithmeticExpression* arithmeticexpr;
};
#define YYSTYPE DATA