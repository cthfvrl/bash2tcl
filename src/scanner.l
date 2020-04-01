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
=               return '=';
;               return ';';
\(\(            return BR2_OPEN;
\)\)            return BR2_CLOSE;
$\(\(           return ARITHM_OPEN;
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
[-a-zA-Z_][a-zA-Z0-9_!@#$%^*,.?/+\-~]* {
                    yylval = yytext;
                    return WORD;
                }
[ \t\r]         ; // ignore whitespaces
[\n]+           {
                    return NEWLINES;
                }

%%
