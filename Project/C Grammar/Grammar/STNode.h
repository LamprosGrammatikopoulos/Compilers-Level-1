#pragma once
#include<list>
#include <string>
#include <fstream>

using namespace std;

typedef enum nodeType {
	NT_COMPILEUNIT, NT_FUNCTIONDEFINITION, NT_FORMALARGS, NT_ACTUALARGS,
	NT_STATEMENTLIST, NT_STATEMENT, NT_EXPRESSIONSTATEMENT, NT_EXPRESSION,
	NT_COMPOUNDSTATEMENT, NT_IFSTATEMENT, NT_WHILESTATEMENT, NT_DOWHILESTATEMENT,
	NT_FORSTATEMENT, NT_RETURNSTATEMENT, NT_BREAKSTATEMENT, NT_NULLSTATEMENT,
	NT_SWITCHSTATEMENT, NT_LABELEDSTATEMENT,
	NT_EXPRESSION_NUMBER, NT_EXPRESSION_IDENTIFIER,
	NT_EXPRESSION_UNARYPLUS, NT_EXPRESSION_UNARYMINUS,
	NT_EXPRESSION_OR, NT_EXPRESSION_AND,
	NT_EXPRESSION_ADDITION, NT_EXPRESSION_SUBTRACTION,
	NT_EXPRESSION_MULTIPLICATION, NT_EXPRESSION_DIVISION,
	NT_EXPRESSION_NOT, NT_EXPRESSION_GT, NT_EXPRESSION_GTE, NT_EXPRESSION_LT,
	NT_EXPRESSION_LTE, NT_EXPRESSION_EQUAL, NT_EXPRESSION_NEQUAL,
	NT_EXPRESSION_ASSIGNMENT,
	NT_EXPRESSION_FCALL
} NodeType;

class CExpression;
class CIDENTIFIER;
class STNode {
public:

	STNode(NodeType type);
	virtual ~STNode();

	NodeType GetNodeType();
	string GetGraphvizLabel();
	STNode* GetChild(int index);
	STNode* GetParent(int index = 0);

	void AddChild(STNode* node);

	virtual void Visit_SyntaxTreePrinter(ofstream* dotfile, STNode* parent);
	virtual int Visit_Eval();

	friend void GetActualArguments(STNode* currentNode, list<CExpression*>* args);
	friend void GetFormalArguments(STNode* currentNode, list<CIDENTIFIER*>* args);

protected:
	static bool m_breakVisit;
	static int m_returnedValue;
	//Type of node
	NodeType m_nodeType;
	//label of node in the graphviz generated files
	string m_graphvizLabel;
	//serial number of the node
	int m_serial;
	//serial counter 
	static int m_serialCounter;
	//children nodes list
	list<STNode*>* m_children;
	//parent nodes list
	list<STNode*>* m_parents;
};

extern STNode* g_root;