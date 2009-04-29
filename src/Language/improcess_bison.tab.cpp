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


/* Line 317 of lalr1.cc.  */
#line 45 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.tab.cpp"

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
    #line 403 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}
  /* Line 547 of yacc.c.  */
#line 282 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.tab.cpp"
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
	  case 4:
#line 904 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
       gr_print("list_command : command\n ");
     ;}
    break;

  case 5:
#line 908 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
       gr_print("list_command : list_commands command\n ");
     ;}
    break;

  case 14:
#line 918 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
                      yyiplineno++;
        ;}
    break;

  case 16:
#line 927 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=yyiplineno;
       int* varint;
        AmiInstructionBlock_ptr block((yysemantic_stack_[(8) - (7)].ablock));

      varint = new int;
      Vars.AddVar(type_int,(yysemantic_stack_[(8) - (2)].ident),(void*)varint);
      gr_print("command : FOR identifier ASSIGN_OP ");
      gr_print("expr TO expr instr_block\n ");

      //          printf(" block = %s \n",$7);
      driver.yyip_switch_to_block(block);
      for(*varint = (int) (yysemantic_stack_[(8) - (4)].adouble); *varint <= (int) (yysemantic_stack_[(8) - (6)].adouble); (*varint)++)
        {

          yyiplineno = block->GetStartingLine();
          yyip_reinit_current_buffer();
          yyip_parse();

        }
      yyip_popup_buffer();
      Vars.deleteVar((yysemantic_stack_[(8) - (2)].ident));
      //      free($7);
      yyiplineno=previous_lineno;
      continue_parse();
    ;}
    break;

  case 17:
#line 956 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=yyiplineno;
       float* var;
        AmiInstructionBlock_ptr block((yysemantic_stack_[(10) - (9)].ablock));

      var = new float;
      Vars.AddVar(type_float,(yysemantic_stack_[(10) - (2)].ident),(void*)var);

      driver.yyip_switch_to_block(block);
      for(*var = (yysemantic_stack_[(10) - (4)].adouble); *var <= (yysemantic_stack_[(10) - (6)].adouble); (*var)+=(yysemantic_stack_[(10) - (8)].adouble))
        {

          yyiplineno = block->GetStartingLine();
          //yyiplineno=previous_lineno;
          yyip_reinit_current_buffer();
          yyip_parse();

        }
      yyip_popup_buffer();
      Vars.deleteVar((yysemantic_stack_[(10) - (2)].ident));
      yyiplineno=previous_lineno;
      continue_parse();
    ;}
    break;

  case 18:
#line 981 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=yyiplineno;
        AmiInstructionBlock_ptr block((yysemantic_stack_[(2) - (2)].ablock));


      //          printf(" block = %s \n",$7);
          int res;
      //yyiplineno = $2->GetStartingLine();
      driver.yyip_switch_to_block(block);
      do {

          //yyiplineno=previous_lineno;
          yyiplineno = block->GetStartingLine();
          yyip_reinit_current_buffer();
          res=yyip_parse();

      } while (!res);
      yyip_popup_buffer();
      yyiplineno = previous_lineno;
      continue_parse();
    ;}
    break;

  case 19:
#line 1006 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno;
      AmiInstructionBlock_ptr block((yysemantic_stack_[(4) - (3)].ablock));

      gr_print("command : IF expr instr_block  \n");

      // Pb with line numbers
      previous_lineno=yyiplineno;

        if ((yysemantic_stack_[(4) - (2)].adouble)>0.5)
        {
          //yyiplineno=previous_lineno;
          driver.yyip_switch_to_block(block);
          yyip_parse();
          yyip_popup_buffer();
          yyiplineno = previous_lineno;
          continue_parse();
        }
    ;}
    break;

  case 20:
#line 1026 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno = yyiplineno;

      AmiInstructionBlock_ptr block_if(  (yysemantic_stack_[(6) - (3)].ablock));
      AmiInstructionBlock_ptr block_else((yysemantic_stack_[(6) - (5)].ablock));

      gr_print("command : IF expr instr_block ELSE instr_block \n");

      // Pb with line numbers
      previous_lineno=yyiplineno;

        if ((yysemantic_stack_[(6) - (2)].adouble)>0.5)
        {
          driver.yyip_switch_to_block(block_if);
          yyip_parse();
          yyip_popup_buffer();
        }
      else
        {
          driver.yyip_switch_to_block(block_else);
          yyip_parse();
          yyip_popup_buffer();
        }
      yyiplineno = previous_lineno;
      continue_parse();

    ;}
    break;

  case 21:
#line 1059 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      AMIFunction* amifunc;
      AmiInstructionBlock_ptr body((yysemantic_stack_[(7) - (6)].ablock));

      amifunc = new AMIFunction;

      amifunc->SetName((yysemantic_stack_[(7) - (2)].ident));
      amifunc->SetFileName(GB_current_file);
      amifunc->SetParamList((yysemantic_stack_[(7) - (4)].paramlistdecl));
      amifunc->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", (yysemantic_stack_[(7) - (2)].ident),body->GetBody().c_str());

      Vars.AddVar( type_ami_function, (yysemantic_stack_[(7) - (2)].ident), (void*) amifunc);

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      procedure_declaration = 0;
    ;}
    break;

  case 22:
#line 1080 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        int previous_lineno;
        string current_filename;

       previous_lineno=yyiplineno;
       current_filename = GB_current_file;

        res_print((yysemantic_stack_[(3) - (2)].astring));
       if (yyip_switch_to_file((yysemantic_stack_[(3) - (2)].astring))) {
         delete [] (yysemantic_stack_[(3) - (2)].astring);
         yyiplineno=1;
         yyip_parse();
         yyip_popup_buffer( );

         GB_current_file = current_filename;
         yyiplineno=previous_lineno;
         continue_parse();
       }

     ;}
    break;

  case 23:
#line 1102 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          //cout << "current wd = "  <<  wxGetCwd() << endl; 
          res=AskScript(name);
          if (!res) {
            yyiperror(" Need script \n");
            YYABORT;
          }
          //cout << "current wd = "  <<  wxGetCwd() << endl; 

        int previous_lineno;
        string current_filename;

       previous_lineno=yyiplineno;
       current_filename = GB_current_file;

        res_print(name.c_str());
        res_print("\n");
       if (yyip_switch_to_file((char*)name.c_str())) {
         yyiplineno=1;
         yyip_parse();
         yyip_popup_buffer( );

         GB_current_file = current_filename;
         yyiplineno=previous_lineno;
         continue_parse();
       }

        // convert path delimiters to avoid pbs with \ character
        wxFileName filename(GetwxStr(name.c_str()),wxPATH_NATIVE);
        filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
        wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                            filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX));
        res_print( newname.mb_str());
        res_print("\n");
          inc_cmd = str(format(" \"%1%\" // from browser ") % newname.c_str());
          if (yy_num_buf==1)
            GB_main_wxFrame->GetConsole()
                           ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      ;}
    break;

  case 24:
#line 1146 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        continue_parse();
      }

        ;}
    break;

  case 25:
#line 1190 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Variable*    var   = (yysemantic_stack_[(2) - (1)].variable);
          AMIFunction_ptr f;

          f = *(AMIFunction_ptr*) (var->Pointer());

          // Call the function
          Vars.NewContext(f->GetName().c_str());
          driver.yyip_call_function(f);
          Vars.DeleteLastContext();
          continue_parse();
        ;}
    break;

  case 26:
#line 1205 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         ;}
    break;

  case 27:
#line 1213 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         ;}
    break;

  case 28:
#line 1218 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 29:
#line 1232 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 30:
#line 1246 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 31:
#line 1260 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
         ;}
    break;

  case 32:
#line 1270 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 33:
#line 1289 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 34:
#line 1314 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
            VarArray* arraysurf;
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            arraysurf = new VarArray();
            arraysurf->Init(type_surface,size);
            Vars.AddVar(type_array,(yysemantic_stack_[(6) - (1)].ident),arraysurf);
          ;}
    break;

  case 35:
#line 1324 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
            VarArray* arraysurf;
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            arraysurf = new VarArray();
            arraysurf->Init(type_surface,size);
            Vars.AddVar(type_array,(yysemantic_stack_[(6) - (1)].ident),arraysurf);
          ;}
    break;

  case 36:
#line 1334 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
            VarArray* array;
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            array = new VarArray();
            array->Init(type_image,size);
            Vars.AddVar(type_array,(yysemantic_stack_[(6) - (1)].ident),array);
          ;}
    break;

  case 37:
#line 1344 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)im_stack.GetLastImage();
          if (imptr != NULL)
            Vars.AddVar(type_image,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
            err_print("assignment of NULL image\n");

          gr_print("command : identifier ASSIGN_OP image\n ");
        ;}
    break;

  case 38:
#line 1356 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)im_stack.GetLastImage();
          if (imptr != NULL)
            Vars.AddVar(type_image,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
            err_print("assignment of NULL image\n");

          gr_print("command : identifier ASSIGN_OP image\n ");
        ;}
    break;

  case 39:
#line 1367 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Variable*      var   = (yysemantic_stack_[(6) - (3)].variable);
          ParamList::ptr param((yysemantic_stack_[(6) - (5)].paramlist));
          Variable::ptr  res;

          res = ((Variable::ptr (*)(ParamList*)) var->Pointer())(param.get());
          if (!res.use_count()) {
            yyiperror(" function returns NULL \n");
            YYABORT;
          }
          res->Rename((yysemantic_stack_[(6) - (1)].ident));
          Vars.AddVar(res);
        ;}
    break;

  case 40:
#line 1382 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          void * imptr = (void*)im_stack.GetLastImage();
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
              err_print("array element already assigned\n");
              delete (InrImage*)imptr;
            }
          else
            err_print("assignment of NULL image\n");

          gr_print("command : identifier ASSIGN_OP image\n ");
        ;}
    break;

  case 41:
#line 1406 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*) matrix_stack.GetLastMatrix();
          if (imptr != NULL)
        Vars.AddVar(type_matrix,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
        err_print("assignment of NULL matrix\n");

          gr_print("command : identifier ASSIGN_OP matrix\n ");
        ;}
    break;

  case 42:
#line 1418 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)gltransf_stack.GetLastMatrix();
          if (imptr != NULL)
            Vars.AddVar(type_gltransform,(yysemantic_stack_[(3) - (1)].ident),imptr);
          else
            err_print("assignment of NULL matrix\n");

          gr_print("command : identifier ASSIGN_OP matrix\n ");
        ;}
    break;

  case 43:
#line 1429 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       ;}
    break;

  case 44:
#line 1434 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          FloatMatrix* m2 = matrix_stack.GetLastMatrix();
          (*m1) = m2;
          printf("delete m2\n");
          delete m2;
          printf("delete m2 end\n");
       ;}
    break;

  case 45:
#line 1444 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          void * surfptr;
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          array = *((VarArray::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer()));
          surfptr = (void*)surf_stack.GetLastSurf();
          if (surfptr != NULL)
          if (array->GetVar(i).Pointer()==NULL) {
            sprintf(name,"%s[%d]",(yysemantic_stack_[(6) - (1)].variable)->Name(),i);
            array->InitElement(i,surfptr,name);
          }
          else
          {
            err_print("array element already assigned\n");
            delete (SurfacePoly*)surfptr;
          }
          else
            err_print("assignment of NULL surface\n");

          gr_print("command : identifier ASSIGN_OP surface\n ");
        ;}
    break;

  case 46:
#line 1469 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          void * surfptr;
          surfptr = (void*)surf_stack.GetLastSurf();
          if (surfptr != NULL)
            Vars.AddVar(type_surface,(yysemantic_stack_[(3) - (1)].ident),surfptr);
          else
            err_print("assignment of NULL surface\n");

          gr_print("command : identifier ASSIGN_OP surface\n ");
        ;}
    break;

  case 47:
#line 1481 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Variable* var = (yysemantic_stack_[(3) - (1)].variable);
          void* surfptr  = (void*) surf_stack.GetLastSurf();

          // instead of deleting and creating,
          // replace the pointer and the information
          if (surfptr != NULL) {
            var->FreeMemory();
            var->Init(type_surface,
                      var->Name(),
                      surfptr);
          }
          else
            err_print("assignment of NULL surface\n");

        ;}
    break;

  case 48:
#line 1499 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
            err_print("not able to create surface array !\n");

        ;}
    break;

  case 49:
#line 1521 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          int* varint;
          varint = new int((int)(yysemantic_stack_[(6) - (5)].adouble));
          Vars.AddVar(type_int,(yysemantic_stack_[(6) - (1)].ident),(void*)varint);
          gr_print("command : identifier ASSIGN_OP T_INT(expr)\n ");
        ;}
    break;

  case 50:
#line 1529 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_uchar,(yysemantic_stack_[(6) - (1)].ident),(void*)varuchar);
        gr_print("command : identifier ASSIGN_OP T_UCHAR(expr)\n ");
        ;}
    break;

  case 51:
#line 1537 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          varfloat = new float((yysemantic_stack_[(3) - (3)].adouble));
          Vars.AddVar(type_float,(yysemantic_stack_[(3) - (1)].ident),(void*)varfloat);
          gr_print("command : identifier ASSIGN_OP expr\n ");
        ;}
    break;

  case 52:
#line 1545 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          string* varstring;
          varstring = new string((yysemantic_stack_[(3) - (3)].astring));
          Vars.AddVar(type_string,(yysemantic_stack_[(3) - (1)].ident),(void*)varstring);
              delete [] (yysemantic_stack_[(3) - (3)].astring);
          gr_print("command : identifier ASSIGN_OP expr_string\n ");
        ;}
    break;

  case 53:
#line 1554 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 54:
#line 1585 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 55:
#line 1601 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        ;}
    break;

  case 56:
#line 1606 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        ;}
    break;

  case 57:
#line 1610 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        ;}
    break;

  case 58:
#line 1614 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
        ;}
    break;

  case 59:
#line 1619 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
        ;}
    break;

  case 60:
#line 1623 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->SetProgress((int)((yysemantic_stack_[(4) - (3)].adouble)+0.5));
        ;}
    break;

  case 61:
#line 1626 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        gr_print("command : QUIT\n ");

        GB_main_wxFrame->Close(true);
    ;}
    break;

  case 62:
#line 1632 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 63:
#line 1671 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          char titre[100];
          Variable* var;

          sprintf(titre,"%s_draw",(yysemantic_stack_[(2) - (2)].variable)->Name());
          if (Vars.GetVar(titre,&var)) {

        if (var->Type() == type_imagedraw) {
            err_print("Hide window \n");
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

  case 64:
#line 1691 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 65:
#line 1720 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 66:
#line 1737 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          InrImage* i2 = (InrImage*) im_stack.GetLastImage();

          Si i2!=NULL Alors
            // copy option
            if (!((*i1)=(*i2))) err_print(" Error in images assignement\n");
          Sinon
            err_print("Error\n");
          FinSi
          delete i2;
        ;}
    break;

  case 67:
#line 1750 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Replacing the previous image by the new one.
        **/
          Variable* var = (yysemantic_stack_[(3) - (1)].variable);
          void* imptr  = (void*) im_stack.GetLastImage();

          // instead of deleting and creating,
          // replace the pointer and the information
          if (imptr != NULL) {
            var->FreeMemory();
            var->Init(type_image,
                      var->Name(),
                      imptr);
          }
          else
            err_print("assignment of NULL image\n");
        ;}
    break;

  case 68:
#line 1770 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 69:
#line 1783 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
                                im_stack.GetLastImage());

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
            yyiperror("image[]=image\t second image has to be scalar \n");
            YYABORT;
          FinSi

        ;}
    break;

  case 70:
#line 1818 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 71:
#line 1848 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          int posx  = (int) (yysemantic_stack_[(16) - (3)].adouble);
          int stepx = (int) (yysemantic_stack_[(16) - (5)].adouble);
          int posy  = (int) (yysemantic_stack_[(16) - (7)].adouble);
          int stepy = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int posz  = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int stepz = (int) (yysemantic_stack_[(16) - (13)].adouble);


          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(16) - (1)].variable)->Pointer();
          InrImage* i2 = (InrImage*) im_stack.GetLastImage();

          Func_Pad(i1.get(),i2,stepx,posx,stepy,posy,stepz,posz);

          delete i2;

        ;}
    break;

  case 72:
#line 1866 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        ;}
    break;

  case 73:
#line 1870 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        ;}
    break;

  case 74:
#line 1874 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 75:
#line 1878 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        ;}
    break;

  case 76:
#line 1882 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        ;}
    break;

  case 77:
#line 1886 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 78:
#line 1890 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 79:
#line 1894 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        ;}
    break;

  case 80:
#line 1898 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        ;}
    break;

  case 81:
#line 1902 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        ;}
    break;

  case 82:
#line 1907 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        ;}
    break;

  case 83:
#line 1911 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         Vars.deleteVar((yysemantic_stack_[(2) - (2)].variable));
        ;}
    break;

  case 84:
#line 1920 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yysemantic_stack_[(5) - (2)].variable)->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
        ;}
    break;

  case 85:
#line 1929 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         std::system((yysemantic_stack_[(2) - (2)].astring));
         gr_print(" command:  ASHELL ASTRING \n");

         delete [] (yysemantic_stack_[(2) - (2)].astring);
           ;}
    break;

  case 86:
#line 1936 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
         gr_print("command : LS\n ");
           ;}
    break;

  case 87:
#line 1945 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        res_print("Topics: \n");
        res_print("\t var:  variables                 \n");
            res_print("\t     image:     Help for image     variables\n");
            res_print("\t     imagedraw: Help for imagedraw variables\n");
        res_print("\t cmd:  commands                  \n");
        res_print("\t fnc:  functions                 \n");
        res_print("\t loop: loops                     \n");
        res_print("\t cond: conditions                \n");
            res_print("\t arit: arithmetical expressions  \n");

            gr_print("command : HELP\n ");
      ;}
    break;

  case 88:
#line 1959 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"var")==0) {
         res_print("var types: void image float int string imagedraw surface surfacedraw \n");
         res_print("\t del varname\n");
         res_print("\t\t\t - deletes a variable and frees its contents from memory \n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"cmd")==0) {
         res_print("commands:\n");
         res_print("\t sh Quit Image Show Help ls print func filter normgrad discnormgrad OpImage EDPdilate EDPerode EDPopen EDPclose\n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"fnc")==0) {
         res_print("functions:\n");
         res_print("\t  filter normgrad gradient OpImage secdergrad ");
             res_print("subimage putimage\n");
         res_print("\t       OpImage( var_image, string ) \n");
         res_print("\t       OpImage( var_image, var_image, string ) \n");
         res_print("\t       OpImage( var_image, var_image, var_image, string ) \n");
         res_print("\t       filter( var_image, expr, number, number, number ) \n");
         res_print("\t       normgrad(   var_image, expr ) \n");
         res_print("\t       discnormgrad(   var_image ) \n");
         res_print("\t       gradient(   var_image, expr ) \n");
         res_print("\t       secdergrad( var_image, expr ) \n");
         res_print("\t       subimage( var_image, expr, expr, expr, expr, expr, expr ) \n");
         res_print("\t       putimage( var_image, var_image, expr, expr, expr  ) \n");
         res_print("\t       EDPdilate( var_image, expr, expr) \n");
         res_print("\t       EDPerode(  var_image, expr, expr) \n");
         res_print("\t       EDPopen(   var_image, expr, expr) \n");
         res_print("\t       EDPclose(  var_image, expr, expr) \n");

         res_print("\t       AnisoGS(   var_image, expr, expr, expr, expr) \n");
         res_print("\t\t  expr 1: standard deviation of the Gaussian convolution  \n");
         res_print("\t\t  expr 2: threshold on the gradient norm \n");
         res_print("\t\t  expr 3: data attachment coefficient \n");
         res_print("\t\t  expr 4: number of iterations \n");
             res_print("\t       StructTensor( var_image, expr, expr ) \n");
             res_print("\t       Curvatures(   var_image, expr ) \n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"loop")==0) {
         res_print("loops:\n");
         res_print("\t  for var=expr to expr { instructions } \n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"cond")==0) {
         res_print("loops:\n");
         res_print("\t  if expr  { instructions } \n");
         res_print("\t\t  [ else { instructions } ]\n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"arit")==0) {
         res_print("arithmetical expressions:\n");
         res_print("\t  constants: Pi\n");
         res_print("\n");
         res_print("\t  functions:  cos()  sin()  tan() \n");
         res_print("\t             acos() asin() atan() \n");
         res_print("\t              exp()   ln()  log() \n");
         res_print("\t             sinh() cosh()        \n");
         res_print("\t  operators:\n");
         res_print("\t            *, /\n");
         res_print("\t            +, -\n");
         res_print("\t            <, >, <=, >=\n");
         res_print("\t            ==, != \n");
         res_print("\t            & \n");
         res_print("\t            ^ \n");
         res_print("\t            | \n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"image")==0) {
         res_print("variable Image\n");
         res_print(" Creation:\n");
         res_print("\t Image \"filename\"\n");
         res_print("\t\t\t - reads an image file \n");
         res_print("\t Image \n");
         res_print("\t\t\t -  open browsing window for choosing the image\n");
         res_print("\t Image(basic_type, size_x , size_y, size_z) \n");
         res_print("\t\t\t - create an image of a basic type and the given dimensions\n");
         res_print("\t\t\t - basic_type are CHAR UCHAR SHORT USHORT FLOAT DOUBLE RGB FLOAT_VECTOR \n");
         res_print("\t\t\t - size_x, size_y, size_z: float expressions \n");
         res_print(" Functions that return a new image: \n");
         res_print("\t OpImage( var_image, string ) \n");
         res_print("\t\t\t - applies point to point operations to 1 image\n");
         res_print("\t OpImage( var_image, var_image, string ) \n");
         res_print("\t\t\t - applies point to point operations to 2 images\n");
         res_print("\t OpImage( var_image, var_image, var_image, string ) \n");
         res_print("\t\t\t - applies point to point operations to 3 images\n");
         res_print("\t filter( var_image, size, number, number, number ) \n");
         res_print("\t\t\t - applies Gaussian (or derivatives) convolution of sd size \n");
         res_print("\t\t\t - number represent the derivation order:\n");
         res_print("\t\t\t\t 0: no           derivation in this dimension\n");
         res_print("\t\t\t\t 1: first order  derivation in this dimension\n");
         res_print("\t\t\t\t 2: second order derivation in this dimension\n");
         res_print("\t normgrad(   var_image, expr ) \n");
         res_print("\t\t\t - applies Gaussian (or derivatives) convolution of sd size \n");

         res_print("\t discnormgrad(   var_image ) \n");
         res_print("\t\t\t - Discrete gradient norm without Gaussian convolution \n");

         res_print("\t gradient(   var_image, expr ) \n");
         res_print("\t\t\t - Gradient of the image using  Gaussian (and derivatives) convolution of sd size \n");

         res_print("\t secdergrad( var_image, expr ) \n");
             res_print("\t\t\t - Compute the second order derivative in the gradient direction.\n");


         res_print("\t subimage( var_image, expr, expr, expr,");
         res_print(" expr, expr, expr ) \n");
             res_print("\t\t\t - extract a subimage \n");

         res_print("\t AddGaussNoise( var_image, expr, expr) \n");
             res_print("\t\t\t - add a Gaussian noise to the image \n");
             res_print("\t\t\t - param 2: mean \n");
             res_print("\t\t\t - param 3: standard deviation \n");

         res_print("\t eccentricity( var_image) \n");
             res_print("\t\t\t - Compute a expression of eccentricity  \n");
             res_print("\t\t\t - of the image, returns an 'expr'  \n");

         res_print("\t isoarea2D( var_image, expr, expr, expr) \n");
             res_print("\t\t\t - Compute the surface area of the region\n");
             res_print("\t\t\t   of positive intensity containing the point\n");
             res_print("\t\t\t   (x,y)\n");
             res_print("\t\t\t expr 1: resolution  \n");
             res_print("\t\t\t expr 2: x  \n");
             res_print("\t\t\t expr 3: y  \n");

         res_print("\t EDPdilate( var_image, expr, expr) \n");
         res_print("\t EDPerode(  var_image, expr, expr) \n");
         res_print("\t EDPopen(   var_image, expr, expr) \n");
         res_print("\t EDPclose(  var_image, expr, expr) \n");

         res_print("\t AnisoGS(   var_image, expr, expr, expr, expr) \n");
         res_print("\t\t  expr 1: sigma     \n");
         res_print("\t\t  expr 2: threshold \n");
         res_print("\t\t  expr 3: data attachment coefficient \n");
         res_print("\t\t  expr 4: number of iterations \n");


         res_print("\t image = AnisoGS.init( var_image, expr, expr, expr )\n");
         res_print("\t\t  expr 1:    sigma  \n");
         res_print("\t\t  expr 2:    theshold  \n");
         res_print("\t\t  expr 3:    data attachment coeff  \n");
         res_print("\t AnisoGS.setcoeff( expr )\n");
         res_print("\t\t  expr 1:    tangential coeff  \n");
         res_print("\t AnisoGS.setcoeff( expr, expr )\n");
         res_print("\t\t  expr 1:    min curv coeff  \n");
         res_print("\t\t  expr 2:    max curv coeff  \n");
         res_print("\t AnisoGS.iterate\n");
         res_print("\t AnisoGS.end\n");

         res_print("\t image = AnisoWeickert.init( var_image, expr, expr, expr )\n");
         res_print("\t\t  expr 1:    sigma  \n");
         res_print("\t\t  expr 2:    theshold  \n");
         res_print("\t\t  expr 3:    evolution step dt  \n");
         res_print("\t AnisoWeickert.iterate\n");
         res_print("\t AnisoWeickert.end\n");

         res_print("\t image = AnisoCW.init( var_image, expr, expr, expr,expr, expr )\n");
         res_print("\t\t  expr 1:    sigma  first Gaussian convolution\n");
         res_print("\t\t  expr 2:    rho    second Gaussian convolution\n");
         res_print("\t\t  expr 2:    C      threshold for the coherence\n");
         res_print("\t\t  expr 2:    alpha  lowest diffusion coefficient\n");
         res_print("\t\t  expr 3:    dt     evolution step \n");
         res_print("\t AnisoCW.iterate\n");
         res_print("\t AnisoCW.end\n");

         res_print(" Operations: \n");

         res_print("\t Show var_image \n");
         res_print("\t\t\t - displays the image \n");

         res_print("\t var_image = var_image \n");
         res_print("\t\t\t - makes a copy \n");

         res_print("\t var_image.initvalue( expr ) \n");
             res_print("\t\t\t - initialize every point to a scalar value \n");

         res_print("\t var_image.initvalue( expr, expr, expr ) \n");
             res_print("\t\t\t - initialization every point to a vector or RGB value \n");

         res_print("\t var_image.set( expr ) \n");
         res_print("\t\t\t - change the value a the current point \n");

         res_print("\t var_image.set( expr, expr, expr ) \n");
         res_print("\t\t\t - change the value a the current point \n");
         res_print("\t\t\t - for RGB or VECTOR FIELD images \n");

         res_print("\t var_image.setpos(expr,expr,expr) \n");
         res_print("\t\t\t - set the current position \n");

         res_print("\t var_image.putimage(var_image,expr,expr,expr) \n");
         res_print("\t\t\t - put an image at the specified position \n");

         res_print("\t var_image(expr,expr) \n");
         res_print("\t\t\t - return the value at a 2D position \n");

         res_print("\t var_image(expr,expr,expr) \n");
         res_print("\t\t\t - return the value at a 3D position \n");

         res_print("\t var_image.tx \n");
         res_print("\t\t\t - return size in X \n");

         res_print("\t var_image.ty \n");
         res_print("\t\t\t - return size in Y \n");

         res_print("\t var_image.tz \n");
         res_print("\t\t\t - return size in Z \n");

         res_print("\t var_image.init \n");
         res_print("\t\t\t - init the current position to (0,0,0) \n");

         res_print("\t var_image.info \n");
         res_print("\t\t\t - print information on the image \n");

         res_print("\t var_image.save \"filename\" \n");
         res_print("\t\t\t - save the image \n");

         res_print("\t var_image.normalize \n");
         res_print("\t\t\t - normalizes a vector field image \n");
       }
       else
       if (strcmp((yysemantic_stack_[(2) - (2)].ident),"imagedraw")==0) {
         res_print("variable imagedraw\n");
         res_print(" Creation:");
         res_print("\t show var_image \n");
         res_print("\t\t\t - displays an image and creates a new variable\n");
         res_print("\t\t\t   of type imagedraw and the name ending by _draw \n");
         res_print(" Functions:\n");

         res_print(" var_imagedraw.setpos( expr, expr, expr) \n");
         res_print("\t\t\t   set the cursor position \n");

         res_print(" var_imagedraw.showcursor( expr) \n");
         res_print("\t\t\t   expr=1-->shows cursor   0-->hides cursor \n");

         res_print(" var_imagedraw.update \n");
         res_print("\t\t\t   update the displayed images \n");

         res_print(" var_imagedraw.compare(var_image) \n");
         res_print("\t\t\t   add a comparison image \n");

         res_print(" var_imagedraw.setvector( number, var_image) \n");
         res_print("\t\t\t   set var_image a the vector image with number \n");
         res_print("\t\t\t   between 1 and 3 \n");
       }
     ;}
    break;

  case 89:
#line 2207 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 90:
#line 2261 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%s",(yysemantic_stack_[(4) - (4)].astring));
          fflush(file.get());
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        ;}
    break;

  case 91:
#line 2269 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        ;}
    break;

  case 92:
#line 2278 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string and newline
          **/
        res_print((yysemantic_stack_[(2) - (2)].astring));
        res_print("\n");
        delete [] (yysemantic_stack_[(2) - (2)].astring);
          ;}
    break;

  case 93:
#line 2288 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          ;}
    break;

  case 94:
#line 2294 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          ;}
    break;

  case 95:
#line 2300 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        ;}
    break;

  case 96:
#line 2307 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        ;}
    break;

  case 97:
#line 2313 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints a numerical value.
        **/
          string st;
          st = str(format("%5.10f") % (yysemantic_stack_[(2) - (2)].adouble));
          res_print(st.c_str());
        ;}
    break;

  case 98:
#line 2323 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints a numerical value and a newline.
        **/
          string st;
          st = str(format("%5.10f\n") %(yysemantic_stack_[(2) - (2)].adouble));
          res_print(st.c_str());
        ;}
    break;

  case 99:
#line 2333 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

          gr_print("command : VAR_IMAGEDRAW '.' SETPOS");
          gr_print("'(' expr ',' expr ',' expr ')'\n ");
        ;}
    break;

  case 100:
#line 2351 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 101:
#line 2363 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        ;}
    break;

  case 102:
#line 2373 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 103:
#line 2422 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 104:
#line 2437 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 105:
#line 2462 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 106:
#line 2489 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 107:
#line 2504 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 108:
#line 2511 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        ;}
    break;

  case 109:
#line 2518 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 110:
#line 2536 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 111:
#line 2559 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 112:
#line 2564 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 113:
#line 2569 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 114:
#line 2582 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        ;}
    break;

  case 115:
#line 2593 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        ;}
    break;

  case 116:
#line 2602 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          InrImage* colmap=(InrImage*) im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        ;}
    break;

  case 117:
#line 2611 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        ;}
    break;

  case 118:
#line 2619 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 119:
#line 2636 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 120:
#line 2652 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 121:
#line 2669 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 122:
#line 2689 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 123:
#line 2704 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 124:
#line 2722 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 125:
#line 2735 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 126:
#line 2749 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        ;}
    break;

  case 127:
#line 2758 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 128:
#line 2772 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 129:
#line 2783 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 130:
#line 2796 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 131:
#line 2814 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 132:
#line 2836 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        sprintf(tmp_string,"coord = %f %f %f \n",(yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        err_print(tmp_string);
          FinSi
        ;}
    break;

  case 133:
#line 2862 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 134:
#line 2890 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 135:
#line 2921 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 136:
#line 2927 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 137:
#line 2945 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 138:
#line 2950 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 139:
#line 2955 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 140:
#line 2960 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 141:
#line 2965 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 142:
#line 2970 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 143:
#line 2984 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 144:
#line 2999 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 145:
#line 3016 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 146:
#line 3030 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 147:
#line 3050 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 148:
#line 3055 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 149:
#line 3060 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    ;}
    break;

  case 150:
#line 3067 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

//    sprintf(tmp_string,"error = %f \n",error);
      res_print(tmp_string);
    ;}
    break;

  case 151:
#line 3077 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    ;}
    break;

  case 152:
#line 3085 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 153:
#line 3090 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    ;}
    break;

  case 154:
#line 3097 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    ;}
    break;

  case 155:
#line 3102 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    ;}
    break;

  case 156:
#line 3107 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 157:
#line 3128 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 158:
#line 3151 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 159:
#line 3156 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 160:
#line 3161 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 161:
#line 3166 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 162:
#line 3171 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 163:
#line 3176 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 164:
#line 3181 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 165:
#line 3186 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 166:
#line 3191 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 167:
#line 3196 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 168:
#line 3201 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 169:
#line 3206 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    ;}
    break;

  case 170:
#line 3211 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    ;}
    break;

  case 171:
#line 3216 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 172:
#line 3221 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 173:
#line 3226 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 174:
#line 3231 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 175:
#line 3236 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        ;}
    break;

  case 176:
#line 3241 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 177:
#line 3246 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        ;}
    break;

  case 178:
#line 3254 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 179:
#line 3259 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 180:
#line 3264 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 181:
#line 3269 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 182:
#line 3274 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 183:
#line 3279 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 184:
#line 3284 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        ;}
    break;

  case 185:
#line 3289 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        ;}
    break;

  case 186:
#line 3294 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        ;}
    break;

  case 187:
#line 3299 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 188:
#line 3304 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 189:
#line 3309 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    ;}
    break;

  case 190:
#line 3314 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    ;}
    break;

  case 191:
#line 3318 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 192:
#line 3345 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 193:
#line 3358 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        ;}
    break;

  case 194:
#line 3363 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    ;}
    break;

  case 195:
#line 3367 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    ;}
    break;

  case 196:
#line 3373 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 197:
#line 3386 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        ;}
    break;

  case 198:
#line 3392 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 199:
#line 3398 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 200:
#line 3404 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 201:
#line 3411 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        ;}
    break;

  case 202:
#line 3418 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

        ;}
    break;

  case 203:
#line 3425 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets the object visible or not visible in the scene.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));

        ;}
    break;

  case 204:
#line 3436 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

        ;}
    break;

  case 205:
#line 3447 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 206:
#line 3462 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 207:
#line 3477 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        ;}
    break;

  case 208:
#line 3485 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) im_stack.GetLastImage();

      s->SetColors( i , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

        ;}
    break;

  case 209:
#line 3494 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) im_stack.GetLastImage();

      s->SetColors( i );

        ;}
    break;

  case 210:
#line 3503 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        ;}
    break;

  case 211:
#line 3511 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 212:
#line 3515 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
        ;}
    break;

  case 213:
#line 3519 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 214:
#line 3556 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage*   i = (InrImage*) im_stack.GetLastImage();

      s->DisplacePoints( i );
      delete i;

        ;}
    break;

  case 215:
#line 3565 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

        ;}
    break;

  case 216:
#line 3572 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        ;}
    break;

  case 217:
#line 3579 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        ;}
    break;

  case 218:
#line 3590 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    ;}
    break;

  case 219:
#line 3598 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) im_stack.GetLastImage();

      s->SelectLines(im);
      s->GLRecomputeList();
      delete im;
    ;}
    break;

  case 220:
#line 3616 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    ;}
    break;

  case 221:
#line 3626 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        ;}
    break;

  case 222:
#line 3631 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        ;}
    break;

  case 223:
#line 3638 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        ;}
    break;

  case 224:
#line 3645 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    ;}
    break;

  case 225:
#line 3653 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    ;}
    break;

  case 226:
#line 3661 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 227:
#line 3680 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 228:
#line 3696 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 229:
#line 3713 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 230:
#line 3730 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 231:
#line 3735 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    ;}
    break;

  case 232:
#line 3740 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    ;}
    break;

  case 233:
#line 3745 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    ;}
    break;

  case 234:
#line 3750 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        ;}
    break;

  case 235:
#line 3759 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 236:
#line 3859 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      AMIFluid::Func_ElevateMesh(s.get(),im);
      delete im;
        ;}
    break;

  case 237:
#line 3893 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 238:
#line 3900 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        ;}
    break;

  case 239:
#line 3908 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        ;}
    break;

  case 240:
#line 3914 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        ;}
    break;

  case 241:
#line 3921 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        ;}
    break;

  case 242:
#line 3931 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        ;}
    break;

  case 243:
#line 3940 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        ;}
    break;

  case 244:
#line 3947 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 245:
#line 3954 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        ;}
    break;

  case 246:
#line 3964 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        ;}
    break;

  case 247:
#line 3971 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 248:
#line 3985 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(16) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(16) - (5)].adouble);
          InrImage* im = (InrImage*) im_stack.GetLastImage();
      int orientation = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int pos = (int) (yysemantic_stack_[(16) - (11)].adouble);
          float Imin = (yysemantic_stack_[(16) - (13)].adouble);
          float Imax = (yysemantic_stack_[(16) - (15)].adouble);

      draw->GetCanvas()->ShowFreeSection(num,im,orientation,pos,Imin,Imax);

          delete im;
        ;}
    break;

  case 249:
#line 3999 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        ;}
    break;

  case 250:
#line 4007 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        ;}
    break;

  case 251:
#line 4012 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        ;}
    break;

  case 252:
#line 4020 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        ;}
    break;

  case 253:
#line 4028 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 254:
#line 4039 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 255:
#line 4051 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 256:
#line 4063 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 257:
#line 4075 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        ;}
    break;

  case 258:
#line 4081 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 259:
#line 4094 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        ;}
    break;

  case 260:
#line 4101 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        ;}
    break;

  case 261:
#line 4112 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 262:
#line 4134 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_StructureTensorHessian(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        ;}
    break;

  case 263:
#line 4160 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* mask = (InrImage*) im_stack.GetLastImage();
      int save_grad = (int) (yysemantic_stack_[(12) - (11)].adouble);

          Func_StructureTensorHessian(((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(12) - (3)].variable)->Name(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask, save_grad);
      delete mask;
        ;}
    break;

  case 264:
#line 4188 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        ;}
    break;

  case 265:
#line 4198 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 0,   // gamma
                 mask  // mask
                 );
      delete mask;
        ;}
    break;

  case 266:
#line 4211 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        ;}
    break;

  case 267:
#line 4221 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(10) - (3)].variable)->Name(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask  // mask
                 );
      delete mask;
        ;}
    break;

  case 268:
#line 4234 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 269:
#line 4263 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

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

  case 270:
#line 4281 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

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

  case 271:
#line 4295 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name(),
              (yysemantic_stack_[(6) - (5)].adouble));
        ;}
    break;

  case 272:
#line 4307 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

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

  case 273:
#line 4328 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 274:
#line 4347 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) im_stack.GetLastImage();

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

  case 275:
#line 4364 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 276:
#line 4375 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 277:
#line 4380 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 278:
#line 4385 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    ;}
    break;

  case 279:
#line 4394 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    ;}
    break;

  case 280:
#line 4399 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    ;}
    break;

  case 281:
#line 4408 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 282:
#line 4422 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    ;}
    break;

  case 283:
#line 4429 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    ;}
    break;

  case 284:
#line 4435 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;;}
    break;

  case 285:
#line 4438 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 286:
#line 4453 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) IMAGE: 1D image to plot, where the voxel size in X is used
            (5) String: plot title
            (7) NUM: delay
        Description:
            Plots a 1D image using gnuplot.
        **/
      InrImage*   image = (InrImage*) im_stack.GetLastImage();
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

  case 287:
#line 4487 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 288:
#line 4504 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 289:
#line 4544 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        ;}
    break;

  case 290:
#line 4549 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      IP_time.Debut();
        ;}
    break;

  case 291:
#line 4554 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      IP_time.Fin();
      cout << "time spent = " << IP_time << endl;
        ;}
    break;

  case 292:
#line 4560 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          void * pwptr;
          //    pwptr = (void*)new ParamPanel(GB_main_wxFrame,  (char*) $5);
          pwptr = (void*)new ParamPanel(GB_main_wxFrame,  (char*) (yysemantic_stack_[(6) - (5)].astring));
          GB_main_wxFrame->AddParamPage((wxWindow*)pwptr,GetwxStr((char*) (yysemantic_stack_[(6) - (5)].astring)));
          //GB_main_wxFrame->GetAuiManager().Update();
          if (pwptr != NULL)
        Vars.AddVar(type_paramwin,(yysemantic_stack_[(6) - (1)].ident),pwptr);
          else
        err_print("assignment of NULL parameter window\n");

          gr_print("command : identifier ASSIGN_OP T_ParamWin\n ");
              delete [] (yysemantic_stack_[(6) - (5)].astring);
        ;}
    break;

  case 293:
#line 4576 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
    pw->BeginBox( (char*) (yysemantic_stack_[(6) - (5)].astring));
    delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 294:
#line 4583 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginBook();
    ;}
    break;

  case 295:
#line 4589 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    ;}
    break;

  case 296:
#line 4595 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->AddPage( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 297:
#line 4602 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginPanel( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    ;}
    break;

  case 298:
#line 4609 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    ;}
    break;

  case 299:
#line 4615 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    ;}
    break;

  case 300:
#line 4621 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    ;}
    break;

  case 301:
#line 4627 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        ;}
    break;

  case 302:
#line 4633 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        ;}
    break;

  case 303:
#line 4639 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 304:
#line 4651 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        ;}
    break;

  case 305:
#line 4657 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 306:
#line 4674 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer() );
        ;}
    break;

  case 307:
#line 4681 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 308:
#line 4692 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        ;}
    break;

  case 309:
#line 4699 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        ;}
    break;

  case 310:
#line 4704 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        ;}
    break;

  case 311:
#line 4710 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        ;}
    break;

  case 312:
#line 4715 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        ;}
    break;

  case 313:
#line 4720 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        ;}
    break;

  case 314:
#line 4725 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        ;}
    break;

  case 315:
#line 4730 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        ;}
    break;

  case 316:
#line 4741 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 317:
#line 4773 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 318:
#line 4797 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        ;}
    break;

  case 319:
#line 4804 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 320:
#line 4825 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        ;}
    break;

  case 321:
#line 4830 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 322:
#line 4837 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 323:
#line 4844 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         ;}
    break;

  case 324:
#line 4852 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 325:
#line 4860 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 326:
#line 4869 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 327:
#line 4876 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 328:
#line 4883 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 329:
#line 4890 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 330:
#line 4897 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 331:
#line 4904 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 332:
#line 4911 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 333:
#line 4918 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 334:
#line 4925 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 335:
#line 4932 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 336:
#line 4939 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        ;}
    break;

  case 337:
#line 4948 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    ;}
    break;

  case 338:
#line 4954 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_float);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 339:
#line 4960 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_string);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 340:
#line 4966 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_image);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 341:
#line 4972 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 342:
#line 4978 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam((yysemantic_stack_[(2) - (2)].ident),type_surface);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 343:
#line 4984 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_float);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 344:
#line 4990 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_string);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 345:
#line 4996 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_image);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 346:
#line 5002 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 347:
#line 5008 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam((yysemantic_stack_[(4) - (4)].ident),type_surface);
      (yyval.paramlistdecl) = pl;
        ;}
    break;

  case 348:
#line 5015 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        ;}
    break;

  case 349:
#line 5020 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      char* res;

      res = new char[(*(string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->length()+1];
      strcpy(res,((string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get()->c_str());
      (yyval.astring)= res;
        ;}
    break;

  case 350:
#line 5032 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           gr_print("->postfixE");
       fflush(stdout);
        ;}
    break;

  case 351:
#line 5038 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 352:
#line 5052 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      char* res;
      long min,hour,sec;

      IP_time.Fin();
      IP_time.AddCumul();
      IP_time.GetCumul(hour,min,sec);
      res = new char[10];
          sprintf(res,"%03d:%02d:%02d",(int)hour,(int)min,(int)sec);
      (yyval.astring)=res;
        ;}
    break;

  case 353:
#line 5064 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    ;}
    break;

  case 355:
#line 5073 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 356:
#line 5083 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        ;}
    break;

  case 357:
#line 5091 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           gr_print("->expr_string\n");
        ;}
    break;

  case 358:
#line 5099 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          ;}
    break;

  case 361:
#line 5112 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        gr_print("\n NUMBER");
    fflush(stdout);
    ;}
    break;

  case 362:
#line 5117 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    ;}
    break;

  case 363:
#line 5125 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=yyiplineno;
    ;}
    break;

  case 364:
#line 5133 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
      gr_print("\n CONST_PI");
    ;}
    break;

  case 365:
#line 5143 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
      gr_print("\n VAR_FLOAT");
    ;}
    break;

  case 366:
#line 5148 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
      //sprintf(tmp_string,"\n VAR_INT %d ", (int)$1);
    gr_print(tmp_string);
    ;}
    break;

  case 367:
#line 5154 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
      //sprintf(tmp_string,"\n VAR_INT %d ", (int)$1);
      gr_print(tmp_string);
    ;}
    break;

  case 368:
#line 5160 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      gr_print("\n(expr)");
      fflush(stdout);
    ;}
    break;

  case 369:
#line 5169 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           gr_print("->postfixE");
       fflush(stdout);
        ;}
    break;

  case 370:
#line 5174 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 371:
#line 5189 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 372:
#line 5205 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(8) - (3)].adouble),(int) ( (yysemantic_stack_[(8) - (5)].adouble)), (int) ((yysemantic_stack_[(8) - (7)].adouble)));
    ;}
    break;

  case 373:
#line 5209 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        err_print("var_image(expr,expr,expr,expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 374:
#line 5226 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        err_print("var_image(expr,expr,expr;expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 375:
#line 5242 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        err_print("var_image(expr,expr;expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 376:
#line 5256 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 1D  position. (y and z components set to 0)
        **/
      Si (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->CoordOK((int) (yysemantic_stack_[(6) - (3)].adouble),   0,   0  )
        Et ((int) (yysemantic_stack_[(6) - (5)].adouble) >=0) Et ((int)(yysemantic_stack_[(6) - (5)].adouble) <3) Alors
        (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(6) - (3)].adouble),0,0, (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Sinon
        err_print("var_image(expr;expr) \t err coord \n");
          FinSi
    ;}
    break;

  case 377:
#line 5269 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 378:
#line 5290 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
          sprintf(tmp_string," %s.%s identifier not recognized \n",
              (yysemantic_stack_[(3) - (1)].variable)->Name(), (yysemantic_stack_[(3) - (3)].ident));
          strcat(tmp_string," known identifiers {tx, ty, tz, vdim, trx, try, trz, vx, vy, vz, init, inc, val, info} \n");
          err_print(tmp_string);
        }

      gr_print("\n var_image '.' identifier->postfixE");
        ;}
    break;

  case 379:
#line 5349 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im;
        im=*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        sprintf(tmp_string," format=%s  dim=(%d,%d,%d)x%d  vox=(%f,%f,%f) \
  translation =(%f,%f,%f) \n",
            im->FormatName(),
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
        res_print(tmp_string);
    ;}
    break;

  case 380:
#line 5368 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      sprintf(tmp_string," %d points  %d polygons  \n",
          s->GetNumberOfPoints(),
          s->GetNumberOfPolys ()
          );
      res_print(tmp_string);
          sprintf(tmp_string," limits X:[%4.2f %4.2f] Y:[%4.2f %4.2f]  Z:[%4.2f %4.2f]  \n",
          s->_xmin,s->_xmax,
          s->_ymin,s->_ymax,
          s->_zmin,s->_zmax);

      res_print(tmp_string);
    ;}
    break;

  case 381:
#line 5385 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    ;}
    break;

  case 382:
#line 5392 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    ;}
    break;

  case 383:
#line 5400 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        ;}
    break;

  case 384:
#line 5405 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        ;}
    break;

  case 385:
#line 5410 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 386:
#line 5438 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
        ;}
    break;

  case 387:
#line 5444 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        ;}
    break;

  case 388:
#line 5455 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      (yyval.adouble)=Func_count( im );
      delete im;
        ;}
    break;

  case 389:
#line 5475 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      (yyval.adouble)=Func_mean( im);
      delete im;
        ;}
    break;

  case 390:
#line 5495 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 391:
#line 5513 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      (yyval.adouble)=Func_argmax( im);
      delete im;
        ;}
    break;

  case 392:
#line 5533 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 393:
#line 5551 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 394:
#line 5569 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
          InrImage* mask = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_max( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),mask);
          delete mask;
        ;}
    break;

  case 395:
#line 5592 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
          InrImage* mask = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_min( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),mask);
          delete mask;
        ;}
    break;

  case 396:
#line 5615 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
          InrImage* mask = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),0.5,mask);
          delete mask;
        ;}
    break;

  case 397:
#line 5638 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        ;}
    break;

  case 398:
#line 5645 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
          InrImage* input = (InrImage*) im_stack.GetLastImage();
          InrImage* mask  = (InrImage*) im_stack.GetLastImage();
          (yyval.adouble)=Func_mean( input,mask);
          delete mask;
          delete input;
        ;}
    break;

  case 399:
#line 5670 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
          InrImage* mask = (InrImage*) im_stack.GetLastImage();

          (yyval.adouble)=Func_mean( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), mask);
          delete mask;
        ;}
    break;

  case 400:
#line 5693 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
        ;}
    break;

  case 401:
#line 5700 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        ;}
    break;

  case 402:
#line 5710 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        ;}
    break;

  case 403:
#line 5720 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        ;}
    break;

  case 404:
#line 5730 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        ;}
    break;

  case 405:
#line 5740 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        ;}
    break;

  case 406:
#line 5750 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        ;}
    break;

  case 407:
#line 5760 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;
          string comment;
          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          (yyval.adouble)=param->_pos._x;
          comment = str(format(" //  xpos=%3d") % param->_pos._x);
          if (yy_num_buf==1)
            GB_main_wxFrame->GetConsole()
                           ->IncCommand(wxString::FromAscii(comment.c_str()));
        ;}
    break;

  case 408:
#line 5774 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._y;

      comment = str( format(" //  ypos=%3d") % param->_pos._y);
      if (yy_num_buf==1)
        GB_main_wxFrame->GetConsole()
                       ->IncCommand(wxString::FromAscii(comment.c_str()));

    ;}
    break;

  case 409:
#line 5791 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._z;

      comment = str( format(" //  xpos=%3d") % param->_pos._z);
      if (yy_num_buf==1)
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    ;}
    break;

  case 410:
#line 5807 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    ;}
    break;

  case 411:
#line 5812 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    ;}
    break;

  case 412:
#line 5817 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    ;}
    break;

  case 413:
#line 5821 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    ;}
    break;

  case 414:
#line 5828 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    ;}
    break;

  case 415:
#line 5836 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 416:
#line 5871 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 417:
#line 5884 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable)->Pointer());
    (yyval.adouble) = bid;
    ;}
    break;

  case 418:
#line 5894 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 419:
#line 5911 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 420:
#line 5930 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 421:
#line 5946 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 422:
#line 5964 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 423:
#line 5984 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 424:
#line 6005 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 425:
#line 6018 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 426:
#line 6031 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    ;}
    break;

  case 427:
#line 6039 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    ;}
    break;

  case 428:
#line 6047 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    ;}
    break;

  case 429:
#line 6051 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        float res;
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),(yysemantic_stack_[(6) - (5)].astring),&res);
        (yyval.adouble) =  res;
    ;}
    break;

  case 430:
#line 6059 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    ;}
    break;

  case 431:
#line 6069 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           gr_print("->unaryE");
       fflush(stdout);
        ;}
    break;

  case 432:
#line 6074 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           gr_print("\n unary_operator castE->unaryE");
       fflush(stdout);
        ;}
    break;

  case 433:
#line 6078 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 434:
#line 6079 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 435:
#line 6080 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 436:
#line 6081 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 437:
#line 6082 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 438:
#line 6083 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 439:
#line 6084 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 440:
#line 6085 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 441:
#line 6087 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        ;}
    break;

  case 442:
#line 6094 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 443:
#line 6095 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 444:
#line 6096 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 445:
#line 6097 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 446:
#line 6098 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 447:
#line 6099 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 448:
#line 6100 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) ;}
    break;

  case 451:
#line 6111 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           gr_print("->castE");
       fflush(stdout);
        ;}
    break;

  case 452:
#line 6117 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 454:
#line 6133 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 455:
#line 6134 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 457:
#line 6139 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 458:
#line 6140 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); ;}
    break;

  case 459:
#line 6145 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      gr_print("->shiftE");
    ;}
    break;

  case 461:
#line 6153 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  ;}
    break;

  case 462:
#line 6154 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  ;}
    break;

  case 463:
#line 6155 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 464:
#line 6156 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 466:
#line 6161 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 467:
#line 6162 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); ;}
    break;

  case 468:
#line 6163 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); ;}
    break;

  case 469:
#line 6164 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); ;}
    break;

  case 470:
#line 6169 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      gr_print("->andE ");
    ;}
    break;

  case 471:
#line 6173 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    ;}
    break;

  case 472:
#line 6181 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      gr_print("->xorE ");
    ;}
    break;

  case 473:
#line 6185 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      gr_print("\n xorE '^' andE->xorE");
    ;}
    break;

  case 474:
#line 6192 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        ;}
    break;

  case 475:
#line 6196 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        ;}
    break;

  case 476:
#line 6203 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        ;}
    break;

  case 477:
#line 6207 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        ;}
    break;

  case 478:
#line 6214 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    ;}
    break;

  case 479:
#line 6218 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    ;}
    break;

  case 481:
#line 6226 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        ;}
    break;

  case 483:
#line 6237 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
           gr_print("->expr\n");
        ;}
    break;

  case 484:
#line 6246 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    ;}
    break;

  case 485:
#line 6251 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       ;}
    break;

  case 486:
#line 6255 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       ;}
    break;

  case 487:
#line 6259 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       ;}
    break;

  case 488:
#line 6263 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       ;}
    break;

  case 489:
#line 6267 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       ;}
    break;

  case 490:
#line 6271 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       ;}
    break;

  case 491:
#line 6275 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       ;}
    break;

  case 492:
#line 6279 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       ;}
    break;

  case 493:
#line 6283 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       ;}
    break;

  case 494:
#line 6287 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      ;}
    break;

  case 495:
#line 6295 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        ;}
    break;

  case 496:
#line 6300 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 497:
#line 6317 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
     im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
         gr_print("image : T_Image  ASTRING  \n ");
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       ;}
    break;

  case 498:
#line 6324 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
     im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
         gr_print("image : T_Image  ASTRING  \n ");
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       ;}
    break;

  case 499:
#line 6332 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
       im_stack.AddImage(im);
     } else {
       // Error message
       sprintf(tmp_string,"ReadRawImages() failed ... \n");
       err_print(tmp_string);
       im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       ;}
    break;

  case 500:
#line 6391 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
       im_stack.AddImage(im);
     } else {
       // Error message
       sprintf(tmp_string,"ReadRawImages() failed ... \n");
       err_print(tmp_string);
       im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       ;}
    break;

  case 501:
#line 6446 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

         im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format;
     delete [] file_format;

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       im_stack.AddImage(im);
     } else {
       // Error message
       sprintf(tmp_string,"ReadRawImages() failed ... \n");
       err_print(tmp_string);
       im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       ;}
    break;

  case 502:
#line 6502 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
                sprintf(tmp_string,"vtkDicomRead() error ... \n");
                err_print(tmp_string);
                im_stack.AddImage((InrImage*)NULL);
            FinSi

            im_stack.AddImage(res);
            delete [] (yysemantic_stack_[(4) - (3)].astring);
       ;}
    break;

  case 503:
#line 6524 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
                sprintf(tmp_string,"vtkMINCRead() error ... \n");
                err_print(tmp_string);
                im_stack.AddImage((InrImage*)NULL);
            FinSi

            im_stack.AddImage(res);
            delete [] (yysemantic_stack_[(4) - (3)].astring);
       ;}
    break;

  case 504:
#line 6546 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
       Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
       ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
       InrImage*  im;

       im = ((InrImage* (*)(ParamList*)) var->Pointer())(param.get());
       if (!im) {
        yyiperror(" image function returns NULL \n");
        YYABORT;
       }
      im_stack.AddImage(im);
       ;}
    break;

  case 505:
#line 6560 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskImage(name);
          if (!res) {
            yyiperror(" Need Image \n");
            YYABORT;
          }
          im_stack.AddImage((char*)name.c_str());


          wxFileName filename(GetwxStr(name));
          filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
          wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                              filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                              filename.GetPathSeparator(wxPATH_UNIX)+
                              filename.GetFullName());
          res_print(newname.mb_str());
          res_print("\n");
          inc_cmd = str(format(" \"%1%\" // from browser ") % newname.c_str());

          if (yy_num_buf==1)
            GB_main_wxFrame->GetConsole()
                            ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
          gr_print("image : T_Image  \n ");
      ;}
    break;

  case 506:
#line 6590 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(10) - (3)].aint), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        im_stack.AddImage(im);
        gr_print("image : T_Image ( basic_type, expr, expr, expr ) \n ");
      ;}
    break;

  case 507:
#line 6599 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
    im_stack.AddImage(im);
    gr_print("image : T_Image ( basic_type, expr, expr, expr ) \n ");
    ;}
    break;

  case 508:
#line 6619 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      im_stack.AddImage(im);
    ;}
    break;

  case 509:
#line 6645 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         InrImage::ptr varim;
         InrImage* im;
         char  imname[200];

         varim=*(InrImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();
         sprintf(imname,"copy_%s",(yysemantic_stack_[(1) - (1)].variable)->Name());
         im = new InrImage(varim->_format,imname,varim.get());
         (*im)=(*varim);
          im_stack.AddImage(im);
         gr_print("image : var_image \n ");
       ;}
    break;

  case 510:
#line 6659 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
             im = new InrImage(WT_UNSIGNED_CHAR,1,imname,im1.get());
          FinValeur

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
        yyiperror(" operator [] does not handle this format \n");
        YYABORT;
         FinSelonQue

         im->InitBuffer();
         im1->InitBuffer();
         Repeter
           im->FixeValeur(im1->VectValeurBuffer(i));
               im1->IncBuffer();
         JusquA Non(im->IncBuffer()) FinRepeter
         im_stack.AddImage(im);

       ;}
    break;

  case 511:
#line 6739 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
    InrImage* im = (InrImage*) im_stack.GetLastImage();
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
          err_print("sum operator only for scalar images ... \n");
        }
        im_stack.AddImage(res);
        delete im;
      ;}
    break;

  case 512:
#line 6806 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) im_stack.GetLastImage();
    InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    im_stack.AddImage(res);
    delete im;
      ;}
    break;

  case 513:
#line 6814 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) im_stack.GetLastImage();
    InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    im_stack.AddImage(res);
    delete im;
      ;}
    break;

  case 514:
#line 6822 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) im_stack.GetLastImage();
    InrImage* im      = (InrImage*) im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    im_stack.AddImage(res);
    delete im;
    delete mean;
      ;}
    break;

  case 515:
#line 6832 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) im_stack.GetLastImage();
    InrImage* im      = (InrImage*) im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    im_stack.AddImage(res);
    delete im;
    delete mean;
      ;}
    break;

  case 516:
#line 6842 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

    im2 = im_stack.GetLastImage();
    im1 = im_stack.GetLastImage();
    im1->InitBuffer();
    im2->InitBuffer();
    Repeter
          val1 = im1->ValeurBuffer();
      val2 = im2->ValeurBuffer();
      Si val2>val1 AlorsFait im1->FixeValeur(val2);
      im2->IncBuffer();
    JusquA Non(im1->IncBuffer())
    FinRepeter
    im_stack.AddImage(im1);
    delete im2;

      ;}
    break;

  case 517:
#line 6872 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              NULL,
              NULL,
              (yysemantic_stack_[(6) - (5)].astring));
    Si res==NULL Alors
      sprintf(tmp_string,"OpImage() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
    delete [] (yysemantic_stack_[(6) - (3)].variable);

      ;}
    break;

  case 518:
#line 6891 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
              NULL,
              NULL,
              (yysemantic_stack_[(8) - (5)].astring),
              (WORDTYPE) (yysemantic_stack_[(8) - (7)].aint));
    Si res==NULL Alors
      sprintf(tmp_string,"OpImage() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);

    delete [] (yysemantic_stack_[(8) - (5)].astring);

      ;}
    break;

  case 519:
#line 6912 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
              ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
              NULL,
              (yysemantic_stack_[(8) - (7)].astring));
    Si res==NULL Alors
      sprintf(tmp_string,"OpImage() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);

    delete [] (yysemantic_stack_[(8) - (7)].astring);
      ;}
    break;

  case 520:
#line 6931 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
              ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
              NULL,
              (yysemantic_stack_[(10) - (7)].astring),
              (yysemantic_stack_[(10) - (9)].aint));
    Si res==NULL Alors
      sprintf(tmp_string,"OpImage() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);

    delete [] (yysemantic_stack_[(10) - (7)].astring);

      ;}
    break;

  case 521:
#line 6952 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_OpImage(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
              (yysemantic_stack_[(10) - (9)].astring));
        Si res==NULL Alors
          sprintf(tmp_string,"OpImage() erreur ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
        FinSi
        im_stack.AddImage(res);

        delete [] (yysemantic_stack_[(10) - (9)].astring);
      ;}
    break;

  case 522:
#line 6972 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_OpImage(
            ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable)->Pointer())->get(),
              (yysemantic_stack_[(12) - (9)].astring),
              (yysemantic_stack_[(12) - (11)].aint));
        Si res==NULL Alors
          sprintf(tmp_string,"OpImage() erreur ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
        FinSi
        im_stack.AddImage(res);
        delete [] (yysemantic_stack_[(12) - (9)].astring);
      ;}
    break;

  case 523:
#line 6994 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        InrImage* im = (InrImage*) im_stack.GetLastImage();

        res = Func_Filter( im,
                  (yysemantic_stack_[(12) - (5)].adouble),
                  (int) (yysemantic_stack_[(12) - (7)].adouble),
                  (int) (yysemantic_stack_[(12) - (9)].adouble),
                  (int) (yysemantic_stack_[(12) - (11)].adouble));

        Si res==NULL Alors
          sprintf(tmp_string,"Filter() erreur ... \n");
          err_print(tmp_string);
          res=im;
        Sinon
          delete im;
        FinSi
        im_stack.AddImage(res);
      ;}
    break;

  case 524:
#line 7032 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        float var           = (yysemantic_stack_[(10) - (7)].adouble);
        float lowthreshold  = (yysemantic_stack_[(10) - (9)].adouble);
        //float highthreshold = $11;
            res = Func_itkCannyEdgeDetector(  ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(), var, lowthreshold);
        Si res==NULL Alors
          sprintf(tmp_string,"itk.CannyEdgeDetector() error ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get();
        FinSi

        im_stack.AddImage(res);
      ;}
    break;

  case 525:
#line 7048 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_vtkDist( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

        Si res==NULL Alors
          sprintf(tmp_string,"vtkDist() erreur ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
        FinSi

        im_stack.AddImage(res);
      ;}
    break;

  case 526:
#line 7063 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_vtkMedianFilter3D(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        Si res==NULL Alors
          sprintf(tmp_string,"vtkMedian3D() erreur ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
        FinSi

        im_stack.AddImage(res);
      ;}
    break;

  case 527:
#line 7080 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        err_print("The function AndreDist() has been removed for licence issues! \n");
/*
        InrImage::ptr  in = *(InrImage::ptr*) $3->Pointer();
        InrImage*  res;
        int ok;

        res = new InrImage(WT_FLOAT,"AndreDist.ami.gz", in.get());

        ok = dist_squared( in.get(),res);

        Si !ok Alors
          sprintf(tmp_string,"AndreDist() erreur ... \n");
          err_print(tmp_string);
          delete res;
          res=NULL;
        Sinon
          im_stack.AddImage(res);
        FinSi
*/
      ;}
    break;

  case 528:
#line 7103 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_2DFlux( im_stack.GetLastImage(),(yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      sprintf(tmp_string,"2DFlux() error ... \n");
      err_print(tmp_string);
      res=NULL;
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 529:
#line 7118 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OutFlux( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      sprintf(tmp_string,"OutFlux() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 530:
#line 7133 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OutFluxScalar( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      sprintf(tmp_string,"OutFluxScalar() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 531:
#line 7148 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OrientationRatio2D( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      sprintf(tmp_string,"OrientationRatio() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 532:
#line 7163 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      sprintf(tmp_string,"Skeleton() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 533:
#line 7199 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SimplePoints( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );

    Si res==NULL Alors
      sprintf(tmp_string,"SimplePoints() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 534:
#line 7215 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
          sprintf(tmp_string,"CircleInt() error ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
        FinSi

        im_stack.AddImage(res);
      ;}
    break;

  case 535:
#line 7237 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        sprintf(tmp_string,"CircleInt() error ... \n");
        err_print(tmp_string);
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
      ;}
    break;

  case 536:
#line 7259 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
          sprintf(tmp_string,"CircleIntSdExc() error ... \n");
          err_print(tmp_string);
          res=((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get();
        FinSi

        im_stack.AddImage(res);
      ;}
    break;

  case 537:
#line 7301 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        sprintf(tmp_string,"CircleIntSdExc() error ... \n");
        err_print(tmp_string);
        res=((InrImage::ptr*) (yysemantic_stack_[(20) - (3)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
      ;}
    break;

  case 538:
#line 7347 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_LocalExtrema( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),  // input image
                 ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),  // first  vector
                 ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),  // second vector
                 ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get()); // mask

    Si res==NULL Alors
      sprintf(tmp_string,"LocalExtrema() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 539:
#line 7365 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    int samples = (int) (yysemantic_stack_[(12) - (11)].adouble);

    res = Func_LocalExtrema( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),  // input image
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),  // first  vector
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable)->Pointer())->get(),  // second vector
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (9)].variable)->Pointer())->get(),  // mask
                 samples);                   // number of sample points around the circle

    Si res==NULL Alors
      sprintf(tmp_string,"LocalExtrema() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 540:
#line 7385 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_NormalSmoothField( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );

    Si res==NULL Alors
      sprintf(tmp_string,"NormalField() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 541:
#line 7400 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_NormalSmoothField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    Si res==NULL Alors
      sprintf(tmp_string,"NormalField() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 542:
#line 7415 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DirConnectivity( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    Si res==NULL Alors
      sprintf(tmp_string,"DirConnectivity() error ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 543:
#line 7432 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    InrImage*    input  = (InrImage*) im_stack.GetLastImage();

    res = Func_NormGrad( input, (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      sprintf(tmp_string,"Filter() error ... \n");
      err_print(tmp_string);
      res=input;
    Sinon
      delete input;
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 544:
#line 7451 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DiscNormGrad( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      sprintf(tmp_string,"discnormgrad() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 545:
#line 7467 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DiscMeanCurvature( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      sprintf(tmp_string,"DiscMeanCurvature() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 546:
#line 7484 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_Gradient( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      sprintf(tmp_string,"Filter() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 547:
#line 7500 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      sprintf(tmp_string,"Filter() erreur ... \n");
      err_print(tmp_string);
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
        ;}
    break;

  case 548:
#line 7524 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SecDerGrad( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SecDerGrad() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 549:
#line 7541 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SecDerGrad2( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 550:
#line 7555 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        im_stack.AddImage(res);
        delete im;
      ;}
    break;

  case 551:
#line 7567 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

    im_stack.AddImage(res);
      ;}
    break;

  case 552:
#line 7598 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

    im_stack.AddImage(res);
      ;}
    break;

  case 553:
#line 7618 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

    im_stack.AddImage(res);
      ;}
    break;

  case 554:
#line 7660 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_dilate( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 555:
#line 7672 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_dilate( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 556:
#line 7683 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    res = Func_EDP_dilate( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax);
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 557:
#line 7696 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_erode( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                  (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 558:
#line 7708 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_erode( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi
    im_stack.AddImage(res);
      ;}
    break;

  case 559:
#line 7719 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
    im_stack.AddImage(res);
      ;}
    break;

  case 560:
#line 7747 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

    im_stack.AddImage(res);
      ;}
    break;

  case 561:
#line 7774 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

    im_stack.AddImage(res);
      ;}
    break;

  case 562:
#line 7806 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_EDP_close( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 563:
#line 7822 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

    im_stack.AddImage(res);
      ;}
    break;

  case 564:
#line 7839 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 565:
#line 7852 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 566:
#line 7865 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

    im_stack.AddImage(res);
      ;}
    break;

  case 567:
#line 7885 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

    im_stack.AddImage(res);
    ;}
    break;

  case 568:
#line 7908 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 569:
#line 7922 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetAttachVectors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

    Si res==NULL Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
    FinSi

    im_stack.AddImage(res);
      ;}
    break;

  case 570:
#line 7939 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(Func_AnisoGS_GetOutput());

      Func_EndAnisoGS();


    ;}
    break;

  case 571:
#line 7972 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);

    ;}
    break;

  case 572:
#line 8010 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      im_stack.AddImage(res);

    ;}
    break;

  case 573:
#line 8045 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);

    ;}
    break;

  case 574:
#line 8078 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_InitWeickert( ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),
                (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble));

      Si res==NULL Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 575:
#line 8095 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_InitWeickertCoherence( ((InrImage::ptr*) (yysemantic_stack_[(16) - (5)].variable)->Pointer())->get(),
                (yysemantic_stack_[(16) - (7)].adouble),  (yysemantic_stack_[(16) - (9)].adouble), (yysemantic_stack_[(16) - (11)].adouble), (yysemantic_stack_[(16) - (13)].adouble), (yysemantic_stack_[(16) - (15)].adouble));

      Si res==NULL Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(16) - (5)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 576:
#line 8110 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_SRAD_qcoeff( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

      Si res==NULL Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
      FinSi

      im_stack.AddImage(res);
        ;}
    break;

  case 577:
#line 8126 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);
        ;}
    break;

  case 578:
#line 8146 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);
        ;}
    break;

  case 579:
#line 8169 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);
        ;}
    break;

  case 580:
#line 8193 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);
        ;}
    break;

  case 581:
#line 8219 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);
        ;}
    break;

  case 582:
#line 8242 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);
        ;}
    break;

  case 583:
#line 8264 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);
        ;}
    break;

  case 584:
#line 8287 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);
        ;}
    break;

  case 585:
#line 8311 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

            im_stack.AddImage(res);
        ;}
    break;

  case 586:
#line 8355 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);
        ;}
    break;

  case 587:
#line 8379 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      im_stack.AddImage(res);

    ;}
    break;

  case 588:
#line 8410 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

        InrImage*    res;

          res = Func_rot2D( ((InrImage::ptr*) (yysemantic_stack_[(14) - (3)].variable)->Pointer())->get(),
                (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble),   // rotation center
                (yysemantic_stack_[(14) - (9)].adouble),       // angle of rotation
                (yysemantic_stack_[(14) - (11)].adouble), (yysemantic_stack_[(14) - (13)].adouble)  // dimension of the new image
                );

      im_stack.AddImage(res);
        ;}
    break;

  case 589:
#line 8423 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

        im_stack.AddImage(res);
        ;}
    break;

  case 590:
#line 8460 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

        im_stack.AddImage(res);
        ;}
    break;

  case 591:
#line 8497 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

        im_stack.AddImage(res);
        ;}
    break;

  case 592:
#line 8534 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

        im_stack.AddImage(res);
        ;}
    break;

  case 593:
#line 8569 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        ;}
    break;

  case 594:
#line 8574 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          im_stack.AddImage((InrImage*)NULL);
/*
          im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    ;}
    break;

  case 595:
#line 8583 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    ;}
    break;

  case 596:
#line 8588 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          im_stack.AddImage(res);

    ;}
    break;

  case 597:
#line 8599 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      im_stack.AddImage(res);

    ;}
    break;

  case 598:
#line 8609 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          im_stack.AddImage(res);

    ;}
    break;

  case 599:
#line 8619 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          im_stack.AddImage(res);
    ;}
    break;

  case 600:
#line 8628 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization
      (7) maximal time
    Description:
      Runs the fast marching algorithm
     **/

        InrImage*    init = (InrImage*) im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
            float   maxtime = (float) (yysemantic_stack_[(8) - (7)].adouble);

          res = Func_vtkFastMarching( input, init,  maxtime);

          im_stack.AddImage(res);
    ;}
    break;

  case 601:
#line 8651 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   maxtime = (float) (yysemantic_stack_[(14) - (7)].adouble);

        res = Func_vtkFastMarchingTarget( input, init,  maxtime,
                (int) round((yysemantic_stack_[(14) - (9)].adouble)),
                (int) round((yysemantic_stack_[(14) - (11)].adouble)),
                (int) round((yysemantic_stack_[(14) - (13)].adouble))
                );

        im_stack.AddImage(res);
    ;}
    break;

  case 602:
#line 8680 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   mean    = (float) (yysemantic_stack_[(12) - (7)].adouble);
        float   sd      = (float) (yysemantic_stack_[(12) - (9)].adouble);
        float   maxtime = (float) (yysemantic_stack_[(12) - (11)].adouble);

          res = Func_vtkFastMarching( input, init, mean, sd, maxtime);

          im_stack.AddImage(res);
          delete init;
          delete input;
    ;}
    break;

  case 603:
#line 8708 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   mean     = (float) (yysemantic_stack_[(14) - (7)].adouble);
        float   sd       = (float) (yysemantic_stack_[(14) - (9)].adouble);
        float   maxtime  = (float) (yysemantic_stack_[(14) - (11)].adouble);
        int     inittype = (int) (yysemantic_stack_[(14) - (13)].adouble);

      res = Func_vtkFastMarching( input, init, mean, sd, maxtime,inittype);

          im_stack.AddImage(res);
          delete init;
          delete input;
    ;}
    break;

  case 604:
#line 8741 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) im_stack.GetLastImage(); // 1st param
        InrImage*    res   = NULL;
        float   maxtime    = (float) (yysemantic_stack_[(12) - (9)].adouble);
        int     inittype   = (int)   (yysemantic_stack_[(12) - (11)].adouble);

      res = Func_vtkFastMarching(
                  input,
                  init,
                  ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable)->Pointer())->get(),
                  maxtime,inittype);

      im_stack.AddImage(res);
      delete init;
      delete input;
    ;}
    break;

  case 605:
#line 8773 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          im_stack.AddImage(res);

        ;}
    break;

  case 606:
#line 8784 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        InrImage* mask = (InrImage*) im_stack.GetLastImage();
;

      res = Func_ConvolveMask(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                  mask);

          im_stack.AddImage(res);
      delete mask;

        ;}
    break;

  case 607:
#line 8800 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          im_stack.AddImage(res);

        ;}
    break;

  case 608:
#line 8810 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          im_stack.AddImage(res);

        ;}
    break;

  case 609:
#line 8820 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float a = (yysemantic_stack_[(12) - (5)].adouble);
        float b = (yysemantic_stack_[(12) - (7)].adouble);
        float c = (yysemantic_stack_[(12) - (9)].adouble);
        float dmax = (yysemantic_stack_[(12) - (11)].adouble);

          res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(), a,b,c,dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 610:
#line 8835 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 611:
#line 8849 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 612:
#line 8863 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 613:
#line 8876 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          im_stack.AddImage(res);

        ;}
    break;

  case 614:
#line 8889 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 615:
#line 8901 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 616:
#line 8913 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 617:
#line 8925 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          im_stack.AddImage(res);
        ;}
    break;

  case 618:
#line 8936 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          im_stack.AddImage(res);
        ;}
    break;

  case 619:
#line 8949 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

          im_stack.AddImage(res);
        ;}
    break;

  case 620:
#line 8976 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
       InrImage* im = (InrImage*) im_stack.GetLastImage();
           InrImage* res;

      res = Func_CC(im);

          im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 621:
#line 9009 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* im2 = (InrImage*) im_stack.GetLastImage();
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

          im_stack.AddImage(res);
      delete im2;
        ;}
    break;

  case 622:
#line 9117 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) im_stack.GetLastImage();
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      InrImage* res;

      res = Func_Histogram(im,vmin,vmax,nint);
      im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 623:
#line 9141 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* im = (InrImage*) im_stack.GetLastImage();
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

      im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 624:
#line 9183 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* res;

      InrImage* im = (InrImage*) im_stack.GetLastImage();
      if (im->DimZ()>1)
        res = Func_MeanHalfSize(im,3);
      else
        res = Func_MeanHalfSize(im,2);

      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 625:
#line 9196 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage* im = (InrImage*) im_stack.GetLastImage();
      res = Func_MeanHalfSize(im,dim);

      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 626:
#line 9207 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
            InrImage* res;
            int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

            InrImage::ptr im = InrImage::ptr((InrImage*) im_stack.GetLastImage());
            res=Func_Flip(im,axis);
            im_stack.AddImage(res);
        ;}
    break;

  case 627:
#line 9216 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

            InrImage* im = (InrImage*) im_stack.GetLastImage();
            res = Func_Resize(im,sx,sy,sz,interpolate);

            if (res!=NULL) im_stack.AddImage(res);
            delete im;
        ;}
    break;

  case 628:
#line 9240 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      if (res!=NULL) im_stack.AddImage(res);

        ;}
    break;

  case 629:
#line 9265 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage* input=(InrImage*) im_stack.GetLastImage();

      res = Func_vtkConvexHull(input,
                   order,resolution);

      if (res!=NULL) im_stack.AddImage(res);
      delete input;
        ;}
    break;

  case 630:
#line 9278 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 631:
#line 9288 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesExtremities(  );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 632:
#line 9298 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageConnections(  );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 633:
#line 9308 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) im_stack.AddImage(res);
        ;}
    break;

  case 634:
#line 9318 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) im_stack.AddImage(res);

      delete im;
        ;}
    break;

  case 635:
#line 9328 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 636:
#line 9336 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 637:
#line 9344 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) im_stack.AddImage(res);
      delete im;
        ;}
    break;

  case 638:
#line 9352 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* coeff =  (InrImage*) im_stack.GetLastImage();
      InrImage* input =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input,coeff);
      if (res!=NULL) im_stack.AddImage(res);

      delete coeff;
      delete input;
        ;}
    break;

  case 639:
#line 9379 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        /**

        description:
        Compute the altitude to the sea level based on the
        temperature channel.

        params:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      InrImage* input =  (InrImage*) im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Temp2Altitudes(input);
      if (res!=NULL) im_stack.AddImage(res);

      delete input;
        ;}
    break;

  case 640:
#line 9400 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    ;}
    break;

  case 641:
#line 9408 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        InrImage* im = (InrImage*) im_stack.GetLastImage();
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
      im_stack.AddImage(res);

        } else
     fprintf(stderr,"only UCHAR format for now \n");

        delete im;

        ;}
    break;

  case 642:
#line 9446 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
                                im_stack.GetLastImage());

      res = LineRecons( surf.get(), ref.get(), rad.get());
      im_stack.AddImage(res);
    ;}
    break;

  case 643:
#line 9469 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      im_stack.AddImage(res);
    ;}
    break;

  case 649:
#line 9494 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               ;}
    break;

  case 651:
#line 9496 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             ;}
    break;

  case 652:
#line 9497 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             ;}
    break;

  case 653:
#line 9498 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            ;}
    break;

  case 654:
#line 9499 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            ;}
    break;

  case 655:
#line 9500 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           ;}
    break;

  case 656:
#line 9501 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           ;}
    break;

  case 657:
#line 9502 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             ;}
    break;

  case 658:
#line 9503 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            ;}
    break;

  case 659:
#line 9504 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            ;}
    break;

  case 660:
#line 9505 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            ;}
    break;

  case 661:
#line 9506 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             ;}
    break;

  case 662:
#line 9507 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) ;}
    break;

  case 663:
#line 9508 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             ;}
    break;

  case 664:
#line 9510 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          InrImage* im1;
          InrImage* res;

          im1 = im_stack.GetLastImage();
          res = Norm(*im1);
          if (res!=NULL)
            im_stack.AddImage(res);
          else
            fprintf(stderr,"Error computing the norm |image| \n");
          delete im1;
        ;}
    break;

  case 666:
#line 9527 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
            im1 = im_stack.GetLastImage();
            im  = new InrImage( (WORDTYPE) (yysemantic_stack_[(4) - (2)].aint), "tmp.inr.gz", im1);
            (*im) = (*im1);
            im_stack.AddImage(im);
            delete im1;
          ;}
    break;

  case 668:
#line 9551 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 669:
#line 9557 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 670:
#line 9559 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   ;}
    break;

  case 671:
#line 9560 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   ;}
    break;

  case 672:
#line 9561 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   ;}
    break;

  case 675:
#line 9570 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 676:
#line 9571 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 677:
#line 9572 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   ;}
    break;

  case 678:
#line 9573 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   ;}
    break;

  case 681:
#line 9581 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    ;}
    break;

  case 682:
#line 9582 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    ;}
    break;

  case 683:
#line 9583 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   ;}
    break;

  case 684:
#line 9584 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   ;}
    break;

  case 685:
#line 9585 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 686:
#line 9586 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 687:
#line 9587 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 688:
#line 9588 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 690:
#line 9593 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   ;}
    break;

  case 691:
#line 9594 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   ;}
    break;

  case 692:
#line 9595 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   ;}
    break;

  case 693:
#line 9596 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   ;}
    break;

  case 708:
#line 9638 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         gltransf_stack.AddMatrix(newglt);

           ;}
    break;

  case 709:
#line 9649 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix glt;
         GLTransfMatrix* newglt;

         printf("GetTransform begin \n");
         newglt = new GLTransfMatrix();
             glt = (*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetObjectTransform();
         (*newglt) = (glt);
         gltransf_stack.AddMatrix(newglt);
         printf("GetTransform \n");
           ;}
    break;

  case 710:
#line 9662 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         gltransf_stack.AddMatrix(newglt);
       ;}
    break;

  case 711:
#line 9673 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         newglt = Func_ReadTransform((yysemantic_stack_[(4) - (3)].astring));
         if (newglt!=NULL)
           gltransf_stack.AddMatrix(newglt);
         else {
           fprintf(stderr,"TRANSFORM() Error reading file ...\n");
           sprintf(tmp_string,"TRANSFORM() Error reading file ...\n");
           err_print(tmp_string);
           gltransf_stack.AddMatrix(NULL);
           //          yyiperror(
           //          YYABORT;
         }
         delete [] (yysemantic_stack_[(4) - (3)].astring);
           ;}
    break;

  case 712:
#line 9691 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         matrix_stack.AddMatrix(m);
       ;}
    break;

  case 713:
#line 9698 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          matrix_stack.AddMatrix(newmat);
       ;}
    break;

  case 714:
#line 9708 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
         Inversion of a symmetric matrix
        **/
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          matrix_stack.AddMatrix(res);
        ;}
    break;

  case 720:
#line 9728 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               ;}
    break;

  case 722:
#line 9731 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          matrix_stack.AddMatrix(res);
        ;}
    break;

  case 723:
#line 9739 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             ;}
    break;

  case 724:
#line 9740 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             ;}
    break;

  case 725:
#line 9741 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            ;}
    break;

  case 726:
#line 9742 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            ;}
    break;

  case 727:
#line 9743 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           ;}
    break;

  case 728:
#line 9744 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           ;}
    break;

  case 729:
#line 9745 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             ;}
    break;

  case 730:
#line 9746 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            ;}
    break;

  case 731:
#line 9747 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            ;}
    break;

  case 732:
#line 9748 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            ;}
    break;

  case 733:
#line 9749 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             ;}
    break;

  case 734:
#line 9750 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) ;}
    break;

  case 735:
#line 9751 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             ;}
    break;

  case 738:
#line 9758 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 739:
#line 9759 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   ;}
    break;

  case 740:
#line 9761 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           ;}
    break;

  case 742:
#line 9771 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 743:
#line 9772 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) ;}
    break;

  case 744:
#line 9773 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   ;}
    break;

  case 745:
#line 9774 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   ;}
    break;

  case 757:
#line 9823 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        ;}
    break;

  case 758:
#line 9828 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 759:
#line 9845 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
          SurfacePoly* surf;
          surf = Func_isosurf(im,
                  (yysemantic_stack_[(6) - (5)].adouble),
                  NULL);
          Si surf != NULL Alors
            surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 760:
#line 9857 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_isosurf((*(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer()),
                  (yysemantic_stack_[(6) - (5)].adouble),
                  NULL,
                  2);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 761:
#line 9869 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(8) - (5)].adouble),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    Si surf != NULL Alors
        surf_stack.AddSurf(surf);
    FinSi
    ;}
    break;

  case 762:
#line 9881 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask = InrImage::ptr(im_stack.GetLastImage());
      InrImage::ptr im   = InrImage::ptr(im_stack.GetLastImage());
      vtkPolyData* vtklines;
      CreeCrest* crestlines;
      SurfacePoly* lines;

      crestlines = Func_IsoLine(im.get(), (yysemantic_stack_[(8) - (5)].adouble), mask.get());
      printf("running conversion to vtkPolyData ...");
      vtklines = (vtkPolyData*) (*crestlines);

      lines = new SurfacePoly(vtklines);
      if (lines != NULL)
        surf_stack.AddSurf(lines);

      //vtklines->Delete();
      delete crestlines;

    ;}
    break;

  case 763:
#line 9914 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 764:
#line 9923 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 765:
#line 9932 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 766:
#line 9941 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 767:
#line 9950 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 768:
#line 9959 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      surf_stack.AddSurf(surf);
          gr_print("image : T_Surface  ()  \n ");
        ;}
    break;

  case 769:
#line 9966 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
          gr_print("surface : T_Surface  ASTRING  \n ");

      delete [] (yysemantic_stack_[(2) - (2)].astring);
        ;}
    break;

  case 770:
#line 9974 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
          gr_print("image : T_Surface  expr_string  \n ");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        ;}
    break;

  case 771:
#line 9981 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskSurface(name);
          if (!res) {
            yyiperror(" Need Surface \n");
            YYABORT;
          }
          surf_stack.AddSurf((char*)name.c_str());
          inc_cmd = str(format(" \"%1%\"  // from browser ") % name);
          if (yy_num_buf==1)
            GB_main_wxFrame->GetConsole()->IncCommand(inc_cmd);
          gr_print("surface : T_Surface  \n ");
        ;}
    break;

  case 772:
#line 9999 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
          surf_stack.AddSurf(surf);
        ;}
    break;

  case 773:
#line 10013 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
          surf_stack.AddSurf(surf);
        ;}
    break;

  case 774:
#line 10029 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          surf_stack.AddSurf(newsurf);
    ;}
    break;

  case 775:
#line 10039 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
          SurfacePoly* surf;

      surf = Func_Skeleton2lines( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get()  );

      Si surf==NULL Alors
        sprintf(tmp_string,"Skeleton2lines() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 776:
#line 10058 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        sprintf(tmp_string,"SmoothLines() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 777:
#line 10087 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        sprintf(tmp_string,"SmoothLines() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 778:
#line 10115 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;

      surf = Func_ResampleLines( ((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     (yysemantic_stack_[(6) - (5)].adouble));

      Si surf==NULL Alors
        sprintf(tmp_string,"ResampleLines() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 779:
#line 10132 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;

      surf = Func_shortestpath( ((SurfacePoly::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        sprintf(tmp_string,"Func_shortestpath () error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 780:
#line 10150 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = Func_shortestpath_image(  im.get(),(yysemantic_stack_[(18) - (5)].adouble),
                                      (yysemantic_stack_[(18) - (7)].adouble), (yysemantic_stack_[(18) - (9)].adouble), (yysemantic_stack_[(18) - (11)].adouble),
                                      (yysemantic_stack_[(18) - (13)].adouble),(yysemantic_stack_[(18) - (15)].adouble),(yysemantic_stack_[(18) - (17)].adouble));

      Si surf==NULL Alors
        sprintf(tmp_string,"Func_shortestpath_image () error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 781:
#line 10184 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = Func_path_from_displ(  im.get(),
          (int) round((yysemantic_stack_[(10) - (5)].adouble)),
          (int) round((yysemantic_stack_[(10) - (7)].adouble)),
          (int) round((yysemantic_stack_[(10) - (9)].adouble))
          );

      Si surf==NULL Alors
        sprintf(tmp_string,"Func_path_from_displ() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 782:
#line 10221 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
      SurfacePoly* surf;

      double start[3] = {(yysemantic_stack_[(20) - (9)].adouble),(yysemantic_stack_[(20) - (11)].adouble),(yysemantic_stack_[(20) - (13)].adouble)};
      double end[3] = {(yysemantic_stack_[(20) - (15)].adouble),(yysemantic_stack_[(20) - (17)].adouble),(yysemantic_stack_[(20) - (19)].adouble)};
      surf = Func_path_from_vectfield(  im.get(),
                                        start,end,
                                        (yysemantic_stack_[(20) - (5)].adouble), (yysemantic_stack_[(20) - (7)].adouble));

      Si surf==NULL Alors
        sprintf(tmp_string,"Func_path_from_vectfield() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
      FinSi
    ;}
    break;

  case 783:
#line 10264 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        sprintf(tmp_string,"ConnectLines() error ... \n");
        err_print(tmp_string);
      FinSi
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi


    ;}
    break;

  case 784:
#line 10291 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
    ;}
    break;

  case 785:
#line 10301 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 786:
#line 10324 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = InrImage::ptr(im_stack.GetLastImage());
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(),minth,maxth);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 787:
#line 10336 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
      InrImage* im = (InrImage*) im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);

      surf = AMIFluid::Func_vtkCreateFlatMesh(im,minth,maxth);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
     delete im;
        ;}
    break;

  case 788:
#line 10349 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* highpos = (InrImage*) im_stack.GetLastImage();
      InrImage* lowpos  = (InrImage*) im_stack.GetLastImage();
      InrImage* input   = (InrImage*) im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yysemantic_stack_[(12) - (5)].adouble);
      float maxth = (yysemantic_stack_[(12) - (7)].adouble);

      surf = AMIFluid::Func_CreateVolume(input, minth, maxth, lowpos, highpos);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
      delete highpos;
      delete lowpos;
      delete input;
        ;}
    break;

  case 789:
#line 10389 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* colors  = (InrImage*) im_stack.GetLastImage();
      InrImage* highpos = (InrImage*) im_stack.GetLastImage();
      InrImage* lowpos  = (InrImage*) im_stack.GetLastImage();
      InrImage* input   = (InrImage*) im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yysemantic_stack_[(16) - (5)].adouble);
      float maxth = (yysemantic_stack_[(16) - (7)].adouble);
      float alpha = (yysemantic_stack_[(16) - (15)].adouble);

      surf = AMIFluid::Func_CreateVolume(input, minth, maxth, lowpos, highpos, colors, alpha);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
      delete highpos;
      delete lowpos;
      delete input;
        ;}
    break;

  case 790:
#line 10434 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      InrImage* alt2  = (InrImage*) im_stack.GetLastImage();
      InrImage* displ = (InrImage*) im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      float scale = (yysemantic_stack_[(16) - (13)].adouble);
      int   type  = (int) (yysemantic_stack_[(16) - (15)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale, type);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        ;}
    break;

  case 791:
#line 10484 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

      InrImage* alt2  = (InrImage*) im_stack.GetLastImage();
      InrImage* displ = (InrImage*) im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(18) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(18) - (11)].adouble);
      float scale = (yysemantic_stack_[(18) - (13)].adouble);
      int   type   = (int) (yysemantic_stack_[(18) - (15)].adouble);
      int   style  = (int) (yysemantic_stack_[(18) - (17)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale, type,style);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        ;}
    break;

  case 792:
#line 10537 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* alt2  = (InrImage*) im_stack.GetLastImage();
      InrImage* displ = (InrImage*) im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (11)].adouble);
      float scale = (yysemantic_stack_[(14) - (13)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        ;}
    break;

  case 793:
#line 10583 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* displ = (InrImage*) im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(14) - (5)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (7)].adouble);
      int stepz   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      float scale = (yysemantic_stack_[(14) - (11)].adouble);
      int style = (int) (yysemantic_stack_[(14) - (13)].adouble);
      SurfacePoly* surf;

       surf = AMIFluid::Func_CreateVectors(displ, stepx, stepy, stepz,  scale, style);
       Si surf != NULL Alors
         surf_stack.AddSurf(surf);
       FinSi
       delete displ;
        ;}
    break;

  case 794:
#line 10612 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage::ptr v3  = InrImage::ptr(im_stack.GetLastImage());
      InrImage::ptr v2  = InrImage::ptr(im_stack.GetLastImage());
      InrImage::ptr v1  = InrImage::ptr(im_stack.GetLastImage());
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
        surf_stack.AddSurf(surf);
          FinSi
        ;}
    break;

  case 795:
#line 10645 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
      InrImage* mask    = (InrImage*) im_stack.GetLastImage();
      InrImage* colors  = (InrImage*) im_stack.GetLastImage();
      InrImage* v3      = (InrImage*) im_stack.GetLastImage();
      InrImage* v2      = (InrImage*) im_stack.GetLastImage();
      InrImage* v1      = (InrImage*) im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(20) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(20) - (11)].adouble);
      int stepz   = (int) (yysemantic_stack_[(20) - (13)].adouble);
      int res     = (int) (yysemantic_stack_[(20) - (15)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids(v1,v2,v3,stepx,stepy,stepz,res,colors,mask);
      Si surf != NULL Alors
        surf_stack.AddSurf(surf);
          FinSi
     delete v1;
     delete v2;
     delete v3;
        ;}
    break;

  case 797:
#line 10690 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_INT \n ");         ;}
    break;

  case 798:
#line 10692 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_FLOAT \n ");       ;}
    break;

  case 799:
#line 10694 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_IMAGE \n ");
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        ;}
    break;

  case 800:
#line 10698 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_IMAGEDRAW \n ");   ;}
    break;

  case 801:
#line 10700 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_SURFACE \n ");     ;}
    break;

  case 802:
#line 10702 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_SURFDRAW \n ");    ;}
    break;

  case 803:
#line 10704 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_FILE \n ");        ;}
    break;

  case 804:
#line 10706 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_C_FUNCTION \n ");  ;}
    break;

  case 805:
#line 10708 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_C_PROCEDURE \n ");  ;}
    break;

  case 806:
#line 10710 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_C_IMAGE_FUNCTION \n ");  ;}
    break;

  case 807:
#line 10712 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_AMI_FUNCTION \n ");;}
    break;

  case 808:
#line 10714 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_STRING \n ");      ;}
    break;

  case 809:
#line 10716 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_MATRIX \n ");      ;}
    break;

  case 810:
#line 10718 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_GLTRANSFORM \n "); ;}
    break;

  case 811:
#line 10720 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_PARAMWIN \n ");    ;}
    break;

  case 812:
#line 10722 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_ARRAY_SURFACE \n ");       ;}
    break;

  case 813:
#line 10724 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {   gr_print("variable : VAR_ARRAY_IMAGE \n ");       ;}
    break;

  case 814:
#line 10730 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ImageExtent* extent=new ImageExtent( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        ;}
    break;

  case 815:
#line 10738 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
    {
          ImageExtent* extent=new ImageExtent((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        ;}
    break;

  case 816:
#line 10745 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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

  case 817:
#line 10761 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
        if (yy_num_buf==1) GB_main_wxFrame->GetConsole()->IncCommand(comment);

        (yyval.imageextent)=extent;
       ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 11855 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2609;
  const short int
  Parser::yypact_[] =
  {
      9351, -2609, -2609, -2609, -2609,  -401, -2609, -2609, -2609,    -3,
     279, -2609,    47,  3283,  5282,  -322,   524, -2609, -2609, -2609,
   -2609, -2609,    36,    69,    77,    79,  -312, -2609,   -54,   -71,
     -22,  -292,     2,  -249,  -226,   -55,  -183,   997, -2609, -2609,
   -2609, -2609,  -199,  -188,  -141,  -314,  -131,  -147,   -76,  -104,
    -101, -2609, -2609, -2609,   -83,   -77,   -74,   -67,   -37,    31,
     -31,   -11,    -5,    17,    25,    27,    32,    39,    65,    90,
      93,   114,   119, -2609,   158,   177, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,   180,   187,   191, -2609,
   -2609,  6986,  6986,  6986,  6986,  6986,  6986,  6986,  6986,  6986,
    6986,  6986,  6986,  6986,   451, -2609, -2609,  5282,   487,   205,
     233,   451,   239,   256,   268,   276, -2609, -2609, -2609, -2609,
   -2609,   292,   306, -2609,  3283,  6986,  6986,  6415, -2609, -2609,
    8841, -2609, -2609, -2609, -2609, -2609,    10, -2609, -2609,  -402,
     122, -2609, -2609, -2609,  6986, -2609,  -178,  -218, -2609,   -48,
     255,    72,   254,   323,   663,   -63, -2609, -2609, -2609, -2609,
      30, -2609, -2609, -2609, -2609,   686,   -20,  -106, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,   -51,
      28,  5282,   344,   359, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609,   363,   354,   376,   378,   380,   388,
     122, -2609,  -243, -2609,   427,   354,  6415,  6415,  6415,  6415,
    6415,  6415,  6415,  6415,  6415,  6415,  6415,  6415,  6415,  5282,
    6415,  6415,   122,  6415, -2609,   524, -2609,   431, -2609, -2609,
    5282, -2609, -2609,  5282, -2609, -2609,  5282,   524,  1050,    95,
      95,   556,  3283,  5282,   422,   116, 10796, 10796, -2609,   829,
      18,   584,  5282,  5282, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,   447,   359,
   -2609, -2609,  5282,  5282, 14319,    47, 14319, 14319,    47, 14319,
      47, 14319,    47,   662,  1542,   379,   381,    47,    47, 14319,
   14319,    47,    47,    47,    47,    47,    47,    47,    47,   914,
     933,  5282,    47,  5282,  5282,    80,   934, 14319,    47, -2609,
    -186,   686, -2609,   686, -2609,   686, -2609,   686, -2609,   686,
   -2609,   686, -2609,   686, -2609,   686, -2609,   686, -2609,   686,
   -2609,   686, -2609,   686, -2609,   686,   866, -2609,   944, -2609,
      10,   907,   946,   496,  5282,   524,   948,    47,    47,    47,
     503,   507,   510, -2609,   686, -2609,   686, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609,    10, -2609,   524,   524,   524,   524,
   -2609,   686,  6415,  6415,  6415,  6415,  6415,  6415,  6415,  6415,
    6415,  6415,  5282,  5282,  5282,  5282,  5282,  5282, 14319, 11724,
    5282,  5282,   636, -2609,    80,  6986,  6986,  6986,   301,  1257,
   13926,  9868,   516,  5282,  5282,   345,   161,   120,   395,   863,
    5282,    44,     3,   523,   981, -2609, -2609, -2609, -2609,   528,
     529,   530,   531,   533,   534, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609,   537,   538,   539, -2609,   540,   541,
     542,   543, -2609,   544,   545,   546,   547,   548,   549,   581,
     586,   587,   588,   589, -2609, -2609,   592,   593,   594,   595,
   -2609,   596,   597,   598,   599,   600, -2609,   601, -2609,   602,
     603,   604,   605,   606, -2609, -2609,   582,   607,  5282, -2609,
     608,   609, -2609,    -6,   610,   585,   611,   612,    71,   613,
     614,   615,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,  -176,   630,   631,   632,   633,   629,   635,   637,
     638,   639,   640,   641,   642,   643,   646,   647,   648,   649,
     650,   651,   653,   654,   655,   656,   657,   659,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   675,   676,
     678,   679,   680,   681,   682,   683,   684,   685,   687,   689,
     690,   692,   694,   696,   698,   699,   700,   702,   703,   704,
     705,   706,   707,   708,   709,   711,   712,   713,   715,   716,
     717,   718, 12648, 12648, 12648, 12648, 12648, 12648, 12648, 12648,
   12648, 12648, 12648, 12648, 12648, 14319,   719,   721,   725,   726,
     727,   728,   658,   736,   738,   739,   740,   741, 11724,   339,
   12648, 12648,   105,   122, 12648, -2609,  -363, -2609, -2609, -2609,
     986, -2609,  -354, -2609,   100, -2609,   -27,   489,   735, -2609,
     645,  1019,   -56, -2609, -2609, -2609,   757,   121,   743, -2609,
   -2609, -2609,   744,   745,   746, -2609, -2609,   763,   764,   765,
     766,   774,   777,   780,   782,   783,   784, -2609, -2609, -2609,
   -2609,   785, -2609,   524,   786,   697,   787,  5282,   789,   790,
     781,   788,  -173,   791, 14319, 14319, 14319, 14319, 14319, 14319,
   14319, 14319, 14319, 14319, 14319, 14319, 14319, 13533, 14319, 14319,
   14319,    75,   792,   793,   794,   798,   802,   804,   803,   805,
     808,   807,   813,   814,   815, -2609, -2609,   816,   817, -2609,
   -2609,   839,   840,   841,   842,   843,   844,   845,   846, -2609,
     847,   857,   869,   872,   876,   879,   880,   882,   884,   887,
     888,   889,   890,   891,   892,   893,   894,   895,   896,   897,
     898,   899,   900,   901,   903,   904,   905,   906,   908, -2609,
   -2609, -2609, -2609, -2609, -2609,   909,   911,  -230,   912,   910,
     913,   917,   918,   919,   920,   921,   922,   923,   924,   926,
     915,   927,   928,  -436,   929, -2609,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,   931,   951,   953,   952,    87,  5282, -2609,
       9, -2609, -2609,   955,   956,   957,   -90,   958,   960,   962,
     963,   964,   965, -2609,  8300, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609,  -178,  -178, -2609, -2609, -2609, -2609,   -48,
     -48,   255,    72,   254,   323,   663,   -72, -2609,   585, -2609,
   -2609,  -260,   966,   959, -2609,   968, -2609, -2609,   524, -2609,
     969,   971,   972,   973,   974,   975,   980,   982, -2609, -2609,
     686, -2609,   686,  -178,   -20,  -178,   -20,   983,   984,   985,
     987,   988,  1002,  1006,  1007,  1008,  1010,  1011,  1012,  1013,
    1014,  1015,    -2,  1016,  1018,  1020,  1021,  1023,   902, -2609,
   -2609, -2609, -2609,   524,  1024,  1025,   524, -2609,  1026, -2609,
    1027,  1028,  1029,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1041,  1042,  1043,  1044, -2609,  1045, -2609,  1046,
   -2609, -2609,  1047,  1048,  1049,  1051,  1052, -2609, -2609,  1054,
    1055,   978, -2609,   -10,  1056,  1053,  1057, -2609,  1059,    -4,
    1060,  1061,  1062,  1063, 12186, 12186, 12186, 12186, 12186, 12186,
   12186, 12186, 12186, 12186, 12186, 12186, 12186, 10332, 12186, 12186,
     122, 12186, -2609, -2609, -2609, -2609,  1064, -2609, -2609,  1066,
    1069,  -191,  5282,  5282,  5282,  5282,  5282,  5282,  5282,    47,
    5282,  5282,    55,  1089,  1128,  5282,  5282,  5282,  5282,  5282,
    5282,  5282, 14319,  5282,  1227,  5282,  1343,  5282,  5282,   301,
    5282,  5282,  5282,  5282,  5282,    95,    52,  1350,  1411,  5282,
    5282,  5282,  5282,   524,   122, -2609,   524,  1432, -2609,   260,
    5282,   315,   310, 10796, 14319,    47, 14319, 14319,    47,    47,
      47,    47,    47, 14319,    47,    47,    47,    47,    47,    67,
      47,    47,    47,    47,    81, 14319, 14319,    47,  1318,  1349,
      47,    47,    47,    47,    47,    47,    47,    47,    47, 14319,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47, 14319, 14319, 14319, 14319, 14319,    47,    47,
      47,    47,    47,    95,    95,   524,   524,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
   14319,    47,    47,    47,    47,    47,    47, 14319, 14319,  -284,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, 14319, 14319, 14319,    47, 14319,
   14319,  1090, 14319, 14319, 14319, 14319,   524,  1065,  1067, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, 11260, -2609, 11724,  4782,
   14319, 12648, 12648, 14319, 12648, 12648, 12648, 12648, 12648, 12648,
   12648, 12648, 14319, 14319, 14319, 14319, 14319,   -21,    10,   524,
     524,  1510,  1512,   524,  1521,  1523,  5282,  1522,  1524,  5282,
    1514,  5282,   524,  5282, -2609,  5282,  1458,  1459,  1083, -2609,
    1529,  1264, 14319,   590,    16,  1088,  -252, 14319, -2609,   197,
   -2609,  1096, -2609, -2609,  1097, -2609,  1098,    47,  5282,    47,
    5282,  5282,  5282,    47,    47,    47,    47,  5282,  5282,  5282,
    5282,  5282,  5282,  5282,    47,  5282,    47,    47,    47,    63,
      47,    66,    68,    47,    47,  5282,  5282,  5282,  5282,  5282,
    5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,
      47, -2609, 14319, -2609,  1099,  5282,  5282,  5282,  5282,  5282,
    5282,  5282,    47,    47,    47, -2609,  5282,  5282, -2609,  5282,
   -2609, -2609,   524, -2609,  1143, -2609, -2609, -2609, -2609, -2609,
   -2609,  1549,  1550,  1551,  1560,  1562,   139,  5282, -2609,  5282,
     524,    47,    47,  5282, -2609,  5282,  5282, -2609,  5282,  5282,
    1490,   524,    47, -2609,    47,    47,  5282,  5282,  5282,  5282,
    5282,  5282,    47,    95,    95,    95, 14319, 14319, 14319,   524,
   14319,    47,    95,    47,    95,    95, 14319, -2609,    -9, 14319,
   14319, 14319, 14319, 14319,  1355, -2609,  5282,  5282, -2609,  5282,
    5282,  5282,  5282,  5282,  5282, 14319,  5282,  5282,  5282,  5282,
    5282,  5282,  5282,  5282,    47, 14319,  5282, 14319,  5282,  5282,
      47,  5282,  5282,  5282, 14319,  5282,  5282,   524,  -227, 10796,
     524,  5282,  1565,  5282,  5282,   524,   -73, -2609, -2609,  1116,
    1132,  -342,  1133,  1134,  1135,  1137,  1138,  1140,  1141,  1144,
    1145,  1146,  1142,  1147,  1150,  1152,  1153,  1169,  1172,  1173,
    1174,  1175,  1176,  1178,  1179,  1181,  1182,   160,  1184,  1185,
    1186,  1187,  1188,  1189,  1191,  1190,   162,  1192,  1194,  1206,
    1228,  1193,  1230,  1231,  1233,  1234,  1235,  1237,  1232,  1238,
   -2609, -2609, -2609,   164,  -220,  1239,  1240,  1241,  1242,  1246,
    1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,  1256,
   -2609, -2609,  1258,  1259,  1261,  1262, -2609,  1139,  1183,  1263,
    1265,  1266,  1269,  1270,  1271,  1272,  1277,  1279,  1281,  1282,
    1283,  1284,  1285,  1289,  1291,  1296,  1298,  1299,  1302,  1307,
    1308,  1309,  1311,  1312,   182,  1314,  1315,  1316,  1317,  1319,
    1320,  1322,  1303,  1324,  1325,  1326,  1329,  1342,  1344,  1346,
    1347,  1348,  1351,  1361,  1362,  1363,  1364,  1365,  1366,  1367,
    1368,  1369,  1370,  1371,  1373,  1374,  1379,  1380,  1381,  1386,
    1387,  1388,  1389,  1390,   184,  1402,  1403,  1404,  1405,  1273,
     188,   192,  1406,  1408,  1409, 13110, -2609,   585,   346,   122,
   -2609, -2609,  1413,   363,  1415,  -109,  -243,  1244, -2609, -2609,
   -2609, -2609, -2609, -2609,  -178,  -354,  -178,  -354, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609,   -27, -2609,   -27,
     489, -2609,   645,  1019,   -50,  1352,  1420,  1421,  1423, -2609,
    1424,  1425,  1426,  1427,  1428,  1430,   194,  1431,  1433,  1434,
    1436,  1438,  1439,  1440,  1441,  1267,   301, 14319, -2609,  1442,
   14712,  1225,    47,    47,    47,   196,  1443,  1446,   198,  1444,
    1448,  1449,  1451,  1452,  1453,  1455,  1456,  1457,  1460,  1461,
    1462,  1463,  1464,  1466,  1467,  1468,  1471,  1473,  1474,  1475,
    1476,  1477,  1478,  1479,  1480,  1481,  1482,  1483,  1485,  1486,
    1488,  1489,  1491,  1492,  1493,  1495,  1496,  1497,  1498,  1499,
    1501,  1500,  1504, 14319,  1505,  1508,   200,  1509,  1511,  1513,
    1515,  1516,  1519,  1526,  1527,  1530,  1533,  1534,  5282,    10,
   -2609, -2609, -2609, -2609, -2609, -2609,   -44,  1535,  1536,  1538,
    1539,  1543, -2609,  1546,  -138,  1547, 11724,  1552,   202,  1553,
    1554,  1555,  -304,  1556,  -251,  1559,   218,  1561,   220,  1563,
     222,  1567,  1568,  1575,  1579,  1585,   224,  1586,  1591,   226,
    1593,  1594,  1595,  1596, -2609,  1566,   228,  1597,  1599,  1600,
    1602,  1465,  1605,  1609,  1610,  1611,   230,  1612,  1613,  1614,
     235,  1616,  1618,  1619,  1621,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,  1632,  1634,  1635,  1636,  1638,  1639,
    1345,  1385,  1640, -2609,   257,  1641,  1487,  1642,  1644,  1645,
    1646, -2609,    47,  5282,  5282,  5282,  5282, -2609,  5282, -2609,
    5282, -2609, -2609, -2609,    47,    47,  5282,  5282,  5282, -2609,
   -2609,  5282,  5282,  5282,  5282, -2609,  5282, -2609,  5282, -2609,
    5282, -2609, -2609,  5282,  5282,  5282,  5282, -2609,  1356, -2609,
    5282, -2609,    47,  5282, 14319, -2609,  1695,  1710, -2609, -2609,
   -2609,  5282,    48,  5282, -2609, 14319,    73,  5282,  5282, -2609,
    5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,
    5282,  5282, -2609,  5282,    47,    47, 14319, 14319,    47,    47,
      47, -2609,  5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,
    5282, -2609, -2609, -2609,    47, -2609,    47,    47,    47,    47,
      47, -2609,    47,    47,  5282,  5282,  5282,  5282, 14319, 14319,
   -2609,  5282,  5282,  5282,  5282,    47,   524, -2609, -2609,    47,
      47,  5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,
    5282,  5282, -2609, -2609, -2609, -2609, -2609, -2609, -2609,  5282,
    5282,  5282, -2609,  5282,  5282,    47,  5282,  5282,    47, -2609,
    5282, -2609,  5282, 14319, -2609, -2609, 11724, -2609, -2609, -2609,
   -2609, -2609, -2609,  1260, -2609,  5282, -2609, 14319,    47,  1648,
    1649,  1650, -2609, -2609,  5282,  5282,  1697, -2609, -2609,  5282,
     524,   524,   524,  5282, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, 14319,  1652,  1653,   259, -2609,    47, -2609,  5282,
   -2609,  5282, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609,  5282, -2609, -2609,    47, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
    5282, -2609,  5282, -2609, -2609, -2609, -2609,  5282, -2609, -2609,
   -2609, -2609, -2609,  5282, -2609, -2609,  1654,  5282,  5282, -2609,
   11724,  5282,  5282, -2609,  5282,  5282,    47,    47,  5282,  5282,
   -2609,  5282,  1484, -2609,    10,  1799,  1875,  1882,  1907,  1908,
    5282,  5282, -2609,    47,  5282, -2609,  5282, -2609,  5282,  5282,
   -2609, -2609, -2609, -2609,  5282, -2609, -2609,  5282, -2609,  5282,
   -2609, -2609, -2609,  5282,  5282, -2609,  5282, -2609, -2609,  5282,
    5282,  5282,  5282,  5282,  5282, -2609,  5282,  5282,  5282, -2609,
    5282,  5282,  5282,  5282,  5282, -2609, -2609,  5282,  5282,  5282,
   11724, 14319,  5282, -2609, -2609, -2609, -2609, -2609,  5282, -2609,
   -2609,  5282, -2609,  5282, -2609,  5282,  5282,  5282, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,  5282,  5282, -2609, -2609,
    5282, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,  1901,
   -2609, -2609,  1935,  1656,  1655,  1657,  1659,  1661,  1660,  1662,
    1664,  1665,  1666,  1667,  1668,  1669,  1671,  1672,  1673,  1674,
    1675,  1677,  1678,  1679,  1680,  1681,  1683,  1684,  1685,  1686,
    5282,  1688,  1689,  1690,  1692,   261,  1693,  1694,  1696,  1698,
    1699,  1700,  1701,  1703,  1704,  1705,  1706,  1707,  1708,  1709,
    1711,  1712,  1714,  1715,  1716,  1717,  1718,  1722,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1733,  1734,  1735,
    1736,  1737,  1738,  1739,  1741,  1742,  1743,  1745,  1747,  1748,
    1749,  1750,  1752,  1753,  1754,  1755,  1756,  1758,  1760,  1762,
    1763,  1764,  1761,  1766,  1767,  1768,  1769,  1770,  1771,   263,
    1772,  1773,  1774,  1775,  1777,  1778,  1779,  1781,  1782,  1783,
    1785,  1787,  1788,  1789,  1790, -2609,  1792, -2609, -2609, -2609,
    1793,  1794,  1796,  1797,  1798,  1800,  1801,  1803, -2609, -2609,
   -2609,  5282,  1804,  1805,  1807,  1808,  1809,  1810,  1812,  1813,
    1814, -2609,   265,   270,   272,  1816,  1817,  1818,  1819,  1820,
    1821,  1822,  1823,  1824,  1826,  5282,    10, -2609, -2609, -2609,
   -2609, -2609, -2609,  1827,  1828,  1829,  1830,  1832,  -134,  1506,
    1833,  1834,  1835,  1836,  1837,  1839,  1841,  1844,  1845,  1846,
    1847,  1848,  1852,   280,  1857,  1862,  1863,  1864,  1866,  1869,
     285,  1870,  1871,  1872,  1874,  1876,  1877,  1867,  1879,  1888,
    1903,  1905,  1906,  1909,  1910,  1911,  1913,  1915,  5282, -2609,
    5282, -2609,  5282, -2609,  5282, -2609, -2609, -2609, -2609,  5282,
    5282, -2609,  5282,  5282,  5282,  5282, -2609,  5282,  5282,  5282,
    5282, -2609, -2609, -2609,  5282, -2609, -2609,  5282,  5282, -2609,
   -2609,   137,    74,  5282, -2609, -2609, -2609, -2609,  5282, -2609,
    5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282, -2609,  5282,
    5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,  5282,
    5282,  5282,  5282, -2609,  5282,    47,    47,    47,    47,    47,
   -2609, -2609,  5282, -2609, -2609, -2609,  5282,  5282, -2609, -2609,
   -2609, -2609, 14319, -2609, -2609, 14319,  5282,  5282, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,  5282,  5282,  5282,  5282,
    5282, -2609,  5282,  5282, -2609,  5282,  5282, -2609, -2609, -2609,
    5282,  5282, -2609,  5282,  5282, -2609, -2609, -2609, -2609,   524,
   -2609,  1916, -2609,  5282, -2609, -2609,    47,  5282, -2609,  5282,
    5282, -2609, 14319, -2609, 14319, -2609, 14319, -2609, 14319,  5282,
    5282,  5282,    47,    47,  5282,  5282, -2609, -2609, -2609, -2609,
    5282,    47,  5282, -2609,  5282, -2609,  5282,  5282,  5282,  5282,
    5282,  5282,  5282,  5282,  5282, -2609,  5282,  5282,  5282,  5282,
   -2609, -2609,    47, -2609, -2609, -2609, -2609, -2609, 14319, -2609,
    5282,  5282,  5282,  5282, 14319, 14319,  5282, -2609,  5282,  5282,
    5282,  5282,  5282,  5282,  5282,  5282,  5282, -2609,  1919,   287,
    1920,  1922,  1923,  1924,  1926,  1928,  1929,  1931,  1932,  1933,
    1934,  1936,  1941,  1944,  -234,  1947,  1948,  1950,  1520,   289,
    1952,  1955,  1956,   293,   295,   303,   311,  1957,  1958,  1959,
    1960,  1962,  -208,   326,  -202,  1964,  1965,  1966,  1968,   328,
    1971,  1972,  1973,  1974,  1975,  1976,  1963,  1977,  1978,  1982,
    1983,  1986,  1987,  1988,  1990,  1992,  1994,  1996,  2005,  2010,
    2012,  2013,  2014,  2015,  2016,  2017,  2018,  2020,  2024,  1637,
    1663,  2026,  2028,  2037, -2609,  2038,  2040,  2041,  2043,  2044,
    2046,   330,  2047,  2048,  2049,  2051,  2052,   332,  2053,  2055,
    2056,    10,  2057,  2058,  2059,  2061,  2062,  2063,  2064,  2066,
    2068,  2069,  2070,  2071,  2072,  2073,  2074,  2075,  2076,  2078,
    2079,  2080,  2081,  2083,  2084,  2085,  2086,  2088,  2089,  2090,
    2091,  2092,  2093,  2094,  2095,  2096,  2097, -2609, -2609,  5282,
    5282, -2609,  5282,  5282, -2609,  5282,  5282, -2609,  5282,  5282,
    5282, -2609,  5282,  5282, -2609,   137,  5282, -2609, -2609,   137,
    1945,  5282,  5282, -2609,  5282, -2609,  5282, -2609,  5282, -2609,
    5282,  5282,  5282,  5282,  5282, -2609, -2609, -2609,  5282,  5282,
    5282,  5282,  5282,  5282, -2609,  5766,  5766,  5766,  5282,  5282,
    5282,  5282, -2609,  5282,  5282,  5282,  5282,  5282,    47,  5282,
   -2609, -2609, -2609, -2609,  5282,  5282, -2609,  5282,  5282,  5282,
    5282,  5282,  5282, -2609,  5282,  5282,  5282, -2609, -2609,   524,
    5282, -2609,  5282, -2609,  5282, -2609, -2609,  5282, -2609,  5282,
    5282, -2609,  5282, -2609, 14319,    47, -2609, -2609, -2609,  5282,
      47,  5282, -2609, -2609,  5282,  5282, -2609, -2609, -2609, -2609,
   -2609,  5282,  5282,  5282,  5282,  5282, -2609, -2609, -2609, 14319,
   -2609,  5282,  5282,  5282, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609,  2098,  2100,  2101,  2102,  2104,  2105,
    2107,  2108,  2109,  2110,   334,  2111,  2112,  2114,   337,  2115,
    2116,   340,   342,  2117,  2118,  2119,  2120,  2121,  2123,  2124,
    2125,  2126,  2127,  2128,  2129,  -411,  2131,  -371,  2132,  1751,
    2133,  2134,  2135,  2136,  2137,  2138,  2139,  2140,  2141,  2142,
     349,  2143,  2145,   351,  2146,  2147,  2148,  2149,  2150,  2151,
    2153,  1502,  2154,  2156,  2157,   355,  2158,  2160,  2161,  2162,
    2163,  2165,  2166,  2167,  2168,  2171,  1784,  2175,  2178,  2181,
    2184,  2186,  2187,  2188,  2189,  2190,  2193,  5282, -2609, -2609,
    5282,  5282,  5282, -2609, -2609, -2609,  5282, -2609,  5282,  5282,
     524, -2609, -2609,   137,  5282,  5282, -2609,  5282, -2609,  5282,
    5282,  5282,  5282,  5282,  5282, -2609,  5282,  5282,  5282,  5282,
    5282,  5282,  5766, -2609,  5766, -2609, -2609,  5766,  5766,  5282,
    5282,  5282,    47,    47,    47,    47, -2609,  5282,  5282, -2609,
   -2609,  5282, -2609, -2609, -2609,  5282,  5282,  5282, -2609, -2609,
    5282, -2609, -2609, -2609,  5282,  5282, -2609, -2609,  5282,  5282,
   -2609,    47,  5282,    47,  5282,  5282, -2609, -2609,  5282,  5282,
   -2609,  5282, 14319,  5282,  5282,  5282,  2196,  2197,  2199,  2205,
    2206,  2208,  2214,  2222,  2231,  2232,  2233,  2237,  2244,  2248,
    2249,  2250,  2252,  2253,   387,  2256,  2258,  2257,  2262,  2263,
    2265,  2266,  2267,  2268,  2270,  2269,  2273,  2274,  2277,  2278,
    2279,  2287,  2288,  2290,  2294,  2291,  2295,  1904,  2296,  2298,
    2299,  2300,  2301,  2302,  2303,  2304,  2306,  2307,  2308,  2309,
     394,  2310,  2311,  2312, -2609,  5282,  5282,  5282,  5282, -2609,
    5282,  5282, -2609, -2609,  5282, -2609, -2609, -2609, -2609, -2609,
   -2609,  5282, -2609,  5282, -2609,  5282, -2609, -2609,  5282, -2609,
   -2609, -2609, -2609,  5766, -2609, -2609, -2609, -2609,  5282,  5282,
   -2609,  5282, -2609,  5282, -2609,  5282,  5282,  5282, -2609,  5282,
    5282,    47,  5282,    47,  5282,  1891,  5282,  5282,  5282, -2609,
   14319,  5282,  5282,  5282,  2314,  2315,  2316,  2318,   -33,  2319,
    2320,  2321,  2323,  2324,  2325,  2326,  2328,  2329,  2330,  2332,
    2333,  2334, -2609,  2336,   402,  2337,   404,  2338,  2339,  2340,
   14319,  2341,  2342,  2343,  2344,  2346,   433,  2347, -2609, -2609,
    5282, -2609, -2609,   524,  5282,  5282, -2609, -2609, -2609,  5282,
   -2609,  5282,  5282, -2609,  5282,  5282, -2609, -2609, 14319,  5282,
   -2609, 14319,  5282,  5282,  5282, -2609,  5282,  5282,  5282,  5282,
   -2609, -2609,  5282,  5282,  2348,  2350,  2351,  2352,  2353,  2354,
    2355,  2356,  2357,  2359,  2360,  2361,  2362,  2363,  2364,  2366,
    2367,  2368,  2370,   437,   439,  5282, -2609, -2609, -2609, -2609,
   -2609,  5282,  5282,  5282, -2609, -2609, -2609,  5282,  5282,    47,
   -2609,  5282,  5282, -2609, -2609,  5282, -2609, 14319,  2371,  2372,
    2374,  2375,  2377,  2378,  2379,  2381,  2382,  2384,  2385,  5282,
    5282, -2609,  5282, -2609,  5282,    47, -2609,  5282, -2609, 14319,
    2386,  2389,  2393,  2394,  2395,  2390,  2398,  5282, -2609,  5282,
    5282,  5282, -2609, -2609,  2400,  2401,  2402,  2404,  5282,  5282,
    5282, -2609,  2406,  2408,  2415,  5282,  5282,  5282,  2424,  2425,
    2426, -2609,  5282,  5282,  2432,  2434,  5282, -2609,  2435, -2609
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         0,    56,    57,    58,    59,     0,   362,    26,    14,     0,
      87,    61,     0,     0,     0,     0,     0,    86,   348,   361,
     796,   495,   365,   366,   367,   349,     0,   757,     0,   713,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    31,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,   352,   291,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,     0,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,     0,     0,     0,   363,
     364,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,    27,     0,    23,     0,
       0,     0,     0,     0,     0,     0,   311,   312,   313,   314,
     315,     0,     0,    15,     0,     0,     0,     0,   449,   450,
       0,     2,     6,     8,    12,    10,     0,   350,   354,   357,
       0,   369,   431,   451,     0,   453,   456,   459,   460,   465,
     470,   472,   474,   476,   478,   480,   482,   483,   284,   428,
       0,   715,   717,   718,   736,   737,   741,   746,   747,   748,
     749,   750,   751,   752,   753,   754,   755,   756,    94,     0,
       0,     0,     0,     0,    82,    62,    64,    89,    88,    63,
     365,   366,   367,   349,     0,   713,     0,     0,     0,     0,
      91,    97,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,    98,     0,    85,     0,    72,    73,
       0,    75,    76,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   320,   320,    25,     0,
       0,     0,     0,     0,   798,   797,   808,   800,   801,   802,
     809,   803,   804,   805,   806,   807,   811,   810,   812,   813,
     799,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   436,
       0,   723,   437,   724,   442,   729,   443,   730,   444,   731,
     445,   732,   446,   733,   448,   735,   447,   734,   438,   725,
     439,   726,   440,   727,   441,   728,     0,    18,     0,   359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   428,     0,   435,   721,   434,   720,   433,     1,     3,
       7,     9,    13,    11,     0,     4,     0,     0,     0,     0,
     432,   719,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   722,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    77,    78,    81,     0,
       0,     0,     0,     0,     0,   405,   406,   403,   404,   401,
     402,   407,   408,   409,     0,     0,     0,   101,     0,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,   240,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,   242,     0,   250,     0,
       0,     0,     0,     0,    43,    44,     0,     0,     0,    96,
       0,     0,    55,   505,     0,   335,     0,     0,     0,     0,
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
       0,     0,     0,   323,     0,   321,   509,   644,   646,   647,
     665,   667,   673,   674,   679,   680,   689,   694,   696,   697,
     699,   701,   703,   705,   707,   329,     0,     0,     0,   298,
     294,   295,     0,     0,     0,   302,   303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   299,   300,   301,
     304,   424,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   509,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,     0,     0,   410,
     411,     0,     0,     0,     0,     0,     0,     0,     0,   412,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     190,   152,   153,   154,   155,     0,     0,   509,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   713,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   360,
       0,    22,   812,     0,     0,     0,   337,     0,     0,     0,
       0,     0,     0,   368,     0,   716,     5,   355,   356,   468,
     469,   454,   455,   457,   458,   463,   464,   461,   462,   466,
     467,   471,   473,   475,   477,   479,     0,    67,     0,    68,
      66,     0,     0,     0,   353,     0,   377,   379,     0,   192,
       0,     0,     0,     0,     0,     0,     0,     0,   494,   378,
     739,   738,   740,   742,   744,   743,   745,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   771,     0,     0,     0,     0,     0,   774,    47,
     380,   381,   382,     0,     0,     0,     0,   226,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,     0,   212,     0,
     222,   223,     0,     0,     0,     0,     0,   231,   233,     0,
       0,     0,    38,   505,     0,     0,     0,   708,     0,   771,
       0,   485,   488,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,    51,    37,    42,    41,   774,    46,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    95,     0,     0,   497,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   509,
     665,   651,   652,   657,   658,   659,   660,   661,   663,   662,
     653,   654,   655,   656,   664,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   428,     0,   325,
     327,   331,   333,   650,   649,   318,     0,   648,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   310,     0,   758,   496,     0,    32,
       0,     0,     0,     0,     0,     0,   509,     0,   388,     0,
     390,     0,   391,   392,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   384,     0,   389,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,     0,     0,   386,     0,
     714,   400,     0,   287,     0,   358,   359,    19,   426,   427,
     289,     0,     0,     0,     0,     0,     0,     0,   234,     0,
       0,     0,     0,     0,   452,     0,     0,   370,     0,     0,
       0,     0,     0,   191,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   769,     0,     0,
       0,     0,     0,     0,     0,   195,     0,     0,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,   758,   496,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     595,   593,   594,     0,   509,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     564,   565,     0,     0,     0,     0,   568,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   645,   336,     0,   324,
     322,   330,     0,   817,     0,     0,   816,     0,   706,   668,
     670,   669,   671,   672,   675,   677,   676,   678,   687,   683,
     688,   684,   685,   681,   686,   682,   692,   690,   693,   691,
     695,   698,   700,   702,     0,     0,     0,     0,     0,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     340,   341,   342,   338,   339,   359,     0,     0,     0,     0,
       0,     0,   481,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   768,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   709,     0,     0,     0,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,   124,     0,   127,
       0,   100,   103,   102,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,     0,   117,     0,   126,     0,   243,
       0,   238,   245,     0,     0,     0,     0,   241,     0,   251,
       0,   246,     0,     0,     0,   249,   413,     0,   429,   430,
     498,     0,     0,     0,   504,     0,     0,     0,     0,   544,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   545,     0,     0,     0,     0,     0,     0,     0,
       0,   576,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   529,   530,   531,     0,   533,     0,     0,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
     547,     0,     0,     0,     0,     0,     0,   502,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   620,   525,   527,   589,   590,   591,   592,     0,
       0,     0,   624,     0,     0,     0,     0,     0,     0,   635,
       0,   637,     0,     0,   639,   640,     0,   666,   326,   328,
     332,   334,   621,     0,   510,     0,   551,     0,     0,     0,
       0,     0,   297,   296,     0,     0,     0,   418,   420,     0,
       0,     0,     0,     0,   306,   307,   293,   425,    48,    45,
      40,    33,     0,     0,     0,     0,   282,     0,   138,     0,
     137,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   158,   159,   160,     0,   173,   174,     0,   176,
     184,   178,   179,   185,   180,   186,   182,   183,   181,   161,
       0,   171,     0,   162,   187,   188,   167,     0,   163,   164,
     165,   166,   169,     0,   383,   399,     0,     0,     0,   264,
       0,     0,     0,   271,     0,     0,     0,     0,     0,     0,
     712,     0,   359,    20,     0,     0,     0,     0,     0,     0,
       0,     0,   308,     0,     0,   376,     0,   371,     0,     0,
      70,    69,   135,   134,     0,   193,   194,     0,   278,     0,
     280,   281,   130,     0,     0,   128,     0,   775,   776,     0,
       0,     0,     0,     0,     0,   772,     0,     0,     0,   763,
       0,     0,     0,     0,     0,   770,   784,     0,     0,     0,
       0,     0,     0,   213,   218,   224,   225,   228,     0,   227,
     197,     0,   209,     0,   205,     0,     0,     0,   201,   202,
     203,   204,   210,   219,   211,   214,     0,     0,   207,   217,
       0,   232,   236,    35,    36,   711,    39,   292,    34,     0,
      50,    49,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   704,     0,   630,   631,   632,
       0,     0,     0,     0,     0,     0,     0,     0,   394,   395,
     396,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   398,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,   345,   346,
     347,   343,   344,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
       0,   122,     0,   125,     0,   106,   104,   107,   109,     0,
       0,   114,     0,     0,     0,     0,   244,     0,     0,     0,
       0,   252,   247,   258,     0,   414,    54,     0,     0,   516,
     517,     0,     0,     0,   543,   546,   548,   549,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,   569,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
     541,   542,     0,   511,   512,   513,     0,     0,   596,   597,
     598,   599,     0,   643,   605,     0,     0,     0,   610,   611,
     612,   613,   614,   615,   616,   617,     0,     0,     0,     0,
       0,   625,     0,     0,   626,     0,     0,   634,   636,   638,
       0,     0,   633,     0,     0,   417,   419,   421,   422,     0,
     305,     0,   283,     0,   149,   172,     0,     0,   175,     0,
       0,   259,     0,   261,     0,   266,     0,   265,     0,     0,
       0,     0,     0,     0,     0,     0,   286,   359,    16,   319,
       0,     0,     0,   375,     0,   372,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   778,     0,     0,     0,     0,
     773,   759,     0,   760,   764,   765,   766,   767,     0,   785,
       0,     0,     0,     0,     0,     0,     0,   229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   397,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   120,     0,
       0,    99,     0,     0,   116,     0,     0,   237,     0,     0,
       0,   257,     0,     0,   508,     0,     0,   518,   519,     0,
       0,     0,     0,   555,     0,   558,     0,   560,     0,   562,
       0,     0,     0,     0,     0,   566,   567,   600,     0,     0,
       0,     0,     0,     0,   577,     0,     0,     0,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
     514,   515,   642,   606,     0,     0,   618,     0,     0,     0,
       0,     0,     0,   629,     0,     0,     0,   415,   416,     0,
       0,   177,     0,   168,     0,   260,   262,     0,   267,     0,
       0,   276,     0,   275,     0,     0,   385,   387,    17,     0,
       0,     0,   374,   373,     0,     0,   277,   279,   131,   132,
     129,     0,     0,     0,     0,     0,   761,   762,   786,     0,
     787,     0,     0,     0,   783,   206,   208,   198,   199,   200,
     215,   216,   230,   710,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   815,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   110,
       0,     0,     0,   254,   255,   256,     0,   506,     0,     0,
       0,   520,   521,     0,     0,     0,   554,     0,   557,     0,
       0,     0,     0,     0,     0,   526,     0,     0,     0,     0,
       0,     0,     0,   578,     0,   580,   582,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   538,     0,     0,   607,
     608,     0,   619,   622,   623,     0,     0,     0,   524,   552,
       0,   423,   136,   156,     0,     0,   263,   270,     0,     0,
     274,     0,     0,     0,     0,     0,   133,   777,     0,     0,
     781,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,     0,   507,
       0,     0,   522,   523,     0,   556,   559,   561,   563,   570,
     573,     0,   602,     0,   604,     0,   571,   574,     0,   579,
     581,   583,   584,     0,   586,   532,   534,   535,     0,     0,
     539,     0,   609,     0,   627,     0,     0,     0,   170,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   788,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   814,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,   115,
       0,   248,   500,     0,     0,     0,   572,   603,   601,     0,
     585,     0,     0,   588,     0,     0,   157,   268,     0,     0,
     273,     0,     0,     0,     0,    71,     0,     0,     0,     0,
     793,   792,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   501,   499,   553,   575,
     536,     0,     0,     0,   269,   288,   272,     0,     0,     0,
     779,     0,     0,   789,   790,     0,   794,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,     0,   235,     0,     0,   780,     0,   791,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   537,     0,
       0,     0,   782,   795,     0,     0,     0,     0,     0,     0,
       0,   317,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,     0,     0,   316,     0,   628
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2609, -2609,   -28,  1883,  1892,  1900,  1980,  1985,  -242, -2609,
   -2609,   557, -2609,   269,  -337, -2609, -2609, -2609, -2609,  -794,
    5633,   112,  -359, -2609,  -370,   551,  1658,  1811,  1806,  1280,
    1765,  1885,   733, -2609,     0,  -123,  3158, -2609, -2609, -2609,
    -521,  -216,  -211, -2609, -2609,  -607,  -194,   941, -2609,  1004,
    1022,   970,  1009,   251,  1040,  6840,  1217, -2609, -2609, -2609,
   -2609,   701,   562, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609,    35,  6683,  -398,   163,  1831, -2608
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   130,   131,   132,   133,   134,   135,   136,   602,  1276,
     137,   138,   139,   140,   337,   338,  1265,   141,   142,   143,
     223,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   350,   159,   202,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,  1128,   954,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   352,   204,   879,   849,   271,  1537
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       158,   351,   790,   957,   248,   627,   815,   816,   817,   818,
    1284,    15,     8,   201,   224,   813,   814,  1008,    18,     8,
       8,  1008,    21,  1317,   386,  1317,   193,   251,    21,   239,
     240,   398,   242,   386,    27,   178,   652,   853,   855,   183,
    1155,  1446,   410,  1258,   182,   183,  1155,   411,   203,   376,
     377,  1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,
    1100,  1100,  1100,  1100,  1100,   924,   368,   369,   834,  2902,
    1146,  1147,   834,  1915,    20,  1421,  1422,   181,    21,  1100,
    1100,   244,   394,  1100,   366,   367,    21,  2816,  2818,  2820,
    1405,  1380,  1440,  1441,    21,   183,   351,    21,   927,    21,
    2145,  2539,   359,   183,    21,    21,  1446,   339,   365,  2904,
     400,   183,   388,  1915,   183,  1138,   183,    20,  1139,   765,
     411,   183,   183,    52,   880,   881,   882,  1743,   228,   229,
     158,   401,    27,   389,   478,  1141,   410,  1142,  1753,   230,
    1143,   411,   182,  1100,  1100,  1100,  1100,  1100,  1100,  1100,
    1100,  1100,  1100,  1100,  1100,  1100,   225,  1100,  1100,  1100,
    1447,   231,   232,   180,   275,   178,  1711,   276,    21,   234,
     235,   238,   233,   188,   410,  2038,   880,   881,   882,   411,
     236,   402,   237,   633,   634,   183,   246,   637,   638,   639,
     640,   641,   642,  1617,  1138,  1448,  1620,  1139,  1622,   787,
     880,   881,   882,   309,   312,   314,   316,   318,   320,   322,
     324,   326,   328,   330,   332,   334,   709,  1286,   653,  1287,
    1288,   368,   369,   836,  1289,  1447,  1187,   410,  2040,  1139,
     415,  1591,   411,   416,   249,   410,   417,   353,   355,   357,
     411,   837,   474,   476,   410,  2664,   605,   605,  1187,   411,
    1242,  1139,   655,   656,   699,   700,   370,   250,  1187,  1190,
    1448,  1139,  1565,  1566,  1567,  1568,   836,   336,   374,   375,
     410,  2686,   658,   659,   343,   411,   410,   475,  2689,   272,
      15,   411,   200,   222,   837,   226,  1286,    18,  1287,  1288,
     273,    21,   410,   180,  2980,   193,  2981,   787,   253,  2982,
    2983,   760,  1028,   762,   764,  1028,   187,  1029,   183,    20,
    1183,   372,   791,   373,  1565,  1566,  1567,  1568,   309,   312,
     314,   316,   318,   320,   322,   324,   326,   328,   330,   332,
     334,   278,   353,   355,   279,   370,   806,   274,    27,  2026,
     783,  2027,  2028,  2474,   797,  2475,  2476,   277,   182,  1271,
    1272,  1273,  1274,  1275,   380,   381,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,
      21,  1129,  1130,  1914,   282,  1915,    27,    21,  1908,  1909,
     396,   397,   283,    27,  1133,  1134,   182,   183,  1137,   829,
     831,   832,    52,   182,   183,  2015,  2016,  2017,  2018,  2019,
     284,   952,   280,   959,   960,   281,   285,   243,   930,   286,
     961,   287,  1285,  1100,  1100,  1100,  1100,  1100,  1100,  1100,
    1100,  1100,  1100,  1100,  1100,  1100,   252,  1100,  1100,   241,
    1100,   184,   399,   387,  1917,  3086,   955,    74,    75,   848,
    1156,   288,  1266,   848,   378,   379,  3112,   291,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,   245,  1133,  1134,  1137,  1148,  1149,   292,  1009,   395,
    1704,  1356,  1009,   293,  1318,  1127,  1318,  1361,  1005,   123,
     247,    20,   848,   651,   811,   812,   123,   123,   766,   767,
     768,   769,   770,   771,   413,   294,   772,   773,   774,   775,
     776,   777,   778,   295,   793,   296,   418,   851,   390,   289,
     297,   391,   290,   392,   340,   603,   603,   298,   479,   480,
     481,   482,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,  1565,  1566,  1567,  1568,   857,   858,   859,  1549,
    1551,  1553,  1555,   299,    15,   860,   861,   862,   863,  1014,
     864,    18,   276,  1187,  1185,    21,  1139,   382,   779,   193,
     741,   742,   743,   744,   480,   481,   780,   781,   300,   128,
     129,   301,   183,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   699,   700,  1135,  1136,  1144,  1145,  1150,  1151,
     865,  1398,   302,   866,   867,   868,   869,   303,   870,   871,
    1158,  1136,   872,   425,   426,   427,   428,   429,   430,   431,
     432,   433,  1421,  1422,   798,  1440,  1441,  1420,  1665,  1666,
    1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,
    1100,  1100,  1100,  1100,  1100,  1100,   304,   809,   810,  1779,
    1780,  1789,  1790,  1804,  1136,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   305,    52,  1178,   306,   833,
     834,  1851,  1852,  1892,  1893,   307,    20,  1899,  1900,   308,
     950,  1901,  1902,  1928,  1929,  1946,  1947,  1950,  1951,  1999,
    2000,  2033,  2034,   341,   309,   312,   314,   316,   318,   320,
     322,   324,   326,   328,   330,   332,   334,  2042,  2043,  2045,
    2046,  2048,  2049,  2055,  2056,  2059,  2060,  2066,  2067,  2077,
    2078,   342,   353,   355,  2082,  2083,   370,   344,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1284,  1133,  1134,   345,  1137,  2106,  1136,  2240,  2241,
    2350,  2351,  2415,  2416,  2451,  2452,   346,  1004,   383,  2453,
    2454,  2455,  2456,   835,   347,   873,   874,   875,   385,  2491,
    2492,   876,  1267,   877,  2499,  2500,  2648,  2649,  2668,  2669,
     348,  1423,  2673,  2674,  2675,  2676,  1548,  1550,  1552,  1554,
    1556,  1558,  2677,  2678,   349,  1544,  1546,   393,  1264,   692,
    2679,  2680,   311,   313,   315,   317,   319,   321,   323,   325,
     327,   329,   331,   333,   335,  2687,  2688,  2694,  2695,  2736,
    2737,  2743,  2744,  2877,  2878,   836,  2882,  2883,   384,  2886,
    2887,  2888,  2889,   477,  1127,   403,   354,   356,  2916,  2917,
    2920,  2921,   243,   837,  2933,  2934,   838,   839,   840,   841,
     404,   693,   694,   695,   696,   371,   405,   697,   698,   699,
     700,   701,   702,   703,   704,   705,   706,   707,   708,   406,
     456,   407,   457,   408,   458,   459,  3032,  3033,   842,   843,
     844,   409,   460,  3069,  3070,   461,   462,   463,   464,   465,
     466,  3127,  3128,  3130,  3131,   654,  1417,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     412,   467,  3141,  3142,   414,   468,  3184,  3185,  3186,  3187,
     469,   470,  1174,   807,   808,  1540,  1542,  1543,   657,  1659,
     471,   819,   820,  1545,  1547,   472,   473,    20,    21,   254,
     255,   758,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   792,   269,  1557,  1559,   854,   856,
     759,   784,  1369,  1370,  1372,  1373,  1374,  1375,  1376,   788,
    1378,  1379,   789,   795,   796,  1384,  1385,  1386,  1387,  1388,
    1389,  1390,   803,  1392,   799,  1394,   804,  1396,  1397,   805,
    1399,  1400,  1401,  1402,  1403,   958,   845,   846,   709,  1409,
    1410,  1411,  1412,   962,  1907,   834,   963,   964,   965,   966,
    1419,   967,   968,   605,   847,   969,   970,   971,   972,   973,
     974,   975,   976,   977,   978,   979,   980,   981,    21,   254,
     255,   848,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   309,   312,   314,   316,
     318,   320,   322,   324,   326,   328,   330,   332,   334,   982,
     353,   355,  1002,   370,   983,   984,   985,   986,  1011,  1907,
     987,   988,   989,   990,   991,   992,   993,   994,   995,   996,
     997,   998,   999,  1000,  1001,  1003,  1006,  1007,  1010,  1140,
    1013,  1015,  1016,  1017,  1012,   850,   852,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1293,  1030,  1031,
    1032,  1033,  1034,  1035,  1154,  1036,  1037,  1744,  1382,  1040,
    1041,  1042,  1038,  1039,  1043,  1044,  1045,  1046,  1047,  1048,
    1569,  1049,  1050,  1051,  1052,  1053,  1530,  1054,   961,  1535,
    1153,  1121,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,  1325,  1065,  1066,  1328,  1067,  1068,  1069,  1070,
    1071,  1072,  1073,  1074,  1383,  1075,  1577,  1076,  1077,  1580,
    1078,  1582,  1079,  1584,  1080,  1585,  1081,  1082,  1083,  1176,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1939,  1092,
    1093,  1094,   651,  1095,  1096,  1097,  1098,  1115,  1596,  1116,
    1598,  1599,  1600,  1117,  1118,  1119,  1120,  1605,  1606,  1607,
    1608,  1609,  1610,  1611,  1122,  1613,  1123,  1124,  1125,  1126,
    1152,  1159,  1160,  1161,  1162,  1626,  1627,  1628,  1629,  1630,
    1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,
    1157,  1163,  1164,  1165,  1166,  1644,  1645,  1646,  1647,  1648,
    1649,  1650,  1167,  1539,  1541,  1168,  1654,  1655,  1169,  1656,
    1170,  1171,  1172,  1173,  1181,  1393,  1182,  1175,  1179,  1177,
    1180,  1188,  1413,  1190,  1184,  1414,  1189,  1667,  1416,  1668,
    1191,  1192,   603,  1193,  1195,  1194,  1673,  1197,  1674,  1675,
    1196,  1198,  1199,  1200,  1201,  1202,  1681,  1683,  1685,  1686,
    1687,  1688,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,  1203,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,  1712,  1713,  2014,  1714,
    1715,  1716,  1717,  1718,  1719,  1212,  1721,  1722,  1723,  1724,
    1725,  1726,  1727,  1728,  1489,  1490,  1731,  1213,  1733,  1734,
    1214,  1736,  1737,  1738,  1215,  1740,  1741,  1216,  1217,   605,
    1218,  1746,  1219,  1748,  1749,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
     434,  1235,  1236,  1237,  1238,  1324,  1239,  1395,  1407,  1240,
    1241,  1243,  1244,  1245,  1255,  1524,  1100,  1246,  1247,  1248,
    1249,  1250,  1251,  1252,  1253,  1529,  1254,  1256,  1257,  1259,
    1260,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,  1570,  1571,
    1261,  1263,  1574,  1262,  1268,  1269,  1270,  1291,  1277,  1278,
    1408,  1583,  1279,  1280,  1281,  1282,  1292,  1294,  1290,  1295,
    1296,  1297,  1298,  1299,   880,   881,   882,   883,  1300,  1355,
    1301,  1302,  1303,  1304,  1415,  1305,  1306,   311,   313,   315,
     317,   319,   321,   323,   325,   327,   329,   331,   333,   335,
    1307,   354,   356,   371,  1308,  1309,  1310,   884,  1311,  1312,
    1313,  1314,  1315,  1316,  1319,   885,  1320,  1452,  1321,  1322,
     452,  1323,  1326,  1327,  1329,  1330,  1331,  1332,   886,  1333,
    1334,  1335,  1336,  1337,  1338,  1339,  1340,  1341,   453,  1342,
    1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1453,  1351,
    1352,  1657,  1353,  1354,  1357,  1359,  1358,  1360,  1362,  1363,
    1364,  1365,  1572,  1519,  1525,  1573,  1526,  1366,  1367,  1669,
     887,  1368,   888,   889,   890,  1575,  1576,  1578,  1581,  1579,
    1677,  1586,  1587,   891,   892,  1588,  1420,  1590,  1658,   893,
     894,   895,   896,  1589,  1592,  1593,  1594,  1643,  1696,  1660,
    1661,  1662,   897,   898,   899,   900,   901,  1705,   902,   903,
    1663,   904,  1664,  1676,  1711,  1751,   905,   906,   907,   908,
     909,   910,   911,   912,   913,   914,   915,   916,   917,   918,
     919,  1747,  1752,  1754,  1755,  1756,  1757,  1824,  1758,  1759,
     848,  1760,  1764,  1761,  1762,  1763,  1742,  1765,   603,  1745,
    1766,  2013,  1767,  1768,  1750,   311,   313,   315,   317,   319,
     321,   323,   325,   327,   329,   331,   333,   335,  1769,   354,
     356,  1770,   371,  1771,  1772,  1773,  1774,  1775,  2012,  1776,
    1777,  1825,  1778,  1781,  1782,   824,  1783,  1784,  1785,  1786,
    1787,  1791,  1795,  1788,  1792,  2266,  2030,   709,   710,   711,
     712,   713,   714,   715,   716,   717,  1793,   718,   719,   720,
     721,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   732,   733,   734,   735,   736,   737,   738,  1794,  1796,
    1743,  1797,  1798,  1799,  1800,  1802,   920,  1801,  1803,  1805,
    1806,  1807,  1808,   739,   740,  1809,  1916,  1810,  1811,  1812,
    1813,  1814,  1815,  1816,  1817,  1818,  1819,  2141,  1820,  1821,
    1822,  2232,  1823,  1826,  2223,  1827,  1828,  1829,  1830,  1938,
    1831,  1898,  1832,  2114,  2115,  2116,  2117,  1833,  2118,  1834,
    2119,  1835,  1836,  1837,  1838,  1839,  2122,  2123,  2124,  1840,
    1841,  2125,  2126,  2127,  2128,  1842,  2129,  1843,  2130,  1844,
    2131,  1845,  1860,  2132,  2133,  2134,  2135,  1846,  1847,  1848,
    2136,  1849,  1850,  2138,  1853,  1854,  1855,  1856,  2140,  1857,
    1858,  2142,  1859,  2143,  1861,  1862,  1863,  2147,  2148,  1864,
    2149,  2150,  2151,  2152,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  1865,  2161,  1866,  1867,  1868,  2103,  1869,  2268,
    1918,  1870,  2169,  2170,  2171,  2172,  2173,  2174,  2175,  2176,
    2177,  1871,  1872,  1873,  1874,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  2186,  2187,  2188,  2189,  1884,  1885,
    1886,  2192,  2193,  2194,  2195,  1887,  1888,  2104,  1889,  1890,
    1891,  2200,  2201,  2202,  2203,  2204,  2205,  2206,  2207,  2208,
    2209,  2210,  1894,  1895,  1896,  1897,  1903,  1904,  1905,  2211,
    2212,  2213,  1912,  2214,  2215,  1913,  2217,  2218,  1919,  1920,
    2220,  1921,  2221,  1922,  1923,  2269,  1924,  1925,  1926,  1927,
    2265,  1930,  2270,  1931,  1932,  2224,  1933,  1934,  1935,  1936,
    1937,  1941,  1948,  1952,  2230,  2231,  1949,  1953,  1954,  2233,
    1955,  1956,  1957,  2237,  1958,  1959,  1960,  2271,  2272,  1961,
    1962,  1963,  1964,  2072,  1965,  1966,  1967,  2316,  1968,  2243,
    1969,  2244,  1970,  1971,  1972,  1973,  1974,  1975,  1976,  1977,
    1978,  1979,  2317,  1980,  1981,  2245,  1982,  1983,  1984,  2108,
    1985,  1986,  2798,  1987,  1988,  1989,  1990,  1991,  1992,  1994,
    2247,  1993,  2248,  1995,  2929,  1997,  2267,  2249,  1998,  2001,
    2477,  2002,  2003,  2250,  3100,  2004,  2005,  2252,  2253,  2006,
    2254,  2256,  2257,  1591,  2258,  2259,  2007,  2008,  2262,  2263,
    2009,  2264,  2010,   360,  2011,  2020,  2021,  2022,  1672,  2023,
    2273,  2274,   361,  2024,  2276,  2025,  2277,  2029,  2278,  2279,
     362,  2032,  2035,  2036,  2280,  2037,  2039,  2281,  2041,  2282,
     821,  2044,  2047,  2283,  2284,  2065,  2285,  2050,  2051,  2286,
    2287,  2288,  2289,  2290,  2291,  2052,  2292,  2293,  2294,  2053,
    2295,  2296,  2297,  2298,  2299,  2054,  2057,  2300,  2301,  2302,
    2303,  2058,  2306,  2061,  2062,  2063,  2064,  2068,  2307,  2069,
    2070,  2308,  2071,  2309,  2073,  2310,  2311,  2312,  2074,  2075,
    2076,  2079,  2080,  1560,  2081,  2084,  2313,  2314,  2085,  2086,
    2315,  2087,  2088,  2089,  2090,  2091,  2092,  2093,  2094,  2095,
     363,  2096,  2097,  2098,  2099,   364,  2100,  2101,  2102,  2105,
    2107,  2725,  2109,  2110,  2111,  1563,  2112,  2227,  2228,  2229,
    2611,  2238,  2239,  2251,  2319,  2197,  2318,  2320,  2321,  2323,
    2345,  2322,  2324,  2325,  2326,  2327,  2328,  2726,  2329,  2330,
    2331,   825,  2332,  2333,  2334,  2335,  2336,  1561,  2337,  2338,
    2339,  2340,  2341,  2342,  2343,  1564,  2344,  2346,  2225,  2347,
    2348,  2349,   794,  2352,  2353,  2354,  1562,  2355,  2356,  2357,
    1538,  2358,  2359,     0,  2360,  2361,  2362,  2363,  2364,  2365,
     823,  2366,  2367,  2368,   822,  2369,  2370,  2371,  2372,  2234,
    2235,  2236,  2373,  2374,  2375,  2376,  2377,  2378,  2379,  2380,
    2381,  2382,  2383,  1406,  2384,  2385,  2386,  2387,  2388,  2389,
    2390,  2391,     0,  2392,  2393,  2536,  2394,  2395,  2537,  2396,
    2397,  2398,  2399,  2400,  2401,  1915,  2402,  2403,  2468,  2404,
    2408,  2441,  2405,  2406,  2407,  2409,  2410,  2411,  2412,  2413,
    2414,     0,  2417,  2418,  2419,  2420,  2421,     0,  2422,  2423,
    2424,     0,  2425,  2426,  2427,  2467,  2428,  2429,  2945,  2430,
    2431,  2432,   826,  2433,  2434,  2435,  2436,  2437,     0,  2438,
       0,  2439,  2440,  2442,     0,  2443,  2444,  2445,     0,  2446,
    2447,  2448,     0,  2449,  2450,  2457,     0,  2458,  2459,  2460,
    2461,  2462,  2463,  2464,  2465,  2466,  2469,     0,  2470,  2471,
    2472,  2473,     0,  2478,  2479,  2480,  2481,  2482,  2518,  2483,
    2519,  2484,  2520,  2485,  2521,  2486,  2487,  2488,  2489,  2522,
    2523,  2490,  2524,  2525,  2526,  2527,  2493,  2528,  2529,  2530,
    2531,  2494,  2495,  2496,  2532,  2497,  2507,  2533,  2535,  2498,
    2501,  2502,  2503,  2541,  2504,     0,  2505,  2506,  2542,  2508,
    2543,  2544,  2545,  2546,  2547,  2548,  2549,  2550,  2509,  2551,
    2553,  2555,  2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,
    2564,  2565,  2566,  2510,  2567,  2511,  2512,     0,  3056,  2513,
    2514,  2515,  2573,  2516,  2517,  2594,  2574,  2575,  2647,     0,
    2650,  2651,     0,  2652,  2653,  2654,  2578,  2579,  2655,  2656,
    2657,     0,  2658,  2659,  2660,  2661,  2580,  2581,  2582,  2583,
    2584,  2662,  2585,  2586,  2663,  2587,  2588,  2665,  2666,  2667,
    2589,  2590,  2670,  2591,  2592,  2671,  2672,  2681,  2682,  2683,
    2684,  2685,  2702,  2595,  2690,  2691,  2692,  2597,  2693,  2598,
    2599,  2696,  2697,  2698,  2699,  2700,  2701,  2703,  2704,  2604,
    2605,  2606,  2705,  2706,  2609,  2610,  2707,  2708,  2709,  2710,
    2612,  2711,  2614,  2712,  2615,  2713,  2616,  2617,  2618,  2619,
    2620,  2621,  2622,  2623,  2624,  2714,  2625,  2626,  2627,  2628,
    2715,  2716,     0,  2717,  2718,  2719,  2720,  2721,  2722,  2723,
    2631,  2632,  2633,  2634,  2724,  2727,  2637,  2728,  2638,  2639,
    2640,  2641,  2642,  2643,  2644,  2645,  2646,  2729,  2730,  2731,
       0,  2732,  2733,     0,  2734,  2735,  2738,     0,  2739,  2740,
    2741,     0,  2742,  2745,  2746,  2747,     0,  2749,  2750,  2751,
    2752,  2753,  2795,  2754,  2755,  2756,  2797,  2757,  2758,  2759,
    2760,     0,  2761,  2762,  2763,  2764,  2765,  2766,  2767,  2768,
       0,  2769,  2770,     0,  2771,  2772,  2773,  2774,  2775,  2776,
    2777,  2778,  2779,  2780,  2781,  2782,  2783,     0,  2867,  2868,
    2869,     0,  2870,  2748,  2871,  2872,  2873,  2874,  2875,     0,
    2876,  2879,  2880,  2881,     0,  2884,  2885,  2890,  2891,  2892,
    2893,  2894,  2895,     0,  2896,  2897,  2898,  2899,  2900,  2901,
    2903,  2905,  2906,     0,  2907,  2908,  2909,  2910,  2911,  2912,
    2913,  2914,  2915,  2918,  2919,  2922,  2923,  2924,     0,  2925,
    2926,  2927,  2928,     0,  2930,  2931,  2932,     0,  2935,  2936,
    2937,     0,  2938,  2939,  2940,     0,  2941,  2942,  2943,  2784,
    2785,  2944,  2786,  2787,  2946,  2788,  2789,  2947,  2790,  2791,
    2792,  2948,  2793,  2794,  2949,  2950,  2796,  2951,  2952,  2953,
    2954,  2799,  2800,  2955,  2801,  3014,  2802,  3015,  2803,  3016,
    2804,  2805,  2806,  2807,  2808,  3017,  3018,  3019,  2809,  2810,
    2811,  2812,  2813,  2814,  3020,  2815,  2817,  2819,  2821,  2822,
    2823,  2824,  3021,  2825,  2826,  2827,  2828,  2829,  2593,  2831,
    3022,  3023,     0,  3024,  2832,  2833,  3025,  2834,  2835,  2836,
    2837,  2838,  2839,  3026,  2840,  2841,  2842,  3027,  3028,  3029,
    2844,  3030,  2845,  3031,  2846,  3034,  3036,  2847,  3035,  2848,
    2849,  3037,  2850,  3038,  3039,  3040,  3041,  3042,  3044,  2853,
    3043,  2855,  3045,  3046,  2856,  2857,  3047,     0,  3048,  3049,
    2964,  2858,  2859,  2860,  2861,  2862,  3050,     0,  3051,  3052,
    3054,  2864,  2865,  2866,  3053,  3055,  3057,  3058,     0,  3059,
    3060,  3061,  3062,  3063,  3064,  3065,     0,  3066,  3067,  3068,
    3071,  3072,  3073,  3108,  3109,     0,  3110,  3111,     0,  3113,
    3114,  3115,  3116,  3117,  3118,     0,  3119,  3120,     0,  3121,
    3122,  3123,     0,  3124,  3125,  3126,     0,  3129,  3132,  3133,
    3134,  3136,  3137,  3138,  3139,  3140,     0,  3143,  3165,  3166,
    3167,  3168,  3169,  3170,     0,  3171,  3172,  3173,  3174,  3175,
    3176,     0,  3177,  3178,  3179,  3180,     0,  3181,  3182,  3183,
       0,  3199,  3200,  3201,     0,  3202,  3203,     0,  3204,  3205,
    3206,     0,  3207,  3208,     0,  3209,  3217,  2956,  3218,  3222,
    2957,  2958,  2959,  3219,  3220,  3221,  2960,  3223,  2961,  2962,
    3228,  3229,  3230,  3231,  2965,  2966,  3235,  2967,  3236,  2968,
    2969,  2970,  2971,  2972,  2973,  3237,  2974,  2975,  2976,  2977,
    2978,  2979,  2819,  3241,  2819,  3242,  3243,  2819,  2819,  2984,
    2985,  2986,  3246,  3247,  3249,     0,     0,  2991,  2992,     0,
       0,  2993,     0,     0,     0,  2994,  2995,  2996,     0,     0,
    2997,     0,     0,     0,  2998,  2999,     0,     0,  3000,  3001,
       0,     0,  3003,     0,  3005,  3006,     0,     0,  3007,  3008,
       0,  3009,     0,  3011,  3012,  3013,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2843,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3074,  3075,  3076,  3077,     0,
    3079,  3080,     0,     0,  3081,     0,     0,     0,     0,     0,
       0,  3082,     0,  3083,     0,  3084,     0,     0,  3085,     0,
       0,     0,     0,  2819,     0,     0,     0,     0,  3087,  3088,
       0,  3089,     0,  3090,     0,  3091,  3092,  3093,     0,  3094,
    3095,     0,  3097,     0,  3099,     0,  3101,  3102,  3103,     0,
       0,  3105,  3106,  3107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3144,     0,     0,     0,  3146,  3147,     0,     0,     0,  3148,
       0,  3149,  3150,     0,  3151,  3152,     0,     0,     0,  3154,
       0,     0,  3156,  3157,  3158,     0,  3159,  3160,  3161,  3162,
       0,     0,  3163,  3164,     0,     0,     0,     0,     0,  2963,
       0,     0,     0,     0,     0,     0,     0,     0,   160,     0,
       0,     0,     0,     0,     0,  3188,     0,   185,     0,     0,
     189,  3189,  3190,  3191,   227,     0,     0,  3192,  3193,     0,
       0,  3195,  3196,     0,     0,  3197,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,     0,     0,  3210,
    3211,     0,  3212,     0,  3213,     0,     0,  3215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3224,     0,  3225,
    3226,  3227,     0,     0,     0,     0,     0,     0,  3232,  3233,
    3234,     0,     0,     0,     0,  3238,  3239,  3240,     0,     0,
       0,     0,  3244,  3245,     0,     0,  3248,     0,     0,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   310,   310,   310,     0,     0,   160,  3078,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,    15,     0,     0,     0,     0,     0,     0,
      18,     0,    19,     0,    21,   190,   191,   192,   193,   194,
      27,     0,   195,   196,     0,     0,     0,     0,   197,     0,
     182,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,     0,   310,   310,
       0,   310,  3145,   227,     0,     0,     0,    44,    45,    46,
      47,    48,     0,     0,     0,   227,     0,     0,     0,     0,
       0,     0,     0,     0,   606,   606,     0,   198,     0,     0,
       0,     0,     0,     0,     0,    52,     0,   199,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   681,   684,   681,   681,   687,   681,   689,   681,
     691,     0,     0,     0,     0,   745,   746,   747,   681,   750,
     751,   752,   753,   754,   755,   756,   757,     0,     0,     0,
     761,   763,     0,     0,     0,   681,   786,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
      58,     0,    59,   227,     0,   800,   801,   802,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   227,   227,   227,     0,     0,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
       0,     0,     0,     0,     0,     0,   681,   606,     0,     0,
       0,     0,     0,   310,   310,   310,     0,     0,   681,   606,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1099,  1099,  1099,  1099,  1099,  1099,  1099,  1099,  1099,  1099,
    1099,  1099,  1099,   681,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   606,  1131,  1099,  1099,
       0,   124,  1099,     0,     0,     0,     0,     0,     0,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   681,   681,   681,   681,   681,   681,   681,   681,
     681,   681,   681,   681,   681,  1186,   681,   681,   681,     0,
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
       0,     0,   310,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,     0,     0,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1099,  1099,  1099,  1099,  1099,  1099,  1099,  1099,
    1099,  1099,  1099,  1099,  1099,   606,  1099,  1099,     0,  1099,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1371,     0,     0,     0,     0,     0,  1377,     0,     0,
    1381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     681,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,     0,     0,   227,     0,     0,  1418,     0,     0,
       0,   606,  1424,  1426,   681,   681,  1429,  1430,  1431,  1432,
    1433,   681,  1435,  1436,  1437,  1438,  1439,     0,  1442,  1443,
    1444,  1445,     0,   681,   681,  1451,     0,     0,  1454,  1455,
    1456,  1457,  1458,  1459,  1460,  1461,  1462,   681,  1464,  1465,
    1466,  1467,  1468,  1469,  1470,  1471,  1472,  1473,  1474,  1475,
    1476,   681,   681,   681,   681,   681,  1482,  1483,  1484,  1485,
    1486,     0,     0,   227,   227,  1491,  1492,  1493,  1494,  1495,
    1496,  1497,  1498,  1499,  1500,  1501,  1502,  1503,   681,  1505,
    1506,  1507,  1508,  1509,  1510,   681,   681,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   681,   681,   681,  1516,   681,   681,     0,
     681,   681,   681,   681,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   606,     0,   606,  1536,   681,  1099,
    1099,   681,  1099,  1099,  1099,  1099,  1099,  1099,  1099,  1099,
     681,   681,   681,   681,   681,     0,     0,   227,   227,     0,
       0,   227,     0,     0,     0,     0,     0,     0,     0,     0,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     681,     0,     0,     0,     0,   681,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1595,     0,  1597,     0,     0,
       0,  1601,  1602,  1603,  1604,     0,     0,     0,     0,     0,
       0,     0,  1612,     0,  1614,  1615,  1616,  1618,  1619,  1621,
    1623,  1624,  1625,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1641,     0,
     681,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1651,  1652,  1653,     0,     0,     0,     0,     0,     0,     0,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,  1670,
    1671,     0,     0,     0,     0,     0,     0,     0,     0,   227,
    1678,     0,  1679,  1680,  1682,  1684,     0,     0,     0,     0,
    1689,     0,     0,     0,   681,   681,   681,   227,   681,  1698,
       0,  1700,     0,     0,   681,     0,   227,   681,   681,   681,
     681,   681,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   681,     0,     0,     0,     0,     0,     0,
       0,     0,  1729,   681,     0,   681,     0,     0,  1735,     0,
       0,     0,   681,     0,     0,   227,     0,   606,   227,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1099,     0,     0,  1910,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   681,     0,     0,   681,     0,
    1943,  1944,  1945,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   681,    15,     0,     0,     0,     0,     0,     0,    18,
       0,    19,     0,    21,   190,   191,   192,   193,  1533,    27,
       0,   205,   196,     0,     0,     0,     0,   197,     0,   182,
     183,     0,     0,     0,   606,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    45,    46,    47,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   198,     0,     0,     0,
    2113,     0,     0,     0,    52,     0,   199,     0,     0,     0,
       0,     0,  2120,  2121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2137,     0,   681,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   681,  2146,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2162,  2163,   681,   681,  2166,  2167,  2168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,    59,  2178,     0,  2179,  2180,  2181,  2182,  2183,     0,
    2184,  2185,     0,     0,     0,     0,   681,   681,     0,     0,
       0,     0,     0,  2196,   227,     0,     0,  2198,  2199,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2216,     0,     0,  2219,     0,     0,     0,
       0,   681,     0,     0,   606,     0,     0,     0,     0,    71,
      72,     0,     0,     0,     0,   681,  2226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   227,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     681,     0,     0,     0,     0,  2242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   606,     0,
       0,     0,     0,     0,  2260,  2261,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,    86,     0,
       0,  2275,     0,     0,     0,     0,     0,     0,    89,    90,
     206,   207,   208,   209,   210,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   606,   681,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,     0,     0,     0,     0,     0,  1534,     0,   220,   221,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,     0,     0,    18,
       0,    19,     0,    21,   190,   191,   192,   193,   194,    27,
       0,   205,   196,     0,     0,     0,     0,   197,     0,   182,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    45,    46,    47,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   198,     0,     0,     0,
       0,     0,     0,     0,    52,     0,   199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,    59,     0,     0,     0,  2534,     0,     0,     0,  2538,
    2540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2552,  2554,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2568,  2569,  2570,  2571,  2572,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     681,     0,     0,   681,     0,     0,     0,     0,     0,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,     0,     0,
       0,     0,     0,     0,  2596,     0,     0,     0,     0,     0,
     681,     0,   681,     0,   681,     0,   681,     0,     0,     0,
    2607,  2608,     0,     0,     0,     0,     0,     0,     0,  2613,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
    2629,     0,     0,     0,     0,     0,   681,     0,     0,     0,
       0,     0,   681,   681,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
     206,   207,   208,   209,   210,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,     0,     0,     0,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,   144,   144,
     219,     0,     0,   144,     0,     0,     0,     0,   220,   221,
     127,   128,   129,     0,     6,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,     0,    18,     0,    19,     0,    21,   190,   191,
     192,   193,  1533,    27,     0,   205,   196,     0,     0,     0,
       0,   197,     0,   182,   183,     0,     0,     0,     0,     0,
       0,     0,     0,  2538,     0,     0,     0,  2538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1536,  1536,  1536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2830,     0,     0,     0,
      44,    45,    46,    47,    48,   144,     0,     0,     0,   604,
     604,     0,     0,     0,     0,     0,     0,   227,     0,     0,
     198,     0,     0,     0,     0,     0,     0,     0,    52,     0,
     199,     0,   681,  2852,     0,     0,     0,   680,  2854,   680,
     680,     0,   680,     0,   680,     0,     0,     0,     0,     0,
       0,     0,   680,   680,     0,     0,     0,   681,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   782,     0,
     680,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   680,   604,     0,     0,     0,     0,   782,   144,   144,
     144,     0,     0,   680,   951,     0,     0,     0,   227,     0,
       0,  2538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    72,     0,     0,     0,     0,     0,
    1536,     0,  1536,     0,     0,  1536,  1536,     0,     0,     0,
    2987,  2988,  2989,  2990,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3002,
       0,  3004,     0,     0,     0,     0,     0,     0,     0,     0,
     681,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,   206,   207,   208,   209,   210,   211,
       0,     0,   212,   213,   214,   215,   216,   217,   218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1536,   109,     0,     0,   604,   604,   604,   604,   604,
     604,   604,   604,   604,   604,   604,   604,   604,   680,  3096,
       0,  3098,     0,     0,     0,     0,     0,     0,   681,     0,
       0,   604,     0,   604,   604,     0,     0,   604,     0,     0,
       0,     0,     0,     0,   219,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   127,   128,   129,     0,   681,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   681,     0,     0,   681,
       0,     0,     0,     0,     0,     0,     0,   680,   680,   680,
     680,   680,   680,   680,   680,   680,   680,   680,   680,   680,
     680,   680,   680,   680,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3194,     0,     0,
       0,     0,     0,     0,     0,   681,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3214,     0,     0,     0,   681,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   782,
     782,   782,   782,   782,   782,   782,   782,   782,   782,   782,
     782,   782,   782,   782,   782,   782,     0,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,    21,   190,   191,   192,
       0,   194,    27,     0,   205,   196,     0,     0,     0,     0,
     197,     0,   182,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   951,   951,   951,
     951,   951,   951,   951,   951,   951,   951,   951,   951,   951,
     951,   951,   951,     0,   951,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   680,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   604,   680,     0,   680,
     680,     0,     0,     0,     0,     0,   680,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   680,   680,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   680,   179,     0,     0,     0,     0,     0,     0,
       0,     0,   186,     0,     0,     0,   680,   680,   680,   680,
     680,     0,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   680,     0,     0,     0,     0,     0,     0,
     680,   680,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   680,   680,
     680,     0,   680,   680,     0,   680,   680,   680,   680,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   604,
       0,   604,     0,   680,   604,   604,   680,   604,   604,   604,
     604,   604,   604,   604,   604,   680,   680,   680,   680,   680,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,    86,     0,   179,     0,   680,     0,     0,     0,     0,
     680,    89,    90,   206,   207,   208,   209,   210,   211,     0,
       0,   212,   213,   214,   215,   216,   217,   218,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   680,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   454,   455,     0,     0,     0,     0,     0,   626,
     626,     0,     0,     0,     0,     0,     0,     0,     0,   680,
     680,   680,     0,   680,     0,     0,     0,     0,     0,   680,
       0,     0,   680,   680,   680,   680,   680,   683,     0,   683,
     683,     0,   683,     0,   683,     0,     0,     0,   680,     0,
       0,     0,   683,   683,     0,     0,     0,     0,   680,     0,
     680,     0,     0,     0,     0,     0,     0,   680,     0,     0,
     683,     0,   604,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,    21,   190,   191,
     192,     0,   194,    27,     0,   195,   196,     0,     0,     0,
       0,   197,     0,   182,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   683,   626,     0,     0,     0,     0,     0,     0,     0,
       0,   878,     0,   683,   956,     0,   625,   625,     0,     0,
      44,    45,    46,    47,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,     0,     0,     0,   682,     0,   685,   686,     0,   688,
     199,   690,     0,     0,     0,     0,     0,     0,     0,   748,
     749,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   785,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   604,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     680,     0,     0,   680,     0,     0,     0,     0,   827,   830,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     922,   953,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   683,     0,
       0,     0,     0,    71,    72,     0,   680,     0,     0,     0,
       0,   626,  1132,   626,   626,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   604,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,     0,     0,   683,   683,   683,
     683,   683,   683,   683,   683,   683,   683,   683,   683,   683,
     683,   683,   683,   683,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,     0,     0,   680,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   680,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   680,
     680,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   680,   680,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   680,     0,     0,   604,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     680,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   680,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   604,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   683,     0,     0,     0,     0,
       0,     0,   878,     0,     0,     0,     0,     0,  1404,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   626,   683,     0,   683,
     683,     0,     0,   604,   680,     0,   683,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   683,   683,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   683,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   683,   683,   683,   683,
     683,     0,     0,     0,     0,     0,  1487,  1488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   683,     0,     0,     0,     0,     0,     0,
     683,   683,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   683,   683,
     683,     0,   683,   683,     0,   683,   683,   683,   683,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   626,
       0,   626,  1391,   683,   626,   626,   683,   626,   626,   626,
     626,   626,   626,   626,   626,   683,   683,   683,   683,   683,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   625,  1425,     0,  1427,  1428,     0,     0,
       0,     0,     0,  1434,     0,   683,     0,     0,     0,     0,
     683,     0,     0,     0,     0,  1449,  1450,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1463,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1477,  1478,  1479,  1480,  1481,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   683,     0,     0,     0,     0,
    1504,     0,     0,     0,     0,     0,     0,  1511,  1512,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1513,  1514,  1515,     0,  1517,
    1518,     0,  1520,  1521,  1522,  1523,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1531,     0,  1532,     0,
       0,     0,     0,     0,     0,     0,  1690,  1691,  1692,   683,
     683,   683,     0,   683,     0,  1699,     0,  1701,  1702,   683,
       0,     0,   683,   683,   683,   683,   683,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   683,     0,
       0,     0,  1425,     0,     0,     0,     0,  1532,   683,     0,
     683,     0,     0,     0,     0,   680,     0,   683,   680,     0,
       0,     0,   626,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1642,     0,     0,   680,     0,   680,     0,   680,
       0,   680,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   680,     0,     0,     0,     0,     0,   680,   680,     0,
       0,     0,     0,     0,     0,     0,  1693,  1694,  1695,     0,
    1697,     0,     0,     0,     0,     0,  1703,     0,     0,  1706,
    1707,  1708,  1709,  1710,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1720,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1730,     0,  1732,     0,     0,
       0,     0,     0,     0,  1739,     0,     0,     0,     0,   625,
       0,     0,     0,     0,     0,     0,     0,     0,   626,     0,
       0,  1911,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   878,
     683,     0,     0,   683,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   683,     0,     0,    19,
       0,    21,   190,   191,   192,     0,   194,    27,     0,   205,
     196,     0,     0,     0,     0,   197,     0,   182,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   680,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   680,     0,    44,    45,    46,    47,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,     0,     0,  1940,     0,     0,
       0,     0,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   683,     0,     0,
       0,     0,     0,  1996,    57,     0,     0,     0,   683,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   683,
     683,     0,     0,     0,     0,     0,  2031,    58,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   683,   683,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   680,   683,    71,    72,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     683,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   683,     0,     0,     0,     0,
       0,     0,     0,     0,  2139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2164,  2165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   626,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,    86,     0,  2190,  2191,
       0,     0,     0,   680,     0,     0,    89,    90,   206,   207,
     208,   209,   210,   211,     0,     0,   212,   213,   214,   215,
     216,   217,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   680,     0,     0,   109,     0,     0,     0,
       0,     0,     0,  2222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   626,   683,     0,     0,     0,     0,     0,
       0,   680,     0,     0,   680,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1283,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   127,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     680,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2255,   358,   680,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,     0,    32,    33,    34,    35,    36,
      37,     0,    38,    39,    40,    41,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2304,  2305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    45,    46,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,    51,    52,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
      59,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,     0,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   683,     0,     0,   683,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,    72,
       0,     0,     0,     0,     0,   683,     0,   683,     0,   683,
       0,   683,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,     0,     0,     0,
       0,   683,     0,     0,     0,     0,     0,   683,   683,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,    86,    87,     0,
       0,    88,  2576,     0,     0,  2577,     0,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,   104,     0,     0,     0,   105,
       0,   106,   107,     0,     0,     0,   108,   109,     0,   110,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,  2600,     0,  2601,     0,  2602,     0,  2603,     0,
       0,     0,   112,     0,     0,     0,     0,   113,   114,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,  2630,     0,
       0,     0,     0,     0,  2635,  2636,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,     0,    32,    33,    34,    35,    36,
      37,     0,    38,    39,    40,    41,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   683,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   683,     0,     0,    44,    45,    46,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,    51,    52,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
      59,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,     0,    66,  2851,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2863,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   683,     0,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,    86,    87,     0,
       0,    88,     0,   683,     0,     0,     0,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,   104,     0,     0,     0,   105,
       0,   106,   107,   683,     0,     0,   108,   109,     0,   110,
       0,     0,  3010,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   683,   112,     0,   683,     0,     0,   113,   114,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     683,     0,     0,     0,     0,     0,     6,     0,     0,   923,
     484,   924,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,   683,     0,     0,    18,     0,    19,     0,    21,
     190,   191,   192,   193,   828,    27,   925,   195,   196,   926,
    3104,   487,     0,   197,   927,   182,   183,     0,     0,     0,
       0,     0,     0,     0,     0,   928,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3153,     0,
       0,  3155,    44,   488,    46,    47,    48,   489,   490,   491,
     492,   493,   494,   495,   496,     0,   497,     0,   498,   499,
     500,   501,   502,   503,   504,     0,   505,   506,     0,     0,
      52,     0,   507,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3198,     0,     0,
       0,     0,     0,     0,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,     0,     0,  3216,
       0,   521,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,    58,   535,    59,   536,   537,
     538,   539,   540,     0,     0,     0,     0,     0,     0,   541,
       0,     0,     0,   857,   858,   859,     0,     0,   542,   543,
     544,   545,   860,   861,   862,   863,   546,   864,   547,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   548,   549,   550,   551,     0,
       0,     0,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,     0,    71,    72,   865,     0,     0,
     866,   867,   868,   869,     0,   870,   871,   564,   565,   929,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   930,    74,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   566,
     567,   568,   569,    76,   931,    78,    79,   932,    81,    82,
      83,    84,    85,     0,    86,     0,   570,   571,     0,   933,
       0,     0,     0,     0,    89,    90,   934,   935,   936,   937,
     938,   939,     0,     0,   940,   941,   942,   943,   944,   945,
     946,   585,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   586,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,     0,   591,
     592,     0,   873,   874,   875,   593,   594,     0,   876,     0,
     877,   595,   596,   597,     0,     0,     0,     0,     0,     0,
       6,     0,     0,   483,   484,     0,   947,     0,     0,     0,
       0,     0,    15,     0,   948,   949,   127,   128,   129,    18,
       0,    19,     0,    21,   190,   191,   192,   193,   828,    27,
     486,   195,   196,     0,     0,   487,     0,   197,     0,   182,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,   488,    46,    47,
      48,   489,   490,   491,   492,   493,   494,   495,   496,     0,
     497,     0,   498,   499,   500,   501,   502,   503,   504,     0,
     505,   506,     0,     0,    52,     0,   507,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,     0,     0,     0,     0,   521,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,    58,
     535,    59,   536,   537,   538,   539,   540,     0,     0,     0,
       0,     0,     0,   541,     0,     0,     0,     0,     0,     0,
       0,     0,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,   547,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   548,
     549,   550,   551,     0,     0,     0,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,     0,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   564,   565,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   566,   567,   568,   569,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,    86,     0,
     570,   571,     0,     0,     0,     0,     0,     0,    89,    90,
     934,   935,   936,   937,   938,   939,     0,     0,   940,   941,
     942,   943,   944,   945,   946,   585,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   586,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,   591,   592,     0,     0,     0,     0,   593,
     594,     0,     0,     0,     0,   595,   596,   597,     0,     0,
       0,     0,     0,     0,     6,     0,     0,   483,   484,     0,
     947,     0,     0,     0,     0,     0,    15,     0,   948,   949,
     127,   128,   129,    18,     0,    19,     0,    21,   190,   191,
     192,   193,   485,    27,   486,   205,   196,     0,     0,   487,
       0,   197,     0,   182,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,   488,    46,    47,    48,   489,   490,   491,   492,   493,
     494,   495,   496,     0,   497,     0,   498,   499,   500,   501,
     502,   503,   504,     0,   505,   506,     0,     0,    52,     0,
     507,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,     0,     0,     0,     0,   521,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,    58,   535,    59,   536,   537,   538,   539,
     540,     0,     0,     0,     0,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   547,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   548,   549,   550,   551,     0,     0,     0,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,     0,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   564,   565,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   566,   567,   568,
     569,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,    86,     0,   570,   571,     0,     0,     0,     0,
       0,     0,    89,    90,   572,   573,   574,   575,   576,   577,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   586,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,   591,   592,     0,
       0,     0,     0,   593,   594,     0,     0,     0,     0,   595,
     596,   597,     0,     0,     0,     0,     0,     0,     6,     0,
       0,   483,   484,     0,   598,     0,     0,     0,     0,     0,
      15,   599,   600,   601,   127,   128,   129,    18,     0,    19,
       0,    21,   190,   191,   192,   193,  1527,    27,   486,   205,
     196,     0,     0,   487,     0,   197,     0,   182,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,   488,    46,    47,    48,   489,
     490,   491,   492,   493,   494,   495,   496,     0,   497,     0,
     498,   499,   500,   501,   502,   503,   504,     0,   505,   506,
       0,     0,    52,     0,   507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,     0,
       0,     0,     0,   521,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,    58,   535,    59,
     536,   537,   538,   539,   540,     0,     0,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     547,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   548,   549,   550,
     551,     0,     0,     0,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,     0,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   564,
     565,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   566,   567,   568,   569,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,    86,     0,   570,   571,
       0,     0,     0,     0,     0,     0,    89,    90,   572,   573,
     574,   575,   576,   577,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   586,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
       0,   591,   592,     0,     0,     0,     0,   593,   594,     0,
       0,     0,     0,   595,   596,   597,     0,     0,     0,     0,
       0,     0,     6,     0,     0,   483,   484,     0,   598,     0,
       0,     0,     0,     0,    15,  1528,   600,   601,   127,   128,
     129,    18,     0,    19,     0,    21,   190,   191,   192,   193,
     828,    27,   486,   205,   196,     0,     0,   487,     0,   197,
       0,   182,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,   488,
      46,    47,    48,   489,   490,   491,   492,   493,   494,   495,
     496,     0,   497,     0,   498,   499,   500,   501,   502,   503,
     504,     0,   505,   506,     0,     0,    52,     0,   507,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,     0,     0,     0,     0,   521,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,    58,   535,    59,   536,   537,   538,   539,   540,     0,
       0,     0,     0,     0,     0,   541,     0,     0,     0,     0,
       0,     0,     0,     0,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,   547,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   548,   549,   550,   551,     0,     0,     0,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
       0,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   564,   565,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   566,   567,   568,   569,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
      86,     0,   570,   571,     0,     0,     0,     0,     0,     0,
      89,    90,   572,   573,   574,   575,   576,   577,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   586,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,     0,   591,   592,     0,     0,     0,
       0,   593,   594,     0,     0,     0,     0,   595,   596,   597,
       0,     0,     0,     0,     6,     0,     0,   483,   484,     0,
       0,     0,   598,     0,     0,     0,     0,     0,     0,     0,
     600,   601,   127,   128,   129,    19,     0,    21,   190,   191,
     192,     0,   828,    27,   486,   195,   196,     0,     0,   487,
       0,   197,     0,   182,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,   488,    46,    47,    48,   489,   490,   491,   492,   493,
     494,   495,   496,     0,   497,     0,   498,   499,   500,   501,
     502,   503,   504,     0,   505,   506,     0,     0,     0,     0,
     507,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,     0,     0,     0,     0,   521,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,    58,   535,    59,   536,   537,   538,   539,
     540,     0,     0,     0,     0,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   547,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   548,   549,   550,   551,     0,     0,     0,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,     0,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   564,   565,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   566,   567,   568,
     569,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,    86,     0,   570,   571,     0,     0,     0,     0,
       0,     0,    89,    90,   934,   935,   936,   937,   938,   939,
       0,     0,   940,   941,   942,   943,   944,   945,   946,   585,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   586,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,   591,   592,     0,
       0,     0,     0,   593,   594,     0,     0,     0,     0,   595,
     596,   597,     0,     0,     0,     0,     6,     0,     0,   483,
     484,     0,     0,     0,   947,     0,     0,     0,     0,     0,
       0,     0,   948,   949,   127,   128,   129,    19,     0,    21,
     190,   191,   192,     0,   828,    27,   486,   205,   196,     0,
       0,   487,     0,   197,     0,   182,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,   488,    46,    47,    48,   489,   490,   491,
     492,   493,   494,   495,   496,     0,   497,     0,   498,   499,
     500,   501,   502,   503,   504,     0,   505,   506,     0,     0,
       0,     0,   507,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,     0,     0,     0,
       0,   521,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,    58,   535,    59,   536,   537,
     538,   539,   540,     0,     0,     0,     0,     0,     0,   541,
       0,     0,     0,     0,     0,     0,     0,     0,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,   547,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   548,   549,   550,   551,     0,
       0,     0,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,     0,    71,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   564,   565,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   566,
     567,   568,   569,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,    86,     0,   570,   571,     0,     0,
       0,     0,     0,     0,    89,    90,   572,   573,   574,   575,
     576,   577,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   586,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,     0,   591,
     592,     0,     0,     0,     0,   593,   594,     0,     0,     0,
       0,   595,   596,   597,     0,     0,     0,     0,     6,     0,
       0,   483,   484,     0,     0,     0,   598,     0,     0,     0,
       0,     0,     0,     0,   600,   601,   127,   128,   129,    19,
       0,    21,   190,   191,   192,     0,   828,    27,   486,   205,
     196,     0,     0,   487,     0,   197,     0,   182,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,   488,    46,    47,    48,   489,
     490,   491,   492,   493,   494,   495,   496,     0,   497,     0,
     498,   499,   500,   501,   502,   503,   504,     0,   505,   506,
       0,     0,     0,     0,   507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,     0,
       0,     0,     0,   521,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,    58,   535,    59,
     536,   537,   538,   539,   540,     0,     0,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     547,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   548,   549,   550,
     551,     0,     0,     0,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,     0,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   564,
     565,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   566,   567,   568,   569,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,    86,     0,   570,   571,
       0,     0,     0,     0,     0,     0,    89,    90,   572,   573,
     574,   575,   576,   577,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   483,   484,   109,   586,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
       0,   591,   592,     0,    21,     0,     0,   593,   594,   660,
      27,   486,     0,   595,   596,   597,   487,     0,     0,     0,
     182,   183,     0,     0,     0,     0,     0,     0,  1906,     0,
       0,     0,     0,     0,     0,     0,   600,   601,   127,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   661,     0,
       0,     0,   489,   490,   491,   492,   493,   494,   495,   496,
       0,   497,     0,   498,   499,   500,   501,   662,   503,   504,
       0,   505,   506,     0,     0,     0,     0,   663,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,     0,     0,     0,     0,   521,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
       0,   535,     0,   536,   537,   538,   539,   540,     0,     0,
       0,     0,     0,     0,   541,     0,     0,     0,     0,     0,
       0,     0,     0,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,   547,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     548,   549,   550,   551,     0,     0,     0,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   564,   565,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   566,   567,   568,   569,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,   570,   571,     0,     0,     0,     0,   483,   484,     0,
       0,   664,   665,   666,   667,   668,   669,     0,     0,   670,
     671,   672,   673,   674,   675,   676,   585,    21,     0,     0,
       0,     0,   660,    27,   486,     0,     0,     0,     0,   487,
     586,     0,     0,   182,   183,     0,     0,     0,     0,   587,
     588,   589,   590,     0,   591,   592,     0,     0,     0,     0,
     593,   594,     0,     0,     0,     0,   595,   596,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   677,     0,     0,     0,     0,     0,     0,     0,   678,
     679,     0,   128,   129,     0,     0,     0,     0,     0,     0,
       0,   661,     0,     0,     0,   489,   490,   491,   492,   493,
     494,   495,   496,     0,   497,     0,   498,   499,   500,   501,
     662,   503,   504,     0,   505,   506,     0,     0,     0,     0,
     663,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,     0,     0,     0,     0,   521,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,     0,   535,     0,   536,   537,   538,   539,
     540,     0,     0,     0,     0,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   547,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   548,   549,   550,   551,     0,     0,     0,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   564,   565,   921,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   566,   567,   568,
     569,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   570,   571,     0,     0,     0,     0,
     483,   484,     0,     0,   664,   665,   666,   667,   668,   669,
       0,     0,   670,   671,   672,   673,   674,   675,   676,   585,
      21,     0,     0,     0,     0,   660,    27,   486,     0,     0,
       0,     0,   487,   586,     0,     0,   182,   183,     0,     0,
       0,     0,   587,   588,   589,   590,     0,   591,   592,     0,
       0,     0,     0,   593,   594,     0,     0,     0,     0,   595,
     596,   597,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   677,     0,     0,     0,     0,     0,
       0,     0,   678,   679,     0,   128,   129,     0,     0,     0,
       0,     0,     0,     0,   661,     0,     0,     0,   489,   490,
     491,   492,   493,   494,   495,   496,     0,   497,     0,   498,
     499,   500,   501,   662,   503,   504,     0,   505,   506,     0,
       0,     0,     0,   663,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,     0,     0,
       0,     0,   521,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,     0,   535,     0,   536,
     537,   538,   539,   540,     0,     0,     0,     0,     0,     0,
     541,     0,     0,     0,     0,     0,     0,     0,     0,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,   547,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   548,   549,   550,   551,
       0,     0,     0,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   564,   565,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     566,   567,   568,   569,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   570,   571,     0,
       0,     0,     0,   483,   484,     0,     0,   664,   665,   666,
     667,   668,   669,     0,     0,   670,   671,   672,   673,   674,
     675,   676,   585,    21,     0,     0,     0,     0,   660,    27,
     486,     0,     0,     0,     0,   487,   586,     0,     0,   182,
     183,     0,     0,     0,     0,   587,   588,   589,   590,     0,
     591,   592,     0,     0,     0,     0,   593,   594,     0,     0,
       0,     0,   595,   596,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   677,     0,     0,
       0,     0,     0,     0,     0,   678,   679,     0,   128,   129,
       0,     0,     0,     0,     0,     0,     0,   661,     0,     0,
       0,   489,   490,   491,   492,   493,   494,   495,   496,     0,
     497,     0,   498,   499,   500,   501,   662,   503,   504,     0,
     505,   506,     0,     0,     0,     0,   663,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,     0,     0,     0,     0,   521,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,     0,
     535,     0,   536,   537,   538,   539,   540,     0,     0,     0,
       0,     0,     0,   541,     0,     0,     0,     0,     0,     0,
       0,     0,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,   547,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   548,
     549,   550,   551,     0,     0,     0,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   564,   565,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   566,   567,   568,   569,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     570,   571,     0,     0,     0,     0,     0,     0,     0,     0,
     664,   665,   666,   667,   668,   669,     0,     0,   670,   671,
     672,   673,   674,   675,   676,   585,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,   591,   592,     0,     0,     0,     0,   593,
     594,     0,     0,     0,     0,   595,   596,   597,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1942,     0,     0,     0,     0,     0,     0,     0,   678,   679,
       0,   128,   129
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,   124,   339,   401,    32,   247,   376,   377,   378,   379,
     804,    20,    10,    13,    14,   374,   375,    27,    27,    10,
      10,    27,    31,    27,    96,    27,    35,    82,    31,    83,
      84,    82,   103,    96,    37,     0,    18,   396,   397,    48,
      96,    25,   478,   479,    47,    48,    96,   483,    13,    97,
      98,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,    13,    99,   100,    24,   480,
      97,    98,    24,   484,    30,   302,   303,   478,    31,   600,
     601,   103,   102,   604,   486,   487,    31,  2695,  2696,  2697,
      38,    36,    25,    26,    31,    48,   219,    31,    46,    31,
      27,    27,   130,    48,    31,    31,    25,   107,   136,   480,
      82,    48,    82,   484,    48,   478,    48,    30,   481,    39,
     483,    48,    48,   132,   197,   198,   199,   354,    92,    93,
     130,   103,    37,   103,    18,   489,   478,   491,   480,   103,
     494,   483,    47,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   478,   678,   679,   680,
     144,    92,    93,     0,   478,   130,   239,   481,    31,    92,
      93,   483,   103,    10,   478,   479,   197,   198,   199,   483,
     103,   181,   103,    63,    64,    48,   478,    67,    68,    69,
      70,    71,    72,   130,   478,   179,   130,   481,   130,   483,
     197,   198,   199,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   135,   477,   200,   479,
     480,    99,   100,   179,   484,   144,   478,   478,   479,   481,
     230,   483,   483,   233,   483,   478,   236,   125,   126,   127,
     483,   197,   242,   243,   478,   479,   246,   247,   478,   483,
     480,   481,   252,   253,   187,   188,   144,   483,   478,   479,
     179,   481,   335,   336,   337,   338,   179,   104,   486,   487,
     478,   479,   272,   273,   111,   483,   478,   242,   480,   478,
      20,   483,    13,    14,   197,    16,   477,    27,   479,   480,
     478,    31,   478,   130,  2902,    35,  2904,   483,   481,  2907,
    2908,   301,   478,   303,   304,   478,    27,   483,    48,    30,
     483,   489,   340,   491,   335,   336,   337,   338,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   478,   220,   221,   481,   223,   364,   478,    37,   477,
     305,   479,   480,   477,   344,   479,   480,   478,    47,   439,
     440,   441,   442,   443,    99,   100,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
      31,    32,    33,   482,   478,   484,    37,    31,    32,    33,
     486,   487,   483,    37,   600,   601,    47,    48,   604,   389,
     390,   391,   132,    47,    48,   439,   440,   441,   442,   443,
     483,   401,   478,   403,   404,   481,   483,   478,   356,   483,
     410,   478,   484,   934,   935,   936,   937,   938,   939,   940,
     941,   942,   943,   944,   945,   946,   481,   948,   949,   483,
     951,   434,   483,   496,   484,  3043,   401,   357,   358,   395,
     496,   478,   433,   395,   492,   493,   479,   478,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   483,   678,   679,   680,   492,   493,   478,   478,   489,
     479,   481,   478,   478,   478,   598,   478,   481,   478,   477,
     478,    30,   395,   363,   372,   373,   477,   477,   408,   409,
     410,   411,   412,   413,   225,   478,   416,   417,   418,   419,
     420,   421,   422,   478,   341,   478,   237,   395,   478,   478,
     478,   481,   481,   483,    27,   246,   247,   478,   402,   403,
     404,   405,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   335,   336,   337,   338,   235,   236,   237,  1146,
    1147,  1148,  1149,   478,    20,   244,   245,   246,   247,   478,
     249,    27,   481,   478,   677,    31,   481,   485,   478,    35,
     181,   182,   181,   182,   403,   404,   486,   487,   478,   489,
     490,   478,    48,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   187,   188,   479,   480,   486,   487,    99,   100,
     289,   989,   478,   292,   293,   294,   295,   478,   297,   298,
     479,   480,   301,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   302,   303,   345,    25,    26,   302,   479,   480,
    1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,
    1151,  1152,  1153,  1154,  1155,  1156,   478,   368,   369,   479,
     480,   479,   480,   479,   480,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   478,   132,   657,   478,    23,
      24,   479,   480,   479,   480,   478,    30,   479,   480,   478,
     401,   479,   480,   479,   480,   479,   480,   479,   480,   479,
     480,   479,   480,   478,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   479,   480,   479,
     480,   479,   480,   479,   480,   479,   480,   479,   480,   479,
     480,   478,   600,   601,   479,   480,   604,   478,   934,   935,
     936,   937,   938,   939,   940,   941,   942,   943,   944,   945,
     946,  1525,   948,   949,   478,   951,   479,   480,   479,   480,
     479,   480,   479,   480,   479,   480,   478,   478,   494,   479,
     480,   479,   480,   117,   478,   454,   455,   456,    95,   479,
     480,   460,   790,   462,   479,   480,   479,   480,   479,   480,
     478,  1013,   479,   480,   479,   480,  1146,  1147,  1148,  1149,
    1150,  1151,   479,   480,   478,  1144,  1145,   101,   788,   127,
     479,   480,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   479,   480,   479,   480,   479,
     480,   479,   480,   479,   480,   179,   479,   480,   495,   479,
     480,   479,   480,   401,   947,   481,   125,   126,   479,   480,
     479,   480,   478,   197,   479,   480,   200,   201,   202,   203,
     481,   179,   180,   181,   182,   144,   483,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   483,
     304,   483,   306,   483,   308,   309,   479,   480,   232,   233,
     234,   483,   316,   479,   480,   319,   320,   321,   322,   323,
     324,   479,   480,   479,   480,   301,  1009,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
     483,   355,   479,   480,   483,   359,   479,   480,   479,   480,
     364,   365,   653,   366,   367,  1141,  1142,  1143,   481,  1266,
     374,   380,   381,  1144,  1145,   379,   380,    30,    31,    32,
      33,    27,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,  1150,  1151,   396,   397,
      27,    27,   962,   963,   964,   965,   966,   967,   968,   103,
     970,   971,    28,    27,   478,   975,   976,   977,   978,   979,
     980,   981,   479,   983,    36,   985,   479,   987,   988,   479,
     990,   991,   992,   993,   994,   479,   360,   361,   135,   999,
    1000,  1001,  1002,   480,  1525,    24,   478,   478,   478,   478,
    1010,   478,   478,  1013,   378,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,    31,    32,
      33,   395,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   934,   935,   936,   937,
     938,   939,   940,   941,   942,   943,   944,   945,   946,   478,
     948,   949,   480,   951,   478,   478,   478,   478,   483,  1590,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   103,
     478,   478,   478,   478,   483,   394,   395,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   838,   478,   478,
     478,   478,   483,   478,    95,   478,   478,  1359,    29,   478,
     478,   478,   483,   483,   478,   478,   478,   478,   478,   478,
    1158,   478,   478,   478,   478,   478,  1136,   478,  1138,  1139,
     495,   483,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   883,   478,   478,   886,   478,   478,   478,   478,
     478,   478,   478,   478,    36,   478,  1166,   478,   478,  1169,
     478,  1171,   478,  1173,   478,  1175,   478,   478,   478,   482,
     478,   478,   478,   478,   478,   478,   478,   478,  1586,   478,
     478,   478,   363,   478,   478,   478,   478,   478,  1198,   478,
    1200,  1201,  1202,   478,   478,   478,   478,  1207,  1208,  1209,
    1210,  1211,  1212,  1213,   478,  1215,   478,   478,   478,   478,
     485,   478,   478,   478,   478,  1225,  1226,  1227,  1228,  1229,
    1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,
     483,   478,   478,   478,   478,  1245,  1246,  1247,  1248,  1249,
    1250,  1251,   478,  1141,  1142,   478,  1256,  1257,   478,  1259,
     478,   478,   478,   478,   483,    38,   478,   481,   479,   482,
     480,   479,  1003,   479,   483,  1006,   483,  1277,  1009,  1279,
     482,   479,  1013,   479,   479,   482,  1286,   480,  1288,  1289,
     482,   478,   478,   478,   478,   478,  1296,  1297,  1298,  1299,
    1300,  1301,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   478,   478,   478,
     478,   478,   478,   478,   478,   478,  1326,  1327,  1665,  1329,
    1330,  1331,  1332,  1333,  1334,   478,  1336,  1337,  1338,  1339,
    1340,  1341,  1342,  1343,  1075,  1076,  1346,   478,  1348,  1349,
     478,  1351,  1352,  1353,   478,  1355,  1356,   478,   478,  1359,
     478,  1361,   478,  1363,  1364,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     330,   478,   478,   478,   478,   483,   478,    44,    38,   480,
     479,   479,   482,   480,   479,  1126,  1917,   480,   480,   480,
     480,   480,   480,   480,   480,  1136,   480,   480,   480,   480,
     479,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,  1159,  1160,
     479,   479,  1163,   480,   479,   479,   479,   478,   480,   479,
      29,  1172,   480,   480,   480,   480,   478,   478,   482,   478,
     478,   478,   478,   478,   197,   198,   199,   200,   478,   481,
     478,   478,   478,   478,    32,   478,   478,   766,   767,   768,
     769,   770,   771,   772,   773,   774,   775,   776,   777,   778,
     478,   780,   781,   782,   478,   478,   478,   230,   478,   478,
     478,   478,   478,   478,   478,   238,   478,   179,   478,   478,
     450,   478,   478,   478,   478,   478,   478,   478,   251,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   468,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   179,   478,
     478,  1262,   478,   478,   478,   478,   483,   478,   478,   478,
     478,   478,    32,   453,   479,    33,   479,   483,   482,  1280,
     293,   482,   295,   296,   297,    34,    33,    35,    44,    35,
    1291,   103,   103,   306,   307,   482,   302,   479,   425,   312,
     313,   314,   315,    44,   478,   478,   478,   478,  1309,    30,
      30,    30,   325,   326,   327,   328,   329,  1318,   331,   332,
      30,   334,    30,   103,   239,   479,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,    46,   480,   480,   480,   480,   479,   478,   480,   479,
     395,   480,   480,   479,   479,   479,  1357,   480,  1359,  1360,
     480,  1659,   480,   480,  1365,   934,   935,   936,   937,   938,
     939,   940,   941,   942,   943,   944,   945,   946,   479,   948,
     949,   479,   951,   480,   480,   480,   480,   479,  1658,   480,
     479,   478,   480,   479,   479,   385,   480,   480,   480,   480,
     479,   479,   479,   483,   480,  2012,  1676,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   480,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   480,   479,
     354,   480,   479,   479,   479,   483,   459,   480,   480,   480,
     480,   480,   480,   181,   182,   479,   482,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,    27,   480,   480,
     479,    44,   480,   480,   484,   480,   480,   478,   478,   482,
     479,   478,   480,  1753,  1754,  1755,  1756,   480,  1758,   480,
    1760,   480,   480,   480,   480,   480,  1766,  1767,  1768,   480,
     479,  1771,  1772,  1773,  1774,   479,  1776,   479,  1778,   480,
    1780,   479,   479,  1783,  1784,  1785,  1786,   480,   480,   480,
    1790,   480,   480,  1793,   480,   480,   480,   480,   103,   480,
     480,  1801,   480,  1803,   480,   480,   480,  1807,  1808,   480,
    1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,   480,  1823,   480,   479,   479,   482,   480,    30,
     478,   480,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,
    1840,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   479,   479,  1854,  1855,  1856,  1857,   479,   479,
     479,  1861,  1862,  1863,  1864,   479,   479,   482,   480,   480,
     480,  1871,  1872,  1873,  1874,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,   480,   480,   480,   480,   480,   479,   479,  1889,
    1890,  1891,   479,  1893,  1894,   480,  1896,  1897,   478,   478,
    1900,   478,  1902,   479,   479,    30,   480,   480,   480,   479,
     426,   480,    30,   480,   480,  1915,   480,   479,   479,   479,
     479,   479,   479,   479,  1924,  1925,   480,   479,   479,  1929,
     479,   479,   479,  1933,   479,   479,   479,    30,    30,   479,
     479,   479,   479,   478,   480,   479,   479,    46,   480,  1949,
     479,  1951,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,    27,   480,   479,  1965,   480,   479,   479,   482,
     479,   479,    27,   480,   479,   479,   479,   479,   479,   479,
    1980,   480,  1982,   479,   482,   480,  2014,  1987,   480,   480,
     484,   480,   479,  1993,   103,   480,   480,  1997,  1998,   480,
    2000,  2001,  2002,   483,  2004,  2005,   480,   480,  2008,  2009,
     480,  2011,   479,   130,   480,   480,   480,   479,  1285,   480,
    2020,  2021,   130,   480,  2024,   479,  2026,   480,  2028,  2029,
     130,   479,   479,   479,  2034,   480,   480,  2037,   479,  2039,
     382,   480,   479,  2043,  2044,   479,  2046,   480,   480,  2049,
    2050,  2051,  2052,  2053,  2054,   480,  2056,  2057,  2058,   480,
    2060,  2061,  2062,  2063,  2064,   480,   480,  2067,  2068,  2069,
    2070,   480,  2072,   480,   480,   480,   480,   480,  2078,   480,
     480,  2081,   480,  2083,   479,  2085,  2086,  2087,   479,   479,
     479,   479,   479,  1152,   480,   479,  2096,  2097,   480,   480,
    2100,   480,   479,   479,   479,   479,   479,   479,   479,   479,
     130,   480,   480,   479,   479,   130,   480,   479,   479,   479,
     479,   484,   480,   479,   479,  1155,   480,   479,   479,   479,
    2467,   479,   479,   479,   479,  1866,   480,   480,   479,   479,
    2140,   480,   480,   479,   479,   479,   479,   484,   480,   480,
     479,   386,   480,   480,   480,   480,   479,  1153,   480,   480,
     480,   480,   479,   479,   479,  1156,   480,   479,  1917,   480,
     480,   479,   341,   480,   480,   479,  1154,   479,   479,   479,
    1140,   480,   479,    -1,   480,   480,   480,   480,   480,   480,
     384,   480,   480,   479,   383,   480,   480,   480,   480,  1930,
    1931,  1932,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   479,   996,   480,   480,   480,   480,   480,   480,
     479,   479,    -1,   480,   479,  2348,   479,   479,  2351,   480,
     480,   479,   479,   479,   479,   484,   480,   479,  2266,   479,
     479,  2241,   480,   480,   480,   479,   479,   479,   479,   479,
     479,    -1,   480,   480,   480,   480,   479,    -1,   480,   480,
     479,    -1,   480,   480,   479,  2265,   479,   479,   484,   480,
     480,   479,   387,   480,   480,   479,   479,   479,    -1,   479,
      -1,   480,   479,   479,    -1,   480,   479,   479,    -1,   480,
     480,   479,    -1,   480,   480,   479,    -1,   480,   480,   480,
     480,   480,   480,   480,   480,   479,   479,    -1,   480,   480,
     480,   479,    -1,   480,   480,   480,   480,   480,  2318,   480,
    2320,   480,  2322,   479,  2324,   480,   480,   480,   480,  2329,
    2330,   479,  2332,  2333,  2334,  2335,   479,  2337,  2338,  2339,
    2340,   479,   479,   479,  2344,   479,   479,  2347,  2348,   480,
     480,   480,   480,  2353,   480,    -1,   480,   480,  2358,   480,
    2360,  2361,  2362,  2363,  2364,  2365,  2366,  2367,   480,  2369,
    2370,  2371,  2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,
    2380,  2381,  2382,   480,  2384,   480,   480,    -1,   484,   480,
     480,   480,  2392,   480,   479,   479,  2396,  2397,   479,    -1,
     480,   479,    -1,   480,   480,   479,  2406,  2407,   480,   480,
     479,    -1,   480,   480,   480,   479,  2416,  2417,  2418,  2419,
    2420,   480,  2422,  2423,   480,  2425,  2426,   480,   480,   479,
    2430,  2431,   480,  2433,  2434,   480,   480,   480,   480,   480,
     480,   479,   479,  2443,   480,   480,   480,  2447,   480,  2449,
    2450,   480,   480,   480,   480,   480,   480,   480,   480,  2459,
    2460,  2461,   480,   480,  2464,  2465,   480,   480,   480,   479,
    2470,   479,  2472,   479,  2474,   479,  2476,  2477,  2478,  2479,
    2480,  2481,  2482,  2483,  2484,   480,  2486,  2487,  2488,  2489,
     480,   479,    -1,   480,   480,   480,   480,   480,   480,   479,
    2500,  2501,  2502,  2503,   480,   479,  2506,   479,  2508,  2509,
    2510,  2511,  2512,  2513,  2514,  2515,  2516,   480,   480,   479,
      -1,   480,   479,    -1,   480,   479,   479,    -1,   480,   480,
     479,    -1,   480,   480,   479,   479,    -1,   480,   480,   480,
     479,   479,  2665,   480,   480,   479,  2669,   479,   479,   479,
     479,    -1,   480,   480,   480,   480,   480,   479,   479,   479,
      -1,   480,   479,    -1,   480,   480,   480,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,    -1,   480,   479,
     479,    -1,   480,  2611,   480,   480,   479,   479,   479,    -1,
     480,   480,   480,   479,    -1,   480,   480,   480,   480,   480,
     480,   480,   479,    -1,   480,   480,   480,   480,   480,   480,
     479,   479,   479,    -1,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   479,   479,   479,   479,    -1,   480,
     480,   480,   479,    -1,   480,   479,   479,    -1,   480,   479,
     479,    -1,   480,   480,   479,    -1,   480,   480,   480,  2649,
    2650,   480,  2652,  2653,   479,  2655,  2656,   479,  2658,  2659,
    2660,   480,  2662,  2663,   480,   479,  2666,   480,   480,   480,
     480,  2671,  2672,   480,  2674,   479,  2676,   480,  2678,   480,
    2680,  2681,  2682,  2683,  2684,   480,   480,   479,  2688,  2689,
    2690,  2691,  2692,  2693,   480,  2695,  2696,  2697,  2698,  2699,
    2700,  2701,   480,  2703,  2704,  2705,  2706,  2707,  2439,  2709,
     479,   479,    -1,   480,  2714,  2715,   479,  2717,  2718,  2719,
    2720,  2721,  2722,   479,  2724,  2725,  2726,   479,   479,   479,
    2730,   479,  2732,   480,  2734,   479,   479,  2737,   480,  2739,
    2740,   479,  2742,   480,   479,   479,   479,   479,   479,  2749,
     480,  2751,   479,   479,  2754,  2755,   479,    -1,   480,   480,
    2883,  2761,  2762,  2763,  2764,  2765,   479,    -1,   480,   479,
     479,  2771,  2772,  2773,   480,   480,   480,   479,    -1,   480,
     480,   480,   480,   480,   480,   479,    -1,   480,   480,   480,
     480,   480,   480,   479,   479,    -1,   480,   479,    -1,   480,
     480,   480,   479,   479,   479,    -1,   480,   479,    -1,   480,
     480,   479,    -1,   480,   480,   479,    -1,   480,   480,   480,
     480,   480,   480,   480,   480,   479,    -1,   480,   480,   479,
     479,   479,   479,   479,    -1,   480,   480,   480,   479,   479,
     479,    -1,   480,   480,   480,   479,    -1,   480,   480,   479,
      -1,   480,   480,   479,    -1,   480,   479,    -1,   480,   480,
     479,    -1,   480,   479,    -1,   480,   480,  2867,   479,   479,
    2870,  2871,  2872,   480,   480,   480,  2876,   479,  2878,  2879,
     480,   480,   480,   479,  2884,  2885,   480,  2887,   480,  2889,
    2890,  2891,  2892,  2893,  2894,   480,  2896,  2897,  2898,  2899,
    2900,  2901,  2902,   479,  2904,   480,   480,  2907,  2908,  2909,
    2910,  2911,   480,   479,   479,    -1,    -1,  2917,  2918,    -1,
      -1,  2921,    -1,    -1,    -1,  2925,  2926,  2927,    -1,    -1,
    2930,    -1,    -1,    -1,  2934,  2935,    -1,    -1,  2938,  2939,
      -1,    -1,  2942,    -1,  2944,  2945,    -1,    -1,  2948,  2949,
      -1,  2951,    -1,  2953,  2954,  2955,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2729,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3015,  3016,  3017,  3018,    -1,
    3020,  3021,    -1,    -1,  3024,    -1,    -1,    -1,    -1,    -1,
      -1,  3031,    -1,  3033,    -1,  3035,    -1,    -1,  3038,    -1,
      -1,    -1,    -1,  3043,    -1,    -1,    -1,    -1,  3048,  3049,
      -1,  3051,    -1,  3053,    -1,  3055,  3056,  3057,    -1,  3059,
    3060,    -1,  3062,    -1,  3064,    -1,  3066,  3067,  3068,    -1,
      -1,  3071,  3072,  3073,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3110,    -1,    -1,    -1,  3114,  3115,    -1,    -1,    -1,  3119,
      -1,  3121,  3122,    -1,  3124,  3125,    -1,    -1,    -1,  3129,
      -1,    -1,  3132,  3133,  3134,    -1,  3136,  3137,  3138,  3139,
      -1,    -1,  3142,  3143,    -1,    -1,    -1,    -1,    -1,  2880,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,
      -1,    -1,    -1,    -1,    -1,  3165,    -1,     9,    -1,    -1,
      12,  3171,  3172,  3173,    16,    -1,    -1,  3177,  3178,    -1,
      -1,  3181,  3182,    -1,    -1,  3185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,  3199,
    3200,    -1,  3202,    -1,  3204,    -1,    -1,  3207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3217,    -1,  3219,
    3220,  3221,    -1,    -1,    -1,    -1,    -1,    -1,  3228,  3229,
    3230,    -1,    -1,    -1,    -1,  3235,  3236,  3237,    -1,    -1,
      -1,    -1,  3242,  3243,    -1,    -1,  3246,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,   130,  3020,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,   220,   221,
      -1,   223,  3113,   225,    -1,    -1,    -1,   104,   105,   106,
     107,   108,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   274,   275,   276,   277,   278,   279,   280,   281,
     282,    -1,    -1,    -1,    -1,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    -1,    -1,    -1,
     302,   303,    -1,    -1,    -1,   307,   308,   184,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,
     217,    -1,   219,   345,    -1,   347,   348,   349,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   366,   367,   368,   369,    -1,    -1,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
      -1,    -1,    -1,    -1,    -1,    -1,   388,   389,    -1,    -1,
      -1,    -1,    -1,   395,   396,   397,    -1,    -1,   400,   401,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     287,   288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     357,   358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,    -1,   396,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
     407,   408,   409,   410,   411,   412,   413,    -1,    -1,   416,
     417,   418,   419,   420,   421,   422,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   598,   599,   600,   601,
      -1,   478,   604,    -1,    -1,    -1,    -1,    -1,    -1,   486,
     487,   488,   489,   490,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   664,   665,   666,   667,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,    -1,
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
      -1,    -1,   804,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   838,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   883,    -1,    -1,   886,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   934,   935,   936,   937,   938,   939,   940,   941,
     942,   943,   944,   945,   946,   947,   948,   949,    -1,   951,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   963,    -1,    -1,    -1,    -1,    -1,   969,    -1,    -1,
     972,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     982,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1003,    -1,    -1,  1006,    -1,    -1,  1009,    -1,    -1,
      -1,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,    -1,  1030,  1031,
    1032,  1033,    -1,  1035,  1036,  1037,    -1,    -1,  1040,  1041,
    1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,    -1,    -1,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1097,  1098,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1115,  1116,  1117,  1118,  1119,  1120,    -1,
    1122,  1123,  1124,  1125,  1126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1136,    -1,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1154,  1155,  1156,    -1,    -1,  1159,  1160,    -1,
      -1,  1163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1182,    -1,    -1,    -1,    -1,  1187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1197,    -1,  1199,    -1,    -1,
      -1,  1203,  1204,  1205,  1206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1214,    -1,  1216,  1217,  1218,  1219,  1220,  1221,
    1222,  1223,  1224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1240,    -1,
    1242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1252,  1253,  1254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1280,  1281,
    1282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1291,
    1292,    -1,  1294,  1295,  1296,  1297,    -1,    -1,    -1,    -1,
    1302,    -1,    -1,    -1,  1306,  1307,  1308,  1309,  1310,  1311,
      -1,  1313,    -1,    -1,  1316,    -1,  1318,  1319,  1320,  1321,
    1322,  1323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1335,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1344,  1345,    -1,  1347,    -1,    -1,  1350,    -1,
      -1,    -1,  1354,    -1,    -1,  1357,    -1,  1359,  1360,    -1,
      -1,    -1,    -1,  1365,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1525,    -1,    -1,  1528,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1587,    -1,    -1,  1590,    -1,
    1592,  1593,  1594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1643,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,    47,
      48,    -1,    -1,    -1,  1676,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,
    1752,    -1,    -1,    -1,   132,    -1,   134,    -1,    -1,    -1,
      -1,    -1,  1764,  1765,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1792,    -1,  1794,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1805,  1806,    -1,   184,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1824,  1825,  1826,  1827,  1828,  1829,  1830,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
      -1,   219,  1844,    -1,  1846,  1847,  1848,  1849,  1850,    -1,
    1852,  1853,    -1,    -1,    -1,    -1,  1858,  1859,    -1,    -1,
      -1,    -1,    -1,  1865,  1866,    -1,    -1,  1869,  1870,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1895,    -1,    -1,  1898,    -1,    -1,    -1,
      -1,  1903,    -1,    -1,  1906,    -1,    -1,    -1,    -1,   287,
     288,    -1,    -1,    -1,    -1,  1917,  1918,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1930,  1931,
    1932,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1942,    -1,    -1,    -1,    -1,  1947,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1968,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2000,    -1,
      -1,    -1,    -1,    -1,  2006,  2007,    -1,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,    -1,   396,    -1,
      -1,  2023,    -1,    -1,    -1,    -1,    -1,    -1,   406,   407,
     408,   409,   410,   411,   412,   413,    -1,    -1,   416,   417,
     418,   419,   420,   421,   422,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2070,  2071,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     478,    -1,    -1,    -1,    -1,    -1,   484,    -1,   486,   487,
     488,   489,   490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
      -1,   219,    -1,    -1,    -1,  2347,    -1,    -1,    -1,  2351,
    2352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2369,  2370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2385,  2386,  2387,  2388,  2389,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2402,    -1,    -1,  2405,    -1,    -1,    -1,    -1,    -1,   287,
     288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2439,    -1,    -1,
      -1,    -1,    -1,    -1,  2446,    -1,    -1,    -1,    -1,    -1,
    2452,    -1,  2454,    -1,  2456,    -1,  2458,    -1,    -1,    -1,
    2462,  2463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2471,
      -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
    2492,    -1,    -1,    -1,    -1,    -1,  2498,    -1,    -1,    -1,
      -1,    -1,  2504,  2505,    -1,    -1,    -1,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,    -1,   396,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,   407,
     408,   409,   410,   411,   412,   413,    -1,    -1,   416,   417,
     418,   419,   420,   421,   422,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     478,    -1,    -1,   130,    -1,    -1,    -1,    -1,   486,   487,
     488,   489,   490,    -1,     8,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    -1,    -1,    -1,
      -1,    45,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2665,    -1,    -1,    -1,  2669,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2695,  2696,  2697,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2708,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   242,    -1,    -1,    -1,   246,
     247,    -1,    -1,    -1,    -1,    -1,    -1,  2729,    -1,    -1,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,
     134,    -1,  2744,  2745,    -1,    -1,    -1,   274,  2750,   276,
     277,    -1,   279,    -1,   281,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   289,   290,    -1,    -1,    -1,  2769,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,    -1,
     307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   388,   389,    -1,    -1,    -1,    -1,   394,   395,   396,
     397,    -1,    -1,   400,   401,    -1,    -1,    -1,  2880,    -1,
      -1,  2883,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   287,   288,    -1,    -1,    -1,    -1,    -1,
    2902,    -1,  2904,    -1,    -1,  2907,  2908,    -1,    -1,    -1,
    2912,  2913,  2914,  2915,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2941,
      -1,  2943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2952,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
      -1,    -1,   416,   417,   418,   419,   420,   421,   422,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3043,   436,    -1,    -1,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,  3061,
      -1,  3063,    -1,    -1,    -1,    -1,    -1,    -1,  3070,    -1,
      -1,   598,    -1,   600,   601,    -1,    -1,   604,    -1,    -1,
      -1,    -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   486,   487,   488,   489,   490,    -1,  3100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3128,    -1,    -1,  3131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,   680,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3179,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3205,    -1,    -1,    -1,  3209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   766,
     767,   768,   769,   770,   771,   772,   773,   774,   775,   776,
     777,   778,   779,   780,   781,   782,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,    34,
      -1,    36,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,
      45,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   934,   935,   936,
     937,   938,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,    -1,   951,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   982,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,    -1,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1013,  1014,    -1,  1016,
    1017,    -1,    -1,    -1,    -1,    -1,  1023,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1035,  1036,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1049,     0,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,  1063,  1064,  1065,  1066,
    1067,    -1,   287,   288,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1090,    -1,    -1,    -1,    -1,    -1,    -1,
    1097,  1098,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1115,  1116,
    1117,    -1,  1119,  1120,    -1,  1122,  1123,  1124,  1125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1136,
      -1,  1138,    -1,  1140,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
      -1,   396,    -1,   130,    -1,  1182,    -1,    -1,    -1,    -1,
    1187,   406,   407,   408,   409,   410,   411,   412,   413,    -1,
      -1,   416,   417,   418,   419,   420,   421,   422,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1242,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   486,   487,   488,   489,   490,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1306,
    1307,  1308,    -1,  1310,    -1,    -1,    -1,    -1,    -1,  1316,
      -1,    -1,  1319,  1320,  1321,  1322,  1323,   274,    -1,   276,
     277,    -1,   279,    -1,   281,    -1,    -1,    -1,  1335,    -1,
      -1,    -1,   289,   290,    -1,    -1,    -1,    -1,  1345,    -1,
    1347,    -1,    -1,    -1,    -1,    -1,    -1,  1354,    -1,    -1,
     307,    -1,  1359,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    -1,    36,    37,    -1,    39,    40,    -1,    -1,    -1,
      -1,    45,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   388,   389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398,    -1,   400,   401,    -1,   246,   247,    -1,    -1,
     104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,    -1,    -1,    -1,   274,    -1,   276,   277,    -1,   279,
     134,   281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,
     290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1525,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1587,    -1,    -1,  1590,    -1,    -1,    -1,    -1,   388,   389,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     400,   401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,    -1,
      -1,    -1,    -1,   287,   288,    -1,  1643,    -1,    -1,    -1,
      -1,   598,   599,   600,   601,    -1,    -1,   604,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   357,   358,    -1,    -1,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,   680,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
      -1,    -1,   416,   417,   418,   419,   420,   421,   422,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   436,    -1,    -1,    -1,    -1,  1794,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1805,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1826,
    1827,    -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   486,   487,   488,   489,   490,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1858,  1859,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1903,    -1,    -1,  1906,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1917,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1942,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   934,   935,   936,
     937,   938,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,  2000,   951,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   982,    -1,    -1,    -1,    -1,
      -1,    -1,   989,    -1,    -1,    -1,    -1,    -1,   995,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1013,  1014,    -1,  1016,
    1017,    -1,    -1,  2070,  2071,    -1,  1023,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1035,  1036,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1049,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1063,  1064,  1065,  1066,
    1067,    -1,    -1,    -1,    -1,    -1,  1073,  1074,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1090,    -1,    -1,    -1,    -1,    -1,    -1,
    1097,  1098,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1115,  1116,
    1117,    -1,  1119,  1120,    -1,  1122,  1123,  1124,  1125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1136,
      -1,  1138,   982,  1140,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1013,  1014,    -1,  1016,  1017,    -1,    -1,
      -1,    -1,    -1,  1023,    -1,  1182,    -1,    -1,    -1,    -1,
    1187,    -1,    -1,    -1,    -1,  1035,  1036,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1049,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1063,  1064,  1065,  1066,  1067,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1242,    -1,    -1,    -1,    -1,
    1090,    -1,    -1,    -1,    -1,    -1,    -1,  1097,  1098,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1115,  1116,  1117,    -1,  1119,
    1120,    -1,  1122,  1123,  1124,  1125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1136,    -1,  1138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1303,  1304,  1305,  1306,
    1307,  1308,    -1,  1310,    -1,  1312,    -1,  1314,  1315,  1316,
      -1,    -1,  1319,  1320,  1321,  1322,  1323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1335,    -1,
      -1,    -1,  1182,    -1,    -1,    -1,    -1,  1187,  1345,    -1,
    1347,    -1,    -1,    -1,    -1,  2402,    -1,  1354,  2405,    -1,
      -1,    -1,  1359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1242,    -1,    -1,  2452,    -1,  2454,    -1,  2456,
      -1,  2458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2498,    -1,    -1,    -1,    -1,    -1,  2504,  2505,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1306,  1307,  1308,    -1,
    1310,    -1,    -1,    -1,    -1,    -1,  1316,    -1,    -1,  1319,
    1320,  1321,  1322,  1323,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1335,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1345,    -1,  1347,    -1,    -1,
      -1,    -1,    -1,    -1,  1354,    -1,    -1,    -1,    -1,  1359,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1525,    -1,
      -1,  1528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1586,
    1587,    -1,    -1,  1590,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1643,    -1,    -1,    29,
      -1,    31,    32,    33,    34,    -1,    36,    37,    -1,    39,
      40,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2744,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2769,    -1,   104,   105,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,    -1,  1587,    -1,    -1,
      -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1794,    -1,    -1,
      -1,    -1,    -1,  1643,   184,    -1,    -1,    -1,  1805,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1826,
    1827,    -1,    -1,    -1,    -1,    -1,  1676,   217,    -1,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1858,  1859,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2952,  1903,   287,   288,  1906,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1917,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1942,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1794,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1805,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1826,  1827,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2000,    -1,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,    -1,   396,    -1,  1858,  1859,
      -1,    -1,    -1,  3070,    -1,    -1,   406,   407,   408,   409,
     410,   411,   412,   413,    -1,    -1,   416,   417,   418,   419,
     420,   421,   422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3100,    -1,    -1,   436,    -1,    -1,    -1,
      -1,    -1,    -1,  1903,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2070,  2071,    -1,    -1,    -1,    -1,    -1,
      -1,  3128,    -1,    -1,  3131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   486,   487,   488,   489,
     490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2000,     0,  3209,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2070,  2071,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,
     219,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
     229,   230,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2402,    -1,    -1,  2405,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   271,   272,   273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,
      -1,    -1,    -1,    -1,    -1,  2452,    -1,  2454,    -1,  2456,
      -1,  2458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,
      -1,  2498,    -1,    -1,    -1,    -1,    -1,  2504,  2505,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,   358,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,    -1,   396,   397,    -1,
      -1,   400,  2402,    -1,    -1,  2405,    -1,   406,   407,   408,
     409,   410,   411,   412,   413,    -1,    -1,   416,   417,   418,
     419,   420,   421,   422,    -1,   424,    -1,    -1,    -1,   428,
      -1,   430,   431,    -1,    -1,    -1,   435,   436,    -1,   438,
      -1,    -1,    -1,    -1,    -1,    -1,   445,    -1,    -1,    -1,
      -1,    -1,  2452,    -1,  2454,    -1,  2456,    -1,  2458,    -1,
      -1,    -1,   461,    -1,    -1,    -1,    -1,   466,   467,    -1,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,   488,
     489,   490,    -1,    -1,    -1,    -1,    -1,    -1,  2498,    -1,
      -1,    -1,    -1,    -1,  2504,  2505,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2744,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2769,    -1,    -1,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,
     219,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
     229,   230,    -1,   232,  2744,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2769,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   271,   272,   273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2952,    -1,   286,   287,   288,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,   358,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,    -1,   396,   397,    -1,
      -1,   400,    -1,  3070,    -1,    -1,    -1,   406,   407,   408,
     409,   410,   411,   412,   413,    -1,    -1,   416,   417,   418,
     419,   420,   421,   422,    -1,   424,    -1,    -1,    -1,   428,
      -1,   430,   431,  3100,    -1,    -1,   435,   436,    -1,   438,
      -1,    -1,  2952,    -1,    -1,    -1,   445,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3128,   461,    -1,  3131,    -1,    -1,   466,   467,    -1,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,   488,
     489,   490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3187,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,  3209,    -1,    -1,    27,    -1,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    3070,    43,    -1,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3128,    -1,
      -1,  3131,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,    -1,    -1,
     132,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3187,    -1,    -1,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,    -1,    -1,  3209,
      -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,
      -1,    -1,    -1,   235,   236,   237,    -1,    -1,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,    -1,
      -1,    -1,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,    -1,   287,   288,   289,    -1,    -1,
     292,   293,   294,   295,    -1,   297,   298,   299,   300,   301,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   356,   357,   358,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,    -1,   396,    -1,   398,   399,    -1,   401,
      -1,    -1,    -1,    -1,   406,   407,   408,   409,   410,   411,
     412,   413,    -1,    -1,   416,   417,   418,   419,   420,   421,
     422,   423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   436,   437,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   446,   447,   448,   449,    -1,   451,
     452,    -1,   454,   455,   456,   457,   458,    -1,   460,    -1,
     462,   463,   464,   465,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    11,    12,    -1,   478,    -1,    -1,    -1,
      -1,    -1,    20,    -1,   486,   487,   488,   489,   490,    27,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    45,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
     118,    -1,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,    -1,    -1,   132,    -1,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,    -1,    -1,    -1,    -1,   183,   184,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,
     268,   269,   270,    -1,    -1,    -1,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    -1,   287,
     288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,
     358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,    -1,   396,    -1,
     398,   399,    -1,    -1,    -1,    -1,    -1,    -1,   406,   407,
     408,   409,   410,   411,   412,   413,    -1,    -1,   416,   417,
     418,   419,   420,   421,   422,   423,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,   437,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,   447,
     448,   449,    -1,   451,   452,    -1,    -1,    -1,    -1,   457,
     458,    -1,    -1,    -1,    -1,   463,   464,   465,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    11,    12,    -1,
     478,    -1,    -1,    -1,    -1,    -1,    20,    -1,   486,   487,
     488,   489,   490,    27,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    43,
      -1,    45,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,    -1,    -1,   132,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,    -1,    -1,    -1,    -1,   183,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   267,   268,   269,   270,    -1,    -1,    -1,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,    -1,   287,   288,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   299,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,    -1,   396,    -1,   398,   399,    -1,    -1,    -1,    -1,
      -1,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
      -1,    -1,   416,   417,   418,   419,   420,   421,   422,   423,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   436,   437,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   446,   447,   448,   449,    -1,   451,   452,    -1,
      -1,    -1,    -1,   457,   458,    -1,    -1,    -1,    -1,   463,
     464,   465,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    11,    12,    -1,   478,    -1,    -1,    -1,    -1,    -1,
      20,   485,   486,   487,   488,   489,   490,    27,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    45,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
      -1,    -1,   132,    -1,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    -1,
      -1,    -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,
     270,    -1,    -1,    -1,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,    -1,   287,   288,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,
     300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,    -1,   396,    -1,   398,   399,
      -1,    -1,    -1,    -1,    -1,    -1,   406,   407,   408,   409,
     410,   411,   412,   413,    -1,    -1,   416,   417,   418,   419,
     420,   421,   422,   423,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,   437,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   446,   447,   448,   449,
      -1,   451,   452,    -1,    -1,    -1,    -1,   457,   458,    -1,
      -1,    -1,    -1,   463,   464,   465,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    11,    12,    -1,   478,    -1,
      -1,    -1,    -1,    -1,    20,   485,   486,   487,   488,   489,
     490,    27,    -1,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    43,    -1,    45,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,    -1,    -1,   132,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,    -1,    -1,    -1,    -1,   183,   184,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
      -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   268,   269,   270,    -1,    -1,    -1,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
      -1,   287,   288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   299,   300,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,    -1,
     396,    -1,   398,   399,    -1,    -1,    -1,    -1,    -1,    -1,
     406,   407,   408,   409,   410,   411,   412,   413,    -1,    -1,
     416,   417,   418,   419,   420,   421,   422,   423,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     436,   437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     446,   447,   448,   449,    -1,   451,   452,    -1,    -1,    -1,
      -1,   457,   458,    -1,    -1,    -1,    -1,   463,   464,   465,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    11,    12,    -1,
      -1,    -1,   478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     486,   487,   488,   489,   490,    29,    -1,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    -1,    -1,    43,
      -1,    45,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,    -1,    -1,    -1,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,    -1,    -1,    -1,    -1,   183,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   267,   268,   269,   270,    -1,    -1,    -1,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,    -1,   287,   288,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   299,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   357,   358,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,    -1,   396,    -1,   398,   399,    -1,    -1,    -1,    -1,
      -1,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
      -1,    -1,   416,   417,   418,   419,   420,   421,   422,   423,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   436,   437,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   446,   447,   448,   449,    -1,   451,   452,    -1,
      -1,    -1,    -1,   457,   458,    -1,    -1,    -1,    -1,   463,
     464,   465,    -1,    -1,    -1,    -1,     8,    -1,    -1,    11,
      12,    -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   486,   487,   488,   489,   490,    29,    -1,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    43,    -1,    45,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,    -1,    -1,    -1,
      -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,    -1,
      -1,    -1,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,    -1,   287,   288,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,   300,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,    -1,   396,    -1,   398,   399,    -1,    -1,
      -1,    -1,    -1,    -1,   406,   407,   408,   409,   410,   411,
     412,   413,    -1,    -1,   416,   417,   418,   419,   420,   421,
     422,   423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   436,   437,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   446,   447,   448,   449,    -1,   451,
     452,    -1,    -1,    -1,    -1,   457,   458,    -1,    -1,    -1,
      -1,   463,   464,   465,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    11,    12,    -1,    -1,    -1,   478,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   486,   487,   488,   489,   490,    29,
      -1,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    45,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
      -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    -1,
      -1,    -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,    -1,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,
     270,    -1,    -1,    -1,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,    -1,   287,   288,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,
     300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,    -1,   396,    -1,   398,   399,
      -1,    -1,    -1,    -1,    -1,    -1,   406,   407,   408,   409,
     410,   411,   412,   413,    -1,    -1,   416,   417,   418,   419,
     420,   421,   422,   423,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,   436,   437,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   446,   447,   448,   449,
      -1,   451,   452,    -1,    31,    -1,    -1,   457,   458,    36,
      37,    38,    -1,   463,   464,   465,    43,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,   478,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   486,   487,   488,   489,
     490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
      -1,   128,   129,    -1,    -1,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,   218,    -1,   220,   221,   222,   223,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     267,   268,   269,   270,    -1,    -1,    -1,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,    -1,    -1,
      -1,   398,   399,    -1,    -1,    -1,    -1,    11,    12,    -1,
      -1,   408,   409,   410,   411,   412,   413,    -1,    -1,   416,
     417,   418,   419,   420,   421,   422,   423,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,    43,
     437,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,   446,
     447,   448,   449,    -1,   451,   452,    -1,    -1,    -1,    -1,
     457,   458,    -1,    -1,    -1,    -1,   463,   464,   465,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,
     487,    -1,   489,   490,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,    -1,    -1,    -1,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,    -1,    -1,    -1,    -1,   183,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,   218,    -1,   220,   221,   222,   223,
     224,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   267,   268,   269,   270,    -1,    -1,    -1,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   299,   300,   301,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   381,   382,   383,
     384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   398,   399,    -1,    -1,    -1,    -1,
      11,    12,    -1,    -1,   408,   409,   410,   411,   412,   413,
      -1,    -1,   416,   417,   418,   419,   420,   421,   422,   423,
      31,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,
      -1,    -1,    43,   437,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,   446,   447,   448,   449,    -1,   451,   452,    -1,
      -1,    -1,    -1,   457,   458,    -1,    -1,    -1,    -1,   463,
     464,   465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   486,   487,    -1,   489,   490,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,    -1,
      -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,   218,    -1,   220,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,
      -1,    -1,    -1,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,   300,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     381,   382,   383,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,   399,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,   408,   409,   410,
     411,   412,   413,    -1,    -1,   416,   417,   418,   419,   420,
     421,   422,   423,    31,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    43,   437,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,   446,   447,   448,   449,    -1,
     451,   452,    -1,    -1,    -1,    -1,   457,   458,    -1,    -1,
      -1,    -1,   463,   464,   465,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   486,   487,    -1,   489,   490,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
     118,    -1,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     218,    -1,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,
     268,   269,   270,    -1,    -1,    -1,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   381,   382,   383,   384,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     398,   399,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     408,   409,   410,   411,   412,   413,    -1,    -1,   416,   417,
     418,   419,   420,   421,   422,   423,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,   447,
     448,   449,    -1,   451,   452,    -1,    -1,    -1,    -1,   457,
     458,    -1,    -1,    -1,    -1,   463,   464,   465,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,
      -1,   489,   490
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     3,     4,     5,     6,     7,     8,     9,    10,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    27,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    42,    44,    45,    46,    47,    48,    49,    51,    52,
      53,    54,    55,    56,   104,   105,   106,   107,   108,   119,
     124,   131,   132,   133,   134,   169,   170,   184,   217,   219,
     225,   226,   227,   228,   229,   230,   232,   271,   272,   273,
     286,   287,   288,   333,   357,   358,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   396,   397,   400,   406,
     407,   408,   409,   410,   411,   412,   413,   416,   417,   418,
     419,   420,   421,   422,   424,   428,   430,   431,   435,   436,
     438,   445,   461,   466,   467,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   486,   487,   488,   489,   490,
     498,   499,   500,   501,   502,   503,   504,   507,   508,   509,
     510,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     574,   478,    47,    48,   434,   533,   572,    27,   574,   533,
      32,    33,    34,    35,    36,    39,    40,    45,   124,   134,
     510,   531,   533,   571,   572,    39,   408,   409,   410,   411,
     412,   413,   416,   417,   418,   419,   420,   421,   422,   478,
     486,   487,   510,   517,   531,   478,   510,   533,    92,    93,
     103,    92,    93,   103,    92,    93,   103,   103,   483,    83,
      84,   483,   103,   478,   103,   483,   478,   478,   499,   483,
     483,    82,   481,   481,    32,    33,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     533,   575,   478,   478,   478,   478,   481,   478,   478,   481,
     478,   481,   478,   483,   483,   483,   483,   478,   478,   478,
     481,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   518,
     533,   558,   518,   558,   518,   558,   518,   558,   518,   558,
     518,   558,   518,   558,   518,   558,   518,   558,   518,   558,
     518,   558,   518,   558,   518,   558,   574,   511,   512,   531,
      27,   478,   478,   574,   478,   478,   478,   478,   478,   478,
     531,   532,   571,   518,   558,   518,   558,   518,     0,   499,
     500,   501,   502,   503,   504,   499,   486,   487,    99,   100,
     518,   558,   489,   491,   486,   487,    97,    98,   492,   493,
      99,   100,   485,   494,   495,    95,    96,   496,    82,   103,
     478,   481,   483,   101,   102,   489,   486,   487,    82,   483,
      82,   103,   531,   481,   481,   483,   483,   483,   483,   483,
     478,   483,   483,   510,   483,   531,   531,   531,   510,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   330,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   450,   468,   572,   572,   304,   306,   308,   309,
     316,   319,   320,   321,   322,   323,   324,   355,   359,   364,
     365,   374,   379,   380,   531,   571,   531,   401,    18,   402,
     403,   404,   405,    11,    12,    36,    38,    43,   105,   109,
     110,   111,   112,   113,   114,   115,   116,   118,   120,   121,
     122,   123,   124,   125,   126,   128,   129,   134,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   183,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   218,   220,   221,   222,   223,
     224,   231,   240,   241,   242,   243,   248,   250,   267,   268,
     269,   270,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   299,   300,   381,   382,   383,   384,
     398,   399,   408,   409,   410,   411,   412,   413,   416,   417,
     418,   419,   420,   421,   422,   423,   437,   446,   447,   448,
     449,   451,   452,   457,   458,   463,   464,   465,   478,   485,
     486,   487,   505,   510,   517,   531,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   572,   505,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   363,    18,   200,   301,   531,   531,   481,   531,   531,
      36,   105,   124,   134,   408,   409,   410,   411,   412,   413,
     416,   417,   418,   419,   420,   421,   422,   478,   486,   487,
     517,   533,   552,   572,   533,   552,   552,   533,   552,   533,
     552,   533,   127,   179,   180,   181,   182,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   181,
     182,   181,   182,   181,   182,   533,   533,   533,   552,   552,
     533,   533,   533,   533,   533,   533,   533,   533,    27,    27,
     531,   533,   531,   533,   531,    39,   408,   409,   410,   411,
     412,   413,   416,   417,   418,   419,   420,   421,   422,   478,
     486,   487,   517,   571,    27,   552,   533,   483,   103,    28,
     511,   499,    47,   574,   575,    27,   478,   531,   510,    36,
     533,   533,   533,   479,   479,   479,   499,   508,   508,   510,
     510,   518,   518,   519,   519,   521,   521,   521,   521,   522,
     522,   523,   524,   525,   526,   527,   528,   552,    36,   531,
     552,   531,   531,    23,    24,   117,   179,   197,   200,   201,
     202,   203,   232,   233,   234,   360,   361,   378,   395,   574,
     558,   518,   558,   519,   559,   519,   559,   235,   236,   237,
     244,   245,   246,   247,   249,   289,   292,   293,   294,   295,
     297,   298,   301,   454,   455,   456,   460,   462,   572,   573,
     197,   198,   199,   200,   230,   238,   251,   293,   295,   296,
     297,   306,   307,   312,   313,   314,   315,   325,   326,   327,
     328,   329,   331,   332,   334,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     459,   301,   552,    11,    13,    38,    41,    46,    57,   301,
     356,   386,   389,   401,   408,   409,   410,   411,   412,   413,
     416,   417,   418,   419,   420,   421,   422,   478,   486,   487,
     510,   517,   531,   552,   553,   571,   572,   573,   479,   531,
     531,   531,   480,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   480,   478,   510,   531,   478,   478,    27,   478,
     478,   483,   483,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   483,
     478,   478,   478,   478,   483,   478,   478,   478,   483,   483,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   533,
     537,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   478,   478,   478,   478,   478,
     478,   483,   478,   478,   478,   478,   478,   532,   552,    32,
      33,   533,   572,   538,   538,   479,   480,   538,   478,   481,
     103,   489,   491,   494,   486,   487,    97,    98,   492,   493,
      99,   100,   485,   495,    95,    96,   496,   483,   479,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   510,   481,   482,   482,   531,   479,
     480,   483,   478,   483,   483,   532,   533,   478,   479,   483,
     479,   482,   479,   479,   482,   479,   482,   480,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     480,   479,   480,   479,   482,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   479,   480,   480,   479,   480,
     479,   479,   480,   479,   531,   513,   433,   499,   479,   479,
     479,   439,   440,   441,   442,   443,   506,   480,   479,   480,
     480,   480,   480,   478,   516,   484,   477,   479,   480,   484,
     482,   478,   478,   510,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,    27,   478,   478,
     478,   478,   478,   478,   483,   510,   478,   478,   510,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   481,   481,   478,   483,   478,
     478,   481,   478,   478,   478,   478,   483,   482,   482,   531,
     531,   533,   531,   531,   531,   531,   531,   533,   531,   531,
      36,   533,    29,    36,   531,   531,   531,   531,   531,   531,
     531,   552,   531,    38,   531,    44,   531,   531,   573,   531,
     531,   531,   531,   531,   572,    38,   553,    38,    29,   531,
     531,   531,   531,   510,   510,    32,   510,   532,   533,   531,
     302,   302,   303,   505,   533,   552,   533,   552,   552,   533,
     533,   533,   533,   533,   552,   533,   533,   533,   533,   533,
      25,    26,   533,   533,   533,   533,    25,   144,   179,   552,
     552,   533,   179,   179,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   552,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   552,   552,   552,
     552,   552,   533,   533,   533,   533,   533,   572,   572,   510,
     510,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   552,   533,   533,   533,   533,   533,
     533,   552,   552,   552,   552,   552,   533,   552,   552,   453,
     552,   552,   552,   552,   510,   479,   479,    36,   485,   510,
     531,   552,   552,    36,   484,   531,   533,   576,   551,   518,
     538,   518,   538,   538,   519,   539,   519,   539,   521,   542,
     521,   542,   521,   542,   521,   542,   521,   543,   521,   543,
     544,   546,   547,   548,   549,   335,   336,   337,   338,   499,
     510,   510,    32,    33,   510,    34,    33,   531,    35,    35,
     531,    44,   531,   510,   531,   531,   103,   103,   482,    44,
     479,   483,   478,   478,   478,   533,   531,   533,   531,   531,
     531,   533,   533,   533,   533,   531,   531,   531,   531,   531,
     531,   531,   533,   531,   533,   533,   533,   130,   533,   533,
     130,   533,   130,   533,   533,   533,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   533,   552,   478,   531,   531,   531,   531,   531,   531,
     531,   533,   533,   533,   531,   531,   531,   510,   425,   511,
      30,    30,    30,    30,    30,   479,   480,   531,   531,   510,
     533,   533,   529,   531,   531,   531,   103,   510,   533,   533,
     533,   531,   533,   531,   533,   531,   531,   531,   531,   533,
     572,   572,   572,   552,   552,   552,   510,   552,   533,   572,
     533,   572,   572,   552,   479,   510,   552,   552,   552,   552,
     552,   239,   531,   531,   531,   531,   531,   531,   531,   531,
     552,   531,   531,   531,   531,   531,   531,   531,   531,   533,
     552,   531,   552,   531,   531,   533,   531,   531,   531,   552,
     531,   531,   510,   354,   505,   510,   531,    46,   531,   531,
     510,   479,   480,   480,   480,   480,   480,   479,   480,   479,
     480,   479,   479,   479,   480,   480,   480,   480,   480,   479,
     479,   480,   480,   480,   480,   479,   480,   479,   480,   479,
     480,   479,   479,   480,   480,   480,   480,   479,   483,   479,
     480,   479,   480,   480,   480,   479,   479,   480,   479,   479,
     479,   480,   483,   480,   479,   480,   480,   480,   480,   479,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   479,   480,   478,   478,   480,   480,   480,   478,
     478,   479,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   479,   479,   479,   480,   479,   480,   480,   480,   480,
     480,   479,   480,   480,   480,   480,   480,   480,   480,   480,
     479,   480,   480,   480,   480,   480,   480,   479,   479,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   479,   479,   479,   479,   479,   479,   479,   480,
     480,   480,   479,   480,   480,   480,   480,   480,   478,   479,
     480,   479,   480,   480,   479,   479,   478,   537,    32,    33,
     533,   572,   479,   480,   482,   484,   482,   484,   478,   478,
     478,   478,   479,   479,   480,   480,   480,   479,   479,   480,
     480,   480,   480,   480,   479,   479,   479,   479,   482,   573,
     552,   479,   478,   533,   533,   533,   479,   480,   479,   480,
     479,   480,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   480,   479,   479,   480,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     480,   479,   480,   479,   479,   479,   479,   480,   479,   479,
     479,   479,   479,   480,   479,   479,   552,   480,   480,   479,
     480,   480,   480,   479,   480,   480,   480,   480,   480,   480,
     479,   480,   531,   499,   511,   439,   440,   441,   442,   443,
     480,   480,   479,   480,   480,   479,   477,   479,   480,   480,
     531,   552,   479,   479,   480,   479,   479,   480,   479,   480,
     479,   479,   479,   480,   480,   479,   480,   479,   479,   480,
     480,   480,   480,   480,   480,   479,   480,   480,   480,   479,
     480,   480,   480,   480,   480,   479,   479,   480,   480,   480,
     480,   480,   478,   479,   479,   479,   479,   479,   480,   479,
     479,   480,   479,   480,   479,   480,   480,   480,   479,   479,
     479,   479,   479,   479,   479,   479,   480,   480,   479,   479,
     480,   479,   479,   482,   482,   479,   479,   479,   482,   480,
     479,   479,   480,   533,   531,   531,   531,   531,   531,   531,
     533,   533,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   533,   531,   552,
     103,    27,   531,   531,   552,    27,   533,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   533,   533,   552,   552,   533,   533,   533,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   533,   533,
     533,   533,   533,   533,   533,   533,   531,   531,   531,   531,
     552,   552,   531,   531,   531,   531,   533,   510,   533,   533,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   533,   531,   531,   533,
     531,   531,   552,   484,   531,   550,   533,   479,   479,   479,
     531,   531,    44,   531,   510,   510,   510,   531,   479,   479,
     479,   480,   533,   531,   531,   531,   533,   531,   531,   531,
     531,   479,   531,   531,   531,   552,   531,   531,   531,   531,
     533,   533,   531,   531,   531,   426,   511,   499,    30,    30,
      30,    30,    30,   531,   531,   533,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   552,   552,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,    46,    27,   480,   479,
     480,   479,   480,   479,   480,   479,   479,   479,   479,   480,
     480,   479,   480,   480,   480,   480,   479,   480,   480,   480,
     480,   479,   479,   479,   480,   531,   479,   480,   480,   479,
     479,   480,   480,   480,   479,   479,   479,   479,   480,   479,
     480,   480,   480,   480,   480,   480,   480,   480,   479,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   479,   480,   480,   480,   480,   480,   480,
     479,   479,   480,   479,   479,   479,   480,   480,   479,   479,
     479,   479,   480,   479,   479,   480,   480,   480,   479,   479,
     479,   479,   479,   479,   479,   479,   480,   480,   480,   480,
     480,   479,   480,   480,   479,   480,   480,   479,   479,   479,
     480,   480,   479,   480,   480,   479,   479,   479,   479,   480,
     479,   531,   479,   480,   479,   479,   480,   480,   479,   480,
     480,   479,   480,   479,   480,   479,   480,   479,   480,   480,
     480,   480,   480,   480,   480,   480,   479,   531,   499,   479,
     480,   480,   480,   479,   477,   479,   480,   484,   480,   480,
     480,   480,   480,   480,   480,   479,   480,   480,   480,   480,
     479,   479,   480,   479,   479,   479,   479,   479,   480,   479,
     480,   480,   480,   480,   480,   480,   480,   479,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   479,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   533,   531,   532,   532,   533,    27,
     533,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   533,   531,   533,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   533,   533,
     533,   533,   533,   531,   531,   531,   552,   552,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   510,   479,   531,   533,   531,   531,   531,
     552,   552,   552,   552,   531,   531,   531,   533,   533,   531,
     531,   511,   531,   533,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   533,
     552,   531,   531,   531,   531,   552,   552,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   479,   479,   480,
     480,   479,   480,   480,   479,   480,   480,   479,   480,   480,
     480,   479,   480,   480,   479,   480,   480,   479,   479,   480,
     480,   480,   480,   479,   480,   479,   480,   479,   480,   479,
     480,   480,   480,   480,   480,   479,   479,   479,   480,   480,
     480,   480,   480,   480,   479,   480,   480,   480,   480,   480,
     480,   480,   479,   480,   480,   480,   480,   480,   480,   480,
     479,   479,   479,   479,   480,   480,   479,   480,   480,   480,
     480,   480,   480,   479,   480,   484,   484,   479,   479,   480,
     480,   479,   480,   479,   480,   479,   479,   480,   479,   480,
     480,   479,   480,   479,   480,   480,   479,   479,   499,   480,
     480,   480,   479,   479,   480,   480,   479,   479,   479,   479,
     479,   480,   480,   480,   480,   480,   479,   479,   479,   480,
     479,   480,   480,   480,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   532,   531,   532,    27,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   576,   531,   576,   531,
     576,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     533,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   510,   531,   531,   531,   531,   531,   531,
     531,   552,   533,   531,   533,   531,   531,   531,   531,   531,
     531,   531,   531,   552,   531,   531,   531,   480,   479,   479,
     480,   480,   480,   479,   479,   479,   480,   479,   480,   480,
     480,   479,   479,   480,   480,   480,   479,   480,   479,   480,
     480,   480,   480,   480,   480,   479,   480,   480,   480,   480,
     480,   480,   480,   479,   480,   479,   479,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   479,   480,   480,   479,
     479,   480,   479,   479,   479,   480,   480,   480,   479,   482,
     480,   479,   479,   479,   480,   480,   479,   479,   480,   480,
     479,   480,   480,   480,   480,   484,   479,   479,   480,   480,
     479,   480,   480,   480,   480,   480,   531,   531,   531,   531,
     531,   531,   531,   510,   532,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     576,   576,   576,   576,   531,   531,   531,   533,   533,   533,
     533,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   533,   531,   533,   531,   531,   531,   531,   531,
     552,   531,   531,   531,   479,   480,   480,   480,   480,   479,
     480,   480,   479,   479,   480,   479,   479,   479,   479,   479,
     479,   480,   479,   480,   479,   480,   479,   479,   480,   479,
     479,   479,   479,   480,   479,   479,   479,   479,   480,   480,
     479,   480,   479,   480,   479,   480,   484,   480,   479,   480,
     480,   480,   480,   480,   480,   479,   480,   480,   480,   479,
     480,   480,   480,   480,   531,   531,   531,   531,   510,   531,
     531,   531,   531,   531,   531,   531,   576,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   533,   531,   533,   531,
     103,   531,   531,   531,   552,   531,   531,   531,   479,   479,
     480,   479,   479,   480,   480,   480,   479,   479,   479,   480,
     479,   480,   480,   479,   480,   480,   479,   479,   480,   480,
     479,   480,   480,   480,   480,   552,   480,   480,   480,   480,
     479,   479,   480,   480,   531,   510,   531,   531,   531,   531,
     531,   531,   531,   552,   531,   552,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   480,   479,   479,   479,   479,
     479,   480,   480,   480,   479,   479,   479,   480,   480,   480,
     479,   480,   480,   479,   479,   480,   479,   480,   531,   531,
     531,   531,   531,   531,   533,   531,   531,   531,   552,   480,
     480,   479,   480,   479,   480,   480,   479,   480,   479,   480,
     531,   531,   531,   531,   533,   531,   552,   480,   479,   480,
     480,   480,   479,   479,   531,   531,   531,   531,   480,   480,
     480,   479,   531,   531,   531,   480,   480,   480,   531,   531,
     531,   479,   480,   480,   531,   531,   480,   479,   531,   479
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
     725,   726,   727,   728,   729,   730,   731,    59,    40,    41,
      44,    91,    93,    46,    58,    38,    43,    45,    33,    42,
     126,    47,    60,    62,    94,   124,    63
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   497,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   499,   499,   500,   500,   500,   501,
     501,   502,   503,   503,   503,   503,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   507,   507,
     508,   508,   508,   508,   509,   509,   509,   510,   511,   512,
     513,   514,   514,   514,   514,   514,   514,   514,   514,   515,
     515,   515,   515,   515,   515,   515,   515,   515,   515,   515,
     515,   515,   515,   515,   515,   515,   515,   515,   515,   515,
     515,   515,   515,   515,   515,   515,   515,   515,   515,   515,
     515,   515,   515,   515,   515,   515,   515,   515,   515,   515,
     515,   515,   515,   515,   515,   515,   515,   515,   515,   515,
     515,   515,   515,   515,   515,   515,   515,   515,   515,   515,
     515,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   517,
     517,   518,   518,   519,   519,   519,   520,   520,   520,   521,
     522,   522,   522,   522,   522,   523,   523,   523,   523,   523,
     524,   524,   525,   525,   526,   526,   527,   527,   528,   528,
     529,   529,   530,   531,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   533,   533,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   535,   535,   536,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   538,   538,   539,   539,   539,
     539,   539,   539,   540,   541,   541,   541,   541,   541,   542,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   544,
     544,   544,   544,   544,   545,   545,   546,   547,   547,   548,
     548,   549,   549,   550,   550,   551,   551,   552,   553,   553,
     553,   553,   554,   554,   554,   555,   555,   556,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   558,   559,   559,   559,
     559,   560,   560,   560,   560,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   572,   573,
     573,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   573,   574,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   576,   576,   576,   576
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     3,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     1,     8,    10,     2,     4,
       6,     7,     3,     1,     5,     2,     1,     1,     1,     1,
       1,     1,     4,     6,     6,     6,     6,     3,     3,     6,
       6,     3,     3,     3,     3,     6,     3,     3,     6,     6,
       6,     3,     3,     8,     8,     3,     1,     1,     1,     1,
       4,     1,     2,     2,     2,     1,     3,     3,     3,     6,
       6,    16,     2,     2,     3,     2,     2,     3,     3,     2,
       2,     3,     2,     2,     5,     2,     1,     1,     2,     2,
       4,     2,     2,     2,     1,     4,     3,     2,     2,    10,
       6,     3,     6,     6,     8,    28,     8,     8,     3,     8,
      12,     6,     6,    16,     8,    16,    10,     6,    10,     8,
      10,    14,     8,    12,     6,     8,     6,     6,     6,    10,
       6,    10,    10,    12,     6,     6,    12,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     8,
       3,     3,     3,     3,     3,     3,    12,    16,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,    10,     6,
      14,     6,     8,     6,     6,     8,     6,    10,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     3,
       3,     4,     3,     6,     6,     4,     4,     6,    10,    10,
      10,     6,     6,     6,     6,     6,    10,     6,    10,     6,
       6,     6,     3,     6,     6,    10,    10,     6,     6,     6,
       3,     3,     3,     3,     6,     6,     3,     6,     6,     8,
      10,     3,     6,     3,     4,    20,     6,    10,     6,     3,
       3,     6,     3,     6,     8,     6,     6,     8,    16,     6,
       3,     6,     8,     3,    12,    12,    12,    10,     8,     8,
      10,     8,    10,    12,     6,     8,     8,    10,    16,    18,
      12,     6,    18,    16,    12,    10,    10,    10,     6,    10,
       6,     6,     6,     8,     1,     4,     8,     4,    18,     4,
       1,     1,     6,     6,     3,     3,     6,     6,     3,     3,
       3,     3,     3,     3,     3,     8,     6,     6,     6,     3,
       4,     1,     1,     1,     1,     1,    30,    24,     4,     8,
       0,     1,     3,     1,     3,     2,     4,     2,     4,     1,
       3,     2,     4,     2,     4,     1,     3,     0,     2,     2,
       2,     2,     2,     4,     4,     4,     4,     4,     1,     1,
       1,     6,     1,     3,     1,     3,     3,     1,     3,     0,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     6,     8,    10,    10,     8,     6,     3,     3,     3,
       3,     3,     3,     6,     4,    10,     4,    10,     4,     4,
       4,     4,     4,     4,     7,     7,     7,     9,     7,     6,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     6,     8,    10,    10,     8,     6,     8,
       6,     8,     8,    12,     3,     6,     4,     4,     1,     6,
       6,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     4,     1,     3,     3,     1,     3,     3,     1,
       1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     2,     4,    16,
      14,    16,     4,     4,     4,     1,    10,    12,     8,     1,
       4,     6,     6,     6,     8,     8,     6,     6,     8,     8,
      10,    10,    12,    12,    10,     4,    10,     4,     6,     4,
       4,     4,    12,     4,    12,    12,    16,    20,    10,    12,
       4,     6,     6,     6,     4,     4,     6,     4,     6,     6,
       6,     4,    10,    16,    10,     8,    12,    10,     8,    12,
       8,    12,     8,    12,     3,     3,     8,     8,     3,     6,
      12,    12,    14,    12,    12,    16,     4,     8,    10,    12,
      10,    12,    10,    12,    12,    14,    12,     8,    14,     4,
       4,     4,     4,     3,     3,     3,     6,     6,     6,     6,
       8,    14,    12,    14,    12,     6,     8,    10,    10,    12,
       6,     6,     6,     6,     6,     6,     6,     6,     8,    10,
       4,     4,    10,    10,     4,     6,     6,    12,    30,     8,
       5,     5,     5,     6,     6,     4,     6,     4,     6,     4,
       4,    18,     8,     6,     1,     3,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     4,     1,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     1,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     3,
       8,     4,     6,     1,     4,     1,     3,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     6,
       6,     8,     8,     4,     6,     6,     6,     6,     3,     2,
       4,     1,     4,     6,     1,     4,     4,    10,     6,    16,
      18,    10,    20,     8,     4,     6,     8,     8,    12,    16,
      16,    18,    14,    14,    16,    20,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,    11,     7,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "$end", "error", "$undefined", "T_SetDebugOn", "T_SetDebugOff",
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
  "T_import_filters", "T_amiOFCorr2D", "T_amiOFVar2D", "';'", "'('", "')'",
  "','", "'['", "']'", "'.'", "':'", "'&'", "'+'", "'-'", "'!'", "'*'",
  "'~'", "'/'", "'<'", "'>'", "'^'", "'|'", "'?'", "$accept",
  "list_commands", "end_instr", "loop_inst", "cond_inst", "proc_decl",
  "func_inst", "command", "param_list", "param_list_decl",
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
       498,     0,    -1,   499,    -1,   498,   499,    -1,   504,   499,
      -1,   498,   504,   499,    -1,   500,    -1,   498,   500,    -1,
     501,    -1,   498,   501,    -1,   503,    -1,   498,   503,    -1,
     502,    -1,   498,   502,    -1,    10,    -1,   477,    -1,   424,
     574,   103,   531,   425,   531,   511,   499,    -1,   424,   574,
     103,   531,   425,   531,   426,   531,   511,   499,    -1,   428,
     511,    -1,   431,   531,   511,   499,    -1,   431,   531,   511,
     433,   511,   499,    -1,   445,   574,   478,   506,   479,   511,
     499,    -1,   435,    27,   499,    -1,   435,    -1,    44,   478,
     505,   479,   499,    -1,    44,   499,    -1,     9,    -1,   430,
      -1,    51,    -1,    53,    -1,    54,    -1,    52,    -1,    55,
     478,   531,   479,    -1,    56,   478,   531,   480,    44,   479,
      -1,   574,   103,   301,   481,   531,   482,    -1,   574,    82,
     301,   481,   531,   482,    -1,   574,   103,    11,   481,   531,
     482,    -1,   574,   103,   552,    -1,   574,    82,   552,    -1,
     574,   103,    41,   478,   505,   479,    -1,    48,   481,   531,
     482,   103,   552,    -1,   574,   103,   571,    -1,   574,   103,
     553,    -1,    39,   103,   531,    -1,    39,   103,   571,    -1,
      47,   481,   531,   482,   103,   573,    -1,   574,   103,   573,
      -1,   572,    82,   573,    -1,    47,    82,   301,   481,   531,
     482,    -1,   574,   103,   389,   478,   531,   479,    -1,   574,
     103,   386,   478,   531,   479,    -1,   574,   103,   531,    -1,
     574,   103,   510,    -1,   574,   103,   401,   478,   510,   480,
      27,   479,    -1,    40,   103,   401,   478,   510,   480,    27,
     479,    -1,    40,   483,   405,    -1,     3,    -1,     4,    -1,
       5,    -1,     6,    -1,     7,   478,   531,   479,    -1,    16,
      -1,    14,   533,    -1,    17,   533,    -1,    14,   572,    -1,
     333,    -1,   533,   103,   552,    -1,   533,    82,   552,    -1,
     533,   103,   531,    -1,   533,   481,   531,   482,   103,   552,
      -1,   533,   481,   531,   482,   103,   531,    -1,   533,   478,
     531,   484,   531,   480,   531,   484,   531,   480,   531,   484,
     531,   479,   103,   552,    -1,    32,    92,    -1,    32,    93,
      -1,    32,   103,   531,    -1,    33,    92,    -1,    33,    93,
      -1,    33,   103,   531,    -1,    34,   103,   531,    -1,    34,
      92,    -1,    34,    93,    -1,    35,   103,   510,    -1,    14,
     434,    -1,    49,   575,    -1,    49,    47,   481,   531,   482,
      -1,    21,   510,    -1,    22,    -1,    15,    -1,    15,   574,
      -1,    15,    27,    -1,    40,   483,    18,   510,    -1,    18,
     510,    -1,    19,   510,    -1,    18,   571,    -1,   571,    -1,
      40,   483,    18,   531,    -1,    40,   483,   402,    -1,    18,
     531,    -1,    19,   531,    -1,    36,   483,   361,   478,   531,
     480,   531,   480,   531,   479,    -1,    36,   483,   362,   478,
     531,   479,    -1,    36,   483,   363,    -1,    36,   483,   364,
     478,   533,   479,    -1,    36,   483,   364,   478,    36,   479,
      -1,    36,   483,   366,   478,    36,   480,   533,   479,    -1,
      36,   483,   450,   478,   531,   480,   531,   480,   531,   480,
     531,   480,   531,   480,   531,   480,   531,   480,   531,   480,
     531,   480,   531,   480,   531,   480,   531,   479,    -1,    36,
     483,   365,   478,    29,   480,   533,   479,    -1,    36,   483,
     367,   478,   531,   480,   531,   479,    -1,    36,   483,   368,
      -1,    36,   483,   369,   478,   531,   480,   531,   479,    -1,
      36,   483,   370,   478,   531,   480,   531,   480,   531,   480,
     531,   479,    -1,    36,   483,   371,   478,   531,   479,    -1,
      36,   483,   372,   478,   531,   479,    -1,    36,   483,   373,
     478,   531,   480,   531,   480,   531,   480,   531,   480,   531,
     480,   531,   479,    -1,    36,   483,   374,   478,   531,   480,
     531,   479,    -1,    36,   483,   376,   478,   531,   480,   531,
     480,   531,   480,   531,   480,   531,   480,   531,   479,    -1,
      36,   483,   375,   478,   552,   480,   531,   480,   531,   479,
      -1,    36,   483,   377,   478,    38,   479,    -1,    36,   483,
     252,   478,   531,   480,   533,   480,   531,   479,    -1,    36,
     483,   252,   478,   533,   480,   531,   479,    -1,    36,   483,
     253,   478,   531,   480,   531,   480,   531,   479,    -1,    36,
     483,   253,   478,   531,   480,   531,   480,   531,   480,   531,
     480,   531,   479,    -1,    36,   483,   254,   478,   531,   480,
     531,   479,    -1,    36,   483,   255,   478,   531,   480,   531,
     480,   531,   480,   531,   479,    -1,    36,   483,   256,   478,
     531,   479,    -1,    36,   483,   257,   478,   531,   480,   531,
     479,    -1,    36,   483,   468,   478,    44,   479,    -1,    36,
     483,   330,   478,   533,   479,    -1,   533,   483,   378,   478,
     531,   479,    -1,   533,   483,   378,   478,   531,   480,   531,
     480,   531,   479,    -1,   533,   483,   360,   478,   531,   479,
      -1,   533,   483,   360,   478,   531,   480,   531,   480,   531,
     479,    -1,   533,   483,   361,   478,   531,   480,   531,   480,
     531,   479,    -1,   533,   483,   117,   478,   533,   480,   531,
     480,   531,   480,   531,   479,    -1,   533,   483,   117,   478,
     533,   479,    -1,   533,   483,    23,   478,   510,   479,    -1,
     124,   483,   179,   478,   533,   480,   531,   480,   531,   480,
     531,   479,    -1,   124,   483,   180,   478,   531,   479,    -1,
     124,   483,   127,   478,   531,   479,    -1,   124,   483,   185,
     478,   531,   479,    -1,   124,   483,   186,   478,   531,   479,
      -1,   124,   483,   189,   478,   533,   479,    -1,   124,   483,
     190,   478,   533,   479,    -1,   124,   483,   191,   478,   533,
     479,    -1,   124,   483,   192,   478,   533,   479,    -1,   124,
     483,   193,   478,   531,   479,    -1,   124,   483,   194,   478,
     531,   479,    -1,   124,   483,   195,   478,   531,   479,    -1,
     124,   483,   196,   478,   531,   479,    -1,   124,   483,   180,
     478,   531,   480,   531,   479,    -1,   124,   483,   181,    -1,
     124,   483,   182,    -1,   169,   483,   181,    -1,   169,   483,
     182,    -1,   170,   483,   181,    -1,   170,   483,   182,    -1,
     134,   483,   152,   478,   531,   480,   531,   480,   531,   480,
     531,   479,    -1,   134,   483,   152,   478,   531,   480,   531,
     480,   531,   480,   531,   480,   531,   480,   531,   479,    -1,
     134,   483,   136,   478,   531,   479,    -1,   134,   483,   137,
     478,   531,   479,    -1,   134,   483,   138,   478,   531,   479,
      -1,   134,   483,   151,   478,   531,   479,    -1,   134,   483,
     155,   478,   531,   479,    -1,   134,   483,   160,   478,   531,
     479,    -1,   134,   483,   161,   478,   531,   479,    -1,   134,
     483,   162,   478,   531,   479,    -1,   134,   483,   163,   478,
     531,   479,    -1,   134,   483,   158,   478,   531,   479,    -1,
     134,   483,   159,   478,   531,   480,   531,   480,   531,   479,
      -1,   134,   483,   164,   478,   531,   479,    -1,   134,   483,
     165,   478,   531,   480,   531,   480,   531,   480,   531,   480,
     531,   479,    -1,   134,   483,   153,   478,   531,   479,    -1,
     134,   483,   139,   478,   533,   480,   531,   479,    -1,   134,
     483,   140,   478,   531,   479,    -1,   134,   483,   141,   478,
     533,   479,    -1,   134,   483,   154,   478,   531,   480,   531,
     479,    -1,   134,   483,   143,   478,   533,   479,    -1,   134,
     483,   142,   478,   533,   480,   533,   480,   533,   479,    -1,
     134,   483,   145,   478,   533,   479,    -1,   134,   483,   146,
     478,   533,   479,    -1,   134,   483,   147,   478,   533,   479,
      -1,   134,   483,   150,   478,   533,   479,    -1,   134,   483,
     148,   478,   533,   479,    -1,   134,   483,   149,   478,   533,
     479,    -1,   134,   483,   145,   478,   130,   479,    -1,   134,
     483,   147,   478,   130,   479,    -1,   134,   483,   148,   478,
     130,   479,    -1,   134,   483,   156,   478,   531,   479,    -1,
     134,   483,   157,   478,   531,   479,    -1,   134,   483,   181,
      -1,   134,   483,   182,    -1,   533,   483,   200,   510,    -1,
     533,   483,   201,    -1,   533,   483,   202,   478,   533,   479,
      -1,   533,   483,   203,   478,   533,   479,    -1,   572,   483,
     200,   510,    -1,   572,   483,   251,   510,    -1,   572,   483,
     312,   478,   531,   479,    -1,   572,   483,   325,   478,   531,
     480,   531,   480,   531,   479,    -1,   572,   483,   326,   478,
     531,   480,   531,   480,   531,   479,    -1,   572,   483,   327,
     478,   531,   480,   531,   480,   531,   479,    -1,   572,   483,
     328,   478,   531,   479,    -1,   572,   483,   329,   478,   531,
     479,    -1,   572,   483,   331,   478,   531,   479,    -1,   572,
     483,   332,   478,   531,   479,    -1,   572,   483,   315,   478,
     531,   479,    -1,   572,   483,   313,   478,   531,   480,   531,
     480,   531,   479,    -1,   572,   483,   348,   478,   533,   479,
      -1,   572,   483,   314,   478,   552,   480,   531,   480,   531,
     479,    -1,   572,   483,   314,   478,   552,   479,    -1,   572,
     483,   334,   478,   533,   479,    -1,   572,   483,   341,   478,
     531,   479,    -1,   572,   483,   342,    -1,   572,   483,   230,
     478,   531,   479,    -1,   572,   483,   343,   478,   552,   479,
      -1,   572,   483,   346,   478,   531,   480,   531,   480,   531,
     479,    -1,   572,   483,   347,   478,   531,   480,   531,   480,
     531,   479,    -1,   572,   483,   349,   478,   531,   479,    -1,
     572,   483,   238,   478,   531,   479,    -1,   572,   483,   339,
     478,   552,   479,    -1,   572,   483,   340,    -1,   572,   483,
     296,    -1,   572,   483,   344,    -1,   572,   483,   345,    -1,
     572,   483,   295,   478,   531,   479,    -1,   572,   483,   297,
     478,   531,   479,    -1,   572,   483,   293,    -1,   572,   483,
     307,   478,   531,   479,    -1,   572,   483,   306,   478,   531,
     479,    -1,   572,   483,   306,   478,   531,   480,   531,   479,
      -1,   572,   483,   350,   478,   531,   480,   531,   480,   531,
     479,    -1,   572,   483,   351,    -1,   572,   483,   353,   478,
     531,   479,    -1,   572,   483,   352,    -1,   466,   478,   510,
     479,    -1,   467,   478,    36,   480,   531,   480,   531,   480,
     531,   480,   531,   480,   531,   480,   531,   480,   531,   480,
     531,   479,    -1,   572,   483,   459,   478,   552,   479,    -1,
      38,   483,   304,   478,   531,   480,   531,   480,   531,   479,
      -1,    38,   483,   308,   478,   573,   479,    -1,    38,    83,
     572,    -1,    38,    84,   572,    -1,    38,   483,   323,   478,
     572,   479,    -1,    38,   483,   324,    -1,    38,   483,   306,
     478,   531,   479,    -1,    38,   483,   306,   478,   531,   480,
     531,   479,    -1,    38,   483,   309,   478,   531,   479,    -1,
      38,   483,   364,   478,    38,   479,    -1,    38,   483,   365,
     478,    29,   480,   533,   479,    -1,    38,   483,   379,   478,
     531,   480,   552,   480,   531,   480,   531,   480,   531,   480,
     531,   479,    -1,    38,   483,   380,   478,   531,   479,    -1,
      38,   483,   359,    -1,    38,   483,   355,   478,   553,   479,
      -1,    38,   483,   355,   478,   553,   480,   531,   479,    -1,
      38,   483,   316,    -1,    38,   483,   319,   478,   531,   480,
     531,   480,   531,   480,   531,   479,    -1,    38,   483,   320,
     478,   531,   480,   531,   480,   531,   480,   531,   479,    -1,
      38,   483,   321,   478,   531,   480,   531,   480,   531,   480,
     531,   479,    -1,    38,   483,   322,   478,   531,   480,   531,
     480,   531,   479,    -1,    38,   483,   374,   478,   531,   480,
     531,   479,    -1,   225,   478,   533,   480,   531,   480,   531,
     479,    -1,   225,   478,   533,   480,   531,   480,   531,   480,
     552,   479,    -1,   226,   478,   533,   480,   531,   480,   531,
     479,    -1,   226,   478,   533,   480,   531,   480,   531,   480,
     552,   479,    -1,   226,   478,   533,   480,   531,   480,   531,
     480,   552,   480,   531,   479,    -1,   227,   478,   533,   480,
     531,   479,    -1,   227,   478,   533,   480,   531,   480,   552,
     479,    -1,   227,   478,   533,   480,   531,   480,   531,   479,
      -1,   227,   478,   533,   480,   531,   480,   531,   480,   552,
     479,    -1,   229,   478,   533,   480,   531,   480,   531,   480,
     531,   480,   531,   480,   531,   480,   531,   479,    -1,   229,
     478,   533,   480,   531,   480,   531,   480,   531,   480,   531,
     480,   531,   480,   531,   480,   552,   479,    -1,   228,   478,
     533,   480,   531,   480,   531,   480,   552,   480,   531,   479,
      -1,   230,   478,   533,   480,   531,   479,    -1,   273,   478,
      27,   480,   533,   480,   533,   480,   533,   480,   533,   480,
     533,   480,   533,   480,   552,   479,    -1,   273,   478,    27,
     480,   533,   480,   533,   480,   533,   480,   533,   480,   533,
     480,   533,   479,    -1,   272,   478,    27,   480,   533,   480,
     533,   480,   533,   480,   552,   479,    -1,   272,   478,    27,
     480,   533,   480,   533,   480,   533,   479,    -1,   232,   478,
     533,   480,   531,   480,   531,   480,   531,   479,    -1,   533,
     483,   232,   478,   531,   480,   531,   480,   531,   479,    -1,
     533,   483,   232,   478,   533,   479,    -1,   533,   483,   233,
     478,   531,   480,   531,   480,   531,   479,    -1,   533,   483,
     233,   478,   533,   479,    -1,   533,   483,   234,   478,   531,
     479,    -1,   119,   478,   533,   480,   533,   479,    -1,   119,
     478,   533,   480,   533,   480,   533,   479,    -1,   531,    -1,
     286,   478,   531,   479,    -1,   397,   478,   552,   480,   510,
     480,   531,   479,    -1,   400,   478,   533,   479,    -1,   271,
     478,   533,   480,   533,   480,   531,   480,   531,   480,   531,
     480,   531,   480,   531,   480,   531,   479,    -1,   438,   478,
      27,   479,    -1,   131,    -1,   133,    -1,   574,   103,    57,
     478,   510,   479,    -1,    45,   483,    76,   478,   510,   479,
      -1,    45,   483,    60,    -1,    45,   483,    61,    -1,    45,
     483,    62,   478,   510,   479,    -1,    45,   483,    58,   478,
     510,   479,    -1,    45,   483,    59,    -1,    45,   483,    77,
      -1,    45,   483,    78,    -1,    45,   483,    79,    -1,    45,
     483,    65,    -1,    45,   483,    66,    -1,    45,   483,    80,
      -1,    45,   483,    73,   478,   531,   480,   531,   479,    -1,
      45,   483,    74,   478,    44,   479,    -1,    45,   483,    75,
     478,   531,   479,    -1,   469,   478,   533,   480,   510,   479,
      -1,    46,   483,    18,    -1,    46,   483,   200,   510,    -1,
     470,    -1,   471,    -1,   472,    -1,   473,    -1,   474,    -1,
     475,   478,   533,   480,   533,   480,   533,   480,   533,   480,
     533,   480,   533,   480,   533,   480,   531,   480,   531,   480,
     531,   480,   531,   480,   531,   480,   531,   480,   531,   479,
      -1,   476,   478,   533,   480,   533,   480,   531,   480,   531,
     480,   531,   480,   531,   480,   531,   480,   531,   480,   533,
     480,   533,   480,   531,   479,    -1,    42,   478,   505,   479,
      -1,   461,   478,   531,   480,   531,   480,   531,   479,    -1,
      -1,   531,    -1,   505,   480,   531,    -1,   510,    -1,   505,
     480,   510,    -1,   485,    32,    -1,   505,   480,   485,    32,
      -1,   485,    33,    -1,   505,   480,   485,    33,    -1,   552,
      -1,   505,   480,   552,    -1,   485,   533,    -1,   505,   480,
     485,   533,    -1,   485,   572,    -1,   505,   480,   485,   572,
      -1,    36,    -1,   505,   480,    36,    -1,    -1,   442,    30,
      -1,   443,    30,    -1,   439,    30,    -1,   440,    30,    -1,
     441,    30,    -1,   506,   480,   442,    30,    -1,   506,   480,
     443,    30,    -1,   506,   480,   439,    30,    -1,   506,   480,
     440,    30,    -1,   506,   480,   441,    30,    -1,    27,    -1,
      35,    -1,   507,    -1,    20,   478,   510,   480,   531,   479,
      -1,   132,    -1,   533,   483,    24,    -1,   508,    -1,   509,
     486,   508,    -1,   509,   487,   508,    -1,   509,    -1,   512,
      28,   513,    -1,    -1,    -1,    29,    -1,     8,    -1,   406,
      -1,   407,    -1,    32,    -1,    33,    -1,    34,    -1,   478,
     531,   479,    -1,   514,    -1,   533,   478,   531,   479,    -1,
     533,   478,   531,   480,   531,   479,    -1,   533,   478,   531,
     480,   531,   480,   531,   479,    -1,   533,   478,   531,   480,
     531,   480,   531,   480,   531,   479,    -1,   533,   478,   531,
     480,   531,   480,   531,   477,   531,   479,    -1,   533,   478,
     531,   480,   531,   477,   531,   479,    -1,   533,   478,   531,
     477,   531,   479,    -1,   533,   483,   179,    -1,   533,   483,
     574,    -1,   533,   483,   197,    -1,   572,   483,   197,    -1,
     572,   483,   198,    -1,   572,   483,   199,    -1,   184,   478,
     533,   480,   533,   479,    -1,   217,   478,   533,   479,    -1,
     287,   478,   533,   480,   531,   480,   531,   480,   531,   479,
      -1,   288,   478,   533,   479,    -1,   288,   478,   531,   480,
     531,   480,   531,   480,   531,   479,    -1,   104,   478,   552,
     479,    -1,   219,   478,   552,   479,    -1,   105,   478,   533,
     479,    -1,   106,   478,   552,   479,    -1,   107,   478,   533,
     479,    -1,   108,   478,   533,   479,    -1,   105,   481,   552,
     482,   478,   533,   479,    -1,   107,   481,   552,   482,   478,
     533,   479,    -1,   108,   481,   552,   482,   478,   533,   479,
      -1,   108,   481,   552,   482,   478,   533,   480,   531,   479,
      -1,   219,   481,   552,   482,   478,   552,   479,    -1,   219,
     478,   533,   480,   552,   479,    -1,   396,   478,    27,   479,
      -1,    36,   483,   262,    -1,    36,   483,   263,    -1,    36,
     483,   260,    -1,    36,   483,   261,    -1,    36,   483,   258,
      -1,    36,   483,   259,    -1,    36,   483,   264,    -1,    36,
     483,   265,    -1,    36,   483,   266,    -1,   124,   483,   187,
      -1,   124,   483,   188,    -1,   134,   483,   135,    -1,    39,
     478,   531,   480,   531,   479,    -1,    39,   478,   531,   480,
     531,   479,   103,   531,    -1,    45,   483,    63,   478,    32,
     480,   531,   480,   531,   479,    -1,    45,   483,    64,   478,
      33,   480,   531,   480,   531,   479,    -1,    45,   483,    67,
     478,   510,   480,    44,   479,    -1,    45,   483,    68,   478,
      34,   479,    -1,    45,   483,    69,   478,    33,   480,   531,
     479,    -1,    45,   483,    69,   478,    33,   479,    -1,    45,
     483,    70,   478,   531,   480,   510,   479,    -1,    45,   483,
      71,   478,    35,   480,   510,   479,    -1,    45,   483,    72,
     478,    35,   480,   510,   480,   510,   480,   510,   479,    -1,
      45,   483,   363,    -1,    45,   483,   363,   478,   531,   479,
      -1,   436,   478,   574,   479,    -1,   436,   478,   575,   479,
      -1,   532,    -1,    40,   483,   403,   478,   510,   479,    -1,
      40,   483,   404,   478,    32,   479,    -1,   515,    -1,   517,
     518,    -1,   488,   518,    -1,   487,   518,    -1,   486,   518,
      -1,   408,   518,    -1,   409,   518,    -1,   419,   518,    -1,
     420,   518,    -1,   421,   518,    -1,   422,   518,    -1,   410,
     518,    -1,   411,   518,    -1,   412,   518,    -1,   413,   518,
      -1,   416,   518,    -1,   418,   518,    -1,   417,   518,    -1,
     489,    -1,   490,    -1,   516,    -1,   478,   532,   479,   516,
      -1,   518,    -1,   519,   489,   518,    -1,   519,   491,   518,
      -1,   519,    -1,   520,   486,   519,    -1,   520,   487,   519,
      -1,   520,    -1,   521,    -1,   522,   492,   521,    -1,   522,
     493,   521,    -1,   522,    97,   521,    -1,   522,    98,   521,
      -1,   522,    -1,   523,    99,   522,    -1,   523,   100,   522,
      -1,   510,    99,   510,    -1,   510,   100,   510,    -1,   523,
      -1,   524,   485,   523,    -1,   524,    -1,   525,   494,   524,
      -1,   525,    -1,   526,   495,   525,    -1,   526,    -1,   527,
      95,   526,    -1,   527,    -1,   528,    96,   527,    -1,   528,
      -1,   528,   496,   528,   484,   529,    -1,   529,    -1,   530,
      -1,   385,    -1,   386,    -1,   387,    -1,   388,    -1,   389,
      -1,   390,    -1,   391,    -1,   392,    -1,   393,    -1,   394,
      -1,   533,   483,   395,    -1,    31,    -1,    48,   481,   531,
     482,    -1,    11,    27,    -1,    11,   478,   510,   479,    -1,
      12,   478,   531,   480,   531,   480,   532,   480,   531,   480,
     510,   480,   531,   480,   531,   479,    -1,    12,   478,   531,
     480,   531,   480,   531,   480,   532,   480,   531,   480,   510,
     479,    -1,    12,   478,   531,   480,   531,   480,   531,   480,
     532,   480,   531,   480,   531,   480,   510,   479,    -1,   267,
     478,   510,   479,    -1,   268,   478,   510,   479,    -1,    43,
     478,   505,   479,    -1,    11,    -1,    11,   478,   532,   480,
     531,   480,   531,   480,   531,   479,    -1,    11,   478,   532,
     480,   531,   480,   531,   480,   531,   480,   531,   479,    -1,
      11,   478,   532,   480,   531,   480,   533,   479,    -1,   533,
      -1,   533,   481,   531,   482,    -1,   220,   478,   552,   480,
     531,   479,    -1,   221,   478,   552,   480,   531,   479,    -1,
     222,   478,   552,   480,   531,   479,    -1,   223,   478,   552,
     480,   552,   480,   531,   479,    -1,   224,   478,   552,   480,
     552,   480,   531,   479,    -1,   105,   478,   552,   480,   552,
     479,    -1,   109,   478,   533,   480,    27,   479,    -1,   109,
     478,   533,   480,    27,   480,   532,   479,    -1,   109,   478,
     533,   480,   533,   480,    27,   479,    -1,   109,   478,   533,
     480,   533,   480,    27,   480,   532,   479,    -1,   109,   478,
     533,   480,   533,   480,   533,   480,    27,   479,    -1,   109,
     478,   533,   480,   533,   480,   533,   480,    27,   480,   532,
     479,    -1,   110,   478,   552,   480,   531,   480,   531,   480,
     531,   480,   531,   479,    -1,   452,   483,   453,   478,   533,
     480,   531,   480,   531,   479,    -1,   299,   478,   533,   479,
      -1,   129,   478,   533,   480,   531,   480,   531,   480,   531,
     479,    -1,   300,   478,   533,   479,    -1,   204,   478,   552,
     480,   531,   479,    -1,   205,   478,   533,   479,    -1,   206,
     478,   533,   479,    -1,   207,   478,   533,   479,    -1,   208,
     478,   533,   480,   533,   480,   531,   480,   531,   480,   531,
     479,    -1,   209,   478,   533,   479,    -1,   210,   478,   533,
     480,   533,   480,   533,   480,   531,   480,   533,   479,    -1,
     211,   478,   533,   480,   533,   480,   533,   480,   531,   480,
     533,   479,    -1,   212,   478,   533,   480,   533,   480,   533,
     480,   531,   480,   533,   480,   531,   480,   531,   479,    -1,
     213,   478,   533,   480,   533,   480,   533,   480,   531,   480,
     533,   480,   531,   480,   531,   480,   531,   480,   531,   479,
      -1,   214,   478,   533,   480,   533,   480,   533,   480,   533,
     479,    -1,   214,   478,   533,   480,   533,   480,   533,   480,
     533,   480,   531,   479,    -1,   215,   478,   533,   479,    -1,
     215,   478,   533,   480,   533,   479,    -1,   216,   478,   533,
     480,   533,   479,    -1,   111,   478,   552,   480,   531,   479,
      -1,   112,   478,   533,   479,    -1,   128,   478,   533,   479,
      -1,   113,   478,   533,   480,   531,   479,    -1,   231,   478,
     533,   479,    -1,   114,   478,   533,   480,   531,   479,    -1,
     115,   478,   533,   480,   531,   479,    -1,   118,   478,   552,
     480,   531,   479,    -1,   533,   481,   576,   482,    -1,   533,
     481,   484,   480,   484,   480,   531,   484,   531,   482,    -1,
     116,   478,   533,   480,   531,   480,   531,   480,   531,   480,
     531,   480,   531,   480,   531,   479,    -1,   120,   478,   533,
     480,   531,   480,   531,   480,   531,   479,    -1,   120,   478,
     533,   480,   531,   480,   531,   479,    -1,   120,   478,   533,
     480,   531,   480,   531,   480,   531,   480,   531,   479,    -1,
     121,   478,   533,   480,   531,   480,   531,   480,   531,   479,
      -1,   121,   478,   533,   480,   531,   480,   531,   479,    -1,
     121,   478,   533,   480,   531,   480,   531,   480,   531,   480,
     531,   479,    -1,   122,   478,   533,   480,   531,   480,   531,
     479,    -1,   122,   478,   533,   480,   531,   480,   531,   480,
     531,   480,   531,   479,    -1,   123,   478,   533,   480,   531,
     480,   531,   479,    -1,   123,   478,   533,   480,   531,   480,
     531,   480,   531,   480,   531,   479,    -1,   124,   483,    25,
      -1,   124,   483,    26,    -1,   134,   483,   179,   478,   533,
     480,   531,   479,    -1,   134,   483,   179,   478,   533,   480,
     533,   479,    -1,   134,   483,    25,    -1,   134,   483,   144,
     478,   533,   479,    -1,   124,   478,   533,   480,   531,   480,
     531,   480,   531,   480,   531,   479,    -1,   168,   478,   533,
     480,   533,   480,   531,   480,   531,   480,   531,   479,    -1,
     126,   478,   533,   480,   531,   480,   531,   480,   531,   480,
     531,   480,   531,   479,    -1,   125,   478,   533,   480,   531,
     480,   531,   480,   531,   480,   531,   479,    -1,   169,   483,
     179,   478,   533,   480,   531,   480,   531,   480,   531,   479,
      -1,   170,   483,   179,   478,   533,   480,   531,   480,   531,
     480,   531,   480,   531,   480,   531,   479,    -1,   171,   478,
     533,   479,    -1,   172,   478,   533,   480,   531,   480,   531,
     479,    -1,   172,   478,   533,   480,   531,   480,   531,   480,
     576,   479,    -1,   172,   478,   533,   480,   531,   480,   531,
     480,   531,   480,   576,   479,    -1,   173,   478,   533,   480,
     531,   480,   531,   480,   576,   479,    -1,   173,   478,   533,
     480,   531,   480,   531,   480,   531,   480,   576,   479,    -1,
     174,   478,   533,   480,   531,   480,   531,   480,   576,   479,
      -1,   175,   478,   533,   480,   531,   480,   531,   480,   531,
     480,   576,   479,    -1,   176,   478,   533,   480,   531,   480,
     531,   480,   531,   480,   576,   479,    -1,   177,   478,   533,
     480,   531,   480,   531,   480,   531,   480,   531,   480,   576,
     479,    -1,   178,   478,   533,   480,   531,   480,   531,   480,
     531,   480,   531,   479,    -1,   183,   478,   533,   480,   531,
     480,   531,   479,    -1,   218,   478,   533,   480,   531,   480,
     531,   480,   531,   480,   531,   480,   531,   479,    -1,   381,
     478,   533,   479,    -1,   382,   478,   533,   479,    -1,   383,
     478,   533,   479,    -1,   384,   478,   533,   479,    -1,    38,
     483,   302,    -1,    38,   483,   303,    -1,    36,   483,   302,
      -1,   240,   478,   533,   480,   531,   479,    -1,   241,   478,
     533,   480,   531,   479,    -1,   242,   478,   533,   480,   531,
     479,    -1,   243,   478,   533,   480,   531,   479,    -1,   166,
     478,   552,   480,   552,   480,   531,   479,    -1,   167,   478,
     552,   480,   552,   480,   531,   480,   531,   480,   531,   480,
     531,   479,    -1,   166,   478,   552,   480,   552,   480,   531,
     480,   531,   480,   531,   479,    -1,   166,   478,   552,   480,
     552,   480,   531,   480,   531,   480,   531,   480,   531,   479,
      -1,   166,   478,   552,   480,   552,   480,   533,   480,   531,
     480,   531,   479,    -1,   269,   478,   533,   480,   533,   479,
      -1,   270,   478,   533,   480,   533,   480,   552,   479,    -1,
     274,   478,   533,   480,   531,   480,   531,   480,   531,   479,
      -1,   275,   478,   533,   480,   531,   480,   531,   480,   531,
     479,    -1,   275,   478,   533,   480,   531,   480,   531,   480,
     531,   480,   531,   479,    -1,   276,   478,   533,   480,   531,
     479,    -1,   277,   478,   533,   480,   531,   479,    -1,   278,
     478,   533,   480,   531,   479,    -1,   279,   478,   533,   480,
     531,   479,    -1,   280,   478,   533,   480,   531,   479,    -1,
     281,   478,   533,   480,   531,   479,    -1,   282,   478,   533,
     480,   531,   479,    -1,   283,   478,   533,   480,   531,   479,
      -1,   283,   478,   533,   480,   531,   480,   531,   479,    -1,
     284,   478,   533,   480,   531,   480,   531,   480,   531,   479,
      -1,   285,   478,   552,   479,    -1,   533,   478,   552,   479,
      -1,   398,   478,   552,   480,   531,   480,   531,   480,   531,
     479,    -1,   399,   478,   552,   480,   531,   480,   531,   480,
     531,   479,    -1,   446,   478,   552,   479,    -1,   446,   478,
     552,   480,   531,   479,    -1,   449,   478,   552,   480,   531,
     479,    -1,   447,   478,   552,   480,   531,   480,   531,   480,
     531,   480,   531,   479,    -1,   448,   478,   533,   480,   533,
     480,   531,   480,   531,   480,   531,   480,   531,   480,   531,
     480,   531,   480,   531,   480,   531,   480,   531,   480,   531,
     480,   531,   480,   531,   479,    -1,   451,   478,   552,   480,
     531,   480,   531,   479,    -1,   572,   483,   336,   478,   479,
      -1,   572,   483,   337,   478,   479,    -1,   572,   483,   338,
     478,   479,    -1,   572,   483,   335,   478,   533,   479,    -1,
     457,   478,   552,   480,   531,   479,    -1,   457,   478,   552,
     479,    -1,   458,   478,   552,   480,   531,   479,    -1,   458,
     478,   552,   479,    -1,   463,   478,   552,   480,   552,   479,
      -1,   464,   478,   552,   479,    -1,   465,   478,   510,   479,
      -1,   437,   478,   552,   480,   531,   480,   531,   480,   531,
     480,   531,   480,   531,   480,   531,   480,   531,   479,    -1,
     248,   478,   572,   480,   533,   480,   552,   479,    -1,   250,
     478,   572,   480,   510,   479,    -1,   534,    -1,   478,   552,
     479,    -1,   535,    -1,   536,    -1,   517,   538,    -1,   487,
     538,    -1,   486,   538,    -1,   408,   538,    -1,   409,   538,
      -1,   419,   538,    -1,   420,   538,    -1,   421,   538,    -1,
     422,   538,    -1,   410,   538,    -1,   411,   538,    -1,   412,
     538,    -1,   413,   538,    -1,   416,   538,    -1,   418,   538,
      -1,   417,   538,    -1,   423,   538,    -1,   537,    -1,   478,
     532,   479,   537,    -1,   538,    -1,   539,   489,   518,    -1,
     539,   491,   518,    -1,   539,   489,   538,    -1,   539,   491,
     538,    -1,   539,   494,   538,    -1,   539,    -1,   540,    -1,
     541,   486,   519,    -1,   541,   487,   519,    -1,   541,   486,
     539,    -1,   541,   487,   539,    -1,   541,    -1,   542,    -1,
     543,   492,   542,    -1,   543,   493,   542,    -1,   543,    97,
     542,    -1,   543,    98,   542,    -1,   543,   492,   521,    -1,
     543,   493,   521,    -1,   543,    97,   521,    -1,   543,    98,
     521,    -1,   543,    -1,   544,    99,   543,    -1,   544,   100,
     543,    -1,   544,    99,   521,    -1,   544,   100,   521,    -1,
     544,    -1,   545,   485,   544,    -1,   545,    -1,   546,    -1,
     547,   495,   546,    -1,   547,    -1,   548,    95,   547,    -1,
     548,    -1,   549,    96,   548,    -1,   549,    -1,   549,   496,
     549,   484,   550,    -1,   550,    -1,   537,   103,   551,    -1,
     551,    -1,    46,    -1,    38,   483,   354,    -1,   356,   478,
      46,   480,    46,   480,   531,   479,    -1,    13,   478,   510,
     479,    -1,   357,   478,   531,   480,   531,   479,    -1,    39,
      -1,   358,   478,   571,   479,    -1,   554,    -1,   478,   571,
     479,    -1,   555,    -1,   556,    -1,   517,   558,    -1,   487,
     558,    -1,   486,   558,    -1,   558,   101,    -1,   408,   558,
      -1,   409,   558,    -1,   419,   558,    -1,   420,   558,    -1,
     421,   558,    -1,   422,   558,    -1,   410,   558,    -1,   411,
     558,    -1,   412,   558,    -1,   413,   558,    -1,   416,   558,
      -1,   418,   558,    -1,   417,   558,    -1,   557,    -1,   558,
      -1,   559,   489,   518,    -1,   559,   102,   558,    -1,   559,
     489,   558,    -1,   559,    -1,   560,   486,   519,    -1,   560,
     487,   519,    -1,   560,   486,   559,    -1,   560,   487,   559,
      -1,   560,    -1,   561,    -1,   562,    -1,   563,    -1,   564,
      -1,   565,    -1,   566,    -1,   567,    -1,   568,    -1,   569,
      -1,   570,    -1,    37,    -1,    47,   481,   531,   482,    -1,
     289,   478,   552,   480,   531,   479,    -1,   292,   478,   533,
     480,   531,   479,    -1,   289,   478,   552,   480,   531,   480,
     533,   479,    -1,   298,   478,   552,   480,   531,   480,   552,
     479,    -1,   293,   478,   572,   479,    -1,   293,   478,   572,
     480,   531,   479,    -1,   294,   478,   533,   480,   531,   479,
      -1,   295,   478,   572,   480,   531,   479,    -1,   297,   478,
     572,   480,   531,   479,    -1,   301,   478,   479,    -1,   301,
      27,    -1,   301,   478,   510,   479,    -1,   301,    -1,   249,
     478,   510,   479,    -1,   249,   478,   510,   480,   531,   479,
      -1,   572,    -1,   235,   478,   533,   479,    -1,   236,   478,
     572,   479,    -1,   236,   478,   572,   480,   531,   480,   531,
     480,   531,   479,    -1,   237,   478,   572,   480,   531,   479,
      -1,   244,   478,   572,   480,   531,   480,   531,   480,   531,
     480,   531,   480,   531,   480,   531,   479,    -1,   245,   478,
     552,   480,   531,   480,   531,   480,   531,   480,   531,   480,
     531,   480,   531,   480,   531,   479,    -1,   246,   478,   552,
     480,   531,   480,   531,   480,   531,   479,    -1,   247,   478,
     552,   480,   531,   480,   531,   480,   531,   480,   531,   480,
     531,   480,   531,   480,   531,   480,   531,   479,    -1,   572,
     483,   239,   478,   531,   480,   531,   479,    -1,   454,   478,
     552,   479,    -1,   454,   478,   552,   480,   531,   479,    -1,
     454,   478,   552,   480,   531,   480,   531,   479,    -1,   456,
     478,   552,   480,   531,   480,   531,   479,    -1,   455,   478,
     552,   480,   531,   480,   531,   480,   552,   480,   552,   479,
      -1,   455,   478,   552,   480,   531,   480,   531,   480,   552,
     480,   552,   480,   552,   480,   531,   479,    -1,   460,   478,
     552,   480,   552,   480,   552,   480,   531,   480,   531,   480,
     531,   480,   531,   479,    -1,   460,   478,   552,   480,   552,
     480,   552,   480,   531,   480,   531,   480,   531,   480,   531,
     480,   531,   479,    -1,   460,   478,   552,   480,   552,   480,
     552,   480,   531,   480,   531,   480,   531,   479,    -1,   460,
     478,   552,   480,   531,   480,   531,   480,   531,   480,   531,
     480,   531,   479,    -1,   462,   478,   552,   480,   552,   480,
     552,   480,   531,   480,   531,   480,   531,   480,   531,   479,
      -1,   462,   478,   552,   480,   552,   480,   552,   480,   531,
     480,   531,   480,   531,   480,   531,   480,   552,   480,   552,
     479,    -1,    30,    -1,    33,    -1,    32,    -1,   533,    -1,
      36,    -1,    37,    -1,    38,    -1,    40,    -1,    41,    -1,
      42,    -1,    43,    -1,    44,    -1,    35,    -1,    39,    -1,
      46,    -1,    45,    -1,    47,    -1,    48,    -1,   531,   484,
     531,   480,   531,   484,   531,   480,   531,   484,   531,    -1,
     531,   484,   531,   480,   531,   484,   531,    -1,   533,    -1,
      36,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    15,    17,    20,    22,
      25,    27,    30,    32,    35,    37,    39,    48,    59,    62,
      67,    74,    82,    86,    88,    94,    97,    99,   101,   103,
     105,   107,   109,   114,   121,   128,   135,   142,   146,   150,
     157,   164,   168,   172,   176,   180,   187,   191,   195,   202,
     209,   216,   220,   224,   233,   242,   246,   248,   250,   252,
     254,   259,   261,   264,   267,   270,   272,   276,   280,   284,
     291,   298,   315,   318,   321,   325,   328,   331,   335,   339,
     342,   345,   349,   352,   355,   361,   364,   366,   368,   371,
     374,   379,   382,   385,   388,   390,   395,   399,   402,   405,
     416,   423,   427,   434,   441,   450,   479,   488,   497,   501,
     510,   523,   530,   537,   554,   563,   580,   591,   598,   609,
     618,   629,   644,   653,   666,   673,   682,   689,   696,   703,
     714,   721,   732,   743,   756,   763,   770,   783,   790,   797,
     804,   811,   818,   825,   832,   839,   846,   853,   860,   867,
     876,   880,   884,   888,   892,   896,   900,   913,   930,   937,
     944,   951,   958,   965,   972,   979,   986,   993,  1000,  1011,
    1018,  1033,  1040,  1049,  1056,  1063,  1072,  1079,  1090,  1097,
    1104,  1111,  1118,  1125,  1132,  1139,  1146,  1153,  1160,  1167,
    1171,  1175,  1180,  1184,  1191,  1198,  1203,  1208,  1215,  1226,
    1237,  1248,  1255,  1262,  1269,  1276,  1283,  1294,  1301,  1312,
    1319,  1326,  1333,  1337,  1344,  1351,  1362,  1373,  1380,  1387,
    1394,  1398,  1402,  1406,  1410,  1417,  1424,  1428,  1435,  1442,
    1451,  1462,  1466,  1473,  1477,  1482,  1503,  1510,  1521,  1528,
    1532,  1536,  1543,  1547,  1554,  1563,  1570,  1577,  1586,  1603,
    1610,  1614,  1621,  1630,  1634,  1647,  1660,  1673,  1684,  1693,
    1702,  1713,  1722,  1733,  1746,  1753,  1762,  1771,  1782,  1799,
    1818,  1831,  1838,  1857,  1874,  1887,  1898,  1909,  1920,  1927,
    1938,  1945,  1952,  1959,  1968,  1970,  1975,  1984,  1989,  2008,
    2013,  2015,  2017,  2024,  2031,  2035,  2039,  2046,  2053,  2057,
    2061,  2065,  2069,  2073,  2077,  2081,  2090,  2097,  2104,  2111,
    2115,  2120,  2122,  2124,  2126,  2128,  2130,  2161,  2186,  2191,
    2200,  2201,  2203,  2207,  2209,  2213,  2216,  2221,  2224,  2229,
    2231,  2235,  2238,  2243,  2246,  2251,  2253,  2257,  2258,  2261,
    2264,  2267,  2270,  2273,  2278,  2283,  2288,  2293,  2298,  2300,
    2302,  2304,  2311,  2313,  2317,  2319,  2323,  2327,  2329,  2333,
    2334,  2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,  2353,
    2355,  2360,  2367,  2376,  2387,  2398,  2407,  2414,  2418,  2422,
    2426,  2430,  2434,  2438,  2445,  2450,  2461,  2466,  2477,  2482,
    2487,  2492,  2497,  2502,  2507,  2515,  2523,  2531,  2541,  2549,
    2556,  2561,  2565,  2569,  2573,  2577,  2581,  2585,  2589,  2593,
    2597,  2601,  2605,  2609,  2616,  2625,  2636,  2647,  2656,  2663,
    2672,  2679,  2688,  2697,  2710,  2714,  2721,  2726,  2731,  2733,
    2740,  2747,  2749,  2752,  2755,  2758,  2761,  2764,  2767,  2770,
    2773,  2776,  2779,  2782,  2785,  2788,  2791,  2794,  2797,  2800,
    2802,  2804,  2806,  2811,  2813,  2817,  2821,  2823,  2827,  2831,
    2833,  2835,  2839,  2843,  2847,  2851,  2853,  2857,  2861,  2865,
    2869,  2871,  2875,  2877,  2881,  2883,  2887,  2889,  2893,  2895,
    2899,  2901,  2907,  2909,  2911,  2913,  2915,  2917,  2919,  2921,
    2923,  2925,  2927,  2929,  2931,  2935,  2937,  2942,  2945,  2950,
    2967,  2982,  2999,  3004,  3009,  3014,  3016,  3027,  3040,  3049,
    3051,  3056,  3063,  3070,  3077,  3086,  3095,  3102,  3109,  3118,
    3127,  3138,  3149,  3162,  3175,  3186,  3191,  3202,  3207,  3214,
    3219,  3224,  3229,  3242,  3247,  3260,  3273,  3290,  3311,  3322,
    3335,  3340,  3347,  3354,  3361,  3366,  3371,  3378,  3383,  3390,
    3397,  3404,  3409,  3420,  3437,  3448,  3457,  3470,  3481,  3490,
    3503,  3512,  3525,  3534,  3547,  3551,  3555,  3564,  3573,  3577,
    3584,  3597,  3610,  3625,  3638,  3651,  3668,  3673,  3682,  3693,
    3706,  3717,  3730,  3741,  3754,  3767,  3782,  3795,  3804,  3819,
    3824,  3829,  3834,  3839,  3843,  3847,  3851,  3858,  3865,  3872,
    3879,  3888,  3903,  3916,  3931,  3944,  3951,  3960,  3971,  3982,
    3995,  4002,  4009,  4016,  4023,  4030,  4037,  4044,  4051,  4060,
    4071,  4076,  4081,  4092,  4103,  4108,  4115,  4122,  4135,  4166,
    4175,  4181,  4187,  4193,  4200,  4207,  4212,  4219,  4224,  4231,
    4236,  4241,  4260,  4269,  4276,  4278,  4282,  4284,  4286,  4289,
    4292,  4295,  4298,  4301,  4304,  4307,  4310,  4313,  4316,  4319,
    4322,  4325,  4328,  4331,  4334,  4337,  4339,  4344,  4346,  4350,
    4354,  4358,  4362,  4366,  4368,  4370,  4374,  4378,  4382,  4386,
    4388,  4390,  4394,  4398,  4402,  4406,  4410,  4414,  4418,  4422,
    4424,  4428,  4432,  4436,  4440,  4442,  4446,  4448,  4450,  4454,
    4456,  4460,  4462,  4466,  4468,  4474,  4476,  4480,  4482,  4484,
    4488,  4497,  4502,  4509,  4511,  4516,  4518,  4522,  4524,  4526,
    4529,  4532,  4535,  4538,  4541,  4544,  4547,  4550,  4553,  4556,
    4559,  4562,  4565,  4568,  4571,  4574,  4577,  4579,  4581,  4585,
    4589,  4593,  4595,  4599,  4603,  4607,  4611,  4613,  4615,  4617,
    4619,  4621,  4623,  4625,  4627,  4629,  4631,  4633,  4635,  4640,
    4647,  4654,  4663,  4672,  4677,  4684,  4691,  4698,  4705,  4709,
    4712,  4717,  4719,  4724,  4731,  4733,  4738,  4743,  4754,  4761,
    4778,  4797,  4808,  4829,  4838,  4843,  4850,  4859,  4868,  4881,
    4898,  4915,  4934,  4949,  4964,  4981,  5002,  5004,  5006,  5008,
    5010,  5012,  5014,  5016,  5018,  5020,  5022,  5024,  5026,  5028,
    5030,  5032,  5034,  5036,  5038,  5050,  5058,  5060
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   902,   902,   902,   903,   907,   911,   911,   912,   912,
     913,   913,   914,   914,   917,   921,   925,   954,   980,  1005,
    1025,  1056,  1079,  1101,  1145,  1189,  1205,  1213,  1217,  1231,
    1245,  1259,  1269,  1288,  1313,  1323,  1333,  1343,  1355,  1366,
    1381,  1405,  1417,  1428,  1433,  1443,  1468,  1480,  1498,  1520,
    1528,  1536,  1544,  1553,  1584,  1600,  1605,  1609,  1613,  1618,
    1622,  1626,  1631,  1670,  1690,  1719,  1736,  1749,  1769,  1782,
    1817,  1847,  1865,  1869,  1873,  1877,  1881,  1885,  1889,  1893,
    1897,  1901,  1906,  1910,  1919,  1928,  1935,  1944,  1958,  2206,
    2260,  2268,  2277,  2287,  2293,  2299,  2306,  2312,  2322,  2332,
    2350,  2362,  2372,  2421,  2436,  2457,  2488,  2503,  2510,  2517,
    2535,  2558,  2563,  2568,  2581,  2592,  2601,  2610,  2618,  2635,
    2651,  2668,  2688,  2703,  2721,  2734,  2748,  2757,  2771,  2782,
    2795,  2813,  2835,  2859,  2889,  2921,  2926,  2944,  2949,  2954,
    2959,  2964,  2969,  2983,  2998,  3015,  3029,  3049,  3054,  3059,
    3066,  3076,  3084,  3089,  3096,  3101,  3106,  3126,  3150,  3155,
    3160,  3165,  3170,  3175,  3180,  3185,  3190,  3195,  3200,  3205,
    3210,  3215,  3220,  3225,  3230,  3235,  3240,  3245,  3253,  3258,
    3263,  3268,  3273,  3278,  3283,  3288,  3293,  3298,  3303,  3308,
    3313,  3317,  3344,  3357,  3362,  3366,  3372,  3385,  3391,  3397,
    3403,  3410,  3417,  3424,  3435,  3446,  3461,  3476,  3484,  3493,
    3502,  3510,  3514,  3518,  3555,  3564,  3571,  3578,  3589,  3597,
    3615,  3625,  3630,  3637,  3644,  3652,  3660,  3679,  3695,  3712,
    3729,  3734,  3739,  3744,  3749,  3757,  3858,  3892,  3899,  3907,
    3913,  3920,  3930,  3939,  3946,  3953,  3963,  3970,  3984,  3998,
    4006,  4011,  4019,  4027,  4038,  4050,  4062,  4074,  4080,  4093,
    4100,  4111,  4133,  4159,  4187,  4197,  4210,  4220,  4233,  4262,
    4279,  4294,  4301,  4323,  4342,  4360,  4374,  4379,  4384,  4393,
    4398,  4407,  4421,  4428,  4435,  4437,  4452,  4486,  4499,  4543,
    4548,  4553,  4559,  4575,  4582,  4588,  4594,  4601,  4608,  4614,
    4620,  4626,  4632,  4638,  4650,  4656,  4673,  4680,  4691,  4698,
    4703,  4709,  4714,  4719,  4724,  4729,  4734,  4769,  4796,  4803,
    4825,  4829,  4836,  4843,  4851,  4859,  4868,  4875,  4882,  4889,
    4896,  4903,  4910,  4917,  4924,  4931,  4938,  4948,  4953,  4959,
    4965,  4971,  4977,  4983,  4989,  4995,  5001,  5007,  5014,  5019,
    5031,  5037,  5051,  5064,  5071,  5072,  5082,  5090,  5096,  5107,
    5108,  5111,  5116,  5124,  5132,  5142,  5147,  5153,  5159,  5168,
    5173,  5188,  5204,  5208,  5225,  5241,  5255,  5268,  5289,  5348,
    5367,  5384,  5391,  5399,  5404,  5409,  5437,  5443,  5454,  5474,
    5494,  5512,  5532,  5550,  5568,  5591,  5614,  5637,  5644,  5669,
    5692,  5699,  5709,  5719,  5729,  5739,  5749,  5759,  5773,  5790,
    5806,  5811,  5816,  5820,  5827,  5835,  5870,  5883,  5893,  5910,
    5929,  5945,  5963,  5983,  6004,  6017,  6030,  6038,  6046,  6050,
    6058,  6068,  6073,  6078,  6079,  6080,  6081,  6082,  6083,  6084,
    6085,  6086,  6094,  6095,  6096,  6097,  6098,  6099,  6100,  6105,
    6106,  6110,  6116,  6132,  6133,  6134,  6138,  6139,  6140,  6144,
    6152,  6153,  6154,  6155,  6156,  6160,  6161,  6162,  6163,  6164,
    6168,  6172,  6180,  6184,  6191,  6195,  6202,  6206,  6213,  6217,
    6224,  6225,  6232,  6236,  6245,  6250,  6254,  6258,  6262,  6266,
    6270,  6274,  6278,  6282,  6286,  6294,  6299,  6316,  6323,  6330,
    6389,  6444,  6501,  6523,  6545,  6559,  6589,  6598,  6618,  6644,
    6658,  6738,  6805,  6813,  6821,  6831,  6841,  6871,  6890,  6911,
    6930,  6951,  6970,  6990,  7031,  7047,  7062,  7079,  7102,  7117,
    7132,  7147,  7162,  7198,  7213,  7235,  7257,  7299,  7346,  7364,
    7384,  7399,  7414,  7429,  7449,  7465,  7481,  7499,  7521,  7538,
    7554,  7566,  7594,  7614,  7659,  7671,  7682,  7695,  7707,  7718,
    7744,  7771,  7803,  7820,  7838,  7851,  7864,  7884,  7907,  7921,
    7936,  7970,  8007,  8042,  8075,  8092,  8109,  8123,  8144,  8167,
    8191,  8216,  8241,  8263,  8285,  8309,  8352,  8376,  8408,  8422,
    8459,  8496,  8533,  8568,  8573,  8582,  8587,  8598,  8608,  8618,
    8627,  8648,  8678,  8706,  8737,  8772,  8783,  8799,  8809,  8819,
    8834,  8848,  8862,  8875,  8888,  8900,  8912,  8924,  8935,  8948,
    8975,  9008,  9116,  9140,  9182,  9195,  9206,  9215,  9239,  9264,
    9277,  9287,  9297,  9307,  9317,  9327,  9335,  9343,  9351,  9378,
    9399,  9407,  9445,  9468,  9488,  9488,  9490,  9492,  9493,  9494,
    9495,  9496,  9497,  9498,  9499,  9500,  9501,  9502,  9503,  9504,
    9505,  9506,  9507,  9508,  9509,  9525,  9526,  9550,  9551,  9557,
    9559,  9560,  9561,  9564,  9569,  9570,  9571,  9572,  9573,  9576,
    9580,  9581,  9582,  9583,  9584,  9585,  9586,  9587,  9588,  9592,
    9593,  9594,  9595,  9596,  9600,  9601,  9606,  9610,  9611,  9615,
    9616,  9620,  9621,  9625,  9626,  9630,  9631,  9634,  9638,  9648,
    9661,  9672,  9690,  9697,  9707,  9722,  9722,  9724,  9726,  9727,
    9728,  9729,  9730,  9739,  9740,  9741,  9742,  9743,  9744,  9745,
    9746,  9747,  9748,  9749,  9750,  9751,  9755,  9757,  9758,  9759,
    9760,  9770,  9771,  9772,  9773,  9774,  9777,  9781,  9785,  9789,
    9794,  9798,  9802,  9806,  9810,  9814,  9817,  9822,  9827,  9844,
    9856,  9868,  9880,  9913,  9922,  9931,  9940,  9949,  9958,  9965,
    9973,  9980,  9998, 10012, 10028, 10038, 10057, 10086, 10114, 10130,
   10148, 10183, 10216, 10263, 10290, 10300, 10323, 10335, 10348, 10388,
   10433, 10483, 10536, 10582, 10611, 10644, 10685, 10689, 10691, 10693,
   10697, 10699, 10701, 10703, 10705, 10707, 10709, 10711, 10713, 10715,
   10717, 10719, 10721, 10723, 10729, 10737, 10744, 10760
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
       2,     2,     2,   488,     2,     2,     2,     2,   485,     2,
     478,   479,   489,   486,   480,   487,   483,   491,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   484,   477,
     492,     2,   493,   496,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   481,     2,   482,   494,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   495,     2,   490,     2,     2,     2,
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
     475,   476
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 15202;
  const int Parser::yynnts_ = 80;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 358;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 497;

  const unsigned int Parser::yyuser_token_number_max_ = 731;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

} // namespace yyip

#line 10780 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"

#include <stdio.h>

void yyiperror(const char *s) {
/*   ---------
 */
  string tmpstr;
  if (yyiplineno) {
    tmpstr = str(format("%s:%d\t %s \n\t ==> at '%s'  \n")
      %GB_current_file.c_str()
      %yyiplineno
      %s
      %yyiptext
    );
    err_print(tmpstr.c_str());
  } else {
    tmpstr = str(format("%s \n")%s);
    err_print(tmpstr.c_str());
  } /* end else */
  fflush(stdout);
  yyERROR = 1;
} /* end yyerror */


int yyip_switch_to_file(  const char* filename)
{
  YY_BUFFER_STATE b;
  string  fullname;

  GB_current_file = filename;

  cout << "yyip_switch_to_file(" << filename << ")" << endl;
  if (yy_num_buf>=YY_MAX_BUF)
    {
      sprintf(tmp_string,
          "yyip_switch_to_file(%s) \t Too many buffers \n",
          filename);
      err_print(tmp_string);
      return 0;
    }

  // Looking for the filename
  wxFileName currentname(GetwxStr(filename));
  wxFileName newname(GetwxStr(filename));

  if (!currentname.IsOk()) {
    sprintf(tmp_string,"Problem with the filename %s\n",
                        currentname.GetFullPath().c_str());
    err_print(tmp_string);
    return 0;
  }

  // could check first if there is another extension ...
  currentname.SetExt(_T("amil"));
  //  cout << "current working directory" << wxGetCwd() << endl;
  //  cout << "current name path" << currentname.GetPath() << endl;
  //  cout << "current name full path" << currentname.GetFullPath() << endl;

  //cout << "current wd = "  <<  wxGetCwd() << endl; 
  if (!currentname.DirExists(currentname.GetPath())) 
  {
    // try with current directory
    newname.Assign(
            wxGetCwd() 
            +
            currentname.GetPathSeparator()
            +
            currentname.GetPath(),
            currentname.GetName(),_T("amil"));
  }

  if (!newname.IsFileReadable()) 
  {
    // try with AMI_SCRIPTS environment variable
    newname.Assign(GB_scripts_dir
						+
						currentname.GetPathSeparator()
						+
						currentname.GetPath(),
						currentname.GetName(),_T("amil"));
  }

  if (!newname.IsFileReadable()) {
   string mess =  (format("Error in reading %s \n") % currentname.GetFullPath().c_str()).str();
   wxMessageDialog* err_msg = new wxMessageDialog(NULL,GetwxStr(mess),GetwxStr("Error"),wxOK | wxICON_ERROR);
   err_msg->ShowModal();
   return 0;
  }

  cout << "current name " << newname.GetFullPath() << endl;
  yyipin=fopen(newname.GetFullPath().mb_str(),"r");
  if (!yyipin) {
    string mess =  (format("Error in reading %s \n") % newname.GetFullPath().c_str()).str();
    wxMessageDialog* err_msg = new wxMessageDialog(NULL,GetwxStr(mess),wxT("Error"),wxOK | wxICON_ERROR);
    err_msg->ShowModal();
    return 0;
  }


  b = yyip_create_buffer(yyipin,YY_BUF_SIZE);
  yyip_switch_to_buffer(b);
  yy_buf_stack[yy_num_buf]=b;
  yy_num_buf++;

  //cout << "current wd = "  <<  wxGetCwd() << endl; 
  return 1;
}

void yyip_switch_to_string( const char* st)
{
  YY_BUFFER_STATE b;

  //  for(int i=0;i<yy_num_buf;i++) printf("  ");
  //  printf("yyip_switch_to_string() \n");

  if (yy_num_buf>=YY_MAX_BUF)
    {
      sprintf(tmp_string,
    "yyip_switch_to_string(%s) \t Too many buffers \n",
    st);
      err_print(tmp_string);
      return;
    }

  //  b = yyip_scan_string(st);

  //  printf("st=*%s*  length= %d\n",st,strlen(st));

  /*
  printf("yyip_switch_to_string(%s)",st);
  printf(" %3u %3u %3u %3u ",
     st[strlen(st)-1],st[strlen(st)],st[strlen(st)+1],st[strlen(st)+2]);
  */

   b = yyip_scan_buffer((char*)st,strlen(st)+2);

  if (b!= NULL) {
    yy_buf_stack[yy_num_buf]=b;
    yy_num_buf++;
  }
  else {
    err_print("yyip_switch_to_string() error in creating buffer \n");
    printf("st=\"%s\"  length= %d\n",st,(int)strlen(st));
    fflush(stdout);
  }
}

void yyip_reinit_current_buffer()
{
  YY_BUFFER_STATE b;

  b                   = yy_buf_stack[yy_num_buf-1];
  b->yy_buf_pos       = b->yy_ch_buf;
  b->yy_n_chars       = b->yy_buf_size;
  b->yy_at_bol        = 1;
  b->yy_fill_buffer   = 0;
  b->yy_buffer_status = YY_BUFFER_NEW;

  yyip_load_buffer_state();
}

void yyip_popup_buffer()
{

  //  for(int i=0;i<yy_num_buf;i++) printf("  ");
  //  printf("yyip_popup_buffer() \n");

  if (!yy_num_buf)
    {
      sprintf(tmp_string,"yyip_popup_buffer() \t empty stack\n");
      err_print(tmp_string);
      return;
    }
  yyip_delete_buffer( yy_buf_stack[yy_num_buf-1]);
  yy_num_buf--;
  if (yy_num_buf) {
    yyip_switch_to_buffer( yy_buf_stack[yy_num_buf-1]);
  }
}

void print_buf_info(YY_BUFFER_STATE b)
{
  int state;
  //int EOB; // end of buffer

  printf(" BUFFER INFO \n");
  printf("yy_ch_buf        = \"%s\" \n",  b->yy_ch_buf);
  printf("*yy_buf_pos      = '%c' \n",*(b->yy_buf_pos));
  //printf("yy_buf_pos-yy_ch_buf    = %d \n", b->yy_buf_pos-b->yy_ch_buf);
  printf("*yy_buf_size     = %d \n",  b->yy_buf_size);
  printf("yy_n_chars       = %d \n",  b->yy_n_chars);
  printf("yy_is_our_buffer = %d \n",  b->yy_is_our_buffer);
  printf("yy_is_interactive= %d \n",  b->yy_is_interactive);
  printf("yy_at_bol        = %d \n",  b->yy_at_bol);
  printf("yy_fill_buffer   = %d \n",  b->yy_fill_buffer);
  printf("yy_buffer_status = ");
  state = yy_buf_stack[yy_num_buf-1]->yy_buffer_status;
  switch (state) {
  case YY_BUFFER_NEW: printf("YY_BUFFER_NEW\n"); break;
  case YY_BUFFER_NORMAL: printf("YY_BUFFER_NORMAL\n"); break;
  case YY_BUFFER_EOF_PENDING: printf("YY_BUFFER_EOF_PENDING\n"); break;
  }
  printf("\n");
}

int is_space(char c)
{
  return ((c==' ')||(c=='\n')||(c=='\t'));
}

int continue_parse()
{
  int res=1;
  YY_BUFFER_STATE b;
  int not_only_spaces;
  char* buf_pos;

  b = yy_buf_stack[yy_num_buf-1];
  //  print_buf_info(b);

  buf_pos = b->yy_buf_pos;

  while (is_space(*buf_pos)) buf_pos++;
  not_only_spaces= ((*buf_pos)!='\0');

  if ((yy_num_buf)&&(not_only_spaces)) {
    res = yyipparse();
  }
  return res;
}

int yyip_parse()
{

  return yyipparse();
}

void init_gr_output()
{
  std::string filename(".improcess/improcess.gr");

  gr_output= FILE_ptr(fopen(filename.c_str(),"w"),file_deleter());

  if (!gr_output) {

    fprintf(stderr,"Error in opening %s\n",filename.c_str());
    FILE_ptr stdout_ptr(stdout);
    gr_output.swap(stdout_ptr);
  }
}
//void gr_print(char* st) { fprintf(gr_output,st); fflush(gr_output); }
void gr_print(const char* st) { }
//void () { fclose(gr_output); }


void init_err_output()
{
  //  char filename[100];

  err_output=&std::cerr;
  /*
  sprintf(filename,"improcess.err");
  err_output=fopen(filename,"w");
  if (!err_output) {
    fprintf(stderr,"Error in opening %s\n",filename);
    err_output=stderr;
  }
  */
}

void err_print(const char* st) {
  *(GB_main_wxFrame->GetConsole()->GetLog()) << wxString::FromAscii(st);
  string mess =  (format("Error %s \n") % st).str();
  wxMessageDialog* err_msg = new wxMessageDialog(NULL,GetwxStr(mess),GetwxStr("Error"),wxOK | wxICON_ERROR);
  err_msg->ShowModal();
}

void close_err_output(void)
{
 if (err_output!=&std::cerr) {}
 //fclose(err_output);
}

void init_res_output()
{
  //  char filename[100];

  res_output = &std::cout;
  /*
  sprintf(filename,"improcess.res");
  res_output=fopen(filename,"w");
  if (!res_output) {
    fprintf(stderr,"Error in opening %s\n",filename);
    err_output=stdout;
  }
  */
}
void res_print(const char* st) {
  *(GB_main_wxFrame->GetConsole()->GetLog()) << wxString::FromAscii(st);
  printf(st);
}

void close_res_output() {
if (res_output!=&std::cout) {}
 //  fclose(res_output);
}

#include <sys/types.h>
#include <sys/stat.h>
#ifndef WIN32
#include <unistd.h>
#endif

void init_cmdhistory()
{
  std::string dirname;
  std::string filename;
  struct stat file_stat;
  int res,isdir;
  int  i;

  if (GB_nofile) return;

  // write in a local directory called .improcess
  // check if directory .improcess exists, otherwise create it
  dirname = ".improcess";
  res=stat(dirname.c_str(),&file_stat);
 	#ifndef S_ISDIR
		#define S_ISDIR(a) (a & _S_IFDIR)
	#endif
  isdir=S_ISDIR(file_stat.st_mode);
  if (!isdir)
    std::system("mkdir .improcess");

  i = 0;
  format ws_filename_format(".improcess/cmdhistory%03d");
  filename = str( ws_filename_format % i);
#ifndef F_OK
#define F_OK 0
#endif
  TantQue access( filename.c_str(), F_OK) == 0 Faire
    i++;
    filename = str( ws_filename_format % i);
  FinTantQue

  cout << format("Opening %1% \n") % filename;
  cmdhistory=FILE_ptr(fopen(filename.c_str(),"w"),file_deleter());

  // change properties to allow execution
  #ifndef WIN32
  chmod(filename.c_str(),S_IRUSR|S_IXUSR|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH);
  #endif

  if (!cmdhistory) {
    cerr << format("Error in opening %s\n") % filename;
    FILE_ptr stdout_ptr = FILE_ptr(stdout);
    cmdhistory.swap(stdout_ptr);
  } else
    cmdhistory_filename = filename;
}


void ws_print(const char* st)
{
//printf("GB_nofile = %d \n",(int)GB_nofile);
  if (GB_nofile) return;
  fprintf(cmdhistory.get(),st);
  fflush(cmdhistory.get());
}

void close_cmdhistory()
{
  if (GB_nofile) return;
  if (cmdhistory.get()!=stdout) {
    cmdhistory.reset();
    // change properties to allow execution
    #ifndef WIN32
    chmod(cmdhistory_filename.c_str(),S_IRUSR|S_IXUSR|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH);
    #endif
  }
}


void example::Parser::error(const Parser::location_type& l,
          const std::string& m)
{
    driver.error(l, m);
}








