%option noyywrap

%{
#include <stdio.h>
extern FILE *fout;
%}



%%

[ \t\n]* { fout=fopen("output6.txt","a"); fprintf_s(fout,"String found: {%s}\n",yytext); fclose(fout); }


%%


