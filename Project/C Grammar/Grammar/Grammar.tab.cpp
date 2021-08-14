/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */
/* Line 279 of lalr1.cc  */
#line 4 "Grammar.y"

#include "Grammar.tab.h"
#include "SymbolNodes.h"
#include "SymbolTable.h"
extern int yylex(yy::parser::semantic_type *yylval);

/* Line 279 of lalr1.cc  */
#line 45 "Grammar.tab.cpp"


#include "Grammar.tab.h"

/* User implementation prologue.  */

/* Line 285 of lalr1.cc  */
#line 53 "Grammar.tab.cpp"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
/* Line 353 of lalr1.cc  */
#line 148 "Grammar.tab.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {
  }

  parser::~parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 670 of lalr1.cc  */
#line 33 "Grammar.y"
    {  g_root = (yyval.node) = new CCompileUnit(); (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 34 "Grammar.y"
    { (yyval.node) = g_root = new CCompileUnit(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 35 "Grammar.y"
    { (yyval.node) = g_root = new CCompileUnit(); (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 36 "Grammar.y"
    { (yyval.node) = g_root = new CCompileUnit(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 39 "Grammar.y"
    { (yyval.node) = new CFunctionDefinition(); (yyval.node)->AddChild((yysemantic_stack_[(6) - (2)].node)); (yyval.node)->AddChild((yysemantic_stack_[(6) - (4)].node)); (yyval.node)->AddChild((yysemantic_stack_[(6) - (6)].node)); g_symbolTable.SetValue(((CIDENTIFIER *)(yysemantic_stack_[(6) - (2)].node))->m_name, (yyval.node)); }
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 40 "Grammar.y"
    { (yyval.node) = new CFunctionDefinition(); (yyval.node)->AddChild((yysemantic_stack_[(5) - (2)].node)); (yyval.node)->AddChild((yysemantic_stack_[(5) - (5)].node)); g_symbolTable.SetValue(((CIDENTIFIER *)(yysemantic_stack_[(5) - (2)].node))->m_name, (yyval.node)); }
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 43 "Grammar.y"
    { (yyval.node) = new CFormalArgs(); (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 44 "Grammar.y"
    { (yyval.node) = new CFormalArgs(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 47 "Grammar.y"
    { (yyval.node) = new CStatement_list(); (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 48 "Grammar.y"
    { (yyval.node) = new CStatement_list(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 51 "Grammar.y"
    { (yyval.node) = new CExpressionStatement(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node)); }
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 59 "Grammar.y"
    { (yyval.node) = new CReturnStatement(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (2)].node)); }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 60 "Grammar.y"
    { (yyval.node) = new CBreakStatement(); }
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 61 "Grammar.y"
    { (yyval.node) = new CNullStatement(); }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 64 "Grammar.y"
    { (yyval.node) = new CSwitchStatement(); (yyval.node)->AddChild((yysemantic_stack_[(5) - (3)].node)); (yyval.node)->AddChild((yysemantic_stack_[(5) - (5)].node)); printf("switch\n"); }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 67 "Grammar.y"
    { (yyval.node) = new CLabeledStatement(); (yyval.node)->AddChild((yysemantic_stack_[(4) - (2)].node)); (yyval.node)->AddChild((yysemantic_stack_[(4) - (4)].node)); printf("labeled\n"); }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 68 "Grammar.y"
    { (yyval.node) = new CLabeledStatement(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 71 "Grammar.y"
    { (yyval.node) = new CIfStatement(); (yyval.node)->AddChild((yysemantic_stack_[(5) - (3)].node)); (yyval.node)->AddChild((yysemantic_stack_[(5) - (5)].node)); }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 72 "Grammar.y"
    { (yyval.node) = new CIfStatement(); (yyval.node)->AddChild((yysemantic_stack_[(7) - (3)].node)); (yyval.node)->AddChild((yysemantic_stack_[(7) - (5)].node)); (yyval.node)->AddChild((yysemantic_stack_[(7) - (7)].node)); }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 75 "Grammar.y"
    { (yyval.node) = new CWhileStatement(); (yyval.node)->AddChild((yysemantic_stack_[(5) - (3)].node)); (yyval.node)->AddChild((yysemantic_stack_[(5) - (5)].node)); }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 78 "Grammar.y"
    { (yyval.node) = new CDoWhileStatement(); (yyval.node)->AddChild((yysemantic_stack_[(6) - (2)].node)); (yyval.node)->AddChild((yysemantic_stack_[(6) - (5)].node)); }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 81 "Grammar.y"
    { (yyval.node) = new CForStatement(); (yyval.node)->AddChild((yysemantic_stack_[(9) - (3)].node)); (yyval.node)->AddChild((yysemantic_stack_[(9) - (5)].node)); (yyval.node)->AddChild((yysemantic_stack_[(9) - (7)].node)); (yyval.node)->AddChild((yysemantic_stack_[(9) - (9)].node)); }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 84 "Grammar.y"
    { (yyval.node) = new CCompoundStatement(); }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 85 "Grammar.y"
    { (yyval.node) = new CCompoundStatement(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (2)].node)); }
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 88 "Grammar.y"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 90 "Grammar.y"
    {(yyval.node) = new CAssignment(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 91 "Grammar.y"
    { (yyval.node) = new CExpressionFCALL(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); }
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 92 "Grammar.y"
    { (yyval.node) = new CExpressionFCALL(); (yyval.node)->AddChild((yysemantic_stack_[(4) - (1)].node)->GetChild(0)); (yyval.node)->AddChild((yysemantic_stack_[(4) - (3)].node)); }
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 93 "Grammar.y"
    { (yyval.node) = new CAddition(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 94 "Grammar.y"
    { (yyval.node) = new CSubtraction(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 95 "Grammar.y"
    { (yyval.node) = new CMultiplication(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 96 "Grammar.y"
    { (yyval.node) = new CDivision(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 97 "Grammar.y"
    { (yyval.node) = (yysemantic_stack_[(3) - (2)].node); }
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 98 "Grammar.y"
    { (yyval.node) = new CExpressionAND(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 99 "Grammar.y"
    { (yyval.node) = new CExpressionOR(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 100 "Grammar.y"
    { (yyval.node) = new CExpressionNOT(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 101 "Grammar.y"
    { (yyval.node) = new CExpressionGT(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 102 "Grammar.y"
    { (yyval.node) = new CExpressionGTE(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 103 "Grammar.y"
    { (yyval.node) = new CExpressionLT(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 104 "Grammar.y"
    { (yyval.node) = new CExpressionLTE(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 105 "Grammar.y"
    { (yyval.node) = new CExpressionEQUAL(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 51:
/* Line 670 of lalr1.cc  */
#line 106 "Grammar.y"
    { (yyval.node) = new CExpressionNEQUAL(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 107 "Grammar.y"
    { (yyval.node) = new CExpressionUnaryPlus(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 108 "Grammar.y"
    { (yyval.node) = new CExpressionUnaryMinus(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 111 "Grammar.y"
    { (yyval.node) = new CActualArgs(); (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 112 "Grammar.y"
    { (yyval.node) = new CActualArgs(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;


/* Line 670 of lalr1.cc  */
#line 695 "Grammar.tab.cpp"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
          }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char parser::yypact_ninf_ = -63;
  const short int
  parser::yypact_[] =
  {
       140,   -63,    -3,   165,   -28,   -21,    13,   174,    14,    20,
      18,   165,    31,   165,   165,   165,   165,   -63,    16,    67,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   211,
     165,   130,   228,   -63,   165,   165,    42,   165,    37,   165,
     193,   174,   -27,   -27,   -63,   279,   -63,   105,   -63,   -63,
     -63,   -63,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   -63,   369,   -63,   369,   -29,   -63,
     294,   309,    44,   245,     3,   324,   174,   -63,   -63,   -63,
     -63,   380,   101,   390,   390,   390,   390,   390,   390,   -27,
     -27,   -63,   -63,   -63,   165,   174,   174,   165,   165,   -63,
      47,   -24,   174,   -63,   369,    76,   -63,   339,   262,   -63,
      47,    81,   -63,   174,   -63,   165,   -63,   -63,   -63,   354,
     174,   -63
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,     0,     0,
       4,     2,    14,    15,    16,    17,    18,    19,    13,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    52,    45,     0,    31,     0,    10,     1,
       5,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    35,    36,    54,     0,    20,
       0,     0,     0,     0,     0,     0,     0,    25,    42,    32,
      11,    44,    43,    51,    50,    48,    49,    46,    47,    39,
      38,    41,    40,    37,     0,     0,     0,     0,     0,     8,
       0,     0,     0,    24,    55,    26,    28,     0,     0,     7,
       0,     0,    23,     0,    29,     0,     6,     9,    27,     0,
       0,    30
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  parser::yypgoto_[] =
  {
       -63,   -63,    68,   -63,   -63,    -7,   -63,   -63,   -63,   -63,
     -63,   -63,   -62,     2,   -63
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  parser::yydefgoto_[] =
  {
        -1,    19,    20,   101,    47,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    68
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -1;
  const signed char
  parser::yytable_[] =
  {
        36,    62,    63,    93,    94,    32,    33,    99,   110,   111,
      34,    48,    51,    40,    30,    42,    43,    44,    45,     1,
       2,     3,     4,     5,    38,     6,     7,     8,    31,    10,
      11,    12,    65,    67,    77,   100,    70,    71,   109,    73,
      80,    75,    13,    14,    35,    37,    15,    16,   116,    39,
      17,    72,    18,    46,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    41,    49,    74,   103,
       1,     2,     3,     4,     5,    97,     6,     7,     8,     9,
      10,    11,    12,    18,   113,   117,     0,    50,   105,   106,
       0,     0,     0,    13,    14,   112,   104,    15,    16,   107,
     108,    17,     0,    18,     0,     0,   118,     0,     1,     2,
       3,     4,     5,   121,     6,     7,     8,   119,    10,    11,
      12,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    13,    14,     1,     2,    15,    16,     0,     0,    17,
       0,    18,    79,     1,     2,     3,     4,     5,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      15,    16,    66,     0,     0,     0,    13,    14,     1,     2,
      15,    16,     0,     0,    17,     0,    18,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     0,    10,    11,    12,
       0,    13,    14,     0,     0,    15,    16,     0,     0,     0,
      13,    14,     0,     0,    15,    16,     0,     0,    17,     0,
      18,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,     0,     0,     0,     0,    76,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,     0,     0,     0,    64,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,     0,
       0,     0,    69,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,     0,     0,     0,    98,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,     0,     0,     0,   115,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
       0,    78,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,     0,    95,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
       0,    96,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,     0,   102,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
       0,   114,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,     0,   120,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63
  };

  /* YYCHECK.  */
  const signed char
  parser::yycheck_[] =
  {
         7,    28,    29,    32,    33,     3,    34,     4,    32,    33,
      31,    18,    19,    11,    17,    13,    14,    15,    16,     3,
       4,     5,     6,     7,     4,     9,    10,    11,    31,    13,
      14,    15,    30,    31,    41,    32,    34,    35,   100,    37,
      47,    39,    26,    27,    31,    31,    30,    31,   110,    31,
      34,     9,    36,    37,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    35,     0,    31,    76,
       3,     4,     5,     6,     7,    31,     9,    10,    11,    12,
      13,    14,    15,    36,     8,     4,    -1,    19,    95,    96,
      -1,    -1,    -1,    26,    27,   102,    94,    30,    31,    97,
      98,    34,    -1,    36,    -1,    -1,   113,    -1,     3,     4,
       5,     6,     7,   120,     9,    10,    11,   115,    13,    14,
      15,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    26,    27,     3,     4,    30,    31,    -1,    -1,    34,
      -1,    36,    37,     3,     4,     5,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    26,    27,    -1,    -1,
      30,    31,    32,    -1,    -1,    -1,    26,    27,     3,     4,
      30,    31,    -1,    -1,    34,    -1,    36,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    -1,    13,    14,    15,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,
      36,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    35,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    34,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    34,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    15,    26,    27,    30,    31,    34,    36,    39,
      40,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      17,    31,    51,    34,    31,    31,    43,    31,     4,    31,
      51,    35,    51,    51,    51,    51,    37,    42,    43,     0,
      40,    43,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    34,    51,    32,    51,    52,    34,
      51,    51,     9,    51,    31,    51,    35,    43,    32,    37,
      43,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    32,    33,    32,    32,    31,    34,     4,
      32,    41,    32,    43,    51,    43,    43,    51,    51,    50,
      32,    33,    43,     8,    32,    34,    50,     4,    43,    51,
      32,    43
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    61,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,    40,    41,    44,    59,    58,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    38,    39,    39,    39,    39,    40,    40,    41,    41,
      42,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    44,    45,    45,    46,    46,    47,    48,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     6,     5,     1,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     5,     4,     3,     5,     7,     5,     6,
       9,     2,     3,     1,     1,     3,     3,     4,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     3
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "$end", "error", "$undefined", "NUMBER", "IDENTIFIER", "RETURN",
  "BREAK", "IF", "ELSE", "WHILE", "DO", "FOR", "FUNCTION", "SWITCH",
  "CASE", "DEFAULT", "IFPREC", "'='", "OR", "AND", "NEQUAL", "EQUAL", "LT",
  "LTE", "GT", "GTE", "MINUS", "PLUS", "DIV", "MULT", "NOT", "'('", "')'",
  "','", "';'", "':'", "'{'", "'}'", "$accept", "compileUnit",
  "function_definition", "fargs", "statement_list", "statement",
  "switch_statement", "labeled_statement", "if_statement",
  "while_statement", "dowhile_statement", "for_statement",
  "compound_statement", "expression", "args", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        39,     0,    -1,    43,    -1,    39,    43,    -1,    40,    -1,
      39,    40,    -1,    12,     4,    31,    41,    32,    50,    -1,
      12,     4,    31,    32,    50,    -1,     4,    -1,    41,    33,
       4,    -1,    43,    -1,    42,    43,    -1,    51,    34,    -1,
      50,    -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,
      48,    -1,    49,    -1,     5,    51,    34,    -1,     6,    34,
      -1,    34,    -1,    13,    31,    51,    32,    43,    -1,    14,
      51,    35,    43,    -1,    15,    35,    43,    -1,     7,    31,
      51,    32,    43,    -1,     7,    31,    51,    32,    43,     8,
      43,    -1,     9,    31,    51,    32,    43,    -1,    10,    43,
       9,    31,    51,    32,    -1,    11,    31,    51,    34,    51,
      34,    51,    32,    43,    -1,    36,    37,    -1,    36,    42,
      37,    -1,     3,    -1,     4,    -1,     4,    17,    51,    -1,
       4,    31,    32,    -1,     4,    31,    52,    32,    -1,    51,
      27,    51,    -1,    51,    26,    51,    -1,    51,    29,    51,
      -1,    51,    28,    51,    -1,    31,    51,    32,    -1,    51,
      19,    51,    -1,    51,    18,    51,    -1,    30,    51,    -1,
      51,    24,    51,    -1,    51,    25,    51,    -1,    51,    22,
      51,    -1,    51,    23,    51,    -1,    51,    21,    51,    -1,
      51,    20,    51,    -1,    27,    51,    -1,    26,    51,    -1,
      51,    -1,    52,    33,    51,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    20,    26,    28,
      32,    34,    37,    40,    42,    44,    46,    48,    50,    52,
      54,    58,    61,    63,    69,    74,    78,    84,    92,    98,
     105,   115,   118,   122,   124,   126,   130,   134,   139,   143,
     147,   151,   155,   159,   163,   167,   170,   174,   178,   182,
     186,   190,   194,   197,   200,   202
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  parser::yyrline_[] =
  {
         0,    33,    33,    34,    35,    36,    39,    40,    43,    44,
      47,    48,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    64,    67,    68,    71,    72,    75,    78,
      81,    84,    85,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   111,   112
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    34,
       2,    17,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 419;
  const int parser::yynnts_ = 15;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 49;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 38;

  const unsigned int parser::yyuser_token_number_max_ = 284;
  const parser::token_number_type parser::yyundef_token_ = 2;


} // yy
/* Line 1141 of lalr1.cc  */
#line 1277 "Grammar.tab.cpp"
/* Line 1142 of lalr1.cc  */
#line 115 "Grammar.y"


namespace yy{
	void parser::error (const location_type& loc, const std::string& msg){
		std::cerr << "error at " << loc << ": " << msg << std::endl;
	}
}