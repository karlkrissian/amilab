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
#line 891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc.  */
#line 57 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

#ifndef YY_
# if YYENABLE_NLS
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
        case 47: /* "ASTRING" */
#line 885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 509: /* "primary_expr_string" */
#line 885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 510: /* "postfix_expr_string" */
#line 885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 227 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 511: /* "additive_expr_string" */
#line 885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 512: /* "expr_string" */
#line 885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 513: /* "instr_block" */
#line 886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };
#line 242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 578: /* "image_extent" */
#line 887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };
#line 247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
    #line 360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}
  /* Line 547 of yacc.c.  */
#line 329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
	  case 18:
#line 928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=driver.yyiplineno;
       int* varint;
        AmiInstructionBlock_ptr block((yysemantic_stack_[(8) - (7)].ablock));

      varint = new int;
      Vars.AddVar(type_int,(yysemantic_stack_[(8) - (2)].ident),(void*)varint);
      for(*varint = (int) (yysemantic_stack_[(8) - (4)].adouble); *varint <= (int) (yysemantic_stack_[(8) - (6)].adouble); (*varint)++)
        {
          driver.yyiplineno = block->GetStartingLine();
          driver.parse_block(block);
        }
      Vars.deleteVar((yysemantic_stack_[(8) - (2)].ident));
      driver.yyiplineno=previous_lineno;
    ;}
    break;

  case 19:
#line 946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=driver.yyiplineno;
       float* var;
        AmiInstructionBlock_ptr block((yysemantic_stack_[(10) - (9)].ablock));

      var = new float;
      Vars.AddVar(type_float,(yysemantic_stack_[(10) - (2)].ident),(void*)var);

      for(*var = (yysemantic_stack_[(10) - (4)].adouble); *var <= (yysemantic_stack_[(10) - (6)].adouble); (*var)+=(yysemantic_stack_[(10) - (8)].adouble))
        {

          driver.yyiplineno = block->GetStartingLine();
          //driver.yyiplineno=previous_lineno;
          driver.parse_block(block);

        }
      Vars.deleteVar((yysemantic_stack_[(10) - (2)].ident));
      driver.yyiplineno=previous_lineno;
    ;}
    break;

  case 20:
#line 967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=driver.yyiplineno;
        AmiInstructionBlock_ptr block((yysemantic_stack_[(2) - (2)].ablock));


      //          printf(" block = %s \n",$7);
          int res;
      //driver.yyiplineno = $2->GetStartingLine();
      
      do {

          //driver.yyiplineno=previous_lineno;
          driver.yyiplineno = block->GetStartingLine();
          res=driver.parse_block(block);

      } while (!res);
      driver.yyiplineno = previous_lineno;
    ;}
    break;

  case 21:
#line 989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno;
      AmiInstructionBlock_ptr block((yysemantic_stack_[(4) - (3)].ablock));

      // Pb with line numbers
      previous_lineno=driver.yyiplineno;

        if ((yysemantic_stack_[(4) - (2)].adouble)>0.5)
        {
          //driver.yyiplineno=previous_lineno;
          driver.parse_block(block);
          driver.yyiplineno = previous_lineno;
        }
    ;}
    break;

  case 22:
#line 1004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno = driver.yyiplineno;

      AmiInstructionBlock_ptr block_if(  (yysemantic_stack_[(6) - (3)].ablock));
      AmiInstructionBlock_ptr block_else((yysemantic_stack_[(6) - (5)].ablock));

      // Pb with line numbers
      previous_lineno=driver.yyiplineno;

      if ((yysemantic_stack_[(6) - (2)].adouble)>0.5)
        driver.parse_block(block_if);
      else
        driver.parse_block(block_else);
      driver.yyiplineno = previous_lineno;

    ;}
    break;

  case 23:
#line 1026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AMIFunction* amifunc;
      AmiInstructionBlock_ptr body((yysemantic_stack_[(7) - (6)].ablock));

      amifunc = new AMIFunction;

      amifunc->SetName((yysemantic_stack_[(7) - (2)].ident));
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(7) - (4)].paramlistdecl));
      amifunc->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", (yysemantic_stack_[(7) - (2)].ident),body->GetBody().c_str());

      Vars.AddVar( type_ami_function, (yysemantic_stack_[(7) - (2)].ident), (void*) amifunc);

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      procedure_declaration = 0;
    ;}
    break;

  case 24:
#line 1047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        int previous_lineno;
        string current_filename;

       previous_lineno=driver.yyiplineno;
       current_filename = driver.current_file;

       driver.res_print((yysemantic_stack_[(3) - (2)].astring));
       driver.yyiplineno=1;
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
       driver.yyiplineno=previous_lineno;
       driver.current_file = current_filename;

     ;}
    break;

  case 25:
#line 1064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        inc_cmd = str(format(" \"%1%\" // from browser ") % newname);
        if (driver.in_console)
          GB_main_wxFrame->GetConsole()
                          ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      ;}
    break;

  case 26:
#line 1098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*       var   = (yysemantic_stack_[(5) - (1)].variable);
          ParamList::ptr  param((yysemantic_stack_[(5) - (3)].paramlist));
          AMIFunction::ptr f;
          int          i,n;
          char*        name;

          f = *(AMIFunction_ptr*) (var->Pointer());

          // Verifier les parametres
          if (f->GetParamList( )->CheckParam(param.get())) {

          // Create the variables in a new context
          Vars.NewContext(f->GetName().c_str());
          for(i=0;i<param->GetNumParam();i++) {
            name = f->GetParamList( )->GetName(i);
            if (Vars.GetCurrentContext()->ExistVar(name,n)) {
              fprintf(stderr,"variable %s already exists ... \n",name);
            }
            else {
              // LOTS OF CARE HERE, now GetParam is a pointer
              // to a smart pointer !!!
              Vars.AddVarPtr( param->GetType(i),
                              name,
                              param->GetParam(i)
                            );
            }
          }

        driver.yyip_call_function(f);
        // destroy the context and its variables
        // removing each parameter is not necessary
        // cause it will be done by DeleteLastContext()
        Vars.DeleteLastContext();

        if (GB_debug)
          cerr  << "End function body = "
                << f->GetString()
                << endl;
      }

        ;}
    break;

  case 27:
#line 1141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*    var   = (yysemantic_stack_[(2) - (1)].variable);
          AMIFunction_ptr f;

          f = *(AMIFunction_ptr*) (var->Pointer());

          // Call the function
          Vars.NewContext(f->GetName().c_str());
          driver.yyip_call_function(f);
          Vars.DeleteLastContext();
        ;}
    break;

  case 28:
#line 1155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         ;}
    break;

  case 29:
#line 1163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         ;}
    break;

  case 30:
#line 1168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a global context for variables,
          creates new variables as global and can only
          access global variables

         Others:
          local, global_new
         **/
       Vars.SetCurrentContext(0);
         ;}
    break;

  case 31:
#line 1182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a global context for new variables,
          creates new variables as global,
          but allow access to lobal variables

         Others:
          local, global
         **/
       Vars.SetGlobalNew(1);
         ;}
    break;

  case 32:
#line 1196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a local context for new variables,
          creates new variables as local,
          and allow access to local variables

         Others:
          local, global, global_new
         **/
       Vars.SetGlobalNew(0);
         ;}
    break;

  case 33:
#line 1210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
         ;}
    break;

  case 34:
#line 1220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
/* TODO
       int ms = (int) $3;

       GB_TimeOut[0] = 0;
       XtAppAddTimeOut( GB_contexte,
                ms,
                CB_TimeOut,
                0);
       TantQue (!GB_TimeOut[0]) Faire
         Si XtAppPending( GB_contexte) Alors
           XtAppProcessEvent( GB_contexte, XtIMAll);
         FinSi
       FinTantQue

*/
         ;}
    break;

  case 35:
#line 1239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
              (3) time in ms
              (5) function to schedule
          **/
          // TODO To avoid pbs, make sure that the variable does not disappears
          // by making a copy of it
/* TODO
          int ms = (int) $3;
          Variable*    var   = $5;
          AMIFunction_ptr* f;

          f = new AMIFunction_ptr();
          f = (AMIFunction_ptr*) (var->Pointer());

          GB_TimeOut[0] = 0;
              XtAppAddTimeOut( GB_contexte,
              ms,
              CB_CallAMIFunction,
              (void*) f);
*/
         ;}
    break;

  case 36:
#line 1264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            VarArray* arraysurf;
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            arraysurf = new VarArray();
            arraysurf->Init(type_surface,size);
            Vars.AddVar(type_array,(yysemantic_stack_[(6) - (1)].ident),arraysurf);
          ;}
    break;

  case 37:
#line 1274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            VarArray* arraysurf;
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            arraysurf = new VarArray();
            arraysurf->Init(type_surface,size);
            Vars.AddVar(type_array,(yysemantic_stack_[(6) - (1)].ident),arraysurf);
          ;}
    break;

  case 38:
#line 1284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            VarArray* array;
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            array = new VarArray();
            array->Init(type_image,size);
            Vars.AddVar(type_array,(yysemantic_stack_[(6) - (1)].ident),array);
          ;}
    break;

  case 39:
#line 1294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)driver.im_stack.GetLastImage();
          if (imptr != NULL)
            Vars.AddVar(type_image,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
            driver.err_print("assignment of NULL image\n");
        ;}
    break;

  case 40:
#line 1304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)driver.im_stack.GetLastImage();
          if (imptr != NULL)
            Vars.AddVar(type_image,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
            driver.err_print("assignment of NULL image\n");
        ;}
    break;

  case 41:
#line 1313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*      var   = (yysemantic_stack_[(6) - (3)].variable);
          ParamList::ptr param((yysemantic_stack_[(6) - (5)].paramlist));
          Variable::ptr  res;

          res = ((Variable::ptr (*)(ParamList*)) var->Pointer())(param.get());
          if (!res.use_count()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          res->Rename((yysemantic_stack_[(6) - (1)].ident));
          Vars.AddVar(res);
        ;}
    break;

  case 42:
#line 1328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          void * imptr = (void*)driver.im_stack.GetLastImage();
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          array = *((VarArray::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer()));
          if (imptr != NULL)
            if (array->GetVar(i).Pointer()==NULL) {
              sprintf(name,"%s[%d]",(yysemantic_stack_[(6) - (1)].variable)->Name(),i);
              array->InitElement(i,imptr,name);
            }
            else
            {
              driver.err_print("array element already assigned\n");
              delete (InrImage*)imptr;
            }
          else
            driver.err_print("assignment of NULL image\n");
        ;}
    break;

  case 43:
#line 1350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*) driver.matrix_stack.GetLastMatrix();
          if (imptr != NULL)
        Vars.AddVar(type_matrix,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
        driver.err_print("assignment of NULL matrix\n");
        ;}
    break;

  case 44:
#line 1360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)driver.gltransf_stack.GetLastMatrix();
          if (imptr != NULL)
            Vars.AddVar(type_gltransform,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
            driver.err_print("assignment of NULL matrix\n");
        ;}
    break;

  case 45:
#line 1369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       ;}
    break;

  case 46:
#line 1374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
          (*m1) = m2;
          printf("delete m2\n");
          delete m2;
          printf("delete m2 end\n");
       ;}
    break;

  case 47:
#line 1384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          void * surfptr;
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          array = *((VarArray::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer()));
          surfptr = (void*)driver.surf_stack.GetLastSurf();
          if (surfptr != NULL)
          if (array->GetVar(i).Pointer()==NULL) {
            sprintf(name,"%s[%d]",(yysemantic_stack_[(6) - (1)].variable)->Name(),i);
            array->InitElement(i,surfptr,name);
          }
          else
          {
            driver.err_print("array element already assigned\n");
            delete (SurfacePoly*)surfptr;
          }
          else
            driver.err_print("assignment of NULL surface\n");
        ;}
    break;

  case 48:
#line 1407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * surfptr;
          surfptr = (void*)driver.surf_stack.GetLastSurf();
          if (surfptr != NULL)
            Vars.AddVar(type_surface,(yysemantic_stack_[(3) - (1)].ident),surfptr);
          else
            driver.err_print("assignment of NULL surface\n");
        ;}
    break;

  case 49:
#line 1417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable* var = (yysemantic_stack_[(3) - (1)].variable);
          void* surfptr  = (void*) driver.surf_stack.GetLastSurf();

          // instead of deleting and creating,
          // replace the pointer and the information
          if (surfptr != NULL) {
            var->FreeMemory();
            var->Init(type_surface,
                      var->Name(),
                      surfptr);
          }
          else
            driver.err_print("assignment of NULL surface\n");

        ;}
    break;

  case 50:
#line 1435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable* var = (yysemantic_stack_[(6) - (1)].variable);
          VarArray* arraysurf;
          int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
          if (size<1) size = 1;
          arraysurf = new VarArray();
          arraysurf->Init(type_surface,size);

          // instead of deleting and creating,
          // replace the pointer and the information
          if (arraysurf != NULL) {
            var->FreeMemory();
            var->Init(type_array,
                      var->Name(),
                      arraysurf);
          }
          else
            driver.err_print("not able to create surface array !\n");

        ;}
    break;

  case 51:
#line 1457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int* varint;
          varint = new int((int)(yysemantic_stack_[(6) - (5)].adouble));
          Vars.AddVar(type_int,(yysemantic_stack_[(6) - (1)].ident),(void*)varint);
        ;}
    break;

  case 52:
#line 1464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_uchar,(yysemantic_stack_[(6) - (1)].ident),(void*)varuchar);
        ;}
    break;

  case 53:
#line 1471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          varfloat = new float((yysemantic_stack_[(3) - (3)].adouble));
          Vars.AddVar(type_float,(yysemantic_stack_[(3) - (1)].ident),(void*)varfloat);
        ;}
    break;

  case 54:
#line 1478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string* varstring;
          varstring = new string((yysemantic_stack_[(3) - (3)].astring));
          Vars.AddVar(type_string,(yysemantic_stack_[(3) - (1)].ident),(void*)varstring);
              delete [] (yysemantic_stack_[(3) - (3)].astring);
        ;}
    break;

  case 55:
#line 1486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE* file;

          file = fopen((yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring));
          if (file!=NULL) {
            Vars.AddVar(type_file,(yysemantic_stack_[(8) - (1)].ident),(void*)file);
          } else {
          fprintf(stderr,"error opening file \n");
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

  case 56:
#line 1517 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::string filename((yysemantic_stack_[(8) - (1)].variable)->Name());
            Variable* var;

            if (Vars.GetVar(filename.c_str(),&var))
                Vars.deleteVar(filename.c_str());

            FILE* file;
            file = fopen((yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring));
            if (file!=NULL) {
                Vars.AddVar(type_file,filename.c_str(),(void*)file);
            } else {
                fprintf(stderr,"error opening file \n");
            }
        ;}
    break;

  case 57:
#line 1533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        ;}
    break;

  case 58:
#line 1538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        ;}
    break;

  case 59:
#line 1542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        ;}
    break;

  case 60:
#line 1546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
        ;}
    break;

  case 61:
#line 1551 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
        ;}
    break;

  case 62:
#line 1555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->SetProgress((int)((yysemantic_stack_[(4) - (3)].adouble)+0.5));
        ;}
    break;

  case 63:
#line 1558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GB_main_wxFrame->Close(true);
    ;}
    break;

  case 64:
#line 1562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          char titre[100];
          int i;
          Variable* var;
          int var_context = Vars.GetContext((yysemantic_stack_[(2) - (2)].variable));

          if (var_context>=0) {
            sprintf(titre,"%s_draw",(yysemantic_stack_[(2) - (2)].variable)->Name());
            if (GB_debug) fprintf(stderr,
                      "SHOW var_image  title %s \n",
                      titre);
            //if (Vars.GetCurrentContext()->GetVar(titre,&var)) {
            if (Vars.GetVar(titre,&var,var_context)) {
              DessinImageParametres* param;
              DessinImage::ptr di;
              di = *((DessinImage::ptr*) var->Pointer());
              param = di->GetParam();
              param->_MAJ.MAJCoupes();
              di->Paint();
            }
            else
            {
              if (GB_debug) fprintf(stderr,"SHOW var_image creating title %s \n",titre);
              DessinImage* di;

              std::string* varname = new std::string(titre);

              di = CreateIDraw( *varname,
                    *((InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

              Vars.SetNextVarContext(var_context);
              i = Vars.AddVar(type_imagedraw,titre, (void*) di);
              di->SetCloseFunction(
                (void*) CB_delete_imagedraw,
                (void*) (varname));
            }
          } // var_context >=0
        ;}
    break;

  case 65:
#line 1601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          char titre[100];
          Variable* var;

          sprintf(titre,"%s_draw",(yysemantic_stack_[(2) - (2)].variable)->Name());
          if (Vars.GetVar(titre,&var)) {

        if (var->Type() == type_imagedraw) {
            driver.err_print("Hide window \n");
            (*(DessinImage::ptr*) var->Pointer())->Hide();
        }
        else
          fprintf(stderr,"Variable %s_draw not of type imagedraw \n",
            (yysemantic_stack_[(2) - (2)].variable)->Name());
          } else
        fprintf(stderr,"Image %s not visible \n",
            (yysemantic_stack_[(2) - (2)].variable)->Name());

        ;}
    break;

  case 66:
#line 1621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string    titre;
          Viewer3D* surfdraw;
          Variable* var;
          int     i;
          int var_context = Vars.GetContext((yysemantic_stack_[(2) - (2)].variable));

          if (var_context>=0) {
            titre = str(format("%s_draw") % (yysemantic_stack_[(2) - (2)].variable)->Name());
            if (!Vars.GetVar(titre.c_str(),&var,var_context)) {
              surfdraw = new Viewer3D(  GB_main_wxFrame,
                                        wxString::FromAscii(titre.c_str()));

              Vars.SetNextVarContext(var_context);
              i = Vars.AddVar(type_surfdraw,titre.c_str(), (void*) surfdraw);
              surfdraw->SetCloseFunction(
                              (void*) CB_delete_surfdraw,
                              (void*) (*Vars.GetCurrentContext())[i]);
              // Add the surface to the OpenGL Object
              surfdraw->GetCanvas()->AddSurface(
                                *(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
              surfdraw->Paint();
              surfdraw->GetCanvas()->Normalize();
              surfdraw->GetCanvas()->Center();
            } else
              cerr << " variable " << titre << " already exists " << endl;
          } // var_context >=0
        ;}
    break;

  case 67:
#line 1650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          // Create the main frame window
          PenguinFrame *frame = new PenguinFrame(GB_main_wxFrame, wxT("wxWidgets Penguin Sample"),
              wxDefaultPosition, wxDefaultSize);

          #if wxUSE_ZLIB
            if (wxFileExists(wxT("penguin.dxf.gz")))
              frame->GetCanvas()->LoadDXF(wxT("penguin.dxf.gz"));
          #else
            if (wxFileExists(wxT("penguin.dxf")))
              frame->GetCanvas()->LoadDXF(wxT("penguin.dxf"));
          #endif

          // Show the frame 
          frame->Show(true);
        ;}
    break;

  case 68:
#line 1667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          InrImage* i2 = (InrImage*) driver.im_stack.GetLastImage();

          Si i2!=NULL Alors
            // copy option
            if (!((*i1)=(*i2))) driver.err_print(" Error in images assignement\n");
          Sinon
            driver.err_print("Error\n");
          FinSi
          delete i2;
        ;}
    break;

  case 69:
#line 1680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Replacing the previous image by the new one.
        **/
          Variable* var = (yysemantic_stack_[(3) - (1)].variable);
          void* imptr  = (void*) driver.im_stack.GetLastImage();

          // instead of deleting and creating,
          // replace the pointer and the information
          if (imptr != NULL) {
            var->FreeMemory();
            var->Init(type_image,
                      var->Name(),
                      imptr);
          }
          else
            driver.err_print("assignment of NULL image\n");
        ;}
    break;

  case 70:
#line 1700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) image
        (3) expression

        description:
        Sets the whole image to a constant value given by expression.
        **/
          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          i1->InitImage((yysemantic_stack_[(3) - (3)].adouble));
        ;}
    break;

  case 71:
#line 1713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) imageval: image expression

        description:
        assigns imageval to the component 'n' of the input image
        **/
          int comp = (int) (yysemantic_stack_[(6) - (3)].adouble);

          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          InrImage::ptr i2 = InrImage::ptr(
                                driver.im_stack.GetLastImage());

          Si (comp<0) Ou (comp>i1->GetVDim()) Alors
            fprintf(stderr,"image[n]=image error index too high, reset to 0 \n");
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
            driver.yyiperror("image[]=image\t second image has to be scalar \n");
            YYABORT;
          FinSi

        ;}
    break;

  case 72:
#line 1748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) val: numerical expression

        description:
        assigns the value val to every component 'n' of the input image
        **/
          int comp = (int) (yysemantic_stack_[(6) - (3)].adouble);

          Si (comp<0) Ou (comp>2) Alors
        fprintf(stderr,"image[n]=image error \n");
        comp = 0;
          FinSi

         InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();

          Si i1->VectorialFormat()  Alors

             i1->InitBuffer();
             Repeter
           i1->VectFixeValeur(comp,(yysemantic_stack_[(6) - (6)].adouble));
             JusquA Non(i1->IncBuffer()) FinRepeter

      FinSi

        ;}
    break;

  case 73:
#line 1778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int posx  = (int) (yysemantic_stack_[(16) - (3)].adouble);
          int stepx = (int) (yysemantic_stack_[(16) - (5)].adouble);
          int posy  = (int) (yysemantic_stack_[(16) - (7)].adouble);
          int stepy = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int posz  = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int stepz = (int) (yysemantic_stack_[(16) - (13)].adouble);


          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(16) - (1)].variable)->Pointer();
          InrImage* i2 = (InrImage*) driver.im_stack.GetLastImage();

          Func_Pad(i1.get(),i2,stepx,posx,stepy,posy,stepz,posz);

          delete i2;

        ;}
    break;

  case 74:
#line 1796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        ;}
    break;

  case 75:
#line 1800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        ;}
    break;

  case 76:
#line 1804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 77:
#line 1808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        ;}
    break;

  case 78:
#line 1812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        ;}
    break;

  case 79:
#line 1816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 80:
#line 1820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 81:
#line 1824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        ;}
    break;

  case 82:
#line 1828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        ;}
    break;

  case 83:
#line 1832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        ;}
    break;

  case 84:
#line 1837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        ;}
    break;

  case 85:
#line 1841 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         Vars.deleteVar((yysemantic_stack_[(2) - (2)].variable));
        ;}
    break;

  case 86:
#line 1850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yysemantic_stack_[(5) - (2)].variable)->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
        ;}
    break;

  case 87:
#line 1859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         std::system((yysemantic_stack_[(2) - (2)].astring));
         delete [] (yysemantic_stack_[(2) - (2)].astring);
           ;}
    break;

  case 88:
#line 1864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           ;}
    break;

  case 89:
#line 1872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 90:
#line 1884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"var")==0) {
         driver.res_print("var types: void image float int string imagedraw surface surfacedraw \n");
         driver.res_print("\t del varname\n");
         driver.res_print("\t\t\t - deletes a variable and frees its contents from memory \n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"cmd")==0) {
         driver.res_print("commands:\n");
         driver.res_print("\t sh Quit Image Show Help ls print func filter normgrad discnormgrad OpImage EDPdilate EDPerode EDPopen EDPclose\n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"fnc")==0) {
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
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"loop")==0) {
         driver.res_print("loops:\n");
         driver.res_print("\t  for var=expr to expr { instructions } \n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"cond")==0) {
         driver.res_print("loops:\n");
         driver.res_print("\t  if expr  { instructions } \n");
         driver.res_print("\t\t  [ else { instructions } ]\n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"arit")==0) {
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
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"image")==0) {
         driver.res_print("variable Image\n");
         driver.res_print(" Creation:\n");
         driver.res_print("\t Image \"filename\"\n");
         driver.res_print("\t\t\t - reads an image file \n");
         driver.res_print("\t Image \n");
         driver.res_print("\t\t\t -  open browsing window for choosing the image\n");
         driver.res_print("\t Image(basic_type, size_x , size_y, size_z) \n");
         driver.res_print("\t\t\t - create an image of a basic type and the given dimensions\n");
         driver.res_print("\t\t\t - basic_type are CHAR UCHAR SHORT USHORT FLOAT DOUBLE RGB FLOAT_VECTOR \n");
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


         driver.res_print("\t image = AnisoGS.init( var_image, expr, expr, expr )\n");
         driver.res_print("\t\t  expr 1:    sigma  \n");
         driver.res_print("\t\t  expr 2:    theshold  \n");
         driver.res_print("\t\t  expr 3:    data attachment coeff  \n");
         driver.res_print("\t AnisoGS.setcoeff( expr )\n");
         driver.res_print("\t\t  expr 1:    tangential coeff  \n");
         driver.res_print("\t AnisoGS.setcoeff( expr, expr )\n");
         driver.res_print("\t\t  expr 1:    min curv coeff  \n");
         driver.res_print("\t\t  expr 2:    max curv coeff  \n");
         driver.res_print("\t AnisoGS.iterate\n");
         driver.res_print("\t AnisoGS.end\n");

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
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"imagedraw")==0) {
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

  case 91:
#line 2132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 92:
#line 2186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%s",(yysemantic_stack_[(4) - (4)].astring));
          fflush(file.get());
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        ;}
    break;

  case 93:
#line 2194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        ;}
    break;

  case 94:
#line 2203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string and newline
          **/
        driver.res_print((yysemantic_stack_[(2) - (2)].astring));
        driver.res_print("\n");
        delete [] (yysemantic_stack_[(2) - (2)].astring);
          ;}
    break;

  case 95:
#line 2213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          ;}
    break;

  case 96:
#line 2219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          ;}
    break;

  case 97:
#line 2225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        ;}
    break;

  case 98:
#line 2232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        ;}
    break;

  case 99:
#line 2238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints a numerical value.
        **/
          string st;
          st = str(format("%5.10f") % (yysemantic_stack_[(2) - (2)].adouble));
          driver.res_print(st.c_str());
        ;}
    break;

  case 100:
#line 2248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints a numerical value and a newline.
        **/
          string st;
          st = str(format("%5.10f\n") %(yysemantic_stack_[(2) - (2)].adouble));
          driver.res_print(st.c_str());
        ;}
    break;

  case 101:
#line 2258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_pos._x = (int) (yysemantic_stack_[(10) - (5)].adouble);
          param->_pos._y = (int) (yysemantic_stack_[(10) - (7)].adouble);
          param->_pos._z = (int) (yysemantic_stack_[(10) - (9)].adouble);
          //      param->_pos.Check();
          param->_MAJ.MAJCoupes();

          draw->Paint();

        ;}
    break;

  case 102:
#line 2274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_curseur._visible = (int) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);
          //      param->_MAJ.MAJCoupes();

          draw->Paint();
        ;}
    break;

  case 103:
#line 2286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        ;}
    break;

  case 104:
#line 2296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;
            InrImage::ptr im;
            char title[255];
            int i;
            Variable* var;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            im   = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();

            sprintf(title,"%s_draw",(yysemantic_stack_[(6) - (5)].variable)->Name());

            if (Vars.GetCurrentContext()->GetVar(title,&var)) {
              DessinImage::ptr di;
              DessinImageParametres* param;
              di = *(DessinImage::ptr*) var->Pointer();
              param = di->GetParam();
              param->_MAJ.MAJCoupes();
              di->Paint();

/* already done at window creation
              std::string* varname = new std::string(title);
              di->SetCloseFunction(
                  (void*) CB_delete_imagedraw,
                  (void*) varname);
*/
              draw->CreeCompare2Image(di);
            }
            else
            {
              DessinImage* di;
              std::string* varname = new std::string(title);
              di = CreateIDraw( *varname, im);

              i = Vars.AddVar(type_imagedraw,title, (void*) di);
              di->SetCloseFunction(
                  (void*) CB_delete_imagedraw,
                  (void*) (varname));
              // get the pointer to the newly created
              // variable
              Variable* var;
              if (Vars.GetVar(title,&var))
                draw->CreeCompare2Image(*(DessinImage::ptr*)var->Pointer());
              else
                fprintf(stderr,"Image comparison: Variable %s not found !\n",title);
            }

        ;}
    break;

  case 105:
#line 2345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        DessinImage::ptr draw1;
        DessinImage::ptr draw2;

          draw1 = *(DessinImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          draw2 = *(DessinImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();

/*          std::string* varname = new std::string($5->Name());
          draw2->SetCloseFunction(
                  (void*) CB_delete_imagedraw,
                  (void*) varname);
*/
          draw1->CreeCompare2Image(draw2);
        ;}
    break;

  case 106:
#line 2360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (1) Image Draw Window
            (5)  comparison window
            (7) Vectorial image

        Description:
            Defines a displacement to apply to the cursor when
            comparing 2 image drawing windows
        **/
          DessinImage::ptr draw;
          DessinImage::ptr draw2;
          InrImage::ptr displ;

          draw  = *(DessinImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          draw2 = *(DessinImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
          displ = *(InrImage::ptr*)    (yysemantic_stack_[(8) - (7)].variable)->Pointer();
          draw->SetCompareDisplacement(draw2,displ);
        ;}
    break;

  case 107:
#line 2385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        DessinImage::ptr draw;
        FloatMatrix* mat;

        draw = *(DessinImage::ptr*) ((yysemantic_stack_[(28) - (1)].variable)->Pointer());

        mat = new FloatMatrix(4,4);
        (*mat)[0][0] = (yysemantic_stack_[(28) - (5)].adouble);
        (*mat)[0][1] = (yysemantic_stack_[(28) - (7)].adouble);
        (*mat)[0][2] = (yysemantic_stack_[(28) - (9)].adouble);
        (*mat)[0][3] = (yysemantic_stack_[(28) - (11)].adouble);
        (*mat)[1][0] = (yysemantic_stack_[(28) - (13)].adouble);
        (*mat)[1][1] = (yysemantic_stack_[(28) - (15)].adouble);
        (*mat)[1][2] = (yysemantic_stack_[(28) - (17)].adouble);
        (*mat)[1][3] = (yysemantic_stack_[(28) - (19)].adouble);
        (*mat)[2][0] = (yysemantic_stack_[(28) - (21)].adouble);
        (*mat)[2][1] = (yysemantic_stack_[(28) - (23)].adouble);
        (*mat)[2][2] = (yysemantic_stack_[(28) - (25)].adouble);
        (*mat)[2][3] = (yysemantic_stack_[(28) - (27)].adouble);

            if (draw->GetCompareWindow(0)!=NULL)
          draw->GetCompareWindow(0)->SetTransformationMatrix(mat);
        // PB: the matrix is never freed from memory ...
        // TODO use smart pointer management !!!

        ;}
    break;

  case 108:
#line 2412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Parameters:
                (1) Image Drawing window
                (5) Index of the vector field to be drawned (between 1 and 3)
                (7) Vector field image
            Description:
                Assign a vector field to be draw in the given image drawing window.
          **/
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->LoadVectImage( (int) (yysemantic_stack_[(8) - (5)].adouble), (*(InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer()));
        ;}
    break;

  case 109:
#line 2427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 110:
#line 2434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        ;}
    break;

  case 111:
#line 2441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
            (5) expression: vector size
            (7) expression: vector spacing

          Description:
            Sets the size and spacing of the vector drawing interface in the given
            image drawing window.
          **/
          DessinImage::ptr draw;
          float size    = (yysemantic_stack_[(8) - (5)].adouble);
          int   spacing = (int)(yysemantic_stack_[(8) - (7)].adouble);

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectParam( size, spacing);
        ;}
    break;

  case 112:
#line 2459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Parameters:
            (5)  expression: vector id
            (7)  expression: red component (0-255)
            (9)  expression: green component (0-255)
            (11) expression: blue component (0-255)

            Description:
            Sets the color of the given vector field (given by vector id),
            the color is set as (R,G,B) components, each component has a value
            between 0 and 255.
          **/
          DessinImage::ptr draw;
          int vectid = (int) (yysemantic_stack_[(12) - (5)].adouble);
          unsigned char red   = (unsigned char) (yysemantic_stack_[(12) - (7)].adouble);
          unsigned char green = (unsigned char) (yysemantic_stack_[(12) - (9)].adouble);
          unsigned char blue  = (unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(12) - (1)].variable)->Pointer());
          draw->SetVectColor( vectid,red,green,blue);
        ;}
    break;

  case 113:
#line 2482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 114:
#line 2487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 115:
#line 2492 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int xmin = (int)  (yysemantic_stack_[(16) - (5)].adouble);
          int ymin = (int)  (yysemantic_stack_[(16) - (7)].adouble);
          int zmin = (int)  (yysemantic_stack_[(16) - (9)].adouble);
          int xmax = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int ymax = (int) (yysemantic_stack_[(16) - (13)].adouble);
          int zmax = (int) (yysemantic_stack_[(16) - (15)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          draw->SetZoom(xmin,ymin,zmin,xmax,ymax,zmax);

        ;}
    break;

  case 116:
#line 2505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        ;}
    break;

  case 117:
#line 2516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        ;}
    break;

  case 118:
#line 2525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        ;}
    break;

  case 119:
#line 2534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        ;}
    break;

  case 120:
#line 2542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) image to use for the isocontour
                (9) intensity value of the isocontour

            Description:
                Sets the image and intensity value of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
            draw->InitIsoContour( (*(InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer()), (yysemantic_stack_[(10) - (9)].adouble) , (int) (yysemantic_stack_[(10) - (5)].adouble) );
            draw->DrawIsoContour( (int) (yysemantic_stack_[(10) - (5)].adouble), true );
        ;}
    break;

  case 121:
#line 2559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) image to use for the isocontour
                (7) intensity value of the isocontour

            Description:
                Sets the image and intensity value of the isocontour number 0 in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
            draw->InitIsoContour( (*(InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer()), (yysemantic_stack_[(8) - (7)].adouble) , 0 );
            draw->DrawIsoContour( 0, true );
        ;}
    break;

  case 122:
#line 2575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) isocontour thickness
                (9) isocontour style

            Description:
                Sets the parameters (line style and thickeness)
                of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
            draw->SetIsoContourParam( (int)(yysemantic_stack_[(10) - (5)].adouble), (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble) );
        ;}
    break;

  case 123:
#line 2592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5)  isocontour index (0,1 or 2)
                (7)  isocontour thickness
                (9)  isocontour style (0,1,2 for LineSolid, LineOnOffDash, or LineDoubleDash)
                (11) cap_style (0:CapNotLast, 1:CapButt, 2:CapRound, or 3:CapProjecting)
                (13) join_style (0:JoinMiter, 1:JoinRound, or 2:JoinBevel)

            Description:
                Sets the parameters (line style and thickeness)
                of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(14) - (1)].variable)->Pointer());
            draw->SetIsoContourParam( (int)(yysemantic_stack_[(14) - (5)].adouble), (int)(yysemantic_stack_[(14) - (7)].adouble), (int)(yysemantic_stack_[(14) - (9)].adouble) );
            draw->SetLineAttributes( (int)(yysemantic_stack_[(14) - (11)].adouble), (int)(yysemantic_stack_[(14) - (13)].adouble));
        ;}
    break;

  case 124:
#line 2612 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) visible or not (0 or 1)

            Description:
                Sets the visibility of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
            draw->DrawIsoContour( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble) );
        ;}
    break;

  case 125:
#line 2627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7)  Red   component in [0,255]
                (9)  Green component in [0,255]
                (11) Blue  component in [0,255]

            Description:
                Sets the color as RGB of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;
            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(12) - (1)].variable)->Pointer());
            draw->SetIsoContourColor( (int) (yysemantic_stack_[(12) - (5)].adouble), (unsigned char) (yysemantic_stack_[(12) - (7)].adouble),
                                                (unsigned char) (yysemantic_stack_[(12) - (9)].adouble),
                                                (unsigned char) (yysemantic_stack_[(12) - (11)].adouble));
        ;}
    break;

  case 126:
#line 2645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) boolean parameter

            Description:
                Activates or desactivates the drawing of a series of isocontours.
            **/
            DessinImage::ptr draw;
            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetDrawAllContours( (int) (yysemantic_stack_[(6) - (5)].adouble) );
        ;}
    break;

  case 127:
#line 2658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) intensity step between isocontours
                (7) half size of the intensity range where to draw isocontours

            Description:
                Parameters for drawing a series of isocontours around the main isocontour.
            **/
            DessinImage::ptr draw;
            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
            draw->AllContoursParam(  (yysemantic_stack_[(8) - (5)].adouble) , (yysemantic_stack_[(8) - (7)].adouble) );
        ;}
    break;

  case 128:
#line 2672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        ;}
    break;

  case 129:
#line 2681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         description:
            Setting the opacity image for the volume rendering.
            This image should have unsigned char values.
         **/
          DessinImage::ptr draw;
          InrImage::ptr im;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
          draw->SetVolRenOpacity( im.get());
        ;}
    break;

  case 130:
#line 2695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
          (5) expr:  value to init the image

        description:
          Set the whole image to the same vector value .
        **/
          (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->InitImage((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 131:
#line 2706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
          (5) expr:  X coord of the init vector
          (7) expr:  Y coord of the init vector
          (9) expr:  Z coord of the init vector

        description:
          Set the whole image to the same value.
        **/
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->InitImage((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        ;}
    break;

  case 132:
#line 2719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
          #1 expr:  scalar value

        description:
        Set the current voxel (or pixel)
        to the specified value.
        The position of the current voxel can be set
        using 'setpos'.


        Others:
                setpos
        **/
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeValeur((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 133:
#line 2737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

        /**
        parameters:
          #1 expr:  X coord of the vector value
          #2 expr:  Y coord of the vector value
          #3 expr:  Z coord of the vector value

        description:
        Set the current voxel (or pixel)
        to the specified value.
        The position of the current voxel can be set
        using 'setpos'.


        Others:
                setpos
        **/

      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->VectFixeValeurs((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        ;}
    break;

  case 134:
#line 2759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X position
          (7) expr:  Y position
          (9) expr:  Z position

        Description:
          Set the current voxel (or pixel) of the image
          to the specified position.

        See Also:
          set
        **/
          Si (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->CoordOK( (int) (yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble))
          Alors
        (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->BufferPos((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          Sinon
        char tmp_string[255];
        sprintf(tmp_string,"coord = %f %f %f \n",(yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        driver.err_print(tmp_string);
          FinSi
        ;}
    break;

  case 135:
#line 2786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1)  var_image: image to modify
          (5)  var_image: image to insert
          (7)  expr:      X position of inserted image
          (9)  expr:      Y position
          (11) expr:      Z position

        description:
          Insert an image (#2) in a given image (#1)
          at the specified position in voxel coordinates,
          does not use the translation information from the image.

        Example:
          i = Image(FLOAT,10,10,10)
          j = Image(FLOAT,5,5,5)
          i.putimage(j,2,2,2)
        **/
       InrImage::ptr  i1;
       InrImage::ptr  i2;

       i1 = *(InrImage::ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
       i2 = *(InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer();
       Func_PutImage( i1.get(), i2.get(), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble));
        ;}
    break;

  case 136:
#line 2814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1)  var_image: image to modify
          (5)  var_image: image to insert

        description:
          Insert an image  in a given image,
          uses the translation and the voxel size information
          to calculate where to insert the image.

        Example:
          i = Image(FLOAT,10,10,10)
          j = Image(FLOAT,5,5,5)
          i.putimage(j,2,2,2)
        **/
      InrImage::ptr  i1;
      InrImage::ptr  i2;
      float tx1,ty1,tz1;
      float tx2,ty2,tz2;

          i1 = *(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          i2 = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      i1->GetTranslation(tx1,ty1,tz1);
      i2->GetTranslation(tx2,ty2,tz2);
      Func_PutImage( i1.get(), i2.get(),
             (int) round((tx2-tx1)/i1->VoxSizeX()),
             (int) round((ty2-ty1)/i1->VoxSizeY()),
             (int) round((tz2-tz1)/i1->VoxSizeZ()));
        ;}
    break;

  case 137:
#line 2845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 138:
#line 2851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (5)  var_image: input image
            (7)  expr: sigma, standard deviation of the Gaussian smoothing used
                        to compute the gradient and principal curvature directions
            (9)  expr:  threshold on the magnitude of the gradient
            (11) expr: data attachment coefficient

        Description:
            Sets parameters for the anisotropic diffusion algorithm using
            Gauss-Seidel scheme.
        **/
        Func_InitAnisoGS( ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),
                          (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble));
        ;}
    break;

  case 139:
#line 2869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 140:
#line 2874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 141:
#line 2879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 142:
#line 2884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 143:
#line 2889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 144:
#line 2894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Parameters:
            (5) image which defines a region of interest used
                to estimate the noise parameters in the
                Oriented Speckle Reducing Anisotropic Diffusion
         Description:
            Sets the region of interest (region of constant tissue in the image)
            and activates the Oriented Speckle Reducing Anisotropic Diffusion
         **/
          Func_AnisoGS_SetSRAD_ROI(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 145:
#line 2908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Parameters:
            (5) image which defines a region of interest used
                to estimate the noise parameters in the
                Rician Noise Reducing Anisotropic Diffusion
         Description:
            Sets the region of interest (region of constant tissue in the image)
            and activates the Rician Noise Reducing Anisotropic Diffusion
            used to reduce noise in MRI data.
         **/
          Func_AnisoGS_SetRNRAD_ROI(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 146:
#line 2923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Parameters:
            (5) image which defines a region of interest used
                to estimate the noise parameters in the
                Rician Noise Reducing Anisotropic Diffusion
         Description:
            Sets the region of interest (region of constant tissue in the image)
            and activates the Rician Noise Reducing Anisotropic Diffusion
            used to reduce noise in MRI data.
            New version of the filter, using local directional mean and variance
            for the diffusion matrix.
         **/
          Func_AnisoGS_SetRNRAD_ROI_NEW(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 147:
#line 2940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
            (5) expr: determine the local structure description
              0 for smoothed gradient and principal curv. directions
              1 for the local structure tensor

          Description:
            Sets the local structure mode.
         **/
      Func_SetLocalStructureMode((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 148:
#line 2954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
            (5) expr: option for selecting the eigenvalues for the
              diffusion matrix
              0: sums the 3D, 2D and 1D diffusions
                - lambda1 will depend on a coefficient based on a
                    3D neighborhood
                - lambda2 will be the sum of lambda1 + a coeff based
                    on a 2D neighborhood
                - lambda3 = lambda2 + coeff based on a linear neigh.
              1: take the maximum instead of the sum

          Description:
            Choose a way to select the diffusion matrix eigenvalues.
         **/
      Func_SetEigenvaluesMode((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 149:
#line 2974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 150:
#line 2979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 151:
#line 2984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    ;}
    break;

  case 152:
#line 2991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      driver.res_print("Error in AnisoGS.Iterate ");
    ;}
    break;

  case 153:
#line 3000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    ;}
    break;

  case 154:
#line 3008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 155:
#line 3013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    ;}
    break;

  case 156:
#line 3020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 157:
#line 3025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    ;}
    break;

  case 158:
#line 3030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
    // 1. number of iterations
    // 2. coefficient of the data attachment
    // 3. curvature coefficient
    // 4. reinitialization frequency for the distance map

    Func_LevelSets_InitParam(
                 0.8,
                 (int) (yysemantic_stack_[(12) - (5)].adouble),
                 (yysemantic_stack_[(12) - (7)].adouble),
                 (yysemantic_stack_[(12) - (9)].adouble),
                 1,
                 (int) (yysemantic_stack_[(12) - (11)].adouble)
                 );

        ;}
    break;

  case 159:
#line 3051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
    // 1. threshold on the cumulative histo of the grad norm for data attachment
    // 2. number of iterations
    // 3. coefficient of the data attachment
    // 4. curvature coefficient
    // 5. evolution step dt
    // 6. reinitialization frequency for the distance map


      Func_LevelSets_InitParam(
                   (yysemantic_stack_[(16) - (5)].adouble),
                   (int) (yysemantic_stack_[(16) - (7)].adouble),
                   (yysemantic_stack_[(16) - (9)].adouble),
                   (yysemantic_stack_[(16) - (11)].adouble),
                   (yysemantic_stack_[(16) - (13)].adouble),
                   (int) (yysemantic_stack_[(16) - (15)].adouble)
                   );

        ;}
    break;

  case 160:
#line 3074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 161:
#line 3079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 162:
#line 3084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 163:
#line 3089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 164:
#line 3094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 165:
#line 3099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 166:
#line 3104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 167:
#line 3109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 168:
#line 3114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 169:
#line 3119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 170:
#line 3124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 171:
#line 3129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 172:
#line 3134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    ;}
    break;

  case 173:
#line 3139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 174:
#line 3144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 175:
#line 3149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 176:
#line 3154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 177:
#line 3159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 178:
#line 3164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 179:
#line 3169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        ;}
    break;

  case 180:
#line 3177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 181:
#line 3182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 182:
#line 3187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 183:
#line 3192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 184:
#line 3197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 185:
#line 3202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 186:
#line 3207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        ;}
    break;

  case 187:
#line 3212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        ;}
    break;

  case 188:
#line 3217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        ;}
    break;

  case 189:
#line 3222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 190:
#line 3227 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 191:
#line 3232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    ;}
    break;

  case 192:
#line 3237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    ;}
    break;

  case 193:
#line 3241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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


        Example:

          rgb_im = (RGB) im
          im.save "image.jpg"


        See also:
          image_cast
        **/
      (*(InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Sauve((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
        ;}
    break;

  case 194:
#line 3268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Normalizes a vector field given by a vectorial image.

        Example:
          v1.normalize

        **/
      Func_Normalize((((InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->get()));
        ;}
    break;

  case 195:
#line 3281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        ;}
    break;

  case 196:
#line 3286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    ;}
    break;

  case 197:
#line 3290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    ;}
    break;

  case 198:
#line 3296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (1) input polydata
        (4) filename
    Description:
        Save the first line of the polydata in text format
    **/
      SurfacePoly::ptr surf = (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer());
      Func_WriteCTALine(surf.get(),(yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    ;}
    break;

  case 199:
#line 3309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        ;}
    break;

  case 200:
#line 3315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 201:
#line 3321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 202:
#line 3327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 203:
#line 3334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        ;}
    break;

  case 204:
#line 3341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

        ;}
    break;

  case 205:
#line 3348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets the object visible or not visible in the scene.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));

        ;}
    break;

  case 206:
#line 3359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

        ;}
    break;

  case 207:
#line 3370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
         (1) surface object
         (5) alpha value

        Description:
         to define the transparency to the RGB color
         associated per each vertex (actived with Enable ColorMaterial)
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetColorOpacity((yysemantic_stack_[(6) - (5)].adouble));

        ;}
    break;

  case 208:
#line 3385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int n;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      Pour(n,0,s->NbPoints()-1)
        (*s)[n].SetColor((unsigned char) (yysemantic_stack_[(10) - (5)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (7)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (9)].adouble));
      FinPour

          s->SetColorMaterial(true);
          s->GLRecomputeList(  );

        ;}
    break;

  case 209:
#line 3400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        ;}
    break;

  case 210:
#line 3408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->SetColors( i , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 211:
#line 3417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->SetColors( i );

        ;}
    break;

  case 212:
#line 3426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        ;}
    break;

  case 213:
#line 3434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 214:
#line 3438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
        ;}
    break;

  case 215:
#line 3442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      float        depth = (yysemantic_stack_[(6) - (5)].adouble);
      char         name[100];
      int          n;

      // param 1: depth (neighborhood)
      //

      // Create images for the curvatures and their directions
      InrImage* Icmin;
      InrImage* Icmax;
      InrImage* Idmin;
      InrImage* Idmax;

      n = surf->GetNumberOfPoints();

      Icmin = new InrImage(n,1,1,WT_FLOAT,"mincurv.ami.gz");
      Icmax = new InrImage(n,1,1,WT_FLOAT,"maxcurv.ami.gz");

      Idmin = new InrImage(n,1,1,3,WT_FLOAT,"mincurvdir.ami.gz");
      Idmax = new InrImage(n,1,1,3,WT_FLOAT,"maxcurvdir.ami.gz");

      surf->ComputeCurvatures(Icmin,Icmax,Idmin,Idmax, (int) depth);

      sprintf(name,"%s_cmin",(yysemantic_stack_[(6) - (1)].variable)->Name());
      Vars.AddVar(type_image,name,Icmin);
      sprintf(name,"%s_cmax",(yysemantic_stack_[(6) - (1)].variable)->Name());
      Vars.AddVar(type_image,name,Icmax);
      sprintf(name,"%s_dmin",(yysemantic_stack_[(6) - (1)].variable)->Name());
      Vars.AddVar(type_image,name,Idmin);
      sprintf(name,"%s_dmax",(yysemantic_stack_[(6) - (1)].variable)->Name());
      Vars.AddVar(type_image,name,Idmax);

        ;}
    break;

  case 216:
#line 3479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->DisplacePoints( i );
      delete i;

        ;}
    break;

  case 217:
#line 3488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

        ;}
    break;

  case 218:
#line 3495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        ;}
    break;

  case 219:
#line 3502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        ;}
    break;

  case 220:
#line 3513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    ;}
    break;

  case 221:
#line 3521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression
      Description:
        Select lines based on an image
        The image is 1D of size the number of lines
        if the value is > 0.5, then select the corresponding line
    **/

      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

      s->SelectLines(im);
      s->GLRecomputeList();
      delete im;
    ;}
    break;

  case 222:
#line 3539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    ;}
    break;

  case 223:
#line 3549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        ;}
    break;

  case 224:
#line 3554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        ;}
    break;

  case 225:
#line 3561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        ;}
    break;

  case 226:
#line 3568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    ;}
    break;

  case 227:
#line 3576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    ;}
    break;

  case 228:
#line 3584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          SurfacePoly::ptr surf_init = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          SurfacePoly* surf;

          surf = Func_decimate(surf_init.get());
      Si surf != NULL Alors

        // Non correct: supprimer la variable et la re-creer:
        // car pb si la variable est deja utilisee ...
        //          $1->Init(type_surface,$1->Name(), surf);
        //      delete surf_init;
      Sinon
        fprintf(stderr,"improcess.y: var_surface.T_vtkDecimate \t error \n ");
          FinSi


    ;}
    break;

  case 229:
#line 3603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets a threshold for drawing connected components
          bigger.
        **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          GLuint _SURFACE;

          Si Non(s->_cc_calculees) Alors
            s->CalculCC();
          FinSi
          s->GLSurfaceMinThCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));

        ;}
    break;

  case 230:
#line 3619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Draw one connected component only
        **/
          SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          GLuint _SURFACE;

            //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceDrawOnlyCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));
            //          FinSi

        ;}
    break;

  case 231:
#line 3636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Activate/Desactivate Drawing of one connected components
        **/
          SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());
          GLuint _SURFACE;

      //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceSetDrawCC( _SURFACE, (int) (yysemantic_stack_[(8) - (5)].adouble),(int) (yysemantic_stack_[(8) - (7)].adouble));
        //          FinSi

        ;}
    break;

  case 232:
#line 3653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 233:
#line 3658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    ;}
    break;

  case 234:
#line 3663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    ;}
    break;

  case 235:
#line 3668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    ;}
    break;

  case 236:
#line 3673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        ;}
    break;

  case 237:
#line 3682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr di = *(DessinImage::ptr*) (yysemantic_stack_[(20) - (3)].variable)->Pointer();
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

      InrImage::ptr           im    = di->GetImage();
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
              di->FixeParametresLigne( 1, wxSOLID, wxCAP_ROUND, wxJOIN_MITER);
            else
              di->FixeParametresLigne( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
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
              di->FixeParametresLigne( 1, wxSOLID, wxCAP_ROUND, wxJOIN_MITER);
            else
              di->FixeParametresLigne( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
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

  case 238:
#line 3782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
          ElevateMesh can have different behaviors depending on the type of
          the input image. In any case, it scans all the points of the mesh,
          and uses their 2 first coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - if the image is scalar, the value of the image at position
            (x,y) is used to set the elevation of the mesh (z coordinate).
            - if the image contains 2D vectors, the vectors are used to set
            the (x,y) coordinates of each vertex of the mesh.
            - if the image contains 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        parameters:
        (1) input surface
        (5) input image

       Examples:
         s = CreateFlatMesh(i)
         ipos = Altitude2Postion(i,1)
         s.ElevateMesh(ipos)

       Others:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      AMIFluid::Func_ElevateMesh(s.get(),im);
      delete im;
        ;}
    break;

  case 239:
#line 3816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 240:
#line 3823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        ;}
    break;

  case 241:
#line 3831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        ;}
    break;

  case 242:
#line 3837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        ;}
    break;

  case 243:
#line 3844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        ;}
    break;

  case 244:
#line 3854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        ;}
    break;

  case 245:
#line 3863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        ;}
    break;

  case 246:
#line 3870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 247:
#line 3877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        ;}
    break;

  case 248:
#line 3887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        ;}
    break;

  case 249:
#line 3894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw;

      draw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());
      switch ((int) (yysemantic_stack_[(8) - (5)].adouble)) {
      case 1:
        draw->GetCanvas()->SetVectors1( (*(InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer()));
        break;
      case 2:
        draw->GetCanvas()->SetVectors2( (*(InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer()));
        break;
      }
    ;}
    break;

  case 250:
#line 3908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(16) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(16) - (5)].adouble);
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      int orientation = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int pos = (int) (yysemantic_stack_[(16) - (11)].adouble);
          float Imin = (yysemantic_stack_[(16) - (13)].adouble);
          float Imax = (yysemantic_stack_[(16) - (15)].adouble);

      draw->GetCanvas()->ShowFreeSection(num,im,orientation,pos,Imin,Imax);

          delete im;
        ;}
    break;

  case 251:
#line 3922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        ;}
    break;

  case 252:
#line 3930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        ;}
    break;

  case 253:
#line 3935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        ;}
    break;

  case 254:
#line 3943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        ;}
    break;

  case 255:
#line 3951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->Paint();
          sdraw->Update();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        ;}
    break;

  case 256:
#line 3962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
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

  case 257:
#line 3974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
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

  case 258:
#line 3986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
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

  case 259:
#line 3998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 260:
#line 4004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
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

  case 261:
#line 4017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        ;}
    break;

  case 262:
#line 4024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        ;}
    break;

  case 263:
#line 4035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Func_StructureTensorHessian(
            ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(8) - (3)].variable)->Name(),
            (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        ;}
    break;

  case 264:
#line 4057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensorHessian(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        ;}
    break;

  case 265:
#line 4083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
      int save_grad = (int) (yysemantic_stack_[(12) - (11)].adouble);

          Func_StructureTensorHessian(((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(12) - (3)].variable)->Name(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask, save_grad);
      delete mask;
        ;}
    break;

  case 266:
#line 4111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        ;}
    break;

  case 267:
#line 4121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 0,   // gamma
                 mask  // mask
                 );
      delete mask;
        ;}
    break;

  case 268:
#line 4134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        ;}
    break;

  case 269:
#line 4144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(10) - (3)].variable)->Name(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask  // mask
                 );
      delete mask;
        ;}
    break;

  case 270:
#line 4157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          Func_Derivatives(((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get(),
               (yysemantic_stack_[(16) - (3)].variable)->Name(),
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

  case 271:
#line 4186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_Derivatives(((InrImage::ptr*) (yysemantic_stack_[(18) - (3)].variable)->Pointer())->get(),
               (yysemantic_stack_[(18) - (3)].variable)->Name(),
               (yysemantic_stack_[(18) - (5)].adouble),   // sigma
               (yysemantic_stack_[(18) - (7)].adouble),   // gamma
               mask,  // mask
               (int)(yysemantic_stack_[(18) - (9)].adouble),   // 1st eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (11)].adouble),   // 2nd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (13)].adouble),   // 3rd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (15)].adouble)   // Gradient vector?
               );
      delete mask;
        ;}
    break;

  case 272:
#line 4204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_HessianVap(((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(12) - (3)].variable)->Name(),
              (yysemantic_stack_[(12) - (5)].adouble),   // sigma
              (yysemantic_stack_[(12) - (7)].adouble),   // gamma
              mask,
              (int) (yysemantic_stack_[(12) - (11)].adouble) // eigenvalue number
              );
      delete mask;
        ;}
    break;

  case 273:
#line 4218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name(),
              (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 274:
#line 4230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(18) - (3)].astring),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (5)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (7)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (9)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (11)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (13)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (15)].variable)->Pointer())->get(),
               mask  // mask
               );
      delete mask;
        ;}
    break;

  case 275:
#line 4251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(16) - (3)].astring),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (5)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (7)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (9)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (11)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (13)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (15)].variable)->Pointer())->get(),
               NULL
               );
        ;}
    break;

  case 276:
#line 4270 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_Eigen2D(
               (char*) (yysemantic_stack_[(12) - (3)].astring),
               ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(12) - (9)].variable) ->Pointer())->get(),
               mask  // mask
               );
      delete mask;
        ;}
    break;

  case 277:
#line 4287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Eigen2D(
               (char*) (yysemantic_stack_[(10) - (3)].astring),
               ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable) ->Pointer())->get(),
               NULL
               );
        ;}
    break;

  case 278:
#line 4298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 279:
#line 4303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 280:
#line 4308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    ;}
    break;

  case 281:
#line 4317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 282:
#line 4322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    ;}
    break;

  case 283:
#line 4331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        (5) boolean, 0 little endianness, 1 big endianness

      Description:
        Forces the endianness of the image, usually before writting it to a file.
        If the endianness is different from the one of the architecture, the bytes
        are swapped before writting, and there are swapped back after.
    **/
      ((amimage*) (*(*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())) )->SetEndianness((AMIENDIANNESS)(int)(yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 284:
#line 4345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    ;}
    break;

  case 285:
#line 4352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    ;}
    break;

  case 286:
#line 4358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;;}
    break;

  case 287:
#line 4361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int nb_event;

/* TODO
      nb_event = 0;
      TantQue (nb_event<500)  Faire
        Si XtAppPending( GB_contexte) Alors
          XtAppProcessEvent( GB_contexte, XtIMAll);
        FinSi
        nb_event++;
      FinTantQue
*/

    ;}
    break;

  case 288:
#line 4376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) IMAGE: 1D image to plot, where the voxel size in X is used
            (5) String: plot title
            (7) NUM: delay
        Description:
            Plots a 1D image using gnuplot.
        **/
      InrImage*   image = (InrImage*) driver.im_stack.GetLastImage();
      float* tabx;
      float* taby;
      GnuPlot   gnuplot;
      int x,num_courbe;
      char name[200];

          tabx = new float[image->_tx];
          taby = new float[image->_tx];

      Pour(x,0,image->_tx-1)
        tabx[x] = image->SpacePosX(x);
        taby[x] = (*image)(x,0,0);
      FinPour

          num_courbe = gnuplot.AddCourbe( image->_tx, tabx, taby, (yysemantic_stack_[(8) - (5)].astring));
      sprintf(name,"%s.gnuplot",(yysemantic_stack_[(8) - (5)].astring));
      gnuplot.XPlot(name,(int)(yysemantic_stack_[(8) - (7)].adouble));

      delete [] tabx;
      delete [] taby;
      delete image;
      delete [] (yysemantic_stack_[(8) - (5)].astring);
         ;}
    break;

  case 289:
#line 4410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
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

  case 290:
#line 4427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Func_Pad(
        ((InrImage::ptr*) (yysemantic_stack_[(18) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(18) - (5)].variable)->Pointer())->get(),
           step_x,step_y,step_z,
           pos_x,pos_y,pos_z);


        ;}
    break;

  case 291:
#line 4467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        ;}
    break;

  case 292:
#line 4472 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        ;}
    break;

  case 293:
#line 4477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        ;}
    break;

  case 294:
#line 4483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * pwptr;
          //    pwptr = (void*)new ParamPanel(GB_main_wxFrame,  (char*) $5);
          pwptr = (void*)new ParamPanel(GB_main_wxFrame,  (char*) (yysemantic_stack_[(6) - (5)].astring));
          GB_main_wxFrame->AddParamPage((wxWindow*)pwptr,GetwxStr((char*) (yysemantic_stack_[(6) - (5)].astring)));
          //GB_main_wxFrame->GetAuiManager().Update();
          if (pwptr != NULL)
        Vars.AddVar(type_paramwin,(yysemantic_stack_[(6) - (1)].ident),pwptr);
          else
        driver.err_print("assignment of NULL parameter window\n");
              delete [] (yysemantic_stack_[(6) - (5)].astring);
        ;}
    break;

  case 295:
#line 4497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
    pw->BeginBox( (char*) (yysemantic_stack_[(6) - (5)].astring));
    delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 296:
#line 4504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginBook();
    ;}
    break;

  case 297:
#line 4510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    ;}
    break;

  case 298:
#line 4516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->AddPage( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 299:
#line 4523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginPanel( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 300:
#line 4530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    ;}
    break;

  case 301:
#line 4536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    ;}
    break;

  case 302:
#line 4542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    ;}
    break;

  case 303:
#line 4548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        ;}
    break;

  case 304:
#line 4554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        ;}
    break;

  case 305:
#line 4560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

/* TODO
          GB_main_wxFrame->GetAuiManager().GetPane((wxWindow*) pw.get()).Show();
          //GB_main_wxFrame->GetAuiManager().GetPane((wxWindow*) pw.get()).Float();
          GB_main_wxFrame->GetAuiManager().Update();
*/
          //pw->AfficheDialogue();
        ;}
    break;

  case 306:
#line 4572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        ;}
    break;

  case 307:
#line 4578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1) Parameter window
          (5) parameter id
          (7) bool: 1/0 for show/hide
        Description:
          Show/hide the slider if there is one.
        **/
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int n = (int) (yysemantic_stack_[(8) - (5)].adouble);
          bool show = (bool) (yysemantic_stack_[(8) - (7)].adouble);

          pw->ParamShowSlider(n,show );
        ;}
    break;

  case 308:
#line 4595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer() );
        ;}
    break;

  case 309:
#line 4602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int n = pw->NbParameters();
      int i = (int) (yysemantic_stack_[(6) - (5)].adouble);
      if ((i>=0)&&(i<n))
        pw->SetDragCallback(i);
      else
        fprintf(stderr,"VAR_PARAMWIN.SetDragCallbackO( %d ) \t bad parameter number \n",i);
        ;}
    break;

  case 310:
#line 4613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        ;}
    break;

  case 311:
#line 4620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        ;}
    break;

  case 312:
#line 4625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        ;}
    break;

  case 313:
#line 4631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        ;}
    break;

  case 314:
#line 4636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        ;}
    break;

  case 315:
#line 4641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        ;}
    break;

  case 316:
#line 4646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        ;}
    break;

  case 317:
#line 4651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        ;}
    break;

  case 318:
#line 4662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im1 = *(InrImage::ptr*) (yysemantic_stack_[(30) - (3)].variable)->Pointer();
    InrImage::ptr im2 = *(InrImage::ptr*) (yysemantic_stack_[(30) - (5)].variable)->Pointer();
    InrImage::ptr u = *(InrImage::ptr*) (yysemantic_stack_[(30) - (7)].variable)->Pointer();
    InrImage::ptr v = *(InrImage::ptr*) (yysemantic_stack_[(30) - (9)].variable)->Pointer();
    InrImage::ptr corr = *(InrImage::ptr*) (yysemantic_stack_[(30) - (11)].variable)->Pointer();
    InrImage::ptr conf_x = *(InrImage::ptr*) (yysemantic_stack_[(30) - (13)].variable)->Pointer();
    InrImage::ptr conf_y = *(InrImage::ptr*) (yysemantic_stack_[(30) - (15)].variable)->Pointer();
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

  case 319:
#line 4694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im1 = *(InrImage::ptr*) (yysemantic_stack_[(24) - (3)].variable)->Pointer();
        InrImage::ptr im2 = *(InrImage::ptr*) (yysemantic_stack_[(24) - (5)].variable)->Pointer();
        float     sigma = (yysemantic_stack_[(24) - (7)].adouble);
        float     T     = (yysemantic_stack_[(24) - (9)].adouble);
        float     alpha = (yysemantic_stack_[(24) - (11)].adouble);
        long      dtype = (long) (yysemantic_stack_[(24) - (13)].adouble);      /* type of smoothness term */
        float     quantile = (yysemantic_stack_[(24) - (15)].adouble);          /* isotropy fraction */
        float     ht       = (yysemantic_stack_[(24) - (17)].adouble);          /* time step size */
        InrImage::ptr u =  *(InrImage::ptr*) (yysemantic_stack_[(24) - (19)].variable)->Pointer();  /* x component of optic flow, changed */
        InrImage::ptr v =  *(InrImage::ptr*) (yysemantic_stack_[(24) - (21)].variable)->Pointer();  /* y component of optic flow, changed */
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

  case 320:
#line 4718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        ;}
    break;

  case 321:
#line 4725 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 322:
#line 4746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        ;}
    break;

  case 323:
#line 4751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 324:
#line 4758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 325:
#line 4765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         ;}
    break;

  case 326:
#line 4773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 327:
#line 4781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 328:
#line 4790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 329:
#line 4797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 330:
#line 4804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 331:
#line 4811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 332:
#line 4818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 333:
#line 4825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 334:
#line 4832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 335:
#line 4839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 336:
#line 4846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 337:
#line 4853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 338:
#line 4860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 339:
#line 4869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 340:
#line 4875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_float);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 341:
#line 4881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_string);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 342:
#line 4887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_image);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 343:
#line 4893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 344:
#line 4899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_surface);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 345:
#line 4905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_float);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 346:
#line 4911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_string);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 347:
#line 4917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_image);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 348:
#line 4923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 349:
#line 4929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_surface);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 350:
#line 4936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        ;}
    break;

  case 351:
#line 4941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;

      res = new char[(*(string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->length()+1];
      strcpy(res,((string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get()->c_str());
      (yyval.astring)= res;
        ;}
    break;

  case 352:
#line 4953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       fflush(stdout);
        ;}
    break;

  case 353:
#line 4958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 354:
#line 4972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;
      long min,hour,sec;

      driver.IP_time.Fin();
      driver.IP_time.AddCumul();
      driver.IP_time.GetCumul(hour,min,sec);
      res = new char[10];
          sprintf(res,"%03d:%02d:%02d",(int)hour,(int)min,(int)sec);
      (yyval.astring)=res;
        ;}
    break;

  case 355:
#line 4984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    ;}
    break;

  case 357:
#line 4993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          char* res;
          res = new char[strlen((yysemantic_stack_[(3) - (1)].astring))+strlen((yysemantic_stack_[(3) - (3)].astring))+1];
          strcpy(res,(yysemantic_stack_[(3) - (1)].astring));
          strcat(res,(yysemantic_stack_[(3) - (3)].astring));
          delete [] (yysemantic_stack_[(3) - (1)].astring);
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          (yyval.astring)=res;
        ;}
    break;

  case 358:
#line 5003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        ;}
    break;

  case 360:
#line 5016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          ;}
    break;

  case 364:
#line 5030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    ;}
    break;

  case 365:
#line 5038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    ;}
    break;

  case 366:
#line 5046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    ;}
    break;

  case 367:
#line 5055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    ;}
    break;

  case 368:
#line 5059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
      char tmp_string[255];
    ;}
    break;

  case 369:
#line 5064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    ;}
    break;

  case 370:
#line 5068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    ;}
    break;

  case 372:
#line 5077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) input_image
        (3) x

        description:
        returns the image value at pixel (x,y=0,z=0).

        return:
        float value
        **/
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(4) - (3)].adouble),0);
    ;}
    break;

  case 373:
#line 5092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) input_image
        (3) x
        (5) y

        description:
        returns the image value at pixel (x,y,z=0) by default

        return:
        float value
        **/
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(6) - (3)].adouble),(int) ( (yysemantic_stack_[(6) - (5)].adouble)));
    ;}
    break;

  case 374:
#line 5108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(8) - (3)].adouble),(int) ( (yysemantic_stack_[(8) - (5)].adouble)), (int) ((yysemantic_stack_[(8) - (7)].adouble)));
    ;}
    break;

  case 375:
#line 5112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 3D voxel position.
        same as image(expr,expr,expr;expr)
        **/
        InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
        Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
           Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr,expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 376:
#line 5129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 3D voxel position.
        **/
        InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
        Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
           Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr;expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 377:
#line 5145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 2D  position. ( z component set to 0)
        **/
        InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      Si (im->CoordOK((int) (yysemantic_stack_[(8) - (3)].adouble),   (int (yysemantic_stack_[(8) - (5)].adouble)),   0  )
        Et ((int) (yysemantic_stack_[(8) - (7)].adouble) >=0) Et ((int)(yysemantic_stack_[(8) - (7)].adouble) <im->GetVDim())) Alors
        (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(8) - (3)].adouble),(int) (yysemantic_stack_[(8) - (5)].adouble),0, (int) (yysemantic_stack_[(8) - (7)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr;expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 378:
#line 5159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 1D  position. (y and z components set to 0)
        **/
      Si (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->CoordOK((int) (yysemantic_stack_[(6) - (3)].adouble),   0,   0  )
        Et ((int) (yysemantic_stack_[(6) - (5)].adouble) >=0) Et ((int)(yysemantic_stack_[(6) - (5)].adouble) <3) Alors
        (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(6) - (3)].adouble),0,0, (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Sinon
        driver.err_print("var_image(expr;expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 379:
#line 5172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
        Init the image buffer to the first voxel or pixel:
        at coordinates (0,0,0).

        See Also:
                inc val

        Example(s):

        i.init
        for x=0 to i.tx-1 {
          print "value at x = "; print x; print ": ";
          print i.val; print "\n";
          i.inc
        }
        **/
        (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->InitBuffer();
        ;}
    break;

  case 380:
#line 5193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"tx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_tx;
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"ty")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_ty;
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"tz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_tz;
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"trx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_translation_x;
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"vdim")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetVDim();
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"try")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_translation_y;
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"trz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_translation_z;
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"vx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_size_x;
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"vy")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_size_y;
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"vz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_size_z;
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"inc")==0) {
        (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->IncBuffer();
      }
      else
      if (strcmp((yysemantic_stack_[(3) - (3)].ident),"val")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->ValeurBuffer();
      }
      else
        {
          char tmp_string[255];
          sprintf(tmp_string," %s.%s identifier not recognized \n",
              (yysemantic_stack_[(3) - (1)].variable)->Name(), (yysemantic_stack_[(3) - (3)].ident));
          strcat(tmp_string," known identifiers {tx, ty, tz, vdim, trx, try, trz, vx, vy, vz, init, inc, val, info} \n");
          driver.err_print(tmp_string);
        }

        ;}
    break;

  case 381:
#line 5252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im;
        im=*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        char tmp_string[255];
        sprintf(tmp_string," format=%s  dim=(%d,%d,%d)x%d  vox=(%f,%f,%f) \
  translation =(%f,%f,%f) \n",
            im->FormatName().c_str(),
            im->_tx,
            im->_ty,
            im->_tz,
            im->GetVDim(),
            im->_size_x,
            im->_size_y,
            im->_size_z,
            im->_translation_x,
            im->_translation_y,
            im->_translation_z);
        driver.res_print(tmp_string);
    ;}
    break;

  case 382:
#line 5272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      char tmp_string[255];
      sprintf(tmp_string," %d points  %d polygons  \n",
          s->GetNumberOfPoints(),
          s->GetNumberOfPolys ()
          );
      driver.res_print(tmp_string);
          sprintf(tmp_string," limits X:[%4.2f %4.2f] Y:[%4.2f %4.2f]  Z:[%4.2f %4.2f]  \n",
          s->_xmin,s->_xmax,
          s->_ymin,s->_ymax,
          s->_zmin,s->_zmax);

      driver.res_print(tmp_string);
    ;}
    break;

  case 383:
#line 5290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    ;}
    break;

  case 384:
#line 5297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    ;}
    break;

  case 385:
#line 5305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 386:
#line 5310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        ;}
    break;

  case 387:
#line 5315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          compute_area = new CalculAireSection( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                        resolution);
      compute_area->InitImagesSurf((InrImage*) NULL, (InrImage*) NULL,
                       (InrImage*) NULL, (InrImage*) NULL);
      surf_inf[0]  = surf_sup[0] = surf_interp[0] = 0.0;
      v1.Init( 1.0, 0.0, 0.0);
      v2.Init( 0.0, 1.0, 0.0);
      point.Init( cx,cy,0);

      (yyval.adouble)=compute_area->Aire( 0, point, v1, v2,
                  surf_inf, surf_sup, surf_interp);

      delete compute_area;

        ;}
    break;

  case 388:
#line 5343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
        ;}
    break;

  case 389:
#line 5349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        ;}
    break;

  case 390:
#line 5360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the of pixels (or voxels) with intensity higher than 0.5

             parameters:
               (3) image expression

            Keywords:

            Others:
                max, mean, min, median

        **/
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      (yyval.adouble)=Func_count( im );
      delete im;
        ;}
    break;

  case 391:
#line 5380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the average value of an image

             parameters:
               (3) image expression

            Keywords:

            Others:
                min, max, median

        **/
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      (yyval.adouble)=Func_mean( im);
      delete im;
        ;}
    break;

  case 392:
#line 5400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the maximal value of an image

             parameters:
               (3) image variable

            Keywords:

            Others:
                min, mean, median

        **/
      (yyval.adouble)=Func_max( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get(),NULL);
        ;}
    break;

  case 393:
#line 5418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the position of the maximal value of an image

             parameters:
               (3) image expression

            Keywords:

            Others:
                min, mean, median, max

        **/
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      (yyval.adouble)=Func_argmax( im);
      delete im;
        ;}
    break;

  case 394:
#line 5438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the minimal value of an image

             parameters:
               (3) image variable

            Keywords:

            Others:
                max, mean, median

        **/
      (yyval.adouble)=Func_min( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get(),NULL);
        ;}
    break;

  case 395:
#line 5456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the median value of an image

             parameters:
               (3) image variable

            Keywords:

            Others:
                min, max, mean, count

        **/
      (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get(),0.5,NULL);
        ;}
    break;

  case 396:
#line 5474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the maximal value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression
               (5) image variable

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_max( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),mask);
          delete mask;
        ;}
    break;

  case 397:
#line 5497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the minimal value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression
               (5) image variable

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_min( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),mask);
          delete mask;
        ;}
    break;

  case 398:
#line 5520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the median value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression
               (5) image variable

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),0.5,mask);
          delete mask;
        ;}
    break;

  case 399:
#line 5543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        ;}
    break;

  case 400:
#line 5550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the average value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression: defines the Region of Interest
               (5) image expression: image from which to compute the mean intensity value.

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* input = (InrImage*) driver.im_stack.GetLastImage();
          InrImage* mask  = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_mean( input,mask);
          delete mask;
          delete input;
        ;}
    break;

  case 401:
#line 5575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the maximal value of an image in a region of
             interest

             parameters:
               (3) image variable
               (5) image expression: the pixels (or voxels) higher than 0.5
               define the Region of Interest

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          (yyval.adouble)=Func_mean( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), mask);
          delete mask;
        ;}
    break;

  case 402:
#line 5598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
        ;}
    break;

  case 403:
#line 5605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        ;}
    break;

  case 404:
#line 5615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        ;}
    break;

  case 405:
#line 5625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        ;}
    break;

  case 406:
#line 5635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        ;}
    break;

  case 407:
#line 5645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        ;}
    break;

  case 408:
#line 5655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        ;}
    break;

  case 409:
#line 5665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;
          string comment;
          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          (yyval.adouble)=param->_pos._x;
          comment = str(format(" //  xpos=%3d") % param->_pos._x);
          if (driver.in_console)
            GB_main_wxFrame->GetConsole()
                           ->IncCommand(wxString::FromAscii(comment.c_str()));
        ;}
    break;

  case 410:
#line 5679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._y;

      comment = str( format(" //  ypos=%3d") % param->_pos._y);
      if (driver.in_console)
        GB_main_wxFrame->GetConsole()
                       ->IncCommand(wxString::FromAscii(comment.c_str()));

    ;}
    break;

  case 411:
#line 5696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._z;

      comment = str( format(" //  xpos=%3d") % param->_pos._z);
      if (driver.in_console)
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    ;}
    break;

  case 412:
#line 5712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    ;}
    break;

  case 413:
#line 5717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    ;}
    break;

  case 414:
#line 5722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    ;}
    break;

  case 415:
#line 5726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    ;}
    break;

  case 416:
#line 5733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    ;}
    break;

  case 417:
#line 5741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
          description:
            Adds an interface for a floating point variable to the window of parameters.

          parameters:
            (1) variable of type window of parameters
            (5) float variable for which we want to create an interface
            (7) minimal value accepted
            (9) maximal value accepted

        Keywords:

        Others:
            ParamWin, AddInt, CreateWin, Display

        Example:
          a=1
          w1 = ParamWin("test")
          w1.AddFloat(a,1,100)
          w1.CreateWin
          w1.Display
      **/

      float* var = ((float_ptr*)(yysemantic_stack_[(10) - (5)].variable)->Pointer())->get();
      float min_value = (float)(yysemantic_stack_[(10) - (7)].adouble);
      float max_value = (float)(yysemantic_stack_[(10) - (9)].adouble);

    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
        int var_id = pw->AddFloat( var, (char*)(yysemantic_stack_[(10) - (5)].variable)->Name());
        pw->FloatConstraints( var_id, min_value, max_value, *var );
        (yyval.adouble) = var_id;
    ;}
    break;

  case 418:
#line 5776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Add interface to set an integer value between a minimal and a maximal value.
      **/
      int* var = ((int_ptr*)(yysemantic_stack_[(10) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
      int var_id = pw->AddInteger( var, (char*)(yysemantic_stack_[(10) - (5)].variable)->Name());
          pw->IntegerConstraints( var_id, (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble), *var );
      (yyval.adouble) = var_id;
    ;}
    break;

  case 419:
#line 5789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable)->Pointer());
    (yyval.adouble) = bid;
    ;}
    break;

  case 420:
#line 5799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type UCHAR

    Description:
      Adds a boolean variable to the parameter window.
    **/
      unsigned char*   var = ((uchar_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int var_id;
      pw->AddBoolean( &var_id, var, (char*)(yysemantic_stack_[(6) - (5)].variable)->Name());
      pw->BooleanDefault( var_id, *var);
      (yyval.adouble) = var_id;
    ;}
    break;

  case 421:
#line 5816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type INT
      (7) number of different values of the enumeration

    Description:
      Adds an integer variable as an enumeration to the parameter window.
    **/
      int*   var = ((int_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int size = (int) (yysemantic_stack_[(8) - (7)].adouble);
      int var_id;
      pw->AddEnumeration( &var_id, size, var, (char*)(yysemantic_stack_[(8) - (5)].variable)->Name());
      //pw->EnumerationDefaut( var_id,  *var);
      (yyval.adouble) = var_id;
    ;}
    break;

  case 422:
#line 5835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type INT

    Description:
      Adds an integer variable as an enumeration to the parameter window.
    **/
      int*   var = ((int_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int var_id;
      pw->AddEnumeration( &var_id, var, (char*)(yysemantic_stack_[(6) - (5)].variable)->Name());
      (yyval.adouble) = var_id;
    ;}
    break;

  case 423:
#line 5851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) expression:        identificator of the enumeration parameter
      (7) string expression: text associated to this choice

    Description:
      Adds a choice for an enumeration created in the parameter window
    **/
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int id = (int) (yysemantic_stack_[(8) - (5)].adouble);
      int var_id;
      pw->AddEnumChoice( id, &var_id, (char*) (yysemantic_stack_[(8) - (7)].astring));
      (yyval.adouble) = var_id;
      delete [] (yysemantic_stack_[(8) - (7)].astring);
    ;}
    break;

  case 424:
#line 5869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) String variable to interface
      (7) label

    Description:
      Adds a string in the parameter window
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
        int var_id;
        pw->AjouteChaine( &var_id,
          ((string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
          (char*) (yysemantic_stack_[(8) - (7)].astring));
        pw->ContraintesChaine(var_id,(char*) ((string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer())->get()->c_str());
        (yyval.adouble)=var_id;
    ;}
    break;

  case 425:
#line 5889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) String variable to interface
      (7) label
      (9) default path
      (11) default mask

    Description:
      Adds a filename in the parameter window
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
        int var_id;
        // passer AjouteNomFichier a std::string !!!!
        pw->AjouteNomFichier( &var_id, ((string_ptr*)(yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(), (char*) (yysemantic_stack_[(12) - (7)].astring));
        pw->ContraintesNomFichier(var_id,(char*) (yysemantic_stack_[(12) - (9)].astring),(char*)"",(char*) (yysemantic_stack_[(12) - (11)].astring));
        (yyval.adouble)=var_id;
    ;}
    break;

  case 426:
#line 5910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window

    Description:
      update the display of all the parameters
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->MAJ();
    ;}
    break;

  case 427:
#line 5923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) parameter id

    Description:
      update the display of one parameter
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
        pw->UpdateParameter((int)(yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 428:
#line 5936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    ;}
    break;

  case 429:
#line 5944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    ;}
    break;

  case 430:
#line 5952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    ;}
    break;

  case 431:
#line 5956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float res;
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),(yysemantic_stack_[(6) - (5)].astring),&res);
        (yyval.adouble) =  res;
    ;}
    break;

  case 432:
#line 5964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    ;}
    break;

  case 435:
#line 5975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 436:
#line 5976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 437:
#line 5977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 438:
#line 5978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 439:
#line 5979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 440:
#line 5980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 441:
#line 5981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 442:
#line 5982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 443:
#line 5984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        ;}
    break;

  case 444:
#line 5991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 445:
#line 5992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 446:
#line 5993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 447:
#line 5994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 448:
#line 5995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 449:
#line 5996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 450:
#line 5997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 454:
#line 6010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      switch((WORDTYPE) (yysemantic_stack_[(4) - (2)].aint)) {
      case WT_UNSIGNED_CHAR:  (yyval.adouble)=(unsigned char) (yysemantic_stack_[(4) - (4)].adouble); break;
      case WT_SIGNED_SHORT:   (yyval.adouble)=(short) (yysemantic_stack_[(4) - (4)].adouble);  break;
      case WT_UNSIGNED_SHORT: (yyval.adouble)=(unsigned short) (yysemantic_stack_[(4) - (4)].adouble);  break;
      case WT_SIGNED_INT:     (yyval.adouble)=(int) (yysemantic_stack_[(4) - (4)].adouble);  break;
      case WT_UNSIGNED_INT:   (yyval.adouble)=(unsigned int) (yysemantic_stack_[(4) - (4)].adouble);  break;
      case WT_FLOAT:          (yyval.adouble)=(float) (yysemantic_stack_[(4) - (4)].adouble);  break;
      default:
        fprintf(stderr,"Conversion not available\n");
      }
        ;}
    break;

  case 456:
#line 6026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 457:
#line 6027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 459:
#line 6032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 460:
#line 6033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 463:
#line 6043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  ;}
    break;

  case 464:
#line 6044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  ;}
    break;

  case 465:
#line 6045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 466:
#line 6046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 468:
#line 6051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 469:
#line 6052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 470:
#line 6053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); ;}
    break;

  case 471:
#line 6054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); ;}
    break;

  case 473:
#line 6060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    ;}
    break;

  case 476:
#line 6073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        ;}
    break;

  case 477:
#line 6077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        ;}
    break;

  case 478:
#line 6084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        ;}
    break;

  case 479:
#line 6088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 480:
#line 6095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    ;}
    break;

  case 481:
#line 6099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    ;}
    break;

  case 483:
#line 6107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        ;}
    break;

  case 486:
#line 6124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    ;}
    break;

  case 487:
#line 6129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       ;}
    break;

  case 488:
#line 6133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       ;}
    break;

  case 489:
#line 6137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       ;}
    break;

  case 490:
#line 6141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       ;}
    break;

  case 491:
#line 6145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       ;}
    break;

  case 492:
#line 6149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       ;}
    break;

  case 493:
#line 6153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       ;}
    break;

  case 494:
#line 6157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       ;}
    break;

  case 495:
#line 6161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       ;}
    break;

  case 496:
#line 6165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      ;}
    break;

  case 497:
#line 6173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        ;}
    break;

  case 498:
#line 6178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          array = *(VarArray::ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          if (array->GetVar(i).Pointer()==NULL) {
            // create a small image to avoid problems
            InrImage* im = new InrImage(1,1,1,WT_UNSIGNED_CHAR);
            string name = str(format("%s[%d]") % (yysemantic_stack_[(4) - (1)].variable)->Name() % i);
            array->InitElement(i,im,name.c_str());
          }
          (yyval.variable)=&(array->GetVar(i));
        ;}
    break;

  case 499:
#line 6195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       ;}
    break;

  case 500:
#line 6201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       ;}
    break;

  case 501:
#line 6208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
         (3)  dimension in X
         (5)  dimension in Y
         (7)  image type, one of: CHAR, UCHAR, SHORT,
                                 USHORT, FLOAT, DOUBLE, RGB, FLOAT_VECTOR.
         (9)  endianess: 0 for little, 1 for big.
         (11) filename or file format
         (13) first slice number
         (15) last slice number

       Description:
         Read 2D raw data (or a sequence of 2D raw data) as an image.
         The program can read raw data compressed with gzip:
         if the file is not found, it looks for the same filename with a '.gz' extention. If
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.

       Examples:
          i = ReadRawImages(1024,1024,USHORT,0,"AfGG.%d",48,48)
       **/
     InrImage* im  = new InrImage();
     amimage* amim = new amimage();
     int dimx                    = (int)           (yysemantic_stack_[(16) - (3)].adouble);
     int dimy                    = (int)           (yysemantic_stack_[(16) - (5)].adouble);
     WORDTYPE inr_format         = (WORDTYPE)      (yysemantic_stack_[(16) - (7)].aint);
     int endianness              = (int)           (yysemantic_stack_[(16) - (9)].adouble);
     char* file_format           = (char*)         (yysemantic_stack_[(16) - (11)].astring);
     unsigned short first_slice  = (unsigned short)(yysemantic_stack_[(16) - (13)].adouble);
     unsigned short last_slice   = (unsigned short)(yysemantic_stack_[(16) - (15)].adouble);

         amim->SetDim(dimx,dimy,1);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

         im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format;
     delete [] file_format;
     amim->first_slice = first_slice;
     amim->last_slice  =  last_slice;

     if (amim->readdata_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       ;}
    break;

  case 502:
#line 6266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
         (3)  dimension in X
         (5)  dimension in Y
         (7)  dimension in Z
         (9)  image type, one of: CHAR, UCHAR, SHORT,
                                 USHORT, FLOAT, DOUBLE, RGB, FLOAT_VECTOR.
         (11)  endianess: 0 for little, 1 for big.
         (13) filename or file format

       Description:
         Read 3D raw data as an image.
         The program can read raw data compressed with gzip:
         if the file is not found, it looks for the same filename with a '.gz' extention. If
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.

       Examples:
          i = ReadRawImages(256,256,256,USHORT,0,"data.raw")
       **/
     InrImage* im  = new InrImage();
     amimage* amim = new amimage();
     int dimx                    = (int)           (yysemantic_stack_[(14) - (3)].adouble);
     int dimy                    = (int)           (yysemantic_stack_[(14) - (5)].adouble);
     int dimz                    = (int)           (yysemantic_stack_[(14) - (7)].adouble);
     WORDTYPE inr_format         = (WORDTYPE)      (yysemantic_stack_[(14) - (9)].aint);
     int endianness              = (int)           (yysemantic_stack_[(14) - (11)].adouble);
     char* file_format           = (char*)         (yysemantic_stack_[(14) - (13)].astring);

         amim->SetDim(dimx,dimy,dimz);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

     im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format;
     delete [] file_format;

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       ;}
    break;

  case 503:
#line 6320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
         (3)  dimension in X
         (5)  dimension in Y
         (7)  dimension in Z
         (9)  image type, one of: CHAR, UCHAR, SHORT,
                                 USHORT, FLOAT, DOUBLE, RGB,
         (11) Vectorial dimension
         (13)  endianess: 0 for little, 1 for big.
         (15) filename or file format

       Description:
         Read 3D raw data as an image.
         The program can read raw data compressed with gzip:
         if the file is not found, it looks for the same filename with a '.gz' extention. If
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.

       Examples:
          i = ReadRawImages(256,256,256,FLOAT,3,0,"3dvectorfielddata.raw")
       **/
     InrImage* im  = new InrImage();
     amimage* amim = new amimage();
     int dimx                    = (int)           (yysemantic_stack_[(16) - (3)].adouble);
     int dimy                    = (int)           (yysemantic_stack_[(16) - (5)].adouble);
     int dimz                    = (int)           (yysemantic_stack_[(16) - (7)].adouble);
     WORDTYPE inr_format         = (WORDTYPE)      (yysemantic_stack_[(16) - (9)].aint);
     int vdim                    = (int)           (yysemantic_stack_[(16) - (11)].adouble);
     int endianness              = (int)           (yysemantic_stack_[(16) - (13)].adouble);
     char* file_format           = (char*)         (yysemantic_stack_[(16) - (15)].astring);

     amim->SetDim(dimx,dimy,dimz);
     amim->SetVDim(vdim);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

     im->AMIFromWT(vdim,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format;
     delete [] file_format;

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       ;}
    break;

  case 504:
#line 6375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
        (3) STRING EXPRESSION: dicom directory

       Description:
         Reads a dicom file using VTK
       **/
            InrImage*  res;

            res = Func_vtkDicomRead( (char*) (yysemantic_stack_[(4) - (3)].astring));

            Si res==NULL Alors
                driver.err_print("vtkDicomRead() error ... \n");
                driver.im_stack.AddImage((InrImage*)NULL);
            FinSi

            driver.im_stack.AddImage(res);
            delete [] (yysemantic_stack_[(4) - (3)].astring);
       ;}
    break;

  case 505:
#line 6396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
        (3) STRING EXPRESSION: filename in minc format

       Description:
         Reads a file in minc format using vtk reader for MINC.
       **/
            InrImage*  res;

            res = Func_vtkMINCRead( (char*) (yysemantic_stack_[(4) - (3)].astring));

            Si res==NULL Alors
                driver.err_print("vtkMINCRead() error ... \n");
                driver.im_stack.AddImage((InrImage*)NULL);
            FinSi

            driver.im_stack.AddImage(res);
            delete [] (yysemantic_stack_[(4) - (3)].astring);
       ;}
    break;

  case 506:
#line 6417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
       ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
       InrImage*  im;

       im = ((InrImage* (*)(ParamList*)) var->Pointer())(param.get());
       if (!im) {
        driver.yyiperror(" image function returns NULL \n");
        YYABORT;
       }
      driver.im_stack.AddImage(im);
       ;}
    break;

  case 507:
#line 6431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskImage(name);
          if (!res) {
            driver.yyiperror(" Need Image \n");
            YYABORT;
          }
          driver.im_stack.AddImage((char*)name.c_str());


          wxFileName filename(GetwxStr(name));
          filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
          wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                              filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                              filename.GetPathSeparator(wxPATH_UNIX)+
                              filename.GetFullName());
          driver.res_print(newname.mb_str());
          driver.res_print("\n");
          inc_cmd = str(format(" \"%1%\" // from browser ") % newname);

          if (driver.in_console)
            GB_main_wxFrame->GetConsole()
                            ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      ;}
    break;

  case 508:
#line 6460 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(10) - (3)].aint), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      ;}
    break;

  case 509:
#line 6468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage* im;
    printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(12) - (3)].aint), (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));
    im = new InrImage( (int) (yysemantic_stack_[(12) - (5)].adouble), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble), (WORDTYPE) (yysemantic_stack_[(12) - (3)].aint));
    driver.im_stack.AddImage(im);
    ;}
    break;

  case 510:
#line 6487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* im;
      WORDTYPE imformat = (WORDTYPE) (yysemantic_stack_[(8) - (3)].aint);
      int vdim   = (int) (yysemantic_stack_[(8) - (5)].adouble);
      InrImage::ptr varim=*(InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer();
      string  imname;

      imname = str(format("newimagefrom_%s.ami.gz")
                  % (yysemantic_stack_[(8) - (7)].variable)->Name());

      im = new InrImage(imformat,vdim,
                        imname.c_str(),varim.get());
      driver.im_stack.AddImage(im);
    ;}
    break;

  case 511:
#line 6513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         InrImage::ptr varim;
         InrImage* im;
         char  imname[200];

         varim=*(InrImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();
         sprintf(imname,"copy_%s",(yysemantic_stack_[(1) - (1)].variable)->Name());
         im = new InrImage(varim->_format,imname,varim.get());
         (*im)=(*varim);
          driver.im_stack.AddImage(im);
       ;}
    break;

  case 512:
#line 6526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
        Description:
          Applied on RGB or vectorial images,
          returns one component of the image:
          expr=0 returns Red   if RGB or the X coordinate if vectorial
          expr=1 returns Green if RGB or the Y coordinate if vectorial
          expr=2 returns Blue  if RGB or the Z coordinate if vectorial

        Examples:
          i = Image "test.jpg"
          ired   = i[0]
          igreen = i[1]
          iblue  = i[2]

          print ired(i.tx/2,i.ty/2); print "\n"
          print i(i.tx/2,i.ty/2,0,0); print "\n"
       **/
         InrImage::ptr im1;
         InrImage* im;
          char  imname[200];
         int i;

         im1=*(InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer();

          i = (int) (yysemantic_stack_[(4) - (3)].adouble);
          Si i<0               AlorsFait i = 0;
          Si i>=im1->GetVDim() AlorsFait i = im1->GetVDim()-1;
          sprintf(imname,"C%d_%s",i,(yysemantic_stack_[(4) - (1)].variable)->Name());

         SelonQue im1->_format Vaut
          Valeur WT_RGB:
          Valeur WT_RGBA:
          Valeur WT_UNSIGNED_CHAR:
             im = new InrImage(WT_UNSIGNED_CHAR,1,imname,im1.get());
          FinValeur

          Valeur WT_UNSIGNED_INT:
             im = new InrImage(WT_UNSIGNED_INT,1,imname,im1.get());
          FinValeur

          Valeur WT_SIGNED_INT:
             im = new InrImage(WT_SIGNED_INT,1,imname,im1.get());
          FinValeur

          Valeur WT_UNSIGNED_SHORT:
             im = new InrImage(WT_UNSIGNED_SHORT,1,imname,im1.get());
          FinValeur

          Valeur WT_SIGNED_SHORT:
             im = new InrImage(WT_SIGNED_SHORT,1,imname,im1.get());
          FinValeur

          Valeur WT_FLOAT_VECTOR:
          Valeur WT_FLOAT:
             im = new InrImage(WT_FLOAT,1,imname,im1.get());
          FinValeur

          Valeur WT_DOUBLE:
             im = new InrImage(WT_DOUBLE,1,imname,im1.get());
          FinValeur

       Defaut:
        driver.yyiperror(" operator [] does not handle this format \n");
        YYABORT;
         FinSelonQue

         im->InitBuffer();
         im1->InitBuffer();
         Repeter
           im->FixeValeur(im1->VectValeurBuffer(i));
               im1->IncBuffer();
         JusquA Non(im->IncBuffer()) FinRepeter
         driver.im_stack.AddImage(im);

       ;}
    break;

  case 513:
#line 6604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the sum of the values of an image along the specified dimension
             0 for X, 1 for Y, 2 for Z

             parameters:
               (3) image expression
               (5) expr

            Keywords:

            Others:
                min, max, median

        **/
    InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
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
        }
        } else
        {
          driver.err_print("sum operator only for scalar images ... \n");
        }
        driver.im_stack.AddImage(res);
        delete im;
      ;}
    break;

  case 514:
#line 6671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
      ;}
    break;

  case 515:
#line 6679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
      ;}
    break;

  case 516:
#line 6687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      ;}
    break;

  case 517:
#line 6697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      ;}
    break;

  case 518:
#line 6707 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      Returns the image corresponding to the pointwise maximum between 2 images.


      See Also:
              min, median
        **/
    InrImage* im1;
    InrImage* im2;
        float val1,val2;

    im2 = driver.im_stack.GetLastImage();
    im1 = driver.im_stack.GetLastImage();
    im1->InitBuffer();
    im2->InitBuffer();
    Repeter
          val1 = im1->ValeurBuffer();
      val2 = im2->ValeurBuffer();
      Si val2>val1 AlorsFait im1->FixeValeur(val2);
      im2->IncBuffer();
    JusquA Non(im1->IncBuffer())
    FinRepeter
    driver.im_stack.AddImage(im1);
    delete im2;

      ;}
    break;

  case 519:
#line 6737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              NULL,
              NULL,
              (yysemantic_stack_[(6) - (5)].astring));
    Si res==NULL Alors
      driver.err_print("OpImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
    delete [] (yysemantic_stack_[(6) - (3)].variable);

      ;}
    break;

  case 520:
#line 6755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
              NULL,
              NULL,
              (yysemantic_stack_[(8) - (5)].astring),
              (WORDTYPE) (yysemantic_stack_[(8) - (7)].aint));
    Si res==NULL Alors
      driver.err_print("OpImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);

    delete [] (yysemantic_stack_[(8) - (5)].astring);

      ;}
    break;

  case 521:
#line 6775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
              ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
              NULL,
              (yysemantic_stack_[(8) - (7)].astring));
    Si res==NULL Alors
      driver.err_print("OpImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);

    delete [] (yysemantic_stack_[(8) - (7)].astring);
      ;}
    break;

  case 522:
#line 6793 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
              ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
              NULL,
              (yysemantic_stack_[(10) - (7)].astring),
              (yysemantic_stack_[(10) - (9)].aint));
    Si res==NULL Alors
      driver.err_print("OpImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);

    delete [] (yysemantic_stack_[(10) - (7)].astring);

      ;}
    break;

  case 523:
#line 6813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_OpImage(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
              (yysemantic_stack_[(10) - (9)].astring));
        Si res==NULL Alors
          driver.err_print("OpImage() erreur ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
        FinSi
        driver.im_stack.AddImage(res);

        delete [] (yysemantic_stack_[(10) - (9)].astring);
      ;}
    break;

  case 524:
#line 6832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_OpImage(
            ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable)->Pointer())->get(),
              (yysemantic_stack_[(12) - (9)].astring),
              (yysemantic_stack_[(12) - (11)].aint));
        Si res==NULL Alors
          driver.err_print("OpImage() erreur ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
        FinSi
        driver.im_stack.AddImage(res);
        delete [] (yysemantic_stack_[(12) - (9)].astring);
      ;}
    break;

  case 525:
#line 6853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters
          #1 expr_image: input image for the filter
          #2 expr:     standard deviation of the Gaussian kernel
          #3 expr:     derivation order in X coordinates
          #4 expr:     derivation order in Y coordinates
          #5 expr:     derivation order in Z coordinates

        description:
        Apply a Gaussian filter of specified standard deviation to
        input image and returns a new image.

        Example(s):
        - Convolution with a Gaussian kernel:
        i = Image(FLOAT,10,10,10)
        j = filter(i,1,0,0,0)

     **/
        InrImage*  res;
        InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_Filter( im,
                  (yysemantic_stack_[(12) - (5)].adouble),
                  (int) (yysemantic_stack_[(12) - (7)].adouble),
                  (int) (yysemantic_stack_[(12) - (9)].adouble),
                  (int) (yysemantic_stack_[(12) - (11)].adouble));

        Si res==NULL Alors
          driver.err_print("Filter() erreur ... \n");
          res=im;
        Sinon
          delete im;
        FinSi
        driver.im_stack.AddImage(res);
      ;}
    break;

  case 526:
#line 6890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        float var           = (yysemantic_stack_[(10) - (7)].adouble);
        float lowthreshold  = (yysemantic_stack_[(10) - (9)].adouble);
        //float highthreshold = $11;
            res = Func_itkCannyEdgeDetector(  ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(), var, lowthreshold);
        Si res==NULL Alors
          driver.err_print("itk.CannyEdgeDetector() error ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get();
        FinSi

        driver.im_stack.AddImage(res);
      ;}
    break;

  case 527:
#line 6905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_vtkDist( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

        Si res==NULL Alors
          driver.err_print("vtkDist() erreur ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
        FinSi

        driver.im_stack.AddImage(res);
      ;}
    break;

  case 528:
#line 6919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_vtkMedianFilter3D(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        Si res==NULL Alors
          driver.err_print("vtkMedian3D() erreur ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
        FinSi

        driver.im_stack.AddImage(res);
      ;}
    break;

  case 529:
#line 6935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
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
          driver.im_stack.AddImage(res);
        FinSi
*/
      ;}
    break;

  case 530:
#line 6958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_2DFlux( driver.im_stack.GetLastImage(),(yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      driver.err_print("2DFlux() error ... \n");
      res=NULL;
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 531:
#line 6972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OutFlux( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      driver.err_print("OutFlux() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 532:
#line 6986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OutFluxScalar( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 533:
#line 7000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OrientationRatio2D( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      driver.err_print("OrientationRatio() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 534:
#line 7014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage*  res;

    res = Func_Thinning( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(12) - (7)].adouble),
                 (yysemantic_stack_[(12) - (9)].adouble),
                 (yysemantic_stack_[(12) - (11)].adouble));

    Si res==NULL Alors
      driver.err_print("Skeleton() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 535:
#line 7049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SimplePoints( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );

    Si res==NULL Alors
      driver.err_print("SimplePoints() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 536:
#line 7064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_CircleIntegration(
          ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable) ->Pointer())->get(), // gradient
          ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable) ->Pointer())->get(),  // first  vector
          ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable) ->Pointer())->get(),  // second vector
          (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
          CIRCLE_RESPONSE_MEAN,          // integration type
          ((InrImage::ptr*) (yysemantic_stack_[(12) - (11)].variable)->Pointer())->get()); // mask

        Si res==NULL Alors
          driver.err_print("CircleInt() error ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
        FinSi

        driver.im_stack.AddImage(res);
      ;}
    break;

  case 537:
#line 7085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_CircleIntegration(
        ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable) ->Pointer())->get(),  // gradient
        ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable) ->Pointer())->get(),  // first  vector
        ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable) ->Pointer())->get(),  // second vector
        (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
        CIRCLE_RESPONSE_MEAN,        // integration type
        ((InrImage::ptr*) (yysemantic_stack_[(12) - (11)].variable)->Pointer())->get()); // mask

      Si res==NULL Alors
        driver.err_print("CircleInt() error ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
      ;}
    break;

  case 538:
#line 7106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage*  res;

        res = Func_CircleIntSdExc(
          ((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable) ->Pointer())->get(),  // gradient
          ((InrImage::ptr*) (yysemantic_stack_[(16) - (5)].variable) ->Pointer())->get(),  // first  vector
          ((InrImage::ptr*) (yysemantic_stack_[(16) - (7)].variable) ->Pointer())->get(),  // second vector
          (float)     (yysemantic_stack_[(16) - (9)].adouble),              // radius
          ((InrImage::ptr*) (yysemantic_stack_[(16) - (11)].variable)->Pointer())->get(),
          (float) (yysemantic_stack_[(16) - (13)].adouble),
          (float) (yysemantic_stack_[(16) - (15)].adouble),
          2, // pairs mode MEAN
          100, // keeps all points
          CIRCLE_RESPONSE_MEAN);

        Si res==NULL Alors
          driver.err_print("CircleIntSdExc() error ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get();
        FinSi

        driver.im_stack.AddImage(res);
      ;}
    break;

  case 539:
#line 7147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage*  res;

      res = Func_CircleIntSdExc(
        ((InrImage::ptr*) (yysemantic_stack_[(20) - (3)].variable) ->Pointer())->get(),  // gradient
        ((InrImage::ptr*) (yysemantic_stack_[(20) - (5)].variable) ->Pointer())->get(),  // first  vector
        ((InrImage::ptr*) (yysemantic_stack_[(20) - (7)].variable) ->Pointer())->get(),  // second vector
        (float)     (yysemantic_stack_[(20) - (9)].adouble),              // radius
        ((InrImage::ptr*) (yysemantic_stack_[(20) - (11)].variable)->Pointer())->get(),
        (float) (yysemantic_stack_[(20) - (13)].adouble),
        (float) (yysemantic_stack_[(20) - (15)].adouble),
        (int) (yysemantic_stack_[(20) - (17)].adouble),
        (int) (yysemantic_stack_[(20) - (19)].adouble),
        CIRCLE_RESPONSE_MEAN);

      Si res==NULL Alors
        driver.err_print("CircleIntSdExc() error ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(20) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
      ;}
    break;

  case 540:
#line 7192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_LocalExtrema( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),  // input image
                 ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),  // first  vector
                 ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),  // second vector
                 ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get()); // mask

    Si res==NULL Alors
      driver.err_print("LocalExtrema() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 541:
#line 7209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    int samples = (int) (yysemantic_stack_[(12) - (11)].adouble);

    res = Func_LocalExtrema( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),  // input image
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),  // first  vector
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable)->Pointer())->get(),  // second vector
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (9)].variable)->Pointer())->get(),  // mask
                 samples);                   // number of sample points around the circle

    Si res==NULL Alors
      driver.err_print("LocalExtrema() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 542:
#line 7228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_NormalSmoothField( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );

    Si res==NULL Alors
      driver.err_print("NormalField() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 543:
#line 7242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_NormalSmoothField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    Si res==NULL Alors
      driver.err_print("NormalField() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 544:
#line 7256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DirConnectivity( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    Si res==NULL Alors
      driver.err_print("DirConnectivity() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 545:
#line 7272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage();

    res = Func_NormGrad( input, (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      driver.err_print("Filter() error ... \n");
      res=input;
    Sinon
      delete input;
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 546:
#line 7290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DiscNormGrad( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      driver.err_print("discnormgrad() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 547:
#line 7305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DiscMeanCurvature( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 548:
#line 7321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_Gradient( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      driver.err_print("Filter() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 549:
#line 7336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
        Parameters:
            (3) input image.

        Description:
        Computes a discrete laplacian (sum of second order derivatives),
        in 2D or 3D depending on the image dimension.
    **/
    InrImage*  res;

    res = Func_Laplacian(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
    Si res==NULL Alors
      driver.err_print("Filter() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
        ;}
    break;

  case 550:
#line 7359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SecDerGrad( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SecDerGrad() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 551:
#line 7376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SecDerGrad2( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 552:
#line 7390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
      ;}
    break;

  case 553:
#line 7402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    ImageExtent* extent = (ImageExtent*) (yysemantic_stack_[(4) - (3)].imageextent);

    //  extent->print();
    extent->SetRelative(((InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get());

    //  extent->print();

    res = Func_SubImage( ((InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),
                 (int)  round(extent->Xmin()),
                 (int)  round(extent->Ymin()),
                 (int)  round(extent->Zmin()),
                 (int)  round(extent->Xmax()),
                 (int)  round(extent->Ymax()),
                 (int)  round(extent->Zmax())
                );
    delete extent;

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res= ((InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 554:
#line 7433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr  im = *(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
    InrImage*  res;

    res = Func_SubImage( im.get(),
                 0, 0,  (int) round((yysemantic_stack_[(10) - (7)].adouble)),
                 im->DimX()-1,  im->DimY()-1, (int) round((yysemantic_stack_[(10) - (9)].adouble)));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 555:
#line 7453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      Example:

      - Extract a subimage of size 4x4x4

      i = Image(FLOAT,10,10,10)
      j = subimage(i,5,5,5,8,8,8)

      Others:
        putimage, []

      **/
    InrImage*  res;

    res = Func_SubImage( ((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get(),
                 (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble),
                 (int) (yysemantic_stack_[(16) - (11)].adouble),(int) (yysemantic_stack_[(16) - (13)].adouble),(int) (yysemantic_stack_[(16) - (15)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 556:
#line 7495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_dilate( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      ;}
    break;

  case 557:
#line 7507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_dilate( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      ;}
    break;

  case 558:
#line 7518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    res = Func_EDP_dilate( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax);
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      ;}
    break;

  case 559:
#line 7531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_erode( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                  (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      ;}
    break;

  case 560:
#line 7543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_erode( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      ;}
    break;

  case 561:
#line 7554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage*  res;
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    res = Func_EDP_erode( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax);
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      ;}
    break;

  case 562:
#line 7582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage*  res;

    res = Func_EDP_open( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                    (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 563:
#line 7609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage*  res;
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

    res = Func_EDP_open( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                    (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax);

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 564:
#line 7641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_EDP_close( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 565:
#line 7657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

    res = Func_EDP_close( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax);

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 566:
#line 7674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 567:
#line 7687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 568:
#line 7700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
    // 1. input image
    // 2. isosurface threshold on the input image

    InrImage*  res;

    res = Func_LevelSets_Init( ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (7)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 569:
#line 7720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
    // 1. input image
    // 2. Initial position of the level set a the zero-crossing of
    //    this image

    InrImage*  res;

    res = Func_LevelSets_Init(
           ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
           ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get()
                   );

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
    ;}
    break;

  case 570:
#line 7743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 571:
#line 7757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetAttachVectors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

    Si res==NULL Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 572:
#line 7774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (1) input image
        (2) sigma: standard deviation of the Gaussian smoothing applied to compute the local structure orientations.
        (3) k: diffusion parameter that controls the diffusion depending on the local gradients.
        (4) beta: data attachment coefficient.
        (5) number of iterations
      Description: 
        Runs an anisotropic diffusion filter using Gauss-Seidel numerical scheme, based on the Flux-diffusion algorithm [Krissian,IEEE TMI 2002].
      **/
      int        nb_iter,i;
      float       error;

      Func_InitAnisoGS( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                  (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));

          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereAnisoGS();
      FinPour

      driver.im_stack.AddImage(Func_AnisoGS_GetOutput());

      Func_EndAnisoGS();


    ;}
    break;

  case 573:
#line 7807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //
      // param 1: input image
      // 2: vector field
      // 3: data attachment coeff
      // 4: diffusion coeff
      // 5: number of iterations
      //
      InrImage*  res;
      int        nb_iter,i;
      float       error;

      Func_InitAnisoGS( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                  1,  1, (yysemantic_stack_[(12) - (7)].adouble));


          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereFlux(((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(12) - (9)].adouble));
      FinPour

          res = Func_AnisoGS_GetOutput();
      Si res==NULL Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      Func_EndAnisoGS();

      driver.im_stack.AddImage(res);

    ;}
    break;

  case 574:
#line 7845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr  in      = *(InrImage::ptr*) (yysemantic_stack_[(14) - (3)].variable)->Pointer();
      float      sigma   = (yysemantic_stack_[(14) - (5)].adouble);
      float      k       = (yysemantic_stack_[(14) - (7)].adouble);
      float      beta    = (yysemantic_stack_[(14) - (9)].adouble);
      int        nb_iter    = (int) (yysemantic_stack_[(14) - (11)].adouble);
      int        nb_threads = (int) (yysemantic_stack_[(14) - (13)].adouble);

          InrImage*  res = Func_vtkAnisoGS(  in.get(), sigma, k, beta, nb_iter, nb_threads);

      Si res==NULL Alors
        fprintf(stderr,"Func_vtkAnisoGS() erreur ... \n");
      FinSi

          //      printf("5 \n");
      driver.im_stack.AddImage(res);

    ;}
    break;

  case 575:
#line 7880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      int        nb_iter,i;
      float       error;

      Func_InitAnisoGS( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                  (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));


          Func_SetSmoothedParam(1);

          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereAnisoGS();
      FinPour

          res = Func_AnisoGS_GetOutput();
      Si res==NULL Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      Func_EndAnisoGS();

      driver.im_stack.AddImage(res);

    ;}
    break;

  case 576:
#line 7913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_InitWeickert( ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),
                (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble));

      Si res==NULL Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 577:
#line 7930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_InitWeickertCoherence( ((InrImage::ptr*) (yysemantic_stack_[(16) - (5)].variable)->Pointer())->get(),
                (yysemantic_stack_[(16) - (7)].adouble),  (yysemantic_stack_[(16) - (9)].adouble), (yysemantic_stack_[(16) - (11)].adouble), (yysemantic_stack_[(16) - (13)].adouble), (yysemantic_stack_[(16) - (15)].adouble));

      Si res==NULL Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(16) - (5)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 578:
#line 7945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_SRAD_qcoeff( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

      Si res==NULL Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 579:
#line 7961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(8) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_SRAD( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),dt,numit,
               0, // Lee mode
               0,  // Yu neighborhood
               NULL); // no extent

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 580:
#line 7981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent* extent = (ImageExtent*) (yysemantic_stack_[(10) - (9)].imageextent);

      res = Func_SRAD( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),dt,numit,
               0, // Lee mode
               0, // Yu neighborhood
               extent);

      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 581:
#line 8004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent* extent = (ImageExtent*) (yysemantic_stack_[(12) - (11)].imageextent);

      res = Func_SRAD( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),dt,numit,
               0, // Lee mode
               neighborhood,
               extent);

      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 582:
#line 8028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent* extent = (ImageExtent*) (yysemantic_stack_[(10) - (9)].imageextent);


      res = Func_SRAD2( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),dt,numit,
                0, // Lee function
                0, // Yu neighborhood
                extent
                );

      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 583:
#line 8054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent* extent = (ImageExtent*) (yysemantic_stack_[(12) - (11)].imageextent);

      res = Func_SRAD2( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),dt,numit,
                0, // Lee function
                neighborhood, // neighborhood size
                extent // bounding box
                );
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 584:
#line 8077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent* extent = (ImageExtent*) (yysemantic_stack_[(10) - (9)].imageextent);

      res = Func_SRAD2( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),dt,numit,
                2, // Additive mode
                0, // Yu neighborhood
                extent // constant region
                );
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 585:
#line 8099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt         = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit        = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent* extent = (ImageExtent*) (yysemantic_stack_[(12) - (11)].imageextent);

      res = Func_SRAD( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),dt,numit,
               1, // Kuan's function
               neighborhood, // Yu neighborhood
               extent);
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 586:
#line 8122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent* extent = (ImageExtent*) (yysemantic_stack_[(12) - (11)].imageextent);

      res = Func_SRAD2( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),dt,numit,
                1, // Kuan's function
                neighborhood, // Yu neighborhood
                extent
                );
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 587:
#line 8146 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            InrImage*  res;
            int mode = (int) (yysemantic_stack_[(14) - (5)].adouble);
            float dt = (float) (yysemantic_stack_[(14) - (7)].adouble);
            int numit = (int) (yysemantic_stack_[(14) - (9)].adouble);
            int neighborhood = (int) (yysemantic_stack_[(14) - (11)].adouble);
            ImageExtent* extent = (ImageExtent*) (yysemantic_stack_[(14) - (13)].imageextent);

            res = Func_SRAD2( ((InrImage::ptr*) (yysemantic_stack_[(14) - (3)].variable)->Pointer())->get(),dt,numit,
                        mode, // fiter mode
                        neighborhood, //  neighborhood size
                        extent
                        );
            delete extent;

            Si res==NULL Alors
                fprintf(stderr,"Func_AnisoNRAD() erreur ... \n");
                res=((InrImage::ptr*) (yysemantic_stack_[(14) - (3)].variable)->Pointer())->get();
            FinSi

            driver.im_stack.AddImage(res);
        ;}
    break;

  case 588:
#line 8190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr  initim = *(InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer();
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int attach = (int) (yysemantic_stack_[(12) - (9)].adouble);
      int scheme = (int) (yysemantic_stack_[(12) - (11)].adouble);

      if (initim->DimZ()==1)
        res = Func_RudinMultiplicative2D( initim.get(),dt,numit,attach, scheme);
      else
        res = Func_RudinMultiplicative3D( initim.get(),dt,numit,attach, scheme);

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoRudinMult() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 589:
#line 8214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Add Gaussian noise with specified mean and variance.
      **/

        AjouteBruit* addnoise;
        InrImage*    res;
        InrImage::ptr    in = *(InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
        float mean;
        float sd;
        char  resname[256];

      mean = (yysemantic_stack_[(8) - (5)].adouble);
      sd   = (yysemantic_stack_[(8) - (7)].adouble);

      sprintf(resname,"%s.noise",in->Nom());
      res = new InrImage(WT_FLOAT, resname, in.get());

      (*res)=(*in);

      addnoise = new AjouteBruit();
      addnoise->AjouteBruitGaussien(res,mean,sd);
      delete addnoise;

      driver.im_stack.AddImage(res);

    ;}
    break;

  case 590:
#line 8245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

        InrImage*    res;

          res = Func_rot2D( ((InrImage::ptr*) (yysemantic_stack_[(14) - (3)].variable)->Pointer())->get(),
                (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble),   // rotation center
                (yysemantic_stack_[(14) - (9)].adouble),       // angle of rotation
                (yysemantic_stack_[(14) - (11)].adouble), (yysemantic_stack_[(14) - (13)].adouble)  // dimension of the new image
                );

      driver.im_stack.AddImage(res);
        ;}
    break;

  case 591:
#line 8258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        Others:
                Ypos, Zpos
       **/

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(x);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        driver.im_stack.AddImage(res);
        ;}
    break;

  case 592:
#line 8295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        Others:
                Xpos, Zpos
       **/

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(y);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        driver.im_stack.AddImage(res);
        ;}
    break;

  case 593:
#line 8332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        Others:
                Xpos, Ypos
       **/

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(z);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        driver.im_stack.AddImage(res);
        ;}
    break;

  case 594:
#line 8369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new FLOAT vectorial image that contains
        the coordinates of the voxels (/pixels) of the given image.
        The coordinates are given in Real Coordinates (world),
        and are saved as vectors.


        Others:
                Xpos, Ypos, Zpos
       **/

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_FLOAT,3,
                   "tmp_spacepos.inr.gz",
                   ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
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

        driver.im_stack.AddImage(res);
        ;}
    break;

  case 595:
#line 8404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        ;}
    break;

  case 596:
#line 8409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    ;}
    break;

  case 597:
#line 8418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    ;}
    break;

  case 598:
#line 8423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    ;}
    break;

  case 599:
#line 8434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    ;}
    break;

  case 600:
#line 8444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    ;}
    break;

  case 601:
#line 8454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    ;}
    break;

  case 602:
#line 8463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization
      (7) maximal time
    Description:
      Runs the fast marching algorithm
     **/

        InrImage*    init = (InrImage*) driver.im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
            float   maxtime = (float) (yysemantic_stack_[(8) - (7)].adouble);

          res = Func_vtkFastMarching( input, init,  maxtime);

          driver.im_stack.AddImage(res);
    ;}
    break;

  case 603:
#line 8486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) driver.im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   maxtime = (float) (yysemantic_stack_[(14) - (7)].adouble);

        res = Func_vtkFastMarchingTarget( input, init,  maxtime,
                (int) round((yysemantic_stack_[(14) - (9)].adouble)),
                (int) round((yysemantic_stack_[(14) - (11)].adouble)),
                (int) round((yysemantic_stack_[(14) - (13)].adouble))
                );

        driver.im_stack.AddImage(res);
    ;}
    break;

  case 604:
#line 8515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) driver.im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   mean    = (float) (yysemantic_stack_[(12) - (7)].adouble);
        float   sd      = (float) (yysemantic_stack_[(12) - (9)].adouble);
        float   maxtime = (float) (yysemantic_stack_[(12) - (11)].adouble);

          res = Func_vtkFastMarching( input, init, mean, sd, maxtime);

          driver.im_stack.AddImage(res);
          delete init;
          delete input;
    ;}
    break;

  case 605:
#line 8543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) driver.im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   mean     = (float) (yysemantic_stack_[(14) - (7)].adouble);
        float   sd       = (float) (yysemantic_stack_[(14) - (9)].adouble);
        float   maxtime  = (float) (yysemantic_stack_[(14) - (11)].adouble);
        int     inittype = (int) (yysemantic_stack_[(14) - (13)].adouble);

      res = Func_vtkFastMarching( input, init, mean, sd, maxtime,inittype);

          driver.im_stack.AddImage(res);
          delete init;
          delete input;
    ;}
    break;

  case 606:
#line 8576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) driver.im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage(); // 1st param
        InrImage*    res   = NULL;
        float   maxtime    = (float) (yysemantic_stack_[(12) - (9)].adouble);
        int     inittype   = (int)   (yysemantic_stack_[(12) - (11)].adouble);

      res = Func_vtkFastMarching(
                  input,
                  init,
                  ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable)->Pointer())->get(),
                  maxtime,inittype);

      driver.im_stack.AddImage(res);
      delete init;
      delete input;
    ;}
    break;

  case 607:
#line 8608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 608:
#line 8619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
;

      res = Func_ConvolveMask(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                  mask);

          driver.im_stack.AddImage(res);
      delete mask;

        ;}
    break;

  case 609:
#line 8635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 610:
#line 8645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 611:
#line 8655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float a = (yysemantic_stack_[(12) - (5)].adouble);
        float b = (yysemantic_stack_[(12) - (7)].adouble);
        float c = (yysemantic_stack_[(12) - (9)].adouble);
        float dmax = (yysemantic_stack_[(12) - (11)].adouble);

          res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(), a,b,c,dmax);

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 612:
#line 8670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 613:
#line 8684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 614:
#line 8698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 615:
#line 8711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 616:
#line 8724 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        ;}
    break;

  case 617:
#line 8736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        ;}
    break;

  case 618:
#line 8748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        ;}
    break;

  case 619:
#line 8760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        ;}
    break;

  case 620:
#line 8771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        ;}
    break;

  case 621:
#line 8784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            InrImage* res;
        float threshold = (yysemantic_stack_[(10) - (5)].adouble);
        float dmin      = (yysemantic_stack_[(10) - (7)].adouble);
        float dmax      = (yysemantic_stack_[(10) - (9)].adouble);

        printf("threshold = %f \n",threshold);
      res = Func_vtkPropDaniel2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                    threshold,dmin,dmax);

          driver.im_stack.AddImage(res);
        ;}
    break;

  case 622:
#line 8811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        Example:
            To analyze connected component from an isocontour value n for an image i,
            you can call i_cc=CC((FLOAT)i-n)
        **/
       InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
           InrImage* res;

      res = Func_CC(im);

          driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 623:
#line 8844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     /**
       Parameters:
         (1) image1: image variable
         (3) image2: image expression

       Description:
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
      // image composition
      // Initialy for applying a RGB colormap to an image
      InrImage::ptr im1;
      InrImage* im2 = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      int pos;

      im1 = *(InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer();

      res = new InrImage(im1->_format,"ImComp.ami.gz",im2);

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
          pos = (int) im2->ValeurBuffer();
          Si (pos<0) AlorsFait pos = 0;
          Si (pos>=im1->DimX()) AlorsFait pos = im1->DimX()-1;
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

          driver.im_stack.AddImage(res);
      delete im2;
        ;}
    break;

  case 624:
#line 8952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      InrImage* res;

      res = Func_Histogram(im,vmin,vmax,nint);
      driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 625:
#line 8976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      int* numpts;
      int  n;
      InrImage* res;
      float v;
      double total = 0;

      res = new InrImage(nint,1,1,WT_SIGNED_INT);

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

      driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 626:
#line 9018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;

      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      if (im->DimZ()>1)
        res = Func_MeanHalfSize(im,3);
      else
        res = Func_MeanHalfSize(im,2);

      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 627:
#line 9031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      res = Func_MeanHalfSize(im,dim);

      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 628:
#line 9042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            InrImage* res;
            int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

            InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
            res=Func_Flip(im,axis);
            driver.im_stack.AddImage(res);
        ;}
    break;

  case 629:
#line 9051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            InrImage* res;
            int sx = (int) (yysemantic_stack_[(12) - (5)].adouble);
            int sy = (int) (yysemantic_stack_[(12) - (7)].adouble);
            int sz = (int) (yysemantic_stack_[(12) - (9)].adouble);
            unsigned char interpolate=(unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

            InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
            res = Func_Resize(im,sx,sy,sz,interpolate);

            if (res!=NULL) driver.im_stack.AddImage(res);
            delete im;
        ;}
    break;

  case 630:
#line 9075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
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

      InrImage::ptr im1 = *(InrImage::ptr*) (yysemantic_stack_[(30) - (3)].variable)->Pointer();
      InrImage::ptr im2 = *(InrImage::ptr*) (yysemantic_stack_[(30) - (5)].variable)->Pointer();

      res = Func_ReSlice(im1.get(),im2.get(),m);

      if (res!=NULL) driver.im_stack.AddImage(res);

        ;}
    break;

  case 631:
#line 9100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage* input=(InrImage*) driver.im_stack.GetLastImage();

      res = Func_vtkConvexHull(input,
                   order,resolution);

      if (res!=NULL) driver.im_stack.AddImage(res);
      delete input;
        ;}
    break;

  case 632:
#line 9113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        ;}
    break;

  case 633:
#line 9123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesExtremities(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        ;}
    break;

  case 634:
#line 9133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageConnections(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        ;}
    break;

  case 635:
#line 9143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        ;}
    break;

  case 636:
#line 9153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
        ;}
    break;

  case 637:
#line 9163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 638:
#line 9171 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 639:
#line 9179 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 640:
#line 9187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**

        description:
          Compute the altitude to the sea level based on the
          infrared channel.

        parameters:
          (3) image containing the infrared channel
          (5) image containing 5 coefficients for the computation
              of the temperature and of the altitude,

        keywords:
          Fluid

        **/
      InrImage* coeff =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* input =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input,coeff);
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete coeff;
      delete input;
        ;}
    break;

  case 641:
#line 9214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**

        description:
        Compute the altitude to the sea level based on the
        temperature channel.

        params:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      InrImage* input =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Temp2Altitudes(input);
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete input;
        ;}
    break;

  case 642:
#line 9235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    ;}
    break;

  case 643:
#line 9243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**

        description:
    Trying the slicing procedure to incorporate into the
    image drawing class

        params:
        (3) image to slice
        (5) width orientation 1,2,3 for XY, XZ, ZY
        (7) height orientation
        (9,11,13) cursor position
        (15) expected width
        (17) expected height

        **/
        InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
        InrImage* res;

        if (im->_format==WT_UNSIGNED_CHAR) {
          ImageDraw<unsigned char> imdraw;
      imdraw.SetInput((unsigned char*)im->GetData(),im->DimX(),im->DimY(),im->DimZ());
      imdraw.SetVoxelSize(im->VoxSizeX(),im->VoxSizeY(),im->VoxSizeZ());
          imdraw.SetCursorPosition((int)(yysemantic_stack_[(18) - (9)].adouble),(int)(yysemantic_stack_[(18) - (11)].adouble),(int)(yysemantic_stack_[(18) - (13)].adouble));
          imdraw.Apply((int)(yysemantic_stack_[(18) - (5)].adouble),(int)(yysemantic_stack_[(18) - (7)].adouble),(int)(yysemantic_stack_[(18) - (15)].adouble),(int)(yysemantic_stack_[(18) - (17)].adouble));
          // copy to RGB image
          res = new InrImage(imdraw.RGB_width, imdraw.RGB_height, 1, WT_RGB);
          memcpy(res->GetData(),imdraw.RGB_image,imdraw.RGB_width*imdraw.RGB_height*3);
      driver.im_stack.AddImage(res);

        } else
     fprintf(stderr,"only UCHAR format for now \n");

        delete im;

        ;}
    break;

  case 644:
#line 9281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage*         res;

      SurfacePoly::ptr  surf = *(SurfacePoly::ptr*)
                                  (yysemantic_stack_[(8) - (3)].variable)->Pointer();
      InrImage::ptr ref = *(InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
      InrImage::ptr rad = InrImage::ptr(
                                driver.im_stack.GetLastImage());

      res = LineRecons( surf.get(), ref.get(), rad.get());
      driver.im_stack.AddImage(res);
    ;}
    break;

  case 645:
#line 9304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input line read with ReadCTALine
      (5) name of the file
    Description:
      Reads the radius information and save it to an image,
      returns this image.
    **/
      InrImage*         res;

      SurfacePoly::ptr  surf = *(SurfacePoly::ptr*)
                                  (yysemantic_stack_[(6) - (3)].variable)->Pointer();

      res = Func_ReadCTALineRadii( surf.get(), (yysemantic_stack_[(6) - (5)].astring));
      driver.im_stack.AddImage(res);
    ;}
    break;

  case 651:
#line 9329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               ;}
    break;

  case 653:
#line 9331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             ;}
    break;

  case 654:
#line 9332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             ;}
    break;

  case 655:
#line 9333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            ;}
    break;

  case 656:
#line 9334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            ;}
    break;

  case 657:
#line 9335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           ;}
    break;

  case 658:
#line 9336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           ;}
    break;

  case 659:
#line 9337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             ;}
    break;

  case 660:
#line 9338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            ;}
    break;

  case 661:
#line 9339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            ;}
    break;

  case 662:
#line 9340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            ;}
    break;

  case 663:
#line 9341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             ;}
    break;

  case 664:
#line 9342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) ;}
    break;

  case 665:
#line 9343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             ;}
    break;

  case 666:
#line 9345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* im1;
          InrImage* res;

          im1 = driver.im_stack.GetLastImage();
          res = Norm(*im1);
          if (res!=NULL)
            driver.im_stack.AddImage(res);
          else
            fprintf(stderr,"Error computing the norm |image| \n");
          delete im1;
        ;}
    break;

  case 668:
#line 9362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
                  The image conversion is done using the cast operator
                  where basic_type can be one of the basic type accepted,
                  currently:
                  CHAR UCHAR SHORT USHORT FLOAT DOUBLE RGB FLOAT_VECTOR


                Example:
                  i = Image(FLOAT,10,10,10)
                  j = (RGB) i
        **/
            InrImage* im1;
            InrImage* im;
            im1 = driver.im_stack.GetLastImage();
            im  = new InrImage( (WORDTYPE) (yysemantic_stack_[(4) - (2)].aint), "tmp.inr.gz", im1);
            (*im) = (*im1);
            driver.im_stack.AddImage(im);
            delete im1;
          ;}
    break;

  case 670:
#line 9386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 671:
#line 9392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 672:
#line 9394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   ;}
    break;

  case 673:
#line 9395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   ;}
    break;

  case 674:
#line 9396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   ;}
    break;

  case 677:
#line 9405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 678:
#line 9406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 679:
#line 9407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   ;}
    break;

  case 680:
#line 9408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   ;}
    break;

  case 683:
#line 9416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    ;}
    break;

  case 684:
#line 9417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    ;}
    break;

  case 685:
#line 9418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   ;}
    break;

  case 686:
#line 9419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   ;}
    break;

  case 687:
#line 9420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 688:
#line 9421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 689:
#line 9422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 690:
#line 9423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 692:
#line 9428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   ;}
    break;

  case 693:
#line 9429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   ;}
    break;

  case 694:
#line 9430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   ;}
    break;

  case 695:
#line 9431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   ;}
    break;

  case 710:
#line 9473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           ;}
    break;

  case 711:
#line 9484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix glt;
         GLTransfMatrix* newglt;

         printf("GetTransform begin \n");
         newglt = new GLTransfMatrix();
             glt = (*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetObjectTransform();
         (*newglt) = (glt);
         driver.gltransf_stack.AddMatrix(newglt);
         printf("GetTransform \n");
           ;}
    break;

  case 712:
#line 9497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       ;}
    break;

  case 713:
#line 9508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         newglt = Func_ReadTransform((yysemantic_stack_[(4) - (3)].astring));
         if (newglt!=NULL)
           driver.gltransf_stack.AddMatrix(newglt);
         else {
           fprintf(stderr,"TRANSFORM() Error reading file ...\n");
           driver.err_print("TRANSFORM() Error reading file ...\n");
           driver.gltransf_stack.AddMatrix(NULL);
           //          yyiperror(
           //          YYABORT;
         }
         delete [] (yysemantic_stack_[(4) - (3)].astring);
           ;}
    break;

  case 714:
#line 9525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       ;}
    break;

  case 715:
#line 9532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       ;}
    break;

  case 716:
#line 9542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
         Inversion of a symmetric matrix
        **/
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        ;}
    break;

  case 722:
#line 9562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               ;}
    break;

  case 724:
#line 9565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        ;}
    break;

  case 725:
#line 9573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             ;}
    break;

  case 726:
#line 9574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             ;}
    break;

  case 727:
#line 9575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            ;}
    break;

  case 728:
#line 9576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            ;}
    break;

  case 729:
#line 9577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           ;}
    break;

  case 730:
#line 9578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           ;}
    break;

  case 731:
#line 9579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             ;}
    break;

  case 732:
#line 9580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            ;}
    break;

  case 733:
#line 9581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            ;}
    break;

  case 734:
#line 9582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            ;}
    break;

  case 735:
#line 9583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             ;}
    break;

  case 736:
#line 9584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) ;}
    break;

  case 737:
#line 9585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             ;}
    break;

  case 740:
#line 9592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 741:
#line 9593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   ;}
    break;

  case 742:
#line 9595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           ;}
    break;

  case 744:
#line 9605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 745:
#line 9606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 746:
#line 9607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   ;}
    break;

  case 747:
#line 9608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   ;}
    break;

  case 759:
#line 9657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        ;}
    break;

  case 760:
#line 9662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          array = *(VarArray::ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          if (array->GetVar(i).Pointer()==NULL) {
            // initialize the surface
            SurfacePoly* surf = new SurfacePoly();
            char name[256];
            sprintf(name,"%s[%d]",(yysemantic_stack_[(4) - (1)].variable)->Name(),i);
            array->InitElement(i,surf,name);
          }
          (yyval.variable)=&(array->GetVar(i));
        ;}
    break;

  case 761:
#line 9679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
          SurfacePoly* surf;
          surf = Func_isosurf(im,
                  (yysemantic_stack_[(6) - (5)].adouble),
                  NULL);
          Si surf != NULL Alors
            driver.surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 762:
#line 9691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_isosurf((*(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer()),
                  (yysemantic_stack_[(6) - (5)].adouble),
                  NULL,
                  2);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 763:
#line 9703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(8) - (5)].adouble),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
    FinSi
    ;}
    break;

  case 764:
#line 9715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr im   = InrImage::ptr(driver.im_stack.GetLastImage());
      vtkPolyData* vtklines;
      CreeCrest* crestlines;
      SurfacePoly* lines;

      crestlines = Func_IsoLine(im.get(), (yysemantic_stack_[(8) - (5)].adouble), mask.get());
      printf("running conversion to vtkPolyData ...");
      vtklines = (vtkPolyData*) (*crestlines);

      lines = new SurfacePoly(vtklines);
      if (lines != NULL)
        driver.surf_stack.AddSurf(lines);

      //vtklines->Delete();
      delete crestlines;

    ;}
    break;

  case 765:
#line 9748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 766:
#line 9757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 767:
#line 9766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 768:
#line 9775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 769:
#line 9784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 770:
#line 9793 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
        ;}
    break;

  case 771:
#line 9799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
        ;}
    break;

  case 772:
#line 9805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        ;}
    break;

  case 773:
#line 9811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskSurface(name);
          if (!res) {
            driver.yyiperror(" Need Surface \n");
            YYABORT;
          }
          driver.surf_stack.AddSurf((char*)name.c_str());

          wxFileName filename(GetwxStr(name));
          filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
          wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                              filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                              filename.GetPathSeparator(wxPATH_UNIX)+
                              filename.GetFullName());


          inc_cmd = str(format(" \"%1%\"  // from browser ") % newname);
          if (driver.in_console)
            GB_main_wxFrame->GetConsole()->IncCommand(inc_cmd);
        ;}
    break;

  case 774:
#line 9837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3): input filename (text file)
        Description:
            Reads a line given described in a text file
            format used in the CTA coronary segmentation challenge
        **/
          SurfacePoly* surf;
          surf = Func_ReadCTALine((yysemantic_stack_[(4) - (3)].astring));
          driver.surf_stack.AddSurf(surf);
        ;}
    break;

  case 775:
#line 9851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          surf = Func_ReadCTALine((yysemantic_stack_[(6) - (3)].astring), (int) (yysemantic_stack_[(6) - (5)].adouble));
          driver.surf_stack.AddSurf(surf);
        ;}
    break;

  case 776:
#line 9867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
    ;}
    break;

  case 777:
#line 9877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
          SurfacePoly* surf;

      surf = Func_Skeleton2lines( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get()  );

      Si surf==NULL Alors
        driver.err_print("Skeleton2lines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 778:
#line 9895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          SurfacePoly* surf;

      surf = Func_SmoothLines( ((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get(),
                      0.1,
                      0.01,
                      10);

      Si surf==NULL Alors
        driver.err_print("SmoothLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 779:
#line 9923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          SurfacePoly* surf;

      surf = Func_SmoothLines( ((SurfacePoly::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                      (yysemantic_stack_[(10) - (5)].adouble),
                      (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble));

      Si surf==NULL Alors
        driver.err_print("SmoothLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 780:
#line 9950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;

      surf = Func_ResampleLines( ((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     (yysemantic_stack_[(6) - (5)].adouble));

      Si surf==NULL Alors
        driver.err_print("ResampleLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 781:
#line 9966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;

      surf = Func_shortestpath( ((SurfacePoly::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath () error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 782:
#line 9983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = Func_shortestpath_image(  im.get(),(yysemantic_stack_[(18) - (5)].adouble),
                                      (yysemantic_stack_[(18) - (7)].adouble), (yysemantic_stack_[(18) - (9)].adouble), (yysemantic_stack_[(18) - (11)].adouble),
                                      (yysemantic_stack_[(18) - (13)].adouble),(yysemantic_stack_[(18) - (15)].adouble),(yysemantic_stack_[(18) - (17)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath_image () error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 783:
#line 10016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = Func_path_from_displ(  im.get(),
          (int) round((yysemantic_stack_[(10) - (5)].adouble)),
          (int) round((yysemantic_stack_[(10) - (7)].adouble)),
          (int) round((yysemantic_stack_[(10) - (9)].adouble))
          );

      Si surf==NULL Alors
        driver.err_print("Func_path_from_displ() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 784:
#line 10052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      double start[3] = {(yysemantic_stack_[(20) - (9)].adouble),(yysemantic_stack_[(20) - (11)].adouble),(yysemantic_stack_[(20) - (13)].adouble)};
      double end[3] = {(yysemantic_stack_[(20) - (15)].adouble),(yysemantic_stack_[(20) - (17)].adouble),(yysemantic_stack_[(20) - (19)].adouble)};
      surf = Func_path_from_vectfield(  im.get(),
                                        start,end,
                                        (yysemantic_stack_[(20) - (5)].adouble), (yysemantic_stack_[(20) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_path_from_vectfield() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 785:
#line 10094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) input polydata
      (5) maximal distance (square distance between extremities)
      (7) maximal angle (square length of the sum of the
                         normalized extremity vectors)
    Description:
      Connecting close lines
    **/
          SurfacePoly* surf;

      surf = Func_ConnectLines( ((SurfacePoly::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())->get(),
                      (yysemantic_stack_[(8) - (5)].adouble),
                      (yysemantic_stack_[(8) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("ConnectLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi


    ;}
    break;

  case 786:
#line 10120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 787:
#line 10130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**

        description:
      creates a flat triangulates mesh from the image domain,
      discarding pixels with null intensity.

        parameters:
        (3) input image
        (5) triangle orientation:
            1: following X^Y
            other value: following -X^Y

          **/
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 788:
#line 10153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(),minth,maxth);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 789:
#line 10165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);

      surf = AMIFluid::Func_vtkCreateFlatMesh(im,minth,maxth);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
     delete im;
        ;}
    break;

  case 790:
#line 10178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
          CreateVolume creates a close surface composed of 2 surfaces:
          a top and a bottom, where each surface is calculated by converting
          the pixel position of 3D positions based on the 2 last parameters.
          It scans all the points of the 2D image,
          and uses their coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - the 2 last parameters are 2D images of 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        parameters:
        (3) input surface
        (5) minimal intensity value of the region of interest
        (7) maximal intensity value of the region of interest
        (9) 3D vector field image for the lower positions
        (11) 3D vector fiels image for the higher positions

       Others:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      InrImage* highpos = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* lowpos  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* input   = (InrImage*) driver.im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yysemantic_stack_[(12) - (5)].adouble);
      float maxth = (yysemantic_stack_[(12) - (7)].adouble);

      surf = AMIFluid::Func_CreateVolume(input, minth, maxth, lowpos, highpos);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
      delete highpos;
      delete lowpos;
      delete input;
        ;}
    break;

  case 791:
#line 10218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
          CreateVolume creates a close surface composed of 2 surfaces:
          a top and a bottom, where each surface is calculated by converting
          the pixel position of 3D positions based on the 2 last parameters.
          It scans all the points of the 2D image,
          and uses their coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - the 2 last parameters are 2D images of 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        parameters:
        (3) input surface
        (5) minimal intensity value of the region of interest
        (7) maximal intensity value of the region of interest
        (9) 3D vector field image for the lower positions
        (11) 3D vector fiels image for the higher positions
        (13) RGB image to color the top surface or NULL if not used
        (15) alpha opacity value (in [0,1], 0 is fully transparent)


       Others:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      InrImage* colors  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* highpos = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* lowpos  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* input   = (InrImage*) driver.im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yysemantic_stack_[(16) - (5)].adouble);
      float maxth = (yysemantic_stack_[(16) - (7)].adouble);
      float alpha = (yysemantic_stack_[(16) - (15)].adouble);

      surf = AMIFluid::Func_CreateVolume(input, minth, maxth, lowpos, highpos, colors, alpha);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
      delete highpos;
      delete lowpos;
      delete input;
        ;}
    break;

  case 792:
#line 10263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale
          #7 expr:              type

        description:
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


        See Also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/

      InrImage* alt2  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* displ = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) driver.im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      float scale = (yysemantic_stack_[(16) - (13)].adouble);
      int   type  = (int) (yysemantic_stack_[(16) - (15)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale, type);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        ;}
    break;

  case 793:
#line 10313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale
          #7 expr:              type
          expr:                 vector_style (in {0,1})

        description:
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


        See Also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/

      InrImage* alt2  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* displ = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) driver.im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(18) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(18) - (11)].adouble);
      float scale = (yysemantic_stack_[(18) - (13)].adouble);
      int   type   = (int) (yysemantic_stack_[(18) - (15)].adouble);
      int   style  = (int) (yysemantic_stack_[(18) - (17)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale, type,style);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        ;}
    break;

  case 794:
#line 10366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale

        description:
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


        See Also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/
      InrImage* alt2  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* displ = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) driver.im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (11)].adouble);
      float scale = (yysemantic_stack_[(14) - (13)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        ;}
    break;

  case 795:
#line 10412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          (3) expr_image:        displacement field in voxel coordinates
          (5) expr:              spacing between vectors in X direction
          (7) expr:              spacing between vectors in Y direction
          (9) expr:              spacing between vectors in Z direction
          (11) expr:             scale
          (13) vector style   0: simple line, 1: 3D vector composed of 2 tetrahedra

        description:
        Creates a 3D vector field for visualization.

      **/
      InrImage* displ = (InrImage*) driver.im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(14) - (5)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (7)].adouble);
      int stepz   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      float scale = (yysemantic_stack_[(14) - (11)].adouble);
      int style = (int) (yysemantic_stack_[(14) - (13)].adouble);
      SurfacePoly* surf;

       surf = AMIFluid::Func_CreateVectors(displ, stepx, stepy, stepz,  scale, style);
       Si surf != NULL Alors
         driver.surf_stack.AddSurf(surf);
       FinSi
       delete displ;
        ;}
    break;

  case 796:
#line 10441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr v3  = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr v2  = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr v1  = InrImage::ptr(driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      int stepz   = (int) (yysemantic_stack_[(16) - (13)].adouble);
      int res     = (int) (yysemantic_stack_[(16) - (15)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids(v1.get(),
              v2.get(),
              v3.get(),
              stepx,stepy,stepz,res);
        Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 797:
#line 10474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* mask    = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* colors  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* v3      = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* v2      = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* v1      = (InrImage*) driver.im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(20) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(20) - (11)].adouble);
      int stepz   = (int) (yysemantic_stack_[(20) - (13)].adouble);
      int res     = (int) (yysemantic_stack_[(20) - (15)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids(v1,v2,v3,stepx,stepy,stepz,res,colors,mask);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
     delete v1;
     delete v2;
     delete v3;
        ;}
    break;

  case 801:
#line 10521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        ;}
    break;

  case 816:
#line 10543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent* extent=new ImageExtent( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        ;}
    break;

  case 817:
#line 10551 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent* extent=new ImageExtent((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        ;}
    break;

  case 818:
#line 10558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

          ImageExtent* extent=new ImageExtent();
          extent->SetMode(0); // absolute
          extent->SetXmin( im->SpacePosX(0));
          extent->SetXmax( im->SpacePosX(im->DimX()-1));
          extent->SetYmin( im->SpacePosY(0));
          extent->SetYmax( im->SpacePosY(im->DimY()-1));
          extent->SetZmin( im->SpacePosZ(0));
          extent->SetZmax( im->SpacePosZ(im->DimZ()-1));
          extent->print();
          (yyval.imageextent)=extent;
       ;}
    break;

  case 819:
#line 10574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        DessinImage::ptr draw = *(DessinImage::ptr*) ((yysemantic_stack_[(1) - (1)].variable)->Pointer());

        int xmin,xmax;
        int ymin,ymax;
        int zmin,zmax;
        string comment;

        draw->GetZoom(xmin,ymin,zmin,xmax,ymax,zmax);
        ImageExtent* extent=new ImageExtent(xmin,xmax,ymin,ymax,zmin,zmax);
        extent->SetMode(1); // relative extent

        comment = str(format(" //  subvolume [%3d:%3d, %3d:%3d, %3d:%3d] ")
            % xmin % xmax % ymin % ymax % zmin % zmax);
        if (GB_debug) cerr << "********* extent ****" << endl;
        if (driver.in_console) GB_main_wxFrame->GetConsole()->IncCommand(comment);

        (yyval.imageextent)=extent;
       ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 11585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2666;
  const short int
  Parser::yypact_[] =
  {
     12869, -2666, 14845, 14684, 14684,  2152, -2666, -2666, -2666, -2666,
   -2666,    29, -2666, -2666, -2666,    -9,   278, -2666,    15,  2152,
    7428,    87,    20, -2666, -2666, -2666, -2666, -2666,   135,   155,
     167,   -21,    99, -2666,    71,    25,    22,   148,    73,   232,
     236,    32,   245,  1071, -2666, -2666, -2666, -2666,   254,   257,
     261,   250,   269,   348,   405,   298,   297, -2666, -2666, -2666,
     327,   345,   367,   381,   397,   424,   404,   408,   423,   434,
     442,   457,   469,   474,   479,   482,   534,   537,   558, -2666,
     570,   595, -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666,
   -2666, -2666,   655,   669,   728, -2666, -2666, 14684, 14684, 14684,
   14684, 14684, 14684, 14684, 14684, 14684, 14684, 14684, 14684, 14684,
     299, -2666, -2666,  7428,   495,   740,   780,   299,   832,   847,
     898,   914, -2666, -2666, -2666, -2666, -2666,   916,   925, -2666,
     586,  8019, -2666, -2666, -2666, -2666, -2666,   212, -2666, -2666,
     313,    68, -2666, -2666, -2666, 14684, -2666,   281,   386, -2666,
      39,   186,   636,   739,   822,   617,    31, -2666, -2666, -2666,
   -2666,   112, -2666, -2666, -2666, -2666,   833,    18,   395, -2666,
   -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666,
      66,   -12, 14845, 14845,  7428, -2666, -2666, -2666,   943,   950,
     946,   947,   959,   963,   960,   968, 14845, 14845, 14845, 14845,
   14845, 14845, 14845, 14845, 14845, 14845, 14845, 14845, 14845, 14845,
   -2666,   204,   970,   950, -2666,   833, -2666,   833, -2666,   977,
     980,   339,  1000,  7428, -2666, -2666, -2666, -2666, -2666, -2666,
      68, -2666, -2666,    68, -2666,    20, -2666,   996, -2666, -2666,
    7428, -2666, -2666,  7428, -2666, -2666,  7428,    20,   441,   156,
     116,   116,  7428,  2152,   -23,   596,  9664,  9664, -2666,   549,
      -2,  7428,   694,  7428, -2666, -2666, -2666, -2666, -2666, -2666,
   -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666,  1002,   963,
   -2666, -2666,  7428,  7428, 13763,    15, 13763, 13763,    15, 13763,
      15, 13763,    15,   389,   695,   304,   336,    15,    15, 13763,
   13763,    15,    15,    15,    15,    15,    15,    15,    15,   972,
     976,  7428,    15,  7428,  7428,    11,   978, 13763,    15, -2666,
     833, -2666,   833, -2666,   833, -2666,   833, -2666,   833, -2666,
     833, -2666,   833, -2666,   833, -2666,   833, -2666,   833, -2666,
     833, -2666,   833, -2666,   833,   903, -2666,   981, -2666,   212,
     883,   983,  1016,  7428,    20,   979,    15,    15,    15, -2666,
   -2666, -2666, -2666, -2666, -2666, -2666,   212, -2666,    20,    20,
      20,    20, -2666,   833, 14845, 14845, 14845, 14845, 14845, 14845,
   14845, 14845, 14845, 14845,  7428,  7428,  7428,  7428,  7428,  7428,
    7428,  7428,   331, 13763, 10622, -2666, 14684,    11, 14684, 14684,
     705,    52, 13321,  8676,   235,    86,   -11,  7428,  7428,   415,
     878,  7428,   -47,     2, -2666, 15164,   -20, -2666,  1021,  1022,
     998, -2666, -2666, -2666, -2666,  1031,  1032,  1033,  1034,  1035,
    1036, -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666,
    1037,  1043,  1046, -2666,  1048,  1049,  1050,  1051, -2666,  1067,
    1068,  1069,  1070,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1080,  1081,  1082,  1083, -2666,  1086,  1087,  1088,  1089,  1090,
   -2666,  1092, -2666,  1093,  1094,  1095,  1096,  1097, -2666, -2666,
    1064, -2666, -2666,  7428, -2666,  1098,  1099, -2666,  1100, 11506,
   11506, 10622,   219,   120,  1102,  1101,  1103,  1104,   510,  1106,
    1129,  1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,
    1141,  1142,   366,  1143,  1144,  1145,  1146,  1147,  1148,  1149,
    1150,  1151,  1153,  1152,  1154,  1155,  1156,  1160,  1162,  1164,
    1166,  1167,  1169,  1170,  1171,  1173,  1175,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1191,  1195,  1196,  1197,  1206,  1208,  1209,  1210,  1211,
    1212,  1213,  1214,  1215,  1216,  1232,  1233,  1234,  1235,  1236,
    1244,  1245,  1246,  1247,  1250,  1253,  1255,  1256,  1257,  1258,
    1259,  1260, 11506, 11506, 11506, 11506, 11506, 11506, 11506, 11506,
   11506, 11506, 11506, 11506, 11506, 13763,  1261,  1262,  1263,  1264,
    1266,  1267,  1268,  1272,  1273,  1275,  1276,  1280,   385,    68,
   11506, -2666,   237, -2666, -2666, -2666,   992, -2666,   340, -2666,
     699, -2666,    44,   661,  1277, -2666,  1278,  1044,    37, -2666,
   -2666, -2666,  1279,   488,  1282, -2666, -2666, -2666,  1284,  1292,
    1295, -2666, -2666,  1302,  1311,  1314,  1317,  1321,  1322,  1323,
    1324,  1325,  1326, -2666, -2666, -2666, -2666,  1327, -2666,    20,
    1265,  1328,  1331,  7428,  1330,  1329, 13763, 13763, 12390,  1332,
    1335,   521,  1333, 13763, 13763, 13763, 13763, 13763, 13763, 13763,
   13763, 13763, 13763, 13763, 13763, 13763, 13763,   533,  1336,  1334,
    1340,  1339,  1342,  1343,  1344,  1347,  1349,  1348,  1350,  1356,
    1357, -2666, -2666,  1358,  1359, -2666, -2666,  1360,  1361,  1362,
    1363,  1364,  1365,  1366,  1367, -2666,  1368,  1369,  1370,  1371,
    1372,  1373,  1374,  1375,  1376,  1377,  1378,  1379,  1380,  1382,
    1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,
    1394,  1395,  1396,  1397,  1398, -2666, -2666, -2666, -2666, -2666,
   -2666,  1401,  1399,   172,  1400,  1402,  1404,  1405,  1406,  1407,
    1408,  1409,  1410,  1411,  1413,  1414,  1403,  1415,  1416,   110,
    1417,    11,    11,    11, -2666,    11,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,    11,    11,  1424,
    1425,  1420,  1427,  7428, -2666,   -16, -2666, -2666,  1428,  1429,
    1430,   456,  1426,  1431,  1432,  1433,  1434,  1435, -2666, -2666,
   -2666, -2666, -2666, -2666, -2666,   281,   281, -2666, -2666, -2666,
   -2666,    39,    39,   186,   636,   739,   822,    47,   617,   333,
    1440,  1436, -2666,  1437, -2666, -2666,    20, -2666,  1438,  1444,
    1445,  1446,  1447,  1448,  1449,  1450, -2666, -2666, -2666,  1101,
   -2666, -2666, -2666,   833,   833,   281,    18,   281,    18, -2666,
   -2666, -2666,    20,  1451,  1452,    20, -2666,  1453, -2666,  1454,
    1455,  1456,  1457,  1458,  1461,  1462,  1477,  1478,  1479,  1480,
    1481,  1482,  1483,  1484,  1485, -2666,  1486, -2666,  1487, -2666,
   -2666,  1488,  1489,  1490,  1491,  1492, -2666, -2666,  1493,  1494,
    1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,  1503,  1504,
    1505,  1506,  1507,  1508,  1510,   131,  1511,  1512,  1513,  1514,
    1515,  1516, -2666,  1517, -2666, 11064, 11064,  9185,    92,  1518,
    1520,  1521, -2666,  1523,   168,  1524,  1528,  1529,  1530, 11064,
   11064, 11064, 11064, 11064, 11064, 11064, 11064, 11064, 11064, 11064,
   11064, 11064,    68, 11064, -2666, -2666, -2666, -2666,  1525, -2666,
    1531,  1532,   177,  7428, -2666, -2666,  7428,  7428,  7428,  7428,
    7428,  7428,  7428,    15,  7428,  7428,    59,  1114,  1285,  7428,
    7428,  7428,  7428,  7428,  7428,  7428, 13763,  7428,  1353,  7428,
    1351,  7428,  7428,    52,  7428,  7428,  7428,  7428,  7428,   116,
      -5,  1470,  1291,  7428,  7428,  7428,  7428,    68, -2666,    20,
    1509,    20,   511, -2666, -2666, -2666,  1519,  1536, -2666, -2666,
   -2666, -2666,    65, -2666,  7428,   295,   472,  9664, 13763,    15,
   13763, 13763,    15,    15,    15,    15,    15, 13763,    15,    15,
      15,    15,    15,    17,    15,    15,    15,    15,   -14, 13763,
   13763,    15,  1222,  1248,    15,    15,    15,    15,    15,    15,
      15,    15,    15, 13763,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15, 13763, 13763, 13763,
   13763, 13763,    15,    15,    15,    15,    15,   116,   116,    20,
      20,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15, 13763,    15,    15,    15,    15,    15,
      15, 13763, 13763, -2666, -2666, -2666, -2666, -2666, -2666, -2666,
   -2666, -2666, -2666, -2666, -2666, -2666, -2666, 13763, 13763, 13763,
      15, 13763, 13763,   941, 13763, 13763, 13763, 13763,    20, -2666,
   10143, -2666, 10622,  6243, 13763, 13763, 11506, 11506, 11506, 11506,
   11506, 11506, 11506, 11506, 11506, 11506, 13763, 13763, 13763, 13763,
   13763,  -126,   212,    20,    20,  1522,  1476,    20,  1526,  1533,
    7428,  1527,  1534,  7428,  1535,  7428,    20,  7428, -2666,  1421,
    7428,  1422,  1537, -2666,  1538,  1540,   594,  1124, 13763,   857,
     -10, 13763, -2666,   644, -2666,  1539, -2666, -2666,  1542, -2666,
    1543,    15,  7428,    15,  7428,  7428,  7428,    15,    15,    15,
      15,  7428,  7428,  7428,  7428,  7428,  7428,  7428,    15,  7428,
      15,    15,    15,    -4,    15,     1,    14,    15,    15,  7428,
    7428,  7428,  7428,  7428,  7428,  7428,  7428,  7428,  7428,  7428,
    7428,  7428,  7428,  7428,    15, -2666, 13763, -2666,  1544,  7428,
    7428,  7428,  7428,  7428,  7428,  7428,    15,    15,    15, -2666,
    7428,  7428, -2666,  7428, -2666, -2666,    20, -2666,  1105, -2666,
   -2666, -2666, -2666, -2666, -2666,  1541,  1545,  1547,  1548,  1550,
     574,  7428, -2666,  7428,    20,    15,    15,  7428, -2666,  7428,
    7428,  7428,  1439,    20,    15, -2666,    15,    15,  7428,  7428,
    7428,  7428,  7428,  7428, -2666,  7428,  7428, -2666,  7428,  7428,
    7428,  7428,  7428,  7428, 13763,  7428,  7428,  7428,  7428,  7428,
    7428,  7428,  7428,    15, 13763,  7428, 13763,  7428,  7428,    15,
    7428,  7428,  7428, 13763,    15,   116,   116,   116, 13763, 13763,
   13763,    20, 13763,    15,   116,    15,   116,   116, 13763,    74,
   -2666, 13763, 13763, 13763, 13763, 13763,  1298,  7428,  7428,    20,
    -225,  9664,    20,  7428,  1546,  7428,  7428,    20,  -163, -2666,
   -2666,  1551,  1549,   308,  1552,  1553,  1554,  1556,  1557,  1562,
    1558,  1565,  1566,  1568,  1564,  1569,  1571,  1573,  1574,  1572,
    1581,  1582,  1584,  1586,  1587,  1594,  1589,  1596,  1591,   600,
    1598,  1600,  1599,  1601,  1602,  1604,  1606,  1597,   601,  1614,
    1609,  1610,  1611,  1618,  1619,  1620,  1621,  1616, 11948, -2666,
    1623,  1633,  1636,  1637, -2666, -2666, -2666,   602,   453,  1638,
    1639,  1640,  1642,  1624,  1643,  1644,  1645,  1646,  1647,  1648,
    1649,  1650,  1651,  1653, -2666, -2666,  1654,  1655,  1625,  1656,
   -2666,  1555,  1575,  1657,  1658,  1660,  1668,  1669,  1670,  1663,
    1665,  1666,  1667,  1671,  1672,  1673,  1674,  1675,  1676,  1682,
    1683,  1678,  1685,  1680,  1681,  1684,  1686,  1687,   605,  1688,
    1689,  1690,  1691,  1692,  1693,  1694,  1701,  1696,  1697,  1698,
    1699,  1700,  1702,  1707,  1709,  1704,  1705,  1706,  1708,  1710,
    1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1725,  1726,
    1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,   637,  1735,
    1740,  1742,  1744,  1736,   638,   640,  1745,  1737,  1752,   436,
    1101,    68, -2666, -2666,  1753,  1748,   943,   639,   339,  1756,
   -2666, -2666, -2666, -2666, -2666, -2666,   281,   340,   281,   340,
   -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666,    44,
   -2666,    44,   661, -2666,  1278,    53,  1044,  1760,  1765,  1767,
    1769, -2666,  1770,  1771,  1772,  1774,  1775,  1776,   642,  1777,
    1778,  1779,  1780,  1787,  1788,  1789,  1790,    52,  1791, 13763,
   -2666,  1795, 14205,  1240,    15,    15,    15,   649,  1796,  1785,
     651,  1797,  1800,  1813,  1815,  1816,  1817,  1818,  1819,  1820,
    1821,  1822,  1832,  1833,  1828,  1835,  1836,  1831,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,  1849,  1850,  1851,  1856,  1852,
    1857,  1853,  1860,  1861,  1873,  1874,  1869,  1876,  1877,  1878,
    1879,  1883,  1880,  1889,  1890, 13763,  1886,  1888,   652,  1891,
    1892,  1895,  1893,  1894,  1896,  1897,  1899,  1900,  1901,  1902,
    7428,   212, -2666, -2666, -2666, -2666, -2666, -2666,   497,  1903,
    1904,  1907,  1905,  1906, -2666,   214,  1909,  1916, 10622,  1917,
     653,  1919,  1920,  1915,   153,  1918,   374,  1923,   656,  1921,
     663,  1925,  1926,  1928,  1929,   664,  1930,  1931,  1927,   665,
    1932,  1933,  1935,  1936,  1934,  1937,  1943,  1944,  1945,  1946,
    1947,  1948,  1949,  1950,  1951,  1952,  1953,  1957,  1958,  1960,
     666,  1955,  1956,  1959,  1961,  1962,   667,  1964,  1966,   687,
    1967,  1968,  1969,  1971, -2666,  1963,   689,  1972,  1973,  1974,
    1975,  1954,  1981,  1982,  1985, -2666,   715,  1988,  1990,  1989,
    1996,  1999,  1995, -2666,    15,  7428,  7428,  7428,  7428, -2666,
    7428, -2666,  7428, -2666, -2666, -2666,    15,    15,  7428,  7428,
    7428, -2666, -2666,  7428,  7428,  7428,  7428, -2666,  7428, -2666,
    7428, -2666,  7428, -2666, -2666,  7428,  7428,  7428,  7428, -2666,
    1192, -2666,  7428, -2666,    15,  7428, 13763, -2666,  1442, -2666,
   -2666,  1641, 10622, -2666, -2666,  7428,   -36,  7428, -2666, 13763,
     108,  7428,  7428, -2666,  7428,  7428,  7428,  7428,  7428,  7428,
    7428,  7428,  7428,  7428,  7428,  7428, -2666,  7428,    15,    15,
   13763, 13763,    15,    15,    15, -2666,  7428,  7428,  7428,  7428,
    7428,  7428,  7428,  7428,  7428, -2666, -2666, -2666,    15, -2666,
      15,    15,    15,    15,    15, -2666,    15,    15,  7428,  7428,
    7428,  7428, 13763, 13763, -2666,  7428,  7428,  7428,  7428,    15,
      20, -2666, -2666,    15,    15,  7428,  7428,  7428,  7428,  7428,
    7428,  7428,  7428,  7428,  7428,  7428, -2666, -2666, -2666, -2666,
   -2666, -2666, -2666,  7428,  7428,  7428, -2666,  7428,  7428,    15,
    7428,  7428,    15, -2666,  7428, -2666,  7428, 13763, -2666, -2666,
   -2666, -2666, -2666, -2666, -2666,  1563, -2666,  7428, -2666, 13763,
      15,  2002,  2003,  2004, -2666, -2666,  7428,  7428,  1662, -2666,
   -2666,  7428,    20,    20,    20,  7428, -2666, -2666, -2666, -2666,
   -2666, -2666, -2666, -2666, 13763,  2005,  2006,   717, -2666,    15,
   -2666,  7428, -2666,  7428, -2666, -2666, -2666, -2666, -2666, -2666,
   -2666, -2666, -2666, -2666, -2666, -2666, -2666,  7428, -2666, -2666,
      15, -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666,
   -2666, -2666,  7428, -2666,  7428, -2666, -2666, -2666, -2666,  7428,
   -2666, -2666, -2666, -2666, -2666,  7428, -2666, -2666,  2007,  7428,
    7428, -2666, 10622,  7428,  7428, -2666,  7428,  7428,    15,    15,
    7428,  7428, -2666,  7428,  1112, -2666,   212,  1652,  1695,  1859,
    1898,  1912,  7428,  7428, -2666,    15,  7428, -2666,  7428,  7428,
    7428, -2666, -2666, -2666, -2666, -2666,  7428, -2666, -2666,  7428,
   -2666,  7428, -2666, -2666, -2666,  7428,  7428, -2666,  7428, -2666,
   -2666, -2666, -2666, -2666,  7428, -2666, -2666,  7428, -2666,  7428,
   -2666,  7428,  7428,  7428, -2666, -2666, -2666, -2666, -2666, -2666,
   -2666, -2666,  7428,  7428, -2666, -2666,  7428, -2666, -2666, -2666,
   -2666,  7428,  7428,  7428,  7428,  7428,  7428, -2666,  7428,  7428,
    7428, -2666,  7428,  7428,  7428,  7428,  7428, -2666, -2666,  7428,
    7428,  7428, 10622, 13763,  7428, -2666, -2666, -2666, -2666, -2666,
   -2666,  1635, -2666, -2666,  1743,  2008,  2011,  2012,  2019,  2014,
    2021,  2016,  2024,  2025,  2027,  2029,  2028,  2030,  2031,  2032,
    2033,  2034,  2036,  2037,  2039,  2041,  2045,  2046,  2043,  2053,
    2054,  2049,  7428,  2056,  2051,  2052,  2061,   718,  2058,  2059,
    2062,  2066,  2067,  2074,  2072,  2084,  2079,  2086,  2087,  2088,
    2089,  2090,  2091,  2092,  2099,  2094,  2095,  2096,  2097,  2098,
    2100,  2101,  2102,  2103,  2104,  2105,  2108,  2109,  2110,  2117,
    2112,  2113,  2114,  2115,  2116,  2118,  2123,  2125,  2120,  2127,
    2128,  2130,  2126,  2129,  2131,  2133,  2134,  2136,  2132,  2137,
    2139,  2135,  2138,  2141,  2140,  2142,  2143,  2145,  2153,  2154,
    2155,   720,  2146,  2150,  2151,  2156,  2158,  2157,  2159,  2160,
    2162,  2163,  2161,  2164,  2166,  2165,  2167, -2666,  2170, -2666,
   -2666, -2666,  2171,  2172,  2180,  2181,  2182,  2183,  2178,  2185,
   -2666, -2666, -2666,  7428,  2187,  2191,  2189,  2200,  2195,  2196,
    2203,  2199,  2202, -2666,   722,   729,   731,  2209,  2204,  2205,
    2206,  2207,  2208,  2210,  2211,  2213,  2215,  7428,   212, -2666,
   -2666, -2666, -2666, -2666, -2666,  2220,  2216,  2217,  2218,   337,
    2221,  1942,  2219,  2222,  2223,  2225,  2226,  2227,  2234,  2229,
    2230,  2231,  2232,  2233,  2235,  2236,  2237,  2238,  2240,  2239,
    2241,  2242,  2243,  2246,   732,  2250,  2251,  2252,  2253,  2255,
    2254,   734,  2256,  2262,  2263,  2264,  2265,  2266,  2267,  2257,
    7428, -2666,  7428, -2666,  7428, -2666,  7428, -2666, -2666, -2666,
   -2666,  7428,  7428, -2666,  7428,  7428,  7428,  7428, -2666,  7428,
    7428,  7428,  7428, -2666, -2666, -2666,  7428, -2666, -2666,  7428,
    7428, -2666, -2666,    50,   130,  7428, -2666, -2666, -2666, -2666,
    7428, -2666,  7428,  7428,  7428,  7428,  7428,  7428,  7428,  7428,
   -2666,  7428,  7428,  7428,  7428,  7428,  7428,  7428,  7428,  7428,
    7428,  7428,  7428,  7428,  7428, -2666,  7428,    15,    15,    15,
      15,    15, -2666, -2666,  7428, -2666, -2666, -2666,  7428,  7428,
   -2666, -2666, -2666, -2666, 13763, -2666, -2666, 13763,  7428,  7428,
   -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666,  7428,  7428,
    7428,  7428,  7428, -2666,  7428,  7428, -2666,  7428,  7428, -2666,
   -2666, -2666,  7428,  7428, -2666,  7428,  7428, -2666, -2666, -2666,
   -2666,    20, -2666,  2258, -2666,  7428, -2666, -2666,    15,  7428,
   -2666,  7428,  7428, -2666, 13763, -2666, 13763, -2666, 13763, -2666,
   13763,  7428,  7428,  7428,    15,    15,  7428,  7428, -2666, -2666,
   -2666, -2666,  7428,    15,  7428, -2666,  7428,  7428, -2666,  7428,
    7428,  7428,  7428,  7428,  7428,  7428, -2666,  7428,  7428,  7428,
    7428,  7428,  7428,  7428,  7428,  7428, -2666,  7428,  7428,  7428,
    7428, -2666, -2666,    15, -2666, -2666, -2666, -2666, -2666, 13763,
   -2666,  7428,  7428,  7428,  7428, 13763, 13763,  7428,  7428, -2666,
    2259,   741,  2268,  2261,  2269,  2270,  2277,  2272,  2273,  2280,
    2275,  2276,  2278,  2285,  2281,  2282,   400,  2283,  2284,  2286,
    2085,   742,  2288,  2289,  2290,   743,   777,   797,   798,  2291,
    2292,  2293,  2294,  2301,   598,   799,   364,  2296,  2297,  2298,
    2299,   800,  2300,  2302,  2304,  2306,  2308,  2309,  2316,  2311,
    2314,  2319,  2324,  2325,  2326,  2328,  2335,  2338,  2339,  2340,
    2342,  2351,  2341,  2366,  2368,  2369,  2371,  2373,  2374,  2344,
    2376,  2000,  2022,  2345,  2346,  2377, -2666,  2378,  2387,  2382,
    2389,  2384,  2391,   801,  2392,  2388,  2393,  2397,  2394,   802,
    2395,  2398,  2402,   212,  2404,  2407,  2410,  2403,  2417,  2418,
    2419,  2426,  2427,  2428,  2429,  2430,  2431,  2433,  2434,  2435,
    2437,  2440,  2441,  2442,  2438,  2439,  2445,  2446,  2449,  2443,
    2456,  2457,  2452,  2460,  2459,  2467,  2477,  2462,  2488, -2666,
   -2666,  7428,  7428, -2666,  7428,  7428, -2666,  7428,  7428, -2666,
    7428,  7428,  7428, -2666,  7428,  7428, -2666,    50,  7428, -2666,
   -2666,    50,  1978,  7428,  7428, -2666,  7428, -2666,  7428, -2666,
    7428, -2666,  7428,  7428,  7428,  7428,  7428, -2666, -2666, -2666,
    7428,  7428,  7428,  7428,  7428,  7428, -2666, 14526, 14526, 14526,
    7428,  7428,  7428,  7428, -2666,  7428,  7428,  7428,  7428,  7428,
      15,  7428, -2666, -2666, -2666, -2666,  7428,  7428, -2666,  7428,
    7428,  7428,  7428,  7428,  7428, -2666,  7428,  7428,  7428, -2666,
   -2666,    20,  7428, -2666,  7428, -2666,  7428, -2666, -2666,  7428,
   -2666,  7428,  7428, -2666,  7428, -2666, 13763,    15, -2666, -2666,
   -2666,  7428,    15,  7428, -2666, -2666,  7428,  7428, -2666, -2666,
   -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666, -2666,
   -2666,  7428,  7428,  7428,  7428,  7428, -2666, -2666, -2666, 13763,
   -2666,  7428,  7428,  7428, -2666, -2666,  2483,  2490,  2491,  2486,
    2487,  2489,  2494,  2496,  2497,  2500,   827,  2501,  2502,  2503,
     828,  2504,  2505,   829,   830,  2506,  2507,  2508,  2509,  2512,
    2519,  2514,  2515,  2516,  2517,  2518,  2520,   686,  2525,   738,
    2527,  2248,  2528,  2523,  2524,  2526,  2529,  2530,  2531,  2532,
    2533,  2534,   868,  2535,  2542,   869,  2543,  2554,  2556,  2551,
    2552,  2553,  2560,  2224,  2555,  2562,  2564,   870,  2567,  2574,
    2582,  2577,  2578,  2585,  2580,  2581,  2583,  2584,  2385,  2588,
    2591,  2586,  2587,  2594,  2590,  2592,  2593,  2595,  2596,  7428,
   -2666, -2666,  7428,  7428,  7428, -2666, -2666, -2666,  7428, -2666,
    7428,  7428,    20, -2666, -2666,    50,  7428,  7428, -2666,  7428,
   -2666,  7428,  7428,  7428,  7428,  7428,  7428, -2666,  7428,  7428,
    7428,  7428,  7428,  7428, 14526, -2666, 14526, -2666, -2666, 14526,
   14526,  7428,  7428,  7428,    15,    15,    15,    15, -2666,  7428,
    7428, -2666, -2666,  7428, -2666, -2666, -2666,  7428,  7428,  7428,
   -2666, -2666,  7428, -2666, -2666, -2666,  7428,  7428, -2666, -2666,
    7428,  7428, -2666,    15,  7428,    15,  7428,  7428, -2666, -2666,
    7428,  7428, -2666,  7428, 13763,  7428,  7428,  7428,  2597,  2598,
    2599,  2600,  2601,  2603,  2602,  2604,  2609,  2611,  2606,  2613,
    2614,  2615,  2616,  2617,  2618,  2619,   871,  2620,  2621,  2622,
    2623,  2624,  2626,  2628,  2629,  2631,  2627,  2632,  2634,  2635,
    2637,  2640,  2644,  2643,  2647,  2654,  2650,  2657,  2652,  2396,
    2653,  2662,  2658,  2660,  2668,  2669,  2670,  2685,  2697,  2693,
    2694,  2695,   872,  2696,  2699,  2706, -2666,  7428,  7428,  7428,
    7428, -2666,  7428,  7428, -2666, -2666,  7428, -2666, -2666, -2666,
   -2666, -2666, -2666,  7428, -2666,  7428, -2666,  7428, -2666, -2666,
    7428, -2666, -2666, -2666, -2666, 14526, -2666, -2666, -2666, -2666,
    7428,  7428, -2666,  7428, -2666,  7428, -2666,  7428,  7428,  7428,
   -2666,  7428,  7428,    15,  7428,    15,  7428,  1605,  7428,  7428,
    7428, -2666, 13763,  7428,  7428,  7428,  2716,  2717,  2712,  2720,
      16,  2718,  2719,  2721,  2722,  2730,  2732,  2727,  2734,  2731,
    2735,  2736,  2739,  2740, -2666,  2742,   873,  2741,   885,  2743,
    2744,  2745, 13763,  2746,  2747,  2748,  2749,  2756,   886,  2751,
   -2666, -2666,  7428, -2666, -2666,    20,  7428,  7428, -2666, -2666,
   -2666,  7428, -2666,  7428,  7428, -2666,  7428,  7428, -2666, -2666,
   13763,  7428, -2666, 13763,  7428,  7428,  7428, -2666,  7428,  7428,
    7428,  7428, -2666, -2666,  7428,  7428,  2757,  2764,  2765,  2766,
    2767,  2771,  2768,  2769,  2770,  2772,  2773,  2777,  2774,  2775,
    2776,  2778,  2779,  2780,  2783,   887,   888,  7428, -2666, -2666,
   -2666, -2666, -2666,  7428,  7428,  7428, -2666, -2666, -2666,  7428,
    7428,    15, -2666,  7428,  7428, -2666, -2666,  7428, -2666, 13763,
    2781,  2782,  2784,  2785,  2789,  2786,  2787,  2790,  2788,  2795,
    2791,  7428,  7428, -2666,  7428, -2666,  7428,    15, -2666,  7428,
   -2666, 13763,  2792,  2796,  2793,  2794,  2797,  2801,  2802,  7428,
   -2666,  7428,  7428,  7428, -2666, -2666,  2798,  2799,  2800,  2807,
    7428,  7428,  7428, -2666,  2803,  2804,  2805,  7428,  7428,  7428,
    2808,  2806,  2809, -2666,  7428,  7428,  2810,  2813,  7428, -2666,
    2814, -2666
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   451,     0,     0,     0,     0,    17,    58,    59,    60,
      61,     0,   364,    28,    16,     0,    89,    63,     0,     0,
       0,     0,     0,    88,   350,   363,   798,   497,   367,   368,
     369,   351,     0,   759,     0,   715,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    33,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   292,   354,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,   365,   366,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   361,    29,     0,    25,     0,     0,     0,     0,     0,
       0,     0,   313,   314,   315,   316,   317,     0,     0,   452,
       0,     0,     4,     8,    10,    14,    12,     0,   352,   356,
     359,     0,   371,   433,   453,     0,   455,   458,   461,   462,
     467,   472,   474,   476,   478,   480,   482,   484,   485,   286,
     430,     0,   717,   719,   720,   738,   739,   743,   748,   749,
     750,   751,   752,   753,   754,   755,   756,   757,   758,    96,
       0,     0,     0,     0,     0,   367,   368,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     435,     0,     0,   715,   437,   723,   436,   722,   351,     0,
     430,     0,     0,     0,    84,    64,    66,    91,    90,    65,
      93,    99,    95,    94,   100,     0,    87,     0,    74,    75,
       0,    77,    78,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   322,   322,    27,     0,
       0,     0,     0,     0,   800,   799,   810,   802,   803,   804,
     811,   805,   806,   807,   808,   809,   813,   812,   814,   815,
     801,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   438,
     725,   439,   726,   444,   731,   445,   732,   446,   733,   447,
     734,   448,   735,   450,   737,   449,   736,   440,   727,   441,
     728,   442,   729,   443,   730,     0,    20,     0,   361,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       3,     5,     9,    11,    15,    13,     0,     6,     0,     0,
       0,     0,   434,   721,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   724,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   370,     0,     0,   718,     0,     0,
       0,    76,    79,    80,    83,     0,     0,     0,     0,     0,
       0,   407,   408,   405,   406,   403,   404,   409,   410,   411,
       0,     0,     0,   103,     0,     0,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,     0,     0,     0,     0,
     244,     0,   252,     0,     0,     0,     0,     0,   241,   242,
       0,    45,    46,     0,    98,     0,     0,    57,     0,     0,
       0,     0,     0,   507,     0,   337,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   325,
       0,   323,   511,   646,   648,   649,   667,   669,   675,   676,
     681,   682,   691,   696,   698,   699,   701,   703,   705,   707,
     709,   331,     0,     0,     0,   300,   296,   297,     0,     0,
       0,   304,   305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   301,   302,   303,   306,   426,   311,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   511,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,   153,     0,     0,   412,   413,     0,     0,     0,
       0,     0,     0,     0,     0,   414,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   192,   154,   155,   156,
     157,     0,     0,   511,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   715,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   362,     0,    24,   814,     0,     0,
       0,   339,     0,     0,     0,     0,     0,     0,     7,   357,
     358,   470,   471,   456,   457,   459,   460,   464,   463,   465,
     466,   468,   469,   473,   475,   477,   479,     0,   481,     0,
       0,     0,   355,     0,   379,   381,     0,   194,     0,     0,
       0,     0,     0,     0,     0,     0,   496,   380,    69,     0,
      70,    68,   740,   742,   741,   744,   746,   745,   747,   382,
     383,   384,     0,     0,     0,     0,   228,     0,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,     0,   214,     0,   224,
     225,     0,     0,     0,     0,     0,   233,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   773,     0,     0,     0,     0,
       0,   776,    49,     0,    40,     0,     0,     0,   507,     0,
       0,     0,   710,     0,   773,     0,   487,   490,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,    53,    39,    44,    43,   776,    48,
       0,     0,     0,     0,   454,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    97,     0,
       0,     0,   511,   667,   652,   651,   430,     0,   327,   329,
     333,   335,     0,   499,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   653,   654,   659,   660,   661,   662,   663,
     665,   664,   655,   656,   657,   658,   666,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   320,
       0,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   312,   760,
       0,   498,     0,    34,     0,     0,   511,     0,     0,     0,
       0,     0,   390,     0,   392,     0,   393,   394,     0,   395,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   386,     0,   391,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
       0,     0,   388,     0,   716,   402,     0,   289,     0,   360,
     361,    21,   428,   429,   291,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,   372,     0,
       0,     0,     0,     0,     0,   193,     0,     0,     0,     0,
       0,     0,     0,     0,   197,     0,     0,   198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     771,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,   760,
     498,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   647,
       0,     0,     0,     0,   597,   595,   596,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   566,   567,     0,     0,     0,     0,
     570,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     338,   326,   324,   332,     0,     0,   819,     0,   818,     0,
     708,   674,   670,   672,   671,   673,   677,   679,   678,   680,
     688,   684,   687,   683,   689,   685,   690,   686,   694,   692,
     695,   693,   697,   700,   702,     0,   704,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   342,   343,   344,   340,   341,   361,     0,     0,
       0,     0,     0,     0,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   770,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   711,     0,     0,     0,     0,
       0,     0,     0,   353,     0,     0,     0,     0,     0,   126,
       0,   129,     0,   102,   105,   104,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   119,     0,   128,
       0,   245,     0,   240,   247,     0,     0,     0,     0,   243,
       0,   253,     0,   248,     0,     0,     0,   251,   415,   431,
     432,     0,     0,   668,   500,     0,     0,     0,   506,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   547,     0,     0,     0,
       0,     0,     0,     0,     0,   578,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   531,   532,   533,     0,   535,
       0,     0,     0,     0,     0,   542,     0,     0,     0,     0,
       0,     0,     0,     0,   549,     0,     0,     0,     0,     0,
       0,   504,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   622,   527,   529,   591,
     592,   593,   594,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,   637,     0,   639,     0,     0,   641,   642,
     328,   330,   334,   336,   623,     0,   512,     0,   553,     0,
       0,     0,     0,     0,   299,   298,     0,     0,     0,   420,
     422,     0,     0,     0,     0,     0,   308,   309,   295,   427,
      47,    50,    42,    35,     0,     0,     0,     0,   284,     0,
     140,     0,   139,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   160,   161,   162,     0,   175,   176,
       0,   178,   186,   180,   181,   187,   182,   188,   184,   185,
     183,   163,     0,   173,     0,   164,   189,   190,   169,     0,
     165,   166,   167,   168,   171,     0,   385,   401,     0,     0,
       0,   266,     0,     0,     0,   273,     0,     0,     0,     0,
       0,     0,   714,     0,   361,    22,     0,     0,     0,     0,
       0,     0,     0,     0,   310,     0,     0,   373,     0,     0,
       0,   378,    72,    71,   137,   136,     0,   195,   196,     0,
     280,     0,   282,   283,   132,     0,     0,   130,     0,   215,
     220,   226,   227,   230,     0,   229,   199,     0,   211,     0,
     207,     0,     0,     0,   203,   204,   205,   206,   212,   221,
     213,   216,     0,     0,   209,   219,     0,   234,   238,   777,
     778,     0,     0,     0,     0,     0,     0,   774,     0,     0,
       0,   765,     0,     0,     0,     0,     0,   772,   786,     0,
       0,     0,     0,     0,     0,    37,    38,   713,    41,   294,
      36,     0,    52,    51,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   706,     0,   632,
     633,   634,     0,     0,     0,     0,     0,     0,     0,     0,
     396,   397,   398,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
     347,   348,   349,   345,   346,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,   124,     0,   127,     0,   108,   106,   109,
     111,     0,     0,   116,     0,     0,     0,     0,   246,     0,
       0,     0,     0,   254,   249,   260,     0,   416,    56,     0,
       0,   518,   519,     0,     0,     0,   545,   548,   550,   551,
       0,   552,     0,     0,     0,     0,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   530,     0,     0,     0,     0,
       0,     0,   543,   544,     0,   513,   514,   515,     0,     0,
     598,   599,   600,   601,     0,   645,   607,     0,     0,     0,
     612,   613,   614,   615,   616,   617,   618,   619,     0,     0,
       0,     0,     0,   627,     0,     0,   628,     0,     0,   636,
     638,   640,     0,     0,   635,     0,     0,   419,   421,   423,
     424,     0,   307,     0,   285,     0,   151,   174,     0,     0,
     177,     0,     0,   261,     0,   263,     0,   268,     0,   267,
       0,     0,     0,     0,     0,     0,     0,     0,   288,   361,
      18,   321,     0,     0,     0,   374,     0,     0,   377,     0,
       0,     0,     0,     0,     0,     0,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   780,     0,     0,     0,
       0,   775,   761,     0,   762,   766,   767,   768,   769,     0,
     787,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     122,     0,     0,   101,     0,     0,   118,     0,     0,   239,
       0,     0,     0,   259,     0,     0,   510,     0,     0,   520,
     521,     0,     0,     0,     0,   557,     0,   560,     0,   562,
       0,   564,     0,     0,     0,     0,     0,   568,   569,   602,
       0,     0,     0,     0,     0,     0,   579,     0,     0,     0,
       0,     0,     0,     0,   589,     0,     0,     0,     0,     0,
       0,     0,   516,   517,   644,   608,     0,     0,   620,     0,
       0,     0,     0,     0,     0,   631,     0,     0,     0,   417,
     418,     0,     0,   179,     0,   170,     0,   262,   264,     0,
     269,     0,     0,   278,     0,   277,     0,     0,   387,   389,
      19,     0,     0,     0,   375,   376,     0,     0,   279,   281,
     133,   134,   131,   208,   210,   200,   201,   202,   217,   218,
     232,     0,     0,     0,     0,     0,   763,   764,   788,     0,
     789,     0,     0,     0,   785,   712,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   817,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,   112,     0,     0,     0,   256,   257,   258,     0,   508,
       0,     0,     0,   522,   523,     0,     0,     0,   556,     0,
     559,     0,     0,     0,     0,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,   580,     0,   582,   584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   540,     0,
       0,   609,   610,     0,   621,   624,   625,     0,     0,     0,
     526,   554,     0,   425,   138,   158,     0,     0,   265,   272,
       0,     0,   276,     0,     0,     0,     0,     0,   135,   779,
       0,     0,   783,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,   509,     0,     0,   524,   525,     0,   558,   561,   563,
     565,   572,   575,     0,   604,     0,   606,     0,   573,   576,
       0,   581,   583,   585,   586,     0,   588,   534,   536,   537,
       0,     0,   541,     0,   611,     0,   629,     0,     0,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   790,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   816,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   117,     0,   250,   502,     0,     0,     0,   574,   605,
     603,     0,   587,     0,     0,   590,     0,     0,   159,   270,
       0,     0,   275,     0,     0,     0,     0,    73,     0,     0,
       0,     0,   795,   794,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   503,   501,
     555,   577,   538,     0,     0,     0,   271,   290,   274,     0,
       0,     0,   781,     0,     0,   791,   792,     0,   796,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   643,     0,   237,     0,     0,   782,     0,
     793,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     539,     0,     0,     0,   784,   797,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,   318,
       0,   630
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2666, -2666, -2666,   -37,  1615,  1846,  1987,  2174,  2413,  -248,
   -2666, -2666,   540, -2666,   255,  -343, -2666, -2666, -2666, -2666,
    -411,  4544,  3482,  -360, -2666,  -368,   530,  1303,  1174,  1318,
    1798,  1560,  1172,   276, -2666,     0,    81,  3154, -2666, -2666,
   -2666,  -382,  -252,  -228, -2666, -2666,  -141,  -224,   414, -2666,
     590,   591,  1012,  1473,   321,  1469,  6175,  1634, -2666, -2666,
   -2666, -2666,   700,   554, -2666, -2666, -2666, -2666, -2666, -2666,
   -2666, -2666, -2666, -2666, -2666,     7,  5827,  -401,    27,  2197,
   -2665
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   130,   131,   132,   133,   134,   135,   136,   137,   608,
    1280,   138,   139,   140,   141,   346,   347,  1269,   142,   143,
     144,   209,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   219,   160,   221,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,  1017,   956,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   222,   212,   922,   847,   281,
    1539
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       159,   258,   959,    26,   964,   795,     6,   179,   832,   633,
     817,   818,   819,   820,    14,   483,   815,   816,     1,   231,
     234,   771,   772,   773,   832,   396,   232,   181,   929,  3114,
      26,  1450,  2818,  2820,  2822,  1450,   658,   252,   855,   857,
     254,   223,    27,   228,   378,   379,   261,    27,    33,  1150,
    1151,   388,    27,  1407,   859,   860,   861,  1159,   192,   193,
      21,   932,  1444,  1445,   193,    27,    27,    24,  1287,   193,
     774,    27,   639,   640,  1919,   218,   643,   644,   645,   646,
     647,   648,   193,   193,   400,   257,   220,  1734,   193,   249,
     402,   859,   860,   861,   361,     6,  1741,  1425,  1426,   235,
     367,    27,   247,    14,  1022,    21,  1358,  1013,  1013,    33,
      27,   403,    24,   348,    21,  1382,    27,   248,   193,   192,
     218,    24,   411,  1262,   390,    27,   391,   193,   416,   218,
     392,   159,  1022,   193,   262,   370,   371,   345,   179,  1023,
     397,   715,   193,  1349,   352,   255,  1619,   389,   253,  1745,
    1451,  1622,   834,  1160,  1451,  2147,   380,   381,   181,    27,
     256,  1152,  1153,   389,  1624,   411,  2040,  1023,   401,  1160,
     835,   416,    58,    33,   250,   251,   193,  2541,  1350,   834,
    1349,    27,  1363,   192,  1191,  1452,  1143,   370,   371,  1452,
    1288,  1246,  1567,  1568,  1569,  1570,  1289,   835,   193,  1291,
    1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,
    1013,  1013,  1013,  1013,   393,  1350,   411,    58,   659,   859,
     860,   861,   412,   418,   705,   706,    58,  2027,  1013,  1567,
    1568,  1569,  1570,  2028,     6,   394,  2029,  1014,  1015,  2982,
     421,  2983,    14,   422,  2984,  2985,   423,   238,   239,  1142,
     259,  1143,   480,   481,   260,   416,   611,   611,   240,   263,
     482,   660,   285,   662,   286,   220,   282,   241,   242,   283,
      27,  1018,  1019,   284,   230,   233,    33,   236,   243,   244,
     245,   287,   664,   665,  1013,  1013,   192,   193,   374,   375,
     246,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,
    1013,  1013,  1013,  1013,  1013,   382,   383,   900,   901,   902,
     292,   766,   796,   768,   770,   293,   903,   904,   905,   906,
     411,   907,   789,   368,   369,   227,   416,  1755,    26,   808,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1145,   294,  1288,  1146,  1147,    26,
    2475,   411,  1289,   802,  1290,  1291,  2476,   416,  1141,  2477,
     288,   908,   289,   295,   909,   910,   911,   912,   846,   913,
     914,   935,   657,   915,   831,   832,   411,   798,  1042,   846,
    3088,    26,   416,  2691,  1043,   296,   411,  2042,    80,    81,
     829,   830,   416,   297,   850,   846,   376,   377,  1139,   484,
     485,   486,   487,   954,  1140,   398,   399,   960,   961,   298,
     957,   962,   411,  2666,  1014,  1015,   301,   290,   416,   291,
     302,  1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,
    1122,  1123,  1124,  1125,  1141,   303,   299,  1270,   300,   775,
     776,   777,   778,   779,   780,   224,   304,   781,   782,   783,
     784,   785,   786,   787,   305,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,  1191,  1194,  1143,   833,   306,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     460,   307,   461,  1008,   462,   463,   308,    27,  1910,  1911,
     419,   309,   464,    33,   310,   465,   466,   467,   468,   469,
     470,  1162,   424,   192,   193,   747,   748,  1140,   129,   485,
     486,   609,   609,   431,   432,   433,   434,   435,   436,   437,
     438,   439,  1028,  1142,   286,  1143,   916,   917,   918,   412,
     834,   471,   919,  1042,   920,   472,   698,   749,   750,  1189,
     473,   474,   349,  1013,  1013,  1191,   311,  1143,   835,   312,
     475,   836,   837,   838,   839,   476,   477,  1013,  1013,  1013,
    1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,
     313,  1013,  1016,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   314,   840,   841,   842,   359,  1667,   699,   700,
     701,   702,  1400,  1668,   703,   704,   705,   706,   707,   708,
     709,   710,   711,   712,   713,   714,  1191,   315,  1143,   803,
     411,  2688,  1593,  1781,  1791,  1808,   416,  1424,  1855,  1782,
    1792,  1140,   705,   706,  1856,   811,   812,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
    1896,  1903,   384,  1905,  1916,  1930,  1897,  1904,   952,  1906,
    1917,  1931,  1948,  1182,  1952,  2001,  2035,   316,  1949,  2044,
    1953,  2002,  2036,  1014,  1015,  2045,  2047,  2053,  2058,  2080,
    2087,   317,  2048,  2054,  2059,  2081,  2088,  1113,  1114,  1115,
    1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,
    2091,  1141,  2098,   215,   217,  2904,  2092,  1917,  2099,  1148,
    1149,   843,   844,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,  2108,   845,
    2242,  2352,   387,  2417,  1140,  2453,  2243,  2353,  1007,  2418,
     318,  2454,  2455,   385,  2457,  2502,   846,  2510,  2456,  1185,
    2458,  2503,   350,  2511,  2650,  2670,  2675,  2906,  1271,  1917,
    2651,  2671,  2676,  1013,  1013,  1013,  1013,  1013,  1013,  1013,
    1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1427,
    1154,  1155,  1550,  1552,  1554,  1556,  1558,  1560,  1546,  1548,
    2677,   440,   351,  1268,  1425,  1426,  2678,   320,   322,   324,
     326,   328,   330,   332,   334,   336,   338,   340,   342,   344,
    2679,  2681,  2689,  2696,  2738,  2745,  2680,  2682,  2690,  2697,
    2739,  2746,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   386,
    2879,  2884,  2888,  2890,   353,   373,  2880,  2885,  2889,  2891,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   354,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
     734,   735,   736,   737,   738,   739,   740,   741,   742,   743,
     744,  2918,  2922,  2935,  3034,  3071,  3129,  2919,  2923,  2936,
    3035,  3072,  3130,  1541,  1543,  1545,   745,   746,  3132,  3143,
    3186,  3188,  1444,  1445,  3133,  3144,  3187,  3189,   809,   810,
     355,   458,   821,   822,  1178,  1275,  1276,  1277,  1278,  1279,
    1547,  1549,   859,   860,   861,   862,   356,  1661,   357,   459,
    1559,  1561,   657,    26,    27,   264,   265,   358,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     797,   279,   856,   858,   395,   863,  2017,  2018,  2019,  2020,
    2021,   404,   252,   864,   405,   406,  1371,  1372,  1374,  1375,
    1376,  1377,  1378,   407,  1380,  1381,   865,   408,   409,  1386,
    1387,  1388,  1389,  1390,  1391,  1392,   410,  1394,   413,  1396,
     414,  1398,  1399,   415,  1401,  1402,  1403,  1404,  1405,  1567,
    1568,  1569,  1570,  1411,  1412,  1413,  1414,   964,  1016,  1551,
    1553,  1555,  1557,   417,   420,   661,   663,   488,   866,   764,
     867,   868,   869,   765,  1423,   790,   793,   611,   801,   794,
     800,   870,   871,   715,   965,   804,  1803,   872,   873,   874,
     875,   966,   832,   967,   968,   969,   970,   971,   972,   973,
     876,   877,   878,   879,   880,   974,   881,   882,   975,   883,
     976,   977,   978,   979,   884,   885,   886,   887,   888,   889,
     890,   891,   892,   893,   894,   895,   896,   897,   898,   980,
     981,   982,   983,  1006,   984,   985,   986,   987,   988,   989,
     990,  1295,   991,   992,   993,   994,   853,   854,   995,   996,
     997,   998,   999,  1421,  1000,  1001,  1002,  1003,  1004,  1005,
    1009,  1010,  1011,  1746,  1024,  1144,  1027,  1304,  1029,  1025,
    1307,  1026,    27,   264,   265,  1571,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
    1532,  1030,   962,  1537,  1031,  1032,  1033,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,  1044,  1045,  1046,  1047,  1158,
    1049,  1050,  1051,  1384,  1054,  1048,  1055,  1056,  1057,  1052,
    1579,  1053,  1058,  1582,  1059,  1584,  1060,  1586,  1061,  1062,
    1588,  1063,  1064,  1065,   899,  1066,  1940,  1067,  1068,  1069,
    1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1598,  1082,  1600,  1601,  1602,  1083,  1084,  1085,
    1803,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1086,  1615,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1628,
    1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,
    1639,  1640,  1641,  1642,  1096,  1097,  1098,  1099,  1100,  1646,
    1647,  1648,  1649,  1650,  1651,  1652,  1101,  1102,  1103,  1104,
    1656,  1657,  1105,  1658,  1415,  1106,  1417,  1107,  1108,  1109,
    1110,  1111,  1112,  1127,  1128,  1129,  1130,  1420,  1131,  1132,
    1179,  1669,   609,  1670,  1134,  1135,  1133,  1136,  1137,  1675,
    1676,  1677,  1138,  1156,  1163,  1157,  1164,  1161,  1683,  1685,
    1687,  1688,  1689,  1690,  1165,  1691,  1692,  1166,  1693,  1694,
    1695,  1696,  1697,  1698,  1167,  1700,  1701,  1702,  1703,  1704,
    1705,  1706,  1707,  1168,  2016,  1710,  1169,  1712,  1713,  1170,
    1715,  1716,  1717,  1171,  1172,  1173,  1174,  1175,  1176,  1177,
    1410,  1385,  1180,  1183,  1493,  1494,  1181,  1188,  1184,  1192,
    1187,  1190,  1193,  1194,  1195,  1196,  1197,  1742,  1743,  1198,
    1199,   611,  1202,  1748,  1200,  1750,  1751,  1201,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  1528,  1228,  1531,  1229,  1230,  1231,  1232,
    1233,  1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,
    1243,  1395,  1245,  1247,  1523,  1397,  1259,  1248,  1572,  1573,
    1244,  1456,  1576,  1249,  1250,  1251,  1252,  1253,  1254,  1255,
    1256,  1585,  1257,  1258,  1260,  1261,  1263,  1264,  1265,  1266,
    1267,  1272,  1273,  1274,  1282,  1281,  1424,  1457,  1293,  1294,
    1296,  1283,  1284,  1285,  1286,  1292,  1297,  1298,  1299,  1300,
    1301,  1302,  1303,  1305,  1306,  1308,  1309,  1310,  1311,  1312,
    1313,   215,   217,  1314,  1315,   320,   322,   324,   326,   328,
     330,   332,   334,   336,   338,   340,   342,   344,   373,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1659,  1348,  1351,  1352,  1353,  1354,  1355,  1409,  1575,
    1359,  1357,  1418,  1361,  1356,  1362,  1364,  1013,  1360,  1671,
    1365,  1366,  1367,  1368,  1587,  1589,  1369,  1370,  1679,  1419,
    1660,  1594,  1590,  1592,  1595,  1596,  1645,  1741,  2267,   824,
     827,  1416,  1678,  1674,  1753,  2142,  1745,  1828,  1754,  1759,
    1562,  1756,  1757,  1758,  1574,  1761,  1760,  1762,  1763,  1764,
    1577,  1765,  1580,  1766,  2225,  1771,  1578,  1829,  1767,  1581,
    1768,  1662,  1769,  1770,  1772,  1663,  1726,  1664,  1665,  1583,
    1666,  1773,  1591,  1774,  1735,  1775,  1776,  1777,  1778,  1779,
    1780,  1783,  1749,  1784,  1744,  1790,   609,  1747,  1785,  1789,
    1786,  1787,  1752,  1788,  2015,   215,   217,  1793,  1794,  1795,
    1796,  1797,  1798,  1799,  1800,  1801,  1804,  1813,  1826,   320,
     322,   324,   326,   328,   330,   332,   334,   336,   338,   340,
     342,   344,  1805,   373,  1806,   846,  1807,  1809,  1810,  1811,
    2014,  1812,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,
    1822,  2268,  1823,  1824,  1825,  1827,  1830,  1831,  2032,  1832,
    1833,  1834,  1836,  1835,  1837,  1838,  1839,   823,  2143,  1845,
    1840,  1841,  1842,  1843,  1844,  1846,  1847,  1848,  1849,  1850,
    1851,  2318,  2270,  1852,   825,  1853,  1854,  1857,  1858,  1859,
    1860,  1861,  1862,  1863,  1864,  1865,  1866,  1867,  1868,  1869,
    1871,  1870,  1872,  1873,  1874,  1875,  2234,  1876,  3102,  1877,
    1878,  1879,  1880,  1881,  1882,  1883,  1884,  1885,  1886,  1887,
    1888,  1889,  1890,  1891,  1892,  2271,   362,  1563,  1902,  1564,
    1908,  1893,  1894,  1895,  1898,  2116,  2117,  2118,  2119,  1899,
    2120,  1900,  2121,  1901,  1907,  1909,  1914,  1915,  2124,  2125,
    2126,  1918,  1920,  2127,  2128,  2129,  2130,  1921,  2131,  1922,
    2132,  1923,  2133,  1924,  1925,  2134,  2135,  2136,  2137,  1929,
    2319,  1926,  2138,  1927,  1928,  2140,  1932,  1933,  1934,  1935,
    1936,  1937,  1938,  1939,  1951,  2144,  1941,  2145,  1943,  1950,
    1954,  2149,  2150,  1955,  2151,  2152,  2153,  2154,  2155,  2156,
    2157,  2158,  2159,  2160,  2161,  2162,  1956,  2163,  1957,  1958,
    1959,  1960,  1961,  1962,  1963,  1964,  2171,  2172,  2173,  2174,
    2175,  2176,  2177,  2178,  2179,  1965,  1966,  1967,  1968,  1969,
    1970,  1971,  1972,  1973,  1974,  1975,  1976,  1977,  2188,  2189,
    2190,  2191,  1978,  1979,  1980,  2194,  2195,  2196,  2197,  1981,
    1983,  1982,  1984,  1985,  1986,  2202,  2203,  2204,  2205,  2206,
    2207,  2208,  2209,  2210,  2211,  2212,  1987,  1988,  1989,  1990,
    1991,  1992,  1993,  2213,  2214,  2215,  1994,  2216,  2217,  1995,
    2219,  2220,  1996,  1997,  2222,  1999,  2223,  2000,  2005,  2272,
    2003,  2004,  2006,  2007,  2012,  2008,  2009,  2226,  2010,  2011,
    2024,  2013,  2022,  2023,  2025,  2026,  2232,  2233,  2030,  2031,
    2034,  2235,  2037,  2038,  2039,  2239,  2043,  2041,  2049,  2050,
    2046,  2051,  2052,  2055,  2056,  2060,  2057,  2064,  2273,   828,
    2065,  2245,  2061,  2246,  2062,  2063,  2066,  2067,  2068,  2069,
    2070,  2071,  2274,  2479,  2074,  2075,  2104,  2247,  2072,  2073,
    2077,  2078,  2076,  2079,  2082,  2083,  2097,   363,  2084,  2269,
    2085,  2086,  2249,  2089,  2250,  2090,  2093,  2094,  2095,  2251,
    2096,  2100,  2101,  2102,  2103,  2252,  2105,  2106,  2107,  2254,
    2255,  2109,  2256,  2258,  2259,  2110,  2260,  2261,  2111,  2112,
    2264,  2265,  2113,  2266,  2114,  2229,  2230,  2231,  2240,  2241,
    2253,  2727,  2275,  2276,  2321,  2800,  2278,  2320,  2279,  2280,
    2281,  2322,  2323,  2324,  2325,  2326,  2282,  2327,  2328,  2283,
    2329,  2284,  2330,  2728,  2333,  2285,  2286,  2331,  2287,  2332,
    2338,  2334,  2335,  2336,  2288,  2337,  2343,  2289,  2339,  2290,
    2340,  2291,  2292,  2293,  2341,  2342,  2344,  2345,  2346,  2348,
    2349,  2350,  2294,  2295,  2351,  2356,  2296,  2354,  2355,  2357,
    2358,  2297,  2298,  2299,  2300,  2301,  2302,  2359,  2303,  2304,
    2305,  2360,  2306,  2307,  2308,  2309,  2310,  2361,  2362,  2311,
    2312,  2313,  2314,  1593,  2317,  2363,  2364,  2365,  2366,  2367,
    2368,  2369,  2370,  2371,  2372,  2373,  2374,  2375,   364,  2376,
    2377,  2378,  2379,  2380,  2381,  2199,  2613,  2382,  2383,  2384,
    2385,  2386,  2387,  2388,  2389,  2390,  2392,  2391,  2393,  2394,
    2395,  2396,  2347,  2397,  2400,  2398,  2401,  2402,  2399,  2403,
    2405,  2404,  2406,  2410,  2407,  2411,  2412,  2408,  2413,     1,
    2409,     2,     3,     4,     5,  2419,  2414,  2415,  2416,  2420,
    2421,  2423,  1566,  2426,  2429,  2422,  2424,  2430,  2425,  2431,
      12,  2427,  2428,  2434,  2432,   826,  2433,  2236,  2237,  2238,
    2435,  2436,    21,  2437,  2438,  2439,  2440,  2441,  2442,    24,
    2444,    25,  2446,    27,   185,   186,   187,   218,   188,    33,
    2445,   213,   190,  2447,  2448,  2449,  2450,   191,  2451,   192,
     193,  2452,  2459,  2460,  2461,  2462,  2463,  2464,  2468,  2465,
    2466,  2470,  2467,  2471,  2478,  2472,  2473,  2474,  2480,  2931,
    2227,  2481,  2482,  2443,  2483,  2484,  2485,  2486,  2487,  2488,
    2489,  2490,  2491,  2496,  2492,  2493,  2494,  2495,  2497,  2501,
    2498,  2499,  2500,  2504,  2505,  2506,  2507,  2469,  2508,  1917,
    2519,  2596,  2649,  2509,  2653,  2512,    50,    51,    52,    53,
      54,  2513,  2514,  2515,  2516,  2517,  2518,  2652,  2654,  2655,
    2656,  2657,  2658,  2659,  2660,  2661,   194,  2662,  2663,  2669,
    2664,  2665,  2667,  2668,    58,   365,   195,  2672,  2673,  2674,
    2683,  2684,  2685,  2686,  2687,  2692,  2693,  2694,  2695,  2698,
    2520,  2699,  2521,  2700,  2522,  2701,  2523,  2702,  2703,  2704,
    2705,  2524,  2525,  2706,  2526,  2527,  2528,  2529,  2707,  2530,
    2531,  2532,  2533,  2708,  2709,  2710,  2534,  2711,  2712,  2535,
    2537,  2713,  2714,  2715,  2718,  2543,    63,  2725,  2729,  2730,
    2544,  2716,  2545,  2546,  2547,  2548,  2549,  2550,  2551,  2552,
    2717,  2553,  2555,  2557,  2558,  2559,  2560,  2561,  2562,  2563,
    2564,  2565,  2566,  2567,  2568,  2719,  2569,  2720,  2721,    64,
    2722,    65,  2723,  2724,  2575,  2726,  2731,  2732,  2576,  2577,
    2733,  2734,  2735,  2736,  2737,  2740,  2947,  2741,  2580,  2581,
    2743,  2748,  2742,  2744,  2747,  2749,  2754,  3058,  2582,  2583,
    2584,  2585,  2586,  2751,  2587,  2588,  2752,  2589,  2590,  2753,
    2755,  2538,  2591,  2592,  2539,  2593,  2594,  2756,  2757,  2758,
    2759,  2760,  2761,  2762,  2763,  2597,  2764,  2765,  2766,  2599,
    2767,  2600,  2601,  2768,  2769,  2770,  2776,  2771,  2772,    77,
      78,  2606,  2607,  2608,  2773,  2774,  2611,  2612,  2775,  2777,
    2778,  2779,  2614,  2780,  2616,  2784,  2617,  2618,  2781,  2619,
    2620,  2621,  2622,  2623,  2624,  2625,  2782,  2626,  2627,  2628,
    2629,  2630,  2631,  2632,  2633,  2634,  2783,  2635,  2636,  2637,
    2638,  2785,  2869,  2870,  2871,  2872,  2873,  2875,  2874,  2876,
    2877,  2641,  2642,  2643,  2644,     0,  2883,  2647,  2648,  2878,
    2881,  2882,     0,  2886,  2887,  2892,  2893,  2894,  2895,    80,
      81,  2896,  2897,  2898,  2899,  2900,  2901,  2902,  2905,  2903,
    2907,  2908,  2909,  2910,   366,  2911,     0,   799,  2912,  2913,
    2914,  2915,  2916,  2917,  2920,  2921,  2924,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,  2925,    92,  2926,
    2927,  2928,  2929,  2930,  2932,  2933,  2750,  2934,    95,    96,
      97,    98,    99,   100,   101,   102,  2937,  2938,   103,   104,
     105,   106,   107,   108,   109,  2939,  2940,  2941,  2942,  2943,
    2944,  2948,  2945,  2946,  2949,  2950,  2951,  2952,   115,  2953,
    3016,  2954,  2955,  1540,  2956,  2957,  3021,  3017,  3018,  3019,
    3020,  3022,  3024,  3023,  3025,  3026,  3027,  3028,  3029,  3030,
    3031,  3032,  1565,  3036,  1408,  3038,  3039,     0,  3033,  3041,
    3037,  3042,  3043,  3040,  3044,  3046,  3045,  3047,  3048,   129,
    3049,  2786,  2787,     0,  2788,  2789,  3052,  2790,  2791,  3050,
    2792,  2793,  2794,  3051,  2795,  2796,  3053,  3054,  2798,  3055,
    3056,  3057,  3059,  2801,  2802,  3060,  2803,  3061,  2804,  3062,
    2805,     0,  2806,  2807,  2808,  2809,  2810,  3063,  3064,  3065,
    2811,  2812,  2813,  2814,  2815,  2816,  2595,  2817,  2819,  2821,
    2823,  2824,  2825,  2826,  3066,  2827,  2828,  2829,  2830,  2831,
    3067,  2833,  3068,  3069,  3070,  3073,  2834,  2835,  3074,  2836,
    2837,  2838,  2839,  2840,  2841,  3075,  2842,  2843,  2844,  3110,
    3111,  3112,  2846,  3113,  2847,  3118,  2848,  3115,  3116,  2849,
    3117,  2850,  2851,  3119,  2852,  3120,  3121,  3122,  2797,  3125,
    3123,  2855,  2799,  2857,  3124,  3128,  2858,  2859,  3126,  3127,
    3131,     0,  3134,  3135,  3136,  3138,  3139,  3140,  3141,  3142,
    3145,  2860,  2861,  2862,  2863,  2864,  3167,  3168,  3169,  3170,
    3171,  2866,  2867,  2868,  3172,  3176,  3177,  3173,  3174,  3175,
    3178,  3182,     0,  3179,  3180,  3181,  3185,  3203,  3183,  3184,
    3201,  3202,  3205,  3208,  3204,  3206,  3207,  3209,  3210,  3220,
    3211,  3219,  3221,  3222,  3224,  3225,  3223,  3230,  3231,  3232,
    3233,  3243,  3237,  3238,  3239,  3244,  3249,  3251,  3245,  3248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2958,
       0,     0,  2959,  2960,  2961,     0,     0,     0,  2962,     0,
    2963,  2964,     0,     0,     0,     0,  2967,  2968,     0,  2969,
       0,  2970,  2971,  2972,  2973,  2974,  2975,     0,  2976,  2977,
    2978,  2979,  2980,  2981,  2821,     0,  2821,     0,     0,  2821,
    2821,  2986,  2987,  2988,     0,     0,     0,     0,     0,  2993,
    2994,     0,     0,  2995,     0,     0,     0,  2996,  2997,  2998,
       0,     0,  2999,     0,     0,     0,  3000,  3001,     0,     0,
    3002,  3003,     0,     0,  3005,     0,  3007,  3008,     0,     0,
    3009,  3010,     0,  3011,     0,  3013,  3014,  3015,     0,     0,
       0,     0,     0,     0,     0,     0,  2966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2845,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3076,  3077,  3078,
    3079,     0,  3081,  3082,     0,     0,  3083,     0,     0,     0,
       0,     0,     0,  3084,     0,  3085,     0,  3086,     0,     0,
    3087,     0,     0,     0,     0,  2821,     0,     0,     0,     0,
    3089,  3090,     0,  3091,     0,  3092,     0,  3093,  3094,  3095,
       0,  3096,  3097,     0,  3099,     0,  3101,     0,  3103,  3104,
    3105,     0,     0,  3107,  3108,  3109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3146,     0,     0,     0,  3148,  3149,     0,     0,
       0,  3150,     0,  3151,  3152,     0,  3153,  3154,     0,     0,
       0,  3156,     0,     0,  3158,  3159,  3160,  2965,  3161,  3162,
    3163,  3164,     0,     0,  3165,  3166,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,   211,   211,   211,     0,
       0,     0,     0,     0,     0,     0,     0,  3190,     0,   225,
       0,     0,   229,  3191,  3192,  3193,   237,     0,     0,  3194,
    3195,     0,     0,  3197,  3198,     0,     0,  3199,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,     0,     0,
       0,  3212,  3213,     0,  3214,     0,  3215,     0,     0,  3217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3226,
       0,  3227,  3228,  3229,     0,     0,     0,     0,     0,     0,
    3234,  3235,  3236,     0,     0,     0,     0,  3240,  3241,  3242,
       0,     0,     0,     0,  3246,  3247,     0,     0,  3250,     0,
       0,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3080,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   211,   211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,     0,     0,     0,     0,     0,     0,
    3147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
     612,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   687,   690,
     687,   687,   693,   687,   695,   687,   697,     0,     0,     0,
       0,   751,   752,   753,   687,   756,   757,   758,   759,   760,
     761,   762,   763,     0,     0,     0,   767,   769,     0,     0,
       0,   687,   792,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   210,   214,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   280,     0,     0,     0,   237,     0,
     805,   806,   807,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   237,   237,   237,     0,     0,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   687,   612,     0,
     211,     0,   211,   211,     0,     0,   687,   612,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
     321,   323,   325,   327,   329,   331,   333,   335,   337,   339,
     341,   343,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   372,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1012,  1012,   612,  1020,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   319,   321,
     323,   325,   327,   329,   331,   333,   335,   337,   339,   341,
     343,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1012,  1012,  1012,  1012,
    1012,  1012,  1012,  1012,  1012,  1012,  1012,  1012,  1012,   687,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1012,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,     0,     0,     0,     0,     0,     0,
     687,   687,  1186,     0,     0,     0,     0,   687,   687,   687,
     687,   687,   687,   687,   687,   687,   687,   687,   687,   687,
     687,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   813,   814,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   852,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   214,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,     0,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   319,   321,   323,   325,   327,   329,
     331,   333,   335,   337,   339,   341,   343,     0,     0,  1012,
    1012,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   372,  1012,  1012,  1012,  1012,  1012,  1012,  1012,
    1012,  1012,  1012,  1012,  1012,  1012,     0,  1012,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1373,     0,     0,     0,     0,     0,  1379,     0,     0,
    1383,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     687,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1422,     0,     0,     0,
       0,   612,  1428,  1430,   687,   687,  1433,  1434,  1435,  1436,
    1437,   687,  1439,  1440,  1441,  1442,  1443,     0,  1446,  1447,
    1448,  1449,     0,   687,   687,  1455,     0,     0,  1458,  1459,
    1460,  1461,  1462,  1463,  1464,  1465,  1466,   687,  1468,  1469,
    1470,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,
    1480,   687,   687,   687,   687,   687,  1486,  1487,  1488,  1489,
    1490,     0,     0,   237,   237,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,   687,  1509,
    1510,  1511,  1512,  1513,  1514,   687,   687,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   687,   687,   687,  1520,   687,   687,     0,   687,   687,
     687,   687,   237,     0,   612,     0,   612,  1538,   687,   687,
    1012,  1012,  1012,  1012,  1012,  1012,  1012,  1012,  1012,  1012,
     687,   687,   687,   687,   687,     0,     0,   237,   237,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   687,     0,     0,   687,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1597,     0,  1599,     0,     0,
       0,  1603,  1604,  1605,  1606,     0,     0,     0,     0,     0,
       0,     0,  1614,     0,  1616,  1617,  1618,  1620,  1621,  1623,
    1625,  1626,  1627,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1643,     0,
     687,     0,     0,     0,     0,     0,     0,   214,   216,     0,
    1653,  1654,  1655,     0,     0,     0,     0,     0,     0,     0,
     237,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   343,     0,   372,     0,     0,   237,  1672,
    1673,     0,     0,     0,     0,     0,     0,   237,  1680,     0,
    1681,  1682,  1684,  1686,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   687,     0,
       0,     0,     0,     0,     0,     0,     0,  1708,   687,     0,
     687,     0,     0,  1714,     0,     0,     0,   687,  1719,     0,
       0,     0,   687,   687,   687,   237,   687,  1728,     0,  1730,
       0,     0,   687,   237,     0,   687,   687,   687,   687,   687,
       0,     0,     0,   237,     0,   612,   237,     0,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,     0,   145,   145,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,  1012,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1542,  1544,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,  1912,     0,     0,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   687,     0,     0,   687,     0,  1945,  1946,
    1947,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,     0,   687,
     610,   610,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   686,     0,
     686,   686,   612,   686,     0,   686,     0,     0,     0,     0,
       0,     0,     0,   686,   686,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   788,
       0,   686,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2122,  2123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   686,   610,     0,
     145,   788,   145,   145,     0,     0,   686,   953,  2139,     0,
     687,     0,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,     0,   687,  2148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2164,  2165,   687,   687,  2168,  2169,  2170,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2180,     0,  2181,  2182,  2183,  2184,  2185,     0,
    2186,  2187,     0,     0,     0,     0,   687,   687,     0,     0,
       0,     0,     0,  2198,   237,     0,     0,  2200,  2201,     0,
       0,     0,     0,   610,   610,   610,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2218,     0,     0,  2221,     0,     0,     0,
       0,   687,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   687,  2228,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   237,   237,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   687,     0,
       0,     0,     0,  2244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2248,     0,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   686,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   610,     0,   612,     0,     0,     0,
       0,     0,  2262,  2263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     686,   686,   686,     0,     0,     0,     0,   686,   686,   686,
     686,   686,   686,   686,   686,   686,   686,   686,   686,   686,
     686,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   612,   687,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   788,   788,   788,     0,   788,
     788,   788,   788,   788,   788,   788,   788,   788,   788,   788,
     788,   788,   788,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   953,
     953,   953,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   953,   953,   953,   953,   953,   953,   953,
     953,   953,   953,   953,   953,   953,     0,   953,     0,     0,
       0,     0,     0,  2536,     0,     0,     0,  2540,  2542,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2554,  2556,     0,     0,     0,
     686,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2570,  2571,  2572,  2573,  2574,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   687,     0,
       0,   687,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   610,   686,     0,   686,   686,     0,     0,     0,     0,
       0,   686,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   686,   686,   237,     0,     0,     0,     0,
       0,     0,  2598,     0,     0,     0,     0,   686,   687,     0,
     687,     0,   687,     0,   687,     0,     0,     0,  2609,  2610,
       0,   686,   686,   686,   686,   686,     0,  2615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   686,     0,
       0,     0,     0,     0,     0,   686,   686,  2639,     0,     0,
       0,     0,     0,   687,     0,     0,     0,     0,     0,   687,
     687,   686,   686,   686,     0,   686,   686,     0,   686,   686,
     686,   686,     0,     0,   610,     0,   610,     0,   686,   686,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     686,   686,   686,   686,   686,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   686,     0,     0,   686,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     686,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2540,     0,     0,     0,  2540,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,  1538,  1538,  1538,     0,     0,     0,     0,   686,     0,
       0,     0,     0,     0,  2832,     0,     0,     0,   686,     0,
     686,     0,     0,     0,     0,     0,     0,   686,     0,     0,
       0,     0,   686,   686,   686,   237,   686,     0,     0,     0,
       0,     0,   686,     0,     0,   686,   686,   686,   686,   686,
     687,  2854,     0,     0,     0,   610,  2856,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   687,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,     0,
       0,     0,   610,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,     0,     0,  2540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1538,     0,
    1538,     0,     0,  1538,  1538,     0,     0,     0,  2989,  2990,
    2991,  2992,     0,     0,     0,     0,     0,   478,   479,     0,
       0,     0,     0,   632,   632,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3004,     0,  3006,
       0,     0,     0,     0,     0,     0,     0,     0,   687,     0,
       0,   689,     0,   689,   689,     0,   689,     0,   689,     0,
       0,     0,     0,     0,     0,     0,   689,   689,     0,     0,
       0,     0,     0,   686,     0,     0,   686,     0,     0,     0,
       0,     0,     0,     0,   689,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   686,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3098,     0,  3100,
     689,   632,   610,     0,     0,     0,   687,     0,   921,   689,
     958,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   182,   183,   184,   687,     0,     0,     0,
       0,     0,     0,     0,  1535,     0,     0,     0,     0,   237,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,   687,     0,     0,   687,     0,     0,
      24,     0,    25,     0,    27,   185,   186,   187,   218,  1536,
      33,     0,   189,   190,     0,     0,     0,     0,   191,     0,
     192,   193,     0,     0,     0,     0,   632,   632,   632,  1021,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3196,     0,     0,     0,     0,
     686,     0,     0,   687,     0,     0,   610,     0,     0,     0,
       0,     0,     0,   686,     0,     0,     0,     0,     0,     0,
       0,  3216,     0,     0,     0,   687,     0,    50,    51,    52,
      53,    54,     0,     0,   686,   686,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,     0,     0,
       0,     0,     0,     0,     0,    58,     0,   195,     0,     0,
       0,     0,     0,     0,     0,     0,   686,   686,     0,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   689,     0,     0,     0,     0,     0,     0,     0,
       0,   631,   631,     0,     0,     0,     0,   632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,   686,     0,     0,     0,     0,     0,     0,     0,   688,
       0,   691,   692,   686,   694,     0,   696,     0,     0,     0,
       0,     0,     0,     0,   754,   755,     0,     0,     0,     0,
      64,     0,    65,     0,     0,     0,     0,     0,   686,     0,
       0,     0,   791,   689,   689,   689,     0,     0,     0,     0,
     689,   689,   689,   689,   689,   689,   689,   689,   689,   689,
     689,   689,   689,   689,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   610,     0,     0,     0,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   848,   851,
       0,     0,     0,     0,     0,     0,     0,   924,   955,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   610,   686,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,   196,   197,   198,   199,   200,   201,     0,     0,   202,
     203,   204,   205,   206,   207,   208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   632,   632,   632,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,     0,
     632,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   689,     0,     0,     0,     0,     0,     0,
     921,     0,     0,     0,     0,     0,  1406,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   632,   689,     0,   689,   689,     0,
       0,     0,     0,     0,   689,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,   689,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     689,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   689,   689,   689,   689,   689,     0,
       0,     0,     0,     0,  1491,  1492,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   689,     0,     0,     0,     0,     0,     0,   689,   689,
       0,     0,     0,     0,     0,     0,     0,     0,   686,     0,
       0,   686,     0,     0,   689,   689,   689,     0,   689,   689,
       0,   689,   689,   689,   689,     0,     0,   632,     0,   632,
       0,   689,   689,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   689,   689,   689,   689,   689,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   686,     0,
     686,     0,   686,     0,   686,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   689,     0,     0,   689,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   686,     0,     0,     0,     0,     0,   686,
     686,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   689,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   689,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   689,     0,   689,     0,     0,     0,     0,     0,     0,
     689,  1393,  1720,  1721,  1722,   689,   689,   689,     0,   689,
       0,  1729,     0,  1731,  1732,   689,     0,     0,   689,   689,
     689,   689,   689,     0,     0,     0,     0,     0,   632,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   631,  1429,     0,  1431,  1432,     0,     0,     0,
       0,     0,  1438,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1453,  1454,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1467,     0,
       0,     0,     0,     0,     0,   632,     0,     0,     0,     0,
       0,     0,  1481,  1482,  1483,  1484,  1485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1508,
       0,     0,     0,     0,     0,     0,  1515,  1516,     0,     0,
     686,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1517,  1518,  1519,     0,  1521,  1522,     0,  1524,
    1525,  1526,  1527,     0,     0,  1533,     0,  1534,     0,     0,
       0,     0,     0,   686,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1913,     0,     0,     0,
       0,     0,     0,  1429,     0,     0,  1534,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   921,     0,   689,     0,     0,   689,
       0,  1644,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,   182,   183,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,   689,     0,     0,    24,     0,    25,     0,    27,
     185,   186,   187,   218,   188,    33,     0,   189,   190,  1699,
       0,     0,     0,   191,     0,   192,   193,     0,   686,  1709,
       0,  1711,     0,     0,     0,   632,     0,     0,  1718,     0,
       0,     0,     0,  1723,  1724,  1725,     0,  1727,     0,     0,
       0,     0,     0,  1733,     0,     0,  1736,  1737,  1738,  1739,
    1740,     0,     0,     0,     0,     0,   631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,     0,     0,     0,     0,     0,     0,     0,
      58,     0,   195,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   686,     0,     0,     0,
       0,     0,     0,   689,     0,     0,     0,     0,     0,   632,
       0,     0,    63,     0,     0,     0,   689,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   686,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   689,   689,     0,
       0,     0,     0,     0,     0,    64,     0,    65,     0,     0,
       0,     0,     0,     0,   686,     0,     0,   686,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   689,
     689,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   686,   689,    77,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,     0,     0,     0,
       0,     0,     0,     0,     0,   686,     0,     0,     0,     0,
       0,     0,     0,     0,  1942,     0,     0,     0,     0,     0,
       0,   689,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1998,     0,     0,     0,     0,     0,     0,     0,     0,   632,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,  2033,    95,    96,   196,   197,   198,   199,
     200,   201,     0,     0,   202,   203,   204,   205,   206,   207,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,     0,     0,     0,   632,
     689,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2166,  2167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   360,
       0,     0,     0,     0,     0,     0,     1,     0,     2,     3,
       4,     5,     0,     0,     0,     0,     0,  2192,  2193,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,     0,     0,     0,    24,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,    37,  2224,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
      57,    58,    59,    60,     0,     0,     0,  2257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,   689,     0,     0,   689,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,     0,    65,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
       0,    72,     0,     0,     0,     0,     0,  2315,  2316,     0,
       0,   689,     0,   689,     0,   689,     0,   689,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,    78,     0,     0,
       0,     0,     0,     0,     0,     0,   689,     0,     0,     0,
       0,     0,   689,   689,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,    93,     0,     0,    94,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,   110,     0,     0,     0,   111,     0,   112,
     113,     0,     0,     0,   114,   115,     0,   116,     0,     0,
       0,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,     0,     0,     0,   119,   120,     0,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   689,     0,     0,     0,     0,     0,  2578,
       0,     0,  2579,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2602,
       0,  2603,     0,  2604,     0,  2605,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,  2640,     2,   925,   926,   927,     0,
    2645,  2646,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,   928,   494,   929,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,    24,     0,    25,     0,    27,   185,   186,
     187,   218,   849,    33,   930,   213,   190,   931,     0,   497,
       0,   191,   932,   192,   193,     0,     0,     0,     0,     0,
       0,     0,     0,   933,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   689,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,   498,    52,    53,    54,   499,   500,   501,   502,   503,
     504,   505,   506,     0,   507,     0,   508,   509,   510,   511,
     512,   513,   514,     0,   515,   516,     0,     0,    58,     0,
     517,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,     0,     0,     0,     0,   531,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   689,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,    64,   545,    65,   546,   547,   548,   549,
     550,  2853,     0,     0,     0,     0,     0,   551,     0,   689,
       0,   900,   901,   902,     0,     0,   552,   553,   554,   555,
     903,   904,   905,   906,   556,   907,   557,     0,     0,     0,
       0,     0,     0,     0,  2865,     0,     0,   689,     0,     0,
     689,     0,     0,   558,   559,   560,   561,     0,     0,     0,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,     0,    77,    78,   908,     0,     0,   909,   910,
     911,   912,     0,   913,   914,   574,   575,   934,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   689,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   935,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   576,   577,   578,
     579,    82,   936,    84,    85,   937,    87,    88,    89,    90,
      91,     0,    92,     0,   580,   581,     0,   938,     0,     0,
       0,     0,    95,    96,   939,   940,   941,   942,   943,   944,
       0,     0,   945,   946,   947,   948,   949,   950,   951,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3012,
       0,     0,   115,   596,     0,     0,     0,     0,     0,     0,
       0,     0,   597,   598,   599,   600,     0,   601,   602,     0,
     916,   917,   918,   603,   604,     0,   919,     0,   920,   605,
     606,   607,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,   925,   926,   927,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,   493,   494,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,    24,     0,    25,     0,    27,   185,   186,   187,
     218,   849,    33,   496,   213,   190,     0,  3106,   497,     0,
     191,     0,   192,   193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3155,     0,     0,  3157,    50,
     498,    52,    53,    54,   499,   500,   501,   502,   503,   504,
     505,   506,     0,   507,     0,   508,   509,   510,   511,   512,
     513,   514,     0,   515,   516,     0,     0,    58,     0,   517,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3200,     0,     0,     0,     0,     0,
       0,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,     0,     0,  3218,     0,   531,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,    64,   545,    65,   546,   547,   548,   549,   550,
       0,     0,     0,     0,     0,     0,   551,     0,     0,     0,
       0,     0,     0,     0,     0,   552,   553,   554,   555,     0,
       0,     0,     0,   556,     0,   557,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   558,   559,   560,   561,     0,     0,     0,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,     0,    77,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   576,   577,   578,   579,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    92,     0,   580,   581,     0,     0,     0,     0,     0,
       0,    95,    96,   939,   940,   941,   942,   943,   944,     0,
       0,   945,   946,   947,   948,   949,   950,   951,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   596,     0,     0,     0,     0,     0,     0,     0,
       0,   597,   598,   599,   600,     0,   601,   602,     0,     0,
       0,     0,   603,   604,     0,     0,     0,     0,   605,   606,
     607,     1,     0,     2,   489,   490,   491,     0,     0,     0,
     492,     0,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,   493,   494,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,    24,     0,    25,     0,    27,   185,   186,   187,   218,
     495,    33,   496,   189,   190,     0,     0,   497,     0,   191,
       0,   192,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,   498,
      52,    53,    54,   499,   500,   501,   502,   503,   504,   505,
     506,     0,   507,     0,   508,   509,   510,   511,   512,   513,
     514,     0,   515,   516,     0,     0,    58,     0,   517,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,     0,     0,     0,     0,   531,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,    64,   545,    65,   546,   547,   548,   549,   550,     0,
       0,     0,     0,     0,     0,   551,     0,     0,     0,     0,
       0,     0,     0,     0,   552,   553,   554,   555,     0,     0,
       0,     0,   556,     0,   557,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   558,   559,   560,   561,     0,     0,     0,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
       0,    77,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   576,   577,   578,   579,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,   580,   581,     0,     0,     0,     0,     0,     0,
      95,    96,   582,   583,   584,   585,   586,   587,     0,     0,
     588,   589,   590,   591,   592,   593,   594,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   596,     0,     0,     0,     0,     0,     0,     0,     0,
     597,   598,   599,   600,     0,   601,   602,     0,     0,     0,
       0,   603,   604,     0,     0,     0,     0,   605,   606,   607,
       1,     0,     2,   489,   490,   491,     0,     0,     0,  1529,
       0,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,   493,   494,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
      24,     0,    25,     0,    27,   185,   186,   187,   218,  1530,
      33,   496,   189,   190,     0,     0,   497,     0,   191,     0,
     192,   193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,   498,    52,
      53,    54,   499,   500,   501,   502,   503,   504,   505,   506,
       0,   507,     0,   508,   509,   510,   511,   512,   513,   514,
       0,   515,   516,     0,     0,    58,     0,   517,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,     0,     0,     0,     0,   531,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
      64,   545,    65,   546,   547,   548,   549,   550,     0,     0,
       0,     0,     0,     0,   551,     0,     0,     0,     0,     0,
       0,     0,     0,   552,   553,   554,   555,     0,     0,     0,
       0,   556,     0,   557,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,   559,   560,   561,     0,     0,     0,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,     0,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   576,   577,   578,   579,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
       0,   580,   581,     0,     0,     0,     0,     0,     0,    95,
      96,   582,   583,   584,   585,   586,   587,     0,     0,   588,
     589,   590,   591,   592,   593,   594,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     596,     0,     0,     0,     0,     0,     0,     0,     0,   597,
     598,   599,   600,     0,   601,   602,     0,     0,     0,     0,
     603,   604,     0,     0,     0,     0,   605,   606,   607,     1,
       0,     2,   489,   490,   491,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,   493,   494,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    24,
       0,    25,     0,    27,   185,   186,   187,   218,   849,    33,
     496,   189,   190,     0,     0,   497,     0,   191,     0,   192,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,   498,    52,    53,
      54,   499,   500,   501,   502,   503,   504,   505,   506,     0,
     507,     0,   508,   509,   510,   511,   512,   513,   514,     0,
     515,   516,     0,     0,    58,     0,   517,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,     0,     0,     0,     0,   531,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,    64,
     545,    65,   546,   547,   548,   549,   550,     0,     0,     0,
       0,     0,     0,   551,     0,     0,     0,     0,     0,     0,
       0,     0,   552,   553,   554,   555,     0,     0,     0,     0,
     556,     0,   557,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   558,
     559,   560,   561,     0,     0,     0,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,     0,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   574,   575,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   576,   577,   578,   579,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,    92,     0,
     580,   581,     0,     0,     0,     0,     0,     0,    95,    96,
     582,   583,   584,   585,   586,   587,     0,     0,   588,   589,
     590,   591,   592,   593,   594,   595,     0,     0,     0,     0,
       0,     1,     0,     2,   925,   926,   927,     0,   115,   596,
       0,     0,     0,     0,     0,     0,     0,     0,   597,   598,
     599,   600,    12,   601,   602,   493,   494,     0,     0,   603,
     604,     0,     0,     0,     0,   605,   606,   607,     0,     0,
       0,     0,     0,    25,     0,    27,   185,   186,   187,   129,
     849,    33,   496,   213,   190,     0,     0,   497,     0,   191,
       0,   192,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,   498,
      52,    53,    54,   499,   500,   501,   502,   503,   504,   505,
     506,     0,   507,     0,   508,   509,   510,   511,   512,   513,
     514,     0,   515,   516,     0,     0,     0,     0,   517,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,     0,     0,     0,     0,   531,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,    64,   545,    65,   546,   547,   548,   549,   550,     0,
       0,     0,     0,     0,     0,   551,     0,     0,     0,     0,
       0,     0,     0,     0,   552,   553,   554,   555,     0,     0,
       0,     0,   556,     0,   557,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   558,   559,   560,   561,     0,     0,     0,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
       0,    77,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   576,   577,   578,   579,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,   580,   581,     0,     0,     0,     0,     0,     0,
      95,    96,   939,   940,   941,   942,   943,   944,     0,     0,
     945,   946,   947,   948,   949,   950,   951,   595,     0,     0,
       0,     0,     0,     1,     0,     2,   489,   490,   491,     0,
     115,   596,     0,     0,     0,     0,     0,     0,     0,     0,
     597,   598,   599,   600,    12,   601,   602,   493,   494,     0,
       0,   603,   604,     0,     0,     0,     0,   605,   606,   607,
       0,     0,     0,     0,     0,    25,     0,    27,   185,   186,
     187,   129,   849,    33,   496,   189,   190,     0,     0,   497,
       0,   191,     0,   192,   193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,   498,    52,    53,    54,   499,   500,   501,   502,   503,
     504,   505,   506,     0,   507,     0,   508,   509,   510,   511,
     512,   513,   514,     0,   515,   516,     0,     0,     0,     0,
     517,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,     0,     0,     0,     0,   531,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,    64,   545,    65,   546,   547,   548,   549,
     550,     0,     0,     0,     0,     0,     0,   551,     0,     0,
       0,     0,     0,     0,     0,     0,   552,   553,   554,   555,
       0,     0,     0,     0,   556,     0,   557,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   558,   559,   560,   561,     0,     0,     0,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,     0,    77,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   576,   577,   578,
     579,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,     0,   580,   581,     0,     0,     0,     0,
       0,     0,    95,    96,   582,   583,   584,   585,   586,   587,
       0,     0,   588,   589,   590,   591,   592,   593,   594,   595,
       0,     0,     0,     0,     0,     1,     0,     2,   489,   490,
    1802,     0,   115,   596,     0,     0,     0,     0,     0,     0,
       0,     0,   597,   598,   599,   600,    12,   601,   602,   493,
     494,     0,     0,   603,   604,     0,     0,     0,     0,   605,
     606,   607,     0,     0,     0,     0,     0,    25,     0,    27,
     185,   186,   187,   129,   849,    33,   496,   189,   190,     0,
       0,   497,     0,   191,     0,   192,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,   498,    52,    53,    54,   499,   500,   501,
     502,   503,   504,   505,   506,     0,   507,     0,   508,   509,
     510,   511,   512,   513,   514,     0,   515,   516,     0,     0,
       0,     0,   517,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,     0,     0,     0,
       0,   531,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,    64,   545,    65,   546,   547,
     548,   549,   550,     0,     0,     0,     0,     0,     0,   551,
       0,     0,     0,     0,     0,     0,     0,     0,   552,   553,
     554,   555,     0,     0,     0,     0,   556,     0,   557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   558,   559,   560,   561,     0,
       0,     0,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,     0,    77,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   574,   575,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   576,
     577,   578,   579,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92,     0,   580,   581,     0,     0,
       0,     0,     0,     0,    95,    96,   582,   583,   584,   585,
     586,   587,     0,     0,   588,   589,   590,   591,   592,   593,
     594,   595,     0,     0,     0,     0,     0,     1,     0,     0,
     666,   667,   668,     0,   115,   596,     0,     0,     0,     0,
       0,     0,     0,     0,   597,   598,   599,   600,     0,   601,
     602,   493,   494,     0,     0,   603,   604,     0,     0,     0,
       0,   605,   606,   607,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,   129,   669,    33,   496,     0,
       0,     0,     0,   497,     0,     0,     0,   192,   193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   670,     0,     0,     0,   499,
     500,   501,   502,   503,   504,   505,   506,     0,   507,     0,
     508,   509,   510,   511,   671,   513,   514,     0,   515,   516,
       0,     0,     0,     0,   672,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,     0,
       0,     0,     0,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,     0,   545,     0,
     546,   547,   548,   549,   550,     0,     0,     0,     0,     0,
       0,   551,     0,     0,     0,     0,     0,     0,     0,     0,
     552,   553,   554,   555,     0,     0,     0,     0,   556,     0,
     557,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   558,   559,   560,
     561,     0,     0,     0,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   574,
     575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,   577,   578,   579,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,   580,   581,
       0,     0,     0,     0,     0,     0,     0,     0,   673,   674,
     675,   676,   677,   678,     0,     0,   679,   680,   681,   682,
     683,   684,   685,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   596,     0,     0,
       0,     0,     0,     0,     0,     0,   597,   598,   599,   600,
       0,   601,   602,     0,     0,     0,     0,   603,   604,     0,
       0,     0,     0,   605,   606,   607,     1,     0,     2,     3,
       4,     5,     0,     0,     0,     0,     0,   129,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,     0,     0,     0,    24,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,    37,     0,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,     0,    65,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
       0,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,    93,     0,     0,    94,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,   110,     0,     0,     0,   111,     0,   112,
     113,     0,     0,     0,   114,   115,     0,   116,     1,     0,
       0,   666,   667,   668,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,   493,   494,     0,   119,   120,     0,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,   669,    33,   496,
       0,     0,     0,     0,   497,     0,     0,     0,   192,   193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   670,     0,     0,     0,
     499,   500,   501,   502,   503,   504,   505,   506,     0,   507,
       0,   508,   509,   510,   511,   671,   513,   514,     0,   515,
     516,     0,     0,     0,     0,   672,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
       0,     0,     0,     0,   531,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,     0,   545,
       0,   546,   547,   548,   549,   550,     0,     0,     0,     0,
       0,     0,   551,     0,     0,     0,     0,     0,     0,     0,
       0,   552,   553,   554,   555,     0,     0,     0,     0,   556,
       0,   557,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   558,   559,
     560,   561,     0,     0,     0,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   923,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   576,   577,   578,   579,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   580,
     581,     0,     0,     0,     0,     0,     0,     0,     0,   673,
     674,   675,   676,   677,   678,     0,     0,   679,   680,   681,
     682,   683,   684,   685,   595,     0,     0,     0,     0,     0,
       1,     0,     0,   666,   667,   668,     0,     0,   596,     0,
       0,     0,     0,     0,     0,     0,     0,   597,   598,   599,
     600,     0,   601,   602,   493,   494,     0,     0,   603,   604,
       0,     0,     0,     0,   605,   606,   607,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,   129,   669,
      33,   496,     0,     0,     0,     0,   497,     0,     0,     0,
     192,   193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   670,     0,
       0,     0,   499,   500,   501,   502,   503,   504,   505,   506,
       0,   507,     0,   508,   509,   510,   511,   671,   513,   514,
       0,   515,   516,     0,     0,     0,     0,   672,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,     0,     0,     0,     0,   531,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
       0,   545,     0,   546,   547,   548,   549,   550,     0,     0,
       0,     0,     0,     0,   551,     0,     0,     0,     0,     0,
       0,     0,     0,   552,   553,   554,   555,     0,     0,     0,
       0,   556,     0,   557,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,   559,   560,   561,     0,     0,     0,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   576,   577,   578,   579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   580,   581,     0,     0,     0,     0,     0,     0,     0,
       0,   673,   674,   675,   676,   677,   678,     0,     0,   679,
     680,   681,   682,   683,   684,   685,   595,     0,     0,     0,
       0,     0,     1,     0,     0,   666,   667,  1944,     0,     0,
     596,     0,     0,     0,     0,     0,     0,     0,     0,   597,
     598,   599,   600,     0,   601,   602,   493,   494,     0,     0,
     603,   604,     0,     0,     0,     0,   605,   606,   607,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
     129,   669,    33,   496,     0,     0,     0,     0,   497,     0,
       0,     0,   192,   193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     670,     0,     0,     0,   499,   500,   501,   502,   503,   504,
     505,   506,     0,   507,     0,   508,   509,   510,   511,   671,
     513,   514,     0,   515,   516,     0,     0,     0,     0,   672,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,     0,     0,     0,     0,   531,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,     0,   545,     0,   546,   547,   548,   549,   550,
       0,     0,     0,     0,     0,     0,   551,     0,     0,     0,
       0,     0,     0,     0,     0,   552,   553,   554,   555,     0,
       0,     0,     0,   556,     0,   557,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   558,   559,   560,   561,     0,     0,     0,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,   182,   183,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,    24,     0,    25,     0,    27,   185,   186,
     187,   218,  1536,    33,     0,   189,   190,     0,     0,     0,
       0,   191,     0,   192,   193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   576,   577,   578,   579,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   580,   581,     0,     0,     0,     0,     0,
       0,     0,     0,   673,   674,   675,   676,   677,   678,     0,
       0,   679,   680,   681,   682,   683,   684,   685,   595,     0,
      50,    51,    52,    53,    54,     0,     0,     0,     0,     0,
       0,     0,   596,     0,     0,     0,     0,     0,     0,     0,
     194,   597,   598,   599,   600,     0,   601,   602,    58,     0,
     195,     0,   603,   604,     0,     0,     0,     0,   605,   606,
     607,     1,     0,     2,     3,     4,     5,     0,     0,     0,
       0,     0,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,     0,    25,     0,    27,   185,   186,   187,     0,
     188,    33,     0,   213,   190,     0,     0,     0,     0,   191,
       0,   192,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,     0,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,     0,
       0,     0,     0,    77,    78,     0,     0,     0,   195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,   182,   183,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,    25,     0,    27,   185,   186,   187,
       0,   188,    33,     0,   189,   190,     0,     0,     0,     0,
     191,     0,   192,   193,     0,     0,     0,     0,     0,     0,
       0,    64,     0,    65,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,   196,   197,   198,   199,   200,   201,
       0,     0,   202,   203,   204,   205,   206,   207,   208,    50,
      51,    52,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,   194,
       0,    77,    78,     0,     0,     0,     0,     0,     0,   195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,     0,    65,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,   101,   102,     0,     0,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,   182,   183,   963,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,     0,    27,   185,   186,   187,     0,
     188,    33,     0,   189,   190,     0,     0,     0,     0,   191,
       0,   192,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,   196,   197,   198,   199,   200,   201,     0,
       0,   202,   203,   204,   205,   206,   207,   208,    50,    51,
      52,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,   196,   197,   198,   199,   200,   201,     0,     0,
     202,   203,   204,   205,   206,   207,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    38,   403,    50,   415,   348,    22,     0,    44,   257,
     378,   379,   380,   381,    30,    38,   376,   377,     7,    19,
      20,    10,    11,    12,    44,     7,    19,     0,    33,    13,
      50,    45,  2697,  2698,  2699,    45,    38,    12,   398,   399,
      18,    12,    51,    16,     5,     6,    14,    51,    57,     5,
       6,    20,    51,    58,   217,   218,   219,    20,    67,    68,
      40,    66,    45,    46,    68,    51,    51,    47,    21,    68,
      59,    51,    83,    84,    21,    55,    87,    88,    89,    90,
      91,    92,    68,    68,    18,    12,     5,    13,    68,    18,
     102,   217,   218,   219,   131,    22,   259,   322,   323,    12,
     137,    51,   123,    30,    12,    40,    14,   489,   490,    57,
      51,   123,    47,   113,    40,    56,    51,    18,    68,    67,
      55,    47,    12,    13,    12,    51,    14,    68,    18,    55,
      18,   131,    12,    68,   102,   119,   120,   110,   131,    47,
     122,   155,    68,    12,   117,   123,   150,   116,   123,   374,
     164,   150,   199,   116,   164,    47,   117,   118,   131,    51,
      12,   117,   118,   116,   150,    12,    13,    47,   102,   116,
     217,    18,   152,    57,   103,   104,    68,    47,    47,   199,
      12,    51,    14,    67,    12,   199,    14,   119,   120,   199,
      13,    19,   355,   356,   357,   358,    19,   217,    68,    22,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   102,    47,    12,   152,   220,   217,
     218,   219,    18,   223,   207,   208,   152,    13,   610,   355,
     356,   357,   358,    19,    22,   123,    22,   489,   490,  2904,
     240,  2906,    30,   243,  2909,  2910,   246,   112,   113,    12,
      18,    14,   252,   253,    18,    18,   256,   257,   123,    14,
     253,   261,    12,   263,    14,   184,    12,   112,   113,    12,
      51,    52,    53,    12,    19,    20,    57,    22,   123,   112,
     113,    12,   282,   283,   666,   667,    67,    68,     7,     8,
     123,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   685,   686,   119,   120,   255,   256,   257,
      12,   311,   349,   313,   314,    18,   264,   265,   266,   267,
      12,   269,   315,    10,    11,    47,    18,    19,    50,   366,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,     4,    18,    13,     7,     8,    50,
      13,    12,    19,   353,    21,    22,    19,    18,   610,    22,
      12,   309,    14,    18,   312,   313,   314,   315,   415,   317,
     318,   376,   383,   321,    43,    44,    12,   350,    12,   415,
    3045,    50,    18,    19,    18,    18,    12,    13,   377,   378,
     390,   391,    18,    12,   394,   415,    10,    11,    13,   422,
     423,   424,   425,   403,    19,    10,    11,   407,   408,    12,
     403,   411,    12,    13,   666,   667,    12,    12,    18,    14,
      12,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   685,   686,    12,    12,   453,    14,   428,
     429,   430,   431,   432,   433,   454,    12,   436,   437,   438,
     439,   440,   441,   442,    12,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,    12,    13,    14,   137,    12,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     324,    12,   326,   483,   328,   329,    12,    51,    52,    53,
     235,    12,   336,    57,    12,   339,   340,   341,   342,   343,
     344,    13,   247,    67,    68,   201,   202,    19,   497,   423,
     424,   256,   257,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    12,    12,    14,    14,   474,   475,   476,    18,
     199,   375,   480,    12,   482,   379,   147,   201,   202,    18,
     384,   385,    47,   925,   926,    12,    12,    14,   217,    12,
     394,   220,   221,   222,   223,   399,   400,   939,   940,   941,
     942,   943,   944,   945,   946,   947,   948,   949,   950,   951,
      12,   953,   491,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    12,   252,   253,   254,     0,    13,   199,   200,
     201,   202,   993,    19,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    12,    12,    14,   354,
      12,    13,    18,    13,    13,    13,    18,   322,    13,    19,
      19,    19,   207,   208,    19,   370,   371,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      13,    13,    16,    13,    15,    13,    19,    19,   403,    19,
      21,    19,    13,   663,    13,    13,    13,    12,    19,    13,
      19,    19,    19,   925,   926,    19,    13,    13,    13,    13,
      13,    12,    19,    19,    19,    19,    19,   939,   940,   941,
     942,   943,   944,   945,   946,   947,   948,   949,   950,   951,
      13,   953,    13,     3,     4,    19,    19,    21,    19,    10,
      11,   380,   381,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,    13,   398,
      13,    13,   115,    13,    19,    13,    19,    19,   483,    19,
      12,    19,    13,     4,    13,    13,   415,    13,    19,   668,
      19,    19,    12,    19,    13,    13,    13,    19,   795,    21,
      19,    19,    19,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1027,
     119,   120,  1150,  1151,  1152,  1153,  1154,  1155,  1148,  1149,
      13,   350,    12,   793,   322,   323,    19,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      13,    13,    13,    13,    13,    13,    19,    19,    19,    19,
      19,    19,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,    17,
      13,    13,    13,    13,    12,   145,    19,    19,    19,    19,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    12,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    13,    13,    13,    13,    13,    13,    19,    19,    19,
      19,    19,    19,  1145,  1146,  1147,   201,   202,    13,    13,
      13,    13,    45,    46,    19,    19,    19,    19,   368,   369,
      12,   470,   382,   383,   659,   459,   460,   461,   462,   463,
    1148,  1149,   217,   218,   219,   220,    12,  1270,    12,   488,
    1154,  1155,   383,    50,    51,    52,    53,    12,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   398,   399,   121,   250,   459,   460,   461,   462,
     463,    18,    12,   258,    18,    18,   966,   967,   968,   969,
     970,   971,   972,    14,   974,   975,   271,    14,    18,   979,
     980,   981,   982,   983,   984,   985,    18,   987,    18,   989,
      13,   991,   992,    13,   994,   995,   996,   997,   998,   355,
     356,   357,   358,  1003,  1004,  1005,  1006,  1418,   927,  1150,
    1151,  1152,  1153,    13,    18,   321,    14,   421,   313,    47,
     315,   316,   317,    47,  1024,    47,   123,  1027,    12,    48,
      47,   326,   327,   155,    13,    56,  1418,   332,   333,   334,
     335,    19,    44,    12,    12,    12,    12,    12,    12,    12,
     345,   346,   347,   348,   349,    12,   351,   352,    12,   354,
      12,    12,    12,    12,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,    12,
      12,    12,    12,    19,    12,    12,    12,    12,    12,    12,
      12,   836,    12,    12,    12,    12,   396,   397,    12,    12,
      12,    12,    12,  1022,    12,    12,    12,    12,    12,    12,
      12,    12,    12,  1361,    12,   123,    12,   862,    12,    18,
     865,    18,    51,    52,    53,  1162,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    1140,    12,  1142,  1143,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,   115,
      12,    12,    12,    49,    12,    18,    12,    12,    12,    18,
    1170,    18,    12,  1173,    12,  1175,    12,  1177,    12,    12,
    1180,    12,    12,    12,   479,    12,  1587,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,  1202,    12,  1204,  1205,  1206,    12,    12,    12,
    1592,  1211,  1212,  1213,  1214,  1215,  1216,  1217,    12,  1219,
      12,    12,    12,    12,    12,    12,    12,    12,    12,  1229,
    1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,  1243,    12,    12,    12,    12,    12,  1249,
    1250,  1251,  1252,  1253,  1254,  1255,    12,    12,    12,    12,
    1260,  1261,    12,  1263,  1009,    12,  1011,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,  1022,    12,    12,
      15,  1281,  1027,  1283,    12,    12,    18,    12,    12,  1289,
    1290,  1291,    12,    16,    12,    17,    12,    18,  1298,  1299,
    1300,  1301,  1302,  1303,    12,  1305,  1306,    12,  1308,  1309,
    1310,  1311,  1312,  1313,    12,  1315,  1316,  1317,  1318,  1319,
    1320,  1321,  1322,    12,  1667,  1325,    12,  1327,  1328,    12,
    1330,  1331,  1332,    12,    12,    12,    12,    12,    12,    12,
      49,    56,    14,    13,  1089,  1090,    15,    12,    19,    13,
      18,    18,    18,    13,    15,    13,    13,  1357,  1358,    15,
      13,  1361,    12,  1363,    15,  1365,  1366,    19,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,  1138,    12,  1140,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    58,    13,    13,   473,    64,    13,    15,  1163,  1164,
      19,   199,  1167,    19,    19,    19,    19,    19,    19,    19,
      19,  1176,    19,    19,    19,    19,    19,    13,    13,    19,
      13,    13,    13,    13,    13,    19,   322,   199,    12,    12,
      12,    19,    19,    19,    19,    15,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,   771,   772,    12,    12,   775,   776,   777,   778,   779,
     780,   781,   782,   783,   784,   785,   786,   787,   788,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,  1266,    12,    12,    12,    12,    12,    12,    58,    53,
      12,    14,    13,    12,    18,    12,    12,  1919,    18,  1284,
      12,    12,    12,    18,   123,   123,    15,    15,  1293,    13,
     445,    12,    15,    13,    12,    12,    12,   259,   446,   385,
     388,    52,   123,  1287,    13,   123,   374,    12,    19,    13,
    1156,    19,    19,    19,    52,    13,    19,    19,    13,    13,
      54,    13,    55,    19,    21,    13,    53,    12,    19,    55,
      19,    50,    19,    19,    13,    50,  1341,    50,    50,    64,
      50,    19,    64,    19,  1349,    19,    19,    13,    19,    13,
      19,    13,    66,    13,  1359,    18,  1361,  1362,    19,    13,
      19,    19,  1367,    19,  1661,   925,   926,    13,    19,    19,
      19,    13,    13,    13,    13,    19,    13,    13,    13,   939,
     940,   941,   942,   943,   944,   945,   946,   947,   948,   949,
     950,   951,    19,   953,    18,   415,    19,    19,    19,    19,
    1660,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,  2014,    19,    19,    19,    19,    19,    19,  1678,    19,
      12,    12,    19,    13,    19,    19,    19,   384,    47,    13,
      19,    19,    19,    19,    19,    13,    13,    19,    13,    19,
      19,    66,    50,    19,   386,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    13,    19,    19,    19,    19,    19,
      13,    19,    13,    19,    19,    19,    64,    19,   123,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    50,   131,  1157,    12,  1158,
      13,    19,    19,    19,    19,  1755,  1756,  1757,  1758,    19,
    1760,    19,  1762,    19,    19,    13,    13,    19,  1768,  1769,
    1770,    15,    12,  1773,  1774,  1775,  1776,    12,  1778,    12,
    1780,    12,  1782,    13,    13,  1785,  1786,  1787,  1788,    13,
      47,    19,  1792,    19,    19,  1795,    19,    19,    19,    19,
      13,    13,    13,    13,    19,  1805,    15,  1807,    13,    13,
      13,  1811,  1812,    13,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,  1824,  1825,    13,  1827,    13,    13,
      13,    13,    13,    13,    13,    13,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,    13,    13,    19,    13,    13,
      19,    13,    13,    13,    13,    13,    13,    13,  1858,  1859,
    1860,  1861,    13,    13,    13,  1865,  1866,  1867,  1868,    13,
      13,    19,    19,    13,    13,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  1884,  1885,    13,    13,    19,    13,
      13,    13,    13,  1893,  1894,  1895,    13,  1897,  1898,    19,
    1900,  1901,    13,    13,  1904,    19,  1906,    19,    13,    50,
      19,    19,    19,    19,    13,    19,    19,  1917,    19,    19,
      13,    19,    19,    19,    19,    19,  1926,  1927,    19,    13,
      13,  1931,    13,    13,    19,  1935,    13,    19,    13,    13,
      19,    13,    13,    13,    13,    13,    19,    13,    50,   389,
      13,  1951,    19,  1953,    19,    19,    13,    13,    13,    13,
      13,    13,    50,    21,    13,    13,    12,  1967,    19,    19,
      13,    13,    19,    13,    19,    19,    13,   131,    19,  2016,
      19,    19,  1982,    19,  1984,    19,    19,    19,    19,  1989,
      19,    19,    19,    19,    19,  1995,    15,    15,    13,  1999,
    2000,    13,  2002,  2003,  2004,    15,  2006,  2007,    19,    13,
    2010,  2011,    13,  2013,    19,    13,    13,    13,    13,    13,
      13,    21,  2022,  2023,    13,    47,  2026,    19,  2028,  2029,
    2030,    19,    13,    19,    13,    19,  2036,    13,    13,  2039,
      13,  2041,    13,    21,    13,  2045,  2046,    19,  2048,    19,
      13,    19,    19,    19,  2054,    19,    13,  2057,    19,  2059,
      19,  2061,  2062,  2063,    19,    19,    13,    13,    19,    13,
      19,    19,  2072,  2073,    13,    13,  2076,    19,    19,    13,
      13,  2081,  2082,  2083,  2084,  2085,  2086,    13,  2088,  2089,
    2090,    19,  2092,  2093,  2094,  2095,  2096,    13,    19,  2099,
    2100,  2101,  2102,    18,  2104,    19,    19,    19,    19,    19,
      19,    19,    13,    19,    19,    19,    19,    19,   131,    19,
      19,    19,    19,    19,    19,  1870,  2469,    19,    19,    19,
      13,    19,    19,    19,    19,    19,    13,    19,    13,    19,
      13,    13,  2142,    13,    13,    19,    13,    13,    19,    13,
      13,    19,    13,    13,    19,    13,    13,    19,    13,     7,
      19,     9,    10,    11,    12,    19,    13,    13,    13,    19,
      19,    13,  1160,    13,    13,    19,    19,    13,    19,    13,
      28,    19,    19,    13,    19,   387,    19,  1932,  1933,  1934,
      19,    19,    40,    13,    13,    13,    13,    19,    13,    47,
      13,    49,    13,    51,    52,    53,    54,    55,    56,    57,
      19,    59,    60,    13,    19,    19,    13,    65,    19,    67,
      68,    19,    13,    19,    19,    19,    19,    19,    13,    19,
      19,  2268,    19,    13,    13,    19,    19,    19,    19,    15,
    1919,    19,    19,  2243,    19,    19,    19,    13,    19,    19,
      19,    19,    19,    13,    19,    19,    19,    19,    19,    13,
      19,    19,    19,    13,    13,    13,    13,  2267,    13,    21,
      13,    13,    13,    19,    13,    19,   124,   125,   126,   127,
     128,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      13,    19,    19,    13,    19,    19,   144,    19,    13,    13,
      19,    19,    19,    19,   152,   131,   154,    19,    19,    19,
      19,    19,    19,    19,    13,    19,    19,    19,    19,    19,
    2320,    19,  2322,    19,  2324,    19,  2326,    19,    19,    13,
      19,  2331,  2332,    19,  2334,  2335,  2336,  2337,    19,  2339,
    2340,  2341,  2342,    19,    19,    19,  2346,    19,    13,  2349,
    2350,    13,    13,    13,    13,  2355,   204,    13,    13,    13,
    2360,    19,  2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,
      19,  2371,  2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,
    2380,  2381,  2382,  2383,  2384,    19,  2386,    19,    19,   237,
      19,   239,    19,    19,  2394,    19,    19,    19,  2398,  2399,
      13,    19,    13,    19,    13,    13,    21,    19,  2408,  2409,
      13,    13,    19,    19,    19,    13,    13,    21,  2418,  2419,
    2420,  2421,  2422,    19,  2424,  2425,    19,  2427,  2428,    19,
      13,  2350,  2432,  2433,  2353,  2435,  2436,    19,    19,    13,
      13,    13,    13,    13,    13,  2445,    13,    13,    13,  2449,
      13,  2451,  2452,    13,    13,    13,    13,    19,    19,   307,
     308,  2461,  2462,  2463,    19,    19,  2466,  2467,    19,    13,
      13,    19,  2472,    13,  2474,    13,  2476,  2477,    19,  2479,
    2480,  2481,  2482,  2483,  2484,  2485,    19,  2487,  2488,  2489,
    2490,  2491,  2492,  2493,  2494,  2495,    19,  2497,  2498,  2499,
    2500,    13,    19,    13,    13,    19,    19,    13,    19,    13,
      13,  2511,  2512,  2513,  2514,    -1,    13,  2517,  2518,    19,
      19,    19,    -1,    19,    19,    19,    19,    19,    19,   377,
     378,    19,    13,    19,    19,    19,    19,    19,    13,    19,
      13,    13,    19,    19,   131,    19,    -1,   350,    19,    19,
      19,    19,    19,    19,    19,    13,    13,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,    13,   416,    13,
      19,    19,    19,    13,    19,    13,  2613,    13,   426,   427,
     428,   429,   430,   431,   432,   433,    19,    13,   436,   437,
     438,   439,   440,   441,   442,    13,    19,    19,    13,    19,
      19,    13,    19,    19,    13,    19,    19,    13,   456,    19,
      13,    19,    19,  1144,    19,    19,    13,    19,    19,    19,
      19,    19,    13,    19,    13,    19,    13,    13,    13,    13,
      13,    13,  1159,    13,  1000,    13,    13,    -1,    19,    13,
      19,    13,    13,    19,    13,    13,    19,    13,    13,   497,
      13,  2651,  2652,    -1,  2654,  2655,    13,  2657,  2658,    19,
    2660,  2661,  2662,    19,  2664,  2665,    19,    13,  2668,    19,
      13,    19,    19,  2673,  2674,    13,  2676,    19,  2678,    19,
    2680,    -1,  2682,  2683,  2684,  2685,  2686,    19,    19,    19,
    2690,  2691,  2692,  2693,  2694,  2695,  2441,  2697,  2698,  2699,
    2700,  2701,  2702,  2703,    19,  2705,  2706,  2707,  2708,  2709,
      13,  2711,    19,    19,    19,    19,  2716,  2717,    19,  2719,
    2720,  2721,  2722,  2723,  2724,    19,  2726,  2727,  2728,    13,
      13,    19,  2732,    13,  2734,    13,  2736,    19,    19,  2739,
      19,  2741,  2742,    13,  2744,    13,    19,    13,  2667,    13,
      19,  2751,  2671,  2753,    19,    13,  2756,  2757,    19,    19,
      19,    -1,    19,    19,    19,    19,    19,    19,    19,    13,
      19,  2771,  2772,  2773,  2774,  2775,    19,    13,    13,    13,
      13,  2781,  2782,  2783,    13,    13,    13,    19,    19,    19,
      13,    13,    -1,    19,    19,    19,    13,    13,    19,    19,
      19,    19,    13,    13,    19,    19,    19,    19,    13,    13,
      19,    19,    19,    19,    13,    13,    19,    19,    19,    19,
      13,    13,    19,    19,    19,    19,    13,    13,    19,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2869,
      -1,    -1,  2872,  2873,  2874,    -1,    -1,    -1,  2878,    -1,
    2880,  2881,    -1,    -1,    -1,    -1,  2886,  2887,    -1,  2889,
      -1,  2891,  2892,  2893,  2894,  2895,  2896,    -1,  2898,  2899,
    2900,  2901,  2902,  2903,  2904,    -1,  2906,    -1,    -1,  2909,
    2910,  2911,  2912,  2913,    -1,    -1,    -1,    -1,    -1,  2919,
    2920,    -1,    -1,  2923,    -1,    -1,    -1,  2927,  2928,  2929,
      -1,    -1,  2932,    -1,    -1,    -1,  2936,  2937,    -1,    -1,
    2940,  2941,    -1,    -1,  2944,    -1,  2946,  2947,    -1,    -1,
    2950,  2951,    -1,  2953,    -1,  2955,  2956,  2957,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2885,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2731,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3017,  3018,  3019,
    3020,    -1,  3022,  3023,    -1,    -1,  3026,    -1,    -1,    -1,
      -1,    -1,    -1,  3033,    -1,  3035,    -1,  3037,    -1,    -1,
    3040,    -1,    -1,    -1,    -1,  3045,    -1,    -1,    -1,    -1,
    3050,  3051,    -1,  3053,    -1,  3055,    -1,  3057,  3058,  3059,
      -1,  3061,  3062,    -1,  3064,    -1,  3066,    -1,  3068,  3069,
    3070,    -1,    -1,  3073,  3074,  3075,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3112,    -1,    -1,    -1,  3116,  3117,    -1,    -1,
      -1,  3121,    -1,  3123,  3124,    -1,  3126,  3127,    -1,    -1,
      -1,  3131,    -1,    -1,  3134,  3135,  3136,  2882,  3138,  3139,
    3140,  3141,    -1,    -1,  3144,  3145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,    -1,     2,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3167,    -1,    15,
      -1,    -1,    18,  3173,  3174,  3175,    22,    -1,    -1,  3179,
    3180,    -1,    -1,  3183,  3184,    -1,    -1,  3187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,  3201,  3202,    -1,  3204,    -1,  3206,    -1,    -1,  3209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3219,
      -1,  3221,  3222,  3223,    -1,    -1,    -1,    -1,    -1,    -1,
    3230,  3231,  3232,    -1,    -1,    -1,    -1,  3237,  3238,  3239,
      -1,    -1,    -1,    -1,  3244,  3245,    -1,    -1,  3248,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3022,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,
    3115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,    -1,    -1,    -1,
      -1,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    -1,    -1,    -1,   312,   313,    -1,    -1,
      -1,   317,   318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     2,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,   354,    -1,
     356,   357,   358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   368,   369,   370,   371,    -1,    -1,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,   394,    -1,
     396,    -1,   398,   399,    -1,    -1,   402,   403,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   415,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   489,   490,   491,   492,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   659,    -1,    -1,    -1,    -1,    -1,    -1,
     666,   667,   668,    -1,    -1,    -1,    -1,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   374,   375,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   489,   490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     836,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   862,    -1,    -1,   865,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,    -1,    -1,   925,
     926,   927,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   610,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   948,   949,   950,   951,    -1,   953,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   967,    -1,    -1,    -1,    -1,    -1,   973,    -1,    -1,
     976,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     986,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1009,    -1,  1011,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1022,    -1,    -1,    -1,
      -1,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,    -1,  1044,  1045,
    1046,  1047,    -1,  1049,  1050,  1051,    -1,    -1,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,    -1,    -1,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1127,  1128,  1129,  1130,  1131,  1132,    -1,  1134,  1135,
    1136,  1137,  1138,    -1,  1140,    -1,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,    -1,    -1,  1163,  1164,    -1,
      -1,  1167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1188,    -1,    -1,  1191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1201,    -1,  1203,    -1,    -1,
      -1,  1207,  1208,  1209,  1210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1218,    -1,  1220,  1221,  1222,  1223,  1224,  1225,
    1226,  1227,  1228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1244,    -1,
    1246,    -1,    -1,    -1,    -1,    -1,    -1,   925,   926,    -1,
    1256,  1257,  1258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1266,   939,   940,   941,   942,   943,   944,   945,   946,   947,
     948,   949,   950,   951,    -1,   953,    -1,    -1,  1284,  1285,
    1286,    -1,    -1,    -1,    -1,    -1,    -1,  1293,  1294,    -1,
    1296,  1297,  1298,  1299,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1314,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1323,  1324,    -1,
    1326,    -1,    -1,  1329,    -1,    -1,    -1,  1333,  1334,    -1,
      -1,    -1,  1338,  1339,  1340,  1341,  1342,  1343,    -1,  1345,
      -1,    -1,  1348,  1349,    -1,  1351,  1352,  1353,  1354,  1355,
      -1,    -1,    -1,  1359,    -1,  1361,  1362,    -1,    -1,    -1,
      -1,  1367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1146,  1147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1529,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1589,    -1,    -1,  1592,    -1,  1594,  1595,
    1596,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,  1645,
     256,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,
     286,   287,  1678,   289,    -1,   291,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   299,   300,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   315,
      -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1754,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1766,  1767,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,   394,    -1,
     396,   397,   398,   399,    -1,    -1,   402,   403,  1794,    -1,
    1796,    -1,    -1,    -1,    -1,    -1,  1802,    -1,    -1,    -1,
      -1,    -1,    -1,  1809,  1810,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1828,  1829,  1830,  1831,  1832,  1833,  1834,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1848,    -1,  1850,  1851,  1852,  1853,  1854,    -1,
    1856,  1857,    -1,    -1,    -1,    -1,  1862,  1863,    -1,    -1,
      -1,    -1,    -1,  1869,  1870,    -1,    -1,  1873,  1874,    -1,
      -1,    -1,    -1,   489,   490,   491,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1899,    -1,    -1,  1902,    -1,    -1,    -1,
      -1,  1907,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1919,  1920,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1932,  1933,  1934,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1944,    -1,
      -1,    -1,    -1,  1949,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1970,    -1,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   610,    -1,  2002,    -1,    -1,    -1,
      -1,    -1,  2008,  2009,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2025,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     666,   667,   668,    -1,    -1,    -1,    -1,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2102,  2103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   771,   772,   773,    -1,   775,
     776,   777,   778,   779,   780,   781,   782,   783,   784,   785,
     786,   787,   788,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   925,
     926,   927,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   948,   949,   950,   951,    -1,   953,    -1,    -1,
      -1,    -1,    -1,  2349,    -1,    -1,    -1,  2353,  2354,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2371,  2372,    -1,    -1,    -1,
     986,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2387,  2388,  2389,  2390,  2391,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2404,    -1,
      -1,  2407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1027,  1028,    -1,  1030,  1031,    -1,    -1,    -1,    -1,
      -1,  1037,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1049,  1050,  2441,    -1,    -1,    -1,    -1,
      -1,    -1,  2448,    -1,    -1,    -1,    -1,  1063,  2454,    -1,
    2456,    -1,  2458,    -1,  2460,    -1,    -1,    -1,  2464,  2465,
      -1,  1077,  1078,  1079,  1080,  1081,    -1,  2473,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1104,    -1,
      -1,    -1,    -1,    -1,    -1,  1111,  1112,  2503,    -1,    -1,
      -1,    -1,    -1,  2509,    -1,    -1,    -1,    -1,    -1,  2515,
    2516,  1127,  1128,  1129,    -1,  1131,  1132,    -1,  1134,  1135,
    1136,  1137,    -1,    -1,  1140,    -1,  1142,    -1,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1188,    -1,    -1,  1191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2667,    -1,    -1,    -1,  2671,    -1,     0,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2697,  2698,  2699,    -1,    -1,    -1,    -1,  1314,    -1,
      -1,    -1,    -1,    -1,  2710,    -1,    -1,    -1,  1324,    -1,
    1326,    -1,    -1,    -1,    -1,    -1,    -1,  1333,    -1,    -1,
      -1,    -1,  1338,  1339,  1340,  2731,  1342,    -1,    -1,    -1,
      -1,    -1,  1348,    -1,    -1,  1351,  1352,  1353,  1354,  1355,
    2746,  2747,    -1,    -1,    -1,  1361,  2752,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2779,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,  1418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2882,    -1,    -1,  2885,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2904,    -1,
    2906,    -1,    -1,  2909,  2910,    -1,    -1,    -1,  2914,  2915,
    2916,  2917,    -1,    -1,    -1,    -1,    -1,   250,   251,    -1,
      -1,    -1,    -1,   256,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2943,    -1,  2945,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2954,    -1,
      -1,   284,    -1,   286,   287,    -1,   289,    -1,   291,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   299,   300,    -1,    -1,
      -1,    -1,    -1,  1589,    -1,    -1,  1592,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1645,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3045,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3063,    -1,  3065,
     393,   394,  1678,    -1,    -1,    -1,  3072,    -1,   401,   402,
     403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    12,  3102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,  3115,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,  3130,    -1,    -1,  3133,    -1,    -1,
      47,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,
      67,    68,    -1,    -1,    -1,    -1,   489,   490,   491,   492,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3181,    -1,    -1,    -1,    -1,
    1796,    -1,    -1,  3189,    -1,    -1,  1802,    -1,    -1,    -1,
      -1,    -1,    -1,  1809,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3207,    -1,    -1,    -1,  3211,    -1,   124,   125,   126,
     127,   128,    -1,    -1,  1830,  1831,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,    -1,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1862,  1863,    -1,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,    -1,    -1,    -1,    -1,   610,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,  1907,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
      -1,   286,   287,  1919,   289,    -1,   291,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   299,   300,    -1,    -1,    -1,    -1,
     237,    -1,   239,    -1,    -1,    -1,    -1,    -1,  1944,    -1,
      -1,    -1,   317,   666,   667,   668,    -1,    -1,    -1,    -1,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683,   684,   685,   686,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2002,    -1,    -1,    -1,
     307,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,   394,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,   403,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2102,  2103,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,
     427,   428,   429,   430,   431,   432,   433,    -1,    -1,   436,
     437,   438,   439,   440,   441,   442,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   925,   926,   927,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   939,   940,   941,   942,
     943,   944,   945,   946,   947,   948,   949,   950,   951,    -1,
     953,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   986,    -1,    -1,    -1,    -1,    -1,    -1,
     993,    -1,    -1,    -1,    -1,    -1,   999,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1027,  1028,    -1,  1030,  1031,    -1,
      -1,    -1,    -1,    -1,  1037,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1049,  1050,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1063,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1077,  1078,  1079,  1080,  1081,    -1,
      -1,    -1,    -1,    -1,  1087,  1088,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1104,    -1,    -1,    -1,    -1,    -1,    -1,  1111,  1112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2404,    -1,
      -1,  2407,    -1,    -1,  1127,  1128,  1129,    -1,  1131,  1132,
      -1,  1134,  1135,  1136,  1137,    -1,    -1,  1140,    -1,  1142,
      -1,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2454,    -1,
    2456,    -1,  2458,    -1,  2460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1188,    -1,    -1,  1191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2509,    -1,    -1,    -1,    -1,    -1,  2515,
    2516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1324,    -1,  1326,    -1,    -1,    -1,    -1,    -1,    -1,
    1333,   986,  1335,  1336,  1337,  1338,  1339,  1340,    -1,  1342,
      -1,  1344,    -1,  1346,  1347,  1348,    -1,    -1,  1351,  1352,
    1353,  1354,  1355,    -1,    -1,    -1,    -1,    -1,  1361,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1027,  1028,    -1,  1030,  1031,    -1,    -1,    -1,
      -1,    -1,  1037,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1049,  1050,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1063,    -1,
      -1,    -1,    -1,    -1,    -1,  1418,    -1,    -1,    -1,    -1,
      -1,    -1,  1077,  1078,  1079,  1080,  1081,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1104,
      -1,    -1,    -1,    -1,    -1,    -1,  1111,  1112,    -1,    -1,
    2746,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1127,  1128,  1129,    -1,  1131,  1132,    -1,  1134,
    1135,  1136,  1137,    -1,    -1,  1140,    -1,  1142,    -1,    -1,
      -1,    -1,    -1,  2779,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1529,    -1,    -1,    -1,
      -1,    -1,    -1,  1188,    -1,    -1,  1191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1587,    -1,  1589,    -1,    -1,  1592,
      -1,  1246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,  1645,    -1,    -1,    47,    -1,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,  1314,
      -1,    -1,    -1,    65,    -1,    67,    68,    -1,  2954,  1324,
      -1,  1326,    -1,    -1,    -1,  1678,    -1,    -1,  1333,    -1,
      -1,    -1,    -1,  1338,  1339,  1340,    -1,  1342,    -1,    -1,
      -1,    -1,    -1,  1348,    -1,    -1,  1351,  1352,  1353,  1354,
    1355,    -1,    -1,    -1,    -1,    -1,  1361,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3072,    -1,    -1,    -1,
      -1,    -1,    -1,  1796,    -1,    -1,    -1,    -1,    -1,  1802,
      -1,    -1,   204,    -1,    -1,    -1,  1809,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1830,  1831,    -1,
      -1,    -1,    -1,    -1,    -1,   237,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,  3130,    -1,    -1,  3133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1862,
    1863,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3189,  1907,   307,   308,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1919,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1589,    -1,    -1,    -1,    -1,    -1,
      -1,  1944,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2002,
      -1,    -1,    -1,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1678,   426,   427,   428,   429,   430,   431,
     432,   433,    -1,    -1,   436,   437,   438,   439,   440,   441,
     442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   497,    -1,    -1,    -1,  2102,
    2103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1796,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1809,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1830,  1831,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,  1862,  1863,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,  1907,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,   154,    -1,    -1,    -1,  2002,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2404,    -1,    -1,  2407,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,    -1,   239,    -1,
      -1,    -1,    -1,    -1,   245,   246,   247,   248,   249,   250,
      -1,   252,    -1,    -1,    -1,    -1,    -1,  2102,  2103,    -1,
      -1,  2454,    -1,  2456,    -1,  2458,    -1,  2460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     291,   292,   293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   306,   307,   308,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2509,    -1,    -1,    -1,
      -1,    -1,  2515,  2516,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   377,   378,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,    -1,   416,   417,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,   426,   427,   428,   429,   430,
     431,   432,   433,    -1,    -1,   436,   437,   438,   439,   440,
     441,   442,    -1,   444,    -1,    -1,    -1,   448,    -1,   450,
     451,    -1,    -1,    -1,   455,   456,    -1,   458,    -1,    -1,
      -1,    -1,    -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     481,    -1,    -1,    -1,    -1,   486,   487,    -1,   489,   490,
     491,   492,   493,   494,   495,   496,   497,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2746,    -1,    -1,    -1,    -1,    -1,  2404,
      -1,    -1,  2407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2779,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2454,
      -1,  2456,    -1,  2458,    -1,  2460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,  2509,     9,    10,    11,    12,    -1,
    2515,  2516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2954,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,    -1,   138,    -1,   140,   141,   142,   143,
     144,   145,   146,    -1,   148,   149,    -1,    -1,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,    -1,    -1,    -1,    -1,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3072,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,  2746,    -1,    -1,    -1,    -1,    -1,   251,    -1,  3102,
      -1,   255,   256,   257,    -1,    -1,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2779,    -1,    -1,  3130,    -1,    -1,
    3133,    -1,    -1,   287,   288,   289,   290,    -1,    -1,    -1,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,    -1,   307,   308,   309,    -1,    -1,   312,   313,
     314,   315,    -1,   317,   318,   319,   320,   321,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   376,   377,   378,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,    -1,   416,    -1,   418,   419,    -1,   421,    -1,    -1,
      -1,    -1,   426,   427,   428,   429,   430,   431,   432,   433,
      -1,    -1,   436,   437,   438,   439,   440,   441,   442,   443,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2954,
      -1,    -1,   456,   457,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   466,   467,   468,   469,    -1,   471,   472,    -1,
     474,   475,   476,   477,   478,    -1,   480,    -1,   482,   483,
     484,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,  3072,    63,    -1,
      65,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3130,    -1,    -1,  3133,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,    -1,   138,    -1,   140,   141,   142,   143,   144,
     145,   146,    -1,   148,   149,    -1,    -1,   152,    -1,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3189,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,  3211,    -1,   203,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,   261,   262,   263,    -1,
      -1,    -1,    -1,   268,    -1,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   287,   288,   289,   290,    -1,    -1,    -1,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    -1,   307,   308,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   319,   320,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
      -1,   416,    -1,   418,   419,    -1,    -1,    -1,    -1,    -1,
      -1,   426,   427,   428,   429,   430,   431,   432,   433,    -1,
      -1,   436,   437,   438,   439,   440,   441,   442,   443,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   456,   457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   466,   467,   468,   469,    -1,   471,   472,    -1,    -1,
      -1,    -1,   477,   478,    -1,    -1,    -1,    -1,   483,   484,
     485,     7,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      16,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    63,    -1,    65,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,    -1,   138,    -1,   140,   141,   142,   143,   144,   145,
     146,    -1,   148,   149,    -1,    -1,   152,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,    -1,    -1,    -1,    -1,   203,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,   261,   262,   263,    -1,    -1,
      -1,    -1,   268,    -1,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   287,   288,   289,   290,    -1,    -1,    -1,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
      -1,   307,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   319,   320,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,    -1,
     416,    -1,   418,   419,    -1,    -1,    -1,    -1,    -1,    -1,
     426,   427,   428,   429,   430,   431,   432,   433,    -1,    -1,
     436,   437,   438,   439,   440,   441,   442,   443,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     456,   457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     466,   467,   468,   469,    -1,   471,   472,    -1,    -1,    -1,
      -1,   477,   478,    -1,    -1,    -1,    -1,   483,   484,   485,
       7,    -1,     9,    10,    11,    12,    -1,    -1,    -1,    16,
      -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    63,    -1,    65,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
      -1,   138,    -1,   140,   141,   142,   143,   144,   145,   146,
      -1,   148,   149,    -1,    -1,   152,    -1,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,    -1,    -1,   203,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,   261,   262,   263,    -1,    -1,    -1,
      -1,   268,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     287,   288,   289,   290,    -1,    -1,    -1,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,    -1,
     307,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   319,   320,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,    -1,   416,
      -1,   418,   419,    -1,    -1,    -1,    -1,    -1,    -1,   426,
     427,   428,   429,   430,   431,   432,   433,    -1,    -1,   436,
     437,   438,   439,   440,   441,   442,   443,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,
     457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,
     467,   468,   469,    -1,   471,   472,    -1,    -1,    -1,    -1,
     477,   478,    -1,    -1,    -1,    -1,   483,   484,   485,     7,
      -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
     497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    63,    -1,    65,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,    -1,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,    -1,
     148,   149,    -1,    -1,   152,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,    -1,    -1,   203,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,   261,   262,   263,    -1,    -1,    -1,    -1,
     268,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,
     288,   289,   290,    -1,    -1,    -1,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    -1,   307,
     308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   319,   320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,    -1,   416,    -1,
     418,   419,    -1,    -1,    -1,    -1,    -1,    -1,   426,   427,
     428,   429,   430,   431,   432,   433,    -1,    -1,   436,   437,
     438,   439,   440,   441,   442,   443,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    12,    -1,   456,   457,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,   467,
     468,   469,    28,   471,   472,    31,    32,    -1,    -1,   477,
     478,    -1,    -1,    -1,    -1,   483,   484,   485,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,   497,
      56,    57,    58,    59,    60,    -1,    -1,    63,    -1,    65,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,    -1,   138,    -1,   140,   141,   142,   143,   144,   145,
     146,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,    -1,    -1,    -1,    -1,   203,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,   261,   262,   263,    -1,    -1,
      -1,    -1,   268,    -1,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   287,   288,   289,   290,    -1,    -1,    -1,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
      -1,   307,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   319,   320,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,    -1,
     416,    -1,   418,   419,    -1,    -1,    -1,    -1,    -1,    -1,
     426,   427,   428,   429,   430,   431,   432,   433,    -1,    -1,
     436,   437,   438,   439,   440,   441,   442,   443,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    12,    -1,
     456,   457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     466,   467,   468,   469,    28,   471,   472,    31,    32,    -1,
      -1,   477,   478,    -1,    -1,    -1,    -1,   483,   484,   485,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,   497,    56,    57,    58,    59,    60,    -1,    -1,    63,
      -1,    65,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,    -1,   138,    -1,   140,   141,   142,   143,
     144,   145,   146,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,    -1,    -1,    -1,    -1,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   260,   261,   262,   263,
      -1,    -1,    -1,    -1,   268,    -1,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   287,   288,   289,   290,    -1,    -1,    -1,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,    -1,   307,   308,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   319,   320,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,    -1,   416,    -1,   418,   419,    -1,    -1,    -1,    -1,
      -1,    -1,   426,   427,   428,   429,   430,   431,   432,   433,
      -1,    -1,   436,   437,   438,   439,   440,   441,   442,   443,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      12,    -1,   456,   457,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   466,   467,   468,   469,    28,   471,   472,    31,
      32,    -1,    -1,   477,   478,    -1,    -1,    -1,    -1,   483,
     484,   485,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      52,    53,    54,   497,    56,    57,    58,    59,    60,    -1,
      -1,    63,    -1,    65,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,    -1,   138,    -1,   140,   141,
     142,   143,   144,   145,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,    -1,    -1,    -1,
      -1,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   261,
     262,   263,    -1,    -1,    -1,    -1,   268,    -1,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   287,   288,   289,   290,    -1,
      -1,    -1,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,    -1,   307,   308,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,   320,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,    -1,   416,    -1,   418,   419,    -1,    -1,
      -1,    -1,    -1,    -1,   426,   427,   428,   429,   430,   431,
     432,   433,    -1,    -1,   436,   437,   438,   439,   440,   441,
     442,   443,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    12,    -1,   456,   457,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   466,   467,   468,   469,    -1,   471,
     472,    31,    32,    -1,    -1,   477,   478,    -1,    -1,    -1,
      -1,   483,   484,   485,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,   497,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,    -1,
     140,   141,   142,   143,   144,   145,   146,    -1,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,   238,    -1,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   261,   262,   263,    -1,    -1,    -1,    -1,   268,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,   288,   289,
     290,    -1,    -1,    -1,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,
     320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,    -1,    -1,    -1,   418,   419,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
     430,   431,   432,   433,    -1,    -1,   436,   437,   438,   439,
     440,   441,   442,   443,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   466,   467,   468,   469,
      -1,   471,   472,    -1,    -1,    -1,    -1,   477,   478,    -1,
      -1,    -1,    -1,   483,   484,   485,     7,    -1,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,   497,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    -1,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,    -1,   239,    -1,
      -1,    -1,    -1,    -1,   245,   246,   247,   248,   249,   250,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     291,   292,   293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   306,   307,   308,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   377,   378,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,    -1,   416,   417,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,   426,   427,   428,   429,   430,
     431,   432,   433,    -1,    -1,   436,   437,   438,   439,   440,
     441,   442,    -1,   444,    -1,    -1,    -1,   448,    -1,   450,
     451,    -1,    -1,    -1,   455,   456,    -1,   458,     7,    -1,
      -1,    10,    11,    12,   465,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     481,    -1,    31,    32,    -1,   486,   487,    -1,   489,   490,
     491,   492,   493,   494,   495,   496,   497,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,    -1,   138,
      -1,   140,   141,   142,   143,   144,   145,   146,    -1,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,    -1,   238,
      -1,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   260,   261,   262,   263,    -1,    -1,    -1,    -1,   268,
      -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,   288,
     289,   290,    -1,    -1,    -1,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     319,   320,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   401,   402,   403,   404,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,
     419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,   430,   431,   432,   433,    -1,    -1,   436,   437,   438,
     439,   440,   441,   442,   443,    -1,    -1,    -1,    -1,    -1,
       7,    -1,    -1,    10,    11,    12,    -1,    -1,   457,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,   467,   468,
     469,    -1,   471,   472,    31,    32,    -1,    -1,   477,   478,
      -1,    -1,    -1,    -1,   483,   484,   485,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,   497,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,   129,   130,   131,   132,   133,   134,   135,   136,
      -1,   138,    -1,   140,   141,   142,   143,   144,   145,   146,
      -1,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,   238,    -1,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,   261,   262,   263,    -1,    -1,    -1,
      -1,   268,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     287,   288,   289,   290,    -1,    -1,    -1,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   319,   320,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   401,   402,   403,   404,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   418,   419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,   430,   431,   432,   433,    -1,    -1,   436,
     437,   438,   439,   440,   441,   442,   443,    -1,    -1,    -1,
      -1,    -1,     7,    -1,    -1,    10,    11,    12,    -1,    -1,
     457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,
     467,   468,   469,    -1,   471,   472,    31,    32,    -1,    -1,
     477,   478,    -1,    -1,    -1,    -1,   483,   484,   485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
     497,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,    -1,    -1,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,    -1,   138,    -1,   140,   141,   142,   143,   144,
     145,   146,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,    -1,    -1,   203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,   238,    -1,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,   261,   262,   263,    -1,
      -1,    -1,    -1,   268,    -1,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   287,   288,   289,   290,    -1,    -1,    -1,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   319,   320,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    -1,    -1,
      -1,    65,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   401,   402,   403,   404,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   418,   419,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,   430,   431,   432,   433,    -1,
      -1,   436,   437,   438,   439,   440,   441,   442,   443,    -1,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   466,   467,   468,   469,    -1,   471,   472,   152,    -1,
     154,    -1,   477,   478,    -1,    -1,    -1,    -1,   483,   484,
     485,     7,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    49,    -1,    51,    52,    53,    54,    -1,
      56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,    -1,    -1,   307,   308,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,
      -1,    56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,
      65,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   426,   427,   428,   429,   430,   431,   432,   433,
      -1,    -1,   436,   437,   438,   439,   440,   441,   442,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,   144,
      -1,   307,   308,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,    -1,   239,    -1,    -1,    -1,    -1,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,   427,   428,   429,   430,   431,   432,   433,    -1,    -1,
     436,   437,   438,   439,   440,   441,   442,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   307,   308,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,    -1,
      56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   426,   427,   428,   429,   430,   431,   432,   433,    -1,
      -1,   436,   437,   438,   439,   440,   441,   442,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   307,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,   427,   428,   429,   430,   431,   432,   433,    -1,    -1,
     436,   437,   438,   439,   440,   441,   442,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   497
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     7,     9,    10,    11,    12,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    47,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    62,    64,    65,
      66,    67,    68,    69,    71,    72,    73,    74,    75,    76,
     124,   125,   126,   127,   128,   139,   144,   151,   152,   153,
     154,   189,   190,   204,   237,   239,   245,   246,   247,   248,
     249,   250,   252,   291,   292,   293,   306,   307,   308,   353,
     377,   378,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   416,   417,   420,   426,   427,   428,   429,   430,
     431,   432,   433,   436,   437,   438,   439,   440,   441,   442,
     444,   448,   450,   451,   455,   456,   458,   465,   481,   486,
     487,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     499,   500,   501,   502,   503,   504,   505,   506,   509,   510,
     511,   512,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   576,    10,    11,    12,    52,    53,    54,    56,    59,
      60,    65,    67,    68,   144,   154,   428,   429,   430,   431,
     432,   433,   436,   437,   438,   439,   440,   441,   442,   519,
     520,   535,   574,    59,   520,   560,   520,   560,    55,   533,
     534,   535,   573,    12,   454,   535,   574,    47,   576,   535,
     512,   533,   573,   512,   533,    12,   512,   535,   112,   113,
     123,   112,   113,   123,   112,   113,   123,   123,    18,    18,
     103,   104,    12,   123,    18,   123,    12,    12,   501,    18,
      18,    14,   102,    14,    52,    53,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     535,   577,    12,    12,    12,    12,    14,    12,    12,    14,
      12,    14,    12,    18,    18,    18,    18,    12,    12,    12,
      14,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,   520,
     560,   520,   560,   520,   560,   520,   560,   520,   560,   520,
     560,   520,   560,   520,   560,   520,   560,   520,   560,   520,
     560,   520,   560,   520,   560,   576,   513,   514,   533,    47,
      12,    12,   576,    12,    12,    12,    12,    12,    12,     0,
       0,   501,   502,   503,   504,   505,   506,   501,    10,    11,
     119,   120,   520,   560,     7,     8,    10,    11,     5,     6,
     117,   118,   119,   120,    16,     4,    17,   115,    20,   116,
      12,    14,    18,   102,   123,   121,     7,   122,    10,    11,
      18,   102,   102,   123,    18,    18,    18,    14,    14,    18,
      18,    12,    18,    18,    13,    13,    18,    13,   533,   512,
      18,   533,   533,   533,   512,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     350,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   470,   488,
     324,   326,   328,   329,   336,   339,   340,   341,   342,   343,
     344,   375,   379,   384,   385,   394,   399,   400,   574,   574,
     533,   533,   573,    38,   422,   423,   424,   425,   421,    10,
      11,    12,    16,    31,    32,    56,    58,    63,   125,   129,
     130,   131,   132,   133,   134,   135,   136,   138,   140,   141,
     142,   143,   144,   145,   146,   148,   149,   154,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   203,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   238,   240,   241,   242,   243,
     244,   251,   260,   261,   262,   263,   268,   270,   287,   288,
     289,   290,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   319,   320,   401,   402,   403,   404,
     418,   419,   428,   429,   430,   431,   432,   433,   436,   437,
     438,   439,   440,   441,   442,   443,   457,   466,   467,   468,
     469,   471,   472,   477,   478,   483,   484,   485,   507,   512,
     519,   533,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   574,   507,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   383,    38,   220,
     533,   321,   533,    14,   533,   533,    10,    11,    12,    56,
     125,   144,   154,   428,   429,   430,   431,   432,   433,   436,
     437,   438,   439,   440,   441,   442,   519,   535,   554,   574,
     535,   554,   554,   535,   554,   535,   554,   535,   147,   199,
     200,   201,   202,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   201,   202,   201,   202,   201,
     202,   535,   535,   535,   554,   554,   535,   535,   535,   535,
     535,   535,   535,   535,    47,    47,   533,   535,   533,   535,
     533,    10,    11,    12,    59,   428,   429,   430,   431,   432,
     433,   436,   437,   438,   439,   440,   441,   442,   519,   573,
      47,   554,   535,   123,    48,   513,   501,    67,   576,   577,
      47,    12,   533,   512,    56,   535,   535,   535,   501,   510,
     510,   512,   512,   520,   520,   521,   521,   523,   523,   523,
     523,   524,   524,   525,   526,   527,   528,   530,   529,   533,
     533,    43,    44,   137,   199,   217,   220,   221,   222,   223,
     252,   253,   254,   380,   381,   398,   415,   576,   554,    56,
     533,   554,   520,   560,   560,   521,   561,   521,   561,   217,
     218,   219,   220,   250,   258,   271,   313,   315,   316,   317,
     326,   327,   332,   333,   334,   335,   345,   346,   347,   348,
     349,   351,   352,   354,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   479,
     255,   256,   257,   264,   265,   266,   267,   269,   309,   312,
     313,   314,   315,   317,   318,   321,   474,   475,   476,   480,
     482,   574,   575,   321,   554,    10,    11,    12,    31,    33,
      58,    61,    66,    77,   321,   376,   406,   409,   421,   428,
     429,   430,   431,   432,   433,   436,   437,   438,   439,   440,
     441,   442,   512,   519,   533,   554,   555,   573,   574,   575,
     533,   533,   533,    12,   518,    13,    19,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    19,   512,   533,    12,
      12,    12,   535,   539,   540,   540,   534,   554,    52,    53,
     535,   574,    12,    47,    12,    18,    18,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    18,    12,    12,    12,    12,    18,    12,
      12,    12,    18,    18,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,    12,    12,    12,
      12,    12,    12,    18,    12,    12,    12,    12,    12,    13,
      19,   540,    12,    14,   123,     4,     7,     8,    10,    11,
       5,     6,   117,   118,   119,   120,    16,    17,   115,    20,
     116,    18,    13,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,   512,    15,
      14,    15,   533,    13,    19,   534,   535,    18,    12,    18,
      18,    12,    13,    18,    13,    15,    13,    13,    15,    13,
      15,    19,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    19,    13,    19,    13,    15,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    13,
      19,    19,    13,    19,    13,    13,    19,    13,   533,   515,
     453,   501,    13,    13,    13,   459,   460,   461,   462,   463,
     508,    19,    13,    19,    19,    19,    19,    21,    13,    19,
      21,    22,    15,    12,    12,   512,    12,    12,    12,    12,
      12,    12,    12,    12,   512,    12,    12,   512,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      47,    12,    12,    12,    12,    12,    18,    14,    14,    12,
      18,    12,    12,    14,    12,    12,    12,    12,    18,    15,
      15,   533,   533,   535,   533,   533,   533,   533,   533,   535,
     533,   533,    56,   535,    49,    56,   533,   533,   533,   533,
     533,   533,   533,   554,   533,    58,   533,    64,   533,   533,
     575,   533,   533,   533,   533,   533,   574,    58,   555,    58,
      49,   533,   533,   533,   533,   512,    52,   512,    13,    13,
     512,   534,   535,   533,   322,   322,   323,   507,   535,   554,
     535,   554,   554,   535,   535,   535,   535,   535,   554,   535,
     535,   535,   535,   535,    45,    46,   535,   535,   535,   535,
      45,   164,   199,   554,   554,   535,   199,   199,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   554,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   554,   554,   554,   554,   554,   535,   535,   535,   535,
     535,   574,   574,   512,   512,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   554,   535,
     535,   535,   535,   535,   535,   554,   554,   554,   554,   554,
     535,   554,   554,   473,   554,   554,   554,   554,   512,    16,
      56,   512,   533,   554,   554,    21,    56,   533,   535,   578,
     553,   540,   520,   540,   520,   540,   521,   541,   521,   541,
     523,   544,   523,   544,   523,   544,   523,   544,   523,   545,
     523,   545,   546,   548,   549,   551,   550,   355,   356,   357,
     358,   501,   512,   512,    52,    53,   512,    54,    53,   533,
      55,    55,   533,    64,   533,   512,   533,   123,   533,   123,
      15,    64,    13,    18,    12,    12,    12,   535,   533,   535,
     533,   533,   533,   535,   535,   535,   535,   533,   533,   533,
     533,   533,   533,   533,   535,   533,   535,   535,   535,   150,
     535,   535,   150,   535,   150,   535,   535,   535,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   535,   554,    12,   533,   533,   533,   533,
     533,   533,   533,   535,   535,   535,   533,   533,   533,   512,
     445,   513,    50,    50,    50,    50,    50,    13,    19,   533,
     533,   512,   535,   535,   531,   533,   533,   533,   123,   512,
     535,   535,   535,   533,   535,   533,   535,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   554,
     533,   533,   533,   533,   533,   533,   533,   533,   535,   554,
     533,   554,   533,   533,   535,   533,   533,   533,   554,   535,
     574,   574,   574,   554,   554,   554,   512,   554,   535,   574,
     535,   574,   574,   554,    13,   512,   554,   554,   554,   554,
     554,   259,   533,   533,   512,   374,   507,   512,   533,    66,
     533,   533,   512,    13,    19,    19,    19,    19,    19,    13,
      19,    13,    19,    13,    13,    13,    19,    19,    19,    19,
      19,    13,    13,    19,    19,    19,    19,    13,    19,    13,
      19,    13,    19,    13,    13,    19,    19,    19,    19,    13,
      18,    13,    19,    13,    19,    19,    19,    13,    13,    13,
      13,    19,    12,   539,    13,    19,    18,    19,    13,    19,
      19,    19,    19,    13,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    13,    19,    12,    12,
      19,    19,    19,    12,    12,    13,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    13,    13,    13,    19,    13,
      19,    19,    19,    19,    19,    13,    19,    19,    19,    19,
      19,    19,    19,    19,    13,    19,    19,    19,    19,    19,
      19,    13,    13,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    13,    13,    13,    13,
      13,    13,    13,    19,    19,    19,    13,    19,    19,    19,
      19,    19,    12,    13,    19,    13,    19,    19,    13,    13,
      52,    53,   535,   574,    13,    19,    15,    21,    15,    21,
      12,    12,    12,    12,    13,    13,    19,    19,    19,    13,
      13,    19,    19,    19,    19,    19,    13,    13,    13,    13,
     575,    15,   554,    13,    12,   535,   535,   535,    13,    19,
      13,    19,    13,    19,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    19,    13,    13,
      19,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    19,    13,    19,    13,    13,    13,    13,    19,
      13,    13,    13,    13,    13,    19,    13,    13,   554,    19,
      19,    13,    19,    19,    19,    13,    19,    19,    19,    19,
      19,    19,    13,    19,   533,   501,   513,   459,   460,   461,
     462,   463,    19,    19,    13,    19,    19,    13,    19,    22,
      19,    13,   533,   554,    13,    13,    19,    13,    13,    19,
      13,    19,    13,    13,    13,    19,    19,    13,    19,    13,
      13,    13,    13,    13,    19,    13,    13,    19,    13,    19,
      13,    19,    19,    19,    13,    13,    13,    13,    13,    13,
      13,    13,    19,    19,    13,    13,    19,    13,    13,    13,
      13,    19,    19,    19,    19,    19,    19,    13,    19,    19,
      19,    13,    19,    19,    19,    19,    19,    13,    13,    19,
      19,    19,    19,    19,    12,    15,    15,    13,    13,    13,
      15,    19,    13,    13,    19,   535,   533,   533,   533,   533,
     533,   533,   535,   535,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   535,
     533,   554,   123,    47,   533,   533,   554,    47,   535,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   535,   535,   554,   554,   535,   535,
     535,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     535,   535,   535,   535,   535,   535,   535,   535,   533,   533,
     533,   533,   554,   554,   533,   533,   533,   533,   535,   512,
     535,   535,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   535,   533,
     533,   535,   533,   533,   554,    21,   533,   552,   535,    13,
      13,    13,   533,   533,    64,   533,   512,   512,   512,   533,
      13,    13,    13,    19,   535,   533,   533,   533,   535,   533,
     533,   533,   533,    13,   533,   533,   533,   554,   533,   533,
     533,   533,   535,   535,   533,   533,   533,   446,   513,   501,
      50,    50,    50,    50,    50,   533,   533,   535,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   554,   554,   533,    66,    47,
      19,    13,    19,    13,    19,    13,    19,    13,    13,    13,
      13,    19,    19,    13,    19,    19,    19,    19,    13,    19,
      19,    19,    19,    13,    13,    13,    19,   533,    13,    19,
      19,    13,    13,    19,    19,    19,    13,    13,    13,    13,
      19,    13,    19,    19,    19,    19,    19,    19,    19,    19,
      13,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    13,    19,    19,    19,    19,
      19,    19,    13,    13,    19,    13,    13,    13,    19,    19,
      13,    13,    13,    13,    19,    13,    13,    19,    19,    19,
      13,    13,    13,    13,    13,    13,    13,    13,    19,    19,
      19,    19,    19,    13,    19,    19,    13,    19,    19,    13,
      13,    13,    19,    19,    13,    19,    19,    13,    13,    13,
      13,    19,    13,   533,    13,    19,    13,    13,    19,    19,
      13,    19,    19,    13,    19,    13,    19,    13,    19,    13,
      19,    19,    19,    19,    19,    19,    19,    19,    13,   533,
     501,    13,    19,    19,    19,    13,    19,    22,    13,    21,
      19,    19,    19,    19,    19,    19,    13,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    13,    19,    19,    19,
      19,    13,    13,    19,    13,    13,    13,    13,    13,    19,
      13,    19,    19,    19,    19,    19,    19,    19,    19,    13,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   535,   533,   534,   534,
     535,    47,   535,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   535,   533,   535,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     535,   535,   535,   535,   535,   533,   533,   533,   554,   554,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   512,    13,   533,   535,   533,
     533,   533,   554,   554,   554,   554,   533,   533,   533,   535,
     535,   533,   533,   513,   533,   535,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   535,
     554,   533,   533,   533,   533,   554,   554,   533,   533,    13,
      13,    19,    19,    13,    19,    19,    13,    19,    19,    13,
      19,    19,    19,    13,    19,    19,    13,    19,    19,    13,
      13,    19,    19,    19,    19,    13,    19,    13,    19,    13,
      19,    13,    19,    19,    19,    19,    19,    13,    13,    13,
      19,    19,    19,    19,    19,    19,    13,    19,    19,    19,
      19,    19,    19,    19,    13,    19,    19,    19,    19,    19,
      19,    19,    13,    13,    13,    13,    19,    19,    13,    19,
      19,    19,    19,    19,    19,    13,    19,    21,    21,    13,
      13,    19,    19,    13,    19,    13,    19,    13,    13,    19,
      13,    19,    19,    13,    19,    13,    19,    19,    13,    13,
     501,    19,    19,    19,    13,    13,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    19,    19,    19,    19,    19,    13,    13,    13,    19,
      13,    19,    19,    19,    13,    13,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   534,   533,   534,
      47,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   578,   533,
     578,   533,   578,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   535,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   512,   533,   533,   533,   533,
     533,   533,   533,   554,   535,   533,   535,   533,   533,   533,
     533,   533,   533,   533,   533,   554,   533,   533,   533,    19,
      13,    13,    19,    19,    19,    13,    13,    13,    19,    13,
      19,    19,    19,    13,    13,    19,    19,    19,    13,    19,
      13,    19,    19,    19,    19,    19,    19,    13,    19,    19,
      19,    19,    19,    19,    19,    13,    19,    13,    13,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    13,    19,
      19,    13,    13,    19,    13,    13,    13,    19,    19,    19,
      13,    15,    19,    13,    13,    13,    19,    19,    13,    13,
      19,    19,    13,    19,    19,    19,    19,    21,    13,    13,
      19,    19,    13,    19,    19,    19,    19,    19,   533,   533,
     533,   533,   533,   533,   533,   512,   534,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   578,   578,   578,   578,   533,   533,   533,   535,
     535,   535,   535,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   535,   533,   535,   533,   533,   533,
     533,   533,   554,   533,   533,   533,    13,    19,    19,    19,
      19,    13,    19,    19,    13,    13,    19,    13,    13,    13,
      13,    13,    13,    19,    13,    19,    13,    19,    13,    13,
      19,    13,    13,    13,    13,    19,    13,    13,    13,    13,
      19,    19,    13,    19,    13,    19,    13,    19,    21,    19,
      13,    19,    19,    19,    19,    19,    19,    13,    19,    19,
      19,    13,    19,    19,    19,    19,   533,   533,   533,   533,
     512,   533,   533,   533,   533,   533,   533,   533,   578,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   535,   533,
     535,   533,   123,   533,   533,   533,   554,   533,   533,   533,
      13,    13,    19,    13,    13,    19,    19,    19,    13,    13,
      13,    19,    13,    19,    19,    13,    19,    19,    13,    13,
      19,    19,    13,    19,    19,    19,    19,   554,    19,    19,
      19,    19,    13,    13,    19,    19,   533,   512,   533,   533,
     533,   533,   533,   533,   533,   554,   533,   554,   533,   533,
     533,   533,   533,   533,   533,   533,   533,    19,    13,    13,
      13,    13,    13,    19,    19,    19,    13,    13,    13,    19,
      19,    19,    13,    19,    19,    13,    13,    19,    13,    19,
     533,   533,   533,   533,   533,   533,   535,   533,   533,   533,
     554,    19,    19,    13,    19,    13,    19,    19,    13,    19,
      13,    19,   533,   533,   533,   533,   535,   533,   554,    19,
      13,    19,    19,    19,    13,    13,   533,   533,   533,   533,
      19,    19,    19,    13,   533,   533,   533,    19,    19,    19,
     533,   533,   533,    13,    19,    19,   533,   533,    19,    13,
     533,    13
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
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   734,
     735,   736,   737,   738,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   498,   499,   499,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   501,   501,   502,   502,
     502,   503,   503,   504,   505,   505,   505,   505,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     509,   509,   510,   510,   510,   510,   511,   511,   511,   512,
     513,   514,   515,   516,   516,   516,   516,   516,   516,   516,
     516,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   519,   519,   520,   520,   521,   521,   521,   522,   522,
     522,   523,   524,   524,   524,   524,   524,   525,   525,   525,
     525,   525,   526,   526,   527,   527,   528,   528,   529,   529,
     530,   530,   531,   531,   532,   533,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   535,   535,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   537,   537,   538,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   540,   540,   541,
     541,   541,   541,   541,   541,   542,   543,   543,   543,   543,
     543,   544,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   546,   546,   546,   546,   546,   547,   547,   548,   549,
     549,   550,   550,   551,   551,   552,   552,   553,   553,   554,
     555,   555,   555,   555,   556,   556,   556,   557,   557,   558,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   560,   561,
     561,   561,   561,   562,   562,   562,   562,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     574,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   576,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   578,   578,   578,   578
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     1,     8,    10,
       2,     4,     6,     7,     3,     1,     5,     2,     1,     1,
       1,     1,     1,     1,     4,     6,     6,     6,     6,     3,
       3,     6,     6,     3,     3,     3,     3,     6,     3,     3,
       6,     6,     6,     3,     3,     8,     8,     3,     1,     1,
       1,     1,     4,     1,     2,     2,     2,     1,     3,     3,
       3,     6,     6,    16,     2,     2,     3,     2,     2,     3,
       3,     2,     2,     3,     2,     2,     5,     2,     1,     1,
       2,     2,     4,     2,     2,     2,     1,     4,     3,     2,
       2,    10,     6,     3,     6,     6,     8,    28,     8,     8,
       3,     8,    12,     6,     6,    16,     8,    16,    10,     6,
      10,     8,    10,    14,     8,    12,     6,     8,     6,     6,
       6,    10,     6,    10,    10,    12,     6,     6,    12,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     8,     3,     3,     3,     3,     3,     3,    12,    16,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
      10,     6,    14,     6,     8,     6,     6,     8,     6,    10,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     3,     3,     4,     3,     6,     6,     4,     4,     6,
      10,    10,    10,     6,     6,     6,     6,     6,    10,     6,
      10,     6,     6,     6,     3,     6,     6,    10,    10,     6,
       6,     6,     3,     3,     3,     3,     6,     6,     3,     6,
       6,     8,    10,     3,     6,     3,     4,    20,     6,    10,
       6,     3,     3,     6,     3,     6,     8,     6,     6,     8,
      16,     6,     3,     6,     8,     3,    12,    12,    12,    10,
       8,     8,    10,     8,    10,    12,     6,     8,     8,    10,
      16,    18,    12,     6,    18,    16,    12,    10,    10,    10,
       6,    10,     6,     6,     6,     8,     1,     4,     8,     4,
      18,     4,     1,     1,     6,     6,     3,     3,     6,     6,
       3,     3,     3,     3,     3,     3,     3,     8,     6,     6,
       6,     3,     4,     1,     1,     1,     1,     1,    30,    24,
       4,     8,     0,     1,     3,     1,     3,     2,     4,     2,
       4,     1,     3,     2,     4,     2,     4,     1,     3,     0,
       2,     2,     2,     2,     2,     4,     4,     4,     4,     4,
       1,     1,     1,     6,     1,     3,     1,     3,     3,     1,
       3,     0,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     6,     8,    10,    10,     8,     6,     3,
       3,     3,     3,     3,     3,     6,     4,    10,     4,    10,
       4,     4,     4,     4,     4,     4,     7,     7,     7,     9,
       7,     6,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     8,    10,    10,     8,
       6,     8,     6,     8,     8,    12,     3,     6,     4,     4,
       1,     6,     6,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     4,     1,     3,     3,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     4,     2,
       4,    16,    14,    16,     4,     4,     4,     1,    10,    12,
       8,     1,     4,     6,     6,     6,     8,     8,     6,     6,
       8,     8,    10,    10,    12,    12,    10,     4,    10,     4,
       6,     4,     4,     4,    12,     4,    12,    12,    16,    20,
      10,    12,     4,     6,     6,     6,     4,     4,     6,     4,
       6,     6,     6,     4,    10,    16,    10,     8,    12,    10,
       8,    12,     8,    12,     8,    12,     3,     3,     8,     8,
       3,     6,    12,    12,    14,    12,    12,    16,     4,     8,
      10,    12,    10,    12,    10,    12,    12,    14,    12,     8,
      14,     4,     4,     4,     4,     3,     3,     3,     6,     6,
       6,     6,     8,    14,    12,    14,    12,     6,     8,    10,
      10,    12,     6,     6,     6,     6,     6,     6,     6,     6,
       8,    10,     4,     4,    10,    10,     4,     6,     6,    12,
      30,     8,     5,     5,     5,     6,     6,     4,     6,     4,
       6,     4,     4,    18,     8,     6,     1,     3,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     4,     1,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     1,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     3,     8,     4,     6,     1,     4,     1,     3,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     6,     6,     8,     8,     4,     6,     6,     6,     6,
       3,     2,     4,     1,     4,     6,     1,     4,     4,    10,
       6,    16,    18,    10,    20,     8,     4,     6,     8,     8,
      12,    16,    16,    18,    14,    14,    16,    20,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,    11,     7,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "LEX_ERROR", "T_EXP", "T_GT",
  "T_LT", "T_MULT", "T_DIV", "T_FACT", "T_ADD", "T_SUB", "T_OP_PAR",
  "T_CL_PAR", "T_OP_BR", "T_CL_BR", "T_AND", "T_OR", "T_POINT", "T_COMMA",
  "T_QUEST", "T_COLON", "T_SEMICOLON", "T_SetDebugOn", "T_SetDebugOff",
  "T_SetVerboseOn", "T_SetVerboseOff", "T_SetProgress", "T_argc",
  "T_emptyargs", "END_INSTRUCTION", "T_Image", "T_ReadRawImages",
  "T_Transform", "SHOW", "HELP", "QUIT", "T_HIDE", "PRINT", "PRINTN",
  "T_SPRINT", "ASHELL", "LS", "T_SetName", "T_GetName", "T_GetOutput",
  "T_GetDiffCoeff", "ASTRING", "ABLOCK", "NUMBER", "IDENTIFIER",
  "VAR_IMAGE", "VAR_FLOAT", "VAR_INT", "VAR_UCHAR", "VAR_STRING",
  "VAR_IMAGEDRAW", "VAR_SURFACE", "VAR_SURFDRAW", "VAR_MATRIX", "VAR_FILE",
  "VAR_C_FUNCTION", "VAR_C_PROCEDURE", "VAR_C_IMAGE_FUNCTION",
  "VAR_AMI_FUNCTION", "VAR_PARAMWIN", "VAR_GLTRANSFORM",
  "VAR_ARRAY_SURFACE", "VAR_ARRAY_IMAGE", "T_del", "ENDOP", "T_global",
  "T_local", "T_global_new", "T_local_new", "T_wait", "T_schedule",
  "T_ParamWin", "T_BeginPanel", "T_EndPanel", "T_BeginBook", "T_EndBook",
  "T_AddPage", "T_AddFloat", "T_AddInt", "T_CreateWin", "T_Display",
  "T_AddButton", "T_AddBoolean", "T_AddEnum", "T_AddEnumChoice",
  "T_AddString", "T_AddFilename", "T_ShowSlider", "T_SetCallback",
  "T_SetDragCallback", "T_BeginBox", "T_EndBox", "T_BeginHorizontal",
  "T_EndHorizontal", "T_redraw", "RIGHT_ASSIGN", "LEFT_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP", "INC_OP", "DEC_OP",
  "PTR_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "TRANSPOSE_OP", "POINTWISE_MULT", "ASSIGN_OP", "T_COUNT", "T_MAX",
  "T_argmax", "T_MIN", "T_MEDIAN", "OpImage", "FILTER", "NormGrad",
  "T_DiscNormGrad", "T_gradient", "SecDerGrad", "SecDerGrad2", "SubImage",
  "PutImage", "T_AutoCrop", "T_DiscSecDerGrad", "T_EDPdilate",
  "T_EDPerode", "T_EDPopen", "T_EDPclose", "AnisoGS", "AnisoSmoothGS",
  "T_vtkAnisoGS", "T_SetDistMap", "T_DiscMeanCurvature", "T_vtkMedian3D",
  "T_NULL", "T_InitTime", "T_TimeSpent", "T_EndTime", "T_LevelSetsCURV",
  "T_UpdateResult", "T_SetMeanCurv", "T_SetAffineCurv",
  "T_SetBalloonScheme", "T_SetVelocity", "T_SetExpansion",
  "T_SetExpansionImage", "T_SetAdvectionField", "T_SetCurvWeights",
  "T_GetAttachVect", "T_GetCurvature", "T_GetDistMap", "T_GetAdvection",
  "T_GetVelocity", "T_GetExpansion", "T_GetSkeleton", "T_SetDistMethod",
  "T_SetParam", "T_SetIsoContourBin", "T_SetBandTube", "T_SetThreads",
  "T_SaveDistMap", "T_SaveSecDerGrad", "T_SetNumGaussians",
  "T_SetGaussian", "T_SetProbThreshold", "T_SetILowTh", "T_SetIHighTh",
  "T_SetProbHighTh", "T_SetNumInitPoints", "T_SetInitPoint",
  "T_vtkFastMarching", "T_vtkFastMarchingTarget", "T_FluxDiffusion",
  "T_AnisoWeickert", "T_AnisoCW", "T_SRAD_qcoeff", "T_AnisoSRAD",
  "T_AnisoSRAD2", "T_AnisoLeeAdd2", "T_AnisoDPAD", "T_AnisoDPAD2",
  "T_AnisoNRAD", "T_AnisoRudinMult", "TInit", "TSetCoeff", "TIterate",
  "TEnd", "TAddGaussNoise", "T_SNR", "T_SetNoiseType", "T_SetNoiseSD",
  "T_GetNoiseSD", "T_GetDAcoeff", "T_SetMask", "T_SetSRADROI",
  "T_SetRNRADROI", "T_SetRNRADROI_NEW", "T_SetLocalStruct",
  "T_SetEigenMode", "T_Setdt", "T_Setneighborhood", "T_info", "T_NbPoints",
  "T_NbPolys", "T_save", "T_normalize", "T_OrientField",
  "T_OrientPositive", "T_2DFlux", "T_OutFlux", "T_OutFluxScalar",
  "T_OrientationRatio", "T_Skeleton", "T_SimplePoints", "T_CircleIntegral",
  "T_CircleIntegralExc", "T_CircleIntSdExc", "T_CircleMinIntSdExc",
  "T_LocalExtrema", "T_NormalField", "T_DirConnectivity", "T_eccentricity",
  "T_rot2D", "T_mean", "T_SUM", "T_localmean", "T_localmean2", "T_localSD",
  "T_localSD2", "T_struct_tensor", "T_StructTensorH", "T_HessianMatrix",
  "T_HessianEVal", "T_Derivatives", "T_curvatures", "T_Laplacian",
  "T_setvoxelsize", "T_settranslation", "T_setendianness",
  "T_Skeleton2lines", "T_SmoothLines", "T_ResampleLines", "T_RemoveLine",
  "T_ConnectLines", "T_threscross", "T_IsocontourPoints", "T_IsosurfDist",
  "T_vtkIsoContourDist", "T_ShortestPath", "T_ShortestPathImage",
  "T_PathFromDispl", "T_PathFromVectField", "T_LineRecons",
  "T_ReadCTALine", "T_ReadCTALineRadii", "T_WriteCTALine",
  "T_SetIsoContour", "T_SetIsoContourParam", "T_DrawIsoContour",
  "T_SetIsoContourColor", "T_DrawAllContours", "T_AllContoursParam",
  "T_GetZmin", "T_GetZmax", "T_GetYmin", "T_GetYmax", "T_GetXmin",
  "T_GetXmax", "T_GetXPos", "T_GetYPos", "T_GetZPos", "T_vtkDicomRead",
  "T_vtkMINCRead", "T_Convolve", "T_ConvolveMask", "T_Pad", "T_Eigen2D",
  "T_Eigen3D", "T_ChamferDT", "T_Chamfer2DT", "T_BorgeforsDT",
  "T_BorgeforsSDT", "T_vtkSignedBorgefors", "T_vtkSignedFMDist",
  "T_PropagationDist", "T_PropagationDist2", "T_PropDanielsson",
  "T_vtkPropDanielsson", "T_vtkPropDaniel2", "T_CC", "T_ProcessXEvents",
  "T_isoarea2D", "T_posarea", "T_isosurf", "T_isosurf_inv",
  "T_isosurf_ijk", "T_isosurf_ras", "T_vtkDecimate", "T_vtkMarchingCubes",
  "T_vtkSmooth", "T_Recompute", "T_vtkWindowedSinc", "T_isoline",
  "T_vtkDist", "T_AndreDist", "T_Surface", "T_getimage", "T_GetImageFromX",
  "T_rotate", "T_computeCC", "T_drawCC", "T_setminCC", "T_addobj",
  "T_setcurrentobj", "T_writeVRML", "T_writeVTK", "T_OwnMaterial",
  "T_SetColor", "T_SetColors", "T_SetColorOpacity", "T_Paint",
  "T_SetLight", "T_SetLightPos", "T_SetLightAmbient", "T_SetLightDiffuse",
  "T_SetLightSpecular", "T_SetBackground", "T_Remove", "T_SwapBuffers",
  "T_SetAmbient", "T_SetDiffuse", "T_SetSpecular", "T_SetShininess",
  "T_SetOpacity", "T_SetOpacityImage", "T_SetVisible",
  "T_SetColorMaterial", "T_penguin", "T_Statistics", "T_GetIntensities",
  "T_GetLinesLength", "T_GetLinesExtremities", "T_GetConnections",
  "T_SelectLines", "T_RemoveSelection", "T_mergepoints", "T_Triangulate",
  "T_Displace", "T_Normals", "T_InvertNormals", "T_Translate", "T_Scale",
  "T_SetPointsColors", "T_SetLineWidth", "T_AddPoint", "T_NewLine",
  "T_EndLine", "T_LineAddPointNumber", "T_GetTransform", "T_SetTransform",
  "T_Interpolate", "T_Matrix", "T_Invert", "T_PrintMatrices", "SET",
  "SETPOS", "SHOWCURSOR", "UPDATE", "COMPARE", "SETVECTOR",
  "T_SetCompareDisplacement", "T_DrawVector", "T_DisplayVectors",
  "T_SetVectParam", "T_SetVectColor", "T_SetVectStyle",
  "T_SetLineThickness", "T_SetZoom", "T_SetWindowSize", "T_SetColormap",
  "T_drawcircle", "T_setGLwin", "T_initvalue", "T_ShowSection",
  "T_HideSection", "T_Xpos", "T_Ypos", "T_Zpos", "T_SpacePos", "T_CHAR",
  "T_UCHAR", "T_SHORT", "T_USHORT", "T_INT", "T_UINT", "T_FLOAT",
  "T_DOUBLE", "T_RGB", "T_FLOAT_VECTOR", "T_GetFormat", "T_atof",
  "T_gnuplot", "T_histo", "T_cumhisto", "T_DisplayHisto", "T_OPEN",
  "T_CLOSE", "T_scan_float", "T_read", "T_rewind", "T_LineNumber",
  "CONST_PI", "SIN", "COS", "TAN", "ASIN", "ACOS", "ATAN", "SINH", "COSH",
  "EXP", "LN", "LOG", "SQRT", "ABS", "ROUND", "FLOOR", "NORM", "FOR", "TO",
  "STEP", "ENDFOR", "T_REPEAT", "T_UNTIL", "T_BREAK", "IF", "THEN", "ELSE",
  "VARIABLES", "FUNCTION", "T_exists", "T_slice", "T_GenRead", "T_IMAGE",
  "T_IMAGEDRAW", "T_SURFACE", "T_NUM", "T_STRING", "T_TRANSFORM", "T_PROC",
  "T_MeanHalfSize", "T_Resize", "T_ReSlice", "T_Flip", "T_SetCompTransf",
  "T_ConvexHull", "T_itk", "T_CannyEdgeDetector", "T_CreateFlatMesh",
  "T_CreateVolume", "T_vtkCreateFlatMesh", "T_Altitude2Position",
  "T_GeoCoordinates", "T_ElevateMesh", "T_CreateVectors",
  "T_Set3DArrowParam", "T_CreateEllipsoids", "T_ComputeAltitudes",
  "T_Temp2Altitudes", "T_ReadFlow", "T_SetFluidNavFile",
  "T_DrawEarthCoord", "T_PaintCallback", "T_SaveStructuredGrid",
  "T_import_ami", "T_import_vtk", "T_import_itk", "T_import_wii",
  "T_import_filters", "T_amiOFCorr2D", "T_amiOFVar2D", "'~'", "$accept",
  "start", "list_commands", "end_instr", "loop_inst", "cond_inst",
  "proc_decl", "func_inst", "command", "param_list", "param_list_decl",
  "primary_expr_string", "postfix_expr_string", "additive_expr_string",
  "expr_string", "instr_block", "begin_block", "end_block", "primary_expr",
  "postfix_expr", "unary_expr", "unary_operator", "cast_expr",
  "multiplicative_expr", "additive_expr", "shift_expr", "relational_expr",
  "equality_expr", "and_expr", "exclusive_or_expr", "inclusive_or_expr",
  "logical_and_expr", "logical_or_expr", "conditional_expr",
  "assignment_expr", "expr", "basic_type", "var_image", "image",
  "primary_image", "postfix_image", "unary_image", "cast_image",
  "multiplicative_image", "additive_image2", "additive_image",
  "shift_image", "relational_image", "equality_image", "and_image",
  "exclusive_or_image", "inclusive_or_image", "logical_and_image",
  "logical_or_image", "conditional_image", "assignment_image",
  "expr_image", "gltransform", "matrix", "primary_matrix",
  "postfix_matrix", "unary_matrix", "cast_matrix", "multiplicative_matrix",
  "additive_matrix", "shift_matrix", "relational_matrix",
  "equality_matrix", "and_matrix", "exclusive_or_matrix",
  "inclusive_or_matrix", "logical_and_matrix", "logical_or_matrix",
  "conditional_matrix", "assignment_matrix", "expr_matrix", "var_surface",
  "surface", "identifier", "variable", "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       499,     0,    -1,    -1,   500,     0,    -1,   501,    -1,   500,
     501,    -1,   506,   501,    -1,   500,   506,   501,    -1,   502,
      -1,   500,   502,    -1,   503,    -1,   500,   503,    -1,   505,
      -1,   500,   505,    -1,   504,    -1,   500,   504,    -1,    30,
      -1,    22,    -1,   444,   576,   123,   533,   445,   533,   513,
     501,    -1,   444,   576,   123,   533,   445,   533,   446,   533,
     513,   501,    -1,   448,   513,    -1,   451,   533,   513,   501,
      -1,   451,   533,   513,   453,   513,   501,    -1,   465,   576,
      12,   508,    13,   513,   501,    -1,   455,    47,   501,    -1,
     455,    -1,    64,    12,   507,    13,   501,    -1,    64,   501,
      -1,    29,    -1,   450,    -1,    71,    -1,    73,    -1,    74,
      -1,    72,    -1,    75,    12,   533,    13,    -1,    76,    12,
     533,    19,    64,    13,    -1,   576,   123,   321,    14,   533,
      15,    -1,   576,   102,   321,    14,   533,    15,    -1,   576,
     123,    31,    14,   533,    15,    -1,   576,   123,   554,    -1,
     576,   102,   554,    -1,   576,   123,    61,    12,   507,    13,
      -1,    68,    14,   533,    15,   123,   554,    -1,   576,   123,
     573,    -1,   576,   123,   555,    -1,    59,   123,   533,    -1,
      59,   123,   573,    -1,    67,    14,   533,    15,   123,   575,
      -1,   576,   123,   575,    -1,   574,   102,   575,    -1,    67,
     102,   321,    14,   533,    15,    -1,   576,   123,   409,    12,
     533,    13,    -1,   576,   123,   406,    12,   533,    13,    -1,
     576,   123,   533,    -1,   576,   123,   512,    -1,   576,   123,
     421,    12,   512,    19,    47,    13,    -1,    60,   123,   421,
      12,   512,    19,    47,    13,    -1,    60,    18,   425,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,    12,
     533,    13,    -1,    36,    -1,    34,   535,    -1,    37,   535,
      -1,    34,   574,    -1,   353,    -1,   535,   123,   554,    -1,
     535,   102,   554,    -1,   535,   123,   533,    -1,   535,    14,
     533,    15,   123,   554,    -1,   535,    14,   533,    15,   123,
     533,    -1,   535,    12,   533,    21,   533,    19,   533,    21,
     533,    19,   533,    21,   533,    13,   123,   554,    -1,    52,
     112,    -1,    52,   113,    -1,    52,   123,   533,    -1,    53,
     112,    -1,    53,   113,    -1,    53,   123,   533,    -1,    54,
     123,   533,    -1,    54,   112,    -1,    54,   113,    -1,    55,
     123,   512,    -1,    34,   454,    -1,    69,   577,    -1,    69,
      67,    14,   533,    15,    -1,    41,   512,    -1,    42,    -1,
      35,    -1,    35,   576,    -1,    35,    47,    -1,    60,    18,
      38,   512,    -1,    38,   512,    -1,    39,   512,    -1,    38,
     573,    -1,   573,    -1,    60,    18,    38,   533,    -1,    60,
      18,   422,    -1,    38,   533,    -1,    39,   533,    -1,    56,
      18,   381,    12,   533,    19,   533,    19,   533,    13,    -1,
      56,    18,   382,    12,   533,    13,    -1,    56,    18,   383,
      -1,    56,    18,   384,    12,   535,    13,    -1,    56,    18,
     384,    12,    56,    13,    -1,    56,    18,   386,    12,    56,
      19,   535,    13,    -1,    56,    18,   470,    12,   533,    19,
     533,    19,   533,    19,   533,    19,   533,    19,   533,    19,
     533,    19,   533,    19,   533,    19,   533,    19,   533,    19,
     533,    13,    -1,    56,    18,   385,    12,    49,    19,   535,
      13,    -1,    56,    18,   387,    12,   533,    19,   533,    13,
      -1,    56,    18,   388,    -1,    56,    18,   389,    12,   533,
      19,   533,    13,    -1,    56,    18,   390,    12,   533,    19,
     533,    19,   533,    19,   533,    13,    -1,    56,    18,   391,
      12,   533,    13,    -1,    56,    18,   392,    12,   533,    13,
      -1,    56,    18,   393,    12,   533,    19,   533,    19,   533,
      19,   533,    19,   533,    19,   533,    13,    -1,    56,    18,
     394,    12,   533,    19,   533,    13,    -1,    56,    18,   396,
      12,   533,    19,   533,    19,   533,    19,   533,    19,   533,
      19,   533,    13,    -1,    56,    18,   395,    12,   554,    19,
     533,    19,   533,    13,    -1,    56,    18,   397,    12,    58,
      13,    -1,    56,    18,   272,    12,   533,    19,   535,    19,
     533,    13,    -1,    56,    18,   272,    12,   535,    19,   533,
      13,    -1,    56,    18,   273,    12,   533,    19,   533,    19,
     533,    13,    -1,    56,    18,   273,    12,   533,    19,   533,
      19,   533,    19,   533,    19,   533,    13,    -1,    56,    18,
     274,    12,   533,    19,   533,    13,    -1,    56,    18,   275,
      12,   533,    19,   533,    19,   533,    19,   533,    13,    -1,
      56,    18,   276,    12,   533,    13,    -1,    56,    18,   277,
      12,   533,    19,   533,    13,    -1,    56,    18,   488,    12,
      64,    13,    -1,    56,    18,   350,    12,   535,    13,    -1,
     535,    18,   398,    12,   533,    13,    -1,   535,    18,   398,
      12,   533,    19,   533,    19,   533,    13,    -1,   535,    18,
     380,    12,   533,    13,    -1,   535,    18,   380,    12,   533,
      19,   533,    19,   533,    13,    -1,   535,    18,   381,    12,
     533,    19,   533,    19,   533,    13,    -1,   535,    18,   137,
      12,   535,    19,   533,    19,   533,    19,   533,    13,    -1,
     535,    18,   137,    12,   535,    13,    -1,   535,    18,    43,
      12,   512,    13,    -1,   144,    18,   199,    12,   535,    19,
     533,    19,   533,    19,   533,    13,    -1,   144,    18,   200,
      12,   533,    13,    -1,   144,    18,   147,    12,   533,    13,
      -1,   144,    18,   205,    12,   533,    13,    -1,   144,    18,
     206,    12,   533,    13,    -1,   144,    18,   209,    12,   535,
      13,    -1,   144,    18,   210,    12,   535,    13,    -1,   144,
      18,   211,    12,   535,    13,    -1,   144,    18,   212,    12,
     535,    13,    -1,   144,    18,   213,    12,   533,    13,    -1,
     144,    18,   214,    12,   533,    13,    -1,   144,    18,   215,
      12,   533,    13,    -1,   144,    18,   216,    12,   533,    13,
      -1,   144,    18,   200,    12,   533,    19,   533,    13,    -1,
     144,    18,   201,    -1,   144,    18,   202,    -1,   189,    18,
     201,    -1,   189,    18,   202,    -1,   190,    18,   201,    -1,
     190,    18,   202,    -1,   154,    18,   172,    12,   533,    19,
     533,    19,   533,    19,   533,    13,    -1,   154,    18,   172,
      12,   533,    19,   533,    19,   533,    19,   533,    19,   533,
      19,   533,    13,    -1,   154,    18,   156,    12,   533,    13,
      -1,   154,    18,   157,    12,   533,    13,    -1,   154,    18,
     158,    12,   533,    13,    -1,   154,    18,   171,    12,   533,
      13,    -1,   154,    18,   175,    12,   533,    13,    -1,   154,
      18,   180,    12,   533,    13,    -1,   154,    18,   181,    12,
     533,    13,    -1,   154,    18,   182,    12,   533,    13,    -1,
     154,    18,   183,    12,   533,    13,    -1,   154,    18,   178,
      12,   533,    13,    -1,   154,    18,   179,    12,   533,    19,
     533,    19,   533,    13,    -1,   154,    18,   184,    12,   533,
      13,    -1,   154,    18,   185,    12,   533,    19,   533,    19,
     533,    19,   533,    19,   533,    13,    -1,   154,    18,   173,
      12,   533,    13,    -1,   154,    18,   159,    12,   535,    19,
     533,    13,    -1,   154,    18,   160,    12,   533,    13,    -1,
     154,    18,   161,    12,   535,    13,    -1,   154,    18,   174,
      12,   533,    19,   533,    13,    -1,   154,    18,   163,    12,
     535,    13,    -1,   154,    18,   162,    12,   535,    19,   535,
      19,   535,    13,    -1,   154,    18,   165,    12,   535,    13,
      -1,   154,    18,   166,    12,   535,    13,    -1,   154,    18,
     167,    12,   535,    13,    -1,   154,    18,   170,    12,   535,
      13,    -1,   154,    18,   168,    12,   535,    13,    -1,   154,
      18,   169,    12,   535,    13,    -1,   154,    18,   165,    12,
     150,    13,    -1,   154,    18,   167,    12,   150,    13,    -1,
     154,    18,   168,    12,   150,    13,    -1,   154,    18,   176,
      12,   533,    13,    -1,   154,    18,   177,    12,   533,    13,
      -1,   154,    18,   201,    -1,   154,    18,   202,    -1,   535,
      18,   220,   512,    -1,   535,    18,   221,    -1,   535,    18,
     222,    12,   535,    13,    -1,   535,    18,   223,    12,   535,
      13,    -1,   574,    18,   220,   512,    -1,   574,    18,   271,
     512,    -1,   574,    18,   332,    12,   533,    13,    -1,   574,
      18,   345,    12,   533,    19,   533,    19,   533,    13,    -1,
     574,    18,   346,    12,   533,    19,   533,    19,   533,    13,
      -1,   574,    18,   347,    12,   533,    19,   533,    19,   533,
      13,    -1,   574,    18,   348,    12,   533,    13,    -1,   574,
      18,   349,    12,   533,    13,    -1,   574,    18,   351,    12,
     533,    13,    -1,   574,    18,   352,    12,   533,    13,    -1,
     574,    18,   335,    12,   533,    13,    -1,   574,    18,   333,
      12,   533,    19,   533,    19,   533,    13,    -1,   574,    18,
     368,    12,   535,    13,    -1,   574,    18,   334,    12,   554,
      19,   533,    19,   533,    13,    -1,   574,    18,   334,    12,
     554,    13,    -1,   574,    18,   354,    12,   535,    13,    -1,
     574,    18,   361,    12,   533,    13,    -1,   574,    18,   362,
      -1,   574,    18,   250,    12,   533,    13,    -1,   574,    18,
     363,    12,   554,    13,    -1,   574,    18,   366,    12,   533,
      19,   533,    19,   533,    13,    -1,   574,    18,   367,    12,
     533,    19,   533,    19,   533,    13,    -1,   574,    18,   369,
      12,   533,    13,    -1,   574,    18,   258,    12,   533,    13,
      -1,   574,    18,   359,    12,   554,    13,    -1,   574,    18,
     360,    -1,   574,    18,   316,    -1,   574,    18,   364,    -1,
     574,    18,   365,    -1,   574,    18,   315,    12,   533,    13,
      -1,   574,    18,   317,    12,   533,    13,    -1,   574,    18,
     313,    -1,   574,    18,   327,    12,   533,    13,    -1,   574,
      18,   326,    12,   533,    13,    -1,   574,    18,   326,    12,
     533,    19,   533,    13,    -1,   574,    18,   370,    12,   533,
      19,   533,    19,   533,    13,    -1,   574,    18,   371,    -1,
     574,    18,   373,    12,   533,    13,    -1,   574,    18,   372,
      -1,   486,    12,   512,    13,    -1,   487,    12,    56,    19,
     533,    19,   533,    19,   533,    19,   533,    19,   533,    19,
     533,    19,   533,    19,   533,    13,    -1,   574,    18,   479,
      12,   554,    13,    -1,    58,    18,   324,    12,   533,    19,
     533,    19,   533,    13,    -1,    58,    18,   328,    12,   575,
      13,    -1,    58,   103,   574,    -1,    58,   104,   574,    -1,
      58,    18,   343,    12,   574,    13,    -1,    58,    18,   344,
      -1,    58,    18,   326,    12,   533,    13,    -1,    58,    18,
     326,    12,   533,    19,   533,    13,    -1,    58,    18,   329,
      12,   533,    13,    -1,    58,    18,   384,    12,    58,    13,
      -1,    58,    18,   385,    12,    49,    19,   535,    13,    -1,
      58,    18,   399,    12,   533,    19,   554,    19,   533,    19,
     533,    19,   533,    19,   533,    13,    -1,    58,    18,   400,
      12,   533,    13,    -1,    58,    18,   379,    -1,    58,    18,
     375,    12,   555,    13,    -1,    58,    18,   375,    12,   555,
      19,   533,    13,    -1,    58,    18,   336,    -1,    58,    18,
     339,    12,   533,    19,   533,    19,   533,    19,   533,    13,
      -1,    58,    18,   340,    12,   533,    19,   533,    19,   533,
      19,   533,    13,    -1,    58,    18,   341,    12,   533,    19,
     533,    19,   533,    19,   533,    13,    -1,    58,    18,   342,
      12,   533,    19,   533,    19,   533,    13,    -1,    58,    18,
     394,    12,   533,    19,   533,    13,    -1,   245,    12,   535,
      19,   533,    19,   533,    13,    -1,   245,    12,   535,    19,
     533,    19,   533,    19,   554,    13,    -1,   246,    12,   535,
      19,   533,    19,   533,    13,    -1,   246,    12,   535,    19,
     533,    19,   533,    19,   554,    13,    -1,   246,    12,   535,
      19,   533,    19,   533,    19,   554,    19,   533,    13,    -1,
     247,    12,   535,    19,   533,    13,    -1,   247,    12,   535,
      19,   533,    19,   554,    13,    -1,   247,    12,   535,    19,
     533,    19,   533,    13,    -1,   247,    12,   535,    19,   533,
      19,   533,    19,   554,    13,    -1,   249,    12,   535,    19,
     533,    19,   533,    19,   533,    19,   533,    19,   533,    19,
     533,    13,    -1,   249,    12,   535,    19,   533,    19,   533,
      19,   533,    19,   533,    19,   533,    19,   533,    19,   554,
      13,    -1,   248,    12,   535,    19,   533,    19,   533,    19,
     554,    19,   533,    13,    -1,   250,    12,   535,    19,   533,
      13,    -1,   293,    12,    47,    19,   535,    19,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    19,   554,    13,
      -1,   293,    12,    47,    19,   535,    19,   535,    19,   535,
      19,   535,    19,   535,    19,   535,    13,    -1,   292,    12,
      47,    19,   535,    19,   535,    19,   535,    19,   554,    13,
      -1,   292,    12,    47,    19,   535,    19,   535,    19,   535,
      13,    -1,   252,    12,   535,    19,   533,    19,   533,    19,
     533,    13,    -1,   535,    18,   252,    12,   533,    19,   533,
      19,   533,    13,    -1,   535,    18,   252,    12,   535,    13,
      -1,   535,    18,   253,    12,   533,    19,   533,    19,   533,
      13,    -1,   535,    18,   253,    12,   535,    13,    -1,   535,
      18,   254,    12,   533,    13,    -1,   139,    12,   535,    19,
     535,    13,    -1,   139,    12,   535,    19,   535,    19,   535,
      13,    -1,   533,    -1,   306,    12,   533,    13,    -1,   417,
      12,   554,    19,   512,    19,   533,    13,    -1,   420,    12,
     535,    13,    -1,   291,    12,   535,    19,   535,    19,   533,
      19,   533,    19,   533,    19,   533,    19,   533,    19,   533,
      13,    -1,   458,    12,    47,    13,    -1,   151,    -1,   153,
      -1,   576,   123,    77,    12,   512,    13,    -1,    65,    18,
      96,    12,   512,    13,    -1,    65,    18,    80,    -1,    65,
      18,    81,    -1,    65,    18,    82,    12,   512,    13,    -1,
      65,    18,    78,    12,   512,    13,    -1,    65,    18,    79,
      -1,    65,    18,    97,    -1,    65,    18,    98,    -1,    65,
      18,    99,    -1,    65,    18,    85,    -1,    65,    18,    86,
      -1,    65,    18,   100,    -1,    65,    18,    93,    12,   533,
      19,   533,    13,    -1,    65,    18,    94,    12,    64,    13,
      -1,    65,    18,    95,    12,   533,    13,    -1,   489,    12,
     535,    19,   512,    13,    -1,    66,    18,    38,    -1,    66,
      18,   220,   512,    -1,   490,    -1,   491,    -1,   492,    -1,
     493,    -1,   494,    -1,   495,    12,   535,    19,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    19,   535,    19,
     533,    19,   533,    19,   533,    19,   533,    19,   533,    19,
     533,    19,   533,    13,    -1,   496,    12,   535,    19,   535,
      19,   533,    19,   533,    19,   533,    19,   533,    19,   533,
      19,   533,    19,   535,    19,   535,    19,   533,    13,    -1,
      62,    12,   507,    13,    -1,   481,    12,   533,    19,   533,
      19,   533,    13,    -1,    -1,   533,    -1,   507,    19,   533,
      -1,   512,    -1,   507,    19,   512,    -1,    16,    52,    -1,
     507,    19,    16,    52,    -1,    16,    53,    -1,   507,    19,
      16,    53,    -1,   554,    -1,   507,    19,   554,    -1,    16,
     535,    -1,   507,    19,    16,   535,    -1,    16,   574,    -1,
     507,    19,    16,   574,    -1,    56,    -1,   507,    19,    56,
      -1,    -1,   462,    50,    -1,   463,    50,    -1,   459,    50,
      -1,   460,    50,    -1,   461,    50,    -1,   508,    19,   462,
      50,    -1,   508,    19,   463,    50,    -1,   508,    19,   459,
      50,    -1,   508,    19,   460,    50,    -1,   508,    19,   461,
      50,    -1,    47,    -1,    55,    -1,   509,    -1,    40,    12,
     512,    19,   533,    13,    -1,   152,    -1,   535,    18,    44,
      -1,   510,    -1,   511,    10,   510,    -1,   511,    11,   510,
      -1,   511,    -1,   514,    48,   515,    -1,    -1,    -1,    49,
      -1,    28,    -1,   426,    -1,   427,    -1,    52,    -1,    53,
      -1,    54,    -1,    12,   533,    13,    -1,   516,    -1,   535,
      12,   533,    13,    -1,   535,    12,   533,    19,   533,    13,
      -1,   535,    12,   533,    19,   533,    19,   533,    13,    -1,
     535,    12,   533,    19,   533,    19,   533,    19,   533,    13,
      -1,   535,    12,   533,    19,   533,    19,   533,    22,   533,
      13,    -1,   535,    12,   533,    19,   533,    22,   533,    13,
      -1,   535,    12,   533,    22,   533,    13,    -1,   535,    18,
     199,    -1,   535,    18,   576,    -1,   535,    18,   217,    -1,
     574,    18,   217,    -1,   574,    18,   218,    -1,   574,    18,
     219,    -1,   204,    12,   535,    19,   535,    13,    -1,   237,
      12,   535,    13,    -1,   307,    12,   535,    19,   533,    19,
     533,    19,   533,    13,    -1,   308,    12,   535,    13,    -1,
     308,    12,   533,    19,   533,    19,   533,    19,   533,    13,
      -1,   124,    12,   554,    13,    -1,   239,    12,   554,    13,
      -1,   125,    12,   535,    13,    -1,   126,    12,   554,    13,
      -1,   127,    12,   535,    13,    -1,   128,    12,   535,    13,
      -1,   125,    14,   554,    15,    12,   535,    13,    -1,   127,
      14,   554,    15,    12,   535,    13,    -1,   128,    14,   554,
      15,    12,   535,    13,    -1,   128,    14,   554,    15,    12,
     535,    19,   533,    13,    -1,   239,    14,   554,    15,    12,
     554,    13,    -1,   239,    12,   535,    19,   554,    13,    -1,
     416,    12,    47,    13,    -1,    56,    18,   282,    -1,    56,
      18,   283,    -1,    56,    18,   280,    -1,    56,    18,   281,
      -1,    56,    18,   278,    -1,    56,    18,   279,    -1,    56,
      18,   284,    -1,    56,    18,   285,    -1,    56,    18,   286,
      -1,   144,    18,   207,    -1,   144,    18,   208,    -1,   154,
      18,   155,    -1,    59,    12,   533,    19,   533,    13,    -1,
      59,    12,   533,    19,   533,    13,   123,   533,    -1,    65,
      18,    83,    12,    52,    19,   533,    19,   533,    13,    -1,
      65,    18,    84,    12,    53,    19,   533,    19,   533,    13,
      -1,    65,    18,    87,    12,   512,    19,    64,    13,    -1,
      65,    18,    88,    12,    54,    13,    -1,    65,    18,    89,
      12,    53,    19,   533,    13,    -1,    65,    18,    89,    12,
      53,    13,    -1,    65,    18,    90,    12,   533,    19,   512,
      13,    -1,    65,    18,    91,    12,    55,    19,   512,    13,
      -1,    65,    18,    92,    12,    55,    19,   512,    19,   512,
      19,   512,    13,    -1,    65,    18,   383,    -1,    65,    18,
     383,    12,   533,    13,    -1,   456,    12,   576,    13,    -1,
     456,    12,   577,    13,    -1,   534,    -1,    60,    18,   423,
      12,   512,    13,    -1,    60,    18,   424,    12,    52,    13,
      -1,   517,    -1,   519,   520,    -1,     9,   520,    -1,    11,
     520,    -1,    10,   520,    -1,   428,   520,    -1,   429,   520,
      -1,   439,   520,    -1,   440,   520,    -1,   441,   520,    -1,
     442,   520,    -1,   430,   520,    -1,   431,   520,    -1,   432,
     520,    -1,   433,   520,    -1,   436,   520,    -1,   438,   520,
      -1,   437,   520,    -1,     7,    -1,   497,    -1,   518,    -1,
      12,   534,    13,   518,    -1,   520,    -1,   521,     7,   520,
      -1,   521,     8,   520,    -1,   521,    -1,   522,    10,   521,
      -1,   522,    11,   521,    -1,   522,    -1,   523,    -1,   524,
       6,   523,    -1,   524,     5,   523,    -1,   524,   117,   523,
      -1,   524,   118,   523,    -1,   524,    -1,   525,   119,   524,
      -1,   525,   120,   524,    -1,   512,   119,   512,    -1,   512,
     120,   512,    -1,   525,    -1,   526,    16,   525,    -1,   526,
      -1,   527,     4,   526,    -1,   527,    -1,   528,    17,   527,
      -1,   528,    -1,   529,   115,   528,    -1,   529,    -1,   530,
     116,   529,    -1,   530,    -1,   530,    20,   530,    21,   531,
      -1,   531,    -1,   532,    -1,   405,    -1,   406,    -1,   407,
      -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,   412,
      -1,   413,    -1,   414,    -1,   535,    18,   415,    -1,    51,
      -1,    68,    14,   533,    15,    -1,    31,    47,    -1,    31,
      12,   512,    13,    -1,    32,    12,   533,    19,   533,    19,
     534,    19,   533,    19,   512,    19,   533,    19,   533,    13,
      -1,    32,    12,   533,    19,   533,    19,   533,    19,   534,
      19,   533,    19,   512,    13,    -1,    32,    12,   533,    19,
     533,    19,   533,    19,   534,    19,   533,    19,   533,    19,
     512,    13,    -1,   287,    12,   512,    13,    -1,   288,    12,
     512,    13,    -1,    63,    12,   507,    13,    -1,    31,    -1,
      31,    12,   534,    19,   533,    19,   533,    19,   533,    13,
      -1,    31,    12,   534,    19,   533,    19,   533,    19,   533,
      19,   533,    13,    -1,    31,    12,   534,    19,   533,    19,
     535,    13,    -1,   535,    -1,   535,    14,   533,    15,    -1,
     240,    12,   554,    19,   533,    13,    -1,   241,    12,   554,
      19,   533,    13,    -1,   242,    12,   554,    19,   533,    13,
      -1,   243,    12,   554,    19,   554,    19,   533,    13,    -1,
     244,    12,   554,    19,   554,    19,   533,    13,    -1,   125,
      12,   554,    19,   554,    13,    -1,   129,    12,   535,    19,
      47,    13,    -1,   129,    12,   535,    19,    47,    19,   534,
      13,    -1,   129,    12,   535,    19,   535,    19,    47,    13,
      -1,   129,    12,   535,    19,   535,    19,    47,    19,   534,
      13,    -1,   129,    12,   535,    19,   535,    19,   535,    19,
      47,    13,    -1,   129,    12,   535,    19,   535,    19,   535,
      19,    47,    19,   534,    13,    -1,   130,    12,   554,    19,
     533,    19,   533,    19,   533,    19,   533,    13,    -1,   472,
      18,   473,    12,   535,    19,   533,    19,   533,    13,    -1,
     319,    12,   535,    13,    -1,   149,    12,   535,    19,   533,
      19,   533,    19,   533,    13,    -1,   320,    12,   535,    13,
      -1,   224,    12,   554,    19,   533,    13,    -1,   225,    12,
     535,    13,    -1,   226,    12,   535,    13,    -1,   227,    12,
     535,    13,    -1,   228,    12,   535,    19,   535,    19,   533,
      19,   533,    19,   533,    13,    -1,   229,    12,   535,    13,
      -1,   230,    12,   535,    19,   535,    19,   535,    19,   533,
      19,   535,    13,    -1,   231,    12,   535,    19,   535,    19,
     535,    19,   533,    19,   535,    13,    -1,   232,    12,   535,
      19,   535,    19,   535,    19,   533,    19,   535,    19,   533,
      19,   533,    13,    -1,   233,    12,   535,    19,   535,    19,
     535,    19,   533,    19,   535,    19,   533,    19,   533,    19,
     533,    19,   533,    13,    -1,   234,    12,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,   234,    12,   535,    19,
     535,    19,   535,    19,   535,    19,   533,    13,    -1,   235,
      12,   535,    13,    -1,   235,    12,   535,    19,   535,    13,
      -1,   236,    12,   535,    19,   535,    13,    -1,   131,    12,
     554,    19,   533,    13,    -1,   132,    12,   535,    13,    -1,
     148,    12,   535,    13,    -1,   133,    12,   535,    19,   533,
      13,    -1,   251,    12,   535,    13,    -1,   134,    12,   535,
      19,   533,    13,    -1,   135,    12,   535,    19,   533,    13,
      -1,   138,    12,   554,    19,   533,    13,    -1,   535,    14,
     578,    15,    -1,   535,    14,    21,    19,    21,    19,   533,
      21,   533,    15,    -1,   136,    12,   535,    19,   533,    19,
     533,    19,   533,    19,   533,    19,   533,    19,   533,    13,
      -1,   140,    12,   535,    19,   533,    19,   533,    19,   533,
      13,    -1,   140,    12,   535,    19,   533,    19,   533,    13,
      -1,   140,    12,   535,    19,   533,    19,   533,    19,   533,
      19,   533,    13,    -1,   141,    12,   535,    19,   533,    19,
     533,    19,   533,    13,    -1,   141,    12,   535,    19,   533,
      19,   533,    13,    -1,   141,    12,   535,    19,   533,    19,
     533,    19,   533,    19,   533,    13,    -1,   142,    12,   535,
      19,   533,    19,   533,    13,    -1,   142,    12,   535,    19,
     533,    19,   533,    19,   533,    19,   533,    13,    -1,   143,
      12,   535,    19,   533,    19,   533,    13,    -1,   143,    12,
     535,    19,   533,    19,   533,    19,   533,    19,   533,    13,
      -1,   144,    18,    45,    -1,   144,    18,    46,    -1,   154,
      18,   199,    12,   535,    19,   533,    13,    -1,   154,    18,
     199,    12,   535,    19,   535,    13,    -1,   154,    18,    45,
      -1,   154,    18,   164,    12,   535,    13,    -1,   144,    12,
     535,    19,   533,    19,   533,    19,   533,    19,   533,    13,
      -1,   188,    12,   535,    19,   535,    19,   533,    19,   533,
      19,   533,    13,    -1,   146,    12,   535,    19,   533,    19,
     533,    19,   533,    19,   533,    19,   533,    13,    -1,   145,
      12,   535,    19,   533,    19,   533,    19,   533,    19,   533,
      13,    -1,   189,    18,   199,    12,   535,    19,   533,    19,
     533,    19,   533,    13,    -1,   190,    18,   199,    12,   535,
      19,   533,    19,   533,    19,   533,    19,   533,    19,   533,
      13,    -1,   191,    12,   535,    13,    -1,   192,    12,   535,
      19,   533,    19,   533,    13,    -1,   192,    12,   535,    19,
     533,    19,   533,    19,   578,    13,    -1,   192,    12,   535,
      19,   533,    19,   533,    19,   533,    19,   578,    13,    -1,
     193,    12,   535,    19,   533,    19,   533,    19,   578,    13,
      -1,   193,    12,   535,    19,   533,    19,   533,    19,   533,
      19,   578,    13,    -1,   194,    12,   535,    19,   533,    19,
     533,    19,   578,    13,    -1,   195,    12,   535,    19,   533,
      19,   533,    19,   533,    19,   578,    13,    -1,   196,    12,
     535,    19,   533,    19,   533,    19,   533,    19,   578,    13,
      -1,   197,    12,   535,    19,   533,    19,   533,    19,   533,
      19,   533,    19,   578,    13,    -1,   198,    12,   535,    19,
     533,    19,   533,    19,   533,    19,   533,    13,    -1,   203,
      12,   535,    19,   533,    19,   533,    13,    -1,   238,    12,
     535,    19,   533,    19,   533,    19,   533,    19,   533,    19,
     533,    13,    -1,   401,    12,   535,    13,    -1,   402,    12,
     535,    13,    -1,   403,    12,   535,    13,    -1,   404,    12,
     535,    13,    -1,    58,    18,   322,    -1,    58,    18,   323,
      -1,    56,    18,   322,    -1,   260,    12,   535,    19,   533,
      13,    -1,   261,    12,   535,    19,   533,    13,    -1,   262,
      12,   535,    19,   533,    13,    -1,   263,    12,   535,    19,
     533,    13,    -1,   186,    12,   554,    19,   554,    19,   533,
      13,    -1,   187,    12,   554,    19,   554,    19,   533,    19,
     533,    19,   533,    19,   533,    13,    -1,   186,    12,   554,
      19,   554,    19,   533,    19,   533,    19,   533,    13,    -1,
     186,    12,   554,    19,   554,    19,   533,    19,   533,    19,
     533,    19,   533,    13,    -1,   186,    12,   554,    19,   554,
      19,   535,    19,   533,    19,   533,    13,    -1,   289,    12,
     535,    19,   535,    13,    -1,   290,    12,   535,    19,   535,
      19,   554,    13,    -1,   294,    12,   535,    19,   533,    19,
     533,    19,   533,    13,    -1,   295,    12,   535,    19,   533,
      19,   533,    19,   533,    13,    -1,   295,    12,   535,    19,
     533,    19,   533,    19,   533,    19,   533,    13,    -1,   296,
      12,   535,    19,   533,    13,    -1,   297,    12,   535,    19,
     533,    13,    -1,   298,    12,   535,    19,   533,    13,    -1,
     299,    12,   535,    19,   533,    13,    -1,   300,    12,   535,
      19,   533,    13,    -1,   301,    12,   535,    19,   533,    13,
      -1,   302,    12,   535,    19,   533,    13,    -1,   303,    12,
     535,    19,   533,    13,    -1,   303,    12,   535,    19,   533,
      19,   533,    13,    -1,   304,    12,   535,    19,   533,    19,
     533,    19,   533,    13,    -1,   305,    12,   554,    13,    -1,
     535,    12,   554,    13,    -1,   418,    12,   554,    19,   533,
      19,   533,    19,   533,    13,    -1,   419,    12,   554,    19,
     533,    19,   533,    19,   533,    13,    -1,   466,    12,   554,
      13,    -1,   466,    12,   554,    19,   533,    13,    -1,   469,
      12,   554,    19,   533,    13,    -1,   467,    12,   554,    19,
     533,    19,   533,    19,   533,    19,   533,    13,    -1,   468,
      12,   535,    19,   535,    19,   533,    19,   533,    19,   533,
      19,   533,    19,   533,    19,   533,    19,   533,    19,   533,
      19,   533,    19,   533,    19,   533,    19,   533,    13,    -1,
     471,    12,   554,    19,   533,    19,   533,    13,    -1,   574,
      18,   356,    12,    13,    -1,   574,    18,   357,    12,    13,
      -1,   574,    18,   358,    12,    13,    -1,   574,    18,   355,
      12,   535,    13,    -1,   477,    12,   554,    19,   533,    13,
      -1,   477,    12,   554,    13,    -1,   478,    12,   554,    19,
     533,    13,    -1,   478,    12,   554,    13,    -1,   483,    12,
     554,    19,   554,    13,    -1,   484,    12,   554,    13,    -1,
     485,    12,   512,    13,    -1,   457,    12,   554,    19,   533,
      19,   533,    19,   533,    19,   533,    19,   533,    19,   533,
      19,   533,    13,    -1,   268,    12,   574,    19,   535,    19,
     554,    13,    -1,   270,    12,   574,    19,   512,    13,    -1,
     536,    -1,    12,   554,    13,    -1,   537,    -1,   538,    -1,
     519,   540,    -1,    11,   540,    -1,    10,   540,    -1,   428,
     540,    -1,   429,   540,    -1,   439,   540,    -1,   440,   540,
      -1,   441,   540,    -1,   442,   540,    -1,   430,   540,    -1,
     431,   540,    -1,   432,   540,    -1,   433,   540,    -1,   436,
     540,    -1,   438,   540,    -1,   437,   540,    -1,   443,   540,
      -1,   539,    -1,    12,   534,    13,   539,    -1,   540,    -1,
     541,     7,   520,    -1,   541,     8,   520,    -1,   541,     7,
     540,    -1,   541,     8,   540,    -1,   541,     4,   540,    -1,
     541,    -1,   542,    -1,   543,    10,   521,    -1,   543,    11,
     521,    -1,   543,    10,   541,    -1,   543,    11,   541,    -1,
     543,    -1,   544,    -1,   545,     6,   544,    -1,   545,     5,
     544,    -1,   545,   117,   544,    -1,   545,   118,   544,    -1,
     545,     6,   523,    -1,   545,     5,   523,    -1,   545,   117,
     523,    -1,   545,   118,   523,    -1,   545,    -1,   546,   119,
     545,    -1,   546,   120,   545,    -1,   546,   119,   523,    -1,
     546,   120,   523,    -1,   546,    -1,   547,    16,   546,    -1,
     547,    -1,   548,    -1,   549,    17,   548,    -1,   549,    -1,
     550,   115,   549,    -1,   550,    -1,   551,   116,   550,    -1,
     551,    -1,   551,    20,   551,    21,   552,    -1,   552,    -1,
     539,   123,   553,    -1,   553,    -1,    66,    -1,    58,    18,
     374,    -1,   376,    12,    66,    19,    66,    19,   533,    13,
      -1,    33,    12,   512,    13,    -1,   377,    12,   533,    19,
     533,    13,    -1,    59,    -1,   378,    12,   573,    13,    -1,
     556,    -1,    12,   573,    13,    -1,   557,    -1,   558,    -1,
     519,   560,    -1,    11,   560,    -1,    10,   560,    -1,   560,
     121,    -1,   428,   560,    -1,   429,   560,    -1,   439,   560,
      -1,   440,   560,    -1,   441,   560,    -1,   442,   560,    -1,
     430,   560,    -1,   431,   560,    -1,   432,   560,    -1,   433,
     560,    -1,   436,   560,    -1,   438,   560,    -1,   437,   560,
      -1,   559,    -1,   560,    -1,   561,     7,   520,    -1,   561,
     122,   560,    -1,   561,     7,   560,    -1,   561,    -1,   562,
      10,   521,    -1,   562,    11,   521,    -1,   562,    10,   561,
      -1,   562,    11,   561,    -1,   562,    -1,   563,    -1,   564,
      -1,   565,    -1,   566,    -1,   567,    -1,   568,    -1,   569,
      -1,   570,    -1,   571,    -1,   572,    -1,    57,    -1,    67,
      14,   533,    15,    -1,   309,    12,   554,    19,   533,    13,
      -1,   312,    12,   535,    19,   533,    13,    -1,   309,    12,
     554,    19,   533,    19,   535,    13,    -1,   318,    12,   554,
      19,   533,    19,   554,    13,    -1,   313,    12,   574,    13,
      -1,   313,    12,   574,    19,   533,    13,    -1,   314,    12,
     535,    19,   533,    13,    -1,   315,    12,   574,    19,   533,
      13,    -1,   317,    12,   574,    19,   533,    13,    -1,   321,
      12,    13,    -1,   321,    47,    -1,   321,    12,   512,    13,
      -1,   321,    -1,   269,    12,   512,    13,    -1,   269,    12,
     512,    19,   533,    13,    -1,   574,    -1,   255,    12,   535,
      13,    -1,   256,    12,   574,    13,    -1,   256,    12,   574,
      19,   533,    19,   533,    19,   533,    13,    -1,   257,    12,
     574,    19,   533,    13,    -1,   264,    12,   574,    19,   533,
      19,   533,    19,   533,    19,   533,    19,   533,    19,   533,
      13,    -1,   265,    12,   554,    19,   533,    19,   533,    19,
     533,    19,   533,    19,   533,    19,   533,    19,   533,    13,
      -1,   266,    12,   554,    19,   533,    19,   533,    19,   533,
      13,    -1,   267,    12,   554,    19,   533,    19,   533,    19,
     533,    19,   533,    19,   533,    19,   533,    19,   533,    19,
     533,    13,    -1,   574,    18,   259,    12,   533,    19,   533,
      13,    -1,   474,    12,   554,    13,    -1,   474,    12,   554,
      19,   533,    13,    -1,   474,    12,   554,    19,   533,    19,
     533,    13,    -1,   476,    12,   554,    19,   533,    19,   533,
      13,    -1,   475,    12,   554,    19,   533,    19,   533,    19,
     554,    19,   554,    13,    -1,   475,    12,   554,    19,   533,
      19,   533,    19,   554,    19,   554,    19,   554,    19,   533,
      13,    -1,   480,    12,   554,    19,   554,    19,   554,    19,
     533,    19,   533,    19,   533,    19,   533,    13,    -1,   480,
      12,   554,    19,   554,    19,   554,    19,   533,    19,   533,
      19,   533,    19,   533,    19,   533,    13,    -1,   480,    12,
     554,    19,   554,    19,   554,    19,   533,    19,   533,    19,
     533,    13,    -1,   480,    12,   554,    19,   533,    19,   533,
      19,   533,    19,   533,    19,   533,    13,    -1,   482,    12,
     554,    19,   554,    19,   554,    19,   533,    19,   533,    19,
     533,    19,   533,    13,    -1,   482,    12,   554,    19,   554,
      19,   554,    19,   533,    19,   533,    19,   533,    19,   533,
      19,   554,    19,   554,    13,    -1,    50,    -1,    53,    -1,
      52,    -1,   535,    -1,    56,    -1,    57,    -1,    58,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      55,    -1,    59,    -1,    66,    -1,    65,    -1,    67,    -1,
      68,    -1,   533,    21,   533,    19,   533,    21,   533,    19,
     533,    21,   533,    -1,   533,    21,   533,    19,   533,    21,
     533,    -1,   535,    -1,    56,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     9,    12,    15,    19,    21,
      24,    26,    29,    31,    34,    36,    39,    41,    43,    52,
      63,    66,    71,    78,    86,    90,    92,    98,   101,   103,
     105,   107,   109,   111,   113,   118,   125,   132,   139,   146,
     150,   154,   161,   168,   172,   176,   180,   184,   191,   195,
     199,   206,   213,   220,   224,   228,   237,   246,   250,   252,
     254,   256,   258,   263,   265,   268,   271,   274,   276,   280,
     284,   288,   295,   302,   319,   322,   325,   329,   332,   335,
     339,   343,   346,   349,   353,   356,   359,   365,   368,   370,
     372,   375,   378,   383,   386,   389,   392,   394,   399,   403,
     406,   409,   420,   427,   431,   438,   445,   454,   483,   492,
     501,   505,   514,   527,   534,   541,   558,   567,   584,   595,
     602,   613,   622,   633,   648,   657,   670,   677,   686,   693,
     700,   707,   718,   725,   736,   747,   760,   767,   774,   787,
     794,   801,   808,   815,   822,   829,   836,   843,   850,   857,
     864,   871,   880,   884,   888,   892,   896,   900,   904,   917,
     934,   941,   948,   955,   962,   969,   976,   983,   990,   997,
    1004,  1015,  1022,  1037,  1044,  1053,  1060,  1067,  1076,  1083,
    1094,  1101,  1108,  1115,  1122,  1129,  1136,  1143,  1150,  1157,
    1164,  1171,  1175,  1179,  1184,  1188,  1195,  1202,  1207,  1212,
    1219,  1230,  1241,  1252,  1259,  1266,  1273,  1280,  1287,  1298,
    1305,  1316,  1323,  1330,  1337,  1341,  1348,  1355,  1366,  1377,
    1384,  1391,  1398,  1402,  1406,  1410,  1414,  1421,  1428,  1432,
    1439,  1446,  1455,  1466,  1470,  1477,  1481,  1486,  1507,  1514,
    1525,  1532,  1536,  1540,  1547,  1551,  1558,  1567,  1574,  1581,
    1590,  1607,  1614,  1618,  1625,  1634,  1638,  1651,  1664,  1677,
    1688,  1697,  1706,  1717,  1726,  1737,  1750,  1757,  1766,  1775,
    1786,  1803,  1822,  1835,  1842,  1861,  1878,  1891,  1902,  1913,
    1924,  1931,  1942,  1949,  1956,  1963,  1972,  1974,  1979,  1988,
    1993,  2012,  2017,  2019,  2021,  2028,  2035,  2039,  2043,  2050,
    2057,  2061,  2065,  2069,  2073,  2077,  2081,  2085,  2094,  2101,
    2108,  2115,  2119,  2124,  2126,  2128,  2130,  2132,  2134,  2165,
    2190,  2195,  2204,  2205,  2207,  2211,  2213,  2217,  2220,  2225,
    2228,  2233,  2235,  2239,  2242,  2247,  2250,  2255,  2257,  2261,
    2262,  2265,  2268,  2271,  2274,  2277,  2282,  2287,  2292,  2297,
    2302,  2304,  2306,  2308,  2315,  2317,  2321,  2323,  2327,  2331,
    2333,  2337,  2338,  2339,  2341,  2343,  2345,  2347,  2349,  2351,
    2353,  2357,  2359,  2364,  2371,  2380,  2391,  2402,  2411,  2418,
    2422,  2426,  2430,  2434,  2438,  2442,  2449,  2454,  2465,  2470,
    2481,  2486,  2491,  2496,  2501,  2506,  2511,  2519,  2527,  2535,
    2545,  2553,  2560,  2565,  2569,  2573,  2577,  2581,  2585,  2589,
    2593,  2597,  2601,  2605,  2609,  2613,  2620,  2629,  2640,  2651,
    2660,  2667,  2676,  2683,  2692,  2701,  2714,  2718,  2725,  2730,
    2735,  2737,  2744,  2751,  2753,  2756,  2759,  2762,  2765,  2768,
    2771,  2774,  2777,  2780,  2783,  2786,  2789,  2792,  2795,  2798,
    2801,  2804,  2806,  2808,  2810,  2815,  2817,  2821,  2825,  2827,
    2831,  2835,  2837,  2839,  2843,  2847,  2851,  2855,  2857,  2861,
    2865,  2869,  2873,  2875,  2879,  2881,  2885,  2887,  2891,  2893,
    2897,  2899,  2903,  2905,  2911,  2913,  2915,  2917,  2919,  2921,
    2923,  2925,  2927,  2929,  2931,  2933,  2935,  2939,  2941,  2946,
    2949,  2954,  2971,  2986,  3003,  3008,  3013,  3018,  3020,  3031,
    3044,  3053,  3055,  3060,  3067,  3074,  3081,  3090,  3099,  3106,
    3113,  3122,  3131,  3142,  3153,  3166,  3179,  3190,  3195,  3206,
    3211,  3218,  3223,  3228,  3233,  3246,  3251,  3264,  3277,  3294,
    3315,  3326,  3339,  3344,  3351,  3358,  3365,  3370,  3375,  3382,
    3387,  3394,  3401,  3408,  3413,  3424,  3441,  3452,  3461,  3474,
    3485,  3494,  3507,  3516,  3529,  3538,  3551,  3555,  3559,  3568,
    3577,  3581,  3588,  3601,  3614,  3629,  3642,  3655,  3672,  3677,
    3686,  3697,  3710,  3721,  3734,  3745,  3758,  3771,  3786,  3799,
    3808,  3823,  3828,  3833,  3838,  3843,  3847,  3851,  3855,  3862,
    3869,  3876,  3883,  3892,  3907,  3920,  3935,  3948,  3955,  3964,
    3975,  3986,  3999,  4006,  4013,  4020,  4027,  4034,  4041,  4048,
    4055,  4064,  4075,  4080,  4085,  4096,  4107,  4112,  4119,  4126,
    4139,  4170,  4179,  4185,  4191,  4197,  4204,  4211,  4216,  4223,
    4228,  4235,  4240,  4245,  4264,  4273,  4280,  4282,  4286,  4288,
    4290,  4293,  4296,  4299,  4302,  4305,  4308,  4311,  4314,  4317,
    4320,  4323,  4326,  4329,  4332,  4335,  4338,  4341,  4343,  4348,
    4350,  4354,  4358,  4362,  4366,  4370,  4372,  4374,  4378,  4382,
    4386,  4390,  4392,  4394,  4398,  4402,  4406,  4410,  4414,  4418,
    4422,  4426,  4428,  4432,  4436,  4440,  4444,  4446,  4450,  4452,
    4454,  4458,  4460,  4464,  4466,  4470,  4472,  4478,  4480,  4484,
    4486,  4488,  4492,  4501,  4506,  4513,  4515,  4520,  4522,  4526,
    4528,  4530,  4533,  4536,  4539,  4542,  4545,  4548,  4551,  4554,
    4557,  4560,  4563,  4566,  4569,  4572,  4575,  4578,  4581,  4583,
    4585,  4589,  4593,  4597,  4599,  4603,  4607,  4611,  4615,  4617,
    4619,  4621,  4623,  4625,  4627,  4629,  4631,  4633,  4635,  4637,
    4639,  4644,  4651,  4658,  4667,  4676,  4681,  4688,  4695,  4702,
    4709,  4713,  4716,  4721,  4723,  4728,  4735,  4737,  4742,  4747,
    4758,  4765,  4782,  4801,  4812,  4833,  4842,  4847,  4854,  4863,
    4872,  4885,  4902,  4919,  4938,  4953,  4968,  4985,  5006,  5008,
    5010,  5012,  5014,  5016,  5018,  5020,  5022,  5024,  5026,  5028,
    5030,  5032,  5034,  5036,  5038,  5040,  5042,  5054,  5062,  5064
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   906,   906,   907,   911,   911,   912,   913,   914,   914,
     915,   915,   916,   916,   917,   917,   920,   921,   926,   944,
     966,   988,  1003,  1023,  1046,  1063,  1097,  1140,  1155,  1163,
    1167,  1181,  1195,  1209,  1219,  1238,  1263,  1273,  1283,  1293,
    1303,  1312,  1327,  1349,  1359,  1368,  1373,  1383,  1406,  1416,
    1434,  1456,  1463,  1470,  1477,  1485,  1516,  1532,  1537,  1541,
    1545,  1550,  1554,  1558,  1561,  1600,  1620,  1649,  1666,  1679,
    1699,  1712,  1747,  1777,  1795,  1799,  1803,  1807,  1811,  1815,
    1819,  1823,  1827,  1831,  1836,  1840,  1849,  1858,  1863,  1871,
    1883,  2131,  2185,  2193,  2202,  2212,  2218,  2224,  2231,  2237,
    2247,  2257,  2273,  2285,  2295,  2344,  2359,  2380,  2411,  2426,
    2433,  2440,  2458,  2481,  2486,  2491,  2504,  2515,  2524,  2533,
    2541,  2558,  2574,  2591,  2611,  2626,  2644,  2657,  2671,  2680,
    2694,  2705,  2718,  2736,  2758,  2783,  2813,  2845,  2850,  2868,
    2873,  2878,  2883,  2888,  2893,  2907,  2922,  2939,  2953,  2973,
    2978,  2983,  2990,  2999,  3007,  3012,  3019,  3024,  3029,  3049,
    3073,  3078,  3083,  3088,  3093,  3098,  3103,  3108,  3113,  3118,
    3123,  3128,  3133,  3138,  3143,  3148,  3153,  3158,  3163,  3168,
    3176,  3181,  3186,  3191,  3196,  3201,  3206,  3211,  3216,  3221,
    3226,  3231,  3236,  3240,  3267,  3280,  3285,  3289,  3295,  3308,
    3314,  3320,  3326,  3333,  3340,  3347,  3358,  3369,  3384,  3399,
    3407,  3416,  3425,  3433,  3437,  3441,  3478,  3487,  3494,  3501,
    3512,  3520,  3538,  3548,  3553,  3560,  3567,  3575,  3583,  3602,
    3618,  3635,  3652,  3657,  3662,  3667,  3672,  3680,  3781,  3815,
    3822,  3830,  3836,  3843,  3853,  3862,  3869,  3876,  3886,  3893,
    3907,  3921,  3929,  3934,  3942,  3950,  3961,  3973,  3985,  3997,
    4003,  4016,  4023,  4034,  4056,  4082,  4110,  4120,  4133,  4143,
    4156,  4185,  4202,  4217,  4224,  4246,  4265,  4283,  4297,  4302,
    4307,  4316,  4321,  4330,  4344,  4351,  4358,  4360,  4375,  4409,
    4422,  4466,  4471,  4476,  4482,  4496,  4503,  4509,  4515,  4522,
    4529,  4535,  4541,  4547,  4553,  4559,  4571,  4577,  4594,  4601,
    4612,  4619,  4624,  4630,  4635,  4640,  4645,  4650,  4655,  4690,
    4717,  4724,  4746,  4750,  4757,  4764,  4772,  4780,  4789,  4796,
    4803,  4810,  4817,  4824,  4831,  4838,  4845,  4852,  4859,  4869,
    4874,  4880,  4886,  4892,  4898,  4904,  4910,  4916,  4922,  4928,
    4935,  4940,  4952,  4957,  4971,  4984,  4991,  4992,  5002,  5010,
    5013,  5024,  5025,  5028,  5029,  5037,  5045,  5054,  5058,  5063,
    5067,  5075,  5076,  5091,  5107,  5111,  5128,  5144,  5158,  5171,
    5192,  5251,  5271,  5289,  5296,  5304,  5309,  5314,  5342,  5348,
    5359,  5379,  5399,  5417,  5437,  5455,  5473,  5496,  5519,  5542,
    5549,  5574,  5597,  5604,  5614,  5624,  5634,  5644,  5654,  5664,
    5678,  5695,  5711,  5716,  5721,  5725,  5732,  5740,  5775,  5788,
    5798,  5815,  5834,  5850,  5868,  5888,  5909,  5922,  5935,  5943,
    5951,  5955,  5963,  5973,  5974,  5975,  5976,  5977,  5978,  5979,
    5980,  5981,  5982,  5983,  5991,  5992,  5993,  5994,  5995,  5996,
    5997,  6002,  6003,  6007,  6009,  6025,  6026,  6027,  6031,  6032,
    6033,  6037,  6042,  6043,  6044,  6045,  6046,  6050,  6051,  6052,
    6053,  6054,  6058,  6059,  6067,  6068,  6072,  6076,  6083,  6087,
    6094,  6098,  6105,  6106,  6113,  6117,  6123,  6128,  6132,  6136,
    6140,  6144,  6148,  6152,  6156,  6160,  6164,  6172,  6177,  6194,
    6200,  6206,  6264,  6318,  6374,  6395,  6416,  6430,  6459,  6467,
    6486,  6512,  6525,  6603,  6670,  6678,  6686,  6696,  6706,  6736,
    6754,  6774,  6792,  6812,  6830,  6849,  6889,  6904,  6918,  6934,
    6957,  6971,  6985,  6999,  7013,  7048,  7062,  7083,  7104,  7145,
    7191,  7208,  7227,  7241,  7255,  7269,  7288,  7303,  7318,  7335,
    7356,  7373,  7389,  7401,  7429,  7449,  7494,  7506,  7517,  7530,
    7542,  7553,  7579,  7606,  7638,  7655,  7673,  7686,  7699,  7719,
    7742,  7756,  7771,  7805,  7842,  7877,  7910,  7927,  7944,  7958,
    7979,  8002,  8026,  8051,  8076,  8098,  8120,  8144,  8187,  8211,
    8243,  8257,  8294,  8331,  8368,  8403,  8408,  8417,  8422,  8433,
    8443,  8453,  8462,  8483,  8513,  8541,  8572,  8607,  8618,  8634,
    8644,  8654,  8669,  8683,  8697,  8710,  8723,  8735,  8747,  8759,
    8770,  8783,  8810,  8843,  8951,  8975,  9017,  9030,  9041,  9050,
    9074,  9099,  9112,  9122,  9132,  9142,  9152,  9162,  9170,  9178,
    9186,  9213,  9234,  9242,  9280,  9303,  9323,  9323,  9325,  9327,
    9328,  9329,  9330,  9331,  9332,  9333,  9334,  9335,  9336,  9337,
    9338,  9339,  9340,  9341,  9342,  9343,  9344,  9360,  9361,  9385,
    9386,  9392,  9394,  9395,  9396,  9399,  9404,  9405,  9406,  9407,
    9408,  9411,  9415,  9416,  9417,  9418,  9419,  9420,  9421,  9422,
    9423,  9427,  9428,  9429,  9430,  9431,  9435,  9436,  9441,  9445,
    9446,  9450,  9451,  9455,  9456,  9460,  9461,  9465,  9466,  9469,
    9473,  9483,  9496,  9507,  9524,  9531,  9541,  9556,  9556,  9558,
    9560,  9561,  9562,  9563,  9564,  9573,  9574,  9575,  9576,  9577,
    9578,  9579,  9580,  9581,  9582,  9583,  9584,  9585,  9589,  9591,
    9592,  9593,  9594,  9604,  9605,  9606,  9607,  9608,  9611,  9615,
    9619,  9623,  9628,  9632,  9636,  9640,  9644,  9648,  9651,  9656,
    9661,  9678,  9690,  9702,  9714,  9747,  9756,  9765,  9774,  9783,
    9792,  9798,  9804,  9810,  9836,  9850,  9866,  9876,  9894,  9922,
    9949,  9964,  9981, 10015, 10047, 10093, 10119, 10129, 10152, 10164,
   10177, 10217, 10262, 10312, 10365, 10411, 10440, 10473, 10514, 10518,
   10519, 10520, 10524, 10525, 10526, 10527, 10528, 10529, 10530, 10531,
   10532, 10533, 10534, 10535, 10536, 10537, 10542, 10550, 10557, 10573
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
       2,     2,     2,     2,     2,     2,   497,     2,     2,     2,
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
     495,   496
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 15661;
  const int Parser::yynnts_ = 81;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 359;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 498;

  const unsigned int Parser::yyuser_token_number_max_ = 751;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

} // namespace yyip

#line 10593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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

void CB_delete_imagedraw( void* varname)
{
  if (GB_debug) fprintf(stderr,"CB_delete_imagedraw() \n");
  std::string* name = (std::string*) varname;
  if (Vars.deleteVar( name->c_str())==0)
    fprintf(stderr,"CB_delete_imagedraw() could not delete variable '%s' !!! \n",name->c_str());

// deleting is risky, use smart pointers instead ...
//  delete name;
}

void CB_delete_surfdraw( void* varid)
{
  fprintf(stderr," CB_delete_surfdraw begin \n");
  Variable* v = (Variable*) varid;
  fprintf(stderr," Delete var %s \n", v->Name());
  Vars.deleteVar( v->Name());
  fprintf(stderr," CB_delete_surfdraw end \n");
}







