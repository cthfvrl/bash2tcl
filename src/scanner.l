%{
    #include <string>
    #include <iostream>
    #include <stack>
    #include "src/types.hpp"
    #include "parser.tab.h"
    void yyerror(std::string_view s);
    std::stack<int> brace_count;
    std::stack<int> state;
%}

%option yylineno
%option noyywrap

%x ARITHM
%x STR_EXACT STR
%s COMMAND_SUBST COMMAND_SUBST_BRACE

%%

'               {
                    state.push(YY_START);
                    BEGIN(STR_EXACT);
                }
<STR_EXACT>'    {
                    yylval.string = new String("{" + std::string(yytext, yytext + strlen(yytext) - 1) + "}");
                    BEGIN(state.top());
                    state.pop();
                    return WORD;
                }
<STR_EXACT>.|\n yymore();
<ARITHM>[a-zA-Z_][a-zA-Z0-9_]* {
                    yylval.string = new String("$" + std::string(yytext));
                    return WORD;
                }
<ARITHM>$[a-zA-Z_][a-zA-Z0-9_]* {
                    yylval.string = new String(yytext);
                    return WORD;
                }
<COMMAND_SUBST>` {
                    BEGIN(state.top());
                    state.pop();
                    return COMMAND_SUBST_CLOSE;
                }
<*>`            {
                    state.push(YY_START);
                    BEGIN(COMMAND_SUBST);
                    return COMMAND_SUBST_OPEN;
                }
<*>$\(          {
                    state.push(YY_START);
                    BEGIN(COMMAND_SUBST_BRACE);
                    brace_count.push(1);
                    return COMMAND_SUBST_OPEN;
                }
<COMMAND_SUBST_BRACE>\( {
                    ++brace_count.top();
                    return '(';
                }
<COMMAND_SUBST_BRACE>\) {
                    --brace_count.top();
                    if(!brace_count.top()) {
                        brace_count.pop();
                        BEGIN(state.top());
                        state.pop();
                        return COMMAND_SUBST_CLOSE;
                    }
                    return ')';
                }
<*>\(\(         {
                    if (YY_START == ARITHM)
                        yyerror("Unsupported nested arithmetic command");
                    state.push(YY_START);
                    BEGIN(ARITHM);
                    brace_count.push(2);
                    return ARITHMETIC_COMMAND_OPEN;
                }
<*>$\(\(        {
                    if (YY_START == ARITHM)
                        yyerror("Unsupported nested arithmetic expression");
                    state.push(YY_START);
                    BEGIN(ARITHM);
                    brace_count.push(2);
                    return ARITHMETIC_EXPR_OPEN;
                }
<ARITHM>\(      {
                    ++brace_count.top();
                    yylval.string = new String(yytext);
                    return WORD;
                }
<ARITHM>\)\)    {
                    brace_count.top() -= 2;
                    if(!brace_count.top()) {
                        BEGIN(state.top());
                        state.pop();
                        return ARITHMETIC_CLOSE;
                    }
                    if (brace_count.top() <= 0) {
                        yyerror("Incorrect bracket sequence");
                    }
                    ++brace_count.top();
                    unput(')');
                    yylval.string = new String(")");
                    return WORD;
                }
<ARITHM>\)      {
                    --brace_count.top();
                    yylval.string = new String(yytext);
                    return WORD;
                }
<ARITHM>.|\n    {
                    if(yytext[0] == '\n')
                        yytext[0] = ' ';
                    yylval.string = new String(yytext);
                    return WORD;
                }
\"              {
                    state.push(YY_START);
                    BEGIN(STR);
                    return '"';
                }
<STR>\"         {
                    BEGIN(state.top());
                    state.pop();
                    return '"';
                }
<STR>.|\n       {
                    yylval.string = new String(yytext);
                    return WORD;
                }
[0-9]+          { 
                    yylval.string = new String(yytext);
                    return WORD;
                }
=               return '=';
;[ \t\r\n;]*    return ';';
\(              return '(';
\)              return ')';
[0-9]*[<]       {
                    yylval.string = new String(yytext);
                    return DESCRIPTOR;
                }
[0-9&]*>        {
                    yylval.string = new String(yytext);
                    return DESCRIPTOR;
                }
&&              return AND;
\|\|            return OR;
\|              return '|';
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
[-$*&a-zA-Z_][a-zA-Z0-9_!@#$%^*,.?/+\-~]* {
                    yylval.string = new String(yytext);
                    return WORD;
                }
[ \t\r]         ; // ignore whitespaces
[\n]+           return ';';
#.*[\n]*        ; // ignore comments

%%

    