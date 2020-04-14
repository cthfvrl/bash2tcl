%{
    #include <string>
    #include <iostream>
    #include <stack>
    #include "src/types.hpp"
    #include "parser.tab.h"
    void yyerror(std::string_view s);
    int arithm_brace_count = 0;
    std::stack<int> command_brace_count;
    std::stack<int> state;
%}

%option yylineno
%option noyywrap

%x ARITHM_EXPR ARITHM_COMMAND
%x STR_EXACT STR
%s COMMAND_SUBST COMMAND_SUBST_BRACE

%%

[0-9]+          { 
                    yylval.string = new String(yytext);
                    return NUMBER;
                }
=               return '=';
;[ \t\r\n;]*    return ';';
'               {
                    state.push(YY_START);
                    BEGIN(STR_EXACT);
                }
<STR_EXACT>'    {
                    yylval.string = new String(std::string(yytext, yytext + strlen(yytext) - 1));
                    BEGIN(state.top());
                    state.pop();
                    return WORD;
                }
<STR_EXACT>.|\n yymore();
\"              {
                    state.push(YY_START);
                    BEGIN(STR);
                    yymore();
                }
<STR>\"         {
                    yylval.string = new String(yytext);
                    BEGIN(state.top());
                    state.pop();
                    return WORD;
                }
<STR>.|\n       yymore();
<COMMAND_SUBST>` {
                    BEGIN(state.top());
                    state.pop();
                    return COMMAND_SUBST_CLOSE;
                }
`               {
                    state.push(YY_START);
                    BEGIN(COMMAND_SUBST);
                    return COMMAND_SUBST_OPEN;
                }
$\(             {
                    state.push(YY_START);
                    BEGIN(COMMAND_SUBST_BRACE);
                    command_brace_count.push(1);
                    return COMMAND_SUBST_OPEN;
                }
<COMMAND_SUBST_BRACE>\( {
                    ++command_brace_count.top();
                }
<COMMAND_SUBST_BRACE>\) {
                    --command_brace_count.top();
                    if(!command_brace_count.top()) {
                        command_brace_count.pop();
                        BEGIN(state.top());
                        state.pop();
                        return COMMAND_SUBST_CLOSE;
                    }
                }
\(\(            {
                    if (arithm_brace_count)
                        yyerror("Unsupported nested arithmetic command");
                    state.push(YY_START);
                    BEGIN(ARITHM_COMMAND);
                    arithm_brace_count = 2;
                }
$\(\(           {
                    if (arithm_brace_count)
                        yyerror("Unsupported nested arithmetic expression");
                    state.push(YY_START);
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
                            yylval.string = new String(std::string(yytext, yytext + strlen(yytext) - 2)); \
                            BEGIN(state.top()); \
                            state.pop(); \
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
                    yylval.string = new String(yytext);
                    return WORD;
                }
[ \t\r]         ; // ignore whitespaces
[\n]+           return ';';
#.*[\n]*        ; // ignore comments

%%

    