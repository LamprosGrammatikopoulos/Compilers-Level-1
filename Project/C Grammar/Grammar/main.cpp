#include <iostream>
#include <stdlib.h>
#include "Grammar.tab.h"
#include "STNode.h"

extern FILE* yyin;
using namespace std;

int main(int argc, char* argv[])
{
	fopen_s(&yyin, "test.txt", "r");
	yy::parser* p = new yy::parser();
	p->parse();

	ofstream* f = new ofstream("stree.dot", ofstream::out); ////dhmiourgia arxeiou eksodou
	g_root->Visit_SyntaxTreePrinter(f, nullptr); ////ksekiname apo thn riza me orismata: to arxeio eksodou kai ton gonea ths rizas pou einai null
	system("dot -Tgif stree.dot -o stree.dot.gif");

	g_root->Visit_Eval(); ////sarwsh tou suntaktikou dentrou

	return 0;
}