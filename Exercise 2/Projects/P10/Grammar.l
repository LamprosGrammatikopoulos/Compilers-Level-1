%option noyywrap

%{
#include <stdio.h>
extern FILE *fout;
%}



%%


cst[0-9]*{4}/2010 { fout=fopen("output10.txt","a"); fprintf_s(fout,"String found: {%s}\n",yytext); fclose(fout); }


%%



