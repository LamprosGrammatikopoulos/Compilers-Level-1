#pragma once
#include "STNode.h"

class CCompileUnit : public STNode {
public:
	CCompileUnit();
	virtual ~CCompileUnit();
	void Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent) override;
};
class CFunctionDefinition : public STNode {
public:
	CFunctionDefinition();
	virtual ~CFunctionDefinition();

	int Visit_Eval() override;
};

class CFormalArgs : public STNode {
public:
	CFormalArgs();
	virtual ~CFormalArgs();
};

class CActualArgs : public STNode {
public:
	CActualArgs();
	virtual ~CActualArgs();
};

class CStatement_list : public STNode {
public:
	CStatement_list();
	virtual ~CStatement_list();
};

class CStatement : public STNode {
public:
	CStatement(NodeType nodeType);
	virtual ~CStatement();
};

class CExpressionStatement : public CStatement {
public:
	CExpressionStatement();
	virtual ~CExpressionStatement();
};

class CExpression : public STNode {
public:
	CExpression(NodeType nodeType);
	virtual ~CExpression();
};

class CAddition : public CExpression {
public:
	CAddition();
	virtual ~CAddition();
	int Visit_Eval() override;
};

class CSubtraction : public CExpression {
public:
	CSubtraction();
	virtual ~CSubtraction();
	int Visit_Eval() override;
};

class CMultiplication : public CExpression {
public:
	CMultiplication();
	virtual ~CMultiplication();
	int Visit_Eval() override;
};

class CDivision : public CExpression {
public:
	CDivision();
	virtual ~CDivision();
	int Visit_Eval() override;
};

class CNUMBER : public CExpression {
public:
	int m_number;

	CNUMBER(char* text);
	virtual ~CNUMBER();
	int Visit_Eval() override;
};

//-------------------------------------------------
class CIDENTIFIER : public CExpression {
public:
	int m_number;
	string m_name;

	CIDENTIFIER(char* text);
	virtual ~CIDENTIFIER();
	int Visit_Eval() override;
};

class CAssignment : public CExpression {
public:
	CAssignment();
	virtual ~CAssignment();
	int Visit_Eval() override;
};
//------------------------------------------------------

class CExpressionFCALL : public CExpression {
public:
	list<CExpression*>* m_actualArguments = nullptr;
	list<CIDENTIFIER*>* m_formalArguments = nullptr;
	CExpressionFCALL();
	virtual ~CExpressionFCALL();

	int Visit_Eval() override;
	void MapActualToFormalArguments();
};

class CCompoundStatement : public CStatement {
public:
	CCompoundStatement();
	virtual ~CCompoundStatement();
};

class CSwitchStatement : public CStatement {
public:
	CSwitchStatement();
	virtual ~CSwitchStatement();
	int Visit_Eval() override;
};

class CLabeledStatement : public STNode {
public:
	CLabeledStatement();
	virtual ~CLabeledStatement();
	int Visit_Eval() override;
};

class CIfStatement : public CStatement {
public:
	CIfStatement();
	virtual ~CIfStatement();
	int Visit_Eval() override;
};

class CWhileStatement : public CStatement {
public:
	CWhileStatement();
	virtual ~CWhileStatement();
	int Visit_Eval() override;
};

class CDoWhileStatement : public CStatement {
public:
	CDoWhileStatement();
	virtual ~CDoWhileStatement();
	int Visit_Eval() override;
};

class CForStatement : public CStatement {
public:
	CForStatement();
	virtual ~CForStatement();
	int Visit_Eval() override;
};

class CReturnStatement : public CStatement {
public:
	CReturnStatement();
	virtual ~CReturnStatement();
	int Visit_Eval() override;
};

class CBreakStatement : public CStatement {
public:
	CBreakStatement();
	virtual ~CBreakStatement();
	int Visit_Eval() override;
};

class CNullStatement : public CStatement {
public:
	CNullStatement();
	virtual ~CNullStatement();
};

class CExpressionNOT : public CExpression {
public:
	CExpressionNOT();
	virtual ~CExpressionNOT();
	int Visit_Eval() override;
};

class CExpressionGT : public CExpression {
public:
	CExpressionGT();
	virtual ~CExpressionGT();
	int Visit_Eval() override;
};

class CExpressionGTE : public CExpression {
public:
	CExpressionGTE();
	virtual ~CExpressionGTE();
	int Visit_Eval() override;
};

class CExpressionLT : public CExpression {
public:
	CExpressionLT();
	virtual ~CExpressionLT();
	int Visit_Eval() override;
};

class CExpressionLTE : public CExpression {
public:
	CExpressionLTE();
	virtual ~CExpressionLTE();
	int Visit_Eval() override;
};

class CExpressionEQUAL : public CExpression {
public:
	CExpressionEQUAL();
	virtual ~CExpressionEQUAL();
	int Visit_Eval() override;
};

class CExpressionNEQUAL : public CExpression {
public:
	CExpressionNEQUAL();
	virtual ~CExpressionNEQUAL();
	int Visit_Eval() override;
};

class CExpressionAND : public CExpression {
public:
	CExpressionAND();
	virtual ~CExpressionAND();
	int Visit_Eval() override;
};

class CExpressionOR : public CExpression {
public:
	CExpressionOR();
	virtual ~CExpressionOR();
	int Visit_Eval() override;
};

class CExpressionUnaryPlus : public CExpression {
public:
	CExpressionUnaryPlus();
	virtual ~CExpressionUnaryPlus();
	int Visit_Eval() override;
};

class CExpressionUnaryMinus : public CExpression {
public:
	CExpressionUnaryMinus();
	virtual ~CExpressionUnaryMinus();
	int Visit_Eval() override;
};