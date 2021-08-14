%option noyywrap

%{
#include <stdio.h>
extern FILE *fout;
%}



%%

0|[+-]?[1-9][0-9]* { fout=fopen("output3.txt","a"); fprintf_s(fout,"String found: {%s}\n",yytext); fclose(fout); }


%%


