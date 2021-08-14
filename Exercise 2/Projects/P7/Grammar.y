%start root

%{
#include <stdio.h>
int yylex();
void yyerror(const char *message);
%}


%%

root : ;

%%

void yyerror(const char *message)
{
	printf("%s",message);
}