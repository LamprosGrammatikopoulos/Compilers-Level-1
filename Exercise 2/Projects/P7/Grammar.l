%option noyywrap

%{
#include <stdio.h>
extern FILE *fout;
%}



%%

"+" printf("add\n");
"-" printf("subtract\n");
"/" printf("devide\n");
"*" printf("multiply\n");
"+=" printf("assign add\n");
"-=" printf("assign subtract\n");
"++" printf("increase\n");
"--" printf("decrease\n");
"&&" printf("AND\n");
"||" printf("OR\n");
"^" printf("XOR\n");
"&" printf("bitwise AND\n");
"|" printf("bitwise OR\n");
">=" printf("bigger or equal\n");
"<=" printf("smaller or equal\n");
">>" printf("left shift\n");
"<<" printf("right shift\n");
"!=" printf("not equal\n");
"==" printf("equal\n");


%%


