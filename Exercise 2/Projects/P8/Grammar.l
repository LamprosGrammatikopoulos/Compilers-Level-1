%option noyywrap

%{
#include <stdio.h>
extern FILE *fout;
%}



%%

(\"[a-zA-Z][0-9a-zA-Z_]*[\.][a-zA-Z0-9]{1,3}\")|(\'[a-zA-Z][0-9a-zA-Z_]*[\.][a-zA-Z0-9]{1,3}\') { fout=fopen("output8.txt","a"); fprintf_s(fout,"String found: {%s}\n",yytext); fclose(fout); }
										

%%


