#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern FILE *yyin;
union semantic_info
{
	char* s;
	int i;
}SEMANTIC_INFO;
int yylex(FILE *yyin, union semantic_info *sem);

int main(int argc, char *argv[])
{
	union semantic_info *sem = &SEMANTIC_INFO;
	int cntint = 0;
	int cntchar = 0;
	int tokentype;
	fopen_s(&yyin, argv[1], "r");
	if (yyin == NULL)
	{
		printf("Error oppening file.");
		return -1;
	}
	while ((tokentype = yylex(yyin, sem)) != 0)
	{
		if (tokentype == 1)
		{
			printf("Vrethhke to alfarithmhtiko: %s\n", sem->s);
			cntchar += 1;
			free(sem->s);
		}
		else if (tokentype == 2)
		{
			printf("Vrethhke o arithmos: %d\n", sem->i);
			cntint += 1;
		}
	}
	printf("Strings found: %d\nNumbers found: %d\n", cntchar, cntint);
	fclose(yyin);
	return 0;
}

int yylex(FILE *yyin, union semantic_info *sem)
{
	int state = 0;
	int nextcharacter;
	char lexeme[100] = "\0";
	while ((nextcharacter = fgetc(yyin)) != EOF)
	{
		char chr = (char)nextcharacter;
		switch (state)
		{
			case 0:
			{
				if (isalpha(nextcharacter))
				{
					
					strncat(lexeme,&chr,1);
					state = 1;
				}
				else if (isdigit(nextcharacter))
				{
					strncat(lexeme, &chr, 1);
					state = 2;
				}
				else
				{
					state = 0;
				}
				break;
			}
			case 1:
			{
				if (isalnum(nextcharacter))
				{
					strncat(lexeme, &chr, 1);
					state = 1;
				}
				else
				{
					sem->s = (char*)malloc(sizeof(lexeme));
					if (sem->s == NULL)
					{
						printf("Error.");
					}
					strcpy_s(sem->s, 100, lexeme);
					return 1;
				}
				break;
			}
			case 2:
			{
				if (isdigit(nextcharacter))
				{
					strncat(lexeme, &chr, 1);
					state = 2;
				}
				/*else if(isalpha(nextcharacter))
				{
					strncat(lexeme, &chr, 1);
					state = 1;
				}*/
				else
				{
					sem->i = atoi(lexeme);
					return 2;
				}
				break;
			}
		}
	}
	return 0;
}