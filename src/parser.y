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
%token AND OR
%token FOR IN IF FI THEN ELSE ELIF WHILE DO DONE
%token COMMAND_SUBST_OPEN COMMAND_SUBST_CLOSE
%token ARITHMETIC_EXPR_OPEN ARITHMETIC_COMMAND_OPEN ARITHMETIC_CLOSE

%type<string> WORD NUMBER
%type<wordlist> WORD_LIST WORD_RANGE
%type<list> LIST
%type<pipeline> PIPELINE
%type<condition> COMPOUND_COMMAND
%type<command> SIMPLE_COMMAND
%type<pipelinecommand> PIPELINE_COMMAND
%type<assignment> ASSIGNMENT
%type<assignmentlist> ASSIGNMENT_LIST
%type<redirection> REDIRECTION
%type<redirectionlist> REDIRECTION_LIST
%type<commandsubstitution> COMMAND_SUBSTITUTION
%type<forclause> FOR_CLAUSE
%type<range> RANGE
%type<whileclause> WHILE_CLAUSE
%type<ifclause> IF_CLAUSE ELSE_CLAUSE
%type<arithmetic> ARITHMETIC ARITHMETIC1
%type<element> ARITHMETIC_ELEMENT

%left ';'
%left OR AND
%left '|'

%%

PROGRAM:
    LIST                                            { $1->print(); std::cout << '\n'; delete $1; }
;

LIST:
    COMPOUND_COMMAND                                { $$ = new List($1); }
|   LIST ';' LIST                                   { $$ = $1; $$->add($3); }
|   LIST AND LIST
|   LIST OR LIST
|   '(' LIST ')'                                    { $$ = new List(new Subshell($2)); $$->setSubshellLevel($2->getSubshellLevel()+1); }
|   LIST ';'                                        { $$ = $1; }
|   ';' LIST                                        { $$ = $2; }
;

COMPOUND_COMMAND:
    PIPELINE                                        { $$ = $1; }
|   SIMPLE_COMMAND                                  { $$ = $1; }
|   ARITHMETIC_COMMAND_OPEN ARITHMETIC              { $$ = $2; }
|   FOR_CLAUSE                                      { $$ = $1; }
|   IF_CLAUSE                                       { $$ = $1; }
|   WHILE_CLAUSE                                    { $$ = $1; }
;

PIPELINE:
    PIPELINE_COMMAND '|' PIPELINE_COMMAND           { $$ = new Pipeline($1); $$->add($3); }
|   PIPELINE '|' PIPELINE_COMMAND                   { $$ = $1; $$->add($3); }
;

ARITHMETIC:
    ARITHMETIC1 ARITHMETIC_CLOSE                    { $$ = $1; }
;

ARITHMETIC1:
    ARITHMETIC_ELEMENT                              { $$ = new Arithmetic($1); }
|   ARITHMETIC1 ARITHMETIC_ELEMENT                  { $$ = $1; $$->add($2); }
;

ARITHMETIC_ELEMENT:
    WORD                                            { $$ = $1; }
|   COMMAND_SUBSTITUTION                            { $$ = $1; }
;

FOR_CLAUSE:
    FOR WORD IN RANGE ';' DO LIST DONE              { $$ = new For($2, $4, $7); }
;

RANGE:
    WORD_RANGE                                      { $$ = new Range($1); }
|   COMMAND_SUBSTITUTION                            { $$ = new Range($1); }
|   RANGE WORD_RANGE                                { $$ = $1; $$->add($2); }
|   RANGE COMMAND_SUBSTITUTION                      { $$ = $1; $$->add($2); }
;

WORD_RANGE:
    WORD                                            { $$ = new WordList(Pattern::check_pattern($1)); }
|   WORD_RANGE WORD                                 { $$ = $1; $$->add(Pattern::check_pattern($2)); }
;

IF_CLAUSE:
    IF LIST THEN LIST FI                            { $$ = new If(new IfElement($2, $4)); }
|   IF LIST THEN LIST ELSE_CLAUSE FI                { $$ = $5; $$->add(new IfElement($2, $4)); }
;

ELSE_CLAUSE:
    ELSE LIST                                       { $$ = new If(); $$->addElse($2); }
|   ELIF LIST THEN LIST                             { $$ = new If(new IfElement($2, $4)); }
|   ELIF LIST THEN LIST ELSE_CLAUSE                 { $$ = $5; $$->add(new IfElement($2, $4)); }
;

WHILE_CLAUSE:
    WHILE LIST DO LIST DONE                         { $$ = new While($2, $4); }
;

SIMPLE_COMMAND:
    ASSIGNMENT_LIST WORD_LIST REDIRECTION_LIST      { $$ = new Command($1, $2, $3); }
|   WORD_LIST REDIRECTION_LIST                      { $$ = new Command($1, $2); }
|   ASSIGNMENT_LIST WORD_LIST                       { $$ = new Command($1, $2); }
|   ASSIGNMENT_LIST                                 { $$ = new Command($1); }
|   WORD_LIST                                       { $$ = new Command($1); }
;

PIPELINE_COMMAND:
    WORD_LIST REDIRECTION_LIST                      { $$ = new PipelineCommand($1, $2); }
|   WORD_LIST                                       { $$ = new PipelineCommand($1); }
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
|   WORD '=' ARITHMETIC_EXPR_OPEN ARITHMETIC        { $$ = new Assignment($1, new CommandSubstitution($4)); }
|   WORD '=' COMMAND_SUBSTITUTION                   { $$ = new Assignment($1, $3); }
;

WORD_LIST:
    WORD                                            { $$ = new WordList($1); }
|   COMMAND_SUBSTITUTION                            { $$ = new WordList($1); }
|   WORD_LIST WORD                                  { $$ = $1; $$->add($2); }
|   WORD_LIST COMMAND_SUBSTITUTION                  { $$ = $1; $$->add($2); }
;

REDIRECTION_LIST:
    REDIRECTION                                     { $$ = new RedirectionList($1); }
|   REDIRECTION_LIST REDIRECTION                    { $$ = $1; $$->add($2); }
;

REDIRECTION:
    '>' WORD                                        { $$ = new Redirection(">", $2); }
|   '<' WORD                                        { $$ = new Redirection("<", $2); }
|   NUMBER '>' WORD                                 { $$ = new Redirection($1, ">", $3); }
|   NUMBER '<' WORD                                 { $$ = new Redirection($1, "<", $3); }
;

%%
int main() {
    #if YYDEBUG == 1
        yydebug = 1;
    #endif
    return yyparse(); 
}