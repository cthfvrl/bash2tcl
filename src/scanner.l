%{
    #include <string>
    #include <iostream>
    #include <stack>
    #define YYSTYPE std::string
    #include "parser.tab.h"
    void yyerror(std::string_view s);
    int arithm_brace_count = 0;
    int command_brace_count = 0;
%}

%option yylineno
%option noyywrap

%x ARITHM_EXPR ARITHM_COMMAND
%x STR_EXACT STR
%x COMMAND_SUBST COMMAND_SUBST_BRACE

%%

[0-9]+          { 
                    yylval = yytext;
                    return NUMBER;
                }
=               return '=';
;[ \t\r\n;]*    return ';';
'               BEGIN(STR_EXACT);
<STR_EXACT>'    {
                    yylval = std::string(yytext, yytext + strlen(yytext - 1));
                    BEGIN(INITIAL);
                    return WORD;
                }
<STR_EXACT>.|\n yymore();
\"              BEGIN(STR);
<STR>\"         {
                    yylval = std::string(yytext, yytext + strlen(yytext - 1));
                    BEGIN(INITIAL);
                    return WORD;
                }
<STR>.|\n       yymore();
`               BEGIN(COMMAND_SUBST);
<COMMAND_SUBST>` {
                    yylval = std::string(yytext, yytext + strlen(yytext - 1));
                    BEGIN(INITIAL);
                    return COMMAND;
                }
<COMMAND_SUBST>.|\n yymore();
$\(             {
                    if (command_brace_count)
                        yyerror("Unsupported nested command substitution");
                    BEGIN(COMMAND_SUBST_BRACE);
                    command_brace_count = 1;
                }
<COMMAND_SUBST_BRACE>.|\n {
                    char c = yytext[strlen(yytext) - 1];
                    if(c == '(')
                        ++command_brace_count;
                    else if(c == ')')
                        --command_brace_count;
                    if(!command_brace_count) {
                        yylval = std::string(yytext, yytext + strlen(yytext - 1));
                        BEGIN(INITIAL);
                        return COMMAND;
                    }
                }
\(\(            {
                    if (arithm_brace_count)
                        yyerror("Unsupported nested arithmetic command");
                    BEGIN(ARITHM_COMMAND);
                    arithm_brace_count = 2;
                }
$\(\(           {
                    if (arithm_brace_count)
                        yyerror("Unsupported nested arithmetic expression");
                    BEGIN(ARITHM_EXPR);
                    arithm_brace_count = 2;
                }
<ARITHM_COMMAND>. {
                #define ARITHMETIC(token) { \
                    char c = yytext[strlen(yytext) - 1]; \
                    if(c == '(') \
                        ++arithm_brace_count; \
                    else if(c == ')') {\
                        --arithm_brace_count; \
                        if(!arithm_brace_count && yytext[strlen(yytext) - 2] == ')') { \
                            yylval = std::string(yytext, yytext + strlen(yytext - 2)); \
                            BEGIN(INITIAL); \
                            return token; \
                        } \
                        else if (arithm_brace_count <= 0) { \
                            yyerror("Incorrect bracket sequence"); \
                        } \
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
[-$*a-zA-Z_][a-zA-Z0-9_!@#$%^*,.?/+\-~]* {
                    yylval = yytext;
                    return WORD;
                }
[ \t\r]         ; // ignore whitespaces
[\n]+           return ';';
#.*[\n]*        ; // ignore comments

%%

    