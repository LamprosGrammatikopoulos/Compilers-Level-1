#include "SymbolTable.h"

SymbolTable g_symbolTable;

STNode* SymbolTable::GetIdentifier(char* name) {
	map<string, STNode*>::iterator it;
	STNode* node = 0;

	it = m_symbolTable.find(name); //an den uparxei o komvos, it = telos ths domhs
	if (it != m_symbolTable.end()) { //an o iterator exei egkurh timh
		node = m_symbolTable[name];
	}
	else {
		node = new CIDENTIFIER(name);
		m_symbolTable[name] = node;
	}
	return node;
}

STNode* SymbolTable::GetIdentifier(string name) {
	return GetIdentifier((char*)name.c_str());
}

void SymbolTable::SetValue(string name, STNode* value) {
	map<string, STNode*>::iterator it;

	it = m_symbolTable.find(name);
	if (it != m_symbolTable.end()) {
		m_symbolTable[name] = value;
	}
}