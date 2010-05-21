
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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

// Take the name prefix into account.
#define yylex   yyiplex

/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 11 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

 /*** C/C++ Declarations ***/
  //#include <stdlib.h>
  //#include <stdio.h>

// use NOMINMAX to avoid conflicts between windows.h min,max and std::min std::max ...
#define NOMINMAX

#include "driver.h"
#include "CoutwxString.h"
#include "MainFrame.h"
#include <locale.h>
#include "fonctions.h"
#include "func_isoline.hpp"

#include "ami_function.h"
#include "ami_class.h"
#include "ami_object.h"
#include "IdentifierInfo.h"

#include "localstats.h"
//#include "dist_squared.hpp"
#include "improcess_bison.tab.hpp"
#include "wrapAMIFluid.h"
#include "wrapVTK.h"
#include "wrapITK.h"
//#include "wrap_mainframe.h"
#include "wrap_imagedraw.h"
#include "itkCannyEdgeDetector.h"
#include "wrapWII.h"
#include "wrapFilters.h"
#include "wrapSystem.h"
#include <cstdlib>

//#include "myscan.h"
#include "ImageDraw.hpp"
#include "Func_ReadCTALine.h"
#include "LineRecons.h"
//#include "PruneLines.h"

#include "wrapfunction_class.h"


#ifndef __FLEX_LEXER_H
#define yyFlexLexer yyipFlexLexer
#include "FlexLexer.h"
#undef yyFlexLexer
#endif


#include "Viewer3D.hpp"

//#include "Erreurs.Main.hpp"
 // #include "Graphique.hpp"
#include "Viewer3D.hpp"
#include "DessinImage.hpp"
#include "CompareImage.hpp"
#include "bruit.hpp"
#include "CalculAireSection.hpp"
#include "reponse_cercle.hpp"
#include "func_shortestpath.h"
#include "Wrap_AnisoGS.h"
#include "LevelSetsCURVES.h"
#include "vtkwrap.h"

#include "gnuplot.hpp"

#include "xmtext.hpp"
#include "StringUtils.hpp"
//#include "histo.hpp"

#ifndef WIN32
#include <unistd.h>
#endif

#include <iostream>

#include "VarContexts.hpp"
#include "VarArray.h"
//#include "Duree.hpp"

#include "DefineClass.hpp"

#include "Variable.hpp"

/*
#include <boost/shared_ptr.hpp>
//--- string formatting using boost
#include <iostream>
#include <iomanip>
#include <cassert>
#include "boost/format.hpp"
namespace MyNS_ForOutput {
  using std::cout; using std::cerr;
  using std::string;
  using std::endl; using std::flush;

  using boost::format;
  using boost::io::group;
}
using namespace MyNS_ForOutput;
*/



//-------

#include "wx/evtloop.h"
#include "driver.h"

extern VarContexts       Vars;

//Duree            IP_time;

extern MainFrame*   GB_main_wxFrame;
extern wxApp*       GB_wxApp;
extern int          GB_argc;

extern int       GB_num_arg_parsed;
extern wxString  GB_scripts_dir;
extern wxString  GB_help_dir;


namespace AMIFluid {
extern char* FLUID_NAVIGATION_FILE;
}


DessinImage* CreateIDraw(  const std::string& title, InrImage::ptr image);
// Creation of a DessinImage pointer
// this function is distinct if compiling with all amilab

extern yyip::Driver GB_driver;

extern unsigned char        GB_debug;
extern unsigned char        GB_verbose;
extern unsigned char        verbose;
extern unsigned char        GB_nofile;

extern char program[80];

extern unsigned char DELETE_IDRAW;

//-------------------------------------------------------
class wxWaitTimer : public wxTimer
//    -----------
{
  public:
    bool finished;

    wxWaitTimer() : finished(false) {}
    //Called each time the timer's timeout expires
    void Notify()     { finished = true; }
};



//------------------------------------------------------
class wxScheduleTimer : public wxTimer
//    ---------------
{
  DEFINE_CLASS(wxScheduleTimer)
  public:
    wxScheduleTimer( Variable<AMIFunction>::ptr callback)
    {
      var = Variable<AMIFunction>::ptr(callback);
    }

    ~wxScheduleTimer()
    { 
      //cout << "~wxScheduleTimer()" << endl; 
    }

    //Called each time the timer's timeout expires
    void Notify();

  private:
    // variable of type type_ami_function
    Variable<AMIFunction>::ptr var;
};

// create a array of shared pointers
// to delete the wxScheduleTimer when necessary
static std::list<wxScheduleTimer::ptr> schedule_timers;

void CB_ParamWin( void* cd );


//static void ( void* cd, long unsigned int *) {
//  CB_ParamWin(cd);
//}

/*
static void CB_Button(  void* cd) {
  CB_ParamWin(cd);
}
*/

void CB_delete_variable( void* var);


//------------------------------------------------------
void CB_update_imagelist( void* imagelist_gui);


#define GET_VARSTACK_VALUE(type,newvar) \
  boost::shared_ptr<type> newvar( \
    driver.var_stack.GetLastVar<type>()->Pointer());

#define GET_VARSTACK_VAR_VAL(type,newvar, newval) \
  Variable<type>::ptr newvar(driver.var_stack.GetLastVar<type>()); \
  boost::shared_ptr<type> newval(newvar->Pointer());

#define ADD_VARSTACK_FLOAT(newval) \
    Variable<float>::ptr new_var(new Variable<float>(float_ptr(new float(newval)))); \
    driver.var_stack.AddVar(new_var);

/*! \def CHECK_VAR
    \brief Checks if the smart pointer really points to a variable, if not abort the current parsing
*/
#define CHECK_VAR(var) \
  if (!var.get()) {  \
    driver.yyiperror(" Empty variable in expression "); \
    YYABORT; }

/*! \def GET_CHECK_VARSTACK
    \brief Gets the last variable from the stack and 
        checks if the smart pointer really points to a variable, if not abort the current parsing
*/
#define GET_CHECK_VARSTACK(varname) \
  BasicVariable::ptr varname(driver.var_stack.GetLastBasicVar()); \
  if (!varname.get()) {  \
    driver.yyiperror(" Empty variable in expression "); \
    YYABORT; }

/**
  newval is a smart pointer to the new value to add
**/
#define ADD_VARSTACK_PTR(type,newval) \
    Variable<type>::ptr new_var(new Variable<type>(newval)); \
    driver.var_stack.AddVar(new_var);

#define UNARYOP_EXPR(operator,val,res)           \
  res=operator(val);






/* Line 311 of lalr1.cc  */
#line 294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace yyip {

/* Line 380 of lalr1.cc  */
#line 386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
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
#endif

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
        case 53: /* "ASTRING" */

/* Line 480 of lalr1.cc  */
#line 736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 56: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 474: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 477: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 478: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 484: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 511: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 518: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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

#if YYDEBUG
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
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 282 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
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

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 22:

/* Line 678 of lalr1.cc  */
#line 783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Repeats the block while the variable value is higher than 0.5
      **/
        int  previous_lineno=driver.yyiplineno;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(3) - (3)].ablock));
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
  
        float res;
        if (var->Type() == type_float) 
          res = *(boost::dynamic_pointer_cast<Variable<float> >(var))->Pointer();
        else
        if (var->Type() == type_int) 
          res = *(boost::dynamic_pointer_cast<Variable<int> >  (var))->Pointer();
        else
        if (var->Type() == type_uchar) 
          res = *(boost::dynamic_pointer_cast<Variable<unsigned char> >  (var))->Pointer();
        else {
          res = 0;
          driver.yyiperror(" while needs a numerical variable as condition \n");
        }
  
        while (res) {
  
          //driver.yyiplineno=previous_lineno;
          driver.yyiplineno = block->GetStartingLine();
          res=driver.parse_block(block);

          if (var->Type() == type_float) 
            res = *(boost::dynamic_pointer_cast<Variable<float> >(var))->Pointer();
          else
          if (var->Type() == type_int) 
            res = *(boost::dynamic_pointer_cast<Variable<int> >  (var))->Pointer();
          else
          if (var->Type() == type_uchar) 
            res = *(boost::dynamic_pointer_cast<Variable<unsigned char> >  (var))->Pointer();
          else {
            res = 0;
            driver.yyiperror(" while needs a numerical variable as condition \n");
          }
        } 
        driver.yyiplineno = previous_lineno;
      }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));

      GET_VARSTACK_VAR_VAL(AMIFunction, var, func);

      // delete previous variable
      std::string varname = var->Name();
      int context = Vars.GetContext(boost::static_pointer_cast<BasicVariable>(var));
      Vars.deleteVar(var);

      FILE_MESSAGE(boost::format("Redefining procedure %1%") % varname); 

      AMIFunction::ptr amifunc( new AMIFunction);

      amifunc->SetName(varname.c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);
      FILE_MESSAGE(boost::format("%1%: body = %2%")
                    % varname  % body->GetBody());

      // add the variable in the same context ...
      BasicVariable::ptr newvar =
        Vars.AddVar<AMIFunction>(
                      varname,
                      amifunc,
                      context);
      if (newvar.get())
        amifunc->SetContext(newvar->GetContext());

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 1052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(4) - (3)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (2)].ident));

      AMIClass::ptr amiclass( new AMIClass);

      amiclass->SetName(ident->GetName());
      amiclass->SetFileName(driver.current_file);
      amiclass->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", ident->GetName().c_str(),body->GetBody().c_str());

      Vars.AddVar<AMIClass>(ident, amiclass);

    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.yyip_instanciate_object(ac,amiobject.get());

      Vars.AddVar<AMIObject>(ident, amiobject);

    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Calls YYABORT to leave the current instruction block.
            See Also:
              repeat
          **/
           YYABORT;
         }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
         }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
         }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1254 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
         }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
         }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        // check counter of the value, not of the variable ...
        if (var.get()) {
          if (var->GetPtrCounter()==1) {
            //cout << "GetPtrCounter == 1" << endl;
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            Vars.AddVar(ident,var);
          } else
          {
            BasicVariable::ptr copy = var->NewCopy();
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            Vars.AddVar(ident,copy);
          }
        } else {
            driver.err_print("identifier = variable, no variable value");
        }
      }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        if (var->GetPtrCounter()==1) {
          IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));
          Vars.AddVar(ident,var);
        } else
        {
          if (var.get()) {
            BasicVariable::ptr copy = var->NewCopy();
            IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));
            copy->SetComments(comments.get());
            Vars.AddVar(ident,copy);
          } else {
            driver.err_print("identifier = variable, no variable value");
          }
        }
      }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/

          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());

          // first process exception cases
          if (var.get()) {
            if (var->Type()==type_class_member) {
                /// C++ wrapped member
                IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
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
                IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
                Vars.AddVar(ident,copy);
            }
          } else {
            driver.err_print("identifier = variable, no variable value");
            YYABORT;
          }
      }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
        if (size<1) size = 1;
        VarArray::ptr arraysurf(new VarArray());
        arraysurf->Init(type_surface,size);
        Vars.AddVar<VarArray>(ident,arraysurf);
      }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
        int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
        if (size<1) size = 1;
        VarArray::ptr arraysurf( new VarArray());
        arraysurf->Init(type_surface,size);
        Vars.AddVar<VarArray>(ident,arraysurf);
      }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            VarArray::ptr array(new VarArray());
            array->Init(type_image,size);
            Vars.AddVar<VarArray>(ident,array);
          }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1460 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr imptr(driver.im_stack.GetLastImage());
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
        }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray, vararray, array);

          InrImage::ptr imptr(driver.im_stack.GetLastImage());
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
      }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix::ptr imptr( 
            driver.gltransf_stack.GetLastMatrix());
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          if (imptr.get())
            Vars.AddVar<GLTransfMatrix>(ident,imptr);
          else
            driver.err_print("assignment of NULL matrix\n");
        }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray,vararray,array)

          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          SurfacePoly::ptr surfptr (driver.surf_stack.GetLastSurf());
          if (surfptr.get()) {
            if (!array->GetVar(i).get()) {
              sprintf(name,"%s[%d]",vararray->Name().c_str(),i);
              array->InitElement<SurfacePoly>(i,surfptr,name);
            }
            else
            {
              driver.err_print("array element already assigned\n");
            }
          }
          else
            driver.err_print("assignment of NULL surface\n");
        }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          // TODO: use smart pointers in surf_stack ...
          SurfacePoly::ptr surfptr (driver.surf_stack.GetLastSurf());

          if (surfptr != NULL)
            Vars.AddVar<SurfacePoly>(ident, surfptr);
          else
            driver.err_print("assignment of NULL surface\n");
        }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(SurfacePoly,var,val)

          SurfacePoly::ptr surfptr( driver.surf_stack.GetLastSurf());

          // instead of deleting and creating,
          // replace the pointer and the information
          if (surfptr.get()) {
            var->Delete();
            var->Init(var->Name().c_str(),
                      surfptr);
          }
          else
            driver.err_print("assignment of NULL surface\n");

        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray,var,array)
          int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
          if (size<1) size = 1;
          VarArray::ptr arraysurf( new VarArray());
          arraysurf->Init(type_surface,size);

          // instead of deleting and creating,
          // replace the pointer and the information
          if (arraysurf != NULL) {
            var->Delete();
            var->Init(var->Name().c_str(),
                      arraysurf);
          }
          else
            driver.err_print("not able to create surface array !\n");

      }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creates a variable of type int
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        int_ptr varint (new int((int)(yysemantic_stack_[(6) - (5)].adouble)));
        Vars.AddVar<int>(ident,varint);
      }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creates a variable of type unsigned char (used for boolean type too)
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
        uchar_ptr varuchar( new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble)));
        Vars.AddVar<unsigned char>(ident,varuchar);
      }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Adds a new link to a script from the menus
      Parameters:
        - string expression: category of the script
        - string expression: menu label
        - string expression: script name
   **/
          boost::shared_array<char> category( (yysemantic_stack_[(8) - (3)].astring));
          boost::shared_array<char> label(    (yysemantic_stack_[(8) - (5)].astring));
          boost::shared_array<char> script(   (yysemantic_stack_[(8) - (7)].astring));
          GB_main_wxFrame->AddMenuScript(category.get(),label.get(),script.get());
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameter:
        Number: percentage of the current process that has been processed.
      Description:
        Sets the Progress bar in the Main window to the given percentage (between 0 and 100).
    **/
          GB_main_wxFrame->SetProgress((int)((yysemantic_stack_[(4) - (3)].adouble)+0.5));
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameter:
        String: input text
      Description:
        Set the given text in the status bar
    **/
        boost::shared_array<char> text( (yysemantic_stack_[(4) - (3)].astring));
        GB_main_wxFrame->SetStatusText( text.get() );
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          std::string titre;
          GET_VARSTACK_VAR_VAL(InrImage, imagevar, im);
          Variable<DessinImage>::ptr var;
          int var_context = Vars.GetContext(imagevar);

          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // set new object context
            Vars.SetObjectContext(imagevar->GetContext());
          }

          if ((var_context>=0)||
              (var_context==OBJECT_CONTEXT_NUMBER)) {
            titre = (boost::format("%s_draw") % imagevar->Name().c_str()).str();
            FILE_MESSAGE(boost::format("SHOW var_image  title %s") % titre);
            //if (Vars.GetCurrentContext()->GetVar(titre,&var)) {
            var = boost::dynamic_pointer_cast<Variable<DessinImage> >(Vars.GetVar(titre.c_str(),var_context));
            if (var.get()) {
              DessinImageParametres* param;
              DessinImage::ptr di( var->Pointer());
              param = di->GetParam();
              param->_MAJ.MAJCoupes();
              di->Paint();
              di->Raise();
            }
            else
            {
              FILE_MESSAGE(boost::format("SHOW var_image creating title %s ") % titre);
              DessinImage::ptr di;

              std::string varname(titre);

              di = DessinImage::Create_ptr( CreateIDraw( varname,  im));

              BasicVariable::ptr newvar = 
                Vars.AddVar<DessinImage>(titre.c_str(), di, var_context);
              di->SetCloseFunction(
                (void*) CB_delete_variable,
                (void*) (newvar.get()));
            }
          } // var_context >=0

          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // Restore the object context
            Vars.SetObjectContext(previous_ocontext);
          }

        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im)
          string title;
          BasicVariable::ptr var;

          title = (boost::format("%s_draw") % varim->Name().c_str()).str();
          var = Vars.GetVar(title.c_str());
          if (var.get()) {
            if (var->Type() == type_imagedraw) {
                Variable<DessinImage>::ptr vard (boost::dynamic_pointer_cast<Variable<DessinImage> >(var));
                driver.err_print("Hide window \n");
                
                vard->Pointer()->Hide();
            }
            else
              fprintf(stderr,"Variable %s_draw not of type imagedraw \n",
                varim->Name().c_str());
          } else
            fprintf(stderr,"Image %s not visible \n",
          varim->Name().c_str());

        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(SurfacePoly,surfvar,surf)
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

        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Replacing the previous image by the new one.
        **/
          GET_VARSTACK_VAR_VAL(InrImage, var, i1);
          InrImage::ptr imptr  (driver.im_stack.GetLastImage());
          bool can_skip_allocation = false;

          if (imptr.get()) {
            if (i1.get()!=imptr.get()) {
              can_skip_allocation = (i1->GetFormat()==imptr->GetFormat());
              if (can_skip_allocation) {
                // first try the standard data copy
                can_skip_allocation = ((*i1)=(*imptr));
                if (can_skip_allocation) {
                  // copy additional information here
                  i1->SetTranslation(imptr->TrX(), imptr->TrY(), imptr->TrZ());
                  i1->SetVoxelSize( imptr->VoxSizeX(), 
                                    imptr->VoxSizeY(),
                                    imptr->VoxSizeZ());
                }
              }
              if (!can_skip_allocation) {
                // instead of deleting and creating,
                // replace the pointer and the information
                  var->Delete();
                  // should be OK
                  var->Init( var->Name().c_str(), imptr);
              } // end if (!can_skip_allocation)
            } // end if (i1.get()!=imptr)
          }
          else
            driver.err_print("assignment of NULL image\n");
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 2039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 2129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Pads the image ...
        **/
          GET_VARSTACK_VALUE(InrImage, i1);
          int posx  = (int) (yysemantic_stack_[(16) - (3)].adouble);
          int stepx = (int) (yysemantic_stack_[(16) - (5)].adouble);
          int posy  = (int) (yysemantic_stack_[(16) - (7)].adouble);
          int stepy = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int posz  = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int stepz = (int) (yysemantic_stack_[(16) - (13)].adouble);

          InrImage::ptr i2 (driver.im_stack.GetLastImage());

          Func_Pad(i1.get(),i2.get(),stepx,posx,stepy,posy,stepz,posz);


        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 2162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer())++;
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 2166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer())--;
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 2170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 2174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())  = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 2178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())++;
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 2182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())--;
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 2194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 2198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 2210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 2224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete all variables that match the expression, where the expression can contain 
            '*' and '?' characters
        **/
        boost::shared_array<char> varmatch( (yysemantic_stack_[(2) - (2)].astring));
         Vars.deleteVars( varmatch.get());
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 2234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<VarArray>::ptr vararray(driver.var_stack.GetLastVar<VarArray>());
          VarArray::ptr array (vararray->Pointer());
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).get()) {
            array->GetVar(i) = BasicVariable::ptr();
          }
      }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - string expression: command to call
        Description:
          calls a command from the system using std::system()
      **/
        boost::shared_array<char> cmd( (yysemantic_stack_[(2) - (2)].astring));
        std::system( cmd.get());
      }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Calls system 'ls' command (for unix systems)
      **/
         std::system("ls");
           }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 2263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
     }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_imagefunction, func);
      // call with NULL paramlist pointer to trigger help message
      (*func)(NULL);
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_varfunction, func);
      // call with NULL paramlist pointer to trigger help message
      (*func)(NULL);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_procedure, proc);
      // call with NULL paramlist pointer to trigger help message
      (*proc)(NULL);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
      GET_VARSTACK_VALUE(WrapClassMember, m);
      m->ShowHelp();
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s",text.get());
          fflush(file.get());
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s\n",text.get());
          fflush(file.get());
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Parameters:
            string expression: information text
          Description:
            Popup an Information Dialog with the given message
          **/
          driver.info_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
      }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = DessinImage::ptr(varimd->Pointer());
          param = draw->GetParam();
          param->_pos._x = (int) (yysemantic_stack_[(10) - (5)].adouble);
          param->_pos._y = (int) (yysemantic_stack_[(10) - (7)].adouble);
          param->_pos._z = (int) (yysemantic_stack_[(10) - (9)].adouble);
          //      param->_pos.Check();
          param->_MAJ.MAJCoupes();

          draw->Paint();

        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 2746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = DessinImage::ptr(varimd->Pointer());
          param = draw->GetParam();
          param->_curseur._visible = (int) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);
          //      param->_MAJ.MAJCoupes();

          draw->Paint();
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 2759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = DessinImage::ptr(varimd->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 2770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage,    varim,  im);
          GET_VARSTACK_VAR_VAL(DessinImage, varimd, draw);
          char title[255];

            sprintf(title,"%s_draw",varim->Name().c_str());

            BasicVariable::ptr var = Vars.GetCurrentContext()->GetVar(title);
            if (var.get()) {
              Variable<DessinImage>::ptr vardi ( boost::dynamic_pointer_cast<Variable<DessinImage> >(var));
              DessinImage::ptr di(vardi->Pointer());
              DessinImageParametres* param;
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
              std::string varname(title);
              DessinImage::ptr di = 
                DessinImage::Create_ptr(CreateIDraw( varname, im));

              Variable<DessinImage>::ptr newvar = Vars.AddVar<DessinImage>(title, di);

              di->SetCloseFunction(
                  (void*) CB_delete_variable,
                  (void*) (newvar.get()));
              // get the pointer to the newly created
              // variable
              //BasicVariable::ptr var = Vars.GetVar(title);
              if (var.get())
                draw->CreeCompare2Image(newvar->Pointer());
              else
                fprintf(stderr,"Image comparison: Variable %s not found !\n",title);
            }

        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw1);

          draw1->CreeCompare2Image(draw2);
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 2823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage,    displ);
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw);

          // TODO: check for SetCompareDisplacement, does it really work?
          draw->SetCompareDisplacement(draw2,displ);
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 2846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
        driver.yyiperror( "SetCompTransf is not available at the moment");
/*
        DessinImage::ptr draw;
        FloatMatrix* mat;

        draw = *(DessinImage::ptr*) ($1->Pointer());

        mat = new FloatMatrix(4,4);
        (*mat)[0][0] = $5;
        (*mat)[0][1] = $7;
        (*mat)[0][2] = $9;
        (*mat)[0][3] = $11;
        (*mat)[1][0] = $13;
        (*mat)[1][1] = $15;
        (*mat)[1][2] = $17;
        (*mat)[1][3] = $19;
        (*mat)[2][0] = $21;
        (*mat)[2][1] = $23;
        (*mat)[2][2] = $25;
        (*mat)[2][3] = $27;

            if (draw->GetCompareWindow(0)!=NULL)
          draw->GetCompareWindow(0)->SetTransformationMatrix(mat);
        // PB: the matrix is never freed from memory ...
        // TODO use smart pointer management !!!
*/
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 2877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Parameters:
                (1) Image Drawing window
                (5) Index of the vector field to be drawned (between 1 and 3)
                (7) Vector field image
            Description:
                Assign a vector field to be draw in the given image drawing window.
          **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->LoadVectImage( (int) (yysemantic_stack_[(8) - (5)].adouble), im);
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 2892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 2908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
            (5) expression: vector size
            (7) expression: vector spacing

          Description:
            Sets the size and spacing of the vector drawing interface in the given
            image drawing window.
          **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          float size    = (yysemantic_stack_[(8) - (5)].adouble);
          int   spacing = (int)(yysemantic_stack_[(8) - (7)].adouble);

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectParam( size, spacing);
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 2927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          int vectid = (int) (yysemantic_stack_[(12) - (5)].adouble);
          unsigned char red   = (unsigned char) (yysemantic_stack_[(12) - (7)].adouble);
          unsigned char green = (unsigned char) (yysemantic_stack_[(12) - (9)].adouble);
          unsigned char blue  = (unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectColor( vectid,red,green,blue);
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 2951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 2957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 2963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          int xmin = (int)  (yysemantic_stack_[(16) - (5)].adouble);
          int ymin = (int)  (yysemantic_stack_[(16) - (7)].adouble);
          int zmin = (int)  (yysemantic_stack_[(16) - (9)].adouble);
          int xmax = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int ymax = (int) (yysemantic_stack_[(16) - (13)].adouble);
          int zmax = (int) (yysemantic_stack_[(16) - (15)].adouble);

          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetZoom(xmin,ymin,zmin,xmax,ymax,zmax);

        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 2977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 2989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          ClasseCouleur c;

          draw = DessinImage::ptr(varimd->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 2999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Set a user-defined colormap.
         **/
          GET_VARSTACK_VALUE(DessinImage, draw);
          InrImage::ptr colmap(driver.im_stack.GetLastImage());

          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 3009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,    surfd);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetGLWindow(surfd);
        }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 3016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) image to use for the isocontour
                (9) intensity value of the isocontour

            Description:
                Sets the image and intensity value of an isocontour in an 'image_draw' window.
            **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->InitIsoContour( im, (yysemantic_stack_[(10) - (9)].adouble) , (int) (yysemantic_stack_[(10) - (5)].adouble) );
          draw->DrawIsoContour( (int) (yysemantic_stack_[(10) - (5)].adouble), true );
        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 3033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) image to use for the isocontour
                (7) intensity value of the isocontour

            Description:
                Sets the image and intensity value of the isocontour number 0 in an 'image_draw' window.
            **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->InitIsoContour( im, (yysemantic_stack_[(8) - (7)].adouble) , 0 );
          draw->DrawIsoContour( 0, true );
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetIsoContourParam( (int)(yysemantic_stack_[(10) - (5)].adouble), (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble) );
        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 3067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetIsoContourParam( (int)(yysemantic_stack_[(14) - (5)].adouble), (int)(yysemantic_stack_[(14) - (7)].adouble), (int)(yysemantic_stack_[(14) - (9)].adouble) );
          draw->SetLineAttributes( (int)(yysemantic_stack_[(14) - (11)].adouble), (int)(yysemantic_stack_[(14) - (13)].adouble));
        }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 3088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) visible or not (0 or 1)

            Description:
                Sets the visibility of an isocontour in an 'image_draw' window.
            **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->DrawIsoContour( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 3104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetIsoContourColor( (int) (yysemantic_stack_[(12) - (5)].adouble), (unsigned char) (yysemantic_stack_[(12) - (7)].adouble),
                                              (unsigned char) (yysemantic_stack_[(12) - (9)].adouble),
                                              (unsigned char) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 3123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) boolean parameter

            Description:
                Activates or desactivates the drawing of a series of isocontours.
            **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetDrawAllContours( (int) (yysemantic_stack_[(6) - (5)].adouble) );
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 3137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) intensity step between isocontours
                (7) half size of the intensity range where to draw isocontours

            Description:
                Parameters for drawing a series of isocontours around the main isocontour.
            **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          draw = DessinImage::ptr(varimd->Pointer());
          draw->AllContoursParam(  (yysemantic_stack_[(8) - (5)].adouble) , (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 3152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(AMIFunction, func);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetPaintCallback( (void*) CB_ParamWin, 
                                  (void*) func.get() );
          // may be a pb to call Paint() here since it will start another interpreter ??? to check
          //draw->Paint();
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Description:
            Setting the opacity image for the volume rendering.
            This image should have unsigned char values.
         **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, imdraw);

          imdraw->SetVolRenOpacity( im.get());
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 3174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 3196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 3220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(SurfacePoly,var,s);
    
          std::string tmp_string;
          tmp_string = (boost::format(" %s: %d points %d lines %d polygons  \n")
            % var->Name()
            % s->GetNumberOfPoints()
            % s->GetNumberOfLines()
            % s->GetNumberOfPolys ()
            ).str();
          driver.res_print(tmp_string);
          tmp_string = (boost::format(" limits X:[%4.2f %4.2f] Y:[%4.2f %4.2f]  Z:[%4.2f %4.2f]  \n")
            % s->_xmin % s->_xmax
            % s->_ymin % s->_ymax
            % s->_zmin % s->_zmax).str();
          driver.res_print(tmp_string);
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 3260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  value to init the image

        Description:
          Set the whole image to the same vector value .
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          (im)->InitImage((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 3272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 3286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 3305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 3327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 3358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 3417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 3614 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 3871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 3899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Normalizes a vector field given by a vectorial image.

        Example(s):
          v1.normalize

        **/
      GET_VARSTACK_VALUE(InrImage, im);
      Func_Normalize((im.get()));
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 3913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 3920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 3926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->Write(filename.get());
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 3934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (1) input polydata
        (4) filename
    Description:
        Save the first line of the polydata in text format
    **/
      boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
      GET_VARSTACK_VALUE(SurfacePoly, surf);
      Func_WriteCTALine(surf.get(),filename.get());

    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 3948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 3955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 4015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (1) surface object
        (5) alpha value
    
      Description:
        to define the transparency to the RGB color
        associated per each vertex (actived with Enable ColorMaterial)
      **/

      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetColorOpacity((yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 4032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);

      int n;
      Pour(n,0,s->NbPoints()-1)
        (*s)[n].SetColor((unsigned char) (yysemantic_stack_[(10) - (5)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (7)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (9)].adouble));
      FinPour

      s->SetColorMaterial(true);
      s->GLRecomputeList(  );

    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 4047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,    im);
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetPointsColors( im.get() );

    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 4055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 4063 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 4071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Statistics( im.get() );

    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 4079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 4085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Triangulate();
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 4091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr surf (surfdraw->Pointer());

      float        depth = (yysemantic_stack_[(6) - (5)].adouble);
      std::string  name;
      int          n;

      // param 1: depth (neighborhood)
      //

      // Create images for the curvatures and their directions
      InrImage::ptr Icmin;
      InrImage::ptr Icmax;
      InrImage::ptr Idmin;
      InrImage::ptr Idmax;

      n = surf->GetNumberOfPoints();

      Icmin = InrImage::ptr(new InrImage(n,1,1,WT_FLOAT,"mincurv.ami.gz"));
      Icmax = InrImage::ptr(new InrImage(n,1,1,WT_FLOAT,"maxcurv.ami.gz"));

      Idmin = InrImage::ptr(new InrImage(n,1,1,3,WT_FLOAT,"mincurvdir.ami.gz"));
      Idmax = InrImage::ptr(new InrImage(n,1,1,3,WT_FLOAT,"maxcurvdir.ami.gz"));

      surf->ComputeCurvatures(Icmin.get(),Icmax.get(),
                              Idmin.get(),Idmax.get(), 
                              (int) depth);

      BasicVariable::ptr var;

      name = (boost::format("%s_cmin") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Icmin);

      name = (boost::format("%s_cmax") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Icmax);

      name = (boost::format("%s_dmin") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Idmin);

      name = (boost::format("%s_dmax") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Idmax);

    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 4137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 4145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 4153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 4161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

      Si w<1  AlorsFait w=1;
      Si w>10 AlorsFait w=10;

      s->_line_width = w;

    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 4173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
      s->GLRecomputeList();

    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression
      Description:
        Select lines based on an image
        The image is 1D of size the number of lines
        if the value is > 0.5, then select the corresponding line
    **/

      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr im (driver.im_stack.GetLastImage());

      s->SelectLines(im.get());
      s->GLRecomputeList();
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->RemoveSelection();
      s->GLRecomputeList();
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 4211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->GLRecomputeList();

    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 4218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->RecomputeNormals();

    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 4225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->InvertNormals();

    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 4233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 4242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      SurfacePoly* surf;

      surf = Func_decimate(s.get());
      Si surf != NULL Alors

        // Non correct: supprimer la variable et la re-creer:
        // car pb si la variable est deja utilisee ...
        //          $1->Init(type_surface,$1->Name(), surf);
        //      delete surf_init;
      Sinon
        fprintf(stderr,"improcess.y: var_surface.T_vtkDecimate \t error \n ");
          FinSi


      }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 4271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets a threshold for drawing connected components
          bigger.
        **/
          Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
          SurfacePoly::ptr s (surfdraw->Pointer());
          GLuint _SURFACE;

          Si Non(s->_cc_calculees) Alors
            s->CalculCC();
          FinSi
          s->GLSurfaceMinThCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 4288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Draw one connected component only
        **/
          Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
          SurfacePoly::ptr s (surfdraw->Pointer());
          GLuint _SURFACE;

            //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceDrawOnlyCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));
            //          FinSi

        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 4306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Activate/Desactivate Drawing of one connected components
        **/
          Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
          SurfacePoly::ptr s (surfdraw->Pointer());
          GLuint _SURFACE;

      //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceSetDrawCC( _SURFACE, (int) (yysemantic_stack_[(8) - (5)].adouble),(int) (yysemantic_stack_[(8) - (7)].adouble));
        //          FinSi

    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 4324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 4330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->NewLine();
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 4342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->EndLine();
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 4348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 4357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage,di);
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

      }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 4457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
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

      Parameters:
      (1) input surface
      (5) input image

      Example(s):
        s = CreateFlatMesh(i)
        ipos = Altitude2Postion(i,1)
        s.ElevateMesh(ipos)

      See also:
        CreateFlatMesh, ElevateMesh
        changes the position of the nodes of a 3D mesh

      **/
          GET_VARSTACK_VALUE(SurfacePoly,s);
          InrImage::ptr im ( driver.im_stack.GetLastImage());
          AMIFluid::Func_ElevateMesh(s.get(),im.get());
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 4490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 4497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 4505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 4513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 4521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint(false);
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 4532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw(varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 4542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 4550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 4569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 4590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(16) - (5)].adouble);
          InrImage::ptr im ( driver.im_stack.GetLastImage());
          int orientation = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int pos = (int) (yysemantic_stack_[(16) - (11)].adouble);
          float Imin = (yysemantic_stack_[(16) - (13)].adouble);
          float Imax = (yysemantic_stack_[(16) - (15)].adouble);

          draw->GetCanvas()->ShowFreeSection(num,im.get(),orientation,pos,Imin,Imax);

        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 4604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 4613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 4618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 4627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 4636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->Paint();
          sdraw->Update();
          //sdraw->Raise();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 4649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 4662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 4675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 4695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 4705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->Center();
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 4715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 4729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 4737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 4771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensorHessian(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 4797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());
          int save_grad = (int) (yysemantic_stack_[(12) - (11)].adouble);

          Func_StructureTensorHessian(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask.get(), save_grad);
        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 4825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 4836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 4879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 4930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage,varim,im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());

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
        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 4948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          Func_HessianVap(im.get(),
              varim->Name().c_str(),
              (yysemantic_stack_[(12) - (5)].adouble),   // sigma
              (yysemantic_stack_[(12) - (7)].adouble),   // gamma
              mask.get(),
              (int) (yysemantic_stack_[(12) - (11)].adouble) // eigenvalue number
              );
        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 4962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 4973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim6( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

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
        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 4999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 5025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_Eigen2D(
               (char*) (yysemantic_stack_[(12) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               mask.get()  // mask
               );
        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 5044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 5058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 5064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 5070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 5081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 5087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 5095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 5110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
                varim1->Pointer().get(),
                varim2->Pointer().get(),
                varim3->Pointer().get());
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 5163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr   image (driver.im_stack.GetLastImage());
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
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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


        }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 5278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 5309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 5325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 5416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 5446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          ParamList* pl = new ParamList();
          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 5493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());

          ParamList* pl = new ParamList();

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          ParamList* pl =  (yysemantic_stack_[(4) - (1)].paramlist);

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: it is now a new reference to the variable, so basically similar to &variable (should be removed?)...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          ParamList* pl(new ParamList);
          BasicVariable::ptr newvar(var->NewCopy());
          newvar->Rename("Param0");
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: it is now a new reference to the variable, so basically similar to &variable (should be removed?)...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          BasicVariable::ptr newvar(var->NewCopy());
          newvar->Rename(paramname.c_str());
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 5558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 5565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 5572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 5586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 5607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 5628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 5636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 5641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 5722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 5745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 5751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 5783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 5816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 5830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ADD_VARSTACK_FLOAT((yysemantic_stack_[(1) - (1)].adouble))
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 5834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      ADD_VARSTACK_FLOAT(GB_argc-GB_num_arg_parsed)
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 5842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      ADD_VARSTACK_FLOAT(driver.yyiplineno)
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 5850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      ADD_VARSTACK_FLOAT(3.14159265358979323846)
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 5859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description: adds a reference to the variable in the stack
      **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      driver.var_stack.AddVar(var->NewReference());
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 5867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Temporary solution: convert int variable to float variable
      **/
      GET_VARSTACK_VALUE(int,n);
      ADD_VARSTACK_FLOAT((double) *n.get())
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 5876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Temporary solution: convert unsigned char variable to float variable
      **/
      GET_VARSTACK_VALUE(unsigned char,n);
      ADD_VARSTACK_FLOAT((double) *n.get())
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 5885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 5902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 5918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 5954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 5972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 5988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 6004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 6010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 6016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 6022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 6028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 6034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 6040 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 6046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 6052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 6058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->GetVDim();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 6064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->IncBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 6070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->ValeurBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 6077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfPoints();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 6084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfPolys();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 6091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      float val=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_eccentricity(im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 6107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 6138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_ComputePositiveArea( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 6146 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      float res=Func_PositiveArea(val);
      ADD_VARSTACK_FLOAT(res);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 6158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_count( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 6178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_mean( im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_max( im.get(),NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_argmax( im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_min( im.get(),NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 6258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_med( im.get(),0.5,NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      InrImage::ptr mask  (driver.im_stack.GetLastImage());
      float val=Func_max( im.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask  (driver.im_stack.GetLastImage());
      float val=Func_min( im.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask ( driver.im_stack.GetLastImage());
      float val=Func_med( im.get(),0.5,mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr mask( driver.im_stack.GetLastImage());
      float val=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr input  (driver.im_stack.GetLastImage());
      InrImage::ptr mask  (driver.im_stack.GetLastImage());
      float val=Func_mean( input.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr mask (driver.im_stack.GetLastImage());
      float val=Func_mean( im.get(), mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      setlocale(LC_NUMERIC, "C");
      float val=atof((yysemantic_stack_[(4) - (3)].astring));
      ADD_VARSTACK_FLOAT(val);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._xmin;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._xmax;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._ymin;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._ymax;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._zmin;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 6473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._zmax;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;
      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_pos._x;
      ADD_VARSTACK_FLOAT(val);
      comment = str(format(" //  xpos=%3d") % param->_pos._x);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_pos._y;
      ADD_VARSTACK_FLOAT(val);

      comment = str( format(" //  ypos=%3d") % param->_pos._y);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                       ->IncCommand(wxString::FromAscii(comment.c_str()));

    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_pos._z;
      ADD_VARSTACK_FLOAT(val);

      comment = str( format(" //  xpos=%3d") % param->_pos._z);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
      float val = (*mat)[i][j];
      // create a reference with a smart pointer without deleter ???
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (3)].ident));
      float val=0;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      float val=1;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returns the value of the pixel format type in float format
      **/
      float val = (int) (yysemantic_stack_[(3) - (1)].aint);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(float,val_ptr);
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
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata
      Description: 
        Returns the number of lines of the polydata structure
    **/
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfLines(  );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var->Type()==type_image)  {
            DYNAMIC_CAST_VARIABLE(InrImage,var,varim) 
            driver.im_stack.AddImage(varim->Pointer());
          } else {
            driver.err_print("Expecting an image variable here ... \n");
            YYABORT;
          }
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 6757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 6761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 6765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 6769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 6773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 6777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 6781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 6785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 6789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 6799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 6818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

       Example(s):
          i = ReadRawImages(1024,1024,USHORT,0,"AfGG.%d",48,48)
       **/
      InrImage::ptr im (new InrImage());
      boost::shared_ptr<amimage> amim(new amimage());
      int dimx                    = (int)           (yysemantic_stack_[(16) - (3)].adouble);
      int dimy                    = (int)           (yysemantic_stack_[(16) - (5)].adouble);
      WORDTYPE inr_format         = (WORDTYPE)    (int)  (yysemantic_stack_[(16) - (7)].adouble);
      int endianness              = (int)           (yysemantic_stack_[(16) - (9)].adouble);
      boost::shared_array<char> file_format( (yysemantic_stack_[(16) - (11)].astring));
      unsigned short first_slice  = (unsigned short)(yysemantic_stack_[(16) - (13)].adouble);
      unsigned short last_slice   = (unsigned short)(yysemantic_stack_[(16) - (15)].adouble);

         amim->SetDim(dimx,dimy,1);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

         im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format.get();
     amim->first_slice = first_slice;
     amim->last_slice  =  last_slice;

     if (amim->readdata_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage(InrImage::ptr());
     }
      }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 6888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

       Example(s):
          i = ReadRawImages(256,256,256,USHORT,0,"data.raw")
       **/
      InrImage::ptr im ( new InrImage());
      boost::shared_ptr<amimage> amim(new amimage());
      int dimx                    = (int)           (yysemantic_stack_[(14) - (3)].adouble);
      int dimy                    = (int)           (yysemantic_stack_[(14) - (5)].adouble);
      int dimz                    = (int)           (yysemantic_stack_[(14) - (7)].adouble);
      WORDTYPE inr_format         = (WORDTYPE)   (int)   (yysemantic_stack_[(14) - (9)].adouble);
      int endianness              = (int)           (yysemantic_stack_[(14) - (11)].adouble);
      boost::shared_array<char> file_format( (yysemantic_stack_[(14) - (13)].astring));

         amim->SetDim(dimx,dimy,dimz);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

     im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format.get();

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage(InrImage::ptr());
     }
       }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 6939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

       Example(s):
          i = ReadRawImages(256,256,256,FLOAT,3,0,"3dvectorfielddata.raw")
       **/
      InrImage::ptr im  = InrImage::ptr(new InrImage());
      boost::shared_ptr<amimage> amim(new amimage());
      int dimx                    = (int)           (yysemantic_stack_[(16) - (3)].adouble);
      int dimy                    = (int)           (yysemantic_stack_[(16) - (5)].adouble);
      int dimz                    = (int)           (yysemantic_stack_[(16) - (7)].adouble);
      WORDTYPE inr_format         = (WORDTYPE)     (int) (yysemantic_stack_[(16) - (9)].adouble);
      int vdim                    = (int)           (yysemantic_stack_[(16) - (11)].adouble);
      int endianness              = (int)           (yysemantic_stack_[(16) - (13)].adouble);
      boost::shared_array<char> file_format( (yysemantic_stack_[(16) - (15)].astring));

     amim->SetDim(dimx,dimy,dimz);
     amim->SetVDim(vdim);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

     im->AMIFromWT(vdim,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format.get();

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage(InrImage::ptr());
     }
       }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 6991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
      }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 7011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
      }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 7046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskImage(name);
          if (!res) {
            driver.yyiperror(" Need Image \n");
            YYABORT;
          }
          driver.im_stack.AddFileImage((char*)name.c_str());


          wxFileName filename(GetwxStr(name));
          filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
          wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                              filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                              filename.GetPathSeparator(wxPATH_UNIX)+
                              filename.GetFullName());
          driver.res_print(newname.mb_str());
          driver.res_print("\n");
          inc_cmd = str(format(" \"%1%\" // from browser ") % newname.mb_str());

          if (driver.InConsole())
            GB_main_wxFrame->GetConsole()
                            ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 7075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        driver.im_stack.AddImage(im);
      }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 7082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(im);
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 7100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(im);
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 7125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returning a reference to the image here ...
      **/
      GET_VARSTACK_VAR_VAL(InrImage,var,im);


/*
      // do we need a copy here ???
      // Yes, we need a copy until we know that the operators, methods, etc.. cannot change the value of the variable !!!
      std::string imname = (boost::format("copy_%s") % var->Name().c_str()).str();
      InrImage::ptr imcopy (new InrImage(im->GetFormat(),im->GetVDim(),imname.c_str(),im.get()));
      (*imcopy)=(*im);
      driver.im_stack.AddImage(imcopy);
*/
      // returning reference here since the smart pointers will take care of everything (hopefully :) !!!)
      // and we can't return a copy here otherwise a=b won't work !!!
      driver.im_stack.AddImage(im);
/*
      GET_VARSTACK_VAR_VAL(InrImage,var,varim);
      InrImage::ptr im;
      std::string  imname;

      driver.im_stack.AddImage(im);
      // driver.im_stack.AddImage(varim);
*/
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 7154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
        Description:
          Applied on RGB or vectorial images,
          returns one component of the image:
          expr=0 returns Red   if RGB or the X coordinate if vectorial
          expr=1 returns Green if RGB or the Y coordinate if vectorial
          expr=2 returns Blue  if RGB or the Z coordinate if vectorial

        Example(s):
          i = Image "test.jpg"
          ired   = i[0]
          igreen = i[1]
          iblue  = i[2]

          print ired(i.tx/2,i.ty/2); print "\n"
          print i(i.tx/2,i.ty/2,0,0); print "\n"
       **/
        GET_VARSTACK_VAR_VAL(InrImage,var,im1);
        InrImage::ptr im;
        char  imname[200];
        int i;


        i = (int) (yysemantic_stack_[(4) - (3)].adouble);
        Si i<0               AlorsFait i = 0;
        Si i>=im1->GetVDim() AlorsFait i = im1->GetVDim()-1;
        sprintf(imname,"C%d_%s",i,var->Name().c_str());

         switch ( im1->_format ){
          case WT_RGB:
          case WT_RGBA:
             im = InrImage::ptr(new InrImage(WT_UNSIGNED_CHAR,1,imname,im1.get()));
          break;
          case WT_FLOAT_VECTOR:
             im = InrImage::ptr(new InrImage(WT_FLOAT,1,imname,im1.get()));
          break;

          case WT_UNSIGNED_CHAR:
          case WT_UNSIGNED_INT:
          case WT_SIGNED_INT:
          case WT_UNSIGNED_SHORT:
          case WT_SIGNED_SHORT:
          case WT_FLOAT:
          case WT_DOUBLE:
             im = InrImage::ptr(new InrImage(im1->_format,1,imname,im1.get()));
          break;

          default:
            driver.yyiperror(" operator [] does not handle this format \n");
            YYABORT;
          }
          im->InitBuffer();
          im1->InitBuffer();
          Repeter
            im->FixeValeur(im1->VectValeurBuffer(i));
                im1->IncBuffer();
          JusquA Non(im->IncBuffer()) FinRepeter
          driver.im_stack.AddImage(im);

       }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 7217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          InrImage::ptr im ( driver.im_stack.GetLastImage());
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
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 7283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 7290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 7297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean    ( driver.im_stack.GetLastImage());
      InrImage::ptr im      ( driver.im_stack.GetLastImage());
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 7305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean  ( driver.im_stack.GetLastImage());
      InrImage::ptr im    ( driver.im_stack.GetLastImage());
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 7313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res (Func_OpImage(im.get(),
                NULL,
                NULL,
                (yysemantic_stack_[(6) - (5)].astring)));
      Si (!res.get()) Alors
        driver.err_print("OpImage() erreur ... \n");
      FinSi
  
      driver.im_stack.AddImage(res);

      }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 7329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

    driver.im_stack.AddImage(res);


      }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 7347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

    driver.im_stack.AddImage(res);

      }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 7365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

    driver.im_stack.AddImage(res);

      }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 7382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
      }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 7400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        driver.im_stack.AddImage(res);
      }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 7420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im (driver.im_stack.GetLastImage());

        InrImage::ptr res( Func_Filter( im.get(),
                  (yysemantic_stack_[(12) - (5)].adouble),
                  (int) (yysemantic_stack_[(12) - (7)].adouble),
                  (int) (yysemantic_stack_[(12) - (9)].adouble),
                  (int) (yysemantic_stack_[(12) - (11)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("Filter() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 7453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float var           = (yysemantic_stack_[(10) - (7)].adouble);
        float lowthreshold  = (yysemantic_stack_[(10) - (9)].adouble);
        //float highthreshold = $11;
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_itkCannyEdgeDetector(  im.get(), var, lowthreshold));
        Si (!res.get()) Alors
          driver.err_print("itk.CannyEdgeDetector() error ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 7466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 7477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res (Func_vtkMedianFilter3D(
            im.get(),
            (int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("vtkMedian3D() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 7490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          driver.im_stack.AddImage(res);
        FinSi
*/
      }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 7514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res (Func_2DFlux( driver.im_stack.GetLastImage().get(),(yysemantic_stack_[(6) - (5)].adouble)));

    Si (res.get()) Alors
      driver.err_print("2DFlux() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 7524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 7535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 7545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 7555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 7588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 7600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        driver.im_stack.AddImage(res);
      }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 7621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);
      }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 7641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        driver.im_stack.AddImage(res);
      }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 7682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);
      }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 7728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

    driver.im_stack.AddImage(res);
      }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 7748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 7769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 7780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res( Func_NormalSmoothField( 
                    varim1->Pointer().get() , 
                    varim2->Pointer().get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 7794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res( Func_DirConnectivity( 
        varim1->Pointer().get() ,
        varim2->Pointer().get() ));

    Si res.get() Alors
      driver.err_print("DirConnectivity() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 7810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr input ( driver.im_stack.GetLastImage());

    InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
    Si (!res.get()) Alors
      driver.err_print("NormGrad() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 7822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 7833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 7845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_Gradient( im.get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 7856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 7876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 7888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_SecDerGrad2( im.get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 7898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im ( driver.im_stack.GetLastImage());
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        driver.im_stack.AddImage(res);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 7905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(4) - (3)].imageextent);
  
      //extent->print();
      extent->SetRelative(im.get());
  
      //extent->print();
      //cout << "xmax = " << (int)  extent->Xmax() << endl;
      //cout << "xmax = " << (int)  round((double)extent->Xmax()) << endl;
      InrImage::ptr res ( Func_SubImage( im.get(),
                  (int)  round((double)extent->Xmin()),
                  (int)  round((double)extent->Ymin()),
                  (int)  round((double)extent->Zmin()),
                  (int)  round((double)extent->Xmax()),
                  (int)  round((double)extent->Ymax()),
                  (int)  round((double)extent->Zmax())
                  ));
      delete extent;
      Si !res.get() Alors
        fprintf(stderr,"SubImage() erreur ... \n");
      FinSi
        driver.im_stack.AddImage(res);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 7934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);

      InrImage::ptr res (Func_SubImage( im.get(),
                  0, 0,  (int) round((yysemantic_stack_[(10) - (7)].adouble)),
                  im->DimX()-1,  im->DimY()-1, (int) round((yysemantic_stack_[(10) - (9)].adouble))));
        if (!res.get()) {
          fprintf(stderr,"SubImage() erreur ... \n");
        }
      driver.im_stack.AddImage(res);
      }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 7950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 7988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(),
                   (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 7999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 8009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si (!res.get()) Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 8021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(),
                  (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 8032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 8042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 8069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 8092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 8120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
    InrImage::ptr res ( Func_EDP_close( im.get(),
                   (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 8133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_close( im.get(),
                   (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 8267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 8302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);

    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 8335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);

    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 8363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_InitWeickert( im.get(),
                (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 8377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_InitWeickertCoherence( im.get(),
                (yysemantic_stack_[(16) - (7)].adouble),  (yysemantic_stack_[(16) - (9)].adouble), (yysemantic_stack_[(16) - (11)].adouble), (yysemantic_stack_[(16) - (13)].adouble), (yysemantic_stack_[(16) - (15)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 8389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 8401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 8419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               0, // Lee mode
               0, // Yu neighborhood
               extent));

      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 8440 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               0, // Lee mode
               neighborhood,
               extent));

      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 8462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);


      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                0, // Lee function
                0, // Yu neighborhood
                extent
                ));

      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 8487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                0, // Lee function
                neighborhood, // neighborhood size
                extent // bounding box
                ));
      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 8509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                2, // Additive mode
                0, // Yu neighborhood
                extent // constant region
                ));
      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 8529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt         = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit        = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               1, // Kuan's function
               neighborhood, // Yu neighborhood
               extent));
      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 8550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                1, // Kuan's function
                neighborhood, // Yu neighborhood
                extent
                ));
      delete extent;
      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 8571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
       GET_VARSTACK_VALUE(InrImage, im);
           int mode = (int) (yysemantic_stack_[(14) - (5)].adouble);
            float dt = (float) (yysemantic_stack_[(14) - (7)].adouble);
            int numit = (int) (yysemantic_stack_[(14) - (9)].adouble);
            int neighborhood = (int) (yysemantic_stack_[(14) - (11)].adouble);
            ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(14) - (13)].imageextent);

            InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                        mode, // fiter mode
                        neighborhood, //  neighborhood size
                        extent
                        ));
            delete extent;

            Si !res.get() Alors
                fprintf(stderr,"Func_AnisoNRAD() erreur ... \n");
            FinSi
            driver.im_stack.AddImage(res);
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 8613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 8635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);

    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 8663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      driver.im_stack.AddImage(res);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 8684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        driver.im_stack.AddImage(res);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 8721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 8758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 8795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        driver.im_stack.AddImage(res);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 8829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.im_stack.AddImage(InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 8835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          driver.im_stack.AddImage(InrImage::ptr());
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 8845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage, imdraw)
      driver.im_stack.AddImagePointer(imdraw->GetInrImage());
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 8851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       driver.im_stack.AddImage(res);
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 8858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 8865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);

    }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 8873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 8880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization image
      (7) maximal time
    Description:
      Runs the fast marching algorithm
     **/

        InrImage::ptr    init (driver.im_stack.GetLastImage()); // 2nd param
        InrImage::ptr    input(driver.im_stack.GetLastImage()); // 1st param
        float   maxtime = (float) (yysemantic_stack_[(8) - (7)].adouble);

        InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(),  maxtime));
        driver.im_stack.AddImage(res);
    }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 8901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      float   maxtime = (float) (yysemantic_stack_[(14) - (7)].adouble);

      InrImage::ptr res ( Func_vtkFastMarchingTarget( input.get(), init.get(),  maxtime,
              (int) round((yysemantic_stack_[(14) - (9)].adouble)),
              (int) round((yysemantic_stack_[(14) - (11)].adouble)),
              (int) round((yysemantic_stack_[(14) - (13)].adouble))
              ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 8928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      float   mean    = (float) (yysemantic_stack_[(12) - (7)].adouble);
      float   sd      = (float) (yysemantic_stack_[(12) - (9)].adouble);
      float   maxtime = (float) (yysemantic_stack_[(12) - (11)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime));
      driver.im_stack.AddImage(res);
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 8952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      float   mean     = (float) (yysemantic_stack_[(14) - (7)].adouble);
      float   sd       = (float) (yysemantic_stack_[(14) - (9)].adouble);
      float   maxtime  = (float) (yysemantic_stack_[(14) - (11)].adouble);
      int     inittype = (int) (yysemantic_stack_[(14) - (13)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime,inittype));
      driver.im_stack.AddImage(res);
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 8981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init ( driver.im_stack.GetLastImage());
      InrImage::ptr input( driver.im_stack.GetLastImage());
      float   maxtime    = (float) (yysemantic_stack_[(12) - (9)].adouble);
      int     inittype   = (int)   (yysemantic_stack_[(12) - (11)].adouble);
      GET_VARSTACK_VALUE(InrImage, im);

      InrImage::ptr res ( Func_vtkFastMarching(
                  input.get(),
                  init.get(),
                  im.get(),
                  maxtime,inittype));
      driver.im_stack.AddImage(res);
    }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 9010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr res ( Func_Convolve(
                  varim1->Pointer().get(),
                  varim2->Pointer().get()));
      driver.im_stack.AddImage(res);

      }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 9021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr mask (driver.im_stack.GetLastImage());

        InrImage::ptr res ( Func_ConvolveMask(varim1->Pointer().get(),
                  varim2->Pointer().get(),
                  mask.get()));
        driver.im_stack.AddImage(res);

      }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 9034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        driver.im_stack.AddImage(res);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 9041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          driver.im_stack.AddImage(res);

        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 9049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

        float a = (yysemantic_stack_[(12) - (5)].adouble);
        float b = (yysemantic_stack_[(12) - (7)].adouble);
        float c = (yysemantic_stack_[(12) - (9)].adouble);
        float dmax = (yysemantic_stack_[(12) - (11)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2(im.get(), a,b,c,dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 9063 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 9075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 9087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 9097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 9108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 9118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 9128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 9139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 9149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 9160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 9187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im(driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_CC(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 9235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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


/*
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
*/

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
          InrImage::ptr im2( driver.im_stack.GetLastImage());
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
    
          Variable<InrImage>::ptr new_var(new Variable<InrImage>(res));
          driver.var_stack.AddVar(new_var);

        }
        else {
          driver.err_print("operator image(expr_var), wrong type of parameter \n");
          YYABORT;
        }
      }


    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 9417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im( driver.im_stack.GetLastImage());
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      InrImage::ptr res ( Func_Histogram(im.get(),vmin,vmax,nint));
      driver.im_stack.AddImage(res);
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 9438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im(driver.im_stack.GetLastImage());
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

      driver.im_stack.AddImage(res);
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 9478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res;
      if (im->DimZ()>1)
        res = InrImage::ptr( Func_MeanHalfSize(im.get(),3));
      else
        res = InrImage::ptr( Func_MeanHalfSize(im.get(),2));

      driver.im_stack.AddImage(res);
    }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 9489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      driver.im_stack.AddImage(res);
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 9497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im (driver.im_stack.GetLastImage());
        InrImage::ptr res(Func_Flip(im,axis));
        driver.im_stack.AddImage(res);
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 9505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

            InrImage::ptr im (driver.im_stack.GetLastImage());
            InrImage::ptr res ( Func_Resize(im.get(),sx,sy,sz,interpolate));
            driver.im_stack.AddImage(res);
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 9526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);

    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 9552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage::ptr input(driver.im_stack.GetLastImage());

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      driver.im_stack.AddImage(res);
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 9563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetImageLinesLength(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 9570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input polydata
          - line number
        Description:
          Get the points of the given line as a vectorial 1D image of 
          the point positions.
      **/
      InrImage::ptr         res;
      GET_VARSTACK_VAR_VAL(SurfacePoly,var,s);
      int linenumber = (int) (yysemantic_stack_[(6) - (5)].adouble);
      
      if ((linenumber>=0)&&(linenumber<s->GetNumberOfLines())) {
        T_Line line=s->GetLine(linenumber);
        if (line.NbElts()>0) {
          // Create the image
          res = InrImage::ptr(new InrImage(line.NbElts(),1,1,3,WT_FLOAT,
            (boost::format("%1%_line%2%") 
              % var->Name()
              % linenumber
            ).str().c_str()));
          // fill it with the point positions
          for(int n=0;n<line.NbElts();n++) {
            res->BufferPos(n,0,0);
            Point_3D<float>  pt = s->GetPoint(line[n]).pt;
            res->VectFixeValeurs( pt.X(),pt.Y(),pt.Z());
          }
          driver.im_stack.AddImage(res);
        } else
          driver.err_print((boost::format("Line %1% has no point.") % linenumber).str());
      } else {
        driver.err_print("Invalid line number.");
      }

    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 9607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Returns an image Mx2 where M is the number of lines and 
        containing the point id of the 2 extremities of each 
        line
    **/
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetImageLinesExtremities(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 9622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Get the number of lines connected to each point.
        The result is given as a 1D image of size the total
        number of points of the polydata
    **/

      GET_VARSTACK_VALUE(SurfacePoly,s);
      InrImage::ptr res ( s->GetImageConnections(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 9637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetIntensities( im.get() ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 9645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 9652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 9658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 9664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      if (res!=NULL) driver.im_stack.AddImagePointer(res);
    }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 9671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr coeff (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input.get(),coeff.get());
      driver.im_stack.AddImagePointer(res);

    }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 9696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**

        Description:
        Compute the altitude to the sea level based on the
        temperature channel.

        Parameters:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      InrImage::ptr input (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Temp2Altitudes(input.get()));
      driver.im_stack.AddImage(res);

    }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 9714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 9721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im (driver.im_stack.GetLastImage());

        if (im->_format==WT_UNSIGNED_CHAR) {
          ImageDraw<unsigned char> imdraw;
          imdraw.SetInput((unsigned char*)im->GetData(),im->DimX(),im->DimY(),im->DimZ());
          imdraw.SetVoxelSize(im->VoxSizeX(),im->VoxSizeY(),im->VoxSizeZ());
          imdraw.SetCursorPosition((int)(yysemantic_stack_[(18) - (9)].adouble),(int)(yysemantic_stack_[(18) - (11)].adouble),(int)(yysemantic_stack_[(18) - (13)].adouble));
          imdraw.Apply((int)(yysemantic_stack_[(18) - (5)].adouble),(int)(yysemantic_stack_[(18) - (7)].adouble),(int)(yysemantic_stack_[(18) - (15)].adouble),(int)(yysemantic_stack_[(18) - (17)].adouble));
          // copy to RGB image
          InrImage::ptr res ( new InrImage(imdraw.RGB_width, imdraw.RGB_height, 1, WT_RGB));
          memcpy(res->GetData(),imdraw.RGB_image,imdraw.RGB_width*imdraw.RGB_height*3);
          driver.im_stack.AddImage(res);
        } else
          fprintf(stderr,"only UCHAR format for now \n");
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 9754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage,ref);
      GET_VARSTACK_VALUE(SurfacePoly,surf);
      InrImage::ptr rad = InrImage::ptr(
                                driver.im_stack.GetLastImage());

      InrImage::ptr res ( LineRecons( surf.get(), ref.get(), rad.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 9774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input line read with ReadCTALine
      (5) name of the file
    Description:
      Reads the radius information and save it to an image,
      returns this image.
    **/
      GET_VARSTACK_VALUE(SurfacePoly,surf);
      boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));

      InrImage::ptr res ( Func_ReadCTALineRadii( surf.get(), filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 9946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: convert the pointer to an image in im_stack to a pointer to a image variable in var_stack
      TODO: get completely rid of im_stack later ...
    **/
    InrImage::ptr im (driver.im_stack.GetLastImage());
    Variable<InrImage>::ptr new_var(new Variable<InrImage>(im));
    driver.var_stack.AddVar(new_var);
  }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 9959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: adds a reference to the variable in the stack
    **/
    BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->NewReference());
  }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 9968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        primary_expr_string value to a string variable
      TODO: get completely rid of char* values
    **/
    string_ptr varstr(new std::string((yysemantic_stack_[(1) - (1)].astring)));
    Variable<std::string>::ptr new_var(new Variable<std::string>(varstr));
    driver.var_stack.AddVar(new_var);
  }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 9990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 10052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 10134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Logical negation (NOT) operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(!(*var));
  }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 10142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix increment operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)++);
  }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 10150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix decrement operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)--);
  }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 10159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Cast operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->BasicCast( (yysemantic_stack_[(4) - (2)].aint)));

  }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 10168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Transpose operator, usefull for matrices
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->Transpose());
  }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 10192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //cout << "T_SUB  cast_var  " << endl;
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(-(*var));
  }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 10198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(+(*var));
  }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 10203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(++(*var));
  }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 10208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(--(*var));
  }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 10213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sin());
  }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 10218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_cos());
  }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 10223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sqrt());
  }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 10228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_fabs());
  }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 10233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_round());
  }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 10238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_floor());
  }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 10243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_tan());
  }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 10248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_asin());
  }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 10253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_acos());
  }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 10258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_atan());
  }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 10263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_exp());
  }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 10268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_log());
  }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 10273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_ln());
  }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 10278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_norm());
  }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 10288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*var2);
  }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 10294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/var2);
  }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 10300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)%var2);
  }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 10311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res(*var1+var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 10318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res((*var1)-var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 10333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<var2);
  }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 10339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>var2);
  }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 10345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<=var2);
  }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 10351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>=var2);
  }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 10361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)==var2);
  }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 10367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)!=var2);
  }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 10408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical AND operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)&&var2);
  }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 10421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical XOR operator, for vectorial images it defines the pointwise vectorial product.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)^var2);
  }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 10434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical OR operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)||var2);
  }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 10447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Operation (cond?a:b) like in C/C++.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->TernaryCondition(var1,var2));
  }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 10461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //cout << "assignment_var" << endl;
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    if (var1->GetPtrCounter()==1) {
      // TODO: here ...
    }
    driver.var_stack.AddVar((*var1)=var2);
  }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 10471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)+=var2);
  }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 10477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)-=var2);
  }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 10483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*=var2);
  }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 10489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/=var2);
  }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 10501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 10512 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 10526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 10537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 10555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix::ptr m( new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble)));
         ADD_VARSTACK_PTR(FloatMatrix,m);
      }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 10561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description: adds a reference to the variable in the stack
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        driver.var_stack.AddVar(var->NewReference());
      }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 10570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 10693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray,var,array);
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          BasicVariable::ptr arrayvar = array->GetVar(i);
          if (!arrayvar.get()) {
            // initialize the surface
            SurfacePoly::ptr surf( new SurfacePoly());
            std::string name = (boost::format("%s[%d]") % var->Name().c_str() %i).str();
            array->InitElement(i,surf,name.c_str());
          }

          driver.var_stack.AddVar(array->GetVar(i));
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 10711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          InrImage::ptr im (driver.im_stack.GetLastImage());
          surf = Func_isosurf(im,
                  (yysemantic_stack_[(6) - (5)].adouble),
                  NULL);
          if (surf==NULL) driver.err_print("Isosurface failed!");
          driver.surf_stack.AddSurf(surf);
    }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 10722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 10733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im (driver.im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(8) - (5)].adouble),
                mask.get());
        if (surf==NULL) driver.err_print("Isosurface failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 10754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask (driver.im_stack.GetLastImage());
      InrImage::ptr im   (driver.im_stack.GetLastImage());
      vtkPolyData* vtklines;
      CreeCrest* crestlines;
      SurfacePoly* lines;

      crestlines = Func_IsoLine(im.get(), (yysemantic_stack_[(8) - (5)].adouble), mask.get());
      printf("running conversion to vtkPolyData ...");
      vtklines = (vtkPolyData*) (*crestlines);

      lines = new SurfacePoly(vtklines);
      if (lines == NULL)
        driver.err_print("IsoLine failed!");
      driver.surf_stack.AddSurf(lines);

      //vtklines->Delete();
      delete crestlines;

    }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 10788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,varsurf);
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 10798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_decimate( surf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 10809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
          surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 10819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 10830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly, surf);
        SurfacePoly* newsurf;

        newsurf = Func_vtkWindowedSinc( surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (newsurf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(newsurf);
    }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 10840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 10846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 10860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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


          inc_cmd = str(format(" \"%1%\"  // from browser ") % newname.mb_str());
          if (driver.InConsole())
            GB_main_wxFrame->GetConsole()->IncCommand(inc_cmd);
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 10886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          driver.surf_stack.AddSurf(surf);
      }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 10901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          driver.surf_stack.AddSurf(surf);
      }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 10919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly,surf);
        SurfacePoly* newsurf;
  
        newsurf = new SurfacePoly( (*surf) );
        driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 10928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
          SurfacePoly* surf;

      GET_VARSTACK_VALUE(InrImage, im);
      surf = Func_Skeleton2lines( im.get()  );

      Si surf==NULL Alors
        driver.err_print("Skeleton2lines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 10947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_SmoothLines( insurf.get(),
                      0.1,
                      0.01,
                      10);

      Si surf==NULL Alors
        driver.err_print("SmoothLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 10976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_SmoothLines( insurf.get(),
                      (yysemantic_stack_[(10) - (5)].adouble),
                      (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble));

      Si surf==NULL Alors
        driver.err_print("SmoothLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 11004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_ResampleLines( insurf.get(),
                     (yysemantic_stack_[(6) - (5)].adouble));

      Si surf==NULL Alors
        driver.err_print("ResampleLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 11021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
        - point 1: x,y,z
        - point 2: x,y,z 
      Description:
        Finds the shortest path within the lines of the polydata
    **/
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_shortestpath( insurf.get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath () error ... \n");
      FinSi
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 11045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
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
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 11078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
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
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 11114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      double start[3] = {(yysemantic_stack_[(20) - (9)].adouble),(yysemantic_stack_[(20) - (11)].adouble),(yysemantic_stack_[(20) - (13)].adouble)};
      double end[3] = {(yysemantic_stack_[(20) - (15)].adouble),(yysemantic_stack_[(20) - (17)].adouble),(yysemantic_stack_[(20) - (19)].adouble)};
      surf = Func_path_from_vectfield(  im,
                                        start,end,
                                        (yysemantic_stack_[(20) - (5)].adouble), (yysemantic_stack_[(20) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_path_from_vectfield() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 11160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      double start[3] = {(yysemantic_stack_[(14) - (9)].adouble),(yysemantic_stack_[(14) - (11)].adouble),(yysemantic_stack_[(14) - (13)].adouble)};
      surf = Func_path_from_vectfield(  im,
                                        start,
                                        (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_path_from_vectfield() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 11198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;
 
      surf = Func_ConnectLines( insurf.get(),
                      (yysemantic_stack_[(8) - (5)].adouble),
                      (yysemantic_stack_[(8) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("ConnectLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 11223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 11233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 11256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(),minth,maxth);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 11268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);

      surf = AMIFluid::Func_vtkCreateFlatMesh(im.get(),minth,maxth);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 11280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr highpos (driver.im_stack.GetLastImage());
      InrImage::ptr lowpos  (driver.im_stack.GetLastImage());
      InrImage::ptr input   (driver.im_stack.GetLastImage());
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(12) - (5)].adouble);
      float maxth = (yysemantic_stack_[(12) - (7)].adouble);

      surf = AMIFluid::Func_CreateVolume(input.get(), minth, maxth, lowpos.get(), highpos.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 11317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr colors  (driver.im_stack.GetLastImage());
      InrImage::ptr highpos (driver.im_stack.GetLastImage());
      InrImage::ptr lowpos  (driver.im_stack.GetLastImage());
      InrImage::ptr input  (driver.im_stack.GetLastImage());
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(16) - (5)].adouble);
      float maxth = (yysemantic_stack_[(16) - (7)].adouble);
      float alpha = (yysemantic_stack_[(16) - (15)].adouble);

      surf = AMIFluid::Func_CreateVolume(input.get(), minth, maxth, 
                                          lowpos.get(), highpos.get(), colors.get(), alpha);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 11360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr alt2  (driver.im_stack.GetLastImage());
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      InrImage::ptr alt1  (driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      float scale = (yysemantic_stack_[(16) - (13)].adouble);
      int   type  = (int) (yysemantic_stack_[(16) - (15)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),displ.get(),alt2.get(), 
                                          stepx, stepy, scale, type);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 11408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr alt2  (driver.im_stack.GetLastImage());
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      InrImage::ptr alt1  (driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(18) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(18) - (11)].adouble);
      float scale = (yysemantic_stack_[(18) - (13)].adouble);
      int   type   = (int) (yysemantic_stack_[(18) - (15)].adouble);
      int   style  = (int) (yysemantic_stack_[(18) - (17)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),
          displ.get(),
          alt2.get(), stepx, stepy, scale, type,style);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 11460 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr alt2  (driver.im_stack.GetLastImage());
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      InrImage::ptr alt1  (driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (11)].adouble);
      float scale = (yysemantic_stack_[(14) - (13)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),displ.get(),alt2.get(), stepx, stepy, scale);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 11503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(14) - (5)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (7)].adouble);
      int stepz   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      float scale = (yysemantic_stack_[(14) - (11)].adouble);
      int style = (int) (yysemantic_stack_[(14) - (13)].adouble);
      SurfacePoly* surf;

      stepx = macro_max(stepx,1);
      stepy = macro_max(stepy,1);
      stepz = macro_max(stepz,1);
       surf = AMIFluid::Func_CreateVectors(displ.get(), stepx, stepy, stepz,  scale, style);
       Si surf != NULL Alors
         driver.surf_stack.AddSurf(surf);
       FinSi
    }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 11534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr v3  (driver.im_stack.GetLastImage());
      InrImage::ptr v2  (driver.im_stack.GetLastImage());
      InrImage::ptr v1  (driver.im_stack.GetLastImage());
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
    }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 11567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask   (driver.im_stack.GetLastImage());
      InrImage::ptr colors (driver.im_stack.GetLastImage());
      InrImage::ptr v3     (driver.im_stack.GetLastImage());
      InrImage::ptr v2     (driver.im_stack.GetLastImage());
      InrImage::ptr v1     (driver.im_stack.GetLastImage());

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
      if (surf != NULL) {
        driver.surf_stack.AddSurf(surf);
      }
    }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 11628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          // todo ... 
          // 1. check if identifier belongs to the object
          // 2. if so return corresponding variable
          Variable<AMIObject>::ptr var(driver.var_stack.GetLastVar<AMIObject>());
          AMIObject::ptr object(var->Pointer());
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (3)].ident));
          Variables::ptr previous_ocontext (Vars.GetObjectContext());
          Vars.SetObjectContext(object->GetContext());
    
          // here, need to do our own checking ...
          BasicVariable::ptr newvar( 
            Vars.GetVar(ident->GetName().c_str(),
            OBJECT_CONTEXT_NUMBER));

          // reset previous object context
          Vars.SetObjectContext(previous_ocontext);
    
          if  ((!GB_driver.procedure_declaration)&& newvar.get())   {
            //cout << "returning variable" << endl;
            newvar->display();
            driver.var_stack.AddVar(newvar);
          } else {
            // error message here
            driver.yyiperror("Identifier does not belong to object context \n");
            YYABORT;
            //driver.var_stack.AddVar(BasicVariable::ptr());
          }
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 11702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 11710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 11717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          (yyval.imageextent)=extent;
       }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 11733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
        DessinImage::ptr draw = DessinImage::ptr(varimd->Pointer());

        int xmin,xmax;
        int ymin,ymax;
        int zmin,zmax;
        string comment;

        draw->GetZoom(xmin,ymin,zmin,xmax,ymax,zmax);
        ImageExtent<float>* extent=new ImageExtent<float>(xmin,xmax,ymin,ymax,zmin,zmax);
        extent->SetMode(1); // relative extent

        comment = str(format(" //  subvolume [%3d:%3d, %3d:%3d, %3d:%3d] ")
            % xmin % xmax % ymin % ymax % zmin % zmax);
        if (GB_debug) cerr << "********* extent ****" << endl;
        if (driver.InConsole()) GB_main_wxFrame->GetConsole()->IncCommand(comment);

        (yyval.imageextent)=extent;
       }
    break;



/* Line 678 of lalr1.cc  */
#line 12820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	default:
          break;
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

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
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
    if (yychar != yyempty_)
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
  const short int Parser::yypact_ninf_ = -2051;
  const short int
  Parser::yypact_[] =
  {
      5554, 12139, 11730, 11730,  9999, -2051, -2051, -2051, -2051, -2051,
      44,    99,   115, -2051, -2051, -2051, -2051, 10434, -2051,   146,
     -36,   159, -2051,    24,  9999,  9999,  9999,   157,  9999, -2051,
     218,   221, -2051, -2051, -2051, -2051,    79,    10,    16,   129,
     143, -2051,    60,   117,    22, -2051, -2051, -2051, -2051, -2051,
     -37,    -6,   185,    34,    38,  1038,  9999, -2051, -2051, -2051,
   -2051,   240,   244, 11730, 11730,   257,   125,   283,   235,   306,
     303,   310,   313,   352,   353,   365,   377,   405,   412,   436,
     489,   498,   509,   532,   539,   543,   544,   545, -2051, -2051,
   -2051, -2051,   546,   565,   566,   188,   273,   567,   571,   572,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   584,
     586,   587,   588,   589,   590,   591,   593,   595,   596,   597,
     598,   599,   459,   600,   601,   602,   604,   617,   618,   619,
     622,   623,   624,   625,   637,   638,   639,   640,   641,   642,
     643,   644,   645,   648,   649,   653,   654,   655,   656,   657,
     658,   660,   661,   664,   666,   667,   668,   669,   675,   676,
     677,   678,   679,   680,   681,   683,   684,   685,   686,   687,
     688,   689,   690, -2051, -2051, -2051, -2051, -2051, -2051, -2051,
   -2051, -2051, -2051,   691,   692,   694,   695,   696, -2051, -2051,
   11730, 11730, 11730, 11730, 11730, 11730, 11730, 11730, 11730, 11730,
   11730, 11730, 11730, 11730,   -37, -2051,  1089, -2051,  9999,  7365,
    9999,   697,   698,   699,   700,    26,   -37,   701,   702,   703,
     704,   705,   282,   706,   707,   708,   709,   710,   711,   714,
     715,   716, -2051, -2051, -2051,   717,   718,   414,  4716, -2051,
   -2051, -2051, -2051, -2051, -2051, -2051,    85, -2051, -2051,   396,
      70, -2051, -2051, -2051,     4, -2051,    50,   191,    80, -2051,
      40,    81,   443, -2051,   719,   372,   728,    27, -2051, -2051,
   -2051, -2051,    35,   -31, -2051,   720, -2051,   484, -2051,   732,
    9999, -2051, -2051, -2051, -2051,   733,   736,   117,   737,   738,
     743,   744,   755,   756,   264, -2051,   757,   720, -2051, -2051,
     227,   721,  9999,  9999,  9999,  9999, -2051, -2051,  9999, -2051,
   -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051,
   -2051, -2051,  9999, -2051,  1089,  1089, -2051, -2051,  9999, -2051,
   -2051,  9999,  1564,   651,    43,    43,  9999,   408,   -11,   409,
   -2051,   -37, -2051,   -25,  9999,   512,  9999, -2051, -2051, -2051,
   -2051, -2051, -2051, -2051, -2051, -2051,   738, -2051,   765,   744,
   -2051, -2051, -2051, -2051, -2051, -2051,  9999,  9999, -2051, -2051,
    9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,    24,  9999,
    9999,    24,    24,    24,    24,    24,  9999,    24,    24,    24,
      24,    24,    24,    24,    24,    24,  9999,  9999,    24,   238,
     393,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,  9999,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,  9999,  9999,  9999,  9999,
    9999,  9999,  9999,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    43,    43,  9999,  9999,    24,
      24,    24,   734,   747,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,  9999,  9999,  9999,    24,  9999,
      24,    24,  9999,  9999,    24,    24,    24,    24,  9999,  9999,
    9999,  9999,    24, -2051, -2051, -2051, -2051, -2051, -2051, -2051,
   -2051, -2051, -2051, -2051, -2051, -2051, -2051,   -88, -2051,   727,
     743, -2051, -2051, -2051, -2051,    85, -2051,   943,  9999,  9999,
     759, -2051, -2051, -2051,  9999,  9999,    24,  9999,  9999,   359,
    9999,  9999,  9999,  9999,  9999,  9999,  9999,   766,    24,    24,
      24, -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051,
      85, -2051,   413,  9999,  7800,   333,  9999, -2051, -2051, -2051,
    9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,
    9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,
    9999,  9999,  9999,  1541,   -41,  8235,  6048,  6495,   750,   -47,
     -71,  -147,  9999,  9999,   693,   712,  9999,   212,  -110, 12139,
   -2051,   811,   818,   819,   279,   828,   829,   839,   840, -2051,
   -2051,   854,   855,   860,   861,   866,   867, -2051, -2051, -2051,
   -2051, -2051, -2051, -2051, -2051, -2051, -2051,   868,   869,   871,
   -2051,   872,   873,   874,   875, -2051,   876,   877,   880,   881,
     882,   883,   884,   886,   888,   889,   891, -2051, -2051,   892,
     893,   894,   896, -2051,   897,   898,   899,   900, -2051, -2051,
     901, -2051,   902, -2051,   908,   910,   913,   914,   915, -2051,
   -2051,   923,   921,  9999,  9999, -2051,   931,   933, -2051,   934,
   -2051, -2051,  9999,   932,   935,   936,  9999,   937,   929,   939,
   -2051,   940,   938,   944,   941,   942,   945,   948,   947,   946,
     950,   951,   953,   954,   957,   958,   959,   960,   963,   964,
     965,   966,   967,   968,   969,   977,   973,   974,   975,  1000,
     952, -2051, -2051,   955, -2051, -2051,  1007,  1002,  1004,  1005,
    1006,  1008,  1010,  1011,  1012,  1013,  1014,  1021,  1022,  1023,
    1018,  1025,  1020,  1024,  1026,  1027,  1028,   135,  1030,  1029,
    1032,  1031,   217,  1037,  1034,  1035,  1036,  1039,  1040,  1042,
    1043,  1044,  1045,  1046,  1047,  1054,  1049,  1050,  1051,  1052,
    1053,  1055,  1056,  1064,  1065,  1060,  1061,  1062,  1063,  1068,
    1069,  1070,  1071,  1072,  1073,  1095,  1096,  1097,  1099,  1100,
    1101,  1108,  1111,  1113,  1109,  1110,   272,  1114,  1118,  1115,
    1119,  1120,  1122,  1123,  1126,  1127,  1124,  1146,  1147,  1128,
    9999,  9999, -2051, -2051,     8, -2051,  1129,  1154,  1155,  1150,
    1157,  1160,  1161,    85,   149,  1156,  1158,  1159,  1162,  1164,
     186,   194,  1163,  1166,  1167,  1170,  1173,  1168,  1169,  1171,
    1172, -2051, -2051,   151,  1176,  1174,   733,   233,   305,  1041,
    1180, -2051,  1182,  1183, -2051, -2051,  9999, -2051,  1184,  1185,
    1186,  1187,  1188,  1191,  1192,  1193,  1195, -2051, -2051, -2051,
   -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051,
   -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051,
   -2051,   191,   191, -2051, -2051, -2051, -2051,    40,    40,    81,
   -2051,   719,   372,    30,   728, -2051, -2051, -2051,  9999,  1196,
    1197, -2051,  1198,  9999, -2051,  1199, -2051,  1200,  1201,  1202,
    1203,  1204,  1205,  1207,  1208,  1209,  1210,  1212,  1213,  1214,
    1216,  1217,  1218,  1219,  1220,  1221,  1222, -2051,  1223, -2051,
    1224, -2051, -2051,  1225,  1227,  1229,  1230,  1232, -2051, -2051,
    1233,  1234,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,
    1246,  1248,  1249,  1250,  1251,  1252,  1253, 10869,  1255,  1256,
    1257,  1258,  1265,  1267,  1066, -2051,   949, -2051,  1089,  8678,
    1271,   733,  1272,   737, -2051,  9121,  1279,  1280,  1281,  1283,
    1277, -2051,  1284, -2051, -2051,  1089,   736,   286, -2051,   757,
   -2051,  1285,  1288,  1289,   127, -2051,  9999, -2051, -2051,  9999,
    9999,  9999, -2051, -2051,  9999,  9999,  9999,  9999,  9999,  9999,
      24,  9999,  9999,    31,   904,   979,  9999,  9999,  9999,  9999,
    9999,  9999,  9999,  9999,  9999,   978,  9999,   956,  9999,  9999,
     -41,  9999,  9999,  9999,  9999,  9999,    43,   -27,   994,  1125,
    9999,  9999,  9999,  9999,  9999, -2051, -2051,  1286, -2051,  9999,
      -3,  9999, -2051,  1206,  9999,  1211,  1292, -2051,  1104, -2051,
   -2051,  9999,  1296, -2051, -2051,  1297, -2051,  1300,    39,  9999,
    9999, -2051,  9999,  9999,  9999,  9999,  9999,    24,  9999,  9999,
    9999,  9999,  9999,  9999, -2051,  9999,  9999,  9999,    24,    24,
      24, -2051,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,
      24,  9999, -2051, -2051, -2051,    24, -2051,    24,    24,    24,
      24,    24, -2051,    24,    24, -2051,  9999, -2051,  9999,  1301,
    9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,
    9999, -2051,  9999,  9999,  9999,  9999,  9999,    24,  9999, -2051,
   -2051,    24,    24,    24,    24,    24,  9999,  9999,  9999,  9999,
    9999,  9999,  9999,  9999,  9999,  9999,  9999, -2051, -2051, -2051,
    9999,  9999, -2051, -2051, -2051,  9999, -2051, -2051, -2051, -2051,
   -2051, -2051,  9999,  9999,  9999, -2051,   907,  1295, -2051, -2051,
   -2051, -2051, -2051, -2051, -2051,  9999, -2051,  -164,  -164, -2051,
   -2051,  9999,  9999,    24,  9999,  9999,    24, -2051,  9999, -2051,
    9999,  9999,  9999, -2051, -2051, -2051,  9999,  9999,    24,    24,
    9999,  9999,  9999, -2051,  1294, -2051,  9999,   154, -2051,  9999,
    9999,    24, -2051,    24,    24,  9999,  9999,  9999,  9999,  9999,
    9999,  9999,  9999, -2051,  9999,  9999,  9999, -2051,  9999,  9999,
    9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,
    9999,  9999,  9999,    24,    24,  1304,  1305,  1306,  9999,  9999,
    9999,  9999,  9999,    24,  9999,  9999,  9999,  9999,    24,    43,
      43,    43,  9999,  9999,  9999,  9999,  9999,    24,    43,    24,
      43,    43,  9999,  9564, -2051,  9999,  9999,  9999,  9999,  9999,
    9999,  1130,  9999, -2051,  9999,  9999,  -181,  9999,  1247,  9999,
    9999,  9999,  9999,  -117, -2051, -2051,  6930,  9999, -2051, -2051,
    1303,  1307,  1308,  1310,  1309,   220,  1312,  1313,  1314,  1311,
    1315,  1316,  1317,  1322,  1324,  1325,  1320,  1321,  1323,  1326,
    1327,  1328,  1330,  1329,  1331,  1332,  1333,  1334,  1335,  1336,
    1337,   311,  1340,  1342,  1338,  1339,  1341,  1343,  1346,  1348,
     314,  1351,  1350,  1352,  1353,  1357,  1360,  1355,  1362,  1363,
    1367,  1364,   -41,  1366,  9999, -2051,  1369,  1371,  9999,    24,
      24,   319,  1368,  1372,  1377,  1379,  1380,  1381,  1376,  1383,
     321,  1378,  1382,  1384,  1386,  1387,  1388,  1389,  1390,  1392,
    1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,  1405,
    1406,  1385,  1413,  1408,  1409,  1410,  1411,  1412,  1414,  1419,
    1422,  1417,  1424,  9999,  1425,  1426,  1427,  1423,  1428,  1429,
    1430,   322,  1431,  1432,  1439,  1434,  1442,  1443,  1444,  1445,
    1440,  1447,  1448,  1446,  1450,  1452,  1453,  1454,  1455,  1449,
    1451,  1462,  1463,  1465,  1466,  1467,   323,  1464,  1468,  1472,
    1469,  1473,  1474,  1475,  9999,  9999,    85,    85,  1476,  1270,
    1345,  1347,  1441,  1457,  1461,   324,   326,  1471,  1478,  1479,
    1486,  1482,  1484,  1491,  1493,  1498,  1505,  1500,  1507,  1502,
    1504,   100,  1506,  1511,  1508,  1512, -2051,  1513,  1514,   334,
    1517,  1519,  1516,   275,  1520,   295,  1523,   335,  1521,  1527,
     336, -2051,  1525,  1534,  1535,  1536,  1537,   337,  1538,  1539,
    1540,   348,  1542,  1543,  1544,  1545,  1547,  1548,  1552,  1553,
    1554,  1555, -2051, -2051, -2051,  1556,  1557,  1560,  1558,  1559,
    1561,  1562,  1563,  1566,  1567,  1568,   349,  1565,  1569,  1570,
    1571,  1572,   367,  1573,  1575,   368,  1576,  1578,  1579,  1580,
   -2051,   371,  1581,  1582,  1583,  1584,  1585,  1349,  1470,  1590,
    1574, -2051,  1591,  1588,  1598,  1599,  1594, -2051,  1089, -2051,
   -2051,  1601,  9999,  9999,  9999, -2051,    24,  9999,  9999,  9999,
    9999, -2051,  9999, -2051,  9999, -2051, -2051, -2051,    24,    24,
    9999,  9999,  9999, -2051, -2051,  9999,  9999,  9999,  9999, -2051,
    9999, -2051,  9999, -2051,  9999, -2051, -2051,  9999,  9999,  9999,
    9999, -2051,   764, -2051,  9999, -2051,    24,  9999,  9999, -2051,
   -2051,  9999, -2051, -2051, -2051,  1391, -2051, -2051, -2051, -2051,
   -2051,  1602,  1603,   375, -2051,   288,    46,  9999, -2051, -2051,
   -2051, -2051,  9999, -2051, -2051,    24,  9999,  9999,  9999,  9999,
    9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999,
    9999,  9999,  9999,  9999,  9999,  9999, -2051, -2051,  9999,    24,
      24,    24,    24,    24, -2051, -2051,  9999, -2051,  1605, -2051,
   -2051, -2051,  9999,  9999,  9999,  9999, -2051,  9999,  9999,  9999,
   -2051,  9999, -2051, -2051, -2051, -2051,  9999, -2051, -2051,  9999,
    9999,    24,    24,  9999,  9999, -2051, -2051, -2051, -2051, -2051,
   -2051, -2051, -2051,  9999,  9999,  9999,  9999, -2051,  9999,  9999,
    9999,  1074, -2051, -2051, -2051,  9999, -2051, -2051, -2051, -2051,
   -2051, -2051, -2051,  -157, -2051, -2051,  9999,  9999, -2051,  9999,
    9999, -2051, -2051,  9999, -2051,  9999, -2051,    24,  9999, -2051,
    9999,  9999,  9999, -2051,  9999,  9999, -2051,  9999, -2051,  9999,
   -2051, -2051,  9999, -2051,  9999, -2051, -2051, -2051,  9999,  9999,
    9999, -2051,  9999, -2051, -2051, -2051, -2051, -2051, -2051,  9999,
   -2051, -2051,  9999, -2051,  9999, -2051,  9999,  9999,  9999, -2051,
   -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051,  9999,  9999,
   -2051, -2051,  9999, -2051, -2051, -2051, -2051,  9999,  9999,  9999,
    9999,  9999,  9999, -2051,  9999,  9999,  9999, -2051,  9999,  9999,
    9999,  9999,  9999, -2051,  9999,  9999,  9999,  9999,  9999,  9999,
    9999, -2051, -2051, -2051, -2051,  1394,  1600,  1608,  1393, -2051,
   -2051,  1607,  1609,   298,  1610,  1611,  1618,  1614,  1621,  1616,
    1623,  1619,  1624,  1626,  1627,  1628,  1625,  1629,  1630,  1631,
    1632,  1633,  1636,  1634,  1637,  1638,  1639,  1640,  1647,  1648,
    1649,  1645,  1646,  1653, -2051, -2051, -2051,  9999,  1654,  1604,
     388,  1650,  1651,  1652,  1659,   389,   392,   399,   402,  1655,
    1656,  1661,   403,   232,  1662,  1664,  1665,  1666,   421,  1668,
    1669,  1670,  1671,  1672,  1673,  1660,  1674,  1675,  1677,  1678,
    1684,  1685,  1686, -2051,  1693,  1694,   422,   425,  1689,  1696,
    1691,  1692,  1695,  1699,  1700,  1697,  1698,  1701,  1702,  1703,
    1705,  1704,  1706,  1707,  1711,  1708,  1709,  9999,    85,  1714,
      85,  1499,  1501,  1503,  1528,  1530,  1531,    85,  1715,  1716,
    1717,  1718,  1723,  1720,  1722,  1724,   112,  1729,  1420,  1460,
    1532,  1731,  1726,  1727,  1728,  1730,  1734,  1735,  1738,  1737,
    1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,  1754,
    1749,  1752,  1753,  1755,  1760,   426,  1762,  1763,  1764,  1765,
    1781,  1776,   437,  1777,  1778,  1784,  1785,  1786,  1787,  1788,
    9999,  9999,  1795, -2051,  9999, -2051,  9999,  9999, -2051,  9999,
   -2051,  9999, -2051,  9999, -2051, -2051, -2051, -2051,  9999,  9999,
   -2051,  9999,  9999,  9999,  9999, -2051,  9999,  9999,  9999,  9999,
   -2051, -2051, -2051,  9999,  9999, -2051,  1796, -2051,   983, -2051,
     288,  1524,  9999,  9999, -2051, -2051,  9999, -2051,  9999, -2051,
    9999, -2051,  9999,  9999,  9999,  9999, -2051,  9999,  9999,  9999,
    9999,  9999,  9999, -2051, 11304, 11304, 11304,  9999,  9999,  9999,
    9999, -2051,  9999,  9999,  9999,  9999,  9999,    24,  9999, -2051,
   -2051, -2051,  9999, -2051,  9999,  9999, -2051,  9999,  9999,  9999,
   -2051, -2051,  9999,    24,    24,  9999,  9999, -2051,  9999,  9999,
    9999, -2051,  9999,  9999, -2051, -2051,  9999, -2051, -2051, -2051,
   -2051, -2051, -2051, -2051, -2051,  9999,  9999, -2051,  9999, -2051,
    9999,    24,  9999, -2051,  9999,  9999, -2051,  9999,  9999,  9999,
   -2051,  9999,  9999,  9999,  9999,  9999,  9999,  9999, -2051,  9999,
    9999,  9999,  9999,  9999,  9999,  9999,  9999,  9999, -2051,  9999,
    9999,  9999,  9999, -2051, -2051,    24, -2051, -2051, -2051, -2051,
   -2051,  9999, -2051,  9999,  9999,  9999,  9999,  9999,  9999,  9999,
    9999, -2051, -2051, -2051,   439,  1791,  1800,   447,  1797,  1801,
    1802,  1803,  1810,  1805,  1806,  1816,  1808,  1812,  1818,  1848,
    1843,  1850, -2051,  1851,   448,  1846,  1847,   449,   450,  1849,
    1852,  1853,  1854,  1856,  1855,  1857,  1858,  1859,  1860,  1861,
     430,  1862,   531,  1868,  1657,  1869,  1864,  1865,  1866,  1867,
    1870,  1876,  1889,  1890,  1891,   457,  1892,  1874,   462,  1875,
    1893,  1894,  1901,  1896,   469,  1897,  1904,   470,  1905,  1906,
    1907,  1908,  1909,    85,  1910,  1911,  1912,  1913,  1914,  1915,
    1916,  1919,  1923,  1918,  1733,  1920,  1921,  1925,  1928,  1929,
    1930,  1931,  1932,  1933,  1934,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  1943,  1944,  1945,  1946,  1952,  1953,  1948,
    1956,  1951,  1955,  1958,  1959,  1962, -2051,  9999,  9999, -2051,
   -2051,  9999,  9999, -2051,  9999,  9999, -2051,  9999,  9999, -2051,
    9999,  9999,  9999, -2051,  9999, -2051, -2051, -2051,   288,  9999,
    9999, -2051,  9999, -2051,  9999,  9999,  9999,  9999,  9999, -2051,
    9999,  9999,  9999,  9999,  9999,  9999, 11304, -2051, 11304, -2051,
   -2051, 11304, 11304,  9999,  9999,  9999,    24,    24,    24,    24,
   -2051,  9999,  9999, -2051, -2051,  9999, -2051,  9999,  9999, -2051,
    9999, -2051,  9999,    24, -2051, -2051,  9999, -2051, -2051, -2051,
   -2051, -2051, -2051,  9999,  9999,  9999, -2051,  9999,    24,  9999,
   -2051, -2051,  9999, -2051,  9999,  9999, -2051, -2051, -2051, -2051,
   -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051, -2051,
    9999,  9999,  9999,  9999,  9999, -2051, -2051, -2051,  9999, -2051,
    9999,  9999,  9999, -2051, -2051,  1965,  1960,  1961,  1963,  1968,
    1970,  1966,  1967,  1971,  1974,  1978,  1979,  1975,  1980,  1982,
    1977,  1984,  1988,  1989,  1990,  1991,  1986,   471,  1993,  1992,
    1994,  1995,  1996,  1997,  1999,  2000,  2001,  2003,  2005,  2006,
    2007,  2010,  2008,  2009,  2011,  2012,  2013,  2016,  2014,  2019,
    2017,  2020,  2027,  2022,  2029,  2024,  2025,  2028,  2030,  1794,
    1902,  2033,  2035,  2031,  2032,  2039,  2036,  2037,  2038,  2040,
    2041, -2051,  9999,  9999,  9999, -2051, -2051,  9999,  9999,  9999,
   -2051, -2051, -2051,  9999, -2051, -2051,  9999, -2051, -2051, -2051,
   -2051, -2051,  9999, -2051,  9999, -2051,  9999, -2051, -2051,  9999,
   -2051, -2051, -2051, -2051, 11304, -2051, -2051, -2051, -2051,  9999,
    9999, -2051,  9999, -2051, -2051,  9999,  9999, -2051,    24, -2051,
    9999, -2051,  9999,  9999,    24,  9999,  9999,  9999, -2051, -2051,
    9999,  9999, -2051,  9999,  9999,  9999,  9999,  9999,  2042,  2045,
    2043,  2050,  2046,  2047,  2048,  2049,  2055,  2051,  2062,  2063,
    2058,  2065,  2060,  2061,  2069,  2066,  2068,  2070,  2071,  2072,
    2073,  2074,  2075,  2082, -2051,  2077,  2078,  2079,   474,  2080,
    2081,  2084,  9999, -2051,  9999, -2051,  9999,  9999,  9999,  9999,
    9999, -2051, -2051, -2051,  9999, -2051,  9999,  9999, -2051,  9999,
    9999,    24,  9999,  9999,  9999,    24,  9999,  1757,  9999,  9999,
    9999, -2051,  9999,  9999,  9999,  9999,  2091,  2092,  2093,  2094,
    2089,  2096,  2097,  2098,  2099,  2095,   485,  2100,   486,  2101,
    2103,  2104,  2105,  2106,  9999,  2107,  2108,   487,  2109,   490,
    2102,  2110, -2051, -2051, -2051, -2051,  9999, -2051, -2051, -2051,
   -2051,  9999, -2051,  9999,  9999, -2051,  9999,  9999,  9999,  9999,
    9999,  9999, -2051,  9999,  9999, -2051,  9999,  9999, -2051,  9999,
   -2051,  9999,  2111,  2112,  2119,  2120,  2121,  2122,  2117,  2118,
    2123,  2124,  2125,  2126,  2127,  2135,   499,   517,  9999,  9999,
   -2051, -2051, -2051, -2051,  9999,  9999,  9999,    24, -2051,  9999,
    9999, -2051, -2051,  9999, -2051,  9999,  2131,  2138,  2133,  2140,
    2136,  2137,  2141,  2139,  2148,  2143,  9999, -2051,  9999, -2051,
    9999,    24, -2051,  9999, -2051,  9999,  2144,  2145,  2147,  2149,
    2156,  2157,  9999,  9999,  9999,  9999, -2051, -2051,  2152,  2153,
    2154,  2161,  9999,  9999,  9999, -2051,  2158,  2159,  2162,  9999,
    9999,  9999,  2163,  2164,  2165, -2051,  9999,  9999,  2169,  2172,
   -2051, -2051
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,     0,     0,     0,     0,    21,    69,    70,    71,    72,
       0,     0,     0,   295,   300,    40,    20,     0,   386,     0,
       0,    96,    76,     0,     0,     0,     0,     0,     0,    95,
       0,     0,   289,   299,   636,   378,   303,   304,   305,   519,
     646,   597,   648,   595,   649,   639,   640,   642,   641,   643,
     650,   651,   637,   647,   652,     0,     0,    42,    45,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     291,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,     0,   301,   302,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   261,   262,   263,     0,     0,     0,     0,     4,
       8,    10,    14,    16,    18,    12,     0,   520,   521,     0,
     390,   518,   522,   523,   528,   534,   553,   558,   561,   562,
     567,   570,   572,   573,   575,   577,   579,   581,   583,   589,
      39,   524,   638,     0,   653,   645,   654,    38,   662,     0,
       0,   303,   304,   305,   519,     0,     0,   595,     0,     0,
       0,     0,     0,     0,   390,   529,     0,     0,   536,   535,
       0,     0,     0,     0,     0,     0,   380,   366,     0,    89,
      77,    79,   102,    99,   100,   101,    98,    97,    78,   105,
     106,   107,     0,    94,     0,     0,    83,    84,     0,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,   141,     0,     0,     0,     0,   657,   655,   656,
     658,   646,   648,   659,   649,   650,   651,   637,   647,   652,
     660,   638,   645,   661,    91,    92,     0,     0,   537,   538,
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
       0,     0,     0,   539,   540,   545,   546,   547,   548,   549,
     551,   550,   541,   542,   543,   544,   552,     0,    25,     0,
     647,   297,   297,   364,    36,     0,    37,     0,     0,     0,
       0,    31,    29,   297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     3,     5,     9,    11,    15,    17,    19,    13,
       0,     6,     0,     0,     0,     0,     0,   530,   531,   533,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,     0,     0,     0,     0,     0,     0,   349,   350,   347,
     348,   345,   346,   351,   352,   353,   468,     0,     0,     0,
     112,     0,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   466,   467,     0,
       0,     0,     0,   217,     0,     0,     0,     0,   222,   223,
       0,   206,     0,   214,     0,     0,     0,     0,     0,   203,
     204,     0,     0,     0,     0,   109,     0,     0,    68,     0,
     644,   259,     0,     0,     0,     0,     0,     0,     0,     0,
     365,     0,   365,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   152,     0,   153,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   390,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   298,    26,     0,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   359,     0,   364,     0,   666,     0,   390,     0,
       0,   292,     0,     0,   139,   140,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   377,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
      80,   585,   586,   587,   588,   584,   557,   554,   555,   556,
     553,   559,   560,   564,   563,   565,   566,   568,   569,   571,
     574,   576,   578,     0,   580,   142,   325,   326,     0,     0,
       0,   363,     0,     0,   190,     0,   185,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,     0,   176,
       0,   186,   187,     0,     0,     0,     0,     0,   195,   197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   610,     0,     0,
       0,     0,     0,     0,   613,    60,     0,    55,     0,     0,
       0,   646,   648,   649,   590,   610,     0,   368,   371,     0,
      49,    57,   613,    59,    51,     0,   648,     0,   274,   638,
     270,     0,     0,     0,     0,   532,     0,    74,    75,     0,
       0,     0,   293,   294,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,   103,   364,   104,     0,
       0,     0,   260,   598,     0,   379,     0,    46,     0,   332,
     334,     0,     0,   335,   336,     0,   337,     0,     0,     0,
       0,   424,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   425,     0,     0,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   409,   410,   411,     0,   413,     0,     0,     0,
       0,     0,   420,     0,     0,   328,     0,   333,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   427,     0,     0,     0,     0,     0,     0,     0,   384,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   493,   249,   250,
       0,     0,   330,   405,   407,     0,   596,   462,   463,   464,
     465,   344,     0,     0,     0,   252,     0,   297,   267,   296,
     297,    27,   356,   357,   358,     0,   254,   276,   276,    33,
     497,     0,     0,     0,     0,     0,     0,   509,     0,   511,
       0,     0,     0,   513,   514,   198,     0,     0,     0,     0,
       0,     0,     0,   494,     0,   391,     0,     0,   431,     0,
       0,     0,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,     0,     0,     0,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   609,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   272,   526,     0,     0,   598,   379,
       0,     0,     0,     0,     0,   390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   665,     0,     0,     0,
       0,     0,     0,   390,     0,   390,     0,     0,     0,     0,
       0,   582,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   503,   505,   506,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     608,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   591,     0,     0,     0,     0,     0,    50,     0,   275,
     271,     0,     0,     0,     0,   290,     0,     0,     0,     0,
       0,   135,     0,   138,     0,   111,   114,   113,     0,     0,
       0,     0,     0,   122,   123,     0,     0,     0,     0,   128,
       0,   137,     0,   207,     0,   202,   209,     0,     0,     0,
       0,   205,     0,   215,     0,   210,     0,     0,     0,   213,
     354,     0,   360,   361,   362,     0,    58,    61,    56,    47,
     525,     0,     0,     0,   397,     0,     0,     0,   423,   426,
     428,   429,     0,   430,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   327,   408,     0,     0,
       0,     0,     0,     0,   421,   422,     0,   343,     0,   392,
     393,   394,     0,     0,     0,     0,   230,     0,     0,     0,
     236,     0,   469,   470,   471,   472,     0,   517,   478,     0,
       0,     0,     0,     0,     0,   483,   484,   485,   486,   487,
     488,   489,   490,     0,     0,     0,     0,   594,     0,     0,
       0,   297,   268,    24,    28,     0,   280,   281,   282,   277,
     279,   278,   297,     0,   297,   498,     0,     0,   499,     0,
       0,   508,   510,     0,   512,     0,   258,     0,     0,   306,
       0,     0,     0,   312,     0,     0,   150,     0,   149,     0,
     157,   158,     0,   243,     0,   245,   246,   145,     0,     0,
       0,   143,     0,   177,   182,   504,   188,   189,   192,     0,
     191,   161,     0,   173,     0,   169,     0,     0,     0,   165,
     166,   167,   168,   174,   507,   183,   175,   178,     0,     0,
     171,   181,     0,   196,   200,   614,   615,     0,     0,     0,
       0,     0,     0,   611,     0,     0,     0,   603,     0,     0,
       0,     0,     0,   624,     0,     0,     0,     0,     0,     0,
       0,    53,    54,   593,    52,     0,    64,    62,     0,   273,
      90,     0,     0,   390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   338,   339,   340,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   342,     0,     0,     0,     0,     0,   364,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,   389,     0,     0,   130,     0,
     133,     0,   136,     0,   117,   115,   118,   120,     0,     0,
     125,     0,     0,     0,     0,   208,     0,     0,     0,     0,
     216,   211,   224,     0,     0,    67,     0,   398,     0,   399,
       0,     0,     0,     0,   248,   435,     0,   438,     0,   440,
       0,   442,     0,     0,     0,     0,   473,     0,     0,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
       0,   460,     0,     0,     0,     0,     0,     0,     0,   395,
     396,   225,     0,   227,     0,     0,   231,     0,     0,     0,
     516,   479,     0,     0,     0,     0,     0,   491,     0,     0,
       0,   251,     0,     0,   297,    22,     0,    32,   286,   287,
     288,   284,   285,   283,    30,     0,     0,   502,     0,   266,
       0,     0,     0,   307,     0,     0,   311,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,   193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,     0,
       0,     0,     0,   612,   599,     0,   600,   604,   605,   606,
     607,     0,   625,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    63,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   341,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   664,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   387,     0,     0,   129,
     131,     0,     0,   110,     0,     0,   127,     0,     0,   201,
       0,     0,     0,   221,     0,   355,   400,   401,     0,     0,
       0,   434,     0,   437,     0,     0,     0,     0,     0,   406,
       0,     0,     0,     0,     0,     0,     0,   451,     0,   453,
     455,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     418,     0,     0,   226,   228,     0,   232,     0,     0,   241,
       0,   240,     0,     0,   480,   481,     0,   492,   329,   331,
     495,   496,    23,     0,     0,     0,   404,     0,     0,     0,
     309,   310,     0,   432,     0,     0,   242,   244,   146,   147,
     308,   144,   170,   172,   162,   163,   164,   179,   180,   194,
       0,     0,     0,     0,     0,   601,   602,   626,     0,   627,
       0,     0,     0,   623,   592,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   388,     0,     0,     0,   134,   121,     0,     0,     0,
     218,   219,   220,     0,   402,   403,     0,   436,   439,   441,
     443,   446,     0,   475,     0,   477,     0,   444,   447,     0,
     452,   454,   456,   457,     0,   459,   412,   414,   415,     0,
       0,   419,     0,   229,   235,     0,     0,   239,     0,   482,
       0,   500,     0,     0,     0,     0,     0,     0,   148,   616,
       0,     0,   620,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   663,     0,     0,     0,     0,     0,
       0,     0,     0,   382,     0,   132,     0,     0,     0,     0,
       0,   445,   476,   474,     0,   458,     0,     0,   461,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   628,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   383,   381,   124,   126,     0,   212,   433,   448,
     416,     0,   233,     0,     0,   238,     0,     0,     0,     0,
       0,     0,    82,     0,     0,   622,     0,     0,   632,     0,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,   253,   237,   515,     0,     0,     0,     0,   618,     0,
       0,   629,   630,     0,   634,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   417,     0,   199,
       0,     0,   619,     0,   631,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   621,   635,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,     0,     0,     0,     0,
     501,   264
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2051, -2051, -2051,  -208,  1226,  1687,  1688, -2051, -2051,  1690,
    1719,  1721,  1772, -2051, -2051,   299, -2051,  -493, -2051, -2051,
   -2051,  1814,  4191,   228,    -2,   401, -2051, -2051, -2051,     9,
     570,  -494,  -285, -2051,   -28,  -213,   878, -2051,   990,  1077,
    1080,  1075,  1145,   411,   -12,     0,   834, -2051,   109,  -564,
     -14, -2051,     5,  1144,     6, -2051,   -52, -2050
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   237,   238,   239,   240,   241,   242,   812,   811,   243,
     244,   245,   246,  1177,   987,  1465,   247,   498,   499,  1179,
     248,  2214,   679,   306,   249,   294,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   503,   981,   271,   296,   965,
     273,   274,   297,   276,   363,   278,   279,   839
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -662;
  const short int
  Parser::yytable_[] =
  {
       270,   504,   300,   364,   301,   275,   277,   317,   803,   804,
     295,   970,   983,   341,  2211,  2213,  2215,   307,   671,    34,
     813,    35,    41,   800,   319,   320,   307,    41,   307,  -655,
     533,     5,   663,   664,   290,  -656,   340,  1349,   541,   290,
     291,   338,    16,   896,   897,   561,   562,   974,   571,   344,
     896,   897,  1232,   346,   573,  1359,   307,   302,  1360,   575,
     362,   876,   877,   878,   879,   880,   880,   880,   880,   880,
     880,   880,   880,   880,   880,   880,   880,   880,   880,   333,
     576,    35,    34,   543,  1557,   544,   637,   638,    35,   545,
     559,   560,  1371,  1324,   901,   902,    35,   511,  -657,  1880,
     291,   901,   902,    35,   547,   548,    41,   291,     5,   272,
     326,   327,   303,   549,  1749,   291,   329,   330,   290,    16,
    1750,   328,   291,  1751,   345,   574,  2123,   331,   304,   311,
     336,   572,  2124,   339,   572,  2125,   337,   672,   371,  1561,
     372,   550,   551,   552,   553,   563,   564,  1210,  -658,  1112,
    1212,   334,   335,   342,   501,  1113,   942,   943,   944,   308,
     546,   554,   332,  1190,   361,   945,   946,   947,   948,  1191,
     322,  1210,   949,  1211,  1212,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   922,   923,   924,   925,   565,   566,
     497,   922,   923,   924,   925,   555,   637,   638,   556,   557,
    1197,   512,   513,   558,   343,   841,  1198,   399,  1199,   307,
     307,   362,   312,   950,  1200,    34,   951,   952,   953,   954,
     616,   955,   956,   666,   667,   957,   313,   314,   315,   316,
     586,   324,   544,   586,   325,   544,   587,  1118,   270,   587,
    1577,   589,  1486,   275,   277,   586,   542,   544,   374,  1215,
     375,   587,  2058,   366,   321,  1216,   323,   367,  1459,  1460,
    1461,  1462,  1463,   841,  1464,  1941,  1942,  1943,  1944,  1945,
     370,  1946,   597,   598,   881,   882,  2433,   586,  2434,   544,
     301,  2435,  2436,   587,   365,   586,  1162,   544,   586,  1763,
     544,   587,   400,   589,   587,   976,   373,   805,   542,   999,
    1305,   519,   307,   594,   307,   301,  1306,   801,   586,  1765,
     544,   586,  2005,   544,   587,   361,   378,   587,   586,   376,
     544,   377,   307,   379,  1217,  1603,   380,   670,  1613,   362,
     362,  1604,   831,  1634,  1614,  1644,  1686,  1712,  1732,  1635,
    1734,  1645,  1687,  1713,  1733,    35,  1733,   272,  1758,  1767,
    1771,  1778,   887,   888,  1759,  1768,  1772,  1779,   665,   666,
     667,   668,  1783,  1806,   291,   381,   382,   309,  1784,  1807,
     680,   682,   680,   680,   680,   680,   680,   680,   383,   680,
     680,  1813,  1817,   840,   841,  1823,   680,  1814,  1818,  1876,
     384,  1824,   710,   711,   712,  1877,   680,   680,   958,   959,
     960,   250,  2039,  2045,   961,   962,  2047,   963,  2040,  2046,
    1180,   680,  2048,  2049,   531,   542,  2051,  2056,   385,  2050,
     842,   310,  2052,  2057,   318,   386,   680,   680,   680,   680,
     680,   680,   680,   361,   361,  2063,  2081,   505,   506,  2083,
    2154,  2064,  2082,   659,   660,  2084,  2155,   307,   307,   387,
    2326,  2162,  1216,  2286,  2551,   807,   360,  2163,   843,  2287,
     567,  2290,  2307,  2311,  2313,   680,  1342,  2291,  2308,  2312,
    2314,  2340,   426,   790,   427,   569,  2344,  2341,   307,   680,
     680,   680,  2345,  2351,  2355,  2493,   855,   844,  2601,  2352,
    2356,  2494,   845,   806,  2602,   846,   847,   848,   849,  2642,
    2645,  2655,   388,  -661,  2658,  2643,  2646,  2656,   307,   680,
    2659,   389,   362,  2692,   680,   680,   857,   680,   680,  2693,
     680,   680,   390,   680,   680,   307,   307,   850,   851,   852,
     591,  2694,   593,   883,   884,   885,   886,  2695,   871,   872,
     873,   874,   875,   834,   855,   391,   680,   713,   714,   715,
     596,  2328,   392,  1216,   761,   762,   393,   394,   395,   396,
     858,   859,   860,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   298,   299,   857,   680,   980,   988,   397,   398,
     401,   275,   275,   990,   402,   403,   834,   404,   405,   406,
     407,   408,   409,   410,   411,   412,  1181,   413,   995,   414,
     415,   416,   417,   418,   419,  1189,   420,   360,   421,   422,
     423,   424,   425,   428,   429,   430,   361,   431,   858,   859,
     860,   861,   862,   863,   864,   865,   866,   867,   868,   869,
     432,   433,   434,   368,   369,   435,   436,   437,   438,   250,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   853,
     854,   448,   449,  1047,   307,   855,   450,   451,   452,   453,
     454,   455,   307,   456,   457,   763,   764,   458,   856,   459,
     460,   461,   462,   964,  1456,   982,   989,  1457,   463,   464,
     465,   466,   467,   468,   469,   857,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   795,   480,   481,   482,
     507,   508,   509,   510,   514,   515,   516,   517,   518,   520,
     521,   522,   523,   524,   525,   360,   360,   526,   527,   528,
     529,   530,   570,   577,   662,   590,   808,   568,   880,   858,
     859,   860,   861,   862,   863,   864,   865,   866,   867,   868,
     869,   578,   579,   825,   826,   580,   581,   341,   582,   583,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   584,   585,   588,   669,   674,   689,
     676,   802,   692,   693,   694,   695,   696,   768,   698,   699,
     700,   701,   702,   703,   704,   705,   706,   819,  1626,   709,
     769,   307,   716,   717,   718,   719,   720,   721,   722,   723,
     724,   725,   810,   727,   728,   729,   730,   731,   732,   733,
     734,   735,   736,   737,   738,   739,   740,   742,   827,   991,
     832,   996,   997,   998,   749,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   307,   710,  1000,  1001,
     765,   766,   767,  1002,  1003,   770,   771,   772,   773,   774,
     775,   776,   777,   778,   779,   780,   713,  1004,  1005,   784,
     786,   787,   788,  1006,  1007,   791,   792,   793,   794,  1008,
    1009,  1010,  1011,   799,  1012,  1013,  1014,  1015,  1016,  1017,
    1018,  1046,  1048,  1019,  1020,  1021,  1022,  1023,   307,  1024,
    1052,  1025,  1026,   307,  1027,  1028,  1029,  1030,   360,  1031,
    1032,  1033,  1034,  1035,  1036,  1037,  1293,   816,   637,   638,
     639,  1038,   640,  1039,   641,   642,  1040,  1041,  1042,   828,
     829,   830,   643,  1304,  1044,   644,   645,   646,   647,   648,
     649,   650,   651,  1043,  1049,   838,  1050,  1051,  1053,  1058,
    1054,  1057,  1055,  1059,  1060,  1063,  1064,   307,  1061,  1326,
    1062,  1065,  1066,  1067,  1292,  1089,  1068,  1071,  1090,   307,
    1069,  1070,   652,   362,  1072,   307,   653,  1073,  1074,  1075,
    1076,   654,   655,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
     362,  1084,   656,  1085,  1086,  1087,   307,   657,   658,    34,
      35,   347,   348,   349,   350,   351,    41,   352,   353,   354,
      45,    46,    47,    48,    49,   355,   356,   357,   500,   359,
    1088,  1091,  1092,   680,  1093,  1094,  1095,  1339,  1096,  1178,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,
    1107,  1327,  1337,  1115,  1108,  1117,  1109,  1110,  1111,   307,
    1114,   307,  1116,  1119,  1120,  1121,  1122,  1218,  1351,  1123,
    1124,  1367,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1222,  1137,  1138,   361,  1139,  1140,
    1141,  1142,  1143,  1144,  1561,  1291,   680,   680,  1145,  1146,
    1147,  1148,  1149,  1150,   361,    35,   347,   348,   349,   350,
     351,    41,   352,   353,   354,    45,    46,    47,    48,    49,
     355,   356,   357,   358,   359,  1151,  1152,  1153,   680,  1154,
    1155,  1156,  1157,   680,   680,  1158,  1233,  1159,  1163,  1160,
    1161,  1237,  1164,  1166,  1167,  1165,  1168,  1169,   307,   964,
    1170,  1171,  1175,  1182,  1172,  1348,    35,   347,   348,   349,
     350,   351,    41,   352,   353,   354,    45,    46,    47,    48,
      49,   355,   356,   357,   500,   359,  1173,  1174,  1183,  1184,
    1185,  1186,   307,  1187,  1188,  1366,  1192,  1196,  1193,  1194,
    1352,  1203,  1195,  1201,  1204,  1284,  1202,  1205,  1206,  1207,
    1213,  1208,  1209,  1219,  1214,  1220,  1221,  1223,  1224,  1225,
    1226,  1227,   680,  1284,  1228,  1229,  1230,   307,  1231,  1234,
    1235,  1236,  1238,  1239,  1240,  1241,  1242,  1243,  1244,   307,
    1245,  1246,  1247,  1248,  1310,  1249,  1250,  1251,  1938,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1940,
    1262,  1947,  1263,  1264,   680,  1265,  1266,  1267,  1723,  1724,
    1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,   680,  1276,
     680,  1277,  1278,  1279,  1280,  1281,  1282,   680,  1285,  1286,
    1287,  1288,   680,   680,   680,   307,   680,  1358,  1289,  1361,
    1290,   300,   680,   301,  1295,   680,   680,   680,   680,   680,
     680,  1296,  1298,  1299,  1300,   307,  1301,  1302,  1307,  1454,
    -366,   307,   307,  1303,  1308,  1309,  1569,   307,  1365,  1368,
    1369,   275,  1570,  1370,  1413,  1455,  1484,  1362,  1522,  1523,
    1524,  1563,  1364,  1572,  1575,  1581,  1726,  1573,  1574,  1576,
    1583,  1557,  1578,  1579,  1580,  1582,  1585,  1584,  1586,  1587,
    1588,  1589,  1593,  1590,  1594,   857,  1591,  1592,  1599,  1595,
    1601,  1596,  1597,  1598,  1605,  1600,  1606,  1602,  1607,  1608,
    1611,  1609,  1830,  1610,   680,  1615,  1431,  1612,   680,   360,
    1616,  1619,  1617,  1618,  1620,  1621,  1622,  1623,  1536,  1537,
    1538,  1624,  1627,  1629,  1625,  1630,   360,  1545,  1636,  1547,
    1548,  1638,  1637,  1639,  1640,  1641,  1642,  1643,  1646,  1666,
    1451,  1727,  1647,  1728,  1648,  1315,  1649,  1650,  1651,  1652,
    1653,  1321,  1654,   680,  1325,   989,  1655,  1656,  1657,  1658,
    1659,  1660,  1661,  1662,  1663,  1664,  1665,  1667,  1668,  1669,
    1670,  1671,  1672,  1674,  1673,  1478,  1675,  1676,  1677,  1679,
    1680,  1681,  2127,  1682,  1873,   889,  2002,  1487,  1683,  1684,
    1685,  1688,  1689,  1690,  1691,   307,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1705,   534,  1706,  1699,  1937,  1999,  1372,
    1700,   964,  1701,  1702,  1703,  1704,  1707,  1708,  1380,  1709,
    1710,  1711,  2128,  1717,  1714,  1735,  1831,  1466,  1715,  1390,
    1391,  1392,  1716,  1718,  1719,  1720,  1725,  1729,  1736,  1737,
    1738,  1401,  1739,  1542,  1740,  1741,  1403,  1742,  1404,  1405,
    1406,  1407,  1408,  1730,  1409,  1410,  1839,  1731,  1743,  1744,
    1745,  1746,  1747,  1560,  1748,  1753,  1752,  1756,  1754,  1566,
    1567,  1760,  1755,  1761,  1757,  1571,  1762,  1766,  1430,  1773,
    1764,  1769,  1432,  1433,  1434,  1435,  1436,  1770,  1774,  1775,
    1776,  1777,  1780,  1781,  2129,  2108,  1785,  2109,   890,  2110,
    1782,  1789,  1790,  1786,  1787,  1788,  1791,  1792,  1793,  1794,
    1795,  1796,   307,   362,  1797,  1800,  1801,  2194,  1798,  1799,
    1803,  1804,  1805,  1802,  2111,  1808,  2112,  2113,  1833,  1809,
    1810,  1811,  1812,  1815,  1469,  1816,  1819,  1472,  1820,  1821,
    1822,  1825,  1826,  1827,  1828,  1829,  1832,  1834,  1835,  1479,
    1480,  2243,  1836,  1837,  1838,  1840,  1874,  1875,   680,  1913,
    2000,  2003,  1489,  2038,  1490,  1491,  1493,  1495,  2001,  2004,
    2006,  2007,  2008,  1878,  2009,  2010,  2011,  2012,  2014,  2013,
    2015,  2016,  2017,  1501,  2020,  2018,   891,   894,  2025,  2019,
     892,  2021,  2022,  2023,  1520,  1521,  2024,  2026,  2027,  2028,
    2029,  2030,  2031,  2032,  1530,  2033,  2034,  2035,  2037,  1535,
    2041,  2042,  2043,  2044,  2071,  2053,  2054,   361,  1544,  1216,
    1546,  2055,  2059,  1722,  2060,  2061,  2062,  1919,  2065,  2066,
    2067,  2068,  2069,  2070,  2072,  2073,   680,  2074,  2075,   680,
     895,   896,   897,   898,  2076,  2077,  2078,  2079,  2080,  2085,
    2086,  2087,  2088,  2090,  2091,  2089,   893,  2092,  2093,  2097,
     984,  2094,  2095,  2096,  2098,  2101,  2099,  2100,  2102,  2103,
    2105,  2117,  2107,   899,  2106,  2115,  2116,  2119,  2118,  2114,
    2120,   900,  2121,  2126,  2122,  2130,  2131,  2132,  2133,  2373,
    2134,  2138,   901,   902,  2135,  2136,   903,  1961,  2137,  2139,
    2140,  2141,  2142,  2143,  2144,  2145,  2146,  2147,  2148,  2149,
    1632,  1633,  2150,  2151,  2153,  2152,  2156,  2157,  2158,  2159,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,  2160,  2161,  2164,  2165,   904,
    1841,   905,   906,   907,  2166,  2167,  2168,  2169,  2170,  2173,
    2192,  2288,   908,   909,  2289,  2293,  2526,  2292,   910,   911,
     912,   913,  2294,  2295,  2296,  2297,  2298,   680,  2300,   680,
    2299,   616,  2301,   914,   915,   916,   917,   918,  2302,   919,
     920,   921,   922,   923,   924,   925,   926,   927,   928,   929,
     930,   931,   932,   933,   934,   935,   936,   937,   938,   939,
     940,   617,  2303,  2304,  2305,  2306,  2309,  2310,  2624,  2315,
    2319,  1350,  2316,  2317,  2318,  2320,  2327,  2321,  2322,  2323,
    2324,  2325,  2329,  2330,  2331,  2332,  2333,  2334,  2343,  2346,
    2335,   618,   619,   620,   621,   622,  2336,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,  2337,
    2338,  2339,  2342,  2347,  2348,  2349,  2350,  2353,  2354,  2357,
    2358,  2359,  2360,  2361,  2527,   535,   536,  2366,   537,     0,
    2363,  2364,  2365,  2370,  2367,  2368,  2369,  2371,  2372,  2376,
    2374,  2375,  2377,  2378,  2379,  2380,  2381,  2382,  2383,  2384,
    2385,  2386,  2387,  2388,  2389,     0,     0,   538,     0,   539,
    2395,  2390,  2391,  2392,  2393,  2394,  2396,  2397,  2398,   360,
    2399,  2400,     0,  2403,  1843,  2401,  2404,  1845,  2402,  2471,
    2472,  2473,  2475,  2474,  2476,   941,  2477,  2478,  2480,  1852,
    1853,  2479,  2481,  2482,  2484,  2483,  2485,  2486,  2487,   635,
     307,   307,  2488,  2489,  2490,  2491,  2492,  2495,  2497,  2498,
     540,  2500,  2496,  2501,  2502,  2503,  2499,  1869,   636,  2505,
    2506,  2507,   502,  2504,  2508,  2511,     0,  2513,  2509,  2510,
    2514,  2517,  2512,     0,  2515,  2362,  1879,  1881,  2193,  2516,
    2518,  2519,  2520,  2521,  2522,  2523,  1884,  2528,  2524,  2529,
    2525,  2530,  2531,  2532,  1893,     0,  2533,  2534,  2535,  2573,
    2536,  2537,  2572,  2574,  2575,  2581,  2576,  2577,  2578,  2579,
    1907,  1908,  1909,  1910,  1911,  2580,  2582,  2583,  2584,  2585,
    2586,  2587,   680,  2588,   680,   680,  2589,   680,  2590,     0,
    2591,  2592,  2593,  2594,  2595,  2596,  2597,  2598,  2599,  2600,
    2603,  2604,  1926,  1927,  2605,  2632,  2633,  2634,  2635,  2636,
    2637,  2638,  2639,  2640,     0,  2641,  2660,   592,     0,     0,
    2644,  2647,   595,  2648,  2649,  2650,  2651,  2653,  2654,  2657,
    2661,  2678,  2679,  2680,  2681,  2682,  2683,  2684,  2685,  2688,
       0,     0,   599,  2686,  2687,   600,  2689,  2690,  1954,  2691,
     661,  2706,  2707,  2708,  2709,  2712,  2710,  2711,   673,  2713,
     675,   680,  2714,  2715,  2722,  2723,   680,  2724,   680,  2725,
    2726,  2727,  2732,  2733,  2734,  2735,     0,  2745,  2739,  2740,
     677,   678,  2741,  2750,  2746,  2747,  2751,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2171,  2172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     782,   783,     0,   785,     0,     0,   789,     0,  1047,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2418,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   822,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   680,     0,     0,     0,     0,   833,   837,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   992,   993,   680,     0,
     994,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1879,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   838,   838,   838,     0,     0,
       0,     0,  1047,     0,     0,     0,     0,  1045,  2225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1056,     0,     0,     0,  2234,  2235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2407,     0,     0,     0,
       0,     0,  2249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   680,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2276,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   307,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   680,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   680,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   680,     0,     0,   680,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   680,     0,     0,     0,     0,
    2539,     0,     0,     0,     0,     0,     0,     0,     0,  1879,
       0,     0,     0,     0,     0,   680,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   838,     0,   838,
       0,     0,   838,   838,     0,     0,     0,  2440,  2441,  2442,
    2443,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2451,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2457,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2606,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1311,  1312,  1313,     0,     0,  1314,  1316,
    1317,  1318,  1319,  1320,     0,  1322,  1323,     0,     0,     0,
    1328,  1329,  1330,  1331,  1332,  1333,  1334,     0,  1336,     0,
    1338,     0,  1340,  1341,     0,  1343,  1344,  1345,  1346,  1347,
       0,     0,     0,     0,  1353,  1354,  1355,  1356,  1357,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1373,  1374,     0,  1375,  1376,  1377,  1378,
    1379,     0,  1381,  1382,  1383,  1384,  1385,  1386,     0,  1387,
       0,     0,     0,     0,     0,   838,  1393,  1394,  1395,  1396,
    1397,  1398,  1399,  1400,     0,  1402,     0,     0,     0,  2557,
       0,     0,     0,     0,     0,  2561,     0,     0,     0,     0,
    1411,     0,     0,     0,  1414,  1415,  1416,     0,     0,  1419,
    1420,  1421,  1422,  1423,  1424,     0,  1425,  1426,  1427,  1428,
    1429,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
    1447,     0,     0,     0,  1448,  1449,     0,     0,     0,  1450,
       0,     0,     0,     0,     0,     0,     0,  1452,  1453,     0,
       0,     0,  2618,     0,     0,     0,  2622,     0,     0,  1458,
       0,     0,     0,     0,     0,  1467,  1468,     0,  1470,  1471,
       0,     0,  1473,     0,  1474,  1475,     0,     0,     0,     0,
    1477,     0,     0,     0,  1481,  1482,  1483,     0,     0,     0,
    1485,     0,     0,     0,  1488,     0,     0,     0,     0,  1492,
    1494,  1496,  1497,  1498,  1499,  1500,     0,     0,  1502,  1503,
    1504,     0,  1505,  1506,  1507,  1508,  1509,  1510,     0,  1512,
    1513,  1514,  1515,  1516,  1517,  1518,  1519,     0,     0,     0,
       0,     0,     0,  1526,     0,  1528,  1529,     0,  1531,  1532,
    1533,     0,     0,     0,     0,     0,     0,     0,  2701,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1558,     0,  1559,     0,
       0,  1562,  2719,  1564,  1565,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,  1721,     0,
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
       0,     0,     0,     0,     0,     0,     0,  1842,  1844,     0,
       0,  1846,  1847,  1848,  1849,     0,  1850,     0,  1851,     0,
       0,     0,     0,     0,  1854,  1855,  1856,     0,     0,  1857,
    1858,  1859,  1860,     0,  1861,     0,  1862,     0,  1863,     0,
       0,  1864,  1865,  1866,  1867,     0,     0,     0,  1868,     0,
       0,  1870,     0,     0,     0,  1872,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1882,     0,     0,     0,     0,  1883,     0,     0,     0,
    1885,  1886,  1887,  1888,  1889,  1890,  1891,  1892,  1894,  1895,
    1896,  1897,  1898,  1899,  1900,  1901,  1902,  1903,  1904,  1905,
       0,     0,  1906,     0,     0,     0,     0,     0,     0,     0,
    1912,     0,     0,     0,     0,     0,  1914,  1915,  1916,  1917,
       0,  1918,  1920,  1921,     0,  1922,     0,     0,     0,     0,
       0,     0,     0,     0,  1925,     0,     0,  1928,  1929,     0,
       0,     0,     0,     0,     0,     0,     0,  1930,  1931,  1932,
    1933,     0,  1934,  1935,  1936,     0,     0,     0,     0,  1939,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1948,  1949,     0,  1950,  1951,     0,     0,  1952,     0,  1953,
       0,     0,  1955,     0,  1956,  1957,  1958,     0,  1959,  1960,
       0,     0,     0,  1962,     0,     0,  1963,     0,  1964,     0,
       0,     0,  1965,  1966,  1967,     0,  1968,     0,     0,     0,
       0,     0,     0,  1969,     0,     0,  1970,     0,  1971,     0,
    1972,  1973,  1974,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1975,  1976,     0,     0,  1977,     0,     0,     0,
       0,  1978,  1979,  1980,  1981,  1982,  1983,     0,  1984,  1985,
    1986,     0,  1987,  1988,  1989,  1990,  1991,     0,  1992,  1993,
    1994,     0,  1996,     0,  1998,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2174,     0,
    2175,  2176,     0,  2177,     0,  2178,     0,  2179,     0,     0,
       0,     0,  2180,  2181,     0,  2182,  2183,  2184,  2185,     0,
    2186,  2187,  2188,  2189,     0,     0,     0,  2190,  2191,     0,
       0,     0,     0,     0,     0,     0,  2195,  2196,     0,     0,
    2197,     0,  2198,     0,  2199,     0,  2200,  2201,  2202,  2203,
       0,  2204,  2205,  2206,  2207,  2208,  2209,     0,  2210,  2212,
       0,  2216,  2217,  2218,  2219,     0,  2220,  2221,  2222,  2223,
    2224,     0,  2226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2231,  2232,     0,     0,  2233,     0,     0,  2236,
    2237,     0,  2238,  2239,  2240,     0,  2241,  2242,     0,     0,
    2244,     0,     0,     0,     0,     0,     0,     0,     0,  2245,
    2246,     0,  2247,     0,  2248,     0,  2250,     0,  2251,  2252,
       0,  2253,  2254,  2255,     0,  2256,  2257,  2258,  2259,  2260,
    2261,  2262,     0,  2263,  2264,  2265,  2266,  2267,  2268,  2269,
    2270,  2271,     0,  2272,  2273,  2274,  2275,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2278,  2279,  2280,
       0,  2282,     0,  2284,  2285,     0,     0,     0,     0,     0,
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
       0,  2405,  2406,     0,     0,  2408,  2409,     0,  2410,  2411,
       0,  2412,  2413,     0,  2414,  2415,  2416,     0,  2417,     0,
       0,     0,     0,  2419,  2420,     0,  2421,     0,  2422,  2423,
    2424,  2425,  2426,     0,  2427,  2428,  2429,  2430,  2431,  2432,
       0,     0,     0,     0,     0,     0,     0,  2437,  2438,  2439,
       0,     0,     0,     0,     0,  2444,  2445,     0,     0,  2446,
       0,  2447,  2448,     0,  2449,     0,     0,     0,     0,     0,
    2452,     0,     0,     0,     0,     0,     0,  2453,  2454,  2455,
       0,  2456,     0,  2458,     0,     0,  2459,     0,  2460,  2461,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2462,  2463,  2464,  2465,  2466,     0,
       0,     0,     0,     0,  2468,  2469,  2470,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2538,  2540,  2541,     0,
       0,  2542,  2543,  2544,     0,     0,     0,  2545,     0,     0,
    2546,     0,     0,     0,     0,     0,  2547,     0,  2548,     0,
    2549,     0,     0,  2550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2552,  2553,     0,  2554,     0,     0,  2555,
    2556,     0,     0,     0,  2558,     0,  2559,  2560,     0,  2562,
    2563,  2564,     0,     0,  2565,  2566,     0,  2567,     0,  2569,
    2570,  2571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2607,     0,
    2608,  2609,  2610,  2611,  2612,     0,     0,     0,  2613,     0,
    2614,  2615,     0,  2616,  2617,     0,  2619,  2620,  2621,     0,
    2623,     0,  2625,  2626,  2627,     0,     0,  2629,  2630,  2631,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2662,     0,     0,     0,     0,  2663,     0,     0,  2665,     0,
       0,  2667,  2668,  2669,  2670,  2671,     0,  2672,  2673,     0,
    2674,  2675,     0,  2676,     0,  2677,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2696,  2697,     0,     0,     0,     0,  2698,  2699,
    2700,     0,     0,  2702,  2703,     0,     0,  2704,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2716,     0,  2717,     0,  2718,     0,     0,  2720,     0,     0,
       0,     0,     0,     0,     0,     0,  2728,  2729,  2730,  2731,
       0,     0,     0,     0,     0,     0,  2736,  2737,  2738,     0,
       0,     0,     0,  2742,  2743,  2744,     0,     0,     0,     0,
    2748,  2749,   681,   683,   684,   685,   686,   687,   688,     0,
     690,   691,     0,     0,     0,     0,     0,   697,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   707,   708,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   726,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   741,   743,   744,
     745,   746,   747,   748,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   781,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     796,   797,   798,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     809,     0,     0,     0,     0,   814,   815,     0,   817,   818,
       0,   820,   821,     0,   823,   824,   532,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     0,     0,   870,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,    26,     0,    27,    28,    29,   967,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,   139,     0,     0,     0,     0,   140,     0,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,     0,   183,
     184,   185,   186,   187,     0,     0,     0,     0,     0,   188,
     189,   190,   191,   192,   193,   194,   195,     0,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,     0,     0,
       0,     0,   205,     0,   206,   207,   208,     0,     0,     0,
     209,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,   215,   216,   217,   218,   219,
     220,     0,   221,   222,     0,     0,     0,     0,   223,   224,
       0,     0,     0,   225,     0,   226,   227,   228,   229,   230,
       0,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1335,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1388,  1389,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1412,
       0,     0,     0,     0,  1417,  1418,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1525,
       0,  1527,     0,     0,     0,     0,     0,     0,  1534,     0,
       0,     0,     0,  1539,  1540,  1541,     0,  1543,     0,     0,
       0,     0,     0,  1549,     0,     0,  1551,  1552,  1553,  1554,
    1555,  1556,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1628,     0,     0,     0,  1631,
       0,     0,     0,     1,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
       0,    27,    28,    29,  1678,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,   105,   106,     0,     0,     0,     0,     0,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,   139,
       0,     0,     0,     0,   140,     0,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     0,  1871,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,     0,     0,  1923,     0,     0,
    1924,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,     0,   183,   184,   185,
     186,   187,     0,     0,     0,     0,     0,   188,   189,   190,
     191,   192,   193,   194,   195,     0,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,     0,     0,     0,     0,
     205,     0,   206,   207,   208,     0,     0,     0,   209,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,   215,   216,   217,   218,   219,   220,     0,
     221,   222,     0,     0,     0,     0,   223,   224,     0,     0,
       0,   225,     0,   226,   227,   228,   229,   230,     0,   231,
     232,   233,   234,   235,   236,     0,     0,     0,  1995,     0,
    1997,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       0,     4,     0,     0,     0,   968,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,     0,     0,   969,    18,    19,   970,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,    30,
      31,    32,     0,    33,     0,    35,   281,   282,   283,   284,
     971,    41,   972,   287,   973,    45,    46,    47,    48,    49,
     355,   356,   974,   500,   359,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,     0,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,    90,     0,    92,
      93,    94,   292,   293,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,   105,   106,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,   134,     0,     0,     0,   942,   943,   944,     0,     0,
     136,   137,   138,   139,   945,   946,   947,   948,   140,     0,
       0,   949,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2227,     0,  2228,  2229,     0,  2230,   142,
     143,   144,   145,     0,     0,     0,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,     0,
     163,   164,   950,     0,     0,   951,   952,   953,   954,     0,
     955,   956,   165,   166,   975,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2277,     0,     0,     0,     0,  2281,     0,  2283,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     976,   167,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,   977,   175,   176,   978,   178,   179,   180,   181,   182,
       0,   183,     0,   185,   186,     0,   979,     0,     0,     0,
       0,   188,   189,   190,   191,   192,   193,   194,   195,     0,
       0,   196,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   211,   212,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
     218,   219,   220,     0,   221,   222,     0,   958,   959,   960,
     223,   224,     0,   961,   962,     0,   963,   226,   227,   228,
       0,     0,     0,     0,     1,     2,     3,     0,     4,     0,
       0,     0,   985,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,  2450,     0,     0,    30,    31,    32,     0,
      33,     0,    35,   281,   282,   283,   284,   971,    41,   986,
     287,   973,    45,    46,    47,    48,    49,   355,   356,   357,
     500,   359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2467,
       0,     0,     0,     0,     0,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,    78,     0,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,    90,     0,    92,    93,    94,   292,
     293,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,   105,   106,     0,     0,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,   134,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,   138,
     139,     0,     0,     0,     0,   140,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2568,   142,   143,   144,   145,
       0,     0,     0,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,   163,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2628,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2652,     0,     0,   167,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2664,     0,     0,  2666,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,     0,   183,     0,
     185,   186,     0,     0,     0,     0,     0,     0,   188,   189,
     190,   191,   192,   193,   194,   195,     0,     0,   196,   197,
     198,   199,   200,   201,   202,   203,  2705,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2721,     0,     0,     0,
       0,     0,     0,   211,   212,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,   218,   219,   220,
       0,   221,   222,     0,     0,     0,     0,   223,   224,     1,
       2,     3,     0,     4,   226,   227,   228,  1568,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    30,    31,    32,     0,    33,     0,    35,   281,   282,
     283,   284,   971,    41,   986,   287,   973,    45,    46,    47,
      48,    49,   355,   356,   357,   500,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,     0,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,    90,
       0,    92,    93,    94,   292,   293,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,   105,   106,     0,
       0,     0,     0,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,     0,     0,     0,
       0,     0,   136,   137,   138,   139,     0,     0,     0,     0,
     140,     0,     0,     0,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,   145,     0,     0,     0,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,     0,   163,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,     0,   183,     0,   185,   186,     0,     0,     0,
       0,     0,     0,   188,   189,   190,   191,   192,   193,   194,
     195,     0,     0,   196,   197,   198,   199,   200,   201,   202,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   211,   212,
     213,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,   218,   219,   220,     0,   221,   222,     0,     0,
       0,     0,   223,   224,     1,     2,     3,     0,     4,   226,
     227,   228,     0,     0,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     0,    16,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,    30,    31,    32,     0,
      33,     0,    35,   281,   282,   283,   284,   285,    41,   286,
     287,   288,    45,    46,    47,    48,    49,     0,   289,     0,
     290,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,    78,     0,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,    90,     0,    92,    93,    94,   292,
     293,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,   105,   106,     0,     0,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,   134,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,   138,
     139,     0,     0,     0,     0,   140,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,   145,
       0,     0,     0,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,   163,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,     0,   183,     0,
     185,   186,     0,     0,     0,     0,     0,     0,   188,   189,
     190,   191,   192,   193,   194,   195,     0,     0,   196,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,   212,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,   218,   219,   220,
       0,   221,   222,     0,     0,     0,     0,   223,   224,     1,
       2,     3,     0,     4,   226,   227,   228,     0,     0,     0,
       0,     0,   835,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    30,    31,    32,     0,    33,     0,    35,   281,   282,
     283,   284,   836,    41,   286,   287,   288,    45,    46,    47,
      48,    49,     0,   289,     0,   290,   291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,     0,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,    90,
       0,    92,    93,    94,   292,   293,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,   105,   106,     0,
       0,     0,     0,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,     0,     0,     0,
       0,     0,   136,   137,   138,   139,     0,     0,     0,     0,
     140,     0,     0,     0,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,   145,     0,     0,     0,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,     0,   163,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,     0,   183,     0,   185,   186,     0,     0,     0,
       0,     0,     0,   188,   189,   190,   191,   192,   193,   194,
     195,     0,     0,   196,   197,   198,   199,   200,   201,   202,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   211,   212,
     213,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,   218,   219,   220,     0,   221,   222,     0,     0,
       0,     0,   223,   224,     1,     2,     3,     0,     4,   226,
     227,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,    30,    31,    32,     0,
      33,     0,    35,   281,   282,   283,   284,   285,    41,   286,
     287,   288,    45,    46,    47,    48,    49,     0,   289,     0,
     290,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,    78,     0,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,    90,     0,    92,    93,    94,   292,
     293,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,   105,   106,     0,     0,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,   134,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,   138,
     139,     0,     0,     0,     0,   140,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,   145,
       0,     0,     0,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,   163,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   966,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,     0,   183,     0,
     185,   186,     0,     0,     0,     0,     0,     0,   188,   189,
     190,   191,   192,   193,   194,   195,     0,     0,   196,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,   212,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,   218,   219,   220,
       0,   221,   222,     0,     0,     0,     0,   223,   224,     0,
       0,     0,     0,     0,   226,   227,   228,     1,     2,     3,
       0,   305,     0,  1294,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,     0,     0,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,    30,
      31,    32,     0,    33,     0,    35,   281,   282,   283,   284,
     285,    41,   286,   287,   288,    45,    46,    47,    48,    49,
       0,   289,     0,   290,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,     0,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,    90,     0,    92,
      93,    94,   292,   293,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,   105,   106,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,   134,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,   138,   139,     0,     0,     0,     0,   140,     0,
       0,     0,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     143,   144,   145,     0,     0,     0,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,     0,
     163,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
       0,   183,     0,   185,   186,     0,     0,     0,     0,     0,
       0,   188,   189,   190,   191,   192,   193,   194,   195,     0,
       0,   196,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   211,   212,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
     218,   219,   220,     0,   221,   222,     0,     0,     0,     0,
     223,   224,     0,     0,     0,     0,     0,   226,   227,   228,
       1,     2,     3,     0,  1283,     0,  1297,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,    30,    31,    32,     0,    33,     0,    35,   281,
     282,   283,   284,   285,    41,   286,   287,   288,    45,    46,
      47,    48,    49,     0,   289,     0,   290,   291,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,    78,     0,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
      90,     0,    92,    93,    94,   292,   293,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,   105,   106,
       0,     0,     0,     0,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,   134,     0,     0,     0,     0,     0,
       0,     0,     0,   136,   137,   138,   139,     0,     0,     0,
       0,   140,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,   145,     0,     0,     0,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,   163,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,     0,   183,     0,   185,   186,     0,     0,
       0,     0,     0,     0,   188,   189,   190,   191,   192,   193,
     194,   195,     0,     0,   196,   197,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   211,
     212,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,   218,   219,   220,     0,   221,   222,     0,
       0,     0,     0,   223,   224,     0,     0,     0,     0,     0,
     226,   227,   228,     1,     2,     3,     0,     4,  1550,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     0,     0,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,    30,    31,    32,     0,    33,
       0,    35,   281,   282,   283,   284,   285,    41,   286,   287,
     288,    45,    46,    47,    48,    49,     0,   289,     0,   290,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,     0,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,    90,     0,    92,    93,    94,   292,   293,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,   105,   106,     0,     0,     0,     0,     0,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,   134,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,   139,
       0,     0,     0,     0,   140,     0,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,   145,     0,
       0,     0,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,     0,   163,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,     0,   183,     0,   185,
     186,     0,     0,     0,     0,     0,     0,   188,   189,   190,
     191,   192,   193,   194,   195,     0,     0,   196,   197,   198,
     199,   200,   201,   202,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   211,   212,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,   218,   219,   220,     0,
     221,   222,     0,     0,     0,     0,   223,   224,     1,     2,
       3,     0,     4,   226,   227,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
      30,    31,    32,     0,    33,     0,    35,   281,   282,   283,
     284,   285,    41,   286,   287,   288,    45,    46,    47,    48,
      49,     0,   289,     0,   290,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,    78,     0,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,    90,     0,
      92,    93,    94,   292,   293,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,   105,   106,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,   138,   139,     0,     0,     0,     0,   140,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,   145,     0,     0,     0,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,   163,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,     0,   183,     0,   185,   186,     0,     0,     0,     0,
       0,     0,   188,   189,   190,   191,   192,   193,   194,   195,
       0,     0,   196,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,   212,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,   218,   219,   220,     0,   221,   222,     0,     0,     0,
       0,   223,   224,     1,     2,     3,     0,   305,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     0,     0,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,    30,    31,    32,     0,    33,
       0,    35,   281,   282,   283,   284,   285,    41,   286,   287,
     288,    45,    46,    47,    48,    49,     0,   289,     0,   290,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,     0,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,    90,     0,    92,    93,    94,   292,   293,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,   105,   106,     0,     0,     0,     0,     0,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,   134,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,   139,
       0,     0,     0,     0,   140,     0,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,   145,     0,
       0,     0,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,     0,   163,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,     0,   183,     0,   185,
     186,     0,     0,     0,     0,     0,     0,   188,   189,   190,
     191,   192,   193,   194,   195,     0,     0,   196,   197,   198,
     199,   200,   201,   202,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   211,   212,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,   218,   219,   220,     0,
     221,   222,     0,     0,     0,     0,   223,   224,     1,     2,
       3,     0,  1283,   226,   227,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
      30,    31,    32,     0,    33,     0,    35,   281,   282,   283,
     284,   285,    41,   286,   287,   288,    45,    46,    47,    48,
      49,     0,   289,     0,   290,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,    78,     0,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,    90,     0,
      92,    93,    94,   292,   293,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,   105,   106,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,   138,   139,     0,     0,     0,     0,   140,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,   145,     0,     0,     0,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,   163,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,     0,   183,     0,   185,   186,     0,     0,     0,     0,
       0,     0,   188,   189,   190,   191,   192,   193,   194,   195,
       0,     0,   196,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,   212,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,   218,   219,   220,     0,   221,   222,     0,     0,     0,
       0,   223,   224,     1,     2,     3,     0,     4,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     0,     0,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,    30,    31,    32,     0,    33,
       0,    35,   281,   282,   283,   284,   836,    41,   286,   287,
     288,    45,    46,    47,    48,    49,     0,   289,     0,   290,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,     0,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,    90,     0,    92,    93,    94,   292,   293,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,   105,   106,     0,     0,     0,     0,     0,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,   134,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,   139,
       0,     0,     0,     0,   140,     0,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,   145,     0,
       0,     0,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,     0,   163,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,     0,   183,     0,   185,
     186,     0,     0,     0,     0,     0,     0,   188,   189,   190,
     191,   192,   193,   194,   195,     0,     0,   196,   197,   198,
     199,   200,   201,   202,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   211,   212,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,   218,   219,   220,     1,
     221,   222,     0,     4,     0,     0,   223,   224,     0,     0,
       0,     0,     0,   226,   227,   228,     0,     0,     0,     0,
       0,    13,    14,     0,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    30,    31,    32,     0,    33,     0,    35,   281,   282,
     283,   284,   285,    41,   286,   287,   288,    45,    46,    47,
      48,    49,     0,   289,     0,   290,   291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,     0,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,    90,
       0,    92,    93,    94,   292,   293,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,   105,   106,     0,
       0,     0,     0,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,     0,     0,     0,
       0,     0,   136,   137,   138,   139,     0,     0,     0,     0,
     140,     0,     0,     0,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,   145,     0,     0,     0,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,     0,   163,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,     0,   183,     0,   185,   186,     0,     0,     0,
       0,     0,     0,   188,   189,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   211,   212,
     213,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,   217,   218,   219,   220,     0,   221,   222,     0,     0,
      13,    14,   223,   224,    17,    18,    19,     0,     0,   226,
     227,   228,     0,     0,     0,     0,    27,     0,     0,     0,
      30,    31,    32,     0,    33,     0,    35,   281,   282,   283,
     284,   285,    41,   286,   287,   288,    45,    46,    47,    48,
      49,     0,   289,     0,   290,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,    78,     0,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,    90,     0,
      92,    93,    94,   292,   293,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,   105,   106,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,   138,   139,     0,     0,     0,     0,   140,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,   145,     0,     0,     0,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,   163,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,     0,   183,     0,   185,   186,     0,     0,     0,     0,
       0,     0,   188,   189,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,   212,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,   218,   219,   220,     0,   221,   222,     0,     0,     0,
       0,   223,   224,     0,     0,     0,     0,     0,   226,   227,
     228
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,   209,     4,    55,     4,     0,     0,    21,   501,   502,
       1,    38,   576,    19,  2064,  2065,  2066,    17,    43,    56,
     513,    57,    63,   111,    24,    25,    26,    63,    28,    19,
     238,    23,    43,    44,    75,    19,    50,    64,   246,    75,
      76,    19,    34,   160,   161,     5,     6,    74,    21,    15,
     160,   161,    22,    15,    19,    58,    56,    13,    61,    90,
      55,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,    19,
     111,    57,    56,    13,   201,    15,   267,   268,    57,    19,
      10,    11,    53,    62,   211,   212,    57,    71,    19,    53,
      76,   211,   212,    57,   100,   101,    63,    76,    23,     0,
     100,   101,    13,   109,    14,    76,   100,   101,    75,    34,
      20,   111,    76,    23,    90,    90,    14,   111,    13,    20,
      13,   104,    20,   111,   104,    23,    19,   162,    13,   320,
      15,    91,    92,    93,    94,   105,   106,    20,    19,    14,
      23,    91,    92,   159,   206,    20,   197,   198,   199,    13,
      90,   111,    19,    14,    55,   206,   207,   208,   209,    20,
      13,    20,   213,    22,    23,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   301,   302,   303,   304,   107,   108,
     204,   301,   302,   303,   304,     4,   267,   268,     7,     8,
      14,   215,   216,    12,    19,    51,    20,    19,    14,   209,
     210,   206,    53,   254,    20,    56,   257,   258,   259,   260,
     267,   262,   263,   370,   371,   266,    67,    68,    69,    70,
      13,    13,    15,    13,    13,    15,    19,    20,   238,    19,
      20,    14,    88,   238,   238,    13,    19,    15,    13,    16,
      15,    19,    20,    13,    26,    22,    28,    13,   422,   423,
     424,   425,   426,    51,   428,   422,   423,   424,   425,   426,
      13,   428,   324,   325,   559,   560,  2326,    13,  2328,    15,
     280,  2331,  2332,    19,    56,    13,    14,    15,    13,    14,
      15,    19,    19,    14,    19,   322,    13,   505,    19,    20,
      14,    19,   302,   305,   304,   305,    20,   395,    13,    14,
      15,    13,    14,    15,    19,   206,    13,    19,    13,    13,
      15,    15,   322,    13,    19,    14,    13,   341,    14,   324,
     325,    20,   540,    14,    20,    14,    14,    14,    14,    20,
      14,    20,    20,    20,    20,    57,    20,   238,    14,    14,
      14,    14,   565,   566,    20,    20,    20,    20,   369,   370,
     371,   372,    14,    14,    76,    13,    13,   403,    20,    20,
     370,   371,   372,   373,   374,   375,   376,   377,    13,   379,
     380,    14,    14,    50,    51,    14,   386,    20,    20,    14,
      13,    20,   154,   155,   156,    20,   396,   397,   439,   440,
     441,     0,    14,    14,   445,   446,    14,   448,    20,    20,
     402,   411,    20,    14,     0,    19,    14,    14,    13,    20,
      87,    20,    20,    20,    23,    13,   426,   427,   428,   429,
     430,   431,   432,   324,   325,    14,    14,   209,   210,    14,
      14,    20,    20,   334,   335,    20,    20,   447,   448,    13,
      20,    14,    22,    14,  2504,   507,    55,    20,   125,    20,
      17,    14,    14,    14,    14,   465,  1030,    20,    20,    20,
      20,    14,    13,   473,    15,   103,    14,    20,   478,   479,
     480,   481,    20,    14,    14,    14,   332,   154,    14,    20,
      20,    20,   159,   507,    20,   162,   163,   164,   165,    14,
      14,    14,    13,    19,    14,    20,    20,    20,   508,   509,
      20,    13,   507,    14,   514,   515,   362,   517,   518,    20,
     520,   521,    13,   523,   524,   525,   526,   194,   195,   196,
     302,    14,   304,   561,   562,   563,   564,    20,   550,   551,
     552,   553,   554,   543,   332,    13,   546,   154,   155,   156,
     322,    20,    13,    22,   445,   446,    13,    13,    13,    13,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     2,     3,   362,   575,   576,   577,    13,    13,
      13,   576,   577,   577,    13,    13,   586,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   804,    13,   589,    13,
      13,    13,    13,    13,    13,   813,    13,   206,    13,    13,
      13,    13,    13,    13,    13,    13,   507,    13,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
      13,    13,    13,    63,    64,    13,    13,    13,    13,   238,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   326,
     327,    13,    13,   663,   664,   332,    13,    13,    13,    13,
      13,    13,   672,    13,    13,   447,   448,    13,   345,    13,
      13,    13,    13,   574,  1177,   576,   577,  1180,    13,    13,
      13,    13,    13,    13,    13,   362,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   478,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   324,   325,    13,    13,    13,
      13,    13,     4,    13,   326,    14,   508,    18,  1232,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,    19,    19,   525,   526,    19,    19,    19,    15,    15,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    19,    19,    19,   368,   266,   378,
      15,    54,   381,   382,   383,   384,   385,    53,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   438,  1362,   398,
      53,   801,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,    53,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,    62,    79,
     417,    20,    14,    14,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   846,   154,    20,    20,
     449,   450,   451,    14,    14,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   154,    13,    13,   468,
     469,   470,   471,    13,    13,   474,   475,   476,   477,    13,
      13,    13,    13,   482,    13,    13,    13,    13,    13,    13,
      13,   663,   664,    13,    13,    13,    13,    13,   898,    13,
     672,    13,    13,   903,    13,    13,    13,    13,   507,    13,
      13,    13,    13,    13,    13,    13,   968,   516,   267,   268,
     269,    13,   271,    13,   273,   274,    13,    13,    13,   528,
     529,   530,   281,   985,    13,   284,   285,   286,   287,   288,
     289,   290,   291,    20,    13,   544,    13,    13,    16,    20,
      15,    14,    16,    14,    14,    14,    14,   957,    20,    55,
      16,    16,    14,    16,    15,    13,    20,    14,    13,   969,
      20,    20,   321,   968,    20,   975,   325,    20,    20,    20,
      20,   330,   331,    20,    20,    20,    20,    20,    20,    20,
     985,    14,   341,    20,    20,    20,   996,   346,   347,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      20,    14,    20,  1023,    20,    20,    20,    71,    20,   801,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    62,    64,    14,    20,    14,    20,    20,    20,  1049,
      20,  1051,    20,    16,    20,    20,    20,    16,    64,    20,
      20,  1061,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,   846,    20,    20,   968,    14,    14,
      20,    20,    20,    20,   320,    19,  1086,  1087,    20,    20,
      20,    20,    20,    20,   985,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    20,    20,    20,  1118,    20,
      20,    20,    14,  1123,  1124,    14,   898,    14,    14,    20,
      20,   903,    14,    14,    14,    20,    14,    14,  1138,  1030,
      14,    14,    14,    14,    20,  1036,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    20,    20,    14,    14,
      20,    14,  1172,    13,    13,    71,    20,    13,    20,    20,
      55,    14,    20,    20,    14,   957,    20,    14,    20,    20,
      14,    20,    20,    13,    20,    13,    13,    13,    13,    13,
      13,    13,  1202,   975,    13,    13,    13,  1207,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,  1219,
      13,    13,    13,    13,   996,    13,    13,    13,  1721,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,  1732,
      13,  1734,    13,    13,  1244,    13,    13,    13,  1456,  1457,
      13,    13,    13,    13,    13,    13,    13,    13,  1258,    13,
    1260,    13,    13,    13,    13,    13,    13,  1267,    13,    13,
      13,    13,  1272,  1273,  1274,  1275,  1276,  1049,    13,  1051,
      13,  1283,  1282,  1283,    13,  1285,  1286,  1287,  1288,  1289,
    1290,    19,    13,    13,    13,  1295,    13,    20,    13,   392,
      14,  1301,  1302,    19,    16,    16,  1306,  1307,    16,    13,
      13,  1306,  1306,    13,    13,    20,    22,   111,    14,    14,
      14,    74,   111,    20,    14,    14,    56,    20,    20,    20,
      14,   201,    20,    20,    20,    20,    14,    20,    14,    14,
      20,    20,    14,    20,    14,   362,    20,    20,    14,    20,
      14,    20,    20,    20,    14,    20,    14,    20,    20,    20,
      14,    20,    13,    20,  1364,    14,  1138,    19,  1368,   968,
      20,    14,    20,    20,    14,    20,    14,    14,  1269,  1270,
    1271,    14,    16,    14,    20,    14,   985,  1278,    20,  1280,
    1281,    14,    20,    14,    14,    14,    20,    14,    20,    14,
    1172,    56,    20,    56,    20,  1004,    20,    20,    20,    20,
      20,  1010,    20,  1413,  1013,  1306,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,  1207,    14,    20,    14,    14,
      14,    14,    22,    20,    53,   567,    53,  1219,    20,    20,
      20,    20,    20,    14,    20,  1455,    14,    14,    14,    14,
      20,    14,    14,    14,   238,    14,    20,   393,    74,  1068,
      20,  1362,    20,    20,    20,    20,    14,    14,  1077,    14,
      14,    14,    22,    14,    20,    14,    16,  1188,    20,  1088,
    1089,  1090,    20,    20,    20,    20,    20,    56,    20,    20,
      14,  1100,    20,  1275,    20,    14,  1105,    14,  1107,  1108,
    1109,  1110,  1111,    56,  1113,  1114,  1568,    56,    20,    14,
      20,    14,    20,  1295,    20,    14,    20,    14,    20,  1301,
    1302,    14,    20,    14,    20,  1307,    20,    14,  1137,    14,
      20,    20,  1141,  1142,  1143,  1144,  1145,    20,    14,    14,
      14,    14,    14,    14,    22,    56,    14,    56,   568,    56,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    14,
      14,    14,  1572,  1568,    14,    14,    14,    53,    20,    20,
      14,    14,    14,    20,    56,    20,    56,    56,    14,    20,
      20,    20,    20,    20,  1193,    20,    20,  1196,    20,    20,
      20,    20,    20,    20,    20,    20,    16,    16,    20,  1208,
    1209,  2104,    14,    14,    20,    14,    14,    14,  1618,    14,
      20,    14,  1221,    19,  1223,  1224,  1225,  1226,    20,    20,
      20,    20,    14,  1635,    20,    14,    20,    14,    14,    20,
      14,    14,    14,  1232,    14,    20,   569,   572,    14,    20,
     570,    20,    20,    20,  1253,  1254,    20,    20,    20,    20,
      20,    14,    14,    14,  1263,    20,    20,    14,    14,  1268,
      20,    20,    20,    14,    14,    20,    20,  1568,  1277,    22,
    1279,    20,    20,  1455,    20,    20,    20,  1687,    20,    20,
      20,    20,    20,    20,    20,    20,  1696,    20,    20,  1699,
     159,   160,   161,   162,    20,    20,    20,    14,    14,    20,
      14,    20,    20,    14,    14,    20,   571,    20,    20,    14,
     576,    20,    20,    20,    20,    14,    20,    20,    20,    20,
    1938,    14,  1940,   192,    20,    20,    20,    14,    20,  1947,
      20,   200,    20,    14,    20,    14,    20,    20,    20,    16,
      20,    14,   211,   212,    20,    20,   215,  1757,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
    1369,  1370,    20,    20,    14,    20,    14,    14,    14,    14,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,    14,    20,    20,    20,   258,
    1572,   260,   261,   262,    20,    20,    20,    20,    20,    14,
      14,    20,   271,   272,    14,    14,    22,    20,   277,   278,
     279,   280,    20,    20,    14,    20,    20,  1827,    20,  1829,
      14,   267,    20,   292,   293,   294,   295,   296,    20,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   297,    14,    20,    14,    14,    20,    20,   111,    20,
      14,  1037,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    14,    14,
      20,   327,   328,   329,   330,   331,    20,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      14,    14,    14,    14,    22,   238,   238,    14,   238,    -1,
      20,    20,    20,    14,    20,    20,    20,    14,    20,    14,
      20,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    -1,    -1,   238,    -1,   238,
      14,    20,    20,    20,    20,    20,    14,    14,    20,  1568,
      14,    20,    -1,    14,  1573,    20,    14,  1576,    20,    14,
      20,    20,    14,    20,    14,   444,    20,    20,    14,  1588,
    1589,    20,    14,    14,    14,    20,    14,    20,    14,   435,
    2000,  2001,    14,    14,    14,    14,    20,    14,    14,    14,
     238,    14,    20,    14,    14,    14,    20,  1616,   454,    14,
      14,    14,   208,    20,    14,    14,    -1,    14,    20,    20,
      14,    14,    20,    -1,    20,  2243,  1635,  1636,  2040,    20,
      20,    14,    20,    14,    20,    20,  1645,    14,    20,    14,
      20,    20,    20,    14,  1653,    -1,    20,    20,    20,    14,
      20,    20,    20,    20,    14,    14,    20,    20,    20,    20,
    1669,  1670,  1671,  1672,  1673,    20,    14,    14,    20,    14,
      20,    20,  2082,    14,  2084,  2085,    20,  2087,    20,    -1,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,  1701,  1702,    20,    14,    14,    14,    14,    20,
      14,    14,    14,    14,    -1,    20,    14,   303,    -1,    -1,
      20,    20,   308,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    14,    20,    20,    14,
      -1,    -1,   328,    20,    20,   331,    20,    20,  1747,    14,
     336,    20,    14,    20,    14,    14,    20,    20,   344,    20,
     346,  2161,    14,    20,    20,    20,  2166,    20,  2168,    20,
      14,    14,    20,    20,    20,    14,    -1,    14,    20,    20,
     366,   367,    20,    14,    20,    20,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2000,  2001,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     466,   467,    -1,   469,    -1,    -1,   472,    -1,  2288,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2308,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2352,    -1,    -1,    -1,    -1,   543,   544,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   582,   583,  2398,    -1,
     586,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2040,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2064,  2065,  2066,    -1,    -1,
      -1,    -1,  2472,    -1,    -1,    -1,    -1,   663,  2077,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     676,    -1,    -1,    -1,  2093,  2094,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2288,    -1,    -1,    -1,
      -1,    -1,  2121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2534,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   800,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2624,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2643,    -1,    -1,  2646,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2695,    -1,    -1,    -1,    -1,
    2472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2308,
      -1,    -1,    -1,    -1,    -1,  2715,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2326,    -1,  2328,
      -1,    -1,  2331,  2332,    -1,    -1,    -1,  2336,  2337,  2338,
    2339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2368,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   999,  1000,  1001,    -1,    -1,  1004,  1005,
    1006,  1007,  1008,  1009,    -1,  1011,  1012,    -1,    -1,    -1,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,    -1,  1024,    -1,
    1026,    -1,  1028,  1029,    -1,  1031,  1032,  1033,  1034,  1035,
      -1,    -1,    -1,    -1,  1040,  1041,  1042,  1043,  1044,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1054,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1069,  1070,    -1,  1072,  1073,  1074,  1075,
    1076,    -1,  1078,  1079,  1080,  1081,  1082,  1083,    -1,  1085,
      -1,    -1,    -1,    -1,    -1,  2504,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,    -1,  1101,    -1,    -1,    -1,  2518,
      -1,    -1,    -1,    -1,    -1,  2524,    -1,    -1,    -1,    -1,
    1116,    -1,    -1,    -1,  1120,  1121,  1122,    -1,    -1,  1125,
    1126,  1127,  1128,  1129,  1130,    -1,  1132,  1133,  1134,  1135,
    1136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,    -1,    -1,    -1,  1160,  1161,    -1,    -1,    -1,  1165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1173,  1174,    -1,
      -1,    -1,  2591,    -1,    -1,    -1,  2595,    -1,    -1,  1185,
      -1,    -1,    -1,    -1,    -1,  1191,  1192,    -1,  1194,  1195,
      -1,    -1,  1198,    -1,  1200,  1201,    -1,    -1,    -1,    -1,
    1206,    -1,    -1,    -1,  1210,  1211,  1212,    -1,    -1,    -1,
    1216,    -1,    -1,    -1,  1220,    -1,    -1,    -1,    -1,  1225,
    1226,  1227,  1228,  1229,  1230,  1231,    -1,    -1,  1234,  1235,
    1236,    -1,  1238,  1239,  1240,  1241,  1242,  1243,    -1,  1245,
    1246,  1247,  1248,  1249,  1250,  1251,  1252,    -1,    -1,    -1,
      -1,    -1,    -1,  1259,    -1,  1261,  1262,    -1,  1264,  1265,
    1266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2687,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1292,    -1,  1294,    -1,
      -1,  1297,  2711,  1299,  1300,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1454,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1573,  1574,    -1,
      -1,  1577,  1578,  1579,  1580,    -1,  1582,    -1,  1584,    -1,
      -1,    -1,    -1,    -1,  1590,  1591,  1592,    -1,    -1,  1595,
    1596,  1597,  1598,    -1,  1600,    -1,  1602,    -1,  1604,    -1,
      -1,  1607,  1608,  1609,  1610,    -1,    -1,    -1,  1614,    -1,
      -1,  1617,    -1,    -1,    -1,  1621,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1637,    -1,    -1,    -1,    -1,  1642,    -1,    -1,    -1,
    1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,
    1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,  1665,
      -1,    -1,  1668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1676,    -1,    -1,    -1,    -1,    -1,  1682,  1683,  1684,  1685,
      -1,  1687,  1688,  1689,    -1,  1691,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1700,    -1,    -1,  1703,  1704,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1713,  1714,  1715,
    1716,    -1,  1718,  1719,  1720,    -1,    -1,    -1,    -1,  1725,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1736,  1737,    -1,  1739,  1740,    -1,    -1,  1743,    -1,  1745,
      -1,    -1,  1748,    -1,  1750,  1751,  1752,    -1,  1754,  1755,
      -1,    -1,    -1,  1759,    -1,    -1,  1762,    -1,  1764,    -1,
      -1,    -1,  1768,  1769,  1770,    -1,  1772,    -1,    -1,    -1,
      -1,    -1,    -1,  1779,    -1,    -1,  1782,    -1,  1784,    -1,
    1786,  1787,  1788,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1798,  1799,    -1,    -1,  1802,    -1,    -1,    -1,
      -1,  1807,  1808,  1809,  1810,  1811,  1812,    -1,  1814,  1815,
    1816,    -1,  1818,  1819,  1820,  1821,  1822,    -1,  1824,  1825,
    1826,    -1,  1828,    -1,  1830,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1877,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1937,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2004,    -1,
    2006,  2007,    -1,  2009,    -1,  2011,    -1,  2013,    -1,    -1,
      -1,    -1,  2018,  2019,    -1,  2021,  2022,  2023,  2024,    -1,
    2026,  2027,  2028,  2029,    -1,    -1,    -1,  2033,  2034,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2042,  2043,    -1,    -1,
    2046,    -1,  2048,    -1,  2050,    -1,  2052,  2053,  2054,  2055,
      -1,  2057,  2058,  2059,  2060,  2061,  2062,    -1,  2064,  2065,
      -1,  2067,  2068,  2069,  2070,    -1,  2072,  2073,  2074,  2075,
    2076,    -1,  2078,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2088,  2089,    -1,    -1,  2092,    -1,    -1,  2095,
    2096,    -1,  2098,  2099,  2100,    -1,  2102,  2103,    -1,    -1,
    2106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2115,
    2116,    -1,  2118,    -1,  2120,    -1,  2122,    -1,  2124,  2125,
      -1,  2127,  2128,  2129,    -1,  2131,  2132,  2133,  2134,  2135,
    2136,  2137,    -1,  2139,  2140,  2141,  2142,  2143,  2144,  2145,
    2146,  2147,    -1,  2149,  2150,  2151,  2152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2163,  2164,  2165,
      -1,  2167,    -1,  2169,  2170,    -1,    -1,    -1,    -1,    -1,
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
      -1,  2287,  2288,    -1,    -1,  2291,  2292,    -1,  2294,  2295,
      -1,  2297,  2298,    -1,  2300,  2301,  2302,    -1,  2304,    -1,
      -1,    -1,    -1,  2309,  2310,    -1,  2312,    -1,  2314,  2315,
    2316,  2317,  2318,    -1,  2320,  2321,  2322,  2323,  2324,  2325,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2333,  2334,  2335,
      -1,    -1,    -1,    -1,    -1,  2341,  2342,    -1,    -1,  2345,
      -1,  2347,  2348,    -1,  2350,    -1,    -1,    -1,    -1,    -1,
    2356,    -1,    -1,    -1,    -1,    -1,    -1,  2363,  2364,  2365,
      -1,  2367,    -1,  2369,    -1,    -1,  2372,    -1,  2374,  2375,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2390,  2391,  2392,  2393,  2394,    -1,
      -1,    -1,    -1,    -1,  2400,  2401,  2402,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2472,  2473,  2474,    -1,
      -1,  2477,  2478,  2479,    -1,    -1,    -1,  2483,    -1,    -1,
    2486,    -1,    -1,    -1,    -1,    -1,  2492,    -1,  2494,    -1,
    2496,    -1,    -1,  2499,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2509,  2510,    -1,  2512,    -1,    -1,  2515,
    2516,    -1,    -1,    -1,  2520,    -1,  2522,  2523,    -1,  2525,
    2526,  2527,    -1,    -1,  2530,  2531,    -1,  2533,    -1,  2535,
    2536,  2537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2574,    -1,
    2576,  2577,  2578,  2579,  2580,    -1,    -1,    -1,  2584,    -1,
    2586,  2587,    -1,  2589,  2590,    -1,  2592,  2593,  2594,    -1,
    2596,    -1,  2598,  2599,  2600,    -1,    -1,  2603,  2604,  2605,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2636,    -1,    -1,    -1,    -1,  2641,    -1,    -1,  2644,    -1,
      -1,  2647,  2648,  2649,  2650,  2651,    -1,  2653,  2654,    -1,
    2656,  2657,    -1,  2659,    -1,  2661,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2678,  2679,    -1,    -1,    -1,    -1,  2684,  2685,
    2686,    -1,    -1,  2689,  2690,    -1,    -1,  2693,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2706,    -1,  2708,    -1,  2710,    -1,    -1,  2713,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2722,  2723,  2724,  2725,
      -1,    -1,    -1,    -1,    -1,    -1,  2732,  2733,  2734,    -1,
      -1,    -1,    -1,  2739,  2740,  2741,    -1,    -1,    -1,    -1,
    2746,  2747,   371,   372,   373,   374,   375,   376,   377,    -1,
     379,   380,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,   397,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,   427,   428,
     429,   430,   431,   432,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   465,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     479,   480,   481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     509,    -1,    -1,    -1,    -1,   514,   515,    -1,   517,   518,
      -1,   520,   521,    -1,   523,   524,     0,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,   575,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    -1,    81,    82,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
     214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   323,
     324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,    -1,   363,
     364,   365,   366,   367,    -1,    -1,    -1,    -1,    -1,   373,
     374,   375,   376,   377,   378,   379,   380,    -1,    -1,   383,
     384,   385,   386,   387,   388,   389,   390,   391,    -1,    -1,
      -1,    -1,   396,    -1,   398,   399,   400,    -1,    -1,    -1,
     404,   405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   418,   419,   420,   421,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   429,   430,   431,   432,   433,
     434,    -1,   436,   437,    -1,    -1,    -1,    -1,   442,   443,
      -1,    -1,    -1,   447,    -1,   449,   450,   451,   452,   453,
      -1,   455,   456,   457,   458,   459,   460,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1023,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1086,  1087,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1118,
      -1,    -1,    -1,    -1,  1123,  1124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1202,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1258,
      -1,  1260,    -1,    -1,    -1,    -1,    -1,    -1,  1267,    -1,
      -1,    -1,    -1,  1272,  1273,  1274,    -1,  1276,    -1,    -1,
      -1,    -1,    -1,  1282,    -1,    -1,  1285,  1286,  1287,  1288,
    1289,  1290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1364,    -1,    -1,    -1,  1368,
      -1,    -1,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,  1413,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,  1618,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   323,   324,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,    -1,
    1699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,    -1,   363,   364,   365,
     366,   367,    -1,    -1,    -1,    -1,    -1,   373,   374,   375,
     376,   377,   378,   379,   380,    -1,    -1,   383,   384,   385,
     386,   387,   388,   389,   390,   391,    -1,    -1,    -1,    -1,
     396,    -1,   398,   399,   400,    -1,    -1,    -1,   404,   405,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   418,   419,   420,   421,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,   430,   431,   432,   433,   434,    -1,
     436,   437,    -1,    -1,    -1,    -1,   442,   443,    -1,    -1,
      -1,   447,    -1,   449,   450,   451,   452,   453,    -1,   455,
     456,   457,   458,   459,   460,    -1,    -1,    -1,  1827,    -1,
    1829,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,   126,    -1,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,   139,    -1,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,   197,   198,   199,    -1,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2082,    -1,  2084,  2085,    -1,  2087,   231,
     232,   233,   234,    -1,    -1,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
     252,   253,   254,    -1,    -1,   257,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2161,    -1,    -1,    -1,    -1,  2166,    -1,  2168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,   324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
      -1,   363,    -1,   365,   366,    -1,   368,    -1,    -1,    -1,
      -1,   373,   374,   375,   376,   377,   378,   379,   380,    -1,
      -1,   383,   384,   385,   386,   387,   388,   389,   390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   418,   419,   420,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   431,
     432,   433,   434,    -1,   436,   437,    -1,   439,   440,   441,
     442,   443,    -1,   445,   446,    -1,   448,   449,   450,   451,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,  2352,    -1,    -1,    51,    52,    53,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2398,
      -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,   139,    -1,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2534,   231,   232,   233,   234,
      -1,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,   252,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2602,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2624,    -1,    -1,   323,   324,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2643,    -1,    -1,  2646,    -1,    -1,
      -1,    -1,    -1,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,    -1,   363,    -1,
     365,   366,    -1,    -1,    -1,    -1,    -1,    -1,   373,   374,
     375,   376,   377,   378,   379,   380,    -1,    -1,   383,   384,
     385,   386,   387,   388,   389,   390,  2695,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2715,    -1,    -1,    -1,
      -1,    -1,    -1,   418,   419,   420,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   431,   432,   433,   434,
      -1,   436,   437,    -1,    -1,    -1,    -1,   442,   443,     9,
      10,    11,    -1,    13,   449,   450,   451,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,   126,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,   139,
      -1,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,   232,   233,   234,    -1,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   323,   324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,    -1,   363,    -1,   365,   366,    -1,    -1,    -1,
      -1,    -1,    -1,   373,   374,   375,   376,   377,   378,   379,
     380,    -1,    -1,   383,   384,   385,   386,   387,   388,   389,
     390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,
     420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   431,   432,   433,   434,    -1,   436,   437,    -1,    -1,
      -1,    -1,   442,   443,     9,    10,    11,    -1,    13,   449,
     450,   451,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    53,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    73,    -1,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,   139,    -1,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   232,   233,   234,
      -1,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,   252,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   323,   324,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,    -1,   363,    -1,
     365,   366,    -1,    -1,    -1,    -1,    -1,    -1,   373,   374,
     375,   376,   377,   378,   379,   380,    -1,    -1,   383,   384,
     385,   386,   387,   388,   389,   390,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   418,   419,   420,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   431,   432,   433,   434,
      -1,   436,   437,    -1,    -1,    -1,    -1,   442,   443,     9,
      10,    11,    -1,    13,   449,   450,   451,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,   126,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,   139,
      -1,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,   232,   233,   234,    -1,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   323,   324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,    -1,   363,    -1,   365,   366,    -1,    -1,    -1,
      -1,    -1,    -1,   373,   374,   375,   376,   377,   378,   379,
     380,    -1,    -1,   383,   384,   385,   386,   387,   388,   389,
     390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,
     420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   431,   432,   433,   434,    -1,   436,   437,    -1,    -1,
      -1,    -1,   442,   443,     9,    10,    11,    -1,    13,   449,
     450,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    53,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    73,    -1,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,   139,    -1,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   232,   233,   234,
      -1,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,   252,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     265,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   323,   324,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,    -1,   363,    -1,
     365,   366,    -1,    -1,    -1,    -1,    -1,    -1,   373,   374,
     375,   376,   377,   378,   379,   380,    -1,    -1,   383,   384,
     385,   386,   387,   388,   389,   390,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   418,   419,   420,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   431,   432,   433,   434,
      -1,   436,   437,    -1,    -1,    -1,    -1,   442,   443,    -1,
      -1,    -1,    -1,    -1,   449,   450,   451,     9,    10,    11,
      -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      -1,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,   126,    -1,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,   139,    -1,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,
     232,   233,   234,    -1,    -1,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
     252,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   323,   324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
      -1,   363,    -1,   365,   366,    -1,    -1,    -1,    -1,    -1,
      -1,   373,   374,   375,   376,   377,   378,   379,   380,    -1,
      -1,   383,   384,   385,   386,   387,   388,   389,   390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   418,   419,   420,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   431,
     432,   433,   434,    -1,   436,   437,    -1,    -1,    -1,    -1,
     442,   443,    -1,    -1,    -1,    -1,    -1,   449,   450,   451,
       9,    10,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,   126,    -1,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
     139,    -1,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,   157,   158,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   232,   233,   234,    -1,    -1,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   323,   324,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,    -1,   363,    -1,   365,   366,    -1,    -1,
      -1,    -1,    -1,    -1,   373,   374,   375,   376,   377,   378,
     379,   380,    -1,    -1,   383,   384,   385,   386,   387,   388,
     389,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,
     419,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   431,   432,   433,   434,    -1,   436,   437,    -1,
      -1,    -1,    -1,   442,   443,    -1,    -1,    -1,    -1,    -1,
     449,   450,   451,     9,    10,    11,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    73,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
     126,    -1,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,   139,    -1,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   231,   232,   233,   234,    -1,
      -1,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,   252,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   323,   324,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,    -1,   363,    -1,   365,
     366,    -1,    -1,    -1,    -1,    -1,    -1,   373,   374,   375,
     376,   377,   378,   379,   380,    -1,    -1,   383,   384,   385,
     386,   387,   388,   389,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   418,   419,   420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   431,   432,   433,   434,    -1,
     436,   437,    -1,    -1,    -1,    -1,   442,   443,     9,    10,
      11,    -1,    13,   449,   450,   451,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,    -1,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,   139,    -1,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   232,   233,   234,    -1,    -1,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,   252,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   323,   324,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,    -1,   363,    -1,   365,   366,    -1,    -1,    -1,    -1,
      -1,    -1,   373,   374,   375,   376,   377,   378,   379,   380,
      -1,    -1,   383,   384,   385,   386,   387,   388,   389,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     431,   432,   433,   434,    -1,   436,   437,    -1,    -1,    -1,
      -1,   442,   443,     9,    10,    11,    -1,    13,   449,   450,
     451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    73,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
     126,    -1,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,   139,    -1,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   231,   232,   233,   234,    -1,
      -1,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,   252,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   323,   324,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,    -1,   363,    -1,   365,
     366,    -1,    -1,    -1,    -1,    -1,    -1,   373,   374,   375,
     376,   377,   378,   379,   380,    -1,    -1,   383,   384,   385,
     386,   387,   388,   389,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   418,   419,   420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   431,   432,   433,   434,    -1,
     436,   437,    -1,    -1,    -1,    -1,   442,   443,     9,    10,
      11,    -1,    13,   449,   450,   451,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,    -1,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,   139,    -1,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   232,   233,   234,    -1,    -1,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,   252,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   323,   324,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,    -1,   363,    -1,   365,   366,    -1,    -1,    -1,    -1,
      -1,    -1,   373,   374,   375,   376,   377,   378,   379,   380,
      -1,    -1,   383,   384,   385,   386,   387,   388,   389,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     431,   432,   433,   434,    -1,   436,   437,    -1,    -1,    -1,
      -1,   442,   443,     9,    10,    11,    -1,    13,   449,   450,
     451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    73,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
     126,    -1,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,   139,    -1,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   231,   232,   233,   234,    -1,
      -1,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,   252,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   323,   324,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,    -1,   363,    -1,   365,
     366,    -1,    -1,    -1,    -1,    -1,    -1,   373,   374,   375,
     376,   377,   378,   379,   380,    -1,    -1,   383,   384,   385,
     386,   387,   388,   389,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   418,   419,   420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   431,   432,   433,   434,     9,
     436,   437,    -1,    13,    -1,    -1,   442,   443,    -1,    -1,
      -1,    -1,    -1,   449,   450,   451,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,   126,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,   139,
      -1,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,   232,   233,   234,    -1,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   323,   324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,    -1,   363,    -1,   365,   366,    -1,    -1,    -1,
      -1,    -1,    -1,   373,   374,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,
     420,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   431,   432,   433,   434,    -1,   436,   437,    -1,    -1,
      31,    32,   442,   443,    35,    36,    37,    -1,    -1,   449,
     450,   451,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,    -1,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,   139,    -1,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   232,   233,   234,    -1,    -1,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,   252,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   323,   324,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,    -1,   363,    -1,   365,   366,    -1,    -1,    -1,    -1,
      -1,    -1,   373,   374,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     431,   432,   433,   434,    -1,   436,   437,    -1,    -1,    -1,
      -1,   442,   443,    -1,    -1,    -1,    -1,    -1,   449,   450,
     451
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     9,    10,    11,    13,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      39,    40,    41,    42,    43,    44,    45,    47,    48,    49,
      51,    52,    53,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    81,    82,    83,
      84,    85,    86,   100,   101,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   157,   158,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   202,   203,   204,   205,
     210,   214,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   264,   265,   323,   324,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   363,   364,   365,   366,   367,   373,   374,
     375,   376,   377,   378,   379,   380,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   396,   398,   399,   400,   404,
     405,   418,   419,   420,   421,   429,   430,   431,   432,   433,
     434,   436,   437,   442,   443,   447,   449,   450,   451,   452,
     453,   455,   456,   457,   458,   459,   460,   462,   463,   464,
     465,   466,   467,   470,   471,   472,   473,   477,   481,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   508,   509,   511,   512,   513,   514,   515,   516,   517,
      13,    58,    59,    60,    61,    62,    64,    65,    66,    73,
      75,    76,   144,   145,   486,   490,   509,   513,   491,   491,
     485,   506,    13,    13,    13,    13,   484,   506,    13,   403,
     486,   509,    53,    67,    68,    69,    70,   511,   486,   506,
     506,   484,    13,   484,    13,    13,   100,   101,   111,   100,
     101,   111,    19,    19,    91,    92,    13,    19,    19,   111,
     511,    19,   159,    19,    15,    90,    15,    58,    59,    60,
      61,    62,    64,    65,    66,    72,    73,    74,    75,    76,
     486,   509,   513,   515,   517,   484,    13,    13,   491,   491,
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
      13,    13,    13,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   511,   478,   479,
      75,   517,   482,   506,   464,   484,   484,    13,    13,    13,
      13,    71,   511,   511,    13,    13,    13,    13,    13,    19,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,     0,     0,   464,   465,   466,   467,   470,   471,   472,
     473,   464,    19,    13,    15,    19,    90,   100,   101,   109,
      91,    92,    93,    94,   111,     4,     7,     8,    12,    10,
      11,     5,     6,   105,   106,   107,   108,    17,    18,   103,
       4,    21,   104,    19,    90,    90,   111,    13,    19,    19,
      19,    19,    15,    15,    19,    19,    13,    19,    19,    14,
      14,   484,   482,   484,   485,   482,   484,   517,   517,   482,
     482,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   267,   297,   327,   328,
     329,   330,   331,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   435,   454,   267,   268,   269,
     271,   273,   274,   281,   284,   285,   286,   287,   288,   289,
     290,   291,   321,   325,   330,   331,   341,   346,   347,   509,
     509,   482,   326,    43,    44,   369,   370,   371,   372,   368,
     511,    43,   162,   482,   266,   482,    15,   482,   482,   483,
     506,   483,   506,   483,   483,   483,   483,   483,   483,   486,
     483,   483,   486,   486,   486,   486,   486,   483,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   483,   483,   486,
     154,   155,   156,   154,   155,   156,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   483,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   483,   486,   483,   483,   483,   483,   483,   483,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   509,   509,   484,   484,   486,   486,   486,    53,    53,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   483,   482,   482,   486,   482,   486,   486,   486,   482,
     506,   486,   486,   486,   486,   484,   483,   483,   483,   486,
     111,   395,    54,   478,   478,   464,   511,   517,   484,   483,
      53,   469,   468,   478,   483,   483,   486,   483,   483,   438,
     483,   483,   482,   483,   483,   484,   484,    62,   486,   486,
     486,   464,   417,   482,   506,    22,    62,   482,   486,   518,
      50,    51,    87,   125,   154,   159,   162,   163,   164,   165,
     194,   195,   196,   326,   327,   332,   345,   362,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     483,   505,   505,   505,   505,   505,   492,   492,   492,   492,
     492,   493,   493,   495,   495,   495,   495,   496,   496,   497,
     499,   500,   501,   503,   502,   159,   160,   161,   162,   192,
     200,   211,   212,   215,   258,   260,   261,   262,   271,   272,
     277,   278,   279,   280,   292,   293,   294,   295,   296,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   444,   197,   198,   199,   206,   207,   208,   209,   213,
     254,   257,   258,   259,   260,   262,   263,   266,   439,   440,
     441,   445,   446,   448,   509,   510,   266,   483,    17,    35,
      38,    62,    64,    66,    74,   266,   322,   353,   356,   368,
     506,   507,   509,   510,   514,    17,    64,   475,   506,   509,
     515,    79,   482,   482,   482,   490,    20,    14,    14,    20,
      20,    20,    14,    14,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    20,    13,   482,   484,   506,   484,    13,
      13,    13,   484,    16,    15,    16,   482,    14,    20,    14,
      14,    20,    16,    14,    14,    16,    14,    16,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    13,
      13,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    14,    20,    14,    20,    16,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    14,
      20,    20,    14,    14,    14,    20,    14,    14,    14,    14,
      14,    14,    20,    20,    20,    14,   482,   474,   484,   480,
     402,   464,    14,    14,    14,    20,    14,    13,    13,   464,
      14,    20,    20,    20,    20,    20,    13,    14,    20,    14,
      20,    20,    20,    14,    14,    14,    20,    20,    20,    20,
      20,    22,    23,    14,    20,    16,    22,    19,    16,    13,
      13,    13,   484,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    22,   484,    13,    13,    13,   484,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   484,    13,    13,    13,    13,    13,
      13,    19,    15,   517,    15,    13,    19,    15,    13,    13,
      13,    13,    20,    19,   517,    14,    20,    13,    16,    16,
     484,   482,   482,   482,   482,   486,   482,   482,   482,   482,
     482,   486,   482,   482,    62,   486,    55,    62,   482,   482,
     482,   482,   482,   482,   482,   483,   482,    64,   482,    71,
     482,   482,   510,   482,   482,   482,   482,   482,   509,    64,
     507,    64,    55,   482,   482,   482,   482,   482,   484,    58,
      61,   484,   111,   482,   111,    16,    71,   506,    13,    13,
      13,    53,   486,   482,   482,   482,   482,   482,   482,   482,
     486,   482,   482,   482,   482,   482,   482,   482,   483,   483,
     486,   486,   486,   482,   482,   482,   482,   482,   482,   482,
     482,   486,   482,   486,   486,   486,   486,   486,   486,   486,
     486,   482,   483,    13,   482,   482,   482,   483,   483,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     486,   484,   486,   486,   486,   486,   486,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   484,   482,   482,   392,    20,   478,   478,   482,   422,
     423,   424,   425,   426,   428,   476,   476,   482,   482,   486,
     482,   482,   486,   482,   482,   482,   483,   482,   484,   486,
     486,   482,   482,   482,    22,   482,    88,   484,   482,   486,
     486,   486,   482,   486,   482,   486,   482,   482,   482,   482,
     482,   504,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   483,   482,   482,   482,   482,   482,   482,   482,   482,
     486,   486,    14,    14,    14,   483,   482,   483,   482,   482,
     486,   482,   482,   482,   483,   486,   509,   509,   509,   483,
     483,   483,   484,   483,   486,   509,   486,   509,   509,   483,
      14,   483,   483,   483,   483,   483,   483,   201,   482,   482,
     484,   320,   482,    74,   482,   482,   484,   484,    17,   506,
     515,   484,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    14,
      20,    14,    20,    14,    20,    14,    14,    20,    20,    20,
      20,    14,    19,    14,    20,    14,    20,    20,    20,    14,
      14,    20,    14,    14,    14,    20,   510,    16,   483,    14,
      14,   483,   486,   486,    14,    20,    20,    20,    14,    14,
      14,    14,    20,    14,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    14,   483,    14,
      14,    14,    20,    20,    20,    20,    14,    20,    20,    20,
      14,    20,    14,    14,    14,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    20,    20,    20,    20,    14,    20,    20,
      20,   482,   484,   464,   464,    20,    56,    56,    56,    56,
      56,    56,    14,    20,    14,    14,    20,    20,    14,    20,
      20,    14,    14,    20,    14,    20,    14,    20,    20,    14,
      20,    23,    20,    14,    20,    20,    14,    20,    14,    20,
      14,    14,    20,    14,    20,    14,    14,    14,    20,    20,
      20,    14,    20,    14,    14,    14,    14,    14,    14,    20,
      14,    14,    20,    14,    20,    14,    20,    20,    20,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      14,    14,    20,    14,    14,    14,    14,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      13,    16,    16,    14,    16,    20,    14,    14,    20,   517,
      14,   484,   482,   486,   482,   486,   482,   482,   482,   482,
     482,   482,   486,   486,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   486,
     482,   483,   482,    53,    14,    14,    14,    20,   485,   486,
      53,   486,   482,   482,   486,   482,   482,   482,   482,   482,
     482,   482,   482,   486,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   486,   486,   486,
     486,   486,   482,    14,   482,   482,   482,   482,   482,   506,
     482,   482,   482,   483,   483,   482,   486,   486,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   393,   478,   482,
     478,   422,   423,   424,   425,   426,   428,   478,   482,   482,
     482,   482,   482,   482,   486,   482,   482,   482,   482,   482,
     482,   506,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   483,   482,   483,   482,    74,
      20,    20,    53,    14,    20,    14,    20,    20,    14,    20,
      14,    20,    14,    20,    14,    14,    14,    14,    20,    20,
      14,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      14,    14,    14,    20,    20,    14,   482,    14,    19,    14,
      20,    20,    20,    20,    14,    14,    20,    14,    20,    14,
      20,    14,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    14,    20,    14,    20,    20,    14,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    20,   482,   464,    20,   464,    56,    56,
      56,    56,    56,    56,   464,    20,    20,    14,    20,    14,
      20,    20,    20,    14,    20,    23,    14,    22,    22,    22,
      14,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    14,    14,    20,    14,    14,    14,    14,
      14,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,   484,   484,    14,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,    14,   485,    53,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   518,   482,   518,   482,   518,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   486,   482,   483,   483,   483,
     483,   482,   482,   482,   486,   486,   482,   482,   482,   482,
     482,   482,   482,   478,   482,   482,   482,   482,   482,   486,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   486,   483,   482,   482,
     482,   483,   482,   483,   482,   482,    14,    20,    20,    14,
      14,    20,    20,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    20,    14,    20,    14,    14,    14,    20,    20,
      20,    14,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    14,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    14,    14,    20,    14,    20,    20,    14,
      20,    14,    20,    20,    14,    14,    20,    14,    14,    14,
      14,    14,   464,    20,    20,    20,    14,    20,    20,    20,
      14,    14,    20,    16,    20,    20,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    20,    20,    14,    14,   482,   482,   484,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   485,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   518,   518,   518,   518,   482,   482,   482,
     486,   486,   486,   486,   482,   482,   482,   482,   482,   482,
     483,   486,   482,   482,   482,   482,   482,   486,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   483,   482,   482,
     482,    14,    20,    20,    20,    14,    14,    20,    20,    20,
      14,    14,    14,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    20,    14,    20,    14,    20,    14,    14,    20,
      14,    14,    14,    14,    20,    14,    14,    14,    14,    20,
      20,    14,    20,    14,    14,    20,    20,    14,    20,    14,
      20,    14,    20,    20,    20,    20,    22,    22,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    20,   482,   484,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   518,   482,   482,   482,   482,   482,   486,   482,   482,
     482,   486,   482,   482,   482,   482,   482,   482,   483,   482,
     482,   482,    20,    14,    20,    14,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    14,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,   484,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   486,   482,
     482,   482,   486,   482,   111,   482,   482,   482,   483,   482,
     482,   482,    14,    14,    14,    14,    20,    14,    14,    14,
      14,    20,    14,    20,    20,    14,    20,    20,    20,    20,
      20,    20,   483,    20,    20,    14,    20,    20,    14,    20,
      14,    20,   482,   482,   483,   482,   483,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,    20,    20,
      14,    14,    14,    14,    20,    20,    20,    20,    14,    20,
      20,    14,    14,    20,    14,    20,   482,   482,   482,   482,
     482,   486,   482,   482,   482,   483,    20,    14,    20,    14,
      20,    20,    14,    20,    14,    20,   482,   482,   482,   486,
     482,   483,    20,    20,    20,    20,    14,    14,   482,   482,
     482,   482,    20,    20,    20,    14,   482,   482,   482,    20,
      20,    20,   482,   482,   482,    14,    20,    20,   482,   482,
      14,    14
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
     715
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   461,   462,   462,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     464,   464,   465,   465,   465,   465,   465,   466,   466,   468,
     467,   469,   467,   470,   471,   472,   472,   472,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   474,   474,   475,
     475,   475,   475,   475,   475,   475,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   477,
     477,   477,   477,   477,   477,   477,   478,   479,   480,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   482,   483,   484,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   486,   486,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   488,   489,
     489,   490,   490,   490,   490,   490,   490,   490,   491,   491,
     491,   491,   491,   491,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   493,   493,   493,   493,   493,   494,   494,
     494,   495,   496,   496,   496,   496,   496,   497,   497,   497,
     498,   498,   499,   500,   500,   501,   501,   502,   502,   503,
     503,   504,   504,   505,   505,   505,   505,   505,   505,   506,
     507,   507,   507,   507,   508,   508,   508,   509,   509,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   511,   512,   512,   513,
     513,   513,   513,   513,   513,   514,   514,   514,   514,   514,
     514,   514,   514,   515,   515,   516,   516,   516,   516,   516,
     516,   517,   517,   518,   518,   518,   518
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     8,    10,     6,     2,     3,     4,     6,     0,
       8,     0,     8,     4,     2,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     6,     4,     3,
       5,     3,     6,     6,     6,     3,     6,     3,     6,     3,
       3,     6,     6,     8,     6,     8,     8,     8,     3,     1,
       1,     1,     1,     8,     4,     4,     1,     2,     2,     2,
       3,     8,    16,     2,     2,     3,     3,     2,     2,     2,
       6,     2,     2,     5,     2,     1,     1,     2,     2,     2,
       2,     2,     2,     4,     4,     2,     2,     2,     4,     3,
      10,     6,     3,     6,     6,     8,    28,     8,     8,     3,
       8,    12,     6,     6,    16,     8,    16,    10,     6,    10,
       8,    10,    14,     8,    12,     6,     8,     6,     6,     3,
       3,     2,     3,     6,    10,     6,    10,    10,    12,     6,
       6,     3,     3,     3,     3,     4,     3,     6,     6,     4,
       4,     6,    10,    10,    10,     6,     6,     6,     6,     6,
      10,     6,    10,     6,     6,     6,     3,     6,     6,    10,
      10,     6,     6,     6,     3,     3,     3,     3,     6,     6,
       3,     6,     6,     8,    10,     3,     6,     3,     4,    20,
       6,    10,     6,     3,     3,     6,     3,     6,     8,     6,
       6,     8,    16,     6,     3,     6,     8,     3,    12,    12,
      12,    10,     3,     3,     8,     8,    10,     8,    10,    12,
       6,     8,    10,    16,    18,    12,     6,    18,    16,    12,
      10,    10,    10,     6,    10,     6,     6,     6,     8,     4,
       4,     8,     4,    18,     4,     1,     1,     1,     6,     3,
       4,     1,     1,     1,    30,    24,     8,     1,     3,     0,
       1,     3,     2,     4,     1,     3,     0,     2,     2,     2,
       2,     2,     2,     4,     4,     4,     4,     4,     4,     1,
       6,     1,     3,     4,     4,     1,     3,     0,     0,     1,
       1,     1,     1,     1,     1,     1,     6,     8,    10,    10,
      10,     8,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     6,     4,    10,
       4,    10,     4,     4,     4,     4,     4,     4,     7,     7,
       7,     9,     7,     6,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     6,    10,     4,     4,     4,     3,
       6,     6,     6,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     4,
       2,    16,    14,    16,     4,     4,     1,    10,    12,     8,
       1,     4,     6,     6,     6,     8,     8,     6,     8,     8,
      10,    10,    12,    12,    10,     4,    10,     4,     6,     4,
       4,     4,    12,     4,    12,    12,    16,    20,    10,    12,
       4,     6,     6,     6,     4,     4,     6,     4,     6,     6,
       6,     4,    10,    16,    10,     8,    12,    10,     8,    12,
       8,    12,     8,    12,    12,    14,    12,    12,    16,     4,
       8,    10,    12,    10,    12,    10,    12,    12,    14,    12,
       8,    14,     4,     4,     4,     4,     3,     3,     3,     6,
       6,     6,     6,     8,    14,    12,    14,    12,     6,     8,
      10,    10,    12,     6,     6,     6,     6,     6,     6,     6,
       6,     8,    10,     4,     4,    10,    10,     4,     6,     6,
      12,    30,     8,     5,     6,     5,     5,     6,     6,     4,
       6,     4,     6,     4,     4,    18,     8,     6,     1,     1,
       1,     1,     1,     1,     1,     6,     4,     3,     1,     2,
       2,     2,     4,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     3,     3,     3,     3,     1,
       1,     3,     8,     4,     6,     1,     4,     1,     4,     6,
       6,     8,     8,     4,     6,     6,     6,     6,     3,     2,
       1,     4,     6,     1,     4,     4,    10,     6,    16,    18,
      10,    20,    14,     8,     4,     6,     8,     8,    12,    16,
      16,    18,    14,    14,    16,    20,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,    11,     7,     3,     1
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
  "T_SetDebugOff", "T_SetVerboseOn", "T_SetVerboseOff", "T_AddMenuScript",
  "T_SetProgress", "T_SetStatusText", "T_GetScriptsDir", "T_argc",
  "T_emptyargs", "END_INSTRUCTION", "T_Image", "T_BrowseImage",
  "T_ReadRawImages", "T_Transform", "SHOW", "HELP", "QUIT", "T_HIDE",
  "PRINT", "PRINTN", "T_InfoDialog", "T_boost_format", "T_SPRINT",
  "ASHELL", "LS", "T_SetName", "T_GetName", "T_GetObjectName", "ASTRING",
  "ABLOCK", "NUMBER", "IDENTIFIER", "VAR_IMAGE", "VAR_FLOAT", "VAR_INT",
  "VAR_UCHAR", "VAR_STRING", "VAR_IMAGEDRAW", "VAR_SURFACE",
  "VAR_SURFDRAW", "VAR_MATRIX", "VAR_FILE", "VAR_C_FUNCTION",
  "VAR_C_PROCEDURE", "VAR_CLASS_MEMBER", "VAR_C_IMAGE_FUNCTION",
  "VAR_AMI_FUNCTION", "VAR_AMI_CLASS", "VAR_AMI_OBJECT", "VAR_GLTRANSFORM",
  "VAR_ARRAY_SURFACE", "VAR_ARRAY_IMAGE", "T_del", "T_delvars",
  "T_Comments", "ENDOP", "T_global", "T_local", "T_global_new",
  "T_local_new", "T_wait", "T_schedule", "T_SetComponent", "T_GetExtent",
  "RIGHT_ASSIGN", "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "RIGHT_OP", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "TRANSPOSE_OP", "POINTWISE_MULT", "ASSIGN_OP",
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
  "T_SNR", "T_info", "T_NbPoints", "T_NbPolys", "T_save", "T_normalize",
  "T_OrientField", "T_OrientPositive", "T_2DFlux", "T_OutFlux",
  "T_OutFluxScalar", "T_OrientationRatio", "T_Skeleton", "T_SimplePoints",
  "T_CircleIntegral", "T_CircleIntegralExc", "T_CircleIntSdExc",
  "T_CircleMinIntSdExc", "T_LocalExtrema", "T_NormalField",
  "T_DirConnectivity", "T_eccentricity", "T_rot2D", "T_mean", "T_SUM",
  "T_localmean", "T_localmean2", "T_localSD", "T_localSD2",
  "T_struct_tensor", "T_StructTensorH", "T_HessianMatrix", "T_HessianEVal",
  "T_Derivatives", "T_curvatures", "T_Laplacian", "T_setvoxelsize",
  "T_settranslation", "T_setendianness", "T_Skeleton2lines",
  "T_SmoothLines", "T_ResampleLines", "T_RemoveLine", "T_ConnectLines",
  "T_threscross", "T_IsocontourPoints", "T_IsosurfDist",
  "T_vtkIsoContourDist", "T_ShortestPath", "T_ShortestPathImage",
  "T_PathFromDispl", "T_PathFromVectField", "T_LineRecons",
  "T_GetNumberOfLines", "T_GetLine", "T_ReadCTALine", "T_ReadCTALineRadii",
  "T_WriteCTALine", "T_SetIsoContour", "T_SetIsoContourParam",
  "T_DrawIsoContour", "T_SetIsoContourColor", "T_DrawAllContours",
  "T_AllContoursParam", "T_GetZmin", "T_GetZmax", "T_GetYmin", "T_GetYmax",
  "T_GetXmin", "T_GetXmax", "T_GetXPos", "T_GetYPos", "T_GetZPos",
  "T_vtkDicomRead", "T_vtkMINCRead", "T_Convolve", "T_ConvolveMask",
  "T_Pad", "T_Eigen2D", "T_Eigen3D", "T_ChamferDT", "T_Chamfer2DT",
  "T_BorgeforsDT", "T_BorgeforsSDT", "T_vtkSignedBorgefors",
  "T_vtkSignedFMDist", "T_PropagationDist", "T_PropagationDist2",
  "T_PropDanielsson", "T_vtkPropDanielsson", "T_vtkPropDaniel2", "T_CC",
  "T_ProcessXEvents", "T_ProcessEvents", "T_isoarea2D", "T_posarea",
  "T_isosurf", "T_isosurf_inv", "T_isosurf_ijk", "T_isosurf_ras",
  "T_vtkDecimate", "T_vtkMarchingCubes", "T_vtkSmooth", "T_Recompute",
  "T_vtkWindowedSinc", "T_isoline", "T_vtkDist", "T_AndreDist",
  "T_Surface", "T_getimage", "T_GetImageFromX", "T_rotate", "T_computeCC",
  "T_drawCC", "T_setminCC", "T_addobj", "T_setcurrentobj", "T_writeVRML",
  "T_writeVTK", "T_OwnMaterial", "T_SetColor", "T_SetColors",
  "T_SetColorOpacity", "T_Paint", "T_SetLight", "T_SetLightPos",
  "T_SetLightAmbient", "T_SetLightDiffuse", "T_SetLightSpecular",
  "T_SetBackground", "T_Normalize", "T_Center", "T_Remove",
  "T_SwapBuffers", "T_SetAmbient", "T_SetDiffuse", "T_SetSpecular",
  "T_SetShininess", "T_SetOpacity", "T_SetOpacityImage", "T_SetVisible",
  "T_SetColorMaterial", "T_Statistics", "T_GetIntensities",
  "T_GetLinesLength", "T_GetLinesExtremities", "T_GetConnections",
  "T_SelectLines", "T_RemoveSelection", "T_mergepoints", "T_Triangulate",
  "T_Displace", "T_Normals", "T_InvertNormals", "T_Translate", "T_Scale",
  "T_SetPointsColors", "T_SetLineWidth", "T_AddPoint", "T_NewLine",
  "T_EndLine", "T_LineAddPointNumber", "T_GetTransform", "T_SetTransform",
  "T_Interpolate", "T_Matrix", "T_Invert", "T_PrintMatrices", "SET",
  "SETPOS", "SHOWCURSOR", "T_update", "COMPARE", "SETVECTOR",
  "T_lininterp", "T_SetCompareDisplacement", "T_DrawVector",
  "T_DisplayVectors", "T_SetVectParam", "T_SetVectColor", "T_SetVectStyle",
  "T_SetLineThickness", "T_SetZoom", "T_SetWindowSize", "T_SetColormap",
  "T_drawcircle", "T_setGLwin", "T_initvalue", "T_ShowSection",
  "T_HideSection", "T_Xpos", "T_Ypos", "T_Zpos", "T_SpacePos", "T_CHAR",
  "T_UCHAR", "T_SHORT", "T_USHORT", "T_INT", "T_UINT", "T_FLOAT",
  "T_DOUBLE", "T_RGB", "T_FLOAT_VECTOR", "T_GetFormat", "T_atof",
  "T_gnuplot", "T_histo", "T_cumhisto", "T_DisplayHisto", "T_OPEN",
  "T_CLOSE", "T_scan_float", "T_read", "T_rewind", "T_LineNumber",
  "CONST_PI", "SIN", "COS", "TAN", "ASIN", "ACOS", "ATAN", "SINH", "COSH",
  "EXP", "LN", "LOG", "SQRT", "ABS", "ROUND", "FLOOR", "NORM", "FOR", "TO",
  "STEP", "ENDFOR", "T_IN", "T_REPEAT", "T_UNTIL", "T_WHILE", "T_BREAK",
  "IF", "THEN", "ELSE", "VARIABLES", "FUNCTION", "T_eval", "T_tx", "T_ty",
  "T_tz", "T_trx", "T_try", "T_trz", "T_vx", "T_vy", "T_vz", "T_vdim",
  "T_inc", "T_val", "T_exists", "T_FileExists", "T_slice", "T_GenRead",
  "T_IMAGE", "T_IMAGEDRAW", "T_SURFACE", "T_NUM", "T_STRING",
  "T_TRANSFORM", "T_OBJECT", "T_PROC", "T_Class", "T_MeanHalfSize",
  "T_Resize", "T_ReSlice", "T_Flip", "T_SetCompTransf", "T_ConvexHull",
  "T_itk", "T_CannyEdgeDetector", "T_CreateFlatMesh", "T_CreateVolume",
  "T_vtkCreateFlatMesh", "T_Altitude2Position", "T_GeoCoordinates",
  "T_ElevateMesh", "T_CreateVectors", "T_CreateVectorsFromField",
  "T_Set3DArrowParam", "T_CreateEllipsoids", "T_ComputeAltitudes",
  "T_Temp2Altitudes", "T_ReadFlow", "T_SetFluidNavFile",
  "T_DrawEarthCoord", "T_PaintCallback", "T_SaveStructuredGrid",
  "T_import_vtk", "T_import_wii", "T_import_filters", "T_amiOFCorr2D",
  "T_amiOFVar2D", "$accept", "start", "list_commands", "end_instr",
  "loop_inst", "cond_inst", "proc_decl", "$@1", "$@2", "class_decl",
  "object_decl", "func_inst", "command", "exprstringlist", "param_list",
  "param_list_decl", "primary_expr_string", "instr_block", "begin_block",
  "end_block", "float_variable", "expr", "expr_image", "expr_string",
  "basic_type", "var_image", "image", "image_variable", "string_variable",
  "primary_var", "postfix_var", "prefix_var", "multiplicative_var",
  "additive_var", "shift_var", "relational_var", "equality_var", "and_var",
  "exclusive_or_var", "inclusive_or_var", "logical_and_var",
  "logical_xor_var", "logical_or_var", "conditional_var", "assignment_var",
  "expr_var", "gltransform", "matrix_variable", "var_surface", "surface",
  "identifier", "variable_with_assign", "function_variable",
  "variable_without_assign", "unprocessed_variable", "processed_variable",
  "variable", "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       462,     0,    -1,    -1,   463,     0,    -1,   464,    -1,   463,
     464,    -1,   473,   464,    -1,   463,   473,   464,    -1,   465,
      -1,   463,   465,    -1,   466,    -1,   463,   466,    -1,   472,
      -1,   463,   472,    -1,   467,    -1,   463,   467,    -1,   470,
      -1,   463,   470,    -1,   471,    -1,   463,   471,    -1,    34,
      -1,    23,    -1,   391,   511,   111,   482,   392,   482,   478,
     464,    -1,   391,   511,   111,   482,   392,   482,   393,   482,
     478,   464,    -1,   391,   511,   395,   474,   478,   464,    -1,
     396,   478,    -1,   398,   517,   478,    -1,   400,   482,   478,
     464,    -1,   400,   482,   478,   402,   478,   464,    -1,    -1,
     429,   511,   468,    13,   476,    14,   478,   464,    -1,    -1,
     429,    71,   469,    13,   476,    14,   478,   464,    -1,   430,
     511,   478,   464,    -1,    72,   511,    -1,   404,   484,   464,
      -1,   404,   464,    -1,   405,   484,    -1,   515,    -1,   506,
      -1,    33,    -1,   399,    -1,    81,    -1,    83,    -1,    84,
      -1,    82,    -1,    85,    13,   482,    14,    -1,    86,    13,
     482,    20,    71,    14,    -1,   511,   111,    17,   517,    -1,
     511,   111,   506,    -1,   511,   111,   506,    20,   484,    -1,
     511,   111,   514,    -1,   511,   111,   266,    15,   482,    16,
      -1,   511,    90,   266,    15,   482,    16,    -1,   511,   111,
      35,    15,   482,    16,    -1,   511,    90,   483,    -1,    76,
      15,   482,    16,   111,   483,    -1,   511,   111,   507,    -1,
      75,    15,   482,    16,   111,   510,    -1,   511,   111,   510,
      -1,   509,    90,   510,    -1,    75,    90,   266,    15,   482,
      16,    -1,   511,   111,   356,    13,   482,    14,    -1,   511,
     111,   356,    13,   482,    14,    20,   484,    -1,   511,   111,
     353,    13,   482,    14,    -1,   511,   111,   353,    13,   482,
      14,    20,   484,    -1,   511,   111,   368,    13,   484,    20,
      53,    14,    -1,    66,   111,   368,    13,   484,    20,    53,
      14,    -1,    66,    19,   372,    -1,    24,    -1,    25,    -1,
      26,    -1,    27,    -1,    28,    13,   484,    20,   484,    20,
     484,    14,    -1,    29,    13,   482,    14,    -1,    30,    13,
     484,    14,    -1,    41,    -1,    39,   486,    -1,    42,   486,
      -1,    39,   509,    -1,   486,    90,   483,    -1,   486,    19,
      87,    13,   482,    20,   506,    14,    -1,   486,    13,   482,
      22,   482,    20,   482,    22,   482,    20,   482,    22,   482,
      14,   111,   483,    -1,    59,   100,    -1,    59,   101,    -1,
      59,   111,   482,    -1,    60,   111,   482,    -1,    60,   100,
      -1,    60,   101,    -1,    39,   403,    -1,   517,    19,    79,
      13,   484,    14,    -1,    77,   517,    -1,    78,   484,    -1,
      77,    75,    15,   482,    16,    -1,    48,   484,    -1,    49,
      -1,    40,    -1,    40,   511,    -1,    40,    70,    -1,    40,
      67,    -1,    40,    68,    -1,    40,    69,    -1,    40,    53,
      -1,    66,    19,    43,   484,    -1,    66,    19,    44,   484,
      -1,    43,   506,    -1,    44,   506,    -1,    45,   484,    -1,
      66,    19,    43,   482,    -1,    66,    19,   369,    -1,    62,
      19,   327,    13,   482,    20,   482,    20,   482,    14,    -1,
      62,    19,   328,    13,   482,    14,    -1,    62,    19,   329,
      -1,    62,    19,   330,    13,   486,    14,    -1,    62,    19,
     330,    13,    62,    14,    -1,    62,    19,   333,    13,    62,
      20,   486,    14,    -1,    62,    19,   435,    13,   482,    20,
     482,    20,   482,    20,   482,    20,   482,    20,   482,    20,
     482,    20,   482,    20,   482,    20,   482,    20,   482,    20,
     482,    14,    -1,    62,    19,   331,    13,    55,    20,   486,
      14,    -1,    62,    19,   334,    13,   482,    20,   482,    14,
      -1,    62,    19,   335,    -1,    62,    19,   336,    13,   482,
      20,   482,    14,    -1,    62,    19,   337,    13,   482,    20,
     482,    20,   482,    20,   482,    14,    -1,    62,    19,   338,
      13,   482,    14,    -1,    62,    19,   339,    13,   482,    14,
      -1,    62,    19,   340,    13,   482,    20,   482,    20,   482,
      20,   482,    20,   482,    20,   482,    14,    -1,    62,    19,
     341,    13,   482,    20,   482,    14,    -1,    62,    19,   343,
      13,   482,    20,   482,    20,   482,    20,   482,    20,   482,
      20,   482,    14,    -1,    62,    19,   342,    13,   483,    20,
     482,    20,   482,    14,    -1,    62,    19,   344,    13,    64,
      14,    -1,    62,    19,   216,    13,   482,    20,   486,    20,
     482,    14,    -1,    62,    19,   216,    13,   486,    20,   482,
      14,    -1,    62,    19,   217,    13,   482,    20,   482,    20,
     482,    14,    -1,    62,    19,   217,    13,   482,    20,   482,
      20,   482,    20,   482,    20,   482,    14,    -1,    62,    19,
     218,    13,   482,    20,   482,    14,    -1,    62,    19,   219,
      13,   482,    20,   482,    20,   482,    20,   482,    14,    -1,
      62,    19,   220,    13,   482,    14,    -1,    62,    19,   221,
      13,   482,    20,   482,    14,    -1,    62,    19,   454,    13,
      71,    14,    -1,    62,    19,   297,    13,   486,    14,    -1,
     486,    19,   154,    -1,   486,    19,   159,    -1,    73,   159,
      -1,   509,    19,   159,    -1,   486,    19,   345,    13,   482,
      14,    -1,   486,    19,   345,    13,   482,    20,   482,    20,
     482,    14,    -1,   486,    19,   326,    13,   482,    14,    -1,
     486,    19,   326,    13,   482,    20,   482,    20,   482,    14,
      -1,   486,    19,   327,    13,   482,    20,   482,    20,   482,
      14,    -1,   486,    19,   125,    13,   486,    20,   482,    20,
     482,    20,   482,    14,    -1,   486,    19,   125,    13,   486,
      14,    -1,   486,    19,    50,    13,   484,    14,    -1,   144,
      19,   155,    -1,   144,    19,   156,    -1,   145,    19,   155,
      -1,   145,    19,   156,    -1,   486,    19,   162,   484,    -1,
     486,    19,   163,    -1,   486,    19,   164,    13,   486,    14,
      -1,   486,    19,   165,    13,   486,    14,    -1,   509,    19,
     162,   484,    -1,   509,    19,   215,   484,    -1,   509,    19,
     277,    13,   482,    14,    -1,   509,    19,   292,    13,   482,
      20,   482,    20,   482,    14,    -1,   509,    19,   293,    13,
     482,    20,   482,    20,   482,    14,    -1,   509,    19,   294,
      13,   482,    20,   482,    20,   482,    14,    -1,   509,    19,
     295,    13,   482,    14,    -1,   509,    19,   296,    13,   482,
      14,    -1,   509,    19,   298,    13,   482,    14,    -1,   509,
      19,   299,    13,   482,    14,    -1,   509,    19,   280,    13,
     482,    14,    -1,   509,    19,   278,    13,   482,    20,   482,
      20,   482,    14,    -1,   509,    19,   314,    13,   486,    14,
      -1,   509,    19,   279,    13,   483,    20,   482,    20,   482,
      14,    -1,   509,    19,   279,    13,   483,    14,    -1,   509,
      19,   300,    13,   486,    14,    -1,   509,    19,   307,    13,
     482,    14,    -1,   509,    19,   308,    -1,   509,    19,   192,
      13,   482,    14,    -1,   509,    19,   309,    13,   483,    14,
      -1,   509,    19,   312,    13,   482,    20,   482,    20,   482,
      14,    -1,   509,    19,   313,    13,   482,    20,   482,    20,
     482,    14,    -1,   509,    19,   315,    13,   482,    14,    -1,
     509,    19,   200,    13,   482,    14,    -1,   509,    19,   305,
      13,   483,    14,    -1,   509,    19,   306,    -1,   509,    19,
     261,    -1,   509,    19,   310,    -1,   509,    19,   311,    -1,
     509,    19,   260,    13,   482,    14,    -1,   509,    19,   262,
      13,   482,    14,    -1,   509,    19,   258,    -1,   509,    19,
     272,    13,   482,    14,    -1,   509,    19,   271,    13,   482,
      14,    -1,   509,    19,   271,    13,   482,    20,   482,    14,
      -1,   509,    19,   316,    13,   482,    20,   482,    20,   482,
      14,    -1,   509,    19,   317,    -1,   509,    19,   319,    13,
     482,    14,    -1,   509,    19,   318,    -1,   452,    13,   484,
      14,    -1,   453,    13,    62,    20,   482,    20,   482,    20,
     482,    20,   482,    20,   482,    20,   482,    20,   482,    20,
     482,    14,    -1,   509,    19,   444,    13,   483,    14,    -1,
      64,    19,   269,    13,   482,    20,   482,    20,   482,    14,
      -1,    64,    19,   273,    13,   510,    14,    -1,    64,    91,
     509,    -1,    64,    92,   509,    -1,    64,    19,   290,    13,
     509,    14,    -1,    64,    19,   291,    -1,    64,    19,   271,
      13,   482,    14,    -1,    64,    19,   271,    13,   482,    20,
     482,    14,    -1,    64,    19,   274,    13,   482,    14,    -1,
      64,    19,   330,    13,    64,    14,    -1,    64,    19,   331,
      13,    55,    20,   486,    14,    -1,    64,    19,   346,    13,
     482,    20,   483,    20,   482,    20,   482,    20,   482,    20,
     482,    14,    -1,    64,    19,   347,    13,   482,    14,    -1,
      64,    19,   325,    -1,    64,    19,   321,    13,   507,    14,
      -1,    64,    19,   321,    13,   507,    20,   482,    14,    -1,
      64,    19,   281,    -1,    64,    19,   284,    13,   482,    20,
     482,    20,   482,    20,   482,    14,    -1,    64,    19,   285,
      13,   482,    20,   482,    20,   482,    20,   482,    14,    -1,
      64,    19,   286,    13,   482,    20,   482,    20,   482,    20,
     482,    14,    -1,    64,    19,   287,    13,   482,    20,   482,
      20,   482,    14,    -1,    64,    19,   288,    -1,    64,    19,
     289,    -1,    64,    19,   341,    13,   482,    20,   482,    14,
      -1,   187,    13,   486,    20,   482,    20,   482,    14,    -1,
     187,    13,   486,    20,   482,    20,   482,    20,   483,    14,
      -1,   188,    13,   486,    20,   482,    20,   482,    14,    -1,
     188,    13,   486,    20,   482,    20,   482,    20,   483,    14,
      -1,   188,    13,   486,    20,   482,    20,   482,    20,   483,
      20,   482,    14,    -1,   189,    13,   486,    20,   482,    14,
      -1,   189,    13,   486,    20,   482,    20,   506,    14,    -1,
     189,    13,   486,    20,   482,    20,   482,    20,   483,    14,
      -1,   191,    13,   486,    20,   482,    20,   482,    20,   482,
      20,   482,    20,   482,    20,   482,    14,    -1,   191,    13,
     486,    20,   482,    20,   482,    20,   482,    20,   482,    20,
     482,    20,   482,    20,   483,    14,    -1,   190,    13,   486,
      20,   482,    20,   482,    20,   483,    20,   482,    14,    -1,
     192,    13,   486,    20,   482,    14,    -1,   237,    13,    53,
      20,   486,    20,   486,    20,   486,    20,   486,    20,   486,
      20,   486,    20,   483,    14,    -1,   237,    13,    53,    20,
     486,    20,   486,    20,   486,    20,   486,    20,   486,    20,
     486,    14,    -1,   236,    13,    53,    20,   486,    20,   486,
      20,   486,    20,   483,    14,    -1,   236,    13,    53,    20,
     486,    20,   486,    20,   486,    14,    -1,   194,    13,   486,
      20,   482,    20,   482,    20,   482,    14,    -1,   486,    19,
     194,    13,   482,    20,   482,    20,   482,    14,    -1,   486,
      19,   194,    13,   486,    14,    -1,   486,    19,   195,    13,
     482,    20,   482,    20,   482,    14,    -1,   486,    19,   195,
      13,   486,    14,    -1,   486,    19,   196,    13,   482,    14,
      -1,   127,    13,   486,    20,   486,    14,    -1,   127,    13,
     486,    20,   486,    20,   486,    14,    -1,   250,    13,   482,
      14,    -1,   251,    13,   482,    14,    -1,   364,    13,   483,
      20,   484,    20,   482,    14,    -1,   367,    13,   486,    14,
      -1,   235,    13,   486,    20,   486,    20,   482,    20,   482,
      20,   482,    20,   482,    20,   482,    20,   482,    14,    -1,
     421,    13,    53,    14,    -1,   137,    -1,   138,    -1,   140,
      -1,   455,    13,   486,    20,   484,    14,    -1,    74,    19,
      43,    -1,    74,    19,   162,   484,    -1,   456,    -1,   457,
      -1,   458,    -1,   459,    13,   486,    20,   486,    20,   486,
      20,   486,    20,   486,    20,   486,    20,   486,    20,   482,
      20,   482,    20,   482,    20,   482,    20,   482,    20,   482,
      20,   482,    14,    -1,   460,    13,   486,    20,   486,    20,
     482,    20,   482,    20,   482,    20,   482,    20,   482,    20,
     482,    20,   486,    20,   486,    20,   482,    14,    -1,   447,
      13,   482,    20,   482,    20,   482,    14,    -1,   484,    -1,
     474,    20,   484,    -1,    -1,   515,    -1,   475,    20,   515,
      -1,    17,   517,    -1,   475,    20,    17,   517,    -1,   506,
      -1,   475,    20,   506,    -1,    -1,   425,    56,    -1,   428,
      56,    -1,   426,    56,    -1,   422,    56,    -1,   423,    56,
      -1,   424,    56,    -1,   476,    20,   428,    56,    -1,   476,
      20,   425,    56,    -1,   476,    20,   426,    56,    -1,   476,
      20,   422,    56,    -1,   476,    20,   423,    56,    -1,   476,
      20,   424,    56,    -1,    53,    -1,    47,    13,   484,    20,
     482,    14,    -1,   139,    -1,   486,    19,    51,    -1,    51,
      13,   517,    14,    -1,    52,    13,   517,    14,    -1,    31,
      -1,   479,    54,   480,    -1,    -1,    -1,    55,    -1,    32,
      -1,   373,    -1,   374,    -1,    58,    -1,    59,    -1,    60,
      -1,   486,    13,   482,    20,   482,    14,    -1,   486,    13,
     482,    20,   482,    20,   482,    14,    -1,   486,    19,   332,
      13,   482,    20,   482,    20,   482,    14,    -1,   486,    13,
     482,    20,   482,    20,   482,    20,   482,    14,    -1,   486,
      13,   482,    20,   482,    20,   482,    23,   482,    14,    -1,
     486,    13,   482,    20,   482,    23,   482,    14,    -1,   486,
      13,   482,    23,   482,    14,    -1,   486,    19,   406,    -1,
     486,    19,   407,    -1,   486,    19,   408,    -1,   486,    19,
     409,    -1,   486,    19,   410,    -1,   486,    19,   411,    -1,
     486,    19,   412,    -1,   486,    19,   413,    -1,   486,    19,
     414,    -1,   486,    19,   415,    -1,   486,    19,   416,    -1,
     486,    19,   417,    -1,   509,    19,   160,    -1,   509,    19,
     161,    -1,   158,    13,   486,    20,   486,    14,    -1,   179,
      13,   486,    14,    -1,   252,    13,   486,    20,   482,    20,
     482,    20,   482,    14,    -1,   253,    13,   486,    14,    -1,
     253,    13,   482,    20,   482,    20,   482,    20,   482,    14,
      -1,   112,    13,   483,    14,    -1,   181,    13,   483,    14,
      -1,   113,    13,   483,    14,    -1,   114,    13,   483,    14,
      -1,   115,    13,   483,    14,    -1,   116,    13,   483,    14,
      -1,   113,    15,   483,    16,    13,   483,    14,    -1,   115,
      15,   483,    16,    13,   486,    14,    -1,   116,    15,   483,
      16,    13,   486,    14,    -1,   116,    15,   483,    16,    13,
     486,    20,   482,    14,    -1,   181,    15,   483,    16,    13,
     483,    14,    -1,   181,    13,   486,    20,   483,    14,    -1,
     363,    13,   484,    14,    -1,    62,    19,   226,    -1,    62,
      19,   227,    -1,    62,    19,   224,    -1,    62,    19,   225,
      -1,    62,    19,   222,    -1,    62,    19,   223,    -1,    62,
      19,   228,    -1,    62,    19,   229,    -1,    62,    19,   230,
      -1,    65,    13,   482,    20,   482,    14,    -1,    65,    19,
     326,    13,   482,    20,   482,    20,   482,    14,    -1,   418,
      13,   511,    14,    -1,   418,    13,   517,    14,    -1,   419,
      13,   484,    14,    -1,   485,    19,   417,    -1,    66,    19,
     370,    13,   484,    14,    -1,    66,    19,   371,    13,    58,
      14,    -1,    66,    19,   371,    13,    61,    14,    -1,   509,
      19,   211,    -1,   506,    -1,   506,    -1,   506,    -1,   352,
      -1,   353,    -1,   354,    -1,   355,    -1,   356,    -1,   357,
      -1,   358,    -1,   359,    -1,   360,    -1,   361,    -1,   486,
      19,   362,    -1,    57,    -1,    76,    15,   482,    16,    -1,
      35,   484,    -1,    37,    13,   482,    20,   482,    20,   482,
      20,   482,    20,   484,    20,   482,    20,   482,    14,    -1,
      37,    13,   482,    20,   482,    20,   482,    20,   482,    20,
     482,    20,   484,    14,    -1,    37,    13,   482,    20,   482,
      20,   482,    20,   482,    20,   482,    20,   482,    20,   484,
      14,    -1,   231,    13,   484,    14,    -1,   232,    13,   484,
      14,    -1,    36,    -1,    35,    13,   485,    20,   482,    20,
     482,    20,   482,    14,    -1,    35,    13,   485,    20,   482,
      20,   482,    20,   482,    20,   482,    14,    -1,    35,    13,
     485,    20,   482,    20,   486,    14,    -1,   486,    -1,   486,
      15,   482,    16,    -1,   182,    13,   483,    20,   482,    14,
      -1,   183,    13,   483,    20,   482,    14,    -1,   184,    13,
     483,    20,   482,    14,    -1,   185,    13,   483,    20,   483,
      20,   482,    14,    -1,   186,    13,   483,    20,   483,    20,
     482,    14,    -1,   117,    13,   486,    20,    53,    14,    -1,
     117,    13,   486,    20,    53,    20,   485,    14,    -1,   117,
      13,   486,    20,   486,    20,    53,    14,    -1,   117,    13,
     486,    20,   486,    20,    53,    20,   485,    14,    -1,   117,
      13,   486,    20,   486,    20,   486,    20,    53,    14,    -1,
     117,    13,   486,    20,   486,    20,   486,    20,    53,    20,
     485,    14,    -1,   118,    13,   483,    20,   482,    20,   482,
      20,   482,    20,   482,    14,    -1,   437,    19,   438,    13,
     486,    20,   482,    20,   482,    14,    -1,   264,    13,   486,
      14,    -1,   135,    13,   486,    20,   482,    20,   482,    20,
     482,    14,    -1,   265,    13,   486,    14,    -1,   166,    13,
     483,    20,   482,    14,    -1,   167,    13,   486,    14,    -1,
     168,    13,   486,    14,    -1,   169,    13,   486,    14,    -1,
     170,    13,   486,    20,   486,    20,   482,    20,   482,    20,
     482,    14,    -1,   171,    13,   486,    14,    -1,   172,    13,
     486,    20,   486,    20,   486,    20,   482,    20,   486,    14,
      -1,   173,    13,   486,    20,   486,    20,   486,    20,   482,
      20,   486,    14,    -1,   174,    13,   486,    20,   486,    20,
     486,    20,   482,    20,   486,    20,   482,    20,   482,    14,
      -1,   175,    13,   486,    20,   486,    20,   486,    20,   482,
      20,   486,    20,   482,    20,   482,    20,   482,    20,   482,
      14,    -1,   176,    13,   486,    20,   486,    20,   486,    20,
     486,    14,    -1,   176,    13,   486,    20,   486,    20,   486,
      20,   486,    20,   482,    14,    -1,   177,    13,   486,    14,
      -1,   177,    13,   486,    20,   486,    14,    -1,   178,    13,
     486,    20,   486,    14,    -1,   119,    13,   483,    20,   482,
      14,    -1,   120,    13,   486,    14,    -1,   134,    13,   486,
      14,    -1,   121,    13,   486,    20,   482,    14,    -1,   193,
      13,   486,    14,    -1,   122,    13,   486,    20,   482,    14,
      -1,   123,    13,   486,    20,   482,    14,    -1,   126,    13,
     483,    20,   482,    14,    -1,   486,    15,   518,    16,    -1,
     486,    15,    22,    20,    22,    20,   482,    22,   482,    16,
      -1,   124,    13,   486,    20,   482,    20,   482,    20,   482,
      20,   482,    20,   482,    20,   482,    14,    -1,   128,    13,
     486,    20,   482,    20,   482,    20,   482,    14,    -1,   128,
      13,   486,    20,   482,    20,   482,    14,    -1,   128,    13,
     486,    20,   482,    20,   482,    20,   482,    20,   482,    14,
      -1,   129,    13,   486,    20,   482,    20,   482,    20,   482,
      14,    -1,   129,    13,   486,    20,   482,    20,   482,    14,
      -1,   129,    13,   486,    20,   482,    20,   482,    20,   482,
      20,   482,    14,    -1,   130,    13,   486,    20,   482,    20,
     482,    14,    -1,   130,    13,   486,    20,   482,    20,   482,
      20,   482,    20,   482,    14,    -1,   131,    13,   486,    20,
     482,    20,   482,    14,    -1,   131,    13,   486,    20,   482,
      20,   482,    20,   482,    20,   482,    14,    -1,   143,    13,
     486,    20,   486,    20,   482,    20,   482,    20,   482,    14,
      -1,   133,    13,   486,    20,   482,    20,   482,    20,   482,
      20,   482,    20,   482,    14,    -1,   132,    13,   486,    20,
     482,    20,   482,    20,   482,    20,   482,    14,    -1,   144,
      19,   154,    13,   486,    20,   482,    20,   482,    20,   482,
      14,    -1,   145,    19,   154,    13,   486,    20,   482,    20,
     482,    20,   482,    20,   482,    20,   482,    14,    -1,   146,
      13,   486,    14,    -1,   147,    13,   486,    20,   482,    20,
     482,    14,    -1,   147,    13,   486,    20,   482,    20,   482,
      20,   518,    14,    -1,   147,    13,   486,    20,   482,    20,
     482,    20,   482,    20,   518,    14,    -1,   148,    13,   486,
      20,   482,    20,   482,    20,   518,    14,    -1,   148,    13,
     486,    20,   482,    20,   482,    20,   482,    20,   518,    14,
      -1,   149,    13,   486,    20,   482,    20,   482,    20,   518,
      14,    -1,   150,    13,   486,    20,   482,    20,   482,    20,
     482,    20,   518,    14,    -1,   151,    13,   486,    20,   482,
      20,   482,    20,   482,    20,   518,    14,    -1,   152,    13,
     486,    20,   482,    20,   482,    20,   482,    20,   482,    20,
     518,    14,    -1,   153,    13,   486,    20,   482,    20,   482,
      20,   482,    20,   482,    14,    -1,   157,    13,   486,    20,
     482,    20,   482,    14,    -1,   180,    13,   486,    20,   482,
      20,   482,    20,   482,    20,   482,    20,   482,    14,    -1,
     348,    13,   486,    14,    -1,   349,    13,   486,    14,    -1,
     350,    13,   486,    14,    -1,   351,    13,   486,    14,    -1,
      64,    19,   267,    -1,    64,    19,   268,    -1,    62,    19,
     267,    -1,   202,    13,   486,    20,   482,    14,    -1,   203,
      13,   486,    20,   482,    14,    -1,   204,    13,   486,    20,
     482,    14,    -1,   205,    13,   486,    20,   482,    14,    -1,
     141,    13,   483,    20,   483,    20,   482,    14,    -1,   142,
      13,   483,    20,   483,    20,   482,    20,   482,    20,   482,
      20,   482,    14,    -1,   141,    13,   483,    20,   483,    20,
     482,    20,   482,    20,   482,    14,    -1,   141,    13,   483,
      20,   483,    20,   482,    20,   482,    20,   482,    20,   482,
      14,    -1,   141,    13,   483,    20,   483,    20,   486,    20,
     482,    20,   482,    14,    -1,   233,    13,   486,    20,   486,
      14,    -1,   234,    13,   486,    20,   486,    20,   483,    14,
      -1,   238,    13,   486,    20,   482,    20,   482,    20,   482,
      14,    -1,   239,    13,   486,    20,   482,    20,   482,    20,
     482,    14,    -1,   239,    13,   486,    20,   482,    20,   482,
      20,   482,    20,   482,    14,    -1,   240,    13,   486,    20,
     482,    14,    -1,   241,    13,   486,    20,   482,    14,    -1,
     242,    13,   486,    20,   482,    14,    -1,   243,    13,   486,
      20,   482,    14,    -1,   244,    13,   486,    20,   482,    14,
      -1,   245,    13,   486,    20,   482,    14,    -1,   246,    13,
     486,    20,   482,    14,    -1,   247,    13,   486,    20,   482,
      14,    -1,   247,    13,   486,    20,   482,    20,   482,    14,
      -1,   248,    13,   486,    20,   482,    20,   482,    20,   482,
      14,    -1,   249,    13,   483,    14,    -1,   486,    13,   506,
      14,    -1,   365,    13,   483,    20,   482,    20,   482,    20,
     482,    14,    -1,   366,    13,   483,    20,   482,    20,   482,
      20,   482,    14,    -1,   431,    13,   483,    14,    -1,   431,
      13,   483,    20,   482,    14,    -1,   434,    13,   483,    20,
     482,    14,    -1,   432,    13,   483,    20,   482,    20,   482,
      20,   482,    20,   482,    14,    -1,   433,    13,   486,    20,
     486,    20,   482,    20,   482,    20,   482,    20,   482,    20,
     482,    20,   482,    20,   482,    20,   482,    20,   482,    20,
     482,    20,   482,    20,   482,    14,    -1,   436,    13,   483,
      20,   482,    20,   482,    14,    -1,   509,    19,   302,    13,
      14,    -1,   509,    19,   212,    13,   482,    14,    -1,   509,
      19,   303,    13,    14,    -1,   509,    19,   304,    13,    14,
      -1,   509,    19,   301,    13,   486,    14,    -1,   442,    13,
     483,    20,   482,    14,    -1,   442,    13,   483,    14,    -1,
     443,    13,   483,    20,   482,    14,    -1,   443,    13,   483,
      14,    -1,   449,    13,   483,    20,   483,    14,    -1,   450,
      13,   483,    14,    -1,   451,    13,   484,    14,    -1,   420,
      13,   483,    20,   482,    20,   482,    20,   482,    20,   482,
      20,   482,    20,   482,    20,   482,    14,    -1,   210,    13,
     509,    20,   486,    20,   483,    14,    -1,   214,    13,   509,
      20,   484,    14,    -1,   487,    -1,    61,    -1,   477,    -1,
     481,    -1,   488,    -1,   489,    -1,   508,    -1,   113,    13,
     506,    20,   506,    14,    -1,   513,    13,   475,    14,    -1,
      13,   506,    14,    -1,   490,    -1,     9,   490,    -1,   490,
     100,    -1,   490,   101,    -1,    13,   485,    14,   490,    -1,
     490,   109,    -1,   491,    -1,    11,   491,    -1,    10,   491,
      -1,   100,   491,    -1,   101,   491,    -1,   375,   491,    -1,
     376,   491,    -1,   386,   491,    -1,   387,   491,    -1,   388,
     491,    -1,   389,   491,    -1,   377,   491,    -1,   378,   491,
      -1,   379,   491,    -1,   380,   491,    -1,   383,   491,    -1,
     385,   491,    -1,   384,   491,    -1,   390,   491,    -1,   492,
      -1,   493,     7,   492,    -1,   493,     8,   492,    -1,   493,
      12,   492,    -1,   493,     4,   492,    -1,   493,    -1,   494,
      10,   493,    -1,   494,    11,   493,    -1,   494,    -1,   495,
      -1,   496,     6,   495,    -1,   496,     5,   495,    -1,   496,
     105,   495,    -1,   496,   106,   495,    -1,   496,    -1,   497,
     107,   496,    -1,   497,   108,   496,    -1,   497,    -1,   498,
      17,   497,    -1,   498,    -1,   499,    -1,   500,    18,   499,
      -1,   500,    -1,   501,   103,   500,    -1,   501,    -1,   502,
       4,   501,    -1,   502,    -1,   503,   104,   502,    -1,   503,
      -1,   503,    21,   503,    22,   504,    -1,   504,    -1,   492,
     111,   505,    -1,   492,    91,   505,    -1,   492,    92,   505,
      -1,   492,    93,   505,    -1,   492,    94,   505,    -1,   505,
      -1,    74,    -1,    64,    19,   320,    -1,   322,    13,    74,
      20,    74,    20,   482,    14,    -1,    38,    13,   484,    14,
      -1,   323,    13,   482,    20,   482,    14,    -1,    65,    -1,
     324,    13,   506,    14,    -1,    63,    -1,    75,    15,   482,
      16,    -1,   254,    13,   483,    20,   482,    14,    -1,   257,
      13,   486,    20,   482,    14,    -1,   254,    13,   483,    20,
     482,    20,   486,    14,    -1,   263,    13,   483,    20,   482,
      20,   483,    14,    -1,   258,    13,   509,    14,    -1,   258,
      13,   509,    20,   482,    14,    -1,   259,    13,   486,    20,
     482,    14,    -1,   260,    13,   509,    20,   482,    14,    -1,
     262,    13,   509,    20,   482,    14,    -1,   266,    13,    14,
      -1,   266,   484,    -1,   266,    -1,   213,    13,   484,    14,
      -1,   213,    13,   484,    20,   482,    14,    -1,   509,    -1,
     197,    13,   486,    14,    -1,   198,    13,   509,    14,    -1,
     198,    13,   509,    20,   482,    20,   482,    20,   482,    14,
      -1,   199,    13,   509,    20,   482,    14,    -1,   206,    13,
     509,    20,   482,    20,   482,    20,   482,    20,   482,    20,
     482,    20,   482,    14,    -1,   207,    13,   483,    20,   482,
      20,   482,    20,   482,    20,   482,    20,   482,    20,   482,
      20,   482,    14,    -1,   208,    13,   483,    20,   482,    20,
     482,    20,   482,    14,    -1,   209,    13,   483,    20,   482,
      20,   482,    20,   482,    20,   482,    20,   482,    20,   482,
      20,   482,    20,   482,    14,    -1,   209,    13,   483,    20,
     482,    20,   482,    20,   482,    20,   482,    20,   482,    14,
      -1,   509,    19,   201,    13,   482,    20,   482,    14,    -1,
     439,    13,   483,    14,    -1,   439,    13,   483,    20,   482,
      14,    -1,   439,    13,   483,    20,   482,    20,   482,    14,
      -1,   441,    13,   483,    20,   482,    20,   482,    14,    -1,
     440,    13,   483,    20,   482,    20,   482,    20,   483,    20,
     483,    14,    -1,   440,    13,   483,    20,   482,    20,   482,
      20,   483,    20,   483,    20,   483,    20,   482,    14,    -1,
     445,    13,   483,    20,   483,    20,   483,    20,   482,    20,
     482,    20,   482,    20,   482,    14,    -1,   445,    13,   483,
      20,   483,    20,   483,    20,   482,    20,   482,    20,   482,
      20,   482,    20,   482,    14,    -1,   445,    13,   483,    20,
     483,    20,   483,    20,   482,    20,   482,    20,   482,    14,
      -1,   446,    13,   483,    20,   482,    20,   482,    20,   482,
      20,   482,    20,   482,    14,    -1,   448,    13,   483,    20,
     483,    20,   483,    20,   482,    20,   482,    20,   482,    20,
     482,    14,    -1,   448,    13,   483,    20,   483,    20,   483,
      20,   482,    20,   482,    20,   482,    20,   482,    20,   483,
      20,   483,    14,    -1,    56,    -1,    74,    -1,   509,    -1,
      67,    -1,    68,    -1,    70,    -1,    69,    -1,    71,    -1,
      73,    19,   511,    -1,   513,    -1,    62,    -1,    75,    -1,
      64,    -1,    66,    -1,    72,    -1,    73,    -1,    76,    -1,
     512,    -1,   514,    -1,    59,    -1,    60,    -1,    58,    -1,
      61,    -1,    65,    -1,   486,    -1,   515,    -1,   516,    -1,
     482,    22,   482,    20,   482,    22,   482,    20,   482,    22,
     482,    -1,   482,    22,   482,    20,   482,    22,   482,    -1,
     486,    19,    88,    -1,    62,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     9,    12,    15,    19,    21,
      24,    26,    29,    31,    34,    36,    39,    41,    44,    46,
      49,    51,    53,    62,    73,    80,    83,    87,    92,    99,
     100,   109,   110,   119,   124,   127,   131,   134,   137,   139,
     141,   143,   145,   147,   149,   151,   153,   158,   165,   170,
     174,   180,   184,   191,   198,   205,   209,   216,   220,   227,
     231,   235,   242,   249,   258,   265,   274,   283,   292,   296,
     298,   300,   302,   304,   313,   318,   323,   325,   328,   331,
     334,   338,   347,   364,   367,   370,   374,   378,   381,   384,
     387,   394,   397,   400,   406,   409,   411,   413,   416,   419,
     422,   425,   428,   431,   436,   441,   444,   447,   450,   455,
     459,   470,   477,   481,   488,   495,   504,   533,   542,   551,
     555,   564,   577,   584,   591,   608,   617,   634,   645,   652,
     663,   672,   683,   698,   707,   720,   727,   736,   743,   750,
     754,   758,   761,   765,   772,   783,   790,   801,   812,   825,
     832,   839,   843,   847,   851,   855,   860,   864,   871,   878,
     883,   888,   895,   906,   917,   928,   935,   942,   949,   956,
     963,   974,   981,   992,   999,  1006,  1013,  1017,  1024,  1031,
    1042,  1053,  1060,  1067,  1074,  1078,  1082,  1086,  1090,  1097,
    1104,  1108,  1115,  1122,  1131,  1142,  1146,  1153,  1157,  1162,
    1183,  1190,  1201,  1208,  1212,  1216,  1223,  1227,  1234,  1243,
    1250,  1257,  1266,  1283,  1290,  1294,  1301,  1310,  1314,  1327,
    1340,  1353,  1364,  1368,  1372,  1381,  1390,  1401,  1410,  1421,
    1434,  1441,  1450,  1461,  1478,  1497,  1510,  1517,  1536,  1553,
    1566,  1577,  1588,  1599,  1606,  1617,  1624,  1631,  1638,  1647,
    1652,  1657,  1666,  1671,  1690,  1695,  1697,  1699,  1701,  1708,
    1712,  1717,  1719,  1721,  1723,  1754,  1779,  1788,  1790,  1794,
    1795,  1797,  1801,  1804,  1809,  1811,  1815,  1816,  1819,  1822,
    1825,  1828,  1831,  1834,  1839,  1844,  1849,  1854,  1859,  1864,
    1866,  1873,  1875,  1879,  1884,  1889,  1891,  1895,  1896,  1897,
    1899,  1901,  1903,  1905,  1907,  1909,  1911,  1918,  1927,  1938,
    1949,  1960,  1969,  1976,  1980,  1984,  1988,  1992,  1996,  2000,
    2004,  2008,  2012,  2016,  2020,  2024,  2028,  2032,  2039,  2044,
    2055,  2060,  2071,  2076,  2081,  2086,  2091,  2096,  2101,  2109,
    2117,  2125,  2135,  2143,  2150,  2155,  2159,  2163,  2167,  2171,
    2175,  2179,  2183,  2187,  2191,  2198,  2209,  2214,  2219,  2224,
    2228,  2235,  2242,  2249,  2253,  2255,  2257,  2259,  2261,  2263,
    2265,  2267,  2269,  2271,  2273,  2275,  2277,  2279,  2283,  2285,
    2290,  2293,  2310,  2325,  2342,  2347,  2352,  2354,  2365,  2378,
    2387,  2389,  2394,  2401,  2408,  2415,  2424,  2433,  2440,  2449,
    2458,  2469,  2480,  2493,  2506,  2517,  2522,  2533,  2538,  2545,
    2550,  2555,  2560,  2573,  2578,  2591,  2604,  2621,  2642,  2653,
    2666,  2671,  2678,  2685,  2692,  2697,  2702,  2709,  2714,  2721,
    2728,  2735,  2740,  2751,  2768,  2779,  2788,  2801,  2812,  2821,
    2834,  2843,  2856,  2865,  2878,  2891,  2906,  2919,  2932,  2949,
    2954,  2963,  2974,  2987,  2998,  3011,  3022,  3035,  3048,  3063,
    3076,  3085,  3100,  3105,  3110,  3115,  3120,  3124,  3128,  3132,
    3139,  3146,  3153,  3160,  3169,  3184,  3197,  3212,  3225,  3232,
    3241,  3252,  3263,  3276,  3283,  3290,  3297,  3304,  3311,  3318,
    3325,  3332,  3341,  3352,  3357,  3362,  3373,  3384,  3389,  3396,
    3403,  3416,  3447,  3456,  3462,  3469,  3475,  3481,  3488,  3495,
    3500,  3507,  3512,  3519,  3524,  3529,  3548,  3557,  3564,  3566,
    3568,  3570,  3572,  3574,  3576,  3578,  3585,  3590,  3594,  3596,
    3599,  3602,  3605,  3610,  3613,  3615,  3618,  3621,  3624,  3627,
    3630,  3633,  3636,  3639,  3642,  3645,  3648,  3651,  3654,  3657,
    3660,  3663,  3666,  3669,  3671,  3675,  3679,  3683,  3687,  3689,
    3693,  3697,  3699,  3701,  3705,  3709,  3713,  3717,  3719,  3723,
    3727,  3729,  3733,  3735,  3737,  3741,  3743,  3747,  3749,  3753,
    3755,  3759,  3761,  3767,  3769,  3773,  3777,  3781,  3785,  3789,
    3791,  3793,  3797,  3806,  3811,  3818,  3820,  3825,  3827,  3832,
    3839,  3846,  3855,  3864,  3869,  3876,  3883,  3890,  3897,  3901,
    3904,  3906,  3911,  3918,  3920,  3925,  3930,  3941,  3948,  3965,
    3984,  3995,  4016,  4031,  4040,  4045,  4052,  4061,  4070,  4083,
    4100,  4117,  4136,  4151,  4166,  4183,  4204,  4206,  4208,  4210,
    4212,  4214,  4216,  4218,  4220,  4224,  4226,  4228,  4230,  4232,
    4234,  4236,  4238,  4240,  4242,  4244,  4246,  4248,  4250,  4252,
    4254,  4256,  4258,  4260,  4272,  4280,  4284
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   759,   759,   760,   764,   764,   765,   766,   767,   767,
     768,   768,   769,   769,   770,   770,   771,   771,   772,   772,
     775,   776,   781,   800,   820,   866,   889,   938,   953,   976,
     975,  1007,  1006,  1050,  1068,  1089,  1096,  1131,  1141,  1174,
    1207,  1215,  1225,  1239,  1253,  1267,  1277,  1293,  1311,  1326,
    1353,  1380,  1427,  1438,  1448,  1459,  1485,  1524,  1554,  1576,
    1588,  1606,  1626,  1638,  1657,  1668,  1755,  1789,  1805,  1811,
    1815,  1819,  1824,  1828,  1843,  1853,  1864,  1867,  1917,  1940,
    1987,  2038,  2128,  2161,  2165,  2169,  2173,  2177,  2181,  2193,
    2197,  2209,  2223,  2233,  2243,  2254,  2262,  2274,  2510,  2520,
    2530,  2540,  2549,  2603,  2612,  2621,  2633,  2674,  2693,  2701,
    2728,  2745,  2758,  2769,  2815,  2822,  2841,  2876,  2891,  2899,
    2907,  2926,  2950,  2956,  2962,  2976,  2988,  2998,  3008,  3015,
    3032,  3048,  3066,  3087,  3103,  3122,  3136,  3151,  3161,  3173,
    3195,  3219,  3241,  3259,  3271,  3285,  3304,  3326,  3355,  3384,
    3416,  3613,  3618,  3625,  3630,  3870,  3898,  3912,  3919,  3925,
    3933,  3947,  3954,  3960,  3967,  3975,  3983,  3991,  4001,  4014,
    4031,  4046,  4054,  4062,  4070,  4078,  4084,  4090,  4136,  4144,
    4152,  4160,  4172,  4181,  4199,  4210,  4217,  4224,  4232,  4241,
    4250,  4270,  4287,  4305,  4323,  4329,  4335,  4341,  4347,  4355,
    4456,  4489,  4496,  4504,  4512,  4520,  4531,  4541,  4549,  4557,
    4568,  4575,  4589,  4603,  4612,  4617,  4626,  4635,  4648,  4661,
    4674,  4687,  4694,  4704,  4714,  4728,  4736,  4747,  4770,  4796,
    4824,  4835,  4878,  4900,  4929,  4946,  4961,  4967,  4994,  5020,
    5040,  5057,  5063,  5069,  5080,  5086,  5094,  5109,  5118,  5129,
    5146,  5162,  5200,  5214,  5261,  5267,  5272,  5277,  5283,  5290,
    5296,  5303,  5308,  5313,  5318,  5361,  5415,  5437,  5445,  5462,
    5466,  5478,  5492,  5504,  5515,  5527,  5543,  5548,  5557,  5564,
    5571,  5578,  5585,  5592,  5599,  5606,  5613,  5620,  5627,  5635,
    5640,  5721,  5745,  5750,  5763,  5782,  5813,  5824,  5825,  5829,
    5833,  5841,  5849,  5858,  5866,  5875,  5884,  5901,  5917,  5934,
    5953,  5971,  5987,  6003,  6009,  6015,  6021,  6027,  6033,  6039,
    6045,  6051,  6057,  6063,  6069,  6076,  6083,  6090,  6099,  6106,
    6137,  6145,  6157,  6177,  6197,  6217,  6237,  6257,  6277,  6301,
    6325,  6349,  6357,  6381,  6404,  6412,  6424,  6436,  6448,  6460,
    6472,  6484,  6500,  6519,  6560,  6570,  6582,  6592,  6602,  6614,
    6622,  6638,  6653,  6665,  6695,  6713,  6726,  6747,  6752,  6756,
    6760,  6764,  6768,  6772,  6776,  6780,  6784,  6788,  6796,  6798,
    6817,  6831,  6886,  6937,  6990,  7010,  7045,  7074,  7081,  7099,
    7124,  7153,  7216,  7282,  7289,  7296,  7304,  7312,  7328,  7346,
    7364,  7381,  7398,  7416,  7452,  7465,  7476,  7489,  7513,  7523,
    7534,  7544,  7554,  7587,  7598,  7619,  7639,  7680,  7727,  7747,
    7768,  7779,  7793,  7807,  7820,  7831,  7842,  7855,  7873,  7885,
    7897,  7904,  7930,  7946,  7987,  7998,  8008,  8020,  8031,  8041,
    8066,  8089,  8117,  8131,  8265,  8299,  8332,  8360,  8374,  8388,
    8398,  8417,  8438,  8460,  8484,  8508,  8528,  8548,  8569,  8610,
    8632,  8661,  8683,  8720,  8757,  8794,  8828,  8834,  8844,  8850,
    8857,  8864,  8872,  8879,  8898,  8926,  8950,  8977,  9009,  9020,
    9033,  9040,  9048,  9062,  9074,  9086,  9096,  9107,  9117,  9127,
    9138,  9148,  9159,  9186,  9234,  9416,  9437,  9477,  9488,  9496,
    9504,  9525,  9551,  9562,  9569,  9606,  9621,  9636,  9644,  9651,
    9657,  9663,  9670,  9695,  9713,  9720,  9753,  9773,  9945,  9958,
    9967,  9981,  9983,  9985,  9987,  9989, 10051, 10129, 10132, 10133,
   10141, 10149, 10158, 10167, 10190, 10191, 10197, 10202, 10207, 10212,
   10217, 10222, 10227, 10232, 10237, 10242, 10247, 10252, 10257, 10262,
   10267, 10272, 10277, 10286, 10287, 10293, 10299, 10305, 10309, 10310,
   10317, 10327, 10331, 10332, 10338, 10344, 10350, 10359, 10360, 10366,
   10392, 10393, 10397, 10401, 10402, 10406, 10407, 10419, 10420, 10432,
   10433, 10445, 10446, 10459, 10460, 10470, 10476, 10482, 10488, 10497,
   10501, 10511, 10525, 10536, 10554, 10560, 10569, 10690, 10692, 10710,
   10721, 10732, 10753, 10787, 10797, 10808, 10818, 10829, 10839, 10845,
   10859, 10885, 10900, 10918, 10927, 10946, 10975, 11003, 11019, 11043,
   11077, 11109, 11156, 11197, 11222, 11232, 11255, 11267, 11279, 11316,
   11359, 11407, 11459, 11502, 11533, 11566, 11609, 11617, 11619, 11622,
   11623, 11624, 11625, 11626, 11627, 11660, 11661, 11662, 11663, 11664,
   11665, 11666, 11667, 11672, 11673, 11679, 11682, 11685, 11688, 11690,
   11692, 11696, 11698, 11701, 11709, 11716, 11732
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
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 12590;
  const int Parser::yynnts_ = 58;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 531;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 461;

  const unsigned int Parser::yyuser_token_number_max_ = 715;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 17477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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


//-------------------------------------------
void CB_ParamWin(void* cd)
 {

  AMIFunction* func_ptr = (AMIFunction*) (cd);

  //cout << "CB_ParamWin pointer is " << func_ptr << endl;

  GB_driver.yyip_call_function(func_ptr);

} // CB_ParamWin( void* cd )

//-----------------------------------------
void CB_delete_variable( void* var)
{
  BasicVariable* vartodelete = (BasicVariable*) var;

  FILE_MESSAGE(boost::format("deleting %1%") % vartodelete->Name());
  if (!Vars.deleteVar(vartodelete))
    FILE_ERROR("Could not delete variable "); 

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
  CB_ParamWin( var->Pointer().get() );

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





