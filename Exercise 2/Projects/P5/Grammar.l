%option noyywrap

%{
#include <stdio.h>
extern FILE *fout;
%}



%%

[+-]?(0|[1-9][0-9]*)(\.(0|[1-9][0-9]*))?(([Xx]10[\*\^]|[Ee])[+-]?(0|[1-9][0-9]+))? { fout=fopen("output5.txt","a"); fprintf_s(fout,"String found: {%s}\n",yytext); fclose(fout); }


%%


