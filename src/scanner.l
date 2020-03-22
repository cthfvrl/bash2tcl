%{
    #include <string>
    #define YYSTYPE std::string
    #include "parser.tab.h"
    void yyerror(char *s);
%}

%option yylineno
%option noyywrap

%%

[0-9]+          { 
                    yylval = yytext;
                    return NUM;
                }
[a-zA-Z_][a-zA-Z0-9_]* {
                    yylval = yytext;
                    return WORD;
                }
[ \t\r]         ; // whitespace
[\n]+           {
                    return NEWLINE;
                }

%%
