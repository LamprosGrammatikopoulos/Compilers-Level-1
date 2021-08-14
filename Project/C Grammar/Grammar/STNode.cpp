#include "STNode.h"
STNode* g_root = nullptr;
int STNode::m_serialCounter = 0;
bool STNode::m_breakVisit = false;
int STNode::m_returnedValue = 0;
const char* g_nodeTypeLabels[] = {
	"COMPILEUNIT", "FUNCTIONDEFINITION", "FORMALARGS", "ACTUALARGS",
	"STATEMENTLIST", "STATEMENT", "EXPRESSIONSTATEMENT", "EXPRESSION",
	"COMPOUNDSTATEMENT", "IFSTATEMENT", "WHILESTATEMENT", "DOWHILESTATEMENT",
	"FORSTATEMENT", "RETURNSTATEMENT", "BREAKSTATEMENT", "NULLSTATEMENT",
	"SWITCHSTATEMENT", "LABELEDSTATEMENT",
	"NUMBER", "IDENTIFIER",
	"UNARYPLUS", "UNARYMINUS",
	"OR","AND",
	"ADDITION", "SUBTRACTION",
	"MULTIPLICATION", "DIVISION",
	"NOT", "GT", "GTE", "LT",
	"LTE", "EQUAL", "NEQUAL",
	"ASSIGNMENT",
	"EXPRESSION_FCALL"
};

STNode::STNode(NodeType type) {
	m_nodeType = type;
	m_serial = m_serialCounter++;
	m_children = new list<STNode*>;
	m_parents = new list<STNode*>;
	m_graphvizLabel = _strdup(g_nodeTypeLabels[m_nodeType]);
	m_graphvizLabel.append("_" + std::to_string(m_serial));
}

////apodesmefsh twn komvwn apo ta fula pros thn riza me DFS 
STNode::~STNode() {
	list<STNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); it++) {
		delete* it;
	}
	delete m_children;
	delete m_parents;
}

void STNode::AddChild(STNode* node) {
	m_children->push_back(node);
	node->m_parents->push_back(this);
}

STNode* STNode::GetChild(int index) {
	list<STNode*>::iterator it = m_children->begin();
	advance(it, index);
	return *it;
}

STNode* STNode::GetParent(int index) {
	list<STNode*>::iterator it = m_parents->begin();
	advance(it, index);
	return *it;
}

void STNode::Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent) {
	list<STNode*>::iterator it;

	(*dotFile) << "\"" << parent->GetGraphvizLabel() << "\"->\"" << GetGraphvizLabel() << "\";\n";

	for (it = m_children->begin(); it != m_children->end(); it++) {
		(*it)->Visit_SyntaxTreePrinter(dotFile, this);
	}
}

//Default version
//den paragei arithmitiko apotelesma giati den anaferetai se komvous pou paragoun arithmhtiko apotelesma
int STNode::Visit_Eval() {
	list<STNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); it++) {
		(*it)->Visit_Eval();
	}
	return 0;
}

NodeType STNode::GetNodeType() {
	return m_nodeType;
}

string STNode::GetGraphvizLabel() {
	return m_graphvizLabel;
}