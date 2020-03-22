%{
    #include <string>
    #include <iostream>
    #define YYSTYPE std::string
    #include "parser.tab.h"
    void yyerror(char *s);
%}

%option yylineno
%option noyywrap

%%

[0-9]+          { 
                    yylval = yytext;
                    return NUMBER;
                }
[-a-zA-Z_][a-zA-Z0-9_!@#$%^*,.?/+-=~]* {
                    yylval = yytext;
                    return WORD;
                }
[ \t\r]         ; // ignore whitespaces
[\n]+           {
                    return NEWLINES;
                }

%%
