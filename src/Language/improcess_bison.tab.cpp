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
#line 902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


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
#line 896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 511: /* "primary_expr_string" */
#line 896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 512: /* "postfix_expr_string" */
#line 896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 227 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 513: /* "additive_expr_string" */
#line 896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 514: /* "expr_string" */
#line 896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };
#line 237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 515: /* "instr_block" */
#line 897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };
#line 242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 580: /* "image_extent" */
#line 898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    #line 370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    ;}
    break;

  case 24:
#line 1040 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AMIFunction* amifunc;
      AmiInstructionBlock_ptr body((yysemantic_stack_[(8) - (7)].ablock));

      amifunc = new AMIFunction;

      amifunc->SetName((yysemantic_stack_[(8) - (2)].ident));
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", (yysemantic_stack_[(8) - (2)].ident),body->GetBody().c_str());

      Vars.AddVar( type_ami_function, (yysemantic_stack_[(8) - (2)].ident), (void*) amifunc);

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    ;}
    break;

  case 25:
#line 1061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 26:
#line 1078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 27:
#line 1112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 28:
#line 1155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 29:
#line 1169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         ;}
    break;

  case 30:
#line 1177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         ;}
    break;

  case 31:
#line 1182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 32:
#line 1196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 33:
#line 1210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 34:
#line 1224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
         ;}
    break;

  case 35:
#line 1234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description: waits the time given in milliseconds
        */
/*
        int ms = (int) $3;
        wxWaitTimer w;
        w.Start(ms,wxTIMER_ONE_SHOT);
        while (!w.finished) {
          if (GB_wxApp->Pending()) {
            GB_wxApp->Dispatch();
          }
        } // end while
*/
      ;}
    break;

  case 36:
#line 1251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) time in ms
            (5) function to schedule
        **/
/*
        // TODO To avoid pbs, make sure that the variable does not disappears
        // by making a copy of it
        int ms = (int) $3;
        Variable*    var   = $5;
  
        wxScheduleTimer::ptr w = wxScheduleTimer::ptr(new wxScheduleTimer(  *(AMIFunction_ptr*) (var->Pointer()) ));
        // add to the list of schedule timers
        schedule_timers.push_back(w);
        w->Start(ms,wxTIMER_ONE_SHOT);
*/
      ;}
    break;

  case 37:
#line 1271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            VarArray* arraysurf;
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            arraysurf = new VarArray();
            arraysurf->Init(type_surface,size);
            Vars.AddVar(type_array,(yysemantic_stack_[(6) - (1)].ident),arraysurf);
          ;}
    break;

  case 39:
#line 1291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            VarArray* array;
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            array = new VarArray();
            array->Init(type_image,size);
            Vars.AddVar(type_array,(yysemantic_stack_[(6) - (1)].ident),array);
          ;}
    break;

  case 40:
#line 1301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)driver.im_stack.GetLastImage();
          if (imptr != NULL)
            Vars.AddVar(type_image,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
            driver.err_print("assignment of NULL image\n");
        ;}
    break;

  case 42:
#line 1320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 43:
#line 1335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 44:
#line 1357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*) driver.matrix_stack.GetLastMatrix();
          if (imptr != NULL)
        Vars.AddVar(type_matrix,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
        driver.err_print("assignment of NULL matrix\n");
        ;}
    break;

  case 45:
#line 1367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)driver.gltransf_stack.GetLastMatrix();
          if (imptr != NULL)
            Vars.AddVar(type_gltransform,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
            driver.err_print("assignment of NULL matrix\n");
        ;}
    break;

  case 46:
#line 1376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       ;}
    break;

  case 47:
#line 1381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
          (*m1) = m2;
          printf("delete m2\n");
          delete m2;
          printf("delete m2 end\n");
       ;}
    break;

  case 48:
#line 1391 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 49:
#line 1414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * surfptr;
          surfptr = (void*)driver.surf_stack.GetLastSurf();
          if (surfptr != NULL)
            Vars.AddVar(type_surface,(yysemantic_stack_[(3) - (1)].ident),surfptr);
          else
            driver.err_print("assignment of NULL surface\n");
        ;}
    break;

  case 50:
#line 1424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 51:
#line 1442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 52:
#line 1464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int* varint;
          varint = new int((int)(yysemantic_stack_[(6) - (5)].adouble));
          Vars.AddVar(type_int,(yysemantic_stack_[(6) - (1)].ident),(void*)varint);
        ;}
    break;

  case 53:
#line 1471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_uchar,(yysemantic_stack_[(6) - (1)].ident),(void*)varuchar);
        ;}
    break;

  case 54:
#line 1478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          varfloat = new float((yysemantic_stack_[(3) - (3)].adouble));
          Vars.AddVar(type_float,(yysemantic_stack_[(3) - (1)].ident),(void*)varfloat);
        ;}
    break;

  case 55:
#line 1485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string* varstring;
          varstring = new string((yysemantic_stack_[(3) - (3)].astring));
          Vars.AddVar(type_string,(yysemantic_stack_[(3) - (1)].ident),(void*)varstring);
              delete [] (yysemantic_stack_[(3) - (3)].astring);
        ;}
    break;

  case 56:
#line 1493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 57:
#line 1524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 58:
#line 1540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        ;}
    break;

  case 59:
#line 1545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        ;}
    break;

  case 60:
#line 1549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        ;}
    break;

  case 61:
#line 1553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
        ;}
    break;

  case 62:
#line 1558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
        ;}
    break;

  case 63:
#line 1562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->SetProgress((int)((yysemantic_stack_[(4) - (3)].adouble)+0.5));
        ;}
    break;

  case 64:
#line 1565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GB_main_wxFrame->Close(true);
    ;}
    break;

  case 65:
#line 1569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 66:
#line 1608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 67:
#line 1628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 68:
#line 1657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 69:
#line 1674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 70:
#line 1687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 71:
#line 1707 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 72:
#line 1720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 73:
#line 1755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 74:
#line 1785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 75:
#line 1803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        ;}
    break;

  case 76:
#line 1807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        ;}
    break;

  case 77:
#line 1811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 78:
#line 1815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        ;}
    break;

  case 79:
#line 1819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        ;}
    break;

  case 80:
#line 1823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 81:
#line 1827 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 82:
#line 1831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        ;}
    break;

  case 83:
#line 1835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        ;}
    break;

  case 84:
#line 1839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        ;}
    break;

  case 85:
#line 1844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        ;}
    break;

  case 86:
#line 1848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         Vars.deleteVar((yysemantic_stack_[(2) - (2)].variable));
        ;}
    break;

  case 87:
#line 1857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yysemantic_stack_[(5) - (2)].variable)->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
        ;}
    break;

  case 88:
#line 1866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         std::system((yysemantic_stack_[(2) - (2)].astring));
         delete [] (yysemantic_stack_[(2) - (2)].astring);
           ;}
    break;

  case 89:
#line 1871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           ;}
    break;

  case 90:
#line 1879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 91:
#line 1891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 92:
#line 2139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%s",(yysemantic_stack_[(4) - (4)].astring));
          fflush(file.get());
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        ;}
    break;

  case 94:
#line 2201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        ;}
    break;

  case 95:
#line 2210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 96:
#line 2220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          ;}
    break;

  case 97:
#line 2226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          ;}
    break;

  case 98:
#line 2232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        ;}
    break;

  case 99:
#line 2239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        ;}
    break;

  case 100:
#line 2245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 101:
#line 2255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 102:
#line 2265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 103:
#line 2281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 104:
#line 2293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        ;}
    break;

  case 105:
#line 2303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 106:
#line 2352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 107:
#line 2367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 108:
#line 2392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 109:
#line 2419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 110:
#line 2434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 111:
#line 2441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        ;}
    break;

  case 112:
#line 2448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 113:
#line 2466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 114:
#line 2489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 115:
#line 2494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 116:
#line 2499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 117:
#line 2512 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        ;}
    break;

  case 118:
#line 2523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        ;}
    break;

  case 119:
#line 2532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        ;}
    break;

  case 120:
#line 2541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        ;}
    break;

  case 121:
#line 2549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 122:
#line 2566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 123:
#line 2582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 124:
#line 2599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 125:
#line 2619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 126:
#line 2634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 127:
#line 2652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 128:
#line 2665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 129:
#line 2679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        ;}
    break;

  case 130:
#line 2688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 131:
#line 2702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 132:
#line 2713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 133:
#line 2726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 134:
#line 2744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 135:
#line 2766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 136:
#line 2793 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 137:
#line 2821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 138:
#line 2852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 139:
#line 2858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 140:
#line 2876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 141:
#line 2881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 142:
#line 2886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 143:
#line 2891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 144:
#line 2896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 145:
#line 2901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 146:
#line 2915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 147:
#line 2930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 148:
#line 2947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 149:
#line 2961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 150:
#line 2981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 151:
#line 2986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 152:
#line 2991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    ;}
    break;

  case 153:
#line 2998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      driver.res_print("Error in AnisoGS.Iterate ");
    ;}
    break;

  case 154:
#line 3007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    ;}
    break;

  case 155:
#line 3015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 156:
#line 3020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    ;}
    break;

  case 157:
#line 3027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 158:
#line 3032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    ;}
    break;

  case 159:
#line 3037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 160:
#line 3058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 161:
#line 3081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 162:
#line 3086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 163:
#line 3091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 164:
#line 3096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 165:
#line 3101 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 166:
#line 3106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 167:
#line 3111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 168:
#line 3116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 169:
#line 3121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 170:
#line 3126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 171:
#line 3131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 172:
#line 3136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 173:
#line 3141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    ;}
    break;

  case 174:
#line 3146 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 175:
#line 3151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 176:
#line 3156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 177:
#line 3161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 178:
#line 3166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 179:
#line 3171 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 180:
#line 3176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        ;}
    break;

  case 181:
#line 3184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 182:
#line 3189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 183:
#line 3194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 184:
#line 3199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 185:
#line 3204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 186:
#line 3209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 187:
#line 3214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        ;}
    break;

  case 188:
#line 3219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        ;}
    break;

  case 189:
#line 3224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        ;}
    break;

  case 190:
#line 3229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 191:
#line 3234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 192:
#line 3239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    ;}
    break;

  case 193:
#line 3244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    ;}
    break;

  case 194:
#line 3248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 195:
#line 3275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 196:
#line 3288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        ;}
    break;

  case 197:
#line 3293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    ;}
    break;

  case 198:
#line 3297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    ;}
    break;

  case 199:
#line 3303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 200:
#line 3316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        ;}
    break;

  case 201:
#line 3322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 202:
#line 3328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 203:
#line 3334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 204:
#line 3341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        ;}
    break;

  case 205:
#line 3348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

        ;}
    break;

  case 206:
#line 3355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets the object visible or not visible in the scene.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));

        ;}
    break;

  case 207:
#line 3366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

        ;}
    break;

  case 208:
#line 3377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 209:
#line 3392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 210:
#line 3407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        ;}
    break;

  case 211:
#line 3415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->SetColors( i , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 212:
#line 3424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->SetColors( i );

        ;}
    break;

  case 213:
#line 3433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        ;}
    break;

  case 214:
#line 3441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 215:
#line 3445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
        ;}
    break;

  case 216:
#line 3449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 217:
#line 3486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->DisplacePoints( i );
      delete i;

        ;}
    break;

  case 218:
#line 3495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

        ;}
    break;

  case 219:
#line 3502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        ;}
    break;

  case 220:
#line 3509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        ;}
    break;

  case 221:
#line 3520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    ;}
    break;

  case 222:
#line 3528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 223:
#line 3546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    ;}
    break;

  case 224:
#line 3556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        ;}
    break;

  case 225:
#line 3561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        ;}
    break;

  case 226:
#line 3568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        ;}
    break;

  case 227:
#line 3575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    ;}
    break;

  case 228:
#line 3583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    ;}
    break;

  case 229:
#line 3591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 230:
#line 3610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 231:
#line 3626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 232:
#line 3643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 233:
#line 3660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 234:
#line 3665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    ;}
    break;

  case 235:
#line 3670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    ;}
    break;

  case 236:
#line 3675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    ;}
    break;

  case 237:
#line 3680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        ;}
    break;

  case 238:
#line 3689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 239:
#line 3789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 240:
#line 3823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 241:
#line 3830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        ;}
    break;

  case 242:
#line 3838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        ;}
    break;

  case 243:
#line 3844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        ;}
    break;

  case 244:
#line 3851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        ;}
    break;

  case 245:
#line 3861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        ;}
    break;

  case 246:
#line 3870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        ;}
    break;

  case 247:
#line 3877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 248:
#line 3884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        ;}
    break;

  case 249:
#line 3894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        ;}
    break;

  case 250:
#line 3901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 251:
#line 3915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 252:
#line 3929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        ;}
    break;

  case 253:
#line 3937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        ;}
    break;

  case 254:
#line 3942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        ;}
    break;

  case 255:
#line 3950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        ;}
    break;

  case 256:
#line 3958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 257:
#line 3969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 258:
#line 3981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 259:
#line 3993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 260:
#line 4005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 261:
#line 4011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 262:
#line 4024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        ;}
    break;

  case 263:
#line 4031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        ;}
    break;

  case 264:
#line 4042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 265:
#line 4064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 266:
#line 4090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 267:
#line 4118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        ;}
    break;

  case 268:
#line 4128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 269:
#line 4141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        ;}
    break;

  case 270:
#line 4151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 271:
#line 4164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 272:
#line 4193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 273:
#line 4211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 274:
#line 4225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name(),
              (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 275:
#line 4237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 276:
#line 4258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 277:
#line 4277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 278:
#line 4294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 279:
#line 4305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 280:
#line 4310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 281:
#line 4315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    ;}
    break;

  case 282:
#line 4324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 283:
#line 4329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    ;}
    break;

  case 284:
#line 4338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 285:
#line 4352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    ;}
    break;

  case 286:
#line 4359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    ;}
    break;

  case 287:
#line 4365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;;}
    break;

  case 288:
#line 4368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: dispatches the given number of events
      **/
      int nb_event;

      nb_event = 0;
      while (nb_event<500) {
        if (GB_wxApp->Pending()) {
          GB_wxApp->Dispatch();
        }
      } // end while
      nb_event++;

    ;}
    break;

  case 289:
#line 4385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: dispatch the given number of events
      **/
      int nb_event;

      nb_event = 0;
      while (nb_event<500) {
        if (GB_wxApp->Pending()) {
          GB_wxApp->Dispatch();
        }
        nb_event++;
      } // end while

    ;}
    break;

  case 290:
#line 4401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 291:
#line 4435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 292:
#line 4452 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 293:
#line 4492 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        ;}
    break;

  case 294:
#line 4497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        ;}
    break;

  case 295:
#line 4502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        ;}
    break;

  case 296:
#line 4508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 297:
#line 4522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
    pw->BeginBox( (char*) (yysemantic_stack_[(6) - (5)].astring));
    delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 298:
#line 4529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginBook();
    ;}
    break;

  case 299:
#line 4535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    ;}
    break;

  case 300:
#line 4541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->AddPage( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 301:
#line 4548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginPanel( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 302:
#line 4555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    ;}
    break;

  case 303:
#line 4561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    ;}
    break;

  case 304:
#line 4567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    ;}
    break;

  case 305:
#line 4573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        ;}
    break;

  case 306:
#line 4579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        ;}
    break;

  case 307:
#line 4585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 308:
#line 4597 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        ;}
    break;

  case 309:
#line 4603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 310:
#line 4620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer() );
        ;}
    break;

  case 311:
#line 4627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 312:
#line 4638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        ;}
    break;

  case 313:
#line 4645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        ;}
    break;

  case 314:
#line 4650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        ;}
    break;

  case 315:
#line 4656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        ;}
    break;

  case 316:
#line 4661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        ;}
    break;

  case 317:
#line 4666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        ;}
    break;

  case 318:
#line 4671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        ;}
    break;

  case 319:
#line 4676 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        ;}
    break;

  case 320:
#line 4687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 321:
#line 4719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 322:
#line 4743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        ;}
    break;

  case 323:
#line 4750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 324:
#line 4771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        ;}
    break;

  case 325:
#line 4776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 326:
#line 4783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 327:
#line 4790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         ;}
    break;

  case 328:
#line 4798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 329:
#line 4806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 330:
#line 4815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 331:
#line 4822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 332:
#line 4829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 333:
#line 4836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 334:
#line 4843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 335:
#line 4850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 336:
#line 4857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 337:
#line 4864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 338:
#line 4871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 339:
#line 4878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 340:
#line 4885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 341:
#line 4894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 342:
#line 4900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_float);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 343:
#line 4906 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_string);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 344:
#line 4912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_image);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 345:
#line 4918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 346:
#line 4924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_surface);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 347:
#line 4930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_float);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 348:
#line 4936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_string);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 349:
#line 4942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_image);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 350:
#line 4948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 351:
#line 4954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_surface);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 352:
#line 4961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        ;}
    break;

  case 353:
#line 4966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;

      res = new char[(*(string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->length()+1];
      strcpy(res,((string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get()->c_str());
      (yyval.astring)= res;
        ;}
    break;

  case 354:
#line 4978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       fflush(stdout);
        ;}
    break;

  case 355:
#line 4983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 356:
#line 4997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 357:
#line 5009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    ;}
    break;

  case 359:
#line 5018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 360:
#line 5028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        ;}
    break;

  case 362:
#line 5041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          ;}
    break;

  case 366:
#line 5055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    ;}
    break;

  case 367:
#line 5063 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    ;}
    break;

  case 368:
#line 5071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    ;}
    break;

  case 369:
#line 5080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    ;}
    break;

  case 370:
#line 5084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
      char tmp_string[255];
    ;}
    break;

  case 371:
#line 5089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    ;}
    break;

  case 372:
#line 5093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    ;}
    break;

  case 374:
#line 5102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 375:
#line 5117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 376:
#line 5133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(8) - (3)].adouble),(int) ( (yysemantic_stack_[(8) - (5)].adouble)), (int) ((yysemantic_stack_[(8) - (7)].adouble)));
    ;}
    break;

  case 377:
#line 5137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 378:
#line 5154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 379:
#line 5170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 380:
#line 5184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 381:
#line 5197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 382:
#line 5218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 383:
#line 5277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 384:
#line 5297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 385:
#line 5315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    ;}
    break;

  case 386:
#line 5322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    ;}
    break;

  case 387:
#line 5330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 388:
#line 5335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        ;}
    break;

  case 389:
#line 5340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 390:
#line 5368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
        ;}
    break;

  case 391:
#line 5374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        ;}
    break;

  case 392:
#line 5385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 393:
#line 5405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 394:
#line 5425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 395:
#line 5443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 396:
#line 5463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 397:
#line 5481 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 398:
#line 5499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 399:
#line 5522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 400:
#line 5545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 401:
#line 5568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        ;}
    break;

  case 402:
#line 5575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 403:
#line 5600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 404:
#line 5623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
        ;}
    break;

  case 405:
#line 5630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        ;}
    break;

  case 406:
#line 5640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        ;}
    break;

  case 407:
#line 5650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        ;}
    break;

  case 408:
#line 5660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        ;}
    break;

  case 409:
#line 5670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        ;}
    break;

  case 410:
#line 5680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        ;}
    break;

  case 411:
#line 5690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 412:
#line 5704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 413:
#line 5721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 414:
#line 5737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    ;}
    break;

  case 415:
#line 5742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    ;}
    break;

  case 416:
#line 5747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    ;}
    break;

  case 417:
#line 5751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    ;}
    break;

  case 418:
#line 5758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    ;}
    break;

  case 419:
#line 5766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 420:
#line 5801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 421:
#line 5814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable)->Pointer());
    (yyval.adouble) = bid;
    ;}
    break;

  case 422:
#line 5824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 423:
#line 5841 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 424:
#line 5860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 425:
#line 5876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 426:
#line 5894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 427:
#line 5914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 428:
#line 5935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 429:
#line 5948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 430:
#line 5961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    ;}
    break;

  case 431:
#line 5969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    ;}
    break;

  case 432:
#line 5977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    ;}
    break;

  case 433:
#line 5981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float res;
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),(yysemantic_stack_[(6) - (5)].astring),&res);
        (yyval.adouble) =  res;
    ;}
    break;

  case 434:
#line 5989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    ;}
    break;

  case 437:
#line 6000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 438:
#line 6001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 439:
#line 6002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 440:
#line 6003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 441:
#line 6004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 442:
#line 6005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 443:
#line 6006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 444:
#line 6007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 445:
#line 6009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        ;}
    break;

  case 446:
#line 6016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 447:
#line 6017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 448:
#line 6018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 449:
#line 6019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 450:
#line 6020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 451:
#line 6021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 452:
#line 6022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 456:
#line 6035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 458:
#line 6051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 459:
#line 6052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 461:
#line 6057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 462:
#line 6058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 465:
#line 6068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  ;}
    break;

  case 466:
#line 6069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  ;}
    break;

  case 467:
#line 6070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 468:
#line 6071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 470:
#line 6076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 471:
#line 6077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 472:
#line 6078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); ;}
    break;

  case 473:
#line 6079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); ;}
    break;

  case 475:
#line 6085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    ;}
    break;

  case 478:
#line 6098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        ;}
    break;

  case 479:
#line 6102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        ;}
    break;

  case 480:
#line 6109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        ;}
    break;

  case 481:
#line 6113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 482:
#line 6120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    ;}
    break;

  case 483:
#line 6124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    ;}
    break;

  case 485:
#line 6132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        ;}
    break;

  case 488:
#line 6149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    ;}
    break;

  case 489:
#line 6154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       ;}
    break;

  case 490:
#line 6158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       ;}
    break;

  case 491:
#line 6162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       ;}
    break;

  case 492:
#line 6166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       ;}
    break;

  case 493:
#line 6170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       ;}
    break;

  case 494:
#line 6174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       ;}
    break;

  case 495:
#line 6178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       ;}
    break;

  case 496:
#line 6182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       ;}
    break;

  case 497:
#line 6186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       ;}
    break;

  case 498:
#line 6190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      ;}
    break;

  case 499:
#line 6198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        ;}
    break;

  case 500:
#line 6203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 501:
#line 6220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       ;}
    break;

  case 502:
#line 6226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       ;}
    break;

  case 503:
#line 6233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 504:
#line 6291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 505:
#line 6345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 506:
#line 6400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 507:
#line 6421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 508:
#line 6442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 509:
#line 6456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 510:
#line 6485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(10) - (3)].aint), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      ;}
    break;

  case 511:
#line 6493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 512:
#line 6512 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 513:
#line 6538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 514:
#line 6551 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 515:
#line 6629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 516:
#line 6696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
      ;}
    break;

  case 517:
#line 6704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
      ;}
    break;

  case 518:
#line 6712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      ;}
    break;

  case 519:
#line 6722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      ;}
    break;

  case 520:
#line 6732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 521:
#line 6762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 522:
#line 6780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 523:
#line 6800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 524:
#line 6818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 525:
#line 6838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 526:
#line 6857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 527:
#line 6878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 528:
#line 6915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 529:
#line 6930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 530:
#line 6944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 531:
#line 6960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 532:
#line 6983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 533:
#line 6997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 534:
#line 7011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 535:
#line 7025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 536:
#line 7039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 537:
#line 7074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 538:
#line 7089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 539:
#line 7110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:
#line 7131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 541:
#line 7172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 542:
#line 7217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 543:
#line 7234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 544:
#line 7253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 545:
#line 7267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 546:
#line 7281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 547:
#line 7297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 548:
#line 7315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 549:
#line 7330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 550:
#line 7346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 551:
#line 7361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 552:
#line 7384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 553:
#line 7401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 554:
#line 7415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
      ;}
    break;

  case 555:
#line 7427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 556:
#line 7458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 557:
#line 7478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 558:
#line 7520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 559:
#line 7532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 560:
#line 7543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 561:
#line 7556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:
#line 7568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:
#line 7579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:
#line 7607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:
#line 7634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:
#line 7666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:
#line 7682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:
#line 7699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 569:
#line 7712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 570:
#line 7725 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:
#line 7745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 572:
#line 7768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      ;}
    break;

  case 573:
#line 7782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:
#line 7799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 575:
#line 7832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 576:
#line 7870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 577:
#line 7905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 578:
#line 7938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 579:
#line 7955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 580:
#line 7970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 581:
#line 7986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:
#line 8006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:
#line 8029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 584:
#line 8053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 585:
#line 8079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:
#line 8102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 587:
#line 8124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 588:
#line 8147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:
#line 8171 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 590:
#line 8215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 591:
#line 8239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 592:
#line 8270 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 593:
#line 8283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 594:
#line 8320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:
#line 8357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 596:
#line 8394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:
#line 8429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        ;}
    break;

  case 598:
#line 8434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    ;}
    break;

  case 599:
#line 8443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    ;}
    break;

  case 600:
#line 8448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    ;}
    break;

  case 601:
#line 8459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    ;}
    break;

  case 602:
#line 8469 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    ;}
    break;

  case 603:
#line 8479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    ;}
    break;

  case 604:
#line 8488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 605:
#line 8511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 606:
#line 8540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:
#line 8568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 608:
#line 8601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 609:
#line 8633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 610:
#line 8644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 611:
#line 8660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 612:
#line 8670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 613:
#line 8680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 614:
#line 8695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 615:
#line 8709 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 616:
#line 8723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 617:
#line 8736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        ;}
    break;

  case 618:
#line 8749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        ;}
    break;

  case 619:
#line 8761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        ;}
    break;

  case 620:
#line 8773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        ;}
    break;

  case 621:
#line 8785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        ;}
    break;

  case 622:
#line 8796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        ;}
    break;

  case 623:
#line 8809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:
#line 8836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:
#line 8869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:
#line 8977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 627:
#line 9001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 628:
#line 9043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 629:
#line 9056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      res = Func_MeanHalfSize(im,dim);

      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 630:
#line 9067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            InrImage* res;
            int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

            InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
            res=Func_Flip(im,axis);
            driver.im_stack.AddImage(res);
        ;}
    break;

  case 631:
#line 9076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 632:
#line 9100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 633:
#line 9125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 634:
#line 9138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        ;}
    break;

  case 635:
#line 9148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesExtremities(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        ;}
    break;

  case 636:
#line 9158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageConnections(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        ;}
    break;

  case 637:
#line 9168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        ;}
    break;

  case 638:
#line 9178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
        ;}
    break;

  case 639:
#line 9188 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 640:
#line 9196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 641:
#line 9204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 642:
#line 9212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 643:
#line 9239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:
#line 9260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    ;}
    break;

  case 645:
#line 9268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 646:
#line 9306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 647:
#line 9329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 653:
#line 9354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               ;}
    break;

  case 655:
#line 9356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             ;}
    break;

  case 656:
#line 9357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             ;}
    break;

  case 657:
#line 9358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            ;}
    break;

  case 658:
#line 9359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            ;}
    break;

  case 659:
#line 9360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           ;}
    break;

  case 660:
#line 9361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           ;}
    break;

  case 661:
#line 9362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             ;}
    break;

  case 662:
#line 9363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            ;}
    break;

  case 663:
#line 9364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            ;}
    break;

  case 664:
#line 9365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            ;}
    break;

  case 665:
#line 9366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             ;}
    break;

  case 666:
#line 9367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) ;}
    break;

  case 667:
#line 9368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             ;}
    break;

  case 668:
#line 9370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 670:
#line 9387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 672:
#line 9411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 673:
#line 9417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 674:
#line 9419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   ;}
    break;

  case 675:
#line 9420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   ;}
    break;

  case 676:
#line 9421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   ;}
    break;

  case 679:
#line 9430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 680:
#line 9431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 681:
#line 9432 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   ;}
    break;

  case 682:
#line 9433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   ;}
    break;

  case 685:
#line 9441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    ;}
    break;

  case 686:
#line 9442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    ;}
    break;

  case 687:
#line 9443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   ;}
    break;

  case 688:
#line 9444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   ;}
    break;

  case 689:
#line 9445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 690:
#line 9446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 691:
#line 9447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 692:
#line 9448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 694:
#line 9453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   ;}
    break;

  case 695:
#line 9454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   ;}
    break;

  case 696:
#line 9455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   ;}
    break;

  case 697:
#line 9456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   ;}
    break;

  case 712:
#line 9498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           ;}
    break;

  case 713:
#line 9509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 714:
#line 9522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       ;}
    break;

  case 715:
#line 9533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 716:
#line 9550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       ;}
    break;

  case 717:
#line 9557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       ;}
    break;

  case 718:
#line 9567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 724:
#line 9587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               ;}
    break;

  case 726:
#line 9590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        ;}
    break;

  case 727:
#line 9598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             ;}
    break;

  case 728:
#line 9599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             ;}
    break;

  case 729:
#line 9600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            ;}
    break;

  case 730:
#line 9601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            ;}
    break;

  case 731:
#line 9602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           ;}
    break;

  case 732:
#line 9603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           ;}
    break;

  case 733:
#line 9604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             ;}
    break;

  case 734:
#line 9605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            ;}
    break;

  case 735:
#line 9606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            ;}
    break;

  case 736:
#line 9607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            ;}
    break;

  case 737:
#line 9608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             ;}
    break;

  case 738:
#line 9609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) ;}
    break;

  case 739:
#line 9610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             ;}
    break;

  case 742:
#line 9617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 743:
#line 9618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   ;}
    break;

  case 744:
#line 9620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           ;}
    break;

  case 746:
#line 9630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 747:
#line 9631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 748:
#line 9632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   ;}
    break;

  case 749:
#line 9633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   ;}
    break;

  case 761:
#line 9682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        ;}
    break;

  case 762:
#line 9687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 763:
#line 9704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 764:
#line 9716 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 765:
#line 9728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 766:
#line 9740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 767:
#line 9773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 768:
#line 9782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 769:
#line 9791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 770:
#line 9800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 771:
#line 9809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 772:
#line 9818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
        ;}
    break;

  case 773:
#line 9824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
        ;}
    break;

  case 774:
#line 9830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        ;}
    break;

  case 775:
#line 9836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 776:
#line 9862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 777:
#line 9876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 778:
#line 9892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
    ;}
    break;

  case 779:
#line 9902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 780:
#line 9920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 781:
#line 9948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 782:
#line 9975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 783:
#line 9991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 784:
#line 10008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 785:
#line 10041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 786:
#line 10077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 787:
#line 10119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 788:
#line 10145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 789:
#line 10155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 790:
#line 10178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 791:
#line 10190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 792:
#line 10203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 793:
#line 10243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 794:
#line 10288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 795:
#line 10338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 796:
#line 10391 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 797:
#line 10437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 798:
#line 10466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 799:
#line 10499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 803:
#line 10546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        ;}
    break;

  case 818:
#line 10568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent* extent=new ImageExtent( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        ;}
    break;

  case 819:
#line 10576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent* extent=new ImageExtent((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        ;}
    break;

  case 820:
#line 10583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 821:
#line 10599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2539;
  const short int
  Parser::yypact_[] =
  {
     13532, -2539,  8172,  7837,  7837,  3266, -2539, -2539, -2539, -2539,
   -2539,    27, -2539, -2539, -2539,   -40,   135, -2539,    60,  3266,
    5276,   105,    53, -2539, -2539, -2539, -2539, -2539,   127,   136,
     197,   -70,    47, -2539,    80,    38,     7,   157,   230,   250,
     293,    16,   175,   776, -2539, -2539, -2539, -2539,   320,   332,
     349,   101,   358,   141,   202,   374,   389, -2539, -2539, -2539,
     398,   459,   463,   509,   512,   253,   514,   534,   554,   559,
     652,   734,   738,   788,   857,   870,   876,   879,   900,   909,
   -2539,   910,   911, -2539, -2539, -2539, -2539, -2539, -2539, -2539,
   -2539, -2539, -2539,   912,   913,   915, -2539, -2539,  7837,  7837,
    7837,  7837,  7837,  7837,  7837,  7837,  7837,  7837,  7837,  7837,
    7837,   540, -2539, -2539,  5276,   558,   916,   917,   540,   918,
     919,   920,   921, -2539, -2539, -2539, -2539, -2539,   922,   923,
   -2539,   602,  8763, -2539, -2539, -2539, -2539, -2539,   181, -2539,
   -2539,   245,   275, -2539, -2539, -2539,  7837, -2539,   314,   458,
   -2539,    41,   391,   608,   932,   925,   822,     6, -2539, -2539,
   -2539, -2539,   159, -2539, -2539, -2539, -2539,   817,    30,   480,
   -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539,
   -2539,    58,   -14,  8172,  8172,  5276, -2539, -2539, -2539,   926,
     927,   929,   930,   949,   950,   947,   948,  8172,  8172,  8172,
    8172,  8172,  8172,  8172,  8172,  8172,  8172,  8172,  8172,  8172,
    8172, -2539,   345,   961,   927, -2539,   817, -2539,   817, -2539,
     955,   967,   354,   968,  5276, -2539, -2539, -2539, -2539, -2539,
   -2539,   275, -2539, -2539,   275, -2539,    53, -2539,   971, -2539,
   -2539,  5276, -2539, -2539,  5276, -2539, -2539,  5276,    53,  1158,
     235,    62,    62,  5276,  3266,   -24,   521, 10320, 10320, -2539,
     592,   -16,  5276,   669,  5276, -2539, -2539, -2539, -2539, -2539,
   -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539,   979,
     950, -2539, -2539,  5276,  5276, 14428,    60, 14428, 14428,    60,
   14428,    60, 14428,    60,   605,   907,   425,   525,    60,    60,
   14428, 14428,    60,    60,    60,    60,    60,    60,    60,    60,
     956,   958,  5276,  5276,    60,  5276,  5276,    33,   963, 14428,
      60, -2539,   817, -2539,   817, -2539,   817, -2539,   817, -2539,
     817, -2539,   817, -2539,   817, -2539,   817, -2539,   817, -2539,
     817, -2539,   817, -2539,   817, -2539,   817,   873, -2539,   954,
   -2539,   181,   477,   965, -2539,  5276,    53,   957,    60,    60,
      60, -2539, -2539, -2539, -2539, -2539, -2539, -2539,   181, -2539,
      53,    53,    53,    53, -2539,   817,  8172,  8172,  8172,  8172,
    8172,  8172,  8172,  8172,  8172,  8172,  5276,  5276,  5276,  5276,
    5276,  5276,  5276,  5276,   106, 14428, 11280, -2539,  7837,    33,
    7837,  7837,   537,    32, 13985,  9360,   303,   365,   -20,  5276,
    5276,   594,   859,  5276,   -27,   229, -2539, 15192,   -29, -2539,
    1002,   997,   974, -2539, -2539, -2539, -2539,  1007,  1008,  1010,
    1011,  1012,  1013, -2539, -2539, -2539, -2539, -2539, -2539, -2539,
   -2539, -2539,  1014,  1016,  1017, -2539,  1019,  1020,  1034,  1035,
   -2539,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,
    1045,  1046,  1047,  1048,  1059,  1081, -2539,  1082,  1083,  1084,
    1085,  1086, -2539,  1089, -2539,  1090,  1091,  1092,  1093,  1098,
   -2539, -2539,  1107, -2539, -2539,  5276, -2539,  1099,  1100, -2539,
    1117, 12166, 12166, 11280,   251,    84,  1118,  1113,  1114,  1121,
     371,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1130,  1132,
    1135,  1136,  1137,  1138,   363,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1150,  1151,  1152,  1155,  1156,
    1157,  1159,  1160,  1162,  1163,  1165,  1167,  1169,  1170,  1173,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1188,  1189,  1190,  1191,  1192,  1194,  1198,
    1199,  1200,  1201,  1209,  1211,  1212,  1214,  1215,  1217,  1218,
    1219,  1235,  1236,  1237,  1238,  1239,  1247,  1248,  1249,  1250,
    1251,  1254,  1256,  1257, 12166, 12166, 12166, 12166, 12166, 12166,
   12166, 12166, 12166, 12166, 12166, 12166, 12166, 14428,  1258,  1259,
    1260,  1261,  1262,  1263,  1265,  1264,  1266,  1267,  1269,  1272,
     196,   275, 12166, -2539,   431, -2539, -2539, -2539,  1032, -2539,
     767, -2539,   812, -2539,    79,   739,  1154, -2539,  1268,  1171,
       9, -2539, -2539, -2539,  1273,   395,  1275, -2539, -2539, -2539,
    1280,  1281,  1282, -2539, -2539,  1283,  1284,  1291,  1294,  1301,
    1310,  1311,  1313,  1316,  1320, -2539, -2539, -2539, -2539,  1321,
   -2539,    53,  1319,  1322,  1323,  5276,  1324,  1325, 14428, 14428,
   13052,  1317,  1327,   438,  1328, 14428, 14428, 14428, 14428, 14428,
   14428, 14428, 14428, 14428, 14428, 14428, 14428, 14428, 14428,   392,
    1329,  1330,  1332,  1326,  1334,  1336,  1335,  1338,  1337,  1339,
    1331,  1341,  1342, -2539, -2539,  1343,  1347, -2539, -2539,  1349,
    1351,  1354,  1355,  1356,  1357,  1358,  1359, -2539,  1361,  1363,
    1364,  1367,  1368,  1369,  1370,  1371,  1372,  1374,  1375,  1376,
    1377,  1392,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1407,  1408, -2539, -2539, -2539,
   -2539, -2539, -2539,  1409,  1410,   355,  1411,  1412,  1426,  1427,
    1428,  1429,  1430,  1431,  1432,  1435,  1436,  1437,  1413,  1416,
    1438,  1439,   312,  1440,    33,    33,    33, -2539,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,  1447,  1448,  1443,  1450,  5276, -2539,   -12, -2539,
   -2539,  1451,  1452,  1453,  1456,  1454,  1457,  1455,  1458,  1459,
    1460, -2539, -2539, -2539, -2539, -2539, -2539, -2539,   314,   314,
   -2539, -2539, -2539, -2539,    41,    41,   391,   608,   932,   925,
      10,   822,   272,  1461,  1463, -2539,  1468, -2539, -2539,    53,
   -2539,  1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476, -2539,
   -2539, -2539,  1113, -2539, -2539, -2539,   817,   817,   314,    30,
     314,    30, -2539, -2539, -2539,    53,  1477,  1478,    53, -2539,
    1479, -2539,  1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,
    1488,  1490,  1492,  1493,  1494,  1495,  1496,  1498, -2539,  1499,
   -2539,  1500, -2539, -2539,  1501,  1502,  1503,  1504,  1505, -2539,
   -2539,  1506,  1507,  1508,  1509,  1510,  1511,  1512,  1513,  1516,
    1517,  1519,  1520,  1521,  1522,  1523,  1524,  1525,   166,  1526,
    1545,  1546,  1547,  1548,  1543, -2539,  1549, -2539, 11723, 11723,
    9840,    40,  1550,  1551,  1552, -2539,  1553,   198,  1554,  1555,
    1556,  1558, 11723, 11723, 11723, 11723, 11723, 11723, 11723, 11723,
   11723, 11723, 11723, 11723, 11723,   275, 11723, -2539, -2539, -2539,
   -2539,  1557, -2539,  1559,  1561,   273,  5276, -2539, -2539,  5276,
    5276,  5276,  5276,  5276,  5276,  5276,    60,  5276,  5276,   195,
    1110,  1104,  5276,  5276,  5276,  5276,  5276,  5276,  5276, 14428,
    5276,  1414,  5276,  1213,  5276,  5276,    32,  5276,  5276,  5276,
    5276,  5276,    62,    -9,  1514,  1373,  5276,  5276,  5276,  5276,
     275, -2539,    53,  1288,    53,   468, -2539, -2539, -2539,  1560,
    1564, -2539, -2539, -2539, -2539,    11, -2539,  5276,    55,   570,
   10320, 14428,    60, 14428, 14428,    60,    60,    60,    60,    60,
   14428,    60,    60,    60,    60,    60,   -13,    60,    60,    60,
      60,    -7, 14428, 14428,    60,  1222,  1226,    60,    60,    60,
      60,    60,    60,    60,    60,    60, 14428,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
   14428, 14428, 14428, 14428, 14428,    60,    60,    60,    60,    60,
      62,    62,    53,    53,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60, 14428,    60,    60,
      60,    60,    60,    60, 14428, 14428, -2539, -2539, -2539, -2539,
   -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539,
   14428, 14428, 14428,    60, 14428, 14428,   995, 14428, 14428, 14428,
   14428,    53, -2539, 10800, -2539, 11280,  4761, 14428, 14428, 12166,
   12166, 12166, 12166, 12166, 12166, 12166, 12166, 12166, 12166, 14428,
   14428, 14428, 14428, 14428,  -158,   181,    53,    53,  1419,  1518,
      53,  1527,  1529,  5276,  1528,  1530,  5276,  1515,  5276,    53,
    5276, -2539,  1464,  5276,  1465,  1563, -2539,  1531,  1567,   502,
    1270, 14428,   803,     3, 14428, -2539,   518, -2539,  1572, -2539,
   -2539,  1574, -2539,  1577,    60,  5276,    60,  5276,  5276,  5276,
      60,    60,    60,    60,  5276,  5276,  5276,  5276,  5276,  5276,
    5276,    60,  5276,    60,    60,    60,    26,    60,    29,    56,
      60,    60,  5276,  5276,  5276,  5276,  5276,  5276,  5276,  5276,
    5276,  5276,  5276,  5276,  5276,  5276,  5276,    60, -2539, 14428,
   -2539,  1578,  5276,  5276,  5276,  5276,  5276,  5276,  5276,    60,
      60,    60, -2539, -2539,  5276,  5276, -2539,  5276, -2539, -2539,
      53, -2539,  1161, -2539, -2539, -2539, -2539, -2539, -2539,    -3,
    5276, -2539,  5276,    53,    60,    60,  5276, -2539,  5276,  5276,
    5276,  1489,    53,    60, -2539,    60,    60,  5276,  5276,  5276,
    5276,  5276,  5276, -2539,  5276,  5276, -2539,  5276,  5276,  5276,
    5276,  5276,  5276, 14428,  5276,  5276,  5276,  5276,  5276,  5276,
    5276,  5276,    60, 14428,  5276, 14428,  5276,  5276,    60,  5276,
    5276,  5276, 14428,    60,    62,    62,    62, 14428, 14428, 14428,
      53, 14428,    60,    62,    60,    62,    62, 14428,    65, -2539,
   14428, 14428, 14428, 14428, 14428,  1333,  5276,  5276,    53,  -221,
   10320,    53,  5276,  1534,  5276,  5276,    53,  -136, -2539, -2539,
    1581,  1582,   288,  1583,  1584,  1585,  1592,  1587,  1595,  1590,
    1597,  1598,  1600,  1596,  1599,  1601,  1602,  1603,  1604,  1606,
    1605,  1607,  1608,  1609,  1612,  1613,  1618,  1614,   506,  1621,
    1622,  1617,  1619,  1623,  1625,  1624,  1573,   578,  1626,  1627,
    1629,  1630,  1628,  1632,  1637,  1638,  1634, 12609, -2539,  1641,
    1636,  1579,  1639, -2539, -2539, -2539,   579,   628,  1642,  1643,
    1644,  1646,  1647,  1648,  1649,  1650,  1651,  1653,  1654,  1655,
    1656,  1658,  1659, -2539, -2539,  1660,  1661,  1668,  1663, -2539,
    1645,  1671,  1665,  1666,  1667,  1675,  1676,  1677,  1670,  1672,
    1673,  1674,  1678,  1679,  1680,  1682,  1683,  1681,  1690,  1691,
    1686,  1693,  1688,  1692,  1694,  1695,  1696,   580,  1697,  1698,
    1700,  1703,  1704,  1705,  1706,  1699,  1708,  1709,  1710,  1711,
    1712,  1713,  1720,  1721,  1716,  1717,  1718,  1719,  1722,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1737,  1738,  1739,
    1744,  1746,  1748,  1749,  1745,  1750,  1751,   587,  1756,  1758,
    1760,  1762,  1684,   588,   590,  1763,  1752,  1774,   387,  1113,
     275, -2539, -2539,  1775,  1770,   926,   589,   354,  1776, -2539,
   -2539, -2539, -2539, -2539, -2539,   314,   767,   314,   767, -2539,
   -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539,    79, -2539,
      79,   739, -2539,  1268,    35,  1171,  1780,  1782,  1783,  1784,
   -2539,  1785,  1786,  1778,  1781,  1787,  1788,   600,  1789,  1792,
    1805,  1807,  1791,  1794,  1814,  1815,    32,  1816, 14428, -2539,
    1817, 14871,  1224,    60,    60,    60,   603,  1819,  1810,   610,
    1820,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,
    1839,  1840,  1841,  1842,  1847,  1849,  1848,  1855,  1856,  1857,
    1858,  1859,  1871,  1872,  1873,  1874,  1875,  1876,  1878,  1877,
    1881,  1888,  1890,  1892,  1893,  1889,  1894,  1896,  1897,  1898,
    1899,  1895,  1900,  1903, 14428,  1901,  1902,   612,  1904,  1907,
    1905,  1908,  1909,  1911,  1912,  1913,  1915,  1906,  1916,  5276,
     181,  1566,  1616,  1689,  1844,  1867,   615,  1917,  1918,  1925,
    1920,  1921, -2539,   330,  1922,  1929, 11280,  1930,   624,  1931,
    1932,  1927,   385,  1928,   471,  1935,   625,  1933,   626,  1937,
    1940,  1941,  1942,   647,  1943,  1944,  1939,   648,  1946,  1945,
    1947,  1948,  1949,  1950,  1955,  1956,  1957,  1958,  1959,  1960,
    1962,  1964,  1961,  1963,  1965,  1966,  1972,  1973,   649,  1969,
    1970,  1971,  1975,  1976,   650,  1977,  1980,   701,  1984,  1987,
    1988,  1991, -2539,  1978,   702,  1993,  1994,  1995,  1996,  1790,
    2001,  2002,  1979, -2539,   704,  2005,  2004,  2007,  2010,  2011,
    2012, -2539,    60,  5276,  5276,  5276,  5276, -2539,  5276, -2539,
    5276, -2539, -2539, -2539,    60,    60,  5276,  5276,  5276, -2539,
   -2539,  5276,  5276,  5276,  5276, -2539,  5276, -2539,  5276, -2539,
    5276, -2539, -2539,  5276,  5276,  5276,  5276, -2539,  1221, -2539,
    5276, -2539,    60,  5276, 14428, -2539,  1491, -2539, -2539,  1662,
   11280, -2539, -2539,  5276,   -28,  5276, -2539, 14428,    59,  5276,
    5276, -2539,  5276,  5276,  5276,  5276,  5276,  5276,  5276,  5276,
    5276,  5276,  5276,  5276, -2539,  5276,    60,    60, 14428, 14428,
      60,    60,    60, -2539,  5276,  5276,  5276,  5276,  5276,  5276,
    5276,  5276,  5276, -2539, -2539, -2539,    60, -2539,    60,    60,
      60,    60,    60, -2539,    60,    60,  5276,  5276,  5276,  5276,
   14428, 14428, -2539,  5276,  5276,  5276,  5276,    60,    53, -2539,
   -2539,    60,    60,  5276,  5276,  5276,  5276,  5276,  5276,  5276,
    5276,  5276,  5276,  5276, -2539, -2539, -2539, -2539, -2539, -2539,
   -2539,  5276,  5276,  5276, -2539,  5276,  5276,    60,  5276,  5276,
      60, -2539,  5276, -2539,  5276, 14428, -2539, -2539, -2539, -2539,
   -2539, -2539, -2539,  1635, -2539,  5276, -2539, 14428,    60,  2017,
    2019,  2020, -2539, -2539,  5276,  5276,  1631, -2539, -2539,  5276,
      53,    53,    53,  5276, -2539, -2539, -2539, -2539, -2539, -2539,
   -2539, -2539, 14428,  2021,  2023,   705, -2539,    60, -2539,  5276,
   -2539,  5276, -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539,
   -2539, -2539, -2539, -2539, -2539,  5276, -2539, -2539,    60, -2539,
   -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539, -2539,
    5276, -2539,  5276, -2539, -2539, -2539, -2539,  5276, -2539, -2539,
   -2539, -2539, -2539,  5276, -2539, -2539,  2024,  5276,  5276, -2539,
   11280,  5276,  5276, -2539,  5276,  5276,    60,    60,  5276,  5276,
   -2539,  5276,  1293, -2539, -2539, -2539, -2539, -2539, -2539, -2539,
     233,  5276,  5276, -2539,    60,  5276, -2539,  5276,  5276,  5276,
   -2539, -2539, -2539, -2539, -2539,  5276, -2539, -2539,  5276, -2539,
    5276, -2539, -2539, -2539,  5276,  5276, -2539,  5276, -2539, -2539,
   -2539, -2539, -2539,  5276, -2539, -2539,  5276, -2539,  5276, -2539,
    5276,  5276,  5276, -2539, -2539, -2539, -2539, -2539, -2539, -2539,
   -2539,  5276,  5276, -2539, -2539,  5276, -2539, -2539, -2539, -2539,
    5276,  5276,  5276,  5276,  5276,  5276, -2539,  5276,  5276,  5276,
   -2539,  5276,  5276,  5276,  5276,  5276, -2539, -2539,  5276,  5276,
    5276, 11280, 14428,  5276, -2539, -2539, -2539, -2539, -2539, -2539,
    1954, -2539, -2539,  1808,  2022,  2026,  2027,  2029,  2030,  2035,
    2031,  2038,  2039,  2041,  2042,  2040,  2044,  2051,  2046,  2047,
    2048,  2049,  2056,  2054,  2055,  2057,  2058,  2065,  2066,  2073,
    2071,  5276,  2083,  2078,  2085,  2089,   706,  2086,  2087,  2094,
    2095,  2096,  2097,  2098,  2100,  2099,  2102,  2103,  2104,  2105,
    2106,  2107,  2108,  2101,  2109,  2110,  2111,  2112,  2113,  2114,
    2115,  2116,  2117,  2118,  2119,  2120,  2121,  2123,  2130,  2125,
    2126,  2127,  2128,  2129,  2131,  2136,  2138,  2133,  2140,  2141,
    2142,  2137,  2139,  2144,  2146,  2147,  2148,  2143,  2150,  2151,
    2149,  2152,  2153,  2154,  2156,  2157,  2160,  2161,  2162,  2163,
     709,  2158,  2159,  2164,  2165,  2166,  2167,  2168,  2169,  2170,
    2171,  2172,  2175,  2178,  2173,  2174, -2539,  2181, -2539, -2539,
   -2539,  2176,  2177,  2184,  2185,  2186,  2187,  2182,  2189, -2539,
   -2539, -2539,  5276,  2190,  2199,  2206,  2207,  2202,  2203,  2210,
    2205,  2208, -2539,   716,   717,   718,  2212,  2214,  2215,  2216,
    2217,  2218,  2219,  2220,  2221,  2213,  5276,   181,   181,  1910,
    2069,  2179,  2191,  2193,  2231,  2226,  2227,  2228,   343,  2235,
    1742,  2230,  2232,  2233,  2234,  2236,  2237,  2241,  2238,  2239,
    2240,  2242,  2243,  2244,  2245,  2246,  2248,  2247,  2249,  2250,
    2251,  2252,  2259,   721,  2260,  2261,  2262,  2263,  2264,  2265,
     725,  2266,  2267,  2268,  2274,  2275,  2290,  2291,  2269,  5276,
   -2539,  5276, -2539,  5276, -2539,  5276, -2539, -2539, -2539, -2539,
    5276,  5276, -2539,  5276,  5276,  5276,  5276, -2539,  5276,  5276,
    5276,  5276, -2539, -2539, -2539,  5276, -2539, -2539,  5276,  5276,
   -2539, -2539,    22,   140,  5276, -2539, -2539, -2539, -2539,  5276,
   -2539,  5276,  5276,  5276,  5276,  5276,  5276,  5276,  5276, -2539,
    5276,  5276,  5276,  5276,  5276,  5276,  5276,  5276,  5276,  5276,
    5276,  5276,  5276,  5276, -2539,  5276,    60,    60,    60,    60,
      60, -2539, -2539,  5276, -2539, -2539, -2539,  5276,  5276, -2539,
   -2539, -2539, -2539, 14428, -2539, -2539, 14428,  5276,  5276, -2539,
   -2539, -2539, -2539, -2539, -2539, -2539, -2539,  5276,  5276,  5276,
    5276,  5276, -2539,  5276,  5276, -2539,  5276,  5276, -2539, -2539,
   -2539,  5276,  5276, -2539,  5276,  5276, -2539, -2539, -2539, -2539,
      53, -2539,  2270, -2539,  5276, -2539, -2539,    60,  5276, -2539,
    5276,  5276, -2539, 14428, -2539, 14428, -2539, 14428, -2539, 14428,
    5276,  5276,  5276,    60,    60,  5276,  5276, -2539, -2539, -2539,
   -2539, -2539, -2539, -2539, -2539, -2539, -2539,  5276,    60,  5276,
   -2539,  5276,  5276, -2539,  5276,  5276,  5276,  5276,  5276,  5276,
    5276, -2539,  5276,  5276,  5276,  5276,  5276,  5276,  5276,  5276,
    5276, -2539,  5276,  5276,  5276,  5276, -2539, -2539,    60, -2539,
   -2539, -2539, -2539, -2539, 14428, -2539,  5276,  5276,  5276,  5276,
   14428, 14428,  5276,  5276, -2539,  2298,   726,  2293,  2300,  2295,
    2296,  2303,  2299,  2301,  2304,  2305,  2307,  2308,  2309,  2310,
    2313,   505,  2318,  2323,  2315,  2025,   728,  2324,  2325,  2327,
     729,   730,   740,   745,  2328,  2331,  2332,  2333,  2340,   555,
     747,   372,  2336,  2337,  2338,  2339,   749,  2341,  2350,  2365,
    2367,  2368,  2369,  2376,  2371,  2372,  2373,  2375,  2377,  2380,
    2381,  2382,  2388,  2389,  2390,  2385,  2386,  2393,  2391,  2392,
    2394,  2395,  2396,  2397,  2399,  2403,  2036,  2145,  2412,  2415,
    2410, -2539,  2417,  2424,  2419,  2426,  2421,  2428,   750,  2429,
    2427,  2430,  2432,  2433,   754,  2434,  2441,  2442,   181,  2437,
    2438,  2439,  2446,  2450,  2445,  2448,  2455,  2456,  2457,  2458,
    2459,  2460,  2461,  2462,  2463,  2465,  2467,  2470,  2478,  2482,
    2487,  2488,  2489,  2490,  2497,  2498,  2499,  2494,  2501,  2496,
    2502,  2505,  2507,  2512, -2539, -2539,  5276,  5276, -2539,  5276,
    5276, -2539,  5276,  5276, -2539,  5276,  5276,  5276, -2539,  5276,
    5276, -2539,    22,  5276, -2539, -2539,    22,  1914,  5276,  5276,
   -2539,  5276, -2539,  5276, -2539,  5276, -2539,  5276,  5276,  5276,
    5276,  5276, -2539, -2539, -2539,  5276,  5276,  5276,  5276,  5276,
    5276, -2539,  7087,  7087,  7087,  5276,  5276,  5276,  5276, -2539,
    5276,  5276,  5276,  5276,  5276,    60,  5276, -2539, -2539, -2539,
   -2539,  5276,  5276, -2539,  5276,  5276,  5276,  5276,  5276,  5276,
   -2539,  5276,  5276,  5276, -2539, -2539,    53,  5276, -2539,  5276,
   -2539,  5276, -2539, -2539,  5276, -2539,  5276,  5276, -2539,  5276,
   -2539, 14428,    60, -2539, -2539, -2539,  5276,    60,  5276, -2539,
   -2539,  5276,  5276, -2539, -2539, -2539, -2539, -2539, -2539, -2539,
   -2539, -2539, -2539, -2539, -2539, -2539,  5276,  5276,  5276,  5276,
    5276, -2539, -2539, -2539, 14428, -2539,  5276,  5276,  5276, -2539,
   -2539,  2508,  2513,  2515,  2510,  2511,  2514,  2518,  2519,  2521,
    2516,   757,  2517,  2520,  2524,   759,  2522,  2523,   775,   778,
    2525,  2526,  2527,  2528,  2531,  2530,  2532,  2533,  2534,  2535,
    2536,  2537,   542,  2544,   593,  2545,  2229,  2546,  2541,  2542,
    2556,  2558,  2559,  2560,  2561,  2563,  2564,   779,  2565,  2572,
     780,  2573,  2574,  2575,  2570,  2571,  2576,  2578,  2577,  2579,
    2580,  2581,   790,  2582,  2583,  2584,  2585,  2586,  2587,  2588,
    2589,  2590,  2591,  2257,  2593,  2598,  2594,  2595,  2599,  2596,
    2597,  2600,  2601,  2602,  5276, -2539, -2539,  5276,  5276,  5276,
   -2539, -2539, -2539,  5276, -2539,  5276,  5276,    53, -2539, -2539,
      22,  5276,  5276, -2539,  5276, -2539,  5276,  5276,  5276,  5276,
    5276,  5276, -2539,  5276,  5276,  5276,  5276,  5276,  5276,  7087,
   -2539,  7087, -2539, -2539,  7087,  7087,  5276,  5276,  5276,    60,
      60,    60,    60, -2539,  5276,  5276, -2539, -2539,  5276, -2539,
   -2539, -2539,  5276,  5276,  5276, -2539, -2539,  5276, -2539, -2539,
   -2539,  5276,  5276, -2539, -2539,  5276,  5276, -2539,    60,  5276,
      60,  5276,  5276, -2539, -2539,  5276,  5276, -2539,  5276, 14428,
    5276,  5276,  5276,  2604,  2603,  2605,  2606,  2607,  2610,  2608,
    2609,  2616,  2617,  2612,  2619,  2620,  2621,  2622,  2623,  2624,
    2625,   811,  2626,  2627,  2628,  2629,  2630,  2632,  2634,  2635,
    2637,  2633,  2638,  2640,  2641,  2642,  2639,  2645,  2648,  2649,
    2658,  2653,  2661,  2656,  2258,  2657,  2664,  2663,  2665,  2667,
    2673,  2674,  2675,  2688,  2690,  2696,  2698,   833,  2699,  2700,
    2701, -2539,  5276,  5276,  5276,  5276, -2539,  5276,  5276, -2539,
   -2539,  5276, -2539, -2539, -2539, -2539, -2539, -2539,  5276, -2539,
    5276, -2539,  5276, -2539, -2539,  5276, -2539, -2539, -2539, -2539,
    7087, -2539, -2539, -2539, -2539,  5276,  5276, -2539,  5276, -2539,
    5276, -2539,  5276,  5276,  5276, -2539,  5276,  5276,    60,  5276,
      60,  5276,  1799,  5276,  5276,  5276, -2539, 14428,  5276,  5276,
    5276,  2710,  2717,  2715,  2722,    61,  2719,  2721,  2723,  2730,
    2732,  2735,  2731,  2738,  2733,  2736,  2741,  2740,  2744, -2539,
    2747,   837,  2745,   844,  2746,  2748,  2752, 14428,  2753,  2754,
    2755,  2756,  2768,   847,  2763, -2539, -2539,  5276, -2539, -2539,
      53,  5276,  5276, -2539, -2539, -2539,  5276, -2539,  5276,  5276,
   -2539,  5276,  5276, -2539, -2539, 14428,  5276, -2539, 14428,  5276,
    5276,  5276, -2539,  5276,  5276,  5276,  5276, -2539, -2539,  5276,
    5276,  2764,  2771,  2772,  2776,  2777,  2778,  2773,  2774,  2775,
    2782,  2783,  2784,  2779,  2780,  2785,  2788,  2786,  2787,  2789,
     848,   849,  5276, -2539, -2539, -2539, -2539, -2539,  5276,  5276,
    5276, -2539, -2539, -2539,  5276,  5276,    60, -2539,  5276,  5276,
   -2539, -2539,  5276, -2539, 14428,  2790,  2791,  2794,  2792,  2795,
    2793,  2796,  2800,  2797,  2801,  2798,  5276,  5276, -2539,  5276,
   -2539,  5276,    60, -2539,  5276, -2539, 14428,  2799,  2806,  2802,
    2803,  2804,  2807,  2811,  5276, -2539,  5276,  5276,  5276, -2539,
   -2539,  2808,  2809,  2810,  2812,  5276,  5276,  5276, -2539,  2813,
    2814,  2815,  5276,  5276,  5276,  2817,  2816,  2818, -2539,  5276,
    5276,  2819,  2823,  5276, -2539,  2826, -2539
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   453,     0,     0,     0,     0,    17,    59,    60,    61,
      62,     0,   366,    29,    16,     0,    90,    64,     0,     0,
       0,     0,     0,    89,   352,   365,   800,   499,   369,   370,
     371,   353,     0,   761,     0,   717,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    34,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   294,   356,   295,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      68,     0,     0,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,   367,   368,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   363,    30,     0,    26,     0,     0,     0,     0,
       0,     0,     0,   315,   316,   317,   318,   319,     0,     0,
     454,     0,     0,     4,     8,    10,    14,    12,     0,   354,
     358,   361,     0,   373,   435,   455,     0,   457,   460,   463,
     464,   469,   474,   476,   478,   480,   482,   484,   486,   487,
     287,   432,     0,   719,   721,   722,   740,   741,   745,   750,
     751,   752,   753,   754,   755,   756,   757,   758,   759,   760,
      97,     0,     0,     0,     0,     0,   369,   370,   371,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   437,     0,     0,   717,   439,   725,   438,   724,   353,
       0,   432,     0,     0,     0,    85,    65,    67,    92,    91,
      66,    94,   100,    96,    95,   101,     0,    88,     0,    75,
      76,     0,    78,    79,     0,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,   324,    28,
       0,     0,     0,     0,     0,   802,   801,   812,   804,   805,
     806,   813,   807,   808,   809,   810,   811,   815,   814,   816,
     817,   803,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   440,   727,   441,   728,   446,   733,   447,   734,   448,
     735,   449,   736,   450,   737,   452,   739,   451,   738,   442,
     729,   443,   730,   444,   731,   445,   732,     0,    20,     0,
     363,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     1,     3,     5,     9,    11,    15,    13,     0,     6,
       0,     0,     0,     0,   436,   723,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   726,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   372,     0,     0,   720,
       0,     0,     0,    77,    80,    81,    84,     0,     0,     0,
       0,     0,     0,   409,   410,   407,   408,   405,   406,   411,
     412,   413,     0,     0,     0,   104,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,     0,     0,
       0,     0,   245,     0,   253,     0,     0,     0,     0,     0,
     242,   243,     0,    46,    47,     0,    99,     0,     0,    58,
       0,     0,     0,     0,     0,   509,     0,   339,     0,     0,
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
       0,   327,     0,   325,   513,   648,   650,   651,   669,   671,
     677,   678,   683,   684,   693,   698,   700,   701,   703,   705,
     707,   709,   711,   333,     0,     0,     0,   302,   298,   299,
       0,     0,     0,   306,   307,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   303,   304,   305,   308,   428,
     313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   513,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   154,     0,     0,   414,   415,     0,
       0,     0,     0,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   193,   155,
     156,   157,   158,     0,     0,   513,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   717,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   364,     0,    25,
     816,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   359,   360,   472,   473,   458,   459,   461,   462,
     466,   465,   467,   468,   470,   471,   475,   477,   479,   481,
       0,   483,     0,     0,     0,   357,     0,   381,   383,     0,
     195,     0,     0,     0,     0,     0,     0,     0,     0,   498,
     382,    70,     0,    71,    69,   742,   744,   743,   746,   748,
     747,   749,   384,   385,   386,     0,     0,     0,     0,   229,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   223,     0,
     215,     0,   225,   226,     0,     0,     0,     0,     0,   234,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   775,     0,
       0,     0,     0,     0,   778,    50,     0,    41,     0,     0,
       0,   509,     0,     0,     0,   712,     0,   775,     0,   489,
     492,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    54,    40,    45,
      44,   778,    49,     0,     0,     0,     0,   456,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    98,     0,     0,     0,   513,   669,   654,   653,   432,
       0,   329,   331,   335,   337,     0,   501,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   655,   656,   661,   662,
     663,   664,   665,   667,   666,   657,   658,   659,   660,   668,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   322,     0,   652,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   314,   762,     0,   500,     0,    35,     0,     0,   513,
       0,     0,     0,     0,     0,   392,     0,   394,     0,   395,
     396,     0,   397,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   388,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   288,   289,     0,     0,   390,     0,   718,   404,
       0,   291,     0,   362,   363,    21,   430,   431,   293,   341,
       0,   237,     0,     0,     0,     0,     0,   374,     0,     0,
       0,     0,     0,     0,   194,     0,     0,     0,     0,     0,
       0,     0,     0,   198,     0,     0,   199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   773,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,     0,   762,   500,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   649,     0,
       0,     0,     0,   599,   597,   598,     0,   513,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   568,   569,     0,     0,     0,     0,   572,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   340,
     328,   326,   334,     0,     0,   821,     0,   820,     0,   710,
     676,   672,   674,   673,   675,   679,   681,   680,   682,   690,
     686,   689,   685,   691,   687,   692,   688,   696,   694,   697,
     695,   699,   702,   704,     0,   706,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   772,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   713,     0,     0,     0,     0,     0,     0,
       0,   355,     0,     0,     0,     0,     0,   127,     0,   130,
       0,   103,   106,   105,     0,     0,     0,     0,     0,   114,
     115,     0,     0,     0,     0,   120,     0,   129,     0,   246,
       0,   241,   248,     0,     0,     0,     0,   244,     0,   254,
       0,   249,     0,     0,     0,   252,   417,   433,   434,     0,
       0,   670,   502,     0,     0,     0,   508,     0,     0,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   549,     0,     0,     0,     0,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   533,   534,   535,     0,   537,     0,     0,
       0,     0,     0,   544,     0,     0,     0,     0,     0,     0,
       0,     0,   551,     0,     0,     0,     0,     0,     0,   506,
     507,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   624,   529,   531,   593,   594,   595,
     596,     0,     0,     0,   628,     0,     0,     0,     0,     0,
       0,   639,     0,   641,     0,     0,   643,   644,   330,   332,
     336,   338,   625,     0,   514,     0,   555,     0,     0,     0,
       0,     0,   301,   300,     0,     0,     0,   422,   424,     0,
       0,     0,     0,     0,   310,   311,   297,   429,    48,    51,
      43,    36,     0,     0,     0,     0,   285,     0,   141,     0,
     140,     0,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   161,   162,   163,     0,   176,   177,     0,   179,
     187,   181,   182,   188,   183,   189,   185,   186,   184,   164,
       0,   174,     0,   165,   190,   191,   170,     0,   166,   167,
     168,   169,   172,     0,   387,   403,     0,     0,     0,   267,
       0,     0,     0,   274,     0,     0,     0,     0,     0,     0,
     716,     0,   363,    22,   344,   345,   346,   342,   343,   363,
       0,     0,     0,   312,     0,     0,   375,     0,     0,     0,
     380,    73,    72,   138,   137,     0,   196,   197,     0,   281,
       0,   283,   284,   133,     0,     0,   131,     0,   216,   221,
     227,   228,   231,     0,   230,   200,     0,   212,     0,   208,
       0,     0,     0,   204,   205,   206,   207,   213,   222,   214,
     217,     0,     0,   210,   220,     0,   235,   239,   779,   780,
       0,     0,     0,     0,     0,     0,   776,     0,     0,     0,
     767,     0,     0,     0,     0,     0,   774,   788,     0,     0,
       0,     0,     0,     0,    38,    39,   715,    42,   296,    37,
       0,    53,    52,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   708,     0,   634,   635,
     636,     0,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   402,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,   125,     0,   128,     0,   109,   107,   110,   112,
       0,     0,   117,     0,     0,     0,     0,   247,     0,     0,
       0,     0,   255,   250,   261,     0,   418,    57,     0,     0,
     520,   521,     0,     0,     0,   547,   550,   552,   553,     0,
     554,     0,     0,     0,     0,     0,     0,     0,     0,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   532,     0,     0,     0,     0,     0,
       0,   545,   546,     0,   515,   516,   517,     0,     0,   600,
     601,   602,   603,     0,   647,   609,     0,     0,     0,   614,
     615,   616,   617,   618,   619,   620,   621,     0,     0,     0,
       0,     0,   629,     0,     0,   630,     0,     0,   638,   640,
     642,     0,     0,   637,     0,     0,   421,   423,   425,   426,
       0,   309,     0,   286,     0,   152,   175,     0,     0,   178,
       0,     0,   262,     0,   264,     0,   269,     0,   268,     0,
       0,     0,     0,     0,     0,     0,     0,   290,   363,    18,
      24,   349,   350,   351,   347,   348,   323,     0,     0,     0,
     376,     0,     0,   379,     0,     0,     0,     0,     0,     0,
       0,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   782,     0,     0,     0,     0,   777,   763,     0,   764,
     768,   769,   770,   771,     0,   789,     0,     0,     0,     0,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   123,     0,     0,   102,     0,
       0,   119,     0,     0,   240,     0,     0,     0,   260,     0,
       0,   512,     0,     0,   522,   523,     0,     0,     0,     0,
     559,     0,   562,     0,   564,     0,   566,     0,     0,     0,
       0,     0,   570,   571,   604,     0,     0,     0,     0,     0,
       0,   581,     0,     0,     0,     0,     0,     0,     0,   591,
       0,     0,     0,     0,     0,     0,     0,   518,   519,   646,
     610,     0,     0,   622,     0,     0,     0,     0,     0,     0,
     633,     0,     0,     0,   419,   420,     0,     0,   180,     0,
     171,     0,   263,   265,     0,   270,     0,     0,   279,     0,
     278,     0,     0,   389,   391,    19,     0,     0,     0,   377,
     378,     0,     0,   280,   282,   134,   135,   132,   209,   211,
     201,   202,   203,   218,   219,   233,     0,     0,     0,     0,
       0,   765,   766,   790,     0,   791,     0,     0,     0,   787,
     714,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   819,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   113,     0,     0,     0,
     257,   258,   259,     0,   510,     0,     0,     0,   524,   525,
       0,     0,     0,   558,     0,   561,     0,     0,     0,     0,
       0,     0,   530,     0,     0,     0,     0,     0,     0,     0,
     582,     0,   584,   586,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   542,     0,     0,   611,   612,     0,   623,
     626,   627,     0,     0,     0,   528,   556,     0,   427,   139,
     159,     0,     0,   266,   273,     0,     0,   277,     0,     0,
       0,     0,     0,   136,   781,     0,     0,   785,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,     0,     0,     0,     0,   511,     0,     0,   526,
     527,     0,   560,   563,   565,   567,   574,   577,     0,   606,
       0,   608,     0,   575,   578,     0,   583,   585,   587,   588,
       0,   590,   536,   538,   539,     0,     0,   543,     0,   613,
       0,   631,     0,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   792,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   818,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   118,     0,   251,   504,
       0,     0,     0,   576,   607,   605,     0,   589,     0,     0,
     592,     0,     0,   160,   271,     0,     0,   276,     0,     0,
       0,     0,    74,     0,     0,     0,     0,   797,   796,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,   503,   557,   579,   540,     0,     0,
       0,   272,   292,   275,     0,     0,     0,   783,     0,     0,
     793,   794,     0,   798,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   645,     0,
     238,     0,     0,   784,     0,   795,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   541,     0,     0,     0,   786,
     799,     0,     0,     0,     0,     0,     0,     0,   321,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,   320,     0,   632
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2539, -2539, -2539,   -37,  1843,  1845,  1846, -2539,  1938,  1983,
    -253, -2539, -2539,   543, -2539,   360,  -348, -2539, -2539, -2539,
   -2539,  -413,  5252,   449,  -366, -2539,  -374,   511,  1779,  1793,
    2059,  1891,  2018,  2053,   424, -2539,     0,    81,  3159, -2539,
   -2539, -2539,  -450,  1620,  -236, -2539, -2539,  -275,  -240,  1022,
   -2539,  1378,  1120,   953,  1441,   623,  1533,  6646,  1615, -2539,
   -2539, -2539, -2539,   171,   519, -2539, -2539, -2539, -2539, -2539,
   -2539, -2539, -2539, -2539, -2539, -2539,    36,  6230,  -402,    75,
    2286, -2538
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   131,   132,   133,   134,   135,   136,   804,   137,   138,
     610,  1666,   139,   140,   141,   142,   348,   349,  1273,   143,
     144,   145,   210,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   220,   161,   222,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,  1020,   959,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   223,   213,   925,   850,
     282,  1538
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       160,   259,   798,   962,   967,   635,   820,   821,   822,   823,
       6,    27,   818,   819,   485,   835,   835,    33,    14,   232,
     235,    26,   660,    26,   932,   255,   390,   193,   194,  1162,
     262,  1286,  1443,  1444,   858,   860,   180,   398,  1449,   224,
       1,  1016,  1016,   774,   775,   776,   380,   381,  1449,  1406,
     253,    21,  1025,   248,  1357,   233,  1917,   935,    24,   862,
     863,   864,    27,   641,   642,   249,   219,   645,   646,   647,
     648,   649,   650,    27,  3119,   182,   402,    27,  1732,   194,
      27,   862,   863,   864,  1153,  1154,   221,  1026,   404,    33,
     194,   229,   777,    21,   194,   363,  1025,   194,   250,   193,
      24,   369,  1424,  1425,    27,    21,  2146,    27,   219,   405,
      27,    27,    24,   286,   350,   287,    27,   236,   263,    33,
     219,   194,   391,  1739,   194,  1163,   391,   194,   194,   193,
     256,  1026,   160,   194,  1016,  1016,  1016,  1016,  1016,  1016,
    1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,   717,   834,
     835,  1163,   399,   289,  1743,   290,    26,  1450,   382,   383,
     403,   254,  1016,    58,  2823,  2825,  2827,  1450,   180,   257,
     837,   392,   837,   393,   216,   218,  1618,   394,  1348,  1621,
     372,   373,   228,   251,   252,    26,   347,  2546,   838,   264,
     838,    27,  1451,   354,   707,   708,  1155,  1156,  1566,  1567,
    1568,  1569,  1451,     6,   661,    58,  1623,   182,   194,  1142,
    1348,    14,  1362,  1349,   291,  1143,   292,    58,  1016,  1016,
    1566,  1567,  1568,  1569,   420,  1016,  1016,  1016,  1016,  1016,
    1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,   239,
     240,   423,   258,   836,   424,  1349,    27,   425,   242,   243,
     241,  1381,     6,   482,   483,   370,   371,   613,   613,   244,
      14,   395,   662,   194,   664,   300,   221,   301,   260,   322,
     324,   326,   328,   330,   332,   334,   336,   338,   340,   342,
     344,   346,   396,   666,   667,  1287,  1287,   903,   904,   905,
     484,  1288,  1288,  1289,  1290,  1290,   906,   907,   908,   909,
     413,   910,    27,  1021,  1022,   837,   418,  1753,    33,   245,
     246,   261,   768,   769,   799,   771,   773,   375,   193,   194,
     247,   376,   377,   838,   413,  1266,   839,   840,   841,   842,
     418,   811,   283,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   911,  2026,   284,   912,   913,   914,   915,  2027,
     916,   917,  2028,   792,   918,   805,  2480,   413,   843,   844,
     845,   285,  2481,   414,   659,  2482,   413,  1194,   938,  1146,
     288,  2987,   418,  2988,  1249,  1045,  2989,  2990,  1423,   231,
     234,  1046,   237,  1031,   413,   287,   293,   849,   849,   849,
     418,  2696,   832,   833,   372,   373,   853,   413,  2039,   486,
     487,   488,   489,   418,  1194,   957,  1146,   294,  1165,   963,
     964,    81,    82,   965,  1143,   225,   295,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,   801,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    27,  1908,
    1909,   960,  1274,  1145,    33,  1146,   862,   863,   864,   418,
    1045,   211,   215,   217,   193,   194,  1192,  1661,  1662,  1663,
    1664,  1665,   778,   779,   780,   781,   782,   783,   378,   379,
     784,   785,   786,   787,   788,   789,   790,   296,  1016,  1016,
    1145,   297,  1146,   413,  2041,  1011,   414,   846,   847,   418,
     400,   401,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,
    1016,  1016,  1016,  1016,  1016,   848,  1016,   919,   920,   921,
     384,   385,  3093,   922,  1194,   923,  1146,   413,  2671,  1779,
    1592,   298,   849,   418,   299,  1780,   302,    26,    27,   265,
     266,   130,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   800,   280,   303,   321,   323,   325,
     327,   329,   331,   333,   335,   337,   339,   341,   343,   345,
     462,  2909,   463,  1915,   464,   465,   304,   413,  2693,   856,
     857,   305,   466,   418,  1019,   467,   468,   469,   470,   471,
     472,   433,   434,   435,   436,   437,   438,   439,   440,   441,
      26,  1789,  1806,  1853,  1399,   374,   421,  1790,  1143,  1854,
    1894,  1901,   361,  1903,  1914,   351,  1895,  1902,   426,  1904,
    1915,   473,  2911,  1928,  1915,   474,  1946,   611,   611,  1929,
     475,   476,  1947,  1950,   386,  1999,   749,   750,  2019,  1951,
     477,  2000,   215,   217,  2020,   478,   479,  2034,  2043,  2046,
    1194,  1197,  1146,  2035,  2044,  2047,   321,   323,   325,   327,
     329,   331,   333,   335,   337,   339,   341,   343,   345,   374,
    2052,  2057,  2079,  2086,   306,  1185,  2053,  2058,  2080,  2087,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   658,  2269,  2270,  2271,  2272,  2273,  1016,  1016,
    1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,
    1016,  1016,  1016,  1016,  2090,  2097,   806,  2107,  2241,  2351,
    2091,  2098,  2416,  1143,  2242,  2352,   751,   752,  2417,  2452,
    2454,  2456,   814,   815,  2507,  2453,  2455,  2457,  2515,  2655,
    2508,  2675,  2680,  2682,  2516,  2656,   307,  2676,  2681,  2683,
     308,  1188,   700,  2684,   862,   863,   864,   865,  2686,  2685,
    2694,  1275,  2701,  2743,  2687,   955,  2695,  2750,  2702,  2744,
    2884,  1148,  2889,  2751,  1149,  1150,  2885,  1426,  2890,  1549,
    1551,  1553,  1555,  1557,  1559,  1545,  1547,   866,  2893,   487,
     488,  2895,  2923,  2927,  2894,   867,  1272,  2896,  2924,  2928,
     309,   707,   708,  2940,   701,   702,   703,   704,   868,  2941,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,  1151,  1152,  3039,   816,   817,    27,   265,   266,
    3040,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,  1010,  3076,   855,  1443,  1444,
    3134,   869,  3077,   870,   871,   872,  3135,  3137,  1157,  1158,
    3148,  3191,  3193,  3138,   873,   874,  3149,  3192,  3194,   310,
     875,   876,   877,   878,  1566,  1567,  1568,  1569,  1550,  1552,
    1554,  1556,   311,   879,   880,   881,   882,   883,   312,   884,
     885,   313,   886,  1424,  1425,   824,   825,   887,   888,   889,
     890,   891,   892,   893,   894,   895,   896,   897,   898,   899,
     900,   901,   314,   812,   813,  1546,  1548,  1558,  1560,   859,
     861,   315,   316,   317,   318,   319,  1660,   320,   352,   353,
     355,   356,   357,   358,   359,   360,   387,   389,   397,   253,
     215,   217,   388,   490,   406,   216,   218,   407,   408,   322,
     324,   326,   328,   330,   332,   334,   336,   338,   340,   342,
     344,   346,   375,   409,   410,   411,   412,  1801,   416,  1370,
    1371,  1373,  1374,  1375,  1376,  1377,   659,  1379,  1380,   415,
     417,   419,  1385,  1386,  1387,  1388,  1389,  1390,  1391,   422,
    1393,   663,  1395,   665,  1397,  1398,   796,  1400,  1401,  1402,
    1403,  1404,   797,   766,   967,   767,  1410,  1411,  1412,  1413,
     793,  1019,   803,   807,   717,   968,   969,   902,   835,   970,
     971,  1181,   972,   973,   974,   975,   976,  1422,   977,   978,
     613,   979,   980,   321,   323,   325,   327,   329,   331,   333,
     335,   337,   339,   341,   343,   345,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,   991,   992,   993,   994,
     995,   374,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   996,   726,   727,   728,   729,   730,   731,   732,   733,
     734,   735,   736,   737,   738,   739,   740,   741,   742,   743,
     744,   745,   746,   997,   998,   999,  1000,  1001,  1002,   216,
     218,  1003,  1004,  1005,  1006,  1007,  1420,  1744,   747,   748,
    1008,  1012,  1013,   322,   324,   326,   328,   330,   332,   334,
     336,   338,   340,   342,   344,   346,  1009,   375,  1570,  1014,
    1027,  1028,  1029,  1030,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1801,  1039,  1531,  1040,   965,  1536,  1041,  1042,  1043,
    1044,  1047,  1048,  1049,  1050,  1147,  1052,  1053,  1054,  1383,
    1384,  1051,  1057,  1058,  1059,  1055,  1056,  1060,  1061,  1062,
    1159,  1063,  1064,  1578,  1065,  1066,  1581,  1067,  1583,  1068,
    1585,  1069,  1070,  1587,  1938,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1294,
    1085,  1086,  1087,  1088,  1089,  1597,  1090,  1599,  1600,  1601,
    1091,  1092,  1093,  1094,  1606,  1607,  1608,  1609,  1610,  1611,
    1612,  1095,  1614,  1096,  1097,  1303,  1098,  1099,  1306,  1100,
    1101,  1102,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,  1641,  1103,  1104,  1105,
    1106,  1107,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1108,
    1109,  1110,  1111,  1112,  1655,  1656,  1113,  1657,  1114,  1115,
    1130,  1131,  1132,  1133,  1134,  1135,  1137,  1396,  1138,  1139,
    1667,  1140,  1668,  1136,  1141,  1160,  1161,  1166,  1673,  1674,
    1675,  1164,  1167,  1168,  1169,  1170,  1171,  1681,  1683,  1685,
    1686,  1687,  1688,  1172,  1689,  1690,  1173,  1691,  1692,  1693,
    1694,  1695,  1696,  1174,  1698,  1699,  1700,  1701,  1702,  1703,
    1704,  1705,  1175,  1176,  1708,  1177,  1710,  1711,  1178,  1713,
    1714,  1715,  1179,  1180,  1182,  1190,  1183,  1186,  1184,  1191,
    1415,  1198,  1195,  1205,  1187,  1197,  1193,  1199,  1196,  1200,
    1201,  1202,  1203,  1206,  1207,  1208,  1740,  1741,  1204,  1209,
     613,  1210,  1746,  1211,  1748,  1749,  1212,  1213,  1214,  1215,
    1216,  1217,  1414,  1218,  1416,  1219,  1220,   215,   217,  1221,
    1222,  1223,  1224,  1225,  1226,  1419,  1227,  1228,  1229,  1230,
     611,   321,   323,   325,   327,   329,   331,   333,   335,   337,
     339,   341,   343,   345,  1231,   374,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,
    1246,  1455,  1409,  1248,  1250,  1456,  1262,  1251,  1247,  1263,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,  1492,  1493,  1259,  1260,  1261,  1264,  1265,  1267,
    1268,  1269,  1270,  1271,  1276,  1277,  1278,  1016,  1279,  1522,
    1281,  1573,  1394,  1280,  1282,  1292,  1291,  1283,  1284,  1285,
    1293,  1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1304,
    1305,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,
    1316,  1527,  1317,  1530,  1318,  1319,  1320,  1321,  1322,   442,
    1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,
    1333,  1334,  1335,  1336,  1337,  1338,  1571,  1572,  1339,  1340,
    1575,  1341,  1342,  1343,  1344,  1345,  1346,  1347,  1350,  1584,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,  1351,  1352,  1353,
    1354,  1355,  1358,  1356,  1360,  1361,  1363,  1364,  1365,  1359,
    1366,  1574,  1408,  1417,  1368,  1367,  1369,  1418,  1589,  1582,
    1591,  1576,  1577,  1579,  1593,  1580,  1594,  1586,  1588,  1595,
    1644,  1788,  1739,  1423,  1751,  1590,  1743,  1804,  1541,  1543,
    1747,  1752,  1754,  1755,  1756,  1757,  1758,  1659,  1759,  1760,
    1761,  1762,  1676,  1763,  2141,  1764,  2014,  1769,  1765,  1770,
    1766,  1767,  1768,  2013,  1771,  1775,  1772,  1773,  1774,   460,
    1658,  1777,  1776,  1778,  1781,  1782,  1783,  1787,  1784,  1791,
     849,  1795,  1785,  1669,  1786,  1796,  1792,   461,  1793,  1794,
    1797,  1798,  1677,  1799,  1802,  1803,  2224,  1826,  1805,  2012,
    1811,  1807,  1808,  1809,  2267,  1810,  2015,  1812,  1813,  1814,
    1815,  2268,  1816,  1817,  1818,  1819,  2031,  1820,  1821,  1822,
    1823,  1824,  1825,  1827,  1828,  1829,  1830,  1831,  1832,  1834,
    1833,  1835,  1836,  1837,  1843,  2233,  1900,  1838,  1839,  1840,
    1724,  1841,  1842,  1844,  1845,  1846,  1847,  1848,  1733,  2142,
    1672,  1849,  1862,  1850,  1851,  1852,  1855,  1856,  1742,  1857,
     611,  1745,  1858,  1859,  1860,  1861,  1750,  1863,  1864,  1865,
    1866,  1867,  1868,  1869,  1870,  1871,  1872,  1873,  1874,  2016,
    2266,  1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,
    1884,  1885,  1886,  2115,  2116,  2117,  2118,  1887,  2119,  1888,
    2120,  1889,  1890,  2484,  1891,  1906,  2123,  2124,  2125,  1892,
    1893,  2126,  2127,  2128,  2129,  1896,  2130,  1897,  2131,  1898,
    2132,  1899,  1905,  2133,  2134,  2135,  2136,  1907,  1912,  1913,
    2137,  1916,  1918,  2139,  1919,  1920,  1921,  1924,  1922,  1923,
    1925,  1927,  2103,  2143,  1934,  2144,  1926,  1935,  1930,  2148,
    2149,  1931,  2150,  2151,  2152,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  1932,  2162,  1933,  1936,  1937,  1949,
    1941,  1939,  1948,  1952,  2170,  2171,  2172,  2173,  2174,  2175,
    2176,  2177,  2178,  1953,  1954,  1955,  1956,  1957,  1958,  1959,
    1960,  1961,  1962,  1963,  1964,  2318,  2187,  2188,  2189,  2190,
    1966,  1965,  1967,  2193,  2194,  2195,  2196,  1968,  1969,  1970,
    1971,  1972,  1973,  2201,  2202,  2203,  2204,  2205,  2206,  2207,
    2208,  2209,  2210,  2211,  1974,  1975,  1976,  1977,  1978,  1979,
    1981,  2212,  2213,  2214,  2017,  2215,  2216,  1980,  2218,  2219,
    1982,  1983,  2221,  1984,  2222,  1985,  1986,  1988,  1987,  1989,
    1990,  1991,  1992,  1994,  1993,  2225,  1995,  2018,  2003,  2010,
    1997,  1998,  3107,  2001,  2231,  2232,  2002,  2004,  2005,  2234,
    2006,  2007,  2008,  2238,  2009,  2011,  2021,  2022,  2023,  2024,
    2025,  2029,  2030,  2033,  2036,  2037,  2038,  2040,  2042,  2244,
    2048,  2245,  2045,  2049,  2050,  2051,  2054,  2055,  2056,  2059,
    2471,  2805,  2063,  2064,  2060,  2246,  2061,  2062,  2065,  2066,
    2067,  2068,  2069,  2070,  2073,   364,  2074,   365,   366,  2076,
    2248,  2071,  2249,  2072,  2075,  2077,  2078,  2250,  2081,  2082,
    2083,  2096,  2106,  2251,  2084,  2085,  2088,  2253,  2254,  2089,
    2255,  2257,  2258,  2092,  2259,  2260,  2093,  2094,  2263,  2264,
    2095,  2265,  2099,  2100,  2101,  2102,  2104,  2105,  2108,  2109,
    2317,  2274,  2275,  2111,  2112,  2277,  2110,  2278,  2279,  2280,
    2228,  2113,  2229,  2230,  2239,  2281,  2240,  2252,  2282,  2320,
    2283,  2319,  2322,  1592,  2284,  2285,  2321,  2286,  2324,  2323,
    2325,  2326,  2327,  2287,  2328,  2329,  2288,  2732,  2289,  2330,
    2290,  2291,  2292,  2331,  2332,  2333,  2334,  2335,  2336,  2337,
     367,  2293,  2294,  2338,  2339,  2295,  2340,  2341,  2342,  2343,
    2296,  2297,  2298,  2299,  2300,  2301,  2344,  2302,  2303,  2304,
    2345,  2305,  2306,  2307,  2308,  2309,  2347,  2348,  2310,  2311,
    2312,  2313,  2350,  2316,  2349,  2353,  2354,  2355,  2356,  2357,
    2358,  1017,  1018,  2360,  2369,   368,  1565,  2359,  2361,  2472,
    2618,  2362,  2363,  2364,  2365,  2366,  2367,  2368,  2370,  2371,
    2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,  2380,  2381,
    2382,  2346,  2383,  2384,  2385,  2386,  2387,  2388,  2389,  2391,
    2390,  2392,  2393,  2394,  2395,  2396,  2397,  2399,  2398,  2400,
    2401,  2402,  2403,  2404,  2405,   826,  2733,  2409,  2406,  2410,
    2411,  2407,  2408,  2412,  2413,  2414,  2415,  2418,  2419,  2422,
     827,  1561,  2425,  2420,  2421,  2428,  2423,  2424,  2429,  2426,
    2427,  2430,  2431,  2432,  2433,  2434,  2435,  2436,  2437,  2438,
    2439,  2440,  2441,  2443,  1116,  1117,  1118,  1119,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  2444,  2445,
    2446,  2447,  2448,  2449,  2450,  2458,  2467,  2451,  2198,  2473,
    2469,  2470,  1144,  2459,  2460,  2461,  2462,  2463,  2464,  2465,
    2466,  2474,  2442,  2475,  2476,  2477,  2478,  2479,  2483,  2485,
    1915,  2486,  2487,  2488,  2491,  2489,  2490,  2492,  2493,  2494,
    2501,  2495,  2496,  2497,  2498,  2499,  2468,  2500,  2502,  2503,
    2504,  2505,  2506,  2509,  2510,  2511,  2512,  2513,  2952,  3063,
     829,  1563,  2524,  2601,  2514,  2517,  2518,  2519,  1017,  1018,
    2235,  2236,  2237,  2520,  2521,  1116,  1117,  1118,  1119,  1120,
    1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1144,  2522,
    2523,  2654,  2657,  2658,  2659,  2660,  2661,  2664,  2662,  2525,
    2663,  2526,  2668,  2527,  2665,  2528,  2666,  2667,  2674,  2669,
    2529,  2530,  2670,  2531,  2532,  2533,  2534,  2672,  2535,  2536,
    2537,  2538,  2673,  2677,  2678,  2539,  2679,  2688,  2540,  2542,
    2689,  2690,  2691,  2692,  2548,  2697,  2698,  2699,  2700,  2549,
    2703,  2550,  2551,  2552,  2553,  2554,  2555,  2556,  2557,  2704,
    2558,  2560,  2562,  2563,  2564,  2565,  2566,  2567,  2568,  2569,
    2570,  2571,  2572,  2573,  2705,  2574,  2706,  2707,  2708,  2709,
    2710,  2711,  2712,  2580,  2713,  2717,  2714,  2581,  2582,  2715,
    2716,  2718,  2719,  2720,  2721,  2722,  2723,  2585,  2586,   831,
    2724,  2725,  2730,  2726,  2727,  2728,  2729,  2587,  2588,  2589,
    2590,  2591,  2731,  2592,  2593,  2734,  2594,  2595,  2735,  2736,
    2543,  2596,  2597,  2544,  2598,  2599,  2737,  2738,  2739,  2740,
    2741,  2742,  2745,   830,  2602,  2748,  2746,   828,  2604,  2747,
    2605,  2606,  2749,  2752,  2753,  2754,  2756,  2757,  2758,  2759,
    2611,  2612,  2613,  2760,  2761,  2616,  2617,  2762,  2763,  2764,
    2765,  2766,  2767,  2768,  2769,  2770,  2771,  2619,  2772,  2621,
    2773,  2622,  2623,  2774,  2624,  2625,  2626,  2627,  2628,  2629,
    2630,  2775,  2631,  2632,  2633,  2634,  2635,  2636,  2637,  2638,
    2639,  2776,  2640,  2641,  2642,  2643,  2777,  2778,  2779,  2780,
    2781,  2782,  2783,  2784,  2785,  2786,  2646,  2647,  2648,  2649,
    2789,  2787,  2652,  2653,  2788,  2790,  2875,  2874,  2876,  2877,
    2878,  2880,  2881,  2879,  2882,  2883,  2886,  2888,  1562,  2887,
    2226,  2891,  2892,  2902,  2897,  2898,  2899,  2900,  1017,  1018,
    2901,  2903,  2904,  2905,  2906,  2907,  2908,  2910,  2912,  2913,
    2914,  2915,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,
    1124,  1125,  1126,  1127,  1128,  2916,  1144,  2917,  2918,  2919,
    2920,  2755,  2921,  2922,  2925,  2926,  2929,  2930,  2931,  2932,
    2933,  2935,  2936,  2938,  2939,  2934,  2943,  2944,  2937,     0,
    2947,  2942,     0,  1564,  2945,  2946,  2953,  2948,  2949,  2950,
    2951,  2954,  2957,  2955,  2956,  2958,  2959,  3021,  1407,  2960,
    2961,  2962,  3022,  3026,  3023,  3024,  3025,  3027,  3028,  3029,
    3030,  3031,  3032,  3033,  3034,  3035,  3036,  3037,   802,  3041,
       0,  3043,  3044,     0,  3038,  3046,  3042,  3047,  3048,  3045,
    3049,  3051,  3050,  3052,  3053,  3054,  2791,  2792,  3055,  2793,
    2794,  3057,  2795,  2796,  3056,  2797,  2798,  2799,  3058,  2800,
    2801,  3059,  3060,  2803,  3061,  3062,  3064,  3065,  2806,  2807,
    1539,  2808,  3066,  2809,  3067,  2810,  3068,  2811,  2812,  2813,
    2814,  2815,  3069,  3070,  3071,  2816,  2817,  2818,  2819,  2820,
    2821,  3072,  2822,  2824,  2826,  2828,  2829,  2830,  2831,  3073,
    2832,  2833,  2834,  2835,  2836,  3074,  2838,  3075,  3078,  3079,
    3080,  2839,  2840,  3115,  2841,  2842,  2843,  2844,  2845,  2846,
    3116,  2847,  2848,  2849,  3117,  3118,     0,  2851,  3120,  2852,
    3121,  2853,  3122,  3123,  2854,  3124,  2855,  2856,  3125,  2857,
    3126,  3127,  3128,  2802,  3130,  3129,  2860,  2804,  2862,  3131,
    3133,  2863,  2864,  3132,  3136,  3139,     0,  3140,  1540,  1542,
    1544,  3141,  3143,  3144,  3145,  3146,  2865,  2866,  2867,  2868,
    2869,  3147,  3150,  3172,  3173,  3174,  2871,  2872,  2873,  3175,
    3176,  3177,  3178,  3179,  3180,  3181,  3182,  3183,  3184,  3185,
    2600,  3187,  3190,     0,  3186,  3188,  3189,  3208,  3210,  3206,
    3207,  3209,  3211,  3213,  3215,  3212,  3214,  3216,  3224,  3225,
    3229,  3226,  3227,  3228,  3230,  3238,     0,  3235,  3236,  3237,
    3248,     0,  3242,  3243,  3244,  3249,  3254,  3250,  3253,  3256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2963,     0,     0,  2964,  2965,  2966,
       0,     0,     0,  2967,     0,  2968,  2969,     0,     0,     0,
       0,  2972,  2973,     0,  2974,     0,  2975,  2976,  2977,  2978,
    2979,  2980,     0,  2981,  2982,  2983,  2984,  2985,  2986,  2826,
       0,  2826,     0,     0,  2826,  2826,  2991,  2992,  2993,     0,
       0,     0,     0,     0,  2998,  2999,     0,     0,  3000,     0,
       0,     0,  3001,  3002,  3003,     0,     0,  3004,     0,     0,
       0,  3005,  3006,     0,     0,  3007,  3008,     0,     0,  3010,
       0,  3012,  3013,     0,     0,  3014,  3015,     0,  3016,     0,
    3018,  3019,  3020,     0,     0,     0,     0,     0,     0,     0,
       0,  2971,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3081,  3082,  3083,  3084,     0,  3086,  3087,     0,
       0,  3088,     0,     0,     0,     0,     0,     0,  3089,     0,
    3090,     0,  3091,     0,     0,  3092,     0,     0,     0,     0,
    2826,     0,     0,     0,     0,  3094,  3095,     0,  3096,     0,
    3097,     0,  3098,  3099,  3100,     0,  3101,  3102,     0,  3104,
       0,  3106,     0,  3108,  3109,  3110,     0,     0,  3112,  3113,
    3114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2850,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3151,     0,     0,
       0,  3153,  3154,     0,     0,     0,  3155,     0,  3156,  3157,
       0,  3158,  3159,     0,     0,     0,  3161,     0,     0,  3163,
    3164,  3165,     0,  3166,  3167,  3168,  3169,     0,     0,  3170,
    3171,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,   212,   212,   212,     0,     0,     0,     0,     0,     0,
       0,     0,  3195,     0,   226,     0,     0,   230,  3196,  3197,
    3198,   238,     0,     0,  3199,  3200,     0,     0,  3202,  3203,
       0,     0,  3204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,     0,     0,  3217,  3218,     0,  3219,
       0,  3220,     0,     0,  3222,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3231,     0,  3232,  3233,  3234,     0,
       0,     0,     0,     0,     0,  3239,  3240,  3241,     0,     0,
       0,     0,  3245,  3246,  3247,     0,     0,  2970,     0,  3251,
    3252,     0,     0,  3255,     0,     0,     0,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
       0,     0,     0,     1,     0,     2,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,    21,     0,     0,     0,
       0,     0,     0,    24,     0,    25,     0,    27,   186,   187,
     188,   219,   189,    33,     0,   214,   191,     0,     0,     0,
       0,   192,     0,   193,   194,     0,     0,     0,     0,     0,
       0,     0,   212,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3085,     0,     0,
      50,    51,    52,    53,    54,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,     0,
     195,     0,     0,     0,     0,     0,   614,   614,    58,     0,
     196,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   689,   692,   689,   689,   695,   689,
     697,   689,   699,     0,     0,     0,     0,   753,   754,   755,
     689,   758,   759,   760,   761,   762,   763,   764,   765,     0,
      63,     0,     0,   770,   772,     0,     0,     0,   689,   795,
    3152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,     0,    65,     0,     0,     0,     0,
       0,   281,     0,     0,     0,   238,     0,   808,   809,   810,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
     238,   238,   238,     0,     0,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   689,   614,     0,   212,     0,   212,
     212,     0,     0,   689,   614,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    79,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    82,     0,     0,     0,     0,
    1015,  1015,   614,  1023,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,   104,   105,   106,   107,   108,   109,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1015,  1015,  1015,  1015,  1015,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,  1015,   689,     0,     0,     0,
       0,     0,     0,     0,   130,     0,     0,     0,     0,     0,
       0,  1015,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,     0,     0,     0,     0,   689,   689,  1189,
       0,     0,     0,     0,   689,   689,   689,   689,   689,   689,
     689,   689,   689,   689,   689,   689,   689,   689,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,     0,     0,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1015,  1015,   614,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,
    1015,  1015,  1015,  1015,     0,  1015,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1372,
       0,     0,     0,     0,     0,  1378,     0,     0,  1382,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   689,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1421,     0,     0,     0,     0,   614,
    1427,  1429,   689,   689,  1432,  1433,  1434,  1435,  1436,   689,
    1438,  1439,  1440,  1441,  1442,     0,  1445,  1446,  1447,  1448,
       0,   689,   689,  1454,     0,     0,  1457,  1458,  1459,  1460,
    1461,  1462,  1463,  1464,  1465,   689,  1467,  1468,  1469,  1470,
    1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,   689,
     689,   689,   689,   689,  1485,  1486,  1487,  1488,  1489,     0,
       0,   238,   238,  1494,  1495,  1496,  1497,  1498,  1499,  1500,
    1501,  1502,  1503,  1504,  1505,  1506,   689,  1508,  1509,  1510,
    1511,  1512,  1513,   689,   689,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   689,
     689,   689,  1519,   689,   689,     0,   689,   689,   689,   689,
     238,     0,   614,     0,   614,  1537,   689,   689,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,   689,   689,
     689,   689,   689,     0,     0,   238,   238,     0,     0,   238,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     689,     0,     0,   689,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1596,     0,  1598,     0,     0,     0,  1602,
    1603,  1604,  1605,     0,     0,     0,     0,     0,     0,     0,
    1613,     0,  1615,  1616,  1617,  1619,  1620,  1622,  1624,  1625,
    1626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1642,     0,   689,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1652,  1653,
    1654,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,  1670,  1671,     0,     0,     0,     0,     0,
       0,   238,  1678,     0,  1679,  1680,  1682,  1684,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   689,     0,     0,     0,     0,     0,     0,     0,
       0,  1706,   689,     0,   689,     0,     0,  1712,     0,     0,
       0,   689,  1717,     0,     0,     0,   689,   689,   689,   238,
     689,  1726,     0,  1728,     0,     0,   689,   238,     0,   689,
     689,   689,   689,   689,     0,     0,     0,   238,     0,   614,
     238,     0,     0,     0,     0,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1015,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,  1910,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   689,     0,     0,
     689,     0,  1943,  1944,  1945,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       2,   183,   184,   185,     0,     0,     0,     0,     0,     0,
       0,     0,  1534,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,   689,     0,     0,     0,     0,    24,     0,
      25,     0,    27,   186,   187,   188,   219,  1535,    33,     0,
     190,   191,     0,     0,     0,     0,   192,     0,   193,   194,
       0,     0,     0,     0,     0,   614,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    53,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   195,     0,     0,     0,     0,
       0,  2114,     0,    58,     0,   196,     0,     0,     0,     0,
       0,     0,     0,  2121,  2122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2138,     0,   689,     0,     0,     0,     0,     0,   614,
       0,     0,     0,     0,     0,    63,   689,  2147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2163,  2164,   689,   689,  2167,
    2168,  2169,     0,     0,     0,     0,     0,     0,    64,     0,
      65,     0,     0,     0,     0,  2179,     0,  2180,  2181,  2182,
    2183,  2184,     0,  2185,  2186,     0,     0,     0,     0,   689,
     689,     0,     0,     0,     0,     0,  2197,   238,     0,     0,
    2199,  2200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2217,     0,     0,  2220,
       0,     0,     0,     0,   689,     0,     0,     0,     0,    78,
      79,     0,     0,     0,     0,     0,   689,  2227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
     238,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   689,     0,     0,     0,     0,  2243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
       0,     0,     0,     0,     0,  2261,  2262,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,    93,     0,
       0,     0,     0,  2276,     0,     0,     0,     0,    96,    97,
     197,   198,   199,   200,   201,   202,     0,     0,   203,   204,
     205,   206,   207,   208,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,     0,     0,   146,   146,   146,     0,   130,
     614,   689,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,   183,   184,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,    24,     0,    25,     0,    27,   186,   187,
     188,   219,   189,    33,     0,   190,   191,     0,     0,     0,
       0,   192,     0,   193,   194,     0,     0,     0,     0,     0,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,     0,
      50,    51,    52,    53,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     195,     0,     0,     0,     0,     0,     0,     0,    58,     0,
     196,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,  2541,     0,   612,
     612,  2545,  2547,    64,     0,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2559,
    2561,     0,     0,     0,     0,     0,     0,   688,     0,   688,
     688,     0,   688,     0,   688,  2575,  2576,  2577,  2578,  2579,
       0,     0,   688,   688,     0,     0,     0,     0,     0,     0,
       0,     0,   689,     0,     0,   689,     0,     0,     0,   791,
       0,   688,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,     0,     0,     0,     0,  2603,     0,     0,     0,
       0,     0,   689,     0,   689,     0,   689,     0,   689,     0,
       0,     0,  2614,  2615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2620,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   688,   612,     0,
     146,   791,   146,   146,     0,     0,   688,   956,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2644,     0,     0,
       0,     0,     0,   689,     0,     0,     0,     0,     0,   689,
     689,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,   197,   198,   199,   200,   201,
     202,     0,     0,   203,   204,   205,   206,   207,   208,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   612,   612,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2545,     0,     0,     0,  2545,   612,   612,   612,   612,
     612,   612,   612,   612,   612,   612,   612,   612,   612,   688,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1537,  1537,  1537,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2837,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     689,  2859,     0,     0,     0,     0,  2861,     0,     0,     0,
     688,   688,   688,     0,     0,     0,     0,   688,   688,   688,
     688,   688,   688,   688,   688,   688,   688,   688,   688,   688,
     688,     0,     0,   689,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   791,   791,   791,     0,
     791,   791,   791,   791,   791,   791,   791,   791,   791,   791,
     791,   791,   791,   791,     0,     0,   238,     0,     0,  2545,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1537,     0,
    1537,     0,     0,  1537,  1537,     0,     0,     0,  2994,  2995,
    2996,  2997,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3009,     0,  3011,
       0,     0,     0,     0,     0,     0,     0,     0,   689,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     956,   956,   956,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   956,   956,   956,   956,   956,   956,
     956,   956,   956,   956,   956,   956,   956,     0,   956,  1537,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3103,     0,  3105,
     181,     0,     0,     0,     0,     0,   689,     0,     0,     0,
       0,   688,     0,     0,     0,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,   612,   688,     0,   688,   688,     0,     0,     0,
       0,     0,   688,     0,   689,     0,     0,   689,     0,     0,
       0,     0,     0,     0,   688,   688,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   688,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   688,   688,   688,   688,   688,     0,     0,     0,
       0,     0,     0,     0,     0,  3201,     0,     0,     0,     0,
       0,     0,     0,   689,     0,     0,     0,     0,     0,   688,
       0,     0,   181,     0,     0,     0,   688,   688,     0,     0,
       0,  3221,     0,     0,     0,   689,     0,     0,     0,     0,
       0,     0,   688,   688,   688,     0,   688,   688,     0,   688,
     688,   688,   688,     0,     0,   612,     0,   612,     0,   688,
     688,   612,   612,   612,   612,   612,   612,   612,   612,   612,
     612,   688,   688,   688,   688,   688,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   688,     0,     0,   688,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,   481,     0,     0,     0,     0,   634,   634,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   688,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   691,     0,   691,   691,     0,
     691,     0,   691,     0,     0,     0,     0,     0,     0,     0,
     691,   691,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   691,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   688,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   688,     0,   688,     0,     0,
       0,     0,     0,     0,   688,     0,     0,     0,     0,   688,
     688,   688,     0,   688,     0,     0,     0,     0,     0,   688,
       0,     0,   688,   688,   688,   688,   688,     0,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   691,   634,     0,     0,     0,
       0,     0,     0,   924,   691,   961,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   634,   634,   634,  1024,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   634,   634,   634,   634,   634,   634,
     634,   634,   634,   634,   634,   634,   634,   691,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     688,     0,   634,   688,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   688,     0,   691,   691,
     691,     0,     0,   633,   633,   691,   691,   691,   691,   691,
     691,   691,   691,   691,   691,   691,   691,   691,   691,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   612,     0,
       0,   690,     0,   693,   694,     0,   696,     0,   698,     0,
       0,     0,     0,     0,     0,     0,   756,   757,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   794,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   851,   854,     0,     0,     0,   688,     0,     0,     0,
     927,   958,   612,     0,     0,     0,     0,     0,     0,   688,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     688,   688,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     2,   183,   184,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   688,   688,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,    24,     0,    25,     0,    27,   186,
     187,   188,   219,  1535,    33,     0,   190,   191,     0,     0,
       0,     0,   192,     0,   193,   194,     0,   688,   634,   634,
     634,     0,     0,     0,     0,     0,     0,     0,     0,   688,
       0,     0,   634,   634,   634,   634,   634,   634,   634,   634,
     634,   634,   634,   634,   634,     0,   634,     0,     0,     0,
       0,     0,     0,     0,   688,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    54,     0,     0,     0,   691,
       0,     0,     0,     0,     0,     0,   924,     0,     0,     0,
       0,   195,  1405,     0,     0,     0,     0,     0,     0,    58,
       0,   196,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,     0,     0,
     634,   691,     0,   691,   691,     0,     0,     0,     0,     0,
     691,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   691,   691,     0,     0,     0,     0,     0,     0,
       0,    63,     0,     0,     0,     0,   691,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     691,   691,   691,   691,   691,     0,     0,     0,     0,     0,
    1490,  1491,     0,     0,    64,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   691,     0,     0,
       0,     0,     0,     0,   691,   691,     0,     0,     0,     0,
       0,     0,     0,   612,   688,     0,     0,     0,     0,     0,
     691,   691,   691,     0,   691,   691,     0,   691,   691,   691,
     691,     0,     0,   634,     0,   634,     0,   691,   691,   634,
     634,   634,   634,   634,   634,   634,   634,   634,   634,   691,
     691,   691,   691,   691,     0,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   691,     0,     0,   691,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   691,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,   197,   198,   199,   200,
     201,   202,     0,     0,   203,   204,   205,   206,   207,   208,
     209,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   691,   116,     0,     0,     0,     0,     0,
       0,     0,     0,   691,     0,   691,     0,     0,     0,     0,
       0,     0,   691,     0,  1718,  1719,  1720,   691,   691,   691,
       0,   691,     0,  1727,     0,  1729,  1730,   691,     0,     0,
     691,   691,   691,   691,   691,   130,     0,     0,     0,     0,
     634,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   634,     0,     0,
       0,     0,     0,     0,     0,   688,     0,     0,   688,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   633,  1428,     0,  1430,
    1431,     0,     0,     0,     0,     0,  1437,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1452,  1453,
       0,     0,     0,     0,     0,   688,     0,   688,     0,   688,
       0,   688,  1466,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1480,  1481,  1482,  1483,
    1484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1507,     0,     0,     0,     0,  1911,     0,
    1514,  1515,     0,     0,     0,     0,   688,     0,     0,     0,
       0,     0,   688,   688,     0,     0,  1516,  1517,  1518,     0,
    1520,  1521,     0,  1523,  1524,  1525,  1526,     0,     0,  1532,
       0,  1533,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   924,     0,   691,     0,
       0,   691,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1428,     0,     0,
    1533,     0,     0,     0,     1,     0,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,   691,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,    27,   186,
     187,   188,     0,   189,    33,  1643,   214,   191,     0,     0,
       0,     0,   192,     0,   193,   194,   634,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1697,
       0,    50,    51,    52,    53,    54,     0,     0,     0,  1707,
       0,  1709,     0,     0,     0,     0,     0,     0,  1716,     0,
       0,   195,     0,  1721,  1722,  1723,     0,  1725,     0,     0,
       0,   196,     0,  1731,     0,     0,  1734,  1735,  1736,  1737,
    1738,     0,     0,   688,     0,     0,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   691,     0,     0,     0,     0,     0,
     634,     0,     0,     0,     0,     0,   688,   691,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   691,   691,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     691,   691,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   691,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,   691,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   691,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   183,   184,   185,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   688,     0,     0,     0,    81,    82,     0,     0,     0,
       0,    25,     0,    27,   186,   187,   188,     0,   189,    33,
     634,   190,   191,     0,  1940,     0,     0,   192,     0,   193,
     194,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,   104,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1996,     0,     0,     0,   116,     0,    50,    51,    52,    53,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   195,     0,     0,     0,
       0,     0,  2032,     0,     0,     0,   196,     0,     0,   688,
       0,   634,   691,     0,     0,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   688,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   688,     0,     0,
     688,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
       0,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2140,     0,     0,     0,     0,     0,   688,     0,     0,     0,
       0,     0,     0,  2145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   688,     0,
       0,     0,     0,     0,  2165,  2166,     0,     0,     0,     0,
      78,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2191,  2192,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,   197,   198,   199,   200,   201,   202,     0,     0,   203,
     204,   205,   206,   207,   208,   209,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,   691,     0,     0,   691,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   691,     0,   691,     0,   691,     0,   691,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   691,     0,     0,  2314,  2315,     0,
     691,   691,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   362,     0,     0,     0,     0,     0,     0,
       1,     0,     2,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
      24,     0,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,    37,     0,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   691,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    65,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,   691,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2583,
       0,     0,  2584,     0,    73,    74,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
      77,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2607,
       0,  2608,     0,  2609,     0,  2610,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2645,     0,     0,     0,     0,     0,  2650,  2651,     0,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
      93,    94,     0,     0,    95,     0,     0,     0,     0,   691,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
     104,   105,   106,   107,   108,   109,   110,     0,   111,     0,
       0,     0,   112,     0,   113,   114,     0,     0,     0,   115,
     116,     0,   117,     0,     0,     0,     0,     0,     0,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,     0,     0,     0,     0,
     120,   121,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   691,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   691,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   691,     0,     1,   691,     2,
     928,   929,   930,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,   931,   496,   932,     0,     0,     0,  2858,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    24,     0,    25,
       0,    27,   186,   187,   188,   219,   852,    33,   933,   214,
     191,   934,     0,   499,   691,   192,   935,   193,   194,     0,
    2870,     0,     0,     0,     0,     0,     0,   936,     0,     0,
       0,     0,     0,     0,     0,     0,   691,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,   500,    52,    53,    54,   501,
     502,   503,   504,   505,   506,   507,   508,     0,   509,     0,
     510,   511,   512,   513,   514,   515,   516,     0,   517,   518,
       0,     0,    58,     0,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,     0,
       0,     0,     0,   533,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,    64,   547,    65,
     548,   549,   550,   551,   552,  3017,     0,     0,     0,     0,
       0,   553,     0,     0,     0,   903,   904,   905,     0,     0,
     554,   555,   556,   557,   906,   907,   908,   909,   558,   910,
     559,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   560,   561,   562,
     563,     0,     0,     0,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,     0,     0,    78,    79,
     911,     0,     0,   912,   913,   914,   915,     0,   916,   917,
     576,   577,   937,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   938,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3142,     0,     0,     0,     0,     0,     0,
       0,     0,   578,   579,   580,   581,    83,   939,    85,    86,
     940,    88,    89,    90,    91,    92,     0,    93,     0,   582,
     583,  3160,   941,     0,  3162,     0,     0,    96,    97,   942,
     943,   944,   945,   946,   947,     0,     0,   948,   949,   950,
     951,   952,   953,   954,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   598,     0,
       0,     0,     0,     0,     0,     0,     0,   599,   600,   601,
     602,     0,   603,   604,     0,   919,   920,   921,   605,   606,
    3205,   922,     0,   923,   607,   608,   609,     1,     0,     2,
     928,   929,   930,     0,     0,     0,     0,     0,   130,     0,
       0,     0,  3223,     0,     0,     0,     0,     0,    12,     0,
       0,   495,   496,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    24,     0,    25,
       0,    27,   186,   187,   188,   219,   852,    33,   498,   214,
     191,     0,     0,   499,     0,   192,     0,   193,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,   500,    52,    53,    54,   501,
     502,   503,   504,   505,   506,   507,   508,     0,   509,     0,
     510,   511,   512,   513,   514,   515,   516,     0,   517,   518,
       0,     0,    58,     0,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,     0,
       0,     0,     0,   533,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,    64,   547,    65,
     548,   549,   550,   551,   552,     0,     0,     0,     0,     0,
       0,   553,     0,     0,     0,     0,     0,     0,     0,     0,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     559,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   560,   561,   562,
     563,     0,     0,     0,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,     0,     0,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   578,   579,   580,   581,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,    93,     0,   582,
     583,     0,     0,     0,     0,     0,     0,    96,    97,   942,
     943,   944,   945,   946,   947,     0,     0,   948,   949,   950,
     951,   952,   953,   954,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   598,     0,
       0,     0,     0,     0,     0,     0,     0,   599,   600,   601,
     602,     0,   603,   604,     0,     0,     0,     0,   605,   606,
       0,     0,     0,     0,   607,   608,   609,     1,     0,     2,
     491,   492,   493,     0,     0,     0,   494,     0,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,   495,   496,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    24,     0,    25,
       0,    27,   186,   187,   188,   219,   497,    33,   498,   190,
     191,     0,     0,   499,     0,   192,     0,   193,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,   500,    52,    53,    54,   501,
     502,   503,   504,   505,   506,   507,   508,     0,   509,     0,
     510,   511,   512,   513,   514,   515,   516,     0,   517,   518,
       0,     0,    58,     0,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,     0,
       0,     0,     0,   533,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,    64,   547,    65,
     548,   549,   550,   551,   552,     0,     0,     0,     0,     0,
       0,   553,     0,     0,     0,     0,     0,     0,     0,     0,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     559,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   560,   561,   562,
     563,     0,     0,     0,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,     0,     0,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   578,   579,   580,   581,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,    93,     0,   582,
     583,     0,     0,     0,     0,     0,     0,    96,    97,   584,
     585,   586,   587,   588,   589,     0,     0,   590,   591,   592,
     593,   594,   595,   596,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   598,     0,
       0,     0,     0,     0,     0,     0,     0,   599,   600,   601,
     602,     0,   603,   604,     0,     0,     0,     0,   605,   606,
       0,     0,     0,     0,   607,   608,   609,     1,     0,     2,
     491,   492,   493,     0,     0,     0,  1528,     0,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,   495,   496,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    24,     0,    25,
       0,    27,   186,   187,   188,   219,  1529,    33,   498,   190,
     191,     0,     0,   499,     0,   192,     0,   193,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,   500,    52,    53,    54,   501,
     502,   503,   504,   505,   506,   507,   508,     0,   509,     0,
     510,   511,   512,   513,   514,   515,   516,     0,   517,   518,
       0,     0,    58,     0,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,     0,
       0,     0,     0,   533,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,    64,   547,    65,
     548,   549,   550,   551,   552,     0,     0,     0,     0,     0,
       0,   553,     0,     0,     0,     0,     0,     0,     0,     0,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     559,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   560,   561,   562,
     563,     0,     0,     0,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,     0,     0,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   578,   579,   580,   581,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,    93,     0,   582,
     583,     0,     0,     0,     0,     0,     0,    96,    97,   584,
     585,   586,   587,   588,   589,     0,     0,   590,   591,   592,
     593,   594,   595,   596,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   598,     0,
       0,     0,     0,     0,     0,     0,     0,   599,   600,   601,
     602,     0,   603,   604,     0,     0,     0,     0,   605,   606,
       0,     0,     0,     0,   607,   608,   609,     1,     0,     2,
     491,   492,   493,     0,     0,     0,     0,     0,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,   495,   496,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    24,     0,    25,
       0,    27,   186,   187,   188,   219,   852,    33,   498,   190,
     191,     0,     0,   499,     0,   192,     0,   193,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,   500,    52,    53,    54,   501,
     502,   503,   504,   505,   506,   507,   508,     0,   509,     0,
     510,   511,   512,   513,   514,   515,   516,     0,   517,   518,
       0,     0,    58,     0,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,     0,
       0,     0,     0,   533,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,    64,   547,    65,
     548,   549,   550,   551,   552,     0,     0,     0,     0,     0,
       0,   553,     0,     0,     0,     0,     0,     0,     0,     0,
     554,   555,   556,   557,     0,     0,     0,     0,   558,     0,
     559,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   560,   561,   562,
     563,     0,     0,     0,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,     0,     0,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   578,   579,   580,   581,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,    93,     0,   582,
     583,     0,     0,     0,     0,     0,     0,    96,    97,   584,
     585,   586,   587,   588,   589,     0,     0,   590,   591,   592,
     593,   594,   595,   596,   597,     0,     0,     0,     0,     0,
       1,     0,     2,   928,   929,   930,     0,   116,   598,     0,
       0,     0,     0,     0,     0,     0,     0,   599,   600,   601,
     602,    12,   603,   604,   495,   496,     0,     0,   605,   606,
       0,     0,     0,     0,   607,   608,   609,     0,     0,     0,
       0,     0,    25,     0,    27,   186,   187,   188,   130,   852,
      33,   498,   214,   191,     0,     0,   499,     0,   192,     0,
     193,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,   500,    52,
      53,    54,   501,   502,   503,   504,   505,   506,   507,   508,
       0,   509,     0,   510,   511,   512,   513,   514,   515,   516,
       0,   517,   518,     0,     0,     0,     0,   519,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,     0,     0,     0,     0,   533,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
      64,   547,    65,   548,   549,   550,   551,   552,     0,     0,
       0,     0,     0,     0,   553,     0,     0,     0,     0,     0,
       0,     0,     0,   554,   555,   556,   557,     0,     0,     0,
       0,   558,     0,   559,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     560,   561,   562,   563,     0,     0,     0,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,     0,
       0,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   576,   577,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   578,   579,   580,   581,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
      93,     0,   582,   583,     0,     0,     0,     0,     0,     0,
      96,    97,   942,   943,   944,   945,   946,   947,     0,     0,
     948,   949,   950,   951,   952,   953,   954,   597,     0,     0,
       0,     0,     0,     1,     0,     2,   491,   492,   493,     0,
     116,   598,     0,     0,     0,     0,     0,     0,     0,     0,
     599,   600,   601,   602,    12,   603,   604,   495,   496,     0,
       0,   605,   606,     0,     0,     0,     0,   607,   608,   609,
       0,     0,     0,     0,     0,    25,     0,    27,   186,   187,
     188,   130,   852,    33,   498,   190,   191,     0,     0,   499,
       0,   192,     0,   193,   194,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,   500,    52,    53,    54,   501,   502,   503,   504,   505,
     506,   507,   508,     0,   509,     0,   510,   511,   512,   513,
     514,   515,   516,     0,   517,   518,     0,     0,     0,     0,
     519,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,     0,     0,     0,     0,   533,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,    64,   547,    65,   548,   549,   550,   551,
     552,     0,     0,     0,     0,     0,     0,   553,     0,     0,
       0,     0,     0,     0,     0,     0,   554,   555,   556,   557,
       0,     0,     0,     0,   558,     0,   559,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   560,   561,   562,   563,     0,     0,     0,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,     0,     0,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   576,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   578,   579,
     580,   581,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,    93,     0,   582,   583,     0,     0,     0,
       0,     0,     0,    96,    97,   584,   585,   586,   587,   588,
     589,     0,     0,   590,   591,   592,   593,   594,   595,   596,
     597,     0,     0,     0,     0,     0,     1,     0,     2,   491,
     492,  1800,     0,   116,   598,     0,     0,     0,     0,     0,
       0,     0,     0,   599,   600,   601,   602,    12,   603,   604,
     495,   496,     0,     0,   605,   606,     0,     0,     0,     0,
     607,   608,   609,     0,     0,     0,     0,     0,    25,     0,
      27,   186,   187,   188,   130,   852,    33,   498,   190,   191,
       0,     0,   499,     0,   192,     0,   193,   194,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,   500,    52,    53,    54,   501,   502,
     503,   504,   505,   506,   507,   508,     0,   509,     0,   510,
     511,   512,   513,   514,   515,   516,     0,   517,   518,     0,
       0,     0,     0,   519,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,     0,     0,
       0,     0,   533,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,    64,   547,    65,   548,
     549,   550,   551,   552,     0,     0,     0,     0,     0,     0,
     553,     0,     0,     0,     0,     0,     0,     0,     0,   554,
     555,   556,   557,     0,     0,     0,     0,   558,     0,   559,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   560,   561,   562,   563,
       0,     0,     0,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,     0,     0,    78,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   576,
     577,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   578,   579,   580,   581,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,    93,     0,   582,   583,
       0,     0,     0,     0,     0,     0,    96,    97,   584,   585,
     586,   587,   588,   589,     0,     0,   590,   591,   592,   593,
     594,   595,   596,   597,     0,     0,     0,     0,     0,     1,
       0,     0,   668,   669,   670,     0,   116,   598,     0,     0,
       0,     0,     0,     0,     0,     0,   599,   600,   601,   602,
       0,   603,   604,   495,   496,     0,     0,   605,   606,     0,
       0,     0,     0,   607,   608,   609,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,   130,   671,    33,
     498,     0,     0,     0,     0,   499,     0,     0,     0,   193,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   672,     0,     0,
       0,   501,   502,   503,   504,   505,   506,   507,   508,     0,
     509,     0,   510,   511,   512,   513,   673,   515,   516,     0,
     517,   518,     0,     0,     0,     0,   674,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,     0,     0,     0,     0,   533,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,     0,
     547,     0,   548,   549,   550,   551,   552,     0,     0,     0,
       0,     0,     0,   553,     0,     0,     0,     0,     0,     0,
       0,     0,   554,   555,   556,   557,     0,     0,     0,     0,
     558,     0,   559,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   560,
     561,   562,   563,     0,     0,     0,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   576,   577,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   578,   579,   580,   581,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,   582,   583,     0,     0,     0,     0,     0,     0,     0,
       0,   675,   676,   677,   678,   679,   680,     0,     0,   681,
     682,   683,   684,   685,   686,   687,   597,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     598,     0,     0,     0,     0,     0,     0,     0,     0,   599,
     600,   601,   602,     0,   603,   604,     0,     0,     0,     0,
     605,   606,     0,     0,     0,     0,   607,   608,   609,     1,
       0,     2,     3,     4,     5,     0,     0,     0,     0,     0,
     130,     0,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,     0,     0,    24,
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,    37,     0,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
       0,    65,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,    71,     0,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,     0,    93,
      94,     0,     0,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,   104,
     105,   106,   107,   108,   109,   110,     0,   111,     0,     0,
       0,   112,     0,   113,   114,     0,     0,     0,   115,   116,
       0,   117,     1,     0,     0,   668,   669,   670,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,     0,   495,   496,     0,   120,
     121,     0,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,   671,    33,   498,     0,     0,     0,     0,   499,     0,
       0,     0,   193,   194,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     672,     0,     0,     0,   501,   502,   503,   504,   505,   506,
     507,   508,     0,   509,     0,   510,   511,   512,   513,   673,
     515,   516,     0,   517,   518,     0,     0,     0,     0,   674,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,     0,     0,     0,     0,   533,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,     0,   547,     0,   548,   549,   550,   551,   552,
       0,     0,     0,     0,     0,     0,   553,     0,     0,     0,
       0,     0,     0,     0,     0,   554,   555,   556,   557,     0,
       0,     0,     0,   558,     0,   559,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   560,   561,   562,   563,     0,     0,     0,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   576,   577,   926,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   578,   579,   580,
     581,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   582,   583,     0,     0,     0,     0,
       0,     0,     0,     0,   675,   676,   677,   678,   679,   680,
       0,     0,   681,   682,   683,   684,   685,   686,   687,   597,
       0,     0,     0,     0,     0,     1,     0,     0,   668,   669,
     670,     0,     0,   598,     0,     0,     0,     0,     0,     0,
       0,     0,   599,   600,   601,   602,     0,   603,   604,   495,
     496,     0,     0,   605,   606,     0,     0,     0,     0,   607,
     608,   609,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,   130,   671,    33,   498,     0,     0,     0,
       0,   499,     0,     0,     0,   193,   194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   672,     0,     0,     0,   501,   502,   503,
     504,   505,   506,   507,   508,     0,   509,     0,   510,   511,
     512,   513,   673,   515,   516,     0,   517,   518,     0,     0,
       0,     0,   674,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,     0,     0,     0,
       0,   533,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,     0,   547,     0,   548,   549,
     550,   551,   552,     0,     0,     0,     0,     0,     0,   553,
       0,     0,     0,     0,     0,     0,     0,     0,   554,   555,
     556,   557,     0,     0,     0,     0,   558,     0,   559,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   560,   561,   562,   563,     0,
       0,     0,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   576,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     578,   579,   580,   581,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   582,   583,     0,
       0,     0,     0,     0,     0,     0,     0,   675,   676,   677,
     678,   679,   680,     0,     0,   681,   682,   683,   684,   685,
     686,   687,   597,     0,     0,     0,     0,     0,     1,     0,
       0,   668,   669,  1942,     0,     0,   598,     0,     0,     0,
       0,     0,     0,     0,     0,   599,   600,   601,   602,     0,
     603,   604,   495,   496,     0,     0,   605,   606,     0,     0,
       0,     0,   607,   608,   609,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,   130,   671,    33,   498,
       0,     0,     0,     0,   499,     0,     0,     0,   193,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   672,     0,     0,     0,
     501,   502,   503,   504,   505,   506,   507,   508,     0,   509,
       0,   510,   511,   512,   513,   673,   515,   516,     0,   517,
     518,     0,     0,     0,     0,   674,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
       0,     0,     0,     0,   533,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,     0,   547,
       0,   548,   549,   550,   551,   552,     0,     0,     0,     0,
       0,     0,   553,     0,     0,     0,     0,     0,     0,     0,
       0,   554,   555,   556,   557,     0,     0,     0,     0,   558,
       0,   559,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   560,   561,
     562,   563,     0,     0,     0,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,   577,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   183,   184,   966,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    27,   186,   187,   188,     0,   189,    33,
       0,   190,   191,     0,     0,     0,     0,   192,     0,   193,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   578,   579,   580,   581,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     582,   583,     0,     0,     0,     0,     0,     0,     0,     0,
     675,   676,   677,   678,   679,   680,     0,     0,   681,   682,
     683,   684,   685,   686,   687,   597,    50,    51,    52,    53,
      54,     0,     0,     0,     0,     0,     0,     0,     0,   598,
       0,     0,     0,     0,     0,     0,   195,     0,   599,   600,
     601,   602,     0,   603,   604,     0,   196,     0,     0,   605,
     606,     0,     0,     0,     0,   607,   608,   609,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
       0,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,   197,   198,   199,   200,   201,   202,     0,     0,   203,
     204,   205,   206,   207,   208,   209,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    38,   350,   405,   417,   258,   380,   381,   382,   383,
      22,    51,   378,   379,    38,    44,    44,    57,    30,    19,
      20,    50,    38,    50,    33,    18,    20,    67,    68,    20,
      14,    21,    45,    46,   400,   401,     0,     7,    45,    12,
       7,   491,   492,    10,    11,    12,     5,     6,    45,    58,
      12,    40,    12,   123,    14,    19,    21,    66,    47,   217,
     218,   219,    51,    83,    84,    18,    55,    87,    88,    89,
      90,    91,    92,    51,    13,     0,    18,    51,    13,    68,
      51,   217,   218,   219,     5,     6,     5,    47,   102,    57,
      68,    16,    59,    40,    68,   132,    12,    68,    18,    67,
      47,   138,   323,   324,    51,    40,    47,    51,    55,   123,
      51,    51,    47,    12,   114,    14,    51,    12,   102,    57,
      55,    68,   116,   259,    68,   116,   116,    68,    68,    67,
     123,    47,   132,    68,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   155,    43,
      44,   116,   122,    12,   375,    14,    50,   164,   117,   118,
     102,   123,   612,   152,  2702,  2703,  2704,   164,   132,    12,
     199,    12,   199,    14,     3,     4,   150,    18,    12,   150,
     119,   120,    47,   103,   104,    50,   111,    47,   217,    14,
     217,    51,   199,   118,   207,   208,   117,   118,   356,   357,
     358,   359,   199,    22,   220,   152,   150,   132,    68,    13,
      12,    30,    14,    47,    12,    19,    14,   152,   668,   669,
     356,   357,   358,   359,   224,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   112,
     113,   241,    12,   137,   244,    47,    51,   247,   112,   113,
     123,    56,    22,   253,   254,    10,    11,   257,   258,   123,
      30,   102,   262,    68,   264,    12,   185,    14,    18,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   123,   283,   284,    13,    13,   255,   256,   257,
     254,    19,    19,    21,    22,    22,   264,   265,   266,   267,
      12,   269,    51,    52,    53,   199,    18,    19,    57,   112,
     113,    18,   312,   313,   351,   315,   316,   146,    67,    68,
     123,     7,     8,   217,    12,    13,   220,   221,   222,   223,
      18,   368,    12,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   310,    13,    12,   313,   314,   315,   316,    19,
     318,   319,    22,   317,   322,   355,    13,    12,   252,   253,
     254,    12,    19,    18,   384,    22,    12,    12,   377,    14,
      12,  2909,    18,  2911,    19,    12,  2914,  2915,   323,    19,
      20,    18,    22,    12,    12,    14,    12,   416,   416,   416,
      18,    19,   392,   393,   119,   120,   396,    12,    13,   423,
     424,   425,   426,    18,    12,   405,    14,    18,    13,   409,
     410,   378,   379,   413,    19,   455,    18,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   352,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,    51,    52,
      53,   405,   454,    12,    57,    14,   217,   218,   219,    18,
      12,     2,     3,     4,    67,    68,    18,   460,   461,   462,
     463,   464,   429,   430,   431,   432,   433,   434,    10,    11,
     437,   438,   439,   440,   441,   442,   443,    18,   928,   929,
      12,    18,    14,    12,    13,   485,    18,   381,   382,    18,
      10,    11,   942,   943,   944,   945,   946,   947,   948,   949,
     950,   951,   952,   953,   954,   399,   956,   475,   476,   477,
     119,   120,  3050,   481,    12,   483,    14,    12,    13,    13,
      18,    12,   416,    18,    12,    19,    12,    50,    51,    52,
      53,   498,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    12,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     325,    19,   327,    21,   329,   330,    12,    12,    13,   398,
     399,    12,   337,    18,   493,   340,   341,   342,   343,   344,
     345,   278,   279,   280,   281,   282,   283,   284,   285,   286,
      50,    13,    13,    13,   996,   146,   236,    19,    19,    19,
      13,    13,     0,    13,    15,    47,    19,    19,   248,    19,
      21,   376,    19,    13,    21,   380,    13,   257,   258,    19,
     385,   386,    19,    13,    16,    13,   201,   202,    13,    19,
     395,    19,   183,   184,    19,   400,   401,    13,    13,    13,
      12,    13,    14,    19,    19,    19,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      13,    13,    13,    13,    12,   665,    19,    19,    19,    19,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   460,   461,   462,   463,   464,  1148,  1149,
    1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,    13,    13,   356,    13,    13,    13,
      19,    19,    13,    19,    19,    19,   201,   202,    19,    13,
      13,    13,   372,   373,    13,    19,    19,    19,    13,    13,
      19,    13,    13,    13,    19,    19,    12,    19,    19,    19,
      12,   670,   147,    13,   217,   218,   219,   220,    13,    19,
      13,   798,    13,    13,    19,   405,    19,    13,    19,    19,
      13,     4,    13,    19,     7,     8,    19,  1030,    19,  1153,
    1154,  1155,  1156,  1157,  1158,  1151,  1152,   250,    13,   424,
     425,    13,    13,    13,    19,   258,   796,    19,    19,    19,
      12,   207,   208,    13,   199,   200,   201,   202,   271,    19,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    10,    11,    13,   376,   377,    51,    52,    53,
      19,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   485,    13,   398,    45,    46,
      13,   314,    19,   316,   317,   318,    19,    13,   119,   120,
      13,    13,    13,    19,   327,   328,    19,    19,    19,    12,
     333,   334,   335,   336,   356,   357,   358,   359,  1153,  1154,
    1155,  1156,    12,   346,   347,   348,   349,   350,    12,   352,
     353,    12,   355,   323,   324,   384,   385,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,    12,   370,   371,  1151,  1152,  1157,  1158,   400,
     401,    12,    12,    12,    12,    12,  1274,    12,    12,    12,
      12,    12,    12,    12,    12,    12,     4,   115,   121,    12,
     491,   492,    17,   422,    18,   774,   775,    18,    18,   778,
     779,   780,   781,   782,   783,   784,   785,   786,   787,   788,
     789,   790,   791,    14,    14,    18,    18,  1417,    13,   969,
     970,   971,   972,   973,   974,   975,   384,   977,   978,    18,
      13,    13,   982,   983,   984,   985,   986,   987,   988,    18,
     990,   322,   992,    14,   994,   995,   123,   997,   998,   999,
    1000,  1001,    48,    47,  1417,    47,  1006,  1007,  1008,  1009,
      47,   930,    47,    56,   155,    13,    19,   480,    44,    12,
      12,   661,    12,    12,    12,    12,    12,  1027,    12,    12,
    1030,    12,    12,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,   612,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    12,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    12,    12,    12,    12,    12,    12,   928,
     929,    12,    12,    12,    12,    12,  1025,  1360,   201,   202,
      12,    12,    12,   942,   943,   944,   945,   946,   947,   948,
     949,   950,   951,   952,   953,   954,    19,   956,  1165,    12,
      12,    18,    18,    12,    12,    12,    12,    12,    12,    12,
      12,  1591,    12,  1143,    12,  1145,  1146,    12,    12,    12,
      12,    12,    12,    12,    12,   123,    12,    12,    12,    49,
      56,    18,    12,    12,    12,    18,    18,    12,    12,    12,
      16,    12,    12,  1173,    12,    12,  1176,    12,  1178,    12,
    1180,    12,    12,  1183,  1586,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,   839,
      12,    12,    12,    12,    12,  1205,    12,  1207,  1208,  1209,
      12,    12,    12,    12,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,    12,  1222,    12,    12,   865,    12,    12,   868,    12,
      12,    12,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,  1243,  1244,  1245,  1246,    12,    12,    12,
      12,    12,  1252,  1253,  1254,  1255,  1256,  1257,  1258,    12,
      12,    12,    12,    12,  1264,  1265,    12,  1267,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    64,    12,    12,
    1280,    12,  1282,    18,    12,    17,   115,    12,  1288,  1289,
    1290,    18,    12,    12,    12,    12,    12,  1297,  1298,  1299,
    1300,  1301,  1302,    12,  1304,  1305,    12,  1307,  1308,  1309,
    1310,  1311,  1312,    12,  1314,  1315,  1316,  1317,  1318,  1319,
    1320,  1321,    12,    12,  1324,    12,  1326,  1327,    12,  1329,
    1330,  1331,    12,    12,    15,    18,    14,    13,    15,    12,
      52,    15,    13,    12,    19,    13,    18,    13,    18,    13,
      15,    13,    15,    12,    12,    12,  1356,  1357,    19,    12,
    1360,    12,  1362,    12,  1364,  1365,    12,    12,    12,    12,
      12,    12,  1012,    12,  1014,    12,    12,   928,   929,    12,
      12,    12,    12,    12,    12,  1025,    12,    12,    12,    12,
    1030,   942,   943,   944,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,    12,   956,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,   199,    49,    13,    13,   199,    13,    15,    19,    13,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,    19,    19,    19,    19,    19,
      19,    19,  1092,  1093,    19,    19,    19,    19,    19,    19,
      13,    13,    19,    13,    13,    13,    13,  1917,    12,   474,
      13,    52,    58,    19,    19,    12,    15,    19,    19,    19,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,  1141,    12,  1143,    12,    12,    12,    12,    12,   351,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,  1166,  1167,    12,    12,
    1170,    12,    12,    12,    12,    12,    12,    12,    12,  1179,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,    12,    12,    12,
      12,    18,    12,    14,    12,    12,    12,    12,    12,    18,
      12,    53,    58,    13,    15,    18,    15,    13,    15,    64,
      13,    54,    53,    55,    12,    55,    12,   123,   123,    12,
      12,    18,   259,   323,    13,    64,   375,    18,  1149,  1150,
      66,    19,    19,    19,    19,    13,    19,   446,    13,    19,
      13,    13,   123,    13,   123,    19,    50,    13,    19,    13,
      19,    19,    19,  1660,    19,    13,    19,    19,    19,   471,
    1270,    13,    19,    19,    13,    13,    19,    13,    19,    13,
     416,    13,    19,  1283,    19,    13,    19,   489,    19,    19,
      13,    13,  1292,    19,    13,    19,    21,    12,    19,  1659,
      13,    19,    19,    19,  2012,    19,    50,    19,    19,    19,
      19,  2019,    19,    19,    19,    19,  1676,    19,    19,    19,
      19,    13,    19,    12,    19,    19,    19,    12,    12,    19,
      13,    19,    19,    19,    13,    64,    12,    19,    19,    19,
    1340,    19,    19,    13,    13,    19,    13,    19,  1348,    47,
    1286,    19,    13,    19,    19,    19,    19,    19,  1358,    19,
    1360,  1361,    19,    19,    19,    19,  1366,    19,    19,    19,
      19,    19,    19,    13,    13,    19,    19,    19,    19,    50,
     447,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      13,    13,    13,  1753,  1754,  1755,  1756,    13,  1758,    13,
    1760,    13,    13,    21,    19,    13,  1766,  1767,  1768,    19,
      19,  1771,  1772,  1773,  1774,    19,  1776,    19,  1778,    19,
    1780,    19,    19,  1783,  1784,  1785,  1786,    13,    13,    19,
    1790,    15,    12,  1793,    12,    12,    12,    19,    13,    13,
      19,    13,    12,  1803,    13,  1805,    19,    13,    19,  1809,
    1810,    19,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,    19,  1825,    19,    13,    13,    19,
      13,    15,    13,    13,  1834,  1835,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    47,  1856,  1857,  1858,  1859,
      13,    19,    13,  1863,  1864,  1865,  1866,    19,    13,    13,
      13,    13,    13,  1873,  1874,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,    13,    13,    13,    13,    13,    13,
      13,  1891,  1892,  1893,    50,  1895,  1896,    19,  1898,  1899,
      19,    13,  1902,    13,  1904,    13,    13,    13,    19,    13,
      13,    13,    13,    13,    19,  1915,    13,    50,    13,    13,
      19,    19,   123,    19,  1924,  1925,    19,    19,    19,  1929,
      19,    19,    19,  1933,    19,    19,    19,    19,    13,    19,
      19,    19,    13,    13,    13,    13,    19,    19,    13,  1949,
      13,  1951,    19,    13,    13,    13,    13,    13,    19,    13,
      50,    47,    13,    13,    19,  1965,    19,    19,    13,    13,
      13,    13,    13,    13,    13,   132,    13,   132,   132,    13,
    1980,    19,  1982,    19,    19,    13,    13,  1987,    19,    19,
      19,    13,    13,  1993,    19,    19,    19,  1997,  1998,    19,
    2000,  2001,  2002,    19,  2004,  2005,    19,    19,  2008,  2009,
      19,  2011,    19,    19,    19,    19,    15,    15,    13,    15,
      66,  2021,  2022,    13,    13,  2025,    19,  2027,  2028,  2029,
      13,    19,    13,    13,    13,  2035,    13,    13,  2038,    13,
    2040,    19,    13,    18,  2044,  2045,    19,  2047,    13,    19,
      19,    13,    13,  2053,    13,    13,  2056,    21,  2058,    19,
    2060,  2061,  2062,    19,    13,    19,    19,    19,    19,    13,
     132,  2071,  2072,    19,    19,  2075,    19,    19,    13,    13,
    2080,  2081,  2082,  2083,  2084,  2085,    13,  2087,  2088,  2089,
      19,  2091,  2092,  2093,  2094,  2095,    13,    19,  2098,  2099,
    2100,  2101,    13,  2103,    19,    19,    19,    13,    13,    13,
      13,   491,   492,    13,    13,   132,  1163,    19,    19,    50,
    2468,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,  2141,    19,    13,    19,    19,    19,    19,    19,    13,
      19,    13,    19,    13,    13,    13,    19,    13,    19,    13,
      13,    13,    19,    13,    13,   386,    21,    13,    19,    13,
      13,    19,    19,    13,    13,    13,    13,    19,    19,    13,
     387,  1159,    13,    19,    19,    13,    19,    19,    13,    19,
      19,    13,    19,    19,    13,    19,    19,    13,    13,    13,
      13,    19,    13,    13,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,    19,    13,
      13,    19,    19,    13,    19,    13,    13,    19,  1868,    50,
    2267,  2268,   612,    19,    19,    19,    19,    19,    19,    19,
      19,    50,  2242,    50,    13,    19,    19,    19,    13,    19,
      21,    19,    19,    19,    13,    19,    19,    19,    19,    19,
      13,    19,    19,    19,    19,    19,  2266,    19,    19,    19,
      19,    19,    13,    13,    13,    13,    13,    13,    21,    21,
     389,  1161,    13,    13,    19,    19,    19,    19,   668,   669,
    1930,  1931,  1932,    19,    19,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,    19,
      19,    13,    19,    13,    19,    19,    13,    13,    19,  2319,
      19,  2321,    13,  2323,    19,  2325,    19,    19,    13,    19,
    2330,  2331,    19,  2333,  2334,  2335,  2336,    19,  2338,  2339,
    2340,  2341,    19,    19,    19,  2345,    19,    19,  2348,  2349,
      19,    19,    19,    13,  2354,    19,    19,    19,    19,  2359,
      19,  2361,  2362,  2363,  2364,  2365,  2366,  2367,  2368,    19,
    2370,  2371,  2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,
    2380,  2381,  2382,  2383,    19,  2385,    19,    19,    19,    13,
      19,    19,    19,  2393,    19,    13,    19,  2397,  2398,    19,
      19,    13,    13,    13,    19,    19,    13,  2407,  2408,   391,
      19,    19,    13,    19,    19,    19,    19,  2417,  2418,  2419,
    2420,  2421,    19,  2423,  2424,    13,  2426,  2427,    13,    19,
    2349,  2431,  2432,  2352,  2434,  2435,    19,    13,    19,    13,
      19,    13,    13,   390,  2444,    13,    19,   388,  2448,    19,
    2450,  2451,    19,    19,    13,    13,    19,    19,    19,    13,
    2460,  2461,  2462,    13,    19,  2465,  2466,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,  2477,    13,  2479,
      13,  2481,  2482,    13,  2484,  2485,  2486,  2487,  2488,  2489,
    2490,    13,  2492,  2493,  2494,  2495,  2496,  2497,  2498,  2499,
    2500,    19,  2502,  2503,  2504,  2505,    19,    19,    19,    19,
      13,    13,    13,    19,    13,    19,  2516,  2517,  2518,  2519,
      13,    19,  2522,  2523,    19,    13,    13,    19,    13,    19,
      19,    13,    13,    19,    13,    19,    19,    13,  1160,    19,
    1917,    19,    19,    13,    19,    19,    19,    19,   928,   929,
      19,    19,    19,    19,    19,    19,    19,    13,    13,    13,
      19,    19,   942,   943,   944,   945,   946,   947,   948,   949,
     950,   951,   952,   953,   954,    19,   956,    19,    19,    19,
      19,  2618,    19,    19,    19,    13,    13,    13,    13,    19,
      19,    13,    15,    13,    13,    19,    13,    13,    19,    -1,
      13,    19,    -1,  1162,    19,    19,    13,    19,    19,    19,
      19,    13,    13,    19,    19,    19,    19,    13,  1003,    19,
      19,    19,    19,    13,    19,    19,    19,    19,    19,    13,
      13,    19,    13,    13,    13,    13,    13,    13,   352,    13,
      -1,    13,    13,    -1,    19,    13,    19,    13,    13,    19,
      13,    13,    19,    13,    13,    13,  2656,  2657,    19,  2659,
    2660,    13,  2662,  2663,    19,  2665,  2666,  2667,    19,  2669,
    2670,    13,    19,  2673,    13,    19,    19,    13,  2678,  2679,
    1147,  2681,    19,  2683,    19,  2685,    19,  2687,  2688,  2689,
    2690,  2691,    19,    19,    19,  2695,  2696,  2697,  2698,  2699,
    2700,    13,  2702,  2703,  2704,  2705,  2706,  2707,  2708,    19,
    2710,  2711,  2712,  2713,  2714,    19,  2716,    19,    19,    19,
      19,  2721,  2722,    13,  2724,  2725,  2726,  2727,  2728,  2729,
      13,  2731,  2732,  2733,    19,    13,    -1,  2737,    19,  2739,
      19,  2741,    19,    13,  2744,    13,  2746,  2747,    13,  2749,
      19,    13,    19,  2672,    13,    19,  2756,  2676,  2758,    19,
      13,  2761,  2762,    19,    19,    19,    -1,    19,  1148,  1149,
    1150,    19,    19,    19,    19,    19,  2776,  2777,  2778,  2779,
    2780,    13,    19,    19,    13,    13,  2786,  2787,  2788,    13,
      13,    13,    19,    19,    19,    13,    13,    13,    19,    19,
    2440,    13,    13,    -1,    19,    19,    19,    13,    13,    19,
      19,    19,    19,    13,    13,    19,    19,    19,    19,    13,
      13,    19,    19,    19,    13,    13,    -1,    19,    19,    19,
      13,    -1,    19,    19,    19,    19,    13,    19,    19,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2874,    -1,    -1,  2877,  2878,  2879,
      -1,    -1,    -1,  2883,    -1,  2885,  2886,    -1,    -1,    -1,
      -1,  2891,  2892,    -1,  2894,    -1,  2896,  2897,  2898,  2899,
    2900,  2901,    -1,  2903,  2904,  2905,  2906,  2907,  2908,  2909,
      -1,  2911,    -1,    -1,  2914,  2915,  2916,  2917,  2918,    -1,
      -1,    -1,    -1,    -1,  2924,  2925,    -1,    -1,  2928,    -1,
      -1,    -1,  2932,  2933,  2934,    -1,    -1,  2937,    -1,    -1,
      -1,  2941,  2942,    -1,    -1,  2945,  2946,    -1,    -1,  2949,
      -1,  2951,  2952,    -1,    -1,  2955,  2956,    -1,  2958,    -1,
    2960,  2961,  2962,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2890,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3022,  3023,  3024,  3025,    -1,  3027,  3028,    -1,
      -1,  3031,    -1,    -1,    -1,    -1,    -1,    -1,  3038,    -1,
    3040,    -1,  3042,    -1,    -1,  3045,    -1,    -1,    -1,    -1,
    3050,    -1,    -1,    -1,    -1,  3055,  3056,    -1,  3058,    -1,
    3060,    -1,  3062,  3063,  3064,    -1,  3066,  3067,    -1,  3069,
      -1,  3071,    -1,  3073,  3074,  3075,    -1,    -1,  3078,  3079,
    3080,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2736,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3117,    -1,    -1,
      -1,  3121,  3122,    -1,    -1,    -1,  3126,    -1,  3128,  3129,
      -1,  3131,  3132,    -1,    -1,    -1,  3136,    -1,    -1,  3139,
    3140,  3141,    -1,  3143,  3144,  3145,  3146,    -1,    -1,  3149,
    3150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
      -1,     2,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3172,    -1,    15,    -1,    -1,    18,  3178,  3179,
    3180,    22,    -1,    -1,  3184,  3185,    -1,    -1,  3188,  3189,
      -1,    -1,  3192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,  3206,  3207,    -1,  3209,
      -1,  3211,    -1,    -1,  3214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3224,    -1,  3226,  3227,  3228,    -1,
      -1,    -1,    -1,    -1,    -1,  3235,  3236,  3237,    -1,    -1,
      -1,    -1,  3242,  3243,  3244,    -1,    -1,  2887,    -1,  3249,
    3250,    -1,    -1,  3253,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   146,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    -1,    -1,
      -1,    65,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3027,    -1,    -1,
     124,   125,   126,   127,   128,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,
     144,    -1,    -1,    -1,    -1,    -1,   257,   258,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   285,   286,   287,   288,   289,   290,
     291,   292,   293,    -1,    -1,    -1,    -1,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     204,    -1,    -1,   314,   315,    -1,    -1,    -1,   319,   320,
    3120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,    -1,   239,    -1,    -1,    -1,    -1,
      -1,   352,    -1,    -1,    -1,   356,    -1,   358,   359,   360,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,
     371,   372,   373,    -1,    -1,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   395,   396,    -1,   398,    -1,   400,
     401,    -1,    -1,   404,   405,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   308,   309,   417,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   378,   379,    -1,    -1,    -1,    -1,
     491,   492,   493,   494,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,    -1,   417,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   427,   428,   429,   430,   431,   432,   433,
     434,    -1,    -1,   437,   438,   439,   440,   441,   442,   443,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,
      -1,   612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     661,    -1,    -1,    -1,    -1,    -1,    -1,   668,   669,   670,
      -1,    -1,    -1,    -1,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   839,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   865,    -1,    -1,   868,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   928,   929,   930,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   942,   943,   944,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,    -1,   956,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   970,
      -1,    -1,    -1,    -1,    -1,   976,    -1,    -1,   979,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   989,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1012,    -1,  1014,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1025,    -1,    -1,    -1,    -1,  1030,
    1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,
    1041,  1042,  1043,  1044,  1045,    -1,  1047,  1048,  1049,  1050,
      -1,  1052,  1053,  1054,    -1,    -1,  1057,  1058,  1059,  1060,
    1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,    -1,
      -1,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,
    1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1130,
    1131,  1132,  1133,  1134,  1135,    -1,  1137,  1138,  1139,  1140,
    1141,    -1,  1143,    -1,  1145,  1146,  1147,  1148,  1149,  1150,
    1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,
    1161,  1162,  1163,    -1,    -1,  1166,  1167,    -1,    -1,  1170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1191,    -1,    -1,  1194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1204,    -1,  1206,    -1,    -1,    -1,  1210,
    1211,  1212,  1213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1221,    -1,  1223,  1224,  1225,  1226,  1227,  1228,  1229,  1230,
    1231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1247,    -1,  1249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1259,  1260,
    1261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1283,  1284,  1285,    -1,    -1,    -1,    -1,    -1,
      -1,  1292,  1293,    -1,  1295,  1296,  1297,  1298,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1322,  1323,    -1,  1325,    -1,    -1,  1328,    -1,    -1,
      -1,  1332,  1333,    -1,    -1,    -1,  1337,  1338,  1339,  1340,
    1341,  1342,    -1,  1344,    -1,    -1,  1347,  1348,    -1,  1350,
    1351,  1352,  1353,  1354,    -1,    -1,    -1,  1358,    -1,  1360,
    1361,    -1,    -1,    -1,    -1,  1366,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1417,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1528,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1588,    -1,    -1,
    1591,    -1,  1593,  1594,  1595,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,  1644,    -1,    -1,    -1,    -1,    47,    -1,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    -1,    -1,    -1,    65,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,  1676,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
      -1,  1752,    -1,   152,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1764,  1765,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1792,    -1,  1794,    -1,    -1,    -1,    -1,    -1,  1800,
      -1,    -1,    -1,    -1,    -1,   204,  1807,  1808,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1826,  1827,  1828,  1829,  1830,
    1831,  1832,    -1,    -1,    -1,    -1,    -1,    -1,   237,    -1,
     239,    -1,    -1,    -1,    -1,  1846,    -1,  1848,  1849,  1850,
    1851,  1852,    -1,  1854,  1855,    -1,    -1,    -1,    -1,  1860,
    1861,    -1,    -1,    -1,    -1,    -1,  1867,  1868,    -1,    -1,
    1871,  1872,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1897,    -1,    -1,  1900,
      -1,    -1,    -1,    -1,  1905,    -1,    -1,    -1,    -1,   308,
     309,    -1,    -1,    -1,    -1,    -1,  1917,  1918,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1930,
    1931,  1932,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1942,    -1,    -1,    -1,    -1,  1947,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1968,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2000,
      -1,    -1,    -1,    -1,    -1,  2006,  2007,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,    -1,   417,    -1,
      -1,    -1,    -1,  2024,    -1,    -1,    -1,    -1,   427,   428,
     429,   430,   431,   432,   433,   434,    -1,    -1,   437,   438,
     439,   440,   441,   442,   443,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,     3,     4,     5,    -1,   498,
    2101,  2102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    -1,    -1,
      -1,    65,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,  2348,    -1,   257,
     258,  2352,  2353,   237,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2370,
    2371,    -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,   287,
     288,    -1,   290,    -1,   292,  2386,  2387,  2388,  2389,  2390,
      -1,    -1,   300,   301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2403,    -1,    -1,  2406,    -1,    -1,    -1,   317,
      -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   308,   309,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2440,
      -1,    -1,    -1,    -1,    -1,    -1,  2447,    -1,    -1,    -1,
      -1,    -1,  2453,    -1,  2455,    -1,  2457,    -1,  2459,    -1,
      -1,    -1,  2463,  2464,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2478,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,   396,    -1,
     398,   399,   400,   401,    -1,    -1,   404,   405,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2508,    -1,    -1,
      -1,    -1,    -1,  2514,    -1,    -1,    -1,    -1,    -1,  2520,
    2521,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,    -1,   417,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   427,   428,   429,   430,   431,   432,   433,
     434,    -1,    -1,   437,   438,   439,   440,   441,   442,   443,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   491,   492,   493,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2672,    -1,    -1,    -1,  2676,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2702,  2703,  2704,   612,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2715,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2736,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2751,  2752,    -1,    -1,    -1,    -1,  2757,    -1,    -1,    -1,
     668,   669,   670,    -1,    -1,    -1,    -1,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,    -1,    -1,  2784,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   774,   775,   776,    -1,
     778,   779,   780,   781,   782,   783,   784,   785,   786,   787,
     788,   789,   790,   791,    -1,    -1,  2887,    -1,    -1,  2890,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2909,    -1,
    2911,    -1,    -1,  2914,  2915,    -1,    -1,    -1,  2919,  2920,
    2921,  2922,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2948,    -1,  2950,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2959,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     928,   929,   930,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   942,   943,   944,   945,   946,   947,
     948,   949,   950,   951,   952,   953,   954,    -1,   956,  3050,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3068,    -1,  3070,
       0,    -1,    -1,    -1,    -1,    -1,  3077,    -1,    -1,    -1,
      -1,   989,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3120,
      -1,    -1,  1030,  1031,    -1,  1033,  1034,    -1,    -1,    -1,
      -1,    -1,  1040,    -1,  3135,    -1,    -1,  3138,    -1,    -1,
      -1,    -1,    -1,    -1,  1052,  1053,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1066,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1080,  1081,  1082,  1083,  1084,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3194,    -1,    -1,    -1,    -1,    -1,  1107,
      -1,    -1,   132,    -1,    -1,    -1,  1114,  1115,    -1,    -1,
      -1,  3212,    -1,    -1,    -1,  3216,    -1,    -1,    -1,    -1,
      -1,    -1,  1130,  1131,  1132,    -1,  1134,  1135,    -1,  1137,
    1138,  1139,  1140,    -1,    -1,  1143,    -1,  1145,    -1,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,
    1158,  1159,  1160,  1161,  1162,  1163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1191,    -1,    -1,  1194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,   252,    -1,    -1,    -1,    -1,   257,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   285,    -1,   287,   288,    -1,
     290,    -1,   292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1313,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1323,    -1,  1325,    -1,    -1,
      -1,    -1,    -1,    -1,  1332,    -1,    -1,    -1,    -1,  1337,
    1338,  1339,    -1,  1341,    -1,    -1,    -1,    -1,    -1,  1347,
      -1,    -1,  1350,  1351,  1352,  1353,  1354,    -1,    -1,    -1,
      -1,    -1,  1360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   395,   396,    -1,    -1,    -1,
      -1,    -1,    -1,   403,   404,   405,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   491,   492,   493,   494,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1588,    -1,   612,  1591,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1644,    -1,   668,   669,
     670,    -1,    -1,   257,   258,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,    -1,
      -1,   285,    -1,   287,   288,    -1,   290,    -1,   292,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   300,   301,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   395,   396,    -1,    -1,    -1,  1794,    -1,    -1,    -1,
     404,   405,  1800,    -1,    -1,    -1,    -1,    -1,    -1,  1807,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1828,  1829,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1860,  1861,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    -1,    -1,
      -1,    -1,    65,    -1,    67,    68,    -1,  1905,   928,   929,
     930,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1917,
      -1,    -1,   942,   943,   944,   945,   946,   947,   948,   949,
     950,   951,   952,   953,   954,    -1,   956,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1942,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,   128,    -1,    -1,    -1,   989,
      -1,    -1,    -1,    -1,    -1,    -1,   996,    -1,    -1,    -1,
      -1,   144,  1002,    -1,    -1,    -1,    -1,    -1,    -1,   152,
      -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2000,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1030,  1031,    -1,  1033,  1034,    -1,    -1,    -1,    -1,    -1,
    1040,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1052,  1053,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,  1066,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1080,  1081,  1082,  1083,  1084,    -1,    -1,    -1,    -1,    -1,
    1090,  1091,    -1,    -1,   237,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1107,    -1,    -1,
      -1,    -1,    -1,    -1,  1114,  1115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2101,  2102,    -1,    -1,    -1,    -1,    -1,
    1130,  1131,  1132,    -1,  1134,  1135,    -1,  1137,  1138,  1139,
    1140,    -1,    -1,  1143,    -1,  1145,    -1,  1147,  1148,  1149,
    1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,    -1,   308,   309,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1191,    -1,    -1,  1194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,    -1,   417,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   427,   428,   429,   430,   431,   432,
     433,   434,    -1,    -1,   437,   438,   439,   440,   441,   442,
     443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1313,   457,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1323,    -1,  1325,    -1,    -1,    -1,    -1,
      -1,    -1,  1332,    -1,  1334,  1335,  1336,  1337,  1338,  1339,
      -1,  1341,    -1,  1343,    -1,  1345,  1346,  1347,    -1,    -1,
    1350,  1351,  1352,  1353,  1354,   498,    -1,    -1,    -1,    -1,
    1360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   989,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2403,    -1,    -1,  2406,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1030,  1031,    -1,  1033,
    1034,    -1,    -1,    -1,    -1,    -1,  1040,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1052,  1053,
      -1,    -1,    -1,    -1,    -1,  2453,    -1,  2455,    -1,  2457,
      -1,  2459,  1066,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1080,  1081,  1082,  1083,
    1084,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1107,    -1,    -1,    -1,    -1,  1528,    -1,
    1114,  1115,    -1,    -1,    -1,    -1,  2514,    -1,    -1,    -1,
      -1,    -1,  2520,  2521,    -1,    -1,  1130,  1131,  1132,    -1,
    1134,  1135,    -1,  1137,  1138,  1139,  1140,    -1,    -1,  1143,
      -1,  1145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1586,    -1,  1588,    -1,
      -1,  1591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1191,    -1,    -1,
    1194,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1644,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    -1,    56,    57,  1249,    59,    60,    -1,    -1,
      -1,    -1,    65,    -1,    67,    68,  1676,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1313,
      -1,   124,   125,   126,   127,   128,    -1,    -1,    -1,  1323,
      -1,  1325,    -1,    -1,    -1,    -1,    -1,    -1,  1332,    -1,
      -1,   144,    -1,  1337,  1338,  1339,    -1,  1341,    -1,    -1,
      -1,   154,    -1,  1347,    -1,    -1,  1350,  1351,  1352,  1353,
    1354,    -1,    -1,  2751,    -1,    -1,  1360,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1794,    -1,    -1,    -1,    -1,    -1,
    1800,    -1,    -1,    -1,    -1,    -1,  2784,  1807,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1828,  1829,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1860,  1861,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1905,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   308,   309,  1917,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1942,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2959,    -1,    -1,    -1,   378,   379,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    -1,    56,    57,
    2000,    59,    60,    -1,  1588,    -1,    -1,    65,    -1,    67,
      68,    -1,    -1,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,    -1,   417,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   427,   428,   429,   430,   431,   432,
     433,   434,    -1,    -1,   437,   438,   439,   440,   441,   442,
     443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1644,    -1,    -1,    -1,   457,    -1,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,    -1,  1676,    -1,    -1,    -1,   154,    -1,    -1,  3077,
      -1,  2101,  2102,    -1,    -1,   498,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3135,    -1,    -1,
    3138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1794,    -1,    -1,    -1,    -1,    -1,  3194,    -1,    -1,    -1,
      -1,    -1,    -1,  1807,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3216,    -1,
      -1,    -1,    -1,    -1,  1828,  1829,    -1,    -1,    -1,    -1,
     308,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1860,  1861,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1905,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,    -1,   417,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
     428,   429,   430,   431,   432,   433,   434,    -1,    -1,   437,
     438,   439,   440,   441,   442,   443,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,
      -1,    -1,    -1,  2403,    -1,    -1,  2406,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2000,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2453,    -1,  2455,    -1,  2457,    -1,  2459,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2514,    -1,    -1,  2101,  2102,    -1,
    2520,  2521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    -1,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2751,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     237,    -1,   239,    -1,    -1,    -1,    -1,    -1,   245,   246,
     247,   248,   249,   250,  2784,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2403,
      -1,    -1,  2406,    -1,   291,   292,   293,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,
     307,   308,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2453,
      -1,  2455,    -1,  2457,    -1,  2459,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   378,   379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2514,    -1,    -1,    -1,    -1,    -1,  2520,  2521,    -1,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,    -1,
     417,   418,    -1,    -1,   421,    -1,    -1,    -1,    -1,  2959,
     427,   428,   429,   430,   431,   432,   433,   434,    -1,    -1,
     437,   438,   439,   440,   441,   442,   443,    -1,   445,    -1,
      -1,    -1,   449,    -1,   451,   452,    -1,    -1,    -1,   456,
     457,    -1,   459,    -1,    -1,    -1,    -1,    -1,    -1,   466,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   482,    -1,    -1,    -1,    -1,
     487,   488,    -1,   490,   491,   492,   493,   494,   495,   496,
     497,   498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3077,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3135,    -1,     7,  3138,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    33,    -1,    -1,    -1,  2751,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    63,  3194,    65,    66,    67,    68,    -1,
    2784,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,    -1,
     140,   141,   142,   143,   144,   145,   146,    -1,   148,   149,
      -1,    -1,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,    -1,    -1,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,  2959,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,   255,   256,   257,    -1,    -1,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,   288,   289,
     290,    -1,    -1,    -1,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,    -1,    -1,   308,   309,
     310,    -1,    -1,   313,   314,   315,   316,    -1,   318,   319,
     320,   321,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3077,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,   378,   379,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,    -1,   417,    -1,   419,
     420,  3135,   422,    -1,  3138,    -1,    -1,   427,   428,   429,
     430,   431,   432,   433,   434,    -1,    -1,   437,   438,   439,
     440,   441,   442,   443,   444,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,
     470,    -1,   472,   473,    -1,   475,   476,   477,   478,   479,
    3194,   481,    -1,   483,   484,   485,   486,     7,    -1,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,   498,    -1,
      -1,    -1,  3216,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    63,    -1,    65,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,    -1,
     140,   141,   142,   143,   144,   145,   146,    -1,   148,   149,
      -1,    -1,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,    -1,    -1,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   261,   262,   263,    -1,    -1,    -1,    -1,   268,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,   288,   289,
     290,    -1,    -1,    -1,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,    -1,    -1,   308,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     320,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,   379,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,    -1,   417,    -1,   419,
     420,    -1,    -1,    -1,    -1,    -1,    -1,   427,   428,   429,
     430,   431,   432,   433,   434,    -1,    -1,   437,   438,   439,
     440,   441,   442,   443,   444,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,
     470,    -1,   472,   473,    -1,    -1,    -1,    -1,   478,   479,
      -1,    -1,    -1,    -1,   484,   485,   486,     7,    -1,     9,
      10,    11,    12,    -1,    -1,    -1,    16,    -1,   498,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    63,    -1,    65,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,    -1,
     140,   141,   142,   143,   144,   145,   146,    -1,   148,   149,
      -1,    -1,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,    -1,    -1,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   261,   262,   263,    -1,    -1,    -1,    -1,   268,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,   288,   289,
     290,    -1,    -1,    -1,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,    -1,    -1,   308,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     320,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,    -1,   417,    -1,   419,
     420,    -1,    -1,    -1,    -1,    -1,    -1,   427,   428,   429,
     430,   431,   432,   433,   434,    -1,    -1,   437,   438,   439,
     440,   441,   442,   443,   444,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,
     470,    -1,   472,   473,    -1,    -1,    -1,    -1,   478,   479,
      -1,    -1,    -1,    -1,   484,   485,   486,     7,    -1,     9,
      10,    11,    12,    -1,    -1,    -1,    16,    -1,   498,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    63,    -1,    65,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,    -1,
     140,   141,   142,   143,   144,   145,   146,    -1,   148,   149,
      -1,    -1,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,    -1,    -1,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   261,   262,   263,    -1,    -1,    -1,    -1,   268,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,   288,   289,
     290,    -1,    -1,    -1,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,    -1,    -1,   308,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     320,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,    -1,   417,    -1,   419,
     420,    -1,    -1,    -1,    -1,    -1,    -1,   427,   428,   429,
     430,   431,   432,   433,   434,    -1,    -1,   437,   438,   439,
     440,   441,   442,   443,   444,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,
     470,    -1,   472,   473,    -1,    -1,    -1,    -1,   478,   479,
      -1,    -1,    -1,    -1,   484,   485,   486,     7,    -1,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,   498,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    63,    -1,    65,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,    -1,
     140,   141,   142,   143,   144,   145,   146,    -1,   148,   149,
      -1,    -1,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,    -1,    -1,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   261,   262,   263,    -1,    -1,    -1,    -1,   268,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,   288,   289,
     290,    -1,    -1,    -1,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,    -1,    -1,   308,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     320,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,    -1,   417,    -1,   419,
     420,    -1,    -1,    -1,    -1,    -1,    -1,   427,   428,   429,
     430,   431,   432,   433,   434,    -1,    -1,   437,   438,   439,
     440,   441,   442,   443,   444,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    12,    -1,   457,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,
     470,    28,   472,   473,    31,    32,    -1,    -1,   478,   479,
      -1,    -1,    -1,    -1,   484,   485,   486,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    51,    52,    53,    54,   498,    56,
      57,    58,    59,    60,    -1,    -1,    63,    -1,    65,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
      -1,   138,    -1,   140,   141,   142,   143,   144,   145,   146,
      -1,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,
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
      -1,   308,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   320,   321,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   378,   379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,    -1,
     417,    -1,   419,   420,    -1,    -1,    -1,    -1,    -1,    -1,
     427,   428,   429,   430,   431,   432,   433,   434,    -1,    -1,
     437,   438,   439,   440,   441,   442,   443,   444,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    12,    -1,
     457,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     467,   468,   469,   470,    28,   472,   473,    31,    32,    -1,
      -1,   478,   479,    -1,    -1,    -1,    -1,   484,   485,   486,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,   498,    56,    57,    58,    59,    60,    -1,    -1,    63,
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
     304,   305,    -1,    -1,   308,   309,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   320,   321,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,    -1,   417,    -1,   419,   420,    -1,    -1,    -1,
      -1,    -1,    -1,   427,   428,   429,   430,   431,   432,   433,
     434,    -1,    -1,   437,   438,   439,   440,   441,   442,   443,
     444,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    12,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   467,   468,   469,   470,    28,   472,   473,
      31,    32,    -1,    -1,   478,   479,    -1,    -1,    -1,    -1,
     484,   485,   486,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    54,   498,    56,    57,    58,    59,    60,
      -1,    -1,    63,    -1,    65,    -1,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    -1,   138,    -1,   140,
     141,   142,   143,   144,   145,   146,    -1,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
      -1,    -1,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,
     261,   262,   263,    -1,    -1,    -1,    -1,   268,    -1,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   287,   288,   289,   290,
      -1,    -1,    -1,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,    -1,    -1,   308,   309,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   320,
     321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,    -1,   417,    -1,   419,   420,
      -1,    -1,    -1,    -1,    -1,    -1,   427,   428,   429,   430,
     431,   432,   433,   434,    -1,    -1,   437,   438,   439,   440,
     441,   442,   443,   444,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    10,    11,    12,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,   470,
      -1,   472,   473,    31,    32,    -1,    -1,   478,   479,    -1,
      -1,    -1,    -1,   484,   485,   486,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,   498,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,    -1,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,    -1,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
     238,    -1,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,   261,   262,   263,    -1,    -1,    -1,    -1,
     268,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,
     288,   289,   290,    -1,    -1,    -1,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   320,   321,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,    -1,    -1,
      -1,   419,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   429,   430,   431,   432,   433,   434,    -1,    -1,   437,
     438,   439,   440,   441,   442,   443,   444,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,
     468,   469,   470,    -1,   472,   473,    -1,    -1,    -1,    -1,
     478,   479,    -1,    -1,    -1,    -1,   484,   485,   486,     7,
      -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
     498,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    -1,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
      -1,   239,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,
     248,   249,   250,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   291,   292,   293,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,   307,
     308,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     378,   379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,    -1,   417,
     418,    -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,   427,
     428,   429,   430,   431,   432,   433,   434,    -1,    -1,   437,
     438,   439,   440,   441,   442,   443,    -1,   445,    -1,    -1,
      -1,   449,    -1,   451,   452,    -1,    -1,    -1,   456,   457,
      -1,   459,     7,    -1,    -1,    10,    11,    12,   466,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   482,    -1,    31,    32,    -1,   487,
     488,    -1,   490,   491,   492,   493,   494,   495,   496,   497,
     498,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
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
      -1,    -1,    -1,    -1,    -1,   320,   321,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,   403,   404,
     405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   419,   420,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   429,   430,   431,   432,   433,   434,
      -1,    -1,   437,   438,   439,   440,   441,   442,   443,   444,
      -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,
      12,    -1,    -1,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   467,   468,   469,   470,    -1,   472,   473,    31,
      32,    -1,    -1,   478,   479,    -1,    -1,    -1,    -1,   484,
     485,   486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,   498,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,    -1,   138,    -1,   140,   141,
     142,   143,   144,   145,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,    -1,    -1,    -1,
      -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,   238,    -1,   240,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   261,
     262,   263,    -1,    -1,    -1,    -1,   268,    -1,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   287,   288,   289,   290,    -1,
      -1,    -1,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   320,   321,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     402,   403,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,   420,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,   430,   431,
     432,   433,   434,    -1,    -1,   437,   438,   439,   440,   441,
     442,   443,   444,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    10,    11,    12,    -1,    -1,   458,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   467,   468,   469,   470,    -1,
     472,   473,    31,    32,    -1,    -1,   478,   479,    -1,    -1,
      -1,    -1,   484,   485,   486,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,   498,    56,    57,    58,
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
      -1,   320,   321,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    -1,    56,    57,
      -1,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   402,   403,   404,   405,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     419,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,   430,   431,   432,   433,   434,    -1,    -1,   437,   438,
     439,   440,   441,   442,   443,   444,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   467,   468,
     469,   470,    -1,   472,   473,    -1,   154,    -1,    -1,   478,
     479,    -1,    -1,    -1,    -1,   484,   485,   486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     308,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,    -1,   417,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
     428,   429,   430,   431,   432,   433,   434,    -1,    -1,   437,
     438,   439,   440,   441,   442,   443,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     498
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
     249,   250,   252,   291,   292,   293,   306,   307,   308,   309,
     354,   378,   379,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   417,   418,   421,   427,   428,   429,   430,
     431,   432,   433,   434,   437,   438,   439,   440,   441,   442,
     443,   445,   449,   451,   452,   456,   457,   459,   466,   482,
     487,   488,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   500,   501,   502,   503,   504,   505,   507,   508,   511,
     512,   513,   514,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   578,    10,    11,    12,    52,    53,    54,    56,
      59,    60,    65,    67,    68,   144,   154,   429,   430,   431,
     432,   433,   434,   437,   438,   439,   440,   441,   442,   443,
     521,   522,   537,   576,    59,   522,   562,   522,   562,    55,
     535,   536,   537,   575,    12,   455,   537,   576,    47,   578,
     537,   514,   535,   575,   514,   535,    12,   514,   537,   112,
     113,   123,   112,   113,   123,   112,   113,   123,   123,    18,
      18,   103,   104,    12,   123,    18,   123,    12,    12,   502,
      18,    18,    14,   102,    14,    52,    53,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   537,   579,    12,    12,    12,    12,    14,    12,    12,
      14,    12,    14,    12,    18,    18,    18,    18,    12,    12,
      12,    14,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,   522,   562,   522,   562,   522,   562,   522,   562,   522,
     562,   522,   562,   522,   562,   522,   562,   522,   562,   522,
     562,   522,   562,   522,   562,   522,   562,   578,   515,   516,
     535,    47,    12,    12,   578,    12,    12,    12,    12,    12,
      12,     0,     0,   502,   503,   504,   505,   507,   508,   502,
      10,    11,   119,   120,   522,   562,     7,     8,    10,    11,
       5,     6,   117,   118,   119,   120,    16,     4,    17,   115,
      20,   116,    12,    14,    18,   102,   123,   121,     7,   122,
      10,    11,    18,   102,   102,   123,    18,    18,    18,    14,
      14,    18,    18,    12,    18,    18,    13,    13,    18,    13,
     535,   514,    18,   535,   535,   535,   514,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   351,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     471,   489,   325,   327,   329,   330,   337,   340,   341,   342,
     343,   344,   345,   376,   380,   385,   386,   395,   400,   401,
     576,   576,   535,   535,   575,    38,   423,   424,   425,   426,
     422,    10,    11,    12,    16,    31,    32,    56,    58,    63,
     125,   129,   130,   131,   132,   133,   134,   135,   136,   138,
     140,   141,   142,   143,   144,   145,   146,   148,   149,   154,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   203,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   238,   240,   241,
     242,   243,   244,   251,   260,   261,   262,   263,   268,   270,
     287,   288,   289,   290,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   320,   321,   402,   403,
     404,   405,   419,   420,   429,   430,   431,   432,   433,   434,
     437,   438,   439,   440,   441,   442,   443,   444,   458,   467,
     468,   469,   470,   472,   473,   478,   479,   484,   485,   486,
     509,   514,   521,   535,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   576,   509,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   384,
      38,   220,   535,   322,   535,    14,   535,   535,    10,    11,
      12,    56,   125,   144,   154,   429,   430,   431,   432,   433,
     434,   437,   438,   439,   440,   441,   442,   443,   521,   537,
     556,   576,   537,   556,   556,   537,   556,   537,   556,   537,
     147,   199,   200,   201,   202,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   201,   202,   201,
     202,   201,   202,   537,   537,   537,   556,   556,   537,   537,
     537,   537,   537,   537,   537,   537,    47,    47,   535,   535,
     537,   535,   537,   535,    10,    11,    12,    59,   429,   430,
     431,   432,   433,   434,   437,   438,   439,   440,   441,   442,
     443,   521,   575,    47,   556,   537,   123,    48,   515,   502,
      67,   578,   579,    47,   506,   535,   514,    56,   537,   537,
     537,   502,   512,   512,   514,   514,   522,   522,   523,   523,
     525,   525,   525,   525,   526,   526,   527,   528,   529,   530,
     532,   531,   535,   535,    43,    44,   137,   199,   217,   220,
     221,   222,   223,   252,   253,   254,   381,   382,   399,   416,
     578,   556,    56,   535,   556,   522,   562,   562,   523,   563,
     523,   563,   217,   218,   219,   220,   250,   258,   271,   314,
     316,   317,   318,   327,   328,   333,   334,   335,   336,   346,
     347,   348,   349,   350,   352,   353,   355,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   480,   255,   256,   257,   264,   265,   266,   267,
     269,   310,   313,   314,   315,   316,   318,   319,   322,   475,
     476,   477,   481,   483,   576,   577,   322,   556,    10,    11,
      12,    31,    33,    58,    61,    66,    77,   322,   377,   407,
     410,   422,   429,   430,   431,   432,   433,   434,   437,   438,
     439,   440,   441,   442,   443,   514,   521,   535,   556,   557,
     575,   576,   577,   535,   535,   535,    12,   520,    13,    19,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    19,
     514,   535,    12,    12,    12,   537,   541,   542,   542,   536,
     556,    52,    53,   537,   576,    12,    47,    12,    18,    18,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    18,    12,    12,    12,
      12,    18,    12,    12,    12,    18,    18,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
      12,    12,    12,    12,    12,    12,    18,    12,    12,    12,
      12,    12,    13,    19,   542,    12,    14,   123,     4,     7,
       8,    10,    11,     5,     6,   117,   118,   119,   120,    16,
      17,   115,    20,   116,    18,    13,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,   514,    15,    14,    15,   535,    13,    19,   536,   537,
      18,    12,    18,    18,    12,    13,    18,    13,    15,    13,
      13,    15,    13,    15,    19,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    19,    13,    19,
      13,    15,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    13,    13,    19,    19,    13,    19,    13,    13,
      19,    13,   535,   517,   454,   502,    13,    13,    13,    12,
      19,    13,    19,    19,    19,    19,    21,    13,    19,    21,
      22,    15,    12,    12,   514,    12,    12,    12,    12,    12,
      12,    12,    12,   514,    12,    12,   514,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    47,
      12,    12,    12,    12,    12,    18,    14,    14,    12,    18,
      12,    12,    14,    12,    12,    12,    12,    18,    15,    15,
     535,   535,   537,   535,   535,   535,   535,   535,   537,   535,
     535,    56,   537,    49,    56,   535,   535,   535,   535,   535,
     535,   535,   556,   535,    58,   535,    64,   535,   535,   577,
     535,   535,   535,   535,   535,   576,    58,   557,    58,    49,
     535,   535,   535,   535,   514,    52,   514,    13,    13,   514,
     536,   537,   535,   323,   323,   324,   509,   537,   556,   537,
     556,   556,   537,   537,   537,   537,   537,   556,   537,   537,
     537,   537,   537,    45,    46,   537,   537,   537,   537,    45,
     164,   199,   556,   556,   537,   199,   199,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   556,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     556,   556,   556,   556,   556,   537,   537,   537,   537,   537,
     576,   576,   514,   514,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   556,   537,   537,
     537,   537,   537,   537,   556,   556,   556,   556,   556,   537,
     556,   556,   474,   556,   556,   556,   556,   514,    16,    56,
     514,   535,   556,   556,    21,    56,   535,   537,   580,   555,
     542,   522,   542,   522,   542,   523,   543,   523,   543,   525,
     546,   525,   546,   525,   546,   525,   546,   525,   547,   525,
     547,   548,   550,   551,   553,   552,   356,   357,   358,   359,
     502,   514,   514,    52,    53,   514,    54,    53,   535,    55,
      55,   535,    64,   535,   514,   535,   123,   535,   123,    15,
      64,    13,    18,    12,    12,    12,   537,   535,   537,   535,
     535,   535,   537,   537,   537,   537,   535,   535,   535,   535,
     535,   535,   535,   537,   535,   537,   537,   537,   150,   537,
     537,   150,   537,   150,   537,   537,   537,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   537,   556,    12,   535,   535,   535,   535,   535,
     535,   535,   537,   537,   537,   535,   535,   535,   514,   446,
     515,   460,   461,   462,   463,   464,   510,   535,   535,   514,
     537,   537,   533,   535,   535,   535,   123,   514,   537,   537,
     537,   535,   537,   535,   537,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   556,   535,   535,
     535,   535,   535,   535,   535,   535,   537,   556,   535,   556,
     535,   535,   537,   535,   535,   535,   556,   537,   576,   576,
     576,   556,   556,   556,   514,   556,   537,   576,   537,   576,
     576,   556,    13,   514,   556,   556,   556,   556,   556,   259,
     535,   535,   514,   375,   509,   514,   535,    66,   535,   535,
     514,    13,    19,    19,    19,    19,    19,    13,    19,    13,
      19,    13,    13,    13,    19,    19,    19,    19,    19,    13,
      13,    19,    19,    19,    19,    13,    19,    13,    19,    13,
      19,    13,    13,    19,    19,    19,    19,    13,    18,    13,
      19,    13,    19,    19,    19,    13,    13,    13,    13,    19,
      12,   541,    13,    19,    18,    19,    13,    19,    19,    19,
      19,    13,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    13,    19,    12,    12,    19,    19,
      19,    12,    12,    13,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    13,    13,    13,    19,    13,    19,    19,
      19,    19,    19,    13,    19,    19,    19,    19,    19,    19,
      19,    19,    13,    19,    19,    19,    19,    19,    19,    13,
      13,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    13,    13,    13,    13,    13,    13,
      13,    19,    19,    19,    13,    19,    19,    19,    19,    19,
      12,    13,    19,    13,    19,    19,    13,    13,    52,    53,
     537,   576,    13,    19,    15,    21,    15,    21,    12,    12,
      12,    12,    13,    13,    19,    19,    19,    13,    13,    19,
      19,    19,    19,    19,    13,    13,    13,    13,   577,    15,
     556,    13,    12,   537,   537,   537,    13,    19,    13,    19,
      13,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    19,    13,    13,    19,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      19,    13,    19,    13,    13,    13,    13,    19,    13,    13,
      13,    13,    13,    19,    13,    13,   556,    19,    19,    13,
      19,    19,    19,    13,    19,    19,    19,    19,    19,    19,
      13,    19,   535,   502,    50,    50,    50,    50,    50,    13,
      19,    19,    19,    13,    19,    19,    13,    19,    22,    19,
      13,   535,   556,    13,    13,    19,    13,    13,    19,    13,
      19,    13,    13,    13,    19,    19,    13,    19,    13,    13,
      13,    13,    13,    19,    13,    13,    19,    13,    19,    13,
      19,    19,    19,    13,    13,    13,    13,    13,    13,    13,
      13,    19,    19,    13,    13,    19,    13,    13,    13,    13,
      19,    19,    19,    19,    19,    19,    13,    19,    19,    19,
      13,    19,    19,    19,    19,    19,    13,    13,    19,    19,
      19,    19,    19,    12,    15,    15,    13,    13,    13,    15,
      19,    13,    13,    19,   537,   535,   535,   535,   535,   535,
     535,   537,   537,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   537,   535,
     556,   123,    47,   535,   535,   556,    47,   537,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   537,   537,   556,   556,   537,   537,   537,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   537,
     537,   537,   537,   537,   537,   537,   537,   535,   535,   535,
     535,   556,   556,   535,   535,   535,   535,   537,   514,   537,
     537,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   537,   535,   535,
     537,   535,   535,   556,    21,   535,   554,   537,    13,    13,
      13,   535,   535,    64,   535,   514,   514,   514,   535,    13,
      13,    13,    19,   537,   535,   535,   535,   537,   535,   535,
     535,   535,    13,   535,   535,   535,   556,   535,   535,   535,
     535,   537,   537,   535,   535,   535,   447,   515,   515,   460,
     461,   462,   463,   464,   535,   535,   537,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   556,   556,   535,    66,    47,    19,
      13,    19,    13,    19,    13,    19,    13,    13,    13,    13,
      19,    19,    13,    19,    19,    19,    19,    13,    19,    19,
      19,    19,    13,    13,    13,    19,   535,    13,    19,    19,
      13,    13,    19,    19,    19,    13,    13,    13,    13,    19,
      13,    19,    19,    19,    19,    19,    19,    19,    19,    13,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    13,    19,    19,    19,    19,    19,
      19,    13,    13,    19,    13,    13,    13,    19,    19,    13,
      13,    13,    13,    19,    13,    13,    19,    19,    19,    13,
      13,    13,    13,    13,    13,    13,    13,    19,    19,    19,
      19,    19,    13,    19,    19,    13,    19,    19,    13,    13,
      13,    19,    19,    13,    19,    19,    13,    13,    13,    13,
      19,    13,   535,    13,    19,    13,    13,    19,    19,    13,
      19,    19,    13,    19,    13,    19,    13,    19,    13,    19,
      19,    19,    19,    19,    19,    19,    19,    13,   535,   502,
     502,    50,    50,    50,    50,    50,    13,    19,    19,    19,
      13,    19,    22,    13,    21,    19,    19,    19,    19,    19,
      19,    13,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    13,    19,    19,    19,    19,    13,    13,    19,    13,
      13,    13,    13,    13,    19,    13,    19,    19,    19,    19,
      19,    19,    19,    19,    13,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   537,   535,   536,   536,   537,    47,   537,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   537,
     535,   537,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   537,   537,   537,   537,   537,
     535,   535,   535,   556,   556,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     514,    13,   535,   537,   535,   535,   535,   556,   556,   556,
     556,   535,   535,   535,   537,   537,   535,   535,   515,   535,
     537,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   537,   556,   535,   535,   535,   535,
     556,   556,   535,   535,    13,    13,    19,    19,    13,    19,
      19,    13,    19,    19,    13,    19,    19,    19,    13,    19,
      19,    13,    19,    19,    13,    13,    19,    19,    19,    19,
      13,    19,    13,    19,    13,    19,    13,    19,    19,    19,
      19,    19,    13,    13,    13,    19,    19,    19,    19,    19,
      19,    13,    19,    19,    19,    19,    19,    19,    19,    13,
      19,    19,    19,    19,    19,    19,    19,    13,    13,    13,
      13,    19,    19,    13,    19,    19,    19,    19,    19,    19,
      13,    19,    21,    21,    13,    13,    19,    19,    13,    19,
      13,    19,    13,    13,    19,    13,    19,    19,    13,    19,
      13,    19,    19,    13,    13,   502,    19,    19,    19,    13,
      13,    19,    19,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    19,    19,    19,    19,
      19,    13,    13,    13,    19,    13,    19,    19,    19,    13,
      13,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   536,   535,   536,    47,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   580,   535,   580,   535,   580,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   537,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     514,   535,   535,   535,   535,   535,   535,   535,   556,   537,
     535,   537,   535,   535,   535,   535,   535,   535,   535,   535,
     556,   535,   535,   535,    19,    13,    13,    19,    19,    19,
      13,    13,    13,    19,    13,    19,    19,    19,    13,    13,
      19,    19,    19,    13,    19,    13,    19,    19,    19,    19,
      19,    19,    13,    19,    19,    19,    19,    19,    19,    19,
      13,    19,    13,    13,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    13,    19,    19,    13,    13,    19,    13,
      13,    13,    19,    19,    19,    13,    15,    19,    13,    13,
      13,    19,    19,    13,    13,    19,    19,    13,    19,    19,
      19,    19,    21,    13,    13,    19,    19,    13,    19,    19,
      19,    19,    19,   535,   535,   535,   535,   535,   535,   535,
     514,   536,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   580,   580,   580,
     580,   535,   535,   535,   537,   537,   537,   537,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   537,
     535,   537,   535,   535,   535,   535,   535,   556,   535,   535,
     535,    13,    19,    19,    19,    19,    13,    19,    19,    13,
      13,    19,    13,    13,    13,    13,    13,    13,    19,    13,
      19,    13,    19,    13,    13,    19,    13,    13,    13,    13,
      19,    13,    13,    13,    13,    19,    19,    13,    19,    13,
      19,    13,    19,    21,    19,    13,    19,    19,    19,    19,
      19,    19,    13,    19,    19,    19,    13,    19,    19,    19,
      19,   535,   535,   535,   535,   514,   535,   535,   535,   535,
     535,   535,   535,   580,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   537,   535,   537,   535,   123,   535,   535,
     535,   556,   535,   535,   535,    13,    13,    19,    13,    13,
      19,    19,    19,    13,    13,    13,    19,    13,    19,    19,
      13,    19,    19,    13,    13,    19,    19,    13,    19,    19,
      19,    19,   556,    19,    19,    19,    19,    13,    13,    19,
      19,   535,   514,   535,   535,   535,   535,   535,   535,   535,
     556,   535,   556,   535,   535,   535,   535,   535,   535,   535,
     535,   535,    19,    13,    13,    13,    13,    13,    19,    19,
      19,    13,    13,    13,    19,    19,    19,    13,    19,    19,
      13,    13,    19,    13,    19,   535,   535,   535,   535,   535,
     535,   537,   535,   535,   535,   556,    19,    19,    13,    19,
      13,    19,    19,    13,    19,    13,    19,   535,   535,   535,
     535,   537,   535,   556,    19,    13,    19,    19,    19,    13,
      13,   535,   535,   535,   535,    19,    19,    19,    13,   535,
     535,   535,    19,    19,    19,   535,   535,   535,    13,    19,
      19,   535,   535,    19,    13,   535,    13
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
     745,   746,   747,   748,   749,   750,   751,   752,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   499,   500,   500,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   502,   502,   503,   503,
     503,   504,   504,   506,   505,   507,   507,   507,   507,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   511,   511,   512,   512,   512,   512,   513,   513,
     513,   514,   515,   516,   517,   518,   518,   518,   518,   518,
     518,   518,   518,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   521,   521,   522,   522,   523,   523,   523,
     524,   524,   524,   525,   526,   526,   526,   526,   526,   527,
     527,   527,   527,   527,   528,   528,   529,   529,   530,   530,
     531,   531,   532,   532,   533,   533,   534,   535,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   537,
     537,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   539,   539,
     540,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   542,
     542,   543,   543,   543,   543,   543,   543,   544,   545,   545,
     545,   545,   545,   546,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   548,   548,   548,   548,   548,   549,   549,
     550,   551,   551,   552,   552,   553,   553,   554,   554,   555,
     555,   556,   557,   557,   557,   557,   558,   558,   558,   559,
     559,   560,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     562,   563,   563,   563,   563,   564,   564,   564,   564,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   576,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     578,   579,   579,   579,   579,   579,   579,   579,   579,   579,
     579,   579,   579,   579,   579,   579,   579,   579,   580,   580,
     580,   580
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     1,     8,    10,
       2,     4,     6,     0,     8,     3,     1,     5,     2,     1,
       1,     1,     1,     1,     1,     4,     6,     6,     6,     6,
       3,     3,     6,     6,     3,     3,     3,     3,     6,     3,
       3,     6,     6,     6,     3,     3,     8,     8,     3,     1,
       1,     1,     1,     4,     1,     2,     2,     2,     1,     3,
       3,     3,     6,     6,    16,     2,     2,     3,     2,     2,
       3,     3,     2,     2,     3,     2,     2,     5,     2,     1,
       1,     2,     2,     4,     2,     2,     2,     1,     4,     3,
       2,     2,    10,     6,     3,     6,     6,     8,    28,     8,
       8,     3,     8,    12,     6,     6,    16,     8,    16,    10,
       6,    10,     8,    10,    14,     8,    12,     6,     8,     6,
       6,     6,    10,     6,    10,    10,    12,     6,     6,    12,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     8,     3,     3,     3,     3,     3,     3,    12,
      16,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,    10,     6,    14,     6,     8,     6,     6,     8,     6,
      10,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     3,     3,     4,     3,     6,     6,     4,     4,
       6,    10,    10,    10,     6,     6,     6,     6,     6,    10,
       6,    10,     6,     6,     6,     3,     6,     6,    10,    10,
       6,     6,     6,     3,     3,     3,     3,     6,     6,     3,
       6,     6,     8,    10,     3,     6,     3,     4,    20,     6,
      10,     6,     3,     3,     6,     3,     6,     8,     6,     6,
       8,    16,     6,     3,     6,     8,     3,    12,    12,    12,
      10,     8,     8,    10,     8,    10,    12,     6,     8,     8,
      10,    16,    18,    12,     6,    18,    16,    12,    10,    10,
      10,     6,    10,     6,     6,     6,     8,     1,     4,     4,
       8,     4,    18,     4,     1,     1,     6,     6,     3,     3,
       6,     6,     3,     3,     3,     3,     3,     3,     3,     8,
       6,     6,     6,     3,     4,     1,     1,     1,     1,     1,
      30,    24,     4,     8,     0,     1,     3,     1,     3,     2,
       4,     2,     4,     1,     3,     2,     4,     2,     4,     1,
       3,     0,     2,     2,     2,     2,     2,     4,     4,     4,
       4,     4,     1,     1,     1,     6,     1,     3,     1,     3,
       3,     1,     3,     0,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     4,     6,     8,    10,    10,     8,
       6,     3,     3,     3,     3,     3,     3,     6,     4,    10,
       4,    10,     4,     4,     4,     4,     4,     4,     7,     7,
       7,     9,     7,     6,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     6,     8,    10,
      10,     8,     6,     8,     6,     8,     8,    12,     3,     6,
       4,     4,     1,     6,     6,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     4,     1,     3,     3,
       1,     3,     3,     1,     1,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     2,     4,    16,    14,    16,     4,     4,     4,     1,
      10,    12,     8,     1,     4,     6,     6,     6,     8,     8,
       6,     6,     8,     8,    10,    10,    12,    12,    10,     4,
      10,     4,     6,     4,     4,     4,    12,     4,    12,    12,
      16,    20,    10,    12,     4,     6,     6,     6,     4,     4,
       6,     4,     6,     6,     6,     4,    10,    16,    10,     8,
      12,    10,     8,    12,     8,    12,     8,    12,     3,     3,
       8,     8,     3,     6,    12,    12,    14,    12,    12,    16,
       4,     8,    10,    12,    10,    12,    10,    12,    12,    14,
      12,     8,    14,     4,     4,     4,     4,     3,     3,     3,
       6,     6,     6,     6,     8,    14,    12,    14,    12,     6,
       8,    10,    10,    12,     6,     6,     6,     6,     6,     6,
       6,     6,     8,    10,     4,     4,    10,    10,     4,     6,
       6,    12,    30,     8,     5,     5,     5,     6,     6,     4,
       6,     4,     6,     4,     4,    18,     8,     6,     1,     3,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       4,     1,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     3,     8,     4,     6,     1,     4,     1,
       3,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     6,     6,     8,     8,     4,     6,     6,
       6,     6,     3,     2,     4,     1,     4,     6,     1,     4,
       4,    10,     6,    16,    18,    10,    20,     8,     4,     6,
       8,     8,    12,    16,    16,    18,    14,    14,    16,    20,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,    11,     7,
       1,     1
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
  "T_ProcessEvents", "T_isoarea2D", "T_posarea", "T_isosurf",
  "T_isosurf_inv", "T_isosurf_ijk", "T_isosurf_ras", "T_vtkDecimate",
  "T_vtkMarchingCubes", "T_vtkSmooth", "T_Recompute", "T_vtkWindowedSinc",
  "T_isoline", "T_vtkDist", "T_AndreDist", "T_Surface", "T_getimage",
  "T_GetImageFromX", "T_rotate", "T_computeCC", "T_drawCC", "T_setminCC",
  "T_addobj", "T_setcurrentobj", "T_writeVRML", "T_writeVTK",
  "T_OwnMaterial", "T_SetColor", "T_SetColors", "T_SetColorOpacity",
  "T_Paint", "T_SetLight", "T_SetLightPos", "T_SetLightAmbient",
  "T_SetLightDiffuse", "T_SetLightSpecular", "T_SetBackground", "T_Remove",
  "T_SwapBuffers", "T_SetAmbient", "T_SetDiffuse", "T_SetSpecular",
  "T_SetShininess", "T_SetOpacity", "T_SetOpacityImage", "T_SetVisible",
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
  "proc_decl", "@1", "func_inst", "command", "param_list",
  "param_list_decl", "primary_expr_string", "postfix_expr_string",
  "additive_expr_string", "expr_string", "instr_block", "begin_block",
  "end_block", "primary_expr", "postfix_expr", "unary_expr",
  "unary_operator", "cast_expr", "multiplicative_expr", "additive_expr",
  "shift_expr", "relational_expr", "equality_expr", "and_expr",
  "exclusive_or_expr", "inclusive_or_expr", "logical_and_expr",
  "logical_or_expr", "conditional_expr", "assignment_expr", "expr",
  "basic_type", "var_image", "image", "primary_image", "postfix_image",
  "unary_image", "cast_image", "multiplicative_image", "additive_image2",
  "additive_image", "shift_image", "relational_image", "equality_image",
  "and_image", "exclusive_or_image", "inclusive_or_image",
  "logical_and_image", "logical_or_image", "conditional_image",
  "assignment_image", "expr_image", "gltransform", "matrix",
  "primary_matrix", "postfix_matrix", "unary_matrix", "cast_matrix",
  "multiplicative_matrix", "additive_matrix", "shift_matrix",
  "relational_matrix", "equality_matrix", "and_matrix",
  "exclusive_or_matrix", "inclusive_or_matrix", "logical_and_matrix",
  "logical_or_matrix", "conditional_matrix", "assignment_matrix",
  "expr_matrix", "var_surface", "surface", "identifier", "variable",
  "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       500,     0,    -1,    -1,   501,     0,    -1,   502,    -1,   501,
     502,    -1,   508,   502,    -1,   501,   508,   502,    -1,   503,
      -1,   501,   503,    -1,   504,    -1,   501,   504,    -1,   507,
      -1,   501,   507,    -1,   505,    -1,   501,   505,    -1,    30,
      -1,    22,    -1,   445,   578,   123,   535,   446,   535,   515,
     502,    -1,   445,   578,   123,   535,   446,   535,   447,   535,
     515,   502,    -1,   449,   515,    -1,   452,   535,   515,   502,
      -1,   452,   535,   515,   454,   515,   502,    -1,    -1,   466,
     578,   506,    12,   510,    13,   515,   502,    -1,   456,    47,
     502,    -1,   456,    -1,    64,    12,   509,    13,   502,    -1,
      64,   502,    -1,    29,    -1,   451,    -1,    71,    -1,    73,
      -1,    74,    -1,    72,    -1,    75,    12,   535,    13,    -1,
      76,    12,   535,    19,    64,    13,    -1,   578,   123,   322,
      14,   535,    15,    -1,   578,   102,   322,    14,   535,    15,
      -1,   578,   123,    31,    14,   535,    15,    -1,   578,   123,
     556,    -1,   578,   102,   556,    -1,   578,   123,    61,    12,
     509,    13,    -1,    68,    14,   535,    15,   123,   556,    -1,
     578,   123,   575,    -1,   578,   123,   557,    -1,    59,   123,
     535,    -1,    59,   123,   575,    -1,    67,    14,   535,    15,
     123,   577,    -1,   578,   123,   577,    -1,   576,   102,   577,
      -1,    67,   102,   322,    14,   535,    15,    -1,   578,   123,
     410,    12,   535,    13,    -1,   578,   123,   407,    12,   535,
      13,    -1,   578,   123,   535,    -1,   578,   123,   514,    -1,
     578,   123,   422,    12,   514,    19,    47,    13,    -1,    60,
     123,   422,    12,   514,    19,    47,    13,    -1,    60,    18,
     426,    -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    12,   535,    13,    -1,    36,    -1,    34,   537,    -1,
      37,   537,    -1,    34,   576,    -1,   354,    -1,   537,   123,
     556,    -1,   537,   102,   556,    -1,   537,   123,   535,    -1,
     537,    14,   535,    15,   123,   556,    -1,   537,    14,   535,
      15,   123,   535,    -1,   537,    12,   535,    21,   535,    19,
     535,    21,   535,    19,   535,    21,   535,    13,   123,   556,
      -1,    52,   112,    -1,    52,   113,    -1,    52,   123,   535,
      -1,    53,   112,    -1,    53,   113,    -1,    53,   123,   535,
      -1,    54,   123,   535,    -1,    54,   112,    -1,    54,   113,
      -1,    55,   123,   514,    -1,    34,   455,    -1,    69,   579,
      -1,    69,    67,    14,   535,    15,    -1,    41,   514,    -1,
      42,    -1,    35,    -1,    35,   578,    -1,    35,    47,    -1,
      60,    18,    38,   514,    -1,    38,   514,    -1,    39,   514,
      -1,    38,   575,    -1,   575,    -1,    60,    18,    38,   535,
      -1,    60,    18,   423,    -1,    38,   535,    -1,    39,   535,
      -1,    56,    18,   382,    12,   535,    19,   535,    19,   535,
      13,    -1,    56,    18,   383,    12,   535,    13,    -1,    56,
      18,   384,    -1,    56,    18,   385,    12,   537,    13,    -1,
      56,    18,   385,    12,    56,    13,    -1,    56,    18,   387,
      12,    56,    19,   537,    13,    -1,    56,    18,   471,    12,
     535,    19,   535,    19,   535,    19,   535,    19,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    19,   535,    19,
     535,    19,   535,    13,    -1,    56,    18,   386,    12,    49,
      19,   537,    13,    -1,    56,    18,   388,    12,   535,    19,
     535,    13,    -1,    56,    18,   389,    -1,    56,    18,   390,
      12,   535,    19,   535,    13,    -1,    56,    18,   391,    12,
     535,    19,   535,    19,   535,    19,   535,    13,    -1,    56,
      18,   392,    12,   535,    13,    -1,    56,    18,   393,    12,
     535,    13,    -1,    56,    18,   394,    12,   535,    19,   535,
      19,   535,    19,   535,    19,   535,    19,   535,    13,    -1,
      56,    18,   395,    12,   535,    19,   535,    13,    -1,    56,
      18,   397,    12,   535,    19,   535,    19,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,    56,    18,   396,    12,
     556,    19,   535,    19,   535,    13,    -1,    56,    18,   398,
      12,    58,    13,    -1,    56,    18,   272,    12,   535,    19,
     537,    19,   535,    13,    -1,    56,    18,   272,    12,   537,
      19,   535,    13,    -1,    56,    18,   273,    12,   535,    19,
     535,    19,   535,    13,    -1,    56,    18,   273,    12,   535,
      19,   535,    19,   535,    19,   535,    19,   535,    13,    -1,
      56,    18,   274,    12,   535,    19,   535,    13,    -1,    56,
      18,   275,    12,   535,    19,   535,    19,   535,    19,   535,
      13,    -1,    56,    18,   276,    12,   535,    13,    -1,    56,
      18,   277,    12,   535,    19,   535,    13,    -1,    56,    18,
     489,    12,    64,    13,    -1,    56,    18,   351,    12,   537,
      13,    -1,   537,    18,   399,    12,   535,    13,    -1,   537,
      18,   399,    12,   535,    19,   535,    19,   535,    13,    -1,
     537,    18,   381,    12,   535,    13,    -1,   537,    18,   381,
      12,   535,    19,   535,    19,   535,    13,    -1,   537,    18,
     382,    12,   535,    19,   535,    19,   535,    13,    -1,   537,
      18,   137,    12,   537,    19,   535,    19,   535,    19,   535,
      13,    -1,   537,    18,   137,    12,   537,    13,    -1,   537,
      18,    43,    12,   514,    13,    -1,   144,    18,   199,    12,
     537,    19,   535,    19,   535,    19,   535,    13,    -1,   144,
      18,   200,    12,   535,    13,    -1,   144,    18,   147,    12,
     535,    13,    -1,   144,    18,   205,    12,   535,    13,    -1,
     144,    18,   206,    12,   535,    13,    -1,   144,    18,   209,
      12,   537,    13,    -1,   144,    18,   210,    12,   537,    13,
      -1,   144,    18,   211,    12,   537,    13,    -1,   144,    18,
     212,    12,   537,    13,    -1,   144,    18,   213,    12,   535,
      13,    -1,   144,    18,   214,    12,   535,    13,    -1,   144,
      18,   215,    12,   535,    13,    -1,   144,    18,   216,    12,
     535,    13,    -1,   144,    18,   200,    12,   535,    19,   535,
      13,    -1,   144,    18,   201,    -1,   144,    18,   202,    -1,
     189,    18,   201,    -1,   189,    18,   202,    -1,   190,    18,
     201,    -1,   190,    18,   202,    -1,   154,    18,   172,    12,
     535,    19,   535,    19,   535,    19,   535,    13,    -1,   154,
      18,   172,    12,   535,    19,   535,    19,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,   154,    18,   156,    12,
     535,    13,    -1,   154,    18,   157,    12,   535,    13,    -1,
     154,    18,   158,    12,   535,    13,    -1,   154,    18,   171,
      12,   535,    13,    -1,   154,    18,   175,    12,   535,    13,
      -1,   154,    18,   180,    12,   535,    13,    -1,   154,    18,
     181,    12,   535,    13,    -1,   154,    18,   182,    12,   535,
      13,    -1,   154,    18,   183,    12,   535,    13,    -1,   154,
      18,   178,    12,   535,    13,    -1,   154,    18,   179,    12,
     535,    19,   535,    19,   535,    13,    -1,   154,    18,   184,
      12,   535,    13,    -1,   154,    18,   185,    12,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    13,    -1,   154,
      18,   173,    12,   535,    13,    -1,   154,    18,   159,    12,
     537,    19,   535,    13,    -1,   154,    18,   160,    12,   535,
      13,    -1,   154,    18,   161,    12,   537,    13,    -1,   154,
      18,   174,    12,   535,    19,   535,    13,    -1,   154,    18,
     163,    12,   537,    13,    -1,   154,    18,   162,    12,   537,
      19,   537,    19,   537,    13,    -1,   154,    18,   165,    12,
     537,    13,    -1,   154,    18,   166,    12,   537,    13,    -1,
     154,    18,   167,    12,   537,    13,    -1,   154,    18,   170,
      12,   537,    13,    -1,   154,    18,   168,    12,   537,    13,
      -1,   154,    18,   169,    12,   537,    13,    -1,   154,    18,
     165,    12,   150,    13,    -1,   154,    18,   167,    12,   150,
      13,    -1,   154,    18,   168,    12,   150,    13,    -1,   154,
      18,   176,    12,   535,    13,    -1,   154,    18,   177,    12,
     535,    13,    -1,   154,    18,   201,    -1,   154,    18,   202,
      -1,   537,    18,   220,   514,    -1,   537,    18,   221,    -1,
     537,    18,   222,    12,   537,    13,    -1,   537,    18,   223,
      12,   537,    13,    -1,   576,    18,   220,   514,    -1,   576,
      18,   271,   514,    -1,   576,    18,   333,    12,   535,    13,
      -1,   576,    18,   346,    12,   535,    19,   535,    19,   535,
      13,    -1,   576,    18,   347,    12,   535,    19,   535,    19,
     535,    13,    -1,   576,    18,   348,    12,   535,    19,   535,
      19,   535,    13,    -1,   576,    18,   349,    12,   535,    13,
      -1,   576,    18,   350,    12,   535,    13,    -1,   576,    18,
     352,    12,   535,    13,    -1,   576,    18,   353,    12,   535,
      13,    -1,   576,    18,   336,    12,   535,    13,    -1,   576,
      18,   334,    12,   535,    19,   535,    19,   535,    13,    -1,
     576,    18,   369,    12,   537,    13,    -1,   576,    18,   335,
      12,   556,    19,   535,    19,   535,    13,    -1,   576,    18,
     335,    12,   556,    13,    -1,   576,    18,   355,    12,   537,
      13,    -1,   576,    18,   362,    12,   535,    13,    -1,   576,
      18,   363,    -1,   576,    18,   250,    12,   535,    13,    -1,
     576,    18,   364,    12,   556,    13,    -1,   576,    18,   367,
      12,   535,    19,   535,    19,   535,    13,    -1,   576,    18,
     368,    12,   535,    19,   535,    19,   535,    13,    -1,   576,
      18,   370,    12,   535,    13,    -1,   576,    18,   258,    12,
     535,    13,    -1,   576,    18,   360,    12,   556,    13,    -1,
     576,    18,   361,    -1,   576,    18,   317,    -1,   576,    18,
     365,    -1,   576,    18,   366,    -1,   576,    18,   316,    12,
     535,    13,    -1,   576,    18,   318,    12,   535,    13,    -1,
     576,    18,   314,    -1,   576,    18,   328,    12,   535,    13,
      -1,   576,    18,   327,    12,   535,    13,    -1,   576,    18,
     327,    12,   535,    19,   535,    13,    -1,   576,    18,   371,
      12,   535,    19,   535,    19,   535,    13,    -1,   576,    18,
     372,    -1,   576,    18,   374,    12,   535,    13,    -1,   576,
      18,   373,    -1,   487,    12,   514,    13,    -1,   488,    12,
      56,    19,   535,    19,   535,    19,   535,    19,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    13,    -1,   576,
      18,   480,    12,   556,    13,    -1,    58,    18,   325,    12,
     535,    19,   535,    19,   535,    13,    -1,    58,    18,   329,
      12,   577,    13,    -1,    58,   103,   576,    -1,    58,   104,
     576,    -1,    58,    18,   344,    12,   576,    13,    -1,    58,
      18,   345,    -1,    58,    18,   327,    12,   535,    13,    -1,
      58,    18,   327,    12,   535,    19,   535,    13,    -1,    58,
      18,   330,    12,   535,    13,    -1,    58,    18,   385,    12,
      58,    13,    -1,    58,    18,   386,    12,    49,    19,   537,
      13,    -1,    58,    18,   400,    12,   535,    19,   556,    19,
     535,    19,   535,    19,   535,    19,   535,    13,    -1,    58,
      18,   401,    12,   535,    13,    -1,    58,    18,   380,    -1,
      58,    18,   376,    12,   557,    13,    -1,    58,    18,   376,
      12,   557,    19,   535,    13,    -1,    58,    18,   337,    -1,
      58,    18,   340,    12,   535,    19,   535,    19,   535,    19,
     535,    13,    -1,    58,    18,   341,    12,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,    58,    18,   342,    12,
     535,    19,   535,    19,   535,    19,   535,    13,    -1,    58,
      18,   343,    12,   535,    19,   535,    19,   535,    13,    -1,
      58,    18,   395,    12,   535,    19,   535,    13,    -1,   245,
      12,   537,    19,   535,    19,   535,    13,    -1,   245,    12,
     537,    19,   535,    19,   535,    19,   556,    13,    -1,   246,
      12,   537,    19,   535,    19,   535,    13,    -1,   246,    12,
     537,    19,   535,    19,   535,    19,   556,    13,    -1,   246,
      12,   537,    19,   535,    19,   535,    19,   556,    19,   535,
      13,    -1,   247,    12,   537,    19,   535,    13,    -1,   247,
      12,   537,    19,   535,    19,   556,    13,    -1,   247,    12,
     537,    19,   535,    19,   535,    13,    -1,   247,    12,   537,
      19,   535,    19,   535,    19,   556,    13,    -1,   249,    12,
     537,    19,   535,    19,   535,    19,   535,    19,   535,    19,
     535,    19,   535,    13,    -1,   249,    12,   537,    19,   535,
      19,   535,    19,   535,    19,   535,    19,   535,    19,   535,
      19,   556,    13,    -1,   248,    12,   537,    19,   535,    19,
     535,    19,   556,    19,   535,    13,    -1,   250,    12,   537,
      19,   535,    13,    -1,   293,    12,    47,    19,   537,    19,
     537,    19,   537,    19,   537,    19,   537,    19,   537,    19,
     556,    13,    -1,   293,    12,    47,    19,   537,    19,   537,
      19,   537,    19,   537,    19,   537,    19,   537,    13,    -1,
     292,    12,    47,    19,   537,    19,   537,    19,   537,    19,
     556,    13,    -1,   292,    12,    47,    19,   537,    19,   537,
      19,   537,    13,    -1,   252,    12,   537,    19,   535,    19,
     535,    19,   535,    13,    -1,   537,    18,   252,    12,   535,
      19,   535,    19,   535,    13,    -1,   537,    18,   252,    12,
     537,    13,    -1,   537,    18,   253,    12,   535,    19,   535,
      19,   535,    13,    -1,   537,    18,   253,    12,   537,    13,
      -1,   537,    18,   254,    12,   535,    13,    -1,   139,    12,
     537,    19,   537,    13,    -1,   139,    12,   537,    19,   537,
      19,   537,    13,    -1,   535,    -1,   306,    12,   535,    13,
      -1,   307,    12,   535,    13,    -1,   418,    12,   556,    19,
     514,    19,   535,    13,    -1,   421,    12,   537,    13,    -1,
     291,    12,   537,    19,   537,    19,   535,    19,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    13,    -1,   459,
      12,    47,    13,    -1,   151,    -1,   153,    -1,   578,   123,
      77,    12,   514,    13,    -1,    65,    18,    96,    12,   514,
      13,    -1,    65,    18,    80,    -1,    65,    18,    81,    -1,
      65,    18,    82,    12,   514,    13,    -1,    65,    18,    78,
      12,   514,    13,    -1,    65,    18,    79,    -1,    65,    18,
      97,    -1,    65,    18,    98,    -1,    65,    18,    99,    -1,
      65,    18,    85,    -1,    65,    18,    86,    -1,    65,    18,
     100,    -1,    65,    18,    93,    12,   535,    19,   535,    13,
      -1,    65,    18,    94,    12,    64,    13,    -1,    65,    18,
      95,    12,   535,    13,    -1,   490,    12,   537,    19,   514,
      13,    -1,    66,    18,    38,    -1,    66,    18,   220,   514,
      -1,   491,    -1,   492,    -1,   493,    -1,   494,    -1,   495,
      -1,   496,    12,   537,    19,   537,    19,   537,    19,   537,
      19,   537,    19,   537,    19,   537,    19,   535,    19,   535,
      19,   535,    19,   535,    19,   535,    19,   535,    19,   535,
      13,    -1,   497,    12,   537,    19,   537,    19,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    19,   535,    19,
     537,    19,   537,    19,   535,    13,    -1,    62,    12,   509,
      13,    -1,   482,    12,   535,    19,   535,    19,   535,    13,
      -1,    -1,   535,    -1,   509,    19,   535,    -1,   514,    -1,
     509,    19,   514,    -1,    16,    52,    -1,   509,    19,    16,
      52,    -1,    16,    53,    -1,   509,    19,    16,    53,    -1,
     556,    -1,   509,    19,   556,    -1,    16,   537,    -1,   509,
      19,    16,   537,    -1,    16,   576,    -1,   509,    19,    16,
     576,    -1,    56,    -1,   509,    19,    56,    -1,    -1,   463,
      50,    -1,   464,    50,    -1,   460,    50,    -1,   461,    50,
      -1,   462,    50,    -1,   510,    19,   463,    50,    -1,   510,
      19,   464,    50,    -1,   510,    19,   460,    50,    -1,   510,
      19,   461,    50,    -1,   510,    19,   462,    50,    -1,    47,
      -1,    55,    -1,   511,    -1,    40,    12,   514,    19,   535,
      13,    -1,   152,    -1,   537,    18,    44,    -1,   512,    -1,
     513,    10,   512,    -1,   513,    11,   512,    -1,   513,    -1,
     516,    48,   517,    -1,    -1,    -1,    49,    -1,    28,    -1,
     427,    -1,   428,    -1,    52,    -1,    53,    -1,    54,    -1,
      12,   535,    13,    -1,   518,    -1,   537,    12,   535,    13,
      -1,   537,    12,   535,    19,   535,    13,    -1,   537,    12,
     535,    19,   535,    19,   535,    13,    -1,   537,    12,   535,
      19,   535,    19,   535,    19,   535,    13,    -1,   537,    12,
     535,    19,   535,    19,   535,    22,   535,    13,    -1,   537,
      12,   535,    19,   535,    22,   535,    13,    -1,   537,    12,
     535,    22,   535,    13,    -1,   537,    18,   199,    -1,   537,
      18,   578,    -1,   537,    18,   217,    -1,   576,    18,   217,
      -1,   576,    18,   218,    -1,   576,    18,   219,    -1,   204,
      12,   537,    19,   537,    13,    -1,   237,    12,   537,    13,
      -1,   308,    12,   537,    19,   535,    19,   535,    19,   535,
      13,    -1,   309,    12,   537,    13,    -1,   309,    12,   535,
      19,   535,    19,   535,    19,   535,    13,    -1,   124,    12,
     556,    13,    -1,   239,    12,   556,    13,    -1,   125,    12,
     537,    13,    -1,   126,    12,   556,    13,    -1,   127,    12,
     537,    13,    -1,   128,    12,   537,    13,    -1,   125,    14,
     556,    15,    12,   537,    13,    -1,   127,    14,   556,    15,
      12,   537,    13,    -1,   128,    14,   556,    15,    12,   537,
      13,    -1,   128,    14,   556,    15,    12,   537,    19,   535,
      13,    -1,   239,    14,   556,    15,    12,   556,    13,    -1,
     239,    12,   537,    19,   556,    13,    -1,   417,    12,    47,
      13,    -1,    56,    18,   282,    -1,    56,    18,   283,    -1,
      56,    18,   280,    -1,    56,    18,   281,    -1,    56,    18,
     278,    -1,    56,    18,   279,    -1,    56,    18,   284,    -1,
      56,    18,   285,    -1,    56,    18,   286,    -1,   144,    18,
     207,    -1,   144,    18,   208,    -1,   154,    18,   155,    -1,
      59,    12,   535,    19,   535,    13,    -1,    59,    12,   535,
      19,   535,    13,   123,   535,    -1,    65,    18,    83,    12,
      52,    19,   535,    19,   535,    13,    -1,    65,    18,    84,
      12,    53,    19,   535,    19,   535,    13,    -1,    65,    18,
      87,    12,   514,    19,    64,    13,    -1,    65,    18,    88,
      12,    54,    13,    -1,    65,    18,    89,    12,    53,    19,
     535,    13,    -1,    65,    18,    89,    12,    53,    13,    -1,
      65,    18,    90,    12,   535,    19,   514,    13,    -1,    65,
      18,    91,    12,    55,    19,   514,    13,    -1,    65,    18,
      92,    12,    55,    19,   514,    19,   514,    19,   514,    13,
      -1,    65,    18,   384,    -1,    65,    18,   384,    12,   535,
      13,    -1,   457,    12,   578,    13,    -1,   457,    12,   579,
      13,    -1,   536,    -1,    60,    18,   424,    12,   514,    13,
      -1,    60,    18,   425,    12,    52,    13,    -1,   519,    -1,
     521,   522,    -1,     9,   522,    -1,    11,   522,    -1,    10,
     522,    -1,   429,   522,    -1,   430,   522,    -1,   440,   522,
      -1,   441,   522,    -1,   442,   522,    -1,   443,   522,    -1,
     431,   522,    -1,   432,   522,    -1,   433,   522,    -1,   434,
     522,    -1,   437,   522,    -1,   439,   522,    -1,   438,   522,
      -1,     7,    -1,   498,    -1,   520,    -1,    12,   536,    13,
     520,    -1,   522,    -1,   523,     7,   522,    -1,   523,     8,
     522,    -1,   523,    -1,   524,    10,   523,    -1,   524,    11,
     523,    -1,   524,    -1,   525,    -1,   526,     6,   525,    -1,
     526,     5,   525,    -1,   526,   117,   525,    -1,   526,   118,
     525,    -1,   526,    -1,   527,   119,   526,    -1,   527,   120,
     526,    -1,   514,   119,   514,    -1,   514,   120,   514,    -1,
     527,    -1,   528,    16,   527,    -1,   528,    -1,   529,     4,
     528,    -1,   529,    -1,   530,    17,   529,    -1,   530,    -1,
     531,   115,   530,    -1,   531,    -1,   532,   116,   531,    -1,
     532,    -1,   532,    20,   532,    21,   533,    -1,   533,    -1,
     534,    -1,   406,    -1,   407,    -1,   408,    -1,   409,    -1,
     410,    -1,   411,    -1,   412,    -1,   413,    -1,   414,    -1,
     415,    -1,   537,    18,   416,    -1,    51,    -1,    68,    14,
     535,    15,    -1,    31,    47,    -1,    31,    12,   514,    13,
      -1,    32,    12,   535,    19,   535,    19,   536,    19,   535,
      19,   514,    19,   535,    19,   535,    13,    -1,    32,    12,
     535,    19,   535,    19,   535,    19,   536,    19,   535,    19,
     514,    13,    -1,    32,    12,   535,    19,   535,    19,   535,
      19,   536,    19,   535,    19,   535,    19,   514,    13,    -1,
     287,    12,   514,    13,    -1,   288,    12,   514,    13,    -1,
      63,    12,   509,    13,    -1,    31,    -1,    31,    12,   536,
      19,   535,    19,   535,    19,   535,    13,    -1,    31,    12,
     536,    19,   535,    19,   535,    19,   535,    19,   535,    13,
      -1,    31,    12,   536,    19,   535,    19,   537,    13,    -1,
     537,    -1,   537,    14,   535,    15,    -1,   240,    12,   556,
      19,   535,    13,    -1,   241,    12,   556,    19,   535,    13,
      -1,   242,    12,   556,    19,   535,    13,    -1,   243,    12,
     556,    19,   556,    19,   535,    13,    -1,   244,    12,   556,
      19,   556,    19,   535,    13,    -1,   125,    12,   556,    19,
     556,    13,    -1,   129,    12,   537,    19,    47,    13,    -1,
     129,    12,   537,    19,    47,    19,   536,    13,    -1,   129,
      12,   537,    19,   537,    19,    47,    13,    -1,   129,    12,
     537,    19,   537,    19,    47,    19,   536,    13,    -1,   129,
      12,   537,    19,   537,    19,   537,    19,    47,    13,    -1,
     129,    12,   537,    19,   537,    19,   537,    19,    47,    19,
     536,    13,    -1,   130,    12,   556,    19,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,   473,    18,   474,    12,
     537,    19,   535,    19,   535,    13,    -1,   320,    12,   537,
      13,    -1,   149,    12,   537,    19,   535,    19,   535,    19,
     535,    13,    -1,   321,    12,   537,    13,    -1,   224,    12,
     556,    19,   535,    13,    -1,   225,    12,   537,    13,    -1,
     226,    12,   537,    13,    -1,   227,    12,   537,    13,    -1,
     228,    12,   537,    19,   537,    19,   535,    19,   535,    19,
     535,    13,    -1,   229,    12,   537,    13,    -1,   230,    12,
     537,    19,   537,    19,   537,    19,   535,    19,   537,    13,
      -1,   231,    12,   537,    19,   537,    19,   537,    19,   535,
      19,   537,    13,    -1,   232,    12,   537,    19,   537,    19,
     537,    19,   535,    19,   537,    19,   535,    19,   535,    13,
      -1,   233,    12,   537,    19,   537,    19,   537,    19,   535,
      19,   537,    19,   535,    19,   535,    19,   535,    19,   535,
      13,    -1,   234,    12,   537,    19,   537,    19,   537,    19,
     537,    13,    -1,   234,    12,   537,    19,   537,    19,   537,
      19,   537,    19,   535,    13,    -1,   235,    12,   537,    13,
      -1,   235,    12,   537,    19,   537,    13,    -1,   236,    12,
     537,    19,   537,    13,    -1,   131,    12,   556,    19,   535,
      13,    -1,   132,    12,   537,    13,    -1,   148,    12,   537,
      13,    -1,   133,    12,   537,    19,   535,    13,    -1,   251,
      12,   537,    13,    -1,   134,    12,   537,    19,   535,    13,
      -1,   135,    12,   537,    19,   535,    13,    -1,   138,    12,
     556,    19,   535,    13,    -1,   537,    14,   580,    15,    -1,
     537,    14,    21,    19,    21,    19,   535,    21,   535,    15,
      -1,   136,    12,   537,    19,   535,    19,   535,    19,   535,
      19,   535,    19,   535,    19,   535,    13,    -1,   140,    12,
     537,    19,   535,    19,   535,    19,   535,    13,    -1,   140,
      12,   537,    19,   535,    19,   535,    13,    -1,   140,    12,
     537,    19,   535,    19,   535,    19,   535,    19,   535,    13,
      -1,   141,    12,   537,    19,   535,    19,   535,    19,   535,
      13,    -1,   141,    12,   537,    19,   535,    19,   535,    13,
      -1,   141,    12,   537,    19,   535,    19,   535,    19,   535,
      19,   535,    13,    -1,   142,    12,   537,    19,   535,    19,
     535,    13,    -1,   142,    12,   537,    19,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,   143,    12,   537,    19,
     535,    19,   535,    13,    -1,   143,    12,   537,    19,   535,
      19,   535,    19,   535,    19,   535,    13,    -1,   144,    18,
      45,    -1,   144,    18,    46,    -1,   154,    18,   199,    12,
     537,    19,   535,    13,    -1,   154,    18,   199,    12,   537,
      19,   537,    13,    -1,   154,    18,    45,    -1,   154,    18,
     164,    12,   537,    13,    -1,   144,    12,   537,    19,   535,
      19,   535,    19,   535,    19,   535,    13,    -1,   188,    12,
     537,    19,   537,    19,   535,    19,   535,    19,   535,    13,
      -1,   146,    12,   537,    19,   535,    19,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,   145,    12,   537,    19,
     535,    19,   535,    19,   535,    19,   535,    13,    -1,   189,
      18,   199,    12,   537,    19,   535,    19,   535,    19,   535,
      13,    -1,   190,    18,   199,    12,   537,    19,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    13,    -1,   191,
      12,   537,    13,    -1,   192,    12,   537,    19,   535,    19,
     535,    13,    -1,   192,    12,   537,    19,   535,    19,   535,
      19,   580,    13,    -1,   192,    12,   537,    19,   535,    19,
     535,    19,   535,    19,   580,    13,    -1,   193,    12,   537,
      19,   535,    19,   535,    19,   580,    13,    -1,   193,    12,
     537,    19,   535,    19,   535,    19,   535,    19,   580,    13,
      -1,   194,    12,   537,    19,   535,    19,   535,    19,   580,
      13,    -1,   195,    12,   537,    19,   535,    19,   535,    19,
     535,    19,   580,    13,    -1,   196,    12,   537,    19,   535,
      19,   535,    19,   535,    19,   580,    13,    -1,   197,    12,
     537,    19,   535,    19,   535,    19,   535,    19,   535,    19,
     580,    13,    -1,   198,    12,   537,    19,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,   203,    12,   537,    19,
     535,    19,   535,    13,    -1,   238,    12,   537,    19,   535,
      19,   535,    19,   535,    19,   535,    19,   535,    13,    -1,
     402,    12,   537,    13,    -1,   403,    12,   537,    13,    -1,
     404,    12,   537,    13,    -1,   405,    12,   537,    13,    -1,
      58,    18,   323,    -1,    58,    18,   324,    -1,    56,    18,
     323,    -1,   260,    12,   537,    19,   535,    13,    -1,   261,
      12,   537,    19,   535,    13,    -1,   262,    12,   537,    19,
     535,    13,    -1,   263,    12,   537,    19,   535,    13,    -1,
     186,    12,   556,    19,   556,    19,   535,    13,    -1,   187,
      12,   556,    19,   556,    19,   535,    19,   535,    19,   535,
      19,   535,    13,    -1,   186,    12,   556,    19,   556,    19,
     535,    19,   535,    19,   535,    13,    -1,   186,    12,   556,
      19,   556,    19,   535,    19,   535,    19,   535,    19,   535,
      13,    -1,   186,    12,   556,    19,   556,    19,   537,    19,
     535,    19,   535,    13,    -1,   289,    12,   537,    19,   537,
      13,    -1,   290,    12,   537,    19,   537,    19,   556,    13,
      -1,   294,    12,   537,    19,   535,    19,   535,    19,   535,
      13,    -1,   295,    12,   537,    19,   535,    19,   535,    19,
     535,    13,    -1,   295,    12,   537,    19,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,   296,    12,   537,    19,
     535,    13,    -1,   297,    12,   537,    19,   535,    13,    -1,
     298,    12,   537,    19,   535,    13,    -1,   299,    12,   537,
      19,   535,    13,    -1,   300,    12,   537,    19,   535,    13,
      -1,   301,    12,   537,    19,   535,    13,    -1,   302,    12,
     537,    19,   535,    13,    -1,   303,    12,   537,    19,   535,
      13,    -1,   303,    12,   537,    19,   535,    19,   535,    13,
      -1,   304,    12,   537,    19,   535,    19,   535,    19,   535,
      13,    -1,   305,    12,   556,    13,    -1,   537,    12,   556,
      13,    -1,   419,    12,   556,    19,   535,    19,   535,    19,
     535,    13,    -1,   420,    12,   556,    19,   535,    19,   535,
      19,   535,    13,    -1,   467,    12,   556,    13,    -1,   467,
      12,   556,    19,   535,    13,    -1,   470,    12,   556,    19,
     535,    13,    -1,   468,    12,   556,    19,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,   469,    12,   537,    19,
     537,    19,   535,    19,   535,    19,   535,    19,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    19,   535,    19,
     535,    19,   535,    19,   535,    13,    -1,   472,    12,   556,
      19,   535,    19,   535,    13,    -1,   576,    18,   357,    12,
      13,    -1,   576,    18,   358,    12,    13,    -1,   576,    18,
     359,    12,    13,    -1,   576,    18,   356,    12,   537,    13,
      -1,   478,    12,   556,    19,   535,    13,    -1,   478,    12,
     556,    13,    -1,   479,    12,   556,    19,   535,    13,    -1,
     479,    12,   556,    13,    -1,   484,    12,   556,    19,   556,
      13,    -1,   485,    12,   556,    13,    -1,   486,    12,   514,
      13,    -1,   458,    12,   556,    19,   535,    19,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    19,   535,    13,
      -1,   268,    12,   576,    19,   537,    19,   556,    13,    -1,
     270,    12,   576,    19,   514,    13,    -1,   538,    -1,    12,
     556,    13,    -1,   539,    -1,   540,    -1,   521,   542,    -1,
      11,   542,    -1,    10,   542,    -1,   429,   542,    -1,   430,
     542,    -1,   440,   542,    -1,   441,   542,    -1,   442,   542,
      -1,   443,   542,    -1,   431,   542,    -1,   432,   542,    -1,
     433,   542,    -1,   434,   542,    -1,   437,   542,    -1,   439,
     542,    -1,   438,   542,    -1,   444,   542,    -1,   541,    -1,
      12,   536,    13,   541,    -1,   542,    -1,   543,     7,   522,
      -1,   543,     8,   522,    -1,   543,     7,   542,    -1,   543,
       8,   542,    -1,   543,     4,   542,    -1,   543,    -1,   544,
      -1,   545,    10,   523,    -1,   545,    11,   523,    -1,   545,
      10,   543,    -1,   545,    11,   543,    -1,   545,    -1,   546,
      -1,   547,     6,   546,    -1,   547,     5,   546,    -1,   547,
     117,   546,    -1,   547,   118,   546,    -1,   547,     6,   525,
      -1,   547,     5,   525,    -1,   547,   117,   525,    -1,   547,
     118,   525,    -1,   547,    -1,   548,   119,   547,    -1,   548,
     120,   547,    -1,   548,   119,   525,    -1,   548,   120,   525,
      -1,   548,    -1,   549,    16,   548,    -1,   549,    -1,   550,
      -1,   551,    17,   550,    -1,   551,    -1,   552,   115,   551,
      -1,   552,    -1,   553,   116,   552,    -1,   553,    -1,   553,
      20,   553,    21,   554,    -1,   554,    -1,   541,   123,   555,
      -1,   555,    -1,    66,    -1,    58,    18,   375,    -1,   377,
      12,    66,    19,    66,    19,   535,    13,    -1,    33,    12,
     514,    13,    -1,   378,    12,   535,    19,   535,    13,    -1,
      59,    -1,   379,    12,   575,    13,    -1,   558,    -1,    12,
     575,    13,    -1,   559,    -1,   560,    -1,   521,   562,    -1,
      11,   562,    -1,    10,   562,    -1,   562,   121,    -1,   429,
     562,    -1,   430,   562,    -1,   440,   562,    -1,   441,   562,
      -1,   442,   562,    -1,   443,   562,    -1,   431,   562,    -1,
     432,   562,    -1,   433,   562,    -1,   434,   562,    -1,   437,
     562,    -1,   439,   562,    -1,   438,   562,    -1,   561,    -1,
     562,    -1,   563,     7,   522,    -1,   563,   122,   562,    -1,
     563,     7,   562,    -1,   563,    -1,   564,    10,   523,    -1,
     564,    11,   523,    -1,   564,    10,   563,    -1,   564,    11,
     563,    -1,   564,    -1,   565,    -1,   566,    -1,   567,    -1,
     568,    -1,   569,    -1,   570,    -1,   571,    -1,   572,    -1,
     573,    -1,   574,    -1,    57,    -1,    67,    14,   535,    15,
      -1,   310,    12,   556,    19,   535,    13,    -1,   313,    12,
     537,    19,   535,    13,    -1,   310,    12,   556,    19,   535,
      19,   537,    13,    -1,   319,    12,   556,    19,   535,    19,
     556,    13,    -1,   314,    12,   576,    13,    -1,   314,    12,
     576,    19,   535,    13,    -1,   315,    12,   537,    19,   535,
      13,    -1,   316,    12,   576,    19,   535,    13,    -1,   318,
      12,   576,    19,   535,    13,    -1,   322,    12,    13,    -1,
     322,    47,    -1,   322,    12,   514,    13,    -1,   322,    -1,
     269,    12,   514,    13,    -1,   269,    12,   514,    19,   535,
      13,    -1,   576,    -1,   255,    12,   537,    13,    -1,   256,
      12,   576,    13,    -1,   256,    12,   576,    19,   535,    19,
     535,    19,   535,    13,    -1,   257,    12,   576,    19,   535,
      13,    -1,   264,    12,   576,    19,   535,    19,   535,    19,
     535,    19,   535,    19,   535,    19,   535,    13,    -1,   265,
      12,   556,    19,   535,    19,   535,    19,   535,    19,   535,
      19,   535,    19,   535,    19,   535,    13,    -1,   266,    12,
     556,    19,   535,    19,   535,    19,   535,    13,    -1,   267,
      12,   556,    19,   535,    19,   535,    19,   535,    19,   535,
      19,   535,    19,   535,    19,   535,    19,   535,    13,    -1,
     576,    18,   259,    12,   535,    19,   535,    13,    -1,   475,
      12,   556,    13,    -1,   475,    12,   556,    19,   535,    13,
      -1,   475,    12,   556,    19,   535,    19,   535,    13,    -1,
     477,    12,   556,    19,   535,    19,   535,    13,    -1,   476,
      12,   556,    19,   535,    19,   535,    19,   556,    19,   556,
      13,    -1,   476,    12,   556,    19,   535,    19,   535,    19,
     556,    19,   556,    19,   556,    19,   535,    13,    -1,   481,
      12,   556,    19,   556,    19,   556,    19,   535,    19,   535,
      19,   535,    19,   535,    13,    -1,   481,    12,   556,    19,
     556,    19,   556,    19,   535,    19,   535,    19,   535,    19,
     535,    19,   535,    13,    -1,   481,    12,   556,    19,   556,
      19,   556,    19,   535,    19,   535,    19,   535,    13,    -1,
     481,    12,   556,    19,   535,    19,   535,    19,   535,    19,
     535,    19,   535,    13,    -1,   483,    12,   556,    19,   556,
      19,   556,    19,   535,    19,   535,    19,   535,    19,   535,
      13,    -1,   483,    12,   556,    19,   556,    19,   556,    19,
     535,    19,   535,    19,   535,    19,   535,    19,   556,    19,
     556,    13,    -1,    50,    -1,    53,    -1,    52,    -1,   537,
      -1,    56,    -1,    57,    -1,    58,    -1,    60,    -1,    61,
      -1,    62,    -1,    63,    -1,    64,    -1,    55,    -1,    59,
      -1,    66,    -1,    65,    -1,    67,    -1,    68,    -1,   535,
      21,   535,    19,   535,    21,   535,    19,   535,    21,   535,
      -1,   535,    21,   535,    19,   535,    21,   535,    -1,   537,
      -1,    56,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     9,    12,    15,    19,    21,
      24,    26,    29,    31,    34,    36,    39,    41,    43,    52,
      63,    66,    71,    78,    79,    88,    92,    94,   100,   103,
     105,   107,   109,   111,   113,   115,   120,   127,   134,   141,
     148,   152,   156,   163,   170,   174,   178,   182,   186,   193,
     197,   201,   208,   215,   222,   226,   230,   239,   248,   252,
     254,   256,   258,   260,   265,   267,   270,   273,   276,   278,
     282,   286,   290,   297,   304,   321,   324,   327,   331,   334,
     337,   341,   345,   348,   351,   355,   358,   361,   367,   370,
     372,   374,   377,   380,   385,   388,   391,   394,   396,   401,
     405,   408,   411,   422,   429,   433,   440,   447,   456,   485,
     494,   503,   507,   516,   529,   536,   543,   560,   569,   586,
     597,   604,   615,   624,   635,   650,   659,   672,   679,   688,
     695,   702,   709,   720,   727,   738,   749,   762,   769,   776,
     789,   796,   803,   810,   817,   824,   831,   838,   845,   852,
     859,   866,   873,   882,   886,   890,   894,   898,   902,   906,
     919,   936,   943,   950,   957,   964,   971,   978,   985,   992,
     999,  1006,  1017,  1024,  1039,  1046,  1055,  1062,  1069,  1078,
    1085,  1096,  1103,  1110,  1117,  1124,  1131,  1138,  1145,  1152,
    1159,  1166,  1173,  1177,  1181,  1186,  1190,  1197,  1204,  1209,
    1214,  1221,  1232,  1243,  1254,  1261,  1268,  1275,  1282,  1289,
    1300,  1307,  1318,  1325,  1332,  1339,  1343,  1350,  1357,  1368,
    1379,  1386,  1393,  1400,  1404,  1408,  1412,  1416,  1423,  1430,
    1434,  1441,  1448,  1457,  1468,  1472,  1479,  1483,  1488,  1509,
    1516,  1527,  1534,  1538,  1542,  1549,  1553,  1560,  1569,  1576,
    1583,  1592,  1609,  1616,  1620,  1627,  1636,  1640,  1653,  1666,
    1679,  1690,  1699,  1708,  1719,  1728,  1739,  1752,  1759,  1768,
    1777,  1788,  1805,  1824,  1837,  1844,  1863,  1880,  1893,  1904,
    1915,  1926,  1933,  1944,  1951,  1958,  1965,  1974,  1976,  1981,
    1986,  1995,  2000,  2019,  2024,  2026,  2028,  2035,  2042,  2046,
    2050,  2057,  2064,  2068,  2072,  2076,  2080,  2084,  2088,  2092,
    2101,  2108,  2115,  2122,  2126,  2131,  2133,  2135,  2137,  2139,
    2141,  2172,  2197,  2202,  2211,  2212,  2214,  2218,  2220,  2224,
    2227,  2232,  2235,  2240,  2242,  2246,  2249,  2254,  2257,  2262,
    2264,  2268,  2269,  2272,  2275,  2278,  2281,  2284,  2289,  2294,
    2299,  2304,  2309,  2311,  2313,  2315,  2322,  2324,  2328,  2330,
    2334,  2338,  2340,  2344,  2345,  2346,  2348,  2350,  2352,  2354,
    2356,  2358,  2360,  2364,  2366,  2371,  2378,  2387,  2398,  2409,
    2418,  2425,  2429,  2433,  2437,  2441,  2445,  2449,  2456,  2461,
    2472,  2477,  2488,  2493,  2498,  2503,  2508,  2513,  2518,  2526,
    2534,  2542,  2552,  2560,  2567,  2572,  2576,  2580,  2584,  2588,
    2592,  2596,  2600,  2604,  2608,  2612,  2616,  2620,  2627,  2636,
    2647,  2658,  2667,  2674,  2683,  2690,  2699,  2708,  2721,  2725,
    2732,  2737,  2742,  2744,  2751,  2758,  2760,  2763,  2766,  2769,
    2772,  2775,  2778,  2781,  2784,  2787,  2790,  2793,  2796,  2799,
    2802,  2805,  2808,  2811,  2813,  2815,  2817,  2822,  2824,  2828,
    2832,  2834,  2838,  2842,  2844,  2846,  2850,  2854,  2858,  2862,
    2864,  2868,  2872,  2876,  2880,  2882,  2886,  2888,  2892,  2894,
    2898,  2900,  2904,  2906,  2910,  2912,  2918,  2920,  2922,  2924,
    2926,  2928,  2930,  2932,  2934,  2936,  2938,  2940,  2942,  2946,
    2948,  2953,  2956,  2961,  2978,  2993,  3010,  3015,  3020,  3025,
    3027,  3038,  3051,  3060,  3062,  3067,  3074,  3081,  3088,  3097,
    3106,  3113,  3120,  3129,  3138,  3149,  3160,  3173,  3186,  3197,
    3202,  3213,  3218,  3225,  3230,  3235,  3240,  3253,  3258,  3271,
    3284,  3301,  3322,  3333,  3346,  3351,  3358,  3365,  3372,  3377,
    3382,  3389,  3394,  3401,  3408,  3415,  3420,  3431,  3448,  3459,
    3468,  3481,  3492,  3501,  3514,  3523,  3536,  3545,  3558,  3562,
    3566,  3575,  3584,  3588,  3595,  3608,  3621,  3636,  3649,  3662,
    3679,  3684,  3693,  3704,  3717,  3728,  3741,  3752,  3765,  3778,
    3793,  3806,  3815,  3830,  3835,  3840,  3845,  3850,  3854,  3858,
    3862,  3869,  3876,  3883,  3890,  3899,  3914,  3927,  3942,  3955,
    3962,  3971,  3982,  3993,  4006,  4013,  4020,  4027,  4034,  4041,
    4048,  4055,  4062,  4071,  4082,  4087,  4092,  4103,  4114,  4119,
    4126,  4133,  4146,  4177,  4186,  4192,  4198,  4204,  4211,  4218,
    4223,  4230,  4235,  4242,  4247,  4252,  4271,  4280,  4287,  4289,
    4293,  4295,  4297,  4300,  4303,  4306,  4309,  4312,  4315,  4318,
    4321,  4324,  4327,  4330,  4333,  4336,  4339,  4342,  4345,  4348,
    4350,  4355,  4357,  4361,  4365,  4369,  4373,  4377,  4379,  4381,
    4385,  4389,  4393,  4397,  4399,  4401,  4405,  4409,  4413,  4417,
    4421,  4425,  4429,  4433,  4435,  4439,  4443,  4447,  4451,  4453,
    4457,  4459,  4461,  4465,  4467,  4471,  4473,  4477,  4479,  4485,
    4487,  4491,  4493,  4495,  4499,  4508,  4513,  4520,  4522,  4527,
    4529,  4533,  4535,  4537,  4540,  4543,  4546,  4549,  4552,  4555,
    4558,  4561,  4564,  4567,  4570,  4573,  4576,  4579,  4582,  4585,
    4588,  4590,  4592,  4596,  4600,  4604,  4606,  4610,  4614,  4618,
    4622,  4624,  4626,  4628,  4630,  4632,  4634,  4636,  4638,  4640,
    4642,  4644,  4646,  4651,  4658,  4665,  4674,  4683,  4688,  4695,
    4702,  4709,  4716,  4720,  4723,  4728,  4730,  4735,  4742,  4744,
    4749,  4754,  4765,  4772,  4789,  4808,  4819,  4840,  4849,  4854,
    4861,  4870,  4879,  4892,  4909,  4926,  4945,  4960,  4975,  4992,
    5013,  5015,  5017,  5019,  5021,  5023,  5025,  5027,  5029,  5031,
    5033,  5035,  5037,  5039,  5041,  5043,  5045,  5047,  5049,  5061,
    5069,  5071
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   917,   917,   918,   922,   922,   923,   924,   925,   925,
     926,   926,   927,   927,   928,   928,   931,   932,   937,   955,
     977,   999,  1014,  1035,  1034,  1060,  1077,  1111,  1154,  1169,
    1177,  1181,  1195,  1209,  1223,  1233,  1250,  1270,  1280,  1290,
    1300,  1310,  1319,  1334,  1356,  1366,  1375,  1380,  1390,  1413,
    1423,  1441,  1463,  1470,  1477,  1484,  1492,  1523,  1539,  1544,
    1548,  1552,  1557,  1561,  1565,  1568,  1607,  1627,  1656,  1673,
    1686,  1706,  1719,  1754,  1784,  1802,  1806,  1810,  1814,  1818,
    1822,  1826,  1830,  1834,  1838,  1843,  1847,  1856,  1865,  1870,
    1878,  1890,  2138,  2192,  2200,  2209,  2219,  2225,  2231,  2238,
    2244,  2254,  2264,  2280,  2292,  2302,  2351,  2366,  2387,  2418,
    2433,  2440,  2447,  2465,  2488,  2493,  2498,  2511,  2522,  2531,
    2540,  2548,  2565,  2581,  2598,  2618,  2633,  2651,  2664,  2678,
    2687,  2701,  2712,  2725,  2743,  2765,  2790,  2820,  2852,  2857,
    2875,  2880,  2885,  2890,  2895,  2900,  2914,  2929,  2946,  2960,
    2980,  2985,  2990,  2997,  3006,  3014,  3019,  3026,  3031,  3036,
    3056,  3080,  3085,  3090,  3095,  3100,  3105,  3110,  3115,  3120,
    3125,  3130,  3135,  3140,  3145,  3150,  3155,  3160,  3165,  3170,
    3175,  3183,  3188,  3193,  3198,  3203,  3208,  3213,  3218,  3223,
    3228,  3233,  3238,  3243,  3247,  3274,  3287,  3292,  3296,  3302,
    3315,  3321,  3327,  3333,  3340,  3347,  3354,  3365,  3376,  3391,
    3406,  3414,  3423,  3432,  3440,  3444,  3448,  3485,  3494,  3501,
    3508,  3519,  3527,  3545,  3555,  3560,  3567,  3574,  3582,  3590,
    3609,  3625,  3642,  3659,  3664,  3669,  3674,  3679,  3687,  3788,
    3822,  3829,  3837,  3843,  3850,  3860,  3869,  3876,  3883,  3893,
    3900,  3914,  3928,  3936,  3941,  3949,  3957,  3968,  3980,  3992,
    4004,  4010,  4023,  4030,  4041,  4063,  4089,  4117,  4127,  4140,
    4150,  4163,  4192,  4209,  4224,  4231,  4253,  4272,  4290,  4304,
    4309,  4314,  4323,  4328,  4337,  4351,  4358,  4365,  4367,  4384,
    4400,  4434,  4447,  4491,  4496,  4501,  4507,  4521,  4528,  4534,
    4540,  4547,  4554,  4560,  4566,  4572,  4578,  4584,  4596,  4602,
    4619,  4626,  4637,  4644,  4649,  4655,  4660,  4665,  4670,  4675,
    4680,  4715,  4742,  4749,  4771,  4775,  4782,  4789,  4797,  4805,
    4814,  4821,  4828,  4835,  4842,  4849,  4856,  4863,  4870,  4877,
    4884,  4894,  4899,  4905,  4911,  4917,  4923,  4929,  4935,  4941,
    4947,  4953,  4960,  4965,  4977,  4982,  4996,  5009,  5016,  5017,
    5027,  5035,  5038,  5049,  5050,  5053,  5054,  5062,  5070,  5079,
    5083,  5088,  5092,  5100,  5101,  5116,  5132,  5136,  5153,  5169,
    5183,  5196,  5217,  5276,  5296,  5314,  5321,  5329,  5334,  5339,
    5367,  5373,  5384,  5404,  5424,  5442,  5462,  5480,  5498,  5521,
    5544,  5567,  5574,  5599,  5622,  5629,  5639,  5649,  5659,  5669,
    5679,  5689,  5703,  5720,  5736,  5741,  5746,  5750,  5757,  5765,
    5800,  5813,  5823,  5840,  5859,  5875,  5893,  5913,  5934,  5947,
    5960,  5968,  5976,  5980,  5988,  5998,  5999,  6000,  6001,  6002,
    6003,  6004,  6005,  6006,  6007,  6008,  6016,  6017,  6018,  6019,
    6020,  6021,  6022,  6027,  6028,  6032,  6034,  6050,  6051,  6052,
    6056,  6057,  6058,  6062,  6067,  6068,  6069,  6070,  6071,  6075,
    6076,  6077,  6078,  6079,  6083,  6084,  6092,  6093,  6097,  6101,
    6108,  6112,  6119,  6123,  6130,  6131,  6138,  6142,  6148,  6153,
    6157,  6161,  6165,  6169,  6173,  6177,  6181,  6185,  6189,  6197,
    6202,  6219,  6225,  6231,  6289,  6343,  6399,  6420,  6441,  6455,
    6484,  6492,  6511,  6537,  6550,  6628,  6695,  6703,  6711,  6721,
    6731,  6761,  6779,  6799,  6817,  6837,  6855,  6874,  6914,  6929,
    6943,  6959,  6982,  6996,  7010,  7024,  7038,  7073,  7087,  7108,
    7129,  7170,  7216,  7233,  7252,  7266,  7280,  7294,  7313,  7328,
    7343,  7360,  7381,  7398,  7414,  7426,  7454,  7474,  7519,  7531,
    7542,  7555,  7567,  7578,  7604,  7631,  7663,  7680,  7698,  7711,
    7724,  7744,  7767,  7781,  7796,  7830,  7867,  7902,  7935,  7952,
    7969,  7983,  8004,  8027,  8051,  8076,  8101,  8123,  8145,  8169,
    8212,  8236,  8268,  8282,  8319,  8356,  8393,  8428,  8433,  8442,
    8447,  8458,  8468,  8478,  8487,  8508,  8538,  8566,  8597,  8632,
    8643,  8659,  8669,  8679,  8694,  8708,  8722,  8735,  8748,  8760,
    8772,  8784,  8795,  8808,  8835,  8868,  8976,  9000,  9042,  9055,
    9066,  9075,  9099,  9124,  9137,  9147,  9157,  9167,  9177,  9187,
    9195,  9203,  9211,  9238,  9259,  9267,  9305,  9328,  9348,  9348,
    9350,  9352,  9353,  9354,  9355,  9356,  9357,  9358,  9359,  9360,
    9361,  9362,  9363,  9364,  9365,  9366,  9367,  9368,  9369,  9385,
    9386,  9410,  9411,  9417,  9419,  9420,  9421,  9424,  9429,  9430,
    9431,  9432,  9433,  9436,  9440,  9441,  9442,  9443,  9444,  9445,
    9446,  9447,  9448,  9452,  9453,  9454,  9455,  9456,  9460,  9461,
    9466,  9470,  9471,  9475,  9476,  9480,  9481,  9485,  9486,  9490,
    9491,  9494,  9498,  9508,  9521,  9532,  9549,  9556,  9566,  9581,
    9581,  9583,  9585,  9586,  9587,  9588,  9589,  9598,  9599,  9600,
    9601,  9602,  9603,  9604,  9605,  9606,  9607,  9608,  9609,  9610,
    9614,  9616,  9617,  9618,  9619,  9629,  9630,  9631,  9632,  9633,
    9636,  9640,  9644,  9648,  9653,  9657,  9661,  9665,  9669,  9673,
    9676,  9681,  9686,  9703,  9715,  9727,  9739,  9772,  9781,  9790,
    9799,  9808,  9817,  9823,  9829,  9835,  9861,  9875,  9891,  9901,
    9919,  9947,  9974,  9989, 10006, 10040, 10072, 10118, 10144, 10154,
   10177, 10189, 10202, 10242, 10287, 10337, 10390, 10436, 10465, 10498,
   10539, 10543, 10544, 10545, 10549, 10550, 10551, 10552, 10553, 10554,
   10555, 10556, 10557, 10558, 10559, 10560, 10561, 10562, 10567, 10575,
   10582, 10598
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
       2,     2,     2,     2,     2,     2,   498,     2,     2,     2,
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
     495,   496,   497
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 15690;
  const int Parser::yynnts_ = 82;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 361;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 499;

  const unsigned int Parser::yyuser_token_number_max_ = 752;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

} // namespace yyip

#line 10618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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


//------------------------------------------------------
void wxScheduleTimer::Notify()
//   -----------------------
{
  cout << "Notify()" << endl;
  CB_ParamWin(&f);

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





