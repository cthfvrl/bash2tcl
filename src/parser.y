%{
    #include <iostream>
    extern int yylineno;
    int yylex();
    void yyerror(std::string_view s) {
      std::cerr << s << ", line " << yylineno << std::endl;
      exit(1);
    }
    #define YYSTYPE std::string
%}

%token WORD NUMBER NEWLINES 
%token ARITHMETIC_EXPR ARITHMETIC_COMMAND
%token LEQ GEQ AND OR
%token FOR IN IF FI THEN ELSE ELIF WHILE DO DONE
%token COMMAND

%%

PROGRAM:
    LIST
;

LIST:
    PIPELINE
|   LIST ';' PIPELINE
|   LIST AND PIPELINE
|   LIST OR PIPELINE
|   '(' LIST ')'
|   LIST ';'
;

PIPELINE:
    PIPELINE_SEQUENCE
|   '!' PIPELINE_SEQUENCE
;

PIPELINE_SEQUENCE:
    COMPOUND_COMMAND
|   PIPELINE_SEQUENCE '|' COMPOUND_COMMAND
;

COMPOUND_COMMAND:
    SIMPLE_COMMAND
|   ARITHMETIC_COMMAND
|   FOR_CLAUSE
|   IF_CLAUSE
|   WHILE_CLAUSE
;

FOR_CLAUSE:
    FOR WORD IN WORD_LIST ';' DO LIST ';' DONE
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
|   ASSIGNMENT_LIST WORD_LIST
|   ASSIGNMENT_LIST
|   WORD_LIST
;

ASSIGNMENT_LIST:
    ASSIGNMENT
|   ASSIGNMENT_LIST ASSIGNMENT
;

ASSIGNMENT:
    WORD '=' WORD
|   WORD '=' NUMBER
|   WORD '=' ARITHMETIC_EXPR
;

WORD_LIST:
    WORD
|   WORD_LIST WORD
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