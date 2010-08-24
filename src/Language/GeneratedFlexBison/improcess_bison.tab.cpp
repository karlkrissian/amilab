/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

// Take the name prefix into account.
#define yylex   yyiplex

#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */
#line 801 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc.  */
#line 57 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG							\
  for (bool yydebugcond_ = yydebug_; yydebugcond_; yydebugcond_ = false)	\
    (*yycdebug_)

/* Enable debugging if requested.  */
#if YYDEBUG

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

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

namespace yyip
{
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif /* ! YYDEBUG */

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 55: /* "ASTRING" */
#line 794 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 217 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 58: /* "IDENTIFIER" */
#line 795 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };
#line 222 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 403: /* "exprstringlist" */
#line 797 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };
#line 227 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 406: /* "primary_expr_string" */
#line 794 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 232 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 407: /* "instr_block" */
#line 796 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };
#line 237 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 413: /* "expr_string" */
#line 794 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 242 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 439: /* "identifier" */
#line 795 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };
#line 247 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;

	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }


  int
  Parser::parse ()
  {
    /// Look-ahead and look-ahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the look-ahead.
    semantic_type yylval;
    /// Location of the look-ahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    #line 344 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}
  /* Line 555 of yacc.c.  */
#line 329 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without look-ahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a look-ahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
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
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Accept?  */
    if (yyn == yyfinal_)
      goto yyacceptlab;

    /* Shift the look-ahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != yyeof_)
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

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 22:
#line 840 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno=driver.yyiplineno;
      AmiInstructionBlock::ptr block((yysemantic_stack_[(8) - (7)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (2)].ident));

      int_ptr varint(new int);
      Vars.AddVar<int>(ident,varint);

      for(*varint = (int) (yysemantic_stack_[(8) - (4)].adouble); *varint <= (int) (yysemantic_stack_[(8) - (6)].adouble); (*varint)++)
        {
          driver.yyiplineno = block->GetStartingLine();
          driver.parse_block(block);
        }
      Vars.deleteVar(ident->GetName().c_str());
      driver.yyiplineno=previous_lineno;
    ;}
    break;

  case 23:
#line 859 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno=driver.yyiplineno;
      AmiInstructionBlock::ptr block((yysemantic_stack_[(10) - (9)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(10) - (2)].ident));

      float_ptr var(new float);
      Vars.AddVar<float>(ident,var);

      for(*var = (yysemantic_stack_[(10) - (4)].adouble); *var <= (yysemantic_stack_[(10) - (6)].adouble); (*var)+=(yysemantic_stack_[(10) - (8)].adouble))
      {
        driver.yyiplineno = block->GetStartingLine();
        //driver.yyiplineno=previous_lineno;
        driver.parse_block(block);
      }
      Vars.deleteVar(ident->GetName().c_str());
      driver.yyiplineno=previous_lineno;
    ;}
    break;

  case 24:
#line 879 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
          Iteration through a list of strings.
    **/

      std::list<std::string>* sl = (yysemantic_stack_[(6) - (4)].string_list);

      int  previous_lineno=driver.yyiplineno;
      AmiInstructionBlock::ptr block((yysemantic_stack_[(6) - (5)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (2)].ident));

      // create the variable
      string_ptr tmp(new string());
      Variable<string>::ptr var = Vars.AddVar<string>(ident,tmp);
      //cout << " *** Create temporary variable " << ident->GetName() << endl;

      std::list<std::string>::iterator sl_it;
      for (sl_it=sl->begin(); sl_it!=sl->end(); sl_it++) {

        // assign new value to the variable
        //string_ptr newval( new std::string(*sl_it));
        (*var->Pointer()) = (*sl_it);

        driver.yyiplineno = block->GetStartingLine();
        //driver.yyiplineno=previous_lineno;
        driver.parse_block(block);

      }
      // should not delete based on the name !!!
      bool res = Vars.deleteVar(ident->GetName().c_str());
      //cout << " *** Delete temporary variable " << ident->GetName() << endl;
      if (!res) {
        cout << "**********" << endl;
        cout << "**** Could not delete variable in loop"  << ident->GetName() << endl;
        cout << "**********" << endl;
      }
      driver.yyiplineno=previous_lineno;

      // forced to delete the pointer to the list here
      delete (yysemantic_stack_[(6) - (4)].string_list);

    ;}
    break;

  case 25:
#line 924 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Repeats a block of instructions, and stop when an error is generated.
        Use the command 'break' to leave the loop
      See Also:
        break
     **/
        int  previous_lineno=driver.yyiplineno;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(2) - (2)].ablock));
        int res;
    
        do {
  
            //driver.yyiplineno=previous_lineno;
            driver.yyiplineno = block->GetStartingLine();
            res=driver.parse_block(block);
  
        } while (res);
        driver.yyiplineno = previous_lineno;
      ;}
    break;

  case 26:
#line 947 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Repeats the block while the variable value is higher than 0.5
      **/
        int  previous_lineno=driver.yyiplineno;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(3) - (3)].ablock));
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
  
        float res;
        if (var->IsNumeric()) 
          res = var->GetValueAsDouble();
        else {
          res = 0;
          driver.yyiperror(" while needs a numerical variable as condition \n");
        }
  
        while (res) {
          //driver.yyiplineno=previous_lineno;
          driver.yyiplineno = block->GetStartingLine();
          res=driver.parse_block(block);
          res = var->GetValueAsDouble();
        } 
        driver.yyiplineno = previous_lineno;
      ;}
    break;

  case 27:
#line 977 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno;
      AmiInstructionBlock::ptr block((yysemantic_stack_[(4) - (3)].ablock));

      // Pb with line numbers
      previous_lineno=driver.yyiplineno;

        if ((yysemantic_stack_[(4) - (2)].adouble)>0.5)
        {
          //driver.yyiplineno=previous_lineno;
          if (!driver.parse_block(block)) YYABORT;
          driver.yyiplineno = previous_lineno;
        }
    ;}
    break;

  case 28:
#line 992 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno = driver.yyiplineno;

      AmiInstructionBlock::ptr block_if(  (yysemantic_stack_[(6) - (3)].ablock));
      AmiInstructionBlock::ptr block_else((yysemantic_stack_[(6) - (5)].ablock));

      // Pb with line numbers
      previous_lineno=driver.yyiplineno;

      bool res;
      if ((yysemantic_stack_[(6) - (2)].adouble)>0.5)
        res = driver.parse_block(block_if);
      else
        res = driver.parse_block(block_else);
      if (!res) YYABORT;
      driver.yyiplineno = previous_lineno;

    ;}
    break;

  case 29:
#line 1014 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    ;}
    break;

  case 30:
#line 1019 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (2)].ident));

      AMIFunction::ptr amifunc(new AMIFunction);

      amifunc->SetName(ident->GetName().c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);

      if (GB_debug)
        cout  << ident->GetName()
              << " body = "
              << body->GetBody()  << endl;

      BasicVariable::ptr newvar = Vars.AddVar<AMIFunction>( ident, amifunc);
      if (newvar.get())
        amifunc->SetContext(newvar->GetContext());

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    ;}
    break;

  case 31:
#line 1045 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    ;}
    break;

  case 32:
#line 1051 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));

      GET_VARSTACK_VAR_VAL(AMIFunction, var, func);

      // Why delete and recreate previous variable ???
      // delete previous variable
//      std::string varname = var->Name();
//      int context = Vars.GetContext(boost::static_pointer_cast<BasicVariable>(var));
//      Vars.deleteVar(var);

      FILE_MESSAGE(boost::format("Redefining procedure %1%") % var->Name()); 

//      AMIFunction::ptr amifunc( new AMIFunction);
      AMIFunction::ptr amifunc(func);

//      amifunc->SetName(varname.c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);
      FILE_MESSAGE(boost::format("%1%: body = %2%")
                    % var->Name()  % body->GetBody());

      // add the variable in the same context ...
//      BasicVariable::ptr newvar =
//        Vars.AddVar<AMIFunction>(
//                      varname,
//                     amifunc,
//                      context);
//      if (newvar.get())
//        amifunc->SetContext(newvar->GetContext());

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    ;}
    break;

  case 33:
#line 1092 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(4) - (3)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (2)].ident));

      AMIClass::ptr amiclass( new AMIClass);

      amiclass->SetName(ident->GetName());
      amiclass->SetFileName(driver.current_file);
      amiclass->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", ident->GetName().c_str(),body->GetBody().c_str());

      Vars.AddVar<AMIClass>(ident, amiclass);

    ;}
    break;

  case 34:
#line 1109 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<AMIClass>::ptr var(driver.var_stack.GetLastVar<AMIClass>());
      AMIClass::ptr parent = var->Pointer();

      AmiInstructionBlock::ptr body((yysemantic_stack_[(7) - (6)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(7) - (2)].ident));

      AMIClass::ptr amiclass( new AMIClass);

      amiclass->SetName(ident->GetName());
      amiclass->SetFileName(driver.current_file);
      amiclass->Inherit(parent);
      amiclass->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", ident->GetName().c_str(),body->GetBody().c_str());

      Vars.AddVar<AMIClass>(ident, amiclass);

    ;}
    break;

  case 35:
#line 1130 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<AMIClass>::ptr var(driver.var_stack.GetLastVar<AMIClass>());
      AMIClass::ptr ac = var->Pointer();
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));

      //AMIObject::ptr amiobject;
      //amiobject = AMIObject::ptr(new AMIObject);
      AMIObject::ptr amiobject( new AMIObject);

      amiobject->SetName(ident->GetName());
      amiobject->SetClass(ac);

      // execute the code of the class with the variables of the object
      driver.yyip_instanciate_object(ac,amiobject);

      Vars.AddVar<AMIObject>(ident, amiobject);

    ;}
    break;

  case 36:
#line 1151 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     ;}
    break;

  case 37:
#line 1158 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          //cout << "current wd = "  <<  wxGetCwd() << endl;
          res=AskScript(name);
          if (!res) {
            driver.yyiperror(" Need script \n");
            YYABORT;
          }
          //cout << "current wd = "  <<  wxGetCwd() << endl;

        driver.res_print(name.c_str());
        driver.res_print("\n");
        driver.parse_file(name.c_str());

        // convert path delimiters to avoid pbs with \ character
        wxFileName filename(GetwxStr(name.c_str()),wxPATH_NATIVE);
        filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);

        wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                            filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                            filename.GetPathSeparator(wxPATH_UNIX)+
                            filename.GetFullName());

        driver.res_print( newname.mb_str());
        driver.res_print("\n");
        inc_cmd = str(format(" \"%1%\" // from browser ") % newname.mb_str());
        if (driver.InConsole())
          GB_main_wxFrame->GetConsole()
                          ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      ;}
    break;

  case 38:
#line 1193 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    ;}
    break;

  case 39:
#line 1203 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (var.get()) {
            // TODO: only do it from the command line ???
            //cout << "display var info" << endl;
            if (driver.InConsole())
              var->display();
          }

        ;}
    break;

  case 40:
#line 1219 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (var.get()) {
            switch (var->Type()) {
              // TODO: ad hoc fix to improve here, result should be a usable variable ??
              /// C++ wrapped member
              case type_class_member: {
                DYNAMIC_CAST_VARIABLE(WrapClassMember,var,m);
                m->Pointer()->CallMember(NULL);
               }
              break;
              /// language function without parameters.
              case type_ami_function: {
                DYNAMIC_CAST_VARIABLE(AMIFunction,var,vf);
                AMIFunction::ptr f(vf->Pointer());
                driver.yyip_call_function(f);
               }
              break;
              default:;
                // TODO: only do it from the command line ???
                //cout << "display var info" << endl;
                if (driver.InConsole())
                  var->display();
            }
          }

        ;}
    break;

  case 41:
#line 1251 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         ;}
    break;

  case 42:
#line 1259 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Calls YYABORT to leave the current instruction block.
            See Also:
              repeat
          **/
           YYABORT;
         ;}
    break;

  case 43:
#line 1270 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a global context for variables,
          creates new variables as global and can only
          access global variables

         See also:
          local, global_new
         **/
       Vars.SetGlobalContext();
         ;}
    break;

  case 44:
#line 1284 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a global context for new variables,
          creates new variables as global,
          but allow access to lobal variables

         See also:
          local, global
         **/
       Vars.SetGlobalNew(1);
         ;}
    break;

  case 45:
#line 1298 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a local context for new variables,
          creates new variables as local,
          and allow access to local variables

         See also:
          local, global, global_new
         **/
       Vars.SetGlobalNew(0);
         ;}
    break;

  case 46:
#line 1312 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
         ;}
    break;

  case 47:
#line 1322 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description: waits the time given in milliseconds
        **/

        int ms = (int) (yysemantic_stack_[(4) - (3)].adouble);
        wxWaitTimer w;
        w.Start(ms,wxTIMER_ONE_SHOT);
        while (!w.finished) {
          if (GB_wxApp->Pending()) {
            GB_wxApp->Dispatch();
          }
        } // end while
      ;}
    break;

  case 48:
#line 1338 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) time in ms
            (5) function to schedule
        **/

        int ms = (int) (yysemantic_stack_[(6) - (3)].adouble);
        GET_VARSTACK_VAR_VAL(AMIFunction,var,val);

        wxScheduleTimer::ptr w = wxScheduleTimer::ptr(new wxScheduleTimer( var ));
        // add to the list of schedule timers
        schedule_timers.push_back(w);
        w->Start(ms,wxTIMER_ONE_SHOT);

      ;}
    break;

  case 49:
#line 1356 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a reference to an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
          IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (1)].ident));
          BasicVariable::ptr newvar( var->NewReference());
          Vars.AddVar(ident,newvar);
      ;}
    break;

  case 50:
#line 1371 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a reference to an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (1)].ident));
        if (var.get() && (var->HasPointer())  ) {
          if ((var->GetPtrCounter()==1)&&(var.use_count()==1)) {
            //cout << "var.use_count() = " << var.use_count() << endl;
            Vars.AddVar(ident,var);
            //cout << "var.use_count() = " << var.use_count() << endl;
          } else {
            BasicVariable::ptr newvar( var->NewReference());
            Vars.AddVar(ident,newvar);
          }
        } else {
          driver.err_print("identifier = &expr_var, no variable value");
          YYABORT;
        }
      ;}
    break;

  case 51:
#line 1397 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
        // check counter of the value, not of the variable ...
        if (var.get() && (var->HasPointer())  ) {
          //cout << "GetPtrCounter == " <<  var->GetPtrCounter()<< endl;
          //cout << "use_count() == " <<  var.use_count() << endl;
          // only if both reference counters are equal to 1, we can avoid copy the variable
          if ((var->GetPtrCounter()==1)&&(var.use_count()==1)) {
            //BasicVariable::ptr ref = var->NewReference();
            // need to run on reference to avoid renaming the own variable !!!
            //Vars.AddVar(ident,ref);
            Vars.AddVar(ident,var);
          } else
          {
            BasicVariable::ptr copy = var->NewCopy();
            if (copy.get()) {
              Vars.AddVar(ident,copy);
            } else {
              driver.err_print("Copy failed for the variable in rule id = expr_var");
              YYABORT;
            }
          }
        } else {
          driver.err_print("identifier = expr_var, no variable value");
          YYABORT;
        }
      ;}
    break;

  case 52:
#line 1434 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one, and sets its comments
          Parameters:
            - new variable name;
            - existing variable name.
        **/
        boost::shared_array<char> comments( (yysemantic_stack_[(5) - (5)].astring));
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));
        if (var->GetPtrCounter()==1) {
          var->SetComments(comments.get());
          Vars.AddVar(ident,var);
        } else
        {
          if (var.get()) {
            BasicVariable::ptr copy = var->NewCopy();
            copy->SetComments(comments.get());
            Vars.AddVar(ident,copy);
          } else {
            driver.err_print("identifier = variable, no variable value");
          }
        }
      ;}
    break;

  case 53:
#line 1461 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/

          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          // first process exception cases
          if (var.get()) {
            if (var->Type()==type_class_member) {
                /// C++ wrapped member
                DYNAMIC_CAST_VARIABLE(WrapClassMember,var,m);
                ParamList::ptr param((ParamList*)NULL);
                BasicVariable::ptr res(m->Pointer()->CallMember(param.get()));
                if (!res.get()) {
                  driver.yyiperror("Class member does not return a variable \n");
                  YYABORT;
                }
                res->Rename(ident->GetName().c_str());
                Vars.AddVar(res,ident->GetCreationContext());
            }
            else
            // general case
            // for now always call new copy here, otherwise a = b would rename b to a, which is bad
/*
            if (var->GetPtrCounter()==1) {
              IdentifierInfo::ptr ident($1);
              Vars.AddVar(ident,var);
            } else
*/
            {
                BasicVariable::ptr copy = var->NewCopy();
                Vars.AddVar(ident,copy);
            }
          } else {
            driver.err_print("identifier = variable, no variable value");
            YYABORT;
          }
      ;}
    break;

  case 54:
#line 1533 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            VarArray::ptr array(new VarArray());
            array->Init(type_image,size);
            Vars.AddVar<VarArray>(ident,array);
          ;}
    break;

  case 55:
#line 1544 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,imptr);
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          InrImage::ptr res;

          if (imptr.get()) {
            // check how many references it has, if only one, move pointer, else create new image
            if (imptr.use_count()==1) 
              res = imptr;
            else {
              // Create a copy since the image is already in use
              res = InrImage::ptr(new InrImage( imptr->GetFormat(),
                                                imptr->GetVDim(),
                                                ident->GetName().c_str(),
                                                imptr.get()));
              (*res) = (*imptr);
            }
            // this should be safe to avoid deleting the image, since the variable will copy the shared pointer
            Vars.AddVar<InrImage>(ident,res);
          }
          else
            driver.err_print((boost::format("assignment of NULL image for %1%  \n") %(yysemantic_stack_[(3) - (1)].ident)).str().c_str() );;
        ;}
    break;

  case 56:
#line 1570 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray, vararray, array);

          GET_VARSTACK_VALUE(InrImage,imptr);
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          std::string name;

          if (imptr.get()) {
            BasicVariable::ptr var = array->GetVar(i);
            if (var.get()) {
              Variable<InrImage>::ptr varim(boost::dynamic_pointer_cast<Variable<InrImage> >(var));
              if (varim->Pointer().get())
                  driver.err_print("array element already assigned\n");
            }
            else 
            {
                  name = (boost::format("%s[%d]") % (vararray->Name().c_str()) %i).str();
                  // should be OK
                  array->InitElement<InrImage>( i, imptr, name.c_str());
            }
          }
          else
            driver.err_print("assignment of NULL image\n");
      ;}
    break;

  case 57:
#line 1609 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix::ptr imptr( 
            driver.gltransf_stack.GetLastMatrix());
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          if (imptr.get())
            Vars.AddVar<GLTransfMatrix>(ident,imptr);
          else
            driver.err_print("assignment of NULL matrix\n");
        ;}
    break;

  case 58:
#line 1704 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creates a variable of type int
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        int_ptr varint (new int((int)(yysemantic_stack_[(6) - (5)].adouble)));
        Vars.AddVar<int>(ident,varint);
      ;}
    break;

  case 59:
#line 1716 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        - identifier: name of the new variable
        - expr: value of the new variable
        - expr_string: short description of the new variable
        Description: 
          Creates a variable of type int
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));
        boost::shared_array<char> comments( (yysemantic_stack_[(8) - (8)].astring));
  
        int_ptr varint( new int((int)(yysemantic_stack_[(8) - (5)].adouble)));
        BasicVariable::ptr var=Vars.AddVar<int>(ident,varint);
        if (var.get())
          var->SetComments(comments.get());
      ;}
    break;

  case 60:
#line 1735 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creates a variable of type unsigned char (used for boolean type too)
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
        uchar_ptr varuchar( new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble)));
        Vars.AddVar<unsigned char>(ident,varuchar);
      ;}
    break;

  case 61:
#line 1746 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        - identifier: name of the new variable
        - expr: value of the new variable
        - expr_string: short description of the new variable
      Description: 
        creates a variable of type unsigned char (used for boolean type too)
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));
        boost::shared_array<char> comments( (yysemantic_stack_[(8) - (8)].astring));

        uchar_ptr varuchar(new unsigned char((unsigned char)(yysemantic_stack_[(8) - (5)].adouble)));
        BasicVariable::ptr var=Vars.AddVar<unsigned char>(ident,varuchar);
        if (var.get())
          var->SetComments(comments.get());
      ;}
    break;

  case 62:
#line 1833 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));
          boost::shared_array<char> filename( (yysemantic_stack_[(8) - (5)].astring));
          boost::shared_array<char> rights( (yysemantic_stack_[(8) - (7)].astring));

          FILE_ptr file(fopen(filename.get(),rights.get()),file_deleter());
          if (file.get()) {
            Vars.AddVar<FILE>(ident,file);
          } else {
            fprintf(stderr,"error opening file '%s' in mode '%s'\n",
                      filename.get(),rights.get());
          /*
          switch (errno) {
          case EEXIST: fprintf(stderr,"EEXIST \n"); break;
          case EISDIR: fprintf(stderr,"EISDIR \n"); break;
          case ETXTBSY:fprintf(stderr,"ETXTBSY \n"); break;
          case EFAULT: fprintf(stderr,"EFAULT \n"); break;
          case EACCES: fprintf(stderr,"EACCES \n"); break;
          case ENAMETOOLONG: fprintf(stderr,"ENAMETOOLONG \n"); break;
          case ENOENT: fprintf(stderr,"ENOENT \n"); break;
          case ENOTDIR:fprintf(stderr,"ENOTDIR \n"); break;
          case EMFILE: fprintf(stderr,"EMFILE \n"); break;
          case ENFILE: fprintf(stderr,"ENFILE \n"); break;
          case ENOMEM: fprintf(stderr,"ENOMEM \n"); break;
          case EROFS:  fprintf(stderr,"EROFS \n"); break;
          case ELOOP:  fprintf(stderr,"ELOOP \n"); break;
          case ENOSPC: fprintf(stderr,"ENOSPC \n"); break;
                  default: fprintf("unknown error \n");
          }
          */
          }
        ;}
    break;

  case 63:
#line 1867 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          std::string filename(varfile->Name());

          if (Vars.GetVar(filename.c_str()).get())
              Vars.deleteVar(filename.c_str());

          FILE_ptr file(fopen((yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring)),file_deleter());
          if (file.get()) {
              Vars.AddVar<FILE>(filename.c_str(),file);
          } else {
            fprintf(stderr,"error opening file '%s' in mode '%s'\n",
                    (yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring));
          }
        ;}
    break;

  case 64:
#line 1883 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        ;}
    break;

  case 65:
#line 1889 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        ;}
    break;

  case 66:
#line 1893 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
    ;}
    break;

  case 67:
#line 1897 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      driver.SetTraceScanning((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    ;}
    break;

  case 68:
#line 1901 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
       Description: 
          Activate the debugging of the parser.
       Parameters:
          bool: 1:activate 0: desactivate
       **/
      driver.SetTraceParsing((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    ;}
    break;

  case 69:
#line 1911 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    ;}
    break;

  case 70:
#line 1916 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    ;}
    break;

  case 71:
#line 1920 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
       Description:
          Activate/Desactivate the display of message dialog in the language driver.
       Parameters:
          bool: 1:activate 0: desactivate
       **/
      driver.SetNoMessageDialog((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    ;}
    break;

  case 72:
#line 1930 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Parameter:
        Number: percentage of the current process that has been processed.
      Description:
        Sets the Progress bar in the Main window to the given percentage (between 0 and 100).
    **/
          GB_main_wxFrame->SetProgress((int)((yysemantic_stack_[(4) - (3)].adouble)+0.5));
    ;}
    break;

  case 73:
#line 1940 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Parameter:
        String: input text
      Description:
        Set the given text in the status bar
    **/
        boost::shared_array<char> text( (yysemantic_stack_[(4) - (3)].astring));
        GB_main_wxFrame->SetStatusText( text.get() );
    ;}
    break;

  case 74:
#line 1950 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
    ;}
    break;

  case 75:
#line 1954 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      std::string titre;
      GET_VARSTACK_VAR_VAL(InrImage, imagevar, im);
      BasicVariable::ptr var;
      int var_context = Vars.GetContext(imagevar);
      Variables::ptr context = imagevar->GetContext();

/*
          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // set new object context
            Vars.SetObjectContext(imagevar->GetContext());
          }
*/
      
      titre = (boost::format("%s_draw") % imagevar->Name().c_str()).str();
      FILE_MESSAGE(boost::format("SHOW var_image  title %s") % titre);
      //if (Vars.GetCurrentContext()->GetVar(titre,&var)) {
      var = context->GetVar(titre.c_str());
      if (var.get()) {
        GET_WRAPPED_OBJECT(DessinImage, var, di)
        if (di.get()) {
          DessinImageParametres* param;
          param = di->GetParam();
          param->_MAJ.MAJCoupes();
          di->Paint();
          di->Raise();
        } else {
          driver.err_print(
            (boost::format
              ("Unable to convert variable %1% to a wrapped DessinImage") % titre).str().c_str());
          YYABORT;
        }
      }
      else
      {
        // Call constructor from DessinImage constructor function
        ParamList* p = new ParamList();
        p->AddParam(imagevar);
        BasicVariable::ptr newvar = wrap_DessinImage().CallMember(p);
        FILE_MESSAGE(boost::format("SHOW var_image creating title %s ") % titre);
        if (newvar.get()) {
          newvar->Rename(titre.c_str());
          context->AddVar(newvar, context);
        } else {
          driver.err_print("Failed to create image viewer.");
          YYABORT;
        }
      }

/*
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // Restore the object context
            Vars.SetObjectContext(previous_ocontext);
          }
*/

        ;}
    break;

  case 76:
#line 2013 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im)
          string title;
          BasicVariable::ptr var;
          Variables::ptr context = varim->GetContext();

          title = (boost::format("%s_draw") % varim->Name()).str();
          var = Vars.GetVar(title.c_str());
          if (var.get()) {
            GET_WRAPPED_OBJECT(DessinImage, var, di)
            if (di.get()) {
              di->Hide();
            }
            else
              fprintf(stderr,"Variable %s_draw not of type imagedraw \n",
                varim->Name().c_str());
          } else
            fprintf(stderr,"Variable %s not visible \n",
          title.c_str());

        ;}
    break;

  case 77:
#line 2035 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description: rule to show a surface, since surface has moved to object wrapping
          **/
          GET_VARSTACK_VAR_OBJECT(SurfacePoly,surfvar,surf)
          string    titre;
          Viewer3D::ptr surfdraw;
          BasicVariable::ptr var;
          int var_context = Vars.GetContext(surfvar);

          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // set new object context
            Vars.SetObjectContext(surfvar->GetContext());
          }

          if ((var_context>=0)||
              (var_context==OBJECT_CONTEXT_NUMBER)) {
            titre = str(format("%s_draw") % surfvar->Name());
            var = Vars.GetVar(titre.c_str(),var_context);
            if (!var.get()) {
              surfdraw = Viewer3D::Create_ptr(
                            new Viewer3D( GB_main_wxFrame,
                                          wxString::FromAscii(titre.c_str())));

              BasicVariable::ptr newvar = 
                Vars.AddVar<Viewer3D>(  titre.c_str(),
                                        surfdraw,
                                        var_context);
              surfdraw->SetCloseFunction(
                              (void*) CB_delete_variable,
                              (void*) (newvar.get()));

              surfdraw->Show(true);
              // Add the surface to the OpenGL Object
              surfdraw->GetCanvas()->AddSurface( surf);
              surfdraw->Paint();
              surfdraw->GetCanvas()->Normalize();
              surfdraw->GetCanvas()->Center();
            } else
              cerr << " variable " << titre << " already exists " << endl;
          } // var_context >=0

          // Restore the object context
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            Vars.SetObjectContext(previous_ocontext);
          }

        ;}
    break;

  case 78:
#line 2085 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
          (1) image: vectorial or RGB input image
          (5) n: component index
          (7) variable expression: numerical or image expression
  
          Description:
            assigns the number or the image to the component 'n' of the input image
          **/

          int comp = (int) (yysemantic_stack_[(8) - (5)].adouble);
          BasicVariable::ptr param2(driver.var_stack.GetLastBasicVar());
          GET_VARSTACK_VALUE(InrImage, i1);
  
          if (param2.get()) {
            if (param2->IsNumeric()) {
              double val = param2->GetValueAsDouble();
              Si (comp<0) Ou (comp>i1->GetVDim()) Alors
                fprintf(stderr,"image.SetComponent(n,number) error index too high, reset to 0 \n");
                comp = 0;
              FinSi
              Si i1->VectorialFormat()  Alors
                i1->InitBuffer();
                Repeter
                  i1->VectFixeValeur(comp,val);
                JusquA Non(i1->IncBuffer()) FinRepeter
              FinSi
            }
            else 
            if (param2->Type()==type_image) {
              DYNAMIC_CAST_VARIABLE(InrImage,param2,varim2) 
              InrImage::ptr i2(varim2->Pointer());
  
              Si (comp<0) Ou (comp>i1->GetVDim()) Alors
                fprintf(stderr,"image.SetComponent(n,image) error index too high, reset to 0 \n");
                comp = 0;
              FinSi
    
              Si i2->ScalarFormat()  Alors
                i1->InitBuffer();
                i2->InitBuffer();
                Repeter
                    i1->VectFixeValeur(comp,i2->ValeurBuffer());
                    i2->IncBuffer();
                JusquA Non(i1->IncBuffer()) FinRepeter
              Sinon
                driver.yyiperror("image.SetComponent\t second image has to be scalar \n");
                YYABORT;
              FinSi
            }
            else {
              driver.err_print("image.SetComponent(expr,expr_var) operator with this type of parameter not available");
              YYABORT;
            }
          }
        ;}
    break;

  case 79:
#line 2175 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Pads the image ...
        **/
          GET_VARSTACK_VALUE(InrImage, i2);
          GET_VARSTACK_VALUE(InrImage, i1);
          int posx  = (int) (yysemantic_stack_[(16) - (3)].adouble);
          int stepx = (int) (yysemantic_stack_[(16) - (5)].adouble);
          int posy  = (int) (yysemantic_stack_[(16) - (7)].adouble);
          int stepy = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int posz  = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int stepz = (int) (yysemantic_stack_[(16) - (13)].adouble);

          Func_Pad(i1.get(),i2.get(),stepx,posx,stepy,posy,stepz,posz);

        ;}
    break;

  case 80:
#line 2201 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        ;}
    break;

  case 81:
#line 2205 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
              variable: input variable
              string expression: comments
          Description: Set comments for a variable
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
          boost::shared_array<char> comments( (yysemantic_stack_[(6) - (5)].astring));
          var->SetComments(comments.get());
        ;}
    break;

  case 82:
#line 2217 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete the given variable
        **/
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
         Vars.deleteVar(var);
        ;}
    break;

  case 83:
#line 2231 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete all variables that match the expression, where the expression can contain 
            '*' and '?' characters
        **/
        boost::shared_array<char> varmatch( (yysemantic_stack_[(2) - (2)].astring));
         Vars.deleteVars( varmatch.get());
        ;}
    break;

  case 84:
#line 2241 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - string expression: command to call
        Description:
          calls a command from the system using std::system()
      **/
        boost::shared_array<char> cmd( (yysemantic_stack_[(2) - (2)].astring));
        std::system( cmd.get());
      ;}
    break;

  case 85:
#line 2252 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Calls system 'ls' command (for unix systems)
      **/
         std::system("ls");
           ;}
    break;

  case 86:
#line 2260 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        driver.res_print("Topics: \n");
        driver.res_print("\t var:  variables                 \n");
            driver.res_print("\t     image:     Help for image     variables\n");
            driver.res_print("\t     imagedraw: Help for imagedraw variables\n");
        driver.res_print("\t cmd:  commands                  \n");
        driver.res_print("\t fnc:  functions                 \n");
        driver.res_print("\t loop: loops                     \n");
        driver.res_print("\t cond: conditions                \n");
            driver.res_print("\t arit: arithmetical expressions  \n");
      ;}
    break;

  case 87:
#line 2272 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
         if (strcmp(ident->GetName().c_str(),"var")==0) {
         driver.res_print("var types: void image float int string imagedraw surface surfacedraw \n");
         driver.res_print("\t del varname\n");
         driver.res_print("\t\t\t - deletes a variable and frees its contents from memory \n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"cmd")==0) {
         driver.res_print("commands:\n");
         driver.res_print("\t sh Quit Image Show Help ls print func filter normgrad discnormgrad OpImage EDPdilate EDPerode EDPopen EDPclose\n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"fnc")==0) {
         driver.res_print("functions:\n");
         driver.res_print("\t  filter normgrad gradient OpImage secdergrad ");
             driver.res_print("subimage putimage\n");
         driver.res_print("\t       OpImage( var_image, string ) \n");
         driver.res_print("\t       OpImage( var_image, var_image, string ) \n");
         driver.res_print("\t       OpImage( var_image, var_image, var_image, string ) \n");
         driver.res_print("\t       filter( var_image, expr, number, number, number ) \n");
         driver.res_print("\t       normgrad(   var_image, expr ) \n");
         driver.res_print("\t       discnormgrad(   var_image ) \n");
         driver.res_print("\t       gradient(   var_image, expr ) \n");
         driver.res_print("\t       secdergrad( var_image, expr ) \n");
         driver.res_print("\t       subimage( var_image, expr, expr, expr, expr, expr, expr ) \n");
         driver.res_print("\t       putimage( var_image, var_image, expr, expr, expr  ) \n");
         driver.res_print("\t       EDPdilate( var_image, expr, expr) \n");
         driver.res_print("\t       EDPerode(  var_image, expr, expr) \n");
         driver.res_print("\t       EDPopen(   var_image, expr, expr) \n");
         driver.res_print("\t       EDPclose(  var_image, expr, expr) \n");

         driver.res_print("\t       AnisoGS(   var_image, expr, expr, expr, expr) \n");
         driver.res_print("\t\t  expr 1: standard deviation of the Gaussian convolution  \n");
         driver.res_print("\t\t  expr 2: threshold on the gradient norm \n");
         driver.res_print("\t\t  expr 3: data attachment coefficient \n");
         driver.res_print("\t\t  expr 4: number of iterations \n");
             driver.res_print("\t       StructTensor( var_image, expr, expr ) \n");
             driver.res_print("\t       Curvatures(   var_image, expr ) \n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"loop")==0) {
         driver.res_print("loops:\n");
         driver.res_print("\t  for var=expr to expr { instructions } \n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"cond")==0) {
         driver.res_print("loops:\n");
         driver.res_print("\t  if expr  { instructions } \n");
         driver.res_print("\t\t  [ else { instructions } ]\n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"arit")==0) {
         driver.res_print("arithmetical expressions:\n");
         driver.res_print("\t  constants: Pi\n");
         driver.res_print("\n");
         driver.res_print("\t  functions:  cos()  sin()  tan() \n");
         driver.res_print("\t             acos() asin() atan() \n");
         driver.res_print("\t              exp()   ln()  log() \n");
         driver.res_print("\t             sinh() cosh()        \n");
         driver.res_print("\t  operators:\n");
         driver.res_print("\t            *, /\n");
         driver.res_print("\t            +, -\n");
         driver.res_print("\t            <, >, <=, >=\n");
         driver.res_print("\t            ==, != \n");
         driver.res_print("\t            & \n");
         driver.res_print("\t            ^ \n");
         driver.res_print("\t            | \n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"image")==0) {
         driver.res_print("variable Image\n");
         driver.res_print(" Creation:\n");
         driver.res_print("\t Image \"filename\"\n");
         driver.res_print("\t\t\t - reads an image file \n");
         driver.res_print("\t Image \n");
         driver.res_print("\t\t\t -  open browsing window for choosing the image\n");
         driver.res_print("\t Image(basic_type, size_x , size_y, size_z) \n");
         driver.res_print("\t\t\t - create an image of a basic type and the given dimensions\n");
         driver.res_print("\t\t\t - basic_type are CHAR UCHAR SHORT USHORT LONG INT FLOAT DOUBLE RGB FLOAT_VECTOR \n");
         driver.res_print("\t\t\t - size_x, size_y, size_z: float expressions \n");
         driver.res_print(" Functions that return a new image: \n");
         driver.res_print("\t OpImage( var_image, string ) \n");
         driver.res_print("\t\t\t - applies point to point operations to 1 image\n");
         driver.res_print("\t OpImage( var_image, var_image, string ) \n");
         driver.res_print("\t\t\t - applies point to point operations to 2 images\n");
         driver.res_print("\t OpImage( var_image, var_image, var_image, string ) \n");
         driver.res_print("\t\t\t - applies point to point operations to 3 images\n");
         driver.res_print("\t filter( var_image, size, number, number, number ) \n");
         driver.res_print("\t\t\t - applies Gaussian (or derivatives) convolution of sd size \n");
         driver.res_print("\t\t\t - number represent the derivation order:\n");
         driver.res_print("\t\t\t\t 0: no           derivation in this dimension\n");
         driver.res_print("\t\t\t\t 1: first order  derivation in this dimension\n");
         driver.res_print("\t\t\t\t 2: second order derivation in this dimension\n");
         driver.res_print("\t normgrad(   var_image, expr ) \n");
         driver.res_print("\t\t\t - applies Gaussian (or derivatives) convolution of sd size \n");

         driver.res_print("\t discnormgrad(   var_image ) \n");
         driver.res_print("\t\t\t - Discrete gradient norm without Gaussian convolution \n");

         driver.res_print("\t gradient(   var_image, expr ) \n");
         driver.res_print("\t\t\t - Gradient of the image using  Gaussian (and derivatives) convolution of sd size \n");

         driver.res_print("\t secdergrad( var_image, expr ) \n");
             driver.res_print("\t\t\t - Compute the second order derivative in the gradient direction.\n");


         driver.res_print("\t subimage( var_image, expr, expr, expr,");
         driver.res_print(" expr, expr, expr ) \n");
             driver.res_print("\t\t\t - extract a subimage \n");

         driver.res_print("\t AddGaussNoise( var_image, expr, expr) \n");
             driver.res_print("\t\t\t - add a Gaussian noise to the image \n");
             driver.res_print("\t\t\t - param 2: mean \n");
             driver.res_print("\t\t\t - param 3: standard deviation \n");

         driver.res_print("\t eccentricity( var_image) \n");
             driver.res_print("\t\t\t - Compute a expression of eccentricity  \n");
             driver.res_print("\t\t\t - of the image, returns an 'expr'  \n");

         driver.res_print("\t isoarea2D( var_image, expr, expr, expr) \n");
             driver.res_print("\t\t\t - Compute the surface area of the region\n");
             driver.res_print("\t\t\t   of positive intensity containing the point\n");
             driver.res_print("\t\t\t   (x,y)\n");
             driver.res_print("\t\t\t expr 1: resolution  \n");
             driver.res_print("\t\t\t expr 2: x  \n");
             driver.res_print("\t\t\t expr 3: y  \n");

         driver.res_print("\t EDPdilate( var_image, expr, expr) \n");
         driver.res_print("\t EDPerode(  var_image, expr, expr) \n");
         driver.res_print("\t EDPopen(   var_image, expr, expr) \n");
         driver.res_print("\t EDPclose(  var_image, expr, expr) \n");

         driver.res_print("\t AnisoGS(   var_image, expr, expr, expr, expr) \n");
         driver.res_print("\t\t  expr 1: sigma     \n");
         driver.res_print("\t\t  expr 2: threshold \n");
         driver.res_print("\t\t  expr 3: data attachment coefficient \n");
         driver.res_print("\t\t  expr 4: number of iterations \n");

         driver.res_print("\t image = AnisoWeickert.init( var_image, expr, expr, expr )\n");
         driver.res_print("\t\t  expr 1:    sigma  \n");
         driver.res_print("\t\t  expr 2:    theshold  \n");
         driver.res_print("\t\t  expr 3:    evolution step dt  \n");
         driver.res_print("\t AnisoWeickert.iterate\n");
         driver.res_print("\t AnisoWeickert.end\n");

         driver.res_print("\t image = AnisoCW.init( var_image, expr, expr, expr,expr, expr )\n");
         driver.res_print("\t\t  expr 1:    sigma  first Gaussian convolution\n");
         driver.res_print("\t\t  expr 2:    rho    second Gaussian convolution\n");
         driver.res_print("\t\t  expr 2:    C      threshold for the coherence\n");
         driver.res_print("\t\t  expr 2:    alpha  lowest diffusion coefficient\n");
         driver.res_print("\t\t  expr 3:    dt     evolution step \n");
         driver.res_print("\t AnisoCW.iterate\n");
         driver.res_print("\t AnisoCW.end\n");

         driver.res_print(" Operations: \n");

         driver.res_print("\t Show var_image \n");
         driver.res_print("\t\t\t - displays the image \n");

         driver.res_print("\t var_image = var_image \n");
         driver.res_print("\t\t\t - makes a copy \n");

         driver.res_print("\t var_image.initvalue( expr ) \n");
             driver.res_print("\t\t\t - initialize every point to a scalar value \n");

         driver.res_print("\t var_image.initvalue( expr, expr, expr ) \n");
             driver.res_print("\t\t\t - initialization every point to a vector or RGB value \n");

         driver.res_print("\t var_image.set( expr ) \n");
         driver.res_print("\t\t\t - change the value a the current point \n");

         driver.res_print("\t var_image.set( expr, expr, expr ) \n");
         driver.res_print("\t\t\t - change the value a the current point \n");
         driver.res_print("\t\t\t - for RGB or VECTOR FIELD images \n");

         driver.res_print("\t var_image.setpos(expr,expr,expr) \n");
         driver.res_print("\t\t\t - set the current position \n");

         driver.res_print("\t var_image.putimage(var_image,expr,expr,expr) \n");
         driver.res_print("\t\t\t - put an image at the specified position \n");

         driver.res_print("\t var_image(expr,expr) \n");
         driver.res_print("\t\t\t - return the value at a 2D position \n");

         driver.res_print("\t var_image(expr,expr,expr) \n");
         driver.res_print("\t\t\t - return the value at a 3D position \n");

         driver.res_print("\t var_image.tx \n");
         driver.res_print("\t\t\t - return size in X \n");

         driver.res_print("\t var_image.ty \n");
         driver.res_print("\t\t\t - return size in Y \n");

         driver.res_print("\t var_image.tz \n");
         driver.res_print("\t\t\t - return size in Z \n");

         driver.res_print("\t var_image.init \n");
         driver.res_print("\t\t\t - init the current position to (0,0,0) \n");

         driver.res_print("\t var_image.info \n");
         driver.res_print("\t\t\t - print information on the image \n");

         driver.res_print("\t var_image.save \"filename\" \n");
         driver.res_print("\t\t\t - save the image \n");

         driver.res_print("\t var_image.normalize \n");
         driver.res_print("\t\t\t - normalizes a vector field image \n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"imagedraw")==0) {
         driver.res_print("variable imagedraw\n");
         driver.res_print(" Creation:");
         driver.res_print("\t show var_image \n");
         driver.res_print("\t\t\t - displays an image and creates a new variable\n");
         driver.res_print("\t\t\t   of type imagedraw and the name ending by _draw \n");
         driver.res_print(" Functions:\n");

         driver.res_print(" var_imagedraw.setpos( expr, expr, expr) \n");
         driver.res_print("\t\t\t   set the cursor position \n");

         driver.res_print(" var_imagedraw.showcursor( expr) \n");
         driver.res_print("\t\t\t   expr=1-->shows cursor   0-->hides cursor \n");

         driver.res_print(" var_imagedraw.update \n");
         driver.res_print("\t\t\t   update the displayed images \n");

         driver.res_print(" var_imagedraw.compare(var_image) \n");
         driver.res_print("\t\t\t   add a comparison image \n");

         driver.res_print(" var_imagedraw.setvector( number, var_image) \n");
         driver.res_print("\t\t\t   set var_image a the vector image with number \n");
         driver.res_print("\t\t\t   between 1 and 3 \n");
       }
     ;}
    break;

  case 88:
#line 2508 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_imagefunction, func);
      // call with NULL paramlist pointer to trigger help message
      (*func)(NULL);
    ;}
    break;

  case 89:
#line 2518 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_varfunction, func);
      // call with NULL paramlist pointer to trigger help message
      (*func)(NULL);
    ;}
    break;

  case 90:
#line 2528 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_procedure, proc);
      // call with NULL paramlist pointer to trigger help message
      (*proc)(NULL);
    ;}
    break;

  case 91:
#line 2538 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
      GET_VARSTACK_VALUE(WrapClassMember, m);
      m->ShowHelp();
    ;}
    break;

  case 92:
#line 2547 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      string  help_cmd;
      string  help_file;


      // Check for directory
      help_file = str( format("%s/%s") % GB_help_dir.c_str() % (yysemantic_stack_[(2) - (2)].astring));

      Si GB_debug AlorsFait fprintf(stderr,"3\n");
          help_cmd = str(format("test -d %s") % help_file.c_str());
          Si (std::system(help_cmd.c_str()) == 0) Alors
            printf("\nAvailable help files in %s:\n",(yysemantic_stack_[(2) - (2)].astring));
            help_cmd = str( format("cd %s; ls *.amih ") % help_file.c_str());
            std::system(help_cmd.c_str());
          Sinon

         Si GB_debug AlorsFait fprintf(stderr,"4\n");
            // Check for file
            help_file = str( format("%s/%s.amih") % GB_help_dir.c_str() %(yysemantic_stack_[(2) - (2)].astring));

            help_cmd = str(format("test -r %s") % help_file.c_str());
            Si (std::system(help_cmd.c_str()) == 0) Alors
              help_cmd = str( format("more %s") % help_file.c_str());
              std::system(help_cmd.c_str());
            Sinon
              Si GB_debug AlorsFait fprintf(stderr,"5\n");
              // Try to find it in any subdirectory of the help dir
              help_cmd = str(format("test -r `find %s -name \"%s.amih\"` 2> /dev/null")
                            % GB_help_dir.c_str()
                            % (yysemantic_stack_[(2) - (2)].astring));
              Si std::system(help_cmd.c_str())==0 Alors
                help_cmd = str(format("find %s -name \"%s.amih\" -exec ls {} \\; -exec more {} \\;")
                  % GB_help_dir.c_str()
                  % (yysemantic_stack_[(2) - (2)].astring));
                std::system(help_cmd.c_str());
              Sinon
                fprintf(stderr,"\nNo help file (%s) found for this command \n",
            help_file.c_str());
            printf("\nAvailable help directories:\n");
            help_cmd = str(format("cd %s; find . -type d  ") % GB_help_dir.c_str());
                std::system(help_cmd.c_str());

                printf("\nAvailable help files:\n");
            help_cmd = str(format("ls *.amih ") %
                std::system(help_cmd.c_str()));
          FinSi
            FinSi

          FinSi

      Si GB_debug AlorsFait fprintf(stderr,"6\n");

        ;}
    break;

  case 93:
#line 2612 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());

          if (var.get()) {
            fprintf(file.get(),var->GetValueAsString().c_str());
            fflush(file.get());
          }
          else
            driver.err_print("empty variable");

      ;}
    break;

  case 94:
#line 2626 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());

          if (var.get()) {
            fprintf(file.get(),var->GetValueAsString().c_str());
            fprintf(file.get(),"\n");
            fflush(file.get());
          }
          else
            driver.err_print("empty variable");

      ;}
    break;

  case 95:
#line 2660 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a value of a variable, if the string conversion is defined, a message otherwise
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var.get())
            driver.res_print(var->GetValueAsString());
          else
            driver.err_print("empty variable");
        ;}
    break;

  case 96:
#line 2672 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a value of a variable + newline, if the string conversion is defined, a message otherwise
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var.get())
            driver.res_print(var->GetValueAsString()+"\n");
          else
            driver.err_print("empty variable");
        ;}
    break;

  case 97:
#line 2713 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         /**
          Parameters:
            string expression: information text
          Description:
            Popup an Information Dialog with the given message
          **/
          driver.info_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
      ;}
    break;

  case 98:
#line 2732 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        ;}
    break;

  case 99:
#line 3195 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
          Description:
            Init the image buffer to the first voxel or pixel:
            at coordinates (0,0,0).
    
          See also:
                  inc val
    
          Example(s):
    
          i.init
          for x=0 to i.tx-1 {
            print "value at x = "; print x; print ": ";
            print i.val; print "\n";
            i.inc
          }
          **/
          GET_VARSTACK_VALUE(InrImage, im);
          im->InitBuffer();
        ;}
    break;

  case 100:
#line 3217 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
            /**
              Description:
                Prints the image information
            **/
            GET_VARSTACK_VAR_VAL(InrImage, varim, im);
            std::string tmp_string;
            tmp_string = (boost::format(" %s: format=%s  dim=(%d,%d,%d)x%d  vox=(%f,%f,%f) \
      translation =(%f,%f,%f) \n")
                % varim->Name()
                % im->FormatName().c_str()
                % im->_tx
                % im->_ty
                % im->_tz
                % im->GetVDim()
                % im->_size_x
                % im->_size_y
                % im->_size_z
                % im->_translation_x
                % im->_translation_y
                % im->_translation_z).str();
            driver.res_print(tmp_string);
        ;}
    break;

  case 101:
#line 3241 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Prints the object information
          **/
          GET_VARSTACK_VAR_VAL(AMIObject,varamio,o);
          
          if (o.get()) {
            cout << "var   name = " << varamio->Name() <<endl;
            if (o->GetClass().get()) {
              cout << "class name = " << o->GetClass()->GetName() <<endl;
            }
            o->GetContext()->display();
          }
    /*      std::string tmp_string;
          tmp_string = (boost::format("Object '%1%' instance of class '%2% \n")
              % $1->Name() % o->GetClass()->GetName() ).str();
          driver.res_print(tmp_string);
          o->GetContext()->display();
    */
        ;}
    break;

  case 102:
#line 3263 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  value to init the image

        Description:
          Set the whole image to the same vector value .
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          (im)->InitImage((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 103:
#line 3275 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X coord of the init vector
          (7) expr:  Y coord of the init vector
          (9) expr:  Z coord of the init vector

        Description:
          Set the whole image to the same value.
        **/
          GET_VARSTACK_VALUE(InrImage,    im);
          im->InitImage((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        ;}
    break;

  case 104:
#line 3289 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          #1 expr:  scalar value

        Description:
        Set the current voxel (or pixel)
        to the specified value.
        The position of the current voxel can be set
        using 'setpos'.


        See also:
                setpos
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          im->FixeValeur((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 105:
#line 3308 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

        /**
        Parameters:
          #1 expr:  X coord of the vector value
          #2 expr:  Y coord of the vector value
          #3 expr:  Z coord of the vector value

        Description:
        Set the current voxel (or pixel)
        to the specified value.
        The position of the current voxel can be set
        using 'setpos'.


        See also:
                setpos
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          im->VectFixeValeurs((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        ;}
    break;

  case 106:
#line 3330 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

        /**
        Parameters:
          #1 expr:  field component
          #2 expr:  image value

        Description:
        Set the current voxel (or pixel) 
        to the specified value for the given component.
        The position of the current voxel can be set
        using 'setpos'.


        See also:
                setpos
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          im->VectFixeValeur((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 107:
#line 3351 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X position
          (7) expr:  Y position
          (9) expr:  Z position

        Description:
          Set the current voxel (or pixel) of the image
          to the specified position.

        See also:
          set
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          int x = (int) round((double)(yysemantic_stack_[(10) - (5)].adouble));
          int y = (int) round((double)(yysemantic_stack_[(10) - (7)].adouble));
          int z = (int) round((double)(yysemantic_stack_[(10) - (9)].adouble));
          Si im->CoordOK( x,y,z)
          Alors
            im->BufferPos(x,y,z);
          Sinon
            std::string tmp_string;
            tmp_string = (boost::format("setpos \t coord = (%1% %2% %3%) from (%4% %5% %6%) \n")%x%y%z % (yysemantic_stack_[(10) - (5)].adouble) % (yysemantic_stack_[(10) - (7)].adouble) % (yysemantic_stack_[(10) - (9)].adouble)).str();
          driver.err_print(tmp_string);
          FinSi
        ;}
    break;

  case 108:
#line 3382 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1)  var_image: image to modify
          (5)  var_image: image to insert
          (7)  expr:      X position of inserted image
          (9)  expr:      Y position
          (11) expr:      Z position

        Description:
          Insert an image (#2) in a given image (#1)
          at the specified position in voxel coordinates,
          does not use the translation information from the image.

        Example(s):
          i = Image(FLOAT,10,10,10)
          j = Image(FLOAT,5,5,5)
          i.putimage(j,2,2,2)
        **/
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          InrImage::ptr  i1(varim1->Pointer());
          InrImage::ptr  i2(varim2->Pointer());
          Func_PutImage( i1.get(), i2.get(), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble));
        ;}
    break;

  case 109:
#line 3409 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1)  var_image: image to modify
          (5)  var_image: image to insert

        Description:
          Insert an image  in a given image,
          uses the translation and the voxel size information
          to calculate where to insert the image.

        Example(s):
          i = Image(FLOAT,10,10,10)
          j = Image(FLOAT,5,5,5)
          i.putimage(j,2,2,2)
        **/
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          InrImage::ptr  i1(varim1->Pointer());
          InrImage::ptr  i2(varim2->Pointer());
          float tx1,ty1,tz1;
          float tx2,ty2,tz2;

          i1->GetTranslation(tx1,ty1,tz1);
          i2->GetTranslation(tx2,ty2,tz2);
          Func_PutImage( i1.get(), i2.get(),
             (int) round((double)(tx2-tx1)/i1->VoxSizeX()),
             (int) round((double)(ty2-ty1)/i1->VoxSizeY()),
             (int) round((double)(tz2-tz1)/i1->VoxSizeZ()));
    ;}
    break;

  case 110:
#line 3441 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    ;}
    break;

  case 111:
#line 3638 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 112:
#line 3643 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    ;}
    break;

  case 113:
#line 3650 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 114:
#line 3655 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    ;}
    break;

  case 115:
#line 3895 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          (4) expr_string:  image name

        Description:
          Save the image to the disk, using the specified
          image name.
          The output format depends on the image type
          and on the filename extension.
          For saving images with standard 2D image format
          (jpeg, gif, etc...) you need to have a RGB image.


        Example(s):

          rgb_im = (RGB) im
          im.save "image.jpg"


        See also:
          image_cast
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
          im->Sauve(filename.get());
        ;}
    break;

  case 116:
#line 3923 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Normalizes a vector field given by a vectorial image.

        Example(s):
          v1.normalize

        **/
      GET_VARSTACK_VALUE(InrImage, im);
      Func_Normalize((im.get()));
    ;}
    break;

  case 117:
#line 3937 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    ;}
    break;

  case 118:
#line 3944 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    ;}
    break;

  case 119:
#line 3950 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    ;}
    break;

  case 120:
#line 3961 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(DessinImage,di);
      float minlat  = (yysemantic_stack_[(20) - (5)].adouble);
      float maxlat  = (yysemantic_stack_[(20) - (7)].adouble);
      float latstep = (yysemantic_stack_[(20) - (9)].adouble);
      float latsmallsteps = (yysemantic_stack_[(20) - (11)].adouble);
      float minlon  = (yysemantic_stack_[(20) - (13)].adouble);
      float maxlon  = (yysemantic_stack_[(20) - (15)].adouble);
      float lonstep = (yysemantic_stack_[(20) - (17)].adouble);
      float lonsmallsteps = (yysemantic_stack_[(20) - (19)].adouble);

      float  lat,lon;
      float  X,Y;
      float  posx1=0,posy1=0;
      int    pos1_OK,pos2_OK;
      float  posx2=0,posy2=0;
      int    len;
      AMIFluid::TNavig nav_params;
      int    i_offset, j_offset;
      int    type=1; // Africa
      char typestring[2][255] = {"NAtl","AfGG"};

      InrImage::ptr           im   = di->GetImage();
      DessinImageParametres* param = di->GetParam();

      AMIFluid::InitCoordinates(i_offset,j_offset,nav_params, typestring[type]);
      minlat  *= PI/180.0;
      maxlat  *= PI/180.0;
      minlon  *= PI/180.0;
      maxlon  *= PI/180.0;
      latstep *= PI/180.0;
      lonstep *= PI/180.0;

      latsmallsteps *= PI/180.0;
      lonsmallsteps *= PI/180.0;

      // Lattitude lines
      for(lat=minlat;lat<=maxlat;lat+=latstep) {
        pos1_OK=0;
        for(lon=minlon;lon<=maxlon;lon+=lonsmallsteps)
          {
        AMIFluid::COOCAR1(lat,lon,X,Y,len,nav_params);
        if (len==0) {
          //          printf("len==0\n");
          X=X-i_offset;
          Y=Y-j_offset;
          posx2=(X-im->TrX())/im->VoxSizeX();
          posy2=(Y-im->TrY())/im->VoxSizeY();

          pos2_OK =  ((posx2>=param->_Zoom._xmin)&&(posx2<=param->_Zoom._xmax)&&
                  (posy2>=param->_Zoom._ymin)&&(posy2<=param->_Zoom._ymax));
          if (pos1_OK&&pos2_OK) {
            if (fabsf(lat)>1E-5)
              di->SetLineParameters( 1, wxSOLID, wxCAP_ROUND, wxJOIN_MITER);
            else
              di->SetLineParameters( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
            di->DrawLineZ(posx1,posy1,posx2,posy2);
          }
        }
        else pos2_OK=0;

        posx1=posx2;
        posy1=posy2;
        pos1_OK=pos2_OK;
          }
      }

      // Longitude Lines
      for(lon=minlon;lon<=maxlon;lon+=lonstep) {
        pos1_OK=0;
        for(lat=minlat;lat<=maxlat;lat+=latsmallsteps)
          {
        AMIFluid::COOCAR1(lat,lon,X,Y,len,nav_params);
        if (len==0) {
          //          printf("len==0\n");
          X=X-i_offset;
          Y=Y-j_offset;
          posx2=(X-im->TrX())/im->VoxSizeX();
          posy2=(Y-im->TrY())/im->VoxSizeY();

          pos2_OK =  ((posx2>=param->_Zoom._xmin)&&(posx2<=param->_Zoom._xmax)&&
                  (posy2>=param->_Zoom._ymin)&&(posy2<=param->_Zoom._ymax));
          if (pos1_OK&&pos2_OK) {
            if (fabsf(lon)>1E-5)
              di->SetLineParameters( 1, wxSOLID, wxCAP_ROUND, wxJOIN_MITER);
            else
              di->SetLineParameters( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
            di->DrawLineZ(posx1,posy1,posx2,posy2);
          }
        }
        else pos2_OK=0;

        posx1=posx2;
        posy1=posy2;
        pos1_OK=pos2_OK;
          }
      }

      ;}
    break;

  case 121:
#line 4061 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 122:
#line 4068 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        ;}
    break;

  case 123:
#line 4076 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        ;}
    break;

  case 124:
#line 4084 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        ;}
    break;

  case 125:
#line 4092 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint(false);
        ;}
    break;

  case 126:
#line 4103 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw(varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        ;}
    break;

  case 127:
#line 4113 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        ;}
    break;

  case 128:
#line 4121 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 129:
#line 4129 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        ;}
    break;

  case 130:
#line 4140 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        ;}
    break;

  case 131:
#line 4147 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,im);
          GET_VARSTACK_VALUE(Viewer3D,draw);

          switch ((int) (yysemantic_stack_[(8) - (5)].adouble)) {
          case 1:
            draw->GetCanvas()->SetVectors1( im);
            break;
          case 2:
            draw->GetCanvas()->SetVectors2( im);
            break;
          }
        ;}
    break;

  case 132:
#line 4161 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(16) - (5)].adouble);
          GET_VARSTACK_VALUE(InrImage,im);
          int orientation = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int pos = (int) (yysemantic_stack_[(16) - (11)].adouble);
          float Imin = (yysemantic_stack_[(16) - (13)].adouble);
          float Imax = (yysemantic_stack_[(16) - (15)].adouble);

          draw->GetCanvas()->ShowFreeSection(num,im.get(),orientation,pos,Imin,Imax);

        ;}
    break;

  case 133:
#line 4175 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        ;}
    break;

  case 134:
#line 4184 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        ;}
    break;

  case 135:
#line 4189 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        ;}
    break;

  case 136:
#line 4198 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        ;}
    break;

  case 137:
#line 4207 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->Paint();
          sdraw->Update();
          //sdraw->Raise();
          // process all pending events ...
		  /*
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
		  */
        ;}
    break;

  case 138:
#line 4222 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          int lightnumber = (int) (yysemantic_stack_[(12) - (5)].adouble);
          int r = (int) (yysemantic_stack_[(12) - (7)].adouble);
          int g = (int) (yysemantic_stack_[(12) - (9)].adouble);
          int b = (int) (yysemantic_stack_[(12) - (11)].adouble);
          if (lightnumber<MAX_LIGHTS) {
                sdraw->GetCanvas()->GetLight(lightnumber)._ambient.FixeValeur(r,g,b);
            sdraw->Paint();
          }
        ;}
    break;

  case 139:
#line 4235 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          int lightnumber = (int) (yysemantic_stack_[(12) - (5)].adouble);
          int r = (int) (yysemantic_stack_[(12) - (7)].adouble);
          int g = (int) (yysemantic_stack_[(12) - (9)].adouble);
          int b = (int) (yysemantic_stack_[(12) - (11)].adouble);
          if (lightnumber<MAX_LIGHTS) {
                sdraw->GetCanvas()->GetLight(lightnumber)._diffuse.FixeValeur(r,g,b);
            sdraw->Paint();
          }
        ;}
    break;

  case 140:
#line 4248 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          int lightnumber = (int) (yysemantic_stack_[(12) - (5)].adouble);
          int r = (int) (yysemantic_stack_[(12) - (7)].adouble);
          int g = (int) (yysemantic_stack_[(12) - (9)].adouble);
          int b = (int) (yysemantic_stack_[(12) - (11)].adouble);
          if (lightnumber<MAX_LIGHTS) {
                sdraw->GetCanvas()->GetLight(lightnumber)._specular.FixeValeur(r,g,b);
            sdraw->Paint();
          }
        ;}
    break;

  case 141:
#line 4261 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 142:
#line 4268 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->Normalize();
        ;}
    break;

  case 143:
#line 4278 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->Center();
        ;}
    break;

  case 144:
#line 4288 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->SetSize((int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
          sdraw->Update();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        ;}
    break;

  case 145:
#line 4302 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        ;}
    break;

  case 146:
#line 4310 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        ;}
    break;

  case 147:
#line 4321 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) Input image
            (5) Numerical expression: sigma, Gaussian standard deviation
            (7) Numerical expression: beta, Hessian matrix coefficient
        Description:
            Computation of a Tensor that combines the standard
            gradient based structure tensor and the square
            of the Hessian matrix
            Computes eigenvalues and eigenvectors of the tensor
            and saves them in images:
            i_STHvap1, i_STHvap2, i_STHvap3
            i_STHvep1, i_STHvep2, i_STHvep3
        **/
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensorHessian(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        ;}
    break;

  case 148:
#line 4344 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) Input image
            (5) Numerical expression: sigma, Gaussian standard deviation
            (7) Numerical expression: beta, Hessian matrix coefficient
            (9) IMAGE: mask of the places to compute the tensor
        Description:
            Computation of a Tensor that combines the standard
            gradient based structure tensor and the square
            of the Hessian matrix
            Computes eigenvalues and eigenvectors of the tensor
            and saves them in images:
            i_STHvap1, i_STHvap2, i_STHvap3
            i_STHvep1, i_STHvep2, i_STHvep3
        **/
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_StructureTensorHessian(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        ;}
    break;

  case 149:
#line 4370 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) Input image
            (5) Numerical expression: sigma, Gaussian standard deviation
            (7) Numerical expression: beta, Hessian matrix coefficient
            (9) IMAGE: mask of the places to compute the tensor
            (11) NUM: boolean for saving the gradient vector
        Description:
            Computation of a Tensor that combines the standard
            gradient based structure tensor and the square
            of the Hessian matrix
            Computes eigenvalues and eigenvectors of the tensor
            and saves them in images:
            i_STHvap1, i_STHvap2, i_STHvap3
            i_STHvep1, i_STHvep2, i_STHvep3
            i_STHgrad
        **/
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          int save_grad = (int) (yysemantic_stack_[(12) - (11)].adouble);

          Func_StructureTensorHessian(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask.get(), save_grad);
        ;}
    break;

  case 150:
#line 4398 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        ;}
    break;

  case 151:
#line 4409 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Computes the Hessian Matrix of an image.
              Computes eigenvalues and eigenvectors of the tensor
              and saves them in images:
              i_Hvap1, i_Hvap2, i_Hvap3
              i_Hvep1, i_Hvep2, i_Hvep3
              i_Hgrad
            Parameters:
              - input image variable
              - sigma
              - gamma or mask image
          **/

          BasicVariable::ptr param3(driver.var_stack.GetLastBasicVar());
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask;
          float gamma = 0;

          // TODO: wrap HessianMatrix and get rid of this conflict ...
          if (param3.get()) {
            if (param3->IsNumeric())  {
              gamma = param3->GetValueAsDouble();
            } else {
              if (param3->Type()==type_image)  {
                DYNAMIC_CAST_VARIABLE(InrImage,param3,maskvar) 
                mask = InrImage::ptr(maskvar->Pointer());
              }
              else
                driver.err_print("HessianMatrix \t wrong type of parameter.");
            }
          }

          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 0,   // gamma
                 mask.get()  // mask
                 );
        ;}
    break;

  case 152:
#line 4452 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Computes the Hessian Matrix in 3D
          Parameters:
            - input image
            - Gaussian kernel standard deviation
            - Gamma normalization parameter
            - Mask image
        **/
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask.get()  // mask
                 );
        ;}
    break;

  case 153:
#line 4474 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3)  input image
          (5)  expr: Gaussian standard deviation
          (7)  expr: normalization parameter gamma
          (9)  choose for 1st eigenvalue/eigenvector
          (11) choose for 1st eigenvalue/eigenvector
          (13) choose for 1st eigenvalue/eigenvector
          (15) choose for gradient vector


        Description:
            Compute information for local first and second order derivatives
         **/
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Derivatives(im.get(),
               varim->Name().c_str(),
               (yysemantic_stack_[(16) - (5)].adouble),   // sigma
               (yysemantic_stack_[(16) - (7)].adouble),   // gamma
               NULL,
               (int)(yysemantic_stack_[(16) - (9)].adouble),   // 1st eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(16) - (11)].adouble),  // 2nd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(16) - (13)].adouble),  // 3rd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(16) - (15)].adouble)  // Gradient vector?
               );
        ;}
    break;

  case 154:
#line 4503 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage,varim,im);

          Func_Derivatives(im.get(),
               varim->Name().c_str(),
               (yysemantic_stack_[(18) - (5)].adouble),   // sigma
               (yysemantic_stack_[(18) - (7)].adouble),   // gamma
               mask.get(),  // mask
               (int)(yysemantic_stack_[(18) - (9)].adouble),   // 1st eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (11)].adouble),   // 2nd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (13)].adouble),   // 3rd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (15)].adouble)   // Gradient vector?
               );
        ;}
    break;

  case 155:
#line 4521 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_HessianVap(im.get(),
              varim->Name().c_str(),
              (yysemantic_stack_[(12) - (5)].adouble),   // sigma
              (yysemantic_stack_[(12) - (7)].adouble),   // gamma
              mask.get(),
              (int) (yysemantic_stack_[(12) - (11)].adouble) // eigenvalue number
              );
        ;}
    break;

  case 156:
#line 4535 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 157:
#line 4546 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          Variable<InrImage>::ptr  varim6( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(18) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               varim4 ->Pointer().get(),
               varim5 ->Pointer().get(),
               varim6 ->Pointer().get(),
               mask.get()  // mask
               );
        ;}
    break;

  case 158:
#line 4572 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

          Variable<InrImage>::ptr  varim6( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(16) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               varim4 ->Pointer().get(),
               varim5 ->Pointer().get(),
               varim6 ->Pointer().get(),
               NULL
               );
        ;}
    break;

  case 159:
#line 4598 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());

          Func_Eigen2D(
               (char*) (yysemantic_stack_[(12) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               mask.get()  // mask
               );
        ;}
    break;

  case 160:
#line 4617 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          Func_Eigen2D(
               (char*) (yysemantic_stack_[(10) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               NULL
               );
        ;}
    break;

  case 161:
#line 4631 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 162:
#line 4637 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 163:
#line 4643 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    ;}
    break;

  case 164:
#line 4654 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 165:
#line 4660 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    ;}
    break;

  case 166:
#line 4668 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        (5) boolean, 0 little endianness, 1 big endianness

      Description:
        Forces the endianness of the image, usually before writting it to a file.
        If the endianness is different from the one of the architecture, the bytes
        are swapped before writting, and there are swapped back after.
    **/
      GET_VARSTACK_VALUE(InrImage, im);
      ((amimage*) (*(im)) )->SetEndianness((AMIENDIANNESS)(int)(yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 167:
#line 4683 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    ;}
    break;

  case 168:
#line 4692 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
                varim1->Pointer().get(),
                varim2->Pointer().get(),
                varim3->Pointer().get());
    ;}
    break;

  case 169:
#line 4703 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description: dispatches the given number of events
      **/
      int nb_event;

      nb_event = 0;
      while (nb_event<(int)(yysemantic_stack_[(4) - (3)].adouble)) {
        if (GB_wxApp->Pending()) {
          GB_wxApp->Dispatch();
        }
        nb_event++;
      } // end while

    ;}
    break;

  case 170:
#line 4720 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description: dispatch the given number of events
      **/
      int nb_event;

      nb_event = 0;
      while (nb_event<(int)(yysemantic_stack_[(4) - (3)].adouble)) {
        if (GB_wxApp->Pending()) {
          GB_wxApp->Dispatch();
        }
        nb_event++;
      } // end while

    ;}
    break;

  case 171:
#line 4736 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) IMAGE: 1D image to plot, where the voxel size in X is used,
            if 2D image, plot several functions, one per line
            (5) String: plot title
            (7) NUM: delay
        Description:
            Plots a 1D image using gnuplot.
        **/
      GET_VARSTACK_VALUE(InrImage, image);
      float* tabx;
      float* taby;
      GnuPlot   gnuplot;
      int x,num_courbe;
      std::string name;

      tabx = new float[image->_tx];
      taby = new float[image->_tx];

      for (int y=0; y<image->DimY(); y++) {
        Pour(x,0,image->_tx-1)
          tabx[x] = image->SpacePosX(x);
          taby[x] = (*image)(x,y,0);
          //cout << boost::format("%1%,%2% --> %3%")%x%y%taby[x] << endl;
        FinPour
        name =  (boost::format("%s_%02d")%(yysemantic_stack_[(8) - (5)].astring)%y).str();
        num_courbe = gnuplot.AddCourbe( image->_tx, tabx, taby, name.c_str());
      }

      name =  (boost::format("%s.gnuplot")%(yysemantic_stack_[(8) - (5)].astring)).str();
      gnuplot.XPlot(name.c_str(),(int)(yysemantic_stack_[(8) - (7)].adouble));

      delete [] tabx;
      delete [] taby;
      delete [] (yysemantic_stack_[(8) - (5)].astring);
    ;}
    break;

  case 172:
#line 4774 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      cerr << "Feature not available, needs to be updated ! " << endl;
      /*
            InrImage::ptr   image = *(InrImage::ptr*) $3->Pointer();
            Histogramme* histo;
      
            histo = new Histogramme(GB_main_window,"histo",
                        image.get(),
                        CREATE_TOPLEVEL_SHELL);
      */
      ;}
    break;

  case 173:
#line 4792 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3)  IMAGE1: image to change
            (5)  IMAGE2: input image
            (7)  expression: step x
            (9)  expression: position x
            (11) expression: step y
            (13) expression: position y
            (15) expression: step z
            (17) expression: position z

        Description:
            Pads the output image (IMAGE1) using the input image (IMAGE2),
            starting from position (posx,posy,posz) in IMAGE1,
            tries to fill all the values of IMAGE2 with a voxel lattice of size
            (step x, step y, step z).
            Works for scalar or vectorial images, both images must be of the same
            type (scalar or vectorial).
        **/

            int step_x = (int) (yysemantic_stack_[(18) - (7)].adouble);
            int step_y = (int) (yysemantic_stack_[(18) - (11)].adouble);
            int step_z = (int) (yysemantic_stack_[(18) - (15)].adouble);
        int pos_x  = (int) (yysemantic_stack_[(18) - (9)].adouble);
        int pos_y  = (int) (yysemantic_stack_[(18) - (13)].adouble);
        int pos_z  = (int) (yysemantic_stack_[(18) - (17)].adouble);

      // pad the first image with the second one
      //
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

      Func_Pad(
        varim1->Pointer().get(),
        varim2->Pointer().get(),
           step_x,step_y,step_z,
           pos_x,pos_y,pos_z);


        ;}
    break;

  case 174:
#line 4835 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    ;}
    break;

  case 175:
#line 4841 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    ;}
    break;

  case 176:
#line 4846 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    ;}
    break;

  case 177:
#line 4851 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    ;}
    break;

  case 178:
#line 4857 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        ;}
    break;

  case 179:
#line 4864 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        ;}
    break;

  case 180:
#line 4870 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        ;}
    break;

  case 181:
#line 4877 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        ;}
    break;

  case 182:
#line 4882 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        ;}
    break;

  case 183:
#line 4887 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        ;}
    break;

  case 184:
#line 4898 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim7(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim6(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

          InrImage::ptr im1    (varim1->Pointer());
          InrImage::ptr im2    (varim2->Pointer());
          InrImage::ptr u      (varim3->Pointer());
          InrImage::ptr v      (varim4->Pointer());
          InrImage::ptr corr   (varim5->Pointer());
          InrImage::ptr conf_x (varim6->Pointer());
          InrImage::ptr conf_y (varim7->Pointer());
          int initx= (int) (yysemantic_stack_[(30) - (17)].adouble);
          int inity= (int) (yysemantic_stack_[(30) - (19)].adouble);
          int displx= (int) (yysemantic_stack_[(30) - (21)].adouble);
          int disply= (int) (yysemantic_stack_[(30) - (23)].adouble);
          int sizex= (int) (yysemantic_stack_[(30) - (25)].adouble);
          int sizey= (int) (yysemantic_stack_[(30) - (27)].adouble);
          int deform = (int) (yysemantic_stack_[(30) - (29)].adouble);
      
          amiOpticFlowCorrelation2D(
            im1.get(),
            im2.get(),
            u.get(),
            v.get(),
            corr.get(),
            conf_x.get(),
            conf_y.get(),
            initx,inity,
            displx,disply,sizex,sizey,deform);
        ;}
    break;

  case 185:
#line 4938 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,v); // x component of the flow
        GET_VARSTACK_VALUE(InrImage,u); // y component of the flow
        GET_VARSTACK_VALUE(InrImage,im2);
        GET_VARSTACK_VALUE(InrImage,im1);
        float     sigma = (yysemantic_stack_[(24) - (7)].adouble);
        float     T     = (yysemantic_stack_[(24) - (9)].adouble);
        float     alpha = (yysemantic_stack_[(24) - (11)].adouble);
        long      dtype = (long) (yysemantic_stack_[(24) - (13)].adouble);      /* type of smoothness term */
        float     quantile = (yysemantic_stack_[(24) - (15)].adouble);          /* isotropy fraction */
        float     ht       = (yysemantic_stack_[(24) - (17)].adouble);          /* time step size */
        int       Niter    = (int)  (yysemantic_stack_[(24) - (23)].adouble);   /* Number of Iterations for Gauss-Seidel */

        amiOpticFlowVariational2D(
          im1.get(),
          im2.get(),
          sigma,T,alpha,dtype,quantile,ht,
          u.get(),
          v.get(),
          Niter);

        ;}
    break;

  case 186:
#line 4989 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) size of the 3D arrow basis (def: 0.05)
          (5) size of the 3D arrow head (def: 0.1)
          (7) position of the 3D arrow (def: 0.85)

        Description:
          Parameters for 3D arrows created by CreateVectors() when the vector style is 1.
          Each arrow is composed of 2 tetrahedra:
            - the basis size in proportion to the arrow size is given by the 1st parameter,
            - the head size by the 2nd parameter,
            - the lower position of the head along the arrow by the 3rd parameter.
        **/
          AMIFluid::Func_SetArrowParameters((float)(yysemantic_stack_[(8) - (3)].adouble),(float)(yysemantic_stack_[(8) - (5)].adouble),(float)(yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 187:
#line 5011 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        ;}
    break;

  case 188:
#line 5019 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        ;}
    break;

  case 189:
#line 5035 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        ;}
    break;

  case 190:
#line 5040 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }
          ParamList* pl = new ParamList();
          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 191:
#line 5056 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 192:
#line 5074 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }

          ParamList* pl = new ParamList();
          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 193:
#line 5089 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }
          ParamList* pl =  (yysemantic_stack_[(4) - (1)].paramlist);

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 194:
#line 5104 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description: it is now a new reference to the variable, so basically similar to &variable (should be removed?)...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }
          ParamList* pl(new ParamList);
          BasicVariable::ptr newvar(var->NewCopy());
          if (newvar.get()) {
            newvar->Rename("Param0");
            pl->AddParam(newvar);
            (yyval.paramlist) = pl;
          } else {
            driver.error(boost::format("Could not copy parameter 0 variable expression !").str().c_str());
            YYABORT;
          }
        ;}
    break;

  case 195:
#line 5125 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description: it is now a new reference to the variable, so basically similar to &variable (should be removed?)...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          BasicVariable::ptr newvar(var->NewCopy());
          if (newvar.get()) {
            newvar->Rename(paramname.c_str());
            pl->AddParam(newvar);
            (yyval.paramlist) = pl;
          } else {
            driver.error((boost::format("Could not copy parameter %1% variable expression !") % pl->GetNumParam()).str().c_str());
            YYABORT;
          }
        ;}
    break;

  case 196:
#line 5149 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 197:
#line 5155 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 198:
#line 5164 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 199:
#line 5171 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 200:
#line 5178 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 201:
#line 5201 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 202:
#line 5208 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 203:
#line 5215 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 204:
#line 5222 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 205:
#line 5247 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
    ;}
    break;

  case 206:
#line 5252 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      char* res;
      //printf("expr_string=%s*\n",$3);
      //printf("expr=%f*\n",$5);
      res = new char[strlen((yysemantic_stack_[(6) - (3)].astring))+20];
      sprintf(res,(yysemantic_stack_[(6) - (3)].astring),(yysemantic_stack_[(6) - (5)].adouble));
      //          res[strlen($3)]=0;
      delete [] (yysemantic_stack_[(6) - (3)].astring);
      //printf("res=%s*\n",res);
      (yyval.astring)=res;
    ;}
    break;

  case 207:
#line 5333 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      long min,hour;
      float sec;

      driver.IP_time.Fin();
      driver.IP_time.AddCumul();
      driver.IP_time.GetCumul(hour,min,sec);
      std::string res;
      if (hour>0) {
        res = (boost::format("%3d h %2d min %2d sec")%(int)hour
                        %(int)min %(int)sec).str();
      } else
        res = (boost::format("%2d min %2d sec")
                        %(int)min %(int)sec).str();
        if (min>0) {
        } else
          res = (boost::format("%2.2f sec") %sec).str();

      char* reschar = new char[res.size()+1];
      strcpy(reschar,res.c_str());
      (yyval.astring)= reschar;
    ;}
    break;

  case 208:
#line 5356 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    ;}
    break;

  case 209:
#line 5362 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the variable as a string
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      char* resstr = (char*) var->Name().c_str();
      char* res = new char[strlen(resstr)+1];
      strcpy(res,resstr);
      (yyval.astring)= res;
    ;}
    break;

  case 210:
#line 5374 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the object instance to which this variable belongs. If this variable does not belong to an object, returns an empty string.
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      boost::shared_ptr<Variables> context = var->GetContext();
      if (context.get()) {
        char* res = new char[strlen(context->GetName().c_str())+1];
        strcpy(res,context->GetName().c_str());
        (yyval.astring)= res;
      } else {
        char* empty_string;
        empty_string = new char[1];
        empty_string[0] = '\0';
        (yyval.astring) = empty_string;
      }
    ;}
    break;

  case 211:
#line 5394 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    ;}
    break;

  case 212:
#line 5427 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          ;}
    break;

  case 215:
#line 5442 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      ADD_VARSTACK_FLOAT((yysemantic_stack_[(1) - (1)].adouble))
    ;}
    break;

  case 216:
#line 5446 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      ADD_VARSTACK_FLOAT(GB_argc-GB_num_arg_parsed)
    ;}
    break;

  case 217:
#line 5454 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      ADD_VARSTACK_FLOAT(driver.yyiplineno)
    ;}
    break;

  case 218:
#line 5462 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      ADD_VARSTACK_FLOAT(3.14159265358979323846)
    ;}
    break;

  case 219:
#line 5471 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) input_image
        (3) x
        (5) y

        Description:
        returns the image value at pixel (x,y,z=0) by default

        return:
        float variable
        **/
      GET_VARSTACK_VALUE(InrImage, im);
      ADD_VARSTACK_FLOAT((*im)((int) (yysemantic_stack_[(6) - (3)].adouble),(int) ( (yysemantic_stack_[(6) - (5)].adouble))));
    ;}
    break;

  case 220:
#line 5488 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position value are rounded to the closest integer
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val=(*im)((int) round((yysemantic_stack_[(8) - (3)].adouble)),
          (int) round( (yysemantic_stack_[(8) - (5)].adouble)), 
          (int) round((yysemantic_stack_[(8) - (7)].adouble)));
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 221:
#line 5504 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position using linear interpolation
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val=im->InterpLinIntensite(
          (yysemantic_stack_[(10) - (5)].adouble),
          (yysemantic_stack_[(10) - (7)].adouble), 
          (yysemantic_stack_[(10) - (9)].adouble));
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 222:
#line 5521 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      same as image(expr,expr,expr;expr)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
          Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        val=(*im)((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                    (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr,expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 223:
#line 5540 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
          Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        val=(*im)((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr;expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 224:
#line 5558 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 2D  position. ( z component set to 0)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si (im->CoordOK((int) (yysemantic_stack_[(8) - (3)].adouble),   (int (yysemantic_stack_[(8) - (5)].adouble)),   0  )
        Et ((int) (yysemantic_stack_[(8) - (7)].adouble) >=0) Et ((int)(yysemantic_stack_[(8) - (7)].adouble) <im->GetVDim())) Alors
        val=(*im)((int) (yysemantic_stack_[(8) - (3)].adouble),(int) (yysemantic_stack_[(8) - (5)].adouble),0, (int) (yysemantic_stack_[(8) - (7)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr;expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 225:
#line 5574 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 1D  position. (y and z components set to 0)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si im->CoordOK((int) (yysemantic_stack_[(6) - (3)].adouble),   0,   0  )
        Et ((int) (yysemantic_stack_[(6) - (5)].adouble) >=0) Et ((int)(yysemantic_stack_[(6) - (5)].adouble) <3) Alors
        val=(*im)((int) (yysemantic_stack_[(6) - (3)].adouble),0,0, (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Sinon
        driver.err_print("var_image(expr;expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 226:
#line 5590 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimX();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 227:
#line 5596 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimY();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 228:
#line 5602 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimZ();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 229:
#line 5608 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrX();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 230:
#line 5614 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrY();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 231:
#line 5620 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrZ();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 232:
#line 5626 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeX();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 233:
#line 5632 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeY();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 234:
#line 5638 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeZ();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 235:
#line 5644 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->GetVDim();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 236:
#line 5650 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->IncBuffer();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 237:
#line 5656 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->ValeurBuffer();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 238:
#line 5663 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      float val=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 239:
#line 5672 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_eccentricity(im.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 240:
#line 5679 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      float   resolution = (yysemantic_stack_[(10) - (5)].adouble);
      int     cx = (int) (yysemantic_stack_[(10) - (7)].adouble);
      int     cy = (int) (yysemantic_stack_[(10) - (9)].adouble);
      float    surf_inf[1];
      float    surf_sup[1];
      float    surf_interp[1];
      Point3D point;
      Vect3D<float> v1,v2;
      CalculAireSection* compute_area;

      GET_VARSTACK_VALUE(InrImage, im);

      compute_area = new CalculAireSection( im.get(),
                    resolution);
      compute_area->InitImagesSurf((InrImage*) NULL, (InrImage*) NULL,
                       (InrImage*) NULL, (InrImage*) NULL);
      surf_inf[0]  = surf_sup[0] = surf_interp[0] = 0.0;
      v1.Init( 1.0, 0.0, 0.0);
      v2.Init( 0.0, 1.0, 0.0);
      point.Init( cx,cy,0);

      float val=compute_area->Aire( 0, point, v1, v2,
                  surf_inf, surf_sup, surf_interp);

      ADD_VARSTACK_FLOAT(val);
      delete compute_area;

    ;}
    break;

  case 241:
#line 5710 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_ComputePositiveArea( im.get() );
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 242:
#line 5718 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      float res=Func_PositiveArea(val);
      ADD_VARSTACK_FLOAT(res);
    ;}
    break;

  case 243:
#line 5730 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
          Description:
          returns the of pixels (or voxels) with intensity higher than 0.5

          Parameters:
            (3) image expression

        Keywords:

        See also:
            max, mean, min, median

    **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_count( im.get() );
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 244:
#line 5750 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the average value of an image

             Parameters:
               (3) image expression

            Keywords:

            See also:
                min, max, median

        **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_mean( im.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 245:
#line 5770 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
             Description: 
             returns the maximal value of an image

             Parameters:
               (3) image variable

            Keywords:

            See also:
                min, mean, median

        **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_max( im.get(),NULL);
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 246:
#line 5790 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the position of the maximal value of an image, the 3D position is returned as a single integer value of the position of the vector of the image intensity, where the voxels are ordered in X first,Y second and Z.

             Parameters:
               (3) image expression

            Keywords:

            See also:
                min, mean, median, max

        **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_argmax( im.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 247:
#line 5810 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
            Description:
            returns the minimal value of an image

            Parameters:
              (3) image variable

          Keywords:

          See also:
              max, mean, median

      **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_min( im.get(),NULL);
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 248:
#line 5830 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
            Description:
            returns the median value of an image

            Parameters:
              (3) image expression

          Keywords:

          See also:
              min, max, mean, count

      **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_med( im.get(),0.5,NULL);
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 249:
#line 5850 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the maximal value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             Parameters:
               (3) image expression: mask
               (5) image expression: input

            Keywords:

            See also:
                min, max, mean, median, count

        **/
      GET_VARSTACK_VALUE(InrImage,im);
      GET_VARSTACK_VALUE(InrImage,mask);
      float val=Func_max( im.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 250:
#line 5874 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the minimal value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             Parameters:
               (3) image expression
               (5) image variable

            Keywords:

            See also:
                min, max, mean, median, count

        **/
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage,mask);
      float val=Func_min( im.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 251:
#line 5898 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the median value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             Parameters:
               (3) image expression
               (5) image variable

            Keywords:

            See also:
                min, max, mean, median, count

        **/
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage,mask);
      float val=Func_med( im.get(),0.5,mask.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 252:
#line 5922 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage, mask);
      float val=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 253:
#line 5930 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the average value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             Parameters:
               (3) image expression: defines the Region of Interest
               (5) image expression: image from which to compute the mean intensity value.

            Keywords:

            See also:
                min, max, mean, median, count

        **/
      GET_VARSTACK_VALUE(InrImage,input);
      GET_VARSTACK_VALUE(InrImage,mask);
      float val=Func_mean( input.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 254:
#line 5954 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the maximal value of an image in a region of
             interest

             Parameters:
               (3) image variable
               (5) image expression: the pixels (or voxels) higher than 0.5
               define the Region of Interest

            Keywords:

            See also:
                min, max, mean, median, count

        **/
      GET_VARSTACK_VALUE(InrImage,mask);
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_mean( im.get(), mask.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 255:
#line 5977 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      setlocale(LC_NUMERIC, "C");
      float val=atof((yysemantic_stack_[(4) - (3)].astring));
      ADD_VARSTACK_FLOAT(val);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    ;}
    break;

  case 256:
#line 6008 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
      float val = (*mat)[i][j];
      // create a reference with a smart pointer without deleter ???
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 257:
#line 6018 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description
      **/
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(10) - (5)].adouble);
      int j = (int)(yysemantic_stack_[(10) - (7)].adouble);
      float val  =  ((*mat)[i][j] = (yysemantic_stack_[(10) - (9)].adouble));
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 258:
#line 6030 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (3)].ident));
      float val=0;
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 259:
#line 6040 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      float val=1;
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 260:
#line 6050 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      string: input filename
    Description:
      Check for the existence of the given filename
    **/
      boost::shared_array<char> name( (yysemantic_stack_[(4) - (3)].astring));
      float val = wxFileExists(wxString(name.get(),wxConvUTF8));
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 261:
#line 6062 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returns the value of the pixel format type in float format
      **/
      float val = (int) (yysemantic_stack_[(3) - (1)].aint);
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 262:
#line 6070 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Scans a float number in the given file and based on the
        given formatting expression.
    **/
      float res;
      GET_VARSTACK_VALUE(FILE,file);
      boost::shared_array<char> format( (yysemantic_stack_[(6) - (5)].astring));

      setlocale(LC_NUMERIC, "C");
      fscanf(file.get(),format.get(),&res);
      float val =  res;
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 263:
#line 6086 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(float,val_ptr);
      if (!val_ptr.get()) {
        driver.err_print("needs float variable");
        YYABORT;
      }
      GET_VARSTACK_VALUE(FILE,file);

      float*  var = val_ptr.get();
      setlocale(LC_NUMERIC, "C");
      float val = 0;
      if (var!=NULL) {
        val = fscanf(file.get(),"%f",var);
      } else {
        // TODO: error message here ...
      }
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 264:
#line 6105 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(std::string,st);
      GET_VARSTACK_VALUE(FILE,file);
      setlocale(LC_NUMERIC, "C");
      // not safe, TODO: use iostream or boost for files here ...
      char res[100];
      float val = fscanf(file.get(),"%s",res);
      //string_ptr var( new std::string(res));
      (*st) = res;
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 265:
#line 6135 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var.get())
            if (var->IsNumeric())
              (yyval.adouble)=var->GetValueAsDouble();
            else {
              (yyval.adouble)=var->GetValueAsDouble();
              driver.err_print("Numerical expression from non-numerical variable expression (check for recent changes like i[j] where i and j are images should now be rewritten as i[j.GetExtent] )...");
              YYABORT;
            }
          else {
            driver.err_print("Expression from null variable ...");
            (yyval.adouble) = 0;
          }
        ;}
    break;

  case 266:
#line 6153 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var->Type()==type_image)  {
            driver.var_stack.AddVar(var);
          } else {
            driver.err_print("Expecting an image variable here ... \n");
            YYABORT;
          }
        ;}
    break;

  case 267:
#line 6165 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  This rule is created to avoid changing a lot of code in the process of converting string operation to operations on Variable\<std::string> ...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var->Type()==type_string)  {
            DYNAMIC_CAST_VARIABLE(std::string,var,varstr) 
            char* res;
            res = new char[varstr->Value().length()+1];
            strcpy(res,varstr->Value().c_str());
            (yyval.astring)= res;
          } else {
            driver.err_print("Expecting a string variable here ... \n");
            YYABORT;
          }
        ;}
    break;

  case 268:
#line 6186 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    ;}
    break;

  case 269:
#line 6191 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       ;}
    break;

  case 270:
#line 6195 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       ;}
    break;

  case 271:
#line 6199 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       ;}
    break;

  case 272:
#line 6203 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       ;}
    break;

  case 273:
#line 6207 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       ;}
    break;

  case 274:
#line 6211 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_LONG;
       ;}
    break;

  case 275:
#line 6215 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       ;}
    break;

  case 276:
#line 6219 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       ;}
    break;

  case 277:
#line 6223 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       ;}
    break;

  case 278:
#line 6227 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       ;}
    break;

  case 279:
#line 6231 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      ;}
    break;

  case 281:
#line 6241 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          // TODO: get rid of VAR_ARRAY ...
          GET_VARSTACK_VAR_VAL(VarArray,var,array);
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          BasicVariable::ptr arrayvar = array->GetVar(i);
          if (!array.get()) {
            // create a small image to avoid problems
            InrImage::ptr im (new InrImage(1,1,1,WT_UNSIGNED_CHAR));
            string name = str(format("%s[%d]") % var->Name() % i);
            array->InitElement<InrImage>( i, im, name.c_str());
          }
          driver.var_stack.AddVar(array->GetVar(i));
          //$$=array->GetVar(i).get();
        ;}
    break;

  case 283:
#line 6262 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        InrImage* res = ReadImage(st.get());
        if (!res) YYABORT;
/* deprecated
*/
        else {
          // add to image history
          if (driver.InConsole())
            GB_main_wxFrame->GetImagesHistory()
                           ->AddFileToHistory(wxString::FromAscii(st.get()));
          ADD_VARSTACK(InrImage,res);
        }
      ;}
    break;

  case 284:
#line 6277 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
        (3) STRING EXPRESSION: dicom directory

       Description:
         Reads a dicom file using VTK
       **/
        InrImage::ptr  res;
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));

        res = InrImage::ptr(Func_vtkDicomRead( filename.get()));

        Si (!res.get()) Alors
            driver.err_print("vtkDicomRead() error ... \n");
        FinSi

        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 285:
#line 6297 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
      (3) STRING EXPRESSION: filename in minc format

      Description:
        Reads a file in minc format using vtk reader for MINC.
      **/
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));

        InrImage::ptr res(Func_vtkMINCRead( filename.get()));

        Si (!res.get()) Alors
            driver.err_print("vtkMINCRead() error ... \n");
        FinSi

        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 286:
#line 6332 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskImage(name);
          if (!res) {
            driver.yyiperror(" Need Image \n");
            YYABORT;
          }
          InrImage* res1 = ReadImage((char*)name.c_str()); 
          if (!res1) YYABORT;
          else
            ADD_VARSTACK(InrImage,res1);

          wxFileName filename(GetwxStr(name));
          filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
          wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                              filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                              filename.GetPathSeparator(wxPATH_UNIX)+
                              filename.GetFullName());
          driver.res_print(newname.mb_str());
          driver.res_print("\n");
          inc_cmd = str(format(" \"%1%\" // from browser ") % newname.mb_str());

          if (driver.InConsole()) {
            GB_main_wxFrame->GetConsole()
                            ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
            GB_main_wxFrame->GetImagesHistory()
                           ->AddFileToHistory(newname);
          }
      ;}
    break;

  case 287:
#line 6366 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        ADD_VARSTACK_PTR(InrImage,im);
      ;}
    break;

  case 288:
#line 6373 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
    Parameters:
      (3)  image type
      (5)  dimension in X
      (7)  dimension in Y
      (9)  dimension in Z
      (11) dimension in V: size of the vectors

    Description:
      Creates a new image
      **/
    //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
    InrImage::ptr im( new InrImage( (int) (yysemantic_stack_[(12) - (5)].adouble), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble), (WORDTYPE) (yysemantic_stack_[(12) - (3)].aint)));
    ADD_VARSTACK_PTR(InrImage,im);
    ;}
    break;

  case 289:
#line 6391 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) image type
      (5) dimension in V: size of the vectors
      (7) reference image variable for the size,
            translation and voxel size.

    Description:
      Creates a new image from a reference image
    **/
      GET_VARSTACK_VAR_VAL(InrImage,var,varim);
      WORDTYPE imformat = (WORDTYPE) (yysemantic_stack_[(8) - (3)].aint);
      int vdim   = (int) (yysemantic_stack_[(8) - (5)].adouble);
      string  imname;

      imname = str(format("newimagefrom_%s.ami.gz")
                  % var->Name());

      InrImage::ptr im (new InrImage(imformat,vdim,
                        imname.c_str(),varim.get()));
      ADD_VARSTACK_PTR(InrImage,im);
    ;}
    break;

  case 290:
#line 6482 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the sum of the values of an image along the specified dimension
             0 for X, 1 for Y, 2 for Z

             Parameters:
               (3) image expression
               (5) expr

            Keywords:

            See also:
                min, max, median

        **/
          GET_VARSTACK_VALUE(InrImage,im);
          InrImage* res = NULL;
          int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);
          int i,j,k;
          double sum;
          // check that the image is scalar
          if (im->ScalarFormat()) {
          switch (dim) {
            case 0:
              res = new InrImage(1,im->DimY(),im->DimZ(),1,WT_FLOAT,"sumX.ami.gz");
              for(j=0;j<=im->DimY()-1;j++)
              for(k=0;k<=im->DimZ()-1;k++) {
                sum=0;
                for(i=0;i<=im->DimX()-1;i++)
                sum += (*im)(i,j,k);
                res->BufferPos(0,j,k);
                res->FixeValeur(sum);
              }
            break;
            case 1:
              res = new InrImage(im->DimX(),1,im->DimZ(),1,WT_FLOAT,"sumY.ami.gz");
              for(i=0;i<=im->DimX()-1;i++)
              for(k=0;k<=im->DimZ()-1;k++) {
                sum=0;
                for(j=0;j<=im->DimY()-1;j++)
                sum += (*im)(i,j,k);
                res->BufferPos(i,0,k);
                res->FixeValeur(sum);
              }
            break;
            case 2:
              res = new InrImage(im->DimX(),im->DimY(),1,1,WT_FLOAT,"sumZ.ami.gz");
              for(i=0;i<=im->DimX()-1;i++)
              for(j=0;j<=im->DimY()-1;j++) {
                sum=0;
                for(k=0;k<=im->DimZ()-1;k++)
          sum += (*im)(i,j,k);
                res->BufferPos(i,j,0);
                res->FixeValeur(sum);
              }
            break;
        } // end switch
      } else
      {
        driver.err_print("sum operator only for scalar images ... \n");
    }
      ADD_VARSTACK(InrImage,res);
    ;}
    break;

  case 291:
#line 6548 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    ;}
    break;

  case 292:
#line 6555 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    ;}
    break;

  case 293:
#line 6562 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      ADD_VARSTACK(InrImage,res);
    ;}
    break;

  case 294:
#line 6570 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 295:
#line 6578 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res (Func_OpImage(im.get(),
                NULL,
                NULL,
                (yysemantic_stack_[(6) - (5)].astring)));
      Si (!res.get()) Alors
        driver.err_print("OpImage() erreur ... \n");
      FinSi
  
      ADD_VARSTACK_PTR(InrImage,res);

      ;}
    break;

  case 296:
#line 6594 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_OpImage(im.get(),
              NULL,
              NULL,
              (yysemantic_stack_[(8) - (5)].astring),
              (WORDTYPE) (yysemantic_stack_[(8) - (7)].aint)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    ADD_VARSTACK_PTR(InrImage,res);


      ;}
    break;

  case 297:
#line 6612 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res ( Func_OpImage(
              varim1->Pointer().get(),
              varim2->Pointer().get(),
              NULL,
              (yysemantic_stack_[(8) - (7)].astring)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    ADD_VARSTACK_PTR(InrImage,res);

      ;}
    break;

  case 298:
#line 6630 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_OpImage(im.get(),
              im.get(),
              NULL,
              (yysemantic_stack_[(10) - (7)].astring),
              (yysemantic_stack_[(10) - (9)].aint)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    ADD_VARSTACK_PTR(InrImage,res);

      ;}
    break;

  case 299:
#line 6647 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr  res ( Func_OpImage(
            varim1->Pointer().get(),
            varim2->Pointer().get(),
            varim3->Pointer().get(),
              (yysemantic_stack_[(10) - (9)].astring)));
        Si (!res.get()) Alors
          driver.err_print("OpImage() erreur ... \n");
        FinSi

        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 300:
#line 6665 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr res (Func_OpImage(
            varim1->Pointer().get(),
            varim2->Pointer().get(),
            varim3->Pointer().get(),
              (yysemantic_stack_[(12) - (9)].astring),
              (yysemantic_stack_[(12) - (11)].aint)));
        Si (!res.get()) Alors
          driver.err_print("OpImage() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 301:
#line 6685 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters
          #1 expr_image: input image for the filter
          #2 expr:     standard deviation of the Gaussian kernel
          #3 expr:     derivation order in X coordinates
          #4 expr:     derivation order in Y coordinates
          #5 expr:     derivation order in Z coordinates

        Description:
        Apply a Gaussian filter of specified standard deviation to
        input image and returns a new image.

        Example(s):
        - Convolution with a Gaussian kernel:
        i = Image(FLOAT,10,10,10)
        j = filter(i,1,0,0,0)

     **/
        GET_VARSTACK_VALUE(InrImage,im);

        InrImage::ptr res( Func_Filter( im.get(),
                  (yysemantic_stack_[(12) - (5)].adouble),
                  (int) (yysemantic_stack_[(12) - (7)].adouble),
                  (int) (yysemantic_stack_[(12) - (9)].adouble),
                  (int) (yysemantic_stack_[(12) - (11)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("Filter() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 302:
#line 6718 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float var           = (yysemantic_stack_[(10) - (7)].adouble);
        float lowthreshold  = (yysemantic_stack_[(10) - (9)].adouble);
        //float highthreshold = $11;
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_itkCannyEdgeDetector(  im.get(), var, lowthreshold));
        Si (!res.get()) Alors
          driver.err_print("itk.CannyEdgeDetector() error ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 303:
#line 6731 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 304:
#line 6742 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res (Func_vtkMedianFilter3D(
            im.get(),
            (int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("vtkMedian3D() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 305:
#line 6755 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        driver.err_print("The function AndreDist() has been removed for licence issues! \n");
/*
        InrImage::ptr  in = *(InrImage::ptr*) $3->Pointer();
        InrImage*  res;
        int ok;

        res = new InrImage(WT_FLOAT,"AndreDist.ami.gz", in.get());

        ok = dist_squared( in.get(),res);

        Si !ok Alors
          sprintf(tmp_string,"AndreDist() erreur ... \n");
          driver.err_print(tmp_string);
          delete res;
          res=NULL;
        Sinon
          ADD_VARSTACK_PTR(InrImage,res);
        FinSi
*/
    ;}
    break;

  case 306:
#line 6779 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
        InrImage::ptr res (Func_2DFlux(input.get(),(yysemantic_stack_[(6) - (5)].adouble)));

      Si (res.get()) Alors
        driver.err_print("2DFlux() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 307:
#line 6790 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 308:
#line 6801 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 309:
#line 6811 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 310:
#line 6821 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          (3) IMAGE: input image
          (5) IMAGE: criterion for thinning
          (7) NUM: minimal threshold
          (9) NUM: maximal threshold
          (11) NUM: endpoint type 1: line 2: surface 3: line&surface
        Description:
          Creates a skeleton of the input image,
          the input image is considered binary (positive or 0 values)
          The skeletonization uses simple points.
          Usually the criterion image is an Euclidean distance
          transform to the boundaries of the object, and we
          can set than any point at distance lower than the minimal
          threshold shoud be removed automatically and any point
          at distance higher than the maximum should be kept.
      **/
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res ( Func_Thinning( varim1->Pointer().get(),
                 varim2->Pointer().get(),
                 (yysemantic_stack_[(12) - (7)].adouble),
                 (yysemantic_stack_[(12) - (9)].adouble),
                 (yysemantic_stack_[(12) - (11)].adouble)));

    Si (!res.get()) Alors
      driver.err_print("Skeleton() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 311:
#line 6854 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 312:
#line 6866 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr res ( Func_CircleIntegration(
          varim1 ->Pointer().get(), // gradient
          varim2 ->Pointer().get(),  // first  vector
          varim3 ->Pointer().get(),  // second vector
          (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
          CIRCLE_RESPONSE_MEAN,          // integration type
          varim4->Pointer().get())); // mask

        Si !res.get() Alors
          driver.err_print("CircleInt() error ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 313:
#line 6887 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr res ( Func_CircleIntegration(
        varim1 ->Pointer().get(),  // gradient
        varim2 ->Pointer().get(),  // first  vector
        varim3 ->Pointer().get(),  // second vector
        (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
        CIRCLE_RESPONSE_MEAN,        // integration type
        varim4->Pointer().get())); // mask
      Si !res.get() Alors
        driver.err_print("CircleInt() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 314:
#line 6907 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) gradient
          (5) first vector
          (7) second vector
          (9) radius
          (11) mask
          (13) threshold on standard deviation
          (15) threshold on excentricity

        Description:
          Compute integrations of the gradient vectors along circles
          in a plane defined by 2 vectors,
          with constraints on the standard deviation and the excentricity
          (see pub. Krissian et al. EMBS 2003)
        **/
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr res ( Func_CircleIntSdExc(
          varim1 ->Pointer().get(),  // gradient
          varim2 ->Pointer().get(),  // first  vector
          varim3 ->Pointer().get(),  // second vector
          (float)     (yysemantic_stack_[(16) - (9)].adouble),              // radius
          varim4->Pointer().get(),
          (float) (yysemantic_stack_[(16) - (13)].adouble),
          (float) (yysemantic_stack_[(16) - (15)].adouble),
          2, // pairs mode MEAN
          100, // keeps all points
          CIRCLE_RESPONSE_MEAN));

        Si !res.get() Alors
          driver.err_print("CircleIntSdExc() error ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 315:
#line 6948 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (3) gradient
        (5) first vector
        (7) second vector
        (9) radius
        (11) mask
        (13) threshold on standard deviation
        (15) threshold on excentricity
        (17) Pairs mode (0: MIN,1: MAX or 2:MEAN)
        (19) Highest percentage (Keeps only a percentage of highest boundary values)

      Description:
        Compute integrations of the gradient vectors along circles
        in a plane defined by 2 vectors,
        with constraints on the standard deviation and the excentricity
        (see pub. Krissian et al. EMBS 2003)
        with an additional constraint:
        it integrates half of the circle and takes the
        minimum between opposite values.
      **/
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

      InrImage::ptr res ( Func_CircleIntSdExc(
        varim1 ->Pointer().get(),  // gradient
        varim2 ->Pointer().get(),  // first  vector
        varim3 ->Pointer().get(),  // second vector
        (float)     (yysemantic_stack_[(20) - (9)].adouble),              // radius
        varim4->Pointer().get(),
        (float) (yysemantic_stack_[(20) - (13)].adouble),
        (float) (yysemantic_stack_[(20) - (15)].adouble),
        (int) (yysemantic_stack_[(20) - (17)].adouble),
        (int) (yysemantic_stack_[(20) - (19)].adouble),
        CIRCLE_RESPONSE_MEAN));

      Si !res.get() Alors
        driver.err_print("CircleIntSdExc() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 316:
#line 6994 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

    InrImage::ptr res( Func_LocalExtrema( 
                  varim1->Pointer().get(),  // input image
                  varim2->Pointer().get(),  // first  vector
                  varim3->Pointer().get(),  // second vector
                  varim4->Pointer().get())); // mask
    Si !res.get() Alors
      driver.err_print("LocalExtrema() error ... \n");
    FinSi

    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 317:
#line 7014 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    int samples = (int) (yysemantic_stack_[(12) - (11)].adouble);

    InrImage::ptr res( Func_LocalExtrema( 
                  varim1->Pointer().get(),  // input image
                  varim2->Pointer().get(),  // first  vector
                  varim3->Pointer().get(),  // second vector
                  varim4->Pointer().get(),  // mask
                 samples));                   // number of sample points around the circle

    Si !res.get() Alors
      driver.err_print("LocalExtrema() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 318:
#line 7035 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 319:
#line 7046 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res( Func_NormalSmoothField( 
                    varim1->Pointer().get() , 
                    varim2->Pointer().get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 320:
#line 7060 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res( Func_DirConnectivity( 
        varim1->Pointer().get() ,
        varim2->Pointer().get() ));

    Si res.get() Alors
      driver.err_print("DirConnectivity() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 321:
#line 7076 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
  
      InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      Si (!res.get()) Alors
        driver.err_print("NormGrad() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 322:
#line 7088 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 323:
#line 7099 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 324:
#line 7111 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_Gradient( im.get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 325:
#line 7122 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
        Parameters:
            (3) input image.

        Description:
        Computes a discrete laplacian (sum of second order derivatives),
        in 2D or 3D depending on the image dimension.
    **/
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_Laplacian(im.get()));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 326:
#line 7142 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 327:
#line 7154 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_SecDerGrad2( im.get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 328:
#line 7164 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 329:
#line 7219 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters
        #1 var_image: input image
        #2 expr:      X min
        #3 expr:      Y min
        #4 expr:      Z min
        #5 expr:      X max
        #6 expr:      Y max
        #7 expr:      Z max

      Extract a rectangular subimage from the input image, the subimage
      keeps the information of the translation and it can be put back
      at the same position using putimage command.
      The same operation can also be achieved using the [] operator.

      Example(s):

      - Extract a subimage of size 4x4x4

      i = Image(FLOAT,10,10,10)
      j = subimage(i,5,5,5,8,8,8)

      See also:
        putimage, []

      **/
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_SubImage( im.get(),
                 (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble),
                 (int) (yysemantic_stack_[(16) - (11)].adouble),(int) (yysemantic_stack_[(16) - (13)].adouble),(int) (yysemantic_stack_[(16) - (15)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 330:
#line 7257 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(),
                   (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 331:
#line 7268 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 332:
#line 7278 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si (!res.get()) Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 333:
#line 7290 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(),
                  (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 334:
#line 7301 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 335:
#line 7311 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  initial image
      (5)  total operation size
      (7)  time step
      (9)  minimal intensity
      (11) maximal intensity
    Description:
      Grayscale morphological erosion
      using Brockett and Maragos scheme with a given
      size and time step in voxel units
      minimal and maximal intensities allow to speed up the process
    **/
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 336:
#line 7338 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  initial image
      (5)  total operation size
      (7)  time step
    Description:
      Grayscale morphological opening
      using Brockett and Maragos scheme with a given
      size and time step in voxel units
    **/
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_open( im.get(),
                    (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 337:
#line 7361 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  initial image
      (5)  total operation size
      (7)  time step
      (9)  minimal intensity
      (11) maximal intensity
    Description:
      Grayscale morphological opening
      using Brockett and Maragos scheme with a given
      size and time step in voxel units
      minimal and maximal intensities allow to speed up the process
    **/
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_open( im.get(),
                    (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 338:
#line 7389 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
    InrImage::ptr res ( Func_EDP_close( im.get(),
                   (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 339:
#line 7402 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_close( im.get(),
                   (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 340:
#line 7536 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      //
      // param 1: input image
      // 2: vector field
      // 3: data attachment coeff
      // 4: diffusion coeff
      // 5: number of iterations
      //
      int        nb_iter,i;
      float       error;

      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_InitAnisoGS( varim1->Pointer().get(),
                  1,  1, (yysemantic_stack_[(12) - (7)].adouble));


          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereFlux(varim2->Pointer().get(),(yysemantic_stack_[(12) - (9)].adouble));
      FinPour

      InrImage::ptr res ( Func_AnisoGS_GetOutput());
      Si !res.get() Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
      FinSi
      Func_EndAnisoGS();
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 341:
#line 7571 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          (3)  input image
          (5)  standard deviation for Gaussian smoothing sigma
          (7)  threshold on the gradient magnitude
          (9)  data attachment coefficient
          (11) number of iterations
          (13) number of threads

        Description:
          Anisotropic diffusion filter based on the Flux diffusion paper
          (Krissian, 2002, IEEE TMI).
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float      sigma   = (yysemantic_stack_[(14) - (5)].adouble);
      float      k       = (yysemantic_stack_[(14) - (7)].adouble);
      float      beta    = (yysemantic_stack_[(14) - (9)].adouble);
      int        nb_iter    = (int) (yysemantic_stack_[(14) - (11)].adouble);
      int        nb_threads = (int) (yysemantic_stack_[(14) - (13)].adouble);

      InrImage::ptr  res ( Func_vtkAnisoGS(  im.get(), sigma, k, beta, nb_iter, nb_threads));

      Si !res.get() Alors
        fprintf(stderr,"Func_vtkAnisoGS() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);

    ;}
    break;

  case 342:
#line 7604 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      int        nb_iter,i;
      float       error;

      GET_VARSTACK_VALUE(InrImage, im);
      Func_InitAnisoGS( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));


      Func_SetSmoothedParam(1);

      nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereAnisoGS();
      FinPour
      InrImage::ptr res ( Func_AnisoGS_GetOutput());
      Si !res.get() Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
      FinSi
      Func_EndAnisoGS();
      ADD_VARSTACK_PTR(InrImage,res);

    ;}
    break;

  case 343:
#line 7632 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_InitWeickert( im.get(),
                (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 344:
#line 7646 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_InitWeickertCoherence( im.get(),
                (yysemantic_stack_[(16) - (7)].adouble),  (yysemantic_stack_[(16) - (9)].adouble), (yysemantic_stack_[(16) - (11)].adouble), (yysemantic_stack_[(16) - (13)].adouble), (yysemantic_stack_[(16) - (15)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 345:
#line 7658 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 346:
#line 7670 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(8) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(8) - (7)].adouble);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               0, // Lee mode
               0,  // Yu neighborhood
               NULL)); // no extent

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 347:
#line 7688 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               0, // Lee mode
               0, // Yu neighborhood
               extent.get()));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 348:
#line 7707 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               0, // Lee mode
               neighborhood,
               extent.get()));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 349:
#line 7727 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                0, // Lee function
                0, // Yu neighborhood
                extent.get()
                ));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi

      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 350:
#line 7749 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                0, // Lee function
                neighborhood, // neighborhood size
                extent.get() // bounding box
                ));
      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi

      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 351:
#line 7769 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                2, // Additive mode
                0, // Yu neighborhood
                extent.get() // constant region
                ));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 352:
#line 7788 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt         = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit        = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               1, // Kuan's function
               neighborhood, // Yu neighborhood
               extent.get()));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 353:
#line 7808 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                1, // Kuan's function
                neighborhood, // Yu neighborhood
                extent.get()
                ));
      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 354:
#line 7828 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        (3) var_image: input image
        (5) numerical expression: mode, 0 for Lee Filter, 1: Kuan Filter,
              2: additive, 3: MRI denoising
        (7) numerical expression: dt, time step
        (9) numerical expression: numit, number of iterations
        (11) numerical expression: size of the neighborhood n, neighborhood is
            (2n+1)^N, where N is the dimension of the image domain.
        (13) image extent: area of interest to calculate the noise
              standard deviation, usually a constant area, for MRI denoising: background area

      Description:
        Runs a noise reducing anisotropic diffusion, Lee and Kuan's mode are
        for speckle noise in ultrasound images, additive mode is for additive
        stationary noise and MRI is for MRI style noise. In the case of MRI,
        the filter is designed to run on the square of the image intensity.
      **/
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      int mode = (int) (yysemantic_stack_[(14) - (5)].adouble);
      float dt = (float) (yysemantic_stack_[(14) - (7)].adouble);
      int numit = (int) (yysemantic_stack_[(14) - (9)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(14) - (11)].adouble);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                  mode, // fiter mode
                  neighborhood, //  neighborhood size
                  extent.get()
                  ));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoNRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 355:
#line 7869 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, initim);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int attach = (int) (yysemantic_stack_[(12) - (9)].adouble);
      int scheme = (int) (yysemantic_stack_[(12) - (11)].adouble);
      InrImage::ptr res;

      if (initim->DimZ()==1)
        res = InrImage::ptr( Func_RudinMultiplicative2D( initim.get(),dt,numit,attach, scheme));
      else
        res = InrImage::ptr( Func_RudinMultiplicative3D( initim.get(),dt,numit,attach, scheme));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoRudinMult() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 356:
#line 7891 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Add Gaussian noise with specified mean and variance.
      **/

      GET_VARSTACK_VALUE(InrImage, im);
        AjouteBruit* addnoise;
        float mean;
        float sd;
        char  resname[256];

      mean = (yysemantic_stack_[(8) - (5)].adouble);
      sd   = (yysemantic_stack_[(8) - (7)].adouble);

      sprintf(resname,"%s.noise",im->GetName());
      InrImage::ptr res( new InrImage(WT_FLOAT, resname, im.get()));

      (*res)=(*im);
      addnoise = new AjouteBruit();
      addnoise->AjouteBruitGaussien(res.get(),mean,sd);
      delete addnoise;
      ADD_VARSTACK_PTR(InrImage,res);

    ;}
    break;

  case 357:
#line 7919 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input image
        - rotation center X,Y
        - rotation angle
        - dimensions of the resulting image
      Description:
        - Performs a 2D rotation of the image
    **/

      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_rot2D( im.get(),
                (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble),   // rotation center
                (yysemantic_stack_[(14) - (9)].adouble),       // angle of rotation
                (yysemantic_stack_[(14) - (11)].adouble), (yysemantic_stack_[(14) - (13)].adouble)  // dimension of the new image
                ));

      ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 358:
#line 7940 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new USHORT image that contains
        the X coordinates of the given image.
        This can be very useful for arithmetic
        operations on images.

        Example(s):
        - Putting the image borders in X coordinates at 0:

        x = Xpos(i)
        i = i * (x>2) * ( x < i.tx-3)

        See also:
                Ypos, Zpos
       **/

          int x,y,z;

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   im.get()));
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(x);
          res->IncBuffer();
        FinPour
        FinPour
        FinPour
        //cout << "(*res)(10,20,0)=" << (*res)(10,20,0) << endl;
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 359:
#line 7977 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new USHORT image that contains
        the Y coordinates of the given image.
        This can be very useful for arithmetic
        operations on images.

        Example(s):
        - Putting the image borders in X coordinates at 0:

        y = Ypos(i)
        i = i * (y>2) * ( y < i.tx-3)

        See also:
                Xpos, Zpos
       **/

          int x,y,z;

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   im.get()));
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(y);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 360:
#line 8014 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new USHORT image that contains
        the Z coordinates of the given image.
        This can be very useful for arithmetic
        operations on images.

        Example(s):
        - Putting the image borders in Z coordinates at 0:

        z = Zpos(i)
        i = i * (z>2) * ( z < i.tx-3)

        See also:
                Xpos, Ypos
       **/

          int x,y,z;

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   im.get()));
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(z);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 361:
#line 8051 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new FLOAT vectorial image that contains
        the coordinates of the voxels (/pixels) of the given image.
        The coordinates are given in Real Coordinates (world),
        and are saved as vectors.


        See also:
                Xpos, Ypos, Zpos
       **/

          int x,y,z;

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_FLOAT,3,
                   "tmp_spacepos.inr.gz",
                   im.get()));
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->VectFixeValeurs(res->SpacePosX(x),
                               res->SpacePosY(y),
                               res->SpacePosZ(z));
          res->IncBuffer();
        FinPour
        FinPour
        FinPour
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 362:
#line 8085 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          ADD_VARSTACK(InrImage,InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        ;}
    break;

  case 363:
#line 8091 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          YYABORT;
/*
          ADD_VARSTACK(InrImage,(*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    ;}
    break;

  case 364:
#line 8108 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 365:
#line 8115 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 366:
#line 8122 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);

    ;}
    break;

  case 367:
#line 8130 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 368:
#line 8137 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization image
      (7) maximal time
    Description:
      Runs the fast marching algorithm
     **/

      // 2nd param
      GET_VARSTACK_VALUE(InrImage, init);
      // 1st param
      GET_VARSTACK_VALUE(InrImage, input);

      float   maxtime = (float) (yysemantic_stack_[(8) - (7)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(),  maxtime));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 369:
#line 8161 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization
      (7) maximal time
      (9)  target point X coord
      (11)               Y
      (13)              Z
    Description:
      Runs the fast marching algorithm
     **/

      GET_VARSTACK_VALUE(InrImage,init);
      GET_VARSTACK_VALUE(InrImage,input);
      float   maxtime = (float) (yysemantic_stack_[(14) - (7)].adouble);

      InrImage::ptr res ( Func_vtkFastMarchingTarget( input.get(), init.get(),  maxtime,
              (int) round((yysemantic_stack_[(14) - (9)].adouble)),
              (int) round((yysemantic_stack_[(14) - (11)].adouble)),
              (int) round((yysemantic_stack_[(14) - (13)].adouble))
              ));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 370:
#line 8188 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image
      (5)  initialization
      (7)  mean
      (9)  standard deviation
      (11) maximal time
    Description:
      Runs the fast marching algorithm
     **/

      GET_VARSTACK_VALUE(InrImage,init);
      GET_VARSTACK_VALUE(InrImage,input);
      float   mean    = (float) (yysemantic_stack_[(12) - (7)].adouble);
      float   sd      = (float) (yysemantic_stack_[(12) - (9)].adouble);
      float   maxtime = (float) (yysemantic_stack_[(12) - (11)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 371:
#line 8212 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image
      (5)  initialization
      (7)  mean
      (9)  standard deviation
      (11) maximal time
      (13) initialization type
    Description:
      Runs the fast marching algorithm
     **/
      /* Version without initialization */

      GET_VARSTACK_VALUE(InrImage,init);
      GET_VARSTACK_VALUE(InrImage,input);
      float   mean     = (float) (yysemantic_stack_[(14) - (7)].adouble);
      float   sd       = (float) (yysemantic_stack_[(14) - (9)].adouble);
      float   maxtime  = (float) (yysemantic_stack_[(14) - (11)].adouble);
      int     inittype = (int) (yysemantic_stack_[(14) - (13)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime,inittype));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 372:
#line 8241 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image
      (5)  initialization
      (7)  track image, must be of format unsigned int
      (9)  maximal time
      (11) initialization type
    Description:
      Runs the fast marching algorithm using Dijkstra
      algorithm and tracking back the trajectories
     **/
      /* Version without initialization */

      int     inittype   = (int)   (yysemantic_stack_[(12) - (11)].adouble);
      float   maxtime    = (float) (yysemantic_stack_[(12) - (9)].adouble);
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage, init);
      GET_VARSTACK_VALUE(InrImage, input);

      InrImage::ptr res ( Func_vtkFastMarching(
                  input.get(),
                  init.get(),
                  im.get(),
                  maxtime,inittype));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 373:
#line 8270 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      InrImage::ptr res ( Func_Convolve(im1.get(), im2.get()));
      ADD_VARSTACK_PTR(InrImage,res);

      ;}
    break;

  case 374:
#line 8279 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,mask);
        Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
        Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

        InrImage::ptr res ( Func_ConvolveMask(varim1->Pointer().get(),
                  varim2->Pointer().get(),
                  mask.get()));
        ADD_VARSTACK_PTR(InrImage,res);

      ;}
    break;

  case 375:
#line 8292 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 376:
#line 8299 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          ADD_VARSTACK_PTR(InrImage,res);

        ;}
    break;

  case 377:
#line 8307 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

        float a = (yysemantic_stack_[(12) - (5)].adouble);
        float b = (yysemantic_stack_[(12) - (7)].adouble);
        float c = (yysemantic_stack_[(12) - (9)].adouble);
        float dmax = (yysemantic_stack_[(12) - (11)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2(im.get(), a,b,c,dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        ;}
    break;

  case 378:
#line 8321 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644f, 1.34065f, 1.65849f,
                  dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        ;}
    break;

  case 379:
#line 8333 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644f, 1.34065f, 1.65849f,
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        ;}
    break;

  case 380:
#line 8345 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 381:
#line 8355 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        ;}
    break;

  case 382:
#line 8366 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 383:
#line 8376 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 384:
#line 8386 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 385:
#line 8397 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 386:
#line 8407 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 387:
#line 8418 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) input image variable
          (5) threshold on the image intensity to define
              the object
          (7) minimal distance (<0)
          (9) maximal distance (>0)

        Description:
          Computes an Euclidean distance by propagation
          starting from the object, up to a given distance
          for positive and negative sides.
        **/
      GET_VARSTACK_VALUE(InrImage, im);
        float threshold = (yysemantic_stack_[(10) - (5)].adouble);
        float dmin      = (yysemantic_stack_[(10) - (7)].adouble);
        float dmax      = (yysemantic_stack_[(10) - (9)].adouble);

        printf("threshold = %f \n",threshold);
        InrImage::ptr res ( Func_vtkPropDaniel2(im.get(),
                    threshold,dmin,dmax));

        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 388:
#line 8445 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) image expression: input image
        Description:
            Computes the connected components of the input image,
            considering the isosurface (or isocontour) of intensity value
            0 as the serapation between the components.
            The image background is supposed to have intensity values of 0.
            Returns an image of type INTEGER, and
            creates the following new variables:
                - reorder   : 1D image of the position position of the component
                    if sorted by size. The image size in X is the number of
                    components.
                    You can use image composition to get the image of the biggest
                    component, for example: reorder(cc_result) == 0.
                - inclusion :
                - cc_size   :
                - cc_sign   :
        Example(s):
            To analyze connected component from an isocontour value n for an image i,
            you can call i_cc=CC((FLOAT)i-n)
        **/
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( Func_CC(im.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 389:
#line 8493 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     /**
       Parameters:
         (1) image1: image variable
         (3) image2: variable expression

       Description:
        if variable expression is numerical, get the image value at the corresponding pixel in X, with y=z=0,
        if variable expression is an image:
          Image Composition
          Several Cases:
          - scalar to scalar: transforms the intensity values
              of image 2 using image1 as a lookup table
          - vectorial to scalar
          - scalar to vectorial: returns the values of image1
              at the positions pointed by image2 (positions are converted
              to spatial coordinates)
          - vectorial to vectorial
      **/

      BasicVariable::ptr param1(driver.var_stack.GetLastBasicVar());
      GET_VARSTACK_VALUE(InrImage, im1);

      if (param1.get()) {
        if (param1->IsNumeric()) {
          ADD_VARSTACK_FLOAT((*im1)((int) param1->GetValueAsDouble(),0))
        }
        else
        if (param1->Type()==type_image) {

          // image composition
          // Initialy for applying a RGB colormap to an image
          DYNAMIC_CAST_VARIABLE(InrImage,param1,var_im2)
          //GET_VARSTACK_VALUE(InrImage,ref);
          InrImage::ptr im2( var_im2->Pointer());
          int pos;
    
          InrImage::ptr res ( new InrImage(
                              im1->_format,
                              im1->GetVDim(),
                              "ImComp.ami.gz",
                              im2.get()));
    
          // Several Cases:
          // 1. scalar to scalar
          // 2. scalar to vectorial
          // 3. vectorial to scalar
          // 4. vectorial to vectorial
          if (res->ScalarFormat())
            res->InitImage(0);
          else
            res->InitImage(0,0,0);
    
          // im1 is a 1D image (colormap)
          //
          if (im1->VectorialFormat()&&im2->ScalarFormat()) {
            res->InitBuffer();
            im2->InitBuffer();
    
            Repeter
    
              pos = (int) im2->ValeurBuffer();
              Si (pos<0) AlorsFait pos = 0;
              Si (pos>=im1->DimX()) AlorsFait pos = im1->DimX()-1;
              im1->BufferPos(pos,0,0);
    
              res->VectFixeValeurs(im1->VectValeurBuffer(0),
                      im1->VectValeurBuffer(1),
                      im1->VectValeurBuffer(2));
    
              im2->IncBuffer();
                JusquA Non(res->IncBuffer()) FinRepeter
          } else
          // Greyscale colormap
          if (im1->ScalarFormat()&&im2->ScalarFormat()) {
            res->InitBuffer();
            im2->InitBuffer();
            Repeter
              //pos = (int) im2->ValeurBuffer();
              int pos = (int) (im1->SpaceToVoxelX(im2->ValeurBuffer())+0.5);
              //cout << boost::format(" im2->ValeurBuffer() = %1% pos = %2%")%im2->ValeurBuffer() % pos << endl;
              Si (pos<0)  AlorsFait pos = 0;
              Si (pos>=im1->DimX()) 
                          AlorsFait pos = im1->DimX()-1;
              // convert to space coordinates
              im1->BufferPos(pos,0,0);
              res->FixeValeur(im1->ValeurBuffer());
              im2->IncBuffer();
            JusquA Non(res->IncBuffer()) FinRepeter
          } else
          // Applying a transformation ...
          if (im1->VectorialFormat()&&im2->VectorialFormat()) {
            float posx, posy, posz;
            res->InitBuffer();
            im2->InitBuffer();
            Repeter
              // linear interpolation
              posx =  im1->SpaceToVoxelX(im2->VectValeurBuffer(0));
              posy =  im1->SpaceToVoxelY(im2->VectValeurBuffer(1));
              posz =  im1->SpaceToVoxelZ(im2->VectValeurBuffer(2));
              res->VectFixeValeurs(
                im1->InterpLinIntensite(posx,posy,posz,0),
                im1->InterpLinIntensite(posx,posy,posz,1),
                im1->InterpLinIntensite(posx,posy,posz,2));
              im2->IncBuffer();
            JusquA Non(res->IncBuffer()) FinRepeter
          } else
          // Applying a transformation ...
          if (im1->ScalarFormat()&&im2->VectorialFormat()) {
            float posx, posy, posz;
            res->InitBuffer();
            im2->InitBuffer();
            Repeter
              // linear interpolation
              posx =  im1->SpaceToVoxelX(im2->VectValeurBuffer(0));
              posy =  im1->SpaceToVoxelY(im2->VectValeurBuffer(1));
              posz =  im1->SpaceToVoxelZ(im2->VectValeurBuffer(2));
              res->FixeValeur(im1->InterpLinIntensite(posx,posy,posz));
              im2->IncBuffer();
                JusquA Non(res->IncBuffer()) FinRepeter
          } else
            fprintf(stderr," Image Composition: type of composition not implemented \n");
          ADD_VARSTACK_PTR(InrImage,res);

        }
        else {
          driver.err_print("operator image(expr_var), wrong type of parameter \n");
          YYABORT;
        }
      }


    ;}
    break;

  case 390:
#line 8627 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
       Parameters:
         (3) image: image to compute the histogram
         (5) expr: minimal value
         (7) expr: maximal value
         (9) expr: number of intervals

       Description:
         Compute the histogram of an image and returns it
         as a 1D image
    **/
      GET_VARSTACK_VALUE(InrImage,im);
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      InrImage::ptr res ( Func_Histogram(im.get(),vmin,vmax,nint));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 391:
#line 8648 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      int* numpts;
      int  n;
      float v;
      double total = 0;

      InrImage::ptr res ( new InrImage(nint,1,1,WT_SIGNED_INT));

      numpts = new int[nint];
      Pour(n,0,nint-1)
        numpts[n]=0;
      FinPour

        im->InitBuffer();
      Repeter
        v = im->ValeurBuffer();
        Si v>=vmin Et v<vmax Alors
          n = (int) ((v-vmin)/(vmax-vmin)*nint);
          Si n==nint AlorsFait n=nint-1;
          numpts[n]++;
        FinSi
          JusquA Non(im->IncBuffer()) FinRepeter

      res->InitBuffer();
      Pour(n,0,nint-1)
        total += numpts[n];
        res->FixeValeur(1.0*total/im->Size());
        res->IncBuffer();
          FinPour

      delete [] numpts;

      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 392:
#line 8688 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res;
      if (im->DimZ()>1)
        res = InrImage::ptr( Func_MeanHalfSize(im.get(),3));
      else
        res = InrImage::ptr( Func_MeanHalfSize(im.get(),2));

      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 393:
#line 8699 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 394:
#line 8707 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res(Func_Flip(im,axis));
        ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 395:
#line 8715 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            image to resize
            new dimension in X
            new dimension in Y
            new dimension in Z
            interpolation: 0: nearest neighbor, 1:linear, 2:spline
        Description:
          Image resize
        **/
            int sx = (int) (yysemantic_stack_[(12) - (5)].adouble);
            int sy = (int) (yysemantic_stack_[(12) - (7)].adouble);
            int sz = (int) (yysemantic_stack_[(12) - (9)].adouble);
            unsigned char interpolate=(unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

            GET_VARSTACK_VALUE(InrImage,im);
            InrImage::ptr res ( Func_Resize(im.get(),sx,sy,sz,interpolate));
            ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 396:
#line 8736 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

      FloatMatrix m(4,4);
      m[0][0] =  (yysemantic_stack_[(30) - (7)].adouble);
      m[0][1] =  (yysemantic_stack_[(30) - (9)].adouble);
      m[0][2] =  (yysemantic_stack_[(30) - (11)].adouble);
      m[0][3] =  (yysemantic_stack_[(30) - (13)].adouble);
      m[1][0] =  (yysemantic_stack_[(30) - (15)].adouble);
      m[1][1] =  (yysemantic_stack_[(30) - (17)].adouble);
      m[1][2] =  (yysemantic_stack_[(30) - (19)].adouble);
      m[1][3] =  (yysemantic_stack_[(30) - (21)].adouble);
      m[2][0] =  (yysemantic_stack_[(30) - (23)].adouble);
      m[2][1] =  (yysemantic_stack_[(30) - (25)].adouble);
      m[2][2] =  (yysemantic_stack_[(30) - (27)].adouble);
      m[2][3] =  (yysemantic_stack_[(30) - (29)].adouble);

      InrImage::ptr im1 ( varim1->Pointer());
      InrImage::ptr im2 ( varim2->Pointer());

      InrImage::ptr res ( Func_ReSlice(im1.get(),im2.get(),m));
      ADD_VARSTACK_PTR(InrImage,res);

    ;}
    break;

  case 397:
#line 8762 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      GET_VARSTACK_VALUE(InrImage,input);

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 398:
#line 8773 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 399:
#line 8780 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 400:
#line 8786 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 401:
#line 8792 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      ADD_VARSTACK(InrImage,res);
    ;}
    break;

  case 402:
#line 8799 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**

        Description:
          Compute the altitude to the sea level based on the
          infrared channel.

        Parameters:
          (3) image containing the infrared channel
          (5) image containing 5 coefficients for the computation
              of the temperature and of the altitude,

        Keywords:
          Fluid

        **/
      GET_VARSTACK_VALUE(InrImage,coeff);
      GET_VARSTACK_VALUE(InrImage,input);
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input.get(),coeff.get());
      ADD_VARSTACK(InrImage,res);

    ;}
    break;

  case 403:
#line 8824 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**

        Description:
        Compute the altitude to the sea level based on the
        temperature channel.

        Parameters:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      GET_VARSTACK_VALUE(InrImage,input);
      InrImage::ptr res ( AMIFluid::Func_Temp2Altitudes(input.get()));
      ADD_VARSTACK_PTR(InrImage,res);

    ;}
    break;

  case 404:
#line 8842 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 405:
#line 8849 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**

      Description:
        Trying the slicing procedure to incorporate into the
        image drawing class

      Parameters:
        (3) image to slice
        (5) width orientation 1,2,3 for XY, XZ, ZY
        (7) height orientation
        (9,11,13) cursor position
        (15) expected width
        (17) expected height

        **/
        GET_VARSTACK_VALUE(InrImage,im);

        if (im->_format==WT_UNSIGNED_CHAR) {
          ImageDraw<unsigned char> imdraw;
          imdraw.SetInput((unsigned char*)im->GetData(),im->DimX(),im->DimY(),im->DimZ());
          imdraw.SetVoxelSize(im->VoxSizeX(),im->VoxSizeY(),im->VoxSizeZ());
          imdraw.SetCursorPosition((int)(yysemantic_stack_[(18) - (9)].adouble),(int)(yysemantic_stack_[(18) - (11)].adouble),(int)(yysemantic_stack_[(18) - (13)].adouble));
          imdraw.Apply((int)(yysemantic_stack_[(18) - (5)].adouble),(int)(yysemantic_stack_[(18) - (7)].adouble),(int)(yysemantic_stack_[(18) - (15)].adouble),(int)(yysemantic_stack_[(18) - (17)].adouble));
          // copy to RGB image
          InrImage::ptr res ( new InrImage(imdraw.RGB_width, imdraw.RGB_height, 1, WT_RGB));
          memcpy(res->GetData(),imdraw.RGB_image,imdraw.RGB_width*imdraw.RGB_height*3);
          ADD_VARSTACK_PTR(InrImage,res);
        } else
          fprintf(stderr,"only UCHAR format for now \n");
        ;}
    break;

  case 406:
#line 8882 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input PolyData containing lines to reconstruct
      (5) reference image for reconstruction
      (7) image of the radii associated to each point of the input PolyData (1D image)
    Description:
      Tubular reconstruction based on a set of lines and an estimated radius
      size for each point
    **/
      GET_VARSTACK_VALUE(InrImage,rad);
      GET_VARSTACK_VALUE(InrImage,ref);
      GET_VARSTACK_OBJECT(SurfacePoly,surf)

      InrImage::ptr res ( LineRecons( surf.get(), ref.get(), rad.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 407:
#line 8901 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input line read with ReadCTALine
      (5) name of the file
    Description:
      Reads the radius information and save it to an image,
      returns this image.
    **/
      GET_VARSTACK_OBJECT(SurfacePoly,surf)
      boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));

      InrImage::ptr res ( Func_ReadCTALineRadii( surf.get(), filename.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 409:
#line 8950 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Description: adds a reference to the variable in the stack
    **/
    BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->NewReference());
  ;}
    break;

  case 410:
#line 8959 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        primary_expr_string value to a string variable
      TODO: get completely rid of char* values
    **/
    string_ptr varstr(new std::string((yysemantic_stack_[(1) - (1)].astring)));
    Variable<std::string>::ptr new_var(new Variable<std::string>(varstr));
    driver.var_stack.AddVar(new_var);
  ;}
    break;

  case 419:
#line 8989 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Returns an AMIObject of type WrapClass_VarVector
          containing 4 SurfacePoly variables.
          Kept for compatibility.
       **/
      int initial_size = (yysemantic_stack_[(4) - (3)].adouble);
      BasicVariable::ptr v = CreateVar_SurfacePoly( new SurfacePoly());

      // Now create the vector 
      VarVector* vv = new VarVector();
      if ((initial_size>0)&&(v.get()))  {
        for (int i=0; i<initial_size; i++)
          vv->push_back(v->NewCopy());
      }
      BasicVariable::ptr new_var = CreateVar_VarVector(vv);
      driver.var_stack.AddVar(new_var);
    ;}
    break;

  case 420:
#line 9010 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /** 
      Description:
        The 2 parameters can be either images or numbers,
        for 2 images:
          Returns the image corresponding to the pointwise maximum between 2 images.
        for 2 numbers:
          Returns the maximal value.


      See also:
              min, median
        **/

        BasicVariable::ptr param2(driver.var_stack.GetLastBasicVar());
        BasicVariable::ptr param1(driver.var_stack.GetLastBasicVar());

        if (param1.get()&&param2.get()) {
          if ((param1->IsNumeric())&&(param2->IsNumeric())) {
            double val1 = param1->GetValueAsDouble();
            double val2 = param2->GetValueAsDouble();
            double res = (val1>val2)?val1:val2;
            ADD_VARSTACK_FLOAT(res);
          }
          else
          if ((param1->Type()==type_image)&&(param2->Type()==type_image)) {
            DYNAMIC_CAST_VARIABLE(InrImage,param1,varim1) 
            DYNAMIC_CAST_VARIABLE(InrImage,param2,varim2) 

            InrImage::ptr im1(varim1->Pointer());
            InrImage::ptr im2(varim2->Pointer());
            double val1,val2;
            InrImage::ptr res;
            // TODO: take advantage of temporary images here??
            res = InrImage::ptr(new InrImage( im1->GetFormat(),
                                              im1->GetVDim(),
                                              "max_im_op.ami.gz",
                                              im1.get()));
            (*res) = (*im1);

            // TODO: use image iterator here
            res->InitBuffer();
            im2->InitBuffer();
            Repeter
              val1 = res->ValeurBuffer();
              val2 = im2->ValeurBuffer();
              Si val2>val1 AlorsFait res->FixeValeur(val2);
              im2->IncBuffer();
            JusquA Non(res->IncBuffer())
            FinRepeter
            Variable<InrImage>::ptr new_var(new Variable<InrImage>(res));
            driver.var_stack.AddVar(new_var);
          }
          else {
            driver.err_print("max operator with these types of parameters not available");
            YYABORT;
          }
        }

      ;}
    break;

  case 424:
#line 9159 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          // todo ... 
          // 1. check if identifier belongs to the object
          // 2. if so return corresponding variable
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (3)].ident));
          Variable<AMIObject>::ptr var(driver.var_stack.GetLastVar<AMIObject>());
          if (!var.get()) {
            driver.err_print("operator . (Element selection) is only available for variables of type AMIObject");
            YYABORT;
          }
          AMIObject::ptr object(var->Pointer());

          // here, need to do our own checking ...
          BasicVariable::ptr newvar( 
            object->GetContext()->GetVar(ident->GetName().c_str()));
    
          if  ((!GB_driver.procedure_declaration)&& newvar.get())   {
            //cout << "returning variable" << endl;
            //newvar->display();
            driver.var_stack.AddVar(newvar);
          } else {
            // error message here
            driver.yyiperror("Identifier does not belong to object context \n");
            YYABORT;
            //driver.var_stack.AddVar(BasicVariable::ptr());
          }
        ;}
    break;

  case 425:
#line 9188 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Call to a function, returning a variable
        **/
        //cout << "call to variable T_OP_PAR param_list T_CL_PAR end_instr" << endl;
        // 1. check the variable type
        GET_CHECK_VARSTACK(var)
        ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));

        // TODO: run this with overloading from BasicVariable ...
        if (var->Type()==type_class_member) {
          ///    Call a wrapped C++ class member.
          DYNAMIC_CAST_VARIABLE(WrapClassMember,var, var1);
          BasicVariable::ptr res ((var1->Pointer())->CallMember(param.get()));
          /*
          if (!res.get()) {
            driver.yyiperror("Class member does not return a variable \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);

        } else
        if (var->Type()==type_ami_function) 
        {
          ///    Call a language function with its parameters.
          DYNAMIC_CAST_VARIABLE(AMIFunction,var, var1);
          AMIFunction::ptr f(var1->Pointer());
          BasicVariable::ptr res(driver.yyip_call_function(f,param));
          /* don't be so strict ...
          if (!res.get()) {
            driver.yyiperror("Ami function does not return a variable \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);

        } else
        if (var->Type()==type_c_function) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_varfunction,var, func);
          BasicVariable::ptr  res;
          res = (*func->Pointer())(param.get());
          /*
          if (!res.get()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);
        } else
        if (var->Type()==type_c_procedure) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_procedure,var, func);
          BasicVariable::ptr  res;
          (*func->Pointer())(param.get());
          driver.var_stack.AddVar(res);
        } else
        if (var->Type()==type_c_image_function) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_imagefunction,var, func);
          InrImage::ptr  im((*func->Pointer())(param.get()));
          if (!im.get()) {
            driver.yyiperror(" image function returns NULL \n");
            YYABORT;
          }
          Variable<InrImage>::ptr res(new Variable<InrImage>(im));
          driver.var_stack.AddVar(res);
        } else
        {
          // error message here
          driver.yyiperror("variable is not of a function type \n");
          driver.var_stack.AddVar(BasicVariable::ptr());
        }
      ;}
    break;

  case 426:
#line 9265 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Logical negation (NOT) operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(!(*var));
  ;}
    break;

  case 427:
#line 9273 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix increment operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)++);
  ;}
    break;

  case 428:
#line 9281 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix decrement operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)--);
  ;}
    break;

  case 429:
#line 9289 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Transpose operator, usefull for matrices
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->Transpose());
  ;}
    break;

  case 430:
#line 9341 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Array subscript operator.
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)[var2]);
  ;}
    break;

  case 432:
#line 9355 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Cast operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->BasicCast( (yysemantic_stack_[(4) - (2)].aint)));

  ;}
    break;

  case 433:
#line 9364 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    //cout << "T_SUB  cast_var  " << endl;
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(-(*var));
  ;}
    break;

  case 434:
#line 9370 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(+(*var));
  ;}
    break;

  case 435:
#line 9375 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(++(*var));
  ;}
    break;

  case 436:
#line 9380 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(--(*var));
  ;}
    break;

  case 437:
#line 9385 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sin());
  ;}
    break;

  case 438:
#line 9390 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_cos());
  ;}
    break;

  case 439:
#line 9395 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sqrt());
  ;}
    break;

  case 440:
#line 9400 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_fabs());
  ;}
    break;

  case 441:
#line 9405 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_round());
  ;}
    break;

  case 442:
#line 9410 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_floor());
  ;}
    break;

  case 443:
#line 9415 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_tan());
  ;}
    break;

  case 444:
#line 9420 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_asin());
  ;}
    break;

  case 445:
#line 9425 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_acos());
  ;}
    break;

  case 446:
#line 9430 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_atan());
  ;}
    break;

  case 447:
#line 9435 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_exp());
  ;}
    break;

  case 448:
#line 9440 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_log());
  ;}
    break;

  case 449:
#line 9445 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_ln());
  ;}
    break;

  case 450:
#line 9450 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_norm());
  ;}
    break;

  case 452:
#line 9460 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*var2);
  ;}
    break;

  case 453:
#line 9466 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/var2);
  ;}
    break;

  case 454:
#line 9472 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)%var2);
  ;}
    break;

  case 456:
#line 9483 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res(*var1+var2);
    driver.var_stack.AddVar(res);
  ;}
    break;

  case 457:
#line 9490 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res((*var1)-var2);
    driver.var_stack.AddVar(res);
  ;}
    break;

  case 460:
#line 9505 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<var2);
  ;}
    break;

  case 461:
#line 9511 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>var2);
  ;}
    break;

  case 462:
#line 9517 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<=var2);
  ;}
    break;

  case 463:
#line 9523 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>=var2);
  ;}
    break;

  case 465:
#line 9533 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)==var2);
  ;}
    break;

  case 466:
#line 9539 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)!=var2);
  ;}
    break;

  case 473:
#line 9580 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical AND operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)&&var2);
  ;}
    break;

  case 475:
#line 9593 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical XOR operator, for vectorial images it defines the pointwise vectorial product.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)^var2);
  ;}
    break;

  case 477:
#line 9606 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical OR operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)||var2);
  ;}
    break;

  case 479:
#line 9619 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Operation (cond?a:b) like in C/C++.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->TernaryCondition(var1,var2));
  ;}
    break;

  case 481:
#line 9633 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    //cout << "assignment_var" << endl;
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    if (var1->GetPtrCounter()==1) {
      // TODO: here ...
    }
    driver.var_stack.AddVar((*var1)=var2);
  ;}
    break;

  case 482:
#line 9643 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    //cout << "assignment_var" << endl;
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1).left_assign(var2));
  ;}
    break;

  case 483:
#line 9650 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)+=var2);
  ;}
    break;

  case 484:
#line 9656 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)-=var2);
  ;}
    break;

  case 485:
#line 9662 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*=var2);
  ;}
    break;

  case 486:
#line 9668 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/=var2);
  ;}
    break;

  case 488:
#line 9680 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        ;}
    break;

  case 489:
#line 9691 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix glt;
          GLTransfMatrix* newglt;
  
          printf("GetTransform begin \n");
          newglt = new GLTransfMatrix();
              glt = (varsurfd->Pointer())->GetCanvas()->GetObjectTransform();
          (*newglt) = (glt);
          driver.gltransf_stack.AddMatrix(newglt);
          printf("GetTransform \n");
      ;}
    break;

  case 490:
#line 9705 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      ;}
    break;

  case 491:
#line 9716 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
         GLTransfMatrix* newglt;
         newglt = Func_ReadTransform(filename.get());
         if (newglt!=NULL)
           driver.gltransf_stack.AddMatrix(newglt);
         else {
           fprintf(stderr,"TRANSFORM() Error reading file ...\n");
           driver.err_print("TRANSFORM() Error reading file ...\n");
           driver.gltransf_stack.AddMatrix(NULL);
           //          yyiperror(
           //          YYABORT;
         }
      ;}
    break;

  case 492:
#line 9734 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         FloatMatrix::ptr m( new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble)));
         ADD_VARSTACK_PTR(FloatMatrix,m);
      ;}
    break;

  case 493:
#line 9740 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description: adds a reference to the variable in the stack
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        driver.var_stack.AddVar(var->NewReference());
      ;}
    break;

  case 494:
#line 9749 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
         Inversion of a symmetric matrix
          TODO: make a real inversion, for now it is a tranpose ...
        **/

        BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
        if (var->Type()==type_matrix)  {
          DYNAMIC_CAST_VARIABLE(FloatMatrix,var,varmat) 
          FloatMatrix::ptr res(varmat->Pointer()->Transpose());
          ADD_VARSTACK_PTR(FloatMatrix,res);
        } else {
          driver.err_print("Expecting an matrix variable here ... \n");
          YYABORT;
        }

      ;}
    break;

  case 495:
#line 9894 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage,im);
      surf = Func_isosurf(im,
              (yysemantic_stack_[(6) - (5)].adouble),
              NULL);
      if (surf==NULL) {
        driver.err_print("Isosurface failed!");
        YYABORT;
      }
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 496:
#line 9909 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      SurfacePoly* surf;
      surf = Func_isosurf(im,
              (yysemantic_stack_[(6) - (5)].adouble),
              NULL,
              2);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 497:
#line 9921 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression: input image
        expression:       isosurface threshold
        image variable:   mask
      Description:
        Computed isosurface of the input image with a given threshold within a region
        defined by the mask image.
    **/
      GET_VARSTACK_VALUE(InrImage, mask);
      GET_VARSTACK_VALUE(InrImage, im);
      SurfacePoly* surf;
      surf = Func_isosurf(im,
              (yysemantic_stack_[(8) - (5)].adouble),
              mask.get());
      if (surf==NULL) driver.err_print("Isosurface failed!");
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 498:
#line 9943 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
     Parameters:
        (3) input image
        (5) Gaussian standard deviation
        (7) mask

     Description:
        Computes the centerlines of bright tubular structures
        as zero-crossing of the gradient vector field in the planes
        of the 2 eigenvectors of the Hessian matrix that
        correspond to the lowest and negative eigenvalues
     **/
      GET_VARSTACK_VALUE(InrImage,mask);
      GET_VARSTACK_VALUE(InrImage,im);
      vtkPolyData* vtklines;
      CreeCrest* crestlines;
      SurfacePoly* lines;

      crestlines = Func_IsoLine(im.get(), (yysemantic_stack_[(8) - (5)].adouble), mask.get());
      printf("running conversion to vtkPolyData ...");
      vtklines = (vtkPolyData*) (*crestlines);

      lines = new SurfacePoly(vtklines);
      if (lines == NULL) {
        driver.err_print("IsoLine failed!");
        YYABORT;
      }

      BasicVariable::ptr res(CreateVar_SurfacePoly(lines));
      driver.var_stack.AddVar(res);

      delete crestlines;
    ;}
    break;

  case 499:
#line 9979 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 500:
#line 9988 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)

      newsurf = Func_decimate( varsurf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 501:
#line 9998 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
      surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 502:
#line 10007 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,surf)

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 503:
#line 10017 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,surf)
      SurfacePoly* newsurf;

      newsurf = Func_vtkWindowedSinc( surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      if (newsurf==NULL) {
        driver.err_print("vtkWindowedSinc failed!");
        YYABORT;
      }
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 504:
#line 10031 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 505:
#line 10038 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      SurfacePoly* surf = new SurfacePoly();
      surf->Read(filename.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 506:
#line 10047 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3): input filename (text file)
        Description:
            Reads a line given described in a text file
            format used in the CTA coronary segmentation challenge
        **/
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
        SurfacePoly* surf;
        surf = Func_ReadCTALine(filename.get());
        BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
        driver.var_stack.AddVar(res);
      ;}
    break;

  case 507:
#line 10063 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3): input filename (text file)
            (5) line type:  0: point + radius + standard dev
                            1: point
        Description:
            Reads a line given described in a text file
            format used in the CTA coronary segmentation challenge
        **/
        SurfacePoly* surf;
        boost::shared_array<char> filename( (yysemantic_stack_[(6) - (3)].astring));

        surf = Func_ReadCTALine(filename.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
        driver.var_stack.AddVar(res);
      ;}
    break;

  case 508:
#line 10082 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
        SurfacePoly* surf;

        GET_VARSTACK_VALUE(InrImage, im);
        surf = Func_Skeleton2lines( im.get()  );
  
        if (surf==NULL) {
          driver.err_print("Skeleton2lines() error ... \n");
          YYABORT;
        } else {
          BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
          driver.var_stack.AddVar(res);
        }
    ;}
    break;

  case 509:
#line 10102 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input polydata
    Description:
      Smooth lines based on a simple scheme of heat diffusion
      with data attachment (applied to each coordinate)
      using default parameters of
        smoothing coeff 0.1
        data coeff      0.01
        iterations      10
    **/
      GET_VARSTACK_OBJECT(SurfacePoly,insurf)
      SurfacePoly* surf;

      surf = Func_SmoothLines( insurf.get(),
                      0.1f,
                      0.01f,
                      10);

      if (surf==NULL) {
        driver.err_print("SmoothLines() error ... \n");
        YYABORT;
      } else {
        BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
        driver.var_stack.AddVar(res);
      }
    ;}
    break;

  case 510:
#line 10132 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input polydata
      (5) smoothing coefficient
      (7) data attachment coefficient
      (9) number of iterations
    Description:
      Smooth lines based on a simple scheme of heat diffusion
      with data attachment
    **/
      GET_VARSTACK_OBJECT(SurfacePoly,insurf)
      SurfacePoly* surf;

      surf = Func_SmoothLines( insurf.get(),
                      (yysemantic_stack_[(10) - (5)].adouble),
                      (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble));

      if (surf==NULL) {
        driver.err_print("SmoothLines() error ... \n");
        YYABORT;
      } else {
        BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
        driver.var_stack.AddVar(res);
      }
    ;}
    break;

  case 511:
#line 10161 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,insurf)
      SurfacePoly* surf;

      surf = Func_ResampleLines( insurf.get(),
                     (yysemantic_stack_[(6) - (5)].adouble));

      if (surf==NULL) {
        driver.err_print("ResampleLines() error ... \n");
        YYABORT;
      } else {
        BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
        driver.var_stack.AddVar(res);
      }
    ;}
    break;

  case 512:
#line 10179 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
        - point 1: x,y,z
        - point 2: x,y,z 
      Description:
        Finds the shortest path within the lines of the polydata
    **/
      GET_VARSTACK_OBJECT(SurfacePoly,insurf)
      SurfacePoly* surf;

      surf = Func_shortestpath( insurf.get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath () error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 513:
#line 10205 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) threshold to discard voxels
      (7)  X position of the first point
      (9)  Y position of the first point
      (11) Z position of the first point
      (13) X position of the second point
      (15) Y position of the second point
      (17) Z position of the second point
    Description:
      Finds the shortest path within the image voxels
      where the image intensity values are used to weight the edges of the graph,
      voxels are linked if their intensities are lower than the given threshold
      creates a path between the first and the second points if it exists
    **/
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      surf = Func_shortestpath_image(  im.get(),(yysemantic_stack_[(18) - (5)].adouble),
                                      (yysemantic_stack_[(18) - (7)].adouble), (yysemantic_stack_[(18) - (9)].adouble), (yysemantic_stack_[(18) - (11)].adouble),
                                      (yysemantic_stack_[(18) - (13)].adouble),(yysemantic_stack_[(18) - (15)].adouble),(yysemantic_stack_[(18) - (17)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath_image () error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 514:
#line 10238 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image containing the tracks as indices:
          voxel index of the preceding voxel
      (5) X coord of the starting point
      (7) Y coord of the starting point
      (9) Z coord of the starting point

    Description:
      Creates a path starting at a point in voxel coordinates
      and following the (integer) displacements given by the input vector field
      image
    **/
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      surf = Func_path_from_displ(  im.get(),
          (int) round((yysemantic_stack_[(10) - (5)].adouble)),
          (int) round((yysemantic_stack_[(10) - (7)].adouble)),
          (int) round((yysemantic_stack_[(10) - (9)].adouble))
          );

      Si surf==NULL Alors
        driver.err_print("Func_path_from_displ() error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 515:
#line 10274 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image as a vector field in spatial coordinates
            or as a scalar potential
      (5) time step for the evolution
      (7) maximal Euclidean distance of the path
      (9)  X coord of the starting point (in spatial coord.)
      (11)  Y coord ---
      (13)  Z coord ---
      (15)  X coord of the expected end point (in spatial coord.)
      (17)  Y coord  ---
      (19)  Z coord  ---

    Description:
      Creates a path starting at a point in spatial coordinates
      and following the displacements given by the input vector field
      image
      if the input is scalar the corresponding vector field is computed
      from its gradient by local linear interpolation
      the tracking stops in one of the following cases:
        - the maximal distance is reached
        - the closest voxel to the current location has a negative intensity
        - the current gradient is very low
    **/
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      double start[3] = {(yysemantic_stack_[(20) - (9)].adouble),(yysemantic_stack_[(20) - (11)].adouble),(yysemantic_stack_[(20) - (13)].adouble)};
      double end[3] = {(yysemantic_stack_[(20) - (15)].adouble),(yysemantic_stack_[(20) - (17)].adouble),(yysemantic_stack_[(20) - (19)].adouble)};
      surf = Func_path_from_vectfield(  im,
                                        start,end,
                                        (yysemantic_stack_[(20) - (5)].adouble), (yysemantic_stack_[(20) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_path_from_vectfield() error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 516:
#line 10320 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image as a vector field in spatial coordinates
            or as a scalar potential
      (5) time step for the evolution
      (7) maximal Euclidean distance of the path
      (9)  X coord of the starting point (in spatial coord.)
      (11)  Y coord ---
      (13)  Z coord ---

    Description:
      Creates a path starting at a point in spatial coordinates
      and following the displacements given by the input vector field
      image
      if the input is scalar the corresponding vector field is computed
      from its gradient by local linear interpolation
      the tracking stops in one of the following cases:
        - the maximal distance is reached
        - the closest voxel to the current location has a negative intensity
        - the current gradient is very low
    **/
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      double start[3] = {(yysemantic_stack_[(14) - (9)].adouble),(yysemantic_stack_[(14) - (11)].adouble),(yysemantic_stack_[(14) - (13)].adouble)};
      surf = Func_path_from_vectfield(  im,
                                        start,
                                        (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_path_from_vectfield() error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 517:
#line 10358 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 518:
#line 10367 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**

        Description:
      creates a flat triangulates mesh from the image domain,
      discarding pixels with null intensity.

        Parameters:
        (3) input image
        (5) triangle orientation:
            1: following X^Y
            other value: following -X^Y

          **/
      GET_VARSTACK_VALUE(InrImage,im);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble) );
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 519:
#line 10389 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(),minth,maxth);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 520:
#line 10400 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);

      surf = AMIFluid::Func_vtkCreateFlatMesh(im.get(),minth,maxth);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 521:
#line 10411 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          CreateVolume creates a close surface composed of 2 surfaces:
          a top and a bottom, where each surface is calculated by converting
          the pixel position of 3D positions based on the 2 last parameters.
          It scans all the points of the 2D image,
          and uses their coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - the 2 last parameters are 2D images of 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        Parameters:
        (3) input surface
        (5) minimal intensity value of the region of interest
        (7) maximal intensity value of the region of interest
        (9) 3D vector field image for the lower positions
        (11) 3D vector fiels image for the higher positions

       See also:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      GET_VARSTACK_VALUE(InrImage,highpos);
      GET_VARSTACK_VALUE(InrImage,lowpos);
      GET_VARSTACK_VALUE(InrImage,input);
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(12) - (5)].adouble);
      float maxth = (yysemantic_stack_[(12) - (7)].adouble);

      surf = AMIFluid::Func_CreateVolume(input.get(), minth, maxth, lowpos.get(), highpos.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 522:
#line 10447 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          CreateVolume creates a closed surface composed of 2 surfaces:
          a top and a bottom, where each surface is calculated by converting
          the pixel position of 3D positions based on the 2 last parameters.
          It scans all the points of the 2D image,
          and uses their coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - the 2 last parameters are 2D images of 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        Parameters:
        (3) input surface
        (5) minimal intensity value of the region of interest
        (7) maximal intensity value of the region of interest
        (9) 3D vector field image for the lower positions
        (11) 3D vector fiels image for the higher positions
        (13) RGB image to color the top surface or NULL if not used
        (15) alpha opacity value (in [0,1], 0 is fully transparent)


       See also:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      GET_VARSTACK_VALUE(InrImage,colors);
      GET_VARSTACK_VALUE(InrImage,highpos);
      GET_VARSTACK_VALUE(InrImage,lowpos);
      GET_VARSTACK_VALUE(InrImage,input);
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(16) - (5)].adouble);
      float maxth = (yysemantic_stack_[(16) - (7)].adouble);
      float alpha = (yysemantic_stack_[(16) - (15)].adouble);

      surf = AMIFluid::Func_CreateVolume(input.get(), minth, maxth, 
                                          lowpos.get(), highpos.get(), colors.get(), alpha);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 523:
#line 10489 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale
          #7 expr:              type

        Description:
        Creates a 3D vector field for visualization of the displacement of clouds
        between times t1 and t2.
        description of the input parameters:
        - altitudes1:    scalar image,    altitudes of the clouds at time t1
        - displacement:  vectorial image, displacement as a 2D vector field
        - altitudes2:    scalar image,    altitudes of the clouds at time t2
        - stepx:         spacing in pixels between successive vectors in X direction
        - stepy:         spacing in pixels between successive vectors in Y direction
        - scale:         scaling of the vectors
        - type:          0 for Altantic, 1 for Africa.

        Example(s):

        vects = CreateVectors(alt1,displ,alt2,8,8,3,1)


        See also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/
      GET_VARSTACK_VALUE(InrImage,alt2);
      GET_VARSTACK_VALUE(InrImage,displ);
      GET_VARSTACK_VALUE(InrImage,alt1);
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      float scale = (yysemantic_stack_[(16) - (13)].adouble);
      int   type  = (int) (yysemantic_stack_[(16) - (15)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),displ.get(),alt2.get(), 
                                          stepx, stepy, scale, type);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 524:
#line 10535 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale
          #7 expr:              type
          expr:                 vector_style (in {0,1})

        Description:
        Creates a 3D vector field for visualization of the displacement of clouds
        between times t1 and t2.
        description of the input parameters:
        - altitudes1:    scalar image,    altitudes of the clouds at time t1
        - displacement:  vectorial image, displacement as a 2D vector field
        - altitudes2:    scalar image,    altitudes of the clouds at time t2
        - stepx:         spacing in pixels between successive vectors in X direction
        - stepy:         spacing in pixels between successive vectors in Y direction
        - scale:         scaling of the vectors
        - type:          0 for Altantic, 1 for Africa.
        - vector style   0: simple line, 1: 3D vector composed of 2 tetrahedra

        Example(s):

        vects = CreateVectors(alt1,displ,alt2,8,8,3,1,1)


        See also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/
      GET_VARSTACK_VALUE(InrImage,alt2);
      GET_VARSTACK_VALUE(InrImage,displ);
      GET_VARSTACK_VALUE(InrImage,alt1);
      int stepx   = (int) (yysemantic_stack_[(18) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(18) - (11)].adouble);
      float scale = (yysemantic_stack_[(18) - (13)].adouble);
      int   type   = (int) (yysemantic_stack_[(18) - (15)].adouble);
      int   style  = (int) (yysemantic_stack_[(18) - (17)].adouble);
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),
          displ.get(),
          alt2.get(), stepx, stepy, scale, type,style);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 525:
#line 10585 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale

        Description:
        Creates a 3D vector field for visualization of the displacement of clouds
        between times t1 and t2.
        description of the input parameters:
        - altitudes1:    scalar image,    altitudes of the clouds at time t1
        - displacement:  vectorial image, displacement as a 2D vector field
        - altitudes2:    scalar image,    altitudes of the clouds at time t2
        - stepx:         spacing in pixels between successive vectors in X direction
        - stepy:         spacing in pixels between successive vectors in Y direction
        - scale:         scaling of the vectors

        Example(s):

        vects = CreateVectors(alt1,displ,alt2,8,8,3)


        See also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/
      GET_VARSTACK_VALUE(InrImage,alt2);
      GET_VARSTACK_VALUE(InrImage,displ);
      GET_VARSTACK_VALUE(InrImage,alt1);
      int stepx   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (11)].adouble);
      float scale = (yysemantic_stack_[(14) - (13)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),displ.get(),alt2.get(), stepx, stepy, scale);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 526:
#line 10627 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) expr_image:        displacement field in voxel coordinates
          (5) expr:              spacing between vectors in X direction
          (7) expr:              spacing between vectors in Y direction
          (9) expr:              spacing between vectors in Z direction
          (11) expr:             scale
          (13) vector style   0: simple line, 1: 3D vector composed of 2 tetrahedra

        Description:
        Creates a 3D vector field for visualization.

      **/
      GET_VARSTACK_VALUE(InrImage,displ);
      int stepx   = (int) (yysemantic_stack_[(14) - (5)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (7)].adouble);
      int stepz   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      float scale = (yysemantic_stack_[(14) - (11)].adouble);
      int style = (int) (yysemantic_stack_[(14) - (13)].adouble);
      SurfacePoly* surf;

      stepx = macro_max(stepx,1);
      stepy = macro_max(stepy,1);
      stepz = macro_max(stepz,1);
      surf = AMIFluid::Func_CreateVectors(displ.get(), 
              stepx, stepy, stepz,  scale, style);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 527:
#line 10658 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (3)  First  vector field v1
        (5)  Second vector field v2
        (7)  Third  vector field v3
        (9)  step in X dimension
        (11) step in Y dimension
        (13) step in Z dimension
        (15) resolution

    Description:
        Create 3D ellipsoids based on 3 vector fields
    **/
      GET_VARSTACK_VALUE(InrImage,v3);
      GET_VARSTACK_VALUE(InrImage,v2);
      GET_VARSTACK_VALUE(InrImage,v1);
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      int stepz   = (int) (yysemantic_stack_[(16) - (13)].adouble);
      int res     = (int) (yysemantic_stack_[(16) - (15)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids(v1.get(),
              v2.get(),
              v3.get(),
              stepx,stepy,stepz,res);
      BasicVariable::ptr varres(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(varres);
    ;}
    break;

  case 528:
#line 10690 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (3)  First  vector field v1
        (5)  Second vector field v2
        (7)  Third  vector field v3
        (9)  step in X dimension
        (11) step in Y dimension
        (13) step in Z dimension
        (15) resolution
        (17) RGB image for the colors
        (19) mask image

    Description:
        Create 3D ellipsoids based on 3 vector fields
    **/
      GET_VARSTACK_VALUE(InrImage,mask);
      GET_VARSTACK_VALUE(InrImage,colors);
      GET_VARSTACK_VALUE(InrImage,v3);
      GET_VARSTACK_VALUE(InrImage,v2);
      GET_VARSTACK_VALUE(InrImage,v1);

      int stepx   = (int) (yysemantic_stack_[(20) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(20) - (11)].adouble);
      int stepz   = (int) (yysemantic_stack_[(20) - (13)].adouble);
      int res     = (int) (yysemantic_stack_[(20) - (15)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids( v1.get(),
                                    v2.get(),
                                    v3.get(),stepx,stepy,stepz,res,
                                    colors.get(),
                                    mask.get());
      BasicVariable::ptr varres(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(varres);
    ;}
    break;

  case 550:
#line 10792 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description: creates an image extent based on the limits in voxel coordinates in X,Y and Z
        Parameters: xmin, xmax, ymin, ymax, zmin, zmax
      **/
      GET_VARSTACK_VALUE(float,zmax)
      GET_VARSTACK_VALUE(float,zmin)
      GET_VARSTACK_VALUE(float,ymax)
      GET_VARSTACK_VALUE(float,ymin)
      GET_VARSTACK_VALUE(float,xmax)
      GET_VARSTACK_VALUE(float,xmin)
      ImageExtent<float>* extent=new ImageExtent<float>(  *xmin, *xmax, 
                                                          *ymin, *ymax, 
                                                          *zmin, *zmax);
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 551:
#line 10812 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description: creates an image extent based on the limits in pixel coordinates in X,Y 
        Parameters: xmin, xmax, ymin, ymax
      **/
      GET_VARSTACK_VALUE(float,ymax)
      GET_VARSTACK_VALUE(float,ymin)
      GET_VARSTACK_VALUE(float,xmax)
      GET_VARSTACK_VALUE(float,xmin)

      ImageExtent<float>* extent=new ImageExtent<float>( *xmin, *xmax, *ymin, *ymax);
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 552:
#line 10829 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      #ifdef min
        #undef min
      #endif
      #ifdef max
        #undef max
      #endif
      GET_VARSTACK_VALUE(float,zmax)
      GET_VARSTACK_VALUE(float,zmin)

      float float_max = std::numeric_limits<float>::max();
      ImageExtent<float>* extent=new ImageExtent<float>(
          -float_max,float_max,
          -float_max,float_max,
          *zmin,*zmax);
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 553:
#line 10850 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);

      ImageExtent<float>* extent=new ImageExtent<float>();
      extent->SetMode(0); // absolute
      extent->SetXmin( im->SpacePosX(0));
      extent->SetXmax( im->SpacePosX(im->DimX()-1));
      extent->SetYmin( im->SpacePosY(0));
      extent->SetYmax( im->SpacePosY(im->DimY()-1));
      extent->SetZmin( im->SpacePosZ(0));
      extent->SetZmax( im->SpacePosZ(im->DimZ()-1));
      //extent->print();
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 9395 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	default: break;
      }
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
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse look-ahead token after an
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

    /* Else will try to reuse look-ahead token after shifting the error
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

    yyerror_range[0] = yylocation_stack_[yylen - 1];
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
	if (yyn != yypact_ninf_)
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

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    if (yyn == yyfinal_)
      goto yyacceptlab;

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the look-ahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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
    if (yychar != yyeof_ && yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Parser::yypact_ninf_ = -1697;
  const short int
  Parser::yypact_[] =
  {
      5533,  9582,  8131,  8131,  8131,    25, -1697, -1697, -1697,  8131,
    8131,  8131, -1697, -1697,    67,    81, -1697, -1697, -1697, -1697,
    8501, -1697,   -51,    19, -1697,    -2,  8131,  8131,  8131,    85,
    8131, -1697,   106,   133, -1697, -1697, -1697, -1697, -1697, -1697,
      40, -1697,    -5, -1697, -1697, -1697, -1697, -1697,   134,    -6,
     178,   192,   118,  8131,   223, -1697, -1697, -1697, -1697,   262,
     306,  8871,  8131,   337,   117,   395,   136,   199,   406,   448,
     453,   461,   463,   464,   466,   471,   476,   481,   482,   483,
     484,   485,   486,   487,   488,   490, -1697, -1697, -1697, -1697,
     491,   492,   493,   185,   231,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     303,   521,   522,   523,   524,   525,   526,   528,   531,   532,
     533,   534,   535,   537,   538,   539,   540,   541,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   559,   560,   561,   562,   563,   565,   568,
     569,   575,   577,   578,   579,   581,   582,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
    7021,   597,   599,   600,   601,   602,   603, -1697, -1697, -1697,
   -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,   604,   605,
     607,   608,   609, -1697, -1697,  8131,  8131,  8131,  8131,  8131,
    8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,   134,
   -1697,   118, -1697,  8131,  6281,  8131,   610,   611,   612,   613,
     -25,   134,   614,   615,   616,   617,   618,   278,   619,   620,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   633,
     634,   635,   636, -1697, -1697, -1697,   637,   638,   333,  5155,
   -1697, -1697, -1697, -1697, -1697, -1697, -1697,    42, -1697, -1697,
     351,    15, -1697, -1697, -1697,   371,    27, -1697,   127,   381,
   -1697,    45,    33,   639, -1697,   402,   558,   648,     5,   -35,
   -1697, -1697,    77, -1697,   -44, -1697, -1697, -1697, -1697, -1697,
    8131,   640,   641, -1697,   642,   643,   644,    92, -1697,    99,
   -1697, -1697,   102,   647,   632, -1697, -1697, -1697, -1697,  8131,
    8131,  8131, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,
   -1697, -1697, -1697, -1697, -1697, -1697, -1697,  8131, -1697,   118,
     118,   156,  8131,  8131,   -30,   356, -1697, -1697,   -26,  8131,
   -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,   642, -1697,
   -1697, -1697, -1697, -1697, -1697,   118,  8131,  8131,    16, -1697,
    8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,    -2,  8131,
    8131,    -2,    -2,    -2,    -2,    -2,  8131,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,  8131,  8131,    -2,   222,
     340,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,  8131,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,  8131,  8131,  8131,  8131,
    8131,  8131,  8131,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,   598,   606,    -2,    -2,    -2,    -2,   621,  8131,
    8131,  8131,   622,  8131,   645,  8131,  8131,    -2,    -2,    -2,
     646,   649,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,  8131,  8131,  8131,    -2,  8131,  8131,    -2,
     650,    -2,   651,   652,  8131,    -2,    -2,  7391,  8131, -1697,
    8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,
      -2, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,
   -1697, -1697, -1697, -1697, -1697,   -76, -1697,   653, -1697, -1697,
   -1697,    42, -1697,    95,  8131,  8131,   655, -1697, -1697,   654,
    8131,  8131,    -2,  8131,  8131,   289,  8131,  8131,  8131,  8131,
    8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,
      -2,    -2,    -2, -1697, -1697, -1697, -1697, -1697, -1697, -1697,
   -1697, -1697,    42, -1697,   319,  8131,   -15,  9582,  4710,  8131,
     134, -1697, -1697, -1697,  8131,  8131,  8131,  8131,  8131,  8131,
    8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  9582,
    8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,   397,  8131,
    4334,    -9,   -14,  8131,   520,   527,  8131,    44,    23,  8131,
   -1697,   659,   656,   658,    90,   660,   661,   667, -1697, -1697,
     669,   670,   671,   672, -1697,   673,   674,   675,   676, -1697,
   -1697,   677, -1697,   678, -1697,   681,   682,   683,   684,   685,
   -1697, -1697,  8131,  8131, -1697,   686,   687, -1697,   689, -1697,
    8131,   657,   688,   691,   692,   693, -1697,   697,   694,   690,
     699,   701,   702,   703,   704,   705,   706,   707,   710,   708,
     709,   711,   712,   713,   714,   715,   716,   718,   719,   720,
     721,   728,   723,   724,   725,   726,   717, -1697, -1697,   734,
   -1697, -1697,   735,   730,   731,   732,   733,   736,   737,   738,
     739,   740,   741,   748,   749,   750,   745,   752,   747,   751,
     753,   754,   755,   186,   756,   758,   757,   764,    80,   763,
     760,   761,   762,   765,   766,   767,   768,   769,   770,   771,
     773,   780,   775,   782,   191,   777,   778,   779,   781,   783,
     784,   785,   786,   787,   788,   235,   789,   796,   797,   792,
     793,   794,   795,   798,   799,   800,   801,   802,   803,   804,
     805,   806,   807,   808,   809,   816,   817,   818,   813,   814,
      47,   815,   819,   237,   820,   821,   822,   823,   824,   830,
   -1697,   829,   826,   833,   834,   835,   836,   837,   838,   839,
     840,   841,   842,  8131,  8131, -1697, -1697,   -18, -1697,   843,
     844,   848,   845,   849,   742,   851,   308,    42,   240,   846,
     847,   850,   852,   855,   245,   853,   854,   252,   259,   856,
     857,   858,   859,   860,   861,   868,   869,   864,   865,   866,
     867, -1697, -1697,   241,   874,   876, -1697,   877, -1697,   878,
   -1697, -1697,  8131, -1697,   879,   880,   881,   882,   883,   884,
     885,   886,   887, -1697, -1697, -1697, -1697, -1697, -1697, -1697,
   -1697, -1697, -1697, -1697, -1697, -1697,   888,  8131,   640,   641,
     260, -1697, -1697,   889, -1697, -1697, -1697, -1697,   127,   127,
   -1697, -1697, -1697, -1697,    45,    45,    33, -1697,   402,   558,
     746,   648, -1697, -1697, -1697, -1697, -1697, -1697,   891,   890,
   -1697,  6651,  7761,   893,   700, -1697,   894,   899,   902,   908,
     903, -1697, -1697,   906,   100, -1697,  9582, -1697, -1697,  8131,
    8131, -1697, -1697,  8131,  8131,  8131,  8131,  8131,  8131,  8131,
    8131,  8131,   -33,   722,   743,  8131,  8131,  8131, -1697, -1697,
    8131,   399,  8131, -1697,   566,  8131, -1697,   679, -1697, -1697,
    8131,   911, -1697, -1697,   915, -1697,   917,     2,  8131,  8131,
   -1697,  8131,  8131,  8131,  8131,  8131,    -2,  8131,  8131,  8131,
    8131,  8131,  8131, -1697,  8131,  8131,  8131,    -2,    -2,    -2,
   -1697,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,    -2,
    8131, -1697, -1697, -1697,    -2, -1697,    -2,    -2,    -2,    -2,
      -2, -1697,    -2,    -2, -1697,  8131, -1697,  8131,   918,  8131,
    8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,
   -1697,  8131, -1697, -1697,  8131,  8131,  8131,  8131,  8131,  8131,
    8131,  8131,  8131,  8131,    -2, -1697,  8131,  8131, -1697, -1697,
      -2,    -2,    -2,    -2,    -2,  8131,  8131,  8131,  8131,  8131,
    8131,  8131,  8131,  8131,  8131,  8131, -1697, -1697, -1697,  8131,
    8131, -1697,  8131,  8131, -1697,  8131,  8131,  8131,  8131,  8131,
   -1697, -1697, -1697,  8131, -1697, -1697, -1697, -1697, -1697, -1697,
    8131,  8131,  8131, -1697,   347,   912, -1697, -1697, -1697, -1697,
   -1697, -1697, -1697,  8131, -1697,   130,   130,   831, -1697, -1697,
    8131,  8131,    -2,  8131,  8131,    -2, -1697,  8131,  8131,  8131,
   -1697,  8131, -1697,  8131,  8131,  8131,  8131,  8131,  8131, -1697,
   -1697, -1697,  8131,  8131,    -2,    -2,  8131,  8131,  8131, -1697,
    8131,  8131,    -2, -1697,    -2,    -2,  8131,  8131,  8131,  8131,
    8131,  8131,  8131,  9582, -1697, -1697,  5911, -1697,  9582,  8131,
    8131, -1697, -1697,  8131,  8131,  -194,   698,  8131,  8131,  8131,
    8131, -1697,   832,   913,   920,   916,   263,   921,   923,   919,
     922,   924,   925,   926,   927,   264,   929,   930,   936,   943,
     933,   951,   952,   953,   948,  8131,   955,   956,   967,  8131,
      -2,    -2,   268,   962,   963,   970,   971,   972,   973,   969,
     977,   273,   976,   978,   982,   983,   990,   992,   993,  1004,
    1005,  1008,  1010,  1011,  1013,  1014,  1026,  1027,  1028,  1031,
    1034,  1040,   979,  1047,  1042,  1044,  1045,  1046,  1048,  1049,
    1053,  1056,  1055,  1062,  8131,  1063,  1064,  1065,  1060,  1061,
    1066,  1067,   275,  1068,  1069,  1070,  1072,  1075,  1071,  1082,
    1086,  1088,  1090,  1087,  1089,  1091,  1093,  1094,  1096,  1101,
    1105,  1100,  1102,  1103,  1113,  1114,  1115,  1111,  1122,  1123,
    1124,  1127,  1128,  1130,   276,  1125,  1126,  1131,   284,  1136,
    1138,  1139,  1140,  1141,  1137,  1142,  1143,  1144,  1145,  8131,
    8131,    42,    42,  1146,   696,   744,   759,   811,   285,   286,
   -1697,  1147,  1148,  1149,  1156,  1151,  1152,   287,  1153,  1154,
    1161,  1162,  1157,  1158,  1159,  1160,  1167,  1163,  1168,  1164,
    1165,    68,  1166,  1173,  1174,  1169,   288,  1176,  1177,  1172,
     180,  1175,   182,  1179,   318,  1178,  1180,   320,   975,  8131,
   -1697, -1697, -1697,  1182,  1181,  1092,  1183, -1697,  1184,  1185,
    1188,  1186, -1697,  9582,  8131, -1697,  8131, -1697,  8131, -1697,
   -1697,  8131,  8131,  8131,  8131, -1697,   576, -1697,  8131, -1697,
      -2,  8131,  8131, -1697, -1697, -1697, -1697,   937, -1697, -1697,
   -1697, -1697,  1189,  1191,   322, -1697,   -43,     8,  8131, -1697,
   -1697, -1697, -1697,  8131, -1697, -1697,    -2,  8131,  8131,  8131,
    8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,
    8131,  8131,  8131,  8131,  8131,  8131,  8131, -1697, -1697,  8131,
      -2,    -2,    -2,    -2,    -2, -1697, -1697,  8131, -1697,  1193,
   -1697, -1697, -1697,  8131,  8131,  8131,  8131, -1697,  8131,  8131,
    8131, -1697,  8131,  8131, -1697, -1697, -1697, -1697, -1697,  8131,
    8131,  8131,  8131,  8131, -1697, -1697, -1697,  8131,  8131,    -2,
      -2,  8131,  8131, -1697, -1697, -1697, -1697, -1697, -1697, -1697,
   -1697,  8131,  8131,  8131,  8131, -1697,    -2, -1697, -1697, -1697,
   -1697, -1697,  8131, -1697,  8131,  8131,  8131,   447, -1697, -1697,
   -1697,  8131, -1697, -1697, -1697, -1697, -1697,   135, -1697,    42,
   -1697,  8131,  8131, -1697,  8131,  8131, -1697,  8131,  8131,  8131,
   -1697, -1697,  8131,  8131,  8131,  8131, -1697,  8131, -1697,    -2,
    8131, -1697,  8131,  8131,  8131, -1697, -1697,  8131, -1697,  8131,
   -1697, -1697,  8131, -1697,  8131, -1697, -1697, -1697,  8131,  8131,
    8131, -1697,  8131,  9582, -1697, -1697,  8131, -1697, -1697,  1150,
    1192,  1194,  1104, -1697,  1195,   189,  1196,  1197,  1198,  1199,
    1200,  1203,  1210,  1211,  1213,  1208,  1215, -1697, -1697, -1697,
    8131,  1216,  1190,   323,  1212,  1214,  1217,  1219,   327,   331,
     332,   334,  1218,  1220,  1222,   335,    82,  1223,  1224,  1225,
    1228,   357,  1229,  1230,  1231,  1232,  1233,  1234,  1221,  1235,
    1236,  1237,  1239,  1240,  1241,  1242, -1697,  1249,  1250,   358,
     380,  1245,  1252,  1247,  1248,  1251,  1253,  1254,  1255,  1256,
    1257,  1258,  1264,  1260,  1262,  1263,  1265,  1266,  1270,  1267,
    1268,  1269,  1276,  1277,  1278,  1273,  1274,  8131,    42,  1275,
      42,  1024,  1155,  1238,  1243,    42, -1697,  1279,  1280,  1283,
    1282,  1284,  1285,  1289,  1286,  1287,  1290,  1288,  1291,  1292,
    1293,    69,  1295,  1209,  1296,  1294,  1297,  1298,   403,  1299,
    1300,  1301,  1302,  1303,  1304,  8131,  8131,  1311,  8131, -1697,
    8131, -1697,  8131,  8131,  8131,  8131, -1697, -1697, -1697,  8131,
   -1697,  1312, -1697,   412, -1697,   -43,  1107,  8131,  8131, -1697,
   -1697,  8131, -1697,  8131, -1697,  8131, -1697,  8131,  8131,  8131,
    8131, -1697,  8131,  8131,  8131,  8131,  8131,  8131, -1697,  8131,
    8131,  9232,  8131,  8131,  8131,  8131, -1697,  8131,  8131,  8131,
    8131,  8131,    -2,  8131, -1697, -1697, -1697,  8131, -1697,  8131,
    8131, -1697,  8131,  8131,  8131,  8131,  8131,  8131,  8131,  8131,
   -1697, -1697,  8131,    -2,    -2,  8131,  8131, -1697,  8131,  8131,
    8131, -1697, -1697, -1697,  8131,  8131, -1697, -1697,  8131, -1697,
   -1697, -1697, -1697, -1697, -1697,  8131,  8131, -1697,  8131, -1697,
    8131, -1697,  8131,  8131, -1697,  8131,  8131,    -2,  8131, -1697,
    8131,  8131, -1697,  8131, -1697,  8131,  8131,  8131, -1697,  8131,
    8131,  8131,  8131,  9582,  8131,  8131, -1697, -1697, -1697,   407,
    1313,  1308,  1309,  1310,  1317,  1314, -1697,  1318,   415,  1315,
    1316,   418,   419,  1319,  1320,  1321,  1322,  1323,  1325,  1327,
    1329,  1330,  1335,  1336,  1337,  1324,  1339,  1346,   371,  1348,
    1343,  1344,  1345,  1347,  1349,  1350,  1351,  1352,  1353,   420,
    1354,  1361,   422,  1362,  1359,  1360,  1367,  1368,  1364,  1365,
    1372,  1387,  1388,   423,  1390,  1397,   427,  1398,  1399,  1400,
    1401,  1402,    42,  1414,  1415,  1416,  1405,  1417,  1418,  1423,
    1424,  1425,  1426,  1427,  1407,  1435,  1430,  1433,  1440,  1441,
    1442,  1443,  1444,  1445,  1438,  1451,  1452, -1697,  8131, -1697,
    8131,  8131,  8131, -1697,  8131, -1697, -1697,   -43,  8131,  8131,
   -1697,  8131, -1697,  8131,  8131,  8131,  8131,  8131, -1697,  8131,
    8131,  8131,  8131,  8131,  8131,  9232, -1697,  9232, -1697, -1697,
    9232,  9232,  8131,  8131,  8131,    -2,    -2,    -2,    -2, -1697,
    8131,  8131, -1697, -1697,  8131, -1697,  8131,  8131, -1697, -1697,
    8131,  8131, -1697,  8131,  8131, -1697,  8131,    -2, -1697, -1697,
    8131, -1697, -1697, -1697, -1697, -1697, -1697,  8131,  8131,  8131,
   -1697,  8131,  8131,  8131,  8131,  8131,    -2,  8131, -1697, -1697,
    8131,  8131, -1697, -1697, -1697, -1697, -1697, -1697,  9582, -1697,
   -1697,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1464,
    1465,  1468,  1469,  1470,  1466,   430,  1471,  1467,  1474,  1475,
    1473,  1476,  1482,  1486,  1487,  1485,  1488,  1492,  1494,  1495,
    1491,  1496,  1501,  1497,  1504,  1506,  1503,  1505,  1507,  1511,
    1513,  1512,  1514,  1521,  1517,  1524,  1519,   431,  1520,  1522,
    1523,  1525,  1526,  1527,  1449,  1530, -1697, -1697, -1697, -1697,
   -1697,  8131, -1697, -1697,  8131, -1697, -1697, -1697, -1697, -1697,
    8131, -1697,  8131, -1697,  8131, -1697, -1697,  8131, -1697, -1697,
   -1697, -1697,  9232, -1697, -1697, -1697, -1697,  8131,  8131, -1697,
    8131, -1697, -1697,  8131,  8131,  8131,  8131,  8131, -1697,    -2,
   -1697,  8131, -1697,  8131, -1697,  8131,  8131,  8131,  8131,  8131,
      -2,  8131,  8131, -1697,  1528,  1529,  1536,  1537,  1538,  1533,
    1540,  1535,  1539,  1542,  1541,  1543,  1544,   432,  1545,  1546,
    1547,  1548,  1549,   434,  1556,  1551,  1552,  1553,  1554,  1561,
    8131,  8131, -1697, -1697, -1697,  8131, -1697,  8131,  8131, -1697,
    8131,  8131,  8131, -1697,  8131,  8131,    -2,  8131,  8131,  8131,
   -1697,  8131, -1697,  8131,  8131,    -2,  8131,  1050,  1562,  1563,
    1564,  1565,  1560,   435,  1567,  1566,  1568,  1569,   439,  1570,
    1571,  1573,   442,   443,  1572,  1574,  1575,  8131, -1697, -1697,
   -1697, -1697,  8131, -1697,  8131, -1697,  8131,  8131,  8131, -1697,
    8131,  8131,  8131, -1697, -1697,  8131, -1697,  8131,  8131,  8131,
    8131, -1697,  1576,  1579,  1583,  1578,  1585,  1586,  1587,  1582,
    1589,  1584,  1588,  1590,  1591,  8131, -1697, -1697,  8131, -1697,
   -1697, -1697,  8131, -1697,  8131,  8131,  8131,    -2,  1592,  1593,
    1594,  1595,  1598,  1596,  1597, -1697, -1697,  8131, -1697, -1697,
    8131,    -2,  1599,  1600,  1602,  8131,  8131,  8131,  1603,  1604,
    1601,  8131,  8131, -1697,  1605,  1606,  8131,  8131,  1608,  1609,
    8131,  8131,  1616,  1617, -1697, -1697
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,     0,     0,     0,     0,     0,    21,    65,    66,     0,
       0,     0,    69,    70,     0,     0,   211,   216,    41,    20,
       0,   286,     0,    86,    74,     0,     0,     0,     0,     0,
       0,    85,     0,     0,   205,   215,   529,   413,   280,   409,
     536,   493,   537,   531,   532,   534,   533,   535,   538,   412,
     530,   539,     0,     0,     0,    43,    46,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,   176,   207,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,     0,     0,
       0,     0,     0,   217,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     213,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,   183,     0,     0,     0,     0,
       4,     8,    10,    14,    16,    18,    12,     0,   410,   414,
       0,   282,   408,   415,   417,   422,   431,   451,   455,   458,
     459,   464,   467,   469,   470,   472,   474,   476,   478,   480,
     487,    40,   418,   416,     0,   540,   411,   541,    39,   423,
       0,     0,     0,   412,     0,     0,     0,   282,   426,   282,
     434,   433,     0,     0,     0,    67,   265,    68,    71,     0,
       0,     0,   283,   267,    77,    80,    75,    92,    89,    90,
      91,    88,    87,    76,    95,    96,    97,     0,    84,     0,
       0,     0,     0,     0,     0,     0,    35,   101,     0,     0,
     543,   544,   536,   545,   537,   538,   542,   530,   539,   546,
     549,   547,   548,    82,    83,     0,     0,     0,   435,   436,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   437,   438,   443,   444,   445,   446,   447,   449,   448,
     439,   440,   441,   442,   450,     0,    25,     0,   213,   213,
      37,     0,    38,     0,     0,     0,     0,    31,    29,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     3,     5,     9,    11,    15,    17,
      19,    13,     0,     6,     0,     0,     0,     0,   189,     0,
       0,   427,   428,   429,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     421,     0,     0,     0,     0,     0,     0,     0,   362,   363,
       0,     0,     0,     0,   137,     0,     0,     0,     0,   142,
     143,     0,   126,     0,   134,     0,     0,     0,     0,     0,
     123,   124,     0,     0,    98,     0,     0,    64,     0,   179,
       0,     0,     0,     0,     0,     0,   266,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   112,     0,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     282,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,    26,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   261,     0,   265,     0,   208,     0,   553,     0,
      99,   100,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,     0,   536,   537,
       0,   194,   190,     0,   424,   452,   453,   454,   456,   457,
     461,   460,   462,   463,   465,   466,   468,   471,   473,   475,
       0,   477,   482,   483,   484,   485,   486,   481,     0,     0,
      55,     0,     0,     0,   536,   488,     0,   269,   272,     0,
      51,    57,    53,     0,     0,   432,     0,    72,    73,     0,
       0,   209,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
       0,     0,     0,   180,   281,     0,    47,     0,   243,   245,
       0,     0,   246,   247,     0,   248,     0,     0,     0,     0,
     322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   323,     0,     0,     0,     0,     0,     0,
     345,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   307,   308,   309,     0,   311,     0,     0,     0,     0,
       0,   318,     0,     0,   239,     0,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     325,     0,   508,   509,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,     0,   284,   285,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   388,   169,   170,     0,
       0,   241,     0,     0,   499,     0,     0,     0,     0,     0,
     303,   305,   419,     0,   494,   358,   359,   360,   361,   255,
       0,     0,     0,   172,     0,   213,   187,   212,   213,    27,
     258,   259,   260,     0,   174,   196,   196,     0,    33,   392,
       0,     0,     0,     0,     0,     0,   517,     0,     0,     0,
     399,     0,   401,     0,     0,     0,     0,     0,     0,   403,
     404,   119,     0,     0,     0,     0,     0,     0,     0,   389,
       0,     0,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,   425,     0,   430,     0,     0,
       0,    50,    49,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     213,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     282,     0,   282,     0,     0,     0,     0,     0,     0,     0,
     195,   191,   479,     0,     0,     0,     0,   489,     0,     0,
       0,     0,    52,     0,     0,   206,     0,   127,     0,   122,
     129,     0,     0,     0,     0,   125,     0,   135,     0,   130,
       0,     0,     0,   133,   262,   263,   264,     0,    56,    81,
      48,   420,     0,     0,     0,   295,     0,     0,     0,   321,
     324,   326,   327,     0,   328,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,   306,     0,
       0,     0,     0,     0,     0,   319,   320,     0,   254,     0,
     290,   291,   292,     0,     0,     0,     0,   150,     0,     0,
       0,   156,     0,     0,   511,   364,   365,   366,   367,     0,
       0,     0,     0,     0,   507,   407,   373,     0,     0,     0,
       0,     0,     0,   378,   379,   380,   381,   382,   383,   384,
     385,     0,     0,     0,     0,   495,     0,   496,   500,   501,
     502,   503,     0,   492,     0,     0,     0,   213,   188,    24,
      28,     0,   200,   197,   199,   198,   213,     0,   213,     0,
     393,     0,     0,   394,     0,     0,   518,     0,     0,     0,
     398,   400,     0,     0,     0,     0,   402,     0,   178,     0,
       0,   219,     0,     0,     0,   225,   110,     0,   109,     0,
     117,   118,     0,   163,     0,   165,   166,   104,     0,     0,
       0,   102,     0,     0,   193,   256,     0,    54,   491,     0,
      60,    58,     0,   552,     0,   282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,   250,   251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   253,     0,     0,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   551,     0,     0,     0,     0,     0,     0,   289,
       0,   128,     0,     0,     0,     0,   136,   131,   144,     0,
      63,     0,   296,     0,   297,     0,     0,     0,     0,   168,
     331,     0,   334,     0,   336,     0,   338,     0,     0,     0,
       0,   368,     0,     0,     0,     0,     0,     0,   346,     0,
       0,     0,     0,     0,     0,     0,   356,     0,     0,     0,
       0,     0,     0,     0,   293,   294,   145,     0,   147,     0,
       0,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     406,   374,     0,     0,     0,     0,     0,   386,     0,     0,
       0,   497,   498,   171,     0,     0,   213,    22,     0,    32,
     204,   202,   203,   201,    30,     0,     0,   397,     0,   519,
       0,   520,     0,     0,   186,     0,     0,     0,     0,   220,
       0,     0,   224,     0,    78,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,    61,    59,    62,     0,
       0,     0,     0,     0,     0,     0,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   423,     0,   423,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,     0,   121,
       0,     0,     0,   141,     0,   298,   299,     0,     0,     0,
     330,     0,   333,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,   347,     0,   349,   351,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   316,
       0,     0,   146,   148,     0,   152,     0,     0,   161,   510,
       0,     0,   514,     0,     0,   160,     0,     0,   375,   376,
       0,   387,   240,   242,   390,   391,    23,     0,     0,     0,
     302,     0,     0,     0,     0,     0,     0,     0,   222,   223,
       0,     0,   162,   164,   105,   107,   221,   103,     0,   257,
     490,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   550,   288,   138,   139,
     140,     0,   300,   301,     0,   332,   335,   337,   339,   342,
       0,   370,     0,   372,     0,   340,   343,     0,   348,   350,
     352,   353,     0,   355,   310,   312,   313,     0,     0,   317,
       0,   149,   155,     0,     0,     0,     0,     0,   159,     0,
     377,     0,   395,     0,   521,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   341,   371,   369,     0,   354,     0,     0,   357,
       0,     0,     0,   516,     0,     0,     0,     0,     0,     0,
     525,     0,   526,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   329,
     344,   314,     0,   153,     0,   512,     0,     0,     0,   158,
       0,     0,     0,   522,   523,     0,   527,     0,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   513,     0,   173,
     157,   405,     0,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   315,   515,     0,   528,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   396,   184
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -1697, -1697, -1697,  -218,   901,   935,   949, -1697, -1697,   980,
    1057,  1074,  1084, -1697, -1697,  -280, -1697,  -508, -1697, -1697,
   -1697,   -10,  3064,    87,    32,  1927, -1697, -1697, -1697,    78,
     810,    10,  -182, -1697,  -410,  -179,   251, -1697,   267,   315,
     350,   265, -1697, -1697,  -123,  2245,     9, -1697, -1697,   -21,
   -1697,   -48,   941,     3, -1697,  -213, -1696
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   258,   259,   260,   261,   262,   263,   805,   804,   264,
     265,   266,   267,  1085,   870,  1298,   268,   516,   517,  1087,
     269,   315,   655,   322,   270,   309,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   316,   911,   292,   293,   294,
     295,   296,   297,   361,   362,   363,   299
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       317,   318,   332,   298,   360,     6,   520,   903,   518,    38,
     796,   797,   310,   311,   344,   642,   643,    38,    19,   649,
     324,   807,   304,  1835,  1837,  1839,   589,   346,   565,  1174,
     304,   569,   793,    36,   566,   570,   312,   835,   836,   905,
     568,   555,   569,   599,   527,   314,   570,   618,   619,   563,
     579,   580,   591,   592,   593,   594,   595,  1192,    38,   341,
     606,  1061,    38,  1573,   600,     6,   608,  1347,    38,   837,
     838,   304,   369,   596,   327,   304,   836,    36,    19,   308,
     319,   304,  1521,  1789,   328,   329,   330,   331,  1522,  1790,
     597,  1523,  1791,   606,   320,   606,   598,   836,   337,   608,
    1007,   608,  1713,   345,   609,   606,   590,   839,   838,   564,
     919,   607,   606,   571,   572,   336,   609,   338,   608,   339,
    1126,   564,   573,  1128,   571,   572,   616,   617,   342,   343,
     371,   650,   372,   573,   574,   575,   840,   583,   584,   576,
     364,   841,   842,   843,   844,   845,   340,   581,   582,   374,
     347,   375,   652,    36,   350,    38,   351,   352,   353,   354,
      43,    44,    45,    46,    47,   355,   356,   357,   358,   880,
     881,   882,   883,   360,   846,   847,   848,   350,    38,   351,
     352,   353,   354,    43,    44,    45,    46,    47,   355,   356,
     357,   358,    36,   606,  1533,   606,  1535,   348,   515,   608,
    1001,   608,   606,  1679,   399,  1023,  1002,   349,   608,   528,
     529,  1024,   376,   519,   377,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,  2011,
     906,  2012,   618,   619,  2013,  2014,   365,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   794,  1035,
     400,  1064,   849,   850,  1099,  1036,   851,  1065,   852,  1106,
    1100,  1126,   298,  1127,  1128,  1107,  1110,   489,   644,   645,
     646,   647,  1111,  1112,  1145,   366,   853,  1357,  1367,  1113,
    1146,   325,  1385,  1358,  1368,   645,   646,  1395,  1386,  1437,
    1470,   360,   360,  1396,   851,  1438,  1471,   535,  1475,  1496,
    1498,  1506,  1528,   798,  1476,  1497,  1497,  1507,  1529,   612,
     800,   521,   522,  1088,   853,   851,   426,   360,   427,   367,
     854,   855,   856,   857,   858,   859,   860,   861,   862,   863,
     864,   865,  1537,   553,  1541,   853,  1569,  1694,  1538,   651,
    1542,  1700,  1570,  1695,   831,  1702,  1704,  1701,  1706,  1711,
     370,  1703,  1705,   614,  1707,  1712,   653,   654,   854,   855,
     856,   857,   858,   859,   860,   861,   862,   863,   864,   865,
     564,  1718,  1736,   686,   687,   688,  2110,  1719,  1737,   854,
     855,   856,   857,   858,   859,   860,   861,   862,   863,   864,
     865,   577,   578,   567,  1738,   878,   879,   618,   619,   620,
    1739,   621,   622,   623,   884,   885,   624,   613,   373,   625,
     626,   627,   628,   629,   630,   631,   632,  1798,   633,   378,
     586,  1897,   634,  1799,   615,   635,   636,  1898,   637,  1906,
     638,   639,  1910,  1912,  1939,  1907,  1943,  1955,  1911,  1913,
    1940,  1959,  1944,  1956,  2061,  2094,  2143,  1960,  2150,  2183,
    2062,  2095,  2144,  2189,  2151,  2184,  2194,  2196,  1182,  2190,
    1183,   379,  2195,  2197,   766,   767,   380,   769,   892,   893,
     894,   895,   896,   897,   381,   360,   382,   383,   781,   384,
     782,  1294,  1295,  1296,   385,  1297,  1641,  1642,  1643,   386,
    1644,   689,   690,   691,   387,   388,   389,   390,   391,   392,
     393,   394,   799,   395,   396,   397,   398,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   312,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   821,   428,   429,   430,   431,   432,   433,
     745,   434,   747,   748,   435,   436,   437,   438,   439,   874,
     440,   441,   442,   443,   444,   833,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   872,   460,   461,   462,   463,   464,  1291,   465,  1089,
    1292,   466,   467,   788,   875,   876,   877,   898,   468,  1098,
     469,   470,   471,   913,   472,   473,   914,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     490,   801,   491,   492,   493,   494,   495,   496,   497,   915,
     498,   499,   500,   523,   524,   525,   526,   530,   531,   532,
     533,   534,   536,   537,   825,   826,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   866,   547,   548,   549,   550,
     551,   552,   588,   648,   611,   813,   585,   603,   587,   601,
     602,   610,   604,   605,   899,   832,  1097,   890,  1289,   734,
     917,   686,   918,   944,  1185,   921,   806,   735,   689,   916,
     920,   922,   923,   924,   925,   926,   927,   928,   929,   930,
     931,   932,   740,   744,   933,   934,   935,   936,   937,   940,
     941,   752,   942,   853,   753,   946,   951,   948,   945,   795,
     803,   949,   947,   952,   950,   953,   746,   955,   954,  1155,
     956,   773,   775,   776,   960,   957,   958,   959,   961,   962,
     978,   963,   964,   965,   966,   967,   968,   943,   969,   970,
     971,   972,   973,   974,   975,   976,   977,   979,  1187,   980,
     981,   982,   983,   984,  1492,  1095,   985,   986,   987,   988,
     989,   990,   991,   992,   993,   994,   995,   996,  1148,  1637,
    1348,   997,  1004,   998,   999,  1000,  1003,  1005,  1006,  1008,
    1009,  1010,  1011,  1084,  1176,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1499,  1019,  1020,  1021,  1022,  1025,  1026,  1027,
    1177,  1028,  1493,  1029,  1030,  1031,  1032,  1033,  1034,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1299,  1494,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1062,   886,  1347,  1070,  1063,
    1066,  1067,  1068,  1069,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,   887,  1353,   891,  1083,  1090,  1091,  1080,
    1081,  1082,  1092,  1094,  1096,  1093,  1101,  1102,  1105,  1495,
    1103,   368,  1104,  1108,  1109,  1119,  1114,  1115,  1116,  1117,
    1118,  1086,  1120,  1121,  1122,  1123,  1124,  1125,  1129,  1130,
    1131,  1132,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1300,   888,  1150,  1152,  1147,  1154,  1156,  1143,  1163,
    1164,  1149,  1157,  1165,  1166,  1158,  1168,  1169,  1170,  1171,
    1172,  1159,  1161,  1160,  1189,  1178,  1179,  1180,  1190,  1133,
    1191,  1234,  1290,  1354,  1355,  1359,  1356,  1360,   889,  1361,
    1365,  1175,  1362,  1369,  1363,  1364,  1366,  1373,  1194,  1195,
    1370,  1196,  1197,  1198,  1199,  1200,  1371,  1202,  1203,  1204,
    1205,  1206,  1207,  1372,  1208,  1374,  1375,  1376,  1377,  1379,
    1380,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1638,
    1223,  1381,  1387,  1388,  1389,  1390,  1391,  1392,  1640,  1393,
    1645,  1394,  1566,  1417,  1162,  1232,  1397,  1543,  1398,  1235,
    1236,  1237,  1399,  1400,  1240,  1241,  1242,  1243,  1244,  1245,
    1401,  1246,  1402,  1403,  1247,  1248,  1249,  1250,  1251,  1252,
    1253,  1254,  1255,  1256,  1404,  1405,  1258,  1181,  1406,  1184,
    1407,  1408,  1186,  1409,  1410,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,  1274,  1275,  1411,  1412,  1413,  1276,
    1277,  1414,  1278,  1279,  1415,  1280,  1281,  1282,  1283,  1284,
    1416,  1418,  1419,  1285,  1420,  1421,  1422,  1425,  1423,  1424,
    1426,  1287,  1288,  1489,  1490,  1427,  1428,  1430,  1431,  1432,
    1433,  1434,  1770,  1293,  1441,  1444,  1435,  1436,  1439,  1440,
    1301,  1302,  1442,  1304,  1305,  1443,  1445,  1307,  1308,  1309,
    1446,  1310,  1447,  1311,  1448,  1313,  1314,  1449,  1547,  1450,
    1454,  1451,  1317,  1452,  1453,  1455,  1321,  1322,  1323,  1456,
    1457,  1325,  1458,  1459,  1259,  1463,  1329,  1331,  1333,  1334,
    1335,  1336,  1337,  1460,  1461,  1462,  1464,  1465,  1466,  1343,
    1344,  1467,  1468,  1345,  1469,  1472,  1473,  1349,  1350,  1341,
    1477,  1474,  1478,  1479,  1480,  1481,  1483,  1482,  2177,  1677,
     556,  1500,  1818,  1484,  1485,  1486,  1491,  1286,  1501,  1502,
    1503,  1504,  1505,  1508,  1509,  1510,  1511,  1512,  1513,  1514,
    1515,  1516,  1518,  1517,  1519,  1520,  1524,  1525,  1526,  1527,
    1530,  1531,  1532,  1536,   557,  1534,  1545,  1548,  1539,  1550,
    1540,  1546,  1551,  1567,  1549,  1568,  1552,  1606,   558,  1693,
    1318,  1681,  1675,  1771,  1676,  1678,  1680,  1324,  1682,  1683,
    1684,  1338,  1674,  1685,  1686,  1687,  1342,  1688,  1689,  1690,
    1692,  1793,  1696,  1699,  1697,  1726,     0,  1698,  1708,   559,
    1709,  1346,  1710,  1714,  1715,  1716,  1351,  1352,  1717,  1720,
    1721,  1722,  1723,  1724,  1725,  1727,  1728,  1729,  1872,  1730,
    1731,  1732,  1733,  1734,  1735,  1740,  1741,  1742,  1743,     0,
       0,  1744,  1750,  1745,  1746,  1747,  1748,  1749,  1751,  1487,
    1752,  1646,  1753,  1754,  1757,  1755,  1756,  1758,  1759,  1760,
    1761,  1762,  1763,  1764,  1765,  1768,  1772,  1777,  1779,  1775,
    1776,  1773,  1778,  1781,  1784,  1780,  1782,  1783,  1785,  1792,
    1794,  1786,  1787,  1788,  1795,     0,   560,  1796,  1797,  1800,
    1801,  1802,  1803,  1804,  1805,  1808,  1816,  1899,  1900,  1901,
    1902,  1903,  1905,   561,  1904,  1908,  1909,  1918,  1926,  1914,
    1915,  1916,  1917,   562,  1554,  1919,  1556,  1920,  1557,  1921,
    1922,  1558,  1559,  1560,  1561,  1923,  1924,  1925,  1562,  1927,
    1928,  1564,  1929,  1930,  1931,  1932,     0,  1933,     0,  1934,
    1935,  1936,  1937,  1938,  1941,  1942,  1945,  1488,  1575,  1946,
    1947,  1948,  1949,  1576,  1950,  1951,  1952,  1578,  1579,  1580,
    1581,  1582,  1583,  1584,  1585,  1587,  1588,  1589,  1590,  1591,
    1592,  1593,  1594,  1595,  1596,  1597,  1598,  1953,  1954,  1599,
    1957,  1958,  1961,  1962,  1963,  1964,  1965,  1605,  1571,  1970,
    1767,  1978,  1769,  1607,  1608,  1609,  1610,  1774,  1611,  1613,
    1614,  1553,  1615,  1616,  1967,  1968,  1969,  1971,  1972,  1617,
    1618,  1619,  1620,  1973,  1974,  1975,  1976,  1977,  1623,  1979,
    1980,  1626,  1627,  1981,  1982,  1983,  1984,  1985,  1986,  1987,
    1988,  1628,  1629,  1630,  1631,  1989,  1990,  2047,  2048,  2049,
    2050,  2102,  2052,  2053,  1634,  1635,  1636,  2051,  2055,  2056,
    2054,  1639,  2057,  2058,  2059,  2063,  2060,  2064,  2065,  2066,
    2068,  1647,  1648,  2067,  1649,  1650,  2069,  1651,  1652,  1653,
    2070,  2071,  2073,  1655,  1656,  2072,  2074,  1658,  2075,  2076,
    1660,  2077,  1661,  1662,  1663,  2079,  2078,  2080,  2081,  1665,
    2082,     0,  1666,  2083,  1667,  2084,  2088,  2085,  1668,  1669,
    1670,  2086,  1671,  2087,  2089,  2090,  1673,  2091,  2092,  2093,
    2096,   912,  2097,  2098,  2103,  2099,  2100,  2101,  2130,  2131,
    2132,  2133,  2134,  2135,  2136,  2137,  2139,     0,     0,  2138,
    1691,  2140,     0,  2141,  2142,  2145,  2146,  2147,  2148,  2149,
    2152,  2153,  2154,  2155,  2156,  2157,  2178,  2179,  2180,  2181,
    2182,  2185,     0,     0,     0,     0,  2186,  2193,  2187,  2188,
    2191,  2192,  2198,  2216,  2199,  2200,  2215,  2217,  2218,  2219,
    2220,  2221,  2222,  2223,  2224,     0,  2235,  2236,  2225,  2238,
    2226,  2227,  2239,     0,  2237,  2253,  2240,  2241,     0,  2245,
    2246,  1672,  2247,  2251,  2252,  2256,  2257,  1766,  2260,  2261,
    2264,  2265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1966,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1809,     0,
    1810,     0,  1811,  1812,  1813,  1814,     0,     0,     0,  1815,
       0,     0,     0,     0,     0,     0,     0,  1819,  1820,     0,
       0,  1821,     0,  1822,     0,  1823,     0,  1824,  1825,  1826,
    1827,     0,  1828,  1829,  1830,  1831,  1832,  1833,     0,  1834,
    1836,     0,  1840,  1841,  1842,  1843,     0,  1844,  1845,  1846,
    1847,  1848,     0,  1850,     0,     0,     0,  1817,     0,     0,
       0,     0,     0,  1855,  1856,  1857,  1858,  1859,  1860,  1861,
       0,     0,  1862,     0,     0,  1865,  1866,     0,  1867,  1868,
    1869,     0,     0,     0,  1870,  1871,     0,     0,  1873,     0,
       0,     0,  1806,  1807,     0,  1874,  1875,     0,  1876,     0,
       0,     0,  1878,  1879,     0,  1880,  1881,     0,  1883,     0,
    1884,  1885,     0,  1886,     0,  1887,  1888,  1889,     0,  1890,
    1891,  1892,  1893,     0,  1895,  1896,     0,     0,     0,  1838,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1894,     0,     0,     0,     0,     0,     0,  1991,     0,
    1992,  1993,  1994,     0,  1995,     0,     0,     0,  1997,  1998,
       0,  1999,     0,  2000,  2001,  2002,  2003,  2004,     0,  2005,
    2006,  2007,  2008,  2009,  2010,     0,     0,     0,     0,     0,
       0,     0,  2015,  2016,  2017,     0,     0,   271,   307,     0,
    2022,  2023,     0,     0,  2024,     0,  2025,  2026,     0,  1996,
    2027,  2028,     0,  2029,  2030,     0,     0,     0,     0,   326,
    2033,     0,   333,     0,     0,     0,     0,  2034,  2035,  2036,
       0,     0,  2038,  2039,  2040,  2041,     0,  2043,     0,     0,
    2044,  2045,     0,     0,     0,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1838,     0,  1838,     0,     0,  1838,  1838,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2104,     0,     0,  2105,     0,     0,     0,     0,     0,
    2106,     0,  2107,     0,  2108,     0,     0,  2109,     0,     0,
       0,     0,     0,     0,     0,     0,  2046,  2111,  2112,     0,
    2113,     0,     0,  2114,  2115,  2116,  2117,  2118,     0,     0,
       0,  2120,     0,  2121,     0,     0,  2123,  2124,  2125,  2126,
       0,  2128,  2129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2158,  2159,     0,     0,     0,  2160,     0,  2161,  2162,     0,
    2163,  2164,  2165,     0,  2166,  2167,     0,  2169,  2170,  2171,
       0,  2172,     0,  2173,  2174,     0,  2176,     0,   359,     0,
    1838,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2202,     0,     0,     0,  2204,  2205,  2206,     0,
       0,  2208,  2209,     0,     0,  2210,   271,     0,  2212,  2213,
    2214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2228,     0,     0,  2229,     0,
       0,     0,  2230,     0,     0,  2232,  2233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2242,     0,     0,
    2243,     0,     0,     0,     0,  2248,  2249,  2250,     0,     0,
       0,  2254,  2255,     0,     0,   291,  2258,  2259,     0,   313,
    2262,  2263,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   323,   359,   359,     0,     0,
       0,   334,   335,   323,     0,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   359,     0,     0,     0,     0,     0,   323,     0,
       0,     0,     0,     0,     0,   665,     0,     0,   668,   669,
     670,   671,   672,     0,   674,   675,   676,   677,   678,   679,
     680,   681,   682,     0,     0,   685,     0,     0,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,     0,   703,
     704,   705,   706,   707,   708,   709,   710,   711,   712,   713,
     714,   715,   716,   718,     0,     0,     0,     0,     0,     0,
     725,   726,   727,   728,   729,   730,   731,   732,   733,     0,
       0,   736,   737,   738,   739,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   749,   750,   751,     0,     0,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
       0,     0,     0,   768,   770,     0,   772,     0,   774,     0,
       0,     0,   778,   779,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   323,     0,   792,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     359,     0,     0,     0,     0,     0,     0,     0,     0,   810,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   323,
     323,     0,     0,     0,     0,     0,     0,   828,   829,   830,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   307,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   307,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   313,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   323,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   323,     0,     0,     0,     0,   640,   641,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   656,   658,   656,   656,   656,
     656,   656,   656,     0,   656,   656,     0,     0,     0,     0,
       0,   656,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   656,   656,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   656,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   656,   656,   656,   656,   656,   656,   656,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   656,   656,   656,     0,   323,     0,
     323,   323,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   656,     0,
       0,     0,     0,   656,     0,     0,     0,     0,     0,   656,
       0,     0,   313,     0,     0,     0,   783,   784,   785,   786,
     787,   323,   656,   656,   656,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   323,
     656,     0,     0,     0,     0,   656,   656,     0,   656,   656,
       0,   656,   656,   656,   656,   656,   656,   656,     0,   656,
     656,   656,   323,   323,   827,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     834,     0,     0,   871,   873,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   307,   656,   910,     0,     0,     0,     0,
       0,   834,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1193,     0,     0,   938,   939,     0,
       0,     0,     0,  1201,     0,   323,     0,     0,     0,     0,
       0,     0,     0,     0,  1211,  1212,  1213,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1222,     0,     0,     0,
       0,  1224,     0,  1225,  1226,  1227,  1228,  1229,     0,  1230,
    1231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1257,     0,     0,     0,     0,     0,  1260,  1261,  1262,
    1263,  1264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1303,
       0,     0,  1306,     0,     0,     0,     0,     0,     0,   323,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1319,  1320,     0,     0,     0,     0,     0,     0,  1326,
       0,  1327,  1328,  1330,  1332,     0,     0,     0,     0,     0,
     307,     0,     0,     0,     0,   307,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1144,     0,     0,     0,     0,  1383,  1384,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1151,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1167,     0,     0,     0,     0,     0,  1173,     0,     0,     0,
       0,     0,     0,     0,     0,   323,     0,   323,     0,     0,
     323,     0,     0,     0,     0,  1188,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     656,   656,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   656,     0,     0,     0,     0,   656,   656,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     307,  1555,   323,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1563,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1572,  1574,     0,     0,     0,     0,     0,
       0,     0,     0,  1577,     0,   323,     0,     0,     0,     0,
       0,  1586,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1600,  1601,  1602,
    1603,  1604,     0,     0,     0,     0,     0,     0,     0,   656,
       0,     0,   656,   656,     0,     0,     0,     0,   323,     0,
       0,     0,     0,     0,     0,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1624,  1625,     0,     0,
       0,  1340,     0,     0,     0,     0,     0,     0,     0,   323,
       0,     0,     0,  1632,   323,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     656,     0,     0,     0,   656,   657,   659,   660,   661,   662,
     663,   664,     0,   666,   667,     0,  1659,     0,     0,     0,
     673,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     683,   684,     0,     0,     0,     0,     0,     0,     0,     0,
     307,     0,     0,     0,     0,   702,     0,     0,     0,   656,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     717,   719,   720,   721,   722,   723,   724,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   741,   742,   743,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   323,     0,   765,     0,     0,
       0,     0,   771,     0,     0,     0,     0,     0,   777,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   789,   790,   791,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1544,     0,     0,     0,     0,   802,
       0,     0,     0,     0,   808,   809,     0,   811,   812,     0,
     814,   815,   816,   817,   818,   819,   820,     0,   822,   823,
     824,     0,     0,     0,     0,     0,     0,   656,     0,     0,
       0,     0,  1572,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1849,
       0,     0,     0,   900,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1863,  1864,     0,  1612,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   656,     0,
       0,     0,   656,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1882,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   656,     0,     0,
     307,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   656,     0,     0,
     656,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1664,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1572,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2018,  2019,  2020,  2021,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2032,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2042,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   307,     0,     0,     0,     0,
     323,   323,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   656,     0,   656,   656,     0,   656,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2119,     0,     0,     0,
       0,     0,     0,     0,     0,   656,     0,  2127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1209,
    1210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1233,     0,  2168,     0,     0,  1238,  1239,     0,     0,
       0,     0,  2175,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1312,     0,
       0,  1315,  1316,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   656,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   656,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1378,
       0,     0,     0,  1382,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     656,     0,     0,     1,     2,     3,     0,     4,     0,     0,
       0,   901,     0,     0,     0,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    17,     0,
       0,   902,    21,     0,   903,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,    32,    33,    34,
       0,    35,     0,    37,    38,    39,   904,    41,   869,    43,
      44,    45,    46,    47,   355,   303,   905,   358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   656,     0,     0,     0,     0,     0,     0,   656,
       0,    61,    62,     0,     0,   656,  1565,     0,     0,     0,
       0,     0,   656,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,    76,     0,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,   656,
      88,     0,    90,    91,    92,   305,   306,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
       0,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,  1621,     0,     0,
       0,  1622,   132,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,  1633,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
       0,   169,   170,   171,     0,     0,   172,   173,   174,   175,
     176,   177,   178,   179,   180,     0,  1654,     0,     0,  1657,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   906,   181,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   184,   185,   186,   187,   907,   189,   190,   908,   192,
     193,   194,   195,   196,   197,     0,   198,     0,   200,   201,
       0,   909,     0,     0,     0,     0,   203,   204,   205,   206,
     207,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,   227,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   232,   233,   234,   235,     0,   236,   237,
       0,   238,   239,   240,   241,   242,   243,   244,     0,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     0,     4,     0,     0,     0,   867,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,   868,    41,   869,    43,    44,    45,    46,    47,
     355,   303,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1851,     0,  1852,  1853,     0,  1854,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,    76,     0,    78,    79,    80,    81,    82,
      83,    84,    85,     0,  1877,     0,    88,     0,    90,    91,
      92,   305,   306,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   103,   104,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,     0,     0,     0,     0,     0,     0,   132,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,     0,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,   169,   170,   171,
       0,     0,   172,   173,   174,   175,   176,   177,   178,   179,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,     0,   198,     0,   200,   201,     0,     0,     0,     0,
       0,     0,   203,   204,   205,   206,   207,   208,   209,   210,
    2031,     0,   211,   212,   213,   214,   215,   216,   217,   218,
       0,     0,     0,     0,     0,  2037,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   226,   227,   228,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,   235,     0,   236,   237,     0,   238,   239,   240,
     241,   242,   243,   244,     0,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   554,     0,     0,     0,  2122,
       0,     0,     0,     0,     1,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,     0,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     0,    55,    56,    57,    58,    59,    60,     0,
       0,  2201,     0,     0,     0,     0,     0,     0,  2203,     0,
       0,     0,    61,    62,  2207,     0,     0,     0,     0,     0,
       0,  2211,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,  2231,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,     0,     0,     0,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,     0,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,     0,     0,     0,     0,     0,   203,   204,   205,
     206,   207,   208,   209,   210,     0,     0,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
     220,     0,   221,   222,   223,     0,     0,     0,   224,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,   227,   228,   229,     0,     0,     0,     0,
       0,   230,   231,     0,   232,   233,   234,   235,     0,   236,
     237,     0,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,     1,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       0,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,     0,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,     0,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
       0,     0,     0,     0,     0,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,   220,     0,
     221,   222,   223,     0,     0,     0,   224,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,   227,   228,   229,     0,     0,     0,     0,     0,   230,
     231,     0,   232,   233,   234,   235,     0,   236,   237,     0,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
       1,     2,     3,     0,     4,     0,     0,     0,  1339,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,   868,    41,   869,    43,    44,    45,    46,
      47,   355,   303,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    88,     0,    90,
      91,    92,   305,   306,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,   169,   170,
     171,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,     0,   198,     0,   200,   201,     0,     0,     0,
       0,     0,     0,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,     0,   236,   237,     0,   238,   239,
     240,   241,   242,   243,   244,     0,   246,   247,   248,   249,
       1,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,   301,    41,   302,    43,    44,    45,    46,
      47,     0,   303,     0,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    88,     0,    90,
      91,    92,   305,   306,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,   169,   170,
     171,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,     0,   198,     0,   200,   201,     0,     0,     0,
       0,     0,     0,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,     0,   236,   237,     0,   238,   239,
     240,   241,   242,   243,   244,     0,   246,   247,   248,   249,
       1,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,   868,    41,   869,    43,    44,    45,    46,
      47,   355,   303,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    88,     0,    90,
      91,    92,   305,   306,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,   169,   170,
     171,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,     0,   198,     0,   200,   201,     0,     0,     0,
       0,     0,     0,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,     0,   236,   237,     0,   238,   239,
     240,   241,   242,   243,   244,     0,   246,   247,   248,   249,
       1,     2,     3,     0,   487,     0,   488,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,   301,    41,   302,    43,    44,    45,    46,
      47,     0,   303,     0,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    88,     0,    90,
      91,    92,   305,   306,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,   169,   170,
     171,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,     0,   198,     0,   200,   201,     0,     0,     0,
       0,     0,     0,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,     0,   236,   237,     0,   238,   239,
     240,   241,   242,   243,   244,     0,   246,   247,   248,   249,
       1,     2,     3,     0,     4,   780,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,   301,    41,   302,    43,    44,    45,    46,
      47,     0,   303,     0,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    88,     0,    90,
      91,    92,   305,   306,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,   169,   170,
     171,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,     0,   198,     0,   200,   201,     0,     0,     0,
       0,     0,     0,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,     0,   236,   237,     0,   238,   239,
     240,   241,   242,   243,   244,     0,   246,   247,   248,   249,
       1,     2,     3,     0,   321,     0,  1153,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,   301,    41,   302,    43,    44,    45,    46,
      47,     0,   303,     0,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    88,     0,    90,
      91,    92,   305,   306,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,   169,   170,
     171,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,     0,   198,     0,   200,   201,     0,     0,     0,
       0,     0,     0,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,     0,   236,   237,     0,   238,   239,
     240,   241,   242,   243,   244,     0,   246,   247,   248,   249,
       1,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,   301,    41,   302,    43,    44,    45,    46,
      47,     0,   303,     0,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    88,     0,    90,
      91,    92,   305,   306,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,   169,   170,
     171,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,     0,   198,     0,   200,   201,     0,     0,     0,
       0,     0,     0,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,     0,   236,   237,     0,   238,   239,
     240,   241,   242,   243,   244,     0,   246,   247,   248,   249,
       1,     2,     3,     0,   321,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,   301,    41,   302,    43,    44,    45,    46,
      47,     0,   303,     0,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    88,     0,    90,
      91,    92,   305,   306,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,   169,   170,
     171,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,     0,   198,     0,   200,   201,     0,     0,     0,
       0,     0,     0,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,     0,   236,   237,     0,   238,   239,
     240,   241,   242,   243,   244,     0,   246,   247,   248,   249,
       1,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,   301,    41,   302,    43,    44,    45,    46,
      47,     0,   303,     0,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    88,     0,    90,
      91,    92,   305,   306,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,   169,   170,
     171,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,     0,   198,     0,   200,   201,     0,     0,     0,
       0,     0,     0,   203,   204,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,     0,   236,   237,     0,   238,   239,
     240,   241,   242,   243,   244,   300,   246,   247,   248,   249,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,    32,    33,    34,     0,    35,
       0,    37,    38,    39,   301,    41,   302,    43,    44,    45,
      46,    47,     0,   303,     0,   304,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    76,     0,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,    88,     0,
      90,    91,    92,   305,   306,    95,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     0,     0,     0,     0,     0,     0,
     132,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,     0,   169,
     170,   171,     0,     0,   172,   173,   174,   175,   176,   177,
     178,   179,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,     0,   198,     0,   200,   201,     0,     0,
       0,     0,     0,     0,   203,   204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
     227,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,   233,   234,   235,   300,   236,   237,     0,   238,
     239,   240,   241,   242,   243,   244,     0,   246,   247,   248,
     249,     0,     0,     0,     0,    16,    17,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,    32,    33,    34,     0,    35,
       0,    37,    38,    39,   301,    41,   302,    43,    44,    45,
      46,    47,     0,   303,     0,   304,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    76,     0,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,    88,     0,
      90,    91,    92,   305,   306,    95,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     0,     0,     0,     0,     0,     0,
     132,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,     0,   169,
     170,   171,     0,     0,   172,   173,   174,   175,   176,   177,
     178,   179,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,     0,   198,     0,   200,   201,     0,     0,
       0,     0,     0,     0,   203,   204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
     227,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,   233,   234,   235,     0,   236,   237,     0,   238,
     239,   240,   241,   242,   243,   244,     0,   246,   247,   248,
     249
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        10,    11,    23,     0,    52,    23,   224,    40,   221,    60,
     518,   519,     2,     3,    19,    45,    46,    60,    36,    45,
      71,   529,    73,  1719,  1720,  1721,    21,    48,    13,    62,
      73,    15,   108,    58,    19,    19,     4,    52,    53,    72,
      13,   259,    15,    87,    69,    20,    19,   241,   242,   267,
       5,     6,    87,    88,    89,    90,    91,    55,    60,    19,
      13,    14,    60,    55,   108,    23,    19,   261,    60,    84,
      85,    73,    62,   108,    55,    73,    53,    58,    36,     1,
      13,    73,    14,    14,    65,    66,    67,    68,    20,    20,
      13,    23,    23,    13,    13,    13,    19,    53,    13,    19,
      20,    19,    20,   108,    14,    13,   101,   122,    85,    19,
      20,    19,    13,    97,    98,    28,    14,    30,    19,    13,
      20,    19,   106,    23,    97,    98,   339,   340,    88,    89,
      13,   157,    15,   106,     7,     8,   151,   104,   105,    12,
      53,   156,   157,   158,   159,   160,    13,   102,   103,    13,
     156,    15,   365,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,   579,
     580,   581,   582,   221,   189,   190,   191,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    58,    13,    14,    13,    14,    19,   219,    19,
      14,    19,    13,    14,    19,    14,    20,    15,    19,   230,
     231,    20,    13,   223,    15,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,  1925,
     263,  1927,   241,   242,  1930,  1931,    13,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   324,    14,
      19,    14,   267,   268,    14,    20,   271,    20,   273,    14,
      20,    20,   259,    22,    23,    20,    14,   180,   298,   299,
     300,   301,    20,    14,    14,    13,   291,    14,    14,    20,
      20,   332,    14,    20,    20,   299,   300,    14,    20,    14,
      14,   339,   340,    20,   271,    20,    20,    19,    14,    14,
      14,    14,    14,   521,    20,    20,    20,    20,    20,   319,
     523,   224,   225,   331,   291,   271,    13,   365,    15,    13,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,    14,     0,    14,   291,    14,    14,    20,   349,
      20,    14,    20,    20,   562,    14,    14,    20,    14,    14,
      13,    20,    20,   321,    20,    20,   366,   367,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
      19,    14,    14,   151,   152,   153,  2072,    20,    20,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,    10,    11,    22,    14,   577,   578,   241,   242,   243,
      20,   245,   246,   247,   583,   584,   250,   320,    13,   253,
     254,   255,   256,   257,   258,   259,   260,    14,   262,    13,
      18,    14,   266,    20,   337,   269,   270,    20,   272,    14,
     274,   275,    14,    14,    14,    20,    14,    14,    20,    20,
      20,    14,    20,    20,    14,    14,    14,    20,    14,    14,
      20,    20,    20,    14,    20,    20,    14,    14,    59,    20,
      61,    13,    20,    20,   474,   475,    13,   477,   591,   592,
     593,   594,   595,   596,    13,   523,    13,    13,   488,    13,
     490,   351,   352,   353,    13,   355,   351,   352,   353,    13,
     355,   151,   152,   153,    13,    13,    13,    13,    13,    13,
      13,    13,   523,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   487,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   543,    13,    13,    13,    13,    13,    13,
     453,    13,   455,   456,    13,    13,    13,    13,    13,   570,
      13,    13,    13,    13,    13,   565,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   568,    13,    13,    13,    13,    13,  1085,    13,   797,
    1088,    13,    13,   496,   574,   575,   576,   597,    13,   807,
      13,    13,    13,   603,    13,    13,   606,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   524,    13,    13,    13,    13,    13,    13,    13,   609,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   547,   548,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   567,    13,    13,    13,    13,
      13,    13,     4,   297,    22,   366,    17,    15,   100,    19,
      19,    14,    19,    19,   267,   346,   358,   589,   321,    71,
      14,   151,    14,    16,   108,    14,    22,    71,   151,    20,
      20,    14,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    71,    71,    13,    13,    13,    13,    13,    13,
      13,    55,    13,   291,    55,    14,    16,    14,    20,    56,
      55,    14,    20,    14,    20,    14,    71,    14,    16,    19,
      16,    71,    71,    71,    14,    20,    20,    20,    20,    20,
      13,    20,    20,    20,    20,    20,    20,   650,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    13,    69,    14,
      20,    20,    20,    20,    58,    13,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    20,    14,    20,    22,   322,
      72,    20,    14,    20,    20,    20,    20,    20,    14,    16,
      20,    20,    20,   793,    62,    20,    20,    20,    20,    20,
      20,    20,  1300,    20,    14,    20,    14,    20,    20,    20,
      57,    20,    58,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,  1096,    58,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    20,    20,   585,   261,    14,    20,
      20,    20,    20,    20,    14,    16,    20,    14,    14,    14,
      14,    14,    14,   586,    22,   590,    14,    14,    14,    20,
      20,    20,    14,    14,    13,    20,    20,    20,    13,    58,
      20,    61,    20,    20,    20,    14,    20,    20,    20,    20,
      20,   794,    14,    14,    20,    20,    20,    20,    14,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    70,   587,    13,   901,    16,    13,    13,    20,   919,
     920,    20,    13,   923,   924,    13,   926,   927,   928,   929,
     930,    13,    16,    20,    13,   935,   936,   937,    13,   842,
      13,    13,    20,    20,    14,    14,    20,    14,   588,    20,
      14,   932,    20,    14,    20,    20,    19,    14,   958,   959,
      20,   961,   962,   963,   964,   965,    20,   967,   968,   969,
     970,   971,   972,    20,   974,    14,    14,    14,    20,    14,
      14,   981,   982,   983,   984,   985,   986,   987,   988,  1487,
     990,    14,    20,    20,    14,    14,    14,    14,  1496,    20,
    1498,    14,    55,    14,   916,  1005,    20,    22,    20,  1009,
    1010,  1011,    20,    20,  1014,  1015,  1016,  1017,  1018,  1019,
      20,  1021,    20,    20,  1024,  1025,  1026,  1027,  1028,  1029,
    1030,  1031,  1032,  1033,    20,    20,  1036,   940,    20,   942,
      20,    20,   945,    20,    20,  1045,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1053,  1054,  1055,    20,    20,    20,  1059,
    1060,    20,  1062,  1063,    20,  1065,  1066,  1067,  1068,  1069,
      20,    14,    20,  1073,    20,    20,    20,    14,    20,    20,
      14,  1081,  1082,  1291,  1292,    20,    14,    14,    14,    14,
      20,    20,    58,  1093,    14,    14,    20,    20,    20,    20,
    1100,  1101,    20,  1103,  1104,    20,    14,  1107,  1108,  1109,
      14,  1111,    14,  1113,    14,  1115,  1116,    20,    16,    20,
      14,    20,  1122,    20,    20,    14,  1126,  1127,  1128,    14,
      20,  1131,    20,    20,  1037,    14,  1136,  1137,  1138,  1139,
    1140,  1141,  1142,    20,    20,    20,    14,    14,    14,  1149,
    1150,    14,    14,  1153,    14,    20,    20,  1157,  1158,  1146,
      14,    20,    14,    14,    14,    14,    14,    20,   108,    55,
     259,    14,    55,    20,    20,    20,    20,  1080,    20,    20,
      14,    20,    20,    20,    20,    14,    14,    20,    20,    20,
      20,    14,    14,    20,    20,    20,    20,    14,    14,    20,
      14,    14,    20,    14,   259,    20,    14,    14,    20,    14,
      20,    20,    14,    14,    20,    14,    20,    14,   259,    19,
    1123,    14,    20,    58,    20,    20,    20,  1130,    20,    20,
      20,  1143,    72,    20,    14,    14,  1148,    14,    20,    14,
      14,    22,    20,    14,    20,    14,    -1,    20,    20,   259,
      20,  1154,    20,    20,    20,    20,  1159,  1160,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,  1766,    20,
      20,    20,    20,    14,    14,    20,    14,    20,    20,    -1,
      -1,    20,    14,    20,    20,    20,    20,    20,    14,  1289,
      20,  1499,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    20,    20,    58,    14,    14,    20,
      20,    58,    20,    14,    14,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    -1,   259,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    20,
      20,    14,    14,   259,    20,    20,    20,    14,    14,    20,
      20,    20,    20,   259,  1354,    20,  1356,    20,  1358,    20,
      20,  1361,  1362,  1363,  1364,    20,    20,    20,  1368,    20,
      14,  1371,    14,    20,    20,    20,    -1,    20,    -1,    20,
      20,    20,    20,    20,    20,    14,    14,  1290,  1388,    20,
      20,    14,    14,  1393,    20,    20,    14,  1397,  1398,  1399,
    1400,  1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,
    1410,  1411,  1412,  1413,  1414,  1415,  1416,    20,    20,  1419,
      20,    14,    14,    14,    14,    14,    14,  1427,  1386,    14,
    1638,    14,  1640,  1433,  1434,  1435,  1436,  1645,  1438,  1439,
    1440,  1353,  1442,  1443,    20,    20,    20,    20,    20,  1449,
    1450,  1451,  1452,    20,    20,    20,    20,    20,  1458,    14,
      20,  1461,  1462,    20,    14,    14,    14,    14,    14,    14,
      22,  1471,  1472,  1473,  1474,    14,    14,    14,    14,    14,
      14,    22,    14,    14,  1484,  1485,  1486,    20,    14,    14,
      20,  1491,    14,    14,    14,    14,    20,    20,    14,    14,
      14,  1501,  1502,    20,  1504,  1505,    14,  1507,  1508,  1509,
      14,    14,    14,  1513,  1514,    20,    14,  1517,    14,    14,
    1520,    20,  1522,  1523,  1524,    14,    20,    20,    14,  1529,
      14,    -1,  1532,    20,  1534,    20,    14,    20,  1538,  1539,
    1540,    20,  1542,    20,    20,    14,  1546,    20,    14,    20,
      20,   600,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    14,    20,    14,    -1,    -1,    20,
    1570,    20,    -1,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    14,    14,    14,    14,    14,
      20,    14,    -1,    -1,    -1,    -1,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    14,    20,    14,
      14,    14,    20,    14,    20,    -1,    14,    14,    20,    14,
      20,    20,    14,    -1,    20,    14,    20,    20,    -1,    20,
      20,  1543,    20,    20,    20,    20,    20,  1637,    20,    20,
      14,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1872,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1678,    -1,
    1680,    -1,  1682,  1683,  1684,  1685,    -1,    -1,    -1,  1689,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1697,  1698,    -1,
      -1,  1701,    -1,  1703,    -1,  1705,    -1,  1707,  1708,  1709,
    1710,    -1,  1712,  1713,  1714,  1715,  1716,  1717,    -1,  1719,
    1720,    -1,  1722,  1723,  1724,  1725,    -1,  1727,  1728,  1729,
    1730,  1731,    -1,  1733,    -1,    -1,    -1,  1695,    -1,    -1,
      -1,    -1,    -1,  1743,  1744,  1745,  1746,  1747,  1748,  1749,
      -1,    -1,  1752,    -1,    -1,  1755,  1756,    -1,  1758,  1759,
    1760,    -1,    -1,    -1,  1764,  1765,    -1,    -1,  1768,    -1,
      -1,    -1,  1675,  1676,    -1,  1775,  1776,    -1,  1778,    -1,
      -1,    -1,  1782,  1783,    -1,  1785,  1786,    -1,  1788,    -1,
    1790,  1791,    -1,  1793,    -1,  1795,  1796,  1797,    -1,  1799,
    1800,  1801,  1802,    -1,  1804,  1805,    -1,    -1,    -1,  1721,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1803,    -1,    -1,    -1,    -1,    -1,    -1,  1898,    -1,
    1900,  1901,  1902,    -1,  1904,    -1,    -1,    -1,  1908,  1909,
      -1,  1911,    -1,  1913,  1914,  1915,  1916,  1917,    -1,  1919,
    1920,  1921,  1922,  1923,  1924,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1932,  1933,  1934,    -1,    -1,     0,     1,    -1,
    1940,  1941,    -1,    -1,  1944,    -1,  1946,  1947,    -1,  1907,
    1950,  1951,    -1,  1953,  1954,    -1,    -1,    -1,    -1,    22,
    1960,    -1,    25,    -1,    -1,    -1,    -1,  1967,  1968,  1969,
      -1,    -1,  1972,  1973,  1974,  1975,    -1,  1977,    -1,    -1,
    1980,  1981,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1925,    -1,  1927,    -1,    -1,  1930,  1931,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2051,    -1,    -1,  2054,    -1,    -1,    -1,    -1,    -1,
    2060,    -1,  2062,    -1,  2064,    -1,    -1,  2067,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1988,  2077,  2078,    -1,
    2080,    -1,    -1,  2083,  2084,  2085,  2086,  2087,    -1,    -1,
      -1,  2091,    -1,  2093,    -1,    -1,  2096,  2097,  2098,  2099,
      -1,  2101,  2102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2130,  2131,    -1,    -1,    -1,  2135,    -1,  2137,  2138,    -1,
    2140,  2141,  2142,    -1,  2144,  2145,    -1,  2147,  2148,  2149,
      -1,  2151,    -1,  2153,  2154,    -1,  2156,    -1,   221,    -1,
    2072,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2182,    -1,    -1,    -1,  2186,  2187,  2188,    -1,
      -1,  2191,  2192,    -1,    -1,  2195,   259,    -1,  2198,  2199,
    2200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2215,    -1,    -1,  2218,    -1,
      -1,    -1,  2222,    -1,    -1,  2225,  2226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2237,    -1,    -1,
    2240,    -1,    -1,    -1,    -1,  2245,  2246,  2247,    -1,    -1,
      -1,  2251,  2252,    -1,    -1,     0,  2256,  2257,    -1,     4,
    2260,  2261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,   339,   340,    -1,    -1,
      -1,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   365,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,   381,   382,
     383,   384,   385,    -1,   387,   388,   389,   390,   391,   392,
     393,   394,   395,    -1,    -1,   398,    -1,    -1,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,    -1,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,    -1,    -1,    -1,    -1,    -1,    -1,
     433,   434,   435,   436,   437,   438,   439,   440,   441,    -1,
      -1,   444,   445,   446,   447,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   457,   458,   459,    -1,    -1,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
      -1,    -1,    -1,   476,   477,    -1,   479,    -1,   481,    -1,
      -1,    -1,   485,   486,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,    -1,   500,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   532,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   550,   551,   552,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   567,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   320,   321,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   337,    -1,    -1,    -1,    -1,   342,   343,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   370,   371,   372,   373,   374,
     375,   376,   377,    -1,   379,   380,    -1,    -1,    -1,    -1,
      -1,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   396,   397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   411,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   426,   427,   428,   429,   430,   431,   432,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   449,   450,   451,    -1,   453,    -1,
     455,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   473,    -1,
      -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,    -1,   484,
      -1,    -1,   487,    -1,    -1,    -1,   491,   492,   493,   494,
     495,   496,   497,   498,   499,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   524,
     525,    -1,    -1,    -1,    -1,   530,   531,    -1,   533,   534,
      -1,   536,   537,   538,   539,   540,   541,   542,    -1,   544,
     545,   546,   547,   548,   549,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     565,    -1,    -1,   568,   569,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   916,   599,   600,    -1,    -1,    -1,    -1,
      -1,   606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   957,    -1,    -1,   642,   643,    -1,
      -1,    -1,    -1,   966,    -1,   650,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   977,   978,   979,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   989,    -1,    -1,    -1,
      -1,   994,    -1,   996,   997,   998,   999,  1000,    -1,  1002,
    1003,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1034,    -1,    -1,    -1,    -1,    -1,  1040,  1041,  1042,
    1043,  1044,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1102,
      -1,    -1,  1105,    -1,    -1,    -1,    -1,    -1,    -1,   794,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1124,  1125,    -1,    -1,    -1,    -1,    -1,    -1,  1132,
      -1,  1134,  1135,  1136,  1137,    -1,    -1,    -1,    -1,    -1,
    1143,    -1,    -1,    -1,    -1,  1148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   842,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   867,    -1,    -1,    -1,    -1,  1190,  1191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   901,   902,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     925,    -1,    -1,    -1,    -1,    -1,   931,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   940,    -1,   942,    -1,    -1,
     945,    -1,    -1,    -1,    -1,   950,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     975,   976,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1007,    -1,    -1,    -1,    -1,  1012,  1013,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1353,  1354,  1037,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1386,  1387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1396,    -1,  1080,    -1,    -1,    -1,    -1,
      -1,  1404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1420,  1421,  1422,
    1423,  1424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1114,
      -1,    -1,  1117,  1118,    -1,    -1,    -1,    -1,  1123,    -1,
      -1,    -1,    -1,    -1,    -1,  1130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1459,  1460,    -1,    -1,
      -1,  1146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1154,
      -1,    -1,    -1,  1476,  1159,  1160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1185,    -1,    -1,    -1,  1189,   371,   372,   373,   374,   375,
     376,   377,    -1,   379,   380,    -1,  1519,    -1,    -1,    -1,
     386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     396,   397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1543,    -1,    -1,    -1,    -1,   411,    -1,    -1,    -1,  1234,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,   427,   428,   429,   430,   431,   432,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   449,   450,   451,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1290,    -1,   473,    -1,    -1,
      -1,    -1,   478,    -1,    -1,    -1,    -1,    -1,   484,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   497,   498,   499,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1339,    -1,    -1,    -1,    -1,   525,
      -1,    -1,    -1,    -1,   530,   531,    -1,   533,   534,    -1,
     536,   537,   538,   539,   540,   541,   542,    -1,   544,   545,
     546,    -1,    -1,    -1,    -1,    -1,    -1,  1372,    -1,    -1,
      -1,    -1,  1695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1732,
      -1,    -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1753,  1754,    -1,  1438,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1453,    -1,
      -1,    -1,  1457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1787,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1482,    -1,    -1,
    1803,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1512,    -1,    -1,
    1515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1907,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1935,  1936,  1937,  1938,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1957,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1976,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1988,    -1,    -1,    -1,    -1,
    1675,  1676,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1737,    -1,  1739,  1740,    -1,  1742,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2089,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1780,    -1,  2100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   975,
     976,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1007,    -1,  2146,    -1,    -1,  1012,  1013,    -1,    -1,
      -1,    -1,  2155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2241,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1114,    -1,
      -1,  1117,  1118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1956,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1971,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1185,
      -1,    -1,    -1,  1189,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2095,    -1,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,    55,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2177,    -1,    -1,    -1,    -1,    -1,    -1,  2184,
      -1,    97,    98,    -1,    -1,  2190,  1372,    -1,    -1,    -1,
      -1,    -1,  2197,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,   123,    -1,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,  2224,
     136,    -1,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,    -1,   154,   155,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,  1453,    -1,    -1,
      -1,  1457,   188,    -1,    -1,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,  1482,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,   227,   228,   229,    -1,    -1,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    -1,  1512,    -1,    -1,  1515,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,   264,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,    -1,   292,    -1,   294,   295,
      -1,   297,    -1,    -1,    -1,    -1,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,    -1,   312,   313,   314,   315,
     316,   317,   318,   319,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   347,   348,   349,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   359,   360,   361,   362,    -1,   364,   365,
      -1,   367,   368,   369,   370,   371,   372,   373,    -1,   375,
     376,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1737,    -1,  1739,  1740,    -1,  1742,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,   123,    -1,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,  1780,    -1,   136,    -1,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,   227,   228,   229,
      -1,    -1,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,    -1,   292,    -1,   294,   295,    -1,    -1,    -1,    -1,
      -1,    -1,   302,   303,   304,   305,   306,   307,   308,   309,
    1956,    -1,   312,   313,   314,   315,   316,   317,   318,   319,
      -1,    -1,    -1,    -1,    -1,  1971,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   348,   349,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   359,
     360,   361,   362,    -1,   364,   365,    -1,   367,   368,   369,
     370,   371,   372,   373,    -1,   375,   376,   377,   378,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,  2095,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,    51,    -1,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,  2177,    -1,    -1,    -1,    -1,    -1,    -1,  2184,    -1,
      -1,    -1,    97,    98,  2190,    -1,    -1,    -1,    -1,    -1,
      -1,  2197,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,  2224,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,    -1,   154,
     155,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,    -1,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,    -1,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    -1,   292,   293,   294,
     295,   296,    -1,    -1,    -1,    -1,    -1,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    -1,    -1,    -1,    -1,
     325,    -1,   327,   328,   329,    -1,    -1,    -1,   333,   334,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   347,   348,   349,   350,    -1,    -1,    -1,    -1,
      -1,   356,   357,    -1,   359,   360,   361,   362,    -1,   364,
     365,    -1,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    51,    -1,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,    -1,   154,   155,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,    -1,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,    -1,    -1,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,    -1,   292,   293,   294,   295,   296,
      -1,    -1,    -1,    -1,    -1,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,   312,   313,   314,   315,   316,
     317,   318,   319,   320,    -1,    -1,    -1,    -1,   325,    -1,
     327,   328,   329,    -1,    -1,    -1,   333,   334,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     347,   348,   349,   350,    -1,    -1,    -1,    -1,    -1,   356,
     357,    -1,   359,   360,   361,   362,    -1,   364,   365,    -1,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,   227,   228,
     229,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,    -1,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,   312,   313,   314,   315,   316,   317,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   348,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,    -1,   364,   365,    -1,   367,   368,
     369,   370,   371,   372,   373,    -1,   375,   376,   377,   378,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,   227,   228,
     229,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,    -1,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,   312,   313,   314,   315,   316,   317,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   348,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,    -1,   364,   365,    -1,   367,   368,
     369,   370,   371,   372,   373,    -1,   375,   376,   377,   378,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,   227,   228,
     229,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,    -1,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,   312,   313,   314,   315,   316,   317,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   348,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,    -1,   364,   365,    -1,   367,   368,
     369,   370,   371,   372,   373,    -1,   375,   376,   377,   378,
       9,    10,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,   227,   228,
     229,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,    -1,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,   312,   313,   314,   315,   316,   317,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   348,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,    -1,   364,   365,    -1,   367,   368,
     369,   370,   371,   372,   373,    -1,   375,   376,   377,   378,
       9,    10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,   227,   228,
     229,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,    -1,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,   312,   313,   314,   315,   316,   317,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   348,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,    -1,   364,   365,    -1,   367,   368,
     369,   370,   371,   372,   373,    -1,   375,   376,   377,   378,
       9,    10,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,   227,   228,
     229,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,    -1,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,   312,   313,   314,   315,   316,   317,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   348,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,    -1,   364,   365,    -1,   367,   368,
     369,   370,   371,   372,   373,    -1,   375,   376,   377,   378,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,   227,   228,
     229,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,    -1,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,   312,   313,   314,   315,   316,   317,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   348,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,    -1,   364,   365,    -1,   367,   368,
     369,   370,   371,   372,   373,    -1,   375,   376,   377,   378,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,   227,   228,
     229,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,    -1,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,   312,   313,   314,   315,   316,   317,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   348,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,    -1,   364,   365,    -1,   367,   368,
     369,   370,   371,   372,   373,    -1,   375,   376,   377,   378,
       9,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,    -1,   227,   228,
     229,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,    -1,   302,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   348,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,    -1,   364,   365,    -1,   367,   368,
     369,   370,   371,   372,   373,    13,   375,   376,   377,   378,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,   123,    -1,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,   227,
     228,   229,    -1,    -1,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,
      -1,    -1,    -1,    -1,   302,   303,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,
     348,   349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   359,   360,   361,   362,    13,   364,   365,    -1,   367,
     368,   369,   370,   371,   372,   373,    -1,   375,   376,   377,
     378,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    53,    54,    55,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,   123,    -1,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,   136,    -1,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,   154,   155,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,   227,
     228,   229,    -1,    -1,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,    -1,   292,    -1,   294,   295,    -1,    -1,
      -1,    -1,    -1,    -1,   302,   303,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,
     348,   349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   359,   360,   361,   362,    -1,   364,   365,    -1,   367,
     368,   369,   370,   371,   372,   373,    -1,   375,   376,   377,
     378
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     9,    10,    11,    13,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    41,    42,    43,    44,    45,    46,    47,    49,
      50,    51,    53,    54,    55,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    78,    79,    80,    81,    82,
      83,    97,    98,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   154,   155,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   264,   265,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   292,   293,
     294,   295,   296,   302,   303,   304,   305,   306,   307,   308,
     309,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     325,   327,   328,   329,   333,   334,   347,   348,   349,   350,
     356,   357,   359,   360,   361,   362,   364,   365,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   391,   392,
     393,   394,   395,   396,   399,   400,   401,   402,   406,   410,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   437,   438,   439,   440,   441,   442,   443,   446,
      13,    62,    64,    71,    73,   141,   142,   415,   419,   415,
     421,   421,   414,   435,    20,   411,   435,   411,   411,    13,
      13,    13,   413,   435,    71,   332,   415,    55,    65,    66,
      67,    68,   439,   415,   435,   435,   413,    13,   413,    13,
      13,    19,    88,    89,    19,   108,   439,   156,    19,    15,
      59,    61,    62,    63,    64,    70,    71,    72,    73,   415,
     441,   443,   444,   445,   413,    13,    13,    13,   420,   421,
      13,    13,    15,    13,    13,    15,    13,    15,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    19,
      19,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    15,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    15,   413,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   439,   407,   408,   445,   411,
     393,   413,   413,    13,    13,    13,    13,    69,   439,   439,
      13,    13,    13,    13,    13,    19,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,     0,     0,   393,   394,   395,   396,   399,
     400,   401,   402,   393,    19,    13,    19,    22,    13,    15,
      19,    97,    98,   106,     7,     8,    12,    10,    11,     5,
       6,   102,   103,   104,   105,    17,    18,   100,     4,    21,
     101,    87,    88,    89,    90,    91,   108,    13,    19,    87,
     108,    19,    19,    15,    19,    19,    13,    19,    19,    14,
      14,    22,   411,   413,   414,   413,   445,   445,   241,   242,
     243,   245,   246,   247,   250,   253,   254,   255,   256,   257,
     258,   259,   260,   262,   266,   269,   270,   272,   274,   275,
     435,   435,    45,    46,   298,   299,   300,   301,   297,    45,
     157,   411,   445,   411,   411,   412,   435,   412,   435,   412,
     412,   412,   412,   412,   412,   415,   412,   412,   415,   415,
     415,   415,   415,   412,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   412,   412,   415,   151,   152,   153,   151,
     152,   153,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   412,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   412,   415,   412,
     412,   412,   412,   412,   412,   415,   415,   415,   415,   415,
     415,   415,   415,   415,    71,    71,   415,   415,   415,   415,
      71,   412,   412,   412,    71,   413,    71,   413,   413,   415,
     415,   415,    55,    55,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   412,   411,   411,   415,   411,
     415,   412,   415,    71,   415,    71,    71,   412,   415,   415,
      14,   411,   411,   435,   435,   435,   435,   435,   413,   412,
     412,   412,   415,   108,   324,    56,   407,   407,   393,   439,
     445,   413,   412,    55,   398,   397,    22,   407,   412,   412,
     415,   412,   412,   366,   412,   412,   412,   412,   412,   412,
     412,   411,   412,   412,   412,   413,   413,   435,   415,   415,
     415,   393,   346,   411,   435,    52,    53,    84,    85,   122,
     151,   156,   157,   158,   159,   160,   189,   190,   191,   267,
     268,   271,   273,   291,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   419,    17,    62,    64,
     404,   435,   443,   435,   439,   421,   421,   421,   422,   422,
     424,   424,   424,   424,   425,   425,   426,   428,   429,   430,
     419,   431,   434,   434,   434,   434,   434,   434,   411,   267,
     412,    17,    37,    40,    62,    72,   263,   281,   284,   297,
     435,   436,   442,   411,   411,   421,    20,    14,    14,    20,
      20,    14,    14,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   435,   435,
      13,    13,    13,   413,    16,    20,    14,    20,    14,    14,
      20,    16,    14,    14,    16,    14,    16,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    13,    13,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    20,    14,    20,    14,    20,    16,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    14,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      20,    14,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    14,    16,    20,    14,    14,    14,    14,    14,    14,
      20,    20,    20,    14,   411,   403,   413,   409,   331,   393,
      14,    14,    14,    20,    14,    13,    13,   358,   393,    14,
      20,    20,    20,    20,    20,    13,    14,    20,    20,    20,
      14,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      14,    14,    20,    20,    20,    20,    20,    22,    23,    14,
      13,    13,    13,   413,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    20,   435,    14,    20,    16,    22,    20,
      13,   435,   443,    15,    13,    19,    13,    13,    13,    13,
      20,    16,   419,   411,   411,   411,   411,   435,   411,   411,
     411,   411,   411,   435,    62,   436,    62,    57,   411,   411,
     411,   413,    59,    61,   413,   108,   413,    69,   435,    13,
      13,    13,    55,   415,   411,   411,   411,   411,   411,   411,
     411,   415,   411,   411,   411,   411,   411,   411,   411,   412,
     412,   415,   415,   415,   411,   411,   411,   411,   411,   411,
     411,   411,   415,   411,   415,   415,   415,   415,   415,   415,
     415,   415,   411,   412,    13,   411,   411,   411,   412,   412,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   415,   411,   413,
     415,   415,   415,   415,   415,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   413,   411,   411,   321,
      20,   407,   407,   411,   351,   352,   353,   355,   405,   405,
      70,   411,   411,   415,   411,   411,   415,   411,   411,   411,
     411,   411,   412,   411,   411,   412,   412,   411,   413,   415,
     415,   411,   411,   411,   413,   411,   415,   415,   415,   411,
     415,   411,   415,   411,   411,   411,   411,   411,   419,    17,
     435,   443,   419,   411,   411,   411,   413,   261,    72,   411,
     411,   413,   413,    22,    20,    14,    20,    14,    20,    14,
      14,    20,    20,    20,    20,    14,    19,    14,    20,    14,
      20,    20,    20,    14,    14,    14,    14,    20,   412,    14,
      14,    14,   412,   415,   415,    14,    20,    20,    20,    14,
      14,    14,    14,    20,    14,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    14,    14,    20,    14,   412,
      14,    14,    14,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    14,    14,    14,    14,    14,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    20,    14,    20,    14,    14,    14,
      14,    14,    20,    14,    20,    20,    20,   411,   413,   393,
     393,    20,    58,    58,    58,    58,    14,    20,    14,   407,
      14,    20,    20,    14,    20,    20,    14,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    14,    20,    14,    20,
      20,    14,    20,    23,    20,    14,    14,    20,    14,    20,
      14,    14,    20,    14,    20,    14,    14,    14,    20,    20,
      20,    14,    20,    22,   435,    14,    20,    16,    14,    20,
      14,    14,    20,   419,   411,   415,   411,   411,   411,   411,
     411,   411,   411,   415,   411,   412,    55,    14,    14,    14,
      20,   414,   415,    55,   415,   411,   411,   415,   411,   411,
     411,   411,   411,   411,   411,   411,   415,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     415,   415,   415,   415,   415,   411,    14,   411,   411,   411,
     411,   411,   435,   411,   411,   411,   411,   411,   411,   411,
     411,   412,   412,   411,   415,   415,   411,   411,   411,   411,
     411,   411,   415,   412,   411,   411,   411,   322,   407,   411,
     407,   351,   352,   353,   355,   407,   393,   411,   411,   411,
     411,   411,   411,   411,   412,   411,   411,   412,   411,   415,
     411,   411,   411,   411,   435,   411,   411,   411,   411,   411,
     411,   411,   419,   411,    72,    20,    20,    55,    20,    14,
      20,    14,    20,    20,    20,    20,    14,    14,    14,    20,
      14,   411,    14,    19,    14,    20,    20,    20,    20,    14,
      14,    20,    14,    20,    14,    20,    14,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    14,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    14,    14,    20,    20,   411,   393,    20,   393,
      58,    58,    58,    58,   393,    20,    20,    14,    20,    14,
      20,    14,    20,    20,    14,    20,    20,    20,    20,    14,
      20,    23,    14,    22,    14,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,   413,   413,    14,   411,
     411,   411,   411,   411,   411,   411,    14,   414,    55,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   446,   411,   446,   419,   446,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   415,
     411,   412,   412,   412,   412,   411,   411,   411,   411,   411,
     411,   411,   411,   415,   415,   411,   411,   411,   411,   411,
     411,   411,   407,   411,   411,   411,   411,   412,   411,   411,
     411,   411,   415,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   419,   411,   411,    14,    20,    14,
      20,    20,    20,    14,    20,    14,    14,    20,    20,    20,
      14,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    14,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    14,    14,    20,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    14,    20,    20,    14,    14,
      20,    14,    14,    14,    14,    14,   393,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      20,    20,    14,    14,    14,    14,    14,    14,    22,    14,
      14,   411,   411,   411,   411,   411,   414,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   446,   446,   446,   446,   411,   411,   411,   415,   415,
     415,   415,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   412,   415,   411,   411,   411,   411,   412,   411,   411,
     411,   411,   415,   411,   411,   411,   419,    14,    14,    14,
      14,    20,    14,    14,    20,    14,    14,    14,    14,    14,
      20,    14,    20,    14,    20,    14,    14,    20,    14,    14,
      14,    14,    20,    14,    14,    14,    14,    20,    20,    14,
      20,    14,    14,    20,    20,    20,    20,    20,    14,    20,
      14,    20,    14,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    22,    14,   411,   411,   411,   411,   411,   411,
     446,   411,   411,   411,   411,   411,   411,   411,   411,   415,
     411,   411,   412,   411,   411,   411,   411,   415,   411,   411,
      20,    20,    14,    14,    14,    20,    14,    20,    20,    14,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      14,    20,    14,    20,    20,    20,    20,    14,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   415,   411,
     411,   411,   411,   411,   411,   415,   411,   108,    14,    14,
      14,    14,    20,    14,    20,    14,    20,    20,    20,    14,
      20,    20,    20,    14,    14,    20,    14,    20,    20,    20,
      20,   412,   411,   412,   411,   411,   411,   412,   411,   411,
     411,   412,   411,   411,   411,    20,    14,    14,    20,    14,
      14,    14,    20,    14,    20,    20,    20,    20,   411,   411,
     411,   412,   411,   411,   415,    14,    14,    20,    14,    14,
      20,    20,   411,   411,   415,    20,    20,    20,   411,   411,
     411,    20,    20,    14,   411,   411,    20,    20,   411,   411,
      20,    20,   411,   411,    14,    14
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   390,   391,   391,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     393,   393,   394,   394,   394,   394,   394,   395,   395,   397,
     396,   398,   396,   399,   399,   400,   401,   401,   401,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   403,   403,   404,
     404,   404,   404,   404,   404,   404,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   406,   406,   406,   406,   406,
     406,   406,   407,   408,   409,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   411,   412,   413,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     415,   415,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   417,   418,
     418,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   422,   422,   422,   422,   423,   423,   423,   424,   425,
     425,   425,   425,   425,   426,   426,   426,   427,   427,   428,
     429,   429,   430,   430,   431,   431,   432,   432,   433,   433,
     434,   434,   434,   434,   434,   434,   434,   435,   436,   436,
     436,   436,   437,   437,   437,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   439,
     440,   441,   441,   441,   441,   441,   442,   442,   442,   442,
     443,   443,   444,   444,   444,   444,   444,   445,   445,   445,
     446,   446,   446,   446
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     8,    10,     6,     2,     3,     4,     6,     0,
       8,     0,     8,     4,     7,     2,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     4,
       4,     3,     5,     3,     6,     3,     6,     3,     6,     8,
       6,     8,     8,     8,     3,     1,     1,     2,     2,     1,
       1,     2,     4,     4,     1,     2,     2,     2,     8,    16,
       2,     6,     2,     2,     2,     1,     1,     2,     2,     2,
       2,     2,     2,     4,     4,     2,     2,     2,     3,     3,
       3,     2,     6,    10,     6,    10,     8,    10,    12,     6,
       6,     3,     3,     3,     3,     4,     3,     6,     6,     4,
      20,    10,     6,     3,     3,     6,     3,     6,     8,     6,
       6,     8,    16,     6,     3,     6,     8,     3,    12,    12,
      12,    10,     3,     3,     8,     8,    10,     8,    10,    12,
       6,     8,    10,    16,    18,    12,     6,    18,    16,    12,
      10,    10,    10,     6,    10,     6,     6,     6,     8,     4,
       4,     8,     4,    18,     4,     1,     1,     1,     6,     3,
       4,     1,     1,     1,    30,    24,     8,     1,     3,     0,
       1,     3,     2,     4,     1,     3,     0,     2,     2,     2,
       2,     4,     4,     4,     4,     1,     6,     1,     3,     4,
       4,     1,     3,     0,     0,     1,     1,     1,     1,     6,
       8,    10,    10,    10,     8,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     6,     4,
      10,     4,    10,     4,     4,     4,     4,     4,     4,     7,
       7,     7,     9,     7,     6,     4,     6,    10,     4,     4,
       4,     3,     6,     6,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     1,     2,     4,     4,     1,    10,    12,     8,
       6,     6,     6,     8,     8,     6,     8,     8,    10,    10,
      12,    12,    10,     4,    10,     4,     6,     4,     4,     4,
      12,     4,    12,    12,    16,    20,    10,    12,     4,     6,
       6,     6,     4,     4,     6,     4,     6,     6,     6,    16,
      10,     8,    12,    10,     8,    12,     8,    12,     8,    12,
      12,    14,    12,    12,    16,     4,     8,    10,    12,    10,
      12,    10,    12,    12,    14,    12,     8,    14,     4,     4,
       4,     4,     3,     3,     6,     6,     6,     6,     8,    14,
      12,    14,    12,     6,     8,    10,    10,    12,     6,     6,
       6,     6,     6,     6,     6,     6,     8,    10,     4,     4,
      10,    10,     4,     6,     6,    12,    30,     8,     6,     4,
       6,     4,     6,     4,     4,    18,     8,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       6,     3,     1,     1,     3,     4,     2,     2,     2,     2,
       4,     1,     4,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     3,
       8,     4,     6,     1,     4,     6,     6,     8,     8,     4,
       6,     6,     6,     6,     3,     2,     4,     6,     4,     4,
      10,     6,    16,    18,    10,    20,    14,     4,     6,     8,
       8,    12,    16,    16,    18,    14,    14,    16,    20,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      11,     7,     7,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "LEX_ERROR", "T_EXP", "T_GT",
  "T_LT", "T_MULT", "T_DIV", "T_NOT", "T_ADD", "T_SUB", "T_MOD",
  "T_OP_PAR", "T_CL_PAR", "T_OP_BR", "T_CL_BR", "T_AND", "T_OR", "T_POINT",
  "T_COMMA", "T_QUEST", "T_COLON", "T_SEMICOLON", "T_SetDebugOn",
  "T_SetDebugOff", "T_TraceScanning", "T_TraceParsing",
  "T_NoMessageDialog", "T_SetVerboseOn", "T_SetVerboseOff",
  "T_SetProgress", "T_SetStatusText", "T_GetScriptsDir", "T_argc",
  "T_emptyargs", "END_INSTRUCTION", "T_Image", "T_BrowseImage",
  "T_ReadRawImages", "T_Transform", "SHOW", "HELP", "QUIT", "T_HIDE",
  "PRINT", "PRINTN", "T_InfoDialog", "T_boost_format", "T_SPRINT",
  "ASHELL", "LS", "T_SetName", "T_GetName", "T_GetObjectName", "ASTRING",
  "ABLOCK", "NUMBER", "IDENTIFIER", "PROCESSED_VAR", "VAR_IMAGE",
  "VAR_STRING", "VAR_SURFDRAW", "VAR_MATRIX", "VAR_FILE", "VAR_C_FUNCTION",
  "VAR_C_PROCEDURE", "VAR_CLASS_MEMBER", "VAR_C_IMAGE_FUNCTION",
  "VAR_AMI_FUNCTION", "VAR_AMI_CLASS", "VAR_AMI_OBJECT", "VAR_GLTRANSFORM",
  "VAR_ARRAY_IMAGE", "T_del", "T_delvars", "T_Comments", "ENDOP",
  "T_global", "T_local", "T_global_new", "T_local_new", "T_wait",
  "T_schedule", "T_SetComponent", "T_GetExtent", "RIGHT_ASSIGN",
  "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP",
  "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "TRANSPOSE_OP", "POINTWISE_MULT", "ASSIGN_OP",
  "T_COUNT", "T_MAX", "T_argmax", "T_MIN", "T_MEDIAN", "OpImage", "FILTER",
  "NormGrad", "T_DiscNormGrad", "T_gradient", "SecDerGrad", "SecDerGrad2",
  "SubImage", "PutImage", "T_AutoCrop", "T_DiscSecDerGrad", "T_EDPdilate",
  "T_EDPerode", "T_EDPopen", "T_EDPclose", "AnisoSmoothGS", "T_vtkAnisoGS",
  "T_DiscMeanCurvature", "T_vtkMedian3D", "T_NULL", "T_RestartTime",
  "T_InitTime", "T_TimeSpent", "T_EndTime", "T_vtkFastMarching",
  "T_vtkFastMarchingTarget", "T_FluxDiffusion", "T_AnisoWeickert",
  "T_AnisoCW", "T_SRAD_qcoeff", "T_AnisoSRAD", "T_AnisoSRAD2",
  "T_AnisoLeeAdd2", "T_AnisoDPAD", "T_AnisoDPAD2", "T_AnisoNRAD",
  "T_AnisoRudinMult", "TInit", "TIterate", "TEnd", "TAddGaussNoise",
  "T_SNR", "T_info", "T_save", "T_normalize", "T_OrientField",
  "T_OrientPositive", "T_2DFlux", "T_OutFlux", "T_OutFluxScalar",
  "T_OrientationRatio", "T_Skeleton", "T_SimplePoints", "T_CircleIntegral",
  "T_CircleIntegralExc", "T_CircleIntSdExc", "T_CircleMinIntSdExc",
  "T_LocalExtrema", "T_NormalField", "T_DirConnectivity", "T_eccentricity",
  "T_rot2D", "T_mean", "T_SUM", "T_localmean", "T_localmean2", "T_localSD",
  "T_localSD2", "T_struct_tensor", "T_StructTensorH", "T_HessianMatrix",
  "T_HessianEVal", "T_Derivatives", "T_curvatures", "T_Laplacian",
  "T_setvoxelsize", "T_settranslation", "T_setendianness",
  "T_Skeleton2lines", "T_SmoothLines", "T_ResampleLines", "T_threscross",
  "T_IsocontourPoints", "T_IsosurfDist", "T_vtkIsoContourDist",
  "T_ShortestPath", "T_ShortestPathImage", "T_PathFromDispl",
  "T_PathFromVectField", "T_LineRecons", "T_ReadCTALine",
  "T_ReadCTALineRadii", "T_vtkDicomRead", "T_vtkMINCRead", "T_Convolve",
  "T_ConvolveMask", "T_Pad", "T_Eigen2D", "T_Eigen3D", "T_ChamferDT",
  "T_Chamfer2DT", "T_BorgeforsDT", "T_BorgeforsSDT",
  "T_vtkSignedBorgefors", "T_vtkSignedFMDist", "T_PropagationDist",
  "T_PropagationDist2", "T_PropDanielsson", "T_vtkPropDanielsson",
  "T_vtkPropDaniel2", "T_CC", "T_ProcessXEvents", "T_ProcessEvents",
  "T_isoarea2D", "T_posarea", "T_isosurf", "T_isosurf_inv",
  "T_isosurf_ijk", "T_isosurf_ras", "T_vtkDecimate", "T_vtkMarchingCubes",
  "T_vtkSmooth", "T_vtkWindowedSinc", "T_isoline", "T_vtkDist",
  "T_AndreDist", "T_Surface", "T_getimage", "T_GetImageFromX", "T_rotate",
  "T_computeCC", "T_drawCC", "T_addobj", "T_setcurrentobj", "T_writeVRML",
  "T_writeVTK", "T_Paint", "T_SetLight", "T_SetLightPos",
  "T_SetLightAmbient", "T_SetLightDiffuse", "T_SetLightSpecular",
  "T_SetBackground", "T_Normalize", "T_Center", "T_Remove",
  "T_SwapBuffers", "T_GetTransform", "T_SetTransform", "T_Interpolate",
  "T_Matrix", "T_Invert", "T_PrintMatrices", "SET", "SETPOS", "COMPARE",
  "SETVECTOR", "T_lininterp", "T_SetWindowSize", "T_initvalue",
  "T_ShowSection", "T_HideSection", "T_Xpos", "T_Ypos", "T_Zpos",
  "T_SpacePos", "T_CHAR", "T_UCHAR", "T_SHORT", "T_USHORT", "T_INT",
  "T_UINT", "T_LONG", "T_FLOAT", "T_DOUBLE", "T_RGB", "T_FLOAT_VECTOR",
  "T_GetFormat", "T_atof", "T_gnuplot", "T_histo", "T_cumhisto",
  "T_DisplayHisto", "T_OPEN", "T_CLOSE", "T_scan_float", "T_read",
  "T_rewind", "T_LineNumber", "CONST_PI", "SIN", "COS", "TAN", "ASIN",
  "ACOS", "ATAN", "SINH", "COSH", "EXP", "LN", "LOG", "SQRT", "ABS",
  "ROUND", "FLOOR", "NORM", "FOR", "TO", "STEP", "ENDFOR", "T_IN",
  "T_REPEAT", "T_UNTIL", "T_WHILE", "T_BREAK", "IF", "THEN", "ELSE",
  "VARIABLES", "FUNCTION", "T_eval", "T_tx", "T_ty", "T_tz", "T_trx",
  "T_try", "T_trz", "T_vx", "T_vy", "T_vz", "T_vdim", "T_inc", "T_val",
  "T_exists", "T_FileExists", "T_slice", "T_GenRead", "T_IMAGE", "T_NUM",
  "T_STRING", "T_TRANSFORM", "T_OBJECT", "T_PROC", "T_Class", "T_public",
  "T_MeanHalfSize", "T_Resize", "T_ReSlice", "T_Flip", "T_SetCompTransf",
  "T_ConvexHull", "T_itk", "T_CannyEdgeDetector", "T_CreateFlatMesh",
  "T_CreateVolume", "T_vtkCreateFlatMesh", "T_Altitude2Position",
  "T_GeoCoordinates", "T_CreateVectors", "T_CreateVectorsFromField",
  "T_Set3DArrowParam", "T_CreateEllipsoids", "T_ComputeAltitudes",
  "T_Temp2Altitudes", "T_ReadFlow", "T_SetFluidNavFile",
  "T_DrawEarthCoord", "T_SaveStructuredGrid", "T_import_vtk",
  "T_import_wii", "T_import_filters", "T_amiOFCorr2D", "T_amiOFVar2D",
  "SHIFT_THERE", "prefix", "postfix", "$accept", "start", "list_commands",
  "end_instr", "loop_inst", "cond_inst", "proc_decl", "@1", "@2",
  "class_decl", "object_decl", "func_inst", "command", "exprstringlist",
  "param_list", "param_list_decl", "primary_expr_string", "instr_block",
  "begin_block", "end_block", "float_variable", "expr", "expr_image",
  "expr_string", "basic_type", "var_image", "image", "image_variable",
  "string_variable", "primary_var", "postfix_var", "prefix_var",
  "multiplicative_var", "additive_var", "shift_var", "relational_var",
  "equality_var", "and_var", "exclusive_or_var", "inclusive_or_var",
  "logical_and_var", "logical_xor_var", "logical_or_var",
  "conditional_var", "assignment_var", "expr_var", "gltransform",
  "matrix_variable", "surface", "identifier", "variable_with_assign",
  "function_variable", "variable_without_assign", "unprocessed_variable",
  "processed_variable", "variable", "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       391,     0,    -1,    -1,   392,     0,    -1,   393,    -1,   392,
     393,    -1,   402,   393,    -1,   392,   402,   393,    -1,   394,
      -1,   392,   394,    -1,   395,    -1,   392,   395,    -1,   401,
      -1,   392,   401,    -1,   396,    -1,   392,   396,    -1,   399,
      -1,   392,   399,    -1,   400,    -1,   392,   400,    -1,    36,
      -1,    23,    -1,   320,   439,   108,   411,   321,   411,   407,
     393,    -1,   320,   439,   108,   411,   321,   411,   322,   411,
     407,   393,    -1,   320,   439,   324,   403,   407,   393,    -1,
     325,   407,    -1,   327,   445,   407,    -1,   329,   411,   407,
     393,    -1,   329,   411,   407,   331,   407,   393,    -1,    -1,
     356,   439,   397,    13,   405,    14,   407,   393,    -1,    -1,
     356,    69,   398,    13,   405,    14,   407,   393,    -1,   357,
     439,   407,   393,    -1,   357,   439,    22,   358,    70,   407,
     393,    -1,    70,   439,    -1,   333,   413,   393,    -1,   333,
     393,    -1,   334,   413,    -1,   443,    -1,   435,    -1,    35,
      -1,   328,    -1,    78,    -1,    80,    -1,    81,    -1,    79,
      -1,    82,    13,   411,    14,    -1,    83,    13,   411,    20,
      69,    14,    -1,   439,   108,    17,   443,    -1,   439,   108,
      17,   435,    -1,   439,   108,   435,    -1,   439,   108,   435,
      20,   413,    -1,   439,   108,   442,    -1,   439,   108,    37,
      15,   411,    16,    -1,   439,    87,   412,    -1,    73,    15,
     411,    16,   108,   412,    -1,   439,   108,   436,    -1,   439,
     108,   284,    13,   411,    14,    -1,   439,   108,   284,    13,
     411,    14,    20,   413,    -1,   439,   108,   281,    13,   411,
      14,    -1,   439,   108,   281,    13,   411,    14,    20,   413,
      -1,   439,   108,   297,    13,   413,    20,    55,    14,    -1,
      64,   108,   297,    13,   413,    20,    55,    14,    -1,    64,
      19,   301,    -1,    24,    -1,    25,    -1,    26,   411,    -1,
      27,   411,    -1,    29,    -1,    30,    -1,    28,   411,    -1,
      31,    13,   411,    14,    -1,    32,    13,   413,    14,    -1,
      43,    -1,    41,   415,    -1,    44,   415,    -1,    41,    71,
      -1,   415,    19,    84,    13,   411,    20,   435,    14,    -1,
     415,    13,   411,    22,   411,    20,   411,    22,   411,    20,
     411,    22,   411,    14,   108,   412,    -1,    41,   332,    -1,
      76,    13,   445,    20,   413,    14,    -1,    74,   445,    -1,
      75,   413,    -1,    50,   413,    -1,    51,    -1,    42,    -1,
      42,   439,    -1,    42,    68,    -1,    42,    65,    -1,    42,
      66,    -1,    42,    67,    -1,    42,    55,    -1,    64,    19,
      45,   435,    -1,    64,    19,    46,   435,    -1,    45,   435,
      -1,    46,   435,    -1,    47,   413,    -1,    64,    19,   298,
      -1,   415,    19,   151,    -1,   415,    19,   156,    -1,    71,
     156,    -1,   415,    19,   273,    13,   411,    14,    -1,   415,
      19,   273,    13,   411,    20,   411,    20,   411,    14,    -1,
     415,    19,   267,    13,   411,    14,    -1,   415,    19,   267,
      13,   411,    20,   411,    20,   411,    14,    -1,   415,    19,
     267,    13,   411,    20,   411,    14,    -1,   415,    19,   268,
      13,   411,    20,   411,    20,   411,    14,    -1,   415,    19,
     122,    13,   415,    20,   411,    20,   411,    20,   411,    14,
      -1,   415,    19,   122,    13,   415,    14,    -1,   415,    19,
      52,    13,   413,    14,    -1,   141,    19,   152,    -1,   141,
      19,   153,    -1,   142,    19,   152,    -1,   142,    19,   153,
      -1,   415,    19,   157,   413,    -1,   415,    19,   158,    -1,
     415,    19,   159,    13,   415,    14,    -1,   415,    19,   160,
      13,   415,    14,    -1,   379,    13,   413,    14,    -1,   380,
      13,   435,    20,   411,    20,   411,    20,   411,    20,   411,
      20,   411,    20,   411,    20,   411,    20,   411,    14,    -1,
      62,    19,   243,    13,   411,    20,   411,    20,   411,    14,
      -1,    62,    19,   246,    13,   435,    14,    -1,    62,    88,
     435,    -1,    62,    89,   435,    -1,    62,    19,   259,    13,
     435,    14,    -1,    62,    19,   260,    -1,    62,    19,   245,
      13,   411,    14,    -1,    62,    19,   245,    13,   411,    20,
     411,    14,    -1,    62,    19,   247,    13,   411,    14,    -1,
      62,    19,   269,    13,    62,    14,    -1,    62,    19,   270,
      13,    57,    20,   415,    14,    -1,    62,    19,   274,    13,
     411,    20,   412,    20,   411,    20,   411,    20,   411,    20,
     411,    14,    -1,    62,    19,   275,    13,   411,    14,    -1,
      62,    19,   266,    -1,    62,    19,   262,    13,   436,    14,
      -1,    62,    19,   262,    13,   436,    20,   411,    14,    -1,
      62,    19,   250,    -1,    62,    19,   253,    13,   411,    20,
     411,    20,   411,    20,   411,    14,    -1,    62,    19,   254,
      13,   411,    20,   411,    20,   411,    20,   411,    14,    -1,
      62,    19,   255,    13,   411,    20,   411,    20,   411,    20,
     411,    14,    -1,    62,    19,   256,    13,   411,    20,   411,
      20,   411,    14,    -1,    62,    19,   257,    -1,    62,    19,
     258,    -1,    62,    19,   272,    13,   411,    20,   411,    14,
      -1,   182,    13,   415,    20,   411,    20,   411,    14,    -1,
     182,    13,   415,    20,   411,    20,   411,    20,   412,    14,
      -1,   183,    13,   415,    20,   411,    20,   411,    14,    -1,
     183,    13,   415,    20,   411,    20,   411,    20,   412,    14,
      -1,   183,    13,   415,    20,   411,    20,   411,    20,   412,
      20,   411,    14,    -1,   184,    13,   415,    20,   411,    14,
      -1,   184,    13,   415,    20,   411,    20,   435,    14,    -1,
     184,    13,   415,    20,   411,    20,   411,    20,   412,    14,
      -1,   186,    13,   415,    20,   411,    20,   411,    20,   411,
      20,   411,    20,   411,    20,   411,    14,    -1,   186,    13,
     415,    20,   411,    20,   411,    20,   411,    20,   411,    20,
     411,    20,   411,    20,   412,    14,    -1,   185,    13,   415,
      20,   411,    20,   411,    20,   412,    20,   411,    14,    -1,
     187,    13,   415,    20,   411,    14,    -1,   212,    13,    55,
      20,   415,    20,   415,    20,   415,    20,   415,    20,   415,
      20,   415,    20,   412,    14,    -1,   212,    13,    55,    20,
     415,    20,   415,    20,   415,    20,   415,    20,   415,    20,
     415,    14,    -1,   211,    13,    55,    20,   415,    20,   415,
      20,   415,    20,   412,    14,    -1,   211,    13,    55,    20,
     415,    20,   415,    20,   415,    14,    -1,   189,    13,   415,
      20,   411,    20,   411,    20,   411,    14,    -1,   415,    19,
     189,    13,   411,    20,   411,    20,   411,    14,    -1,   415,
      19,   189,    13,   415,    14,    -1,   415,    19,   190,    13,
     411,    20,   411,    20,   411,    14,    -1,   415,    19,   190,
      13,   415,    14,    -1,   415,    19,   191,    13,   411,    14,
      -1,   124,    13,   415,    20,   415,    14,    -1,   124,    13,
     415,    20,   415,    20,   415,    14,    -1,   225,    13,   411,
      14,    -1,   226,    13,   411,    14,    -1,   293,    13,   412,
      20,   413,    20,   411,    14,    -1,   296,    13,   415,    14,
      -1,   210,    13,   415,    20,   415,    20,   411,    20,   411,
      20,   411,    20,   411,    20,   411,    20,   411,    14,    -1,
     350,    13,    55,    14,    -1,   134,    -1,   135,    -1,   137,
      -1,   381,    13,   415,    20,   413,    14,    -1,    72,    19,
      45,    -1,    72,    19,   157,   413,    -1,   382,    -1,   383,
      -1,   384,    -1,   385,    13,   415,    20,   415,    20,   415,
      20,   415,    20,   415,    20,   415,    20,   415,    20,   411,
      20,   411,    20,   411,    20,   411,    20,   411,    20,   411,
      20,   411,    14,    -1,   386,    13,   415,    20,   415,    20,
     411,    20,   411,    20,   411,    20,   411,    20,   411,    20,
     411,    20,   415,    20,   415,    20,   411,    14,    -1,   374,
      13,   411,    20,   411,    20,   411,    14,    -1,   413,    -1,
     403,    20,   413,    -1,    -1,   443,    -1,   404,    20,   443,
      -1,    17,   435,    -1,   404,    20,    17,   435,    -1,   435,
      -1,   404,    20,   435,    -1,    -1,   352,    58,    -1,   355,
      58,    -1,   353,    58,    -1,   351,    58,    -1,   405,    20,
     355,    58,    -1,   405,    20,   352,    58,    -1,   405,    20,
     353,    58,    -1,   405,    20,   351,    58,    -1,    55,    -1,
      49,    13,   413,    20,   411,    14,    -1,   136,    -1,   415,
      19,    53,    -1,    53,    13,   445,    14,    -1,    54,    13,
     445,    14,    -1,    33,    -1,   408,    56,   409,    -1,    -1,
      -1,    57,    -1,    34,    -1,   302,    -1,   303,    -1,   415,
      13,   411,    20,   411,    14,    -1,   415,    13,   411,    20,
     411,    20,   411,    14,    -1,   415,    19,   271,    13,   411,
      20,   411,    20,   411,    14,    -1,   415,    13,   411,    20,
     411,    20,   411,    20,   411,    14,    -1,   415,    13,   411,
      20,   411,    20,   411,    23,   411,    14,    -1,   415,    13,
     411,    20,   411,    23,   411,    14,    -1,   415,    13,   411,
      23,   411,    14,    -1,   415,    19,   335,    -1,   415,    19,
     336,    -1,   415,    19,   337,    -1,   415,    19,   338,    -1,
     415,    19,   339,    -1,   415,    19,   340,    -1,   415,    19,
     341,    -1,   415,    19,   342,    -1,   415,    19,   343,    -1,
     415,    19,   344,    -1,   415,    19,   345,    -1,   415,    19,
     346,    -1,   155,    13,   415,    20,   415,    14,    -1,   174,
      13,   415,    14,    -1,   227,    13,   415,    20,   411,    20,
     411,    20,   411,    14,    -1,   228,    13,   415,    14,    -1,
     228,    13,   411,    20,   411,    20,   411,    20,   411,    14,
      -1,   109,    13,   412,    14,    -1,   176,    13,   412,    14,
      -1,   110,    13,   412,    14,    -1,   111,    13,   412,    14,
      -1,   112,    13,   412,    14,    -1,   113,    13,   412,    14,
      -1,   110,    15,   412,    16,    13,   412,    14,    -1,   112,
      15,   412,    16,    13,   415,    14,    -1,   113,    15,   412,
      16,    13,   415,    14,    -1,   113,    15,   412,    16,    13,
     415,    20,   411,    14,    -1,   176,    15,   412,    16,    13,
     412,    14,    -1,   176,    13,   415,    20,   412,    14,    -1,
     292,    13,   413,    14,    -1,   437,    13,   411,    20,   411,
      14,    -1,   437,    19,   267,    13,   411,    20,   411,    20,
     411,    14,    -1,   347,    13,   439,    14,    -1,   347,    13,
     445,    14,    -1,   348,    13,   413,    14,    -1,   414,    19,
     346,    -1,    64,    19,   299,    13,   413,    14,    -1,    64,
      19,   300,    13,    59,    14,    -1,    64,    19,   300,    13,
      61,    14,    -1,   435,    -1,   435,    -1,   435,    -1,   280,
      -1,   281,    -1,   282,    -1,   283,    -1,   284,    -1,   285,
      -1,   286,    -1,   287,    -1,   288,    -1,   289,    -1,   290,
      -1,   415,    19,   291,    -1,    60,    -1,    73,    15,   411,
      16,    -1,   415,    -1,    37,   413,    -1,   206,    13,   413,
      14,    -1,   207,    13,   413,    14,    -1,    38,    -1,    37,
      13,   414,    20,   411,    20,   411,    20,   411,    14,    -1,
      37,    13,   414,    20,   411,    20,   411,    20,   411,    20,
     411,    14,    -1,    37,    13,   414,    20,   411,    20,   415,
      14,    -1,   177,    13,   412,    20,   411,    14,    -1,   178,
      13,   412,    20,   411,    14,    -1,   179,    13,   412,    20,
     411,    14,    -1,   180,    13,   412,    20,   412,    20,   411,
      14,    -1,   181,    13,   412,    20,   412,    20,   411,    14,
      -1,   114,    13,   415,    20,    55,    14,    -1,   114,    13,
     415,    20,    55,    20,   414,    14,    -1,   114,    13,   415,
      20,   415,    20,    55,    14,    -1,   114,    13,   415,    20,
     415,    20,    55,    20,   414,    14,    -1,   114,    13,   415,
      20,   415,    20,   415,    20,    55,    14,    -1,   114,    13,
     415,    20,   415,    20,   415,    20,    55,    20,   414,    14,
      -1,   115,    13,   412,    20,   411,    20,   411,    20,   411,
      20,   411,    14,    -1,   365,    19,   366,    13,   415,    20,
     411,    20,   411,    14,    -1,   238,    13,   415,    14,    -1,
     132,    13,   415,    20,   411,    20,   411,    20,   411,    14,
      -1,   239,    13,   415,    14,    -1,   161,    13,   412,    20,
     411,    14,    -1,   162,    13,   415,    14,    -1,   163,    13,
     415,    14,    -1,   164,    13,   415,    14,    -1,   165,    13,
     415,    20,   415,    20,   411,    20,   411,    20,   411,    14,
      -1,   166,    13,   415,    14,    -1,   167,    13,   415,    20,
     415,    20,   415,    20,   411,    20,   415,    14,    -1,   168,
      13,   415,    20,   415,    20,   415,    20,   411,    20,   415,
      14,    -1,   169,    13,   415,    20,   415,    20,   415,    20,
     411,    20,   415,    20,   411,    20,   411,    14,    -1,   170,
      13,   415,    20,   415,    20,   415,    20,   411,    20,   415,
      20,   411,    20,   411,    20,   411,    20,   411,    14,    -1,
     171,    13,   415,    20,   415,    20,   415,    20,   415,    14,
      -1,   171,    13,   415,    20,   415,    20,   415,    20,   415,
      20,   411,    14,    -1,   172,    13,   415,    14,    -1,   172,
      13,   415,    20,   415,    14,    -1,   173,    13,   415,    20,
     415,    14,    -1,   116,    13,   412,    20,   411,    14,    -1,
     117,    13,   415,    14,    -1,   131,    13,   415,    14,    -1,
     118,    13,   415,    20,   411,    14,    -1,   188,    13,   415,
      14,    -1,   119,    13,   415,    20,   411,    14,    -1,   120,
      13,   415,    20,   411,    14,    -1,   123,    13,   412,    20,
     411,    14,    -1,   121,    13,   415,    20,   411,    20,   411,
      20,   411,    20,   411,    20,   411,    20,   411,    14,    -1,
     125,    13,   415,    20,   411,    20,   411,    20,   411,    14,
      -1,   125,    13,   415,    20,   411,    20,   411,    14,    -1,
     125,    13,   415,    20,   411,    20,   411,    20,   411,    20,
     411,    14,    -1,   126,    13,   415,    20,   411,    20,   411,
      20,   411,    14,    -1,   126,    13,   415,    20,   411,    20,
     411,    14,    -1,   126,    13,   415,    20,   411,    20,   411,
      20,   411,    20,   411,    14,    -1,   127,    13,   415,    20,
     411,    20,   411,    14,    -1,   127,    13,   415,    20,   411,
      20,   411,    20,   411,    20,   411,    14,    -1,   128,    13,
     415,    20,   411,    20,   411,    14,    -1,   128,    13,   415,
      20,   411,    20,   411,    20,   411,    20,   411,    14,    -1,
     140,    13,   415,    20,   415,    20,   411,    20,   411,    20,
     411,    14,    -1,   130,    13,   415,    20,   411,    20,   411,
      20,   411,    20,   411,    20,   411,    14,    -1,   129,    13,
     415,    20,   411,    20,   411,    20,   411,    20,   411,    14,
      -1,   141,    19,   151,    13,   415,    20,   411,    20,   411,
      20,   411,    14,    -1,   142,    19,   151,    13,   415,    20,
     411,    20,   411,    20,   411,    20,   411,    20,   411,    14,
      -1,   143,    13,   415,    14,    -1,   144,    13,   415,    20,
     411,    20,   411,    14,    -1,   144,    13,   415,    20,   411,
      20,   411,    20,   446,    14,    -1,   144,    13,   415,    20,
     411,    20,   411,    20,   411,    20,   446,    14,    -1,   145,
      13,   415,    20,   411,    20,   411,    20,   446,    14,    -1,
     145,    13,   415,    20,   411,    20,   411,    20,   411,    20,
     446,    14,    -1,   146,    13,   415,    20,   411,    20,   411,
      20,   446,    14,    -1,   147,    13,   415,    20,   411,    20,
     411,    20,   411,    20,   446,    14,    -1,   148,    13,   415,
      20,   411,    20,   411,    20,   411,    20,   446,    14,    -1,
     149,    13,   415,    20,   411,    20,   411,    20,   411,    20,
     411,    20,   446,    14,    -1,   150,    13,   415,    20,   411,
      20,   411,    20,   411,    20,   411,    14,    -1,   154,    13,
     415,    20,   411,    20,   411,    14,    -1,   175,    13,   415,
      20,   411,    20,   411,    20,   411,    20,   411,    20,   411,
      14,    -1,   276,    13,   435,    14,    -1,   277,    13,   435,
      14,    -1,   278,    13,   435,    14,    -1,   279,    13,   435,
      14,    -1,    62,    19,   241,    -1,    62,    19,   242,    -1,
     195,    13,   415,    20,   411,    14,    -1,   196,    13,   415,
      20,   411,    14,    -1,   197,    13,   415,    20,   411,    14,
      -1,   198,    13,   415,    20,   411,    14,    -1,   138,    13,
     412,    20,   412,    20,   411,    14,    -1,   139,    13,   412,
      20,   412,    20,   411,    20,   411,    20,   411,    20,   411,
      14,    -1,   138,    13,   412,    20,   412,    20,   411,    20,
     411,    20,   411,    14,    -1,   138,    13,   412,    20,   412,
      20,   411,    20,   411,    20,   411,    20,   411,    14,    -1,
     138,    13,   412,    20,   412,    20,   415,    20,   411,    20,
     411,    14,    -1,   208,    13,   415,    20,   415,    14,    -1,
     209,    13,   415,    20,   415,    20,   412,    14,    -1,   213,
      13,   415,    20,   411,    20,   411,    20,   411,    14,    -1,
     214,    13,   415,    20,   411,    20,   411,    20,   411,    14,
      -1,   214,    13,   415,    20,   411,    20,   411,    20,   411,
      20,   411,    14,    -1,   215,    13,   415,    20,   411,    14,
      -1,   216,    13,   415,    20,   411,    14,    -1,   217,    13,
     415,    20,   411,    14,    -1,   218,    13,   415,    20,   411,
      14,    -1,   219,    13,   415,    20,   411,    14,    -1,   220,
      13,   415,    20,   411,    14,    -1,   221,    13,   415,    20,
     411,    14,    -1,   222,    13,   415,    20,   411,    14,    -1,
     222,    13,   415,    20,   411,    20,   411,    14,    -1,   223,
      13,   415,    20,   411,    20,   411,    20,   411,    14,    -1,
     224,    13,   412,    14,    -1,   415,    13,   435,    14,    -1,
     294,    13,   412,    20,   411,    20,   411,    20,   411,    14,
      -1,   295,    13,   412,    20,   411,    20,   411,    20,   411,
      14,    -1,   359,    13,   412,    14,    -1,   359,    13,   412,
      20,   411,    14,    -1,   362,    13,   412,    20,   411,    14,
      -1,   360,    13,   412,    20,   411,    20,   411,    20,   411,
      20,   411,    14,    -1,   361,    13,   415,    20,   415,    20,
     411,    20,   411,    20,   411,    20,   411,    20,   411,    20,
     411,    20,   411,    20,   411,    20,   411,    20,   411,    20,
     411,    20,   411,    14,    -1,   364,    13,   412,    20,   411,
      20,   411,    14,    -1,   370,    13,   412,    20,   411,    14,
      -1,   370,    13,   412,    14,    -1,   371,    13,   412,    20,
     411,    14,    -1,   371,    13,   412,    14,    -1,   376,    13,
     412,    20,   412,    14,    -1,   377,    13,   412,    14,    -1,
     378,    13,   413,    14,    -1,   349,    13,   412,    20,   411,
      20,   411,    20,   411,    20,   411,    20,   411,    20,   411,
      20,   411,    14,    -1,   203,    13,    71,    20,   415,    20,
     412,    14,    -1,   205,    13,    71,    20,   413,    14,    -1,
     416,    -1,    61,    -1,   406,    -1,   441,    -1,    71,    -1,
      59,    -1,   410,    -1,   417,    -1,   438,    -1,   418,    -1,
     437,    -1,   240,    15,   411,    16,    -1,   110,    13,   435,
      20,   435,    14,    -1,    13,   435,    14,    -1,   419,    -1,
     446,    -1,   420,    19,   439,    -1,   420,    13,   404,    14,
      -1,     9,   419,    -1,   420,    97,    -1,   420,    98,    -1,
     420,   106,    -1,   420,    15,   435,    16,    -1,   420,    -1,
      13,   414,    14,   421,    -1,    11,   421,    -1,    10,   421,
      -1,    97,   420,    -1,    98,   421,    -1,   304,   421,    -1,
     305,   421,    -1,   315,   421,    -1,   316,   421,    -1,   317,
     421,    -1,   318,   421,    -1,   306,   421,    -1,   307,   421,
      -1,   308,   421,    -1,   309,   421,    -1,   312,   421,    -1,
     314,   421,    -1,   313,   421,    -1,   319,   421,    -1,   421,
      -1,   422,     7,   421,    -1,   422,     8,   421,    -1,   422,
      12,   421,    -1,   422,    -1,   423,    10,   422,    -1,   423,
      11,   422,    -1,   423,    -1,   424,    -1,   425,     6,   424,
      -1,   425,     5,   424,    -1,   425,   102,   424,    -1,   425,
     103,   424,    -1,   425,    -1,   426,   104,   425,    -1,   426,
     105,   425,    -1,   426,    -1,   427,    17,   426,    -1,   427,
      -1,   428,    -1,   429,    18,   428,    -1,   429,    -1,   430,
     100,   429,    -1,   430,    -1,   431,     4,   430,    -1,   431,
      -1,   432,   101,   431,    -1,   432,    -1,   432,    21,   419,
      22,   419,    -1,   433,    -1,   433,   108,   434,    -1,   433,
      87,   434,    -1,   433,    88,   434,    -1,   433,    89,   434,
      -1,   433,    90,   434,    -1,   433,    91,   434,    -1,   434,
      -1,    72,    -1,    62,    19,   261,    -1,   263,    13,    72,
      20,    72,    20,   411,    14,    -1,    40,    13,   413,    14,
      -1,   264,    13,   411,    20,   411,    14,    -1,    63,    -1,
     265,    13,   435,    14,    -1,   229,    13,   412,    20,   411,
      14,    -1,   232,    13,   415,    20,   411,    14,    -1,   229,
      13,   412,    20,   411,    20,   415,    14,    -1,   237,    13,
     412,    20,   411,    20,   412,    14,    -1,   233,    13,    71,
      14,    -1,   233,    13,    71,    20,   411,    14,    -1,   234,
      13,   415,    20,   411,    14,    -1,   235,    13,    71,    20,
     411,    14,    -1,   236,    13,    71,    20,   411,    14,    -1,
     240,    13,    14,    -1,   240,   413,    -1,   204,    13,   413,
      14,    -1,   204,    13,   413,    20,   411,    14,    -1,   192,
      13,   415,    14,    -1,   193,    13,    71,    14,    -1,   193,
      13,    71,    20,   411,    20,   411,    20,   411,    14,    -1,
     194,    13,    71,    20,   411,    14,    -1,   199,    13,    71,
      20,   411,    20,   411,    20,   411,    20,   411,    20,   411,
      20,   411,    14,    -1,   200,    13,   412,    20,   411,    20,
     411,    20,   411,    20,   411,    20,   411,    20,   411,    20,
     411,    14,    -1,   201,    13,   412,    20,   411,    20,   411,
      20,   411,    14,    -1,   202,    13,   412,    20,   411,    20,
     411,    20,   411,    20,   411,    20,   411,    20,   411,    20,
     411,    20,   411,    14,    -1,   202,    13,   412,    20,   411,
      20,   411,    20,   411,    20,   411,    20,   411,    14,    -1,
     367,    13,   412,    14,    -1,   367,    13,   412,    20,   411,
      14,    -1,   367,    13,   412,    20,   411,    20,   411,    14,
      -1,   369,    13,   412,    20,   411,    20,   411,    14,    -1,
     368,    13,   412,    20,   411,    20,   411,    20,   412,    20,
     412,    14,    -1,   368,    13,   412,    20,   411,    20,   411,
      20,   412,    20,   412,    20,   412,    20,   411,    14,    -1,
     372,    13,   412,    20,   412,    20,   412,    20,   411,    20,
     411,    20,   411,    20,   411,    14,    -1,   372,    13,   412,
      20,   412,    20,   412,    20,   411,    20,   411,    20,   411,
      20,   411,    20,   411,    14,    -1,   372,    13,   412,    20,
     412,    20,   412,    20,   411,    20,   411,    20,   411,    14,
      -1,   373,    13,   412,    20,   411,    20,   411,    20,   411,
      20,   411,    20,   411,    14,    -1,   375,    13,   412,    20,
     412,    20,   412,    20,   411,    20,   411,    20,   411,    20,
     411,    14,    -1,   375,    13,   412,    20,   412,    20,   412,
      20,   411,    20,   411,    20,   411,    20,   411,    20,   412,
      20,   412,    14,    -1,    58,    -1,    72,    -1,    65,    -1,
      66,    -1,    68,    -1,    67,    -1,    69,    -1,    62,    -1,
      64,    -1,    70,    -1,    73,    -1,   440,    -1,   442,    -1,
      71,    -1,    59,    -1,    61,    -1,    63,    -1,   415,    -1,
     443,    -1,   444,    -1,   441,    -1,   419,    22,   419,    20,
     419,    22,   419,    20,   419,    22,   419,    -1,   419,    22,
     419,    20,   419,    22,   419,    -1,    22,    20,    22,    20,
     419,    22,   419,    -1,   415,    19,    85,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     9,    12,    15,    19,    21,
      24,    26,    29,    31,    34,    36,    39,    41,    44,    46,
      49,    51,    53,    62,    73,    80,    83,    87,    92,    99,
     100,   109,   110,   119,   124,   132,   135,   139,   142,   145,
     147,   149,   151,   153,   155,   157,   159,   161,   166,   173,
     178,   183,   187,   193,   197,   204,   208,   215,   219,   226,
     235,   242,   251,   260,   269,   273,   275,   277,   280,   283,
     285,   287,   290,   295,   300,   302,   305,   308,   311,   320,
     337,   340,   347,   350,   353,   356,   358,   360,   363,   366,
     369,   372,   375,   378,   383,   388,   391,   394,   397,   401,
     405,   409,   412,   419,   430,   437,   448,   457,   468,   481,
     488,   495,   499,   503,   507,   511,   516,   520,   527,   534,
     539,   560,   571,   578,   582,   586,   593,   597,   604,   613,
     620,   627,   636,   653,   660,   664,   671,   680,   684,   697,
     710,   723,   734,   738,   742,   751,   760,   771,   780,   791,
     804,   811,   820,   831,   848,   867,   880,   887,   906,   923,
     936,   947,   958,   969,   976,   987,   994,  1001,  1008,  1017,
    1022,  1027,  1036,  1041,  1060,  1065,  1067,  1069,  1071,  1078,
    1082,  1087,  1089,  1091,  1093,  1124,  1149,  1158,  1160,  1164,
    1165,  1167,  1171,  1174,  1179,  1181,  1185,  1186,  1189,  1192,
    1195,  1198,  1203,  1208,  1213,  1218,  1220,  1227,  1229,  1233,
    1238,  1243,  1245,  1249,  1250,  1251,  1253,  1255,  1257,  1259,
    1266,  1275,  1286,  1297,  1308,  1317,  1324,  1328,  1332,  1336,
    1340,  1344,  1348,  1352,  1356,  1360,  1364,  1368,  1372,  1379,
    1384,  1395,  1400,  1411,  1416,  1421,  1426,  1431,  1436,  1441,
    1449,  1457,  1465,  1475,  1483,  1490,  1495,  1502,  1513,  1518,
    1523,  1528,  1532,  1539,  1546,  1553,  1555,  1557,  1559,  1561,
    1563,  1565,  1567,  1569,  1571,  1573,  1575,  1577,  1579,  1581,
    1585,  1587,  1592,  1594,  1597,  1602,  1607,  1609,  1620,  1633,
    1642,  1649,  1656,  1663,  1672,  1681,  1688,  1697,  1706,  1717,
    1728,  1741,  1754,  1765,  1770,  1781,  1786,  1793,  1798,  1803,
    1808,  1821,  1826,  1839,  1852,  1869,  1890,  1901,  1914,  1919,
    1926,  1933,  1940,  1945,  1950,  1957,  1962,  1969,  1976,  1983,
    2000,  2011,  2020,  2033,  2044,  2053,  2066,  2075,  2088,  2097,
    2110,  2123,  2138,  2151,  2164,  2181,  2186,  2195,  2206,  2219,
    2230,  2243,  2254,  2267,  2280,  2295,  2308,  2317,  2332,  2337,
    2342,  2347,  2352,  2356,  2360,  2367,  2374,  2381,  2388,  2397,
    2412,  2425,  2440,  2453,  2460,  2469,  2480,  2491,  2504,  2511,
    2518,  2525,  2532,  2539,  2546,  2553,  2560,  2569,  2580,  2585,
    2590,  2601,  2612,  2617,  2624,  2631,  2644,  2675,  2684,  2691,
    2696,  2703,  2708,  2715,  2720,  2725,  2744,  2753,  2760,  2762,
    2764,  2766,  2768,  2770,  2772,  2774,  2776,  2778,  2780,  2782,
    2787,  2794,  2798,  2800,  2802,  2806,  2811,  2814,  2817,  2820,
    2823,  2828,  2830,  2835,  2838,  2841,  2844,  2847,  2850,  2853,
    2856,  2859,  2862,  2865,  2868,  2871,  2874,  2877,  2880,  2883,
    2886,  2889,  2891,  2895,  2899,  2903,  2905,  2909,  2913,  2915,
    2917,  2921,  2925,  2929,  2933,  2935,  2939,  2943,  2945,  2949,
    2951,  2953,  2957,  2959,  2963,  2965,  2969,  2971,  2975,  2977,
    2983,  2985,  2989,  2993,  2997,  3001,  3005,  3009,  3011,  3013,
    3017,  3026,  3031,  3038,  3040,  3045,  3052,  3059,  3068,  3077,
    3082,  3089,  3096,  3103,  3110,  3114,  3117,  3122,  3129,  3134,
    3139,  3150,  3157,  3174,  3193,  3204,  3225,  3240,  3245,  3252,
    3261,  3270,  3283,  3300,  3317,  3336,  3351,  3366,  3383,  3404,
    3406,  3408,  3410,  3412,  3414,  3416,  3418,  3420,  3422,  3424,
    3426,  3428,  3430,  3432,  3434,  3436,  3438,  3440,  3442,  3444,
    3446,  3458,  3466,  3474
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   816,   816,   817,   821,   821,   822,   823,   824,   824,
     825,   825,   826,   826,   827,   827,   828,   828,   829,   829,
     832,   833,   838,   857,   877,   923,   946,   976,   991,  1014,
    1013,  1045,  1044,  1090,  1107,  1129,  1150,  1157,  1192,  1202,
    1218,  1251,  1259,  1269,  1283,  1297,  1311,  1321,  1337,  1355,
    1370,  1396,  1433,  1460,  1532,  1543,  1569,  1608,  1703,  1715,
    1734,  1745,  1832,  1866,  1882,  1888,  1892,  1896,  1900,  1910,
    1915,  1919,  1929,  1939,  1950,  1953,  2012,  2034,  2084,  2174,
    2200,  2204,  2216,  2230,  2240,  2251,  2259,  2271,  2507,  2517,
    2527,  2537,  2546,  2611,  2625,  2659,  2671,  2712,  2731,  3194,
    3216,  3240,  3262,  3274,  3288,  3307,  3329,  3350,  3379,  3408,
    3440,  3637,  3642,  3649,  3654,  3894,  3922,  3936,  3943,  3949,
    3957,  4060,  4067,  4075,  4083,  4091,  4102,  4112,  4120,  4128,
    4139,  4146,  4160,  4174,  4183,  4188,  4197,  4206,  4221,  4234,
    4247,  4260,  4267,  4277,  4287,  4301,  4309,  4320,  4343,  4369,
    4397,  4408,  4451,  4473,  4502,  4519,  4534,  4540,  4567,  4593,
    4613,  4630,  4636,  4642,  4653,  4659,  4667,  4682,  4691,  4702,
    4719,  4735,  4773,  4787,  4834,  4840,  4845,  4850,  4856,  4863,
    4869,  4876,  4881,  4886,  4891,  4934,  4988,  5010,  5018,  5035,
    5039,  5055,  5073,  5088,  5103,  5124,  5149,  5154,  5163,  5170,
    5177,  5200,  5207,  5214,  5221,  5246,  5251,  5332,  5356,  5361,
    5374,  5393,  5424,  5435,  5436,  5441,  5445,  5453,  5461,  5470,
    5487,  5503,  5520,  5539,  5557,  5573,  5589,  5595,  5601,  5607,
    5613,  5619,  5625,  5631,  5637,  5643,  5649,  5655,  5662,  5671,
    5678,  5709,  5717,  5729,  5749,  5769,  5789,  5809,  5829,  5849,
    5873,  5897,  5921,  5929,  5953,  5976,  6007,  6017,  6029,  6039,
    6049,  6061,  6069,  6085,  6104,  6134,  6152,  6164,  6185,  6190,
    6194,  6198,  6202,  6206,  6210,  6214,  6218,  6222,  6226,  6230,
    6238,  6240,  6259,  6261,  6276,  6296,  6331,  6365,  6372,  6390,
    6481,  6547,  6554,  6561,  6569,  6577,  6593,  6611,  6629,  6646,
    6663,  6681,  6717,  6730,  6741,  6754,  6778,  6789,  6800,  6810,
    6820,  6853,  6864,  6885,  6905,  6946,  6993,  7013,  7034,  7045,
    7059,  7073,  7086,  7097,  7108,  7121,  7139,  7151,  7163,  7215,
    7256,  7267,  7277,  7289,  7300,  7310,  7335,  7358,  7386,  7400,
    7534,  7568,  7601,  7629,  7643,  7657,  7667,  7686,  7705,  7725,
    7746,  7768,  7787,  7806,  7826,  7866,  7888,  7917,  7939,  7976,
    8013,  8050,  8084,  8090,  8107,  8114,  8121,  8129,  8136,  8158,
    8186,  8210,  8237,  8269,  8278,  8291,  8298,  8306,  8320,  8332,
    8344,  8354,  8365,  8375,  8385,  8396,  8406,  8417,  8444,  8492,
    8626,  8647,  8687,  8698,  8706,  8714,  8735,  8761,  8772,  8779,
    8785,  8791,  8798,  8823,  8841,  8848,  8881,  8900,  8921,  8949,
    8958,  8972,  8974,  8976,  8978,  8980,  8982,  8984,  8986,  8988,
    9009,  9151,  9154,  9156,  9158,  9187,  9264,  9272,  9280,  9288,
    9340,  9352,  9354,  9363,  9369,  9374,  9379,  9384,  9389,  9394,
    9399,  9404,  9409,  9414,  9419,  9424,  9429,  9434,  9439,  9444,
    9449,  9458,  9459,  9465,  9471,  9481,  9482,  9489,  9499,  9503,
    9504,  9510,  9516,  9522,  9531,  9532,  9538,  9564,  9565,  9569,
    9573,  9574,  9578,  9579,  9591,  9592,  9604,  9605,  9617,  9618,
    9631,  9632,  9642,  9649,  9655,  9661,  9667,  9676,  9680,  9690,
    9704,  9715,  9733,  9739,  9748,  9893,  9908,  9920,  9942,  9978,
    9987,  9997, 10006, 10016, 10030, 10037, 10046, 10062, 10081, 10101,
   10131, 10160, 10177, 10203, 10237, 10269, 10316, 10357, 10366, 10388,
   10399, 10410, 10446, 10488, 10534, 10584, 10626, 10657, 10689, 10731,
   10739, 10742, 10743, 10744, 10745, 10746, 10753, 10754, 10755, 10756,
   10761, 10762, 10768, 10770, 10772, 10775, 10777, 10781, 10783, 10785,
   10789, 10811, 10828, 10849
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "), ";
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 9960;
  const int Parser::yynnts_ = 57;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 553;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 390;

  const unsigned int Parser::yyuser_token_number_max_ = 644;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

} // namespace yyip

#line 10890 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"

#include <stdio.h>



int is_space(char c)
{
  return ((c==' ')||(c=='\n')||(c=='\t'));
}




void yyip::Parser::error(const Parser::location_type& l,
          const std::string& m)
{
    driver.error(l, m);
}


//------------------------------------------------------
void CB_update_imagelist( void* imagelist_gui)
//   -------------------
{
  wxEnumerationParameter* imlist = (wxEnumerationParameter*) imagelist_gui;
  boost::shared_ptr<wxArrayString> imagelist;

  imagelist = Vars.SearchVariables(type_image);
  imagelist->Add(_T("BrowseImage"));
  imlist->SetChoices(imagelist);
}


//------------------------------------------------------
void wxScheduleTimer::Notify()
//   -----------------------
{
  //cout << "Notify()" << endl;
  GB_driver.yyip_call_function(var->Pointer().get());

  std::list<wxScheduleTimer::ptr>::iterator Iter;
  for (Iter  = schedule_timers.begin();
       Iter != schedule_timers.end()  ; Iter++ )
  {
    if ((*Iter).use_count()) {
      if (Iter->get() == this) {
        Iter = schedule_timers.erase(Iter);
     }
    }
  }
} // wxScheduleTimer::Notify()

InrImage* ReadImage( const char* name)
{
  // look for the image 
  wxFileName inputname(wxString(name, wxConvUTF8));
  wxFileName newname(wxString(name,wxConvUTF8));
  InrImage* res = NULL;

  if (!inputname.IsFileReadable()) 
  // add the current script path
  {
    newname.Assign(
            wxFileName(wxString(GB_driver.GetCurrentFilename().c_str(),wxConvUTF8)).GetPath() +
            inputname.GetPathSeparator()+
            inputname.GetPath(),
            inputname.GetFullName());
  }

  if (newname.IsFileReadable()) {
    try {
      res=new InrImage(newname.GetFullPath().mb_str());
    }
    catch (InrImage::ErreurLecture)
    {
      FILE_ERROR(boost::format("Unable to read image %s") % name);
      //AddImagePointer(NULL);
      return NULL;
    }
  } else {
    FILE_ERROR(boost::format("Invalid image filename '%s'") % name);
    //AddImagePointer(NULL);
  }
  return res;
}




