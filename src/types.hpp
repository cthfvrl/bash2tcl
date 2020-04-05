#pragma once
#include "command.hpp"
#include "element.hpp"
#include "list.hpp"
#include "pipeline.hpp"
#include "string.hpp"
#include "wordlist.hpp"

struct DATA {
    String* string;
    Element* element;
    List* list;
    Pipeline* pipeline;
    Command* command;
    WordList* wordlist;
};
#define YYSTYPE DATA