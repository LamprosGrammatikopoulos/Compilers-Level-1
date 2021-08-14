%option noyywrap

%{
#include "Grammar.tab.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
typedef yy::parser::token token;
int a;
double b, PI = 3.142, E = 2.718;
%}


%%

";" {return ';';}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}

"%" {return '%';}
"(" {return '(';}
")" {return ')';}
"=" {return '=';}
"<" {return '<';}
">" {return '>';}
"&" {return '&';}
"^" {return '^';}
"|" {return '|';}

"==" {return token::EQ_OP;}
"!=" {return token::NE_OP;}

"log2" {return token::LOG2;}
"log10" {return token::LOG10;}
"cos" {return token::COS;}
"sin" {return token::SIN;}
"tan" {return token::TAN;}
"cosh" {return token::COSH;}
"sinh" {return token::SINH;}
"tanh" {return token::TANH;}
"sqrt" {return token::SQRT;}
"exp" {return token::EXPONENTIAL;}
"abs" {return token::ABS;}
"floor" {return token::FLOOR;}
"ceil" {return token::CEIL;}
"pow" {return token::POW;}
"div" {return token::DIV;}
"mul" {return token::MUL;}
"add" {return token::ADD;}
"sub" {return token::SUB;}
"equals" {return token::EQUALS;}

"0"|[1-9][0-9]* {	yylval->i = atoi(yytext);
					return token::NUMBERint; }

[0-9]+[\.]?[0-9]*|[\.]?[0-9]+ {	yylval->d = atof(yytext);
								return token::NUMBERdouble; }

"a" { yylval->i = a;
	  return token::VARIABLEint; }

"b" { yylval->d = b;
	  return token::VARIABLEdouble; }

"PI" { yylval->d = PI;
	   return token::PI; }

"E" { yylval->d = E;
	  return token::E; }

[ \r\n\t]+ ;

%%




















