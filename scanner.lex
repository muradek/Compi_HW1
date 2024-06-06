%{
#include <stdio.h>
#include "tokens.hpp"

%}

%option noyywrap

digit ([0-9])

%%
{digit}+    return NUM;
.   printf("unrecognized");
%%
