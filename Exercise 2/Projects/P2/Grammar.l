%option noyywrap

%{
#include <stdio.h>
extern FILE *fout;
%}



%%

(\/\*([^*]|\*+[^\/\*])*\*+\/)|\/\/([^\n])* { fout=fopen("output2.txt","a"); fprintf_s(fout,"String found: {%s}\n",yytext); fclose(fout); }

%%



