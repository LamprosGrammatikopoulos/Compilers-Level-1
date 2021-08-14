%language "C++"


%{
#include "Grammar.tab.h"
#include "SymbolNodes.h"
#include "SymbolTable.h"
extern int yylex(yy::parser::semantic_type *yylval);
%}

%code requires{
#include "STNode.h"
}
%union{
	STNode *node;
}
 
%start compileUnit
%token <node> NUMBER IDENTIFIER
%token RETURN BREAK IF ELSE WHILE DO FOR FUNCTION SWITCH CASE DEFAULT
%nonassoc IFPREC
%left '='
%left OR
%left AND
%nonassoc GTE GT LTE LT EQUAL NEQUAL
%left PLUS MINUS
%left MULT DIV
%nonassoc NOT ELSE
%type <node> expression compileUnit statement_list statement if_statement compound_statement while_statement dowhile_statement for_statement function_definition fargs args switch_statement labeled_statement

%%

compileUnit : statement {  g_root = $$ = new CCompileUnit(); $$->AddChild($1); }
			| compileUnit statement { $$ = g_root = new CCompileUnit(); $$->AddChild($1); $$->AddChild($2); }
			| function_definition { $$ = g_root = new CCompileUnit(); $$->AddChild($1); }
            | compileUnit function_definition { $$ = g_root = new CCompileUnit(); $$->AddChild($1); $$->AddChild($2); }
			;

function_definition : FUNCTION IDENTIFIER '(' fargs ')' compound_statement { $$ = new CFunctionDefinition(); $$->AddChild($2); $$->AddChild($4); $$->AddChild($6); g_symbolTable.SetValue(((CIDENTIFIER *)$2)->m_name, $$); }
                    | FUNCTION IDENTIFIER '(' ')' compound_statement { $$ = new CFunctionDefinition(); $$->AddChild($2); $$->AddChild($5); g_symbolTable.SetValue(((CIDENTIFIER *)$2)->m_name, $$); }
                    ;

fargs : IDENTIFIER { $$ = new CFormalArgs(); $$->AddChild($1); }
      | fargs ',' IDENTIFIER { $$ = new CFormalArgs(); $$->AddChild($1); $$->AddChild($3); }
      ;

statement_list : statement { $$ = new CStatement_list(); $$->AddChild($1); }
		       | statement_list statement { $$ = new CStatement_list(); $$->AddChild($1); $$->AddChild($2); }
		       ;

statement : expression ';' { $$ = new CExpressionStatement(); $$->AddChild($1); }
		  | compound_statement
		  | switch_statement
		  | labeled_statement
		  | if_statement
		  | while_statement
		  | dowhile_statement
		  | for_statement
		  | RETURN expression ';' { $$ = new CReturnStatement(); $$->AddChild($2); } 
		  | BREAK ';' { $$ = new CBreakStatement(); }
		  | ';' { $$ = new CNullStatement(); }
		  ;

switch_statement : SWITCH '(' expression ')' statement { $$ = new CSwitchStatement(); $$->AddChild($3); $$->AddChild($5); printf("switch\n"); }
				 ;

labeled_statement : CASE expression ':' statement { $$ = new CLabeledStatement(); $$->AddChild($2); $$->AddChild($4); printf("labeled\n"); }
				  | DEFAULT ':' statement { $$ = new CLabeledStatement(); $$->AddChild($3); }
				  ;

if_statement : IF '(' expression ')' statement %prec IFPREC { $$ = new CIfStatement(); $$->AddChild($3); $$->AddChild($5); }
			 | IF '(' expression ')' statement ELSE statement { $$ = new CIfStatement(); $$->AddChild($3); $$->AddChild($5); $$->AddChild($7); }
			 ;

while_statement : WHILE '(' expression ')' statement  { $$ = new CWhileStatement(); $$->AddChild($3); $$->AddChild($5); }
			    ;

dowhile_statement : DO statement WHILE '(' expression ')' { $$ = new CDoWhileStatement(); $$->AddChild($2); $$->AddChild($5); }
				  ;

for_statement : FOR '(' expression ';' expression ';' expression ')' statement { $$ = new CForStatement(); $$->AddChild($3); $$->AddChild($5); $$->AddChild($7); $$->AddChild($9); }
			  ;

compound_statement : '{' '}' { $$ = new CCompoundStatement(); }
				   | '{' statement_list '}' { $$ = new CCompoundStatement(); $$->AddChild($2); }
				   ;

expression : NUMBER { $$ = $1; }
		   | IDENTIFIER
		   | IDENTIFIER '=' expression {$$ = new CAssignment(); $$->AddChild($1); $$->AddChild($3); }
		   | IDENTIFIER '(' ')' { $$ = new CExpressionFCALL(); $$->AddChild($1); }
           | IDENTIFIER '(' args ')' { $$ = new CExpressionFCALL(); $$->AddChild($1->GetChild(0)); $$->AddChild($3); }
		   | expression PLUS expression { $$ = new CAddition(); $$->AddChild($1); $$->AddChild($3); }
		   | expression MINUS expression { $$ = new CSubtraction(); $$->AddChild($1); $$->AddChild($3); }
		   | expression MULT expression { $$ = new CMultiplication(); $$->AddChild($1); $$->AddChild($3); }
		   | expression DIV expression { $$ = new CDivision(); $$->AddChild($1); $$->AddChild($3); }
		   | '(' expression ')' { $$ = $2; }
		   | expression AND expression { $$ = new CExpressionAND(); $$->AddChild($1); $$->AddChild($3); }
		   | expression OR expression { $$ = new CExpressionOR(); $$->AddChild($1); $$->AddChild($3); }
		   | NOT expression { $$ = new CExpressionNOT(); $$->AddChild($2); }
		   | expression GT expression { $$ = new CExpressionGT(); $$->AddChild($1); $$->AddChild($3); }
		   | expression GTE expression { $$ = new CExpressionGTE(); $$->AddChild($1); $$->AddChild($3); }
		   | expression LT expression { $$ = new CExpressionLT(); $$->AddChild($1); $$->AddChild($3); }
		   | expression LTE expression { $$ = new CExpressionLTE(); $$->AddChild($1); $$->AddChild($3); }
		   | expression EQUAL expression { $$ = new CExpressionEQUAL(); $$->AddChild($1); $$->AddChild($3); }
		   | expression NEQUAL expression { $$ = new CExpressionNEQUAL(); $$->AddChild($1); $$->AddChild($3); }
		   | PLUS expression { $$ = new CExpressionUnaryPlus(); $$->AddChild($2); }
		   | MINUS expression { $$ = new CExpressionUnaryMinus(); $$->AddChild($2); }
		   ;

args : expression { $$ = new CActualArgs(); $$->AddChild($1); }
     | args ',' expression { $$ = new CActualArgs(); $$->AddChild($1); $$->AddChild($3); }
     ;

%%

namespace yy{
	void parser::error (const location_type& loc, const std::string& msg){
		std::cerr << "error at " << loc << ": " << msg << std::endl;
	}
}