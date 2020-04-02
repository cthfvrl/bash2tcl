%{
    #include <string>
    #include <iostream>
    #include <stack>
    #define YYSTYPE std::string
    #include "parser.tab.h"
    void yyerror(std::string_view s);
    int brace_count = 0;

%}

%option yylineno
%option noyywrap

%x ARITHM_EXPR ARITHM_COMMAND

%%

[0-9]+          { 
                    yylval = yytext;
                    return NUMBER;
                }
=               return '=';
;[ \t\r\n;]*    return ';';
\(\(            {
                    if (brace_count)
                        yyerror("Unsupported nested arithmetic command");
                    BEGIN(ARITHM_COMMAND);
                }
$\(\(           {
                    if (brace_count)
                        yyerror("Unsupported nested arithmetic expression");
                    BEGIN(ARITHM_EXPR);
                }
<ARITHM_COMMAND>. {
                #define ARITHMETIC(token) { \
                    char c = yytext[strlen(yytext) - 1]; \
                    if(c == '(') \
                        ++brace_count; \
                    else if(c == ')') \
                        --brace_count; \
                        if(brace_count == -2 && yytext[strlen(yytext) - 2] == ')') { \
                            brace_count = 0; \
                            yylval = std::string(yytext, yytext + strlen(yytext - 2)); \
                            BEGIN(INITIAL); \
                            return token; \
                        } \
                        else if (brace_count <= -2) { \
                            yyerror("Incorrect bracket sequence"); \
                        } \
                    yymore(); \
                }
                ARITHMETIC(ARITHMETIC_COMMAND)
                }
<ARITHM_EXPR>.  ARITHMETIC(ARITHMETIC_EXPR)
\(              return '(';
\)              return ')';
[<]             return '<';
>               return '>';
[<]=            return LEQ;
>=              return GEQ;
!               return '!';
&&              return AND;
\|\|            return OR; 
for             return FOR;
in              return IN;
if              return IF;
fi              return FI;
then            return THEN;
else            return ELSE;
elif            return ELIF;
while           return WHILE;
do              return DO;
done            return DONE;
$?[-a-zA-Z_][a-zA-Z0-9_!@#$%^*,.?/+\-~]* {
                    yylval = yytext;
                    return WORD;
                }
[ \t\r]         ; // ignore whitespaces
[\n]+           return ';';
#.*[\n]*        ; // ignore comments

%%

    