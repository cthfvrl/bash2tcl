%{
    #include <iostream>
    #include "src/types.hpp"
    extern int yylineno;
    int yylex();
    void yyerror(std::string_view s) {
      std::cerr << s << ", line " << yylineno << std::endl;
      exit(1);
    }
%}

%token WORD NUMBER 
%token ARITHMETIC_EXPR ARITHMETIC_COMMAND
%token LEQ GEQ AND OR
%token FOR IN IF FI THEN ELSE ELIF WHILE DO DONE
%token COMMAND_SUBST_OPEN COMMAND_SUBST_CLOSE

%type<string> WORD NUMBER
%type<wordlist> WORD_LIST WORD_RANGE
%type<list> LIST
%type<pipeline> PIPELINE
%type<element> COMPOUND_COMMAND 
%type<command> SIMPLE_COMMAND
%type<assignment> ASSIGNMENT
%type<assignmentlist> ASSIGNMENT_LIST
%type<commandsubstitution> COMMAND_SUBSTITUTION
%type<forclause> FOR_CLAUSE
%type<range> RANGE
%type<element> IF_CLAUSE ELSE_CLAUSE WHILE_CLAUSE
%type<element> REDIRECTION_LIST REDIRECTION
%type<string> ARITHMETIC_EXPR ARITHMETIC_COMMAND

%%

PROGRAM:
    LIST                                            { $1->print(); delete $1; }
;

LIST:
    PIPELINE                                        { $$ = new List($1);  }
|   LIST ';' PIPELINE                               { $$ = $1; $$->add($3); }
|   LIST AND PIPELINE
|   LIST OR PIPELINE
|   '(' LIST ')'
|   LIST ';'                                        { $$ = $1; }
;

PIPELINE:
    COMPOUND_COMMAND                                { $$ = new Pipeline($1); }
|   PIPELINE '|' COMPOUND_COMMAND                   { $$ = $1; $$->add($3); }
;

COMPOUND_COMMAND:
    SIMPLE_COMMAND                                  { $$ = $1; }
|   ARITHMETIC_COMMAND
|   FOR_CLAUSE                                      { $$ = $1; }
|   IF_CLAUSE
|   WHILE_CLAUSE
;

FOR_CLAUSE:
    FOR WORD IN RANGE ';' DO LIST ';' DONE          { $$ = new For($2, $4, $7); }
;

RANGE:
    WORD_RANGE                                      { $$ = new Range($1); }
|   COMMAND_SUBSTITUTION                            { $$ = new Range($1); }
|   RANGE WORD_RANGE                                { $$ = $1; $$->add($2); }
|   RANGE COMMAND_SUBSTITUTION                      { $$ = $1; $$->add($2); }
;

WORD_RANGE:
    WORD                                            { $$ = new WordList($1); }
|   WORD_RANGE WORD                                 { $$ = $1; $$->add($2); }
;

IF_CLAUSE:
    IF LIST ';' THEN LIST ';' FI
|   IF LIST ';' THEN LIST ';' ELSE_CLAUSE FI
;

ELSE_CLAUSE:
    ELSE LIST ';'
|   ELIF LIST ';' THEN LIST ';'
|   ELIF LIST ';' THEN LIST ';' ELSE_CLAUSE
;

WHILE_CLAUSE:
    WHILE LIST ';' DO LIST ';' DONE
;

SIMPLE_COMMAND:
    ASSIGNMENT_LIST WORD_LIST REDIRECTION_LIST
|   WORD_LIST REDIRECTION_LIST
|   ASSIGNMENT_LIST WORD_LIST                       { $$ = new Command($1, $2); }
|   ASSIGNMENT_LIST                                 { $$ = new Command($1); }
|   WORD_LIST                                       { $$ = new Command($1); }
;

COMMAND_SUBSTITUTION:
    COMMAND_SUBST_OPEN LIST COMMAND_SUBST_CLOSE     { $$ = new CommandSubstitution($2); }
;

ASSIGNMENT_LIST:
    ASSIGNMENT                                      { $$ = new AssignmentList($1); }
|   ASSIGNMENT_LIST ASSIGNMENT                      { $$ = $1; $$->add($2); }
;

ASSIGNMENT:
    WORD '=' WORD                                   { $$ = new Assignment($1, $3); }
|   WORD '=' NUMBER                                 { $$ = new Assignment($1, $3); }
|   WORD '=' ARITHMETIC_EXPR
|   WORD '=' COMMAND_SUBSTITUTION
;

WORD_LIST:
    WORD                                            { $$ = new WordList($1); }
|   COMMAND_SUBSTITUTION                            { $$ = new WordList($1); }
|   WORD_LIST WORD                                  { $$ = $1; $$->add($2); }
|   WORD_LIST COMMAND_SUBSTITUTION                  { $$ = $1; $$->add($2); }
;

REDIRECTION_LIST:
    REDIRECTION
|   REDIRECTION_LIST REDIRECTION
;

REDIRECTION:
    '>' WORD
|   '<' WORD
|   NUMBER '>' WORD
|   NUMBER '<' WORD
;

%%
int main() {
    #if YYDEBUG == 1
        yydebug = 1;
    #endif
    return yyparse(); 
}