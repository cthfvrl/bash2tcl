#pragma once
#include "command.hpp"
#include "element.hpp"
#include "list.hpp"
#include "pipeline.hpp"
#include "string.hpp"
#include "wordlist.hpp"
#include "assignment.hpp"

struct DATA {
    String* string;
    Element* element;
    List* list;
    Pipeline* pipeline;
    Command* command;
    WordList* wordlist;
    Assignment* assignment;
    AssignmentList* assignmentlist;
};
#define YYSTYPE DATA