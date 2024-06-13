%{
#include <stdio.h>
#include "tokens.hpp"

%}
%option yylineno
%option noyywrap
digit ([0-9])

%%
\n
int return INT;
byte return BYTE;
b return B;
bool return BOOL;
and return AND;
or return OR;
not return NOT;
true return TRUE;
false return FALSE;
return return RETURN;
if return IF;
else return ELSE;
while return WHILE;
break return BREAK;
continue return CONTINUE;
; return SC;
\( return LPAREN;
\) return RPAREN;
\{ return LBRACE;
\} return RBRACE;
= return ASSIGN;

== return RELOP;
!= return RELOP;
\< return RELOP;
> return RELOP;
\<= return RELOP;
>= return RELOP;

\+ return BINOP;
\- return BINOP;
\* return BINOP;
\/ return BINOP;

\/\/.* return COMMENT;
[a-zA-Z]+[0-9a-zA-Z]*  return ID;
0|([1-9]+[0-9]*)    return NUM;
\"\\n\"    return FORBIDDEN_STR;
\"\\r\"    return FORBIDDEN_STR;
\"[^\\\"]*((\\n)|(\\r)|(\\t)|(\\0))*\"    return STRING;


.   return -1;
%%
