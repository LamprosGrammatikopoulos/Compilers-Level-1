%option noyywrap

%{
#include <stdio.h>
extern FILE *fout;
%}



%%

\"([^"'\n\\]|(\\\n)|(\\.))*\"|\'([^"'\n\\]|(\\\n)|(\\.))*\' { fout=fopen("output1.txt","a"); fprintf_s(fout,"String found: {%s}\n",yytext); fclose(fout); }


%%



