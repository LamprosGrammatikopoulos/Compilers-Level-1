#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern FILE *yyin;
FILE* fout;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("\nError!!! Missing Command line arguments");
		printf("\nUsage exe <inputfile> <outputfile>");
		exit(1);
	}
	else
	{
		fout = fopen(argv[2], "w");
		if (fout == NULL)
		{
			printf("Error openning file.\n");
		}
		yyin = fopen(argv[1], "r");
		if (yyin == NULL)
		{
			printf("Error openning file.\n");
		}
		yylex();
	}
	fclose(fout);
	fclose(yyin);
}

// (\"[\w\s]*\")|(\'[\w\s]*\')
// (\"[a-zA-Z0-9_ \n]*\")|(\'[a-zA-Z0-9_ \n]*\')