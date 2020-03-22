%{
    #include <iostream>
    extern int yylineno;
    extern int yylex();
    void yyerror(char *s) {
      std::cerr << s << ", line " << yylineno << std::endl;
      exit(1);
    }
    #define YYSTYPE std::string
%}

%token WORD NUMBER NEWLINES

%%

PROGRAM:
    COMPOUND_COMMANDS
;

COMPOUND_COMMANDS:
    COMPOUND_COMMAND
|   COMPOUND_COMMAND NEWLINES
|   COMPOUND_COMMANDS NEWLINES COMPOUND_COMMAND
;

COMPOUND_COMMAND:
    SUBSHELL
|   LIST
/*|   ARITHMETIC_EXPRESSION*/
|   FOR_CLAUSE
|   IF_CLAUSE
|   WHILE_CLAUSE
;

SUBSHELL:
    '(' LIST ')'
;

FOR_CLAUSE:
    "for" WORD "in" WORD_LIST ';' "do" LIST ';' "done"
;

IF_CLAUSE:
    "if" LIST ';' "then" LIST ';' "fi"
|   "if" LIST ';' "then" LIST ';' ELSE_CLAUSE "fi"
;

ELSE_CLAUSE:
    "else" LIST ';'
|   "elif" LIST ';' "then" LIST ';'
|   "elif" LIST ';' "then" LIST ';' ELSE_CLAUSE
;

WHILE_CLAUSE:
    "while" LIST ';' "do" LIST ';' "done";

LIST:
    PIPELINE
|   LIST ';' PIPELINE
|   LIST "&&" PIPELINE
|   LIST "||" PIPELINE
;

PIPELINE:
    PIPELINE_SEQUENCE
|   '!' PIPELINE_SEQUENCE
;

PIPELINE_SEQUENCE:
    SIMPLE_COMMAND
|   PIPELINE_SEQUENCE '|' SIMPLE_COMMAND
;

SIMPLE_COMMAND:
    ASSIGNMENT_LIST WORD_LIST REDIRECTION_LIST
|   WORD_LIST REDIRECTION_LIST
|   ASSIGNMENT_LIST WORD_LIST
|   WORD_LIST
;

ASSIGNMENT_LIST:
    ASSIGNMENT
|   ASSIGNMENT_LIST ASSIGNMENT
;

ASSIGNMENT:
    WORD '=' WORD
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