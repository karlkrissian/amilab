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
#line 807 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"


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
        case 54: /* "ASTRING" */
#line 800 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 217 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */
#line 801 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };
#line 222 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 366: /* "exprstringlist" */
#line 803 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };
#line 227 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 369: /* "primary_expr_string" */
#line 800 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 232 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 370: /* "instr_block" */
#line 802 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };
#line 237 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 376: /* "expr_string" */
#line 800 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 242 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 401: /* "identifier" */
#line 801 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
    #line 347 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 846 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 865 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 885 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      //cout << " *** Create temporary variable " << ident->GetName() << std::endl;

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
      //cout << " *** Delete temporary variable " << ident->GetName() << std::endl;
      if (!res) {
       std::cout << "**********" << std::endl;
       std::cout << "**** Could not delete variable in loop"  << ident->GetName() << std::endl;
       std::cout << "**********" << std::endl;
      }
      driver.yyiplineno=previous_lineno;

      // forced to delete the pointer to the list here
      delete (yysemantic_stack_[(6) - (4)].string_list);

    ;}
    break;

  case 25:
#line 930 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 953 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 983 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 998 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1020 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    ;}
    break;

  case 30:
#line 1025 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (2)].ident));

      AMIFunction::ptr amifunc(new AMIFunction);

      amifunc->SetName(ident->GetName().c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);

      if (GB_debug)
       std::cout  << ident->GetName()
              << " body = "
              << body->GetBody()  << std::endl;

      BasicVariable::ptr newvar = Vars.AddVar<AMIFunction>( ident, amifunc);
      if (newvar.get())
        amifunc->SetContext(newvar->GetContext());

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    ;}
    break;

  case 31:
#line 1051 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    ;}
    break;

  case 32:
#line 1057 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1098 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1115 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1136 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1157 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     ;}
    break;

  case 37:
#line 1164 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          //cout << "current wd = "  <<  wxGetCwd() << std::endl;
          res=AskScript(name);
          if (!res) {
            driver.yyiperror(" Need script \n");
            YYABORT;
          }
          //cout << "current wd = "  <<  wxGetCwd() << std::endl;

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
                          ->IncCommand(wxString(inc_cmd.c_str(),wxConvUTF8));
      ;}
    break;

  case 38:
#line 1199 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    ;}
    break;

  case 39:
#line 1209 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (var.get()) {
            // TODO: only do it from the command line ???
            //cout << "display var info" << std::endl;
            if (driver.InConsole())
              var->display();
          }

        ;}
    break;

  case 40:
#line 1225 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
                //cout << "display var info" << std::endl;
                if (driver.InConsole())
                  var->display();
            }
          }

        ;}
    break;

  case 41:
#line 1257 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         ;}
    break;

  case 42:
#line 1265 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1276 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1290 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1304 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1318 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1328 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1344 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1362 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1377 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
            //cout << "var.use_count() = " << var.use_count() << std::endl;
            Vars.AddVar(ident,var);
            //cout << "var.use_count() = " << var.use_count() << std::endl;
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
#line 1403 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
          //cout << "GetPtrCounter == " <<  var->GetPtrCounter()<< std::endl;
          //cout << "use_count() == " <<  var.use_count() << std::endl;
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
#line 1440 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1467 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1539 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1550 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1576 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 1712 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 58:
#line 1724 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 59:
#line 1743 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 60:
#line 1754 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 61:
#line 1897 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        ;}
    break;

  case 62:
#line 1901 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
    ;}
    break;

  case 63:
#line 1905 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      driver.SetTraceScanning((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    ;}
    break;

  case 64:
#line 1909 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 65:
#line 1919 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    ;}
    break;

  case 66:
#line 1924 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    ;}
    break;

  case 67:
#line 1928 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 68:
#line 1938 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 69:
#line 1948 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 70:
#line 1958 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
    ;}
    break;

  case 71:
#line 1962 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      std::string titre;
      GET_VARSTACK_VAR_VAL(InrImage, imagevar, im);
      BasicVariable::ptr var;
//      int var_context = Vars.GetContext(imagevar);
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
        BasicVariable::ptr newvar = WrapClass<DessinImage>::CreateVar(p);
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

  case 72:
#line 2021 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 73:
#line 2043 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description: rule to show a surface, since surface has moved to object wrapping
          **/
          GET_VARSTACK_VAR_OBJECT(SurfacePoly,surfvar,surf)
          string    titre;
          //Viewer3D::ptr surfdraw;
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

              Variables::ptr context = surfvar->GetContext();

              // Call constructor from Viewer3D constructor function
              Variable<string>::ptr Title(new Variable<string>(string_ptr(new string(titre))));
              ParamList* p = new ParamList();
              p->AddParam(Title);
              BasicVariable::ptr newvar = WrapClass<Viewer3D>::CreateVar(p);
              FILE_MESSAGE(boost::format("SHOW var_ami_object creating title %s ") % titre);

              if (newvar.get()) {
                newvar->Rename(titre.c_str());
                context->AddVar(newvar, context);
              } else {
                driver.err_print("Failed to create the viewer.");
                YYABORT;
              }

              GET_WRAPPED_OBJECT(Viewer3D, newvar, surfdraw);
              if (surfdraw.get()) {
                surfdraw->Show(true);
                // Add the surface to the OpenGL Object
                surfdraw->GetCanvas()->AddSurface( surf);
                surfdraw->Paint();
                surfdraw->GetCanvas()->Normalize();
                surfdraw->GetCanvas()->Center();
              } else {
                driver.err_print(
                  (boost::format
                    ("Unable to convert variable %1% to a wrapped Viewer3D") % titre).str().c_str());
                YYABORT;
              }
            } else
              std::cerr << " variable " << titre << " already exists " << std::endl;
          }
/*
            if (!var.get()) {
              surfdraw = Viewer3D::Create_ptr(
                            new Viewer3D( GB_main_wxFrame,
                                          wxString(titre.c_str(),wxConvUTF8)));

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
              std::cerr << " variable " << titre << " already exists " << std::endl;
          } // var_context >=0
*/
          // Restore the object context
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            Vars.SetObjectContext(previous_ocontext);
          }

        ;}
    break;

  case 74:
#line 2131 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 75:
#line 2221 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 76:
#line 2247 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        ;}
    break;

  case 77:
#line 2251 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 78:
#line 2263 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 79:
#line 2277 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 80:
#line 2287 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 81:
#line 2298 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Calls system 'ls' command (for unix systems)
      **/
         std::system("ls");
           ;}
    break;

  case 82:
#line 2306 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 83:
#line 2318 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 84:
#line 2554 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 85:
#line 2564 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 86:
#line 2574 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 87:
#line 2584 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
      GET_VARSTACK_VALUE(WrapClassMember, m);
      m->ShowHelp();
    ;}
    break;

  case 88:
#line 2593 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 89:
#line 2705 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 90:
#line 2717 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 91:
#line 2758 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 92:
#line 3228 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 93:
#line 3250 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 94:
#line 3274 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Prints the object information
          **/
          GET_VARSTACK_VAR_VAL(AMIObject,varamio,o);
          
          if (o.get()) {
           std::cout << "var   name = " << varamio->Name() <<std::endl;
            if (o->GetClass().get()) {
             std::cout << "class name = " << o->GetClass()->GetName() <<std::endl;
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

  case 95:
#line 3296 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 96:
#line 3308 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 97:
#line 3322 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 98:
#line 3341 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 99:
#line 3363 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 100:
#line 3384 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 101:
#line 3415 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 102:
#line 3442 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 103:
#line 3474 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    ;}
    break;

  case 104:
#line 3671 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 105:
#line 3676 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    ;}
    break;

  case 106:
#line 3683 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 107:
#line 3688 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    ;}
    break;

  case 108:
#line 3928 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 109:
#line 3956 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 110:
#line 3970 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    ;}
    break;

  case 111:
#line 3977 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    ;}
    break;

  case 112:
#line 3983 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    ;}
    break;

  case 113:
#line 3994 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 114:
#line 4342 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        ;}
    break;

  case 115:
#line 4350 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        ;}
    break;

  case 116:
#line 4361 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 117:
#line 4384 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 118:
#line 4410 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 119:
#line 4438 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 120:
#line 4449 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 121:
#line 4492 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 122:
#line 4514 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 123:
#line 4543 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 124:
#line 4561 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 125:
#line 4575 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 126:
#line 4586 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 127:
#line 4612 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 128:
#line 4638 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 129:
#line 4657 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 130:
#line 4671 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 131:
#line 4677 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 132:
#line 4683 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 133:
#line 4694 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 134:
#line 4700 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    ;}
    break;

  case 135:
#line 4708 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 136:
#line 4723 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    ;}
    break;

  case 137:
#line 4732 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 138:
#line 4743 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 139:
#line 4760 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 140:
#line 4776 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
          //cout << boost::format("%1%,%2% --> %3%")%x%y%taby[x] << std::endl;
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

  case 141:
#line 4814 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      std::cerr << "Feature not available, needs to be updated ! " << std::endl;
      /*
            InrImage::ptr   image = *(InrImage::ptr*) $3->Pointer();
            Histogramme* histo;
      
            histo = new Histogramme(GB_main_window,"histo",
                        image.get(),
                        CREATE_TOPLEVEL_SHELL);
      */
      ;}
    break;

  case 142:
#line 4832 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 143:
#line 4875 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    ;}
    break;

  case 144:
#line 4881 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    ;}
    break;

  case 145:
#line 4886 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    ;}
    break;

  case 146:
#line 4891 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
     std::cout << "time spent = " << driver.IP_time << std::endl;
    ;}
    break;

  case 147:
#line 4897 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        ;}
    break;

  case 148:
#line 4919 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        ;}
    break;

  case 149:
#line 4924 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        ;}
    break;

  case 150:
#line 4929 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        ;}
    break;

  case 151:
#line 4940 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 152:
#line 4980 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 153:
#line 5031 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 154:
#line 5053 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        ;}
    break;

  case 155:
#line 5061 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        ;}
    break;

  case 156:
#line 5077 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        ;}
    break;

  case 157:
#line 5082 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 158:
#line 5098 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 159:
#line 5116 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 160:
#line 5131 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 161:
#line 5146 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 162:
#line 5167 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 163:
#line 5191 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 164:
#line 5197 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
     std::cout << "param_list_decl: T_NUM IDENTIFIER" << std::endl;
     std::cout << ident->GetName().c_str() << std::endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 165:
#line 5206 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 166:
#line 5213 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 167:
#line 5220 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 168:
#line 5243 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 169:
#line 5250 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 170:
#line 5257 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 171:
#line 5264 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 172:
#line 5289 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
    ;}
    break;

  case 173:
#line 5294 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 174:
#line 5375 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 175:
#line 5398 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    ;}
    break;

  case 176:
#line 5404 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 177:
#line 5416 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 178:
#line 5436 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    ;}
    break;

  case 179:
#line 5469 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          std::cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << std::endl;
          ;}
    break;

  case 182:
#line 5484 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      ADD_VARSTACK_FLOAT((yysemantic_stack_[(1) - (1)].adouble))
    ;}
    break;

  case 183:
#line 5488 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      ADD_VARSTACK_FLOAT(GB_argc-GB_num_arg_parsed)
    ;}
    break;

  case 184:
#line 5496 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      ADD_VARSTACK_FLOAT(driver.yyiplineno)
    ;}
    break;

  case 185:
#line 5504 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      ADD_VARSTACK_FLOAT(3.14159265358979323846)
    ;}
    break;

  case 186:
#line 5513 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 187:
#line 5530 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 188:
#line 5546 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 189:
#line 5563 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 190:
#line 5582 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 191:
#line 5600 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 192:
#line 5616 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 193:
#line 5632 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimX();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 194:
#line 5638 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimY();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 195:
#line 5644 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimZ();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 196:
#line 5650 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrX();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 197:
#line 5656 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrY();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 198:
#line 5662 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrZ();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 199:
#line 5668 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeX();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 200:
#line 5674 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeY();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 201:
#line 5680 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeZ();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 202:
#line 5686 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->GetVDim();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 203:
#line 5692 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->IncBuffer();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 204:
#line 5698 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->ValeurBuffer();
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 205:
#line 5705 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      float val=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 206:
#line 5714 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_eccentricity(im.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 207:
#line 5721 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 208:
#line 5752 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_ComputePositiveArea( im.get() );
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 209:
#line 5760 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 210:
#line 5772 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 211:
#line 5792 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 212:
#line 5812 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 213:
#line 5832 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 214:
#line 5852 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 215:
#line 5872 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 216:
#line 5892 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 217:
#line 5916 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 218:
#line 5940 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 219:
#line 5964 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage, mask);
      float val=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 220:
#line 5972 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 221:
#line 5996 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 222:
#line 6019 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      setlocale(LC_NUMERIC, "C");
      float val=atof((yysemantic_stack_[(4) - (3)].astring));
      ADD_VARSTACK_FLOAT(val);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    ;}
    break;

  case 223:
#line 6050 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 224:
#line 6060 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 225:
#line 6072 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 226:
#line 6082 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 227:
#line 6092 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 228:
#line 6104 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returns the value of the pixel format type in float format
      **/
      float val = (int) (yysemantic_stack_[(3) - (1)].aint);
      ADD_VARSTACK_FLOAT(val);
    ;}
    break;

  case 229:
#line 6179 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 230:
#line 6197 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 231:
#line 6209 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 232:
#line 6230 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    ;}
    break;

  case 233:
#line 6235 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       ;}
    break;

  case 234:
#line 6239 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       ;}
    break;

  case 235:
#line 6243 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       ;}
    break;

  case 236:
#line 6247 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       ;}
    break;

  case 237:
#line 6251 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       ;}
    break;

  case 238:
#line 6255 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_LONG;
       ;}
    break;

  case 239:
#line 6259 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       ;}
    break;

  case 240:
#line 6263 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       ;}
    break;

  case 241:
#line 6267 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       ;}
    break;

  case 242:
#line 6271 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       ;}
    break;

  case 243:
#line 6275 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      ;}
    break;

  case 245:
#line 6285 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 247:
#line 6306 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
                           ->AddFileToHistory(wxString(st.get(),wxConvUTF8));
          ADD_VARSTACK(InrImage,res);
        }
      ;}
    break;

  case 248:
#line 6321 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 249:
#line 6341 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 250:
#line 6376 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;

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
          driver.res_print(newname.mb_str(wxConvUTF8));
          driver.res_print("\n");
          wxString inc_cmd; // increment the command line string
          inc_cmd = wxT(" \"")+newname+wxT("\" // from browser ");

          if (driver.InConsole()) {
            GB_main_wxFrame->GetConsole()
                            ->IncCommand(inc_cmd);
            GB_main_wxFrame->GetImagesHistory()
                           ->AddFileToHistory(newname);
          }
      ;}
    break;

  case 251:
#line 6410 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        ADD_VARSTACK_PTR(InrImage,im);
      ;}
    break;

  case 252:
#line 6417 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 253:
#line 6435 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 254:
#line 6526 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 255:
#line 6592 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    ;}
    break;

  case 256:
#line 6599 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    ;}
    break;

  case 257:
#line 6606 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      ADD_VARSTACK(InrImage,res);
    ;}
    break;

  case 258:
#line 6614 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 259:
#line 6622 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 260:
#line 6638 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 261:
#line 6656 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 262:
#line 6674 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 263:
#line 6691 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 264:
#line 6709 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 265:
#line 6729 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 266:
#line 6762 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 267:
#line 6775 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 268:
#line 6786 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 269:
#line 6799 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 270:
#line 6823 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
        InrImage::ptr res (Func_2DFlux(input.get(),(yysemantic_stack_[(6) - (5)].adouble)));

      Si (res.get()) Alors
        driver.err_print("2DFlux() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 271:
#line 6834 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 272:
#line 6845 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 273:
#line 6855 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 274:
#line 6865 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 275:
#line 6898 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 276:
#line 6910 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 277:
#line 6931 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 278:
#line 6951 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 279:
#line 6992 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 280:
#line 7038 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 281:
#line 7058 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 282:
#line 7079 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 283:
#line 7090 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 284:
#line 7104 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 285:
#line 7120 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
  
      InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      Si (!res.get()) Alors
        driver.err_print("NormGrad() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 286:
#line 7132 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 287:
#line 7143 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 288:
#line 7155 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 289:
#line 7166 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 290:
#line 7186 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      ;}
    break;

  case 291:
#line 7198 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 292:
#line 7208 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 293:
#line 7263 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 294:
#line 7582 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 295:
#line 7617 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 296:
#line 7650 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 297:
#line 7678 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 298:
#line 7692 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 299:
#line 7704 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 300:
#line 7716 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 301:
#line 7734 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 302:
#line 7753 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 303:
#line 7773 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 304:
#line 7795 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 305:
#line 7815 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 306:
#line 7834 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 307:
#line 7854 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 308:
#line 7874 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 309:
#line 7915 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 310:
#line 7937 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 311:
#line 7965 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 312:
#line 7986 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
        //cout << "(*res)(10,20,0)=" << (*res)(10,20,0) << std::endl;
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 313:
#line 8023 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 314:
#line 8060 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 315:
#line 8097 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 316:
#line 8155 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 317:
#line 8162 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 318:
#line 8169 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);

    ;}
    break;

  case 319:
#line 8177 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 320:
#line 8184 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 321:
#line 8208 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 322:
#line 8235 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 323:
#line 8259 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 324:
#line 8288 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 325:
#line 8317 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      InrImage::ptr res ( Func_Convolve(im1.get(), im2.get()));
      ADD_VARSTACK_PTR(InrImage,res);

      ;}
    break;

  case 326:
#line 8326 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 327:
#line 8339 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 328:
#line 8346 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          ADD_VARSTACK_PTR(InrImage,res);

        ;}
    break;

  case 329:
#line 8354 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 330:
#line 8368 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644f, 1.34065f, 1.65849f,
                  dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        ;}
    break;

  case 331:
#line 8380 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644f, 1.34065f, 1.65849f,
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        ;}
    break;

  case 332:
#line 8392 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 333:
#line 8402 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        ;}
    break;

  case 334:
#line 8413 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 335:
#line 8423 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 336:
#line 8433 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 337:
#line 8444 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 338:
#line 8454 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        ;}
    break;

  case 339:
#line 8465 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 340:
#line 8492 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 341:
#line 8540 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
              //cout << boost::format(" im2->ValeurBuffer() = %1% pos = %2%")%im2->ValeurBuffer() % pos << std::endl;
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

  case 342:
#line 8674 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 343:
#line 8695 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 344:
#line 8735 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 345:
#line 8746 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 346:
#line 8754 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res(Func_Flip(im,axis));
        ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 347:
#line 8762 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 348:
#line 8783 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 349:
#line 8809 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      GET_VARSTACK_VALUE(InrImage,input);

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 350:
#line 8820 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 351:
#line 8827 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 352:
#line 8833 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 353:
#line 8839 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      ADD_VARSTACK(InrImage,res);
    ;}
    break;

  case 354:
#line 8846 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 355:
#line 8871 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 356:
#line 8889 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    ;}
    break;

  case 357:
#line 8896 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 358:
#line 8929 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 359:
#line 8948 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 361:
#line 8997 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
    Description: adds a reference to the variable in the stack
    **/
    BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->NewReference());
  ;}
    break;

  case 362:
#line 9006 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 371:
#line 9036 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Returns an AMIObject of type WrapClass_VarVector
          containing 4 SurfacePoly variables.
          Kept for compatibility.
       **/
      int initial_size = (yysemantic_stack_[(4) - (3)].adouble);
      BasicVariable::ptr v = WrapClass_SurfacePoly::CreateVar( new SurfacePoly());

      // Now create the vector 
      VarVector* vv = new VarVector();
      if ((initial_size>0)&&(v.get()))  {
        for (int i=0; i<initial_size; i++)
          vv->push_back(v->NewCopy());
      }
      BasicVariable::ptr new_var = AMILabType<VarVector>::CreateVar(vv);
      driver.var_stack.AddVar(new_var);
    ;}
    break;

  case 372:
#line 9057 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 376:
#line 9206 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
            //cout << "returning variable" << std::endl;
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

  case 377:
#line 9235 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Call to a function, returning a variable
        **/
        //cout << "call to variable T_OP_PAR param_list T_CL_PAR end_instr" << std::endl;
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

  case 378:
#line 9312 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Logical negation (NOT) operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(!(*var));
  ;}
    break;

  case 379:
#line 9320 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix increment operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)++);
  ;}
    break;

  case 380:
#line 9328 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix decrement operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)--);
  ;}
    break;

  case 381:
#line 9336 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Transpose operator, usefull for matrices
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->Transpose());
  ;}
    break;

  case 382:
#line 9388 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Array subscript operator.
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)[var2]);
  ;}
    break;

  case 384:
#line 9402 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Cast operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->BasicCast( (yysemantic_stack_[(4) - (2)].aint)));

  ;}
    break;

  case 385:
#line 9411 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    //cout << "T_SUB  cast_var  " << std::endl;
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(-(*var));
  ;}
    break;

  case 386:
#line 9417 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(+(*var));
  ;}
    break;

  case 387:
#line 9422 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(++(*var));
  ;}
    break;

  case 388:
#line 9427 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(--(*var));
  ;}
    break;

  case 389:
#line 9432 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sin());
  ;}
    break;

  case 390:
#line 9437 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_cos());
  ;}
    break;

  case 391:
#line 9442 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sqrt());
  ;}
    break;

  case 392:
#line 9447 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_fabs());
  ;}
    break;

  case 393:
#line 9452 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_round());
  ;}
    break;

  case 394:
#line 9457 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_floor());
  ;}
    break;

  case 395:
#line 9462 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_tan());
  ;}
    break;

  case 396:
#line 9467 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_asin());
  ;}
    break;

  case 397:
#line 9472 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_acos());
  ;}
    break;

  case 398:
#line 9477 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_atan());
  ;}
    break;

  case 399:
#line 9482 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_exp());
  ;}
    break;

  case 400:
#line 9487 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_log());
  ;}
    break;

  case 401:
#line 9492 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_ln());
  ;}
    break;

  case 402:
#line 9497 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_norm());
  ;}
    break;

  case 404:
#line 9507 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*var2);
  ;}
    break;

  case 405:
#line 9513 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/var2);
  ;}
    break;

  case 406:
#line 9519 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)%var2);
  ;}
    break;

  case 408:
#line 9530 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res(*var1+var2);
    driver.var_stack.AddVar(res);
  ;}
    break;

  case 409:
#line 9537 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res((*var1)-var2);
    driver.var_stack.AddVar(res);
  ;}
    break;

  case 412:
#line 9552 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<var2);
  ;}
    break;

  case 413:
#line 9558 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>var2);
  ;}
    break;

  case 414:
#line 9564 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<=var2);
  ;}
    break;

  case 415:
#line 9570 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>=var2);
  ;}
    break;

  case 417:
#line 9580 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)==var2);
  ;}
    break;

  case 418:
#line 9586 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)!=var2);
  ;}
    break;

  case 420:
#line 9613 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    driver.err_print("binary operator & between variables not defined at the moment ...\n");
  ;}
    break;

  case 423:
#line 9626 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    driver.err_print("binary operator | between variables not defined at the moment ...\n");
  ;}
    break;

  case 425:
#line 9635 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical AND operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)&&var2);
  ;}
    break;

  case 427:
#line 9648 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical XOR operator, for vectorial images it defines the pointwise vectorial product.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)^var2);
  ;}
    break;

  case 429:
#line 9661 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical OR operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)||var2);
  ;}
    break;

  case 431:
#line 9674 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 433:
#line 9688 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    //cout << "assignment_var" << std::endl;
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    if (var1->GetPtrCounter()==1) {
      // TODO: here ...
    }
    driver.var_stack.AddVar((*var1)=var2);
  ;}
    break;

  case 434:
#line 9698 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    //cout << "assignment_var" << std::endl;
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1).left_assign(var2));
  ;}
    break;

  case 435:
#line 9705 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)+=var2);
  ;}
    break;

  case 436:
#line 9711 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)-=var2);
  ;}
    break;

  case 437:
#line 9717 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*=var2);
  ;}
    break;

  case 438:
#line 9723 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/=var2);
  ;}
    break;

  case 440:
#line 9790 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
         FloatMatrix::ptr m( new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble)));
         ADD_VARSTACK_PTR(FloatMatrix,m);
      ;}
    break;

  case 441:
#line 9796 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
        /**
        Description: adds a reference to the variable in the stack
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        driver.var_stack.AddVar(var->NewReference());
      ;}
    break;

  case 442:
#line 9805 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 443:
#line 9950 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 444:
#line 9965 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      SurfacePoly* surf;
      surf = Func_isosurf(im,
              (yysemantic_stack_[(6) - (5)].adouble),
              NULL,
              2);
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 445:
#line 9977 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 446:
#line 9999 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(lines));
      driver.var_stack.AddVar(res);

      delete crestlines;
    ;}
    break;

  case 447:
#line 10035 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 448:
#line 10044 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)

      newsurf = Func_decimate( varsurf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(newsurf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 449:
#line 10054 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
      surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 450:
#line 10063 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,surf)

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(newsurf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 451:
#line 10073 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,surf)
      SurfacePoly* newsurf;

      newsurf = Func_vtkWindowedSinc( surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      if (newsurf==NULL) {
        driver.err_print("vtkWindowedSinc failed!");
        YYABORT;
      }
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(newsurf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 452:
#line 10087 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 453:
#line 10094 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      SurfacePoly* surf = new SurfacePoly();
      surf->Read(filename.get());
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 454:
#line 10103 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
        BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
        driver.var_stack.AddVar(res);
      ;}
    break;

  case 455:
#line 10119 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
        BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
        driver.var_stack.AddVar(res);
      ;}
    break;

  case 456:
#line 10138 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
          driver.var_stack.AddVar(res);
        }
    ;}
    break;

  case 457:
#line 10158 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
        BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
        driver.var_stack.AddVar(res);
      }
    ;}
    break;

  case 458:
#line 10188 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
        BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
        driver.var_stack.AddVar(res);
      }
    ;}
    break;

  case 459:
#line 10217 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,insurf)
      SurfacePoly* surf;

      surf = Func_ResampleLines( insurf.get(),
                     (yysemantic_stack_[(6) - (5)].adouble));

      if (surf==NULL) {
        driver.err_print("ResampleLines() error ... \n");
        YYABORT;
      } else {
        BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
        driver.var_stack.AddVar(res);
      }
    ;}
    break;

  case 460:
#line 10235 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 461:
#line 10261 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 462:
#line 10294 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 463:
#line 10330 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 464:
#line 10376 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 465:
#line 10414 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
    GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 466:
#line 10423 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 467:
#line 10445 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(),minth,maxth);
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 468:
#line 10456 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);

      surf = AMIFluid::Func_vtkCreateFlatMesh(im.get(),minth,maxth);
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 469:
#line 10467 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 470:
#line 10503 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 471:
#line 10545 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 472:
#line 10591 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 473:
#line 10641 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 474:
#line 10683 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    ;}
    break;

  case 475:
#line 10714 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr varres(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(varres);
    ;}
    break;

  case 476:
#line 10746 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr varres(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(varres);
    ;}
    break;

  case 494:
#line 10853 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 495:
#line 10873 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 496:
#line 10890 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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

  case 497:
#line 10911 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 8690 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -1520;
  const short int
  Parser::yypact_[] =
  {
      4895,  8870,  7900,  7900,  7900,    30, -1520, -1520, -1520,  7900,
    7900,  7900, -1520, -1520,    66,   123, -1520, -1520, -1520, -1520,
    8233, -1520,   -40,    20, -1520,   -48,  7900,  7900,  7900,   131,
    7900, -1520,   135,   201, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520,    34,  -105,    97,    -2,
    7900,   273, -1520, -1520, -1520, -1520,   285,   313,  4066,  7900,
     316,   113,   337,   132,   317,   358,   375,   382,   383,   397,
     399,   400,   401,   402,   403,   404,   405,   406,   407, -1520,
   -1520, -1520, -1520,   408,   409,   410,   147,   166,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   430,   432,   433,   434,   435,
     436,   437,   438,   396,   439,   440,   441,   443,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   463,   466,   467,   469,   470,   471,
     472,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   485,   486,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   498,   499,   500,   501,   502,   503,   504,   506,
     507,   508,   509,  6568,   510,   511,   512,   513,   514,   516,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520,   517,   518,   520,   521,   522, -1520, -1520,  7900,  7900,
    7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,
    7900,  7900,    34, -1520,    -2, -1520,  7900,  5236,  7900,   523,
     524,   525,   526,   -20,    34,   527,   528,   529,   530,   531,
     217,   532,   534,   535,   536,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548, -1520, -1520, -1520,   549,
     550,   245,  4554, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
      12, -1520, -1520,   274,    91, -1520, -1520, -1520,   335,    23,
   -1520,   344,   266, -1520,    10,   213,   558, -1520,   559,   484,
     561,    -4,   -53, -1520, -1520,   122, -1520,   -63, -1520, -1520,
   -1520, -1520,  7900, -1520,   551,   557,   560,   127, -1520,   130,
   -1520, -1520,   242,   553,   556, -1520, -1520, -1520, -1520,  7900,
    7900,  7900, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520,  7900, -1520,    -2,
      -2, -1520, -1520,  7900, -1520, -1520, -1520, -1520, -1520,   551,
   -1520, -1520, -1520, -1520, -1520, -1520,    -2,  7900,  7900,     3,
   -1520,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,   -48,
    7900,  7900,   -48,   -48,   -48,   -48,   -48,  7900,   -48,   -48,
     -48,   -48,   -48,  7900,  7900,   -48,   -74,    55,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,  7900,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,  7900,  7900,  7900,  7900,  7900,  7900,  7900,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   515,
     519,   -48,   -48,   -48,   -48,   533,  7900,  7900,  7900,   552,
    7900,   554,  7900,  7900,   -48,   -48,   -48,   537,   555,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
    7900,  7900,  7900,   -48,  7900,  7900,   -48,   562,   -48,   563,
     564,  7900,   -48,   -48,  6901,  7900, -1520,  7900,  7900,  7900,
    7900,  7900,  7900,  7900,  7900,  7900,  7900,   -48, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520,   -90, -1520,   566, -1520, -1520, -1520,    12, -1520,
      95,  7900,  7900,   565, -1520, -1520,   567,  7900,  7900,   -48,
    7900,  7900,   252,  7900,  7900,  7900,  7900,  7900,  7900,  7900,
    7900,  7900,  7900,  7900,  7900,  7900,  7900,   -48,   -48,   -48,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,    12,
   -1520,   279,  7900,    99,  8870,  5569,  7900,    34, -1520, -1520,
   -1520,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,
    7900,  7900,  7900,  7900,  7900,  7900,  8870,  7900,  7900,  7900,
    7900,  7900,  7900,  7900,  7900,   342,  7900,  5902,  7900,   442,
     464,  7900,    75,    61,  7900, -1520,   570,   579,   580,    33,
     575,   583,   584,   568,   582,   585,   586,   589, -1520,   590,
     588,   594,   597,   598,   599,   602,   601,   593,   603,   604,
     611,   606,   607,   608,   609,   613,   614,   615,   616,   623,
     618,   619,   620,   621,   587, -1520, -1520,   605, -1520, -1520,
     628,   624,   625,   626,   627,   629,   630,   631,   632,   633,
     634,   641,   642,   643,   638,   645,   640,   644,   646,   647,
     648,    74,   649,   651,   650,   657,    87,   656,   653,   654,
     655,   658,   659,   660,   661,   662,   663,   665,   666,   673,
     668,   675,   151,   670,   671,   672,   674,   676,   677,   678,
     679,   680,   681,   153,   682,   689,   690,   685,   686,   687,
     688,   691,   692,   693,   694,   695,   696,   697,   698,   699,
     700,   702,   703,   710,   711,   712,   707,   708,   101,   709,
     713,   154,   714,   715,   716,   717,   718,   724, -1520,   723,
     720,   727,   728,   729,   730,   731,   732,   733,   734,   735,
     736,  7900,  7900, -1520, -1520,   -11, -1520,   737,   738,   742,
     739,   743,   635,   664,   322,    12,   155,   740,   741,   744,
     745,   749,   156,   746,   747,   163,   164,   748,   750,   751,
     752,   753,   755,   760,   761,   756,   758,   759,   762, -1520,
   -1520,    67,   766,   768, -1520,   770, -1520,   771, -1520, -1520,
    7900, -1520,   772,   773,   774,   775,   776,   777,   778,   779,
     780, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520,   781,  7900,   167, -1520, -1520,   782,
   -1520, -1520, -1520, -1520,   344,   344, -1520, -1520, -1520, -1520,
      10,    10,   213, -1520,   559,   484,   639,   561, -1520, -1520,
   -1520, -1520, -1520, -1520,   783,   784, -1520,  7234,  7567,   786,
     787,   785, -1520,   788,    79, -1520,  8870, -1520, -1520,  7900,
    7900, -1520, -1520,   572,  7900, -1520,   596, -1520, -1520,  7900,
     789, -1520, -1520,   793, -1520,   794,   -15,  7900,  7900, -1520,
    7900,  7900,  7900,  7900,  7900,   -48,  7900,  7900, -1520,  7900,
    7900,  7900,   -48,   -48,   -48, -1520,  7900,  7900,  7900,  7900,
    7900,  7900,  7900,  7900,   -48,  7900, -1520, -1520, -1520,   -48,
   -1520,   -48,   -48,   -48,   -48,   -48, -1520,   -48,   -48, -1520,
    7900, -1520,  7900,   795,  7900,  7900,  7900,  7900,  7900,  7900,
    7900,  7900,  7900,  7900,  7900, -1520,  7900, -1520, -1520,  7900,
    7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,   -48,
   -1520,  7900,  7900, -1520, -1520,   -48,   -48,   -48,   -48,   -48,
    7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,
    7900, -1520, -1520, -1520,  7900,  7900, -1520,  7900,  7900, -1520,
    7900,  7900,  7900,  7900,  7900, -1520, -1520, -1520,  7900, -1520,
   -1520, -1520, -1520, -1520, -1520,  7900,  7900,  7900, -1520,   379,
     790, -1520, -1520, -1520, -1520, -1520, -1520, -1520,  7900, -1520,
    -103,  -103,   754, -1520, -1520,  7900,  7900,   -48,  7900,  7900,
     -48, -1520,  7900,  7900,  7900, -1520,  7900, -1520,  7900,  7900,
    7900,  7900,  7900,  7900, -1520, -1520, -1520,  7900,  7900,   -48,
     -48,  7900,  7900,  7900, -1520,  7900,  7900,   -48, -1520,   -48,
     -48,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  8870, -1520,
   -1520,  6235, -1520,  8870,  7900,  7900, -1520, -1520,  7900,  7900,
    7900,  7900, -1520,   725,   791,   798,  7900,   799,   800,   801,
    7900,   -48,   -48,   168,   796,   797,   804,   805,   806,   808,
     803,   810,   172,   807,   809,   811,   812,   813,   814,   815,
     816,   817,   818,   823,   824,   825,   826,   827,   828,   835,
     837,   833,   834,   836,   839,   845,   848,   841,   856,   851,
     858,  7900,   859,   860,   861,   864,   866,   867,   868,   176,
     869,   870,   877,   872,   873,   881,   882,   883,   884,   887,
     888,   895,   897,   898,   909,   889,   893,   916,   912,   913,
     914,   915,   917,   918,   922,   925,   937,   938,   939,   942,
     945,   187,   946,   947,   949,   188,   951,   956,   957,   958,
     959,   954,   961,   960,   962,   963,  7900,  7900,    12,    12,
     964,   636,   652,   701,   706,   189,   196, -1520,   965,   966,
     969,   967,   970,   971,   219,   972,   973,   980,   983,   981,
     985,   987,   989,   986,   992,   999,   994,   995,    58,   996,
    1004,  1010,  1005,   220,  1013,  1014,  1009,   105,  1018,   118,
    1025,   221,  1020,  1021,   223,   726,  7900, -1520, -1520, -1520,
    1028,  1023,   886,  1032,  1033, -1520,  8870,  7900, -1520, -1520,
   -1520, -1520, -1520,  1037,  1038,   224, -1520,    17,   -14,  7900,
   -1520, -1520, -1520, -1520,  7900, -1520, -1520,   -48,  7900,  7900,
    7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900,
    7900,  7900,  7900,  7900, -1520, -1520,  7900,   -48,   -48,   -48,
     -48,   -48, -1520, -1520,  7900, -1520,  1039, -1520, -1520, -1520,
    7900,  7900,  7900,  7900, -1520,  7900,  7900,  7900, -1520,  7900,
    7900, -1520, -1520, -1520, -1520, -1520,  7900,  7900,  7900,  7900,
    7900, -1520, -1520, -1520,  7900,  7900,   -48,   -48,  7900,  7900,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,  7900,  7900,
    7900,  7900, -1520,   -48, -1520, -1520, -1520, -1520, -1520,  7900,
   -1520,  7900,  7900,  7900,   445, -1520, -1520, -1520,  7900, -1520,
   -1520, -1520, -1520, -1520,    71, -1520,    12, -1520,  7900,  7900,
   -1520,  7900,  7900, -1520,  7900,  7900,  7900, -1520, -1520,  7900,
    7900,  7900,  7900, -1520,  7900, -1520,   -48,  7900, -1520,  7900,
    7900,  7900, -1520, -1520,  7900, -1520,  7900, -1520, -1520,  7900,
   -1520,  7900, -1520, -1520, -1520,  7900,  7900,  7900, -1520,  7900,
    8870, -1520, -1520,  7900, -1520,  1034,  1035, -1520,  1040,   120,
   -1520, -1520, -1520,  7900,  1043,  1042,   232,  1044,  1045,  1046,
    1048,  1047,  1049,  1050,   239,   110,  1051,  1052,  1054,  1055,
     240,  1056,  1057,  1058,  1059,  1062,  1063,  1070,  1065,  1066,
    1067,  1068,  1069,  1071,  1072, -1520,  1076,  1079,   244,   264,
    1074,  1081,  1077,  1078,  1080,  1082,  1083,  1084,  1085,  1087,
    1094,  1095,  1090,  1091,  1092,  1093,  1096,  1100,  1097,  1098,
    1099,  1101,  1106,  1107,  1102,  1103,  7900,    12,  1104,    12,
     769,   921,   928,  1001,    12, -1520,  1105,  1108,  1112,  1109,
    1113,  1110,  1117,  1114,  1115,  1118,  1116,  1119,  1120,  1121,
      78,  1123,  1041,  1124,  1122,  1125,  1126,   265,  1127,  1128,
    1129,  1130,  1131,  7900,  7900,  7900, -1520,  1138, -1520,   569,
   -1520,    17,  1089,  7900,  7900, -1520,  7900,  7900,  7900, -1520,
    7900,  7900,  7900,  7900,  7900,  7900, -1520,  7900,  7900,  8557,
    7900,  7900,  7900,  7900, -1520,  7900,  7900,  7900,  7900,  7900,
     -48,  7900, -1520, -1520, -1520,  7900, -1520,  7900,  7900, -1520,
    7900,  7900,  7900,  7900,  7900,  7900,  7900,  7900, -1520, -1520,
    7900,   -48,   -48,  7900,  7900, -1520,  7900,  7900,  7900, -1520,
   -1520, -1520,  7900,  7900, -1520, -1520,  7900, -1520, -1520, -1520,
   -1520, -1520, -1520,  7900,  7900, -1520,  7900, -1520,  7900, -1520,
    7900,  7900, -1520,  7900,  7900,   -48,  7900, -1520,  7900,  7900,
   -1520,  7900, -1520,  7900,  7900,  7900, -1520,  7900,  7900,  7900,
    7900,  8870,  7900, -1520, -1520,   275, -1520,  1139,   276,  1134,
    1135,  1137,  1140,  1144,  1141,  1142,  1143,  1145,  1146,  1147,
    1148,  1150,  1149,  1156,   335,  1157,  1152,  1153,  1154,  1155,
    1158,  1159,  1160,  1161,  1162,   277,  1163,  1170,   280,  1171,
    1166,  1167,  1174,  1175,  1172,  1173,  1176,  1178,  1179,   287,
    1180,  1177,   288,  1181,  1182,  1187,  1188,  1189,    12,  1184,
    1185,  1186,  1193,  1190,  1191,  1194,  1195,  1196,  1198,  1199,
    1206,  1207,  1202,  1203,  1210,  1211,  1212,  1213,  1214,  1216,
    1111,  1217, -1520,  7900, -1520, -1520,    17,  7900,  7900,  7900,
    7900, -1520,  7900,  7900,  7900,  7900,  7900,  7900,  8557, -1520,
    8557, -1520, -1520,  8557,  8557,  7900,  7900,  7900,   -48,   -48,
     -48,   -48, -1520,  7900,  7900, -1520, -1520,  7900, -1520,  7900,
    7900, -1520, -1520,  7900,  7900, -1520,  7900,  7900, -1520,  7900,
     -48, -1520, -1520,  7900, -1520, -1520, -1520, -1520, -1520, -1520,
    7900,  7900,  7900, -1520,  7900,  7900,  7900,  7900,  7900,   -48,
    7900, -1520, -1520,  7900,  7900, -1520, -1520, -1520, -1520, -1520,
   -1520,  8870, -1520,  1218,  1219,  1221,  1234,  1222,  1235,   291,
    1223,  1237,  1244,  1246,  1241,  1248,  1249,  1251,  1252,  1247,
    1254,  1255,  1264,  1267,  1262,  1263,  1270,  1265,  1276,  1277,
    1272,  1273,  1274,  1280,  1281,  1282,  1283,  1288,  1284,  1291,
    1286,   292,  1287,  1292,  1293,  1294,  1295,  1296,  1275,  1303,
   -1520, -1520, -1520, -1520,  7900, -1520,  7900, -1520,  7900, -1520,
    7900, -1520, -1520,  7900, -1520, -1520, -1520, -1520,  8557, -1520,
   -1520, -1520, -1520,  7900,  7900, -1520,  7900, -1520, -1520,  7900,
    7900,  7900,  7900,  7900, -1520,   -48, -1520,  7900, -1520,  7900,
   -1520,  7900,  7900,  7900,  7900,  7900,   -48,  7900,  7900, -1520,
    1299,  1310,  1312,  1313,  1309,  1316,  1311,  1314,  1318,  1315,
    1317,  1320,   295,  1323,  1327,  1328,  1329,  1332,   296,  1319,
    1333,  1335,  1336,  1338,  1322,  7900, -1520, -1520, -1520,  7900,
   -1520,  7900,  7900, -1520,  7900,  7900,  7900, -1520,  7900,  7900,
     -48,  7900,  7900,  7900, -1520,  7900, -1520,  7900,  7900,   -48,
    7900,   591,  1348,  1349,  1350,  1345,   304,  1353,  1352,  1354,
    1358,   307,  1360,  1361,  1356,   308,   311,  1362,  1364,  1365,
    7900, -1520, -1520, -1520,  7900, -1520,  7900, -1520,  7900,  7900,
    7900, -1520,  7900,  7900,  7900, -1520, -1520,  7900, -1520,  7900,
    7900,  7900,  7900, -1520,  1366,  1359,  1373,  1368,  1375,  1376,
    1377,  1372,  1380,  1378,  1379,  1381,  1382,  7900, -1520, -1520,
    7900, -1520, -1520, -1520,  7900, -1520,  7900,  7900,  7900,   -48,
    1383,  1386,  1384,  1389,  1391,  1387,  1388, -1520, -1520,  7900,
   -1520, -1520,  7900,   -48,  1390,  1392,  1393,  7900,  7900,  7900,
    1394,  1395,  1397,  7900,  7900, -1520,  1396,  1398,  7900,  7900,
    1399,  1400,  7900,  7900,  1403,  1407, -1520, -1520
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,     0,     0,     0,     0,     0,    21,    61,    62,     0,
       0,     0,    65,    66,     0,     0,   178,   183,    41,    20,
       0,   250,     0,    82,    70,     0,     0,     0,     0,     0,
       0,    81,     0,     0,   172,   182,   477,   365,   244,   361,
     441,   478,   479,   481,   480,   482,   483,   364,   484,     0,
       0,     0,    43,    46,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   144,
     145,   174,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     0,     0,     0,   184,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,     0,
       0,     0,     0,     4,     8,    10,    14,    16,    18,    12,
       0,   362,   366,     0,   246,   360,   367,   369,   374,   383,
     403,   407,   410,   411,   416,   419,   421,   422,   424,   426,
     428,   430,   432,   439,    40,   370,   368,     0,   363,   485,
      39,   375,     0,   364,     0,     0,     0,   246,   378,   246,
     386,   385,     0,     0,     0,    63,   229,    64,    67,     0,
       0,     0,   247,   231,    73,    76,    71,    88,    85,    86,
      87,    84,    83,    72,    89,    90,    91,     0,    80,     0,
       0,    35,    94,     0,   487,   488,   489,   483,   486,   484,
     490,   493,   491,   492,    78,    79,     0,     0,     0,   387,
     388,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   453,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   389,   390,
     395,   396,   397,   398,   399,   401,   400,   391,   392,   393,
     394,   402,     0,    25,     0,   180,   180,    37,     0,    38,
       0,     0,     0,     0,    31,    29,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     3,     5,     9,    11,    15,    17,    19,    13,     0,
       6,     0,     0,     0,     0,   156,     0,     0,   379,   380,
     381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   373,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,     0,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,     0,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   452,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,    26,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
     228,     0,   229,     0,   175,     0,   497,     0,    92,    93,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,     0,     0,     0,   161,   157,     0,
     376,   404,   405,   406,   408,   409,   413,   412,   414,   415,
     417,   418,   420,   423,   425,   427,     0,   429,   434,   435,
     436,   437,   438,   433,     0,     0,    55,     0,     0,   233,
     236,    51,    53,     0,     0,   384,     0,    68,    69,     0,
       0,   176,   177,   245,     0,    47,     0,   210,   212,     0,
       0,   213,   214,     0,   215,     0,     0,     0,     0,   286,
       0,     0,     0,     0,     0,     0,     0,     0,   287,     0,
       0,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   272,   273,     0,
     275,     0,     0,     0,     0,     0,   282,     0,     0,   206,
       0,   211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   289,     0,   456,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     454,     0,     0,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   340,   138,   139,     0,     0,   208,     0,     0,   447,
       0,     0,     0,     0,     0,   267,   269,   371,     0,   442,
     312,   313,   314,   315,   222,     0,     0,     0,   141,     0,
     180,   154,   179,   180,    27,   225,   226,   227,     0,   143,
     163,   163,     0,    33,   344,     0,     0,     0,     0,     0,
       0,   465,     0,     0,     0,   351,     0,   353,     0,     0,
       0,     0,     0,     0,   355,   356,   112,     0,     0,     0,
       0,     0,     0,     0,   341,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     377,     0,   382,     0,     0,     0,    50,    49,     0,     0,
       0,     0,   245,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,     0,   246,
       0,     0,     0,     0,     0,     0,     0,   162,   158,   431,
       0,     0,     0,     0,     0,    52,     0,     0,   173,    56,
      77,    48,   372,     0,     0,     0,   259,     0,     0,     0,
     285,   288,   290,   291,     0,   292,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,   270,     0,     0,     0,     0,
       0,     0,   283,   284,     0,   221,     0,   254,   255,   256,
       0,     0,     0,     0,   119,     0,     0,     0,   125,     0,
       0,   459,   316,   317,   318,   319,     0,     0,     0,     0,
       0,   455,   359,   325,     0,     0,     0,     0,     0,     0,
     330,   331,   332,   333,   334,   335,   336,   337,     0,     0,
       0,     0,   443,     0,   444,   448,   449,   450,   451,     0,
     440,     0,     0,     0,   180,   155,    24,    28,     0,   167,
     164,   166,   165,   180,     0,   180,     0,   345,     0,     0,
     346,     0,     0,   466,     0,     0,     0,   350,   352,     0,
       0,     0,     0,   354,     0,   147,     0,     0,   186,     0,
       0,     0,   192,   103,     0,   102,     0,   110,   111,     0,
     132,     0,   134,   135,    97,     0,     0,     0,    95,     0,
       0,   160,   223,     0,    54,    59,    57,   496,     0,   246,
     216,   217,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,     0,     0,     0,     0,
       0,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,     0,     0,     0,     0,   253,     0,   260,     0,
     261,     0,     0,     0,     0,   137,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,     0,   310,     0,     0,     0,     0,     0,
       0,     0,   257,   258,   114,     0,   116,     0,     0,   120,
       0,     0,     0,     0,     0,     0,     0,     0,   358,   326,
       0,     0,     0,     0,     0,   338,     0,     0,     0,   445,
     446,   140,     0,     0,   180,    22,     0,    32,   171,   169,
     170,   168,    30,     0,     0,   349,     0,   467,     0,   468,
       0,     0,   153,     0,     0,     0,     0,   187,     0,     0,
     191,     0,    74,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,    60,    58,     0,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   375,     0,   375,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   251,     0,   262,   263,     0,     0,     0,     0,
       0,   268,     0,     0,     0,     0,     0,     0,     0,   301,
       0,   303,   305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,     0,     0,   115,   117,     0,   121,     0,
       0,   130,   458,     0,     0,   462,     0,     0,   129,     0,
       0,   327,   328,     0,   339,   207,   209,   342,   343,    23,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,   189,   190,     0,     0,   131,   133,    98,   100,   188,
      96,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     494,   252,   264,   265,     0,   296,     0,   322,     0,   324,
       0,   294,   297,     0,   302,   304,   306,   307,     0,   309,
     274,   276,   277,     0,     0,   281,     0,   118,   124,     0,
       0,     0,     0,     0,   128,     0,   329,     0,   347,     0,
     469,     0,     0,     0,     0,     0,     0,     0,     0,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,   323,   321,     0,
     308,     0,     0,   311,     0,     0,     0,   464,     0,     0,
       0,     0,     0,     0,   473,     0,   474,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,   298,   278,     0,   122,     0,   460,     0,     0,
       0,   127,     0,     0,     0,   470,   471,     0,   475,     0,
       0,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   461,
       0,   142,   126,   357,     0,   472,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   279,   463,     0,
     476,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   348,   151
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -1520, -1520, -1520,  -149,   497,   578,   847, -1520, -1520,   892,
     907,   924,  1183, -1520, -1520,  -291, -1520,  -493, -1520, -1520,
   -1520,   -10,  1930,    45,    22,  1676, -1520, -1520, -1520,    48,
    1136,    21,  -219, -1520,  -165,  -207,   169, -1520,   231,   831,
     230,   229, -1520, -1520,  -225,  2607, -1520, -1520,   -19,   -42,
     600,     5, -1520,  -208, -1519
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   251,   252,   253,   254,   255,   256,   743,   742,   257,
     258,   259,   260,   990,   806,  1175,   261,   493,   494,   992,
     262,   305,   597,   312,   263,   299,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   306,   285,   286,   287,   288,
     289,   342,   343,   344,   291
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       307,   308,   734,   735,   322,   290,   495,   341,  1631,  1633,
    1635,    38,     6,   745,   731,   556,   557,   566,   546,    38,
     576,   294,   547,   300,   301,    19,   302,   331,   314,   294,
     568,   569,   570,   571,   572,     6,   545,    36,   546,  1073,
    1406,   577,   547,   332,    38,    38,   504,   584,    19,   298,
     304,   573,   541,   849,   294,   294,   334,    38,   335,   336,
      41,    42,    43,    44,    45,   337,   338,   339,   497,   624,
     625,   626,  1368,   326,   317,   328,    38,    36,  1369,   309,
     350,  1370,   318,   319,   320,   321,   294,  1031,   906,  1032,
    1033,    36,  1597,   567,   907,   345,   548,   549,  1598,  1031,
     581,  1599,  1033,   532,   542,   550,   583,   912,   558,   559,
     543,   540,   333,   774,   581,   966,   548,   549,   581,  1380,
     583,   591,   592,   581,   583,   550,   352,   774,   353,   583,
    1521,   581,  1382,   581,  1506,   574,   310,   583,   594,   583,
     581,   575,   776,   581,   327,   355,   582,   356,   329,   583,
     773,   774,    36,   334,    38,   335,   336,    41,    42,    43,
      44,    45,   337,   338,   339,   928,   376,   940,   969,  1004,
    1011,   929,   341,   941,   970,  1005,  1012,  1015,  1017,   775,
     776,  1050,  1236,  1016,  1018,   377,  1246,  1051,  1237,  1785,
    1284,  1786,  1247,   492,  1787,  1788,  1285,   732,   627,   628,
     629,  1317,  1322,  1343,   505,   506,   496,  1318,  1323,  1344,
    1345,  1171,  1172,  1173,   330,  1174,  1344,   777,   466,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,  1353,  1375,  1384,   512,  1388,  1402,  1354,
    1376,  1385,   778,  1389,  1403,   530,  1510,   779,   780,   781,
     782,   783,  1511,  1519,  1526,   315,   584,   290,  1544,  1520,
    1527,   541,   498,   499,  1545,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   554,   555,  1546,  1606,
     784,   785,   786,   993,  1547,  1607,   346,   341,   341,  1692,
    1695,  1722,   738,   541,  1726,  1693,  1696,  1723,   347,   587,
    1727,  1738,  1742,   789,   341,  1827,  1860,  1739,  1743,  1907,
    1914,  1828,  1861,   560,   561,  1908,  1915,   789,  1945,  1875,
     791,  1951,  1956,   593,  1946,  1958,   348,  1952,  1957,   351,
     357,  1959,   358,   589,   791,   814,   815,   595,   596,   787,
     788,   789,   790,   828,   829,   830,   831,   832,   833,   736,
     354,   551,   552,   820,   821,   588,   553,   544,   791,   792,
     793,   794,   795,   796,   797,   798,   799,   800,   801,   802,
     803,   359,   590,   792,   793,   794,   795,   796,   797,   798,
     799,   800,   801,   802,   803,  1470,  1471,  1472,   360,  1473,
     769,   816,   817,   818,   819,   361,   362,   792,   793,   794,
     795,   796,   797,   798,   799,   800,   801,   802,   803,   403,
     363,   404,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   704,   705,   395,   707,   396,   397,   398,   399,   400,
     401,   402,   405,   406,   407,   719,   408,   720,   341,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   683,   425,   685,   686,   426,
     427,   737,   428,   429,   430,   431,   302,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,  1168,   442,   443,
    1169,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     759,   453,   454,   455,   456,   457,   458,   459,   726,   460,
     461,   462,   463,   467,   468,   469,   470,   471,   810,   472,
     473,   474,   771,   475,   476,   477,   500,   501,   502,   503,
     507,   508,   509,   510,   511,   513,   739,   514,   515,   516,
     808,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   834,   565,   578,   585,   843,   763,
     764,   844,   811,   812,   813,   562,   579,   563,   586,   580,
     564,   751,   835,   672,   853,   624,   994,   673,   770,   744,
     846,   690,   804,   847,   848,   850,  1003,   851,   852,   855,
     883,   678,   854,   857,   858,   845,   856,   627,   859,   691,
     860,   861,   862,   866,   826,   863,   864,   865,   884,   741,
     682,   733,   684,   867,   868,   869,   870,   871,   872,   873,
     711,   713,   714,   874,   875,   876,   877,   878,   879,   880,
     881,   882,   885,  1002,   886,   887,   888,   889,  1000,   890,
     891,   892,   893,   894,   895,   896,   897,   898,   899,   900,
     901,  1053,  1068,  1166,   902,   909,   903,   904,   905,   908,
     910,   911,   913,   914,   915,   916,  1066,  1001,   917,   918,
     919,   920,   921,   922,  1346,   923,   924,   925,   926,   927,
     930,   931,   932,  1339,   933,  1940,   934,   935,   936,   937,
     938,   939,   942,   943,   944,   945,   946,   947,   948,  1340,
    1176,   949,   950,   951,   952,   953,   954,   955,   956,   957,
     958,   989,   959,   960,   961,   962,   963,   964,   965,   967,
    1466,   822,   975,   968,   971,   972,   973,   974,   976,   977,
     978,   979,   980,   981,   982,   983,   984,  1226,  1390,   533,
     988,   995,   996,   985,   986,   987,   997,   999,  1341,   998,
    1006,  1007,  1010,  1342,  1008,  1009,  1013,  1014,  1019,  1024,
    1020,  1021,  1022,  1023,  1025,  1026,  1027,   991,  1028,  1029,
    1034,  1035,  1030,  1036,  1037,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,  1047,   823,   825,   827,  1055,  1052,  1059,
    1060,  1048,  1070,  1054,  1062,  1061,  1071,  1072,  1111,     0,
    1167,  1227,  1228,  1230,  1231,  1232,  1238,  1239,  1240,  1241,
    1242,  1177,  1243,  1244,  1245,  1038,  1578,  1248,   791,  1249,
     534,  1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1064,
    1065,  1467,  1057,  1258,  1259,  1260,  1261,  1262,  1263,  1264,
    1469,  1265,  1474,  1266,  1267,  1272,  1268,  1075,  1076,  1269,
    1077,  1078,  1079,  1080,  1081,  1270,  1083,  1084,  1271,  1085,
    1273,  1274,  1275,  1277,  1278,  1279,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,  1098,  1280,  1100,  1281,  1282,  1283,  1286,
    1287,  1288,  1289,  1290,  1063,  1291,  1292,  1293,  1294,  1067,
    1109,  1295,  1394,  1301,  1112,  1113,  1114,  1302,  1296,  1117,
    1118,  1119,  1120,  1121,  1122,  1297,  1123,  1298,  1299,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1300,
    1303,  1135,  1304,  1305,  1306,  1307,  1310,  1308,  1309,  1311,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1312,  1313,  1314,  1153,  1154,  1315,  1155,  1156,  1316,
    1157,  1158,  1159,  1160,  1161,  1324,  1319,  1320,  1162,  1321,
    1325,  1326,  1327,  1328,  1329,  1330,  1164,  1165,  1579,  1347,
    1331,  1350,  1332,  1333,  1338,  1580,  1348,  1136,  1170,  1349,
    1351,  1352,  1355,  1356,  1357,  1178,  1179,  1358,  1181,  1182,
    1363,  1359,  1184,  1185,  1186,  1360,  1187,  1361,  1188,  1362,
    1190,  1191,  1364,  1365,  1366,  1367,  1371,  1194,  1372,  1336,
    1337,  1198,  1199,  1200,  1373,  1374,  1202,  1377,  1378,  1379,
    1163,  1206,  1208,  1210,  1211,  1212,  1213,  1214,  1381,  1383,
    1386,  1387,  1392,  1393,  1220,  1221,  1395,  1396,  1222,  1223,
    1224,  1400,  1401,  1435,  1503,  1504,  1218,  1508,  1581,     0,
    1505,  1509,  1515,  1601,  1512,  1513,  1514,  1516,     0,  1517,
    1518,  1522,  1523,  1195,  1524,  1525,  1528,  1529,  1530,  1531,
    1201,  1668,  1532,  1533,  1534,  1535,  1536,  1537,  1538,  1539,
    1542,  1540,  1541,  1543,  1548,  1549,  1215,  1550,  1551,   535,
    1552,  1219,  1553,  1554,  1555,  1556,  1225,  1557,  1558,  1559,
    1560,  1561,  1562,  1563,  1565,  1569,  1564,  1566,  1567,  1568,
    1570,  1571,  1572,  1573,  1576,  1583,  1585,  1587,  1584,  1586,
    1588,  1589,  1592,  1771,  1590,  1591,  1593,  1600,  1602,  1594,
    1595,  1596,  1603,  1618,   536,  1604,  1605,  1608,  1609,  1610,
    1611,  1612,  1616,  1694,  1697,  1698,  1334,  1699,  1701,   537,
    1700,  1702,  1703,  1704,  1709,  1705,  1706,  1707,  1708,  1710,
    1711,  1712,  1713,  1714,  1715,  1716,   538,   842,  1717,  1718,
    1719,  1720,  1721,  1724,  1725,  1728,  1729,  1730,  1731,  1732,
    1735,  1741,  1733,  1734,   349,  1744,  1745,  1475,  1736,  1737,
    1740,  1746,  1747,  1748,  1750,  1751,  1752,  1753,     0,     0,
    1754,  1755,  1335,     0,  1756,  1757,  1758,  1398,  1759,  1760,
    1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,  1408,
    1770,  1772,  1821,  1822,  1409,  1823,  1825,  1829,  1411,  1412,
    1413,  1414,  1416,  1417,  1418,  1419,  1420,  1421,  1422,  1423,
    1424,  1425,  1426,  1427,  1824,  1826,  1428,  1830,  1831,  1404,
    1832,  1833,  1834,  1835,  1434,  1836,  1837,  1838,  1839,  1840,
    1436,  1437,  1438,  1439,  1397,  1440,  1442,  1443,  1841,  1444,
    1445,  1842,  1843,  1844,  1845,  1846,  1446,  1447,  1448,  1449,
    1847,  1848,  1849,  1850,  1851,  1452,  1854,  1868,  1455,  1456,
    1852,  1853,  1856,  1855,  1857,  1858,  1859,  1862,  1457,  1458,
    1459,  1460,  1863,  1864,  1865,  1866,  1867,  1869,  1575,  1895,
    1577,  1463,  1464,  1465,  1896,  1582,  1897,  1898,  1468,  1899,
    1900,  1901,  1903,  1916,  1902,  1904,  1921,  1905,  1476,  1477,
    1906,  1478,  1479,  1909,  1480,  1481,  1482,  1910,  1911,  1912,
    1484,  1485,  1913,  1917,  1487,  1918,  1919,  1489,  1920,  1490,
    1491,  1492,  1941,  1942,  1943,  1944,  1494,  1947,     0,  1495,
    1955,  1496,  1948,  1978,  1949,  1497,  1498,  1499,  1950,  1500,
    1953,  1954,  1960,  1502,  1961,  1962,  1977,  1979,  1980,  1981,
    1982,  1983,  1984,  1507,  1985,   824,     0,  1997,  1986,  1987,
    1998,  1988,  1989,  2000,  1999,  2001,     0,  2002,  2003,     0,
    2007,  2015,  2008,  2009,  2013,  2014,  2018,  2026,  2019,  2022,
    2023,  2027,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   539,     0,     0,  1501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1574,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1615,     0,     0,     0,     0,
       0,     0,     0,  1619,  1620,     0,  1621,  1622,  1623,     0,
    1624,  1625,  1626,  1627,  1628,  1629,     0,  1630,  1632,  1749,
    1636,  1637,  1638,  1639,     0,  1640,  1641,  1642,  1643,  1644,
       0,  1646,     0,  1617,     0,     0,     0,     0,     0,     0,
       0,  1651,  1652,  1653,  1654,  1655,  1656,  1657,  1613,  1614,
    1658,     0,     0,  1661,  1662,     0,  1663,  1664,  1665,     0,
       0,     0,  1666,  1667,     0,     0,  1669,     0,     0,     0,
       0,     0,     0,  1670,  1671,     0,  1672,  1634,     0,     0,
    1674,  1675,     0,  1676,  1677,     0,  1679,     0,  1680,  1681,
       0,  1682,     0,  1683,  1684,  1685,     0,  1686,  1687,  1688,
    1689,     0,  1691,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1690,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   297,     0,     0,
       0,     0,     0,  1773,     0,     0,     0,  1775,  1776,  1777,
    1778,     0,  1779,  1780,  1781,  1782,  1783,  1784,   316,     0,
       0,   323,     0,     0,     0,  1789,  1790,  1791,     0,     0,
       0,     0,     0,  1796,  1797,     0,     0,  1798,  1774,  1799,
    1800,     0,     0,  1801,  1802,   340,  1803,  1804,     0,     0,
       0,     0,     0,  1807,     0,     0,     0,     0,     0,     0,
    1808,  1809,  1810,     0,     0,  1812,  1813,  1814,  1815,     0,
    1817,     0,     0,  1818,  1819,     0,  1634,     0,  1634,     0,
       0,  1634,  1634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1870,     0,  1871,     0,  1872,  1820,
    1873,     0,     0,  1874,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1876,  1877,     0,  1878,     0,     0,  1879,
    1880,  1881,  1882,  1883,     0,     0,     0,  1885,     0,  1886,
       0,     0,  1888,  1889,  1890,  1891,     0,  1893,  1894,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1922,  1634,     0,     0,  1923,
     340,  1924,  1925,     0,  1926,  1927,  1928,     0,  1929,  1930,
       0,  1932,  1933,  1934,     0,  1935,     0,  1936,  1937,     0,
    1939,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,     0,     0,  1964,     0,     0,     0,  1966,  1967,
    1968,     0,     0,  1970,  1971,     0,     0,  1972,     0,     0,
    1974,  1975,  1976,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1990,     0,     0,
    1991,     0,     0,     0,  1992,     0,     0,  1994,  1995,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2004,
       0,     0,  2005,     0,     0,     0,     0,  2010,  2011,  2012,
       0,     0,     0,  2016,  2017,   340,   340,     0,  2020,  2021,
       0,     0,  2024,  2025,     0,     0,     0,     0,     0,     0,
       0,     0,   340,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   607,     0,     0,   610,   611,
     612,   613,   614,     0,   616,   617,   618,   619,   620,     0,
       0,   623,     0,     0,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,     0,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   656,
       0,     0,     0,     0,     0,     0,   663,   664,   665,   666,
     667,   668,   669,   670,   671,     0,     0,   674,   675,   676,
     677,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     687,   688,   689,     0,     0,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,     0,     0,     0,   706,
     708,     0,   710,     0,   712,     0,     0,     0,   716,   717,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   730,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   340,     0,     0,     0,
       0,     0,     0,     0,     0,   748,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   766,   767,   768,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     297,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   599,   601,   602,   603,   604,   605,   606,     0,
     608,   609,     0,     0,     0,     0,     0,   615,     0,     0,
       0,     0,     0,   621,   622,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   640,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   655,   657,   658,   659,   660,   661,   662,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   679,   680,   681,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     703,     0,     0,     0,     0,   709,     0,     0,     0,     0,
       0,   715,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   727,   728,   729,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   740,     0,     0,     0,     0,   746,   747,     0,
     749,   750,     0,   752,   753,   754,   755,   756,   757,   758,
       0,   760,   761,   762,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   836,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1074,     0,     0,     0,     0,     0,     0,     0,
       0,  1082,     0,     0,     0,     0,     0,     0,  1088,  1089,
    1090,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1099,     0,     0,     0,     0,  1101,     0,  1102,  1103,  1104,
    1105,  1106,     0,  1107,  1108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
       0,   303,     0,     0,     0,  1134,     0,     0,     0,     0,
       0,  1137,  1138,  1139,  1140,  1141,     0,   313,     0,     0,
       0,     0,     0,   324,   325,   313,     0,   313,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1180,     0,     0,  1183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1196,  1197,     0,     0,     0,
       0,     0,     0,  1203,     0,  1204,  1205,  1207,  1209,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,   297,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1234,  1235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1086,  1087,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   313,   313,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,     0,  1115,  1116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   303,
       0,     0,   297,  1399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1405,  1407,     0,     0,   313,   303,     0,
       0,     0,     0,  1410,     0,     0,     0,  1415,     0,     0,
       0,     0,     0,     0,   313,     0,     0,     0,     0,     0,
       0,     0,     0,  1429,  1430,  1431,  1432,  1433,     0,  1189,
       0,     0,  1192,  1193,     0,     0,     0,     0,   598,   600,
     598,   598,   598,   598,   598,   598,     0,   598,   598,     0,
       0,     0,     0,     0,   598,     0,     0,     0,     0,     0,
     598,   598,  1453,  1454,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   598,  1229,     0,     0,  1461,
    1233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     598,   598,   598,   598,   598,   598,   598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   598,   598,   598,     0,   313,     0,   313,
     313,  1276,  1488,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,     0,     0,
       0,     0,   598,     0,     0,     0,   297,     0,   598,     0,
       0,   303,     0,     0,     0,   721,   722,   723,   724,   725,
     313,   598,   598,   598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   313,   598,
       0,     0,     0,     0,   598,   598,     0,   598,   598,     0,
     598,   598,   598,   598,   598,   598,   598,     0,   598,   598,
     598,   313,   313,   765,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   772,
       0,     0,   807,   809,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   598,   841,     0,     0,  1405,   772,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1645,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1450,     0,     0,     0,  1451,     0,     0,  1659,  1660,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1462,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1678,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,  1483,
       0,     0,  1486,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   313,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1405,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,     0,     0,
       0,     0,     0,     0,  1792,  1793,  1794,  1795,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1049,     0,     0,     0,  1806,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1816,     0,     0,     0,     0,
       0,     0,     0,     0,  1056,   313,     0,   297,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   313,     0,     0,     0,     0,  1069,     0,     0,     0,
       0,     0,     0,     0,     0,  1647,     0,  1648,  1649,     0,
    1650,     0,     0,     0,     0,     0,     0,   598,   598,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1673,   598,
       0,     0,     0,     0,   598,   598,     0,     0,     0,     0,
       0,  1884,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1892,     0,     0,     0,     0,     0,     0,   313,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1931,     0,     0,     0,
       0,     0,   313,     0,     0,  1938,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   598,     0,     0,   598,
     598,     0,     0,     0,     0,   313,     0,     0,     0,     0,
       0,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1217,     0,
       0,     0,     0,     0,     0,  1996,     0,     0,   313,  1805,
       0,     0,     0,   598,     0,     0,     0,   598,     0,  2006,
       0,     0,     0,     0,  1811,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   313,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1887,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1391,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1963,     0,     0,     0,     0,     0,  1965,     0,     0,     0,
       0,     0,  1969,     0,     0,     0,     0,     0,     0,  1973,
       0,     0,  1441,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,     0,     0,
       0,   598,     0,     0,     0,     0,  1993,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   598,     0,     0,   598,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,   292,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,     0,    20,    21,     0,     0,     0,     0,     0,
     313,   313,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,   293,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   598,     0,   598,   598,     0,   598,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,    73,     0,    75,    76,    77,
      78,     0,     0,     0,    81,   598,    83,    84,    85,   295,
     296,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,    96,    97,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       0,     0,     0,     0,     0,     0,   125,     0,     0,     0,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     0,     0,   162,   163,   164,     0,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,     0,     0,   174,   175,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,     0,   193,   194,
       0,   196,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   598,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,   226,
     227,   228,     0,   229,   230,     0,   231,   232,   233,   234,
     235,   236,   237,     0,   239,   240,   241,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,     0,     0,
       0,     0,     0,   598,   531,     0,     0,     0,     0,   598,
       0,     0,     0,     1,     2,     3,   598,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   598,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     0,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,    73,    74,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
      96,    97,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     0,     0,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,     0,
       0,     0,   174,   175,     0,     0,     0,     0,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,     0,     0,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,     0,
       0,     0,   213,     0,   214,   215,   216,     0,     0,     0,
     217,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   219,   220,   221,   222,     0,     0,
       0,     0,     0,   223,   224,     0,   225,   226,   227,   228,
       0,   229,   230,     0,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,     1,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,    31,     0,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,    73,    74,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    96,    97,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
       0,     0,     0,   174,   175,     0,     0,     0,     0,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,     0,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
       0,     0,     0,   213,     0,   214,   215,   216,     0,     0,
       0,   217,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   221,   222,     0,
       0,     0,     0,     0,   223,   224,     0,   225,   226,   227,
     228,     0,   229,   230,     0,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     1,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,   293,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,    73,     0,    75,    76,    77,
      78,     0,     0,     0,    81,     0,    83,    84,    85,   295,
     296,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,    96,    97,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       0,     0,     0,     0,     0,     0,   125,     0,     0,     0,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     0,     0,   162,   163,   164,     0,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,     0,     0,   174,   175,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,     0,   193,   194,
       0,   196,   197,   198,   199,   200,   201,   202,   203,     0,
       0,   204,   205,   206,   207,   208,   209,   210,   211,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,   226,
     227,   228,     0,   229,   230,     0,   231,   232,   233,   234,
     235,   236,   237,     0,   239,   240,   241,   242,     1,     2,
       3,     0,     4,     0,     0,     0,   805,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    17,     0,     0,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,    32,    33,    34,     0,    35,     0,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   337,   293,   339,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,    73,     0,
      75,    76,    77,    78,     0,     0,     0,    81,     0,    83,
      84,    85,   295,   296,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,    96,    97,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     0,     0,     0,     0,     0,     0,   125,
       0,     0,     0,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,     0,   162,   163,
     164,     0,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,     0,     0,   174,   175,     0,
       0,     0,     0,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
       0,   193,   194,     0,   196,   197,   198,   199,   200,   201,
     202,   203,     0,     0,   204,   205,   206,   207,   208,   209,
     210,   211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   226,   227,   228,     0,   229,   230,     0,   231,
     232,   233,   234,   235,   236,   237,     0,   239,   240,   241,
     242,     1,     2,     3,     0,     4,     0,     0,     0,   837,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,     0,     0,   838,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   337,
     293,   339,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,    73,     0,    75,    76,    77,    78,     0,     0,     0,
      81,     0,    83,    84,    85,   295,   296,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,    96,    97,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,   125,     0,     0,     0,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,     0,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
       0,   162,   163,   164,     0,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,     0,     0,     0,
     174,   175,     0,     0,     0,     0,   176,   177,   178,   179,
     180,   839,   182,   183,   840,   185,   186,   187,   188,   189,
     190,     0,   191,     0,   193,   194,     0,   196,   197,   198,
     199,   200,   201,   202,   203,     0,     0,   204,   205,   206,
     207,   208,   209,   210,   211,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   220,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   226,   227,   228,     0,   229,
     230,     0,   231,   232,   233,   234,   235,   236,   237,     0,
     239,   240,   241,   242,     1,     2,     3,     0,     4,     0,
       0,     0,  1216,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,    32,    33,    34,
       0,    35,     0,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   337,   293,   339,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,    73,     0,    75,    76,    77,    78,
       0,     0,     0,    81,     0,    83,    84,    85,   295,   296,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    96,    97,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,     0,
       0,     0,     0,     0,     0,   125,     0,     0,     0,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,     0,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     0,     0,   162,   163,   164,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
       0,     0,     0,   174,   175,     0,     0,     0,     0,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,     0,   193,   194,     0,
     196,   197,   198,   199,   200,   201,   202,   203,     0,     0,
     204,   205,   206,   207,   208,   209,   210,   211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
     228,     0,   229,   230,     0,   231,   232,   233,   234,   235,
     236,   237,     0,   239,   240,   241,   242,     1,     2,     3,
       0,   464,     0,   465,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,     0,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
      32,    33,    34,     0,    35,     0,    37,    38,    39,    40,
      41,    42,    43,    44,    45,     0,   293,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,    73,     0,    75,
      76,    77,    78,     0,     0,     0,    81,     0,    83,    84,
      85,   295,   296,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,    96,    97,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,     0,     0,     0,     0,     0,     0,   125,     0,
       0,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,     0,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     0,     0,   162,   163,   164,
       0,     0,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,     0,     0,   174,   175,     0,     0,
       0,     0,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,     0,
     193,   194,     0,   196,   197,   198,   199,   200,   201,   202,
     203,     0,     0,   204,   205,   206,   207,   208,   209,   210,
     211,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,   220,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,   226,   227,   228,     0,   229,   230,     0,   231,   232,
     233,   234,   235,   236,   237,     0,   239,   240,   241,   242,
       1,     2,     3,     0,     4,   718,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,   293,
     294,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
      73,     0,    75,    76,    77,    78,     0,     0,     0,    81,
       0,    83,    84,    85,   295,   296,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,    96,    97,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,     0,     0,     0,     0,     0,
       0,   125,     0,     0,     0,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,     0,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,     0,
     162,   163,   164,     0,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,     0,     0,     0,   174,
     175,     0,     0,     0,     0,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,     0,   193,   194,     0,   196,   197,   198,   199,
     200,   201,   202,   203,     0,     0,   204,   205,   206,   207,
     208,   209,   210,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,   228,     0,   229,   230,
       0,   231,   232,   233,   234,   235,   236,   237,     0,   239,
     240,   241,   242,     1,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    17,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,    32,    33,    34,     0,
      35,     0,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   337,   293,   339,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,    73,     0,    75,    76,    77,    78,     0,
       0,     0,    81,     0,    83,    84,    85,   295,   296,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
      96,    97,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,     0,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,     0,   162,   163,   164,     0,     0,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,     0,
       0,     0,   174,   175,     0,     0,     0,     0,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,     0,   193,   194,     0,   196,
     197,   198,   199,   200,   201,   202,   203,     0,     0,   204,
     205,   206,   207,   208,   209,   210,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   219,   220,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   226,   227,   228,
       0,   229,   230,     0,   231,   232,   233,   234,   235,   236,
     237,     0,   239,   240,   241,   242,     1,     2,     3,     0,
     311,     0,  1058,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,     0,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,    32,
      33,    34,     0,    35,     0,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,   293,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,    73,     0,    75,    76,
      77,    78,     0,     0,     0,    81,     0,    83,    84,    85,
     295,   296,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,    96,    97,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,     0,     0,     0,     0,     0,     0,   125,     0,     0,
       0,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,     0,     0,   162,   163,   164,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,     0,     0,     0,   174,   175,     0,     0,     0,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,     0,   193,
     194,     0,   196,   197,   198,   199,   200,   201,   202,   203,
       0,     0,   204,   205,   206,   207,   208,   209,   210,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,   220,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
     226,   227,   228,     0,   229,   230,     0,   231,   232,   233,
     234,   235,   236,   237,     0,   239,   240,   241,   242,     1,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,    32,    33,    34,     0,    35,     0,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     0,   293,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,    73,
       0,    75,    76,    77,    78,     0,     0,     0,    81,     0,
      83,    84,    85,   295,   296,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,    96,    97,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,     0,     0,     0,     0,     0,     0,
     125,     0,     0,     0,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,     0,   162,
     163,   164,     0,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,     0,     0,   174,   175,
       0,     0,     0,     0,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   193,   194,     0,   196,   197,   198,   199,   200,
     201,   202,   203,     0,     0,   204,   205,   206,   207,   208,
     209,   210,   211,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,   228,     0,   229,   230,     0,
     231,   232,   233,   234,   235,   236,   237,     0,   239,   240,
     241,   242,     1,     2,     3,     0,   311,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,    32,    33,    34,     0,    35,
       0,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,   293,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,    73,     0,    75,    76,    77,    78,     0,     0,
       0,    81,     0,    83,    84,    85,   295,   296,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,    96,
      97,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,     0,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,     0,   162,   163,   164,     0,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,     0,     0,
       0,   174,   175,     0,     0,     0,     0,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,     0,   193,   194,     0,   196,   197,
     198,   199,   200,   201,   202,   203,     0,     0,   204,   205,
     206,   207,   208,   209,   210,   211,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   225,   226,   227,   228,     0,
     229,   230,     0,   231,   232,   233,   234,   235,   236,   237,
     292,   239,   240,   241,   242,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,     0,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,    32,
      33,    34,     0,    35,     0,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,   293,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,    73,     0,    75,    76,
      77,    78,     0,     0,     0,    81,     0,    83,    84,    85,
     295,   296,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,    96,    97,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,     0,     0,     0,     0,     0,     0,   125,     0,     0,
       0,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,     0,     0,   162,   163,   164,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,     0,     0,     0,   174,   175,     0,     0,     0,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,     0,   193,
     194,     0,   196,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,   220,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
     226,   227,   228,   292,   229,   230,     0,   231,   232,   233,
     234,   235,   236,   237,     0,   239,   240,   241,   242,     0,
       0,     0,     0,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,    32,    33,    34,     0,    35,     0,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     0,   293,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,    73,
       0,    75,    76,    77,    78,     0,     0,     0,    81,     0,
      83,    84,    85,   295,   296,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,    96,    97,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,     0,     0,     0,     0,     0,     0,
     125,     0,     0,     0,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,     0,   162,
     163,   164,     0,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,     0,     0,   174,   175,
       0,     0,     0,     0,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   193,   194,     0,   196,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,   228,     0,   229,   230,     0,
     231,   232,   233,   234,   235,   236,   237,     0,   239,   240,
     241,   242
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        10,    11,   495,   496,    23,     0,   214,    49,  1527,  1528,
    1529,    59,    23,   506,   104,     5,     6,    21,    15,    59,
      83,    69,    19,     2,     3,    36,     4,    46,    68,    69,
      83,    84,    85,    86,    87,    23,    13,    57,    15,    54,
      54,   104,    19,   148,    59,    59,    66,    14,    36,     1,
      20,   104,    19,    20,    69,    69,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,   217,   143,
     144,   145,    14,    28,    54,    30,    59,    57,    20,    13,
      59,    23,    62,    63,    64,    65,    69,    20,    14,    22,
      23,    57,    14,    97,    20,    50,    93,    94,    20,    20,
      13,    23,    23,   252,    13,   102,    19,    20,    98,    99,
      19,   260,    15,    52,    13,    14,    93,    94,    13,    14,
      19,   329,   330,    13,    19,   102,    13,    52,    15,    19,
      20,    13,    14,    13,    14,    13,    13,    19,   346,    19,
      13,    19,    81,    13,    13,    13,    19,    15,    13,    19,
      51,    52,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    14,    19,    14,    14,    14,
      14,    20,   214,    20,    20,    20,    20,    14,    14,    80,
      81,    14,    14,    20,    20,    19,    14,    20,    20,  1708,
      14,  1710,    20,   212,  1713,  1714,    20,   287,   143,   144,
     145,    14,    14,    14,   223,   224,   216,    20,    20,    20,
      14,   314,   315,   316,    13,   318,    20,   118,   173,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    14,    14,    14,    19,    14,    14,    20,
      20,    20,   143,    20,    20,     0,    14,   148,   149,   150,
     151,   152,    20,    14,    14,   295,    14,   252,    14,    20,
      20,    19,   217,   218,    20,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    10,    11,    14,    14,
     181,   182,   183,   294,    20,    20,    13,   329,   330,    14,
      14,    14,   500,    19,    14,    20,    20,    20,    13,   309,
      20,    14,    14,   242,   346,    14,    14,    20,    20,    14,
      14,    20,    20,   100,   101,    20,    20,   242,    14,  1838,
     259,    14,    14,   333,    20,    14,    13,    20,    20,    13,
      13,    20,    15,   311,   259,   554,   555,   347,   348,   240,
     241,   242,   243,   568,   569,   570,   571,   572,   573,   498,
      13,     7,     8,   560,   561,   310,    12,    22,   259,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    13,   327,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   314,   315,   316,    13,   318,
     539,   556,   557,   558,   559,    13,    13,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    13,
      13,    15,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   451,   452,    13,   454,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   465,    13,   467,   500,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   430,    13,   432,   433,    13,
      13,   500,    13,    13,    13,    13,   464,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   990,    13,    13,
     993,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     520,    13,    13,    13,    13,    13,    13,    13,   473,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   547,    13,
      13,    13,   542,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   501,    13,    13,    13,
     545,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   574,     4,    15,    14,   578,   524,
     525,   581,   551,   552,   553,    17,    19,    18,    22,    19,
      96,   329,   240,    68,    16,   143,   735,    68,   309,    22,
      20,    54,   544,    14,    14,    20,   745,    14,    14,    14,
      13,    68,    20,    14,    14,   584,    20,   143,    20,    54,
      16,    14,    14,    20,   566,    16,    14,    16,    13,    54,
      68,    55,    68,    20,    20,    14,    20,    20,    20,    20,
      68,    68,    68,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    14,   321,    20,    20,    20,    20,    13,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    22,    66,   284,    20,    14,    20,    20,    20,    20,
      20,    14,    16,    20,    20,    20,   104,    13,    20,    20,
      20,    20,    20,    20,  1177,    20,    20,    14,    20,    14,
      20,    20,    20,    57,    20,   104,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    57,
    1001,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,   731,    20,    20,    14,    14,    14,    20,    20,    20,
     285,   562,    14,    20,    20,    20,    20,    20,    14,    16,
      20,    14,    14,    14,    14,    14,    14,    22,    22,   252,
      14,    14,    14,    20,    20,    20,    14,    14,    57,    20,
      20,    20,    13,    57,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    14,    14,    20,   732,    20,    20,
      14,    13,    20,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   563,   565,   567,    13,    16,    13,
      13,    20,    13,    20,    16,    20,    13,    13,    13,    -1,
      20,    20,    14,    14,    14,    14,    20,    20,    14,    14,
      14,    67,    14,    20,    14,   780,    57,    20,   259,    20,
     252,    20,    20,    20,    20,    20,    20,    20,    20,   849,
     850,  1334,   837,    20,    20,    20,    20,    20,    20,    14,
    1343,    14,  1345,    20,    20,    14,    20,   867,   868,    20,
     870,   871,   872,   873,   874,    20,   876,   877,    20,   879,
      14,    20,    14,    14,    14,    14,   886,   887,   888,   889,
     890,   891,   892,   893,    20,   895,    20,    20,    20,    20,
      20,    14,    20,    20,   846,    14,    14,    14,    14,   854,
     910,    14,    16,    14,   914,   915,   916,    14,    20,   919,
     920,   921,   922,   923,   924,    20,   926,    20,    20,   929,
     930,   931,   932,   933,   934,   935,   936,   937,   938,    20,
      14,   941,    20,    20,    20,    20,    14,    20,    20,    14,
     950,   951,   952,   953,   954,   955,   956,   957,   958,   959,
     960,    14,    14,    14,   964,   965,    14,   967,   968,    14,
     970,   971,   972,   973,   974,    14,    20,    20,   978,    20,
      14,    14,    14,    14,    20,    14,   986,   987,    57,    14,
      20,    14,    20,    20,    20,    57,    20,   942,   998,    20,
      20,    20,    20,    20,    14,  1005,  1006,    14,  1008,  1009,
      14,    20,  1012,  1013,  1014,    20,  1016,    20,  1018,    20,
    1020,  1021,    20,    14,    20,    20,    20,  1027,    14,  1168,
    1169,  1031,  1032,  1033,    14,    20,  1036,    14,    14,    20,
     985,  1041,  1042,  1043,  1044,  1045,  1046,  1047,    20,    14,
      20,    20,    14,    20,  1054,  1055,    14,    14,  1058,  1059,
    1060,    14,    14,    14,    20,    20,  1051,    14,    57,    -1,
      20,    19,    14,    22,    20,    20,    20,    20,    -1,    20,
      20,    20,    20,  1028,    20,    20,    20,    20,    20,    20,
    1035,  1574,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    20,    20,    14,    20,    14,  1048,    20,    20,   252,
      20,  1053,    20,    20,    20,    20,  1061,    20,    14,    14,
      20,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    14,    14,    22,    20,    20,    20,    14,    14,    20,
      20,    20,    20,    54,   252,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    20,  1166,    20,    14,   252,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,   252,   577,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    14,    14,
      14,    14,    20,    20,    58,    14,    14,  1346,    20,    20,
      20,    14,    14,    14,    20,    20,    20,    14,    -1,    -1,
      20,    20,  1167,    -1,    20,    20,    20,  1227,    20,    20,
      14,    14,    20,    20,    14,    14,    14,    14,    14,  1239,
      14,    14,    14,    14,  1244,    14,    14,    14,  1248,  1249,
    1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,    20,    20,  1266,    20,    14,  1237,
      14,    20,    14,    14,  1274,    14,    14,    20,    14,    14,
    1280,  1281,  1282,  1283,  1226,  1285,  1286,  1287,    14,  1289,
    1290,    14,    20,    20,    14,    20,  1296,  1297,  1298,  1299,
      14,    14,    20,    20,    20,  1305,    14,    22,  1308,  1309,
      20,    20,    14,    20,    20,    14,    20,    20,  1318,  1319,
    1320,  1321,    20,    20,    20,    20,    20,    14,  1467,    20,
    1469,  1331,  1332,  1333,    14,  1474,    14,    14,  1338,    20,
      14,    20,    14,    14,    20,    20,    14,    20,  1348,  1349,
      20,  1351,  1352,    20,  1354,  1355,  1356,    20,    20,    20,
    1360,  1361,    20,    20,  1364,    20,    20,  1367,    20,  1369,
    1370,  1371,    14,    14,    14,    20,  1376,    14,    -1,  1379,
      14,  1381,    20,    14,    20,  1385,  1386,  1387,    20,  1389,
      20,    20,    20,  1393,    20,    20,    20,    14,    20,    14,
      14,    14,    20,  1403,    14,   564,    -1,    14,    20,    20,
      14,    20,    20,    14,    20,    14,    -1,    20,    20,    -1,
      20,    14,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,  1390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1466,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1505,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1513,  1514,    -1,  1516,  1517,  1518,    -1,
    1520,  1521,  1522,  1523,  1524,  1525,    -1,  1527,  1528,  1668,
    1530,  1531,  1532,  1533,    -1,  1535,  1536,  1537,  1538,  1539,
      -1,  1541,    -1,  1511,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1551,  1552,  1553,  1554,  1555,  1556,  1557,  1503,  1504,
    1560,    -1,    -1,  1563,  1564,    -1,  1566,  1567,  1568,    -1,
      -1,    -1,  1572,  1573,    -1,    -1,  1576,    -1,    -1,    -1,
      -1,    -1,    -1,  1583,  1584,    -1,  1586,  1529,    -1,    -1,
    1590,  1591,    -1,  1593,  1594,    -1,  1596,    -1,  1598,  1599,
      -1,  1601,    -1,  1603,  1604,  1605,    -1,  1607,  1608,  1609,
    1610,    -1,  1612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1611,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
      -1,    -1,    -1,  1693,    -1,    -1,    -1,  1697,  1698,  1699,
    1700,    -1,  1702,  1703,  1704,  1705,  1706,  1707,    22,    -1,
      -1,    25,    -1,    -1,    -1,  1715,  1716,  1717,    -1,    -1,
      -1,    -1,    -1,  1723,  1724,    -1,    -1,  1727,  1696,  1729,
    1730,    -1,    -1,  1733,  1734,    49,  1736,  1737,    -1,    -1,
      -1,    -1,    -1,  1743,    -1,    -1,    -1,    -1,    -1,    -1,
    1750,  1751,  1752,    -1,    -1,  1755,  1756,  1757,  1758,    -1,
    1760,    -1,    -1,  1763,  1764,    -1,  1708,    -1,  1710,    -1,
      -1,  1713,  1714,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1824,    -1,  1826,    -1,  1828,  1771,
    1830,    -1,    -1,  1833,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1843,  1844,    -1,  1846,    -1,    -1,  1849,
    1850,  1851,  1852,  1853,    -1,    -1,    -1,  1857,    -1,  1859,
      -1,    -1,  1862,  1863,  1864,  1865,    -1,  1867,  1868,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1895,  1838,    -1,    -1,  1899,
     214,  1901,  1902,    -1,  1904,  1905,  1906,    -1,  1908,  1909,
      -1,  1911,  1912,  1913,    -1,  1915,    -1,  1917,  1918,    -1,
    1920,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,  1944,    -1,    -1,    -1,  1948,  1949,
    1950,    -1,    -1,  1953,  1954,    -1,    -1,  1957,    -1,    -1,
    1960,  1961,  1962,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1977,    -1,    -1,
    1980,    -1,    -1,    -1,  1984,    -1,    -1,  1987,  1988,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1999,
      -1,    -1,  2002,    -1,    -1,    -1,    -1,  2007,  2008,  2009,
      -1,    -1,    -1,  2013,  2014,   329,   330,    -1,  2018,  2019,
      -1,    -1,  2022,  2023,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   359,    -1,    -1,   362,   363,
     364,   365,   366,    -1,   368,   369,   370,   371,   372,    -1,
      -1,   375,    -1,    -1,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,    -1,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
      -1,    -1,    -1,    -1,    -1,    -1,   410,   411,   412,   413,
     414,   415,   416,   417,   418,    -1,    -1,   421,   422,   423,
     424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     434,   435,   436,    -1,    -1,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,    -1,    -1,    -1,   453,
     454,    -1,   456,    -1,   458,    -1,    -1,    -1,   462,   463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   477,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   500,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   509,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   527,   528,   529,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   352,   353,   354,   355,   356,   357,   358,    -1,
     360,   361,    -1,    -1,    -1,    -1,    -1,   367,    -1,    -1,
      -1,    -1,    -1,   373,   374,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   403,   404,   405,   406,   407,   408,   409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   426,   427,   428,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     450,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,
      -1,   461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,   475,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   502,    -1,    -1,    -1,    -1,   507,   508,    -1,
     510,   511,    -1,   513,   514,   515,   516,   517,   518,   519,
      -1,   521,   522,   523,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   576,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   846,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   866,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   875,    -1,    -1,    -1,    -1,    -1,    -1,   882,   883,
     884,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     894,    -1,    -1,    -1,    -1,   899,    -1,   901,   902,   903,
     904,   905,    -1,   907,   908,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,
      -1,     4,    -1,    -1,    -1,   939,    -1,    -1,    -1,    -1,
      -1,   945,   946,   947,   948,   949,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1007,    -1,    -1,  1010,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1029,  1030,    -1,    -1,    -1,
      -1,    -1,    -1,  1037,    -1,  1039,  1040,  1041,  1042,    -1,
      -1,    -1,    -1,    -1,  1048,    -1,    -1,    -1,    -1,  1053,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1071,  1072,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     880,   881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   912,    -1,    -1,    -1,    -1,   917,   918,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   292,
      -1,    -1,  1226,  1227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1237,  1238,    -1,    -1,   310,   311,    -1,
      -1,    -1,    -1,  1247,    -1,    -1,    -1,  1251,    -1,    -1,
      -1,    -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1267,  1268,  1269,  1270,  1271,    -1,  1019,
      -1,    -1,  1022,  1023,    -1,    -1,    -1,    -1,   351,   352,
     353,   354,   355,   356,   357,   358,    -1,   360,   361,    -1,
      -1,    -1,    -1,    -1,   367,    -1,    -1,    -1,    -1,    -1,
     373,   374,  1306,  1307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   388,  1066,    -1,    -1,  1323,
    1070,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     403,   404,   405,   406,   407,   408,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   426,   427,   428,    -1,   430,    -1,   432,
     433,  1111,  1366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,
      -1,    -1,   455,    -1,    -1,    -1,  1390,    -1,   461,    -1,
      -1,   464,    -1,    -1,    -1,   468,   469,   470,   471,   472,
     473,   474,   475,   476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,   502,
      -1,    -1,    -1,    -1,   507,   508,    -1,   510,   511,    -1,
     513,   514,   515,   516,   517,   518,   519,    -1,   521,   522,
     523,   524,   525,   526,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,
      -1,    -1,   545,   546,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   576,   577,    -1,    -1,  1511,   581,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1540,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1300,    -1,    -1,    -1,  1304,    -1,    -1,  1561,  1562,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1329,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1611,    -1,  1359,
      -1,    -1,  1362,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   732,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1696,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   780,    -1,    -1,
      -1,    -1,    -1,    -1,  1718,  1719,  1720,  1721,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   805,    -1,    -1,    -1,  1740,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1759,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   837,   838,    -1,  1771,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   854,    -1,    -1,    -1,    -1,   859,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1545,    -1,  1547,  1548,    -1,
    1550,    -1,    -1,    -1,    -1,    -1,    -1,   880,   881,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1588,   912,
      -1,    -1,    -1,    -1,   917,   918,    -1,    -1,    -1,    -1,
      -1,  1855,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1866,    -1,    -1,    -1,    -1,    -1,    -1,   942,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1910,    -1,    -1,    -1,
      -1,    -1,   985,    -1,    -1,  1919,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1019,    -1,    -1,  1022,
    1023,    -1,    -1,    -1,    -1,  1028,    -1,    -1,    -1,    -1,
      -1,    -1,  1035,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1051,    -1,
      -1,    -1,    -1,    -1,    -1,  1989,    -1,    -1,  1061,  1739,
      -1,    -1,    -1,  1066,    -1,    -1,    -1,  1070,    -1,  2003,
      -1,    -1,    -1,    -1,  1754,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1861,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1940,    -1,    -1,    -1,    -1,    -1,  1946,    -1,    -1,    -1,
      -1,    -1,  1952,    -1,    -1,    -1,    -1,    -1,    -1,  1959,
      -1,    -1,  1285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1300,    -1,    -1,
      -1,  1304,    -1,    -1,    -1,    -1,  1986,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1329,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1359,    -1,    -1,  1362,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
    1503,  1504,    -1,    -1,    48,    -1,    -1,    -1,    52,    53,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1545,    -1,  1547,  1548,    -1,  1550,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,   128,  1588,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    -1,    -1,
      -1,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,   219,   220,   221,    -1,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,    -1,   262,   263,
      -1,   265,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1739,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1754,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,   311,   312,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
     324,   325,    -1,   327,   328,    -1,   330,   331,   332,   333,
     334,   335,   336,    -1,   338,   339,   340,   341,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1861,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1940,    -1,    -1,
      -1,    -1,    -1,  1946,     0,    -1,    -1,    -1,    -1,  1952,
      -1,    -1,    -1,     9,    10,    11,  1959,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,  1986,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    -1,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    -1,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,   119,   120,   121,   122,   123,   124,    -1,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,    -1,   238,   239,    -1,    -1,    -1,    -1,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,    -1,    -1,   275,
     276,   277,   278,   279,   280,   281,   282,   283,    -1,    -1,
      -1,    -1,   288,    -1,   290,   291,   292,    -1,    -1,    -1,
     296,   297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,   313,    -1,    -1,
      -1,    -1,    -1,   319,   320,    -1,   322,   323,   324,   325,
      -1,   327,   328,    -1,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    -1,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,   122,   123,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,    -1,   238,   239,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    -1,    -1,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    -1,
      -1,    -1,    -1,   288,    -1,   290,   291,   292,    -1,    -1,
      -1,   296,   297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   310,   311,   312,   313,    -1,
      -1,    -1,    -1,    -1,   319,   320,    -1,   322,   323,   324,
     325,    -1,   327,   328,    -1,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,    53,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    -1,    -1,
      -1,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,   219,   220,   221,    -1,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,    -1,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,    -1,
      -1,   275,   276,   277,   278,   279,   280,   281,   282,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,   311,   312,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
     324,   325,    -1,   327,   328,    -1,   330,   331,   332,   333,
     334,   335,   336,    -1,   338,   339,   340,   341,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    52,    53,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,    -1,
     121,   122,   123,   124,    -1,    -1,    -1,   128,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,   219,   220,
     221,    -1,    -1,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,
      -1,    -1,    -1,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,   260,
      -1,   262,   263,    -1,   265,   266,   267,   268,   269,   270,
     271,   272,    -1,    -1,   275,   276,   277,   278,   279,   280,
     281,   282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   322,   323,   324,   325,    -1,   327,   328,    -1,   330,
     331,   332,   333,   334,   335,   336,    -1,   338,   339,   340,
     341,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    52,    53,    54,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,   119,    -1,   121,   122,   123,   124,    -1,    -1,    -1,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,   147,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    -1,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,    -1,    -1,    -1,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,   219,   220,   221,    -1,    -1,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,    -1,
     238,   239,    -1,    -1,    -1,    -1,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,    -1,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,    -1,    -1,   275,   276,   277,
     278,   279,   280,   281,   282,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   310,   311,   312,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,   324,   325,    -1,   327,
     328,    -1,   330,   331,   332,   333,   334,   335,   336,    -1,
     338,   339,   340,   341,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    52,    53,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,    -1,   121,   122,   123,   124,
      -1,    -1,    -1,   128,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    -1,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,   219,   220,   221,    -1,    -1,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,    -1,   238,   239,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,   260,    -1,   262,   263,    -1,
     265,   266,   267,   268,   269,   270,   271,   272,    -1,    -1,
     275,   276,   277,   278,   279,   280,   281,   282,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   310,   311,   312,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,   324,
     325,    -1,   327,   328,    -1,   330,   331,   332,   333,   334,
     335,   336,    -1,   338,   339,   340,   341,     9,    10,    11,
      -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      52,    53,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,    -1,    -1,    -1,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,   219,   220,   221,
      -1,    -1,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,    -1,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,    -1,    -1,   275,   276,   277,   278,   279,   280,   281,
     282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,   311,
     312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,   324,   325,    -1,   327,   328,    -1,   330,   331,
     332,   333,   334,   335,   336,    -1,   338,   339,   340,   341,
       9,    10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,    -1,   121,   122,   123,   124,    -1,    -1,    -1,   128,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,    -1,    -1,    -1,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
     219,   220,   221,    -1,    -1,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,    -1,   238,
     239,    -1,    -1,    -1,    -1,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,   260,    -1,   262,   263,    -1,   265,   266,   267,   268,
     269,   270,   271,   272,    -1,    -1,   275,   276,   277,   278,
     279,   280,   281,   282,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,   312,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,   323,   324,   325,    -1,   327,   328,
      -1,   330,   331,   332,   333,   334,   335,   336,    -1,   338,
     339,   340,   341,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    52,    53,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,   119,    -1,   121,   122,   123,   124,    -1,
      -1,    -1,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,    -1,    -1,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,   219,   220,   221,    -1,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,    -1,   238,   239,    -1,    -1,    -1,    -1,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,    -1,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,    -1,    -1,   275,
     276,   277,   278,   279,   280,   281,   282,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,   323,   324,   325,
      -1,   327,   328,    -1,   330,   331,   332,   333,   334,   335,
     336,    -1,   338,   339,   340,   341,     9,    10,    11,    -1,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,
      53,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,    -1,    -1,    -1,   128,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,   219,   220,   221,    -1,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,
      -1,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,    -1,   262,
     263,    -1,   265,   266,   267,   268,   269,   270,   271,   272,
      -1,    -1,   275,   276,   277,   278,   279,   280,   281,   282,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,   311,   312,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,   324,   325,    -1,   327,   328,    -1,   330,   331,   332,
     333,   334,   335,   336,    -1,   338,   339,   340,   341,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    52,    53,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
      -1,   121,   122,   123,   124,    -1,    -1,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
     180,    -1,    -1,    -1,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,   219,
     220,   221,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,    -1,   238,   239,
      -1,    -1,    -1,    -1,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,    -1,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,    -1,    -1,   275,   276,   277,   278,   279,
     280,   281,   282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     310,   311,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,   324,   325,    -1,   327,   328,    -1,
     330,   331,   332,   333,   334,   335,   336,    -1,   338,   339,
     340,   341,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    52,    53,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,    -1,   121,   122,   123,   124,    -1,    -1,
      -1,   128,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,    -1,    -1,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,   219,   220,   221,    -1,    -1,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
      -1,   238,   239,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,   260,    -1,   262,   263,    -1,   265,   266,
     267,   268,   269,   270,   271,   272,    -1,    -1,   275,   276,
     277,   278,   279,   280,   281,   282,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   310,   311,   312,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,   323,   324,   325,    -1,
     327,   328,    -1,   330,   331,   332,   333,   334,   335,   336,
      13,   338,   339,   340,   341,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,
      53,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,    -1,    -1,    -1,   128,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,   219,   220,   221,    -1,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,
      -1,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,    -1,   262,
     263,    -1,   265,   266,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,   311,   312,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,   324,   325,    13,   327,   328,    -1,   330,   331,   332,
     333,   334,   335,   336,    -1,   338,   339,   340,   341,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    52,    53,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
      -1,   121,   122,   123,   124,    -1,    -1,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
     180,    -1,    -1,    -1,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,   219,
     220,   221,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,    -1,   238,   239,
      -1,    -1,    -1,    -1,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,    -1,   262,   263,    -1,   265,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     310,   311,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,   324,   325,    -1,   327,   328,    -1,
     330,   331,   332,   333,   334,   335,   336,    -1,   338,   339,
     340,   341
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     9,    10,    11,    13,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    40,    41,    42,    43,    44,    45,    46,    48,
      49,    50,    52,    53,    54,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    74,    75,    76,    77,    78,    79,    93,    94,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   119,   120,   121,   122,   123,   124,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   146,   147,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   238,   239,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   288,   290,   291,   292,   296,   297,   310,
     311,   312,   313,   319,   320,   322,   323,   324,   325,   327,
     328,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   354,   355,   356,   357,   358,   359,   362,   363,   364,
     365,   369,   373,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   407,    13,    68,    69,   133,   134,   378,   382,   378,
     384,   384,   377,   398,    20,   374,   398,   374,   374,    13,
      13,    13,   376,   398,    68,   295,   378,    54,    62,    63,
      64,    65,   401,   378,   398,   398,   376,    13,   376,    13,
      13,   401,   148,    15,    58,    60,    61,    67,    68,    69,
     378,   402,   404,   405,   406,   376,    13,    13,    13,   383,
     384,    13,    13,    15,    13,    13,    15,    13,    15,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    15,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    15,   376,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   401,   370,   371,   406,   374,   356,   376,   376,
      13,    13,    13,    13,    66,   401,   401,    13,    13,    13,
      13,    13,    19,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
       0,     0,   356,   357,   358,   359,   362,   363,   364,   365,
     356,    19,    13,    19,    22,    13,    15,    19,    93,    94,
     102,     7,     8,    12,    10,    11,     5,     6,    98,    99,
     100,   101,    17,    18,    96,     4,    21,    97,    83,    84,
      85,    86,    87,   104,    13,    19,    83,   104,    15,    19,
      19,    13,    19,    19,    14,    14,    22,   374,   376,   377,
     376,   406,   406,   374,   406,   374,   374,   375,   398,   375,
     398,   375,   375,   375,   375,   375,   375,   378,   375,   375,
     378,   378,   378,   378,   378,   375,   378,   378,   378,   378,
     378,   375,   375,   378,   143,   144,   145,   143,   144,   145,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     375,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   375,   378,   375,   375,   375,
     375,   375,   375,   378,   378,   378,   378,   378,   378,   378,
     378,   378,    68,    68,   378,   378,   378,   378,    68,   375,
     375,   375,    68,   376,    68,   376,   376,   378,   378,   378,
      54,    54,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   375,   374,   374,   378,   374,   378,   375,
     378,    68,   378,    68,    68,   375,   378,   378,    14,   374,
     374,   398,   398,   398,   398,   398,   376,   375,   375,   375,
     378,   104,   287,    55,   370,   370,   356,   401,   406,   376,
     375,    54,   361,   360,    22,   370,   375,   375,   378,   375,
     375,   329,   375,   375,   375,   375,   375,   375,   375,   374,
     375,   375,   375,   376,   376,   398,   378,   378,   378,   356,
     309,   374,   398,    51,    52,    80,    81,   118,   143,   148,
     149,   150,   151,   152,   181,   182,   183,   240,   241,   242,
     243,   259,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   382,    17,   367,   398,   404,   398,
     401,   384,   384,   384,   385,   385,   387,   387,   387,   387,
     388,   388,   389,   391,   392,   393,   382,   394,   397,   397,
     397,   397,   397,   397,   374,   240,   375,    17,    37,   249,
     252,   398,   403,   374,   374,   384,    20,    14,    14,    20,
      20,    14,    14,    16,    20,    14,    20,    14,    14,    20,
      16,    14,    14,    16,    14,    16,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    13,    13,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    20,    20,    20,    14,    20,    20,    14,
      20,    14,    20,    16,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    14,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    20,    20,    20,    14,    14,    16,    20,    14,
      14,    14,    14,    14,    14,    20,    20,    20,    14,   374,
     366,   376,   372,   294,   356,    14,    14,    14,    20,    14,
      13,    13,   321,   356,    14,    20,    20,    20,    20,    20,
      13,    14,    20,    20,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    20,    20,
      20,    20,    22,    23,    14,    13,    13,    13,   376,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    20,   398,
      14,    20,    16,    22,    20,    13,   398,   404,    15,    13,
      13,    20,    16,   382,   374,   374,   104,   376,    66,   398,
      13,    13,    13,    54,   378,   374,   374,   374,   374,   374,
     374,   374,   378,   374,   374,   374,   375,   375,   378,   378,
     378,   374,   374,   374,   374,   374,   374,   374,   374,   378,
     374,   378,   378,   378,   378,   378,   378,   378,   378,   374,
     375,    13,   374,   374,   374,   375,   375,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   378,   374,   376,   378,   378,   378,
     378,   378,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   376,   374,   374,   284,    20,   370,   370,
     374,   314,   315,   316,   318,   368,   368,    67,   374,   374,
     378,   374,   374,   378,   374,   374,   374,   374,   374,   375,
     374,   374,   375,   375,   374,   376,   378,   378,   374,   374,
     374,   376,   374,   378,   378,   378,   374,   378,   374,   378,
     374,   374,   374,   374,   374,   382,    17,   398,   404,   382,
     374,   374,   374,   374,   374,   376,    22,    20,    14,   375,
      14,    14,    14,   375,   378,   378,    14,    20,    20,    20,
      14,    14,    14,    14,    20,    14,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    14,   375,    14,    14,    14,
      20,    20,    20,    20,    14,    20,    20,    20,    14,    20,
      20,    14,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    20,    20,    20,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    14,    20,    14,    14,    14,    14,    14,    20,
      14,    20,    20,    20,   374,   376,   356,   356,    20,    57,
      57,    57,    57,    14,    20,    14,   370,    14,    20,    20,
      14,    20,    20,    14,    20,    20,    20,    14,    14,    20,
      20,    20,    20,    14,    20,    14,    20,    20,    14,    20,
      23,    20,    14,    14,    20,    14,    20,    14,    14,    20,
      14,    20,    14,    14,    14,    20,    20,    20,    14,    20,
      22,   398,    14,    20,    16,    14,    14,   382,   374,   378,
      14,    14,    14,    20,   377,   378,    54,   378,   374,   374,
     378,   374,   374,   374,   374,   378,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   378,
     378,   378,   378,   378,   374,    14,   374,   374,   374,   374,
     374,   398,   374,   374,   374,   374,   374,   374,   374,   374,
     375,   375,   374,   378,   378,   374,   374,   374,   374,   374,
     374,   378,   375,   374,   374,   374,   285,   370,   374,   370,
     314,   315,   316,   318,   370,   356,   374,   374,   374,   374,
     374,   374,   374,   375,   374,   374,   375,   374,   378,   374,
     374,   374,   374,   398,   374,   374,   374,   374,   374,   374,
     374,   382,   374,    20,    20,    20,    14,   374,    14,    19,
      14,    20,    20,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    20,    14,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    14,
      14,    14,    20,    20,   374,   356,    20,   356,    57,    57,
      57,    57,   356,    20,    20,    14,    20,    14,    20,    14,
      20,    20,    14,    20,    20,    20,    20,    14,    20,    23,
      14,    22,    14,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,   376,   376,   374,    14,   377,    54,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   407,   374,   407,   382,   407,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   378,   374,   375,   375,   375,
     375,   374,   374,   374,   374,   374,   374,   374,   374,   378,
     378,   374,   374,   374,   374,   374,   374,   374,   370,   374,
     374,   374,   374,   375,   374,   374,   374,   374,   378,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     382,   374,    14,    20,    14,    14,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    14,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    14,    14,    20,    14,    20,
      20,    14,    14,    20,    20,    14,    20,    20,    14,    20,
      20,    14,    14,    20,    14,    14,    14,    14,    14,   356,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    14,    14,    14,    14,    14,
      14,    22,    14,   374,   377,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   407,   407,   407,   407,   374,
     374,   374,   378,   378,   378,   378,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   375,   378,   374,   374,   374,
     374,   375,   374,   374,   374,   374,   378,   374,   374,   374,
     382,    14,    14,    14,    20,    14,    20,    14,    20,    14,
      20,    14,    14,    20,    14,    14,    14,    14,    20,    14,
      14,    14,    14,    20,    20,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    22,    14,
     374,   374,   374,   374,   374,   407,   374,   374,   374,   374,
     374,   374,   374,   374,   378,   374,   374,   375,   374,   374,
     374,   374,   378,   374,   374,    20,    14,    14,    14,    20,
      14,    20,    20,    14,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    20,    14,    20,    20,    20,
      20,    14,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   378,   374,   374,   374,   374,   374,   374,   378,   374,
     104,    14,    14,    14,    20,    14,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    14,    14,    20,    14,    20,
      20,    20,    20,   375,   374,   375,   374,   374,   374,   375,
     374,   374,   374,   375,   374,   374,   374,    20,    14,    14,
      20,    14,    14,    14,    20,    14,    20,    20,    20,    20,
     374,   374,   374,   375,   374,   374,   378,    14,    14,    20,
      14,    14,    20,    20,   374,   374,   378,    20,    20,    20,
     374,   374,   374,    20,    20,    14,   374,   374,    20,    20,
     374,   374,    20,    20,   374,   374,    14,    14
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
     605,   606,   607
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   353,   354,   354,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     356,   356,   357,   357,   357,   357,   357,   358,   358,   360,
     359,   361,   359,   362,   362,   363,   364,   364,   364,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   366,   366,   367,   367,   367,   367,
     367,   367,   367,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   369,   369,   369,   369,   369,   369,   369,   370,
     371,   372,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   374,
     375,   376,   377,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   377,   377,   378,   378,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     380,   381,   381,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   385,   385,   385,   385,   386,   386,   386,
     387,   388,   388,   388,   388,   388,   389,   389,   389,   390,
     390,   391,   392,   392,   393,   393,   394,   394,   395,   395,
     396,   396,   397,   397,   397,   397,   397,   397,   397,   398,
     399,   399,   399,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   401,   402,   402,
     402,   402,   402,   403,   403,   404,   405,   405,   405,   405,
     405,   406,   406,   406,   407,   407,   407,   407
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
       4,     3,     5,     3,     6,     3,     6,     6,     8,     6,
       8,     1,     1,     2,     2,     1,     1,     2,     4,     4,
       1,     2,     2,     2,     8,    16,     2,     6,     2,     2,
       2,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     2,     6,    10,     6,    10,     8,
      10,    12,     6,     6,     3,     3,     3,     3,     4,     3,
       6,     6,     4,    20,     8,    10,     8,    10,    12,     6,
       8,    10,    16,    18,    12,     6,    18,    16,    12,    10,
      10,    10,     6,    10,     6,     6,     6,     8,     4,     4,
       8,     4,    18,     4,     1,     1,     1,     6,     1,     1,
       1,    30,    24,     8,     1,     3,     0,     1,     3,     2,
       4,     1,     3,     0,     2,     2,     2,     2,     4,     4,
       4,     4,     1,     6,     1,     3,     4,     4,     1,     3,
       0,     0,     1,     1,     1,     1,     6,     8,    10,    10,
      10,     8,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     4,    10,     4,    10,
       4,     4,     4,     4,     4,     4,     7,     7,     7,     9,
       7,     6,     4,     6,    10,     4,     4,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     1,     2,     4,     4,
       1,    10,    12,     8,     6,     6,     6,     8,     8,     6,
       8,     8,    10,    10,    12,    12,    10,     4,    10,     4,
       6,     4,     4,     4,    12,     4,    12,    12,    16,    20,
      10,    12,     4,     6,     6,     6,     4,     4,     6,     4,
       6,     6,     6,    16,    12,    14,    12,    12,    16,     4,
       8,    10,    12,    10,    12,    10,    12,    12,    14,    12,
       8,    14,     4,     4,     4,     4,     6,     6,     6,     6,
       8,    14,    12,    14,    12,     6,     8,    10,    10,    12,
       6,     6,     6,     6,     6,     6,     6,     6,     8,    10,
       4,     4,    10,    10,     4,     6,     6,    12,    30,     8,
       6,     4,     6,     4,     6,     4,     4,    18,     8,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     3,     1,     1,     3,     4,     2,     2,
       2,     2,     4,     1,     4,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     3,     3,     3,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     3,     3,     3,     3,     3,     1,
       6,     1,     4,     6,     6,     8,     8,     4,     6,     6,
       6,     6,     3,     2,     4,     6,     4,     4,    10,     6,
      16,    18,    10,    20,    14,     4,     6,     8,     8,    12,
      16,    16,    18,    14,    14,    16,    20,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,    11,     7,     7,     3
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
  "T_ReadRawImages", "SHOW", "HELP", "QUIT", "T_HIDE", "PRINT", "PRINTN",
  "T_InfoDialog", "T_boost_format", "T_SPRINT", "ASHELL", "LS",
  "T_SetName", "T_GetName", "T_GetObjectName", "ASTRING", "ABLOCK",
  "NUMBER", "IDENTIFIER", "PROCESSED_VAR", "VAR_IMAGE", "VAR_STRING",
  "VAR_MATRIX", "VAR_C_FUNCTION", "VAR_C_PROCEDURE", "VAR_CLASS_MEMBER",
  "VAR_C_IMAGE_FUNCTION", "VAR_AMI_FUNCTION", "VAR_AMI_CLASS",
  "VAR_AMI_OBJECT", "VAR_ARRAY_IMAGE", "T_del", "T_delvars", "T_Comments",
  "ENDOP", "T_global", "T_local", "T_global_new", "T_local_new", "T_wait",
  "T_schedule", "T_SetComponent", "T_GetExtent", "RIGHT_ASSIGN",
  "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP",
  "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "TRANSPOSE_OP", "POINTWISE_MULT", "ASSIGN_OP",
  "T_COUNT", "T_MAX", "T_argmax", "T_MIN", "T_MEDIAN", "OpImage", "FILTER",
  "NormGrad", "T_DiscNormGrad", "T_gradient", "SecDerGrad", "SecDerGrad2",
  "SubImage", "PutImage", "T_AutoCrop", "T_DiscSecDerGrad",
  "AnisoSmoothGS", "T_vtkAnisoGS", "T_DiscMeanCurvature", "T_vtkMedian3D",
  "T_NULL", "T_RestartTime", "T_InitTime", "T_TimeSpent", "T_EndTime",
  "T_vtkFastMarching", "T_vtkFastMarchingTarget", "T_FluxDiffusion",
  "T_AnisoWeickert", "T_AnisoCW", "T_SRAD_qcoeff", "T_AnisoSRAD",
  "T_AnisoSRAD2", "T_AnisoLeeAdd2", "T_AnisoDPAD", "T_AnisoDPAD2",
  "T_AnisoNRAD", "T_AnisoRudinMult", "TInit", "TIterate", "TEnd",
  "TAddGaussNoise", "T_SNR", "T_info", "T_save", "T_normalize",
  "T_OrientField", "T_OrientPositive", "T_2DFlux", "T_OutFlux",
  "T_OutFluxScalar", "T_OrientationRatio", "T_Skeleton", "T_SimplePoints",
  "T_CircleIntegral", "T_CircleIntegralExc", "T_CircleIntSdExc",
  "T_CircleMinIntSdExc", "T_LocalExtrema", "T_NormalField",
  "T_DirConnectivity", "T_eccentricity", "T_rot2D", "T_mean", "T_SUM",
  "T_localmean", "T_localmean2", "T_localSD", "T_localSD2",
  "T_struct_tensor", "T_StructTensorH", "T_HessianMatrix", "T_HessianEVal",
  "T_Derivatives", "T_curvatures", "T_Laplacian", "T_setvoxelsize",
  "T_settranslation", "T_setendianness", "T_Skeleton2lines",
  "T_SmoothLines", "T_ResampleLines", "T_threscross", "T_IsocontourPoints",
  "T_IsosurfDist", "T_vtkIsoContourDist", "T_ShortestPath",
  "T_ShortestPathImage", "T_PathFromDispl", "T_PathFromVectField",
  "T_LineRecons", "T_ReadCTALine", "T_ReadCTALineRadii", "T_vtkDicomRead",
  "T_vtkMINCRead", "T_Convolve", "T_ConvolveMask", "T_Pad", "T_Eigen2D",
  "T_Eigen3D", "T_ChamferDT", "T_Chamfer2DT", "T_BorgeforsDT",
  "T_BorgeforsSDT", "T_vtkSignedBorgefors", "T_vtkSignedFMDist",
  "T_PropagationDist", "T_PropagationDist2", "T_PropDanielsson",
  "T_vtkPropDanielsson", "T_vtkPropDaniel2", "T_CC", "T_ProcessXEvents",
  "T_ProcessEvents", "T_isoarea2D", "T_posarea", "T_isosurf",
  "T_isosurf_inv", "T_isosurf_ijk", "T_isosurf_ras", "T_vtkDecimate",
  "T_vtkMarchingCubes", "T_vtkSmooth", "T_vtkWindowedSinc", "T_isoline",
  "T_vtkDist", "T_AndreDist", "T_Surface", "T_computeCC", "T_writeVRML",
  "T_writeVTK", "T_SetLight", "T_SetLightPos", "T_Matrix", "T_Invert",
  "SET", "SETPOS", "T_lininterp", "T_initvalue", "T_Xpos", "T_Ypos",
  "T_Zpos", "T_SpacePos", "T_CHAR", "T_UCHAR", "T_SHORT", "T_USHORT",
  "T_INT", "T_UINT", "T_LONG", "T_FLOAT", "T_DOUBLE", "T_RGB",
  "T_FLOAT_VECTOR", "T_GetFormat", "T_atof", "T_gnuplot", "T_histo",
  "T_cumhisto", "T_DisplayHisto", "T_LineNumber", "CONST_PI", "SIN", "COS",
  "TAN", "ASIN", "ACOS", "ATAN", "SINH", "COSH", "EXP", "LN", "LOG",
  "SQRT", "ABS", "ROUND", "FLOOR", "NORM", "FOR", "TO", "STEP", "ENDFOR",
  "T_IN", "T_REPEAT", "T_UNTIL", "T_WHILE", "T_BREAK", "IF", "THEN",
  "ELSE", "VARIABLES", "FUNCTION", "T_eval", "T_tx", "T_ty", "T_tz",
  "T_trx", "T_try", "T_trz", "T_vx", "T_vy", "T_vz", "T_vdim", "T_inc",
  "T_val", "T_exists", "T_FileExists", "T_slice", "T_GenRead", "T_IMAGE",
  "T_NUM", "T_STRING", "T_TRANSFORM", "T_OBJECT", "T_PROC", "T_Class",
  "T_public", "T_MeanHalfSize", "T_Resize", "T_ReSlice", "T_Flip",
  "T_SetCompTransf", "T_ConvexHull", "T_itk", "T_CannyEdgeDetector",
  "T_CreateFlatMesh", "T_CreateVolume", "T_vtkCreateFlatMesh",
  "T_Altitude2Position", "T_GeoCoordinates", "T_CreateVectors",
  "T_CreateVectorsFromField", "T_Set3DArrowParam", "T_CreateEllipsoids",
  "T_ComputeAltitudes", "T_Temp2Altitudes", "T_ReadFlow",
  "T_SetFluidNavFile", "T_DrawEarthCoord", "T_SaveStructuredGrid",
  "T_import_vtk", "T_import_wii", "T_import_filters", "T_amiOFCorr2D",
  "T_amiOFVar2D", "SHIFT_THERE", "prefix", "postfix", "$accept", "start",
  "list_commands", "end_instr", "loop_inst", "cond_inst", "proc_decl",
  "@1", "@2", "class_decl", "object_decl", "func_inst", "command",
  "exprstringlist", "param_list", "param_list_decl", "primary_expr_string",
  "instr_block", "begin_block", "end_block", "float_variable", "expr",
  "expr_image", "expr_string", "basic_type", "var_image", "image",
  "image_variable", "string_variable", "primary_var", "postfix_var",
  "prefix_var", "multiplicative_var", "additive_var", "shift_var",
  "relational_var", "equality_var", "and_var", "exclusive_or_var",
  "inclusive_or_var", "logical_and_var", "logical_xor_var",
  "logical_or_var", "conditional_var", "assignment_var", "expr_var",
  "matrix_variable", "surface", "identifier", "function_variable",
  "variable_without_assign", "unprocessed_variable", "processed_variable",
  "variable", "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       354,     0,    -1,    -1,   355,     0,    -1,   356,    -1,   355,
     356,    -1,   365,   356,    -1,   355,   365,   356,    -1,   357,
      -1,   355,   357,    -1,   358,    -1,   355,   358,    -1,   364,
      -1,   355,   364,    -1,   359,    -1,   355,   359,    -1,   362,
      -1,   355,   362,    -1,   363,    -1,   355,   363,    -1,    36,
      -1,    23,    -1,   283,   401,   104,   374,   284,   374,   370,
     356,    -1,   283,   401,   104,   374,   284,   374,   285,   374,
     370,   356,    -1,   283,   401,   287,   366,   370,   356,    -1,
     288,   370,    -1,   290,   406,   370,    -1,   292,   374,   370,
     356,    -1,   292,   374,   370,   294,   370,   356,    -1,    -1,
     319,   401,   360,    13,   368,    14,   370,   356,    -1,    -1,
     319,    66,   361,    13,   368,    14,   370,   356,    -1,   320,
     401,   370,   356,    -1,   320,   401,    22,   321,    67,   370,
     356,    -1,    67,   401,    -1,   296,   376,   356,    -1,   296,
     356,    -1,   297,   376,    -1,   404,    -1,   398,    -1,    35,
      -1,   291,    -1,    74,    -1,    76,    -1,    77,    -1,    75,
      -1,    78,    13,   374,    14,    -1,    79,    13,   374,    20,
      66,    14,    -1,   401,   104,    17,   404,    -1,   401,   104,
      17,   398,    -1,   401,   104,   398,    -1,   401,   104,   398,
      20,   376,    -1,   401,   104,   403,    -1,   401,   104,    37,
      15,   374,    16,    -1,   401,    83,   375,    -1,    69,    15,
     374,    16,   104,   375,    -1,   401,   104,   252,    13,   374,
      14,    -1,   401,   104,   252,    13,   374,    14,    20,   376,
      -1,   401,   104,   249,    13,   374,    14,    -1,   401,   104,
     249,    13,   374,    14,    20,   376,    -1,    24,    -1,    25,
      -1,    26,   374,    -1,    27,   374,    -1,    29,    -1,    30,
      -1,    28,   374,    -1,    31,    13,   374,    14,    -1,    32,
      13,   376,    14,    -1,    42,    -1,    40,   378,    -1,    43,
     378,    -1,    40,    68,    -1,   378,    19,    80,    13,   374,
      20,   398,    14,    -1,   378,    13,   374,    22,   374,    20,
     374,    22,   374,    20,   374,    22,   374,    14,   104,   375,
      -1,    40,   295,    -1,    72,    13,   406,    20,   376,    14,
      -1,    70,   406,    -1,    71,   376,    -1,    49,   376,    -1,
      50,    -1,    41,    -1,    41,   401,    -1,    41,    65,    -1,
      41,    62,    -1,    41,    63,    -1,    41,    64,    -1,    41,
      54,    -1,    44,   398,    -1,    45,   398,    -1,    46,   376,
      -1,   378,    19,   143,    -1,   378,    19,   148,    -1,    68,
     148,    -1,   378,    19,   243,    13,   374,    14,    -1,   378,
      19,   243,    13,   374,    20,   374,    20,   374,    14,    -1,
     378,    19,   240,    13,   374,    14,    -1,   378,    19,   240,
      13,   374,    20,   374,    20,   374,    14,    -1,   378,    19,
     240,    13,   374,    20,   374,    14,    -1,   378,    19,   241,
      13,   374,    20,   374,    20,   374,    14,    -1,   378,    19,
     118,    13,   378,    20,   374,    20,   374,    20,   374,    14,
      -1,   378,    19,   118,    13,   378,    14,    -1,   378,    19,
      51,    13,   376,    14,    -1,   133,    19,   144,    -1,   133,
      19,   145,    -1,   134,    19,   144,    -1,   134,    19,   145,
      -1,   378,    19,   149,   376,    -1,   378,    19,   150,    -1,
     378,    19,   151,    13,   378,    14,    -1,   378,    19,   152,
      13,   378,    14,    -1,   342,    13,   376,    14,    -1,   343,
      13,   398,    20,   374,    20,   374,    20,   374,    20,   374,
      20,   374,    20,   374,    20,   374,    20,   374,    14,    -1,
     174,    13,   378,    20,   374,    20,   374,    14,    -1,   174,
      13,   378,    20,   374,    20,   374,    20,   375,    14,    -1,
     175,    13,   378,    20,   374,    20,   374,    14,    -1,   175,
      13,   378,    20,   374,    20,   374,    20,   375,    14,    -1,
     175,    13,   378,    20,   374,    20,   374,    20,   375,    20,
     374,    14,    -1,   176,    13,   378,    20,   374,    14,    -1,
     176,    13,   378,    20,   374,    20,   398,    14,    -1,   176,
      13,   378,    20,   374,    20,   374,    20,   375,    14,    -1,
     178,    13,   378,    20,   374,    20,   374,    20,   374,    20,
     374,    20,   374,    20,   374,    14,    -1,   178,    13,   378,
      20,   374,    20,   374,    20,   374,    20,   374,    20,   374,
      20,   374,    20,   375,    14,    -1,   177,    13,   378,    20,
     374,    20,   374,    20,   375,    20,   374,    14,    -1,   179,
      13,   378,    20,   374,    14,    -1,   204,    13,    54,    20,
     378,    20,   378,    20,   378,    20,   378,    20,   378,    20,
     378,    20,   375,    14,    -1,   204,    13,    54,    20,   378,
      20,   378,    20,   378,    20,   378,    20,   378,    20,   378,
      14,    -1,   203,    13,    54,    20,   378,    20,   378,    20,
     378,    20,   375,    14,    -1,   203,    13,    54,    20,   378,
      20,   378,    20,   378,    14,    -1,   181,    13,   378,    20,
     374,    20,   374,    20,   374,    14,    -1,   378,    19,   181,
      13,   374,    20,   374,    20,   374,    14,    -1,   378,    19,
     181,    13,   378,    14,    -1,   378,    19,   182,    13,   374,
      20,   374,    20,   374,    14,    -1,   378,    19,   182,    13,
     378,    14,    -1,   378,    19,   183,    13,   374,    14,    -1,
     120,    13,   378,    20,   378,    14,    -1,   120,    13,   378,
      20,   378,    20,   378,    14,    -1,   217,    13,   374,    14,
      -1,   218,    13,   374,    14,    -1,   261,    13,   375,    20,
     376,    20,   374,    14,    -1,   264,    13,   378,    14,    -1,
     202,    13,   378,    20,   378,    20,   374,    20,   374,    20,
     374,    20,   374,    20,   374,    20,   374,    14,    -1,   313,
      13,    54,    14,    -1,   126,    -1,   127,    -1,   129,    -1,
     344,    13,   378,    20,   376,    14,    -1,   345,    -1,   346,
      -1,   347,    -1,   348,    13,   378,    20,   378,    20,   378,
      20,   378,    20,   378,    20,   378,    20,   378,    20,   374,
      20,   374,    20,   374,    20,   374,    20,   374,    20,   374,
      20,   374,    14,    -1,   349,    13,   378,    20,   378,    20,
     374,    20,   374,    20,   374,    20,   374,    20,   374,    20,
     374,    20,   378,    20,   378,    20,   374,    14,    -1,   337,
      13,   374,    20,   374,    20,   374,    14,    -1,   376,    -1,
     366,    20,   376,    -1,    -1,   404,    -1,   367,    20,   404,
      -1,    17,   398,    -1,   367,    20,    17,   398,    -1,   398,
      -1,   367,    20,   398,    -1,    -1,   315,    57,    -1,   318,
      57,    -1,   316,    57,    -1,   314,    57,    -1,   368,    20,
     318,    57,    -1,   368,    20,   315,    57,    -1,   368,    20,
     316,    57,    -1,   368,    20,   314,    57,    -1,    54,    -1,
      48,    13,   376,    20,   374,    14,    -1,   128,    -1,   378,
      19,    52,    -1,    52,    13,   406,    14,    -1,    53,    13,
     406,    14,    -1,    33,    -1,   371,    55,   372,    -1,    -1,
      -1,    56,    -1,    34,    -1,   265,    -1,   266,    -1,   378,
      13,   374,    20,   374,    14,    -1,   378,    13,   374,    20,
     374,    20,   374,    14,    -1,   378,    19,   242,    13,   374,
      20,   374,    20,   374,    14,    -1,   378,    13,   374,    20,
     374,    20,   374,    20,   374,    14,    -1,   378,    13,   374,
      20,   374,    20,   374,    23,   374,    14,    -1,   378,    13,
     374,    20,   374,    23,   374,    14,    -1,   378,    13,   374,
      23,   374,    14,    -1,   378,    19,   298,    -1,   378,    19,
     299,    -1,   378,    19,   300,    -1,   378,    19,   301,    -1,
     378,    19,   302,    -1,   378,    19,   303,    -1,   378,    19,
     304,    -1,   378,    19,   305,    -1,   378,    19,   306,    -1,
     378,    19,   307,    -1,   378,    19,   308,    -1,   378,    19,
     309,    -1,   147,    13,   378,    20,   378,    14,    -1,   166,
      13,   378,    14,    -1,   219,    13,   378,    20,   374,    20,
     374,    20,   374,    14,    -1,   220,    13,   378,    14,    -1,
     220,    13,   374,    20,   374,    20,   374,    20,   374,    14,
      -1,   105,    13,   375,    14,    -1,   168,    13,   375,    14,
      -1,   106,    13,   375,    14,    -1,   107,    13,   375,    14,
      -1,   108,    13,   375,    14,    -1,   109,    13,   375,    14,
      -1,   106,    15,   375,    16,    13,   375,    14,    -1,   108,
      15,   375,    16,    13,   378,    14,    -1,   109,    15,   375,
      16,    13,   378,    14,    -1,   109,    15,   375,    16,    13,
     378,    20,   374,    14,    -1,   168,    15,   375,    16,    13,
     375,    14,    -1,   168,    13,   378,    20,   375,    14,    -1,
     260,    13,   376,    14,    -1,   399,    13,   374,    20,   374,
      14,    -1,   399,    19,   240,    13,   374,    20,   374,    20,
     374,    14,    -1,   310,    13,   401,    14,    -1,   310,    13,
     406,    14,    -1,   311,    13,   376,    14,    -1,   377,    19,
     309,    -1,   398,    -1,   398,    -1,   398,    -1,   248,    -1,
     249,    -1,   250,    -1,   251,    -1,   252,    -1,   253,    -1,
     254,    -1,   255,    -1,   256,    -1,   257,    -1,   258,    -1,
     378,    19,   259,    -1,    59,    -1,    69,    15,   374,    16,
      -1,   378,    -1,    37,   376,    -1,   198,    13,   376,    14,
      -1,   199,    13,   376,    14,    -1,    38,    -1,    37,    13,
     377,    20,   374,    20,   374,    20,   374,    14,    -1,    37,
      13,   377,    20,   374,    20,   374,    20,   374,    20,   374,
      14,    -1,    37,    13,   377,    20,   374,    20,   378,    14,
      -1,   169,    13,   375,    20,   374,    14,    -1,   170,    13,
     375,    20,   374,    14,    -1,   171,    13,   375,    20,   374,
      14,    -1,   172,    13,   375,    20,   375,    20,   374,    14,
      -1,   173,    13,   375,    20,   375,    20,   374,    14,    -1,
     110,    13,   378,    20,    54,    14,    -1,   110,    13,   378,
      20,    54,    20,   377,    14,    -1,   110,    13,   378,    20,
     378,    20,    54,    14,    -1,   110,    13,   378,    20,   378,
      20,    54,    20,   377,    14,    -1,   110,    13,   378,    20,
     378,    20,   378,    20,    54,    14,    -1,   110,    13,   378,
      20,   378,    20,   378,    20,    54,    20,   377,    14,    -1,
     111,    13,   375,    20,   374,    20,   374,    20,   374,    20,
     374,    14,    -1,   328,    19,   329,    13,   378,    20,   374,
      20,   374,    14,    -1,   230,    13,   378,    14,    -1,   124,
      13,   378,    20,   374,    20,   374,    20,   374,    14,    -1,
     231,    13,   378,    14,    -1,   153,    13,   375,    20,   374,
      14,    -1,   154,    13,   378,    14,    -1,   155,    13,   378,
      14,    -1,   156,    13,   378,    14,    -1,   157,    13,   378,
      20,   378,    20,   374,    20,   374,    20,   374,    14,    -1,
     158,    13,   378,    14,    -1,   159,    13,   378,    20,   378,
      20,   378,    20,   374,    20,   378,    14,    -1,   160,    13,
     378,    20,   378,    20,   378,    20,   374,    20,   378,    14,
      -1,   161,    13,   378,    20,   378,    20,   378,    20,   374,
      20,   378,    20,   374,    20,   374,    14,    -1,   162,    13,
     378,    20,   378,    20,   378,    20,   374,    20,   378,    20,
     374,    20,   374,    20,   374,    20,   374,    14,    -1,   163,
      13,   378,    20,   378,    20,   378,    20,   378,    14,    -1,
     163,    13,   378,    20,   378,    20,   378,    20,   378,    20,
     374,    14,    -1,   164,    13,   378,    14,    -1,   164,    13,
     378,    20,   378,    14,    -1,   165,    13,   378,    20,   378,
      14,    -1,   112,    13,   375,    20,   374,    14,    -1,   113,
      13,   378,    14,    -1,   123,    13,   378,    14,    -1,   114,
      13,   378,    20,   374,    14,    -1,   180,    13,   378,    14,
      -1,   115,    13,   378,    20,   374,    14,    -1,   116,    13,
     378,    20,   374,    14,    -1,   119,    13,   375,    20,   374,
      14,    -1,   117,    13,   378,    20,   374,    20,   374,    20,
     374,    20,   374,    20,   374,    20,   374,    14,    -1,   132,
      13,   378,    20,   378,    20,   374,    20,   374,    20,   374,
      14,    -1,   122,    13,   378,    20,   374,    20,   374,    20,
     374,    20,   374,    20,   374,    14,    -1,   121,    13,   378,
      20,   374,    20,   374,    20,   374,    20,   374,    14,    -1,
     133,    19,   143,    13,   378,    20,   374,    20,   374,    20,
     374,    14,    -1,   134,    19,   143,    13,   378,    20,   374,
      20,   374,    20,   374,    20,   374,    20,   374,    14,    -1,
     135,    13,   378,    14,    -1,   136,    13,   378,    20,   374,
      20,   374,    14,    -1,   136,    13,   378,    20,   374,    20,
     374,    20,   407,    14,    -1,   136,    13,   378,    20,   374,
      20,   374,    20,   374,    20,   407,    14,    -1,   137,    13,
     378,    20,   374,    20,   374,    20,   407,    14,    -1,   137,
      13,   378,    20,   374,    20,   374,    20,   374,    20,   407,
      14,    -1,   138,    13,   378,    20,   374,    20,   374,    20,
     407,    14,    -1,   139,    13,   378,    20,   374,    20,   374,
      20,   374,    20,   407,    14,    -1,   140,    13,   378,    20,
     374,    20,   374,    20,   374,    20,   407,    14,    -1,   141,
      13,   378,    20,   374,    20,   374,    20,   374,    20,   374,
      20,   407,    14,    -1,   142,    13,   378,    20,   374,    20,
     374,    20,   374,    20,   374,    14,    -1,   146,    13,   378,
      20,   374,    20,   374,    14,    -1,   167,    13,   378,    20,
     374,    20,   374,    20,   374,    20,   374,    20,   374,    14,
      -1,   244,    13,   398,    14,    -1,   245,    13,   398,    14,
      -1,   246,    13,   398,    14,    -1,   247,    13,   398,    14,
      -1,   187,    13,   378,    20,   374,    14,    -1,   188,    13,
     378,    20,   374,    14,    -1,   189,    13,   378,    20,   374,
      14,    -1,   190,    13,   378,    20,   374,    14,    -1,   130,
      13,   375,    20,   375,    20,   374,    14,    -1,   131,    13,
     375,    20,   375,    20,   374,    20,   374,    20,   374,    20,
     374,    14,    -1,   130,    13,   375,    20,   375,    20,   374,
      20,   374,    20,   374,    14,    -1,   130,    13,   375,    20,
     375,    20,   374,    20,   374,    20,   374,    20,   374,    14,
      -1,   130,    13,   375,    20,   375,    20,   378,    20,   374,
      20,   374,    14,    -1,   200,    13,   378,    20,   378,    14,
      -1,   201,    13,   378,    20,   378,    20,   375,    14,    -1,
     205,    13,   378,    20,   374,    20,   374,    20,   374,    14,
      -1,   206,    13,   378,    20,   374,    20,   374,    20,   374,
      14,    -1,   206,    13,   378,    20,   374,    20,   374,    20,
     374,    20,   374,    14,    -1,   207,    13,   378,    20,   374,
      14,    -1,   208,    13,   378,    20,   374,    14,    -1,   209,
      13,   378,    20,   374,    14,    -1,   210,    13,   378,    20,
     374,    14,    -1,   211,    13,   378,    20,   374,    14,    -1,
     212,    13,   378,    20,   374,    14,    -1,   213,    13,   378,
      20,   374,    14,    -1,   214,    13,   378,    20,   374,    14,
      -1,   214,    13,   378,    20,   374,    20,   374,    14,    -1,
     215,    13,   378,    20,   374,    20,   374,    20,   374,    14,
      -1,   216,    13,   375,    14,    -1,   378,    13,   398,    14,
      -1,   262,    13,   375,    20,   374,    20,   374,    20,   374,
      14,    -1,   263,    13,   375,    20,   374,    20,   374,    20,
     374,    14,    -1,   322,    13,   375,    14,    -1,   322,    13,
     375,    20,   374,    14,    -1,   325,    13,   375,    20,   374,
      14,    -1,   323,    13,   375,    20,   374,    20,   374,    20,
     374,    20,   374,    14,    -1,   324,    13,   378,    20,   378,
      20,   374,    20,   374,    20,   374,    20,   374,    20,   374,
      20,   374,    20,   374,    20,   374,    20,   374,    20,   374,
      20,   374,    20,   374,    14,    -1,   327,    13,   375,    20,
     374,    20,   374,    14,    -1,   333,    13,   375,    20,   374,
      14,    -1,   333,    13,   375,    14,    -1,   334,    13,   375,
      20,   374,    14,    -1,   334,    13,   375,    14,    -1,   339,
      13,   375,    20,   375,    14,    -1,   340,    13,   375,    14,
      -1,   341,    13,   376,    14,    -1,   312,    13,   375,    20,
     374,    20,   374,    20,   374,    20,   374,    20,   374,    20,
     374,    20,   374,    14,    -1,   195,    13,    68,    20,   378,
      20,   375,    14,    -1,   197,    13,    68,    20,   376,    14,
      -1,   379,    -1,    60,    -1,   369,    -1,   402,    -1,    68,
      -1,    58,    -1,   373,    -1,   380,    -1,   400,    -1,   381,
      -1,   399,    -1,   232,    15,   374,    16,    -1,   106,    13,
     398,    20,   398,    14,    -1,    13,   398,    14,    -1,   382,
      -1,   407,    -1,   383,    19,   401,    -1,   383,    13,   367,
      14,    -1,     9,   382,    -1,   383,    93,    -1,   383,    94,
      -1,   383,   102,    -1,   383,    15,   398,    16,    -1,   383,
      -1,    13,   377,    14,   384,    -1,    11,   384,    -1,    10,
     384,    -1,    93,   383,    -1,    94,   384,    -1,   267,   384,
      -1,   268,   384,    -1,   278,   384,    -1,   279,   384,    -1,
     280,   384,    -1,   281,   384,    -1,   269,   384,    -1,   270,
     384,    -1,   271,   384,    -1,   272,   384,    -1,   275,   384,
      -1,   277,   384,    -1,   276,   384,    -1,   282,   384,    -1,
     384,    -1,   385,     7,   384,    -1,   385,     8,   384,    -1,
     385,    12,   384,    -1,   385,    -1,   386,    10,   385,    -1,
     386,    11,   385,    -1,   386,    -1,   387,    -1,   388,     6,
     387,    -1,   388,     5,   387,    -1,   388,    98,   387,    -1,
     388,    99,   387,    -1,   388,    -1,   389,   100,   388,    -1,
     389,   101,   388,    -1,   389,    -1,   390,    17,   389,    -1,
     390,    -1,   391,    -1,   392,    18,   391,    -1,   392,    -1,
     393,    96,   392,    -1,   393,    -1,   394,     4,   393,    -1,
     394,    -1,   395,    97,   394,    -1,   395,    -1,   395,    21,
     382,    22,   382,    -1,   396,    -1,   396,   104,   397,    -1,
     396,    83,   397,    -1,   396,    84,   397,    -1,   396,    85,
     397,    -1,   396,    86,   397,    -1,   396,    87,   397,    -1,
     397,    -1,   238,    13,   374,    20,   374,    14,    -1,    61,
      -1,   239,    13,   398,    14,    -1,   221,    13,   375,    20,
     374,    14,    -1,   224,    13,   378,    20,   374,    14,    -1,
     221,    13,   375,    20,   374,    20,   378,    14,    -1,   229,
      13,   375,    20,   374,    20,   375,    14,    -1,   225,    13,
      68,    14,    -1,   225,    13,    68,    20,   374,    14,    -1,
     226,    13,   378,    20,   374,    14,    -1,   227,    13,    68,
      20,   374,    14,    -1,   228,    13,    68,    20,   374,    14,
      -1,   232,    13,    14,    -1,   232,   376,    -1,   196,    13,
     376,    14,    -1,   196,    13,   376,    20,   374,    14,    -1,
     184,    13,   378,    14,    -1,   185,    13,    68,    14,    -1,
     185,    13,    68,    20,   374,    20,   374,    20,   374,    14,
      -1,   186,    13,    68,    20,   374,    14,    -1,   191,    13,
      68,    20,   374,    20,   374,    20,   374,    20,   374,    20,
     374,    20,   374,    14,    -1,   192,    13,   375,    20,   374,
      20,   374,    20,   374,    20,   374,    20,   374,    20,   374,
      20,   374,    14,    -1,   193,    13,   375,    20,   374,    20,
     374,    20,   374,    14,    -1,   194,    13,   375,    20,   374,
      20,   374,    20,   374,    20,   374,    20,   374,    20,   374,
      20,   374,    20,   374,    14,    -1,   194,    13,   375,    20,
     374,    20,   374,    20,   374,    20,   374,    20,   374,    14,
      -1,   330,    13,   375,    14,    -1,   330,    13,   375,    20,
     374,    14,    -1,   330,    13,   375,    20,   374,    20,   374,
      14,    -1,   332,    13,   375,    20,   374,    20,   374,    14,
      -1,   331,    13,   375,    20,   374,    20,   374,    20,   375,
      20,   375,    14,    -1,   331,    13,   375,    20,   374,    20,
     374,    20,   375,    20,   375,    20,   375,    20,   374,    14,
      -1,   335,    13,   375,    20,   375,    20,   375,    20,   374,
      20,   374,    20,   374,    20,   374,    14,    -1,   335,    13,
     375,    20,   375,    20,   375,    20,   374,    20,   374,    20,
     374,    20,   374,    20,   374,    14,    -1,   335,    13,   375,
      20,   375,    20,   375,    20,   374,    20,   374,    20,   374,
      14,    -1,   336,    13,   375,    20,   374,    20,   374,    20,
     374,    20,   374,    20,   374,    14,    -1,   338,    13,   375,
      20,   375,    20,   375,    20,   374,    20,   374,    20,   374,
      20,   374,    14,    -1,   338,    13,   375,    20,   375,    20,
     375,    20,   374,    20,   374,    20,   374,    20,   374,    20,
     375,    20,   375,    14,    -1,    57,    -1,    62,    -1,    63,
      -1,    65,    -1,    64,    -1,    66,    -1,    67,    -1,    69,
      -1,   403,    -1,    68,    -1,    58,    -1,    60,    -1,    61,
      -1,   378,    -1,   404,    -1,   405,    -1,   402,    -1,   382,
      22,   382,    20,   382,    22,   382,    20,   382,    22,   382,
      -1,   382,    22,   382,    20,   382,    22,   382,    -1,    22,
      20,    22,    20,   382,    22,   382,    -1,   378,    19,    81,
      -1
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
     178,   183,   187,   193,   197,   204,   208,   215,   222,   231,
     238,   247,   249,   251,   254,   257,   259,   261,   264,   269,
     274,   276,   279,   282,   285,   294,   311,   314,   321,   324,
     327,   330,   332,   334,   337,   340,   343,   346,   349,   352,
     355,   358,   361,   365,   369,   372,   379,   390,   397,   408,
     417,   428,   441,   448,   455,   459,   463,   467,   471,   476,
     480,   487,   494,   499,   520,   529,   540,   549,   560,   573,
     580,   589,   600,   617,   636,   649,   656,   675,   692,   705,
     716,   727,   738,   745,   756,   763,   770,   777,   786,   791,
     796,   805,   810,   829,   834,   836,   838,   840,   847,   849,
     851,   853,   884,   909,   918,   920,   924,   925,   927,   931,
     934,   939,   941,   945,   946,   949,   952,   955,   958,   963,
     968,   973,   978,   980,   987,   989,   993,   998,  1003,  1005,
    1009,  1010,  1011,  1013,  1015,  1017,  1019,  1026,  1035,  1046,
    1057,  1068,  1077,  1084,  1088,  1092,  1096,  1100,  1104,  1108,
    1112,  1116,  1120,  1124,  1128,  1132,  1139,  1144,  1155,  1160,
    1171,  1176,  1181,  1186,  1191,  1196,  1201,  1209,  1217,  1225,
    1235,  1243,  1250,  1255,  1262,  1273,  1278,  1283,  1288,  1292,
    1294,  1296,  1298,  1300,  1302,  1304,  1306,  1308,  1310,  1312,
    1314,  1316,  1318,  1320,  1324,  1326,  1331,  1333,  1336,  1341,
    1346,  1348,  1359,  1372,  1381,  1388,  1395,  1402,  1411,  1420,
    1427,  1436,  1445,  1456,  1467,  1480,  1493,  1504,  1509,  1520,
    1525,  1532,  1537,  1542,  1547,  1560,  1565,  1578,  1591,  1608,
    1629,  1640,  1653,  1658,  1665,  1672,  1679,  1684,  1689,  1696,
    1701,  1708,  1715,  1722,  1739,  1752,  1767,  1780,  1793,  1810,
    1815,  1824,  1835,  1848,  1859,  1872,  1883,  1896,  1909,  1924,
    1937,  1946,  1961,  1966,  1971,  1976,  1981,  1988,  1995,  2002,
    2009,  2018,  2033,  2046,  2061,  2074,  2081,  2090,  2101,  2112,
    2125,  2132,  2139,  2146,  2153,  2160,  2167,  2174,  2181,  2190,
    2201,  2206,  2211,  2222,  2233,  2238,  2245,  2252,  2265,  2296,
    2305,  2312,  2317,  2324,  2329,  2336,  2341,  2346,  2365,  2374,
    2381,  2383,  2385,  2387,  2389,  2391,  2393,  2395,  2397,  2399,
    2401,  2403,  2408,  2415,  2419,  2421,  2423,  2427,  2432,  2435,
    2438,  2441,  2444,  2449,  2451,  2456,  2459,  2462,  2465,  2468,
    2471,  2474,  2477,  2480,  2483,  2486,  2489,  2492,  2495,  2498,
    2501,  2504,  2507,  2510,  2512,  2516,  2520,  2524,  2526,  2530,
    2534,  2536,  2538,  2542,  2546,  2550,  2554,  2556,  2560,  2564,
    2566,  2570,  2572,  2574,  2578,  2580,  2584,  2586,  2590,  2592,
    2596,  2598,  2604,  2606,  2610,  2614,  2618,  2622,  2626,  2630,
    2632,  2639,  2641,  2646,  2653,  2660,  2669,  2678,  2683,  2690,
    2697,  2704,  2711,  2715,  2718,  2723,  2730,  2735,  2740,  2751,
    2758,  2775,  2794,  2805,  2826,  2841,  2846,  2853,  2862,  2871,
    2884,  2901,  2918,  2937,  2952,  2967,  2984,  3005,  3007,  3009,
    3011,  3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,
    3031,  3033,  3035,  3037,  3039,  3051,  3059,  3067
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   822,   822,   823,   827,   827,   828,   829,   830,   830,
     831,   831,   832,   832,   833,   833,   834,   834,   835,   835,
     838,   839,   844,   863,   883,   929,   952,   982,   997,  1020,
    1019,  1051,  1050,  1096,  1113,  1135,  1156,  1163,  1198,  1208,
    1224,  1257,  1265,  1275,  1289,  1303,  1317,  1327,  1343,  1361,
    1376,  1402,  1439,  1466,  1538,  1549,  1575,  1711,  1723,  1742,
    1753,  1896,  1900,  1904,  1908,  1918,  1923,  1927,  1937,  1947,
    1958,  1961,  2020,  2042,  2130,  2220,  2246,  2250,  2262,  2276,
    2286,  2297,  2305,  2317,  2553,  2563,  2573,  2583,  2592,  2704,
    2716,  2757,  3227,  3249,  3273,  3295,  3307,  3321,  3340,  3362,
    3383,  3412,  3441,  3473,  3670,  3675,  3682,  3687,  3927,  3955,
    3969,  3976,  3982,  3990,  4341,  4349,  4360,  4383,  4409,  4437,
    4448,  4491,  4513,  4542,  4559,  4574,  4580,  4607,  4633,  4653,
    4670,  4676,  4682,  4693,  4699,  4707,  4722,  4731,  4742,  4759,
    4775,  4813,  4827,  4874,  4880,  4885,  4890,  4896,  4918,  4923,
    4928,  4933,  4976,  5030,  5052,  5060,  5077,  5081,  5097,  5115,
    5130,  5145,  5166,  5191,  5196,  5205,  5212,  5219,  5242,  5249,
    5256,  5263,  5288,  5293,  5374,  5398,  5403,  5416,  5435,  5466,
    5477,  5478,  5483,  5487,  5495,  5503,  5512,  5529,  5545,  5562,
    5581,  5599,  5615,  5631,  5637,  5643,  5649,  5655,  5661,  5667,
    5673,  5679,  5685,  5691,  5697,  5704,  5713,  5720,  5751,  5759,
    5771,  5791,  5811,  5831,  5851,  5871,  5891,  5915,  5939,  5963,
    5971,  5995,  6018,  6049,  6059,  6071,  6081,  6091,  6103,  6178,
    6196,  6208,  6229,  6234,  6238,  6242,  6246,  6250,  6254,  6258,
    6262,  6266,  6270,  6274,  6282,  6284,  6303,  6305,  6320,  6340,
    6375,  6409,  6416,  6434,  6525,  6591,  6598,  6605,  6613,  6621,
    6637,  6655,  6673,  6690,  6707,  6725,  6761,  6774,  6785,  6798,
    6822,  6833,  6844,  6854,  6864,  6897,  6908,  6929,  6949,  6990,
    7037,  7057,  7078,  7089,  7103,  7117,  7130,  7141,  7152,  7165,
    7183,  7195,  7207,  7259,  7580,  7614,  7647,  7675,  7689,  7703,
    7713,  7732,  7751,  7771,  7792,  7814,  7833,  7852,  7872,  7912,
    7934,  7963,  7985,  8022,  8059,  8096,  8154,  8161,  8168,  8176,
    8183,  8205,  8233,  8257,  8284,  8316,  8325,  8338,  8345,  8353,
    8367,  8379,  8391,  8401,  8412,  8422,  8432,  8443,  8453,  8464,
    8491,  8539,  8673,  8694,  8734,  8745,  8753,  8761,  8782,  8808,
    8819,  8826,  8832,  8838,  8845,  8870,  8888,  8895,  8928,  8947,
    8968,  8996,  9005,  9019,  9021,  9023,  9025,  9027,  9029,  9031,
    9033,  9035,  9056,  9198,  9201,  9203,  9205,  9234,  9311,  9319,
    9327,  9335,  9387,  9399,  9401,  9410,  9416,  9421,  9426,  9431,
    9436,  9441,  9446,  9451,  9456,  9461,  9466,  9471,  9476,  9481,
    9486,  9491,  9496,  9505,  9506,  9512,  9518,  9528,  9529,  9536,
    9546,  9550,  9551,  9557,  9563,  9569,  9578,  9579,  9585,  9611,
    9612,  9620,  9624,  9625,  9633,  9634,  9646,  9647,  9659,  9660,
    9672,  9673,  9686,  9687,  9697,  9704,  9710,  9716,  9722,  9731,
    9789,  9795,  9804,  9949,  9964,  9976,  9998, 10034, 10043, 10053,
   10062, 10072, 10086, 10093, 10102, 10118, 10137, 10157, 10187, 10216,
   10233, 10259, 10293, 10325, 10372, 10413, 10422, 10444, 10455, 10466,
   10502, 10544, 10590, 10640, 10682, 10713, 10745, 10787, 10800, 10801,
   10802, 10803, 10804, 10815, 10816, 10823, 10829, 10831, 10833, 10836,
   10838, 10842, 10844, 10846, 10850, 10872, 10889, 10910
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
     345,   346,   347,   348,   349,   350,   351,   352
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 9211;
  const int Parser::yynnts_ = 55;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 530;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 353;

  const unsigned int Parser::yyuser_token_number_max_ = 607;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

} // namespace yyip

#line 10951 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"

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
  //cout << "Notify()" << std::endl;
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




