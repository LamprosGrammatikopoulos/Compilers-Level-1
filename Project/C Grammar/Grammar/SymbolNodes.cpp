#pragma once
#include "SymbolNodes.h"
#include "SymbolTable.h"
#include <iostream>

using namespace std;

void GetActualArguments(STNode* currentNode, list<CExpression*>* args);
void GetFormalArguments(STNode* currentNode, list<CIDENTIFIER*>* args);

int switch_child1 = 0;

CCompileUnit::CCompileUnit() : STNode(NodeType::NT_COMPILEUNIT) {} ////ston constractor tou CCompileUint kaloume ton contractor ths gonikhs klashs
CCompileUnit::~CCompileUnit() {}

CFunctionDefinition::CFunctionDefinition() : STNode(NodeType::NT_FUNCTIONDEFINITION) {}
CFunctionDefinition::~CFunctionDefinition() {}

CFormalArgs::CFormalArgs() : STNode(NodeType::NT_FORMALARGS) {}
CFormalArgs::~CFormalArgs() {}

CActualArgs::CActualArgs() : STNode(NodeType::NT_ACTUALARGS) {}
CActualArgs::~CActualArgs() {}

CStatement_list::CStatement_list() : STNode(NodeType::NT_STATEMENTLIST) {}
CStatement_list::~CStatement_list() {}

CStatement::CStatement(NodeType nodeType) : STNode(nodeType) {} // to nodetype einai p.x. to NT_EXPRESSIONSTATEMENT
CStatement::~CStatement() {}

CExpressionStatement::CExpressionStatement() : CStatement(NodeType::NT_EXPRESSIONSTATEMENT) {}
CExpressionStatement::~CExpressionStatement() {}

CExpression::CExpression(NodeType nodeType) : STNode(nodeType) {} // to nodetype einai p.x. to NT_EXPRESSION_ADDITION
CExpression::~CExpression() {}

CAddition::CAddition() : CExpression(NodeType::NT_EXPRESSION_ADDITION) {}
CAddition::~CAddition() {}

CSubtraction::CSubtraction() : CExpression(NodeType::NT_EXPRESSION_SUBTRACTION) {}
CSubtraction::~CSubtraction() {}

CMultiplication::CMultiplication() : CExpression(NodeType::NT_EXPRESSION_MULTIPLICATION) {}
CMultiplication::~CMultiplication() {}

CDivision::CDivision() : CExpression(NodeType::NT_EXPRESSION_DIVISION) {}
CDivision::~CDivision() {}

CCompoundStatement::CCompoundStatement() : CStatement(NodeType::NT_COMPOUNDSTATEMENT) {}
CCompoundStatement::~CCompoundStatement() {}

CSwitchStatement::CSwitchStatement() : CStatement(NodeType::NT_SWITCHSTATEMENT) {}
CSwitchStatement::~CSwitchStatement() {}

CLabeledStatement::CLabeledStatement() : STNode(NodeType::NT_LABELEDSTATEMENT) {}
CLabeledStatement::~CLabeledStatement() {}

CIfStatement::CIfStatement() : CStatement(NodeType::NT_IFSTATEMENT) {}
CIfStatement::~CIfStatement() {}

CWhileStatement::CWhileStatement() : CStatement(NodeType::NT_WHILESTATEMENT) {}
CWhileStatement::~CWhileStatement() {}

CDoWhileStatement::CDoWhileStatement() : CStatement(NodeType::NT_DOWHILESTATEMENT) {}
CDoWhileStatement::~CDoWhileStatement() {}

CForStatement::CForStatement() : CStatement(NodeType::NT_FORSTATEMENT) {}
CForStatement::~CForStatement() {}

CReturnStatement::CReturnStatement() : CStatement(NodeType::NT_RETURNSTATEMENT) {}
CReturnStatement::~CReturnStatement() {}

CBreakStatement::CBreakStatement() : CStatement(NodeType::NT_BREAKSTATEMENT) {}
CBreakStatement::~CBreakStatement() {}

CNullStatement::CNullStatement() : CStatement(NodeType::NT_NULLSTATEMENT) {}
CNullStatement::~CNullStatement() {}

CExpressionNOT::CExpressionNOT() : CExpression(NodeType::NT_EXPRESSION_NOT) {}
CExpressionNOT::~CExpressionNOT() {}

CExpressionGT::CExpressionGT() : CExpression(NodeType::NT_EXPRESSION_GT) {}
CExpressionGT::~CExpressionGT() {}

CExpressionGTE::CExpressionGTE() : CExpression(NodeType::NT_EXPRESSION_GTE) {}
CExpressionGTE::~CExpressionGTE() {}

CExpressionLT::CExpressionLT() : CExpression(NodeType::NT_EXPRESSION_LT) {}
CExpressionLT::~CExpressionLT() {}

CExpressionLTE::CExpressionLTE() : CExpression(NodeType::NT_EXPRESSION_LTE) {}
CExpressionLTE::~CExpressionLTE() {}

CExpressionEQUAL::CExpressionEQUAL() : CExpression(NodeType::NT_EXPRESSION_EQUAL) {}
CExpressionEQUAL::~CExpressionEQUAL() {}

CExpressionNEQUAL::CExpressionNEQUAL() : CExpression(NodeType::NT_EXPRESSION_NEQUAL) {}
CExpressionNEQUAL::~CExpressionNEQUAL() {}

CExpressionAND::CExpressionAND() : CExpression(NodeType::NT_EXPRESSION_OR) {}
CExpressionAND::~CExpressionAND() {}

CExpressionOR::CExpressionOR() : CExpression(NodeType::NT_EXPRESSION_OR) {}
CExpressionOR::~CExpressionOR() {}

CExpressionUnaryPlus::CExpressionUnaryPlus() : CExpression(NodeType::NT_EXPRESSION_UNARYPLUS) {}
CExpressionUnaryPlus::~CExpressionUnaryPlus() {}

CExpressionUnaryMinus::CExpressionUnaryMinus() : CExpression(NodeType::NT_EXPRESSION_UNARYMINUS) {}
CExpressionUnaryMinus::~CExpressionUnaryMinus() {}

CExpressionFCALL::CExpressionFCALL() : CExpression(NodeType::NT_EXPRESSION_FCALL) {}
CExpressionFCALL::~CExpressionFCALL() {}

CNUMBER::CNUMBER(char* text) : CExpression(NodeType::NT_EXPRESSION_NUMBER) {
	m_number = atoi(text);
	m_graphvizLabel.append("_" + std::to_string(m_number));
}
CNUMBER::~CNUMBER() {}

CIDENTIFIER::CIDENTIFIER(char* text) : CExpression(NodeType::NT_EXPRESSION_IDENTIFIER) {
	m_name = (string)text;
	m_number = 0;
	m_graphvizLabel.append("_" + m_name);
}
CIDENTIFIER::~CIDENTIFIER() {}

CAssignment::CAssignment() : CExpression(NodeType::NT_EXPRESSION_ASSIGNMENT) {}
CAssignment::~CAssignment() {}


void CCompileUnit::Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent) {
	list<STNode*>::iterator it;

	if (parent == nullptr) {
		(*dotFile) << "digraph G{ \n";
		for (it = m_children->begin(); it != m_children->end(); it++) {
			(*it)->Visit_SyntaxTreePrinter(dotFile, this);
		}
		(*dotFile) << "}";
		dotFile->close();
	}
	else {
		STNode::Visit_SyntaxTreePrinter(dotFile, parent);
	}
}
/*int CStatement::Visit_Eval() {
	list<STNode*>::iterator it;
	if (m_children->size() != 0) {
		it = m_children->begin();
		cout << "Result : " << (*it)->Visit_Eval() << endl;
	}
	return 0;
}*/
int CFunctionDefinition::Visit_Eval() {
	return 0;
}
int CNUMBER::Visit_Eval() {
	return m_number;
}
int CIDENTIFIER::Visit_Eval() {
	return m_number;
}
int CAssignment::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin(); //a=5 a
	CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it); // (CIDENTIFIER)a gia an mporoume na prospelasoume ta pedia ths klashs
	advance(it, 1);
	id->m_number = (*it)->Visit_Eval();
	cout << id->m_name << "=" << id->m_number << endl;
	return id->m_number;
}
int CAddition::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result += (*it)->Visit_Eval();
	return result; //h anathesh apotelei ekfrash kai oi ekfraseis prepei na epistrefoun timh, epistrefoume to apotelesma ths prakshs ston gonea komvo
}
int CSubtraction::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result -= (*it)->Visit_Eval();
	return result;
}
int CMultiplication::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result *= (*it)->Visit_Eval();
	return result;
}
int CDivision::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	if ((*it)->Visit_Eval() == 0)
	{
		cout << "Division by zero" << endl;
		exit(1);
	}
	else
	{
		result /= (*it)->Visit_Eval();
	}
	return result;
}
int CSwitchStatement::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	switch_child1 = (*it)->Visit_Eval();
	return 0;
}
int CLabeledStatement::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	cout << m_children->size() << endl;
	switch (m_children->size()) {
		case 2:
		{
			if ((*it)->Visit_Eval() == switch_child1) {
				advance(it, 1);
				(*it)->Visit_Eval();
				if (m_breakVisit) {
					m_breakVisit = false;
				}
			}
		}
		case 1:
		{
			(*it)->Visit_Eval();
			if (m_breakVisit) {
				m_breakVisit = false;
			}
		}
		default:;
	}
	return 0;
}
int CIfStatement::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	switch (m_children->size()) {
		case 2:
		{
			if ((*it)->Visit_Eval()) {
				advance(it, 1);
				(*it)->Visit_Eval();
			}
			break;
		}
		case 3:
		{
			if ((*it)->Visit_Eval()) {
				advance(it, 1);
				(*it)->Visit_Eval();
			}
			else {
				advance(it, 2);
				(*it)->Visit_Eval();
			}
			break;
		}
		default:;
	}
	return 0;
}
int CWhileStatement::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	while ((*it)->Visit_Eval()) {
		advance(it, 1);
		(*it)->Visit_Eval();
		if (m_breakVisit) {
			m_breakVisit = false;
			break;
		}
		advance(it, -1);
	}
	return 0;
}
int CDoWhileStatement::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	advance(it, 1);
	while ((*it)->Visit_Eval()) {
		advance(it, -1);
		(*it)->Visit_Eval();
		if (m_breakVisit) {
			m_breakVisit = false;
			break;
		}
		advance(it, 1);
	}
	return 0;
}
int CForStatement::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	while ((*it)->Visit_Eval())
	{
		advance(it, 2);         //Paw sta statements
		(*it)->Visit_Eval();   //Kanw ta statements otidhpote uparxei mesa stin for
		if (m_breakVisit)
		{
			m_breakVisit = false;
			break;
		}
		advance(it, -1);            //Paw sto increment
		(*it)->Visit_Eval();
		advance(it, -1);
	}
	return 0;
}
int CReturnStatement::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	//1.Mark the end of function
	m_breakVisit = true;
	m_returnedValue = (*it)->Visit_Eval();
	return m_returnedValue;
}
int CBreakStatement::Visit_Eval() {
	m_breakVisit = true;
	return  0;
}
int CExpressionNOT::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	return !result;
}
int CExpressionGT::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = (result > (*it)->Visit_Eval() ? 1 : 0);
	return result;
}
int CExpressionGTE::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = (result >= (*it)->Visit_Eval() ? 1 : 0);
	return result;
}
int CExpressionLT::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = (result < (*it)->Visit_Eval() ? 1 : 0);
	return result;
}
int CExpressionLTE::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = (result <= (*it)->Visit_Eval() ? 1 : 0);
	return result;
}
int CExpressionEQUAL::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = (result == (*it)->Visit_Eval() ? 1 : 0);
	return result;
}
int CExpressionNEQUAL::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = (result != (*it)->Visit_Eval() ? 1 : 0);
	return result;
}
int CExpressionAND::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = (result && (*it)->Visit_Eval());
	return result;
}
int CExpressionOR::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = (result || (*it)->Visit_Eval());
	return result;
}
int CExpressionUnaryPlus::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	return +result;
}
int CExpressionUnaryMinus::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	return -result;
}
int CExpressionFCALL::Visit_Eval() {
	int result = 0;
	CIDENTIFIER* id = (CIDENTIFIER*)GetChild(0);
	CFunctionDefinition* fundef;

	// Calling functions that are created inside the program.
	fundef = (CFunctionDefinition*)g_symbolTable.GetIdentifier(id->m_name);
	MapActualToFormalArguments();
	fundef->GetChild(2)->Visit_Eval();
	result = m_returnedValue;
	m_breakVisit = false;

	return result;
}
void CExpressionFCALL::MapActualToFormalArguments() { //metatrepw ta actual arguments se formal arguments
	CIDENTIFIER* id = (CIDENTIFIER*)GetChild(0);
	CActualArgs* aArgs = (CActualArgs*)GetChild(1);
	CFunctionDefinition* fundef = (CFunctionDefinition*)g_symbolTable.GetIdentifier(id->m_name);
	CFormalArgs* fArgs = (CFormalArgs*)fundef->GetChild(1);
	list<CExpression*>::iterator ite;
	list<CIDENTIFIER*>::iterator it;
	m_actualArguments = new list<CExpression*>();
	m_formalArguments = new list<CIDENTIFIER*>();
	GetActualArguments(aArgs, m_actualArguments);
	GetFormalArguments(fArgs, m_formalArguments);
	for (it = m_formalArguments->begin(), ite = m_actualArguments->begin(); it != m_formalArguments->end(); it++, ite++) {
		((CIDENTIFIER*)(g_symbolTable.GetIdentifier((*it)->m_name)))->m_number = (*ite)->Visit_Eval();
	}
}
void GetActualArguments(STNode* currentNode, list<CExpression*>* args) { //pairnw ta actual args ths klhshs ths sunarthshs 
	list<STNode*>::iterator it;
	if (dynamic_cast<CExpression*>(currentNode) != nullptr) {
		args->push_back((CExpression*)currentNode);
	}

	for (it = currentNode->m_children->begin(); it != currentNode->m_children->end(); it++) {
		GetActualArguments((*it), args);
	}
}
void GetFormalArguments(STNode* currentNode, list<CIDENTIFIER*>* args) { //pairnw ta formal args ths dhlwshs/dhmiourgias ths sunarthshs
	list<STNode*>::iterator it;
	if (dynamic_cast<CIDENTIFIER*>(currentNode) != nullptr) {
		args->push_back((CIDENTIFIER*)currentNode);
	}

	for (it = currentNode->m_children->begin(); it != currentNode->m_children->end(); it++) {
		GetFormalArguments((*it), args);
	}
}