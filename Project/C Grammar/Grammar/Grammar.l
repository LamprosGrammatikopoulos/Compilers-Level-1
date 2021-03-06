%option noyywrap

%{
#include "Grammar.tab.h"
#include "SymbolNodes.h"
#include "SymbolTable.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
typedef yy::parser::token token;
%}


%%

"switch" { return token::SWITCH; }
"case" { return token::CASE; }
"default" { return token::DEFAULT; }
"function" { return token::FUNCTION; }
"if" { return token::IF; }
"else" { return token::ELSE; }
"return" { return token::RETURN; }
"break" { return token::BREAK; }
"while" { return token::WHILE; }
"do" { return token::DO; }
"for" { return token::FOR; }
":" { return ':'; }
"=" { return '='; }
"(" { return '('; }
")" { return ')'; }
"{" { return '{'; }
"}" { return '}'; }
";" { return ';'; }
"+" { return token::PLUS; }
"-" { return token::MINUS; }
"*" { return token::MULT; }
"/" { return token::DIV; }
"!" { return token::NOT; }
"<" { return token::LT; }
">" { return token::GT; }
">=" { return token::GTE; }
"<=" { return token::LTE; }
"==" { return token::EQUAL; }
"!=" { return token::NEQUAL; }
"&&" { return token::AND; }
"||" { return token::OR; }

"0"|[1-9][0-9]* {  yylval->node = new CNUMBER(yytext);
				   return token::NUMBER;
				}

[a-zA-Z][a-zA-Z0-9_]* {  yylval->node = g_symbolTable.GetIdentifier(yytext); //epistrefei enan komvo an to IDENTIFIER exei dhmiourghthei ksana 
																			 //h dhmiourgei enan neo komvo kai ton anathetei sthn sumasiologikh timh gia thn apostolh tou ston suntaktiko analuth
						 return token::IDENTIFIER;
					  }

[ \r\n\t]+ ;

%%

