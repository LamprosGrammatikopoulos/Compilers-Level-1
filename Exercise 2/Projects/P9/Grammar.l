%option noyywrap

%{
#include <stdio.h>
extern FILE *fout;
%}



%%

"do" printf("do");
"for" printf("for");
"continue" printf("continue");
"state" printf("state");
"else" printf("else");


%%


