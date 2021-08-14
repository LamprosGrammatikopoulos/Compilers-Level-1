%option noyywrap

%{
#include <stdio.h>
extern FILE *fout;
%}



%%

^[a-zA-Z0-9_]* { fout=fopen("output11.txt","a"); fprintf_s(fout,"String found: {%s}\n",yytext); fclose(fout); }


%%


